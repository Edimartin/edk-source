#include "RevoluteJoint2D.h"

/*
Library RevoluteJoint2D - Physics revolute joints used with PhysicsObjects
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

edk::physics2D::RevoluteJoint2D::RevoluteJoint2D(bool collide)
    :
      edk::physics2D::Joint2D(collide)
{
    this->type = EDK_REVOLUTE_JOINT;
    this->revoluteType = false;
    this->removeType();
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
