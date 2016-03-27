#ifndef DECODERVIDEO_H
#define DECODERVIDEO_H

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
#warning "Inside DecoderVideo"
#endif

#pragma once
#include "CodecVideo.h"

#ifdef printMessages
#warning "    Compiling DecoderVideo"
#endif

namespace edk{
namespace codecs{
class DecoderVideo : protected edk::codecs::CodecVideo{
public:
    DecoderVideo();
    virtual ~DecoderVideo();

    //start the encoder
    virtual bool startDecoder(edk::uint32 spaceDecodeSize=0u);

    //alloc a new frameEncoded
    bool newSpaceEncoded(edk::uint32 size);
    //delete the encoded
    void deleteSpaceEncoded();

    //process the decoder
    virtual bool decode(edk::uint8* encoded,edk::uint32 size);
    virtual bool decode(const unsigned char* encoded,edk::uint32 size);

    //Return the frame
    edk::uint8* getFrame();
    edk::size2ui32 getFrameSize();
    edk::uint32 getFrameWidth();
    edk::uint32 getFrameHeight();
    edk::uint32 getFrameChannels();
    edk::uint32 getFrameVectorSize();
    //delete the frame
    void deleteFrame();
    //clean the frame
    edk::uint8* cleanFrame();

    //finish the encoder
    virtual void finishDecoder();
};
}//end namespace codecs
}//end namespace edk

#endif // DECODERVIDEO_H
