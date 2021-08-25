#ifndef DECODERVIDEO_H
#define DECODERVIDEO_H

/*
Library C++ codecs - Set the parameters use for the video decoder
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
#warning "Inside DecoderVideo"
#endif

#pragma once
#include "CodecVideo.h"

#ifdef printMessages
#warning "    Compiling DecoderVideo"
#endif

namespace edk{
namespace codecs{
class DecoderVideo : protected edk::codecs::CodecVideo{
public:
    DecoderVideo();
    virtual ~DecoderVideo();

    //start the encoder
    virtual bool startDecoder(edk::uint32 spaceDecodeSize=0u);

    //alloc a new frameEncoded
    bool newSpaceEncoded(edk::uint32 size);
    //delete the encoded
    void deleteSpaceEncoded();

    //process the decoder
    virtual bool decode(edk::uint8* encoded,edk::uint32 size);
    virtual bool decode(const unsigned char* encoded,edk::uint32 size);

    //Return the frame
    edk::uint8* getFrame();
    edk::size2ui32 getFrameSize();
    edk::uint32 getFrameWidth();
    edk::uint32 getFrameHeight();
    edk::uint32 getFrameChannels();
    edk::uint32 getFrameVectorSize();
    //delete the frame
    void deleteFrame();
    //clean the frame
    edk::uint8* cleanFrame();

    //finish the encoder
    virtual void finishDecoder();
};
}//end namespace codecs
}//end namespace edk

#endif // DECODERVIDEO_H
