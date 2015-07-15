#include "BSplines3D.h"

/*
Library BSplines3D - BSplines curve 3D in EDK Game Engine
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
#warning "            Inside BSplines3D.cpp"
#endif

edk::shape::BSplines3D::BSplines3D()
{
    //ctor
}
edk::shape::BSplines3D::BSplines3D(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4){
    //
    this->point1=p1;
    this->point2=p2;
    this->point3=p3;
    this->point4=p4;
}

edk::shape::BSplines3D::~BSplines3D()
{
    //dtor
}



//return the point
edk::vec3f32 edk::shape::BSplines3D::getPoint(float percent){
    //create a vector to return
    edk::vec3f32 ret;

    #define div 0.166666

    //percent pow's
    float percent2 = percent * percent;
    float percent3 = percent * percent * percent;

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
edk::vec3f32 edk::shape::BSplines3D::getPoint(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4,float percent){
    //create a vector to return
    edk::vec3f32 ret;

    #define div 0.166666

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
    //get Z
    ret.y = (((-1*percent3 +3*percent2 -3*percent+1) *p1.z +
            (   3*percent3 -6*percent2 +0*percent+4) *p2.z +
            (  -3*percent3 +3*percent2 +3*percent+1) *p3.z +
            (   1*percent3 +0*percent2 +0*percent+0) *p4.z)
             *div
             );

    return ret;
}
