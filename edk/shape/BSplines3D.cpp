#include "BSplines3D.h"

/*
Library BSplines3D - BSplines curve 3D in EDK Game Engine
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
#pragma message "            Inside BSplines3D.cpp"
#endif

edk::shape::BSplines3D::BSplines3D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::shape::BSplines3D::BSplines3D(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4){
    this->classThis=NULL;
    this->Constructor(p1,p2,p3,p4);
}

edk::shape::BSplines3D::~BSplines3D(){
    this->Destructor();
}

void edk::shape::BSplines3D::Constructor(){
    edk::shape::Curve3D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->point1=0.f;
        this->point2=0.f;
        this->point3=0.f;
        this->point4=0.f;
    }
}
void edk::shape::BSplines3D::Constructor(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4){
    edk::shape::Curve3D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->point1=p1;
        this->point2=p2;
        this->point3=p3;
        this->point4=p4;
    }
}
void edk::shape::BSplines3D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::shape::Curve3D::Destructor();
}



//return the point
edk::vec3f32 edk::shape::BSplines3D::getPoint(edk::float32 percent){
    //create a vector to return
    edk::vec3f32 ret;

#define div 0.166666

    //percent pow's
    edk::float32 percent2 = percent * percent;
    edk::float32 percent3 = percent * percent * percent;

    //get X
    ret.x = (((-1*percent3 +3*percent2 -3*percent+1) *this->point1.x +
              (   3*percent3 -6*percent2 +0*percent+4) *this->point2.x +
              (  -3*percent3 +3*percent2 +3*percent+1) *this->point3.x +
              (   1*percent3 +0*percent2 +0*percent+0) *this->point4.x)
             *div
             );
    //get Y
    ret.y = (((-1*percent3 +3*percent2 -3*percent+1) *this->point1.y +
              (   3*percent3 -6*percent2 +0*percent+4) *this->point2.y +
              (  -3*percent3 +3*percent2 +3*percent+1) *this->point3.y +
              (   1*percent3 +0*percent2 +0*percent+0) *this->point4.y)
             *div
             );
    //get Z
    ret.y = (((-1*percent3 +3*percent2 -3*percent+1) *this->point1.z +
              (   3*percent3 -6*percent2 +0*percent+4) *this->point2.z +
              (  -3*percent3 +3*percent2 +3*percent+1) *this->point3.z +
              (   1*percent3 +0*percent2 +0*percent+0) *this->point4.z)
             *div
             );

    return edk::shape::BSplines3D::getPoint(this->point1,this->point2,this->point3,this->point4,percent);
}
edk::vec3f32 edk::shape::BSplines3D::getPoint(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4,edk::float32 percent){
    //create a vector to return
    edk::vec3f32 ret;

#define div 0.166666

    //percent pow's
    edk::float32 percent2 = percent * percent;
    edk::float32 percent3 = percent * percent * percent;

    //get X
    ret.x = (((-1*percent3 +3*percent2 -3*percent+1) *p1.x +
              (   3*percent3 -6*percent2 +0*percent+4) *p2.x +
              (  -3*percent3 +3*percent2 +3*percent+1) *p3.x +
              (   1*percent3 +0*percent2 +0*percent+0) *p4.x)
             *div
             );
    //get Y
    ret.y = (((-1*percent3 +3*percent2 -3*percent+1) *p1.y +
              (   3*percent3 -6*percent2 +0*percent+4) *p2.y +
              (  -3*percent3 +3*percent2 +3*percent+1) *p3.y +
              (   1*percent3 +0*percent2 +0*percent+0) *p4.y)
             *div
             );
    //get Z
    ret.y = (((-1*percent3 +3*percent2 -3*percent+1) *p1.z +
              (   3*percent3 -6*percent2 +0*percent+4) *p2.z +
              (  -3*percent3 +3*percent2 +3*percent+1) *p3.z +
              (   1*percent3 +0*percent2 +0*percent+0) *p4.z)
             *div
             );

    return ret;
}
