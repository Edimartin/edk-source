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
    edk::uint16 getValueSMS(edk::vec2ui32 position);
    edk::uint16 getValueSMS(edk::uint32 x,edk::uint32 y);
    edk::retro::RetroTileSpecs getSpecs(edk::vec2ui32 position);
    edk::retro::RetroTileSpecs getSpecs(edk::uint32 x,edk::uint32 y);

    //bits
    bool setFlipH(edk::vec2ui32 position,bool flipH);
    bool setFlipH(edk::uint32 x,edk::uint32 y,bool flipH);
    bool setFlipV(edk::vec2ui32 position,bool flipV);
    bool setFlipV(edk::uint32 x,edk::uint32 y,bool flipV);
    bool setUsingPalette(edk::vec2ui32 position,bool usingPalette);
    bool setUsingPalette(edk::uint32 x,edk::uint32 y,bool usingPalette);
    bool setUsingPriority(edk::vec2ui32 position,bool priority);
    bool setUsingPriority(edk::uint32 x,edk::uint32 y,bool priority);
    bool getFlipH(edk::vec2ui32 position);
    bool getFlipH(edk::uint32 x,edk::uint32 y);
    bool getFlipV(edk::vec2ui32 position);
    bool getFlipV(edk::uint32 x,edk::uint32 y);
    bool getUsingPalette(edk::vec2ui32 position);
    bool getUsingPalette(edk::uint32 x,edk::uint32 y);
    bool getUsingPriority(edk::vec2ui32 position);
    bool getUsingPriority(edk::uint32 x,edk::uint32 y);


    //set the tileSet
    bool setTileSet(edk::retro::RetroTileSet* set);
private:

    //change it to SMS
    /*
    Bit:  15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
          ┌───┬───┬───┬───┬───┴───┴───────────────────────────────────────┐
          │ - │ P │ C │ V │ H │             TILE NUMBER                  │
          └───┴───┴───┴───┴───┴───────────────────────────────────────────┘
           3    1   1   1   1                    9 bits

    Bits	Function
    0–8	    ID of tile — 9 bits
    9	    Flip horizontal
    10	    Flip vertical
    11	    Select palette
    12	    Priority over sprites (background tile will be draw in front of the sprites. Like a TREE on the front)
    13–15	Não usados/reservados
    */
    class TileInsideMap : public edk::retro::RetroTileSpecs{
    public:
        TileInsideMap(){
            this->value=0u;
            this->flipH=false;
            this->flipV=false;
            this->usingPalette=false;
            this->priority=false;
        }
        ~TileInsideMap(){}
        inline bool operator==(edk::retro::RetroTileMap::TileInsideMap tile){
            if(this->value==tile.value
                    && this->flipH==tile.flipH
                    && this->flipV==tile.flipV
                    && this->usingPalette==tile.usingPalette
                    && this->priority==tile.priority
                    ){
                return true;
            }
            return false;
        }
        inline edk::retro::RetroTileMap::TileInsideMap operator=(edk::retro::RetroTileMap::TileInsideMap tile){
            this->value=tile.value;
            this->flipH=tile.flipH;
            this->flipV=tile.flipV;
            this->usingPalette=tile.usingPalette;
            this->priority=tile.priority;
            return *this;
        }

        //get the tileValue for sms
        edk::uint16 getValueSMS(){
            edk::uint16 ret = (this->value<<9u)>>9u;
            if(this->flipH){
                //pos 9
                ret |= 0b0000001000000000;
            }
            if(this->flipV){
                //pos 10
                ret |= 0b0000010000000000;
            }
            if(this->usingPalette){
                //pos 11
                ret |= 0b0000100000000000;
            }
            if(this->priority){
                //pos 12
                ret |= 0b0001000000000000;
            }
            return ret;
        }
        inline edk::retro::RetroTileMap::TileInsideMap operator*(edk::retro::RetroTileMap::TileInsideMap /*tile*/){
            return *this;
        }
        inline edk::retro::RetroTileMap::TileInsideMap operator*(edk::int32 /*value*/){
            return *this;
        }
        inline edk::retro::RetroTileMap::TileInsideMap operator+(edk::retro::RetroTileMap::TileInsideMap /*tile*/){
            return *this;
        }
        inline edk::retro::RetroTileMap::TileInsideMap operator-(edk::retro::RetroTileMap::TileInsideMap /*tile*/){
            return *this;
        }
        inline edk::retro::RetroTileMap::TileInsideMap operator/(edk::retro::RetroTileMap::TileInsideMap /*tile*/){
            return *this;
        }
        bool usingPalette;
        bool priority;
    };

    edk::vector::MatrixDynamic<edk::retro::RetroTileMap::TileInsideMap> map;

    edk::retro::RetroTileSet* set;

    static edk::uint64 staticCounter;
    static edk::retro::RetroTileSet staticSet;
private:
    edk::classID classThis;
};
}//end namespace retro
}//end namespace edk

#endif // RETROTILEMAP_H
