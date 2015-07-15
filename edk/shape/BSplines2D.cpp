#include "BSplines2D.h"

/*
Library BSplines2D - BSplines curve 2D in EDK Game Engine
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "            Inside BSplines2D.cpp"
#endif

edk::shape::BSplines2D::BSplines2D(){
    //ctor
}
edk::shape::BSplines2D::BSplines2D(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4){
    //
    this->point1=p1;
    this->point2=p2;
    this->point3=p3;
    this->point4=p4;
}

edk::shape::BSplines2D::~BSplines2D()
{
    //dtor
}


//Implement the Bezier Curve
edk::vec2f32 edk::shape::BSplines2D::getPoint(float percent){
    //return the ret
    return edk::shape::BSplines2D::getPoint(this->point1,this->point2,this->point3,this->point4,percent);
}
edk::vec2f32 edk::shape::BSplines2D::getPoint(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4,float percent){

    //create a return point
    edk::vec2f32 ret;

    #define div 0.1666

    //percent pow's
    float percent2 = percent * percent;
    float percent3 = percent * percent * percent;

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

    //return the ret
    return ret;
}
