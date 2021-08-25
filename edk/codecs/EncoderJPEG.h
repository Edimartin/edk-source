#ifndef ENCODERJPEG_H
#define ENCODERJPEG_H

/*
Library C++ EncoderJPEG - Encode a frame to a JPEG stream or file
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
#warning "Inside EncoderJPEG"
#endif

#pragma once
#include "EncoderImage.h"
//Use JPEGlib
#include "../../jpeglib/jpeglib.h"

#ifdef printMessages
#warning "    Compiling EncoderJPEG"
#endif

namespace edk{
namespace codecs{
class EncoderJPEG : public edk::codecs::EncoderImage{
    public:
        EncoderJPEG();
        virtual ~EncoderJPEG();

        //process the encoder
        bool encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality);
        bool encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality);
        //delete the encoded
        void deleteEncoded();
    protected:
    private:
        //Process the libJpeg Encoder
        jpeg_compress_struct cinfo;
        jpeg_error_mgr jerr;
};
}//end namespace codecs
}//end namespace edk

#endif // ENCODERJPEG_H
