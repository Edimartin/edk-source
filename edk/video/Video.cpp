#include "Video.h"

/*
Library Video - Play video files
Copyright 2013 Eduardo Moura Sales Martins (edimartin@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

//threadFunction
edk::classID functionThread(edk::classID values){
    edk::ThreadVideo* thread = (edk::ThreadVideo*)values;
    if(thread){
        while(true){
            //
            thread->mutVideo.lock();

            if(thread->haveEncoded && !thread->haveDecoded){
                if(thread->canDecodeFrame()){
                    if(thread->decodeFrame()){
                        thread->buffer.cleanWrite();
                        thread->copyDecodedFrame();
                    }
                    thread->haveDecoded=true;
                }
            }
            if(thread->needExit){
                thread->mutVideo.unlock();
                break;
            }
            thread->mutVideo.unlock();
            edk::watch::Time::sleepProcessMicroseconds(1u);
        }
        thread->canDelete=true;
    }
    return NULL;
}

edk::Video::Video(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::Video::~Video(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->close();edkEnd();
        this->buffer.clean();edkEnd();
    }
}

void edk::Video::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;edkEnd();

        this->writingFile=edk::edkVideoWriteNothing;edkEnd();
        this->file.Constructor();edkEnd();
        this->buffer.Constructor();edkEnd();
        this->timeCounter.Constructor();edkEnd();
        this->timeIncrement=0.f;edkEnd();
        this->size=0u;edkEnd();
        this->channels=0u;edkEnd();
        this->frameID=0xFFFFFFFF;
    }
}

//close the file
void edk::Video::close(){
    //finish all threads
    edk::ThreadVideo* thread = NULL;
    edk::uint32 size = this->threads.size();
    for(edk::uint8 i=0u;i<size;i++){
        thread = this->threads.get(i);
        if(thread){
            thread->mutVideo.lock();
            thread->needExit=true;
            thread->mutVideo.unlock();
            thread->mutVideo.lock();
            while(thread->canDelete){
                thread->mutVideo.unlock();
                edk::watch::Time::sleepProcessMicroseconds(1u);
                thread->mutVideo.lock();
            }
            thread->mutVideo.unlock();
            delete thread;
        }
    }
    this->threads.clean();
    if(this->file.isOpened()){
        switch(this->writingFile){
        case edk::edkVideoWriteTrue:
            this->finishEncoder();
            break;
        case edk::edkVideoWriteFalse:
            this->finishDecoder();
            break;
        default:
            break;
        }
        this->file.closeFile();edkEnd();
    }
    this->writingFile=edk::edkVideoWriteNothing;edkEnd();
}

//create a file
bool edk::Video::newFile(edk::char8* name,
                         edk::float32 seconds,
                         edk::float32 fps,
                         edk::uint32 width,
                         edk::uint32 height,
                         edk::uint32 channels
                         ){
    this->frameID=0u;
    this->close();edkEnd();
    if(name && fps>0.f && width && height && channels){
        if(this->file.createAndOpenBinFile(name)){
            //write the header
            this->buffer.clean();
            this->writeHeader(&this->file);edkEnd();
            this->file.flush();
            //write the aditional values to the video file
            this->file.writeBin(fps);
            this->file.writeBin(seconds);
            this->seconds=seconds;
            //set writing
            this->writingFile=edk::edkVideoWriteTrue;edkEnd();
            this->timeIncrement=1.f/fps;edkEnd();

            //start write the frames
            this->size.width = width;
            this->size.height = height;
            this->channels = channels;
            this->file.writeBin(this->size.width);
            this->file.writeBin(this->size.height);
            this->file.writeBin(this->channels);
            this->file.flush();
            if(this->startEncoder(this->size.width,this->size.height,this->channels,fps)){
                return true;
            }
        }
    }
    return false;
}

//open a file
bool edk::Video::openFile(edk::char8* name,
                          edk::uint8 threads
                          ){
    this->frameID=0u;
    this->close();edkEnd();
    if(name){
        if(this->file.openBinFile(name)){
            //read the header
            if(this->readHeader(&this->file)){
                //set reading
                this->writingFile=edk::edkVideoWriteFalse;edkEnd();
                //read the aditional values
                edk::float32 fps=0.f;
                this->file.readBin(&fps,sizeof(fps));
                this->file.readBin(&this->seconds,sizeof(this->seconds));
                this->file.readBin(&this->size.width,sizeof(this->size.width));
                this->file.readBin(&this->size.height,sizeof(this->size.height));
                this->file.readBin(&this->channels,sizeof(this->channels));
                this->timeIncrement=1.f/fps;

                //ceate the threads
                if(!threads){
                    threads=1u;
                }
                edk::ThreadVideo* thread = NULL;
                edk::uint32 size = 0u;
                for(edk::uint8 i=0u;i<threads;i++){
                    thread = new edk::ThreadVideo(this->threads.size(),this);
                    if(thread){
                        size = this->threads.size();
                        this->threads.pushBack(thread);
                        if(size < this->threads.size()){
                            if(!thread->thread.start(&functionThread,thread)){
                                if(this->threads.size()){
                                    this->threads.remove(this->threads.size()-1u);
                                }
                                delete thread;
                            }
                        }
                        else{
                            delete thread;
                        }
                    }
                }
                return this->startDecoder();
            }
        }
    }
    return false;
}

//return true if have the file opened
bool edk::Video::haveFile(){
    return this->file.isOpened();
}
edk::uint8* edk::Video::getFrameVector(){
    if(this->writingFile==edk::edkVideoWriteFalse
            && this->file.isOpened()
            ){
        return (edk::uint8*)this->buffer.getPointer();
    }
    return NULL;
}

//function tu write an image into the file
bool edk::Video::writeFrame(edk::uint8* vector,bool keyFrame){
    if(this->writingFile==edk::edkVideoWriteTrue
            && this->file.isOpened()
            ){
        if(vector && this->size.width && this->size.height && this->channels){
            this->buffer.cleanWrite();
            if(this->encodeFrame(vector,
                                 this->size.width * this->size.height * this->channels,
                                 this->channels,
                                 &this->buffer,
                                 keyFrame
                                 )
                    ){
                //write the lenght and then the buffer
                this->file.writeBin(this->buffer.getSize());
                this->file.writeBin(this->buffer.getPointer(),this->buffer.getSize());
                this->file.flush();
                return true;
            }
        }
    }
    return false;
}
//read frames
bool edk::Video::readNextFrame(){
    if(this->writingFile==edk::edkVideoWriteFalse
            && this->file.isOpened()
            ){
        //copy the packages to be decoded by the threads
        edk::uint32 size = this->threads.size();
        edk::ThreadVideo* thread=NULL;
        edk::uint64 lenght = 0uL;
        if(!this->file.endOfFile()){
            for(edk::uint32 i=0u;i<size;i++){
                thread=(edk::ThreadVideo*)this->threads.get(i);
                thread->mutVideo.lock();
                if(!thread->haveEncoded && !thread->haveDecoded){
                    //add the thread into queue
                    this->queueEncode.pushBack(thread);
                }
                thread->mutVideo.unlock();
            }

            while(this->queueEncode.size()){
                thread=(edk::ThreadVideo*)this->queueEncode.popFront();
                //copy the frame into the thread
                thread->mutVideo.lock();
                if(!this->file.endOfFile()){
                    this->file.readBin(&lenght,sizeof(thread->buffer.getSize()));
                    if(lenght){
                        //read the next encoded frame
                        if(thread->buffer.writeFileToBuffer(&this->file,lenght)){
                            //
                            thread->haveEncoded=true;
                            thread->haveDecoded=false;
                            thread->frameID=this->frameID;
                            this->frameID++;

                            //add into the queue
                            this->queueDecode.pushBack(thread);
                        }
                    }
                }
                thread->mutVideo.unlock();
            }
        }
        if(this->queueDecode.size()){
            edk::uint8 counter = 0u;
            //wait to get the frame
            thread=(edk::ThreadVideo*)this->queueDecode.popFront();
            thread->mutVideo.lock();
            while(!thread->haveDecoded){
                thread->mutVideo.unlock();
                edk::watch::Time::sleepProcessMicroseconds(1u);
                counter++;
                if(counter>100u){
                    counter=0u;
                }
                thread->mutVideo.lock();
            }
            if(thread->haveDecoded){
                //copy the decoded
                this->buffer.cleanWrite();
                this->buffer.pushToBuffer((edk::uint8*)thread->buffer.getPointer(),
                                          thread->buffer.size()
                                          );
                thread->haveDecoded=false;
                thread->haveEncoded=false;
                thread->frameID=0xFFFFFFFF;
            }
            thread->mutVideo.unlock();
            return true;
        }
    }
    return false;
}
//get the frame vector
edk::uint8* edk::Video::getFramePixels(){
    return (edk::uint8*)this->buffer.getPointer();
}
