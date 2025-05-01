#ifndef FONTMAP_H
#define FONTMAP_H

/*
Library FontMap - Tile Map for Font Set to show text
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
#pragma message "Inside FontMap"
#endif

#pragma once
#include "FontSet.h"
#include "../Object2DValues.h"
#include "../tiles/TileMap2D.h"
#include "../vector/Stack.h"
//Animation
#include "../animation/Interpolation1DGroup.h"

#include "../pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling FontMap"
#endif


namespace edk{
namespace fonts{
class FontMap;
class FontCallback{
public:
    virtual void originFoundEnd()=0;
    virtual void lastFoundEnd()=0;
    virtual void animationEnd(edk::fonts::FontMap* text,bool isOrigin)=0;
};

class FontMap : public edk::Object2DValues , public edk::animation::AnimationCallback{
public:
    FontMap();
    virtual ~FontMap();

    void Constructor();
    void Destructor();

    //save the FontTemplate
    static bool saveTemplate(const edk::char8* folder);
    static bool saveTemplate(edk::char8* folder);

    //SET
    void setPosition(edk::vec2f32 position);
    void setPosition(edk::float32 x,edk::float32 y);
    void setScale(edk::size2f32 scale);
    void setScale(edk::float32 width,edk::float32 height);

    //GET
    edk::vec2f32 getPosition();
    edk::float32 getPositionX();
    edk::float32 getPositionY();
    //get size of the map
    edk::size2ui32 getMapSize();
    edk::uint32 getMapSizeWidth();
    edk::uint32 getMapSizeHeight();
    //get the mapScale
    edk::size2f32 getMapScale();
    edk::float32 getMapScaleWidth();
    edk::float32 getMapScaleHeight();
    //return the last position
    edk::vec2ui32 getTheLastPosition();
    edk::uint32 getTheLastPositionX();
    edk::uint32 getTheLastPositionY();

    //load fontImage
    bool loadFontImage(const edk::char8* name,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
    bool loadFontImage(edk::char8* name,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
    bool loadFontImageFromMemory(const edk::char8* name,
                                 edk::uint8* image,
                                 edk::uint32 size,
                                 edk::uint32 filter = GU_NEAREST,
                                 edk::color4f32 color = edk::color4f32(0,0,0,1)
            );
    bool loadFontImageFromMemory(edk::char8* name,
                                 edk::uint8* image,
                                 edk::uint32 size,
                                 edk::uint32 filter = GU_NEAREST,
                                 edk::color4f32 color = edk::color4f32(0,0,0,1)
            );
    bool loadFontImageFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));
    bool loadFontImageFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(0,0,0,1));

    //create a map
    bool createMap(edk::size2ui32 size);
    bool createMap(edk::uint32 width,edk::uint32 height);
    //create the string
    bool createStringMap(const edk::char8* str,edk::uint32 width);
    bool createStringMap(edk::char8* str,edk::uint32 width);
    bool createStringMap(const edk::char8* str);
    bool createStringMap(edk::char8* str);
    bool addStringLine(const edk::char8* str,edk::uint32 width);
    bool addStringLine(edk::char8* str,edk::uint32 width);
    bool addStringLine(const edk::char8* str);
    bool addStringLine(edk::char8* str);
    bool createStringMapOneLine(const edk::char8* str,edk::uint32 width);
    bool createStringMapOneLine(edk::char8* str,edk::uint32 width);
    bool createStringMapOneLine(const edk::char8* str);
    bool createStringMapOneLine(edk::char8* str);

    //write a character in the map position
    bool writeChar(edk::uchar8 c,edk::uint32 x,edk::uint32 y);
    bool writeChar(edk::uchar8 c,edk::vec2ui32 position);
    bool writeChar(edk::char8* c,edk::uint32 x,edk::uint32 y);
    bool writeChar(edk::char8* c,edk::vec2ui32 position);
    bool writeChar(const edk::char8* c,edk::uint32 x,edk::uint32 y);
    bool writeChar(const edk::char8* c,edk::vec2ui32 position);
    bool writeColor(edk::color4f32 color,edk::uint32 x,edk::uint32 y);
    bool writeColor(edk::color4f32 color,edk::vec2ui32 position);
    bool writeColor(edk::color3f32 color,edk::uint32 x,edk::uint32 y);
    bool writeColor(edk::color3f32 color,edk::vec2ui32 position);
    bool writeColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::uint32 x,edk::uint32 y);
    bool writeColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::vec2ui32 position);
    bool writeColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::uint32 x,edk::uint32 y);
    bool writeColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::vec2ui32 position);

    bool writeString(const edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width);
    bool writeString(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width);
    bool writeString(const edk::char8* str,edk::vec2ui32 position,edk::uint32 width);
    bool writeString(edk::char8* str,edk::vec2ui32 position,edk::uint32 width);
    bool writeString(const edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width,edk::uint32 height);
    bool writeString(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width,edk::uint32 height);
    bool writeString(const edk::char8* str,edk::vec2ui32 position,edk::uint32 width,edk::uint32 height);
    bool writeString(edk::char8* str,edk::vec2ui32 position,edk::uint32 width,edk::uint32 height);
    bool writeString(const edk::char8* str,edk::uint32 x,edk::uint8 y,edk::size2ui32 size);
    bool writeString(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::size2ui32 size);
    bool writeString(const edk::char8* str,edk::vec2ui32 position,edk::size2ui32 size);
    bool writeString(edk::char8* str,edk::vec2ui32 position,edk::size2ui32 size);

    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );

    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );

    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::color4f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::color4f32 color
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::color4f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::color4f32 color
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color4f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color4f32 color
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color4f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color4f32 color
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::color4f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::color4f32 color
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::color4f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::color4f32 color
                          );

    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::color3f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::color3f32 color
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::color3f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::color3f32 color
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color3f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color3f32 color
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color3f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color3f32 color
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::color3f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::color3f32 color
                          );
    bool writeStringColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::color3f32 color
                          );
    bool writeStringColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::color3f32 color
                          );

    bool writeSpaces(const edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width);
    bool writeSpaces(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width);
    bool writeSpaces(const edk::char8* str,edk::vec2ui32 position,edk::uint32 width);
    bool writeSpaces(edk::char8* str,edk::vec2ui32 position,edk::uint32 width);
    bool writeSpaces(const edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width,edk::uint32 height);
    bool writeSpaces(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::uint32 width,edk::uint32 height);
    bool writeSpaces(const edk::char8* str,edk::vec2ui32 position,edk::uint32 width,edk::uint32 height);
    bool writeSpaces(edk::char8* str,edk::vec2ui32 position,edk::uint32 width,edk::uint32 height);
    bool writeSpaces(const edk::char8* str,edk::uint32 x,edk::uint8 y,edk::size2ui32 size);
    bool writeSpaces(edk::char8* str,edk::uint32 x,edk::uint8 y,edk::size2ui32 size);
    bool writeSpaces(const edk::char8* str,edk::vec2ui32 position,edk::size2ui32 size);
    bool writeSpaces(edk::char8* str,edk::vec2ui32 position,edk::size2ui32 size);

    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b,
                          edk::float32 a
                          );

    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::float32 r,
                          edk::float32 g,
                          edk::float32 b
                          );

    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::color4f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::color4f32 color
                          );

    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::uint32 width,
                          edk::uint32 height,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::uint32 x,
                          edk::uint8 y,
                          edk::size2ui32 size,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(const edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::color3f32 color
                          );
    bool writeSpacesColor(edk::char8* str,
                          edk::vec2ui32 position,
                          edk::size2ui32 size,
                          edk::color3f32 color
                          );
    //clean the text charaters with spaces in all positions of the map
    bool cleanSpaces();
    //clean the text characters with spaces with color
    bool cleanSpacesColor(edk::color3f32 color);
    bool cleanSpacesColor(edk::float32 r,edk::float32 g,edk::float32 b);
    bool cleanSpacesColor(edk::color4f32 color);
    bool cleanSpacesColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);

    //set the color
    void setColor(edk::color4f32 color);
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setAlpha(edk::float32 value);
    void setColor(edk::color4ui8 color);
    void setColor(edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
    void setAlpha(edk::uint8 value);

    //delete tileMap
    void deleteMap();
    //return true if have a text
    bool haveText();

    //add callback
    bool addCallback(edk::fonts::FontCallback* callback);
    bool removeCallback(edk::fonts::FontCallback* callback);
    //cleanCallacks
    void cleanCallbacks();

    //Select characters to draw
    void selectAll();

    //set the origin and the last values
    bool setOriginAndLast(edk::uint32 originID, edk::uint32 lastID);
    bool setOriginAndLast(edk::vec2ui32 origin, edk::vec2ui32 last);
    bool setOriginAndLast(edk::uint32 originX,edk::uint32 originY,edk::uint32 lastX,edk::uint32 lastY);
    bool setOrigin(edk::uint32 originID);
    bool setOrigin(edk::vec2ui32 origin);
    bool setOrigin(edk::uint32 originX,edk::uint32 originY);
    bool setLast(edk::uint32 lastID);
    bool setLast(edk::vec2ui32 last);
    bool setLast(edk::uint32 lastX,edk::uint32 lastY);

    //add animations
    bool addInterpolation(edk::float32 second,edk::uint32 originID, edk::uint32 lastID);
    bool addInterpolation(edk::float32 second,edk::vec2ui32 origin, edk::vec2ui32 last);
    bool addInterpolation(edk::float32 second,edk::uint32 originX,edk::uint32 originY,edk::uint32 lastX,edk::uint32 lastY);
    bool addInterpolationOrigin(edk::float32 second,edk::uint32 ID);
    bool addInterpolationOrigin(edk::float32 second,edk::vec2ui32 origin);
    bool addInterpolationOrigin(edk::float32 second,edk::uint32 originX,edk::uint32 originY);
    bool addInterpolationLast(edk::float32 second,edk::uint32 ID);
    bool addInterpolationLast(edk::float32 second,edk::vec2ui32 last);
    bool addInterpolationLast(edk::float32 second,edk::uint32 lastX,edk::uint32 lastY);

    //Set animation speed
    void setAnimationSpeedOrigin(edk::float32 speed);
    //set faster
    void setAtimationFasterSpeedOrigin(edk::float32 faster);
    //speed
    void setAnimationSpeedLast(edk::float32 speed);
    //set faster
    void setAtimationFasterSpeedLast(edk::float32 faster);

    //CONTROLS
    //animation controllers
    void playForward();
    void playForwardIn(edk::float32 second);
    void playRewind();
    void playRewindIn(edk::float32 second);
    void pause();
    void pauseOn();
    void pauseOff();
    void stop();
    //set loop
    void setLoop(bool loop);
    void loopOn();
    void loopOff();

    //Force speed for the next update
    void forceSpeedInOrigin(edk::float32 speed);
    void forceSpeedInLast(edk::float32 speed);
    //update animations
    bool updateAnimations();
    bool updateAnimations(edk::float32 seconds);

    //draw the text
    void draw(edk::color4f32 color);
    void draw(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void draw(edk::float32 r,edk::float32 g,edk::float32 b);
    void draw();
    void drawWithoutMaterial(edk::color4f32 color);
    void drawWithoutMaterial(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void drawWithoutMaterial(edk::float32 r,edk::float32 g,edk::float32 b);
    void drawWithoutMaterial();
    void drawWire(edk::color4f32 color);
    void drawWire(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void drawWire(edk::float32 r,edk::float32 g,edk::float32 b);
    void drawWire();
    void drawSelection();
    //draw the pivo
    void drawPivo(edk::float32 size,edk::color3f32 color);

    //remove the fontImage
    void removeFontImage();

    void animationEnd(edk::animation::InterpolationGroup* animation);

private:
    edk::vec2f32 savePosition;
    edk::float32 saveAngle;
    edk::size2f32 saveSize;

    edk::tiles::TileMap2D map;
    edk::fonts::fontSetList list;
    edk::fonts::FontSet* set;

    //positions to draw
    edk::uint32 originID;
    edk::uint32 lastID;
    edk::vec2ui32 origin;
    edk::vec2ui32 last;
    //force animation speed
    bool forceSpeedOrigin;
    bool forceSpeedLast;
    edk::float32 forceSpeedOriginValue;
    edk::float32 forceSpeedLastValue;
    //save the write value on the line
    edk::uint32 write;

    //interpolation to select what characters to draw
    edk::animation::Interpolation1DGroup animOrigin;
    edk::animation::Interpolation1DGroup animLast;
    edk::float32 speedOrigin;
    edk::float32 fasterOrigin;
    edk::float32 speedLast;
    edk::float32 fasterLast;
    //found enter in origin or last
    bool enterOrigin;
    bool enterLast;

    //FontsCallback tree
    edk::vector::BinaryTree<edk::fonts::FontCallback*> treeCallbacks;

    class FontLine{
    public:
        FontLine(edk::uint32 size);
        virtual ~FontLine();

        void Constructor(edk::uint32 size);
        void Destructor();

        //get the size
        edk::uint32 getSize();
        //return true if have the line
        bool haveLine();
        //set the value
        bool setValue(edk::uint32 position,edk::uint32 value);
        //get the value
        edk::uint32 getValue(edk::uint32 position);
        //test if have position
        bool havePosition(edk::uint32 position);
    private:
        edk::uint32 size;
        edk::uint32* line;
    private:
        edk::classID classThis;
    };

    //stack with the lines
    edk::vector::Stack<edk::fonts::FontMap::FontLine *> lines;
    //maxLine
    edk::uint32 maxSizeLine;

    //gete the tileID
    edk::uint32 getTileID(edk::char8* str,edk::uint8* jump);
    //return the wordSize
    edk::uint32 wordSize(edk::char8* str);
    //return the lineSize
    edk::uint32 lineSize(edk::char8* str);
    //delete lines
    void deleteLines();
    //create new line
    edk::fonts::FontMap::FontLine* newLine(edk::uint32 size);
    //return the last line on the map
    edk::fonts::FontMap::FontLine* getLastLine();
    //copy the text to the map
    bool copyLinesToMap();
    //test if have the ID
    bool haveID(edk::uint32 ID);
    //get position of the tile
    edk::vec2ui32 getCharacterPosition(edk::uint32 ID);
    edk::uint32 getCharacterID(edk::vec2ui32 position);

    //update position, size and angle with the saved position, size and angle
    inline void updateSavedTransform(){
        if(this->position!=this->savePosition){
            //set the position
            this->savePosition = this->position;
            this->setPosition(this->position);
        }
        if(this->angle!=this->saveAngle){
            //set the position
            this->saveAngle = this->angle;
        }
        if(this->position!=this->savePosition){
            //set the scale
            this->saveSize = this->size;
            this->setScale(this->size);
        }
    }


    //Draw
    void draw(edk::vec2ui32 origin,edk::vec2ui32 last,edk::color4f32 color);
    void draw(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine,edk::color4f32 color);
    void drawWithoutMaterial(edk::vec2ui32 origin,edk::vec2ui32 last,edk::color4f32 color);
    void drawWithoutMaterial(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine,edk::color4f32 color);
    void drawWire(edk::vec2ui32 origin,edk::vec2ui32 last,edk::color4f32 color);
    void drawWire(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine,edk::color4f32 color);
    void drawSelection(edk::vec2ui32 origin,edk::vec2ui32 last);
    void drawSelection(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine);
    //Draw without passing a color
    void draw(edk::vec2ui32 origin,edk::vec2ui32 last);
    void draw(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine);
    void drawWithoutMaterial(edk::vec2ui32 origin,edk::vec2ui32 last);
    void drawWithoutMaterial(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine);
    void drawWire(edk::vec2ui32 origin,edk::vec2ui32 last);
    void drawWire(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine);
    //draw the ID
    void draw(edk::uint32 originID,edk::uint32 lastID,edk::color4f32 color);
    void draw(edk::vec2ui32 origin,edk::uint32 lastID,edk::color4f32 color);
    void draw(edk::uint32 originID,edk::vec2ui32 last,edk::color4f32 color);
    void drawWithoutMaterial(edk::uint32 originID,edk::uint32 lastID,edk::color4f32 color);
    void drawWithoutMaterial(edk::vec2ui32 origin,edk::uint32 lastID,edk::color4f32 color);
    void drawWithoutMaterial(edk::uint32 originID,edk::vec2ui32 last,edk::color4f32 color);
    void drawWire(edk::uint32 originID,edk::uint32 lastID,edk::color4f32 color);
    void drawWire(edk::vec2ui32 origin,edk::uint32 lastID,edk::color4f32 color);
    void drawWire(edk::uint32 originID,edk::vec2ui32 last,edk::color4f32 color);
    void drawSelection(edk::uint32 originID,edk::uint32 lastID);
    void drawSelection(edk::vec2ui32 origin,edk::uint32 lastID);
    void drawSelection(edk::uint32 originID,edk::vec2ui32 last);
    //draw the ID without passing a color
    void draw(edk::uint32 originID,edk::uint32 lastID);
    void draw(edk::vec2ui32 origin,edk::uint32 lastID);
    void draw(edk::uint32 originID,edk::vec2ui32 last);
    void drawWithoutMaterial(edk::uint32 originID,edk::uint32 lastID);
    void drawWithoutMaterial(edk::vec2ui32 origin,edk::uint32 lastID);
    void drawWithoutMaterial(edk::uint32 originID,edk::vec2ui32 last);
    void drawWire(edk::uint32 originID,edk::uint32 lastID);
    void drawWire(edk::vec2ui32 origin,edk::uint32 lastID);
    void drawWire(edk::uint32 originID,edk::vec2ui32 last);
private:
    edk::classID classThis;
};
}//end namespace fonts
}//end namespace edk

#endif // FONTMAP_H
