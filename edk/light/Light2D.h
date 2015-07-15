#ifndef EDK_LIGHT_LIGHT2D_H
#define EDK_LIGHT_LIGHT2D_H

/*
Library Light2D - Control GU lights on the EDK Game Engine
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
#warning "Inside Light2D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../GU/GU.h"
#include "Light.h"

#ifdef printMessages
#warning "    Compiling Light2D"
#endif

namespace edk{
namespace light{
class Light2D : public edk::light::Light{
public:
    Light2D();

    //Set the 2D Values
    void setPosition(edk::float32 x,edk::float32 y);
    void setPosition(edk::vec2f32 position);
    void setZ(edk::float32 z);
    void setDirection(edk::float32 x,edk::float32 y);
    void setDirection(edk::vec2f32 direction);
};
}//end namespace light
}//end namespace edk

#endif // LIGHT2D_H

/*
GU_SPOT_DIRECTION (0.0, 0.0, -1.0) (x, y, z) direction of spotlight

GU_SPOT_EXPONENT 0.0 spotlight exponent

GU_SPOT_CUTOFF 180.0 spotlight cutoff angle

GU_CONSTANT_ATTENUATION 1.0 constant attenuation factor

GU_LINEAR_ATTENUATION 0.0 linear attenuation factor

GU_QUADRATIC_ATTENUATION 0.0 quadratic attenuation factor
*/
