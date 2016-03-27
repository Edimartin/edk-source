#include "EncoderVideo.h"

/*
Library C++ codecs - Set the parameters use for the video encoder
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "            Inside EncoderVideo.cpp"
#endif

edk::codecs::EncoderVideo::EncoderVideo(){
    //
}
edk::codecs::EncoderVideo::~EncoderVideo(){
    //
    this->finishEncoder();
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
void edk::codecs::EncoderVideo::setNextkeyframe(){
    edk::codecs::CodecVideo::setNextkeyframe();
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

