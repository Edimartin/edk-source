#ifndef REVOLUTEJOINT2D_H
#define REVOLUTEJOINT2D_H

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

#ifdef printMessages
#warning "Inside RevoluteJoint2D"
#endif

#pragma once
#include "Joint2D.h"
//Include edkGU
#include "../GU/GU.h"
//                                                              edk::float32 lowerAngle,edk::float32 upperAngle,
//                                                              edk::float32 maxTorque,edk::float32 speed,

#ifdef printMessages
#warning "    Compiling RevoluteJoint2D"
#endif

namespace edk{
namespace physics2D{
class RevoluteJoint2D : public edk::physics2D::Joint2D{
public:
    RevoluteJoint2D(bool collide=false);

    //
    void setAngle(edk::float32 lowerAngle,edk::float32 upperAngle);
    //set motor
    void setMotor(edk::float32 maxTorque,edk::float32 speed);
    //remove type
    void removeType();
    //GETERS
    edk::uint8 getRevoluteType();
    edk::float32 getLowerAngle();
    edk::float32 getUpperAngle();
    edk::float32 getMaxTorque();
    edk::float32 getSpeed();


    //draw the joint in debug mode
    virtual void draw(edk::size2f32 size,edk::color3f32 color);

private:
    edk::float32 lowerAngle;
    edk::float32 upperAngle;
    edk::float32 maxTorque;
    edk::float32 speed;
    edk::uint8 revoluteType;
};
}
}

#endif // REVOLUTEJOINT2D_H
