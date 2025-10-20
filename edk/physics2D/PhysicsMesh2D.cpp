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

#ifdef printMessages
#pragma message "            Inside PhysicsMesh2D.cpp"
#endif

edk::physics2D::PhysicsMesh2D::PhysicsMesh2D(){
    this->classThis=NULL;
    this->Constructor();
}
edk::physics2D::PhysicsMesh2D::~PhysicsMesh2D(){
    this->Destructor();
}

void edk::physics2D::PhysicsMesh2D::Constructor(){
    edk::shape::Polygon2DList::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::physics2D::PhysicsMesh2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
    edk::shape::Polygon2DList::Destructor();
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
            //set the color
            rect.setVertexColor(0u,polygon.getVertexColor(0u)); 
            rect.setVertexColor(1u,polygon.getVertexColor(1u)); 
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
            //p2 = polygon; 
            p2.cloneFrom(&polygon); 

            //salva o menor vertice
            edk::physics2D::vec3f32Color4f32 temp; 
            edk::physics2D::vec3f32Color4f32 menor; 
            if(polygon.getVertexCount()){
                temp = polygon.getVertexPosition(0u); 
                temp = polygon.getVertexColor(0u); 
                menor=temp; 
                for(edk::uint32 i=1u;i<polygon.getVertexCount();i++){
                    //
                    temp = polygon.getVertexPosition(i); 
                    temp = polygon.getVertexColor(i); 
                    if(temp.position.y < menor.position.y){
                        menor=temp; 
                    }
                    else if(temp.position.y==menor.position.y
                            &&
                            temp.position.x < menor.position.x
                            ){
                        menor=temp; 
                    }
                }
                //cria a arvore de vertices ordenada por angulo
                edk::physics2D::PhysicsMesh2D::ConvexTree tree; 
                for(edk::uint32 i=0u;i<polygon.getVertexCount();i++){
                    temp = polygon.getVertexPosition(i); 
                    temp = polygon.getVertexColor(i); 
                    if(temp.position.x!=menor.position.x
                            ||
                            temp.position.y != menor.position.y
                            ){
                        //
                        edk::physics2D::vec3f32Color4f32 *vert = new edk::physics2D::vec3f32Color4f32; 
                        if(vert){
                            vert->position.x = temp.position.x; 
                            vert->position.y = temp.position.y; 
                            vert->position.z = edk::Math::getAngle(temp.position.x-menor.position.x,temp.position.y-menor.position.y); 
                            vert->color = temp.color; 
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
                    edk::physics2D::vec3f32Color4f32 *test = tree.getElementInPosition(0u); 
                    edk::physics2D::vec3f32Color4f32 sub = menor; 
                    for(edk::uint32 i=1u;i<tree.size();i++){
                        edk::physics2D::vec3f32Color4f32 *next = tree.getElementInPosition(i); 
                        if(next){
                            if(edk::Math::getAngleDistance(edk::vec2f32(next->position.x - sub.position.x,next->position.y - sub.position.y),
                                                    edk::vec2f32(test->position.x - sub.position.x,test->position.y - sub.position.y)
                                                    )>=0.f
                                    ){
                                //
                                tree.remove(test); 
                                delete test; 
                                i--; 
                            }
                            test = tree.getElementInPosition(i); 

                            if(i){
                                edk::physics2D::vec3f32Color4f32 *temp = tree.getElementInPosition(i-1u); 
                                if(temp){
                                    sub.position.x = temp->position.x; 
                                    sub.position.y = temp->position.y; 
                                    sub.color = temp->color; 
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
                        while(tree.size()>8u){
                            //
                            p2.createPolygon(maxPolyCount+2u); 
                            //set the first vertex
                            p2.setVertexPosition(0u,menor.position.x,menor.position.y); 
                            p2.setVertexColor(0u,menor.color); 
                            for(edk::uint32 i=0u;i<=maxPolyCount;i++){
                                //
                                edk::physics2D::vec3f32Color4f32 *vert = tree.getElementInPosition(count); 
                                if(vert){

                                    //set the vertex
                                    p2.setVertexPosition(i+1u,vert->position.x,vert->position.y); 
                                    p2.setVertexColor(i+1u,vert->color); 


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
                            p2.setVertexPosition(0u,menor.position.x,menor.position.y); 
                            p2.setVertexColor(0u,menor.color); 
                            for(edk::uint32 i=0u;i<tree.size();i++){
                                edk::physics2D::vec3f32Color4f32 *vert = tree.getElementInPosition(i); 
                                if(vert){

                                    //set the vertex
                                    p2.setVertexPosition(i+1u,vert->position.x,vert->position.y); 
                                    p2.setVertexColor(i+1u,vert->color); 
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
    return ret;
}
