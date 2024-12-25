#include "MathCollision.h"

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
#pragma message "            Inside MathCollision.cpp"
#endif

edk::collision::MathCollision::MathCollision(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::collision::MathCollision::~MathCollision(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
    }
}

void edk::collision::MathCollision::Constructor(bool runFather){
    if(runFather){
        edk::Math::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;
    }
}

bool edk::collision::MathCollision::boundingContact3D(edk::vec3f32 point,edk::vec3f32 vec1,edk::vec3f32 vec2){
    //
    edk::float32 xMe,yMe,zMe;edkEnd();
    edk::float32 xMa,yMa,zMa;edkEnd();

    if(vec1.x>vec2.x){
        xMa=vec1.x;edkEnd();
        xMe=vec2.x;edkEnd();
    }
    else{
        xMa=vec2.x;edkEnd();
        xMe=vec1.x;edkEnd();
    }

    if(vec1.y>vec2.y){
        yMa=vec1.y;edkEnd();
        yMe=vec2.y;edkEnd();
    }
    else{
        yMa=vec2.y;edkEnd();
        yMe=vec1.y;edkEnd();
    }

    if(vec1.z>vec2.z){
        zMa=vec1.z;edkEnd();
        zMe=vec2.z;edkEnd();
    }
    else{
        zMa=vec2.z;edkEnd();
        zMe=vec1.z;edkEnd();
    }

    //Entao ele calcula se o ponto esta dentro ou fora
    if(point.x <= xMa && point.x>= xMe){
        if(point.y <= yMa && point.y>= yMe){
            if(point.z <= zMa && point.z>= zMe){
                return true;
            }
        }
    }
    return false;
}
bool edk::collision::MathCollision::boundingContact2D(edk::vec2f32 point,edk::vec2f32 vec1,edk::vec2f32 vec2){
    //
    edk::float32 xMe,yMe;edkEnd();
    edk::float32 xMa,yMa;edkEnd();

    if(vec1.x>vec2.x){
        xMa=vec1.x;edkEnd();
        xMe=vec2.x;edkEnd();
    }
    else{
        xMa=vec2.x;edkEnd();
        xMe=vec1.x;edkEnd();
    }

    if(vec1.y>vec2.y){
        yMa=vec1.y;edkEnd();
        yMe=vec2.y;edkEnd();
    }
    else{
        yMa=vec2.y;edkEnd();
        yMe=vec1.y;edkEnd();
    }

    //Entao ele calcula se o ponto esta dentro ou fora
    if(point.x <= xMa && point.x>= xMe){
        if(point.y <= yMa && point.y>= yMe){
            return true;
        }
    }
    return false;
}
//2D
bool edk::collision::MathCollision::aabb(edk::float32 x1,edk::float32 y1,edk::float32 width1,edk::float32 height1,
                                         edk::float32 x2,edk::float32 y2,edk::float32 width2,edk::float32 height2
                                         ){
    return edk::collision::MathCollision::aabb(edk::vec2f32(x1,y1),edk::size2f32(width1,height1),edk::vec2f32(x2,y2),edk::size2f32(width2,height2));edkEnd();
}
bool edk::collision::MathCollision::aabb(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2){
    return edk::collision::MathCollision::aabb(edk::rectf32(position1.x,position1.y,size1.width,size1.height),
                                               edk::rectf32(position2.x,position2.y,size2.width,size2.height)
                                               );edkEnd();
}
bool edk::collision::MathCollision::aabb(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect2.origin.x <= rect1.origin.x + rect1.size.width
            &&
            rect2.origin.x + rect2.size.width >= rect1.origin.x
            &&
            rect2.origin.y <= rect1.origin.y + rect1.size.height
            &&
            rect2.origin.y + rect2.size.height >= rect1.origin.y
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbLeft(edk::float32 x1,edk::float32 width1,
                                             edk::float32 x2,edk::float32 width2
                                             ){
    return edk::collision::MathCollision::aabbLeft(edk::vec2f32(x1,0.f),edk::size2f32(width1,0.f),
                                                   edk::vec2f32(x2,0.f),edk::size2f32(width2,0.f)
                                                   );
}
bool edk::collision::MathCollision::aabbLeft(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2){
    return edk::collision::MathCollision::aabbLeft(edk::rectf32(position1.x,position1.y,size1.width,size1.height),
                                                   edk::rectf32(position2.x,position2.y,size2.width,size2.height)
                                                   );
}
bool edk::collision::MathCollision::aabbLeft(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect1.origin.x <= rect2.origin.x + rect2.size.width
            ||
            rect1.origin.x + rect1.size.width <= rect2.origin.x + rect2.size.width
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbRight(edk::float32 x1,edk::float32 width1,
                                              edk::float32 x2,edk::float32 width2
                                              ){
    return edk::collision::MathCollision::aabbRight(edk::vec2f32(x1,0.f),edk::size2f32(width1,0.f),
                                                    edk::vec2f32(x2,0.f),edk::size2f32(width2,0.f)
                                                    );
}
bool edk::collision::MathCollision::aabbRight(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2){
    return edk::collision::MathCollision::aabbRight(edk::rectf32(position1.x,position1.y,size1.width,size1.height),
                                                    edk::rectf32(position2.x,position2.y,size2.width,size2.height)
                                                    );
}
bool edk::collision::MathCollision::aabbRight(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect1.origin.x >= rect2.origin.x
            ||
            rect1.origin.x + rect1.size.width >= rect2.origin.x
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbUp(edk::float32 y1,edk::float32 height1,
                                           edk::float32 y2,edk::float32 height2
                                           ){
    return edk::collision::MathCollision::aabbUp(edk::vec2f32 (0.f,y1),edk::size2f32 (0.f,height1),
                                                 edk::vec2f32 (0.f,y2),edk::size2f32 (0.f,height2)
                                                 );
}
bool edk::collision::MathCollision::aabbUp(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2){
    return edk::collision::MathCollision::aabbUp(edk::rectf32(position1.x,position1.y,size1.width,size1.height),
                                                 edk::rectf32(position2.x,position2.y,size2.width,size2.height)
                                                 );
}
bool edk::collision::MathCollision::aabbUp(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect1.origin.y >= rect2.origin.y
            ||
            rect1.origin.y + rect1.size.height >= rect2.origin.y
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbDown(edk::float32 y1,edk::float32 height1,
                                             edk::float32 y2,edk::float32 height2
                                             ){
    return edk::collision::MathCollision::aabbDown(edk::vec2f32 (0.f,y1),edk::size2f32 (0.f,height1),
                                                   edk::vec2f32 (0.f,y2),edk::size2f32 (0.f,height2)
                                                   );
}
bool edk::collision::MathCollision::aabbDown(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2){
    return edk::collision::MathCollision::aabbDown(edk::rectf32(position1.x,position1.y,size1.width,size1.height),
                                                   edk::rectf32(position2.x,position2.y,size2.width,size2.height)
                                                   );
}
bool edk::collision::MathCollision::aabbDown(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect1.origin.y <= rect2.origin.y + rect2.size.height
            ||
            rect1.origin.y + rect1.size.height <= rect2.origin.y + rect2.size.height
            )
        return true;
    return false;
}
//aabb where the first is inside the secons
bool edk::collision::MathCollision::aabbInside(edk::float32 insideX,edk::float32 insideY,
                                               edk::float32 insideWidth,edk::float32 insideHeight,
                                               edk::float32 outsideX,edk::float32 outsideY,
                                               edk::float32 outsideWidth,edk::float32 outsideHeight
                                               ){
    return edk::collision::MathCollision::aabbInside(edk::vec2f32(insideX,insideY),
                                                     edk::size2f32(insideWidth,insideHeight),
                                                     edk::vec2f32(outsideX,outsideY),
                                                     edk::size2f32(outsideWidth,outsideHeight)
                                                     );
}
bool edk::collision::MathCollision::aabbInside(edk::vec2f32 insidePosition,
                                               edk::size2f32 insideSize,
                                               edk::vec2f32 outsidePosition,
                                               edk::size2f32 outsideSize
                                               ){
    return edk::collision::MathCollision::aabbInside(edk::rectf32(insidePosition,insideSize),
                                                     edk::rectf32(outsidePosition,outsideSize)
                                                     );
}
bool edk::collision::MathCollision::aabbInside(edk::rectf32 insideRect,edk::rectf32 outsideRect){
    insideRect.convertIntoPoints();
    outsideRect.convertIntoPoints();
    return edk::collision::MathCollision::aabbPointsInside(insideRect,outsideRect);
}
//aabb points
bool edk::collision::MathCollision::aabbPoints(edk::float32 x1_1,edk::float32 y1_1,edk::float32 x1_2,edk::float32 y1_2,
                                               edk::float32 x2_1,edk::float32 y2_1,edk::float32 x2_2,edk::float32 y2_2
                                               ){
    return edk::collision::MathCollision::aabbPoints(edk::vec2f32(x1_1,y1_1),edk::vec2f32(x1_2,y1_2),
                                                     edk::vec2f32(x2_1,y2_1),edk::vec2f32(x2_2,y2_2)
                                                     );
}
bool edk::collision::MathCollision::aabbPoints(edk::vec2f32 position1_1,edk::vec2f32 position1_2,edk::vec2f32 position2_1,edk::vec2f32 position2_2){
    return edk::collision::MathCollision::aabbPoints(edk::rectf32(position1_1.x,position1_1.y,position1_2.x,position1_2.y),
                                                     edk::rectf32(position2_1.x,position2_1.y,position2_2.x,position2_2.y)
                                                     );edkEnd();
}
bool edk::collision::MathCollision::aabbPoints(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect2.origin.x <= rect1.size.width
            &&
            rect2.size.width >= rect1.origin.x
            &&
            rect2.origin.y <= rect1.size.height
            &&
            rect2.size.height >= rect1.origin.y
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbPointsLeft(edk::float32 x1_1,
                                                   edk::float32 x1_2,
                                                   edk::float32 x2_1,
                                                   edk::float32 x2_2
                                                   ){
    return edk::collision::MathCollision::aabbPointsLeft(edk::vec2f32(x1_1,0.f),edk::vec2f32(x1_2,0.f),
                                                         edk::vec2f32(x2_1,0.f),edk::vec2f32(x2_2,0.f)
                                                         );
}
bool edk::collision::MathCollision::aabbPointsLeft(edk::vec2f32 position1_1,edk::vec2f32 position1_2,
                                                   edk::vec2f32 position2_1,edk::vec2f32 position2_2
                                                   ){
    return edk::collision::MathCollision::aabbPointsLeft(edk::rectf32(position1_1.x,position1_1.y,position1_2.x,position1_2.y),
                                                         edk::rectf32(position2_1.x,position2_1.y,position2_2.x,position2_2.y)
                                                         );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsLeft(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect1.origin.x <= rect2.size.width
            ||
            rect1.size.width <= rect2.size.width
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbPointsRight(edk::float32 x1_1,
                                                    edk::float32 x1_2,
                                                    edk::float32 x2_1,
                                                    edk::float32 x2_2
                                                    ){
    return edk::collision::MathCollision::aabbPointsRight(edk::vec2f32(x1_1,0.f),edk::vec2f32(x1_2,0.f),
                                                          edk::vec2f32(x2_1,0.f),edk::vec2f32(x2_2,0.f)
                                                          );
}
bool edk::collision::MathCollision::aabbPointsRight(edk::vec2f32 position1_1,edk::vec2f32 position1_2,
                                                    edk::vec2f32 position2_1,edk::vec2f32 position2_2
                                                    ){
    return edk::collision::MathCollision::aabbPointsRight(edk::rectf32(position1_1.x,position1_1.y,position1_2.x,position1_2.y),
                                                          edk::rectf32(position2_1.x,position2_1.y,position2_2.x,position2_2.y)
                                                          );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsRight(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect1.origin.x >= rect2.origin.x
            ||
            rect1.size.width >= rect2.origin.x
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbPointsUp(edk::float32 y1_1,
                                                 edk::float32 y1_2,
                                                 edk::float32 y2_1,
                                                 edk::float32 y2_2
                                                 ){
    return edk::collision::MathCollision::aabbPointsUp(edk::vec2f32(0.f,y1_1),edk::vec2f32(0.f,y1_2),
                                                       edk::vec2f32(0.f,y2_1),edk::vec2f32(0.f,y2_2)
                                                       );
}
bool edk::collision::MathCollision::aabbPointsUp(edk::vec2f32 position1_1,edk::vec2f32 position1_2,
                                                 edk::vec2f32 position2_1,edk::vec2f32 position2_2
                                                 ){
    return edk::collision::MathCollision::aabbPointsUp(edk::rectf32(position1_1.x,position1_1.y,position1_2.x,position1_2.y),
                                                       edk::rectf32(position2_1.x,position2_1.y,position2_2.x,position2_2.y)
                                                       );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsUp(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect1.origin.y >= rect2.origin.y
            ||
            rect1.size.height >= rect2.origin.y
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbPointsDown(edk::float32 y1_1,
                                                   edk::float32 y1_2,
                                                   edk::float32 y2_1,
                                                   edk::float32 y2_2
                                                   ){
    return edk::collision::MathCollision::aabbPointsDown(edk::vec2f32(0.f,y1_1),edk::vec2f32(0.f,y1_2),
                                                         edk::vec2f32(0.f,y2_1),edk::vec2f32(0.f,y2_2)
                                                         );
}
bool edk::collision::MathCollision::aabbPointsDown(edk::vec2f32 position1_1,edk::vec2f32 position1_2,
                                                   edk::vec2f32 position2_1,edk::vec2f32 position2_2
                                                   ){
    return edk::collision::MathCollision::aabbPointsDown(edk::rectf32(position1_1.x,position1_1.y,position1_2.x,position1_2.y),
                                                         edk::rectf32(position2_1.x,position2_1.y,position2_2.x,position2_2.y)
                                                         );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsDown(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect1.origin.y <= rect2.size.height
            ||
            rect1.size.height <= rect2.size.height
            )
        return true;
    return false;
}
//abb points where the first is inside the second
bool edk::collision::MathCollision::aabbPointsInside(edk::float32 insideX1,edk::float32 insideY1,
                                                     edk::float32 insideX2,edk::float32 insideY2,
                                                     edk::float32 outsidexX1,edk::float32 outsideyY1,
                                                     edk::float32 outsidexX2,edk::float32 outsideY2
                                                     ){
    return edk::collision::MathCollision::aabbPointsInside(edk::vec2f32(insideX1,insideY1),
                                                           edk::vec2f32(insideX2,insideY2),
                                                           edk::vec2f32(outsidexX1,outsideyY1),
                                                           edk::vec2f32(outsidexX2,outsideY2)
                                                           );
}
bool edk::collision::MathCollision::aabbPointsInside(edk::vec2f32 insidePosition1,
                                                     edk::vec2f32 insidePosition2,
                                                     edk::vec2f32 outsidePosition1,
                                                     edk::vec2f32 outsidePosition2
                                                     ){
    return edk::collision::MathCollision::aabbPointsInside(edk::rectf32(insidePosition1.x,insidePosition1.y,
                                                                        insidePosition2.x,insidePosition2.y
                                                                        ),
                                                           edk::rectf32(outsidePosition1.x,outsidePosition1.y,
                                                                        outsidePosition2.x,outsidePosition2.y
                                                                        )
                                                           );
}
bool edk::collision::MathCollision::aabbPointsInside(edk::rectf32 insideRect,edk::rectf32 outsideRect){
    if(insideRect.origin.x >= outsideRect.origin.x
            &&
            insideRect.origin.y >= outsideRect.origin.y
            &&
            insideRect.origin.x <= outsideRect.size.width
            &&
            insideRect.origin.y <= outsideRect.size.height
            &&
            insideRect.size.width >= outsideRect.origin.x
            &&
            insideRect.size.height >= outsideRect.origin.y
            &&
            insideRect.size.width <= outsideRect.size.width
            &&
            insideRect.size.height <= outsideRect.size.height
            )
        return true;
    return false;
}
//X
bool edk::collision::MathCollision::aabbX(edk::float32 x1,edk::float32 width1,
                                          edk::float32 x2,edk::float32 width2
                                          ){
    return edk::collision::MathCollision::aabbX(edk::vec2f32(x1,0.f),edk::size2f32(width1,0.f),edk::vec2f32(x2,0.f),edk::size2f32(width2,0.f));edkEnd();
}
bool edk::collision::MathCollision::aabbX(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2){
    return edk::collision::MathCollision::aabbX(edk::rectf32(position1.x,position1.y,size1.width,size1.height),
                                                edk::rectf32(position2.x,position2.y,size2.width,size2.height)
                                                );edkEnd();
}
bool edk::collision::MathCollision::aabbX(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect2.origin.x <= rect1.origin.x + rect1.size.width
            &&
            rect2.origin.x + rect2.size.width >= rect1.origin.x
            )
        return true;
    return false;
}
//aabb X inside
bool edk::collision::MathCollision::aabbXInside(edk::float32 insideX,edk::float32 insideWidth,
                                                edk::float32 outsideX,edk::float32 outsideWidth
                                                ){
    return edk::collision::MathCollision::aabbXInside(edk::vec2f32 (insideX,0.f),edk::size2f32 (insideWidth,0.f),
                                                      edk::vec2f32 (outsideX,0.f),edk::size2f32 (outsideWidth,0.f)
                                                      );
}
bool edk::collision::MathCollision::aabbXInside(edk::vec2f32 insidePosition,edk::size2f32 insideSize,
                                                edk::vec2f32 outsidePosition,edk::size2f32 outsideSize
                                                ){
    return edk::collision::MathCollision::aabbXInside(edk::rectf32(insidePosition,insideSize),
                                                      edk::rectf32(outsidePosition,outsideSize)
                                                      );
}
bool edk::collision::MathCollision::aabbXInside(edk::rectf32 insideRect,edk::rectf32 outsideRect){
    return edk::collision::MathCollision::aabbPointsXInside(insideRect,outsideRect);
}
//aabb X points
bool edk::collision::MathCollision::aabbPointsX(edk::float32 x1_1,edk::float32 x1_2,
                                                edk::float32 x2_1,edk::float32 x2_2
                                                ){
    return edk::collision::MathCollision::aabbPointsX(edk::vec2f32(x1_1,0.f),edk::vec2f32(x1_2,0.f),edk::vec2f32(x2_1,0.f),edk::vec2f32(x2_2,0.f));edkEnd();
}
bool edk::collision::MathCollision::aabbPointsX(edk::vec2f32 position1_1,edk::vec2f32 position1_2,edk::vec2f32 position2_1,edk::vec2f32 position2_2){
    return edk::collision::MathCollision::aabbPointsX(edk::rectf32(position1_1.x,position1_1.y,position1_2.x,position1_2.y),
                                                      edk::rectf32(position2_1.x,position2_1.y,position2_2.x,position2_2.y)
                                                      );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsX(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect2.origin.x <= rect1.size.width
            &&
            rect2.size.width >= rect1.origin.x
            )
        return true;
    return false;
}
//aabb X points inside
bool edk::collision::MathCollision::aabbPointsXInside(edk::float32 insideX1,edk::float32 insideX2,
                                                      edk::float32 outsideX1,edk::float32 outsideX2
                                                      ){
    return edk::collision::MathCollision::aabbPointsXInside(edk::vec2f32(insideX1,0.f),edk::vec2f32(insideX2,0.f),
                                                            edk::vec2f32(outsideX1,0.f),edk::vec2f32(outsideX2,0.f)
                                                            );
}
bool edk::collision::MathCollision::aabbPointsXInside(edk::vec2f32 insidePosition1,edk::vec2f32 insidePosition2,
                                                      edk::vec2f32 outsidePosition1,edk::vec2f32 outsidePosition2
                                                      ){
    return edk::collision::MathCollision::aabbPointsXInside(edk::rectf32(insidePosition1.x,insidePosition1.y,
                                                                         insidePosition2.x,insidePosition2.y
                                                                         ),
                                                            edk::rectf32(outsidePosition1.x,outsidePosition1.y,
                                                                         outsidePosition2.x,outsidePosition2.y
                                                                         )
                                                            );
}
bool edk::collision::MathCollision::aabbPointsXInside(edk::rectf32 insideRect,edk::rectf32 outsideRect){
    if(insideRect.origin.x >= outsideRect.origin.x
            //&&
            //insideRect.origin.y >= outsideRect.origin.y
            &&
            insideRect.origin.x <= outsideRect.size.width
            //&&
            //insideRect.origin.y <= outsideRect.size.height
            &&
            insideRect.size.width >= outsideRect.origin.x
            //&&
            //insideRect.size.height >= outsideRect.origin.y
            &&
            insideRect.size.width <= outsideRect.size.width
            //&&
            //insideRect.size.height <= outsideRect.size.height
            )
        return true;
    return false;
}
//aabb Y
bool edk::collision::MathCollision::aabbY(edk::float32 y1,edk::float32 height1,
                                          edk::float32 y2,edk::float32 height2
                                          ){
    return edk::collision::MathCollision::aabbY(edk::vec2f32(0.f,y1),edk::size2f32(0.f,height1),edk::vec2f32(0.f,y2),edk::size2f32(0.f,height2));edkEnd();
}
bool edk::collision::MathCollision::aabbY(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2){
    return edk::collision::MathCollision::aabbY(edk::rectf32(position1.x,position1.y,size1.width,size1.height),
                                                edk::rectf32(position2.x,position2.y,size2.width,size2.height)
                                                );edkEnd();
}
bool edk::collision::MathCollision::aabbY(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect2.origin.y <= rect1.origin.y + rect1.size.height
            &&
            rect2.origin.y + rect2.size.height >= rect1.origin.y
            )
        return true;
    return false;
}
//aabb Y inside
bool edk::collision::MathCollision::aabbYInside(edk::float32 insideY,edk::float32 insideHeight,
                                                edk::float32 outsideY,edk::float32 outsideHeight
                                                ){
    return edk::collision::MathCollision::aabbYInside(edk::vec2f32(0.f,insideY),edk::size2f32(0.f,insideHeight),
                                                      edk::vec2f32(0.f,outsideY),edk::size2f32(0.f,outsideHeight)
                                                      );
}
bool edk::collision::MathCollision::aabbYInside(edk::vec2f32 insidePosition,edk::size2f32 insideSize,
                                                edk::vec2f32 outsidePosition,edk::size2f32 outsideSize
                                                ){
    return edk::collision::MathCollision::aabbYInside(edk::rectf32(insidePosition,insideSize),
                                                      edk::rectf32(outsidePosition,outsideSize)
                                                      );
}
bool edk::collision::MathCollision::aabbYInside(edk::rectf32 insideRect,edk::rectf32 outsideRect){
    insideRect.convertIntoPoints();
    outsideRect.convertIntoPoints();
    return edk::collision::MathCollision::aabbPointsYInside(insideRect,outsideRect);
}
//aabb Y points
bool edk::collision::MathCollision::aabbPointsY(edk::float32 y1_1,edk::float32 y1_2,
                                                edk::float32 y2_1,edk::float32 y2_2
                                                ){
    return edk::collision::MathCollision::aabbPointsY(edk::vec2f32(0.f,y1_1),edk::vec2f32(0.f,y1_2),edk::vec2f32(0.f,y2_1),edk::vec2f32(0.f,y2_2));edkEnd();
}
bool edk::collision::MathCollision::aabbPointsY(edk::vec2f32 position1_1,edk::vec2f32 position1_2,edk::vec2f32 position2_1,edk::vec2f32 position2_2){
    return edk::collision::MathCollision::aabbPointsY(edk::rectf32(position1_1.x,position1_1.y,position1_2.x,position1_2.y),
                                                      edk::rectf32(position2_1.x,position2_1.y,position2_2.x,position2_2.y)
                                                      );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsY(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect2.origin.y <= rect1.size.height
            &&
            rect2.size.height >= rect1.origin.y
            )
        return true;
    return false;
}
//aabb Y points inside
bool edk::collision::MathCollision::aabbPointsYInside(edk::float32 insideY1,edk::float32 insideY2,
                                                      edk::float32 outsideY1,edk::float32 outsideY2
                                                      ){
    return edk::collision::MathCollision::aabbPointsYInside(edk::vec2f32(0.f,insideY1),edk::vec2f32(0.f,insideY2),
                                                            edk::vec2f32(0.f,outsideY1),edk::vec2f32(0.f,outsideY2)
                                                            );
}
bool edk::collision::MathCollision::aabbPointsYInside(edk::vec2f32 insidePosition1,edk::vec2f32 insidePosition2,
                                                      edk::vec2f32 outsidePosition1,edk::vec2f32 outsidePosition2
                                                      ){
    return edk::collision::MathCollision::aabbPointsYInside(edk::rectf32(insidePosition1.x,insidePosition1.y,
                                                                         insidePosition2.x,insidePosition2.y
                                                                         ),
                                                            edk::rectf32(outsidePosition1.x,outsidePosition1.y,
                                                                         outsidePosition2.x,outsidePosition2.y
                                                                         )
                                                            );
}
bool edk::collision::MathCollision::aabbPointsYInside(edk::rectf32 insideRect,edk::rectf32 outsideRect){
    if(//insideRect.origin.x >= outsideRect.origin.x
            //&&
            insideRect.origin.y >= outsideRect.origin.y
            //&&
            //insideRect.origin.x <= outsideRect.size.width
            &&
            insideRect.origin.y <= outsideRect.size.height
            //&&
            //insideRect.size.width >= outsideRect.origin.x
            &&
            insideRect.size.height >= outsideRect.origin.y
            //&&
            //insideRect.size.width <= outsideRect.size.width
            &&
            insideRect.size.height <= outsideRect.size.height
            )
        return true;
    return false;
}
//AABB 3D
bool edk::collision::MathCollision::aabb(edk::float32 x1,edk::float32 y1,edk::float32 z1,edk::float32 width1,edk::float32 height1,edk::float32 length1,
                                         edk::float32 x2,edk::float32 y2,edk::float32 z2,edk::float32 width2,edk::float32 height2,edk::float32 length2
                                         ){
    return edk::collision::MathCollision::aabb(edk::vec3f32(x1,y1,z1),edk::size3f32(width1,height1,length1),
                                               edk::vec3f32(x2,y2,z2),edk::size3f32(width2,height2,length2)
                                               );edkEnd();
}
bool edk::collision::MathCollision::aabb(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabb(edk::cubef32(position1.x,position1.y,position1.z,size1.width,size1.height,size1.length),
                                               edk::cubef32(position2.x,position2.y,position2.z,size2.width,size2.height,size2.length)
                                               );edkEnd();
}
bool edk::collision::MathCollision::aabb(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.x <= cube1.origin.x + cube1.size.width
            &&
            cube2.origin.x + cube2.size.width >= cube1.origin.x
            &&
            cube2.origin.y <= cube1.origin.y + cube1.size.height
            &&
            cube2.origin.y + cube2.size.height >= cube1.origin.y
            &&
            cube2.origin.z <= cube1.origin.z + cube1.size.length
            &&
            cube2.origin.z + cube2.size.length >= cube1.origin.z
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbLeft(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbLeft(edk::cubef32(position1.x,position1.y,position1.z,
                                                                size1.width,size1.height,size1.length
                                                                ),
                                                   edk::cubef32(position2.x,position2.y,position2.z,
                                                                size2.width,size2.height,size2.length
                                                                )
                                                   );edkEnd();
}
bool edk::collision::MathCollision::aabbLeft(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.x <= cube2.origin.x + cube2.size.width
            ||
            cube1.origin.x + cube1.size.width <= cube2.origin.x + cube2.size.width
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbRight(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbRight(edk::cubef32(position1.x,position1.y,position1.z,
                                                                 size1.width,size1.height,size1.length
                                                                 ),
                                                    edk::cubef32(position2.x,position2.y,position2.z,
                                                                 size2.width,size2.height,size2.length
                                                                 )
                                                    );edkEnd();
}
bool edk::collision::MathCollision::aabbRight(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.x >= cube2.origin.x
            ||
            cube1.origin.x + cube1.size.width >= cube2.origin.x
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbUp(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbUp(edk::cubef32(position1.x,position1.y,position1.z,
                                                              size1.width,size1.height,size1.length
                                                              ),
                                                 edk::cubef32(position2.x,position2.y,position2.z,
                                                              size2.width,size2.height,size2.length
                                                              )
                                                 );edkEnd();
}
bool edk::collision::MathCollision::aabbUp(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.y <= cube2.origin.y + cube2.size.height
            ||
            cube1.origin.y + cube1.size.height <= cube2.origin.y + cube2.size.height
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbDown(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbDown(edk::cubef32(position1.x,position1.y,position1.z,
                                                                size1.width,size1.height,size1.length
                                                                ),
                                                   edk::cubef32(position2.x,position2.y,position2.z,
                                                                size2.width,size2.height,size2.length
                                                                )
                                                   );edkEnd();
}
bool edk::collision::MathCollision::aabbDown(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.y >= cube2.origin.y
            ||
            cube1.origin.y + cube1.size.height >= cube2.origin.y
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbFront(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbFront(edk::cubef32(position1.x,position1.y,position1.z,
                                                                 size1.width,size1.height,size1.length
                                                                 ),
                                                    edk::cubef32(position2.x,position2.y,position2.z,
                                                                 size2.width,size2.height,size2.length
                                                                 )
                                                    );edkEnd();
}
bool edk::collision::MathCollision::aabbFront(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.z <= cube2.origin.z + cube2.size.length
            ||
            cube1.origin.z + cube1.size.length <= cube2.origin.z + cube2.size.length
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbBack(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbBack(edk::cubef32(position1.x,position1.y,position1.z,
                                                                size1.width,size1.height,size1.length
                                                                ),
                                                   edk::cubef32(position2.x,position2.y,position2.z,
                                                                size2.width,size2.height,size2.length
                                                                )
                                                   );edkEnd();
}
bool edk::collision::MathCollision::aabbBack(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.z >= cube2.origin.z
            ||
            cube1.origin.z + cube1.size.length >= cube2.origin.z
            )
        return true;
    return false;
}
//AABB 3D INSIDE
bool edk::collision::MathCollision::aabbInside(edk::float32 insideX,edk::float32 insideY,edk::float32 insideZ,
                                               edk::float32 insideWidth,edk::float32 insideHeight,edk::float32 insideLength,
                                               edk::float32 outsideX,edk::float32 outsideY,edk::float32 outsideZ,
                                               edk::float32 outsideWidth,edk::float32 outsideHeight,edk::float32 outsideLength
                                               ){
    return edk::collision::MathCollision::aabbInside(edk::vec3f32(insideX,insideY,insideZ),
                                                     edk::size3f32(insideWidth,insideHeight,insideLength),
                                                     edk::vec3f32(outsideX,outsideY,outsideZ),
                                                     edk::size3f32(outsideWidth,outsideHeight,outsideLength)
                                                     );
}
bool edk::collision::MathCollision::aabbInside(edk::vec3f32 insidePosition1,edk::size3f32 insideSize1,
                                               edk::vec3f32 outsidePosition2,edk::size3f32 outsideSize2
                                               ){
    return edk::collision::MathCollision::aabbInside(edk::cubef32(insidePosition1,insideSize1),
                                                     edk::cubef32(outsidePosition2,outsideSize2)
                                                     );
}
bool edk::collision::MathCollision::aabbInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    insideCube.convertIntoPoints();
    outsideCube.convertIntoPoints();
    return edk::collision::MathCollision::aabbPointsInside(insideCube,outsideCube);
}
//AABB 3D POINTS
bool edk::collision::MathCollision::aabbPoints(edk::float32 x1_1,edk::float32 y1_1,edk::float32 z1_1,edk::float32 x1_2,edk::float32 y1_2,edk::float32 z1_2,
                                               edk::float32 x2_1,edk::float32 y2_1,edk::float32 z2_1,edk::float32 x2_2,edk::float32 y2_2,edk::float32 z2_2
                                               ){
    return edk::collision::MathCollision::aabbPoints(edk::vec3f32(x1_1,y1_1,z1_1),edk::vec3f32(x1_2,y1_2,z1_2),
                                                     edk::vec3f32(x2_1,y2_1,z2_1),edk::vec3f32(x2_2,y2_2,z2_2)
                                                     );edkEnd();
}
bool edk::collision::MathCollision::aabbPoints(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2){
    return edk::collision::MathCollision::aabbPoints(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,
                                                                  position1_2.x,position1_2.y,position1_2.z
                                                                  ),
                                                     edk::cubef32(position2_1.x,position2_1.y,position2_1.z,
                                                                  position2_2.x,position2_2.y,position2_2.z
                                                                  )
                                                     );edkEnd();
}
bool edk::collision::MathCollision::aabbPoints(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.x <= cube1.size.width
            &&
            cube2.size.width >= cube1.origin.x
            &&
            cube2.origin.y <= cube1.size.height
            &&
            cube2.size.height >= cube1.origin.y
            &&
            cube2.origin.z <= cube1.size.length
            &&
            cube2.size.length >= cube1.origin.z
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbPointsLeft(edk::vec3f32 position1_1,edk::vec3f32 position1_2,
                                                   edk::vec3f32 position2_1,edk::vec3f32 position2_2
                                                   ){
    return edk::collision::MathCollision::aabbPointsLeft(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,
                                                                      position1_2.x,position1_2.y,position1_2.z
                                                                      ),
                                                         edk::cubef32(position2_1.x,position2_1.y,position2_1.z,
                                                                      position2_2.x,position2_2.y,position2_2.z
                                                                      )
                                                         );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsLeft(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.x <= cube2.size.width
            ||
            cube1.size.width <= cube2.size.width
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbPointsRight(edk::vec3f32 position1_1,edk::vec3f32 position1_2,
                                                    edk::vec3f32 position2_1,edk::vec3f32 position2_2
                                                    ){
    return edk::collision::MathCollision::aabbPointsRight(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,
                                                                       position1_2.x,position1_2.y,position1_2.z
                                                                       ),
                                                          edk::cubef32(position2_1.x,position2_1.y,position2_1.z,
                                                                       position2_2.x,position2_2.y,position2_2.z
                                                                       )
                                                          );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsRight(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.x >= cube2.origin.x
            ||
            cube1.size.width >= cube2.origin.x
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbPointsUp(edk::vec3f32 position1_1,edk::vec3f32 position1_2,
                                                 edk::vec3f32 position2_1,edk::vec3f32 position2_2
                                                 ){
    return edk::collision::MathCollision::aabbPointsUp(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,
                                                                    position1_2.x,position1_2.y,position1_2.z
                                                                    ),
                                                       edk::cubef32(position2_1.x,position2_1.y,position2_1.z,
                                                                    position2_2.x,position2_2.y,position2_2.z
                                                                    )
                                                       );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsUp(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.y <= cube2.size.height
            ||
            cube1.size.height <= cube2.size.height
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbPointsDown(edk::vec3f32 position1_1,edk::vec3f32 position1_2,
                                                   edk::vec3f32 position2_1,edk::vec3f32 position2_2
                                                   ){
    return edk::collision::MathCollision::aabbPointsDown(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,
                                                                      position1_2.x,position1_2.y,position1_2.z
                                                                      ),
                                                         edk::cubef32(position2_1.x,position2_1.y,position2_1.z,
                                                                      position2_2.x,position2_2.y,position2_2.z
                                                                      )
                                                         );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsDown(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.y >= cube2.origin.y
            ||
            cube1.size.height >= cube2.origin.y
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbPointsFront(edk::vec3f32 position1_1,edk::vec3f32 position1_2,
                                                    edk::vec3f32 position2_1,edk::vec3f32 position2_2
                                                    ){
    return edk::collision::MathCollision::aabbPointsFront(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,
                                                                       position1_2.x,position1_2.y,position1_2.z
                                                                       ),
                                                          edk::cubef32(position2_1.x,position2_1.y,position2_1.z,
                                                                       position2_2.x,position2_2.y,position2_2.z
                                                                       )
                                                          );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsFront(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.z <= cube2.size.length
            ||
            cube1.size.length <= cube2.size.length
            )
        return true;
    return false;
}
bool edk::collision::MathCollision::aabbPointsBack(edk::vec3f32 position1_1,edk::vec3f32 position1_2,
                                                   edk::vec3f32 position2_1,edk::vec3f32 position2_2
                                                   ){
    return edk::collision::MathCollision::aabbPointsBack(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,
                                                                      position1_2.x,position1_2.y,position1_2.z
                                                                      ),
                                                         edk::cubef32(position2_1.x,position2_1.y,position2_1.z,
                                                                      position2_2.x,position2_2.y,position2_2.z
                                                                      )
                                                         );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsBack(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.z >= cube2.origin.z
            ||
            cube1.size.length >= cube2.origin.z
            )
        return true;
    return false;
}
//AABB 3D POINTS
bool edk::collision::MathCollision::aabbPointsInside(edk::float32 insideX1,edk::float32 insideY1,edk::float32 insideZ1,
                                                     edk::float32 insideX2,edk::float32 insideY2,edk::float32 insideZ2,
                                                     edk::float32 outsideX1,edk::float32 outsideY1,edk::float32 outsideZ1,
                                                     edk::float32 outsideX2,edk::float32 outsideY2,edk::float32 outsideZ2
                                                     ){
    return edk::collision::MathCollision::aabbPointsInside(edk::vec3f32(insideX1,insideY1,insideZ1),
                                                           edk::vec3f32(insideX2,insideY2,insideZ2),
                                                           edk::vec3f32(outsideX1,outsideY1,outsideZ1),
                                                           edk::vec3f32(outsideX2,outsideY2,outsideZ2)
                                                           );
}
bool edk::collision::MathCollision::aabbPointsInside(edk::vec3f32 insidePosition1,edk::vec3f32 insidePosition2,
                                                     edk::vec3f32 outsidePosition1,edk::vec3f32 outsidePosition2
                                                     ){
    return edk::collision::MathCollision::aabbPointsInside(edk::cubef32(insidePosition1.x,insidePosition1.y,insidePosition1.z,
                                                                        insidePosition2.x,insidePosition2.y,insidePosition2.z
                                                                        ),
                                                           edk::cubef32(outsidePosition1.y,outsidePosition1.y,outsidePosition1.z,
                                                                        outsidePosition2.y,outsidePosition2.y,outsidePosition2.z
                                                                        )
                                                           );
}
bool edk::collision::MathCollision::aabbPointsInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    if(insideCube.origin.x >= outsideCube.origin.x
            &&
            insideCube.origin.y >= outsideCube.origin.y
            &&
            insideCube.origin.z >= outsideCube.origin.z
            &&
            insideCube.origin.x <= outsideCube.size.width
            &&
            insideCube.origin.y <= outsideCube.size.height
            &&
            insideCube.origin.z <= outsideCube.size.length
            &&
            insideCube.size.width >= outsideCube.origin.x
            &&
            insideCube.size.height >= outsideCube.origin.y
            &&
            insideCube.size.length >= outsideCube.origin.z
            &&
            insideCube.size.width <= outsideCube.size.width
            &&
            insideCube.size.height <= outsideCube.size.height
            &&
            insideCube.size.length <= outsideCube.size.length
            )
        return true;
    return false;
}
//X
bool edk::collision::MathCollision::aabbX(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbX(edk::cubef32(position1.x,position1.y,position1.z,size1.width,size1.height,size1.length),
                                                edk::cubef32(position2.x,position2.y,position2.z,size2.width,size2.height,size2.length)
                                                );edkEnd();
}
bool edk::collision::MathCollision::aabbX(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.x <= cube1.origin.x + cube1.size.width
            &&
            cube2.origin.x + cube2.size.width >= cube1.origin.x
            )
        return true;
    return false;
}
//X inside
bool edk::collision::MathCollision::aabbXInside(edk::vec3f32 insidePosition,edk::size3f32 insideSize,
                                                edk::vec3f32 outsidePosition,edk::size3f32 outsideSize
                                                ){
    return edk::collision::MathCollision::aabbXInside(edk::cubef32(insidePosition,insideSize),
                                                      edk::cubef32(outsidePosition,outsideSize)
                                                      );
}
bool edk::collision::MathCollision::aabbXInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    insideCube.convertIntoPoints();
    outsideCube.convertIntoPoints();
    return edk::collision::MathCollision::aabbPointsXInside(insideCube,outsideCube);
}
//AABB 3D X POINTS
bool edk::collision::MathCollision::aabbPointsX(edk::vec3f32 position1_1,edk::vec3f32 position1_2,
                                                edk::vec3f32 position2_1,edk::vec3f32 position2_2
                                                ){
    return edk::collision::MathCollision::aabbX(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,position1_2.x,position1_2.y,position1_2.z),
                                                edk::cubef32(position2_1.x,position2_1.y,position2_1.z,position2_2.x,position2_2.y,position2_2.z)
                                                );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsX(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.x <= cube1.size.width
            &&
            cube2.size.width >= cube1.origin.x
            )
        return true;
    return false;
}
//AABB 3D X POINTS INSIDE
bool edk::collision::MathCollision::aabbPointsXInside(edk::vec3f32 insidePosition1,edk::vec3f32 insidePosition2,
                                                      edk::vec3f32 outsidePosition1,edk::vec3f32 outsidePosition2
                                                      ){
    return edk::collision::MathCollision::aabbPointsXInside(edk::cubef32(insidePosition1.x,insidePosition1.y,insidePosition1.z,
                                                                         insidePosition2.x,insidePosition2.y,insidePosition2.z
                                                                         ),
                                                            edk::cubef32(outsidePosition1.x,outsidePosition1.y,outsidePosition1.z,
                                                                         outsidePosition2.x,outsidePosition2.y,outsidePosition2.z
                                                                         )
                                                            );
}
bool edk::collision::MathCollision::aabbPointsXInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    if(insideCube.origin.x >= outsideCube.origin.x
            //&&
            //insideCube.origin.y >= outsideCube.origin.y
            //&&
            //insideCube.origin.z >= outsideCube.origin.z
            &&
            insideCube.origin.x <= outsideCube.size.width
            //&&
            //insideCube.origin.y <= outsideCube.size.height
            //&&
            //insideCube.origin.z <= outsideCube.size.length
            &&
            insideCube.size.width >= outsideCube.origin.x
            //&&
            //insideCube.size.height >= outsideCube.origin.y
            //&&
            //insideCube.size.length >= outsideCube.origin.z
            &&
            insideCube.size.width <= outsideCube.size.width
            //&&
            //insideCube.size.height <= outsideCube.size.height
            //&&
            //insideCube.size.length <= outsideCube.size.length
            )
        return true;
    return false;
}
//Y
bool edk::collision::MathCollision::aabbY(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbY(edk::cubef32(position1.x,position1.y,position1.z,size1.width,size1.height,size1.length),
                                                edk::cubef32(position2.x,position2.y,position2.z,size2.width,size2.height,size2.length)
                                                );edkEnd();
}
bool edk::collision::MathCollision::aabbY(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.y <= cube1.origin.y + cube1.size.height
            &&
            cube2.origin.y + cube2.size.height >= cube1.origin.y
            )
        return true;
    return false;
}
//Y INSIDE
bool edk::collision::MathCollision::aabbYInside(edk::vec3f32 insidePosition,edk::size3f32 insideSize,
                                                edk::vec3f32 outsidePosition,edk::size3f32 outsideSize
                                                ){
    return edk::collision::MathCollision::aabbYInside(edk::cubef32(insidePosition,insideSize),
                                                      edk::cubef32(outsidePosition,outsideSize)
                                                      );
}
bool edk::collision::MathCollision::aabbYInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    insideCube.convertIntoPoints();
    outsideCube.convertIntoPoints();
    return edk::collision::MathCollision::aabbPointsYInside(insideCube,outsideCube);
}
//AABB 3D Y POINTS
bool edk::collision::MathCollision::aabbPointsY(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2){
    return edk::collision::MathCollision::aabb(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,position1_2.x,position1_2.y,position1_2.z),
                                               edk::cubef32(position2_1.x,position2_1.y,position2_1.z,position2_2.x,position2_2.y,position2_2.z)
                                               );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsY(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.x <= cube1.size.width
            &&
            cube2.size.width >= cube1.origin.x
            &&
            cube2.origin.y <= cube1.size.height
            &&
            cube2.size.height >= cube1.origin.y
            &&
            cube2.origin.z <= cube1.size.length
            &&
            cube2.size.length >= cube1.origin.z
            )
        return true;
    return false;
}
//AABB 3D Y POINTS INSIDE
bool edk::collision::MathCollision::aabbPointsYInside(edk::vec3f32 insidePosition1,edk::vec3f32 insidePosition2,
                                                      edk::vec3f32 outsidePosition1,edk::vec3f32 outsidePosition2
                                                      ){
    return edk::collision::MathCollision::aabbPointsYInside(edk::cubef32(insidePosition1.x,insidePosition1.y,insidePosition1.z,
                                                                         insidePosition2.x,insidePosition2.y,insidePosition2.z
                                                                         ),
                                                            edk::cubef32(outsidePosition1.x,outsidePosition1.y,outsidePosition1.z,
                                                                         outsidePosition2.x,outsidePosition2.y,outsidePosition2.z
                                                                         )
                                                            );
}
bool edk::collision::MathCollision::aabbPointsYInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){

    if(//insideCube.origin.x >= outsideCube.origin.x
            //&&
            insideCube.origin.y >= outsideCube.origin.y
            //&&
            //insideCube.origin.z >= outsideCube.origin.z
            //&&
            //insideCube.origin.x <= outsideCube.size.width
            &&
            insideCube.origin.y <= outsideCube.size.height
            //&&
            //insideCube.origin.z <= outsideCube.size.length
            //&&
            //insideCube.size.width >= outsideCube.origin.x
            &&
            insideCube.size.height >= outsideCube.origin.y
            //&&
            //insideCube.size.length >= outsideCube.origin.z
            //&&
            //insideCube.size.width <= outsideCube.size.width
            &&
            insideCube.size.height <= outsideCube.size.height
            //&&
            //insideCube.size.length <= outsideCube.size.length
            )
        return true;
    return false;
}
//Z
bool edk::collision::MathCollision::aabbZ(edk::float32 z1,edk::float32 length1,
                                          edk::float32 z2,edk::float32 length2
                                          ){
    return edk::collision::MathCollision::aabbZ(edk::vec3f32(0.f,0.f,z1),edk::size3f32(0.f,0.f,length1),
                                                edk::vec3f32(0.f,0.f,z2),edk::size3f32(0.f,0.f,length2)
                                                );edkEnd();
}
bool edk::collision::MathCollision::aabbZ(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbZ(edk::cubef32(position1.x,position1.y,position1.z,size1.width,size1.height,size1.length),
                                                edk::cubef32(position2.x,position2.y,position2.z,size2.width,size2.height,size2.length)
                                                );edkEnd();
}
bool edk::collision::MathCollision::aabbZ(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.z <= cube1.origin.z + cube1.size.length
            &&
            cube2.origin.z + cube2.size.length >= cube1.origin.z
            )
        return true;
    return false;
}
//Z INSIDE
bool edk::collision::MathCollision::aabbZInside(edk::float32 insideZ,edk::float32 insideLength,
                                                edk::float32 outsideZ,edk::float32 outsideLength
                                                ){
    return edk::collision::MathCollision::aabbZInside(edk::vec3f32(0.f,0.f,insideZ),edk::size3f32(0.f,0.f,insideLength),
                                                      edk::vec3f32(0.f,0.f,outsideZ),edk::size3f32(0.f,0.f,outsideLength)
                                                      );
}
bool edk::collision::MathCollision::aabbZInside(edk::vec3f32 insidePosition,edk::size3f32 insideSize,
                                                edk::vec3f32 outsidePosition,edk::size3f32 outsideSize
                                                ){
    return edk::collision::MathCollision::aabbZInside(edk::cubef32(insidePosition,insideSize),
                                                      edk::cubef32(outsidePosition,outsideSize)
                                                      );
}
bool edk::collision::MathCollision::aabbZInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    insideCube.convertIntoPoints();
    outsideCube.convertIntoPoints();
    return edk::collision::MathCollision::aabbPointsZInside(insideCube,outsideCube);
}
//AABB 3D Z POINTS
bool edk::collision::MathCollision::aabbPointsZ(edk::float32 z1_1,edk::float32 z1_2,
                                                edk::float32 z2_1,edk::float32 z2_2
                                                ){
    return edk::collision::MathCollision::aabbPointsZ(edk::vec3f32(0.f,0.f,z1_1),edk::vec3f32(0.f,0.f,z1_2),
                                                      edk::vec3f32(0.f,0.f,z2_1),edk::vec3f32(0.f,0.f,z2_2)
                                                      );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsZ(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2){
    return edk::collision::MathCollision::aabbZ(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,position1_2.x,position1_2.y,position1_2.z),
                                                edk::cubef32(position2_1.x,position2_1.y,position2_1.z,position2_2.x,position2_2.y,position2_2.z)
                                                );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsZ(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.z <= cube1.size.length
            &&
            cube2.size.length >= cube1.origin.z
            )
        return true;
    return false;
}
//AABB 3D Z POINTS INSIDE
bool edk::collision::MathCollision::aabbPointsZInside(edk::float32 insideZ1,edk::float32 insideZ2,
                                                      edk::float32 outsideZ1,edk::float32 outsideZ2
                                                      ){
    return edk::collision::MathCollision::aabbPointsZInside(edk::vec3f32(0.f,0.f,insideZ1),edk::vec3f32(0.f,0.f,insideZ2),
                                                            edk::vec3f32(0.f,0.f,outsideZ1),edk::vec3f32(0.f,0.f,outsideZ2)
                                                            );
}
bool edk::collision::MathCollision::aabbPointsZInside(edk::vec3f32 insidePosition1,edk::vec3f32 insidePosition2,
                                                      edk::vec3f32 outsidePosition1,edk::vec3f32 outsidePosition2
                                                      ){
    return edk::collision::MathCollision::aabbPointsZInside(edk::cubef32(insidePosition1.x,insidePosition1.y,insidePosition1.z,
                                                                         insidePosition2.x,insidePosition2.y,insidePosition2.z
                                                                         ),
                                                            edk::cubef32(outsidePosition1.x,outsidePosition1.y,outsidePosition1.z,
                                                                         outsidePosition2.x,outsidePosition2.y,outsidePosition2.z
                                                                         )
                                                            );
}
bool edk::collision::MathCollision::aabbPointsZInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    if(//insideCube.origin.x >= outsideCube.origin.x
            //&&
            //insideCube.origin.y >= outsideCube.origin.y
            //&&
            insideCube.origin.z >= outsideCube.origin.z
            //&&
            //insideCube.origin.x <= outsideCube.size.width
            //&&
            //insideCube.origin.y <= outsideCube.size.height
            &&
            insideCube.origin.z <= outsideCube.size.length
            //&&
            //insideCube.size.width >= outsideCube.origin.x
            //&&
            //insideCube.size.height >= outsideCube.origin.y
            &&
            insideCube.size.length >= outsideCube.origin.z
            //&&
            //insideCube.size.width <= outsideCube.size.width
            //&&
            //insideCube.size.height <= outsideCube.size.height
            &&
            insideCube.size.length <= outsideCube.size.length
            )
        return true;
    return false;
}
//AABB XY
bool edk::collision::MathCollision::aabbXY(edk::float32 x1,edk::float32 y1,edk::float32 width1,edk::float32 height1,
                                           edk::float32 x2,edk::float32 y2,edk::float32 width2,edk::float32 height2
                                           ){
    return edk::collision::MathCollision::aabbXY(edk::vec3f32(x1,y1,0.f),edk::size3f32(width1,height1,0.f),
                                                 edk::vec3f32(x2,y2,0.f),edk::size3f32(width2,height2,0.f)
                                                 );edkEnd();
}
bool edk::collision::MathCollision::aabbXY(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbXY(edk::cubef32(position1.x,position1.y,position1.z,size1.width,size1.height,size1.length),
                                                 edk::cubef32(position2.x,position2.y,position2.z,size2.width,size2.height,size2.length)
                                                 );edkEnd();
}
bool edk::collision::MathCollision::aabbXY(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.x <= cube1.origin.x + cube1.size.width
            &&
            cube2.origin.x + cube2.size.width >= cube1.origin.x
            &&
            cube2.origin.y <= cube1.origin.y + cube1.size.height
            &&
            cube2.origin.y + cube2.size.height >= cube1.origin.y
            )
        return true;
    return false;
}
//AABB XY INSIDE
bool edk::collision::MathCollision::aabbXYInside(edk::float32 insideX,edk::float32 insideY,
                                                 edk::float32 insideWidth,edk::float32 insideHeight,
                                                 edk::float32 outsideX,edk::float32 outsideY,
                                                 edk::float32 outsideWidth,edk::float32 outsideHeight
                                                 ){
    return edk::collision::MathCollision::aabbXYInside(edk::vec3f32(insideX,insideY,0.f),
                                                       edk::size3f32(insideWidth,insideHeight,0.f),
                                                       edk::vec3f32(outsideX,outsideY,0.f),
                                                       edk::size3f32(outsideWidth,outsideHeight,0.f)
                                                       );
}
bool edk::collision::MathCollision::aabbXYInside(edk::vec3f32 insidePosition,edk::size3f32 insideSize,
                                                 edk::vec3f32 outsidePosition,edk::size3f32 outsideSize
                                                 ){
    return edk::collision::MathCollision::aabbXYInside(edk::cubef32(insidePosition,insideSize),
                                                       edk::cubef32(outsidePosition,outsideSize)
                                                       );
}
bool edk::collision::MathCollision::aabbXYInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    insideCube.convertIntoPoints();
    outsideCube.convertIntoPoints();
    return edk::collision::MathCollision::aabbPointsXYInside(insideCube,outsideCube);
}
//AABB XY POINTS
bool edk::collision::MathCollision::aabbPointsXY(edk::float32 x1_1,edk::float32 y1_1,edk::float32 x1_2,edk::float32 y1_2,
                                                 edk::float32 x2_1,edk::float32 y2_1,edk::float32 x2_2,edk::float32 y2_2
                                                 ){
    return edk::collision::MathCollision::aabbPointsXY(edk::vec3f32(x1_1,y1_1,0.f),edk::vec3f32(x1_2,y1_2,0.f),
                                                       edk::vec3f32(x2_1,y2_1,0.f),edk::vec3f32(x2_2,y2_2,0.f)
                                                       );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsXY(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2){
    return edk::collision::MathCollision::aabbPointsXY(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,position1_2.x,position1_2.y,position1_2.z),
                                                       edk::cubef32(position2_1.x,position2_1.y,position2_1.z,position2_2.x,position2_2.y,position2_2.z)
                                                       );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsXY(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.x <= cube1.size.width
            &&
            cube2.size.width >= cube1.origin.x
            &&
            cube2.origin.y <= cube1.size.height
            &&
            cube2.size.height >= cube1.origin.y
            )
        return true;
    return false;
}
//AABB XY POINTS INSIDE
bool edk::collision::MathCollision::aabbPointsXYInside(edk::float32 insideX1,edk::float32 insideY1,
                                                       edk::float32 insideX2,edk::float32 insideY2,
                                                       edk::float32 outsideX1,edk::float32 outsideY1,
                                                       edk::float32 outsideX2,edk::float32 outsideY2
                                                       ){
    return edk::collision::MathCollision::aabbPointsXYInside(edk::vec3f32(insideX1,insideY1,0.f),
                                                             edk::vec3f32(insideX2,insideY2,0.f),
                                                             edk::vec3f32(outsideX1,outsideY1,0.f),
                                                             edk::vec3f32(outsideX2,outsideY2,0.f)
                                                             );
}
bool edk::collision::MathCollision::aabbPointsXYInside(edk::vec3f32 insidePosition1,edk::vec3f32 insidePosition2,
                                                       edk::vec3f32 outsidePosition1,edk::vec3f32 outsidePosition2
                                                       ){
    return edk::collision::MathCollision::aabbPointsXYInside(edk::cubef32(insidePosition1.x,insidePosition1.y,insidePosition1.z,
                                                                          insidePosition2.x,insidePosition2.y,insidePosition2.z
                                                                          ),
                                                             edk::cubef32(outsidePosition1.x,outsidePosition1.y,outsidePosition1.z,
                                                                          outsidePosition2.x,outsidePosition2.y,outsidePosition2.z
                                                                          )
                                                             );
}
bool edk::collision::MathCollision::aabbPointsXYInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    if(insideCube.origin.x >= outsideCube.origin.x
            &&
            insideCube.origin.y >= outsideCube.origin.y
            //&&
            //insideCube.origin.z >= outsideCube.origin.z
            &&
            insideCube.origin.x <= outsideCube.size.width
            &&
            insideCube.origin.y <= outsideCube.size.height
            //&&
            //insideCube.origin.z <= outsideCube.size.length
            &&
            insideCube.size.width >= outsideCube.origin.x
            &&
            insideCube.size.height >= outsideCube.origin.y
            //&&
            //insideCube.size.length >= outsideCube.origin.z
            &&
            insideCube.size.width <= outsideCube.size.width
            &&
            insideCube.size.height <= outsideCube.size.height
            //&&
            //insideCube.size.length <= outsideCube.size.length
            )
        return true;
    return false;
}
//AABB XZ
bool edk::collision::MathCollision::aabbXZ(edk::float32 x1,edk::float32 z1,edk::float32 width1,edk::float32 length1,
                                           edk::float32 x2,edk::float32 z2,edk::float32 width2,edk::float32 length2
                                           ){
    return edk::collision::MathCollision::aabbXZ(edk::vec3f32(x1,0.f,z1),edk::size3f32(width1,0.f,length1),
                                                 edk::vec3f32(x2,0.f,z2),edk::size3f32(width2,0.f,length2)
                                                 );edkEnd();
}
bool edk::collision::MathCollision::aabbXZ(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbXZ(edk::cubef32(position1.x,position1.y,position1.z,size1.width,size1.height,size1.length),
                                                 edk::cubef32(position2.x,position2.y,position2.z,size2.width,size2.height,size2.length)
                                                 );edkEnd();
}
bool edk::collision::MathCollision::aabbXZ(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.x <= cube1.origin.x + cube1.size.width
            &&
            cube2.origin.x + cube2.size.width >= cube1.origin.x
            &&
            cube2.origin.z <= cube1.origin.z + cube1.size.length
            &&
            cube2.origin.z + cube2.size.length >= cube1.origin.z
            )
        return true;
    return false;
}
//AABB XZ INSIDE
bool edk::collision::MathCollision::aabbXZInside(edk::float32 insideX,edk::float32 insideZ,
                                                 edk::float32 insideWidth,edk::float32 insideLength,
                                                 edk::float32 outsideX,edk::float32 outsideZ,
                                                 edk::float32 outsideWidth,edk::float32 outsideLength
                                                 ){
    return edk::collision::MathCollision::aabbXZInside(edk::vec3f32(insideX,0.f,insideZ),
                                                       edk::size3f32(insideWidth,0.f,insideLength),
                                                       edk::vec3f32(outsideX,0.f,outsideZ),
                                                       edk::size3f32(outsideWidth,0.f,outsideLength)
                                                       );
}
bool edk::collision::MathCollision::aabbXZInside(edk::vec3f32 insidePosition,edk::size3f32 insideSize,
                                                 edk::vec3f32 outsidePosition,edk::size3f32 outsideSize
                                                 ){
    return edk::collision::MathCollision::aabbXZInside(edk::cubef32(insidePosition,insideSize),
                                                       edk::cubef32(outsidePosition,outsideSize)
                                                       );
}
bool edk::collision::MathCollision::aabbXZInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    insideCube.convertIntoPoints();
    outsideCube.convertIntoPoints();
    return edk::collision::MathCollision::aabbPointsXZInside(insideCube,outsideCube);
}
//AABB XZ POINTS
bool edk::collision::MathCollision::aabbPointsXZ(edk::float32 x1_1,edk::float32 z1_1,edk::float32 x1_2,edk::float32 z1_2,
                                                 edk::float32 x2_1,edk::float32 z2_1,edk::float32 x2_2,edk::float32 z2_2
                                                 ){
    return edk::collision::MathCollision::aabbPointsXZ(edk::vec3f32(x1_1,0.f,z1_1),edk::vec3f32(x1_2,0.f,z1_2),
                                                       edk::vec3f32(x2_1,0.f,z2_1),edk::vec3f32(x2_2,0.f,z2_2)
                                                       );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsXZ(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2){
    return edk::collision::MathCollision::aabbXZ(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,position1_2.x,position1_2.y,position1_2.z),
                                                 edk::cubef32(position2_1.x,position2_1.y,position2_1.z,position2_2.x,position2_2.y,position2_2.z)
                                                 );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsXZ(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.x <= cube1.size.width
            &&
            cube2.size.width >= cube1.origin.x
            &&
            cube2.origin.z <= cube1.size.length
            &&
            cube2.size.length >= cube1.origin.z
            )
        return true;
    return false;
}
//AABB XZ POINTS INSIDE
bool edk::collision::MathCollision::aabbPointsXZInside(edk::float32 insideX1,edk::float32 insideZ1,
                                                       edk::float32 insideX2,edk::float32 insideZ2,
                                                       edk::float32 outsideX1,edk::float32 outsideZ1,
                                                       edk::float32 outsideX2,edk::float32 outsideZ2
                                                       ){
    return edk::collision::MathCollision::aabbPointsXZInside(edk::vec3f32(insideX1,0.f,insideZ1),
                                                             edk::vec3f32(insideX2,0.f,insideZ2),
                                                             edk::vec3f32(outsideX1,0.f,outsideZ1),
                                                             edk::vec3f32(outsideX2,0.f,outsideZ2)
                                                             );
}
bool edk::collision::MathCollision::aabbPointsXZInside(edk::vec3f32 insidePosition1,edk::vec3f32 insidePosition2,
                                                       edk::vec3f32 outsidePosition1,edk::vec3f32 outsidePosition2
                                                       ){
    return edk::collision::MathCollision::aabbPointsXZInside(edk::cubef32(insidePosition1.x,insidePosition1.y,insidePosition1.z,
                                                                          insidePosition2.x,insidePosition2.y,insidePosition2.z
                                                                          ),
                                                             edk::cubef32(outsidePosition1.x,outsidePosition1.y,outsidePosition1.z,
                                                                          outsidePosition2.x,outsidePosition2.y,outsidePosition2.z
                                                                          )
                                                             );
}
bool edk::collision::MathCollision::aabbPointsXZInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    if(insideCube.origin.x >= outsideCube.origin.x
            //&&
            //insideCube.origin.y >= outsideCube.origin.y
            &&
            insideCube.origin.z >= outsideCube.origin.z
            &&
            insideCube.origin.x <= outsideCube.size.width
            //&&
            //insideCube.origin.y <= outsideCube.size.height
            &&
            insideCube.origin.z <= outsideCube.size.length
            &&
            insideCube.size.width >= outsideCube.origin.x
            //&&
            //insideCube.size.height >= outsideCube.origin.y
            &&
            insideCube.size.length >= outsideCube.origin.z
            &&
            insideCube.size.width <= outsideCube.size.width
            //&&
            //insideCube.size.height <= outsideCube.size.height
            &&
            insideCube.size.length <= outsideCube.size.length
            )
        return true;
    return false;
}
//AABB YZ
bool edk::collision::MathCollision::aabbYZ(edk::float32 y1,edk::float32 z1,edk::float32 height1,edk::float32 length1,
                                           edk::float32 y2,edk::float32 z2,edk::float32 height2,edk::float32 length2
                                           ){
    return edk::collision::MathCollision::aabbYZ(edk::vec3f32(0.f,y1,z1),edk::size3f32(0.f,height1,length1),
                                                 edk::vec3f32(0.f,y2,z2),edk::size3f32(0.f,height2,length2)
                                                 );edkEnd();
}
bool edk::collision::MathCollision::aabbYZ(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabbYZ(edk::cubef32(position1.x,position1.y,position1.z,size1.width,size1.height,size1.length),
                                                 edk::cubef32(position2.x,position2.y,position2.z,size2.width,size2.height,size2.length)
                                                 );edkEnd();
}
bool edk::collision::MathCollision::aabbYZ(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.y <= cube1.origin.y + cube1.size.height
            &&
            cube2.origin.y + cube2.size.height >= cube1.origin.y
            &&
            cube2.origin.z <= cube1.origin.z + cube1.size.length
            &&
            cube2.origin.z + cube2.size.length >= cube1.origin.z
            )
        return true;
    return false;
}
//AABB YZ INSIDE
bool edk::collision::MathCollision::aabbYZInside(edk::float32 insideY,edk::float32 insideZ,
                                                 edk::float32 insideHeight,edk::float32 insideLength,
                                                 edk::float32 outsideY,edk::float32 outsideZ,
                                                 edk::float32 outsideHeight,edk::float32 outsideLength
                                                 ){
    return edk::collision::MathCollision::aabbYZInside(edk::vec3f32(0.f,insideY,insideZ),
                                                       edk::size3f32(0.f,insideHeight,insideLength),
                                                       edk::vec3f32(0.f,outsideY,outsideZ),
                                                       edk::size3f32(0.f,outsideHeight,outsideLength)
                                                       );
}
bool edk::collision::MathCollision::aabbYZInside(edk::vec3f32 insidePosition,edk::size3f32 insideSize,
                                                 edk::vec3f32 outsidePosition,edk::size3f32 outsideSize
                                                 ){
    return edk::collision::MathCollision::aabbYZInside(edk::cubef32(insidePosition,insideSize),
                                                       edk::cubef32(outsidePosition,outsideSize)
                                                       );
}
bool edk::collision::MathCollision::aabbYZInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    insideCube.convertIntoPoints();
    outsideCube.convertIntoPoints();
    return edk::collision::MathCollision::aabbPointsYZInside(insideCube,outsideCube);
}
//AABB YZ POINTS
bool edk::collision::MathCollision::aabbPointsYZ(edk::float32 y1_1,edk::float32 z1_1,edk::float32 y1_2,edk::float32 z1_2,
                                                 edk::float32 y2_1,edk::float32 z2_1,edk::float32 y2_2,edk::float32 z2_2
                                                 ){
    return edk::collision::MathCollision::aabbPointsYZ(edk::vec3f32(0.f,y1_1,z1_1),edk::vec3f32(0.f,y1_2,z1_2),
                                                       edk::vec3f32(0.f,y2_1,z2_1),edk::vec3f32(0.f,y2_2,z2_2)
                                                       );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsYZ(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2){
    return edk::collision::MathCollision::aabbPointsYZ(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,position1_2.x,position1_2.y,position1_2.z),
                                                       edk::cubef32(position2_1.x,position2_1.y,position2_1.z,position2_2.x,position2_2.y,position2_2.z)
                                                       );edkEnd();
}
bool edk::collision::MathCollision::aabbPointsYZ(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube2.origin.y <= cube1.size.height
            &&
            cube2.size.height >= cube1.origin.y
            &&
            cube2.origin.z <= cube1.size.length
            &&
            cube2.size.length >= cube1.origin.z
            )
        return true;
    return false;
}
//AABB YZ POINTS INSIDE
bool edk::collision::MathCollision::aabbPointsYZInside(edk::float32 insideY1,edk::float32 insideZ1,
                                                       edk::float32 insideY2,edk::float32 insideZ2,
                                                       edk::float32 outsideY1,edk::float32 outsideZ1,
                                                       edk::float32 outsideY2,edk::float32 outsideZ2
                                                       ){
    return edk::collision::MathCollision::aabbPointsYZInside(edk::vec3f32(0.f,insideY1,insideZ1),
                                                             edk::vec3f32(0.f,insideY2,insideZ2),
                                                             edk::vec3f32(0.f,outsideY1,outsideZ1),
                                                             edk::vec3f32(0.f,outsideY2,outsideZ2)
                                                             );
}
bool edk::collision::MathCollision::aabbPointsYZInside(edk::vec3f32 insidePosition1,edk::vec3f32 insidePosition2,
                                                       edk::vec3f32 outsidePosition1,edk::vec3f32 outsidePosition2
                                                       ){
    return edk::collision::MathCollision::aabbPointsYZInside(edk::cubef32(insidePosition1.x,insidePosition1.y,insidePosition1.z,
                                                                          insidePosition2.x,insidePosition2.y,insidePosition2.z
                                                                          ),
                                                             edk::cubef32(outsidePosition1.x,outsidePosition1.y,outsidePosition1.z,
                                                                          outsidePosition2.x,outsidePosition2.y,outsidePosition2.z
                                                                          )
                                                             );
}
bool edk::collision::MathCollision::aabbPointsYZInside(edk::cubef32 insideCube,edk::cubef32 outsideCube){
    if(//insideCube.origin.x >= outsideCube.origin.x
            //&&
            insideCube.origin.y >= outsideCube.origin.y
            &&
            insideCube.origin.z >= outsideCube.origin.z
            //&&
            //insideCube.origin.x <= outsideCube.size.width
            &&
            insideCube.origin.y <= outsideCube.size.height
            &&
            insideCube.origin.z <= outsideCube.size.length
            //&&
            //insideCube.size.width >= outsideCube.origin.x
            &&
            insideCube.size.height >= outsideCube.origin.y
            &&
            insideCube.size.length >= outsideCube.origin.z
            &&
            //insideCube.size.width <= outsideCube.size.width
            //&&
            insideCube.size.height <= outsideCube.size.height
            &&
            insideCube.size.length <= outsideCube.size.length
            )
        return true;
    return false;
}

