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
#pragma message "            Inside ParticlesLine2D.cpp"
#endif

edk::animation::ParticlesLine2D::ParticlesLine2D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::animation::ParticlesLine2D::~ParticlesLine2D(){
    this->Destructor();
}

void edk::animation::ParticlesLine2D::Constructor(){
    edk::animation::ParticlesPoint2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->point1 = this->point2 = edk::vec2f32(0,0);
    }
}
void edk::animation::ParticlesLine2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
    }
    edk::animation::ParticlesPoint2D::Destructor();
}

//get the position
edk::vec2f32 edk::animation::ParticlesLine2D::newPosition(){
    edk::float32 percent = edk::Random::getStaticRandPercent();
    return this->position + edk::Math::rotatePlus((this->point1 + ((this->point2 - this->point1)*percent)),this->angle);
}

//set the points
void edk::animation::ParticlesLine2D::setP1Local(edk::vec2f32 point){
    this->point1 = point;
}
void edk::animation::ParticlesLine2D::setP1Local(edk::float32 px,edk::float32 py){
    this->setP1Local(edk::vec2f32(px,py));
}
void edk::animation::ParticlesLine2D::setP2Local(edk::vec2f32 point){
    this->point2 = point;
}
void edk::animation::ParticlesLine2D::setP2Local(edk::float32 px,edk::float32 py){
    this->setP2Local(edk::vec2f32(px,py));
}
void edk::animation::ParticlesLine2D::setPointsLocal(edk::vec2f32 p1,edk::vec2f32 p2){
    this->setP1Local(p1);
    this->setP2Local(p2);
}
void edk::animation::ParticlesLine2D::setPointsLocal(edk::float32 p1x,edk::float32 p1y,edk::float32 p2x,edk::float32 p2y){
    this->setP1Local(edk::vec2f32(p1x,p1y));
    this->setP2Local(edk::vec2f32(p2x,p2y));
}
void edk::animation::ParticlesLine2D::setP1World(edk::vec2f32 point){
    //calculate the middle point to be the position
    this->position = ((this->point2-point)*0.5f)+point;
    //set the points local
    this->setP1Local(point-this->position);
}
void edk::animation::ParticlesLine2D::setP1World(edk::float32 px,edk::float32 py){
    this->setP1World(edk::vec2f32(px,py));
}
void edk::animation::ParticlesLine2D::setP2World(edk::vec2f32 point){
    //calculate the middle point to be the position
    this->position = ((point-this->point1)*0.5f)+this->point1;
    //set the points local
    this->setP2Local(point-this->position);
}
void edk::animation::ParticlesLine2D::setP2World(edk::float32 px,edk::float32 py){
    this->setP2World(edk::vec2f32(px,py));
}
void edk::animation::ParticlesLine2D::setPointsWorld(edk::vec2f32 p1,edk::vec2f32 p2){
    //calculate the middle point to be the position
    this->position = ((p2-p1)*0.5f)+p1;
    //set the points local
    this->setP1Local(p1-this->position);
    this->setP2Local(p2-this->position);
}
void edk::animation::ParticlesLine2D::setPointsWorld(edk::float32 p1x,edk::float32 p1y,edk::float32 p2x,edk::float32 p2y){
    this->setPointsWorld(edk::vec2f32(p1x,p1y),edk::vec2f32(p2x,p2y));
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
    edk::GU::guVertex2f32(this->point1 + edk::Math::rotate(edk::vec2f32(1,0),this->angleFar)*size);
    //LINE 2
    edk::GU::guVertex2f32(this->point2);
    edk::GU::guVertex2f32(this->point2 + edk::Math::rotate(edk::vec2f32(1,0),this->angleNear)*size);
    //
    edk::GU::guEnd();

    //lineSize
    edk::GU::guLineWidth(1);

    edk::GU::guPopMatrix();
}
void edk::animation::ParticlesLine2D::drawAngles(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b){
    this->drawAngles(size,edk::color3f32(r,g,b));
}
