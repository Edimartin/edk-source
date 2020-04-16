#ifndef SPOT_H
#define SPOT_H

/*
Library Spot - Control GU spot lights on the EDK Game Engine
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
#warning "Inside SUN"
#endif

#pragma once
#include "../TypeVars.h"
#include "../GU/GU.h"
#include "Light.h"

#ifdef printMessages
#warning "    Compiling SUN"
#endif

namespace edk{
namespace light{
class Spot : public edk::light::Light{
public:
    Spot();
    ~Spot();

    //DRAW THE LIGH USING THE LIGHT NUMBER
    void draw(edk::uint32 lightNumber);
    //draw the pivo
    void drawPivo(edk::float32 size,edk::color3f32 color);

    //Set the position of the light
    void setPosition(edk::float32 x,edk::float32 y,edk::float32 z);
    void setPosition(edk::float32 x,edk::float32 y);
    void setPosition(edk::vec3f32 position);
    void setPosition(edk::vec2f32 position);
    void setDirection(edk::float32 x,edk::float32 y,edk::float32 z);
    void setDirection(edk::float32 x,edk::float32 y);
    void setDirection(edk::vec3f32 direction);
    void setDirection(edk::vec2f32 direction);
    //Spot Values
    void setExponent(edk::float32 exponent);
    void setCutoff(edk::float32 cutoff);
    void setConstantAttenuation(edk::float32 constantAttenuation);
    void setLinearAttenuation(edk::float32 linearAttenuation);
    void setQuadraticAttenuation(edk::float32 quadraticAttenuation);

    //get the position of the light
    edk::float32 getPositionX();
    edk::float32 getPositionY();
    edk::float32 getPositionZ();
    edk::vec2f32 getPosition2f();
    edk::vec3f32 getPosition3f();
    edk::float32 getDirectionX();
    edk::float32 getDirectionY();
    edk::float32 getDirectionZ();
    edk::vec2f32 getDirection2f();
    edk::vec3f32 getDirection3f();

    //Spot Values
    edk::float32 getExponent();
    edk::float32 getCutoff();
    edk::float32 getConstantAttenuation();
    edk::float32 getLinearAttenuation();
    edk::float32 getQuadraticAttenuation();
};
}//end namespace light
}//end namespace edk

#endif // SPOT_H