//test if a bounsingBox2D is inside other boundingBox2D
bool edk::collision::MathCollision::boundingBox2DFirstInsideSecond(edk::float32 x1,edk::float32 y1,edk::float32 width1,edk::float32 height1,
                                                                   edk::float32 x2,edk::float32 y2,edk::float32 width2,edk::float32 height2
                                                                   ){
    return edk::collision::MathCollision::boundingBox2DFirstInsideSecond(edk::vec2f32(x1,y1),edk::size2f32(width1,height1),edk::vec2f32(x2,y2),edk::size2f32(width2,height2));edkEnd();
}
bool edk::collision::MathCollision::boundingBox2DFirstInsideSecond(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2){
    return edk::collision::MathCollision::boundingBox2DFirstInsideSecond(edk::rectf32(position1,size1),edk::rectf32(position2,size2));edkEnd();
}
bool edk::collision::MathCollision::boundingBox2DFirstInsideSecond(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect1.origin.x >= rect2.origin.x
            &&
            rect1.origin.y >= rect2.origin.y
            &&
            rect1.origin.x + rect1.size.width < rect2.size.width + rect2.origin.x
            &&
            rect1.origin.x + rect1.size.height < rect2.size.height + rect2.origin.y
            ){
        return true;
    }
    return false;
}
bool edk::collision::MathCollision::boundingBox2DPointsFirstInsideSecond(edk::float32 x1_1,edk::float32 y1_1,edk::float32 x1_2,edk::float32 y1_2,
                                                                         edk::float32 x2_1,edk::float32 y2_1,edk::float32 x2_2,edk::float32 y2_2
                                                                         ){
    return edk::collision::MathCollision::boundingBox2DPointsFirstInsideSecond(edk::vec2f32(x1_1,y1_1),edk::vec2f32(x1_2,y1_2),edk::vec2f32(x2_1,y2_1),edk::vec2f32(x2_2,y2_2));edkEnd();
}
bool edk::collision::MathCollision::boundingBox2DPointsFirstInsideSecond(edk::vec2f32 position1_1,edk::vec2f32 position1_2,edk::vec2f32 position2_1,edk::vec2f32 position2_2){
    return edk::collision::MathCollision::boundingBox2DPointsFirstInsideSecond(edk::rectf32(position1_1.x,position1_1.y,position1_2.x,position1_2.y),
                                                                               edk::rectf32(position2_1.x,position2_1.y,position2_2.x,position2_2.y)
                                                                               );edkEnd();
}
bool edk::collision::MathCollision::boundingBox2DPointsFirstInsideSecond(edk::rectf32 rect1,edk::rectf32 rect2){
    if(rect1.origin.x >= rect2.origin.x
            &&
            rect1.origin.y >= rect2.origin.y
            &&
            rect1.size.width < rect2.size.width
            &&
            rect1.size.height < rect2.size.height
            ){
        return true;
    }
    return false;
}
//test if a bounsingBox3D is inside other boundingBox3D
bool edk::collision::MathCollision::boundingBox3DFirstInsideSecond(edk::float32 x1,edk::float32 y1,edk::float32 z1,edk::float32 width1,edk::float32 height1,edk::float32 lenght1,
                                                                   edk::float32 x2,edk::float32 y2,edk::float32 z2,edk::float32 width2,edk::float32 height2,edk::float32 lenght2
                                                                   ){
    return edk::collision::MathCollision::boundingBox3DFirstInsideSecond(edk::vec3f32(x1,y1,z1),edk::size3f32(width1,height1,lenght1),edk::vec3f32(x2,y2,z2),edk::size3f32(width2,height2,lenght2));edkEnd();
}
bool edk::collision::MathCollision::boundingBox3DFirstInsideSecond(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::boundingBox3DFirstInsideSecond(edk::cubef32(position1,size1),edk::cubef32(position2,size2));edkEnd();
}
bool edk::collision::MathCollision::boundingBox3DFirstInsideSecond(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.x >= cube2.origin.x
            &&
            cube1.origin.y >= cube2.origin.y
            &&
            cube1.origin.z >= cube2.origin.z
            &&
            cube1.origin.x + cube1.size.width < cube2.size.width + cube2.origin.x
            &&
            cube1.origin.x + cube1.size.height < cube2.size.height + cube2.origin.y
            &&
            cube1.origin.z + cube1.size.length < cube2.size.length + cube2.origin.z
            ){
        return true;
    }
    return false;
}
bool edk::collision::MathCollision::boundingBox3DPointsFirstInsideSecond(edk::float32 x1_1,edk::float32 y1_1,edk::float32 z1_1,edk::float32 x1_2,edk::float32 y1_2,edk::float32 z1_2,
                                                                         edk::float32 x2_1,edk::float32 y2_1,edk::float32 z2_1,edk::float32 x2_2,edk::float32 y2_2,edk::float32 z2_2
                                                                         ){
    return edk::collision::MathCollision::boundingBox3DPointsFirstInsideSecond(edk::vec3f32(x1_1,y1_1,z1_1),edk::vec3f32(x1_2,y1_2,z1_2),edk::vec3f32(x2_1,y2_1,z2_1),edk::vec3f32(x2_2,y2_2,z2_2));edkEnd();
}
bool edk::collision::MathCollision::boundingBox3DPointsFirstInsideSecond(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2){
    return edk::collision::MathCollision::boundingBox3DPointsFirstInsideSecond(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,position1_2.x,position1_2.y,position1_2.z),
                                                                               edk::cubef32(position2_1.x,position2_1.y,position2_1.z,position2_2.x,position2_2.y,position2_2.z)
                                                                               );edkEnd();
}
bool edk::collision::MathCollision::boundingBox3DPointsFirstInsideSecond(edk::cubef32 cube1,edk::cubef32 cube2){
    if(cube1.origin.x >= cube2.origin.x
            &&
            cube1.origin.y >= cube2.origin.y
            &&
            cube1.origin.z >= cube2.origin.z
            &&
            cube1.size.width < cube2.size.width
            &&
            cube1.size.height < cube2.size.height
            &&
            cube1.size.length < cube2.size.length
            ){
        return true;
    }
    return false;
}

