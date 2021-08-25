#include "ParticlesLine2D.h"

/*
Biblioteca C++ ParticlesPoint2D - Manage a particle system generated in a line
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
#warning "            Inside ParticlesLine2D.cpp"
#endif

edk::animation::ParticlesLine2D::ParticlesLine2D(){
    this->point1 = this->point2 = edk::vec2f32(0,0);
}
//get the position
edk::vec2f32 edk::animation::ParticlesLine2D::newPosition(){
    edk::float32 percent = edk::Random::getRandPercent();
    return this->position + edk::Math::rotatePlus2f((this->point1 + ((this->point2 - this->point1)*percent)),this->angle);
}

//set the points
void edk::animation::ParticlesLine2D::setP1(edk::vec2f32 point){
    this->point1 = point;
}
void edk::animation::ParticlesLine2D::setP1(edk::float32 px,edk::float32 py){
    this->setP1(edk::vec2f32(px,py));
}
void edk::animation::ParticlesLine2D::setP2(edk::vec2f32 point){
    this->point2 = point;
}
void edk::animation::ParticlesLine2D::setP2(edk::float32 px,edk::float32 py){
    this->setP2(edk::vec2f32(px,py));
}
void edk::animation::ParticlesLine2D::setPoints(edk::vec2f32 p1,edk::vec2f32 p2){
    this->setP1(p1);
    this->setP2(p2);
}
void edk::animation::ParticlesLine2D::setPoints(edk::float32 p1x,edk::float32 p1y,edk::float32 p2x,edk::float32 p2y){
    this->setP1(edk::vec2f32(p1x,p1y));
    this->setP2(edk::vec2f32(p2x,p2y));
}

//draw the angles vector
void edk::animation::ParticlesLine2D::drawAngles(edk::float32 size,edk::color3f32 color){
    //put the transformation on a stack
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    edk::GU::guScale2f32(this->size);


    //lineSize
    edk::GU::guLineWidth(3);

    //set the colors
    edk::GU::guColor3f32(color);
    //draw the lines
    edk::GU::guBegin(GU_LINES);
    //LINE
    edk::GU::guVertex2f32(this->point1);
    edk::GU::guVertex2f32(this->point2);
    //LINE 1
    edk::GU::guVertex2f32(this->point1);
    edk::GU::guVertex2f32(this->point1 + edk::Math::rotate2f(edk::vec2f32(1,0),this->angleFar)*size);
    //LINE 2
    edk::GU::guVertex2f32(this->point2);
    edk::GU::guVertex2f32(this->point2 + edk::Math::rotate2f(edk::vec2f32(1,0),this->angleNear)*size);
    //
    edk::GU::guEnd();

    //lineSize
    edk::GU::guLineWidth(1);

    edk::GU::guPopMatrix();
}
