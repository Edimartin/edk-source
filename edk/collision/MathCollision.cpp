#include "MathCollision.h"

/*
Library MathCollision - Math functions to test collisions
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
#warning "            Inside MathCollision.cpp"
#endif

edk::collision::MathCollision::MathCollision()
{
    //ctor
}

edk::collision::MathCollision::~MathCollision()
{
    //dtor
}

/*

bool edk::math::boundingContact2D(edk::float32 pontoX,edk::float32 pontoY,edk::float32 pontoZ,
                                  edk::float32 X1,edk::float32 Y1,edk::float32 Z1,
                                  edk::float32 X2,edk::float32 Y2,edk::float32 Z2
                                  ){

*/
bool edk::collision::MathCollision::boundingContact3D(edk::vec3f32 point,edk::vec3f32 vec1,edk::vec3f32 vec2){
    //
    edk::float32 xMe,yMe,zMe;
    edk::float32 xMa,yMa,zMa;

    if(vec1.x>vec2.x){
        //
        xMa=vec1.x;
        xMe=vec2.x;
    }
    else{
        //
        xMa=vec2.x;
        xMe=vec1.x;
    }

    if(vec1.y>vec2.y){
        //
        yMa=vec1.y;
        yMe=vec2.y;
    }
    else{
        //
        yMa=vec2.y;
        yMe=vec1.y;
    }

    if(vec1.z>vec2.z){
        //
        zMa=vec1.z;
        zMe=vec2.z;
    }
    else{
        //
        zMa=vec2.z;
        zMe=vec1.z;
    }

    //Entao ele calcula se o ponto esta dentro ou fora
    if(point.x <= xMa && point.x>= xMe){
        if(point.y <= yMa && point.y>= yMe){
            if(point.z <= zMa && point.z>= zMe){
                //
                return true;
            }
        }
    }
    return false;
}
bool edk::collision::MathCollision::boundingContact2D(edk::vec2f32 point,edk::vec2f32 vec1,edk::vec2f32 vec2){
    //
    edk::float32 xMe,yMe/*,zMe*/;
    edk::float32 xMa,yMa/*,zMa*/;

    if(vec1.x>vec2.x){
        //
        xMa=vec1.x;
        xMe=vec2.x;
    }
    else{
        //
        xMa=vec2.x;
        xMe=vec1.x;
    }

    if(vec1.y>vec2.y){
        //
        yMa=vec1.y;
        yMe=vec2.y;
    }
    else{
        //
        yMa=vec2.y;
        yMe=vec1.y;
    }

    //Entao ele calcula se o ponto esta dentro ou fora
    if(point.x <= xMa && point.x>= xMe){
        if(point.y <= yMa && point.y>= yMe){
            //
            return true;
        }
    }
    return false;
}

