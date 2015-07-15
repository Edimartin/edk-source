#include "Light2D.h"

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
#warning "            Inside Light2D.cpp"
#endif

edk::light::Light2D::Light2D(){
    //
}

//Set the 2D Values
void edk::light::Light2D::setPosition(edk::float32 x,edk::float32 y){
    edk::light::Light::setPosition(x,y);
}
void edk::light::Light2D::setPosition(edk::vec2f32 position){
    edk::light::Light::setPosition(position);
}
void edk::light::Light2D::setZ(edk::float32 z){
    edk::light::Light::position[2u] = z;
}
void edk::light::Light2D::setDirection(edk::float32 x,edk::float32 y){
    edk::light::Light::setDirection(x,y);
}
void edk::light::Light2D::setDirection(edk::vec2f32 direction){
    edk::light::Light::setDirection(direction);
}
