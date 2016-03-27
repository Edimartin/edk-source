#include "DecoderVideo.h"

/*
Library C++ codecs - Set the parameters use for the video decoder
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
#warning "            Inside DecoderVideo.cpp"
#endif

edk::codecs::DecoderVideo::DecoderVideo(){
    //
}
edk::codecs::DecoderVideo::~DecoderVideo(){
    this->finishDecoder();
}

//start the encoder
bool edk::codecs::DecoderVideo::startDecoder(edk::uint32 spaceDecodeSize){
    //test the deconderSize
    if(spaceDecodeSize){
        //create the space decode size
        return edk::codecs::CodecVideo::newSpaceEncoded(spaceDecodeSize);
    }
    return false;
}

//alloc a new frameEncoded
bool edk::codecs::DecoderVideo::newSpaceEncoded(edk::uint32 size){
    return edk::codecs::CodecVideo::newSpaceEncoded(size);
}
//delete the encoded
void edk::codecs::DecoderVideo::deleteSpaceEncoded(){
    edk::codecs::CodecVideo::deleteSpaceEncoded();
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
    return this->decode((edk::uint8*) encoded,size);
}

//Return the frame
edk::uint8* edk::codecs::DecoderVideo::getFrame(){
    return edk::codecs::CodecVideo::getFrame();
}
edk::size2ui32 edk::codecs::DecoderVideo::getFrameSize(){
    return edk::codecs::CodecVideo::getFrameSize();
}
edk::uint32 edk::codecs::DecoderVideo::getFrameWidth(){
    return edk::codecs::CodecVideo::getFrameWidth();
}
edk::uint32 edk::codecs::DecoderVideo::getFrameHeight(){
    return edk::codecs::CodecVideo::getFrameHeight();
}
edk::uint32 edk::codecs::DecoderVideo::getFrameChannels(){
    return edk::codecs::CodecVideo::getFrameChannels();
}
edk::uint32 edk::codecs::DecoderVideo::getFrameVectorSize(){
    return edk::codecs::CodecVideo::getFrameVectorSize();
}
//delete the frame
void edk::codecs::DecoderVideo::deleteFrame(){
    edk::codecs::CodecVideo::deleteFrame();
}
//clean the frame
edk::uint8* edk::codecs::DecoderVideo::cleanFrame(){
    return edk::codecs::CodecVideo::cleanFrame();
}

//finish the encoder
void edk::codecs::DecoderVideo::finishDecoder(){
    edk::codecs::CodecVideo::deleteFrame();
    edk::codecs::CodecVideo::deleteSpaceEncoded();
}
