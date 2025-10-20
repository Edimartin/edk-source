#include "Point.h"

/*
Library Point - Control GU point lights on the EDK Game Engine
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
#pragma message "            Inside Point.cpp"
#endif

edk::light::Point::Point(){
    this->classThis=NULL;
    this->Constructor();
}
edk::light::Point::~Point(){
    this->Destructor();
}

void edk::light::Point::Constructor(){
    edk::light::Light::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::light::Point::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::light::Light::Destructor();
}

//DRAW THE LIGH USING THE LIGHT NUMBER
void edk::light::Point::draw(edk::uint32 lightNumber){
    edk::GU::guLightfv32(GU_LIGHT0+lightNumber,GU_POSITION,this->position);
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

//Set the position of the light
void edk::light::Point::setPosition(edk::float32 x,edk::float32 y,edk::float32 z){
    edk::light::Light::setPosition(x,y,z,1.f);
}
void edk::light::Point::setPosition(edk::float32 x,edk::float32 y){
    edk::light::Light::setPosition(x,y,this->getPositionZ(),1.f);
}
void edk::light::Point::setPosition(edk::vec3f32 position){
    edk::light::Light::setPosition(position.x,position.y,position.z,1.f);
}
void edk::light::Point::setPosition(edk::vec2f32 position){
    edk::light::Light::setPosition(position.x,position.y,this->getPositionZ(),1.f);
}

//get the position of the light
edk::float32 edk::light::Point::getPositionX(){
    return edk::light::Light::getPositionX();
}
edk::float32 edk::light::Point::getPositionY(){
    return edk::light::Light::getPositionY();
}
edk::float32 edk::light::Point::getPositionZ(){
    return edk::light::Light::getPositionZ();
}
edk::vec2f32 edk::light::Point::getPosition2f(){
    return edk::light::Light::getPosition2f();
}
edk::vec3f32 edk::light::Point::getPosition3f(){
    return edk::light::Light::getPosition3f();
}