//POINT STRAIGHT 2D
bool edk::collision::MathCollision::pointStraigh2D(edk::float32 pointX,edk::float32 pointY,float32 lineX1,float32 lineY1,float32 lineX2,float32 lineY2, edk::float32 radius){
    return edk::collision::MathCollision::pointStraigh2D(edk::vec2f32(pointX,pointY),vec2f32(lineX1,lineY1),vec2f32(lineX2,lineY2), radius);edkEnd();
}
bool edk::collision::MathCollision::pointStraigh2D(edk::vec2f32 point,vec2f32 lineStart,vec2f32 lineEnd, edk::float32 radius){
    edk::float32 value = (point.x*lineStart.y)+
            (point.y*lineEnd.x)+
            (lineStart.x*lineEnd.y)-
            (lineEnd.x*lineStart.y)-
            (lineEnd.y*point.x)-
            (lineStart.x*point.y);edkEnd();
    if(value<radius && value>-radius){
        //Entao ele retorna true
        return true;
    }
    //else return zero
    return false;
}
bool edk::collision::MathCollision::straightStraight2D(float32 line1StartX,float32 line1StartY,float32 line1EndX,float32 line1EndY,
                                                       float32 line2StartX,float32 line2StartY,float32 line2EndX,float32 line2EndY,
                                                       edk::collision::Vecs2f32* vecs
                                                       ){
    return edk::collision::MathCollision::straightStraight2D(vec2f32(line1StartX,line1StartY),vec2f32(line1EndX,line1EndY),
                                                             vec2f32(line2StartX,line2StartY),vec2f32(line2EndX,line2EndY),
                                                             vecs
                                                             );edkEnd();
}
bool edk::collision::MathCollision::straightStraight2D(vec2f32 line1Start,vec2f32 line1End,
                                                       vec2f32 line2Start,vec2f32 line2End,
                                                       edk::collision::Vecs2f32* vecs
                                                       ){
    bool ret = false;edkEnd();
    //create the vectors to the contact
    if(vecs){
        //the temp vec
        edk::vec2f32 temp;edkEnd();
        edk::float64 det;edkEnd();
        det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);edkEnd();
        if(!det){
            det=0.0001f;edkEnd();
        }
        //
        temp.x=((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
        temp.y=((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
        if( temp.x>=0.f && temp.x<=1.f && temp.y>=0.f && temp.y<=1.f){
            vecs->pushBack(edk::vec2f32(line1Start.x+(temp.x*(line1End.x-line1Start.x)),
                                        line1Start.y+(temp.x*(line1End.y-line1Start.y))
                                        )
                           );edkEnd();
            ret=true;edkEnd();
        }
    }
    else{
        //the temp vec
        edk::vec2f32 temp;edkEnd();
        edk::float64 det;edkEnd();
        det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);edkEnd();
        if(!det){
            det=0.0001f;edkEnd();
        }
        //
        temp.x=((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
        temp.y=((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
        if( temp.x>=0.f && temp.x<=1.f && temp.y>=0.f && temp.y<=1.f){
            ret=true;edkEnd();
        }
    }
    //else return a zero vector
    return ret;
}
bool edk::collision::MathCollision::straightStraight2DtoBool(float32 line1StartX,float32 line1StartY,float32 line1EndX,float32 line1EndY,
                                                             float32 line2StartX,float32 line2StartY,float32 line2EndX,float32 line2EndY
                                                             ){
    return edk::collision::MathCollision::straightStraight2DtoBool(vec2f32(line1StartX,line1StartY),vec2f32(line1EndX,line1EndY),
                                                                   vec2f32(line2StartX,line2StartY),vec2f32(line2EndX,line2EndY)
                                                                   );edkEnd();
}
bool edk::collision::MathCollision::straightStraight2DtoBool(vec2f32 line1Start,vec2f32 line1End,
                                                             vec2f32 line2Start,vec2f32 line2End
                                                             ){
    //create the vectors to the contact

    //the temp vec
    edk::vec2f32 temp;edkEnd();
    edk::float64 det;edkEnd();

    //( Ponto k,           Ponto l,         Ponto m,           Ponto n)
    //vec2f32 line1Start,vec2f32 line1End,vec2f32 line2Start,vec2f32 line2End
    //det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);edkEnd();
    det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);edkEnd();

    if(!det){
        det=0.0001f;edkEnd();
    }

    //
    //s =  ((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/ det ;edkEnd();
    temp.x=((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
    //t =  ((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/ det ;edkEnd();
    temp.y=((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
    if( temp.x>=0.f && temp.y<=1.f && temp.y>=0.f && temp.y<=1.f){
        //
        return true;
    }
    return false;
}
//POINT STRAIGHT 3D
bool edk::collision::MathCollision::pointStraigh3D(edk::float32 pointX,edk::float32 pointY,edk::float32 pointZ,
                                                   float32 lineX1,float32 lineY1,float32 lineZ1,
                                                   float32 lineX2,float32 lineY2,float32 lineZ2,
                                                   edk::float32 radius
        ){
    return edk::collision::MathCollision::pointStraigh3D(edk::vec3f32(pointX,pointY,pointZ),
                                                         vec3f32(lineX1,lineY1,lineZ1),
                                                         vec3f32(lineX2,lineY2,lineZ2),
                                                         radius);
}
bool edk::collision::MathCollision::pointStraigh3D(edk::vec3f32 point,vec3f32 lineStart,vec3f32 lineEnd, edk::float32 radius){
    edk::float32 value = (point.x*lineStart.y)+
            (point.y*lineEnd.x)+
            (lineStart.x*lineEnd.y)-
            (lineEnd.x*lineStart.y)-
            (lineEnd.y*point.x)-
            (lineStart.x*point.y);edkEnd();
    if(value<radius && value>-radius){
        //Entao ele retorna true
        return true;
    }
    //else return zero
    return false;
}
bool edk::collision::MathCollision::straightStraight3D(float32 line1StartX,float32 line1StartY,float32 line1StartZ,
                                                       float32 line1EndX,float32 line1EndY,float32 line1EndZ,
                                                       float32 line2StartX,float32 line2StartY,float32 line2StartZ,
                                                       float32 line2EndX,float32 line2EndY,float32 line2EndZ,
                                                       edk::collision::Vecs3f32* vecs
                                                       ){
    return edk::collision::MathCollision::straightStraight3D(vec3f32(line1StartX,line1StartY,line1StartZ),
                                                             vec3f32(line1EndX,line1EndY,line1EndZ),
                                                             vec3f32(line2StartX,line2StartY,line2StartZ),
                                                             vec3f32(line2EndX,line2EndY,line2EndZ),
                                                             vecs
                                                             );edkEnd();
}
bool edk::collision::MathCollision::straightStraight3D(vec3f32 line1Start,vec3f32 line1End,
                                                       vec3f32 line2Start,vec3f32 line2End,
                                                       edk::collision::Vecs3f32* vecs
                                                       ){
    bool ret = false;edkEnd();
    //create the vectors to the contact
    if(vecs){
        //the temp vec
        edk::vec3f32 temp;edkEnd();
        edk::float64 det;edkEnd();
        det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);edkEnd();
        if(!det){
            det=0.0001f;edkEnd();
        }
        //
        temp.x=((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
        temp.y=((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
        if( temp.x>=0.f && temp.x<=1.f && temp.y>=0.f && temp.y<=1.f){
            vecs->pushBack(edk::vec3f32(line1Start.x+(temp.x*(line1End.x-line1Start.x)),
                                        line1Start.y+(temp.x*(line1End.y-line1Start.y)),
                                        line1Start.z+(temp.z*(line1End.z-line1Start.z))
                                        )
                           );edkEnd();
            ret=true;edkEnd();
        }
    }
    else{
        //the temp vec
        edk::vec2f32 temp;edkEnd();
        edk::float64 det;edkEnd();
        det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);edkEnd();
        if(!det){
            det=0.0001f;edkEnd();
        }
        //
        temp.x=((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
        temp.y=((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
        if( temp.x>=0.f && temp.x<=1.f && temp.y>=0.f && temp.y<=1.f){
            ret=true;edkEnd();
        }
    }
    //else return a zero vector
    return ret;
}
bool edk::collision::MathCollision::straightStraight3DtoBool(float32 line1StartX,float32 line1StartY,float32 line1StartZ,
                                                             float32 line1EndX,float32 line1EndY,float32 line1EndZ,
                                                             float32 line2StartX,float32 line2StartY,float32 line2StartZ,
                                                             float32 line2EndX,float32 line2EndY,float32 line2EndZ
                                                             ){
    return edk::collision::MathCollision::straightStraight3DtoBool(vec3f32(line1StartX,line1StartY,line1StartZ),
                                                                   vec3f32(line1EndX,line1EndY,line1EndZ),
                                                                   vec3f32(line2StartX,line2StartY,line2StartZ),
                                                                   vec3f32(line2EndX,line2EndY,line2EndZ)
                                                                   );edkEnd();
}
bool edk::collision::MathCollision::straightStraight3DtoBool(vec3f32 line1Start,vec3f32 line1End,
                                                             vec3f32 line2Start,vec3f32 line2End
                                                             ){
    //create the vectors to the contact

    //the temp vec
    edk::vec2f32 temp;edkEnd();
    edk::float64 det;edkEnd();

    //( Ponto k,           Ponto l,         Ponto m,           Ponto n)
    //vec2f32 line1Start,vec2f32 line1End,vec2f32 line2Start,vec2f32 line2End
    //det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);edkEnd();
    det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);edkEnd();

    if(!det){
        det=0.0001f;edkEnd();
    }

    //
    //s =  ((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/ det ;edkEnd();
    temp.x=((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
    //t =  ((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/ det ;edkEnd();
    temp.y=((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;edkEnd();
    if( temp.x>=0.f && temp.y<=1.f && temp.y>=0.f && temp.y<=1.f){
        //
        return true;
    }
    return false;
}

edk::collision::Vecs2f32 edk::collision::MathCollision::straightCircle2D(edk::vec2f32 lineStart,edk::vec2f32 lineEnd,
                                                                         edk::vec2f32 circlePosition,edk::float32 circleRadius){
    edk::collision::Vecs2f32 ret(2u);edkEnd();
    edk::float32 a,b,c,mu,i;edkEnd();
    //vectors
    edk::vec2f32 v1,v2;edkEnd();

    a=edk::Math::square(lineEnd.x-lineStart.x)+edk::Math::square(lineEnd.y-lineStart.y);edkEnd();
    b=2.f*((lineEnd.x-lineStart.x)*(lineStart.x-circlePosition.x)
           +(lineEnd.y-lineStart.y)*(lineStart.y-circlePosition.y));edkEnd();
    c=edk::Math::square(circlePosition.x)+edk::Math::square(circlePosition.y)+
            edk::Math::square(lineStart.x)+
            edk::Math::square(lineStart.y)
            -2*(circlePosition.x*lineStart.x+circlePosition.y*lineStart.y)-edk::Math::square(circleRadius);edkEnd();
    i=b*b-4*a*c;edkEnd();

    if(!a){
        a=0.0001f;edkEnd();
    }

    if(i==0.0f){
        //one intersection
        mu=-b/(2*a) ;edkEnd();
        v1.x=lineStart.x+mu*(lineEnd.x-lineStart.x);edkEnd();
        v1.y=lineStart.y+mu*(lineEnd.y-lineStart.y);edkEnd();

        //test colision with line boundingBox
        if(boundingContact2D(v1,lineStart,lineEnd)){
            //add the v1 to return
            ret.pushBack(v1);edkEnd();
        }
    }
    if(i>0.0f){
        //two intersections

        //first intersection
        mu=(-b+edk::Math::squareRoot(edk::Math::square(b)-4*a*c))/(2*a);edkEnd();
        v1.x=lineStart.x+mu*(lineEnd.x-lineStart.x);edkEnd();
        v1.y=lineStart.y+mu*(lineEnd.y-lineStart.y);edkEnd();
        //second intersection
        mu=(-b-edk::Math::squareRoot(edk::Math::square(b)-4*a*c))/(2*a);edkEnd();
        v2.x=lineStart.x+mu*(lineEnd.x-lineStart.x);edkEnd();
        v2.y=lineStart.y+mu*(lineEnd.y-lineStart.y);edkEnd();
        //return 2 points
        if(boundingContact2D(v1,lineStart,lineEnd)){
            if(boundingContact2D(v2,lineStart,lineEnd)){
                //add the two points
                ret.pushBack(v1);edkEnd();
                ret.pushBack(v2);edkEnd();
            }
            else{
                //add just the first point
                ret.pushBack(v1);edkEnd();
            }
        }
        else{
            if(boundingContact2D(v2,lineStart,lineEnd)){
                //add just the second point
                ret.pushBack(v2);edkEnd();
            }
        }
    }
    //return the ret
    return ret;
}

edk::collision::Vecs3f32 edk::collision::MathCollision::straightSphere3D(edk::vec3f32 lineStart,edk::vec3f32 lineEnd,
                                                                         edk::vec3f32 spherePosition,edk::float32 sphereRadius
                                                                         ){
    //
    edk::collision::Vecs3f32 ret(2u);edkEnd();

    edk::vec3f32 distance = lineEnd - lineStart;edkEnd();

    edk::float32 a = distance.x * distance.x + distance.y * distance.y + distance.z * distance.z;edkEnd();
    edk::float32 b = 2.0 * (lineStart.x * distance.x + lineStart.y * distance.y + lineStart.z * distance.z - distance.x * spherePosition.x - distance.y * spherePosition.y - distance.z * spherePosition.z);edkEnd();
    edk::float32 c = lineStart.x * lineStart.x - 2 * lineStart.x * spherePosition.x + spherePosition.x * spherePosition.x + lineStart.y * lineStart.y - 2 * lineStart.y * spherePosition.y + spherePosition.y * spherePosition.y +
            lineStart.z * lineStart.z - 2 * lineStart.z * spherePosition.z + spherePosition.z * spherePosition.z - sphereRadius * sphereRadius;edkEnd();

    // discriminant
    edk::float32 d=b*b-4.f*a*c;edkEnd();

    if(d<0){
        return ret;
    }

    if(!a){
        a=0.0001f;edkEnd();
    }

    edk::float32 t1 =(-b-edk::Math::squareRoot(d))/(2.0*a);edkEnd();

    edk::vec3f32 solution1(lineStart.x*(1-t1)+t1*lineEnd.x,
                           lineStart.y*(1-t1)+t1*lineEnd.y,
                           lineStart.z*(1-t1)+t1*lineEnd.z);edkEnd();
    if(d==0.f){
        ret.pushBack(solution1);edkEnd();
        return ret;
    }

    edk::float32 t2=(-b+edk::Math::squareRoot(d))/(2.0*a);edkEnd();
    edk::vec3f32 solution2(lineStart.x*(1-t2)+t2*lineEnd.x,
                           lineStart.y*(1-t2)+t2*lineEnd.y,
                           lineStart.z*(1-t2)+t2*lineEnd.z);edkEnd();

    // prefer a solution that's on the line segment itself

    if(edk::Math::module(t1-0.5f)<edk::Math::module(t2-0.5f)){
        ret.pushBack(solution1);edkEnd();
        ret.pushBack(solution2);edkEnd();
        return ret;
    }

    ret.pushBack(solution2);edkEnd();
    ret.pushBack(solution1);edkEnd();

    //return the ret
    return ret;
}

bool edk::collision::MathCollision::straightTriangle3D(edk::vec3f32 lineStart,edk::vec3f32 lineEnd,
                                                       edk::vec3f32 triangle1,edk::vec3f32 triangle2,edk::vec3f32 triangle3,
                                                       edk::vec3f32* result){
    edk::vec3f32 e1,e2,h,s,q;edkEnd();
    edk::float32 a,f,u,v;edkEnd();
    edk::float32 t;edkEnd();
    e1=triangle2-triangle1;edkEnd();
    e2=triangle3-triangle1;edkEnd();

    h = edk::Math::crossProduct(lineEnd,e2);edkEnd();

    a = edk::Math::dotProduct(e1,h);edkEnd();

    if(a > -0.00001 && a < 0.00001){
        edkEnd();
        return false;
    }

    f = 1.f/a;edkEnd();
    s=lineStart-triangle1;edkEnd();
    u = f * edk::Math::dotProduct(s,h);edkEnd();

    if(u < 0.0 || u > 1.0){
        edkEnd();
        return false;
    }

    q = edk::Math::crossProduct(s,e1);edkEnd();

    v = f * edk::Math::dotProduct(lineEnd,q);edkEnd();

    if(v < 0.0 || u + v > 1.0){
        edkEnd();
        return false;
    }

    // at this stage we can compute t to find out where
    // the intersection point is on the line
    t = f * edk::Math::dotProduct(e2,q);edkEnd();

    if(t > -0.00001f && t<1.00001){ // ray intersection
        if(result){
            result->x = lineStart.x + (lineEnd.x * t);edkEnd();
            result->y = lineStart.y + (lineEnd.y * t);edkEnd();
            result->z = lineStart.z + (lineEnd.z * t);edkEnd();
        }
        return true;
    }

    // this means that there is a line intersection
    // but not a ray intersection

    return false;
}

//POLYGON
bool edk::collision::MathCollision::polygonPoint(edk::shape::Polygon2D polygon, edk::vec2f32 point){
    //create the second point to check the line
    if(polygon.getVertexCount()>=3u){
        edk::vec2f32 pointTemp=edk::vec2f32(0.f,0.f);
        edk::vec2f32 pointEnd = polygon.getVertexPosition(0u);
        for(edk::uint32 i=1u;i<polygon.getVertexCount();i++){
            pointTemp = polygon.getVertexPosition(i);
            if(pointEnd.x<pointTemp.x){
                pointEnd.x=pointTemp.x;
            }
        }
        if(pointEnd.x<point.x){
            //else return false
            return false;
        }
        {
            pointEnd.y=point.y;
            edk::int32 collisions=0u;
            edk::collision::Vecs2f32 vecs;edkEnd();
            edk::vec2f32 p1;
            edk::vec2f32 p2;
            //calculate the intersection beetween the lines
            for(edk::uint32 i=0u;i<polygon.getVertexCount();i++){
                //test what line of the polygon is test
                if(i==(polygon.getVertexCount()-1u)){
                    p1 = polygon.getVertexPosition(i);
                    p2 = polygon.getVertexPosition(0u);
                    if(edk::collision::MathCollision::straightStraight2D(p1,
                                                                         p2,
                                                                         point,
                                                                         pointEnd,
                                                                         &vecs
                                                                         )){
                        for(edk::uint32 j=0u;j<vecs.size();j++){
                            pointTemp = vecs[j];
                            if(edk::collision::MathCollision::pointStraigh2D(pointTemp,point,pointEnd)){
                                collisions++;
                            }
                        }
                    }
                }
                else{
                    p1 = polygon.getVertexPosition(i);
                    p2 = polygon.getVertexPosition(i+1u);
                    if(edk::collision::MathCollision::straightStraight2D(p1,
                                                                         p2,
                                                                         point,
                                                                         pointEnd,
                                                                         &vecs
                                                                         )){
                        for(edk::uint32 j=0u;j<vecs.size();j++){
                            pointTemp = vecs[j];
                            if(edk::collision::MathCollision::pointStraigh2D(pointTemp,point,pointEnd)){
                                collisions++;
                            }
                        }
                    }
                }
                vecs.clean();
            }
            //test if the collisions are even
            if(!edk::Math::isEven(collisions)){
                //INSIDE
                //then return true because is inside
                return true;
            }
        }
    }
    //else return false
    return false;
}

//POLYGON WITH POLYGON
bool edk::collision::MathCollision::polygonPolygon2D(edk::shape::Polygon2D polygon1,edk::shape::Polygon2D polygon2){
    //test if the polygons have vertexes
    if(polygon1.getVertexCount()>2u && polygon2.getVertexCount()>2u){
        edk::uint32 size1 = polygon1.getVertexCount();
        edk::uint32 size2 = polygon2.getVertexCount();
        edk::rectf32 rect;
        edk::vec2f32 middle;
        edk::vec2f32 vert,v1,v2,v4;
        //calculate the middle point inside the polygon
        middle = polygon2.getVertexPosition(0u);
        rect.origin.x = middle.x;
        rect.origin.y = middle.y;
        rect.size.width = middle.x;
        rect.size.height = middle.y;
        for(edk::uint32 i=1u;i<size2;i++){
            middle = polygon1.getVertexPosition(i);
            if(rect.size.width<middle.x){
                rect.size.width=middle.x;
            }
            if(rect.size.height<middle.y){
                rect.size.height=middle.y;
            }
            if(rect.origin.x>middle.x){
                rect.origin.x=middle.x;
            }
            if(rect.origin.y>middle.y){
                rect.origin.y=middle.y;
            }
        }
        middle.x = ((rect.size.width - rect.origin.x)*0.5f) + rect.origin.x;
        middle.y = ((rect.size.height - rect.origin.y)*0.5f) + rect.origin.y;

        //test if a vertex is inside the polygon
        for(edk::uint32 i=1u;i<size1;i++){
            vert = polygon1.getVertexPosition(i);
            v1 = polygon2.getVertexPosition(size2-1u);
            v2 = polygon2.getVertexPosition(0u);
            //test the collision of two lines
            if(edk::collision::MathCollision::straightStraight2D(middle.x,middle.y,vert.x,vert.y,
                                                                 v1.x,v2.y,v2.x,v2.y,
                                                                 NULL
                                                                 )){
                continue;
            }
            for(edk::uint32 j=0u;j<size2;j++){
                v1 = polygon2.getVertexPosition(j-1u);
                v2 = polygon2.getVertexPosition(j);
                //test the collision of two lines
                if(edk::collision::MathCollision::straightStraight2D(middle.x,middle.y,vert.x,vert.y,
                                                                     v1.x,v2.y,v2.x,v2.y,
                                                                     NULL
                                                                     )){
                    continue;
                }
            }
            return true;
        }

        vert = polygon1.getVertexPosition(size1-1u);
        v4 = polygon1.getVertexPosition(0u);
        v1 = polygon2.getVertexPosition(size2-1u);
        v2 = polygon2.getVertexPosition(0u);
        //test the collision of two lines
        if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,v4.x,v4.y,
                                                             v1.x,v2.y,v2.x,v2.y,
                                                             NULL
                                                             )){
            return true;
        }
        for(edk::uint32 j=1u;j<size2;j++){
            v1 = polygon2.getVertexPosition(j-1u);
            v2 = polygon2.getVertexPosition(j);
            //test the collision of two lines
            if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,v4.x,v4.y,
                                                                 v1.x,v2.y,v2.x,v2.y,
                                                                 NULL
                                                                 )){
                return true;
            }
        }
        for(edk::uint32 i=1u;i<size1;i++){
            vert = polygon1.getVertexPosition(i-1u);
            v4 = polygon1.getVertexPosition(i);
            v1 = polygon2.getVertexPosition(size2-1u);
            v2 = polygon2.getVertexPosition(0u);
            //test the collision of two lines
            if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,v4.x,v4.y,
                                                                 v1.x,v2.y,v2.x,v2.y,
                                                                 NULL
                                                                 )){
                return true;
            }
            for(edk::uint32 j=1u;j<size2;j++){
                v1 = polygon2.getVertexPosition(j-1u);
                v2 = polygon2.getVertexPosition(j);
                //test the collision of two lines
                if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,v4.x,v4.y,
                                                                     v1.x,v2.y,v2.x,v2.y,
                                                                     NULL
                                                                     )){
                    return true;
                }
            }
        }
    }
    return false;
}
bool edk::collision::MathCollision::polygon2DRectPoints(edk::shape::Polygon2D polygon,edk::rectf32 rect){
    //test if the polygons have vertexes
    if(polygon.getVertexCount()){
        edk::uint32 size = polygon.getVertexCount();
        edk::vec2f32 middle;
        edk::vec2f32 vert,vert2;
        middle.x = ((rect.size.width - rect.origin.x)*0.5f) + rect.origin.x;
        middle.y = ((rect.size.height - rect.origin.y)*0.5f) + rect.origin.y;

        //test if a vertex is inside the polygon
        for(edk::uint32 i=0u;i<size;i++){
            vert = polygon.getVertexPosition(i);
            //test the collision of two lines
            if(edk::collision::MathCollision::straightStraight2D(middle.x,middle.y,vert.x,vert.y,
                                                                 rect.origin.x,rect.origin.y,
                                                                 rect.origin.x,rect.size.height,
                                                                 NULL
                                                                 )){
                continue;
            }
            if(edk::collision::MathCollision::straightStraight2D(middle.x,middle.y,vert.x,vert.y,
                                                                 rect.origin.x,rect.size.height,
                                                                 rect.size.width,rect.size.height,
                                                                 NULL
                                                                 )){
                continue;
            }
            if(edk::collision::MathCollision::straightStraight2D(middle.x,middle.y,vert.x,vert.y,
                                                                 rect.size.width,rect.size.height,
                                                                 rect.size.width,rect.origin.y,
                                                                 NULL
                                                                 )){
                continue;
            }
            if(edk::collision::MathCollision::straightStraight2D(middle.x,middle.y,vert.x,vert.y,
                                                                 rect.size.width,rect.origin.y,
                                                                 rect.origin.x,rect.origin.y,
                                                                 NULL
                                                                 )){
                continue;
            }
            return true;
        }

        //test the collision beetween the straights
        vert = polygon.getVertexPosition(size-1u);
        vert2 = polygon.getVertexPosition(0u);
        //test the collision of two lines
        if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,vert2.x,vert2.y,
                                                             rect.origin.x,rect.origin.y,
                                                             rect.origin.x,rect.size.height,
                                                             NULL
                                                             )){
            return true;
        }
        if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,vert2.x,vert2.y,
                                                             rect.origin.x,rect.size.height,
                                                             rect.size.width,rect.size.height,
                                                             NULL
                                                             )){
            return true;
        }
        if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,vert2.x,vert2.y,
                                                             rect.size.width,rect.size.height,
                                                             rect.size.width,rect.origin.y,
                                                             NULL
                                                             )){
            return true;
        }
        if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,vert2.x,vert2.y,
                                                             rect.size.width,rect.origin.y,
                                                             rect.origin.x,rect.origin.y,
                                                             NULL
                                                             )){
            return true;
        }
        for(edk::uint32 i=1u;i<size;i++){
            vert = polygon.getVertexPosition(i);
            vert2 = polygon.getVertexPosition(i-1u);
            //test the collision of two lines
            if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,vert2.x,vert2.y,
                                                                 rect.origin.x,rect.origin.y,
                                                                 rect.origin.x,rect.size.height,
                                                                 NULL
                                                                 )){
                return true;
            }
            if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,vert2.x,vert2.y,
                                                                 rect.origin.x,rect.size.height,
                                                                 rect.size.width,rect.size.height,
                                                                 NULL
                                                                 )){
                return true;
            }
            if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,vert2.x,vert2.y,
                                                                 rect.size.width,rect.size.height,
                                                                 rect.size.width,rect.origin.y,
                                                                 NULL
                                                                 )){
                return true;
            }
            if(edk::collision::MathCollision::straightStraight2D(vert.x,vert.y,vert2.x,vert2.y,
                                                                 rect.size.width,rect.origin.y,
                                                                 rect.origin.x,rect.origin.y,
                                                                 NULL
                                                                 )){
                return true;
            }
        }
    }
    return false;
}

