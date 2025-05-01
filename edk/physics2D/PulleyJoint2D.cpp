#include "PulleyJoint2D.h"

/*
Library PulleyJoint2D - Physics pulley joint used with PhysicsObjects
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

edk::physics2D::PulleyJoint2D::PulleyJoint2D(bool collide)
    :
      edk::physics2D::DistanceJoint2D(collide)
{
    this->classThis=NULL;
    this->Constructor(collide);
}
edk::physics2D::PulleyJoint2D::~PulleyJoint2D(){
    this->Destructor();
}

void edk::physics2D::PulleyJoint2D::Constructor(bool collide){
    edk::physics2D::DistanceJoint2D::Constructor(collide);
    if(this->classThis!=this){
        this->classThis=this;
        this->type = EDK_PULLEY_JOINT;
        this->lenghtA=0.f;
        this->lenghtB=0.f;
    }
}
void edk::physics2D::PulleyJoint2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
}

//draw the joint in debug mode
void edk::physics2D::PulleyJoint2D::draw(edk::size2f32,edk::color3f32 color){
    edk::GU::guColor3f32(color);
    edk::GU::guPushMatrix();
    edk::GU::guBegin(GU_LINE_STRIP);
    edk::GU::guVertex2f32(this->worldPositionA.x,this->worldPositionA.y);
    edk::GU::guVertex2f32(this->pulleyPositionA.x,this->pulleyPositionA.y);
    edk::GU::guVertex2f32(this->pulleyPositionB.x,this->pulleyPositionB.y);
    edk::GU::guVertex2f32(this->worldPositionB.x,this->worldPositionB.y);
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
