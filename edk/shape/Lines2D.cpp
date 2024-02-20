#include "Lines2D.h"

/*
Library Lines2D - Draw Lines 2D in EDK Game Engine
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

edk::shape::Lines2D::Lines2D(){
    this->type = edk::shape::typeLine2D;edkEnd();
    this->polygonLine=true;edkEnd();
}
//return true if it's lines
bool edk::shape::Lines2D::isLine(){
    return true;
}
//print the polygon
void edk::shape::Lines2D::print(){
    printf("\nLINES:");edkEnd();
    edk::shape::Polygon2D::print();edkEnd();
}
//Draw the polygon
void edk::shape::Lines2D::draw(){
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate2f32(this->translate);edkEnd();
    edk::GU::guRotateZf32(this->angle);edkEnd();
    edk::GU::guScale2f32(this->scale);edkEnd();
    /*
    edk::GU::guBegin(GU_LINE_STRIP);edkEnd();
        this->drawVertexs();edkEnd();
    edk::GU::guEnd();edkEnd();
    */

    //drawVBO
    (this->*vboDraw)(GU_LINE_STRIP);

    edk::GU::guPopMatrix();edkEnd();
}
//set collisionID
void edk::shape::Lines2D::setCollisionID(edk::uint8 collisionID){
    this->collisionID = collisionID;edkEnd();
}
