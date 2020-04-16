#ifndef POINT_H
#define POINT_H

/*
Library Point - Control GU point lights on the EDK Game Engine
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
#warning "Inside Point"
#endif

#pragma once
#include "../TypeVars.h"
#include "../GU/GU.h"
#include "Light.h"

#ifdef printMessages
#warning "    Compiling Point"
#endif

namespace edk{
namespace light{
class Point: public edk::light::Light{
public:
    Point();
    ~Point();
    //DRAW THE LIGH USING THE LIGHT NUMBER
    virtual void draw(edk::uint32 lightNumber);

    //Set the position of the light
    void setPosition(edk::float32 x,edk::float32 y,edk::float32 z);
    void setPosition(edk::float32 x,edk::float32 y);
    void setPosition(edk::vec3f32 position);
    void setPosition(edk::vec2f32 position);

    //get the position of the light
    edk::float32 getPositionX();
    edk::float32 getPositionY();
    edk::float32 getPositionZ();
    edk::vec2f32 getPosition2f();
    edk::vec3f32 getPosition3f();
};
}//end namespace light
}//end namespace edk

#endif // POINT_H
