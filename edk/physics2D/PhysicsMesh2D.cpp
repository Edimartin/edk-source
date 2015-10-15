#include "PhysicsMesh2D.h"

/*
Library PhysicMesh - Mesh for box2D in EDK
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

edk::physics2D::PhysicsMesh2D::PhysicsMesh2D()
{
}

//convert a polygon to a convexHull polygons to use in Box2D
edk::uint32 edk::physics2D::PhysicsMesh2D::addPolygon(edk::shape::Polygon2D polygon){
    edk::int32 ret=0u;

    //test if is line
    if(polygon.isLine()){
        ret = edk::shape::Polygon2DList::addPolygon(polygon);
    }
    else{

        //Test the polygon
        if(polygon.isCircle()){
            //its a rect
            ret = edk::shape::Polygon2DList::addPolygon(polygon);
        }
        else if(polygon.getVertexCount()==2u){
            //its a rectangle
            edk::shape::Rectangle2D rect;
            edk::vec2f32 vec0;
            edk::vec2f32 vec1;
            //test the vertex
            if(polygon.getVertexPosition(0u).x>polygon.getVertexPosition(1u).x){
                vec0.x = polygon.getVertexPosition(0u).x;
                vec1.x = polygon.getVertexPosition(1u).x;
            }
            else{
                vec0.x = polygon.getVertexPosition(1u).x;
                vec1.x = polygon.getVertexPosition(0u).x;
            }
            if(polygon.getVertexPosition(0u).y>polygon.getVertexPosition(1u).y){
                vec0.y = polygon.getVertexPosition(0u).y;
                vec1.y = polygon.getVertexPosition(1u).y;
            }
            else{
                vec0.y = polygon.getVertexPosition(1u).y;
                vec1.y = polygon.getVertexPosition(0u).y;
            }
            rect.setVertexPosition(0u,vec0);
            rect.setVertexPosition(1u,vec1);
            //set rect
            rect.setScale(polygon.getScale());
            rect.setTranslate(polygon.getTranslate());
            rect.setAngle(polygon.getAngle());
            //set physics
            rect.setDensity(polygon.getDensity());
            rect.setFriction(polygon.getFriction());
            rect.setRestitution(polygon.getRestitution());
            //add the rect
            ret = edk::shape::Polygon2DList::addPolygon(rect);
        }
        else{

            //temporary polygons
            edk::shape::Polygon2D p2;
            p2 = polygon;

            //salva o menor vertice
            edk::vec2f32 temp;
            edk::vec2f32 menor;
            if(polygon.getVertexCount()){
                temp = polygon.getVertexPosition(0u);
                menor=temp;
                for(edk::uint32 i=1u;i<polygon.getVertexCount();i++){
                    //
                    temp = polygon.getVertexPosition(i);
                    if(temp.y < menor.y){
                        menor=temp;
                    }
                    else if(temp.y==menor.y
                            &&
                            temp.x < menor.x
                            ){
                        menor=temp;
                    }
                }
                //cria a arvore de vertices ordenada por angulo
                edk::physics2D::PhysicsMesh2D::ConvexTree tree;
                for(edk::uint32 i=0u;i<polygon.getVertexCount();i++){
                    temp = polygon.getVertexPosition(i);
                    if(temp.x!=menor.x
                            ||
                            temp.y != menor.y
                            ){
                        //
                        edk::vec3f32 *vert = new edk::vec3f32;
                        if(vert){
                            vert->x = temp.x;
                            vert->y = temp.y;
                            vert->z = edk::Math::getAngle2f(temp-menor);
                            //adiciona o vert
                            if(!tree.add(vert)){
                                //
                                delete vert;
                            }
                        }
                        vert=NULL;
                    }
                }
                if(tree.size()){
                    edk::vec3f32 *test = tree.getElementInPosition(0u);
                    edk::vec2f32 sub = menor;
                    for(edk::uint32 i=1u;i<tree.size();i++){
                        edk::vec3f32 *next = tree.getElementInPosition(i);
                        if(next){
                            if(edk::Math::getAngleDistance(edk::vec2f32(next->x - sub.x,next->y - sub.y),
                                                    edk::vec2f32(test->x - sub.x,test->y - sub.y)
                                                    )>=0.f
                                    ){
                                //
                                tree.remove(test);
                                delete test;
                                i--;
                            }
                            test = tree.getElementInPosition(i);

                            if(i){
                                edk::vec3f32 *temp = tree.getElementInPosition(i-1u);
                                if(temp){
                                    sub.x = temp->x;
                                    sub.y = temp->y;
                                }
                            }
                            else{
                                sub = menor;
                            }
                        }
                    }


                    //test if the tree have vertices
                    if(tree.size()){
                        edk::uint32 maxPolyCount = 6u;
                        edk::uint32 count = 0u;
                        while(tree.size()>maxPolyCount){
                            //
                            p2.createPolygon(maxPolyCount+2u);
                            //set the first vertex
                            p2.setVertexPosition(0u,menor.x,menor.y);
                            for(edk::uint32 i=0u;i<=maxPolyCount;i++){
                                //
                                edk::vec3f32 *vert = tree.getElementInPosition(count);
                                if(vert){

                                    //set the vertex
                                    p2.setVertexPosition(i+1u,vert->x,vert->y);


                                    if(i<maxPolyCount){
                                        tree.remove(vert);
                                        //deleta o vert
                                        delete vert;
                                    }
                                }
                            }
                            ret = edk::shape::Polygon2DList::addPolygon(p2);
                        }
                        if(tree.size()){
                            //
                            p2.createPolygon(tree.size()+1u);
                            //set the first vertex
                            p2.setVertexPosition(0u,menor.x,menor.y);
                            for(edk::uint32 i=0u;i<tree.size();i++){
                                edk::vec3f32 *vert = tree.getElementInPosition(i);
                                if(vert){

                                    //set the vertex
                                    p2.setVertexPosition(i+1u,vert->x,vert->y);
                                    //deleta o vert
                                    delete vert;
                                }
                            }
                            ret = edk::shape::Polygon2DList::addPolygon(p2);
                        }
                    }
                    tree.clean();
                }
            }
        }
    }
    //remove the delete from the polygon. This dont delete polygon in the next destrutor
    polygon.cantDeletePolygon();
    return ret;
}
