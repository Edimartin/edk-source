#include "WheelJoint2D.h"

/*
Library WheelJoint2D - Wheel Joint to be used in the physics 2D world.
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

edk::physics2D::WheelJoint2D::WheelJoint2D(bool collide)
    : edk::physics2D::Joint2D(collide)
{
    this->type = EDK_WHEEL_JOINT;edkEnd();
    this->removeType();edkEnd();
}

//set motor
void edk::physics2D::WheelJoint2D::setMotor(edk::float32 maxTorque,edk::float32 speed){
    this->maxTorque = maxTorque;edkEnd();
    this->speed = speed;edkEnd();
    this->WheelType = EDK_JOINT_MOTOR;edkEnd();
}
//remove type
void edk::physics2D::WheelJoint2D::removeType(){
    this->WheelType = 0u;edkEnd();
}
//GETERS
edk::uint8 edk::physics2D::WheelJoint2D::getWheelType(){
    return this->WheelType;edkEnd();
}
edk::float32 edk::physics2D::WheelJoint2D::getMaxTorque(){
    return this->getMaxTorque();edkEnd();
}
edk::float32 edk::physics2D::WheelJoint2D::getSpeed(){
    return this->speed;edkEnd();
}
//draw the joint in debug mode
void edk::physics2D::WheelJoint2D::draw(edk::size2f32,edk::color3f32 color){
    edk::GU::guColor3f32(color);edkEnd();
    edk::GU::guPushMatrix();edkEnd();
    edk::GU::guBegin(GU_LINE_STRIP);edkEnd();
    //
    edk::GU::guVertex2f32(this->objectA->position.x,this->objectA->position.y);edkEnd();
    edk::GU::guVertex2f32(this->objectB->position.x,this->objectB->position.y);edkEnd();
    edk::GU::guVertex2f32(this->worldPositionA.x,this->worldPositionA.y);edkEnd();
    edk::GU::guEnd();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
