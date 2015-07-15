#ifndef PRISMATICJOINT2D_H
#define PRISMATICJOINT2D_H

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

#pragma once
#include "Joint2D.h"
#include "../TypeDefines.h"

namespace edk{
namespace physics2D{
class PrismaticJoint2D : public edk::physics2D::Joint2D{
public:
    PrismaticJoint2D(bool collide=false);

    //set motor
    void setForce(edk::float32 maxForce,edk::float32 speed);
    //remove type
    void removeType();
    //GETERS
    edk::uint8 getPrismaticType();
    edk::float32 getMaxForce();
    edk::float32 getSpeed();

    //draw the joint in debug mode
    virtual void draw(edk::size2f32 size,edk::color3f32 color);

    //add an vector
    //bool collide;
    edk::vec2f32 direction;
    edk::float32 lowerDistance;
    edk::float32 upperDistance;
private:
    edk::float32 maxForce;
    edk::float32 speed;
    edk::uint8 prismaticType;
};
}
}

#endif // PRISMATICJOINT2D_H
