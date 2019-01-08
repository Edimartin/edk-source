#ifndef DYNAMICSENSOR2D_H
#define DYNAMICSENSOR2D_H

/*
Library DynamicSensor2D - Dynamic Sensors in physics2D
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
#warning "Inside DynamicSensor2D"
#endif

#pragma once
#include <stdio.h>
#include "PhysicObject2D.h"
#include "StaticSensor2D.h"
#include "KinematicSensor2D.h"

#ifdef printMessages
#warning "    Compiling DynamicSensor2D"
#endif

namespace edk{
namespace physics2D{
class DynamicSensor2D: public edk::physics2D::KinematicSensor2D{
public:
    DynamicSensor2D();
    ~DynamicSensor2D();
};
}
}


#endif // DYNAMICSENSOR2D_H
