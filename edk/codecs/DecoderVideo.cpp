#include "DecoderVideo.h"

/*
Library C++ codecs - Set the parameters use for the video decoder
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
#pragma message "            Inside DecoderVideo.cpp"
#endif

edk::codecs::DecoderVideo::DecoderVideo(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::codecs::DecoderVideo::~DecoderVideo(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->finishDecoder();edkEnd();
    }
}

void edk::codecs::DecoderVideo::Constructor(bool runFather){
    if(runFather){
        edk::codecs::CodecVideo::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
    }
}

//start the encoder
bool edk::codecs::DecoderVideo::startDecoder(edk::uint32 spaceDecodeSize){
    //test the deconderSize
    if(spaceDecodeSize){
        //create the space decode size
        return edk::codecs::CodecVideo::newSpaceEncoded(spaceDecodeSize);edkEnd();
    }
    return false;
}

//alloc a new frameEncoded
bool edk::codecs::DecoderVideo::newSpaceEncoded(edk::uint32 size){
    return edk::codecs::CodecVideo::newSpaceEncoded(size);edkEnd();
}
//delete the encoded
void edk::codecs::DecoderVideo::deleteSpaceEncoded(){
    edk::codecs::CodecVideo::deleteSpaceEncoded();edkEnd();
}

//process the decoder
bool edk::codecs::DecoderVideo::decode(edk::uint8* encoded,edk::uint32 size){
    if(encoded&&size){
        //write the decode
        return true;
    }
    return false;
}
bool edk::codecs::DecoderVideo::decode(const unsigned char* encoded,edk::uint32 size){
    return this->decode((edk::uint8*) encoded,size);edkEnd();
}

//Return the frame
edk::uint8* edk::codecs::DecoderVideo::getFrame(){
    return edk::codecs::CodecVideo::getFrame();edkEnd();
}
edk::size2ui32 edk::codecs::DecoderVideo::getFrameSize(){
    return edk::codecs::CodecVideo::getFrameSize();edkEnd();
}
edk::uint32 edk::codecs::DecoderVideo::getFrameWidth(){
    return edk::codecs::CodecVideo::getFrameWidth();edkEnd();
}
edk::uint32 edk::codecs::DecoderVideo::getFrameHeight(){
    return edk::codecs::CodecVideo::getFrameHeight();edkEnd();
}
edk::uint32 edk::codecs::DecoderVideo::getFrameChannels(){
    return edk::codecs::CodecVideo::getFrameChannels();edkEnd();
}
edk::uint32 edk::codecs::DecoderVideo::getFrameVectorSize(){
    return edk::codecs::CodecVideo::getFrameVectorSize();edkEnd();
}
//delete the frame
void edk::codecs::DecoderVideo::deleteFrame(){
    edk::codecs::CodecVideo::deleteFrame();edkEnd();
}
//clean the frame
edk::uint8* edk::codecs::DecoderVideo::cleanFrame(){
    return edk::codecs::CodecVideo::cleanFrame();edkEnd();
}

//finish the encoder
void edk::codecs::DecoderVideo::finishDecoder(){
    edk::codecs::CodecVideo::deleteFrame();edkEnd();
    edk::codecs::CodecVideo::deleteSpaceEncoded();edkEnd();
}
