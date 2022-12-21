#include "BSplines2D.h"

/*
Library BSplines2D - BSplines curve 2D in EDK Game Engine
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
#warning "            Inside BSplines2D.cpp"
#endif

edk::shape::BSplines2D::BSplines2D(){
    //ctor
}
edk::shape::BSplines2D::BSplines2D(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4){
    //
    this->point1=p1;edkEnd();
    this->point2=p2;edkEnd();
    this->point3=p3;edkEnd();
    this->point4=p4;edkEnd();
}

edk::shape::BSplines2D::~BSplines2D()
{
    //dtor
}


//Implement the Bezier Curve
edk::vec2f32 edk::shape::BSplines2D::getPoint(edk::float32 percent){
    //return the ret
    return edk::shape::BSplines2D::getPoint(this->point1,this->point2,this->point3,this->point4,percent);edkEnd();
}
edk::vec2f32 edk::shape::BSplines2D::getPoint(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4,edk::float32 percent){

    //create a return point
    edk::vec2f32 ret;edkEnd();

    #define div 0.1666

    //percent pow's
    edk::float32 percent2 = percent * percent;edkEnd();
    edk::float32 percent3 = percent * percent * percent;edkEnd();

    //get X
    ret.x = (((-1*percent3 +3*percent2 -3*percent+1) *p1.x +
            (   3*percent3 -6*percent2 +0*percent+4) *p2.x +
            (  -3*percent3 +3*percent2 +3*percent+1) *p3.x +
            (   1*percent3 +0*percent2 +0*percent+0) *p4.x)
             *div
             );edkEnd();
    //get Y
    ret.y = (((-1*percent3 +3*percent2 -3*percent+1) *p1.y +
            (   3*percent3 -6*percent2 +0*percent+4) *p2.y +
            (  -3*percent3 +3*percent2 +3*percent+1) *p3.y +
            (   1*percent3 +0*percent2 +0*percent+0) *p4.y)
             *div
             );edkEnd();

    //return the ret
    return ret;
}
