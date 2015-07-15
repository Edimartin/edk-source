#ifndef EDK_SHAPE_LINES2D_H
#define EDK_SHAPE_LINES2D_H

/*
Library Lines2D - Draw Lines 2D in EDK Game Engine
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
#warning "Inside Lines2D"
#endif

//Include EDK
#pragma once
#include "Polygon2D.h"

#ifdef printMessages
#warning "    Compiling Lines2D"
#endif

namespace edk{
namespace shape{
class Lines2D: public edk::shape::Polygon2D{
public:
    Lines2D();
    //return true if it's lines
    bool isLine();
    //print the polygon
    virtual void print();
    //Draw the polygon
    virtual void draw();
    //set collisionID
    void setCollisionID(edk::uint8 collisionID);
};
}
}

#endif // EDK_SHAPE_LINES2D_H
