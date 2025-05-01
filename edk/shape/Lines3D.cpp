#include "Lines3D.h"

/*
Library Lines3D - Draw Lines 3D in EDK Game Engine
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

edk::shape::Lines3D::Lines3D(){
    this->type = edk::shape::typeLine3D; 
    this->polygonLine=true; 
}
//return true if it's lines
bool edk::shape::Lines3D::isLine(){
    return true;
}
//print the polygon
void edk::shape::Lines3D::print(){
    printf("\nLINES:"); 
    edk::shape::Polygon3D::print(); 
}
//Draw the polygon
void edk::shape::Lines3D::draw(){
    edk::GU::guPushMatrix(); 
    edk::GU::guTranslate3f32(this->translate); 
    edk::GU::guRotateZf32(this->angle); 
    edk::GU::guScale3f32(this->scale); 
    /*
    edk::GU::guBegin(GU_LINE_STRIP); 
        this->drawVertexs(); 
    edk::GU::guEnd(); 
    */

    //drawVBO
    (this->*vboDraw)(GU_LINE_STRIP);

    edk::GU::guPopMatrix(); 
}
//set collisionID
void edk::shape::Lines3D::setCollisionID(edk::uint8 collisionID){
    this->collisionID = collisionID; 
}
