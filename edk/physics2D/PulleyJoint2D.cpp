#include "PulleyJoint2D.h"

/*
Library PulleyJoint2D - Physics pulley joint used with PhysicsObjects
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

edk::physics2D::PulleyJoint2D::PulleyJoint2D(bool collide)
    :
        edk::physics2D::DistanceJoint2D(collide)
{
    this->type = EDK_PULLEY_JOINT;
    this->lenghtA=0.f;
    this->lenghtB=0.f;
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
