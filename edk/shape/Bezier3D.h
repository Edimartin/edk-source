#ifndef EDK_SHAPE_BEZIER3D_H
#define EDK_SHAPE_BEZIER3D_H

/*
Library Bezier3D - Bezier curve 3D in EDK Game Engine
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
#pragma message "Inside Bezier3D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec3.h"
#include "Curve3D.h"

#ifdef printMessages
#pragma message "    Compiling Bezier3D"
#endif

namespace edk{
namespace shape{
class Bezier3D : public edk::shape::Curve3D{
public:
    Bezier3D();
    Bezier3D(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4);
    virtual ~Bezier3D();

    void Constructor();
    void Constructor(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4);
    void Destructor();

    //return the point
    edk::vec3f32 getPoint(edk::float32 percent);
    static edk::vec3f32 getPoint(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4,edk::float32 percent);
protected:
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // BEZIER3D_H