//RECTS
bool edk::collision::MathCollision::rectRectPoints(edk::rectf32 r1,edk::rectf32 r2,
                                                   edk::collision::Vecs2f32* vecs
                                                   ){
    //calculate the collision
    if(vecs){
        if(r1.origin.x>=r2.origin.x
                && r1.origin.x<=r2.size.width
                ){
            if(r2.origin.y>=r1.origin.y
                    && r2.origin.y<=r1.size.height
                    ){
                vecs->pushBack(r1.origin.x,r2.origin.y);
            }
            if(r2.size.height>=r1.origin.y
                    && r2.size.height<=r1.size.height
                    ){
                vecs->pushBack(r1.origin.x,r2.size.height);
            }
        }
        if(r1.size.width>=r2.origin.x
                && r1.size.width<=r2.size.width
                ){
            if(r2.origin.y>=r1.origin.y
                    && r2.origin.y<=r1.size.height
                    ){
                vecs->pushBack(r1.size.width,r2.origin.y);
            }
            if(r2.size.height>=r1.origin.y
                    && r2.size.height<=r1.size.height
                    ){
                vecs->pushBack(r1.size.width,r2.size.height);
            }
        }
        if(!vecs->size()){
            //test if one rect are inside other rect
            if(r1.origin.x >=r2.origin.x
                    && r1.origin.y >=r2.origin.y
                    && r1.size.width <=r2.size.width
                    && r1.size.height <=r2.size.height
                    ){
                vecs->pushBack(r1.origin.x,r1.origin.y);
                vecs->pushBack(r1.origin.x,r1.size.height);
                vecs->pushBack(r1.size.width,r1.size.height);
                vecs->pushBack(r1.size.width,r1.size.height);
                return true;
            }
            if(r1.origin.x >=r2.origin.x
                    && r1.origin.y >=r2.origin.y
                    && r1.size.width <=r2.size.width
                    && r1.size.height <=r2.size.height
                    ){
                vecs->pushBack(r1.origin.x,r1.origin.y);
                vecs->pushBack(r1.origin.x,r1.size.height);
                vecs->pushBack(r1.size.width,r1.size.height);
                vecs->pushBack(r1.size.width,r1.size.height);
                return true;
            }
        }
        else return true;
    }
    return edk::collision::MathCollision::aabbPoints(r1,r2);
}
