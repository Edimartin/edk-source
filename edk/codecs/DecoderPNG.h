#ifndef DecoderPNG_H
#define DecoderPNG_H

/*
Library C++ EncoderPNG - Encode a frame to a PNG stream or file
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
#warning "Inside DecoderImage"
#endif

#pragma once
#include "DecoderImage.h"
//Add the stb to decode the JPEG
#include "../../stb/stb_image.h"

#ifdef printMessages
#warning "    Compiling DecoderImage"
#endif

namespace edk{
namespace codecs{
class DecoderPNG : public edk::codecs::DecoderImage{
    public:
        DecoderPNG();
        virtual ~DecoderPNG();

        //process the decoder
        bool decode(edk::uint8* encoded,edk::uint32 size);
        bool decode(const unsigned char* encoded,edk::uint32 size);

        //return the vector size
        edk::uint32 getVectorSize();
    protected:
    private:
};
}//end namespace codecs
}//end namespace edk

#endif // DecoderPNG_H
