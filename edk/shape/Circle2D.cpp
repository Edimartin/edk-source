#include "Circle2D.h"

/*
Library Circle2D - Draw a Circle in EDK Game Engine
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
#warning "            Inside Circle2D.cpp"
#endif

edk::shape::Circle2D::Circle2D()
{
    //ctor
    this->polygonCircle=true;
    this->createPolygon(4u,1.0);
}
edk::shape::Circle2D::Circle2D(edk::uint32 sides,edk::float32 radius){
    //
    this->polygonCircle=true;
    this->createPolygon(sides,radius);
}

edk::shape::Circle2D::~Circle2D()
{
    //dtor
}


//Create the circle
bool edk::shape::Circle2D::createPolygon(edk::uint32 sides,edk::float32 radius){
    //delete the circle
    this->deletePolygon();

    //update the radius
    if(radius>0.0f){
        //
        this->radius=radius;
    }
    else{
        //normalize the radius
        this->radius=1.0;
    }

    //create the polygon
    if(edk::shape::Polygon2D::createPolygon(sides)){
        //set the vertex positions
        //divide the angles
        edk::float32 angles = 360.f/sides;
        //vecTemp
        edk::vec2f32 temp(0,0);
        edk::vec2f32 translateUV(0.5f,0.5f);
        for(edk::uint32 i=0u;i<sides;i++){
            temp = edk::Math::rotate2f(edk::vec2f32(0.5f,0.0f),angles*i);
            //set the position of the vertex
            edk::shape::Polygon2D::setVertexPosition(i,(temp*this->radius)*2.f);
            //set the same position to the UV
            edk::shape::Polygon2D::setVertexUV(i,temp + translateUV);
        }

        //return true
        return true;
    }

    //else return false
    return false;
}

//delete
void edk::shape::Circle2D::deletePolygon(){
    //
    edk::shape::Polygon2D::deletePolygon();
}

//Set the color
bool edk::shape::Circle2D::setPolygonColor(edk::color4f32 color){
    //
    return edk::shape::Polygon2D::setPolygonColor(color);
}
bool edk::shape::Circle2D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //
    return edk::shape::Polygon2D::setPolygonColor(r,g,b);
}
bool edk::shape::Circle2D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return edk::shape::Polygon2D::setPolygonColor(r,g,b,a);
}
/*
//return true if the polygon is a circle
bool edk::shape::Circle2D::isCircle(){
    return true;
}
//return the circleRadius only if is a circle
edk::float32 edk::shape::Circle2D::getCircleRadius(){
    return this->radius;
}
*/

//print the polygon
void edk::shape::Circle2D::print(){
    //
    printf("\nCircle");
    edk::shape::Polygon2D::print();
}
//Draw the polygon
void edk::shape::Circle2D::draw(){
    //
    edk::shape::Polygon2D::draw();
}
void edk::shape::Circle2D::drawWire(){

    edk::shape::Polygon2D::drawWire();
}
