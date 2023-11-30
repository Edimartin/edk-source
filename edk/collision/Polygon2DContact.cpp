#include "Polygon2DContact.h"

/*
Library Polygon2DContact - Teste collision between polygons in EDK
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
#pragma message "            Inside Polygon2DContact.cpp"
#endif


edk::collision::Polygon2DContact::Polygon2DContact(){
    //
}
edk::collision::Polygon2DContact::~Polygon2DContact(){
    //
}
//calculate the vertexes
bool edk::collision::Polygon2DContact::pointsCalculateFromPolygons(edk::shape::Polygon2D* polyA,
                                                                   edk::shape::Polygon2D* polyB,
                                                                   edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* aOutside,
                                                                   edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* aInside,
                                                                   edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* bOutside,
                                                                   edk::vector::Stack<edk::shape::Vertex2DAnimatedUV>* bInside,
                                                                   edk::vector::Stack<edk::collision::Polygon2DContact::ContactVertex>* newVertexesA,
                                                                   edk::vector::Stack<edk::collision::Polygon2DContact::ContactVertex>* newVertexesB
                                                                   ){
    //test if have the polygons and stacks
    if(polyA
            && polyB
            && aOutside
            && aInside
            && bOutside
            && bInside
            && newVertexesA
            && newVertexesB
            ){
        bool ret=false;edkEnd();
        //calculate if the lines internect creating new vertexes
        edk::uint32 sizeA = polyA->getVertexCount();edkEnd();
        edk::uint32 sizeB = polyB->getVertexCount();edkEnd();
        edk::collision::Vecs2f32 vecs;edkEnd();
        edk::collision::Polygon2DContact::ContactVertex vA,vB;edkEnd();
        edk::vec2f32 vec;edkEnd();
        edk::float32 percentA,percentB;edkEnd();
        edk::vec2f32 aStart,aEnd;edkEnd();
        edk::vec2f32 bStart,bEnd;edkEnd();
        edk::shape::Vertex2DAnimatedUV v;edkEnd();
        //type of the vertex
        //EDK_SHAPE_ANIMATED_UV
        //EDK_SHAPE_UV
        //EDK_SHAPE_NOUV
        for(edk::uint32 i=1u;i<sizeA;i++){
            for(edk::uint32 j=1u;j<sizeB;j++){
                aStart = polyA->getVertexPosition(i-1u);edkEnd();
                aEnd = polyA->getVertexPosition(i);edkEnd();
                bStart = polyB->getVertexPosition(i-1u);edkEnd();
                bEnd = polyB->getVertexPosition(i);edkEnd();
                if(edk::collision::MathCollision::straightStraight2D(aStart,
                                                                     aEnd,
                                                                     bStart,
                                                                     bEnd,
                                                                     &vecs
                                                                     )){
                    ret=true;edkEnd();
                    vec = vecs[0u];edkEnd();
                    //set the positions
                    vA.vec.position = vB.vec.position = vec;edkEnd();

                    //calculate the percent
                    percentA = edk::Math::pythagoras(vec - aStart)/edk::Math::pythagoras(aEnd - aStart);edkEnd();
                    percentB = edk::Math::pythagoras(vec - bStart)/edk::Math::pythagoras(bEnd - bStart);edkEnd();

                    //set the vA
                    vA.vec.color = (((polyA->getVertexColor(i)-polyA->getVertexColor(i-1u))*percentA)+polyA->getVertexColor(i-1u));edkEnd();
                    if(polyA->getVertexType(i-1u) == polyA->getVertexType(i)){
                        switch(polyA->getVertexType(i)){
                        case EDK_SHAPE_ANIMATED_UV:
                            vA.vec.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percentA)+polyA->getVertexUV(i-1u));edkEnd();
                            vA.vec.setUVFrames(polyA->getFrames());edkEnd();
                            //set the vA
                            break;
                        case EDK_SHAPE_UV:
                            vA.vec.setUV(((polyA->getVertexUV(i)-polyA->getVertexUV(i-1u))*percentA)+polyA->getVertexUV(i-1u));edkEnd();
                            //set the vA
                            break;
                        }
                    }

                    //set the vB color
                    vB.vec.color = (((polyB->getVertexColor(i)-polyB->getVertexColor(i-1u))*percentB)+polyB->getVertexColor(i-1u));edkEnd();
                    if(polyB->getVertexType(i-1u) == polyB->getVertexType(i)){
                        switch(polyB->getVertexType(i)){
                        case EDK_SHAPE_ANIMATED_UV:
                            vB.vec.setUV(((polyB->getVertexUV(i)-polyB->getVertexUV(i-1u))*percentB)+polyB->getVertexUV(i-1u));edkEnd();
                            vB.vec.setUVFrames(polyB->getFrames());edkEnd();
                            //set the vB uv
                            break;
                        case EDK_SHAPE_UV:
                            vB.vec.setUV(((polyB->getVertexUV(i)-polyB->getVertexUV(i-1u))*percentB)+polyB->getVertexUV(i-1u));edkEnd();
                            //set the vB uv
                            break;
                        }
                    }

                    //copy the new vertex
                    newVertexesA->pushBack(vA);edkEnd();
                    newVertexesB->pushBack(vB);edkEnd();

                }
                vecs.clean();edkEnd();
            }
        }
        //test vertexes inside outside
        for(edk::uint32 i=0u;i<sizeA;i++){
            if(edk::collision::MathCollision::polygonPoint(*polyB,polyA->getVertexPosition(i))){
                //inside
                v.position = polyA->getVertexPosition(i);edkEnd();
                v.color = polyA->getVertexColor(i);edkEnd();
                v.setUV(polyA->getVertexUV(i));edkEnd();
                v.setUVFrames(polyA->getFrames());edkEnd();
                aInside->pushBack(v);edkEnd();
            }
            else{
                //outside
                v.position = polyA->getVertexPosition(i);edkEnd();
                v.color = polyA->getVertexColor(i);edkEnd();
                v.setUV(polyA->getVertexUV(i));edkEnd();
                v.setUVFrames(polyA->getFrames());edkEnd();
                aOutside->pushBack(v);edkEnd();
            }
        }
        for(edk::uint32 i=0u;i<sizeB;i++){
            if(edk::collision::MathCollision::polygonPoint(*polyA,polyB->getVertexPosition(i))){
                //inside
                v.position = polyB->getVertexPosition(i);edkEnd();
                v.color = polyB->getVertexColor(i);edkEnd();
                v.setUV(polyB->getVertexUV(i));edkEnd();
                v.setUVFrames(polyB->getFrames());edkEnd();
                bInside->pushBack(v);edkEnd();
            }
            else{
                //outside
                v.position = polyB->getVertexPosition(i);edkEnd();
                v.color = polyB->getVertexColor(i);edkEnd();
                v.setUV(polyB->getVertexUV(i));edkEnd();
                v.setUVFrames(polyB->getFrames());edkEnd();
                bOutside->pushBack(v);edkEnd();
            }
        }
        return ret;
    }
    return false;
}

//boolean with two polygons
bool edk::collision::Polygon2DContact::booleanAnotB(edk::shape::Polygon2D* polyA,edk::shape::Polygon2D* polyB,edk::shape::Polygon2D* polyDest){
    if(polyA && polyB && polyDest){
        edk::vector::Stack<edk::shape::Vertex2DAnimatedUV> aOutside;
        edk::vector::Stack<edk::shape::Vertex2DAnimatedUV> aInside;
        edk::vector::Stack<edk::shape::Vertex2DAnimatedUV> bOutside;
        edk::vector::Stack<edk::shape::Vertex2DAnimatedUV> bInside;
        edk::vector::Stack<edk::collision::Polygon2DContact::ContactVertex> newVertexesA;
        edk::vector::Stack<edk::collision::Polygon2DContact::ContactVertex> newVertexesB;
        bool ret = false;
        //test if the polygon have 2 vertexes
        if(polyA->getVertexCount() <= 2u){
            if(polyA->isRect()){
                if(polyB->getVertexCount() <= 2u){
                    if(polyB->isRect()){
                        edk::shape::Polygon2D newPolyA;
                        edk::shape::Polygon2D newPolyB;
                        if(newPolyA.createPolygon(4u) && newPolyB.createPolygon(4u)){
                            newPolyA.setVertexPosition(0u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(0u).y);
                            newPolyA.setVertexPosition(1u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(0u).y);
                            newPolyA.setVertexPosition(2u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(1u).y);
                            newPolyA.setVertexPosition(3u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(1u).y);
                            newPolyA.setVertexColor(0u,polyA->getVertexColor(0u));
                            newPolyA.setVertexColor(1u,polyA->getVertexColor(0u));
                            newPolyA.setVertexColor(2u,polyA->getVertexColor(1u));
                            newPolyA.setVertexColor(3u,polyA->getVertexColor(1u));
                            if(polyA->getVertexType(0u) == EDK_SHAPE_UV
                                    && polyA->getVertexType(1u) == EDK_SHAPE_UV
                                    ){
                                newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                                newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                            }
                            else if(polyA->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                    && polyA->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                    ){
                                newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                                newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                                newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                                newPolyA.setPolygonUVFrames(polyA->getFrames());
                            }
                            newPolyB.setVertexPosition(0u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(0u).y);
                            newPolyB.setVertexPosition(1u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(0u).y);
                            newPolyB.setVertexPosition(2u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(1u).y);
                            newPolyB.setVertexPosition(3u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(1u).y);
                            newPolyB.setVertexColor(0u,polyB->getVertexColor(0u));
                            newPolyB.setVertexColor(1u,polyB->getVertexColor(0u));
                            newPolyB.setVertexColor(2u,polyB->getVertexColor(1u));
                            newPolyB.setVertexColor(3u,polyB->getVertexColor(1u));
                            if(polyB->getVertexType(0u) == EDK_SHAPE_UV
                                    && polyB->getVertexType(1u) == EDK_SHAPE_UV
                                    ){
                                newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                                newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                            }
                            else if(polyB->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                    && polyB->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                    ){
                                newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                                newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                                newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                                newPolyB.setPolygonUVFrames(polyB->getFrames());
                            }
                            ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygons(&newPolyA,
                                                                                                &newPolyB,
                                                                                                &aOutside,
                                                                                                &aInside,
                                                                                                &bOutside,
                                                                                                &bInside,
                                                                                                &newVertexesA,
                                                                                                &newVertexesB
                                                                                                );
                        }
                    }
                }
                else{
                    edk::shape::Polygon2D newPolyA;
                    if(newPolyA.createPolygon(4u)){
                        newPolyA.setVertexPosition(0u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(0u).y);
                        newPolyA.setVertexPosition(1u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(0u).y);
                        newPolyA.setVertexPosition(2u,polyA->getVertexPosition(1u).x,polyA->getVertexPosition(1u).y);
                        newPolyA.setVertexPosition(3u,polyA->getVertexPosition(0u).x,polyA->getVertexPosition(1u).y);
                        newPolyA.setVertexColor(0u,polyA->getVertexColor(0u));
                        newPolyA.setVertexColor(1u,polyA->getVertexColor(0u));
                        newPolyA.setVertexColor(2u,polyA->getVertexColor(1u));
                        newPolyA.setVertexColor(3u,polyA->getVertexColor(1u));
                        if(polyA->getVertexType(0u) == EDK_SHAPE_UV
                                && polyA->getVertexType(1u) == EDK_SHAPE_UV
                                ){
                            newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                            newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                        }
                        else if(polyA->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                && polyA->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                ){
                            newPolyA.setVertexUV(0u,polyA->getVertexUV(0u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(1u,polyA->getVertexUV(1u).x,polyA->getVertexUV(0u).y);
                            newPolyA.setVertexUV(2u,polyA->getVertexUV(1u).x,polyA->getVertexUV(1u).y);
                            newPolyA.setVertexUV(3u,polyA->getVertexUV(0u).x,polyA->getVertexUV(1u).y);
                            newPolyA.setPolygonUVFrames(polyA->getFrames());
                        }
                        ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygons(&newPolyA,
                                                                                            polyB,
                                                                                            &aOutside,
                                                                                            &aInside,
                                                                                            &bOutside,
                                                                                            &bInside,
                                                                                            &newVertexesA,
                                                                                            &newVertexesB
                                                                                            );
                    }
                }
            }
        }
        else{
            if(polyB->getVertexCount() <= 2u){if(polyB->isRect()){
                    edk::shape::Polygon2D newPolyB;
                    if(newPolyB.createPolygon(4u)){
                        newPolyB.setVertexPosition(0u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(0u).y);
                        newPolyB.setVertexPosition(1u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(0u).y);
                        newPolyB.setVertexPosition(2u,polyB->getVertexPosition(1u).x,polyB->getVertexPosition(1u).y);
                        newPolyB.setVertexPosition(3u,polyB->getVertexPosition(0u).x,polyB->getVertexPosition(1u).y);
                        newPolyB.setVertexColor(0u,polyB->getVertexColor(0u));
                        newPolyB.setVertexColor(1u,polyB->getVertexColor(0u));
                        newPolyB.setVertexColor(2u,polyB->getVertexColor(1u));
                        newPolyB.setVertexColor(3u,polyB->getVertexColor(1u));
                        if(polyB->getVertexType(0u) == EDK_SHAPE_UV
                                && polyB->getVertexType(1u) == EDK_SHAPE_UV
                                ){
                            newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                            newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                        }
                        else if(polyB->getVertexType(0u) == EDK_SHAPE_ANIMATED_UV
                                && polyB->getVertexType(1u) == EDK_SHAPE_ANIMATED_UV
                                ){
                            newPolyB.setVertexUV(0u,polyB->getVertexUV(0u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(1u,polyB->getVertexUV(1u).x,polyB->getVertexUV(0u).y);
                            newPolyB.setVertexUV(2u,polyB->getVertexUV(1u).x,polyB->getVertexUV(1u).y);
                            newPolyB.setVertexUV(3u,polyB->getVertexUV(0u).x,polyB->getVertexUV(1u).y);
                            newPolyB.setPolygonUVFrames(polyB->getFrames());
                        }
                        ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygons(polyA,
                                                                                            &newPolyB,
                                                                                            &aOutside,
                                                                                            &aInside,
                                                                                            &bOutside,
                                                                                            &bInside,
                                                                                            &newVertexesA,
                                                                                            &newVertexesB
                                                                                            );
                    }
                }
            }
            else{
                ret = edk::collision::Polygon2DContact::pointsCalculateFromPolygons(polyA,
                                                                                    polyB,
                                                                                    &aOutside,
                                                                                    &aInside,
                                                                                    &bOutside,
                                                                                    &bInside,
                                                                                    &newVertexesA,
                                                                                    &newVertexesB
                                                                                    );
            }
        }
        if(ret){
            //
        }
    }
    return false;
}
