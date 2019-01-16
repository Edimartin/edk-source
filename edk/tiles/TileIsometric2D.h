#ifndef TILEISOMETRIC2D_H
#define TILEISOMETRIC2D_H

/*
Library TileIsometric2D -Tile to be used in a Isometric TimeSet.
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "Inside TileIsometric2D"
#endif

#pragma once
#include "Tile2D.h"

#ifdef printMessages
#warning "    Compiling TileIsometric2D"
#endif

namespace edk{
namespace tiles{
class TileIsometric2D : public edk::tiles::Tile2D{
public:
    TileIsometric2D();
    virtual ~TileIsometric2D();

    //return the type of the tile to the tileSet know witch tile is before delete it
    virtual edk::tiles::tile2DType getType();
};
}
}

#endif // TILEISOMETRIC2D_H
