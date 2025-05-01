#ifndef TILEISOMETRICFLAT2D_H
#define TILEISOMETRICFLAT2D_H

/*
Library TileIsometricFlat -Tile to be used in a Isometric TimeSet with flat texture.
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
#pragma message "Inside TileIsometricFlat"
#endif

#pragma once
#include "Tile2D.h"

#ifdef printMessages
#pragma message "    Compiling TileIsometricFlat"
#endif

namespace edk{
namespace tiles{
class TileIsometricFlat2D : public edk::tiles::Tile2D{
public:
    TileIsometricFlat2D();
    virtual ~TileIsometricFlat2D();

    void Constructor();
    void Destructor();

    //return the type of the tile to the tileSet know witch tile is before delete it
    edk::tiles::tile2DType getType();
private:
    edk::classID classThis;
};
}
}

#endif // TILEISOMETRICFLAT_H
