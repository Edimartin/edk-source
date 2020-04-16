#include "Sun.h"

/*
Library Sun - Control GU sun lights on the EDK Game Engine
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

edk::light::Sun::Sun(){
    //
}
edk::light::Sun::~Sun(){
    //
}

//DRAW THE LIGH USING THE LIGHT NUMBER
void edk::light::Sun::draw(edk::uint32 lightNumber){
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_POSITION,this->direction);
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_DIFFUSE,this->diffuse);
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_AMBIENT,this->ambient);
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPECULAR,this->specular);
    //edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPOT_DIRECTION,this->direction);
    //edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_EXPONENT,this->exponent);
    //edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_CUTOFF,this->cutoff);
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_CONSTANT_ATTENUATION,this->constantAttenuation);
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_LINEAR_ATTENUATION,this->linearAttenuation);
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_QUADRATIC_ATTENUATION,this->quadraticAttenuation);
}
//draw the pivo
void edk::light::Sun::drawPivo(edk::float32 size,edk::color3f32 color){
    edk::light::Light::drawPivo(size,color);
}

//Set the position of the light
void edk::light::Sun::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setPosition(x,y,z);
}
void edk::light::Sun::setPosition(edk::float32 x,edk::float32 y){
    edk::light::Light::setPosition(x,y);
}
void edk::light::Sun::setPosition(edk::vec3f32 position){
    edk::light::Light::setPosition(position);
}
void edk::light::Sun::setPosition(edk::vec2f32 position){
    edk::light::Light::setPosition(position);
}
void edk::light::Sun::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    this->direction[0u]=x;
    this->direction[1u]=y;
    this->direction[2u]=z;
    this->direction[3u]=0.f;
}
void edk::light::Sun::setDirection(edk::float32 x,edk::float32 y){
    this->setDirection(x,y,this->getDirectionZ());
}
void edk::light::Sun::setDirection(edk::vec3f32 direction){
    this->setDirection(direction.x,direction.y,direction.z);
}
void edk::light::Sun::setDirection(edk::vec2f32 direction){
    this->setDirection(direction.x,direction.y,this->getDirectionZ());
}

//get the position of the light
edk::float32 edk::light::Sun::getPositionX(){
    return edk::light::Light::getPositionX();
}
edk::float32 edk::light::Sun::getPositionY(){
    return edk::light::Light::getPositionY();
}
edk::float32 edk::light::Sun::getPositionZ(){
    return edk::light::Light::getPositionZ();
}
edk::vec2f32 edk::light::Sun::getPosition2f(){
    return edk::light::Light::getPosition2f();
}
edk::vec3f32 edk::light::Sun::getPosition3f(){
    return edk::light::Light::getPosition3f();
}
edk::float32 edk::light::Sun::getDirectionX(){
    return edk::light::Light::getDirectionX();
}
edk::float32 edk::light::Sun::getDirectionY(){
    return edk::light::Light::getDirectionY();
}
edk::float32 edk::light::Sun::getDirectionZ(){
    return edk::light::Light::getDirectionZ();
}
edk::vec2f32 edk::light::Sun::getDirection2f(){
    return edk::light::Light::getDirection2f();
}
edk::vec3f32 edk::light::Sun::getDirection3f(){
    return edk::light::Light::getDirection3f();
}
