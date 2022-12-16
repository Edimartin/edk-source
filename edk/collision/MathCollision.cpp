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
#warning "            Inside MathCollision.cpp"
#endif

edk::collision::MathCollision::MathCollision(){
    //
}

edk::collision::MathCollision::~MathCollision(){
    //
}

bool edk::collision::MathCollision::boundingContact3D(edk::vec3f32 point,edk::vec3f32 vec1,edk::vec3f32 vec2){
    //
    edk::float32 xMe,yMe,zMe;
    edk::float32 xMa,yMa,zMa;

    if(vec1.x>vec2.x){
        xMa=vec1.x;
        xMe=vec2.x;
    }
    else{
        xMa=vec2.x;
        xMe=vec1.x;
    }

    if(vec1.y>vec2.y){
        yMa=vec1.y;
        yMe=vec2.y;
    }
    else{
        yMa=vec2.y;
        yMe=vec1.y;
    }

    if(vec1.z>vec2.z){
        zMa=vec1.z;
        zMe=vec2.z;
    }
    else{
        zMa=vec2.z;
        zMe=vec1.z;
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
    edk::float32 xMe,yMe;
    edk::float32 xMa,yMa;

    if(vec1.x>vec2.x){
        xMa=vec1.x;
        xMe=vec2.x;
    }
    else{
        xMa=vec2.x;
        xMe=vec1.x;
    }

    if(vec1.y>vec2.y){
        yMa=vec1.y;
        yMe=vec2.y;
    }
    else{
        yMa=vec2.y;
        yMe=vec1.y;
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
    return edk::collision::MathCollision::aabb(edk::vec2f32(x1,y1),edk::size2f32(width1,height1),edk::vec2f32(x2,y2),edk::size2f32(width2,height2));
}
bool edk::collision::MathCollision::aabb(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2){
    return edk::collision::MathCollision::aabb(edk::rectf32(position1.x,position1.y,size1.width,size1.height),
                                               edk::rectf32(position2.x,position2.y,size2.width,size2.height)
                                               );
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
bool edk::collision::MathCollision::aabbPoints(edk::float32 x1_1,edk::float32 y1_1,edk::float32 x1_2,edk::float32 y1_2,
                                               edk::float32 x2_1,edk::float32 y2_1,edk::float32 x2_2,edk::float32 y2_2
                                               ){
    return edk::collision::MathCollision::aabbPoints(edk::vec2f32(x1_1,y1_1),edk::vec2f32(x1_2,y1_2),edk::vec2f32(x2_1,y2_1),edk::vec2f32(x2_2,y2_2));
}
bool edk::collision::MathCollision::aabbPoints(edk::vec2f32 position1_1,edk::vec2f32 position1_2,edk::vec2f32 position2_1,edk::vec2f32 position2_2){
    return edk::collision::MathCollision::aabbPoints(edk::rectf32(position1_1.x,position1_1.y,position1_2.x,position1_2.y),
                                                     edk::rectf32(position2_1.x,position2_1.y,position2_2.x,position2_2.y)
                                                     );
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
//3D
bool edk::collision::MathCollision::aabb(edk::float32 x1,edk::float32 y1,edk::float32 z1,edk::float32 width1,edk::float32 height1,edk::float32 length1,
                                         edk::float32 x2,edk::float32 y2,edk::float32 z2,edk::float32 width2,edk::float32 height2,edk::float32 length2
                                         ){
    return edk::collision::MathCollision::aabb(edk::vec3f32(x1,y1,z1),edk::size3f32(width1,height1,length1),
                                               edk::vec3f32(x2,y2,z2),edk::size3f32(width2,height2,length2)
                                               );
}
bool edk::collision::MathCollision::aabb(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::aabb(edk::cubef32(position1.x,position1.y,position1.z,size1.width,size1.height,size1.length),
                                               edk::cubef32(position2.x,position2.y,position2.z,size2.width,size2.height,size2.length)
                                               );
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
bool edk::collision::MathCollision::aabbPoints(edk::float32 x1_1,edk::float32 y1_1,edk::float32 z1_1,edk::float32 x1_2,edk::float32 y1_2,edk::float32 z1_2,
                                               edk::float32 x2_1,edk::float32 y2_1,edk::float32 z2_1,edk::float32 x2_2,edk::float32 y2_2,edk::float32 z2_2
                                               ){
    return edk::collision::MathCollision::aabbPoints(edk::vec3f32(x1_1,y1_1,z1_1),edk::vec3f32(x1_2,y1_2,z1_2),
                                                     edk::vec3f32(x2_1,y2_1,z2_1),edk::vec3f32(x2_2,y2_2,z2_2)
                                                     );
}
bool edk::collision::MathCollision::aabbPoints(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2){
    return edk::collision::MathCollision::aabb(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,position1_2.x,position1_2.y,position1_2.z),
                                               edk::cubef32(position2_1.x,position2_1.y,position2_1.z,position2_2.x,position2_2.y,position2_2.z)
                                               );
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

//test if a bounsingBox2D is inside other boundingBox2D
bool edk::collision::MathCollision::boundingBox2DFirstInsideSecond(edk::float32 x1,edk::float32 y1,edk::float32 width1,edk::float32 height1,
                                                                   edk::float32 x2,edk::float32 y2,edk::float32 width2,edk::float32 height2
                                                                   ){
    return edk::collision::MathCollision::boundingBox2DFirstInsideSecond(edk::vec2f32(x1,y1),edk::size2f32(width1,height1),edk::vec2f32(x2,y2),edk::size2f32(width2,height2));
}
bool edk::collision::MathCollision::boundingBox2DFirstInsideSecond(edk::vec2f32 position1,edk::size2f32 size1,edk::vec2f32 position2,edk::size2f32 size2){
    return edk::collision::MathCollision::boundingBox2DFirstInsideSecond(edk::rectf32(position1,size1),edk::rectf32(position2,size2));
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
    return edk::collision::MathCollision::boundingBox2DPointsFirstInsideSecond(edk::vec2f32(x1_1,y1_1),edk::vec2f32(x1_2,y1_2),edk::vec2f32(x2_1,y2_1),edk::vec2f32(x2_2,y2_2));
}
bool edk::collision::MathCollision::boundingBox2DPointsFirstInsideSecond(edk::vec2f32 position1_1,edk::vec2f32 position1_2,edk::vec2f32 position2_1,edk::vec2f32 position2_2){
    return edk::collision::MathCollision::boundingBox2DPointsFirstInsideSecond(edk::rectf32(position1_1.x,position1_1.y,position1_2.x,position1_2.y),
                                                                               edk::rectf32(position2_1.x,position2_1.y,position2_2.x,position2_2.y)
                                                                               );
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
    return edk::collision::MathCollision::boundingBox3DFirstInsideSecond(edk::vec3f32(x1,y1,z1),edk::size3f32(width1,height1,lenght1),edk::vec3f32(x2,y2,z2),edk::size3f32(width2,height2,lenght2));
}
bool edk::collision::MathCollision::boundingBox3DFirstInsideSecond(edk::vec3f32 position1,edk::size3f32 size1,edk::vec3f32 position2,edk::size3f32 size2){
    return edk::collision::MathCollision::boundingBox3DFirstInsideSecond(edk::cubef32(position1,size1),edk::cubef32(position2,size2));
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
    return edk::collision::MathCollision::boundingBox3DPointsFirstInsideSecond(edk::vec3f32(x1_1,y1_1,z1_1),edk::vec3f32(x1_2,y1_2,z1_2),edk::vec3f32(x2_1,y2_1,z2_1),edk::vec3f32(x2_2,y2_2,z2_2));
}
bool edk::collision::MathCollision::boundingBox3DPointsFirstInsideSecond(edk::vec3f32 position1_1,edk::vec3f32 position1_2,edk::vec3f32 position2_1,edk::vec3f32 position2_2){
    return edk::collision::MathCollision::boundingBox3DPointsFirstInsideSecond(edk::cubef32(position1_1.x,position1_1.y,position1_1.z,position1_2.x,position1_2.y,position1_2.z),
                                                                               edk::cubef32(position2_1.x,position2_1.y,position2_1.z,position2_2.x,position2_2.y,position2_2.z)
                                                                               );
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

//POINT STRAIGHT
bool edk::collision::MathCollision::pointStraigh2D(edk::float32 pointX,edk::float32 pointY,float32 lineX1,float32 lineY1,float32 lineX2,float32 lineY2, edk::float32 radius){
    return edk::collision::MathCollision::pointStraigh2D(edk::vec2f32(pointX,pointY),vec2f32(lineX1,lineY1),vec2f32(lineX2,lineY2), radius);
}
bool edk::collision::MathCollision::pointStraigh2D(edk::vec2f32 point,vec2f32 lineStart,vec2f32 lineEnd, edk::float32 radius){
    edk::float32 value = (point.x*lineStart.y)+
            (point.y*lineEnd.x)+
            (lineStart.x*lineEnd.y)-
            (lineEnd.x*lineStart.y)-
            (lineEnd.y*point.x)-
            (lineStart.x*point.y);
    if(value<radius && value>-radius)
        //Entao ele retorna true
        return true;
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
                                                             );
}
bool edk::collision::MathCollision::straightStraight2D(vec2f32 line1Start,vec2f32 line1End,
                                                       vec2f32 line2Start,vec2f32 line2End,
                                                       edk::collision::Vecs2f32* vecs
                                                       ){
    bool ret = false;
    //create the vectors to the contact
    if(vecs){

        //the temp vec
        edk::vec2f32 temp;
        edk::float64 det;

        //( Ponto k,           Ponto l,         Ponto m,           Ponto n)
        //vec2f32 line1Start,vec2f32 line1End,vec2f32 line2Start,vec2f32 line2End
        //det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);
        det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);

        if(!det)det=0.0001f;


        //
        //s =  ((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/ det ;
        temp.x=((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;
        //t =  ((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/ det ;
        temp.y=((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;
        if( temp.x>=0.f && temp.y<=1.f && temp.y>=0.f && temp.y<=1.f){
            //
            //ret.createVectors(1u);
            //Pi.x = k.x + (l.x-k.x)*s;
            //Pi.y = k.y + (l.y-k.y)*s;

            vecs->pushBack(edk::vec2f32(line1Start.x+(temp.x*(line1End.x-line1Start.x)),
                                        line1Start.y+(temp.x*(line1End.y-line1Start.y))
                                        )
                           );
            ret=true;
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
                                                                   );
}
bool edk::collision::MathCollision::straightStraight2DtoBool(vec2f32 line1Start,vec2f32 line1End,
                                                             vec2f32 line2Start,vec2f32 line2End
                                                             ){
    //create the vectors to the contact

    //the temp vec
    edk::vec2f32 temp;
    edk::float64 det;

    //( Ponto k,           Ponto l,         Ponto m,           Ponto n)
    //vec2f32 line1Start,vec2f32 line1End,vec2f32 line2Start,vec2f32 line2End
    //det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);
    det = (line2End.x - line2Start.x) * (line1End.y - line1Start.y)  -  (line2End.y - line2Start.y) * (line1End.x - line1Start.x);

    if(!det)det=0.0001f;

    //
    //s =  ((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/ det ;
    temp.x=((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;
    //t =  ((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/ det ;
    temp.y=((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;
    if( temp.x>=0.f && temp.y<=1.f && temp.y>=0.f && temp.y<=1.f){
        //
        return true;
    }
    return false;
}

edk::collision::Vecs2f32 edk::collision::MathCollision::straightCircle2D(edk::vec2f32 lineStart,edk::vec2f32 lineEnd,
                                                                         edk::vec2f32 circlePosition,edk::float32 circleRadius){
    edk::collision::Vecs2f32 ret(2u);
    edk::float32 a,b,c,mu,i;
    //vectors
    edk::vec2f32 v1,v2;

    a=edk::Math::square(lineEnd.x-lineStart.x)+edk::Math::square(lineEnd.y-lineStart.y);
    b=2.f*((lineEnd.x-lineStart.x)*(lineStart.x-circlePosition.x)
           +(lineEnd.y-lineStart.y)*(lineStart.y-circlePosition.y));
    c=edk::Math::square(circlePosition.x)+edk::Math::square(circlePosition.y)+
            edk::Math::square(lineStart.x)+
            edk::Math::square(lineStart.y)
            -2*(circlePosition.x*lineStart.x+circlePosition.y*lineStart.y)-edk::Math::square(circleRadius);
    i=b*b-4*a*c;

    if(!a)a=0.0001f;

    if (i==0.0f){
        //one intersection
        mu=-b/(2*a) ;
        v1.x=lineStart.x+mu*(lineEnd.x-lineStart.x);
        v1.y=lineStart.y+mu*(lineEnd.y-lineStart.y);

        //test colision with line boundingBox
        if(boundingContact2D(v1,lineStart,lineEnd)){
            //add the v1 to return
            ret.pushBack(v1);
        }
    }
    if (i>0.0f){
        //two intersections

        //first intersection
        mu=(-b+edk::Math::squareRoot(edk::Math::square(b)-4*a*c))/(2*a);
        v1.x=lineStart.x+mu*(lineEnd.x-lineStart.x);
        v1.y=lineStart.y+mu*(lineEnd.y-lineStart.y);
        //second intersection
        mu=(-b-edk::Math::squareRoot(edk::Math::square(b)-4*a*c))/(2*a);
        v2.x=lineStart.x+mu*(lineEnd.x-lineStart.x);
        v2.y=lineStart.y+mu*(lineEnd.y-lineStart.y);
        //return 2 points
        if(boundingContact2D(v1,lineStart,lineEnd)){
            if(boundingContact2D(v2,lineStart,lineEnd)){
                //add the two points
                ret.pushBack(v1);
                ret.pushBack(v2);
            }
            else{
                //add just the first point
                ret.pushBack(v1);
            }
        }
        else{
            if(boundingContact2D(v2,lineStart,lineEnd)){
                //add just the second point
                ret.pushBack(v2);
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
    edk::collision::Vecs3f32 ret(2u);

    edk::vec3f32 distance = lineEnd - lineStart;

    edk::float32 a = distance.x * distance.x + distance.y * distance.y + distance.z * distance.z;
    edk::float32 b = 2.0 * (lineStart.x * distance.x + lineStart.y * distance.y + lineStart.z * distance.z - distance.x * spherePosition.x - distance.y * spherePosition.y - distance.z * spherePosition.z);
    edk::float32 c = lineStart.x * lineStart.x - 2 * lineStart.x * spherePosition.x + spherePosition.x * spherePosition.x + lineStart.y * lineStart.y - 2 * lineStart.y * spherePosition.y + spherePosition.y * spherePosition.y +
            lineStart.z * lineStart.z - 2 * lineStart.z * spherePosition.z + spherePosition.z * spherePosition.z - sphereRadius * sphereRadius;

    // discriminant
    edk::float32 d=b*b-4.f*a*c;

    if (d<0){
        return ret;
    }

    if(!a)a=0.0001f;

    edk::float32 t1 =(-b-edk::Math::squareRoot(d))/(2.0*a);

    edk::vec3f32 solution1(lineStart.x*(1-t1)+t1*lineEnd.x,
                           lineStart.y*(1-t1)+t1*lineEnd.y,
                           lineStart.z*(1-t1)+t1*lineEnd.z);
    if (d==0.f){
        ret.pushBack(solution1);
        return ret;
    }

    edk::float32 t2=(-b+edk::Math::squareRoot(d))/(2.0*a);
    edk::vec3f32 solution2(lineStart.x*(1-t2)+t2*lineEnd.x,
                           lineStart.y*(1-t2)+t2*lineEnd.y,
                           lineStart.z*(1-t2)+t2*lineEnd.z);

    // prefer a solution that's on the line segment itself

    if(edk::Math::module(t1-0.5f)<edk::Math::module(t2-0.5f)){
        ret.pushBack(solution1);
        ret.pushBack(solution2);
        return ret;
    }

    ret.pushBack(solution2);
    ret.pushBack(solution1);

    //return the ret
    return ret;
}

bool edk::collision::MathCollision::straightTriangle3D(edk::vec3f32 lineStart,edk::vec3f32 lineEnd,
                                                       edk::vec3f32 triangle1,edk::vec3f32 triangle2,edk::vec3f32 triangle3,
                                                       edk::vec3f32* result){
    //stark to be returned
    edk::collision::Vecs3f32 ret(1u);

    edk::vec3f32 e1,e2,h,s,q;
    edk::float32 a,f,u,v;
    edk::float32 t;
    e1=triangle2-triangle1;
    e2=triangle3-triangle1;

    h = edk::Math::crossProduct(lineEnd,e2);

    a = edk::Math::dotProduct(e1,h);

    if (a > -0.00001 && a < 0.00001)
        return false;

    f = 1.f/a;
    s=lineStart-triangle1;
    u = f * edk::Math::dotProduct(s,h);

    if (u < 0.0 || u > 1.0)
        return false;

    q = edk::Math::crossProduct(s,e1);

    v = f * edk::Math::dotProduct(lineEnd,q);

    if (v < 0.0 || u + v > 1.0)
        return false;

    // at this stage we can compute t to find out where
    // the intersection point is on the line
    t = f * edk::Math::dotProduct(e2,q);

    if (t > -0.00001f && t<1.00001){ // ray intersection
        if(result){
            result->x = lineStart.x + (lineEnd.x * t);
            result->y = lineStart.y + (lineEnd.y * t);
            result->z = lineStart.z + (lineEnd.z * t);
        }
        return true;
    }

    // this means that there is a line intersection
    // but not a ray intersection

    return false;
}

//POLYGON POINT
bool edk::collision::MathCollision::polygonPoint(edk::shape::Polygon2D polygon, edk::vec2f32 point){
    //test if the point is inside the polygon
    for(edk::uint32 i=0u;i<polygon.getVertexCount();i++){
        //test what line of the polygon is test
        if(i==(polygon.getVertexCount()-1u)){
            //if this is the last line. Test if the point is inside
            if(edk::Math::getAngleDistance(polygon.getVertexPosition(i) - polygon.getVertexPosition(0u)
                                           ,point - polygon.getVertexPosition(0u)
                                           )
                    ){
                //set cant delete the polygon
                polygon.cantDeletePolygon();
                //if the point is inside the polygon. Return true
                return true;
            }
        }
        else{
            //test if the point is outside the line
            if(edk::Math::getAngleDistance(polygon.getVertexPosition(i+1u) - polygon.getVertexPosition(i)
                                           ,point - polygon.getVertexPosition(i)
                                           )
                    <=0.f){
                //if the point is outside the polygon. Return false
                break;
            }
        }
    }
    //set cant delete the polygon
    polygon.cantDeletePolygon();
    //else return false
    return false;
}
