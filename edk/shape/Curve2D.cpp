#include "Curve2D.h"

/*
Library Curve2D - Template for a 2D Curve in EDK Game Engine
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
#pragma message "            Inside Curve2D.cpp"
#endif

edk::shape::Curve2D::Curve2D(){
    this->classThis=NULL; 
    this->Constructor();
}
edk::shape::Curve2D::Curve2D(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4){
    this->classThis=NULL; 
    this->Constructor(p1,p2,p3,p4);
}

edk::shape::Curve2D::~Curve2D(){
    this->Destructor();
}

void edk::shape::Curve2D::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
        this->setPoints(edk::vec2f32(0.f,0.f),edk::vec2f32(0.f,0.f),edk::vec2f32(0.f,0.f),edk::vec2f32(0.f,0.f));
    }
}
void edk::shape::Curve2D::Constructor(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4){
    if(this->classThis!=this){
        this->classThis=this;
        this->setPoints(p1,p2,p3,p4);
    }
}
void edk::shape::Curve2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

//set one point position
bool edk::shape::Curve2D::setPoint(edk::uint8 position,edk::vec2f32 point){
    switch(position){
    case 0u:
        this->point1 = point; 
        return true;
    case 1u:
        this->point2 = point; 
        return true;
    case 2u:
        this->point3 = point; 
        return true;
    case 3u:
        this->point4 = point; 
        return true;
    default:
        break;
    }
    return false;
}
void edk::shape::Curve2D::setPoint1(edk::vec2f32 point){
    this->point1=point;
}
void edk::shape::Curve2D::setPoint2(edk::vec2f32 point){
    this->point2=point;
}
void edk::shape::Curve2D::setPoint3(edk::vec2f32 point){
    this->point3=point;
}
void edk::shape::Curve2D::setPoint4(edk::vec2f32 point){
    this->point4=point;
}

//set points
void edk::shape::Curve2D::setPoints(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4){
    //
    this->point1=p1; 
    this->point2=p2; 
    this->point3=p3; 
    this->point4=p4; 
}


//return the point
edk::vec2f32 edk::shape::Curve2D::getPoint(edk::float32 percent){
    if(percent>-0.001f){
        if(percent>0.75f){
            return this->point4; 
        }
        else if(percent>0.50f){
            return this->point3; 
        }
        else if(percent>0.25f){
            return this->point2; 
        }
        else{
            return this->point1; 
        }
    }
    //return a zero point
    return edk::vec2f32(); 
}
