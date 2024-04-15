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
#pragma message "Inside MathCollision"
#endif

#pragma once
#include "../TypeVec2.h"
#include "../TypeVec3.h"
#include "../TypeRect.h"
#include "../TypeCube.h"
#include "../Math.h"
#include "Vecs2f32.h"
#include "Vecs3f32.h"
#include "Vecs4f32.h"
#include "../shape/Polygon2D.h"

#ifdef printMessages
#pragma message "    Compiling MathCollision"
#endif

namespace edk{
namespace collision{
class MathCollision: public edk::Math{
public:
    MathCollision();
    virtual ~MathCollision();

    void Constructor(bool runFather=true);

    //BOUNDING BOX
    static bool boundingContact3D(edk::vec3f32 point,edk::vec3f32 vec1,edk::vec3f32 vec2);
    static bool boundingContact2D(edk::vec2f32 point,edk::vec2f32 vec1,edk::vec2f32 vec2);

    //AABB 2D
    static bool aabb(edk::float32 x1,edk::float32 y1,edk::float32 width1,edk::float32 height1,
                     edk::float32 x2,edk::float32 y2,edk::float32 width2,edk::float32 height2
                     );
    static bool aabb(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2);
    static bool aabb(edk::rectf32 rect1,edk::rectf32 rect2);
    static bool aabbPoints(edk::float32 x1_1,edk::float32 y1_1,edk::float32 x1_2,edk::float32 y1_2,
                           edk::float32 x2_1,edk::float32 y2_1,edk::float32 x2_2,edk::float32 y2_2
                           );
    static bool aabbPoints(edk::vec2f32 position1_1,edk::vec2f32 position1_2,edk::vec2f32 position2_1,edk::vec2f32 position2_2);
    static bool aabbPoints(edk::rectf32 rect1,edk::rectf32 rect2);
    //X
    static bool aabbX(edk::float32 x1,edk::float32 width1,
                      edk::float32 x2,edk::float32 width2
                      );
    static bool aabbX(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2);
    static bool aabbX(edk::rectf32 rect1,edk::rectf32 rect2);
    static bool aabbPointsX(edk::float32 x1_1,edk::float32 x1_2,
                            edk::float32 x2_1,edk::float32 x2_2
                            );
    static bool aabbPointsX(edk::vec2f32 position1_1,edk::vec2f32 position1_2,edk::vec2f32 position2_1,edk::vec2f32 position2_2);
    static bool aabbPointsX(edk::rectf32 rect1,edk::rectf32 rect2);
    //Y
    static bool aabbY(edk::float32 y1,edk::float32 height1,
                      edk::float32 y2,edk::float32 height2
                      );
    static bool aabbY(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2);
    static bool aabbY(edk::rectf32 rect1,edk::rectf32 rect2);
    static bool aabbPointsY(edk::float32 y1_1,edk::float32 y1_2,
                            edk::float32 y2_1,edk::float32 y2_2
                            );
    static bool aabbPointsY(edk::vec2f32 position1_1,edk::vec2f32 position1_2,edk::vec2f32 position2_1,edk::vec2f32 position2_2);
    static bool aabbPointsY(edk::rectf32 rect1,edk::rectf32 rect2);
    //AABB 3D
    static bool aabb(edk::float32 x1,edk::float32 y1,edk::float32 z1,edk::float32 width1,edk::float32 height1,edk::float32 length1,
                     edk::float32 x2,edk::float32 y2,edk::float32 z2,edk::float32 width2,edk::float32 height2,edk::float32 length2
                     );
    static bool aabb(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2);
    static bool aabb(edk::cubef32 cube1,edk::cubef32 cube2);
    static bool aabbPoints(edk::float32 x1_1,edk::float32 y1_1,edk::float32 z1_1,edk::float32 x1_2,edk::float32 y1_2,edk::float32 z1_2,
                           edk::float32 x2_1,edk::float32 y2_1,edk::float32 z2_1,edk::float32 x2_2,edk::float32 y2_2,edk::float32 z2_2
                           );
    static bool aabbPoints(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2);
    static bool aabbPoints(edk::cubef32 cube1,edk::cubef32 cube2);
    //X
    static bool aabbX(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2);
    static bool aabbX(edk::cubef32 cube1,edk::cubef32 cube2);
    static bool aabbPointsX(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2);
    static bool aabbPointsX(edk::cubef32 cube1,edk::cubef32 cube2);
    //Y
    static bool aabbY(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2);
    static bool aabbY(edk::cubef32 cube1,edk::cubef32 cube2);
    static bool aabbPointsY(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2);
    static bool aabbPointsY(edk::cubef32 cube1,edk::cubef32 cube2);
    //Z
    static bool aabbZ(edk::float32 z1,edk::float32 length1,
                      edk::float32 z2,edk::float32 length2
                      );
    static bool aabbZ(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2);
    static bool aabbZ(edk::cubef32 cube1,edk::cubef32 cube2);
    static bool aabbPointsZ(edk::float32 z1_1,edk::float32 z1_2,
                            edk::float32 z2_1,edk::float32 z2_2
                            );
    static bool aabbPointsZ(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2);
    static bool aabbPointsZ(edk::cubef32 cube1,edk::cubef32 cube2);
    //XY
    static bool aabbXY(edk::float32 x1,edk::float32 y1,edk::float32 width1,edk::float32 height1,
                       edk::float32 x2,edk::float32 y2,edk::float32 width2,edk::float32 height2
                       );
    static bool aabbXY(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2);
    static bool aabbXY(edk::cubef32 cube1,edk::cubef32 cube2);
    static bool aabbPointsXY(edk::float32 x1_1,edk::float32 y1_1,edk::float32 x1_2,edk::float32 y1_2,
                             edk::float32 x2_1,edk::float32 y2_1,edk::float32 x2_2,edk::float32 y2_2
                             );
    static bool aabbPointsXY(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2);
    static bool aabbPointsXY(edk::cubef32 cube1,edk::cubef32 cube2);
    //XZ
    static bool aabbXZ(edk::float32 x1,edk::float32 z1,edk::float32 width1,edk::float32 length1,
                       edk::float32 x2,edk::float32 z2,edk::float32 width2,edk::float32 length2
                       );
    static bool aabbXZ(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2);
    static bool aabbXZ(edk::cubef32 cube1,edk::cubef32 cube2);
    static bool aabbPointsXZ(edk::float32 x1_1,edk::float32 z1_1,edk::float32 x1_2,edk::float32 z1_2,
                             edk::float32 x2_1,edk::float32 z2_1,edk::float32 x2_2,edk::float32 z2_2
                             );
    static bool aabbPointsXZ(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2);
    static bool aabbPointsXZ(edk::cubef32 cube1,edk::cubef32 cube2);
    //YZ
    static bool aabbYZ(edk::float32 y1,edk::float32 z1,edk::float32 height1,edk::float32 length1,
                       edk::float32 y2,edk::float32 z2,edk::float32 height2,edk::float32 length2
                       );
    static bool aabbYZ(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2);
    static bool aabbYZ(edk::cubef32 cube1,edk::cubef32 cube2);
    static bool aabbPointsYZ(edk::float32 y1_1,edk::float32 z1_1,edk::float32 y1_2,edk::float32 z1_2,
                             edk::float32 y2_1,edk::float32 z2_1,edk::float32 y2_2,edk::float32 z2_2
                             );
    static bool aabbPointsYZ(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2);
    static bool aabbPointsYZ(edk::cubef32 cube1,edk::cubef32 cube2);

