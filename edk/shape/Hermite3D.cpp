#include "Hermite3D.h"

/*
Library Hermite3D - Hermite curve 3D in EDK Game Engine
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
#warning "            Inside Hermite3D.cpp"
#endif

edk::shape::Hermite3D::Hermite3D()
{
    //ctor
    this->attenuation=1;
}
edk::shape::Hermite3D::Hermite3D(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4){
    //
    this->point1=p1;
    this->point2=p2;
    this->point3=p3;
    this->point4=p4;
    this->attenuation=1;
}

edk::shape::Hermite3D::~Hermite3D()
{
    //dtor
}



//return the point
edk::vec3f32 edk::shape::Hermite3D::getPoint(edk::float32 percent){
    return edk::shape::Hermite3D::getPoint(this->point1,this->point2,this->point3,this->point4,percent,this->attenuation);
}
edk::vec3f32 edk::shape::Hermite3D::getPoint(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4,edk::float32 percent,edk::float32 attenuation){
    //create a vector to return
    edk::vec3f32 ret;

    //percent pow's
    edk::float32 percent2 = percent * percent;
    edk::float32 percent3 = percent * percent * percent;

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
    //get Z
    ret.y = ((( 2*percent3 -3*percent2 +0*percent +1)* p1.z +
            (  -2*percent3 +3*percent2 +0*percent)   * p4.z +
            (   1*percent3 -2*percent2 +1*percent)   * attenuation*p3.z +
            (   1*percent3 -1*percent2 +0*percent)   * attenuation*p2.z
            ));

    return ret;
}
