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
    this->classThis=NULL;
    this->Constructor();
}
edk::light::Spot::~Spot(){
    this->Destructor();
}

void edk::light::Spot::Constructor(){
    edk::light::Light::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::light::Spot::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::light::Light::Destructor();
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
void edk::light::Spot::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawPivo(size,edk::color3f32(r,g,b));
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
