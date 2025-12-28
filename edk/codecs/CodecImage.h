#ifndef CODECIMAGE_H
#define CODECIMAGE_H

/*
Library C++ codecs - Set the parameters use for the image codecs
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
#pragma message "Inside CodecImage"
#endif

#pragma once
#include <string.h>
#include "../TypeVars.h"
#include "../TypeSize2.h"
#include "../TypeColor.h"
#include "../DebugFile.h"
#include "../Math.h"

#include <stdio.h>

#ifdef printMessages
#pragma message "    Compiling CodecImage"
#endif

namespace edk{
namespace codecs{
class CodecImage{
public:
    CodecImage();
    virtual ~CodecImage();

    void Constructor();
    void Destructor();
protected:
    //create a new frame
    bool newFrame(edk::size2ui32 size,edk::uint8 channels);
    bool newFrame(edk::uint32 width,edk::uint32 height,edk::uint8 channels);
    //delete the frame
    void deleteFrame();
    //alloc a new frameEncoded
    bool newFrameEncoded(edk::uint32 size);
    //delete the encoded
    void deleteEncoded();

    //draw a image in the frame
    bool drawFrame(edk::uint8* frame,edk::size2ui32 size,edk::uint8 channels);
    bool drawFrame(edk::uint8* frame,edk::uint32 width,edk::uint32 height,edk::uint8 channels);

    //write in the frame encoded
    bool writeEncoded(edk::uint8* frame);

    //set the quality
    bool setQuality(edk::uint32 quality);

    //get the frames
    edk::uint8* getFrame();
    edk::uint8* getEncoded();
    edk::uint8** getEncodedPosition();

    //clean the pointers
    edk::uint8* cleanFrame();
    edk::uint8* cleanEncoded();

    //return the size of the frame
    edk::size2ui32 getFrameSize();
    edk::uint32 getFrameWidth();
    edk::uint32 getFrameHeight();
    edk::uint32 getFrameChannels();
    edk::uint32 getFrameVectorSize();
    //return the size of the encoded
    edk::uint32 getEncodedSize();
    edk::uint32* getEncodedSizePosition();
    edk::uint32 getQuality();

public:
    //Convertions
    //https://github.com/ratkins/RGBConverter/blob/master/RGBConverter.cpp
    //RGB to HSV
    static edk::color3f32 rgbTohsv(edk::uint8 r,edk::uint8 g,edk::uint8 b);
    static edk::color3f32 rgbTohsv(edk::color3ui8 rgb);
    static edk::color3f32 rgbTohsv(edk::color4ui8 rgba);
    static edk::uint8 rgbToV(edk::uint8 r,edk::uint8 g,edk::uint8 b);
    static edk::uint8 rgbToV(edk::color3ui8 rgb);
    static edk::uint8 rgbaToV(edk::color4ui8 rgba);
    //RGB to A
    static edk::uint8 rgbToA(edk::uint8 r,edk::uint8 g,edk::uint8 b
                             ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                             );
    static edk::uint8 rgbToA(edk::uint8 r,edk::uint8 g,edk::uint8 b
                             ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                             ,edk::uint8 min,edk::uint8 max
                             );
    static edk::uint8 rgbToA(edk::color3ui8 rgb,edk::color3ui8 compareRGB);
    static edk::uint8 rgbToA(edk::color3ui8 rgb,edk::color3ui8 compareRGB,edk::uint8 min,edk::uint8 max);
    //RGBA to A
    static edk::uint8 rgbaToA(edk::color4ui8 rgba,edk::color3ui8 compareRGB);
    static edk::uint8 rgbaToA(edk::color4ui8 rgba,edk::color3ui8 compareRGB,edk::uint8 min,edk::uint8 max);
    //vector
    static bool rgbToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest);
    static edk::uint8* rgbToV(edk::uint8* vector,edk::size2ui32 size);
    static bool rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest);
    static edk::uint8* rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height);
    static bool rgbaToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest);
    static edk::uint8* rgbaToV(edk::uint8* vector,edk::size2ui32 size);
    static bool rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest);
    static edk::uint8* rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height);
    static bool rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                            ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                            ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                            ,edk::uint8 min,edk::uint8 max
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                            ,edk::color3ui8 compareRGB
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::size2ui32 size
                            ,edk::color3ui8 compareRGB
                            ,edk::uint8 min,edk::uint8 max
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                            ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                            ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                            ,edk::uint8 min,edk::uint8 max
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                            ,edk::color3ui8 compareRGB
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height
                            ,edk::color3ui8 compareRGB
                            ,edk::uint8 min,edk::uint8 max
                            );
    //HSV to RGB
    static edk::color3ui8 hsvTorgb(edk::float32 h,edk::float32 s,edk::float32 v);
    static edk::color3ui8 hsvTorgb(edk::color3f32 hsv);
    //RGB to HSL
    static edk::color3f32 rgbTohsl(edk::uint8 r,edk::uint8 g,edk::uint8 b);
    static edk::color3f32 rgbTohsl(edk::color3ui8 rgb);
    static edk::color3f32 rgbaTohsl(edk::color4ui8 rgba);
    static edk::float32 rgbToL(edk::uint8 r,edk::uint8 g,edk::uint8 b);
    static edk::float32 rgbToL(edk::color3ui8 rgb);
    static edk::float32 rgbaToL(edk::color4ui8 rgba);
    static edk::uint8 rgbToLui8(edk::uint8 r,edk::uint8 g,edk::uint8 b);
    static edk::uint8 rgbToLui8(edk::color3ui8 rgb);
    static edk::uint8 rgbaToLui8(edk::color4ui8 rgba);
    //vector
    static bool rgbToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest);
    static edk::uint8* rgbToLui8(edk::uint8* vector,edk::size2ui32 size);
    static bool rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest);
    static edk::uint8* rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height);
    static bool rgbaToLui8(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest);
    static edk::uint8* rgbaToLui8(edk::uint8* vector,edk::size2ui32 size);
    static bool rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest);
    static edk::uint8* rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height);
    //HSL to RGB
    static edk::color3ui8 hslTorgb(edk::float32 h,edk::float32 s,edk::float32 l);
    static edk::color3ui8 hslTorgb(edk::color3f32 hsl);
    //RGB to YUV
    static edk::vec3ui8 rgbToyuv(edk::uint8 r,edk::uint8 g,edk::uint8 b);
    static edk::vec3ui8 rgbToyuv(edk::color3ui8 color);
    static edk::vec3ui8 grayToyuv(edk::uint8 gray);
    //vector
    static bool rgbToyuv(edk::uint8* rgb,edk::size2ui32 size,edk::uint8* yuv);
    static bool rgbToyuv(edk::uint8* rgb,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v);
    static bool grayToyuv(edk::uint8* gray,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v);
    static bool rgbToi420(edk::uint8* rgb,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v);
    static bool grayToi420(edk::uint8* gray,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v);
    //YUV to RGB
    static edk::color3ui8 yuvTorgb(edk::uint8 y,edk::uint8 u,edk::uint8 v);
    static edk::color3ui8 yuvTorgb(edk::vec3ui8 color);
    static bool i420Torgb(edk::uint8* y,edk::uint8* u,edk::uint8* v,edk::size2ui32 size,edk::uint8* rgb);
    //RGB32toRGB8
    static bool rgb32Torgb8(edk::uint8* rgb32,edk::uint32 size,edk::uint8* rgb8);
    static bool rgb32Torgb8(edk::uint8* rgb32,
                            edk::uint32 size,
                            edk::uint8* rgb8,
                            edk::float32 min,
                            edk::float32 max
                            );
protected:
    //save the size of the frame
    edk::size2ui32 frameSize;

    //get the channel size
    virtual inline edk::uint32 getChannelByteSize(){
        return 1u;
    }
private:
    //image vector to encode
    edk::uint8* frame;
    edk::uint32 vectorFrameSize;
    edk::uint32 vectorFrameFullSize;
    //save the type of the frame
    edk::float32 frameChannels;
    //save the frame encoded
    edk::uint8* encoded;
    //size of the frame encoded
    edk::uint32 encodedSize;
    //save the quality of the frame encoded
    edk::uint32 encodedQuality;
private:
    edk::classID classThis;
};
}//end namespace codecs
}//end namespace edk
#endif // CODECIMAGE_H
