#ifndef EDK_SHAPE_BEZIER3D_H
#define EDK_SHAPE_BEZIER3D_H

/*
Library Bezier3D - Bezier curve 3D in EDK Game Engine
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
#warning "Inside Bezier3D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec3.h"
#include "Curve3D.h"

#ifdef printMessages
#warning "    Compiling Bezier3D"
#endif

namespace edk{
namespace shape{
class Bezier3D : public edk::shape::Curve3D{
    public:
        Bezier3D();
        Bezier3D(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4);
        virtual ~Bezier3D();

        //return the point
        edk::vec3f32 getPoint(edk::float32 percent);
        static edk::vec3f32 getPoint(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4,edk::float32 percent);
    protected:
    private:
};
}//end namespace shape
}//end namespace edk

#endif // BEZIER3D_H
