#ifndef EDK_SHAPE_CIRCLE2D_H
#define EDK_SHAPE_CIRCLE2D_H

/*
Library Circle2D - Draw a Circle in EDK Game Engine
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
#warning "Inside Circle2D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec2.h"
#include "../TypeColor.h"
#include "Polygon2D.h"
//Math
#include "../Math.h"

#ifdef printMessages
#warning "    Compiling Circle2D"
#endif

namespace edk{
namespace shape{
class Circle2D: public edk::shape::Polygon2D{
    public:
        Circle2D();
        Circle2D(edk::uint32 sides,edk::float32 radius);
        virtual ~Circle2D();
        //radius of the circle
        //edk::float32 radius;

        //Create the circle
        bool createPolygon(edk::uint32 sides,edk::float32 radius);

        //delete the polygonVertex
        void deletePolygon();

        //Set the color
        bool setPolygonColor(edk::color4f32 color);
        bool setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b);
        bool setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);

        //print the polygon
        void print();
        //Draw the polygon
        void draw();
        void drawWire();
    protected:
    private:
};
}//end namespace shape
}//end namespace edk

#endif // CIRCLE2D_H
