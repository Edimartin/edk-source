#ifndef VIDEOEDK_H
#define VIDEOEDK_H

/*
Library VideoEDK - Play video using openH264
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
#pragma message "Inside VideoEDK"
#endif

#pragma once
#include "Video.h"
#include "../codecs/DecoderH264.h"
#include "../codecs/EncoderH264.h"

#ifdef printMessages
#pragma message "    Compiling VideoEDK"
#endif

#define VIDEO_EDK_HEADER_NAME "EDK_VIDEO"

namespace edk{
namespace video{
enum VideoEDK_CODEC{
    VideoEDK_codecNothing=0u,
    VideoEDK_h264,

    VideoEDK_codecSize
};
class VideoEDK : public edk::Video{
public:
    VideoEDK();
    ~VideoEDK();

    void Constructor(bool runFather=true);
protected:
    virtual void writeHeader(edk::File* file);
    virtual bool readHeader(edk::File*  file);
    //start the encoder
    virtual bool startEncoder(edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::float32 fps);
    //encode a frame
    virtual bool encodeFrame(edk::uint8* vector,
                             edk::uint64 lenght,
                             edk::uint8 channels,
                             edk::MemoryBuffer<edk::uint8>* bufferWrite,
                             bool keyFrame
                             );
    //finish the encoder
    virtual void finishEncoder();
    //start the decoder
    virtual bool startDecoder();
    //decode a frame
    virtual bool decodeFrame(edk::MemoryBuffer<edk::uint8>* bufferRead,
                             edk::uint32* width,
                             edk::uint32* height,
                             edk::uint8* channels
                             );
    //decode a frame
    virtual bool copyDecodedFrame(edk::MemoryBuffer<edk::uint8>* bufferDest);
    //finish the decoder
    virtual void finishDecoder();
private:
    struct SaveLevel{
        edk::float32 fps;
        edk::float32 timeIncrement;
    }headerEDK;
    //size
    edk::size2ui32 size;
    //video codec
    edk::codecs::DecoderH264 dec;
    edk::codecs::EncoderH264 enc;
private:
    edk::classID classThis;
};
}
}

#endif // VIDEOEDK_H
