#include "RetroTileSet.h"
/*
Library C++ RetroTileSet - Retro TileSet used in EDK
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
#pragma message "            Inside RetroTileSet.cpp"
#endif

edk::retro::RetroTileSpecs edk::retro::RetroTileSet::staticSpecs;

edk::retro::RetroTileSet::RetroTileSet(){
    this->classThis=NULL;
    this->Constructor();
}
edk::retro::RetroTileSet::~RetroTileSet(){
    this->Destructor();
}

void edk::retro::RetroTileSet::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::retro::RetroTileSet::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
}

//search for equal tiles
bool edk::retro::RetroTileSet::haveEqualTile(edk::retro::RetroTile tile,edk::retro::RetroTileSpecs* specs){
    edk::retro::RetroTile temp;
    edk::uint32 size = this->size();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->get(i);
        if(temp == tile){
            specs->clean();
            specs->value = i;
            return true;
        }
    }
    return false;
}
bool edk::retro::RetroTileSet::haveEqualFlipTile(edk::retro::RetroTile tile,edk::retro::RetroTileSpecs* specs){
    edk::retro::RetroTile temp;
    edk::uint32 size = this->size();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->get(i);
        if(temp == tile){
            specs->clean();
            specs->value = i;
            return true;
        }
        else if(temp.equalFlipH(tile)){
            specs->clean();
            specs->flipH=true;
            specs->value = i;
            return true;
        }
        else if(temp.equalFlipV(tile)){
            specs->clean();
            specs->flipV=true;
            specs->value = i;
            return true;
        }
        else if(temp.equalFlipHV(tile)){
            specs->clean();
            specs->flipH=true;
            specs->flipV=true;
            specs->value = i;
            return true;
        }
    }
    return false;
}

bool edk::retro::RetroTileSet::addTileEqualTest(edk::retro::RetroTile tile,
                                       edk::retro::RetroTileSpecs* specs
                                       ){
    if(!this->haveEqualTile(tile,specs)){
        edk::uint32 size = this->size();
        specs->value = this->pushBack(tile);
        if(size<this->size()){
            return true;
        }
    }
    return false;
}
bool edk::retro::RetroTileSet::addTileEqualFlipTest(edk::retro::RetroTile tile,
                                       edk::retro::RetroTileSpecs* specs
                                       ){
    if(!this->haveEqualFlipTile(tile,specs)){
        edk::uint32 size = this->size();
        specs->value = this->pushBack(tile);
        if(size<this->size()){
            return true;
        }
    }
    return false;
}
bool edk::retro::RetroTileSet::addTileNoTest(edk::retro::RetroTile tile,
                                             edk::retro::RetroTileSpecs* specs
                                             ){
    edk::uint32 size = this->size();
    specs->value = this->pushBack(tile);
    if(size<this->size()){
        return true;
    }
    return false;
}
edk::retro::RetroPalette* edk::retro::RetroTileSet::getPalette(edk::uint32 position){
    if(this->havePos(position)){
        edk::retro::RetroTile tile = this->get(position);
        return tile.getPalette();
    }
    return NULL;
}

bool edk::retro::RetroTileSet::haveTile(edk::retro::RetroTile tile){
    edk::retro::RetroTile temp;
    edk::uint32 size = this->size();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->get(i);
        if(temp == tile){
            return true;
        }
    }
    return false;
}
edk::uint32 edk::retro::RetroTileSet::getID(edk::retro::RetroTile tile){
    edk::retro::RetroTile temp;
    edk::uint32 size = this->size();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->get(i);
        if(temp == tile){
            return i;
        }
    }
    return 0u;
}
edk::uint32 edk::retro::RetroTileSet::getIDFlipH(edk::retro::RetroTile tile){
    edk::retro::RetroTile temp;
    edk::uint32 size = this->size();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->get(i);
        if(temp.equalFlipH(tile)){
            return i;
        }
    }
    return 0u;
}
edk::uint32 edk::retro::RetroTileSet::getIDFlipV(edk::retro::RetroTile tile){
    edk::retro::RetroTile temp;
    edk::uint32 size = this->size();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->get(i);
        if(temp.equalFlipV(tile)){
            return i;
        }
    }
    return 0u;
}
edk::uint32 edk::retro::RetroTileSet::getIDFlipHV(edk::retro::RetroTile tile){
    edk::retro::RetroTile temp;
    edk::uint32 size = this->size();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->get(i);
        if(temp.equalFlipHV(tile)){
            return i;
        }
    }
    return 0u;
}

//update the tile in position
bool edk::retro::RetroTileSet::updateTile(edk::uint32 position,edk::retro::RetroTile tile){
    if(this->havePos(position)){
        return this->set(position,tile);
    }
    return false;
}

//convert a color ID form a palette
bool edk::retro::RetroTileSet::swapColorID(edk::retro::RetroPalette* palette,edk::uint32 start,edk::uint32 end){
    if(palette){
        edk::uint32 id;
        edk::retro::RetroTile temp;
        edk::uint32 size = this->size();
        for(edk::uint32 i=0u;i<size;i++){
            if(this->havePos(i)){
                temp = this->get(i);
                for(edk::uint8 y=0u;y<8u;y++){
                    for(edk::uint8 x=0u;x<8u;x++){
                        id = temp.getPixel(x,y);
                        if(id == start){
                            temp.setPixel(x,y,end);
                        }
                        else if(id==end){
                            temp.setPixel(x,y,start);
                        }
                    }
                }
                this->set(i,temp);
            }
        }
        return true;
    }
    return false;
}
