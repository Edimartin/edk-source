#include "EncoderVideo.h"

/*
Library C++ codecs - Set the parameters use for the video encoder
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

#ifdef printMessages
#pragma message "            Inside EncoderVideo.cpp"
#endif

edk::codecs::EncoderVideo::EncoderVideo(){
    this->classThis=NULL;
    this->Constructor();
}
edk::codecs::EncoderVideo::~EncoderVideo(){
    this->Destructor();
}

void edk::codecs::EncoderVideo::Constructor(){
    edk::codecs::CodecVideo::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::codecs::EncoderVideo::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->finishEncoder();
    }
    edk::codecs::CodecVideo::Destructor();
}

//start the encoder
bool edk::codecs::EncoderVideo::startEncoder(edk::size2ui32 size,edk::uint32 fps){
    if(size.width && size.height && fps){
        //create the frame
        return this->newFrameYUV(size);
    }
    return false;
}
bool edk::codecs::EncoderVideo::startEncoder(edk::uint32 width, edk::uint32 height, edk::uint32 fps){
    return this->startEncoder(edk::size2ui32(width,height),fps);
}

//alloc a new frameEncoded
bool edk::codecs::EncoderVideo::newSpaceEncoded(edk::uint32 size){
    return edk::codecs::CodecVideo::newSpaceEncoded(size);
}
//delete the encoded
void edk::codecs::EncoderVideo::deleteSpaceEncoded(){
    edk::codecs::CodecVideo::deleteSpaceEncoded();
}

//set next keyFrame
void edk::codecs::EncoderVideo::setNextKeyframe(){
    edk::codecs::CodecVideo::setNextKeyframe();
}

//process the encoder
bool edk::codecs::EncoderVideo::encode(edk::uint8* frame,edk::uint8 channels){
    //test the frame and the size
    if(frame  && channels){
        return true;
    }
    return false;
}
bool edk::codecs::EncoderVideo::encode(const unsigned char* frame,edk::uint8 channels){
    return this->encode((edk::uint8*)frame,channels);
}

//return the frame encoded
edk::uint8* edk::codecs::EncoderVideo::getEncoded(){
    return edk::codecs::CodecVideo::getEncoded();
}
edk::uint32 edk::codecs::EncoderVideo::getSpaceEncodedSize(){
    return edk::codecs::CodecVideo::getSpaceEncodedSize();
}
edk::uint32 edk::codecs::EncoderVideo::getEncodedUsedSize(){
    return edk::codecs::CodecVideo::getEncodedUsedSize();
}

//finish the encoder
void edk::codecs::EncoderVideo::finishEncoder(){
    this->deleteFrame();
}

