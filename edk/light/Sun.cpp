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

#ifdef printMessages
#pragma message "            Inside Sun.cpp"
#endif

edk::light::Sun::Sun(){
    this->classThis=NULL;
    this->Constructor();
}
edk::light::Sun::~Sun(){
    this->Destructor();
}

void edk::light::Sun::Constructor(){
    edk::light::Light::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::light::Sun::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::light::Light::Destructor();
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
void edk::light::Sun::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawPivo(size,edk::color3f32(r,g,b));
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
