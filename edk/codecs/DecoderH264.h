#ifndef DECODERH264_H
#define DECODERH264_H

/*
Library C++ DecoderH264 - Decode a frame to H264
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

    //return true if have load the encoder
    bool haveInitialized();
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
