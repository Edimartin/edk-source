#include "Object3DValues.h"

/*
Library Object3DValues - 3D Position angle and size
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

edk::Object3DValues::Object3DValues(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::Object3DValues::~Object3DValues(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::Object3DValues::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;

        this->animationPosition.Constructor();
        this->animationRotation.Constructor();
        this->animationSize.Constructor();

        this->type=edk::TypeObject3DValues;
        //this->angle=0.f;edkEnd();
        this->loadIdentityValues();edkEnd();
        this->connectedLoadIdentityValues();edkEnd();
        this->fixedRotation=false;edkEnd();
        //this->cleanSaved();edkEnd();
    }
}

//print the values
void edk::Object3DValues::print(){
    printf("\nVALUES:"
           "\nposition          [%.2f][%.2f][%.2f]"
           "\nangle             [%.2f][%.2f][%.2f]"
           "\nsize              [%.2f][%.2f][%.2f]"
           "\npivo              [%.2f][%.2f][%.2f]"
           "\nfixedRotation     '%s'"
           "\n"
           "\nconnectedPosition [%.2f][%.2f][%.2f]"
           "\nconnectedAngle    [%.2f][%.2f][%.2f]"
           "\nconnectedSize     [%.2f][%.2f][%.2f]"
           "\nconnectedPivo     [%.2f][%.2f][%.2f]"
           ,this->position.x,this->position.y,this->position.z
           ,this->angle.x,this->angle.y,this->angle.z
           ,this->size.width,this->size.height,this->size.length
           ,this->pivo.x,this->pivo.y,this->pivo.z
           ,this->fixedRotation?"true":"false"
                                ,this->connectedPosition.x,this->connectedPivo.y,this->connectedPivo.z
           ,this->connectedAngle.x,this->connectedAngle.y,this->connectedAngle.z
           ,this->connectedSize.width,this->connectedSize.height,this->connectedSize.length
           ,this->connectedPivo.x,this->connectedPivo.y,this->connectedPivo.z
           );
}

void edk::Object3DValues::loadIdentityValues(){
    this->position = edk::vec3f32(0,0,0);edkEnd();
    this->angle = 0.f;edkEnd();
    this->size = edk::size3f32(1,1,1);edkEnd();
}

void edk::Object3DValues::connectedLoadIdentityValues(){
    this->connectedPosition = edk::vec3f32(0,0,0);edkEnd();
    this->connectedAngle = 0.f;edkEnd();
    this->connectedSize = edk::size3f32(1,1,1);edkEnd();
    this->connectedPivo = edk::vec3f32(0,0,0);edkEnd();
}
void edk::Object3DValues::updateValuesFromConnected(){
    this->position = this->connectedPosition;edkEnd();
    this->angle = this->connectedAngle;edkEnd();
    this->size = this->connectedSize;edkEnd();
}

//draw the pivo
void edk::Object3DValues::drawPivo(edk::float32 ,edk::color3f32 ){
    //
}
void edk::Object3DValues::drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawPivo(size,edk::color3f32(r,g,b));
}
//update all animations
bool edk::Object3DValues::updateAnimations(){
    bool ret=false;edkEnd();
    this->animationPosition.updateClockAnimation();edkEnd();
    this->animationRotation.updateClockAnimation();edkEnd();
    this->animationSize.updateClockAnimation();edkEnd();
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //
        edk::vec3f32 posTemp;edkEnd();
        posTemp.x = this->animationPosition.getClockX(this->position.x);edkEnd();
        posTemp.y = this->animationPosition.getClockY(this->position.y);edkEnd();
        posTemp.z = this->animationPosition.getClockZ(this->position.z);edkEnd();
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
        edk::size3f32 sizeTemp;edkEnd();
        sizeTemp.width = this->animationSize.getClockX();edkEnd();
        sizeTemp.height = this->animationSize.getClockY();edkEnd();
        sizeTemp.length = this->animationSize.getClockZ();edkEnd();
        //set the value
        this->size = sizeTemp;edkEnd();
        ret=true;edkEnd();
    }
    return ret;
}
bool edk::Object3DValues::updateAnimations(edk::float32 seconds){
    bool ret=false;edkEnd();
    this->animationPosition.updateClockAnimation(seconds);edkEnd();
    this->animationRotation.updateClockAnimation(seconds);edkEnd();
    this->animationSize.updateClockAnimation(seconds);edkEnd();
    //test if are playing the animations
    if(this->animationPosition.isPlaying()){
        //
        edk::vec3f32 posTemp;edkEnd();
        posTemp.x = this->animationPosition.getClockX(this->position.x);edkEnd();
        posTemp.y = this->animationPosition.getClockY(this->position.y);edkEnd();
        posTemp.z = this->animationPosition.getClockZ(this->position.z);edkEnd();
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
        edk::size3f32 sizeTemp;edkEnd();
        sizeTemp.width = this->animationSize.getClockX();edkEnd();
        sizeTemp.height = this->animationSize.getClockY();edkEnd();
        sizeTemp.length = this->animationSize.getClockZ();edkEnd();
        //set the value
        this->size = sizeTemp;edkEnd();
        ret=true;edkEnd();
    }
    return ret;
}
//draw
void edk::Object3DValues::draw(){
    //
}
//get the bodyType
edk::TypeObject edk::Object3DValues::getType(){
    //return edk::TypeObject3DValues;
    return this->type;
}
edk::uint8 edk::Object3DValues::getTypeValue(){
    return (edk::uint8)this->type;
}
