#ifndef EncoderPNG_H
#define EncoderPNG_H

/*
Library C++ EncoderPNG - Encode a frame to a JPEG stream or file
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
#pragma message "Inside EncoderPNG"
#endif

#pragma once
#include "EncoderImage.h"
//Add the stb to encode the JPEG
#include "../../stb/stb_image_write.h"
#include "../../stb/stb_image.h" //add the stb image to use the STBI_FREE

#ifdef printMessages
#pragma message "    Compiling EncoderPNG"
#endif

namespace edk{
namespace codecs{
class EncoderPNG : public edk::codecs::EncoderImage{
public:
    EncoderPNG();
    virtual ~EncoderPNG();

    void Constructor();
    void Destructor();

    //process the encoder
    bool encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32);
    bool encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality);
    //delete the encoded
    void deleteEncoded();
protected:
private:
    edk::classID classThis;
};
}//end namespace codecs
}//end namespace edk

#endif // EncoderPNG_H
