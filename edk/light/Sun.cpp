#include "Sun.h"

/*
Library Sun - Control GU sun lights on the EDK Game Engine
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

edk::light::Sun::Sun(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::light::Sun::~Sun(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::light::Sun::Constructor(bool runFather){
    if(runFather){
        edk::light::Light::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
    }
}

//DRAW THE LIGH USING THE LIGHT NUMBER
void edk::light::Sun::draw(edk::uint32 lightNumber){
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_POSITION,this->direction);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_DIFFUSE,this->diffuse);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_AMBIENT,this->ambient);edkEnd();
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPECULAR,this->specular);edkEnd();
    //edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_SPOT_DIRECTION,this->direction);edkEnd();
    //edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_EXPONENT,this->exponent);edkEnd();
    //edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_SPOT_CUTOFF,this->cutoff);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_CONSTANT_ATTENUATION,this->constantAttenuation);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_LINEAR_ATTENUATION,this->linearAttenuation);edkEnd();
    edk::GU::guLightf32(GU_LIGHT0+lightNumber,GU_QUADRATIC_ATTENUATION,this->quadraticAttenuation);edkEnd();
}
//draw the pivo
void edk::light::Sun::drawPivo(edk::float32 size,edk::color3f32 color){
    edk::light::Light::drawPivo(size,color);edkEnd();
}
void edk::light::Sun::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawPivo(size,edk::color3f32(r,g,b));
}

//Set the position of the light
void edk::light::Sun::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setPosition(x,y,z);edkEnd();
}
void edk::light::Sun::setPosition(edk::float32 x,edk::float32 y){
    edk::light::Light::setPosition(x,y);edkEnd();
}
void edk::light::Sun::setPosition(edk::vec3f32 position){
    edk::light::Light::setPosition(position);edkEnd();
}
void edk::light::Sun::setPosition(edk::vec2f32 position){
    edk::light::Light::setPosition(position);edkEnd();
}
void edk::light::Sun::setDirection(edk::float32 x,edk::float32 y,edk::float32 z){
    this->direction[0u]=x;edkEnd();
    this->direction[1u]=y;edkEnd();
    this->direction[2u]=z;edkEnd();
    this->direction[3u]=0.f;edkEnd();
}
void edk::light::Sun::setDirection(edk::float32 x,edk::float32 y){
    this->setDirection(x,y,this->getDirectionZ());edkEnd();
}
void edk::light::Sun::setDirection(edk::vec3f32 direction){
    this->setDirection(direction.x,direction.y,direction.z);edkEnd();
}
void edk::light::Sun::setDirection(edk::vec2f32 direction){
    this->setDirection(direction.x,direction.y,this->getDirectionZ());edkEnd();
}

//get the position of the light
edk::float32 edk::light::Sun::getPositionX(){
    return edk::light::Light::getPositionX();edkEnd();
}
edk::float32 edk::light::Sun::getPositionY(){
    return edk::light::Light::getPositionY();edkEnd();
}
edk::float32 edk::light::Sun::getPositionZ(){
    return edk::light::Light::getPositionZ();edkEnd();
}
edk::vec2f32 edk::light::Sun::getPosition2f(){
    return edk::light::Light::getPosition2f();edkEnd();
}
edk::vec3f32 edk::light::Sun::getPosition3f(){
    return edk::light::Light::getPosition3f();edkEnd();
}
edk::float32 edk::light::Sun::getDirectionX(){
    return edk::light::Light::getDirectionX();edkEnd();
}
edk::float32 edk::light::Sun::getDirectionY(){
    return edk::light::Light::getDirectionY();edkEnd();
}
edk::float32 edk::light::Sun::getDirectionZ(){
    return edk::light::Light::getDirectionZ();edkEnd();
}
edk::vec2f32 edk::light::Sun::getDirection2f(){
    return edk::light::Light::getDirection2f();edkEnd();
}
edk::vec3f32 edk::light::Sun::getDirection3f(){
    return edk::light::Light::getDirection3f();edkEnd();
}
