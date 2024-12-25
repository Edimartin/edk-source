#include "Line3D.h"

/*
Library Line3D - Draw a 3D line in EDK Game Engine
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
#pragma message "            Inside Line3D.cpp"
#endif

edk::shape::Line3D::Line3D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::shape::Line3D::Line3D(edk::vec3f32 start,edk::vec3f32 end){
    this->classThis=NULL;edkEnd();
    this->Constructor(start,end,false);edkEnd();
}

edk::shape::Line3D::~Line3D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::shape::Line3D::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::shape::Line3D::Constructor(edk::vec3f32 start,edk::vec3f32 end,bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;
        this->start.position=start;edkEnd();
        this->end.position=end;edkEnd();
    }
}

//set the points
void edk::shape::Line3D::setStart(edk::vec3f32 point){
    this->start.position = point;
}
void edk::shape::Line3D::setEnd(edk::vec3f32 point){
    this->end.position = point;
}

//set points
void edk::shape::Line3D::setPoints(edk::vec3f32 start,edk::vec3f32 end){
    this->start.position = start;
    this->end.position = end;
}

//return the point
edk::vec3f32 edk::shape::Line3D::getPoint(edk::float32 percent){
    return edk::vec3f32(this->start.position.x+ ((this->end.position.x - this->start.position.x)*percent),
                        this->start.position.y + ((this->end.position.y - this->start.position.y)*percent),
                        this->start.position.z + ((this->end.position.z - this->start.position.z)*percent)
                        );
}

//print the line
void edk::shape::Line3D::print(){
    //
    printf("\nLine");edkEnd();
}
//Draw the line
void edk::shape::Line3D::draw(){
    //
    this->start.draw();edkEnd();
    this->end.draw();edkEnd();
}
