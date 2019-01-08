#ifndef CONTACT2D_H
#define CONTACT2D_H

/*
Library Contact2D - Physics Contacts used in the World2D
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
#warning "Inside Contact2D"
#endif

#pragma once
#include "../TypeDefines.h"
#include "../TypeVec2.h"
#include "PhysicObject2D.h"
#include "../vector/Array.h"

#ifdef printMessages
#warning "    Compiling Contact2D"
#endif

namespace edk{
namespace physics2D{
class Contact2D{
public:
    Contact2D(edk::classID pointer);

    //return the max contact poits
    edk::uint8 getMaxPoints();

    //return the contactPointer
    edk::classID getContactPointer();

    //disable the contact
    void disableContact();
    void enableContact();
    void setEnabled(bool enabled);
    bool isEnabled();

    //objects
    edk::physics2D::PhysicObject2D* objectA;
    edk::physics2D::PhysicObject2D* objectB;
    //shape ID's
    edk::uint32 shapeA;
    edk::uint32 shapeB;
    //Speed
    edk::float32 velocityA;
    edk::float32 velocityB;
    //world positions
    edk::vector::Array<edk::vec2f32> worldPositions;
    //ObjectA position
    edk::vector::Array<edk::vec2f32> objectAPositions;
    //ObjectB position
    edk::vector::Array<edk::vec2f32> objectBPositions;
    //Impulses
    edk::vector::Array<edk::float32> impulses;

    //poinst contact
    edk::uint8 points;

private:
    edk::classID contactPointer;
    //set if is enabled
    bool enabled;
};
}//end namespace physics2D
}//end namespace edk

#endif // CONTACT2D_H
