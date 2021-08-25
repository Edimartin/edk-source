#ifndef EDK_COLLISIONS_MATHCOLLISION_H
#define EDK_COLLISIONS_MATHCOLLISION_H

/*
Library MathCollision - Math functions to test collisions
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
#warning "Inside MathCollision"
#endif

#pragma once
#include "../TypeVec2.h"
#include "../Math.h"
#include "Vecs2f32.h"
#include "../shape/Polygon2D.h"

#ifdef printMessages
#warning "    Compiling MathCollision"
#endif

namespace edk{
namespace collision{
class MathCollision: public edk::Math{
public:
    MathCollision();
    virtual ~MathCollision();

    //BOUNDING BOX
    static bool boundingContact3D(edk::vec3f32 point,edk::vec3f32 vec1,edk::vec3f32 vec2);
    static bool boundingContact2D(edk::vec2f32 point,edk::vec2f32 vec1,edk::vec2f32 vec2);

    //POINT STRAIGHT
    static bool pointStraigh2D(edk::vec2f32 point,vec2f32 lineStart,vec2f32 lineEnd, edk::float32 radius=0.01f);
    static bool straightStraight2D(vec2f32 line1Start,vec2f32 line1End,
                                   vec2f32 line2Start,vec2f32 line2End,
                                   edk::collision::Vecs2f32* vecs
                                   );
    static bool straightStraight2DtoBool(vec2f32 line1Start,vec2f32 line1End,
                                         vec2f32 line2Start,vec2f32 line2End
                                         );
    static edk::collision::Vecs2f32 straightCircle2D(edk::vec2f32 lineStart,edk::vec2f32 lineEnd,edk::vec2f32 circlePosition,edk::float32 circleRadius);
    //static edk::collision::Vecs3f32 straightSphere3D(edk::vec3f32 lineStart,edk::vec3f32 lineEnd,edk::vec3f32 circlePosition,edk::float32 circleRadius);


    //POLYGON POINT
    static bool polygonPoint(edk::shape::Polygon2D polygon, edk::vec2f32 point);
protected:
private:
};
}//end namespace collision
}//end namespace edk

#endif // MATHCOLLISION2D_H
