#ifndef RETROTILE_H
#define RETROTILE_H

/*
Library C++ RetroTile - Retro Tile used in EDK
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
#pragma message "Inside RetroTile"
#endif

#pragma once
#include "./RetroPalette.h"

#ifdef printMessages
#pragma message "    Compiling RetroTile"
#endif

namespace edk{
namespace retro{
class RetroTile{
public:
    RetroTile();
    ~RetroTile();

    void Constructor();
    void Destructor();

    //set the palette pointer
    bool setPalette(edk::retro::RetroPalette* palette);

    //set the pixel in position
    bool setPixel(edk::uint8 x,edk::uint8 y,edk::uint32 id);
    edk::uint32 getPixel(edk::uint8 x,edk::uint8 y);

    //palettes
    edk::retro::RetroPalette* getPalette();
    edk::uint32 getPaletteSize();
    edk::uint8 getPaletteChannels();
    edk::uint8 getPaletteBytesPerChannel();

    //Palette color
    bool setPaletteColor(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a);
    bool setPaletteColor(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b);
    bool setPaletteColor(edk::uint32 position,edk::uint8 g,edk::uint8 a);
    bool setPaletteColor(edk::uint32 position,edk::uint8 g);
    bool setPaletteColor(edk::uint32 position,edk::uint16 r,edk::uint16 g,edk::uint16 b,edk::uint16 a);
    bool setPaletteColor(edk::uint32 position,edk::uint16 r,edk::uint16 g,edk::uint16 b);
    bool setPaletteColor(edk::uint32 position,edk::uint16 g,edk::uint16 a);
    bool setPaletteColor(edk::uint32 position,edk::uint16 g);
    bool setPaletteColor(edk::uint32 position,edk::color4ui8 color);
    bool setPaletteColor(edk::uint32 position,edk::color3ui8 color);
    bool setPaletteColor(edk::uint32 position,edk::color2ui8 color);
    bool setPaletteColor(edk::uint32 position,edk::color1ui8 color);
    bool setPaletteColor(edk::uint32 position,edk::color4ui16 color);
    bool setPaletteColor(edk::uint32 position,edk::color3ui16 color);
    bool setPaletteColor(edk::uint32 position,edk::color2ui16 color);
    bool setPaletteColor(edk::uint32 position,edk::color1ui16 color);
    edk::uint8 getPaletteColorR8(edk::uint32 position);
    edk::uint8 getPaletteColorG8(edk::uint32 position);
    edk::uint8 getPaletteColorB8(edk::uint32 position);
    edk::uint8 getPaletteColorA8(edk::uint32 position);
    edk::uint16 getPaletteColorR16(edk::uint32 position);
    edk::uint16 getPaletteColorG16(edk::uint32 position);
    edk::uint16 getPaletteColorB16(edk::uint32 position);
    edk::uint16 getPaletteColorA16(edk::uint32 position);
    edk::color1ui8 getPaletteColor1ui8(edk::uint32 position);
    edk::color2ui8 getPaletteColor2ui8(edk::uint32 position);
    edk::color3ui8 getPaletteColor3ui8(edk::uint32 position);
    edk::color4ui8 getPaletteColor4ui8(edk::uint32 position);
    edk::color1ui16 getPaletteColor1ui16(edk::uint32 position);
    edk::color2ui16 getPaletteColor2ui16(edk::uint32 position);
    edk::color3ui16 getPaletteColor3ui16(edk::uint32 position);
    edk::color4ui16 getPaletteColor4ui16(edk::uint32 position);
    //get the color of a pixel
    edk::uint8 getPixelColorR8(edk::uint8 x,edk::uint8 y);
    edk::uint8 getPixelColorG8(edk::uint8 x,edk::uint8 y);
    edk::uint8 getPixelColorB8(edk::uint8 x,edk::uint8 y);
    edk::uint8 getPixelColorA8(edk::uint8 x,edk::uint8 y);
    edk::uint16 getPixelColorR16(edk::uint8 x,edk::uint8 y);
    edk::uint16 getPixelColorG16(edk::uint8 x,edk::uint8 y);
    edk::uint16 getPixelColorB16(edk::uint8 x,edk::uint8 y);
    edk::uint16 getPixelColorA16(edk::uint8 x,edk::uint8 y);
    edk::color1ui8 getPixelColor1ui8(edk::uint8 x,edk::uint8 y);
    edk::color2ui8 getPixelColor2ui8(edk::uint8 x,edk::uint8 y);
    edk::color3ui8 getPixelColor3ui8(edk::uint8 x,edk::uint8 y);
    edk::color4ui8 getPixelColor4ui8(edk::uint8 x,edk::uint8 y);
    edk::color1ui16 getPixelColor1ui16(edk::uint8 x,edk::uint8 y);
    edk::color2ui16 getPixelColor2ui16(edk::uint8 x,edk::uint8 y);
    edk::color3ui16 getPixelColor3ui16(edk::uint8 x,edk::uint8 y);
    edk::color4ui16 getPixelColor4ui16(edk::uint8 x,edk::uint8 y);

    //compare
    bool isEqual(edk::retro::RetroTile* tile);
    bool isEqualID(edk::retro::RetroTile* tile);
    bool clone(edk::retro::RetroTile* tile);

    //print
    void print();
    void printPixels();

    //operators
    inline bool operator==(edk::retro::RetroTile tile){
        bool ret = true;
        if(this->palette == tile.palette){
            for(edk::uint32 y=0u;y<8u;y++){
                for(edk::uint32 x=0u;x<8u;x++){
                    if(this->vec[x][y] != tile.vec[x][y]){
                        ret=false;
                        break;
                    }
                }
            }
        }
        else{
            ret = false;
        }
        return ret;
    }
    inline edk::retro::RetroTile operator=(edk::retro::RetroTile tile){
        this->palette = tile.palette;
        edkMemCpy(this->vec,tile.vec,sizeof(this->vec));
        return *this;
    }
private:
    static edk::uint64 staticConstruct;
    static edk::retro::RetroPalette staticPalette;

    edk::retro::RetroPalette* palette;
    edk::uint32 vec[8u][8u];

    void cleanTile();
private:
    edk::classID classThis;
};
}//end namespace retro
}//end namespace edk

#endif // RETROTILE_H
