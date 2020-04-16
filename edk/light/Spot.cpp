#include "Spot.h"

/*
Library Spor - Control GU spot lights on the EDK Game Engine
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

edk::light::Spot::Spot(){
    //
}
edk::light::Spot::~Spot(){
    //
}

//DRAW THE LIGH USING THE LIGHT NUMBER
void edk::light::Spot::draw(edk::uint32 lightNumber){
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_POSITION,this->position);
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_DIFFUSE,this->diffuse);
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_AMBIENT,this->ambient);
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPECULAR,this->specular);
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPOT_DIRECTION,this->direction);
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_EXPONENT,this->exponent);
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_CUTOFF,this->cutoff);
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_CONSTANT_ATTENUATION,this->constantAttenuation);
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_LINEAR_ATTENUATION,this->linearAttenuation);
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_QUADRATIC_ATTENUATION,this->quadraticAttenuation);
}
//draw the pivo
void edk::light::Spot::drawPivo(edk::float32 size,edk::color3f32 color){
    edk::light::Light::drawPivo(size,color);
}

//Set the position of the light
void edk::light::Spot::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setPosition(x,y,z);
}
void edk::light::Spot::setPosition(edk::float32 x,edk::float32 y){
    edk::light::Light::setPosition(x,y);
}
void edk::light::Spot::setPosition(edk::vec3f32 position){
    edk::light::Light::setPosition(position);
}
void edk::light::Spot::setPosition(edk::vec2f32 position){
    edk::light::Light::setPosition(position);
}
void edk::light::Spot::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setDirection(x,y,z);
}
void edk::light::Spot::setDirection(edk::float32 x,edk::float32 y){
    edk::light::Light::setDirection(x,y);
}
void edk::light::Spot::setDirection(edk::vec3f32 direction){
    edk::light::Light::setDirection(direction);
}
void edk::light::Spot::setDirection(edk::vec2f32 direction){
    edk::light::Light::setDirection(direction);
}
//Spot Values
void edk::light::Spot::setExponent(edk::float32 exponent){
    edk::light::Light::setExponent(exponent);
}
void edk::light::Spot::setCutoff(edk::float32 cutoff){
    edk::light::Light::setCutoff(cutoff);
}
void edk::light::Spot::setConstantAttenuation(edk::float32 constantAttenuation){
    edk::light::Light::setConstantAttenuation(constantAttenuation);
}
void edk::light::Spot::setLinearAttenuation(edk::float32 linearAttenuation){
    edk::light::Light::setLinearAttenuation(linearAttenuation);
}
void edk::light::Spot::setQuadraticAttenuation(edk::float32 quadraticAttenuation){
    edk::light::Light::setQuadraticAttenuation(quadraticAttenuation);
}

//get the position of the light
edk::float32 edk::light::Spot::getPositionX(){
    return edk::light::Light::getPositionX();
}
edk::float32 edk::light::Spot::getPositionY(){
    return edk::light::Light::getPositionY();
}
edk::float32 edk::light::Spot::getPositionZ(){
    return edk::light::Light::getPositionZ();
}
edk::vec2f32 edk::light::Spot::getPosition2f(){
    return edk::light::Light::getPosition2f();
}
edk::vec3f32 edk::light::Spot::getPosition3f(){
    return edk::light::Light::getPosition3f();
}
edk::float32 edk::light::Spot::getDirectionX(){
    return edk::light::Light::getDirectionX();
}
edk::float32 edk::light::Spot::getDirectionY(){
    return edk::light::Light::getDirectionY();
}
edk::float32 edk::light::Spot::getDirectionZ(){
    return edk::light::Light::getDirectionZ();
}
edk::vec2f32 edk::light::Spot::getDirection2f(){
    return edk::light::Light::getDirection2f();
}
edk::vec3f32 edk::light::Spot::getDirection3f(){
    return edk::light::Light::getDirection3f();
}

//Spot Values
edk::float32 edk::light::Spot::getExponent(){
    return edk::light::Light::getExponent();
}
edk::float32 edk::light::Spot::getCutoff(){
    return edk::light::Light::getCutoff();
}
edk::float32 edk::light::Spot::getConstantAttenuation(){
    return edk::light::Light::getConstantAttenuation();
}
edk::float32 edk::light::Spot::getLinearAttenuation(){
    return edk::light::Light::getLinearAttenuation();
}
edk::float32 edk::light::Spot::getQuadraticAttenuation(){
    return edk::light::Light::getQuadraticAttenuation();
}
