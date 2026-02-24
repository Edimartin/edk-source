#ifndef IMAGE3D_H
#define IMAGE3D_H

/*
Library Image3D - Create a 3D Image in EDK
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
#pragma message "Inside Image3D"
#endif

#pragma once
//#include "Types.h"
#include "TypeColor.h"
#include "DebugFile.h"
#include "TypeDefines.h"
#include "String.h"
#include "TypeSize3.h"

#ifdef printMessages
#pragma message "    Compiling Image3D"
#endif

namespace edk {
class Image3D
{
public:
    Image3D();

    ~Image3D();

    void Constructor();

    void Destructor();

    void clean();

    //create a new Image
    bool newImage(edk::char8 *imageName,
                  edk::size3ui32 size,
                  edk::uint8 channels,
                  edk::uint8 bytesPerChannel
                  );
    bool newImage(edk::char8 *imageName,
                  edk::uint32 width,
                  edk::uint32 height,
                  edk::uint32 length,
                  edk::uint8 channels,
                  edk::uint8 bytesPerChannel
                  );
    bool newImage(const edk::char8 *imageName,
                  edk::size3ui32 size,
                  edk::uint8 channels,
                  edk::uint8 bytesPerChannel
                  );
    bool newImage(const edk::char8 *imageName,
                  edk::uint32 width,
                  edk::uint32 height,
                  edk::uint32 length,
                  edk::uint8 channels,
                  edk::uint8 bytesPerChannel
                  );

    //create a new image with a palette
    bool newImage(edk::char8 *imageName,
                  edk::size3ui32 size,
                  edk::uint8 channels,
                  edk::uint32 paletteSize,
                  edk::uint8 bytesPerChannel
                  );
    bool newImage(edk::char8 *imageName,
                  edk::uint32 width,
                  edk::uint32 height,
                  edk::uint32 length,
                  edk::uint8 channels,
                  edk::uint32 paletteSize,
                  edk::uint8 bytesPerChannel
                  );
    bool newImage(const edk::char8 *imageName,
                  edk::size3ui32 size,
                  edk::uint8 channels,
                  edk::uint32 paletteSize,
                  edk::uint8 bytesPerChannel
                  );
    bool newImage(const edk::char8 *imageName,
                  edk::uint32 width,
                  edk::uint32 height,
                  edk::uint32 length,
                  edk::uint8 channels,
                  edk::uint32 paletteSize,
                  edk::uint8 bytesPerChannel
                  );

    //function used to generate the pixels from colors palette
    bool generatePixelsFromColors();

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
    bool drawPosition(edk::vec3ui32 position,edk::uint8* color);
    bool drawPosition(edk::vec3ui32 position,edk::uint8 g);
    bool drawPosition(edk::vec3ui32 position,edk::uint8 g,edk::uint8 a);
    bool drawPosition(edk::vec3ui32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b);
    bool drawPosition(edk::vec3ui32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
    bool drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8* color);
    bool drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8 g);
    bool drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8 g,edk::uint8 a);
    bool drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8 r,edk::uint8 g,edk::uint8 b);
    bool drawPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
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
    bool drawColorsPosition(edk::vec3ui32 position,edk::uint8* colorID);
    bool drawColorsPosition(edk::vec3ui32 position,edk::uint8 colorID);
    bool drawColorsPosition(edk::vec3ui32 position,edk::uint16 colorID);
    bool drawColorsPosition(edk::vec3ui32 position,edk::uint32 colorID);
    bool drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8* colorID);
    bool drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint8 colorID);
    bool drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint16 colorID);
    bool drawColorsPosition(edk::uint32 positionX,edk::uint32 positionY,edk::uint32 positionZ,edk::uint32 colorID);

    size3ui32 getSize();

    uint32 getWidth();

    uint32 getHeight();

    uint32 getLength();

    uint32 width();

    uint32 height();

    uint32 length();
    //return the channels of the image
    edk::uint8 getChannels();
    edk::uint8 channels();
    //return the bytes per color to set the color values with the palette positions.
    edk::uint8 getBytesPerColor();
    //return the bytes per pixel to have different images from normal RGB to RHB HDR
    edk::uint8 getBytesPerChannel();
    //return the number of colors on the palette
    edk::uint32 getPaletteSize();
    //get the vector size
    edk::uint32 getPixelsLenght();
    //get the palette size
    edk::uint32 getPaletteLenght();
    //get the colors length returh the colors vector length with the palette ID's
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
    edk::uint8 getPixelR(edk::vec3ui32 position);
    edk::uint8 getPixelR(edk::uint32 x,edk::uint32 y,edk::uint32 z);
    edk::uint8 getPixelG(edk::vec3ui32 position);
    edk::uint8 getPixelG(edk::uint32 x,edk::uint32 y,edk::uint32 z);
    edk::uint8 getPixelB(edk::vec3ui32 position);
    edk::uint8 getPixelB(edk::uint32 x,edk::uint32 y,edk::uint32 z);
    edk::uint8 getPixelGray(edk::vec3ui32 position);
    edk::uint8 getPixelGray(edk::uint32 x,edk::uint32 y,edk::uint32 z);
    edk::uint8 getPixelA(edk::vec3ui32 position);
    edk::uint8 getPixelA(edk::uint32 x,edk::uint32 y,edk::uint32 z);
    edk::color3ui8 getPixelRGB(edk::vec3ui32 position);
    edk::color3ui8 getPixelRGB(edk::uint32 x,edk::uint32 y,edk::uint32 z);
    edk::color4ui8 getPixelRGBA(edk::vec3ui32 position);
    edk::color4ui8 getPixelRGBA(edk::uint32 x,edk::uint32 y,edk::uint32 z);
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
    edk::uint64 compareToUint64(edk::Image3D* compare);
    edk::float64 compareToFloat64(edk::Image3D* compare);
    edk::float64 compareLeftToFloat64(edk::Image3D* compare,edk::uint32 length);
    edk::float64 compareRightToFloat64(edk::Image3D* compare,edk::uint32 length);
    edk::float64 compareUpToFloat64(edk::Image3D* compare,edk::uint32 length);
    edk::float64 compareDownToFloat64(edk::Image3D* compare,edk::uint32 length);
    //compare dockable with other image
    edk::float64 compareDockableLeftToFloat64(edk::Image3D* compare,edk::uint32 length);
    edk::float64 compareDockableRightToFloat64(edk::Image3D* compare,edk::uint32 length);
    edk::float64 compareDockableUpToFloat64(edk::Image3D* compare,edk::uint32 length);
    edk::float64 compareDockableDownToFloat64(edk::Image3D* compare,edk::uint32 length);

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
    static bool rgbToV(edk::uint8* vector,edk::size3ui32 size,edk::uint8* dest);
    static edk::uint8* rgbToV(edk::uint8* vector,edk::size3ui32 size);
    static bool rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint8* dest);
    static edk::uint8* rgbToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length);
    static bool rgbaToV(edk::uint8* vector,edk::size3ui32 size,edk::uint8* dest);
    static edk::uint8* rgbaToV(edk::uint8* vector,edk::size3ui32 size);
    static bool rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint8* dest);
    static edk::uint8* rgbaToV(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length);
    //RGB to Alpha
    static bool rgbaToAlpha(edk::uint8* vector,edk::size3ui32 size
                            ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::size3ui32 size
                            ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                            ,edk::uint8 min,edk::uint8 max
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::size3ui32 size
                            ,edk::color3ui8 compareRGB
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::size3ui32 size
                            ,edk::color3ui8 compareRGB
                            ,edk::uint8 min,edk::uint8 max
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length
                            ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length
                            ,edk::uint8 compareR,edk::uint8 compareG,edk::uint8 compareB
                            ,edk::uint8 min,edk::uint8 max
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length
                            ,edk::color3ui8 compareRGB
                            );
    static bool rgbaToAlpha(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length
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
    static bool rgbToLui8(edk::uint8* vector,edk::size3ui32 size,edk::uint8* dest);
    static edk::uint8* rgbToLui8(edk::uint8* vector,edk::size3ui32 size);
    static bool rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint8* dest);
    static edk::uint8* rgbToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length);
    static bool rgbaToLui8(edk::uint8* vector,edk::size3ui32 size,edk::uint8* dest);
    static edk::uint8* rgbaToLui8(edk::uint8* vector,edk::size3ui32 size);
    static bool rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint8* dest);
    static edk::uint8* rgbaToLui8(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length);
    //HSL to RGB
    static edk::color3ui8 hslTorgb(edk::float32 h,edk::float32 s,edk::float32 l);
    static edk::color3ui8 hslTorgb(edk::color3f32 hsl);
    //RGB to RGBA
    static edk::color4ui8 rgbTorgba(edk::uint8 r,edk::uint8 g,edk::uint8 b);
    static edk::color4ui8 rgbTorgba(edk::color3ui8 rgb);
    static edk::color4f32 rgbTorgba(edk::float32 r,edk::float32 g,edk::float32 b);
    static edk::color4f32 rgbTorgba(edk::color3f32 rgb);
    //vector
    static bool rgbTorgba(edk::uint8* vector,edk::size3ui32 size,edk::uint8* dest);
    static edk::uint8* rgbTorgba(edk::uint8* vector,edk::size3ui32 size);
    static bool rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint8* dest);
    static edk::uint8* rgbTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length);
    //LA to RGBA
    static edk::color4ui8 laTorgba(edk::uint8 l,edk::uint8 a);
    static edk::color4f32 laTorgba(edk::float32 l,edk::float32 a);
    //vector
    static bool laTorgba(edk::uint8* vector,edk::size3ui32 size,edk::uint8* dest);
    static edk::uint8* laTorgba(edk::uint8* vector,edk::size3ui32 size);
    static bool laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint8* dest);
    static edk::uint8* laTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length);
    //L to RGBA
    static edk::color4ui8 lTorgba(edk::uint8 l);
    static edk::color4f32 lTorgba(edk::float32 l);
    //vector
    static bool lTorgba(edk::uint8* vector,edk::size3ui32 size,edk::uint8* dest);
    static edk::uint8* lTorgba(edk::uint8* vector,edk::size3ui32 size);
    static bool lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint8* dest);
    static edk::uint8* lTorgba(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length);
    //compare
    static edk::uint64 cmpToUint64(edk::uint8* vector,
                                   edk::uint32 width,
                                   edk::uint32 height,
                                   edk::uint32 length,
                                   edk::uint8* compare,
                                   edk::uint8 channels,
                                   edk::uint8 bytesPerChannel
                                   );
    static edk::float64 cmpToFloat64(edk::uint8* vector,
                                     edk::uint32 width,
                                     edk::uint32 height,
                                     edk::uint32 length,
                                     edk::uint8* compare,
                                     edk::uint8 channels,
                                     edk::uint8 bytesPerChannel
                                     );
    static edk::float64 cmpLeftToFloat64(edk::uint8* vector,
                                         edk::uint32 width,
                                         edk::uint32 height,
                                         edk::uint32 length,
                                         edk::uint8* compare,
                                         edk::uint8 channels,
                                         edk::uint8 bytesPerChannel
                                         );
    static edk::float64 cmpRightToFloat64(edk::uint8* vector,
                                          edk::uint32 width,
                                          edk::uint32 height,
                                          edk::uint32 length,
                                          edk::uint8* compare,
                                          edk::uint8 channels,
                                          edk::uint8 bytesPerChannel
                                          );
    static edk::float64 cmpUpToFloat64(edk::uint8* vector,
                                       edk::uint32 width,
                                       edk::uint32 height,
                                       edk::uint32 length,
                                       edk::uint8* compare,
                                       edk::uint8 channels,
                                       edk::uint8 bytesPerChannel
                                       );
    static edk::float64 cmpDownToFloat64(edk::uint8* vector,
                                         edk::uint32 width,
                                         edk::uint32 height,
                                         edk::uint32 length,
                                         edk::uint8* compare,
                                         edk::uint8 channels,
                                         edk::uint8 bytesPerChannel
                                         );
    //compare dockable
    static edk::float64 cmpDkbleLeftToFloat64(edk::uint8* vector,
                                              edk::uint32 width,
                                              edk::uint32 height,
                                              edk::uint32 length,
                                              edk::uint8* compare,
                                              edk::uint8 channels,
                                              edk::uint8 bytesPerChannel
                                              );
    static edk::float64 cmpDkbleRightToFloat64(edk::uint8* vector,
                                               edk::uint32 width,
                                               edk::uint32 height,
                                               edk::uint32 length,
                                               edk::uint8* compare,
                                               edk::uint8 channels,
                                               edk::uint8 bytesPerChannel
                                               );
    static edk::float64 cmpDkbleUpToFloat64(edk::uint8* vector,
                                            edk::uint32 width,
                                            edk::uint32 height,
                                            edk::uint32 length,
                                            edk::uint8* compare,
                                            edk::uint8 channels,
                                            edk::uint8 bytesPerChannel
                                            );
    static edk::float64 cmpDkbleDownToFloat64(edk::uint8* vector,
                                              edk::uint32 width,
                                              edk::uint32 height,
                                              edk::uint32 length,
                                              edk::uint8* compare,
                                              edk::uint8 channels,
                                              edk::uint8 bytesPerChannel
                                              );

    //flip pixels
    static bool flipY(edk::uint8* vector,
                      edk::uint32 width,
                      edk::uint32 height,
                      edk::uint32 length,
                      edk::uint32 channels,
                      edk::uint8 bytesPerChannel
                      );

    static bool imageClone(edk::uint8* vector,edk::uint32 width,edk::uint32 height,edk::uint32 length,edk::uint32 channels,edk::uint32 bytesPerChannes,
                           edk::uint8* dest,edk::uint32 dWidth,edk::uint32 dHeight,edk::uint32 dLength,edk::uint32 dChannels,edk::uint32 dBytesPerChannes,
                           edk::uint32 positionX,edk::uint32 positionY
                           );

    bool cloneFrom(edk::Image3D* image);
    bool newFrom(edk::Image3D* image);

    //copy one image into nother image
    static bool copyImageToImage(edk::uint8* copy,
                                 edk::size3ui32 sizeCopy,
                                 edk::uint8* dest,
                                 edk::size3ui32 sizeDest,
                                 edk::vec3ui32 position,
                                 edk::uint32 channels,
                                 edk::uint8 bytesPerChannel
                                 );
    static bool copyImageToImage(edk::uint8* copy,
                                 edk::uint32 copySizeW,edk::uint32 copySizeH,edk::uint32 copySizeL,
                                 edk::uint8* dest,
                                 edk::uint32 destSizeW,edk::uint32 destSizeH,edk::uint32 destSizeL,
                                 edk::uint32 posX,edk::uint32 posY,edk::uint32 posZ,
                                 edk::uint32 channels,
                                 edk::uint8 bytesPerChannel
                                 );
    static bool copyImageToImage(edk::Image3D* copy,edk::Image3D* dest,edk::vec3ui32 position);
    static bool copyImageToImage(edk::Image3D* copy,edk::Image3D* dest,edk::uint32 posX,edk::uint32 posY,edk::uint32 posZ);
private:
    edk::Image3D operator=(edk::Image3D){return *this;}
    //pixel vector
    edk::uint8* vec;
    //color id vector
    edk::uint8* colors;
    //channels of the image
    edk::uint8 channelsValue;
    //save the bits per colors
    edk::uint8 bytesPerColors;
    //save the bits per colors
    edk::uint8 bytesPerChannel;
    //Size of the image
    edk::size3ui32 size;
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
}

#endif // IMAGE3D_H
