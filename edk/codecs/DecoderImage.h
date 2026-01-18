#ifndef DECODERIMAGE_H
#define DECODERIMAGE_H

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
#pragma message "Inside DecoderImage"
#endif

#pragma once
#include "CodecImage.h"
#include "../File.h"

#ifdef printMessages
#pragma message "    Compiling DecoderImage"
#endif

namespace edk{
namespace codecs{
class DecoderImage : protected edk::codecs::CodecImage{
public:
    DecoderImage();
    virtual ~DecoderImage();

    void Constructor();
    void Destructor();

    //process the decoder
    virtual bool decode(edk::uint8* encoded,edk::uint32 size);
    virtual bool decode(const unsigned char* encoded,edk::uint32 size);

    //decode from file
    bool decodeFromFile(const edk::char8* fileName);
    bool decodeFromFile(edk::char8* fileName);

    //Return the frame
    edk::uint8* getFrame();
    edk::size2ui32 getFrameSize();
    edk::uint32 getFrameWidth();
    edk::uint32 getFrameHeight();
    edk::uint32 getFrameChannels();
    //delete the frame
    virtual void deleteFrame();
    //clean the frame
    edk::uint8* cleanFrame();
    //get the channel size
    virtual inline edk::uint8 getChannelByteSize(){
        return sizeof(edk::float32);
    }
protected:
    edk::File file;
private:
    edk::classID classThis;
};
}//end namespace codecs
}//end namespace edk

#endif // DECODERIMAGE_H
