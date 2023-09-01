#include "Grid3D.h"

/*
Library Grid3D - Draw a 3D Grid in EDK Game Engine
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
#pragma message "            Inside Grid3D.cpp"
#endif

edk::shape::Grid3D::Grid3D(){
    //position of the grid
    this->position=0.f;
    this->size=1.f;
    this->angles=0.f;
    //color of the lines
    this->colorLines=edk::color4f32(0.f,0.f,0.f,1.f);
    this->colorLinesBold=edk::color4f32(0.f,0.f,0.f,1.f);
    this->setDistanceLines(0.f);
    this->setDistanceLinesBold(0.f);
}
edk::shape::Grid3D::~Grid3D(){
    //
}

//set the distanceLines
bool edk::shape::Grid3D::setDistanceLines(edk::float32 distance){
    if(distance>0.f){
        this->distanceLines=distance;
        return true;
    }
    this->distanceLines=0.1f;
    return false;
}
bool edk::shape::Grid3D::setDistanceLinesBold(edk::float32 distance){
    if(distance>0.f){
        this->distanceLinesBold=distance;
        return true;
    }
    this->distanceLinesBold=1.0f;
    return false;
}
edk::float32 edk::shape::Grid3D::getDistanceLines(){
    return this->distanceLines;
}
edk::float32 edk::shape::Grid3D::getDistanceLinesBold(){
    return this->distanceLinesBold;
}

//draw the grid
void edk::shape::Grid3D::drawXY(){
    //
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate3f32(this->position);edkEnd();
    edk::GU::guRotateZf32(this->angles.z);edkEnd();

    edk::GU::guLineWidth(1u);

    edk::GU::guColor4f32(this->colorLines);

    //draw the lines
    edk::GU::guBegin(GU_LINES);
    //WIDTH
    this->limit = this->size.width*0.5;
    this->p1=this->size.height*-0.5;
    this->p2=this->size.height*0.5;
    for(this->i=this->size.width*-0.5f;this->i<this->limit;this->i+=this->distanceLines){
        edk::GU::guVertex3f32(this->i,this->p1,0.f);
        edk::GU::guVertex3f32(this->i,this->p2,0.f);
    }
    //HEIGHT
    this->limit = this->size.height*0.5;
    this->p1=this->size.width*-0.5;
    this->p2=this->size.width*0.5;
    for(this->i=this->size.height*-0.5f;this->i<this->limit;this->i+=this->distanceLines){
        edk::GU::guVertex3f32(this->p1,this->i,0.f);
        edk::GU::guVertex3f32(this->p2,this->i,0.f);
    }
    edk::GU::guEnd();

    edk::GU::guLineWidth(2u);

    edk::GU::guColor4f32(this->colorLinesBold);

    //draw the lines bold
    edk::GU::guBegin(GU_LINES);
    //WIDTH
    this->limit = this->size.width*0.5;
    this->p1=this->size.height*-0.5;
    this->p2=this->size.height*0.5;
    for(this->i=this->size.width*-0.5f;this->i<this->limit;this->i+=this->distanceLinesBold){
        edk::GU::guVertex3f32(this->i,this->p1,0.f);
        edk::GU::guVertex3f32(this->i,this->p2,0.f);
    }
    //HEIGHT
    this->limit = this->size.height*0.5;
    this->p1=this->size.width*-0.5;
    this->p2=this->size.width*0.5;
    for(this->i=this->size.height*-0.5f;this->i<this->limit;this->i+=this->distanceLinesBold){
        edk::GU::guVertex3f32(this->p1,this->i,0.f);
        edk::GU::guVertex3f32(this->p2,this->i,0.f);
    }
    edk::GU::guEnd();

    edk::GU::guLineWidth(1u);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Grid3D::drawXZ(){
    //
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate3f32(this->position);edkEnd();
    edk::GU::guRotateYf32(this->angles.y);edkEnd();

    edk::GU::guLineWidth(1u);

    edk::GU::guColor4f32(this->colorLines);

    //draw the lines
    edk::GU::guBegin(GU_LINES);
    //WIDTH
    this->limit = this->size.width*0.5;
    this->p1=this->size.length*-0.5;
    this->p2=this->size.length*0.5;
    for(this->i=this->size.width*-0.5f;this->i<this->limit;this->i+=this->distanceLines){
        edk::GU::guVertex3f32(this->i,0.f,this->p1);
        edk::GU::guVertex3f32(this->i,0.f,this->p2);
    }
    //LENGHT
    this->limit = this->size.length*0.5;
    this->p1=this->size.width*-0.5;
    this->p2=this->size.width*0.5;
    for(this->i=this->size.length*-0.5f;this->i<this->limit;this->i+=this->distanceLines){
        edk::GU::guVertex3f32(this->p1,0.f,this->i);
        edk::GU::guVertex3f32(this->p2,0.f,this->i);
    }
    edk::GU::guEnd();

    edk::GU::guLineWidth(2u);

    edk::GU::guColor4f32(this->colorLinesBold);

    //draw the lines bold
    edk::GU::guBegin(GU_LINES);
    //WIDTH
    this->limit = this->size.width*0.5;
    this->p1=this->size.length*-0.5;
    this->p2=this->size.length*0.5;
    for(this->i=this->size.width*-0.5f;this->i<this->limit;this->i+=this->distanceLinesBold){
        edk::GU::guVertex3f32(this->i,0.f,this->p1);
        edk::GU::guVertex3f32(this->i,0.f,this->p2);
    }
    //LENGHT
    this->limit = this->size.length*0.5;
    this->p1=this->size.width*-0.5;
    this->p2=this->size.width*0.5;
    for(this->i=this->size.length*-0.5f;this->i<this->limit;this->i+=this->distanceLinesBold){
        edk::GU::guVertex3f32(this->p1,0.f,this->i);
        edk::GU::guVertex3f32(this->p2,0.f,this->i);
    }
    edk::GU::guEnd();

    edk::GU::guLineWidth(1u);

    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Grid3D::drawYZ(){
    //
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guTranslate3f32(this->position);edkEnd();
    edk::GU::guRotateXf32(this->angles.x);edkEnd();

    edk::GU::guLineWidth(1u);

    edk::GU::guColor4f32(this->colorLines);

    //draw the lines
    edk::GU::guBegin(GU_LINES);
    //HEIGHT
    this->limit = this->size.height*0.5;
    this->p1=this->size.length*-0.5;
    this->p2=this->size.length*0.5;
    for(this->i=this->size.height*-0.5f;this->i<this->limit;this->i+=this->distanceLines){
        edk::GU::guVertex3f32(0.f,this->i,this->p1);
        edk::GU::guVertex3f32(0.f,this->i,this->p2);
    }
    //LENGTH
    this->limit = this->size.length*0.5;
    this->p1=this->size.height*-0.5;
    this->p2=this->size.height*0.5;
    for(this->i=this->size.length*-0.5f;this->i<this->limit;this->i+=this->distanceLines){
        edk::GU::guVertex3f32(0.f,this->p1,this->i);
        edk::GU::guVertex3f32(0.f,this->p2,this->i);
    }
    edk::GU::guEnd();

    edk::GU::guLineWidth(2u);

    edk::GU::guColor4f32(this->colorLinesBold);

    //draw the lines bold
    edk::GU::guBegin(GU_LINES);
    //HEIGHT
    this->limit = this->size.height*0.5;
    this->p1=this->size.length*-0.5;
    this->p2=this->size.length*0.5;
    for(this->i=this->size.height*-0.5f;this->i<this->limit;this->i+=this->distanceLinesBold){
        edk::GU::guVertex3f32(0.f,this->i,this->p1);
        edk::GU::guVertex3f32(0.f,this->i,this->p2);
    }
    //LENGTH
    this->limit = this->size.length*0.5;
    this->p1=this->size.height*-0.5;
    this->p2=this->size.height*0.5;
    for(this->i=this->size.length*-0.5f;this->i<this->limit;this->i+=this->distanceLinesBold){
        edk::GU::guVertex3f32(0.f,this->p1,this->i);
        edk::GU::guVertex3f32(0.f,this->p2,this->i);
    }
    edk::GU::guEnd();

    edk::GU::guLineWidth(1u);

    edk::GU::guPopMatrix();edkEnd();
}
