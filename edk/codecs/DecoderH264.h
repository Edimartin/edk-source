#ifndef DECODERH264_H
#define DECODERH264_H

/*
Library C++ DecoderH264 - Decode a frame to H264
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
#warning "Inside DecoderH264"
#endif

#pragma once
#include "DecoderVideo.h"
#include "../TypeDefines.h"
#ifdef EDK_USE_OPENH264
//openH264
#include "openh264/codec_api.h"
#include "openh264/macros.h"
#include "openh264/memory_align.h"
#include "openh264/wels_common_defs.h"
#include <stdlib.h>
#endif

#ifdef printMessages
#warning "    Compiling DecoderH264"
#endif

namespace edk{
namespace codecs{
class DecoderH264 : public edk::codecs::DecoderVideo{
public:
    DecoderH264();
    virtual ~DecoderH264();

    //start the encoder
    bool startDecoder(edk::uint32 spaceDecodeSize);

    //process the decoder
    bool decode(edk::uint8* encoded,edk::uint32 size);

    //finish the encoder
    void finishDecoder();
private:
#ifdef EDK_USE_OPENH264
    ISVCDecoder * decoder;
    //openH264 version
    OpenH264Version version;
    Source_Picture_s pic;
    SDecodingParam param;
    SBufferInfo m_sBufferInfo;
#endif
    //convert the frame with border
    bool i240TorgbWithBorder(edk::uint8* y,edk::uint8* u,edk::uint8* v,edk::size2ui32 size,edk::uint8* rgb,edk::uint32 border);
};
}//end namespace codecs
}//end namespace edk

#endif // DECODERH264_H
