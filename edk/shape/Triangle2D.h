#ifndef EDK_SHAPE_TRIANGLE2D_H
#define EDK_SHAPE_TRIANGLE2D_H

/*
Library Triangle2D - Draw a 2D Triangle in EDK Game Engine
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
#warning "Inside Triangle2D"
#endif

//Include the polygon
#pragma once
#include "Polygon2D.h"

#ifdef printMessages
#warning "    Compiling Triangle2D"
#endif

namespace edk{
namespace shape{
class Triangle2D : public edk::shape::Polygon2D{
    public:
        Triangle2D();
        virtual ~Triangle2D();

        //Virtual Functions
        bool createPolygon(edk::uint32 vertexCount);
        void deletePolygon();

        //print the triangle
        void print();
        //Draw the triangle
        void draw();
        void drawWire();
    protected:
    private:
    //createPolygon
    bool createPolygon();
};
}//end namespace shape
}//end namespace edk

#endif // TRIANGLE2D_H
