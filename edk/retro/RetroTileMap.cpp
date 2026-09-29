#include "RetroTileMap.h"
/*
Library C++ RetroTileMap - Retro TileMap used in EDK
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
#pragma message "            Inside RetroTileMap.cpp"
#endif

edk::uint64 edk::retro::RetroTileMap::staticCounter=0uL;
edk::retro::RetroTileSet edk::retro::RetroTileMap::staticSet;

edk::retro::RetroTileMap::RetroTileMap(){
    this->classThis=NULL;
    this->Constructor();
}
edk::retro::RetroTileMap::~RetroTileMap(){
    this->Destructor();
}

void edk::retro::RetroTileMap::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->map.Constructor();

        if(!edk::retro::RetroTileMap::staticCounter){
            //
            edk::retro::RetroTileMap::staticSet.Constructor();
        }
        edk::retro::RetroTileMap::staticCounter++;
    }
}
void edk::retro::RetroTileMap::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;

        this->map.Destructor();

        if(edk::retro::RetroTileMap::staticCounter){
            edk::retro::RetroTileMap::staticCounter--;
            if(!edk::retro::RetroTileMap::staticCounter){
                //
                edk::retro::RetroTileMap::staticSet.Destructor();
            }
        }
    }
}

void edk::retro::RetroTileMap::clean(){
    if(this->map.haveMatrix()){
        this->map.deleteMatrix();
    }
}

void edk::retro::RetroTileMap::cleanIDs(){
    if(this->map.haveMatrix()){
        edk::uint32 width=this->map.getWidth(),height=this->map.getHeight();
        for(edk::uint32 y=0u;y<height;y++){
            for(edk::uint32 x=0u;x<width;x++){
                this->map.set(x,y,0xFF*sizeof(edk::uint32));
            }
        }
    }
}

//create a new map
bool edk::retro::RetroTileMap::newMap(edk::size2ui32 size){
    this->clean();
    if(size.width && size.height){
        return this->map.createMatrix(size);
    }
    return false;
}
bool edk::retro::RetroTileMap::newMap(edk::uint32 width,edk::uint32 height){
    return this->newMap(edk::size2ui32(width,height));
}

edk::size2ui32 edk::retro::RetroTileMap::getSize(){
    return this->map.getSize();
}
edk::uint32 edk::retro::RetroTileMap::getWidth(){
    return this->map.getWidth();
}
edk::uint32 edk::retro::RetroTileMap::getHeight(){
    return this->map.getHeight();
}

//set and get
bool edk::retro::RetroTileMap::setID(edk::vec2ui32 position,edk::uint32 id){
    if(this->map.have(position)){
        return this->map.set(position,id);
    }
    return false;
}
bool edk::retro::RetroTileMap::setID(edk::uint32 x,edk::uint32 y,edk::uint32 id){
    return this->setID(edk::vec2ui32(x,y),id);
}
edk::uint32 edk::retro::RetroTileMap::getID(edk::vec2ui32 position){
    if(this->map.haveMatrix()){
        return this->map.get(position);
    }
    return 0u;
}
edk::uint32 edk::retro::RetroTileMap::getID(edk::uint32 x,edk::uint32 y){
    return this->getID(edk::vec2ui32(x,y));
}

//set the tileSet
bool edk::retro::RetroTileMap::setTileSet(edk::retro::RetroTileSet* set){
    if(set){
        this->set = set;
        return true;
    }
    this->set = &edk::retro::RetroTileMap::staticSet;
    return false;
}