    //test if a bounsingBox2D is inside other boundingBox2D
    static bool boundingBox2DFirstInsideSecond(edk::float32 x1,edk::float32 y1,edk::float32 width1,edk::float32 height1,
                                               edk::float32 x2,edk::float32 y2,edk::float32 width2,edk::float32 height2
                                               );
    static bool boundingBox2DFirstInsideSecond(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2);
    static bool boundingBox2DFirstInsideSecond(edk::rectf32 rect1,edk::rectf32 rect2);
    static bool boundingBox2DPointsFirstInsideSecond(edk::float32 x1_1,edk::float32 y1_1,edk::float32 x1_2,edk::float32 y1_2,
                                                     edk::float32 x2_1,edk::float32 y2_1,edk::float32 x2_2,edk::float32 y2_2
                                                     );
    static bool boundingBox2DPointsFirstInsideSecond(edk::vec2f32 position1_1,edk::vec2f32 position1_2,edk::vec2f32 position2_1,edk::vec2f32 position2_2);
    static bool boundingBox2DPointsFirstInsideSecond(edk::rectf32 rect1,edk::rectf32 rect2);
    //test if a bounsingBox3D is inside other boundingBox3D
    static bool boundingBox3DFirstInsideSecond(edk::float32 x1,edk::float32 y1,edk::float32 z1,edk::float32 width1,edk::float32 height1,edk::float32 lenght1,
                                               edk::float32 x2,edk::float32 y2,edk::float32 z2,edk::float32 width2,edk::float32 height2,edk::float32 lenght2
                                               );
    static bool boundingBox3DFirstInsideSecond(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2);
    static bool boundingBox3DFirstInsideSecond(edk::cubef32 cube1,edk::cubef32 cube2);
    static bool boundingBox3DPointsFirstInsideSecond(edk::float32 x1_1,edk::float32 y1_1,edk::float32 z1_1,edk::float32 x1_2,edk::float32 y1_2,edk::float32 z1_2,
                                                     edk::float32 x2_1,edk::float32 y2_1,edk::float32 z2_1,edk::float32 x2_2,edk::float32 y2_2,edk::float32 z2_2
                                                     );
    static bool boundingBox3DPointsFirstInsideSecond(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2);
    static bool boundingBox3DPointsFirstInsideSecond(edk::cubef32 cube1,edk::cubef32 cube2);

