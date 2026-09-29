#include "RetroTile.h"
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
#pragma message "            Inside RetroTile.cpp"
#endif

edk::uint64 edk::retro::RetroTile::staticConstruct=0uL;
edk::retro::RetroPalette edk::retro::RetroTile::staticPalette;

edk::retro::RetroTile::RetroTile(){
    this->classThis=NULL;
    this->Constructor();
}
edk::retro::RetroTile::~RetroTile(){
    this->Destructor();
}

void edk::retro::RetroTile::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        if(!edk::retro::RetroTile::staticConstruct){
            edk::retro::RetroTile::staticPalette.Constructor();
        }
        edk::retro::RetroTile::staticConstruct++;

        //set the palette pointer
        this->palette = &edk::retro::RetroTile::staticPalette;

        this->cleanTile();
    }
}
void edk::retro::RetroTile::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;

        if(edk::retro::RetroTile::staticConstruct){
            edk::retro::RetroTile::staticConstruct--;
            if(!edk::retro::RetroTile::staticConstruct){
                edk::retro::RetroTile::staticPalette.Destructor();
            }
        }
    }
}

void edk::retro::RetroTile::cleanTile(){
    for(edk::uint32 y=0u;y<8u;y++){
        for(edk::uint32 x=0u;x<8u;x++){
            this->vec[x][y]=0u;
        }
    }
}

//set the palette pointer
bool edk::retro::RetroTile::setPalette(edk::retro::RetroPalette* palette){
    if(palette){
        this->palette = palette;
        return true;
    }
    this->palette = &edk::retro::RetroTile::staticPalette;
    return false;
}

//set the pixel in position
bool edk::retro::RetroTile::setPixel(edk::uint8 x,edk::uint8 y,edk::uint32 id){
    if(x<8u && y<8u){
        if(this->palette->havePosition(id)){
            this->vec[x][y] = id;
            return true;
        }
        else{
            //
        }
    }
    return false;
}
edk::uint32 edk::retro::RetroTile::getPixel(edk::uint8 x,edk::uint8 y){
    edk::uint32 ret=0u;
    if(x<8u && y<8u){
        ret = this->vec[x][y];
    }
    return ret;
}

//palettes
edk::retro::RetroPalette* edk::retro::RetroTile::getPalette(){
    return this->palette;
}
edk::uint32 edk::retro::RetroTile::getPaletteSize(){
    return this->palette->getSize();
}
edk::uint8 edk::retro::RetroTile::getPaletteChannels(){
    return this->palette->getChannels();
}
edk::uint8 edk::retro::RetroTile::getPaletteBytesPerChannel(){
    return this->palette->getBytesPerChannel();
}

