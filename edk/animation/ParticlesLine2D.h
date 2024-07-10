#ifndef PARTICLESLINE2D_H
#define PARTICLESLINE2D_H

/*
Biblioteca C++ ParticlesLine2D - Manage a particle system generated in a line
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
#pragma message "Inside ParticlesLine2D"
#endif

#pragma once
#include "ParticlesPoint2D.h"

#ifdef printMessages
#pragma message "    Compiling ParticlesLine2D"
#endif

namespace edk{
namespace animation{
class ParticlesLine2D : public edk::animation::ParticlesPoint2D{
public:
    ParticlesLine2D();
    virtual ~ParticlesLine2D();

    void Constructor(bool runFather=true);

    //set the points
    void setP1Local(edk::vec2f32 point);
    void setP1Local(edk::float32 px,edk::float32 py);
    void setP2Local(edk::vec2f32 point);
    void setP2Local(edk::float32 px,edk::float32 py);
    void setPointsLocal(edk::vec2f32 p1,edk::vec2f32 p2);
    void setPointsLocal(edk::float32 p1x,edk::float32 p1y,edk::float32 p2x,edk::float32 p2y);
    void setPointsWorld(edk::vec2f32 p1,edk::vec2f32 p2);
    void setPointsWorld(edk::float32 p1x,edk::float32 p1y,edk::float32 p2x,edk::float32 p2y);

    //draw the angles vector
    virtual void drawAngles(edk::float32 size,edk::color3f32 color);
    virtual void drawAngles(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
protected:
    //get the position
    virtual edk::vec2f32 newPosition();
private:
    edk::vec2f32 point1,point2;
private:
    edk::classID classThis;
};
}//end namespace animation
}//end namespace edk

#endif // PARTICLESLINE2D_H
