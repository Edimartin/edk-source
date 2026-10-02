#ifndef RETROTILESET_H
#define RETROTILESET_H

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
#pragma message "Inside RetroTileSet"
#endif

#pragma once
#include "./RetroPalette.h"
#include "./RetroTile.h"
#include "../vector/Stack.h"

#ifdef printMessages
#pragma message "    Compiling RetroTileSet"
#endif

namespace edk{
namespace retro{
class RetroTileSet: private edk::vector::Stack<edk::retro::RetroTile>{
public:
    RetroTileSet();
    ~RetroTileSet();

    void Constructor();
    void Destructor();

    void clean(){
        edk::vector::Stack<edk::retro::RetroTile>::clean();
    }

    inline bool havePos(edk::uint32 position){
        return this->edk::vector::Stack<edk::retro::RetroTile>::havePos(position);
    }

    inline edk::uint32 getSize(){
        return this->edk::vector::Stack<edk::retro::RetroTile>::getSize();
    }
    inline edk::uint32 size(){
        return this->edk::vector::Stack<edk::retro::RetroTile>::size();
    }

    bool addTile(edk::retro::RetroTile tile,
                 edk::uint32* position=&edk::retro::RetroTileSet::staticPosition
            );
    bool addTileNoTest(edk::retro::RetroTile tile,
                       edk::uint32* position=&edk::retro::RetroTileSet::staticPosition
            );

    edk::retro::RetroTile get(edk::uint32 position){
        return this->edk::vector::Stack<edk::retro::RetroTile>::get(position);
    }
    edk::retro::RetroPalette* getPalette(edk::uint32 position);

    bool haveTile(edk::retro::RetroTile tile);
    edk::uint32 getID(edk::retro::RetroTile tile);

    //update the tile in position
    bool updateTile(edk::uint32 position,edk::retro::RetroTile tile);

    //convert a color ID form a palette
    bool swapColorID(edk::retro::RetroPalette* palette,edk::uint32 start,edk::uint32 end);
private:
    //search for equal tiles
    bool haveEqualTile(edk::retro::RetroTile tile);

    static edk::uint32 staticPosition;
private:
    edk::classID classThis;
};
}//end namespace retro
}//end namespace edk

#endif // RETROTILESET_H
