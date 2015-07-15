#include "Curve2D.h"

/*
Library Curve2D - Template for a 2D Curve in EDK Game Engine
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
#warning "            Inside Curve2D.cpp"
#endif

edk::shape::Curve2D::Curve2D()
{
    //ctor
}
edk::shape::Curve2D::Curve2D(edk::vec2f32 p1,edk::vec2f32 p2,edk::vec2f32 p3,edk::vec2f32 p4){
    //
    this->point1=p1;
    this->point2=p2;
    this->point3=p3;
    this->point4=p4;
}

edk::shape::Curve2D::~Curve2D()
{
    //dtor
}


//return the point
edk::vec2f32 edk::shape::Curve2D::getPoint(float percent){
    if(percent){
        return edk::vec2f32();
    }
    //return a zero point
    return edk::vec2f32();
}
