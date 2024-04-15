#ifndef EDK_COLLISIONS_LINE2D_H
#define EDK_COLLISIONS_LINE2D_H

/*
Library LineCollider2D - Teste collision between a line and other types
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
#pragma message "Inside LineContact2D"
#endif

#pragma once
#include "MathCollision.h"
#include "Vecs2f32.h"
#include "../shape/Vertex2D.h"
#include "../shape/Line2D.h"
#include "../shape/Circle2D.h"
#include "../shape/Polygon2D.h"

#ifdef printMessages
#pragma message "    Compiling LineContact2D"
#endif

namespace edk{
namespace collision{
class LineContact2D{
public:
    LineContact2D();
    virtual ~LineContact2D();

    void Constructor(bool runFather=true);

    //Contacts
    //point
    static bool contactPoint(edk::vec2f32 point,edk::shape::Line2D test);
    //line
    static bool contactLine(edk::shape::Line2D line,edk::shape::Line2D test, edk::collision::Vecs2f32* collision);
    //Circle
    static edk::collision::Vecs2f32 contactCircle(edk::shape::Circle2D circle,edk::shape::Line2D test);
    //polygon
    static edk::collision::Vecs2f32 contactPolygon(edk::shape::Polygon2D polygon,edk::shape::Line2D test);

protected:
private:
    edk::classID classThis;
};
}//end namesoace collision
}//end namespace edk

#endif // LINECOLLIDER2D_H
