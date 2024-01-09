#include "Curve3D.h"

/*
Library Curve3D - Template for a 3D Curve in EDK Game Engine
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
#pragma message "            Inside Curve3D.cpp"
#endif

edk::shape::Curve3D::Curve3D()
{
    //ctor
}
edk::shape::Curve3D::Curve3D(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4){
    //
    this->point1=p1;edkEnd();
    this->point2=p2;edkEnd();
    this->point3=p3;edkEnd();
    this->point4=p4;edkEnd();
}
edk::shape::Curve3D::~Curve3D()
{
    //dtor
}

//set one point position
bool edk::shape::Curve3D::setPoint(edk::uint8 position,edk::vec3f32 point){
    switch(position){
    case 0u:
        this->point1 = point;edkEnd();
        return true;
    case 1u:
        this->point2 = point;edkEnd();
        return true;
    case 2u:
        this->point3 = point;edkEnd();
        return true;
    case 3u:
        this->point4 = point;edkEnd();
        return true;
    default:
        break;
    }
    return false;
}
void edk::shape::Curve3D::setPoint1(edk::vec3f32 point){
    this->point1=point;
}
void edk::shape::Curve3D::setPoint2(edk::vec3f32 point){
    this->point2=point;
}
void edk::shape::Curve3D::setPoint3(edk::vec3f32 point){
    this->point3=point;
}
void edk::shape::Curve3D::setPoint4(edk::vec3f32 point){
    this->point4=point;
}

//set points
void edk::shape::Curve3D::setPoints(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4){
    //
    this->point1=p1;edkEnd();
    this->point2=p2;edkEnd();
    this->point3=p3;edkEnd();
    this->point4=p4;edkEnd();
}

//return the point
edk::vec3f32 edk::shape::Curve3D::getPoint(edk::float32 percent){
    if(percent>-0.001f){
        if(percent>0.75f){
            return this->point4;edkEnd();
        }
        else if(percent>0.50f){
            return this->point3;edkEnd();
        }
        else if(percent>0.25f){
            return this->point2;edkEnd();
        }
        else{
            return this->point1;edkEnd();
        }
    }
    return edk::vec3f32();edkEnd();
}
