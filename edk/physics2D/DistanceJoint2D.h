#ifndef DISTANCEJOINT2D_H
#define DISTANCEJOINT2D_H

/*
Library DistanceJoint2D - Physics distance joint used with PhysicsObjects
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
#include "RevoluteJoint2D.h"

namespace edk{
namespace physics2D{
class DistanceJoint2D : public edk::physics2D::Joint2D{
public:
    DistanceJoint2D(bool collide=false);

    edk::vec2f32 worldPositionB;

    //draw the joint in debug mode
    virtual void draw(edk::size2f32 size,edk::color3f32 color);

    edk::float32 distance;
};
}
}

#endif // DISTANCEJOINT_H
