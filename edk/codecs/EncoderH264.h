#ifndef ENCODERH264_H
#define ENCODERH264_H

/*
Library C++ EncoderH264 - Encode a frame to H264
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
#pragma message "Inside EncoderH264"
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
#pragma message "    Compiling EncoderH264"
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
