#ifndef CODECIMAGE_H
#define CODECIMAGE_H

/*
Library C++ codecs - Set the parameters use for the image codecs
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "Inside CodecImage"
#endif

#pragma once
#include <string.h>
#include "../TypeVars.h"
#include "../TypeSize2.h"
#include "../TypeColor.h"

#include <stdio.h>

#ifdef printMessages
#warning "    Compiling CodecImage"
#endif

namespace edk{
namespace codecs{
class CodecImage{
public:
    CodecImage();
    virtual ~CodecImage();
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
    //vector
    static bool rgbToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest);
    static edk::uint8* rgbToV(edk::uint8* vector,edk::size2ui32 size);
    static bool rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest);
    static edk::uint8* rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height);
    static bool rgbaToV(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest);
    static edk::uint8* rgbaToV(edk::uint8* vector,edk::size2ui32 size);
    static bool rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest);
    static edk::uint8* rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height);
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
    static bool rgbToi240(edk::uint8* rgb,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v);
    static bool grayToi240(edk::uint8* gray,edk::size2ui32 size,edk::uint8* y,edk::uint8* u,edk::uint8* v);
    //YUV to RGB
    static edk::color3ui8 yuvTorgb(edk::uint8 y,edk::uint8 u,edk::uint8 v);
    static edk::color3ui8 yuvTorgb(edk::vec3ui8 color);
    static bool i240Torgb(edk::uint8* y,edk::uint8* u,edk::uint8* v,edk::size2ui32 size,edk::uint8* rgb);
protected:
    //save the size of the frame
    edk::size2ui32 frameSize;
private:
    //image vector to encode
    edk::uint8* frame;
    edk::uint32 vectorFrameSize;
    //save the type of the frame
    edk::float32 frameChannels;
    //save the frame encoded
    edk::uint8* encoded;
    //size of the frame encoded
    edk::uint32 encodedSize;
    //save the quality of the frame encoded
    edk::uint32 encodedQuality;
};
}//end namespace codecs
}//end namespace edk
#endif // CODECIMAGE_H
