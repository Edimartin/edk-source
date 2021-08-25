#ifndef STATICSENSOR2D_H
#define STATICSENSOR2D_H

/*
Library StaticSensor2D - Static Sensors in physics2D
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

#ifdef printMessages
#warning "Inside StaticSensor2D"
#endif

#pragma once
#include <stdio.h>
#include "PhysicObject2D.h"
#include "../vector/BinaryTree.h"

#ifdef printMessages
#warning "    Compiling StaticSensor2D"
#endif


namespace edk{
namespace physics2D{
class StaticSensor2D: public edk::physics2D::PhysicObject2D{
public:
    StaticSensor2D();
    ~StaticSensor2D();

    //return if it's a sensor
    virtual bool isSensor();

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
