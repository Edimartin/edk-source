#ifndef JOINT2D_H
#define JOINT2D_H

/*
Library Joint2D - Physics joints used with PhysicsObjects
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
#include "PhysicObject2D.h"
#include "../TypeDefines.h"
#include "../Math.h"

namespace edk{
namespace physics2D{
class Joint2D{
public:
    Joint2D(bool collide=false);
    virtual ~Joint2D();

    edk::physics2D::PhysicObject2D* objectA;
    edk::physics2D::PhysicObject2D* objectB;

    edk::vec2f32 positionA;
    edk::vec2f32 positionB;

    edk::vec2f32 worldPositionA;

    //draw the joint in debug mode
    virtual void draw(edk::size2f32 size,edk::color3f32 color);

    //return the joint type
    edk::uint8 getType();
    //get Collide
    bool getCollide();
protected:
    edk::uint8 type;
private:
    bool collide;
};
}//end namespace
}

#endif // JOINT2D_H
