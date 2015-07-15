#ifndef EDK_SHAPE_HERMITE3D_H
#define EDK_SHAPE_HERMITE3D_H

/*
Library Hermite3D - Hermite curve 3D in EDK Game Engine
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
#warning "Inside Hermite3D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec3.h"
#include "Curve3D.h"

#ifdef printMessages
#warning "    Compiling Hermite3D"
#endif

namespace edk{
namespace shape{
class Hermite3D : public edk::shape::Curve3D{
    public:
        Hermite3D();
        Hermite3D(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4);
        virtual ~Hermite3D();

        //return the point
        edk::vec3f32 getPoint(float percent);
        static edk::vec3f32 getPoint(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4,float percent,edk::float32 atenuation);

        //Atenuation
        edk::float32 attenuation;
    protected:
    private:
};
}//end namespace shape
}//end namespace edk

#endif // HERMITE3D_H
