#include "Circle3D.h"

/*
Library Circle3D - Draw a Circle in EDK Game Engine
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
#pragma message "            Inside Circle3D.cpp"
#endif

edk::shape::Circle3D::Circle3D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::shape::Circle3D::Circle3D(edk::uint32 sides,edk::float32 radius){
    this->classThis=NULL;edkEnd();
    this->Constructor(sides,radius,false);edkEnd();
}

edk::shape::Circle3D::~Circle3D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::shape::Circle3D::Constructor(bool runFather){
    if(runFather){
        edk::shape::Polygon3D::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
        this->polygonCircle=true;edkEnd();
        this->type=edk::shape::typeCircle3D;
        this->createPolygon(4u,1.0);edkEnd();
    }
}
void edk::shape::Circle3D::Constructor(edk::uint32 sides,edk::float32 radius,bool runFather){
    if(runFather){
        edk::shape::Polygon3D::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
        this->polygonCircle=true;edkEnd();
        this->createPolygon(sides,radius);edkEnd();
    }
}


//Create the circle
bool edk::shape::Circle3D::createPolygon(edk::uint32 sides,edk::float32 radius){
    //delete the circle
    this->deletePolygon();edkEnd();

    //update the radius
    if(radius>0.0f){
        //
        this->radius=radius;edkEnd();
    }
    else{
        //normalize the radius
        this->radius=1.0;
    }

    //create the polygon
    if(edk::shape::Polygon3D::createPolygon(sides)){
        //set the vertex positions
        //divide the angles
        edk::float32 angles = 360.f/sides;edkEnd();
        //vecTemp
        edk::vec2f32 temp(0,0);edkEnd();
        edk::vec2f32 translateUV(0.5f,0.5f);edkEnd();
        for(edk::uint32 i=0u;i<sides;i++){
            temp = edk::Math::rotate(edk::vec2f32(0.5f,0.0f),angles*i);edkEnd();
            //set the position of the vertex
            edk::shape::Polygon3D::setVertexPosition(i,(temp.x*this->radius)*2.f,(temp.y*this->radius)*2.f,0.f);edkEnd();
            //set the same position to the UV
            edk::shape::Polygon3D::setVertexUV(i,temp.x + translateUV.x,temp.y + translateUV.y);edkEnd();
        }

        //return true
        return true;
    }

    //else return false
    return false;
}

//delete
void edk::shape::Circle3D::deletePolygon(){
    //
    edk::shape::Polygon3D::deletePolygon();edkEnd();
}

//Set the color
bool edk::shape::Circle3D::setPolygonColor(edk::color4f32 color){
    //
    return edk::shape::Polygon3D::setPolygonColor(color);edkEnd();
}
bool edk::shape::Circle3D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //
    return edk::shape::Polygon3D::setPolygonColor(r,g,b);edkEnd();
}
bool edk::shape::Circle3D::setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    return edk::shape::Polygon3D::setPolygonColor(r,g,b,a);edkEnd();
}
/*
//return true if the polygon is a circle
bool edk::shape::Circle3D::isCircle(){
    return true;
}
//return the circleRadius only if is a circle
edk::float32 edk::shape::Circle3D::getCircleRadius(){
    return this->radius;edkEnd();
}
*/

//print the polygon
void edk::shape::Circle3D::print(){
    //
    printf("\nCircle");edkEnd();
    edk::shape::Polygon3D::print();edkEnd();
}
//Draw the polygon
void edk::shape::Circle3D::draw(){
    //
    edk::shape::Polygon3D::draw();edkEnd();
}
void edk::shape::Circle3D::drawWire(){

    edk::shape::Polygon3D::drawWire();edkEnd();
}
