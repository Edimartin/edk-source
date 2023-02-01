#ifndef EDK_SHAPE_CIRCLE2D_H
#define EDK_SHAPE_CIRCLE2D_H

/*
Library Circle2D - Draw a Circle in EDK Game Engine
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
#warning "Inside Circle2D"
#endif

#pragma once
#include "../TypeVars.h"
#include "../DebugFile.h"
#include "../TypeVec2.h"
#include "../TypeColor.h"
#include "Polygon2D.h"
//Math
#include "../Math.h"

#ifdef printMessages
#warning "    Compiling Circle2D"
#endif

namespace edk{
namespace shape{
class Circle2D: public edk::shape::Polygon2D{
    public:
        Circle2D();
        Circle2D(edk::uint32 sides,edk::float32 radius);
        virtual ~Circle2D();
        //radius of the circle
        //edk::float32 radius;

        //Create the circle
        bool createPolygon(edk::uint32 sides,edk::float32 radius);

        //delete the polygonVertex
        void deletePolygon();

        //Set the color
        bool setPolygonColor(edk::color4f32 color);
        bool setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b);
        bool setPolygonColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);

        //print the polygon
        void print();
        //Draw the polygon
        void draw();
        void drawWire();
    protected:
    private:
};
}//end namespace shape
}//end namespace edk

#endif // CIRCLE2D_H
