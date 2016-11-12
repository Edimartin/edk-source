#ifndef EDK_SHAPE_CURVE2D_H
#define EDK_SHAPE_CURVE2D_H

/*
Library Curve2D - Template for a 2D Curve in EDK Game Engine
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
#warning "Inside Curve2D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec2.h"

#ifdef printMessages
#warning "    Compiling Curve2D"
#endif

namespace edk{
namespace shape{
class Curve2D{
    public:
        Curve2D();
        Curve2D(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4);
        virtual ~Curve2D();

        //return the point
        virtual edk::vec2f32 getPoint(edk::float32 percent);

        //the points of the curve
        edk::vec2f32 point1,point2,point3,point4;

    protected:
    private:
};
}//end namespace shape
}//end namespace edk

#endif // CURVE2D_H
