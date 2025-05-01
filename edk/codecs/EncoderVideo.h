#ifndef ENCODERVIDEO_H
#define ENCODERVIDEO_H

/*
Library C++ codecs - Set the parameters use for the video encoder
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
#pragma message "Inside EncoderVideo"
#endif

#pragma once
#include "CodecVideo.h"

#ifdef printMessages
#pragma message "    Compiling EncoderVideo"
#endif

namespace edk{
namespace codecs{
class EncoderVideo : protected edk::codecs::CodecVideo{
public:
    EncoderVideo();
    virtual ~EncoderVideo();

    void Constructor();
    void Destructor();

    //start the encoder
    virtual bool startEncoder(edk::size2ui32 size, edk::uint32 fps);
    virtual bool startEncoder(edk::uint32 width, edk::uint32 height, edk::uint32 fps);

    //alloc a new frameEncoded
    bool newSpaceEncoded(edk::uint32 size);
    //delete the encoded
    void deleteSpaceEncoded();

    //set next keyFrame
    void setNextKeyframe();

    //process the encoder
    virtual bool encode(edk::uint8* frame,edk::uint8 channels);
    virtual bool encode(const unsigned char* frame,edk::uint8 channels);

    //return the frame encoded
    edk::uint8* getEncoded();
    edk::uint32 getSpaceEncodedSize();
    edk::uint32 getEncodedUsedSize();

    //finish the encoder
    virtual void finishEncoder();
private:
    edk::classID classThis;
};
}//end namespace codecs
}//end namescace edk

#endif // ENCODERVIDEO_H
