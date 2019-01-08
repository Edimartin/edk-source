#ifndef DYNAMICOBJECT2D_H
#define DYNAMICOBJECT2D_H

/*
Library DynamicObject2D - Dinamic Objects in physics2D
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
#warning "Inside DynamicObject2D"
#endif

#pragma once
#include <stdio.h>
#include "PhysicObject2D.h"
#include "KinematicObject2D.h"

#ifdef printMessages
#warning "    Compiling DynamicObject2D"
#endif


namespace edk{
namespace physics2D{
class DynamicObject2D : public edk::physics2D::KinematicObject2D{
public:
    DynamicObject2D();
    ~DynamicObject2D();
};
}
}

#endif // DYNAMICOBJECT2D_H
