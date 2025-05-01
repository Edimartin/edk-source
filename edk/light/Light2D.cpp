#include "Light2D.h"

/*
Library Light2D - Control GU lights on the EDK Game Engine
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
#pragma message "            Inside Light2D.cpp"
#endif

edk::light::Light2D::Light2D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::light::Light2D::~Light2D(){
    this->Destructor();
}

void edk::light::Light2D::Constructor(){
    edk::light::Light::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::light::Light2D::Destructor(){
    if(this->classThis==this){
        //
    }
    edk::light::Light::Destructor();
}

//Set the 2D Values
void edk::light::Light2D::setPosition(edk::float32 x,edk::float32 y){
    edk::light::Light::setPosition(x,y); 
}
void edk::light::Light2D::setPosition(edk::vec2f32 position){
    edk::light::Light::setPosition(position); 
}
void edk::light::Light2D::setZ(edk::float32 z){
    edk::light::Light::position[2u] = z; 
}
void edk::light::Light2D::setDirection(edk::float32 x,edk::float32 y){
    edk::light::Light::setDirection(x,y); 
}
void edk::light::Light2D::setDirection(edk::vec2f32 direction){
    edk::light::Light::setDirection(direction); 
}

//get Position
edk::float32 edk::light::Light2D::getPositionX(){
    return edk::light::Light::getPositionX(); 
}
edk::float32 edk::light::Light2D::getPositionY(){
    return edk::light::Light::getPositionY(); 
}
edk::vec2f32 edk::light::Light2D::getPosition2f(){
    return edk::light::Light::getPosition2f(); 
}
edk::float32 edk::light::Light2D::getDirectionX(){
    return edk::light::Light::getDirectionX(); 
}
edk::float32 edk::light::Light2D::getDirectionY(){
    return edk::light::Light::getDirectionY(); 
}
edk::vec2f32 edk::light::Light2D::getDirection2f(){
    return edk::light::Light::getDirection2f(); 
}
