#ifndef RETROPALETTES_H
#define RETROPALETTES_H

/*
Library C++ RetroPalettes - Save retro palettes in EDK
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
#pragma message "Inside RetroPalettes"
#endif

#pragma once
#include "./RetroPalette.h"
#include "../vector/BinaryTree.h"

#ifdef printMessages
#pragma message "    Compiling RetroPalettes"
#endif

namespace edk{
namespace retro{
class RetroPalettes: public edk::vector::BinaryTree<edk::retro::RetroPalette*>{
public:
    RetroPalettes();
    ~RetroPalettes();

    void Constructor();
    void Destructor();

    //compare if the value is bigger
    virtual bool firstBiggerSecond(edk::retro::RetroPalette* first,edk::retro::RetroPalette* second);
    //compare if the value is equal
    virtual bool firstEqualSecond(edk::retro::RetroPalette* first,edk::retro::RetroPalette* second);

    //delete all palettes
    void clean();

    //new palette
    edk::retro::RetroPalette* newPalette(edk::uint32 size,edk::uint8 channels,edk::uint8 bytesPerChannel);
    edk::retro::RetroPalette* newPaletteFromVector(edk::uint8* palette,
                                                   edk::uint32 size,
                                                   edk::uint8 channels,
                                                   edk::uint8 bytesPerChannel
                                                   );
    bool deletePalette(edk::retro::RetroPalette* palette);
    bool deletePaletteInPosition(edk::uint32 position);
private:
    edk::classID classThis;
};
}//end namespace retro
}//end namespace edk

#endif // RETROPALETTES_H
