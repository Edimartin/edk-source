#include "Spot.h"

/*
Library Spor - Control GU spot lights on the EDK Game Engine
Copyright 2013 Eduardo Moura Sales Martins (edimartin@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

edk::light::Spot::Spot(){
    //
}
edk::light::Spot::~Spot(){
    //
}

//DRAW THE LIGH USING THE LIGHT NUMBER
void edk::light::Spot::draw(edk::uint32 lightNumber){
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_POSITION,this->position);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_DIFFUSE,this->diffuse);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_AMBIENT,this->ambient);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPECULAR,this->specular);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPOT_DIRECTION,this->direction);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_EXPONENT,this->exponent);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_CUTOFF,this->cutoff);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_CONSTANT_ATTENUATION,this->constantAttenuation);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_LINEAR_ATTENUATION,this->linearAttenuation);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_QUADRATIC_ATTENUATION,this->quadraticAttenuation);edkEnd();
}
//draw the pivo
void edk::light::Spot::drawPivo(edk::float32 size,edk::color3f32 color){
    edk::light::Light::drawPivo(size,color);edkEnd();
}
void edk::light::Spot::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawPivo(size,edk::color3f32(r,g,b));
}

//Set the position of the light
void edk::light::Spot::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setPosition(x,y,z);edkEnd();
}
void edk::light::Spot::setPosition(edk::float32 x,edk::float32 y){
    edk::light::Light::setPosition(x,y);edkEnd();
}
void edk::light::Spot::setPosition(edk::vec3f32 position){
    edk::light::Light::setPosition(position);edkEnd();
}
void edk::light::Spot::setPosition(edk::vec2f32 position){
    edk::light::Light::setPosition(position);edkEnd();
}
void edk::light::Spot::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setDirection(x,y,z);edkEnd();
}
void edk::light::Spot::setDirection(edk::float32 x,edk::float32 y){
    edk::light::Light::setDirection(x,y);edkEnd();
}
void edk::light::Spot::setDirection(edk::vec3f32 direction){
    edk::light::Light::setDirection(direction);edkEnd();
}
void edk::light::Spot::setDirection(edk::vec2f32 direction){
    edk::light::Light::setDirection(direction);edkEnd();
}
//Spot Values
void edk::light::Spot::setExponent(edk::float32 exponent){
    edk::light::Light::setExponent(exponent);edkEnd();
}
void edk::light::Spot::setCutoff(edk::float32 cutoff){
    edk::light::Light::setCutoff(cutoff);edkEnd();
}
void edk::light::Spot::setConstantAttenuation(edk::float32 constantAttenuation){
    edk::light::Light::setConstantAttenuation(constantAttenuation);edkEnd();
}
void edk::light::Spot::setLinearAttenuation(edk::float32 linearAttenuation){
    edk::light::Light::setLinearAttenuation(linearAttenuation);edkEnd();
}
void edk::light::Spot::setQuadraticAttenuation(edk::float32 quadraticAttenuation){
    edk::light::Light::setQuadraticAttenuation(quadraticAttenuation);edkEnd();
}

//get the position of the light
edk::float32 edk::light::Spot::getPositionX(){
    return edk::light::Light::getPositionX();edkEnd();
}
edk::float32 edk::light::Spot::getPositionY(){
    return edk::light::Light::getPositionY();edkEnd();
}
edk::float32 edk::light::Spot::getPositionZ(){
    return edk::light::Light::getPositionZ();edkEnd();
}
edk::vec2f32 edk::light::Spot::getPosition2f(){
    return edk::light::Light::getPosition2f();edkEnd();
}
edk::vec3f32 edk::light::Spot::getPosition3f(){
    return edk::light::Light::getPosition3f();edkEnd();
}
edk::float32 edk::light::Spot::getDirectionX(){
    return edk::light::Light::getDirectionX();edkEnd();
}
edk::float32 edk::light::Spot::getDirectionY(){
    return edk::light::Light::getDirectionY();edkEnd();
}
edk::float32 edk::light::Spot::getDirectionZ(){
    return edk::light::Light::getDirectionZ();edkEnd();
}
edk::vec2f32 edk::light::Spot::getDirection2f(){
    return edk::light::Light::getDirection2f();edkEnd();
}
edk::vec3f32 edk::light::Spot::getDirection3f(){
    return edk::light::Light::getDirection3f();edkEnd();
}

//Spot Values
edk::float32 edk::light::Spot::getExponent(){
    return edk::light::Light::getExponent();edkEnd();
}
edk::float32 edk::light::Spot::getCutoff(){
    return edk::light::Light::getCutoff();edkEnd();
}
edk::float32 edk::light::Spot::getConstantAttenuation(){
    return edk::light::Light::getConstantAttenuation();edkEnd();
}
edk::float32 edk::light::Spot::getLinearAttenuation(){
    return edk::light::Light::getLinearAttenuation();edkEnd();
}
edk::float32 edk::light::Spot::getQuadraticAttenuation(){
    return edk::light::Light::getQuadraticAttenuation();edkEnd();
}
