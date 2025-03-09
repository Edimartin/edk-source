#ifndef CODECVIDEO_H
#define CODECVIDEO_H

/*
Library C++ codecs - Set the parameters use for the video codecs
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
#pragma message "Inside CodecVideo"
#endif

#pragma once
#include "CodecImage.h"

#ifdef printMessages
#pragma message "    Compiling CodecVideo"
#endif

namespace edk{
namespace codecs{
class CodecVideo : private edk::codecs::CodecImage{
public:
    CodecVideo();
    virtual ~CodecVideo();

    void Constructor(bool runFather=true);
protected:
    //create a new frame
    bool newFrame(edk::size2ui32 size,edk::uint8 channels);
    bool newFrame(edk::uint32 width,edk::uint32 height,edk::uint8 channels);
    //create a new frame
    bool newFrameYUV(edk::size2ui32 size);
    bool newFrameYUV(edk::uint32 width,edk::uint32 height);
    //delete the frame
    void deleteFrame();
    //alloc a new frameEncoded
    bool newSpaceEncoded(edk::uint32 size);
    //delete the encoded
    void deleteSpaceEncoded();

    //draw an image in the frame
    bool drawFrame(edk::uint8* frame,edk::uint8 channels);

    //write in the frame encoded
    bool writeEncoded(edk::uint8* frame,edk::uint32 size);
    bool appendEncoded(edk::uint8* frame,edk::uint32 size);

    //set the quality
    bool setQuality(edk::uint32 quality);
    //set the next is keyFrame
    void setNextKeyframe();
    //return true if the next is keyframe
    bool isNextKeyframe();

    //get the frames
    edk::uint8* getFrame();
    edk::uint8* getEncoded();
    edk::uint8** getEncodedPosition();
    edk::uint8* getFrameY();
    edk::uint8* getFrameU();
    edk::uint8* getFrameV();

    //clean the pointers
    edk::uint8* cleanFrame();
    bool cleanYUV(edk::uint8** Y,edk::uint8** U,edk::uint8** V);
    edk::uint8* cleanEncoded();

    //return the size of the frame
    edk::size2ui32 getFrameSize();
    edk::uint32 getFrameWidth();
    edk::uint32 getFrameHeight();
    edk::uint32 getFrameChannels();
    edk::uint32 getFrameVectorSize();
    edk::uint32 getFrameYSize();
    edk::uint32 getFrameUSize();
    edk::uint32 getFrameVSize();
    //return the size of the encoded
    edk::uint32 getSpaceEncodedSize();
    edk::uint32 getEncodedUsedSize();
    edk::uint32 getQuality();
private:
    //YUV channels
    edk::uint8 *Y, *U, *V;
    edk::uint32 sizeY;
    edk::uint32 sizeU;
    edk::uint32 sizeV;
    //set the next keyFrame
    bool nexKeyframe;
    //frame encoded size
    edk::uint32 usingEncodedSize;
private:
    edk::classID classThis;
};
}//end namespace codecs
}//end namespace edk

#endif // CODECVIDEO_H
