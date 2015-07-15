#include "Light.h"

/*
Library Light - Control GU lights on the EDK Game Engine
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
#warning "            Inside Light.cpp"
#endif

edk::light::Light::Light()
{
    this->clean();
    this->on = false;
}
//clean the light
void edk::light::Light::clean(){
    this->position[0u] = 0.f;
    this->position[1u] = 0.f;
    this->position[2u] = 1.f;
    this->position[3u] = 1.f;

    this->diffuse[0u] = 1.f;
    this->diffuse[1u] = 1.f;
    this->diffuse[2u] = 1.f;
    this->diffuse[3u] = 1.f;

    this->ambient[0u] = 0.f;
    this->ambient[1u] = 0.f;
    this->ambient[2u] = 0.f;
    this->ambient[3u] = 1.f;

    this->specular[0u] = 1.f;
    this->specular[1u] = 1.f;
    this->specular[2u] = 1.f;
    this->specular[3u] = 1.f;

    this->direction[0u] = 0.f;
    this->direction[1u] = 0.f;
    this->direction[2u] = 1.f;
    this->direction[2u] = 1.f;

    this->exponent=0.f;
    this->cutoff=180.f;
    this->constantAttenuation=1.f;
    this->linearAttenuation=0.f;
    this->quadraticAttenuation=0.f;
}
//Set Vectors
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    this->position[0u] = x;this->position[1u] = y;this->position[2u] = z;this->position[3u] = w;
}
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    this->position[0u] = x;this->position[1u] = y;this->position[2u] = z;
}
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y){
    this->position[0u] = x;this->position[1u] = y;
}
void edk::light::Light::setPosition(edk::vec4f32 position){
    return this->setPosition(position.x,position.y,position.z,position.w);
}
void edk::light::Light::setPosition(edk::vec3f32 position){
    return this->setPosition(position.x,position.y,position.z);
}
void edk::light::Light::setPosition(edk::vec2f32 position){
    return this->setPosition(position.x,position.y);
}
void edk::light::Light::setDirection(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    this->direction[0u] = x;this->direction[1u] = y;this->direction[2u] = z;this->direction[3u] = w;
}
void edk::light::Light::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    this->direction[0u] = x;this->direction[1u] = y;this->direction[2u] = z;
}
void edk::light::Light::setDirection(edk::float32 x,edk::float32 y){
    this->direction[0u] = x;this->direction[1u] = y;
}
void edk::light::Light::setDirection(edk::vec4f32 direction){
    return this->setDirection(direction.x,direction.y,direction.z,direction.w);
}
void edk::light::Light::setDirection(edk::vec3f32 direction){
    return this->setDirection(direction.x,direction.y,direction.z);
}
void edk::light::Light::setDirection(edk::vec2f32 direction){
    return this->setDirection(direction.x,direction.y);
}
//Spot Values
void edk::light::Light::setExponent(edk::float32 exponent){
    this->exponent = exponent;
}
void edk::light::Light::setCutoff(edk::float32 cutoff){
    this->cutoff=cutoff;
}
void edk::light::Light::setConstantAttenuation(edk::float32 constantAttenuation){
    this->constantAttenuation=constantAttenuation;
}
void edk::light::Light::setLinearAttenuation(edk::float32 linearAttenuation){
    this->linearAttenuation=linearAttenuation;
}
void edk::light::Light::setQuadraticAttenuation(edk::float32 quadraticAttenuation){
    this->quadraticAttenuation=quadraticAttenuation;
}

//Set Colors
void edk::light::Light::setAmbient(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->ambient[0u] = r;this->ambient[1u] = g;this->ambient[2u] = b;this->ambient[3u] = a;
}
void edk::light::Light::setAmbient(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setAmbient(r,g,b,1.f);
}
void edk::light::Light::setAmbient(edk::color4f32 color){
    return this->setAmbient(color.r,color.g,color.b,color.a);
}
void edk::light::Light::setAmbient(edk::color3f32 color){
    return this->setAmbient(color.r,color.g,color.b);
}
void edk::light::Light::setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->ambient[0u] = r;this->ambient[1u] = g;this->ambient[2u] = b;this->ambient[3u] = a;
}
void edk::light::Light::setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setDiffuse(r,g,b,1.f);
}
void edk::light::Light::setDiffuse(edk::color4f32 color){
    return this->setDiffuse(color.r,color.g,color.b,color.a);
}
void edk::light::Light::setDiffuse(edk::color3f32 color){
    return this->setDiffuse(color.r,color.g,color.b);
}
void edk::light::Light::setSpecular(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->ambient[0u] = r;this->ambient[1u] = g;this->ambient[2u] = b;this->ambient[3u] = a;
}
void edk::light::Light::setSpecular(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setSpecular(r,g,b,1.f);
}
void edk::light::Light::setSpecular(edk::color4f32 color){
    return this->setSpecular(color.r,color.g,color.b,color.a);
}
void edk::light::Light::setSpecular(edk::color3f32 color){
    return this->setSpecular(color.r,color.g,color.b);
}

//get Position
edk::float32 edk::light::Light::getPositionX(){
    return this->position[0u];
}
edk::float32 edk::light::Light::getPositionY(){
    return this->position[1u];
}
edk::float32 edk::light::Light::getPositionZ(){
    return this->position[2u];
}
edk::vec2f32 edk::light::Light::getPosition2f(){
    return edk::vec2f32(this->position[0u],this->position[1u]);
}
edk::vec3f32 edk::light::Light::getPosition3f(){
    return edk::vec3f32(this->position[0u],this->position[1u],this->position[2u]);
}
edk::float32 edk::light::Light::getDirectionX(){
    return this->direction[0u];
}
edk::float32 edk::light::Light::getDirectionY(){
    return this->direction[1u];
}
edk::float32 edk::light::Light::getDirectionZ(){
    return this->direction[2u];
}
edk::vec2f32 edk::light::Light::getDirection2f(){
    return edk::vec2f32(this->direction[0u],this->direction[1u]);
}
edk::vec3f32 edk::light::Light::getDirection3f(){
    return edk::vec3f32(this->direction[0u],this->direction[1u],this->direction[2u]);
}
//DRAW THE LIGH USING THE LIGHT NUMBER
void edk::light::Light::draw(edk::uint32 lightNumber){
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
