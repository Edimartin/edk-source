#ifndef WHEELJOINT2D_H
#define WHEELJOINT2D_H

/*
Library WheelJoint2D - Wheel Joint to be used in the physics 2D world.
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
#pragma message "Inside WheelJoint2D"
#endif

#ifdef printMessages
#pragma message "    Compiling WheelJoint2D"
#endif

/*
                                                        edk::vec2f32 direction,
                                                        edk::float32 maxTorque,edk::float32 speed,
                                                        bool collide
*/
#pragma once
#include "Joint2D.h"
#include "../TypeDefines.h"

namespace edk{
namespace physics2D{
class WheelJoint2D : public edk::physics2D::Joint2D{
public:
    WheelJoint2D(bool collide=false);

    //set motor
    void setMotor(edk::float32 maxTorque,edk::float32 speed);
    //remove type
    void removeType();
    //GETERS
    edk::uint8 getWheelType();
    edk::float32 getMaxTorque();
    edk::float32 getSpeed();

    //draw the joint in debug mode
    virtual void draw(edk::size2f32 size,edk::color3f32 color);

    //add an vector
    edk::vec2f32 direction;
private:
    edk::float32 maxTorque;
    edk::float32 speed;
    edk::uint8 WheelType;
};
}
}

#endif // WHEELJOINT2D_H
