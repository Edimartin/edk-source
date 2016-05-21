#ifndef ENCODERH264_H
#define ENCODERH264_H

/*
Library C++ EncoderH264 - Encode a frame to H264
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
#warning "Inside EncoderH264"
#endif

#pragma once
#include "EncoderVideo.h"
#include "../TypeDefines.h"
#ifdef EDK_USE_OPENH264
//openH264
#include "openh264/codec_api.h"
#include "openh264/macros.h"
#include "openh264/memory_align.h"
#include "openh264/wels_common_defs.h"
#endif
#include <stdlib.h>

#ifdef printMessages
#warning "    Compiling EncoderH264"
#endif

namespace edk{
namespace codecs{
class EncoderH264: public edk::codecs::EncoderVideo{
public:
    EncoderH264();
    virtual ~EncoderH264();

    //start the encoder
    bool startEncoder(edk::size2ui32 size, edk::uint32 fps);

    //process the encoder
    bool encode(edk::uint8* frame,edk::uint8 channels);

    //finish the encoder
    void finishEncoder();

    //return true if have load the encoder
    bool haveInitialized();
private:
#ifdef EDK_USE_OPENH264
    ISVCEncoder* encoder=NULL;
    //openH264 version
    OpenH264Version version;
    //parameters
    SEncParamBase param;

    //encode image
    Source_Picture_s pic;
    //return parameters
    SFrameBSInfo sFbi;
#endif
};
}//end namespace codecs
}//end namespace edk

#endif // ENCODERH264_H
