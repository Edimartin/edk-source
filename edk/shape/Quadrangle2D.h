#ifndef EDK_SHAPE_QUADRANGLE2D_H
#define EDK_SHAPE_QUADRANGLE2D_H

/*
Library Quadrangle2D - Draw a 2D Quadrangle in EDK Game Engine
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
#pragma message "Inside Quadrangle2D"
#endif

//Include the polygon
#pragma once
#include "Polygon2D.h"

#ifdef printMessages
#pragma message "    Compiling Quadrangle2D"
#endif

namespace edk{
namespace shape{
class Quadrangle2D : public edk::shape::Polygon2D{
public:
    Quadrangle2D();
    virtual ~Quadrangle2D();

    void Constructor();
    void Destructor();

    //Virtual Functions
    bool createPolygon(edk::uint32 vertexCount);
    void deletePolygon();

    //print the triangle
    void print();
    //Draw the triangle
    void draw();
    void drawWire();
protected:
private:
    //createPolygon
    bool createPolygon();
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // QUADRANGLE2D_H
