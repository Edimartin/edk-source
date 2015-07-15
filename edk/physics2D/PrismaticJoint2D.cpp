#include "PrismaticJoint2D.h"

/*
Library PrismaticJoint2D - Physics prismatic joint used with PhysicsObjects
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
