#ifndef OBJECT3DVALUES_H
#define OBJECT3DVALUES_H

/*
Library Object3DValues - 3D Position angle and size
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
#warning "Inside Object3DValues"
#endif

#pragma once
#include "TypeVec3.h"
#include "TypeSize3.h"

#ifdef printMessages
#warning "    Compiling Object3DValues"
#endif

namespace edk{
class Object3DValues
{
public:
    Object3DValues();
    ~Object3DValues();
    edk::vec3f32 position;
    edk::vec3f32 angle;
    edk::size3f32 size;
    bool fixedRotation;
    void loadIdentityValues();
};
}//end namespace edk

#endif // OBJECT3DVALUES_H
