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
#pragma message "Inside Image2D"
#endif

#pragma once
//#include "Types.h"
#include "TypeColor.h"
#include "TypeDefines.h"
#include "File.h"
#include "String.h"
#include "codecs/DecoderJPEG.h"
#include "codecs/EncoderJPEG.h"
#include "codecs/DecoderPNG.h"
#include "codecs/EncoderPNG.h"

#ifdef printMessages
#pragma message "    Compiling Image2D"
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

    virtual ~Image2D();

    void Constructor();

    void Constructor(char8 *imageFileName);

    void Constructor(const char *imageFileName);

    void Destructor();

    void clean();

    //create a new Image
    bool newImage(edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels);
    bool newImage(edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels);
    bool newImage(const edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels);
    bool newImage(const edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels);

    //create a new image with a palette
    bool newImage(edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels,edk::uint32 paletteSize);
    bool newImage(edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 paletteSize);
    bool newImage(const edk::char8 *imageName,edk::size2ui32 size,edk::uint8 channels,edk::uint32 paletteSize);
    bool newImage(const edk::char8 *imageName,edk::uint32 width,edk::uint32 height,edk::uint8 channels,edk::uint32 paletteSize);

    bool loadFromFile(char8 *imageFileName);

    bool loadFromFile(const char *imageFileName);

    bool loadFromFileToRGB(char8 *imageFileName);

    bool loadFromFileToRGB(const char *imageFileName);

    bool loadFromFileToRGBA(char8 *imageFileName);

    bool loadFromFileToRGBA(const char *imageFileName);

    bool loadFromMemory(uint8 *image, edk::uint32 vecSize);

    bool loadFromMemoryToRGB(uint8 *image, edk::uint32 vecSize);

    bool loadFromMemoryToRGBA(uint8 *image, edk::uint32 vecSize);

    //function used to generate the pixels from colors palette
    bool generatePixelsFromColors();

    //save the image
    bool saveToFile(edk::char8 *fileName = NULL);
    bool saveToFile(const char *fileName);

    bool setName(char8 *imageName);

    bool setName(const char *imageName);

    //draw on the image
    bool draw(edk::uint8* pixels);
    //clean the image with an color
    bool drawColorPointer(edk::uint8* color,edk::uint8 channels);
    bool drawColor(edk::uint8 r);
    bool drawColor(edk::uint8 r,edk::uint8 g);
    bool drawColor(edk::uint8 r,edk::uint8 g,edk::uint8 b);
    bool drawColor(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
    bool drawColorBlack();
    bool drawColorWhite();
    //draw a color in the image vector
    bool drawPosition(edk::vec2ui32 position,edk::uint8* color);
    bool drawPosition(edk::vec2ui32 position,edk::uint8 g);
    bool drawPosition(edk::vec2ui32 position,edk::uint8 g,edk::uint8 a);
    bool drawPosition(edk::vec2ui32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b);
    bool drawPosition(edk::vec2ui32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
    bool drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8* color);
    bool drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 g);
    bool drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 g,edk::uint8 a);
    bool drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 r,edk::uint8 g,edk::uint8 b);
    bool drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
    bool drawPosition(edk::uint32 position,edk::uint8* color);
    bool drawPosition(edk::uint32 position,edk::uint8 g);
    bool drawPosition(edk::uint32 position,edk::uint8 g,edk::uint8 a);
    bool drawPosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b);
    bool drawPosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
    //draw the colors on the palette. The user need to know the size of the palette multiply by channel size
    bool drawPalette(edk::uint8* colors);
    //draw a color in palette position
    bool drawPalettePosition(edk::uint32 position,edk::uint8* color);
    bool drawPalettePosition(edk::uint32 position,edk::uint8 g);
    bool drawPalettePosition(edk::uint32 position,edk::uint8 g,edk::uint8 a);
    bool drawPalettePosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b);
    bool drawPalettePosition(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
    //draw the colorIDs in the image using the palette positions. The user need to know the colors size which is the paletteSize multiply by bytesPerColor
    bool drawColors(edk::uint8* colors);
    //draw a color position from the palette in colors vector.
    bool drawColorsPosition(edk::vec2ui32 position,edk::uint8* colorID);
    bool drawColorsPosition(edk::vec2ui32 position,edk::uint8 colorID);
    bool drawColorsPosition(edk::vec2ui32 position,edk::uint16 colorID);
    bool drawColorsPosition(edk::vec2ui32 position,edk::uint32 colorID);
    bool drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8* colorID);
    bool drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint8 colorID);
    bool drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint16 colorID);
    bool drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 colorID);

    size2ui32 getSize();

    uint32 getWidth();

    uint32 getHeight();

    uint32 width();

    uint32 height();
    //return the channels of the image
    edk::uint8 getChannels();
    edk::uint8 channels();
    //return the bytes per color to set the color values with the palette positions.
    edk::uint8 getBytesPerColor();
    //return the number of colors on the palette
    edk::uint32 getPaletteSize();
    //get the vector size
    edk::uint32 getPixelsLenght();
    //get the palette size
    edk::uint32 getPaletteLenght();
    //get the colors lenght returh the colors vector lenght with the palette ID's
    edk::uint32 getColorsLenght();

    bool haveImage();

    bool haveColors();

    bool havePalette();

    bool haveName();

    bool haveFileName();

    char8* getName();

    char8* name();

    char8* getFileName();

    char8* fileName();

    //return the pixels of the image to use in videoBoard
    edk::uint8* getPixels();
    edk::uint8 getPixelR(edk::vec2ui32 position);
    edk::uint8 getPixelR(edk::uint32 x,edk::uint32 y);
    edk::uint8 getPixelG(edk::vec2ui32 position);
    edk::uint8 getPixelG(edk::uint32 x,edk::uint32 y);
    edk::uint8 getPixelB(edk::vec2ui32 position);
    edk::uint8 getPixelB(edk::uint32 x,edk::uint32 y);
    edk::uint8 getPixelGray(edk::vec2ui32 position);
    edk::uint8 getPixelGray(edk::uint32 x,edk::uint32 y);
    edk::uint8 getPixelA(edk::vec2ui32 position);
    edk::uint8 getPixelA(edk::uint32 x,edk::uint32 y);
    edk::color3ui8 getPixelRGB(edk::vec2ui32 position);
    edk::color3ui8 getPixelRGB(edk::uint32 x,edk::uint32 y);
    edk::color4ui8 getPixelRGBA(edk::vec2ui32 position);
    edk::color4ui8 getPixelRGBA(edk::uint32 x,edk::uint32 y);
    //return the colors vector with all the palette codes
    edk::uint8* getColors();

    //convert the image pixels
    bool calculateAlpha(edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB);
    bool calculateAlpha(edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB,edk::uint8 min,edk::uint8 max);
    bool calculateAlpha(edk::color3ui8 compareRGB);
    bool calculateAlpha(edk::color3ui8 compareRGB,edk::uint8 min,edk::uint8 max);

    void deleteImage();

    void deleteName();

    //process the flip image in Y
    bool flipImageY();

    //Compare with other image
    edk::uint64 compareToUint64(edk::Image2D* compare);
    edk::float64 compareToFloat64(edk::Image2D* compare);
    edk::float64 compareLeftToFloat64(edk::Image2D* compare,edk::uint32 lenght);
    edk::float64 compareRightToFloat64(edk::Image2D* compare,edk::uint32 lenght);
    edk::float64 compareUpToFloat64(edk::Image2D* compare,edk::uint32 lenght);
    edk::float64 compareDownToFloat64(edk::Image2D* compare,edk::uint32 lenght);
    //compare dockable with other image
    edk::float64 compareDockableLeftToFloat64(edk::Image2D* compare,edk::uint32 lenght);
    edk::float64 compareDockableRightToFloat64(edk::Image2D* compare,edk::uint32 lenght);
    edk::float64 compareDockableUpToFloat64(edk::Image2D* compare,edk::uint32 lenght);
    edk::float64 compareDockableDownToFloat64(edk::Image2D* compare,edk::uint32 lenght);

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
    //RGB to Alpha
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
    //compare
    static edk::uint64 cmpToUint64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* compare,edk::uint8 channels);
    static edk::float64 cmpToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint8* compare,edk::uint8 channels);
    static edk::float64 cmpLeftToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels);
    static edk::float64 cmpRightToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels);
    static edk::float64 cmpUpToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels);
    static edk::float64 cmpDownToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels);
    //compare dockable
    static edk::float64 cmpDkbleLeftToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels);
    static edk::float64 cmpDkbleRightToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels);
    static edk::float64 cmpDkbleUpToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels);
    static edk::float64 cmpDkbleDownToFloat64(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 lenght,edk::uint8* compare,edk::uint8 channels);

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
    //pixel vector
    edk::uint8* vec;
    //color id vector
    edk::uint8* colors;
    //channels of the image
    edk::uint8 channelsValue;
    //save the bits per colors
    edk::uint8 bytesPerColors;
    //Size of the image
    edk::size2ui32 size;
    //imageName of the image
    edk::char8* imageName;
    //imageName of the file
    edk::char8* imageFileName;

    //image palette
    edk::uint8* palette;
    edk::uint32 paletteSize;

    //imageFileNameFunctions
    void setFileName(edk::char8* imageFileName);
    void setFileName(const edk::char8* imageFileName);
    void deleteFileName();
    //discover the imageType
    edk::uint8 getStreamType(edk::uint8* encoded);
    //discover the nameType
    edk::uint8 getNameType(edk::char8* name);
private:
    edk::classID classThis;
};

}//End of namespace edk

#endif // edk_Image2D_h
