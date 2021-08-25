#ifndef EDK_IMAGE2D_h
#define EDK_IMAGE2D_h

/*
Library Image2D - Load a 2D Image using SFML
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

/*LIBS WINDOWS LINUX MAC

-lsfml-graphics

*/

#ifdef printMessages
#warning "Inside Image2D"
#endif

#pragma once
//#include "Types.h"
#include "TypeColor.h"
#include "TypeDefines.h"
#include <SFML/Graphics.hpp>
#include "File.h"
#include "String.h"
#include "codecs/DecoderJPEG.h"
#include "codecs/EncoderJPEG.h"

#ifdef printMessages
#warning "    Compiling Image2D"
#endif

/*
//CODECS
EDK_CODEC_NO
EDK_CODEC_JPEG
EDK_CODEC_PNG
*/


namespace edk {

class Image2D {

public:

    Image2D();

    Image2D(char8 *imageFileName);

    Image2D(const char *imageFileName);

    ~Image2D();

    //create a new Image
    bool newImage(edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels);
    bool newImage(edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels);
    bool newImage(const char *imageName,edk::size2ui32 size,edk::uint8 channels);
    bool newImage(const char *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels);

    bool loadFromFile(char8 *imageFileName);

    bool loadFromFile(const char *imageFileName);

    bool loadFromFileToRGBA(char8 *imageFileName);

    bool loadFromFileToRGBA(const char *imageFileName);

    bool loadFromMemory(uint8 *image, edk::uint32 vecSize);

    bool loadFromMemoryToRGBA(uint8 *image, edk::uint32 vecSize);

    //save the image
    bool saveToFile(edk::char8 *fileName = NULL);
    bool saveToFile(const char *fileName);

    bool setName(char8 *imageName);

    bool setName(const char *imageName);

    //draw on the image
    bool draw(edk::uint8* pixels);

    size2ui32 getSize();

    uint32 getWidth();

    uint32 getHeight();

    uint32 width();

    uint32 height();
    //return the channels of the image
    edk::uint8 getChannels();

    bool haveImage();

    bool haveName();

    bool haveFileName();

    char8* getName();

    char8* name();

    char8* getFileName();

    char8* fileName();

    //return the pixels of the image to use in videoBoard
    edk::uint8* getPixels();

    void deleteImage();

    void deleteName();

    //process the flip image in Y
    bool flipImageY();

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
    //RGB to RGBA
    static edk::color4ui8 rgbTorgba(edk::uint8 r,edk::uint8 g,edk::uint8 b);
    static edk::color4ui8 rgbTorgba(edk::color3ui8 rgb);
    static edk::color4f32 rgbTorgba(edk::float32 r,edk::float32 g,edk::float32 b);
    static edk::color4f32 rgbTorgba(edk::color3f32 rgb);
    //vector
    static bool rgbTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest);
    static edk::uint8* rgbTorgba(edk::uint8* vector,edk::size2ui32 size);
    static bool rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest);
    static edk::uint8* rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height);
    //LA to RGBA
    static edk::color4ui8 laTorgba(edk::uint8 l,edk::uint8 a);
    static edk::color4f32 laTorgba(edk::float32 l,edk::float32 a);
    //vector
    static bool laTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest);
    static edk::uint8* laTorgba(edk::uint8* vector,edk::size2ui32 size);
    static bool laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest);
    static edk::uint8* laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height);
    //L to RGBA
    static edk::color4ui8 lTorgba(edk::uint8 l);
    static edk::color4f32 lTorgba(edk::float32 l);
    //vector
    static bool lTorgba(edk::uint8* vector,edk::size2ui32 size,edk::uint8* dest);
    static edk::uint8* lTorgba(edk::uint8* vector,edk::size2ui32 size);
    static bool lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* dest);
    static edk::uint8* lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height);

    //flip pixels
    static bool flipY(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 channels);

    static bool imageClone(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 channels,
                           edk::uint8* dest,edk::uint32 dWidth,edk::uint32 dHeight,edk::uint32 dChannels,
                           edk::uint32 positionX,edk::uint32 positionY
                           );

    bool cloneFrom(edk::Image2D* image);
    bool newFrom(edk::Image2D* image);
private:
    edk::Image2D operator=(edk::Image2D){return *this;}
    //Save the image
    //sf::Image* image;
    //image vector
    edk::uint8* vec;
    //channels of the image
    edk::uint8 channels;
    //Size of the image
    edk::size2ui32 size;
    //imageName of the image
    edk::char8* imageName;
    //imageName of the file
    edk::char8* imageFileName;

    //imageFileNameFunctions
    void setFileName(edk::char8* imageFileName);
    void setFileName(const edk::char8* imageFileName);
    void deleteFileName();
    //discover the imageType
    edk::uint8 getStreamType(edk::uint8* encoded);
    //discover the nameType
    edk::uint8 getNameType(edk::char8* name);
};

} /* End of namespace edk */

#endif // edk_Image2D_h
