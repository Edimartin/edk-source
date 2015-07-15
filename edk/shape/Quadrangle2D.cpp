#include "Quadrangle2D.h"

/*
Library Quadrangle2D - Draw a 2D Quadrangle in EDK Game Engine
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
#warning "            Inside Quadrangle2D.cpp"
#endif

edk::shape::Quadrangle2D::Quadrangle2D()
{
    //ctor
    this->polygonColor.a=1.f;
    //create a new polygon with 3 vertex
    edk::shape::Polygon2D::createPolygon(4u);
}

edk::shape::Quadrangle2D::~Quadrangle2D()
{
    //dtor
    edk::shape::Polygon2D::deletePolygon();
}
//createPolygon
bool edk::shape::Quadrangle2D::createPolygon(){
    //
    return true;
}


//Virtual Functions
bool edk::shape::Quadrangle2D::createPolygon(edk::uint32 vertexCount){
    //the fundtion do nothing
    if(vertexCount)
        return true;
    return false;
}
void edk::shape::Quadrangle2D::deletePolygon(){
    //the fundtion do nothing
}

//print the triangle
void edk::shape::Quadrangle2D::print(){
    //
    printf("\nQuadrangle");
    edk::shape::Polygon2D::print();
}

//Draw the triangle
void edk::shape::Quadrangle2D::draw(){
    //
    edk::GU::guPushMatrix();
    edk::GU::guTranslate2f32(this->translate);
    edk::GU::guRotateZf32(this->angle);
    edk::GU::guScale2f32(this->scale);
    edk::GU::guBegin(GU_QUADS);
        this->drawVertexs();
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
void edk::shape::Quadrangle2D::drawWire(){

    edk::GU::guPushMatrix();
    edk::GU::guTranslate2f32(this->translate);
    edk::GU::guRotateZf32(this->angle);
    edk::GU::guScale2f32(this->scale);
    edk::GU::guBegin(GU_LINES);
        this->drawVertexs();
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
