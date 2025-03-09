#include "VideoEDK.h"

/*
Library Audio - Play video using openH264
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

edk::video::VideoEDK::VideoEDK(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::video::VideoEDK::~VideoEDK(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
    }
}

void edk::video::VideoEDK::writeHeader(edk::File* file){
    this->headerEDK.fps = this->getFPS();
    this->headerEDK.timeIncrement = this->getTimeIncrement();
    //write the header
    file->writeBin((edk::uint8*)VIDEO_EDK_HEADER_NAME,sizeof(VIDEO_EDK_HEADER_NAME));
    file->writeBin((edk::uint8*)&this->headerEDK,sizeof(this->headerEDK));
    file->flush();
}
bool edk::video::VideoEDK::readHeader(edk::File* file){
    if(file->isOpened()){
        //read the header
        edk::char8 headerName[sizeof(VIDEO_EDK_HEADER_NAME)+1u];
        edkMemSet(&headerName,0u,sizeof(headerName));
        file->readBin((edk::uint8*)&headerName,sizeof(VIDEO_EDK_HEADER_NAME));
        printf("\nheaderName == '%s'",headerName);fflush(stdout);
        if(edk::String::strCompare(headerName,VIDEO_EDK_HEADER_NAME)){
            if(file->readBin((edk::uint8*)&this->headerEDK,sizeof(this->headerEDK))){
                printf("\nFPS == %.2f TimeIncrement == %.2f",this->headerEDK.fps,this->headerEDK.timeIncrement);fflush(stdout);
                return true;
            }
        }
    }
    return false;
}
//start the encoder
bool edk::video::VideoEDK::startEncoder(edk::uint32 width,edk::uint32 height,edk::uint32 /*channels*/,edk::float32 fps){
    return this->enc.startEncoder(width,height,(edk::uint32)fps);
}
//encode a frame
bool edk::video::VideoEDK::encodeFrame(edk::uint8* vector,
                                       edk::uint64 lenght,
                                       edk::uint8 channels,
                                       edk::MemoryBuffer<edk::uint8>* bufferWrite,
                                       bool keyFrame
                                       ){
    if(vector && lenght && channels && bufferWrite){
        //encode the frame
        if(keyFrame){
            this->enc.setNextKeyframe();
        }
        if(this->enc.encode(vector,channels)){
            //read the encoded
            return bufferWrite->pushToBuffer(this->enc.getEncoded(),this->enc.getEncodedUsedSize());
        }
    }
    return false;
}
//finish the encoder
void edk::video::VideoEDK::finishEncoder(){
    this->enc.finishEncoder();
}
//start the decoder
bool edk::video::VideoEDK::startDecoder(){
    return this->dec.startDecoder(1024u*1024u*3u);
}
//decode a frame
bool edk::video::VideoEDK::decodeFrame(edk::MemoryBuffer<edk::uint8>* bufferRead,
                                       edk::uint32* width,
                                       edk::uint32* height,
                                       edk::uint8* channels
                                       ){
    if(bufferRead && width && height && channels){
        //
        if(this->dec.decode((edk::uint8*)bufferRead->getPointer(),bufferRead->size())){
            *width = this->dec.getFrameWidth();
            *height = this->dec.getFrameHeight();
            *channels = this->dec.getFrameChannels();
            if(*width && *height && *channels){
                return true;
            }
        }
    }
    return false;
}
//decode a frame
bool edk::video::VideoEDK::copyDecodedFrame(edk::MemoryBuffer<edk::uint8>* bufferDest){
    if(bufferDest){
        if(this->dec.getFrame()
                && this->dec.getFrameWidth()
                && this->dec.getFrameHeight()
                && this->dec.getFrameChannels()
                ){
            return bufferDest->pushToBuffer(this->dec.getFrame(),
                                            this->dec.getFrameWidth()
                                            * this->dec.getFrameHeight()
                                            * this->dec.getFrameChannels()
                                            );
        }
    }
    return false;
}
//finish the decoder
void edk::video::VideoEDK::finishDecoder(){
    this->dec.finishDecoder();
}

void edk::video::VideoEDK::Constructor(bool runFather){
    if(runFather){
        edk::Video::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->headerEDK.fps = 0.f;
        this->headerEDK.timeIncrement = 0.f;
        this->size=0u;
        this->enc.Constructor();
        this->dec.Constructor();
    }
}
