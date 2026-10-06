#ifndef RETROIMAGECONVERTER_H
#define RETROIMAGECONVERTER_H

/*
Library RetroImageConverter - Retro class to convert images using EDK
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

#ifdef printMessages
#pragma message "Inside RetroImageConverter"
#endif

//Include the binaryTree to save the elements
#pragma once
#include "../TypeVars.h"
#include "RetroPalette.h"
#include "RetroTile.h"
#include "RetroTileMap.h"
#include "../MemoryBuffer.h"
#include "../Math.h"
#include "../BinaryConverter.h"

#ifdef printMessages
#pragma message "    Compiling RetroImageConverter"
#endif

namespace edk{
class RetroImageConverter{
public:
    RetroImageConverter();
    ~RetroImageConverter();

    void Constructor();
    void Destructor();

    //convert retroIMG to sms
    //H
    static edk::MemoryBuffer<edk::char8>* retroIMGtoCodeH_SMS(edk::char8* name,
                                                              edk::retro::RetroPalette* palette,
                                                              edk::retro::RetroTileSet* set,
                                                              edk::retro::RetroTileMap* map
                                                              );
    static bool retroIMGtoCodeFileH_SMS(const edk::char8* fileName,
                                        edk::retro::RetroPalette* palette,
                                        edk::retro::RetroTileSet* set,
                                        edk::retro::RetroTileMap* map
                                        );
    static bool retroIMGtoCodeFileH_SMS(edk::char8* fileName,
                                        edk::retro::RetroPalette* palette,
                                        edk::retro::RetroTileSet* set,
                                        edk::retro::RetroTileMap* map
                                        );
    //CPP
    static edk::MemoryBuffer<edk::char8>* retroIMGtoHeaderH_SMS(edk::char8* name,
                                                                edk::retro::RetroPalette* palette,
                                                                edk::retro::RetroTileSet* set,
                                                                edk::retro::RetroTileMap* map
                                                                );
    static edk::MemoryBuffer<edk::char8>* retroIMGtoCodeCPP_SMS(edk::char8* name,
                                                                edk::retro::RetroPalette* palette,
                                                                edk::retro::RetroTileSet* set,
                                                                edk::retro::RetroTileMap* map
                                                                );
    static bool retroIMGtoCodeFileCPP_SMS(const edk::char8* fileNameH,
                                          const edk::char8* fileNameCPP,
                                          edk::retro::RetroPalette* palette,
                                          edk::retro::RetroTileSet* set,
                                          edk::retro::RetroTileMap* map
                                          );
    static bool retroIMGtoCodeFileCPP_SMS(edk::char8* fileNameH,
                                          edk::char8* fileNameCPP,
                                          edk::retro::RetroPalette* palette,
                                          edk::retro::RetroTileSet* set,
                                          edk::retro::RetroTileMap* map
                                          );
private:
    static edk::uint8 rgb8ToSMSRound(edk::uint8 r, edk::uint8 g, edk::uint8 b);
    static edk::uint8 rgb8ToSMSRound(edk::color3ui8 color);
    static edk::uint8 rgb8ToSMSRound(edk::color4ui8 color);
    static edk::uint8 rgb8ToSMSFast(edk::uint8 r, edk::uint8 g, edk::uint8 b);
    static edk::uint8 rgb8ToSMSFast(edk::color3ui8 color);
    static edk::uint8 rgb8ToSMSFast(edk::color4ui8 color);
private:
    edk::classID classThis;
};
}

#endif // RETROIMAGECONVERTER_H