//POINT STRAIGHT
bool edk::collision::MathCollision::pointStraigh2D(edk::vec2f32 point,vec2f32 lineStart,vec2f32 lineEnd, edk::float32 radius){
    //
    edk::float32 value = (point.x*lineStart.y)+
            (point.y*lineEnd.x)+
            (lineStart.x*lineEnd.y)-
            (lineEnd.x*lineStart.y)-
            (lineEnd.y*point.x)-
            (lineStart.x*point.y);
    //0==(pontoX*Y1)           +(pontoY*X2)        +(X1*Y2)                -(X2*Y1)                -(Y2*pontoX)        -(X1*pontoY))
    if(value<radius && value>-radius)
        //Entao ele retorna true
        return true;
    //else return zero
    return false;
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

        if(det!=0.0){
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
    }
    //else return a zero vector
    return ret;
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

    if(det!=0.0){
        //
        //s =  ((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/ det ;
        temp.x=((line2End.x - line2Start.x) * (line2Start.y - line1Start.y) - (line2End.y - line2Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;
        //t =  ((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/ det ;
        temp.y=((line1End.x - line1Start.x) * (line2Start.y - line1Start.y) - (line1End.y - line1Start.y) * (line2Start.x - line1Start.x))/(edk::float32)det;
        if( temp.x>=0.f && temp.y<=1.f && temp.y>=0.f && temp.y<=1.f){
            //
            return true;
        }
    }
    return false;
}
/*

edk::uint32 edk::math::straighSphere(edk::float32 X1,edk::float32 Y1,edk::float32 Z1,
                                      edk::float32 X2,edk::float32 Y2,edk::float32 Z2,
                                      edk::float32 EX,edk::float32 EY,edk::float32 EZ,
                                      edk::float32 raio
                                      ){

*/
edk::collision::Vecs2f32 edk::collision::MathCollision::straightCircle2D(edk::vec2f32 lineStart,edk::vec2f32 lineEnd,
                                                                         edk::vec2f32 circlePosition,edk::float32 circleRadius){
    //
    edk::collision::Vecs2f32 ret(2u);

    //
    edk::float32 a, b, c, mu, i ;
    //vectors
    edk::vec2f32 v1,v2;

    a =  squareFloat32(lineEnd.x - lineStart.x) + squareFloat32(lineEnd.y - lineStart.y)/* + squareFloat32(lineEnd.z - lineStart.z)*/;
    b =  2.0* ( (lineEnd.x - lineStart.x)*(lineStart.x - circlePosition.x)
                + (lineEnd.y - lineStart.y)*(lineStart.y - circlePosition.y)
                //+ (lineEnd.z - lineStart.z)*(lineStart.z - circlePosition.z)
                ) ;
    c =  squareFloat32(circlePosition.x) + squareFloat32(circlePosition.y) +
            //squareFloat32(circlePosition.z) +
            squareFloat32(lineStart.x) +
            squareFloat32(lineStart.y)
            //+ squareFloat32(lineStart.z)
            - 2* ( circlePosition.x*lineStart.x + circlePosition.y*lineStart.y /* + circlePosition.z*lineStart.z */ ) - squareFloat32(circleRadius) ;
    i =   b * b - 4 * a * c ;

    if ( i == 0.0f ){
        // one intersection

        mu = -b/(2*a) ;
        v1.x = lineStart.x + mu*(lineEnd.x-lineStart.x);
        v1.y = lineStart.y + mu*(lineEnd.y-lineStart.y);
        //v1.z = lineStart.z + mu*(lineEnd.z-lineStart.z);
        //return 1 point

        //test colision with line boundingBox
        if(boundingContact2D(v1,lineStart,lineEnd)){
            //
            //add the v1 to return
            ret.pushBack(v1);
        }
    }
    if ( i > 0.0f ){
        // two intersections

        // first intersection
        mu = (-b + sqrt( squareFloat32(b) - 4*a*c )) / (2*a);
        v1.x = lineStart.x + mu*(lineEnd.x-lineStart.x);
        v1.y = lineStart.y + mu*(lineEnd.y-lineStart.y);
        //v1.z = lineStart.z + mu*(lineEnd.z-lineStart.z);
        // second intersection
        mu = (-b - sqrt(squareFloat32(b) - 4*a*c )) / (2*a);
        v2.x = lineStart.x + mu*(lineEnd.x-lineStart.x);
        v2.y = lineStart.y + mu*(lineEnd.y-lineStart.y);
        //v2.z = lineStart.x + mu*(lineEnd.z-lineStart.x);
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
/*
edk::collision::Vecs3f32 edk::collision::MathCollision::straightSphere3D(edk::vec3f32 lineStart,edk::vec3f32 lineEnd,
                                                                         edk::vec3f32 circlePosition,edk::float32 circleRadius){
    //
    edk::collision::Vecs2f32 ret(2u);

    //
    edk::float32 a, b, c, mu, i ;
    //vectors
    edk::vec3f32 v1,v2;

    a =  squareFloat32(lineEnd.x - lineStart.x) + squareFloat32(lineEnd.y - lineStart.y) + squareFloat32(lineEnd.z - lineStart.z);
    b =  2* ( (lineEnd.x - lineStart.x)*(lineStart.x - circlePosition.x)
             + (lineEnd.y - lineStart.y)*(lineStart.y - circlePosition.y)
             + (lineEnd.z - lineStart.z)*(lineStart.z - circlePosition.z)
             ) ;
    c =  squareFloat32(circlePosition.x) + squareFloat32(circlePosition.y) +
    squareFloat32(circlePosition.z) +
    squareFloat32(lineStart.x) +
    squareFloat32(lineStart.y)
    + squareFloat32(lineStart.z)
    - 2* ( circlePosition.x*lineStart.x + circlePosition.y*lineStart.y  + circlePosition.z*lineStart.z  ) - squareFloat32(circleRadius) ;
    i =   b * b - 4 * a * c ;

    if ( i == 0.0f ){
        // one intersection

        mu = -b/(2*a) ;
        v1.x = lineStart.x + mu*(lineEnd.x-lineStart.x);
        v1.y = lineStart.y + mu*(lineEnd.y-lineStart.y);
        v1.z = lineStart.z + mu*(lineEnd.z-lineStart.z);
        //return 1 point

        //test colision with line boundingBox
        if(boundingContact3D(v1,lineStart,lineEnd)){
            //
            //add the v1 to return
            ret.pushBack(v1);
        }
    }
    if ( i > 0.0f ){
    // two intersections

        // first intersection
        mu = (-b + sqrt( squareFloat32(b) - 4*a*c )) / (2*a);
        v1.x = lineStart.x + mu*(lineEnd.x-lineStart.x);
        v1.y = lineStart.y + mu*(lineEnd.y-lineStart.y);
        v1.z = lineStart.z + mu*(lineEnd.z-lineStart.z);
        // second intersection
        mu = (-b - sqrt(squareFloat32(b) - 4*a*c )) / (2*a);
        v2.x = lineStart.x + mu*(lineEnd.x-lineStart.x);
        v2.y = lineStart.y + mu*(lineEnd.y-lineStart.y);
        v2.z = lineStart.x + mu*(lineEnd.z-lineStart.x);
        //return 2 points
        if(boundingContact3D(v1,lineStart,lineEnd)){
            if(boundingContact3D(v2,lineStart,lineEnd)){
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
        if(boundingContact3D(v2,lineStart,lineEnd)){
            //add just the second point
            ret.pushBack(v2);
            }
        }
    }

    //return the ret
    return ret;
    //
}
*/

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
