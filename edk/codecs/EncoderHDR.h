#ifndef ENCODERHDR_H
#define ENCODERHDR_H

/*
Library C++ EncoderHDR - Encode a frame to a HDRi stream or file
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
#pragma message "Inside EncoderHDR"
#endif

#pragma once
#include "EncoderImage.h"
//Add the stb to encode the JPEG
#include "../../stb/stb_image_write.h"
#include "../vector/Stack.h"

#ifdef printMessages
#pragma message "    Compiling EncoderHDR"
#endif

namespace edk{
namespace codecs{
class EncoderHDR : public edk::codecs::EncoderImage{
public:
    EncoderHDR();
    ~EncoderHDR();

    void Constructor();
    void Destructor();

    static void hdr_write_func(void *context, void *data, int size);

    //process the encoder
    bool encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality);
    bool encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality);
    //delete the encoded
    void deleteEncoded();
    //get the channel size
    virtual inline edk::uint8 getChannelByteSize(){
        return sizeof(edk::float32);
    }
private:
    edk::vector::Stack<edk::uint8> stack;
    //Functions to write the data
    void startWriteData();
    void writeData(void *data, edk::uint32 size);
    bool endWriteData();
private:
    edk::classID classThis;
};
}//end namespace codecs
}//end namespace edk


#endif // ENCODERHDR_H