//Palette color
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b,edk::uint8 a){
    return this->palette->setColor(position,r,g,b,a);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::uint8 r,edk::uint8 g,edk::uint8 b){
    return this->palette->setColor(position,r,g,b);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::uint8 g,edk::uint8 a){
    return this->palette->setColor(position,g,a);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::uint8 g){
    return this->palette->setColor(position,g);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::uint16 r,edk::uint16 g,edk::uint16 b,edk::uint16 a){
    return this->palette->setColor(position,r,g,b,a);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::uint16 r,edk::uint16 g,edk::uint16 b){
    return this->palette->setColor(position,r,g,b);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::uint16 g,edk::uint16 a){
    return this->palette->setColor(position,g,a);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::uint16 g){
    return this->palette->setColor(position,g);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::color4ui8 color){
    return this->palette->setColor(position,color);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::color3ui8 color){
    return this->palette->setColor(position,color);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::color2ui8 color){
    return this->palette->setColor(position,color);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::color1ui8 color){
    return this->palette->setColor(position,color);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::color4ui16 color){
    return this->palette->setColor(position,color);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::color3ui16 color){
    return this->palette->setColor(position,color);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::color2ui16 color){
    return this->palette->setColor(position,color);
}
bool edk::retro::RetroTile::setPaletteColor(edk::uint32 position,edk::color1ui16 color){
    return this->palette->setColor(position,color);
}
edk::uint8 edk::retro::RetroTile::getPaletteColorR8(edk::uint32 position){
    return this->palette->getColorR8(position);
}
edk::uint8 edk::retro::RetroTile::getPaletteColorG8(edk::uint32 position){
    return this->palette->getColorG8(position);
}
edk::uint8 edk::retro::RetroTile::getPaletteColorB8(edk::uint32 position){
    return this->palette->getColorB8(position);
}
edk::uint8 edk::retro::RetroTile::getPaletteColorA8(edk::uint32 position){
    return this->palette->getColorA8(position);
}
edk::uint16 edk::retro::RetroTile::getPaletteColorR16(edk::uint32 position){
    return this->palette->getColorR16(position);
}
edk::uint16 edk::retro::RetroTile::getPaletteColorG16(edk::uint32 position){
    return this->palette->getColorG16(position);
}
edk::uint16 edk::retro::RetroTile::getPaletteColorB16(edk::uint32 position){
    return this->palette->getColorB16(position);
}
edk::uint16 edk::retro::RetroTile::getPaletteColorA16(edk::uint32 position){
    return this->palette->getColorA16(position);
}
edk::color1ui8 edk::retro::RetroTile::getPaletteColor1ui8(edk::uint32 position){
    return this->palette->getColor1ui8(position);
}
edk::color2ui8 edk::retro::RetroTile::getPaletteColor2ui8(edk::uint32 position){
    return this->palette->getColor2ui8(position);
}
edk::color3ui8 edk::retro::RetroTile::getPaletteColor3ui8(edk::uint32 position){
    return this->palette->getColor3ui8(position);
}
edk::color4ui8 edk::retro::RetroTile::getPaletteColor4ui8(edk::uint32 position){
    return this->palette->getColor4ui8(position);
}
edk::color1ui16 edk::retro::RetroTile::getPaletteColor1ui16(edk::uint32 position){
    return this->palette->getColor1ui16(position);
}
edk::color2ui16 edk::retro::RetroTile::getPaletteColor2ui16(edk::uint32 position){
    return this->palette->getColor2ui16(position);
}
edk::color3ui16 edk::retro::RetroTile::getPaletteColor3ui16(edk::uint32 position){
    return this->palette->getColor3ui16(position);
}
edk::color4ui16 edk::retro::RetroTile::getPaletteColor4ui16(edk::uint32 position){
    return this->palette->getColor4ui16(position);
}
//get the color of a pixel
edk::uint8 edk::retro::RetroTile::getPixelColorR8(edk::uint8 x,edk::uint8 y){
    return this->getPaletteColorR8(this->getPixel(x,y));
}
edk::uint8 edk::retro::RetroTile::getPixelColorG8(edk::uint8 x,edk::uint8 y){
    return this->getPaletteColorG8(this->getPixel(x,y));
}
edk::uint8 edk::retro::RetroTile::getPixelColorB8(edk::uint8 x,edk::uint8 y){
    return this->getPaletteColorB8(this->getPixel(x,y));
}
edk::uint8 edk::retro::RetroTile::getPixelColorA8(edk::uint8 x,edk::uint8 y){
    return this->getPaletteColorA8(this->getPixel(x,y));
}
edk::uint16 edk::retro::RetroTile::getPixelColorR16(edk::uint8 x,edk::uint8 y){
    return this->getPaletteColorR16(this->getPixel(x,y));
}
edk::uint16 edk::retro::RetroTile::getPixelColorG16(edk::uint8 x,edk::uint8 y){
    return this->getPaletteColorG16(this->getPixel(x,y));
}
edk::uint16 edk::retro::RetroTile::getPixelColorB16(edk::uint8 x,edk::uint8 y){
    return this->getPaletteColorB16(this->getPixel(x,y));
}
edk::uint16 edk::retro::RetroTile::getPixelColorA16(edk::uint8 x,edk::uint8 y){
    return this->getPaletteColorA16(this->getPixel(x,y));
}
edk::color1ui8 edk::retro::RetroTile::getPixelColor1ui8(edk::uint8 x,edk::uint8 y){
return this->getPaletteColor1ui8(this->getPixel(x,y));
}
edk::color2ui8 edk::retro::RetroTile::getPixelColor2ui8(edk::uint8 x,edk::uint8 y){
return this->getPaletteColor2ui8(this->getPixel(x,y));
}
edk::color3ui8 edk::retro::RetroTile::getPixelColor3ui8(edk::uint8 x,edk::uint8 y){
return this->getPaletteColor3ui8(this->getPixel(x,y));
}
edk::color4ui8 edk::retro::RetroTile::getPixelColor4ui8(edk::uint8 x,edk::uint8 y){
return this->getPaletteColor4ui8(this->getPixel(x,y));
}
edk::color1ui16 edk::retro::RetroTile::getPixelColor1ui16(edk::uint8 x,edk::uint8 y){
return this->getPaletteColor1ui16(this->getPixel(x,y));
}
edk::color2ui16 edk::retro::RetroTile::getPixelColor2ui16(edk::uint8 x,edk::uint8 y){
return this->getPaletteColor2ui16(this->getPixel(x,y));
}
edk::color3ui16 edk::retro::RetroTile::getPixelColor3ui16(edk::uint8 x,edk::uint8 y){
return this->getPaletteColor3ui16(this->getPixel(x,y));
}
edk::color4ui16 edk::retro::RetroTile::getPixelColor4ui16(edk::uint8 x,edk::uint8 y){
return this->getPaletteColor4ui16(this->getPixel(x,y));
}

