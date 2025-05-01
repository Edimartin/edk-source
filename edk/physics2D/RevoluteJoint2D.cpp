#include "RevoluteJoint2D.h"

/*
Library RevoluteJoint2D - Physics revolute joints used with PhysicsObjects
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

edk::physics2D::RevoluteJoint2D::RevoluteJoint2D(bool collide)
    :
      edk::physics2D::Joint2D(collide)
{
    this->classThis=NULL;
    this->Constructor(collide);
}
edk::physics2D::RevoluteJoint2D::~RevoluteJoint2D(){
    this->Destructor();
}

void edk::physics2D::RevoluteJoint2D::Constuctor(bool collide){
    edk::physics2D::Joint2D::Constructor(collide);
    if(this->classThis!=this){
        this->classThis=this;
        this->type = EDK_REVOLUTE_JOINT;
        this->revoluteType = 0u;
        this->removeType();
    }
}
void edk::physics2D::RevoluteJoint2D::Destuctor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
}

void edk::physics2D::RevoluteJoint2D::setAngle(edk::float32 lowerAngle,edk::float32 upperAngle){
    this->lowerAngle = lowerAngle;
    this->upperAngle = upperAngle;
    this->revoluteType = EDK_JOINT_ANGLE;
}
//set motor
void edk::physics2D::RevoluteJoint2D::setMotor(edk::float32 maxTorque,edk::float32 speed){
    this->maxTorque = maxTorque;
    this->speed = speed;
    this->revoluteType = EDK_JOINT_MOTOR;
}
//remove type
void edk::physics2D::RevoluteJoint2D::removeType(){
    this->revoluteType=0u;
}

//GETERS
edk::uint8 edk::physics2D::RevoluteJoint2D::getRevoluteType(){
    return this->revoluteType;
}
edk::float32 edk::physics2D::RevoluteJoint2D::getLowerAngle(){
    return this->lowerAngle;
}
edk::float32 edk::physics2D::RevoluteJoint2D::getUpperAngle(){
    return this->upperAngle;
}
edk::float32 edk::physics2D::RevoluteJoint2D::getMaxTorque(){
    return this->maxTorque;
}
edk::float32 edk::physics2D::RevoluteJoint2D::getSpeed(){
    return this->speed;
}

//draw the joint in debug mode
void edk::physics2D::RevoluteJoint2D::draw(edk::size2f32 size,edk::color3f32 color){
    //
    size*=0.5;
    edk::GU::guColor3f32(color);
    edk::GU::guPushMatrix();
    edk::GU::guBegin(GU_LINES);
    //draw the first line
    edk::GU::guVertex2f32(this->worldPositionA.x - size.width,this->worldPositionA.y + size.height);
    edk::GU::guVertex2f32(this->worldPositionA.x + size.width,this->worldPositionA.y - size.height);
    //draw the second line
    edk::GU::guVertex2f32(this->worldPositionA.x + size.width,this->worldPositionA.y + size.height);
    edk::GU::guVertex2f32(this->worldPositionA.x - size.width,this->worldPositionA.y - size.height);
    edk::GU::guEnd();
    edk::GU::guPopMatrix();
}
