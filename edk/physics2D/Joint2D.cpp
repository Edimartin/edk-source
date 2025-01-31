#include "Joint2D.h"

/*
Library Joint2D - Physics joints used in the PhysicsObjects
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

edk::physics2D::Joint2D::Joint2D(bool collide){
    this->classThis=NULL;edkEnd();
    this->Constructor(collide,false);edkEnd();
}

edk::physics2D::Joint2D::~Joint2D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::physics2D::Joint2D::Constructor(bool collide,bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;
        this->objectA=NULL;edkEnd();
        this->objectB=NULL;edkEnd();
        this->collide = collide;edkEnd();
        this->type = EDK_JOINT;edkEnd();
    }
}

//draw the joint in debug mode
void edk::physics2D::Joint2D::draw(edk::size2f32,edk::color3f32){
    //
}

//return the joint type
edk::uint8 edk::physics2D::Joint2D::getType(){
    return this->type;edkEnd();
}
//get Collide
bool edk::physics2D::Joint2D::getCollide(){
    return this->collide;edkEnd();
}
