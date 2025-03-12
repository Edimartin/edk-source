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
#include "../codecs/DecoderJPEG.h"
#include "../codecs/EncoderJPEG.h"

#ifdef printMessages
#pragma message "    Compiling VideoEDK"
#endif

#define VIDEO_EDK_HEADER_NAME "EDK_VIDEO"

namespace edk{
namespace video{
enum EDKcodecName{
    edkCodecNothing=0x00,
    edkCodecH264,
    edkCodecJPEGvideo,
    edkCodecRGB,

    edkCodecSize
};
class VideoEDK : public edk::Video{
public:
    VideoEDK(edk::video::EDKcodecName codec=edk::video::edkCodecNothing);
    ~VideoEDK();

    void Constructor(edk::video::EDKcodecName codec=edk::video::edkCodecNothing,bool runFather=true);

    //set use a codec
    bool useCodec(edk::video::EDKcodecName codec);
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
        //codecType
        edk::uint8
        /*edk::video::VideoEDK_CODEC*/ codec;
    }headerEDK;
    //size
    edk::size2ui32 size;
    //video codec
    edk::codecs::DecoderH264 decH264;
    edk::codecs::EncoderH264 encH264;
    edk::codecs::DecoderJPEG decJPEG;
    edk::codecs::EncoderJPEG encJPEG;
    bool haveEncNOTHING;
    bool haveDecNOTHING;
    bool haveEncJPEG;
    bool haveDecJPEG;
    bool haveEncH264;
    bool haveDecH264;
    bool haveEncRGB;
    bool haveDecRGB;

    edk::MemoryBuffer<edk::uint8> bufferRGB;

    //remove the last coded
    void removeCodec();

    //CODEC FUNCTIONS
    //H264
    inline bool startEncoderNOTHING(edk::uint32 /*width*/,
                      edk::uint32 /*height*/,
                      edk::uint32 /*channels*/,
                      edk::float32 /*fps*/
                                    ){return false;}
    inline bool encodeFrameNOTHING(edk::uint8* /*vector*/,
                     edk::uint64 /*lenght*/,
                     edk::uint8 /*channels*/,
                     edk::MemoryBuffer<edk::uint8>* /*bufferWrite*/,
                     bool /*keyFrame*/
                     ){return false;}
    inline void finishEncoderNOTHING(){}
    inline bool startDecoderNOTHING(){return false;}
    inline bool decodeFrameNOTHING(edk::MemoryBuffer<edk::uint8>* /*bufferRead*/,
                     edk::uint32* /*width*/,
                     edk::uint32* /*height*/,
                     edk::uint8* /*channels*/
                     ){return false;}
    inline bool copyDecodedFrameNOTHING(edk::MemoryBuffer<edk::uint8>* /*bufferDest*/){return false;}
    inline void finishDecoderNOTHING(){}
    //H264
    bool startEncoderH264(edk::uint32 /*width*/,
                      edk::uint32 /*height*/,
                      edk::uint32 /*channels*/,
                      edk::float32 /*fps*/
                      );
    bool encodeFrameH264(edk::uint8* /*vector*/,
                     edk::uint64 /*lenght*/,
                     edk::uint8 /*channels*/,
                     edk::MemoryBuffer<edk::uint8>* /*bufferWrite*/,
                     bool /*keyFrame*/
                     );
    void finishEncoderH264();
    bool startDecoderH264();
    bool decodeFrameH264(edk::MemoryBuffer<edk::uint8>* /*bufferRead*/,
                     edk::uint32* /*width*/,
                     edk::uint32* /*height*/,
                     edk::uint8* /*channels*/
                     );
    bool copyDecodedFrameH264(edk::MemoryBuffer<edk::uint8>* /*bufferDest*/);
    void finishDecoderH264();
    //JPEG
    bool startEncoderJPEG(edk::uint32 /*width*/,
                      edk::uint32 /*height*/,
                      edk::uint32 /*channels*/,
                      edk::float32 /*fps*/
                      );
    bool encodeFrameJPEG(edk::uint8* /*vector*/,
                     edk::uint64 /*lenght*/,
                     edk::uint8 /*channels*/,
                     edk::MemoryBuffer<edk::uint8>* /*bufferWrite*/,
                     bool /*keyFrame*/
                     );
    void finishEncoderJPEG();
    bool startDecoderJPEG();
    bool decodeFrameJPEG(edk::MemoryBuffer<edk::uint8>* /*bufferRead*/,
                     edk::uint32* /*width*/,
                     edk::uint32* /*height*/,
                     edk::uint8* /*channels*/
                     );
    bool copyDecodedFrameJPEG(edk::MemoryBuffer<edk::uint8>* /*bufferDest*/);
    void finishDecoderJPEG();
    //RGB
    bool startEncoderRGB(edk::uint32 /*width*/,
                      edk::uint32 /*height*/,
                      edk::uint32 /*channels*/,
                      edk::float32 /*fps*/
                      );
    bool encodeFrameRGB(edk::uint8* /*vector*/,
                     edk::uint64 /*lenght*/,
                     edk::uint8 /*channels*/,
                     edk::MemoryBuffer<edk::uint8>* /*bufferWrite*/,
                     bool /*keyFrame*/
                     );
    void finishEncoderRGB();
    bool startDecoderRGB();
    bool decodeFrameRGB(edk::MemoryBuffer<edk::uint8>* /*bufferRead*/,
                     edk::uint32* /*width*/,
                     edk::uint32* /*height*/,
                     edk::uint8* /*channels*/
                     );
    bool copyDecodedFrameRGB(edk::MemoryBuffer<edk::uint8>* /*bufferDest*/);
    void finishDecoderRGB();

    //pointer functions
    bool (edk::video::VideoEDK::*functionStartEncoder)(edk::uint32 width,
                                                       edk::uint32 height,
                                                       edk::uint32 channels,
                                                       edk::float32 fps
                                                       );
    bool (edk::video::VideoEDK::*functionEncodeFrame)(edk::uint8* vector,
                                                      edk::uint64 lenght,
                                                      edk::uint8 channels,
                                                      edk::MemoryBuffer<edk::uint8>* bufferWrite,
                                                      bool keyFrame
                                                      );
    void (edk::video::VideoEDK::*functionFinishEncoder)();
    bool (edk::video::VideoEDK::*functionStartDecoder)();
    bool (edk::video::VideoEDK::*functionDecodeFrame)(edk::MemoryBuffer<edk::uint8>* bufferRead,
                                                      edk::uint32* width,
                                                      edk::uint32* height,
                                                      edk::uint8* channels
                                                      );
    bool (edk::video::VideoEDK::*functionCopyDecodedFrame)(edk::MemoryBuffer<edk::uint8>* bufferDest);
    void (edk::video::VideoEDK::*functionFinishDecoder)();

    bool* haveEnc;
    bool* haveDec;
private:
    edk::classID classThis;
};
}
}

#endif // VIDEOEDK_H
