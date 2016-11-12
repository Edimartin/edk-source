#ifndef EDK_SHAPE_BEZIER2D_H
#define EDK_SHAPE_BEZIER2D_H

/*
Library Bezier2D - Bezier curve 2D in EDK Game Engine
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
#warning "Inside Bezier2D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec2.h"
#include "Curve2D.h"

#ifdef printMessages
#warning "    Compiling Bezier2D"
#endif

namespace edk{
namespace shape{
class Bezier2D:public edk::shape::Curve2D{
    public:
        Bezier2D();
        Bezier2D(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4);
        virtual ~Bezier2D();

        //Implement the Bezier Curve
        edk::vec2f32 getPoint(edk::float32 percent);

        static edk::vec2f32 getPoint(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4,edk::float32 percent);
    protected:
    private:
};
}//end namespace shape
}//end namespace edk

#endif // BEZIER2D_H
