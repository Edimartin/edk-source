#include "Light3D.h"

/*
Library Light3D - Control GU 3D lights on the EDK Game Engine
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

edk::light::Light3D::Light3D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::light::Light3D::~Light3D(){
    this->Destructor();
}

void edk::light::Light3D::Constructor(){
    edk::light::Light::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::light::Light3D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::light::Light::Destructor();
}

//Set Vectors
void edk::light::Light3D::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setPosition(x,y,z);
}
void edk::light::Light3D::setPosition(edk::float32 x,edk::float32 y){
    edk::light::Light::setPosition(x,y);
}
void edk::light::Light3D::setPosition(edk::vec3f32 position){
    edk::light::Light::setPosition(position);
}
void edk::light::Light3D::setPosition(edk::vec2f32 position){
    edk::light::Light::setPosition(position);
}
void edk::light::Light3D::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setDirection(x,y,z);
}
void edk::light::Light3D::setDirection(edk::float32 x,edk::float32 y){
    edk::light::Light::setDirection(x,y);
}
void edk::light::Light3D::setDirection(edk::vec3f32 direction){
    edk::light::Light::setDirection(direction);
}
void edk::light::Light3D::setDirection(edk::vec2f32 direction){
    edk::light::Light::setDirection(direction);
}
//Spot Values
void edk::light::Light3D::setExponent(edk::float32 exponent){
    edk::light::Light::setExponent(exponent);
}
void edk::light::Light3D::setCutoff(edk::float32 cutoff){
    edk::light::Light::setCutoff(cutoff);
}
void edk::light::Light3D::setConstantAttenuation(edk::float32 constantAttenuation){
    edk::light::Light::setConstantAttenuation(constantAttenuation);
}
void edk::light::Light3D::setLinearAttenuation(edk::float32 linearAttenuation){
    edk::light::Light::setLinearAttenuation(linearAttenuation);
}
void edk::light::Light3D::setQuadraticAttenuation(edk::float32 quadraticAttenuation){
    edk::light::Light::setQuadraticAttenuation(quadraticAttenuation);
}

//get Position
edk::float32 edk::light::Light3D::getPositionX(){
    return edk::light::Light::getPositionX();
}
edk::float32 edk::light::Light3D::getPositionY(){
    return edk::light::Light::getPositionY();
}
edk::float32 edk::light::Light3D::getPositionZ(){
    return edk::light::Light::getPositionZ();
}
edk::vec2f32 edk::light::Light3D::getPosition2f(){
    return edk::light::Light::getPosition2f();
}
edk::vec3f32 edk::light::Light3D::getPosition3f(){
    return edk::light::Light::getPosition3f();
}
edk::float32 edk::light::Light3D::getDirectionX(){
    return edk::light::Light::getDirectionX();
}
edk::float32 edk::light::Light3D::getDirectionY(){
    return edk::light::Light::getDirectionY();
}
edk::float32 edk::light::Light3D::getDirectionZ(){
    return edk::light::Light::getDirectionZ();
}
edk::vec2f32 edk::light::Light3D::getDirection2f(){
    return edk::light::Light::getDirection2f();
}
edk::vec3f32 edk::light::Light3D::getDirection3f(){
    return edk::light::Light::getDirection3f();
}

//Spot Values
edk::float32 edk::light::Light3D::getExponent(){
    return edk::light::Light::getExponent();
}
edk::float32 edk::light::Light3D::getCutoff(){
    return edk::light::Light::getCutoff();
}
edk::float32 edk::light::Light3D::getConstantAttenuation(){
    return edk::light::Light::getConstantAttenuation();
}
edk::float32 edk::light::Light3D::getLinearAttenuation(){
    return edk::light::Light::getLinearAttenuation();
}
edk::float32 edk::light::Light3D::getQuadraticAttenuation(){
    return edk::light::Light::getQuadraticAttenuation();
}
