#include "Catmull3D.h"

/*
Library Catmull3D - BSplines curve 3D in EDK Game Engine
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
#warning "            Inside Catmull3D.cpp"
#endif

edk::shape::Catmull3D::Catmull3D()
{
    //ctor
}
edk::shape::Catmull3D::Catmull3D(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4){
    //
    this->point1=p1;
    this->point2=p2;
    this->point3=p3;
    this->point4=p4;
}

edk::shape::Catmull3D::~Catmull3D()
{
    //dtor
}



//return the point
edk::vec3f32 edk::shape::Catmull3D::getPoint(float percent){
    return edk::shape::Catmull3D::getPoint(this->point1,this->point2,this->point3,this->point4,percent);
}
edk::vec3f32 edk::shape::Catmull3D::getPoint(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4,float percent){
    //create a vector to return
    edk::vec3f32 ret;

    //percent pow's
    float percent2 = percent * percent;
    float percent3 = percent * percent * percent;

    //get X
    ret.x = 0.5 *((2 * p2.x) +
            (-p1.x + p3.x) * percent +
            (2*p1.x - 5*p2.x + 4*p3.x - p4.x) * percent2 +
            (-p1.x + 3*p2.x- 3*p3.x + p4.x) * percent3
            );
    //get Y
    ret.y = 0.5 *((2 * p2.y) +
            (-p1.y + p3.y) * percent +
            (2*p1.y- 5*p2.y + 4*p3.y - p4.y) * percent2 +
            (-p1.y + 3*p2.y- 3*p3.y + p4.y) * percent3
            );
    //get Z
    ret.y = 0.5 *((2 * p2.z) +
            (-p1.z + p3.z) * percent +
            (2*p1.z- 5*p2.z + 4*p3.z - p4.z) * percent2 +
            (-p1.z + 3*p2.z- 3*p3.z + p4.z) * percent3
            );

    return ret;
}