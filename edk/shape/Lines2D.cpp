#include "Lines2D.h"

/*
Library Lines2D - Draw Lines 2D in EDK Game Engine
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

edk::shape::Lines2D::Lines2D()
{
    this->polygonLine=true;
}
//return true if it's lines
bool edk::shape::Lines2D::isLine(){
    return true;
}
//print the polygon
void edk::shape::Lines2D::print(){
    printf("\nLINES:");
    edk::shape::Polygon2D::print();
}
//Draw the polygon
void edk::shape::Lines2D::draw(){
    edk::GU::guPushMatrix();
    edk::GU::guTranslate2f32(this->translate);
    edk::GU::guRotateZf32(this->angle);
    edk::GU::guScale2f32(this->scale);
    edk::GU::guBegin(GU_LINE_STRIP);
        this->drawVertexs();
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
//set collisionID
void edk::shape::Lines2D::setCollisionID(edk::uint8 collisionID){
    this->collisionID = collisionID;
}