    //POINT STRAIGHT
    static bool pointStraigh2D(edk::float32 pointX,edk::float32 pointY,float32 lineX1,float32 lineY1,float32 lineX2,float32 lineY2, edk::float32 radius=0.01f);
    static bool pointStraigh2D(edk::vec2f32 point,vec2f32 lineStart,vec2f32 lineEnd, edk::float32 radius=0.01f);
    static bool straightStraight2D(float32 line1StartX,float32 line1StartY,float32 line1EndX,float32 line1EndY,
                                   float32 line2StartX,float32 line2StartY,float32 line2EndX,float32 line2EndY,
                                   edk::collision::Vecs2f32* vecs
                                   );
    static bool straightStraight2D(vec2f32 line1Start,vec2f32 line1End,
                                   vec2f32 line2Start,vec2f32 line2End,
                                   edk::collision::Vecs2f32* vecs
                                   );
    static bool straightStraight2DtoBool(float32 line1StartX,float32 line1StartY,float32 line1EndX,float32 line1EndY,
                                         float32 line2StartX,float32 line2StartY,float32 line2EndX,float32 line2EndY
                                         );
    static bool straightStraight2DtoBool(vec2f32 line1Start,vec2f32 line1End,
                                         vec2f32 line2Start,vec2f32 line2End
                                         );

    static edk::collision::Vecs2f32 straightCircle2D(edk::vec2f32 lineStart,edk::vec2f32 lineEnd,edk::vec2f32 circlePosition,edk::float32 circleRadius);
    static edk::collision::Vecs3f32 straightSphere3D(edk::vec3f32 lineStart,edk::vec3f32 lineEnd,edk::vec3f32 spherePosition,edk::float32 sphereRadius);

    //http://www.lighthouse3d.com/tutorials/maths/ray-triangle-intersection/
    static bool straightTriangle3D(edk::vec3f32 lineStart,edk::vec3f32 lineEnd,
                                   edk::vec3f32 triangle1,edk::vec3f32 triangle2,edk::vec3f32 triangle3,
                                   edk::vec3f32* result
                                   );


    //POLYGON POINT
    static bool polygonPoint(edk::shape::Polygon2D polygon, edk::vec2f32 point);

    //RECTS
    static bool rectRectPoints(edk::rectf32 r1,edk::rectf32 r2,
                               edk::collision::Vecs2f32* vecs
                               );
protected:
private:
    edk::classID classThis;
};
}//end namespace collision
}//end namespace edk

#endif // MATHCOLLISION2D_H
