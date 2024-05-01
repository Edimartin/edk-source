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
    //
    if(this->classThis!=this){
        this->classThis=this;
        this->type=edk::TypeObject3DValues;
        this->loadIdentityValues();
        this->connectedLoadIdentityValues();
    }
}

void edk::Object3DValues::connectedLoadIdentityValues(){
    //
    this->connectedPosition = edk::vec3f32(0,0,0);edkEnd();
    this->connectedAngle = edk::vec3f32(0,0,0);edkEnd();
    this->connectedSize = edk::size3f32(1,1,1);edkEnd();
}
void edk::Object3DValues::updateValuesFromConnected(){
    this->position = this->connectedPosition;edkEnd();
    this->angle = this->connectedAngle;edkEnd();
    this->size = this->connectedSize;edkEnd();
}

void edk::Object3DValues::loadIdentityValues(){
    //
    this->position = edk::vec3f32(0,0,0);edkEnd();
    this->angle = edk::vec3f32(0,0,0);edkEnd();
    this->size = edk::size3f32(1,1,1);edkEnd();
}

//get the bodyType
edk::TypeObject edk::Object3DValues::getType(){
    //edk::TypeObject3DValues;
    return this->type;
}
edk::uint8 edk::Object3DValues::getTypeValue(){
    return (edk::uint8)this->type;
}
