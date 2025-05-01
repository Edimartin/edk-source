#ifndef PRISMATICJOINT2D_H
#define PRISMATICJOINT2D_H

/*
Library PrismaticJoint2D - Physics prismatic joint used with PhysicsObjects
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
#pragma message "Inside PrismaticJoint2D"
#endif

#pragma once
#include "Joint2D.h"
#include "../TypeDefines.h"

#ifdef printMessages
#pragma message "    Compiling PrismaticJoint2D"
#endif

namespace edk{
namespace physics2D{
class PrismaticJoint2D : public edk::physics2D::Joint2D{
public:
    PrismaticJoint2D(bool collide=false);
    ~PrismaticJoint2D();

    void Constuctor(bool collide=false);
    void Destuctor();

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
private:
    edk::classID classThis;
};
}
}

#endif // PRISMATICJOINT2D_H
