#include "LineContact2D.h"

/*
Library LineCollider2D - Teste collision between a line and other types
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "            Inside LineContact2D.cpp"
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
    return edk::collision::MathCollision::pointStraigh2D(point,test.start.position,test.end.position);
}
//line
edk::collision::Vecs2f32 edk::collision::LineContact2D::contactLine(edk::shape::Line2D line,edk::shape::Line2D test){
    //
    //else return no point
    return edk::collision::MathCollision::straightStraight2D(line.start.position,line.end.position,test.start.position,test.end.position);
}
//Circle
edk::collision::Vecs2f32 edk::collision::LineContact2D::contactCircle(edk::shape::Circle2D circle,edk::shape::Line2D test){
    //
    //else return no point
    circle.cantDeletePolygon();
    return edk::collision::MathCollision::straightCircle2D(test.start.position,test.end.position,circle.getTranslate(),circle.getCircleRadius()) ;
}
//polygon
edk::collision::Vecs2f32 edk::collision::LineContact2D::contactPolygon(edk::shape::Polygon2D polygon,edk::shape::Line2D test){
    //create the return vector
    edk::collision::Vecs2f32 ret(1u);

    //test if the first is inside
    if(edk::collision::MathCollision::polygonPoint(polygon,test.start.position)){
        //the point is inside

        //then test if the second is inside
        if(edk::collision::MathCollision::polygonPoint(polygon,test.end.position)){
            //Then the two points are inside of the polygon

            //return the two points
            ret.pushBack(test.start.position);
            ret.pushBack(test.end.position);
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
//                                                                    );
            edk::collision::Vecs2f32 straight = edk::collision::MathCollision::straightStraight2D(test.start.position,test.end.position,
                                                                                                  polygon.getVertexPosition(i),polygon.getVertexPosition(0u)
                                                                                                  );
            ret.incrementFrom(&straight);
        }
        else{
            //test the line collision
//            ret+= edk::collision::MathCollision::straightStraight2D(test.start.position,test.end.position,
//                                                                    polygon.getVertexPosition(i),polygon.getVertexPosition(i+1u)
//                                                                    );
            edk::collision::Vecs2f32 straight = edk::collision::MathCollision::straightStraight2D(test.start.position,test.end.position,
                                                                    polygon.getVertexPosition(i),polygon.getVertexPosition(i+1u)
                                                                    );
            ret.incrementFrom(&straight);
        }
    }
    //set cant delete the polygon
    polygon.cantDeletePolygon();
    //else return no point
    return ret;
}
