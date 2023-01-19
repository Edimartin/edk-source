#include "Object2DValues.h"

/*
Library Object2DValues - 2D Position angle and size
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

edk::Object2DValues::Object2DValues()
{
    //this->angle=0.f;edkEnd();
    this->loadIdentityValues();edkEnd();
    this->fixedRotation=false;edkEnd();
    //this->cleanSaved();edkEnd();
}
void edk::Object2DValues::loadIdentityValues(){
    this->position = edk::vec2f32(0,0);edkEnd();
    this->angle = 0.f;edkEnd();
    this->size = edk::size2f32(1,1);edkEnd();
}
//draw the pivo
void edk::Object2DValues::drawPivo(edk::float32 ,edk::color3f32 ){
    //
}
//update all animations
bool edk::Object2DValues::updateAnimations(){
    bool ret=false;edkEnd();
    this->animationPosition.updateClockAnimation();edkEnd();
    this->animationRotation.updateClockAnimation();edkEnd();
    this->animationSize.updateClockAnimation();edkEnd();
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //
        edk::vec2f32 posTemp;edkEnd();
        posTemp.x = this->animationPosition.getClockX();edkEnd();
        posTemp.y = this->animationPosition.getClockY();edkEnd();
        //set the value
        this->position = posTemp;edkEnd();
        ret=true;edkEnd();
    }
    if(this->animationRotation.isPlaying()){
        //
        edk::float32 angleTemp = this->animationRotation.getClockX();edkEnd();
        //set the value
        this->angle = angleTemp;edkEnd();
        ret=true;edkEnd();
    }
    if(this->animationSize.isPlaying()){
        //
        edk::size2f32 sizeTemp;edkEnd();
        sizeTemp.width = this->animationSize.getClockX();edkEnd();
        sizeTemp.height = this->animationSize.getClockY();edkEnd();
        //set the value
        this->size = sizeTemp;edkEnd();
        ret=true;edkEnd();
    }
    return ret;
}
bool edk::Object2DValues::updateAnimations(edk::float32 seconds){
    bool ret=false;edkEnd();
    this->animationPosition.updateClockAnimation(seconds);edkEnd();
    this->animationRotation.updateClockAnimation(seconds);edkEnd();
    this->animationSize.updateClockAnimation(seconds);edkEnd();
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //
        edk::vec2f32 posTemp;edkEnd();
        posTemp.x = this->animationPosition.getClockX();edkEnd();
        posTemp.y = this->animationPosition.getClockY();edkEnd();
        //set the value
        this->position = posTemp;edkEnd();
        ret=true;edkEnd();
    }
    if(this->animationRotation.isPlaying()){
        //
        edk::float32 angleTemp = this->animationRotation.getClockX();edkEnd();
        //set the value
        this->angle = angleTemp;edkEnd();
        ret=true;edkEnd();
    }
    if(this->animationSize.isPlaying()){
        //
        edk::size2f32 sizeTemp;edkEnd();
        sizeTemp.width = this->animationSize.getClockX();edkEnd();
        sizeTemp.height = this->animationSize.getClockY();edkEnd();
        //set the value
        this->size = sizeTemp;edkEnd();
        ret=true;edkEnd();
    }
    return ret;
}
//draw
void edk::Object2DValues::draw(){
    //
}
