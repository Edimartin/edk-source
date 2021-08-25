#ifndef PULLEYJOINT2D_H
#define PULLEYJOINT2D_H

/*
Library PulleyJoint2D - Physics pulley joint used with PhysicsObjects
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
#warning "Inside PulleyJoint2D"
#endif

#pragma once
#include "DistanceJoint2D.h"
#include "../TypeDefines.h"

#ifdef printMessages
#warning "    Compiling PulleyJoint2D"
#endif

namespace edk{
namespace physics2D{
class PulleyJoint2D : public edk::physics2D::DistanceJoint2D{
public:
    PulleyJoint2D(bool collide=false);

    edk::vec2f32 pulleyPositionA;
    edk::vec2f32 pulleyPositionB;
    edk::float32 lenghtA;
    edk::float32 lenghtB;

    //draw the joint in debug mode
    virtual void draw(edk::size2f32 size,edk::color3f32 color);
};
}
}

#endif // PULLEYJOINT2D_H
