#include "GridLines2D.h"

/*
Library GridLines2D - Draw lines in a 2D Grid in EDK Game Engine
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
#pragma message "            Inside GridLines2D.cpp"
#endif

edk::shape::GridLines2D::GridLines2D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::shape::GridLines2D::~Grid2D(){
    this->Destructor();
}

void edk::shape::GridLines2D::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;
        this->position = 0.f;
        this->size = 1.f;
        this->angle=0.f;
        this->colorLines = edk::color4f32(0.f,0.f,0.f,1.f);;
        this->colorLinesBold = edk::color4f32(0.f,0.f,0.f,1.f);
        this->setDistanceLines(0.f);
        this->setDistanceLinesBold(0.f);
    }
}
void edk::shape::GridLines2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
}

//set the distanceLines
bool edk::shape::GridLines2D::setDistanceLines(edk::float32 distance){
    if(distance>0.f){
        this->distanceLines=distance;
        return true;
    }
    this->distanceLines=0.1f;
    return false;
}
bool edk::shape::GridLines2D::setDistanceLinesBold(edk::float32 distance){
    if(distance>0.f){
        this->distanceLinesBold=distance;
        return true;
    }
    this->distanceLinesBold=1.0f;
    return false;
}
edk::float32 edk::shape::GridLines2D::getDistanceLines(){
    return this->distanceLines;
}
edk::float32 edk::shape::GridLines2D::getDistanceLinesBold(){
    return this->distanceLinesBold;
}

//draw the grid
void edk::shape::GridLines2D::draw(){
    //
    edk::GU::guPushMatrix();
    edk::GU::guTranslate2f32(this->position);
    edk::GU::guRotateZf32(this->angle);

    edk::GU::guLineWidth(1u);

    edk::GU::guColor4f32(this->colorLines);

    //draw the lines
    edk::GU::guBegin(GU_LINES);
    //WIDTH
    this->limit = this->size.width*0.5;
    this->p1=this->size.height*-0.5;
    this->p2=this->size.height*0.5;
    for(this->i=this->size.width*-0.5f;this->i<this->limit;this->i+=this->distanceLines){
        edk::GU::guVertex2f32(this->i,this->p1);
        edk::GU::guVertex2f32(this->i,this->p2);
    }
    //HEIGHT
    this->limit = this->size.height*0.5;
    this->p1=this->size.width*-0.5;
    this->p2=this->size.width*0.5;
    for(this->i=this->size.height*-0.5f;this->i<this->limit;this->i+=this->distanceLines){
        edk::GU::guVertex2f32(this->p1,this->i);
        edk::GU::guVertex2f32(this->p2,this->i);
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
    for(this->i=this->size.width*-0.5f;this->i<this->limit;this->i+=this->distanceLines){
        edk::GU::guVertex2f32(this->i,this->p1);
        edk::GU::guVertex2f32(this->i,this->p2);
    }
    //HEIGHT
    this->limit = this->size.height*0.5;
    this->p1=this->size.width*-0.5;
    this->p2=this->size.width*0.5;
    for(this->i=this->size.height*-0.5f;this->i<this->limit;this->i+=this->distanceLines){
        edk::GU::guVertex2f32(this->p1,this->i);
        edk::GU::guVertex2f32(this->p2,this->i);
    }
    edk::GU::guEnd();

    edk::GU::guLineWidth(1u);

    edk::GU::guPopMatrix();
}
