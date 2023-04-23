#include "PhysicsMesh2D.h"

/*
Library PhysicMesh - Mesh for box2D in EDK
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

edk::physics2D::PhysicsMesh2D::PhysicsMesh2D()
{
}

//convert a polygon to a convexHull polygons to use in Box2D
edk::uint32 edk::physics2D::PhysicsMesh2D::addPolygon(edk::shape::Polygon2D polygon){
    edk::int32 ret=0u;

    //test if is line
    if(polygon.isLine()){
        ret = edk::shape::Polygon2DList::addPolygon(polygon);edkEnd();
    }
    else{

        //Test the polygon
        if(polygon.isCircle()){
            //its a rect
            ret = edk::shape::Polygon2DList::addPolygon(polygon);edkEnd();
        }
        else if(polygon.getVertexCount()==2u){
            //its a rectangle
            edk::shape::Rectangle2D rect;edkEnd();
            edk::vec2f32 vec0;
            edk::vec2f32 vec1;edkEnd();
            //test the vertex
            if(polygon.getVertexPosition(0u).x>polygon.getVertexPosition(1u).x){
                vec0.x = polygon.getVertexPosition(0u).x;edkEnd();
                vec1.x = polygon.getVertexPosition(1u).x;edkEnd();
            }
            else{
                vec0.x = polygon.getVertexPosition(1u).x;edkEnd();
                vec1.x = polygon.getVertexPosition(0u).x;edkEnd();
            }
            if(polygon.getVertexPosition(0u).y>polygon.getVertexPosition(1u).y){
                vec0.y = polygon.getVertexPosition(0u).y;edkEnd();
                vec1.y = polygon.getVertexPosition(1u).y;edkEnd();
            }
            else{
                vec0.y = polygon.getVertexPosition(1u).y;edkEnd();
                vec1.y = polygon.getVertexPosition(0u).y;edkEnd();
            }
            rect.setVertexPosition(0u,vec0);edkEnd();
            rect.setVertexPosition(1u,vec1);edkEnd();
            //set the color
            rect.setVertexColor(0u,polygon.getVertexColor(0u));edkEnd();
            rect.setVertexColor(1u,polygon.getVertexColor(1u));edkEnd();
            //set rect
            rect.setScale(polygon.getScale());edkEnd();
            rect.setTranslate(polygon.getTranslate());edkEnd();
            rect.setAngle(polygon.getAngle());edkEnd();
            //set physics
            rect.setDensity(polygon.getDensity());edkEnd();
            rect.setFriction(polygon.getFriction());edkEnd();
            rect.setRestitution(polygon.getRestitution());edkEnd();
            //add the rect
            ret = edk::shape::Polygon2DList::addPolygon(rect);edkEnd();
        }
        else{

            //temporary polygons
            edk::shape::Polygon2D p2;edkEnd();
            //p2 = polygon;edkEnd();
            p2.cloneFrom(&polygon);edkEnd();

            //salva o menor vertice
            edk::physics2D::vec3f32Color4f32 temp;edkEnd();
            edk::physics2D::vec3f32Color4f32 menor;edkEnd();
            if(polygon.getVertexCount()){
                temp = polygon.getVertexPosition(0u);edkEnd();
                temp = polygon.getVertexColor(0u);edkEnd();
                menor=temp;edkEnd();
                for(edk::uint32 i=1u;i<polygon.getVertexCount();i++){
                    //
                    temp = polygon.getVertexPosition(i);edkEnd();
                    temp = polygon.getVertexColor(i);edkEnd();
                    if(temp.position.y < menor.position.y){
                        menor=temp;edkEnd();
                    }
                    else if(temp.position.y==menor.position.y
                            &&
                            temp.position.x < menor.position.x
                            ){
                        menor=temp;edkEnd();
                    }
                }
                //cria a arvore de vertices ordenada por angulo
                edk::physics2D::PhysicsMesh2D::ConvexTree tree;edkEnd();
                for(edk::uint32 i=0u;i<polygon.getVertexCount();i++){
                    temp = polygon.getVertexPosition(i);edkEnd();
                    temp = polygon.getVertexColor(i);edkEnd();
                    if(temp.position.x!=menor.position.x
                            ||
                            temp.position.y != menor.position.y
                            ){
                        //
                        edk::physics2D::vec3f32Color4f32 *vert = new edk::physics2D::vec3f32Color4f32;edkEnd();
                        if(vert){
                            vert->position.x = temp.position.x;edkEnd();
                            vert->position.y = temp.position.y;edkEnd();
                            vert->position.z = edk::Math::getAngle(temp.position.x-menor.position.x,temp.position.y-menor.position.y);edkEnd();
                            vert->color = temp.color;edkEnd();
                            //adiciona o vert
                            if(!tree.add(vert)){
                                //
                                delete vert;edkEnd();
                            }
                        }
                        vert=NULL;edkEnd();
                    }
                }
                if(tree.size()){
                    edk::physics2D::vec3f32Color4f32 *test = tree.getElementInPosition(0u);edkEnd();
                    edk::physics2D::vec3f32Color4f32 sub = menor;edkEnd();
                    for(edk::uint32 i=1u;i<tree.size();i++){
                        edk::physics2D::vec3f32Color4f32 *next = tree.getElementInPosition(i);edkEnd();
                        if(next){
                            if(edk::Math::getAngleDistance(edk::vec2f32(next->position.x - sub.position.x,next->position.y - sub.position.y),
                                                    edk::vec2f32(test->position.x - sub.position.x,test->position.y - sub.position.y)
                                                    )>=0.f
                                    ){
                                //
                                tree.remove(test);edkEnd();
                                delete test;edkEnd();
                                i--;edkEnd();
                            }
                            test = tree.getElementInPosition(i);edkEnd();

                            if(i){
                                edk::physics2D::vec3f32Color4f32 *temp = tree.getElementInPosition(i-1u);edkEnd();
                                if(temp){
                                    sub.position.x = temp->position.x;edkEnd();
                                    sub.position.y = temp->position.y;edkEnd();
                                    sub.color = temp->color;edkEnd();
                                }
                            }
                            else{
                                sub = menor;edkEnd();
                            }
                        }
                    }


                    //test if the tree have vertices
                    if(tree.size()){
                        edk::uint32 maxPolyCount = 6u;edkEnd();
                        edk::uint32 count = 0u;edkEnd();
                        while(tree.size()>8u){
                            //
                            p2.createPolygon(maxPolyCount+2u);edkEnd();
                            //set the first vertex
                            p2.setVertexPosition(0u,menor.position.x,menor.position.y);edkEnd();
                            p2.setVertexColor(0u,menor.color);edkEnd();
                            for(edk::uint32 i=0u;i<=maxPolyCount;i++){
                                //
                                edk::physics2D::vec3f32Color4f32 *vert = tree.getElementInPosition(count);edkEnd();
                                if(vert){

                                    //set the vertex
                                    p2.setVertexPosition(i+1u,vert->position.x,vert->position.y);edkEnd();
                                    p2.setVertexColor(i+1u,vert->color);edkEnd();


                                    if(i<maxPolyCount){
                                        tree.remove(vert);edkEnd();
                                        //deleta o vert
                                        delete vert;edkEnd();
                                    }
                                }
                            }
                            ret = edk::shape::Polygon2DList::addPolygon(p2);edkEnd();
                        }
                        if(tree.size()){
                            //
                            p2.createPolygon(tree.size()+1u);edkEnd();
                            //set the first vertex
                            p2.setVertexPosition(0u,menor.position.x,menor.position.y);edkEnd();
                            p2.setVertexColor(0u,menor.color);edkEnd();
                            for(edk::uint32 i=0u;i<tree.size();i++){
                                edk::physics2D::vec3f32Color4f32 *vert = tree.getElementInPosition(i);edkEnd();
                                if(vert){

                                    //set the vertex
                                    p2.setVertexPosition(i+1u,vert->position.x,vert->position.y);edkEnd();
                                    p2.setVertexColor(i+1u,vert->color);edkEnd();
                                    //deleta o vert
                                    delete vert;edkEnd();
                                }
                            }
                            ret = edk::shape::Polygon2DList::addPolygon(p2);edkEnd();
                        }
                    }
                    tree.clean();edkEnd();
                }
            }
        }
    }
    //remove the delete from the polygon. This dont delete polygon in the next destrutor
    polygon.cantDeletePolygon();edkEnd();
    return ret;
}
