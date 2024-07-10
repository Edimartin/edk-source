#ifndef KINEMATICSENSOR2D_H
#define KINEMATICSENSOR2D_H

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
#pragma message "Inside KinematicSensor2D"
#endif

#pragma once
#include <stdio.h>
#include "PhysicObject2D.h"
#include "StaticSensor2D.h"

#ifdef printMessages
#pragma message "    Compiling KinematicSensor2D"
#endif

namespace edk{
namespace physics2D{
class KinematicSensor2D: public edk::physics2D::StaticSensor2D{
public:
    KinematicSensor2D();
    virtual ~KinematicSensor2D();

    void Constructor(bool runFather=true);
private:
    edk::classID classThis;
};
}
}

#endif // KINEMATICSENSOR2D_H
