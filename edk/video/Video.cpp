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
    }
}

//close the file
void edk::Video::close(){
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
bool edk::Video::newFile(const edk::char8* name,edk::float32 seconds,edk::float32 fps){
    return this->newFile((edk::char8*) name,seconds,fps);
}
bool edk::Video::newFile(edk::char8* name,edk::float32 seconds,edk::float32 fps){
    this->close();edkEnd();
    if(name && fps){
        if(this->file.createAndOpenBinFile(name)){
            //write the header
            this->buffer.clean();
            this->writeHeader(&this->file);edkEnd();
            //write the aditional values to the video file
            this->file.writeBin(fps);
            this->file.writeBin(seconds);
            this->seconds=seconds;
            this->file.flush();
            //set writing
            this->writingFile=edk::edkVideoWriteTrue;edkEnd();
            this->timeIncrement=1.f/fps;edkEnd();
            return true;
        }
    }
    return false;
}

//open a file
bool edk::Video::openFile(const edk::char8* name){
    return this->openFile((edk::char8*) name);
}
bool edk::Video::openFile(edk::char8* name){
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
                this->timeIncrement=1.f/fps;
                return true;
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
    if(this->writingFile==edk::edkVideoWriteTrue
            && this->file.isOpened()
            ){
        //
    }
    return NULL;
}

bool edk::Video::startWriteFrames(edk::uint32 width,edk::uint32 height,edk::uint32 channels){
    if(this->writingFile==edk::edkVideoWriteTrue
            && this->file.isOpened()
            ){
        if(width && height && channels){
            this->size.width = width;
            this->size.height = height;
            this->channels = channels;
            edk::float32 fps = 24.f;
            if(this->frames && this->seconds>0.f){
                fps = this->seconds / this->frames;
            }
            return this->startEncoder(this->size.width,this->size.height,this->channels,fps);
        }
    }
    return false;
}
bool edk::Video::startWriteFrames(edk::size2ui32 size,edk::uint32 channels){
    return this->startWriteFrames(size.width,size.height,channels);
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
bool edk::Video::startReadFrames(){
    if(this->writingFile==edk::edkVideoWriteFalse
            && this->file.isOpened()
            ){
        return this->startDecoder();
    }
    return false;
}
bool edk::Video::readNextFrame(){
    if(this->writingFile==edk::edkVideoWriteFalse
            && this->file.isOpened()
            ){
        if(!this->file.endOfFile()){
            edk::uint64 lenght = 0uL;
            this->file.readBin(&lenght,sizeof(this->buffer.getSize()));
            if(lenght){
                //read the next encoded frame
                if(this->buffer.writeFileToBuffer(&this->file,lenght)){
                    if(this->decodeFrame(&this->buffer,
                                             &this->size.width,
                                             &this->size.height,
                                             &this->channels
                                         )){
                        this->buffer.cleanWrite();
                        return this->copyDecodedFrame(&this->buffer);
                    }
                }
            }
        }
        //return this->decodeFrame()
    }
    return false;
}
//get the frame vector
edk::uint8* edk::Video::getFramePixels(){
    return (edk::uint8*)this->buffer.getPointer();
}
