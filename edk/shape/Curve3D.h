#ifndef EDK_SHAPE_CURVE3D_H
#define EDK_SHAPE_CURVE3D_H

/*
Library Curve3D - Template for a 3D Curve in EDK Game Engine
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
#warning "Inside Curve3D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../TypeVec3.h"

#ifdef printMessages
#warning "    Compiling Curve3D"
#endif

namespace edk{
namespace shape{
class Curve3D{
    public:
        Curve3D();
        Curve3D(edk::vec3f32 p1,edk::vec3f32 p2,edk::vec3f32 p3,edk::vec3f32 p4);
        virtual ~Curve3D();

        //return the point
        virtual edk::vec3f32 getPoint(edk::float32 percent);

        //the points of the curve
        edk::vec3f32 point1,point2,point3,point4;
    protected:
    private:
};
}//end namespace shape
}//end namespace edk

#endif // CURVE3D_H
