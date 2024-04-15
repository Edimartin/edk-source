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
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::light::Light3D::~Light3D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::light::Light3D::Constructor(bool runFather){
    if(runFather){
        edk::light::Light::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
    }
}

//Set Vectors
void edk::light::Light3D::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setPosition(x,y,z);edkEnd();
}
void edk::light::Light3D::setPosition(edk::float32 x,edk::float32 y){
    edk::light::Light::setPosition(x,y);edkEnd();
}
void edk::light::Light3D::setPosition(edk::vec3f32 position){
    edk::light::Light::setPosition(position);edkEnd();
}
void edk::light::Light3D::setPosition(edk::vec2f32 position){
    edk::light::Light::setPosition(position);edkEnd();
}
void edk::light::Light3D::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setDirection(x,y,z);edkEnd();
}
void edk::light::Light3D::setDirection(edk::float32 x,edk::float32 y){
    edk::light::Light::setDirection(x,y);edkEnd();
}
void edk::light::Light3D::setDirection(edk::vec3f32 direction){
    edk::light::Light::setDirection(direction);edkEnd();
}
void edk::light::Light3D::setDirection(edk::vec2f32 direction){
    edk::light::Light::setDirection(direction);edkEnd();
}
//Spot Values
void edk::light::Light3D::setExponent(edk::float32 exponent){
    edk::light::Light::setExponent(exponent);edkEnd();
}
void edk::light::Light3D::setCutoff(edk::float32 cutoff){
    edk::light::Light::setCutoff(cutoff);edkEnd();
}
void edk::light::Light3D::setConstantAttenuation(edk::float32 constantAttenuation){
    edk::light::Light::setConstantAttenuation(constantAttenuation);edkEnd();
}
void edk::light::Light3D::setLinearAttenuation(edk::float32 linearAttenuation){
    edk::light::Light::setLinearAttenuation(linearAttenuation);edkEnd();
}
void edk::light::Light3D::setQuadraticAttenuation(edk::float32 quadraticAttenuation){
    edk::light::Light::setQuadraticAttenuation(quadraticAttenuation);edkEnd();
}

//get Position
edk::float32 edk::light::Light3D::getPositionX(){
    return edk::light::Light::getPositionX();edkEnd();
}
edk::float32 edk::light::Light3D::getPositionY(){
    return edk::light::Light::getPositionY();edkEnd();
}
edk::float32 edk::light::Light3D::getPositionZ(){
    return edk::light::Light::getPositionZ();edkEnd();
}
edk::vec2f32 edk::light::Light3D::getPosition2f(){
    return edk::light::Light::getPosition2f();edkEnd();
}
edk::vec3f32 edk::light::Light3D::getPosition3f(){
    return edk::light::Light::getPosition3f();edkEnd();
}
edk::float32 edk::light::Light3D::getDirectionX(){
    return edk::light::Light::getDirectionX();edkEnd();
}
edk::float32 edk::light::Light3D::getDirectionY(){
    return edk::light::Light::getDirectionY();edkEnd();
}
edk::float32 edk::light::Light3D::getDirectionZ(){
    return edk::light::Light::getDirectionZ();edkEnd();
}
edk::vec2f32 edk::light::Light3D::getDirection2f(){
    return edk::light::Light::getDirection2f();edkEnd();
}
edk::vec3f32 edk::light::Light3D::getDirection3f(){
    return edk::light::Light::getDirection3f();edkEnd();
}

//Spot Values
edk::float32 edk::light::Light3D::getExponent(){
    return edk::light::Light::getExponent();edkEnd();
}
edk::float32 edk::light::Light3D::getCutoff(){
    return edk::light::Light::getCutoff();edkEnd();
}
edk::float32 edk::light::Light3D::getConstantAttenuation(){
    return edk::light::Light::getConstantAttenuation();edkEnd();
}
edk::float32 edk::light::Light3D::getLinearAttenuation(){
    return edk::light::Light::getLinearAttenuation();edkEnd();
}
edk::float32 edk::light::Light3D::getQuadraticAttenuation(){
    return edk::light::Light::getQuadraticAttenuation();edkEnd();
}
