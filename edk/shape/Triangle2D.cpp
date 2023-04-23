#include "Triangle2D.h"

/*
Library Triangle2D - Draw a 2D Triangle in EDK Game Engine
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
#pragma message "            Inside Triangle2D.cpp"
#endif

edk::shape::Triangle2D::Triangle2D()
{
    this->polygonColor.a=1.f;edkEnd();
    //create a new polygon with 3 vertex
    edk::shape::Polygon2D::createPolygon(3u);edkEnd();
}

edk::shape::Triangle2D::~Triangle2D()
{
    //delete the polygon
    edk::shape::Polygon2D::deletePolygon();edkEnd();
}

//createPolygon
bool edk::shape::Triangle2D::createPolygon(){
    //return true
    return true;
}

//Virtual Functions
bool edk::shape::Triangle2D::createPolygon(edk::uint32 vertexCount){
    //set the function no do nothing
    if(vertexCount){
        return true;
    }
    return false;
}
void edk::shape::Triangle2D::deletePolygon(){
    //set the function no do nothing
}

//change the vertex position to the polygon be counterClockwise
bool edk::shape::Triangle2D::calculateCounterClockwise(){
    //
    bool ret=false;
    if(this->getVertexCount()==3u){
        if(this->vertexs.get(0u) &&
                this->vertexs.get(1u) &&
                this->vertexs.get(2u)
                ){
            if(!this->isCounterclockwise()){
                edk::shape::Vertex2D* temp = this->vertexs.get(1u);edkEnd();
                this->vertexs.set(1u,this->vertexs.get(2u));edkEnd();
                this->vertexs.set(2u,temp);edkEnd();
            }
            ret=true;
        }
        if(this->vertexsOriginal.get(0u) &&
                this->vertexsOriginal.get(1u) &&
                this->vertexsOriginal.get(2u)
                ){
            if(!this->isCounterclockwise()){
                edk::shape::Vertex2D* temp = this->vertexsOriginal.get(1u);edkEnd();
                this->vertexsOriginal.set(1u,this->vertexsOriginal.get(2u));edkEnd();
                this->vertexsOriginal.set(2u,temp);edkEnd();
            }
            ret=true;
        }
    }
    return ret;
}
//print the triangle
void edk::shape::Triangle2D::print(){
    //
    printf("\nTriangle");edkEnd();
    edk::shape::Polygon2D::print();edkEnd();
}

//Draw the triangle
void edk::shape::Triangle2D::draw(){
    //draw the polygon
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->translate);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->scale);edkEnd();
    edk::GU::guBegin(GU_TRIANGLES);edkEnd();
        this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Triangle2D::drawWire(){
    //draw the polygon
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->translate);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->scale);edkEnd();
    edk::GU::guBegin(GU_LINES);edkEnd();
        this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}

