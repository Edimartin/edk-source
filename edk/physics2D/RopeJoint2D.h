#ifndef ROPEJOINT2D_H
#define ROPEJOINT2D_H

/*
Library DistanceJoint2D - Physics distance joint used with PhysicsObjects
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
#pragma message "Inside RopeJoint2D"
#endif

#pragma once
#include "Joint2D.h"

#ifdef printMessages
#pragma message "    Compiling RopeJoint2D"
#endif

namespace edk{
namespace physics2D{
class RopeJoint2D : public edk::physics2D::Joint2D{
public:
    RopeJoint2D(bool collide=false);
    ~RopeJoint2D();

    void Constructor(bool collide=false);
    void Destructor();

    //draw the joint in debug mode
    virtual void draw(edk::size2f32 size,edk::color3f32 color);

    edk::vec2f32 worldPositionB;
    edk::float32 maxLength;
private:
    edk::vec2f32 temp;
private:
    edk::classID classThis;
};
}//end namespace physics2D
}//end namespace edk

#endif // ROPEJOINT2D_H
