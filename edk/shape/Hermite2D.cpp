#include "Hermite2D.h"

/*
Library Hermite2D - Hermite curve 2D in EDK Game Engine
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
#warning "            Inside Hermite2D.cpp"
#endif

edk::shape::Hermite2D::Hermite2D()
{
    //ctor
    this->attenuation=1;
}
edk::shape::Hermite2D::Hermite2D(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4){
    //
    this->point1=p1;
    this->point2=p2;
    this->point3=p3;
    this->point4=p4;
    this->attenuation=1;
}

edk::shape::Hermite2D::~Hermite2D()
{
    //dtor
}

//Implement the Bezier Curve
edk::vec2f32 edk::shape::Hermite2D::getPoint(float percent){
    //return the ret
    return edk::shape::Hermite2D::getPoint(this->point1,this->point2,this->point3,this->point4,percent,this->attenuation);
}
edk::vec2f32 edk::shape::Hermite2D::getPoint(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4,float percent,edk::float32 attenuation){

    //create a return point
    edk::vec2f32 ret;

    //percent pow's
    float percent2 = percent * percent;
    float percent3 = percent * percent * percent;

    //get X
    ret.x = ((( 2*percent3 -3*percent2 +0*percent +1)* p1.x +
            (  -2*percent3 +3*percent2 +0*percent)   * p4.x +
            (   1*percent3 -2*percent2 +1*percent)   * attenuation*p3.x +
            (   1*percent3 -1*percent2 +0*percent)   * attenuation*p2.x
            ));
    //get Y
    ret.y = ((( 2*percent3 -3*percent2 +0*percent +1)* p1.y +
            (  -2*percent3 +3*percent2 +0*percent)   * p4.y +
            (   1*percent3 -2*percent2 +1*percent)   * attenuation*p3.y +
            (   1*percent3 -1*percent2 +0*percent)   * attenuation*p2.y
            ));

    //return the ret
    return ret;
}
