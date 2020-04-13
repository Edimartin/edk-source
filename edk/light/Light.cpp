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

edk::light::Light::Light(){
    this->clean();
    this->on = false;
}
edk::light::Light::~Light(){
    //
}
void edk::light::Light::updateDirection(){
    this->direction[0u] = this->lightDirection[0u] - this->position[0u];
    this->direction[1u] = this->lightDirection[1u] - this->position[1u];
    this->direction[2u] = this->lightDirection[2u] - this->position[2u];
    this->direction[3u] = 1.f;
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

    this->setDirection(0.f,0.f,0.f);

    this->exponent=1.f;
    this->cutoff=180.f;
    this->cutoffRadian=(PI * this->cutoff)/180.f;
    this->constantAttenuation=1.f;
    this->linearAttenuation=0.0f;
    this->quadraticAttenuation=0.0;
}
//Set Vectors
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    this->position[0u] = x;
    this->position[1u] = y;
    this->position[2u] = z;
    this->position[3u] = w;
    this->updateDirection();
}
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    this->position[0u] = x;
    this->position[1u] = y;
    this->position[2u] = z;
    this->updateDirection();
}
void edk::light::Light::setPosition(edk::float32 x,edk::float32 y){
    this->position[0u] = x;
    this->position[1u] = y;
    this->updateDirection();
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
void edk::light::Light::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    this->lightDirection[0u] = x;
    this->lightDirection[1u] = y;
    this->lightDirection[2u] = z;
    this->lightDirection[3u] = 1.f;
    this->updateDirection();
}
void edk::light::Light::setDirection(edk::float32 x,edk::float32 y){
    this->lightDirection[0u] = x;
    this->lightDirection[1u] = y;
    this->lightDirection[3u] = 1.f;
    this->updateDirection();
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

//Spot Values
edk::float32 edk::light::Light::getExponent(){
    return this->exponent;
}
edk::float32 edk::light::Light::getCutoff(){
    return this->cutoff;
}
edk::float32 edk::light::Light::getConstantAttenuation(){
    return this->constantAttenuation;
}
edk::float32 edk::light::Light::getLinearAttenuation(){
    return this->linearAttenuation;
}
edk::float32 edk::light::Light::getQuadraticAttenuation(){
    return this->quadraticAttenuation;
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
//draw the pivo
void edk::light::Light::drawPivo(edk::float32 size,edk::color3f32 color){

    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate3f32(this->position[0u],this->position[1u],this->position[2u]);
    //add scale
    edk::GU::guScale3f32(edk::size3f32(size,size,size));

    //lineSize
    edk::GU::guLineWidth(3);

    //set the colors
    edk::GU::guColor3f32(color);
    //draw the lines
    edk::GU::guBegin(GU_LINES);
    //LINE 1
    edk::GU::guVertex3f32(-0.5f,-0.5f,0.f);
    edk::GU::guVertex3f32( 0.5f, 0.5f,0.f);
    //LINE 2
    edk::GU::guVertex3f32(-0.5f, 0.5f,0.f);
    edk::GU::guVertex3f32( 0.5f,-0.5f,0.f);
    //LINE 3
    edk::GU::guVertex3f32(0.0f, 0.5f,-0.5f);
    edk::GU::guVertex3f32(0.0f,-0.5f, 0.5f);
    //LINE 4
    edk::GU::guVertex3f32(0.0f, 0.5f, 0.5f);
    edk::GU::guVertex3f32(0.0f,-0.5f,-0.5f);
    edk::GU::guEnd();

    //lineSize
    edk::GU::guLineWidth(1);

    //
    edk::GU::guPopMatrix();
}
