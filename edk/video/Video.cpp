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
        edk::watch::Time::sleepProcessMicroseconds(1u);
    }
    return NULL;
}

edk::Video::Video(){
    this->classThis=NULL;
    this->Constructor();
}
edk::Video::~Video(){
    this->Destructor();
}

void edk::Video::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->writingFile=edk::edkVideoWriteNothing;

        this->file.Constructor();
        this->buffer.Constructor();
        this->timeCounter.Constructor();

        this->timeIncrement=0.f;
        this->size=0u;
        this->channels=0u;
        this->frameID=0xFFFFFFFF;
    }
}
void edk::Video::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;

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
                thread->thread.waitEnd();
                delete thread;
            }
        }
        this->threads.clean();

        //can destruct the class
        this->close();
        this->buffer.clean();

        this->file.Destructor();
        this->buffer.Destructor();
        this->timeCounter.Destructor();
    }
}

//close the file
void edk::Video::close(){
    this->buffer.cleanWrite();
    edk::ThreadVideo* thread=NULL;
    while(this->queueDecode.size()){
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
            thread->haveDecoded=false;
            thread->haveEncoded=false;
            thread->frameID=0xFFFFFFFF;
        }
        thread->mutVideo.unlock();
    }

    this->queueEncode.clean();
    this->queueDecode.clean();
    /*
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
            thread->thread.waitEnd();
            delete thread;
        }
    }
    this->threads.clean();
    */

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
        this->file.closeFile();
    }
    this->writingFile=edk::edkVideoWriteNothing;
}

//create a file
bool edk::Video::newFile(edk::char8* name,
                         edk::float32 fps,
                         edk::uint32 width,
                         edk::uint32 height,
                         edk::uint32 channels
                         ){
    this->frameID=0u;
    this->close();
    if(name && fps>0.f && width && height && channels){
        if(this->file.createAndOpenBinFile(name)){
            //set writing
            this->writingFile=edk::edkVideoWriteTrue;
            this->fps=fps;
            this->timeIncrement=1.f/this->fps;
            //write the header
            this->buffer.clean();
            this->writeHeader(&this->file);
            this->file.flush();

            //start write the frames
            this->size.width = width;
            this->size.height = height;
            this->channels = channels;
            this->file.writeBin(this->fps);
            this->file.writeBin(this->size.width);
            this->file.writeBin(this->size.height);
            this->file.writeBin(this->channels);
            this->file.flush();
            this->frameLenght=this->timeIncrement;
            if(this->startEncoder(this->size.width,this->size.height,this->channels,fps)){
                return true;
            }
            this->close();
        }
    }
    return false;
}

//open a file
bool edk::Video::openFile(edk::char8* name,
                          edk::uint8 threads
                          ){
    this->frameID=0u;
    this->close();
    if(name){
        if(this->file.openBinFile(name)){
            //read the header
            if(this->readHeader(&this->file)){
                //set reading
                this->writingFile=edk::edkVideoWriteFalse;
                //read the aditional values
                this->file.readBin(&this->fps,sizeof(this->fps));
                this->file.readBin(&this->size.width,sizeof(this->size.width));
                this->file.readBin(&this->size.height,sizeof(this->size.height));
                this->file.readBin(&this->channels,sizeof(this->channels));
                if(this->fps){
                    this->timeIncrement=1.f/fps;
                }
                else{
                    this->timeIncrement=1.f;
                }
                //ceate the threads
                if(!threads){
                    threads=1u;
                }
                edk::ThreadVideo* thread = NULL;
                edk::uint32 size = 0u;
                while(this->threads.size()<threads){
                    thread = new edk::ThreadVideo(this->threads.size(),this);
                    if(thread){
                        size = this->threads.size();
                        this->threads.pushBack(thread);
                        if(size < this->threads.size()){
                            if(!thread->thread.start(&functionThread,thread)){
                                if(this->threads.size()){
                                    this->threads.remove(size);
                                }
                                delete thread;
                            }
                        }
                        else{
                            delete thread;
                        }
                    }
                }
                this->counterTime.start();
                this->saveFrameLenght=0.f;
                this->frameLenght+=this->timeIncrement*0.5f;
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
                this->file.writeBin(this->frameLenght);
                this->file.writeBin(this->buffer.getSize());
                this->file.writeBin(this->buffer.getPointer(),this->buffer.getSize());
                this->file.flush();
                this->frameLenght+=this->timeIncrement;
                return true;
            }
        }
    }
    return false;
}
//read frames
bool edk::Video::readNextFrame(){
    return this->readNextFrame(this->counterTime.getSeconds());
}
bool edk::Video::readNextFrame(edk::float32 seconds){
    if(this->writingFile==edk::edkVideoWriteFalse
            && this->file.isOpened()
            ){
        //copy the packages to be decoded by the threads
        edk::uint32 size = this->threads.size();
        edk::ThreadVideo* thread=NULL;
        edk::uint64 lenght = 0uL;
        edk::float64 lenghtFrame = 0.f;
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
                    this->file.readBin(&lenghtFrame,sizeof(lenghtFrame));
                    this->file.readBin(&lenght,sizeof(thread->buffer.getSize()));
                    if(lenght){
                        //read the next encoded frame
                        if(thread->buffer.writeFileToBuffer(&this->file,lenght)){
                            //
                            thread->haveEncoded=true;
                            thread->haveDecoded=false;
                            thread->frameID=this->frameID;
                            thread->frameLenght=lenghtFrame;
                            this->frameID++;

                            //add into the queue
                            this->queueDecode.pushBack(thread);
                        }
                    }
                }
                thread->mutVideo.unlock();
            }
        }
        while(this->queueDecode.size()){
            if(seconds>=this->saveFrameLenght && seconds<=this->frameLenght){
                this->saveFrameLenght = this->frameLenght;
                edk::uint8 counter = 0u;
                //wait to get the frame
                thread=(edk::ThreadVideo*)this->queueDecode.popFront();
                thread->mutVideo.lock();
                this->frameLenght = thread->frameLenght;
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
            else if(seconds>this->frameLenght){
                this->saveFrameLenght = this->frameLenght;
                //else jump the actual frame
                thread=(edk::ThreadVideo*)this->queueDecode.popFront();
                thread->mutVideo.lock();
                this->frameLenght = thread->frameLenght;
                while(!thread->haveDecoded){
                    thread->mutVideo.unlock();
                    edk::watch::Time::sleepProcessMicroseconds(1u);
                    thread->mutVideo.lock();
                }
                if(thread->haveDecoded){
                    //copy the decoded
                    /*
                    this->buffer.cleanWrite();
                    this->buffer.pushToBuffer((edk::uint8*)thread->buffer.getPointer(),
                                              thread->buffer.size()
                                              );
                                              */
                    thread->haveDecoded=false;
                    thread->haveEncoded=false;
                    thread->frameID=0xFFFFFFFF;
                }
                thread->mutVideo.unlock();
            }
            else{
                break;
            }
        }
    }
    return false;
}
//return true if reach the end of the file
bool edk::Video::endOfFile(){
    if(!this->queueDecode.size() && this->file.endOfFile()){
        return true;
    }
    return false;
}
//get the frame vector
edk::uint8* edk::Video::getFramePixels(){
    return (edk::uint8*)this->buffer.getPointer();
}