//compare
bool edk::retro::RetroTile::isEqual(edk::retro::RetroTile* tile){
    bool ret = true;
    if(this->palette == tile->palette){
        for(edk::uint32 y=0u;y<8u;y++){
            for(edk::uint32 x=0u;x<8u;x++){
                if(this->vec[x][y] != tile->vec[x][y]){
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
bool edk::retro::RetroTile::isEqualID(edk::retro::RetroTile* tile){
    bool ret = true;
    for(edk::uint32 y=0u;y<8u;y++){
        for(edk::uint32 x=0u;x<8u;x++){
            if(this->vec[x][y] != tile->vec[x][y]){
                ret=false;
                break;
            }
        }
    }
    return ret;
}
bool edk::retro::RetroTile::clone(edk::retro::RetroTile* tile){
    if(tile){
        //copy
        this->palette = tile->palette;
        edkMemCpy(this->vec,tile->vec,sizeof(this->vec));
    }
    return false;
}

//print
void edk::retro::RetroTile::print(){
    if(this->palette!=&edk::retro::RetroTile::staticPalette){
        printf("\nTILE:\n");
        edk::uint8 count = 0u;
        for(edk::uint32 y=0u;y<8u;y++){
            for(edk::uint32 x=0u;x<8u;x++){
                printf("[%u]",this->vec[x][y]);
                count++;
                if(count>=8u){
                    printf("\n");
                    count=0u;
                }
            }
        }
    }
}
void edk::retro::RetroTile::printPixels(){
    if(this->palette!=&edk::retro::RetroTile::staticPalette){
        switch(this->palette->getChannels()){
        case 1u:
            printf("\nTILE 4u:\n");
            break;
        case 2u:
            printf("\nTILE 2u:\n");
            break;
        case 3u:
            printf("\nTILE 3u:\n");
            break;
        case 4u:
            printf("\nTILE 4u:\n");
            break;
        }
        edk::uint8 count = 0u;
        for(edk::uint32 y=0u;y<8u;y++){
            for(edk::uint32 x=0u;x<8u;x++){
                this->palette->printPosition(this->vec[x][y]);
                printf(",");
                count++;
                if(count>=8u){
                    printf("\n");
                    count=0u;
                }
            }
        }
    }
}
