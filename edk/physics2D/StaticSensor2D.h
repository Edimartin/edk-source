#ifndef STATICSENSOR2D_H
#define STATICSENSOR2D_H

/*
Library StaticSensor2D - Static Sensors in physics2D
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
#include <stdio.h>
#include "PhysicObject2D.h"
#include "../vector/BinaryTree.h"


namespace edk{
namespace physics2D{
class StaticSensor2D: public edk::physics2D::PhysicObject2D{
public:
    StaticSensor2D();
    ~StaticSensor2D();

    //get the bodyType
    /*
    virtual edk::uint8 getType();
    //return if it's a sensor
    virtual bool isSensor();
    */
    //Objects to activate the sensor
    //add
    bool addActivateObject(edk::physics2D::PhysicObject2D* object);
    //remove
    bool removeActivateObject(edk::physics2D::PhysicObject2D* object);
    //clean the activateObject
    void cleanActivateObjects();
    //test if have the object
    bool haveActivateObject(edk::physics2D::PhysicObject2D* object);
    //getSize
    edk::uint32 getActivateSize();

private:
    //objects Tree
    edk::vector::BinaryTree<edk::physics2D::PhysicObject2D*> tree;
};
}
}

#endif // STATICSENSOR2D_H
