#ifndef RETROTILEMAP_H
#define RETROTILEMAP_H

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
#pragma message "Inside RetroTileMap"
#endif

#pragma once
#include "./RetroPalette.h"
#include "./RetroTile.h"
#include "./RetroTileSet.h"
#include "../vector/Matrix.h"

#ifdef printMessages
#pragma message "    Compiling RetroTileMap"
#endif

namespace edk{
namespace retro{
class RetroTileMap{
public:
    RetroTileMap();
    ~RetroTileMap();

    void Constructor();
    void Destructor();

    void clean();
    inline void deleteMap(){
        this->clean();
    }

    void cleanIDs();

    //create a new map
    bool newMap(edk::size2ui32 size);
    bool newMap(edk::uint32 width,edk::uint32 height);

    edk::size2ui32 getSize();
    edk::uint32 getWidth();
    edk::uint32 getHeight();

    //set and get
    bool setID(edk::vec2ui32 position,edk::uint32 id);
    bool setID(edk::uint32 x,edk::uint32 y,edk::uint32 id);
    edk::uint32 getID(edk::vec2ui32 position);
    edk::uint32 getID(edk::uint32 x,edk::uint32 y);

    //set the tileSet
    bool setTileSet(edk::retro::RetroTileSet* set);
private:
    edk::vector::MatrixDynamic<edk::uint32> map;

    edk::retro::RetroTileSet* set;

    static edk::uint64 staticCounter;
    static edk::retro::RetroTileSet staticSet;
private:
    edk::classID classThis;
};
}//end namespace retro
}//end namespace edk

#endif // RETROTILEMAP_H
