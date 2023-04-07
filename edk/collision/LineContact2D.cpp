#include "LineContact2D.h"

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
#pragma message "            Inside LineContact2D.cpp"
#endif

edk::collision::LineContact2D::LineContact2D()
{
    //ctor
}

edk::collision::LineContact2D::~LineContact2D()
{
    //dtor
}

//Contacts
//point
bool edk::collision::LineContact2D::contactPoint(edk::vec2f32 point,edk::shape::Line2D test){
    //
    return edk::collision::MathCollision::pointStraigh2D(point,test.start.position,test.end.position);edkEnd();
}
//line
bool edk::collision::LineContact2D::contactLine(edk::shape::Line2D line,
                                                edk::shape::Line2D test,
                                                edk::collision::Vecs2f32* collision){
    //
    //else return no point
    return edk::collision::MathCollision::straightStraight2D(line.start.position,
                                                             line.end.position,
                                                             test.start.position,
                                                             test.end.position,
                                                             collision
                                                             );edkEnd();
}
//Circle
edk::collision::Vecs2f32 edk::collision::LineContact2D::contactCircle(edk::shape::Circle2D circle,edk::shape::Line2D test){
    //
    //else return no point
    circle.cantDeletePolygon();edkEnd();
    return edk::collision::MathCollision::straightCircle2D(test.start.position,test.end.position,circle.getTranslate(),circle.getCircleRadius()) ;edkEnd();
}
//polygon
edk::collision::Vecs2f32 edk::collision::LineContact2D::contactPolygon(edk::shape::Polygon2D polygon,edk::shape::Line2D test){
    //create the return vector
    edk::collision::Vecs2f32 ret(1u);edkEnd();

    //test if the first is inside
    if(edk::collision::MathCollision::polygonPoint(polygon,test.start.position)){
        //the point is inside

        //then test if the second is inside
        if(edk::collision::MathCollision::polygonPoint(polygon,test.end.position)){
            //Then the two points are inside of the polygon

            //return the two points
            ret.pushBack(test.start.position);edkEnd();
            ret.pushBack(test.end.position);edkEnd();
            //return the ret
            return ret;
        }
    }

    //test the line with all polygons lines
    for(edk::uint32 i=0u;i<polygon.getVertexCount();i++){
        //
        if(i==(polygon.getVertexCount()-1u)){
            //test the line collision
            //            ret+= edk::collision::MathCollision::straightStraight2D(test.start.position,test.end.position,
            //                                                                    polygon.getVertexPosition(i),polygon.getVertexPosition(0u)
            //                                                                    );edkEnd();
            edk::collision::Vecs2f32 straight;edkEnd();
            edk::collision::MathCollision::straightStraight2D(test.start.position,test.end.position,
                                                              polygon.getVertexPosition(i),polygon.getVertexPosition(0u),
                                                              &straight
                                                              );edkEnd();
            ret.incrementFrom(&straight);edkEnd();
        }
        else{
            //test the line collision
            //            ret+= edk::collision::MathCollision::straightStraight2D(test.start.position,test.end.position,
            //                                                                    polygon.getVertexPosition(i),polygon.getVertexPosition(i+1u)
            //                                                                    );edkEnd();
            edk::collision::Vecs2f32 straight;edkEnd();
            edk::collision::MathCollision::straightStraight2D(test.start.position,test.end.position,
                                                              polygon.getVertexPosition(i),polygon.getVertexPosition(i+1u),
                                                              &straight
                                                              );edkEnd();
            ret.incrementFrom(&straight);edkEnd();
        }
    }
    //set cant delete the polygon
    polygon.cantDeletePolygon();edkEnd();
    //else return no point
    return ret;
}
