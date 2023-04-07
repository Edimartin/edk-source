#ifndef CONTACT2D_H
#define CONTACT2D_H

/*
Library Contact2D - Physics Contacts used in the World2D
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
#pragma message "Inside Contact2D"
#endif

#pragma once
#include "../TypeDefines.h"
#include "../TypeVec2.h"
#include "PhysicObject2D.h"
#include "../vector/Array.h"

#ifdef printMessages
#pragma message "    Compiling Contact2D"
#endif

namespace edk{
namespace physics2D{
class World2D;
class Contact2D{
public:
    Contact2D(edk::classID pointer);

    friend edk::physics2D::World2D;

    //return the max contact poits
    edk::uint8 getMaxPoints();

    //return the contactPointer
    edk::classID getContactPointer();

    //disable the contact
    void disableContact();
    void enableContact();
    void setEnabled(bool enabled);
    bool isEnabled();
    //return true if aready have a contact with the same objects
    bool haveAreadyContact();

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
    //save if aready have the contact
    bool areadyContacted;
};
}//end namespace physics2D
}//end namespace edk

#endif // CONTACT2D_H
