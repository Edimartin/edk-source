#include "PrismaticJoint2D.h"

/*
Library PrismaticJoint2D - Physics prismatic joint used with PhysicsObjects
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

edk::physics2D::PrismaticJoint2D::PrismaticJoint2D(bool collide)
    : edk::physics2D::Joint2D(collide)
{
    this->type = EDK_PRISMATIC_JOINT;
    this->removeType();
}

//set motor
void edk::physics2D::PrismaticJoint2D::setForce(edk::float32 maxForce,edk::float32 speed){
    this->maxForce = maxForce;
    this->speed = speed;
    this->prismaticType = EDK_JOINT_MOTOR;
}
//remove type
void edk::physics2D::PrismaticJoint2D::removeType(){
    this->prismaticType = 0u;
}

//GETERS
edk::uint8 edk::physics2D::PrismaticJoint2D::getPrismaticType(){
    return this->prismaticType = 0u;
}
edk::float32 edk::physics2D::PrismaticJoint2D::getMaxForce(){
    return this->maxForce;
}
edk::float32 edk::physics2D::PrismaticJoint2D::getSpeed(){
    return this->speed;
}

//draw the joint in debug mode
void edk::physics2D::PrismaticJoint2D::draw(edk::size2f32 size,edk::color3f32 color){
    edk::GU::guColor3f32(color);
    edk::GU::guPushMatrix();
    edk::GU::guBegin(GU_LINES);
    edk::GU::guVertex2f32(this->worldPositionA.x,this->worldPositionA.y);
    edk::GU::guVertex2f32(this->worldPositionA.x + size.width,this->worldPositionA.y + size.height);
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
