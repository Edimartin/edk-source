#ifndef ENCODERVIDEO_H
#define ENCODERVIDEO_H

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
#warning "Inside EncoderVideo"
#endif

#pragma once
#include "CodecVideo.h"

#ifdef printMessages
#warning "    Compiling EncoderVideo"
#endif

namespace edk{
namespace codecs{
class EncoderVideo : protected edk::codecs::CodecVideo{
public:
    EncoderVideo();
    virtual ~EncoderVideo();

    //start the encoder
    virtual bool startEncoder(edk::size2ui32 size, edk::uint32 fps);
    bool startEncoder(edk::uint32 width, edk::uint32 height, edk::uint32 fps);

    //alloc a new frameEncoded
    bool newSpaceEncoded(edk::uint32 size);
    //delete the encoded
    void deleteSpaceEncoded();

    //set next keyFrame
    void setNextkeyframe();

    //process the encoder
    virtual bool encode(edk::uint8* frame,edk::uint8 channels);
    virtual bool encode(const unsigned char* frame,edk::uint8 channels);

    //return the frame encoded
    edk::uint8* getEncoded();
    edk::uint32 getSpaceEncodedSize();
    edk::uint32 getEncodedUsedSize();

    //finish the encoder
    virtual void finishEncoder();
};
}//end namespace codecs
}//end namescace edk

#endif // ENCODERVIDEO_H
