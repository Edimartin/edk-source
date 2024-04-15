#ifndef ENCODERIMAGE_H
#define ENCODERIMAGE_H

/*
Library C++ codecs - Set the parameters use for the image encoder
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
#pragma message "Inside EncoderImage"
#endif

#pragma once
#include "CodecImage.h"
#include "../File.h"

#ifdef printMessages
#pragma message "    Compiling EncoderImage"
#endif

namespace edk{
namespace codecs{
class EncoderImage : protected edk::codecs::CodecImage{
public:
    EncoderImage();
    virtual ~EncoderImage();

    void Constructor(bool runFather=true);

    //process the encoder
    virtual bool encode(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality);
    virtual bool encode(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality);
    virtual bool encode(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality);
    virtual bool encode(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality);

    //process the encoder and save to a file
    bool encodeToFile(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName);
    bool encodeToFile(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName);
    bool encodeToFile(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName);
    bool encodeToFile(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName);
    bool encodeToFile(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName);
    bool encodeToFile(const unsigned char* frame,edk::size2ui32 size,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName);
    bool encodeToFile(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,const edk::char8* fileName);
    bool encodeToFile(const unsigned char* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 quality,edk::char8* fileName);

    //return the frame encoded
    edk::uint8* getEncoded();
    edk::uint32 getEncodedSize();
    //delete the encoded
    virtual void deleteEncoded();
protected:
private:
    //file manipulator
    edk::File file;
private:
    edk::classID classThis;
};
}//end namespace codecs
}//end namespace edk

#endif // ENCODERIMAGE_H
