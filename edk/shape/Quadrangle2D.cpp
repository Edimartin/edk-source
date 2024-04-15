#include "Quadrangle2D.h"

/*
Library Quadrangle2D - Draw a 2D Quadrangle in EDK Game Engine
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
#pragma message "            Inside Quadrangle2D.cpp"
#endif

edk::shape::Quadrangle2D::Quadrangle2D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::shape::Quadrangle2D::~Quadrangle2D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        edk::shape::Polygon2D::deletePolygon();edkEnd();
    }
}

void edk::shape::Quadrangle2D::Constructor(bool runFather){
    if(runFather){
        edk::shape::Polygon2D::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
        this->type = edk::shape::typeQuadrangle2D;edkEnd();
        //ctor
        this->polygonColor.a=1.f;edkEnd();
        //create a new polygon with 3 vertex
        edk::shape::Polygon2D::createPolygon(4u);edkEnd();
    }
}

//createPolygon
bool edk::shape::Quadrangle2D::createPolygon(){
    //
    return true;
}


//Virtual Functions
bool edk::shape::Quadrangle2D::createPolygon(edk::uint32 vertexCount){
    //the fundtion do nothing
    if(vertexCount){
        return true;
    }
    return false;
}
void edk::shape::Quadrangle2D::deletePolygon(){
    //the fundtion do nothing
}

//print the triangle
void edk::shape::Quadrangle2D::print(){
    //
    printf("\nQuadrangle");edkEnd();
    edk::shape::Polygon2D::print();edkEnd();
}

//Draw the triangle
void edk::shape::Quadrangle2D::draw(){
    //
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->translate);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->scale);edkEnd();
    /*
    edk::GU::guBegin(GU_QUADS);edkEnd();
        this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
    */

    //drawVBO
    (this->*vboDraw)(GU_QUADS);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Quadrangle2D::drawWire(){

    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->translate);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->scale);edkEnd();
    /*
    edk::GU::guBegin(GU_LINES);edkEnd();
        this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
    */

    //drawVBO
    (this->*vboDraw)(GU_LINES);

    edk::GU::guPopMatrix();edkEnd();
}
