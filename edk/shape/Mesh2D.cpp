#include "Mesh2D.h"

/*
Library Mesh2D - Draw a 2D Mesh in EDK Game Engine
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
#warning "            Inside Mesh2D.cpp"
#endif

edk::shape::Mesh2D::Mesh2D()
{
    //ctor
    this->polygons.clean(2u);
    //clean the selected
    this->freeSelected();
    this->canDeleteMesh=true;
}

edk::shape::Mesh2D::~Mesh2D()
{
    if(this->canDeleteMesh){
        this->cleanTextures();
    }
    else{
        this->material.cantDelete();
        this->cantDeleteList();
    }
    this->canDeleteMesh=true;
}

inline bool edk::shape::Mesh2D::floatDifferent(edk::float32 f1,edk::float32 f2){
    if((f1<f2-0.0001f || f1>f2+0.0001f)){
        return true;
    }
    return false;
}
bool edk::shape::Mesh2D::pointInsideLine(edk::vec2f32 point,edk::vec2f32 lineStart,edk::vec2f32 lineEnd){
    /*
    printf("\n%u %s %s point %.2f %.2f lineStart %.2f %.2f lineEnd %.2f %.2f pointStraigh2D %s"
           ,__LINE__,__FILE__,__func__
           ,point.x
           ,point.y
           ,lineStart.x
           ,lineStart.y
           ,lineEnd.x
           ,lineEnd.y
           ,edk::collision::MathCollision::pointStraigh2D(point,lineStart,lineEnd,0.01f)?"true":"false"
           );fflush(stdout);
*/
    edk::vec2f32 pStart,pEnd;
    if(lineStart.x < lineEnd.x){
        pStart.x = lineStart.x;
        pEnd.x = lineEnd.x;
    }
    else{
        pStart.x = lineEnd.x;
        pEnd.x = lineStart.x;
    }
    if(lineStart.y < lineEnd.y){
        pStart.y = lineStart.y;
        pEnd.y = lineEnd.y;
    }
    else{
        pStart.y = lineEnd.y;
        pEnd.y = lineStart.y;
    }
    //
    /*
    printf("\n%u %s %s point %.2f %.2f pStart %.2f %.2f pEnd %.2f %.2f"
           ,__LINE__,__FILE__,__func__
           ,point.x
           ,point.y
           ,pStart.x
           ,pStart.y
           ,pEnd.x
           ,pEnd.y
           );fflush(stdout);
*/
    if(edk::collision::MathCollision::pointStraigh2D(point,lineStart,lineEnd,0.01f)
            &&
            point.x>=pStart.x && point.x<=pEnd.x
            &&
            point.y>=pStart.y && point.y<=pEnd.y
            ){
        /*
        printf(" TRUE");fflush(stdout);
*/
        return true;
    }
    /*
    printf(" FALSE");fflush(stdout);
*/
    return false;
}

//remove the rextures
void edk::shape::Mesh2D::cleanTextures(){
    this->material.removeAllTextures();
}
//remove the texture
bool edk::shape::Mesh2D::removeTexture(edk::uint32 position){
    return this->material.removeTexture(position);
}

//DRAW
//print the mesh
void edk::shape::Mesh2D::print(){
    //
    this->printPolygons();
}
//draw the mesh
void edk::shape::Mesh2D::drawOneTexture(){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture();
        //Draw the mesh
        this->drawPolygons();

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygons();
    }
}
void edk::shape::Mesh2D::drawOneTexture(edk::uint32 position){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture(position);
        //Draw the mesh
        this->drawPolygons();

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygons();
    }
}
bool edk::shape::Mesh2D::selectedDrawOneTexture(){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture();
            //Draw the polygon
            this->selected->draw();

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the polygon
            this->selected->draw();
        }
        return true;
    }
    return false;
}
bool edk::shape::Mesh2D::selectedDrawOneTexture(edk::uint32 position){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture(position);
            //Draw the polygon
            this->selected->draw();

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the polygon
            this->selected->draw();
        }
        return true;
    }
    return false;
}

void edk::shape::Mesh2D::drawOneTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture();
        //Draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);
    }
}
void edk::shape::Mesh2D::drawOneTextureWithLight(edk::uint32 position,edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture(position);
        //Draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);
    }
}
bool edk::shape::Mesh2D::SelectedDrawOneTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture();
            //Draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);
        }
        return true;
    }
    return false;
}
bool edk::shape::Mesh2D::SelectedDrawOneTextureWithLight(edk::uint32 position,edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture(position);
            //Draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);
        }
        return true;
    }
    return false;
}

//draw the mesh
void edk::shape::Mesh2D::drawMultiTexture(){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithMultiTexture();
        //Draw the mesh
        this->drawPolygons();

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygons();
    }
}
bool edk::shape::Mesh2D::SelectedDrawMultiTexture(){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithMultiTexture();
            //Draw the mesh
            this->selected->draw();

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the mesh
            this->selected->draw();
        }
        return true;
    }
    return false;
}
void edk::shape::Mesh2D::drawMultiTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithMultiTexture();
        //Draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        this->drawPolygonsWithLight(lightPositions,lightDirections,lightIsOn);
    }
}
bool edk::shape::Mesh2D::SelectedDrawMultiTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]){
    if(selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithMultiTexture();
            //Draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);

            this->material.drawEndWithTexture();
        }
        else{
            this->material.drawNoTexture();
            //else just draw the mesh
            this->selected->drawWithLight(lightPositions,lightDirections,lightIsOn);
        }
        return true;
    }
    return false;
}
void edk::shape::Mesh2D::drawWire(){
    this->material.drawNoTexture();
    //else just draw the mesh
    this->drawWirePolygons();
}

bool edk::shape::Mesh2D::triangularizateFromVertex(edk::vector::Stack<edk::vec2f32>* vertexes){
    return edk::shape::Mesh2D::vertexTriangularization(vertexes,this);
}
bool edk::shape::Mesh2D::triangularizateFromPolygon(edk::shape::Polygon2D polygon){
    bool ret = edk::shape::Mesh2D::polygonTriangularization(polygon,this);
    polygon.cantDeletePolygon();
    return ret;
}

//vertexTriangularization the mesh with the triangles
bool edk::shape::Mesh2D::vertexTriangularization(edk::vector::Stack<edk::vec2f32>* vertexes,edk::shape::Mesh2D *mesh){
    bool ret=false;
    if(vertexes && mesh){
        treeTriangles tree;
        //test all the vertex to create all the polygons
        edk::uint32 size = vertexes->size();
        edk::uint32 psize = 0u;
        edk::uint32 vsize = 0u;
        edk::uint32 csize = 0u;
        edk::shape::Triangle2D tri;
        edk::float32 angle = 0.f;
        edk::uint8 goContinue=0u;
        edk::vec2f32 p1;
        edk::vec2f32 p2;
        edk::vec2f32 t1;
        edk::vec2f32 t2;
        edk::collision::Vecs2f32 collision;
        for(edk::uint32 i=0u;i<size;i++){
            for(edk::uint32 j=0u;j<size;j++){
                if(j==i) continue;
                for(edk::uint32 k=0u;k<size;k++){
                    if(k==i) continue;
                    if(k==j) continue;
                    /*
                    printf("\nTri %u %u %u",i,j,k);fflush(stdout);
*/
                    //test if aready have the triangle on the tree
                    if(!tree.haveTriangle(i,j,k)){
                        //if not then test the new poligon internesctions

                        //create the triangle and test if it's counter clockwise
                        tri.setVertexPosition(0u,vertexes->get(i).x,vertexes->get(i).y);
                        tri.setVertexPosition(1u,vertexes->get(j).x,vertexes->get(j).y);
                        tri.setVertexPosition(2u,vertexes->get(k).x,vertexes->get(k).y);

                        if(tri.isCounterclockwise()){

                            //test if the triangle have a vertex inside
                            for(edk::uint32 l=0u;l<size;l++){
                                if(l==i) continue;
                                if(l==j) continue;
                                if(l==k) continue;

                                //calculate if the point is inside the triangle
                                angle = edk::Math::getAngle2f(vertexes->get(l)-vertexes->get(i)) -
                                        edk::Math::getAngle2f(vertexes->get(j)-vertexes->get(i));
                                if(angle<=180.f && angle>=0.f){
                                    angle = edk::Math::getAngle2f(vertexes->get(l)-vertexes->get(j)) -
                                            edk::Math::getAngle2f(vertexes->get(k)-vertexes->get(j));
                                    if(angle<=180.f && angle>=0.f){
                                        angle = edk::Math::getAngle2f(vertexes->get(l)-vertexes->get(k)) -
                                                edk::Math::getAngle2f(vertexes->get(i)-vertexes->get(k));
                                        if(angle<=180.f && angle>=0.f){
                                            //
                                            /*
                                            printf("\n%u %s %s point      inside",__LINE__,__FILE__,__func__);fflush(stdout);
*/
                                            goContinue++;
                                            break;
                                        }
                                    }
                                }
                            }
                            if(goContinue){
                                goContinue=0u;
                                continue;
                            }

                            //test if the lines intersect
                            psize = mesh->getPolygonSize();
                            for(edk::uint32 m=0u;m<psize;m++){
                                mesh->selectPolygon(m);
                                vsize = mesh->selectedGetVertexCount();
                                if(vsize) vsize--;
                                for(edk::uint32 n=0u;n<vsize;n++){
                                    //
                                    p1 = mesh->selectedGetVertexPosition(n);
                                    p2 = mesh->selectedGetVertexPosition(n+1u);

                                    //test intersection with all

                                    //0 1
                                    t1 = tri.getVertexPosition(0u);
                                    t2 = tri.getVertexPosition(1u);
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,n,p1.x,p1.y
                                           ,n+1u,p2.x,p2.y
                                           ,0u,t1.x,t1.y
                                           ,1u,t2.x,t2.y
                                           );fflush(stdout);
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );fflush(stdout);
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);
                                        /*
                                        printf("\nCollision size %u",collision.size());fflush(stdout);
*/
                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );fflush(stdout);
*/
                                                if((floatDifferent(collision.get(c).x,p1.x)
                                                    ||
                                                    floatDifferent(collision.get(c).y,p1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){
                                                    /*
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);fflush(stdout);
*/
                                                    goContinue++;
                                                    break;
                                                }
                                            }
                                            collision.clean();
                                        }
                                    }

                                    //1 2
                                    t1 = tri.getVertexPosition(1u);
                                    t2 = tri.getVertexPosition(2u);
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,n,p1.x,p1.y
                                           ,n+1u,p2.x,p2.y
                                           ,1u,t1.x,t1.y
                                           ,2u,t2.x,t2.y
                                           );fflush(stdout);
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );fflush(stdout);
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);
                                        /*
                                        printf("\nCollision size %u",collision.size());fflush(stdout);
*/
                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );fflush(stdout);
*/
                                                if((floatDifferent(collision.get(c).x,p1.x)
                                                    ||
                                                    floatDifferent(collision.get(c).y,p1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){
                                                    /*
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);fflush(stdout);
*/
                                                    goContinue++;
                                                    break;
                                                }
                                            }
                                            collision.clean();
                                        }
                                    }

                                    //2 0
                                    t1 = tri.getVertexPosition(2u);
                                    t2 = tri.getVertexPosition(0u);
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,n,p1.x,p1.y
                                           ,n+1u,p2.x,p2.y
                                           ,2u,t1.x,t1.y
                                           ,0u,t2.x,t2.y
                                           );fflush(stdout);
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );fflush(stdout);
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);
                                        /*
                                        printf("\nCollision size %u",collision.size());fflush(stdout);
*/
                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );fflush(stdout);
*/
                                                if((floatDifferent(collision.get(c).x,p1.x)
                                                    ||
                                                    floatDifferent(collision.get(c).y,p1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){
                                                    /*
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);fflush(stdout);
*/
                                                    goContinue++;
                                                    break;
                                                }
                                            }
                                            collision.clean();
                                        }
                                    }
                                }
                                //test the last internection
                                if(!goContinue){
                                    //
                                    p1 = mesh->selectedGetVertexPosition(vsize);
                                    p2 = mesh->selectedGetVertexPosition(0u);

                                    //test intersection with all

                                    //0 1
                                    t1 = tri.getVertexPosition(0u);
                                    t2 = tri.getVertexPosition(1u);
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,vsize,p1.x,p1.y
                                           ,0u,p2.x,p2.y
                                           ,0u,t1.x,t1.y
                                           ,1u,t2.x,t2.y
                                           );fflush(stdout);
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );fflush(stdout);
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);
                                        /*
                                        printf("\nCollision size %u",collision.size());fflush(stdout);
*/
                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );fflush(stdout);
*/
                                                if((floatDifferent(collision.get(c).x,p1.x)
                                                    ||
                                                    floatDifferent(collision.get(c).y,p1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){
                                                    /*
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);fflush(stdout);
*/
                                                    goContinue++;
                                                    break;
                                                }
                                            }
                                            collision.clean();
                                        }
                                    }

                                    //1 2
                                    t1 = tri.getVertexPosition(1u);
                                    t2 = tri.getVertexPosition(2u);
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,vsize,p1.x,p1.y
                                           ,0u,p2.x,p2.y
                                           ,1u,t1.x,t1.y
                                           ,2u,t2.x,t2.y
                                           );fflush(stdout);
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );fflush(stdout);
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);
                                        /*
                                        printf("\nCollision size %u",collision.size());fflush(stdout);
*/
                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );fflush(stdout);
                                                printf("\n((floatDifferent(collision.get(c).x[%.2f],p1.x[%.2f])%s"
                                                       "\n  &&"
                                                       "\n  floatDifferent(collision.get(c).y[%.2f],p1.y[%.2f]))%s"
                                                       "\n      &&"
                                                       "\n      (floatDifferent(collision.get(c).x,p2.x)%s"
                                                       "\n       &&"
                                                       "\n       floatDifferent(collision.get(c).y,p2.y))%s"
                                                       "\n      &&"
                                                       "\n      (floatDifferent(collision.get(c).x,t1.x)%s"
                                                       "\n       &&"
                                                       "\n       floatDifferent(collision.get(c).y,t1.y))%s"
                                                       "\n      &&"
                                                       "\n      (floatDifferent(collision.get(c).x,t2.x)%s"
                                                       "\n       &&"
                                                       "\n       floatDifferent(collision.get(c).y,t2.y))%s"

                                                       "\n      &&"
                                                       "\n      pointInsideLine(collision.get(c),p1,p2)%s &&"
                                                       "\n      pointInsideLine(collision.get(c),t1,t2)%s"

                                                       "\n      )"
                                                       ,collision.get(c).x,p1.x
                                                       ,floatDifferent(collision.get(c).x,p1.x)?"true":"false"
                                                       ,collision.get(c).y,p1.y
                                                       ,floatDifferent(collision.get(c).y,p1.y)?"true":"false"
                                                       ,floatDifferent(collision.get(c).x,p2.x)?"true":"false"
                                                       ,floatDifferent(collision.get(c).y,p2.y)?"true":"false"
                                                       ,floatDifferent(collision.get(c).x,t1.x)?"true":"false"
                                                       ,floatDifferent(collision.get(c).y,t1.y)?"true":"false"
                                                       ,floatDifferent(collision.get(c).x,t2.x)?"true":"false"
                                                       ,floatDifferent(collision.get(c).y,t2.y)?"true":"false"
                                                       ,pointInsideLine(collision.get(c),p1,p2)?"true":"false"
                                                       ,pointInsideLine(collision.get(c),t1,t2)?"true":"false"
                                                       );fflush(stdout);
*/
                                                if((floatDifferent(collision.get(c).x,p1.x)
                                                    ||
                                                    floatDifferent(collision.get(c).y,p1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){
                                                    /*
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);fflush(stdout);
*/
                                                    goContinue++;
                                                    break;
                                                }
                                            }
                                            collision.clean();
                                        }
                                    }

                                    //2 0
                                    t1 = tri.getVertexPosition(2u);
                                    t2 = tri.getVertexPosition(0u);
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,vsize,p1.x,p1.y
                                           ,0u,p2.x,p2.y
                                           ,2u,t1.x,t1.y
                                           ,0u,t2.x,t2.y
                                           );fflush(stdout);
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );fflush(stdout);
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);
                                        /*
                                        printf("\nCollision size %u",collision.size());fflush(stdout);
*/
                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );fflush(stdout);
*/
                                                if((floatDifferent(collision.get(c).x,p1.x)
                                                    ||
                                                    floatDifferent(collision.get(c).y,p1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){
                                                    /*
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);fflush(stdout);
*/
                                                    goContinue++;
                                                    break;
                                                }
                                            }
                                            collision.clean();
                                        }
                                    }
                                }
                                if(goContinue>1u)break;
                            }
                            if(goContinue>0u){
                                goContinue=0u;
                                continue;
                            }

                            //create the polygon
                            /*
                            printf("\n    Create %u %u %u",i,j,k);fflush(stdout);
*/

                            //add to the tree
                            tree.newTriangle(i,j,k);

                            //add the tri on the mesh
                            mesh->addPolygon(tri);

                            ret=true;
                        }
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::shape::Mesh2D::polygonTriangularization(edk::shape::Polygon2D polygon,edk::shape::Mesh2D *mesh){
    bool ret=false;
    edk::shape::Triangle2D tri;
    edk::vector::Stack<edk::vec2f32> concaves;
    edk::uint32 concaveActual=0u;
    edk::uint32 concaveFirst=0u;
    edk::shape::Polygon2D polyTemp;
    edk::uint32 size = polygon.getVertexCount();
    edk::float32 angle = 0.f;
    if(size>=3u && mesh){
        //search for the concave vertexes
        size-=2u;
        printf("\n%u %s %s vertex %u LINE %u %u with %u %u",__LINE__,__FILE__,__func__
               ,0u
               ,size+1u
               ,0u
               ,0u
               ,1u
               );fflush(stdout);

        //calculate if the point is inside the triangle
        angle = edk::Math::getAngle2f(polygon.getVertexPosition(0u)-polygon.getVertexPosition(size+1u)) -
                edk::Math::getAngle2f(polygon.getVertexPosition(1u)-polygon.getVertexPosition(size+1u));
        if(angle<0.f)angle+=360.f;
        printf("\nAngle == %.2f"
               ,angle
               );fflush(stdout);
        if(angle<=180.f){
            printf(" concave");fflush(stdout);
            if(!concaves.size()) concaveFirst = 0u;
            concaves.pushBack(polygon.getVertexPosition(0u));
            concaveActual = 0u;
        }
        else{
            printf(" convex");fflush(stdout);
        }
        bool goBreak=false;
        for(edk::uint32 i=0u;i<size;i++){
            //test the two lines
            printf("\n%u %s %s vertex %u LINE %u %u with %u %u",__LINE__,__FILE__,__func__
                   ,i+1u
                   ,i
                   ,i+1u
                   ,i+1u
                   ,i+2u
                   );fflush(stdout);

            //calculate if the point is inside the triangle
            angle = edk::Math::getAngle2f(polygon.getVertexPosition(i+1u)-polygon.getVertexPosition(i)) -
                    edk::Math::getAngle2f(polygon.getVertexPosition(i+2u)-polygon.getVertexPosition(i));
            if(angle<0.f)angle+=360.f;
            printf("\nAngle == %.2f"
                   ,angle
                   );fflush(stdout);
            if(angle<=180.f){
                printf(" concave");fflush(stdout);
                if(!concaves.size()) concaveFirst = i+1u;
                concaves.pushBack(polygon.getVertexPosition(i+1u));
                concaveActual = i+1u;
            }
            else{
                printf(" convex");fflush(stdout);
                //test if have concaves
                if(concaves.size()){
                    //join the concave, the convex and the next vertex to create a triangle
                    tri.setVertexPosition(0u,polygon.getVertexPosition(concaveActual).x,polygon.getVertexPosition(concaveActual).y);
                    tri.setVertexPosition(1u,polygon.getVertexPosition(i+1u).x,polygon.getVertexPosition(i+1u).y);
                    tri.setVertexPosition(2u,polygon.getVertexPosition(i+2u).x,polygon.getVertexPosition(i+2u).y);
                    if(tri.isCounterclockwise()){
                        //test if the triangle have a vertex inside
                        bool goContinue = true;
                        for(edk::uint32 l=0u;l<size;l++){

                            //calculate if the point is inside the triangle
                            angle = edk::Math::getAngle2f(polygon.getVertexPosition(l)-tri.getVertexPosition(0u)) -
                                    edk::Math::getAngle2f(tri.getVertexPosition(1u)-tri.getVertexPosition(0u));
                            if(angle<=180.f && angle>=0.f){
                                angle = edk::Math::getAngle2f(polygon.getVertexPosition(l)-tri.getVertexPosition(1u)) -
                                        edk::Math::getAngle2f(tri.getVertexPosition(2u)-tri.getVertexPosition(1u));
                                if(angle<=180.f && angle>=0.f){
                                    angle = edk::Math::getAngle2f(polygon.getVertexPosition(l)-tri.getVertexPosition(2u)) -
                                            edk::Math::getAngle2f(tri.getVertexPosition(0u)-tri.getVertexPosition(2u));
                                    if(angle<=180.f && angle>=0.f){
                                        //
                                        /*
                                        printf("\n%u %s %s point      inside",__LINE__,__FILE__,__func__);fflush(stdout);
*/
                                        goContinue=false;
                                        break;
                                    }
                                }
                            }
                        }
                        if(goContinue){
                            mesh->addPolygon(tri);
                        }
                        else{
                            //add the vertex as a concave
                            if(!concaves.size()) concaveFirst = i+1u;
                            concaves.pushBack(polygon.getVertexPosition(i+1u));
                            concaveActual = i+1u;
                        }
                    }
                    else{
                        goBreak=true;
                        break;
                    }
                }
            }
        }
        if(!goBreak){
            //then test the last vertexes
            printf("\n%u %s %s vertex %u LINE %u %u with %u %u",__LINE__,__FILE__,__func__
                   ,size+1u
                   ,size
                   ,size+1u
                   ,size+1u
                   ,0u
                   );fflush(stdout);

            //calculate if the point is inside the triangle
            angle = edk::Math::getAngle2f(polygon.getVertexPosition(size+1u)-polygon.getVertexPosition(size)) -
                    edk::Math::getAngle2f(polygon.getVertexPosition(0u)-polygon.getVertexPosition(size));
            if(angle<0.f)angle+=360.f;
            printf("\nAngle == %.2f"
                   ,angle
                   );fflush(stdout);
            if(angle<=180.f){
                printf(" concave");fflush(stdout);
                if(!concaves.size()) concaveFirst = size+1u;
                concaves.pushBack(polygon.getVertexPosition(size+1u));
                concaveActual = size+1u;
            }
            else{
                printf(" convex");fflush(stdout);
                //test if have concaves
                if(concaves.size()){
                    //join the concave, the convex and the next vertex to create a triangle
                    tri.setVertexPosition(0u,polygon.getVertexPosition(concaveActual).x,polygon.getVertexPosition(concaveActual).y);
                    tri.setVertexPosition(1u,polygon.getVertexPosition(size+1u).x,polygon.getVertexPosition(size+1u).y);
                    tri.setVertexPosition(2u,polygon.getVertexPosition(0u).x,polygon.getVertexPosition(0u).y);
                    if(tri.isCounterclockwise()){
                        //test if the triangle have a vertex inside
                        bool goContinue = true;
                        for(edk::uint32 l=0u;l<size;l++){

                            //calculate if the point is inside the triangle
                            angle = edk::Math::getAngle2f(polygon.getVertexPosition(l)-tri.getVertexPosition(0u)) -
                                    edk::Math::getAngle2f(tri.getVertexPosition(1u)-tri.getVertexPosition(0u));
                            if(angle<=180.f && angle>=0.f){
                                angle = edk::Math::getAngle2f(polygon.getVertexPosition(l)-tri.getVertexPosition(1u)) -
                                        edk::Math::getAngle2f(tri.getVertexPosition(2u)-tri.getVertexPosition(1u));
                                if(angle<=180.f && angle>=0.f){
                                    angle = edk::Math::getAngle2f(polygon.getVertexPosition(l)-tri.getVertexPosition(2u)) -
                                            edk::Math::getAngle2f(tri.getVertexPosition(0u)-tri.getVertexPosition(2u));
                                    if(angle<=180.f && angle>=0.f){
                                        //
                                        /*
                                        printf("\n%u %s %s point      inside",__LINE__,__FILE__,__func__);fflush(stdout);
*/
                                        goContinue=false;
                                        break;
                                    }
                                }
                            }
                        }
                        if(goContinue){
                            mesh->addPolygon(tri);
                        }
                        else{
                            //add the vertex as a concave
                            if(!concaves.size()) concaveFirst = size+1u;
                            concaves.pushBack(polygon.getVertexPosition(size+1u));
                            concaveActual = size+1u;
                        }
                    }
                }
            }

            //test if have vertexes before the first concave
            if(concaveFirst){
                //test the vertexes
                for(edk::uint32 i=0u;i<concaveFirst;i++){
                    //
                    tri.setVertexPosition(0u,polygon.getVertexPosition(concaveActual).x,polygon.getVertexPosition(concaveActual).y);
                    tri.setVertexPosition(1u,polygon.getVertexPosition(i).x,polygon.getVertexPosition(i).y);
                    tri.setVertexPosition(2u,polygon.getVertexPosition(i+1u).x,polygon.getVertexPosition(i+1u).y);
                    if(tri.isCounterclockwise()){
                        //test if the triangle have a vertex inside
                        bool goContinue = true;
                        for(edk::uint32 l=0u;l<size;l++){

                            //calculate if the point is inside the triangle
                            angle = edk::Math::getAngle2f(polygon.getVertexPosition(l)-tri.getVertexPosition(0u)) -
                                    edk::Math::getAngle2f(tri.getVertexPosition(1u)-tri.getVertexPosition(0u));
                            if(angle<=180.f && angle>=0.f){
                                angle = edk::Math::getAngle2f(polygon.getVertexPosition(l)-tri.getVertexPosition(1u)) -
                                        edk::Math::getAngle2f(tri.getVertexPosition(2u)-tri.getVertexPosition(1u));
                                if(angle<=180.f && angle>=0.f){
                                    angle = edk::Math::getAngle2f(polygon.getVertexPosition(l)-tri.getVertexPosition(2u)) -
                                            edk::Math::getAngle2f(tri.getVertexPosition(0u)-tri.getVertexPosition(2u));
                                    if(angle<=180.f && angle>=0.f){
                                        //
                                        /*
                                        printf("\n%u %s %s point      inside",__LINE__,__FILE__,__func__);fflush(stdout);
*/
                                        goContinue=false;
                                        break;
                                    }
                                }
                            }
                        }
                        if(goContinue){
                            mesh->addPolygon(tri);
                        }
                        else{
                            //add the vertex as a concave
                            concaves.pushBack(polygon.getVertexPosition(i));
                        }
                    }
                }
            }
            if(!goBreak){
                ret = true;
                size = concaves.size();
                //test if have concaves
                if(size){
                    //draw a polyTemp with the concaves
                    polyTemp.createPolygon(size);
                    for(edk::uint32 i=0u;i<size;i++){
                        polyTemp.setVertexPosition(i,concaves.get(i).x,concaves.get(i).y);
                    }
                    //run the same function with the polyTemp
                    edk::shape::Mesh2D::polygonTriangularization(polyTemp,mesh);
                }
                else{
                    //run the simple vertex triangularization
                    edk::vector::Stack<edk::vec2f32> vertexes;
                    edk::uint32 size = polygon.getVertexCount();
                    for(edk::uint32 i=0u;i<size;i++){
                        vertexes.pushBack(edk::vec2f32(polygon.getVertexPosition(i)));
                    }
                    edk::shape::Mesh2D::vertexTriangularization(&vertexes,mesh);
                }
            }
        }
    }
    polygon.cantDeletePolygon();
    return ret;
}

void edk::shape::Mesh2D::cantDeleteMesh(){
    canDeleteMesh=false;
}
//XML
bool edk::shape::Mesh2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon2DList::writeToXML(xml,id)){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //write the material
                    this->material.writeToXML(xml,0u);
                    ret=true;
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
bool edk::shape::Mesh2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon2DList::readFromXML(xml,id)){
        bool ret=true;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);
            if(name){
                //select the name
                if(xml->selectChild(name)){
                    //read the material
                    this->material.readFromXML(xml,0u);
                    ret=true;
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}

bool edk::shape::Mesh2D::cloneFrom(edk::shape::Mesh2D* mesh){
    if(mesh){
        //
        edk::shape::Mesh2D::TreeAnimations tree;

        //delete the polygons
        this->cleanPolygons();
        //read the polygons
        register edk::uint32 size = mesh->polygons.size();
        edk::uint32 select=0u;
        edk::shape::Polygon2D* temp = NULL;
        edk::uint32 id;
        edk::animation::Interpolation1DGroup* animTemp=NULL;
        for(edk::uint32 i=0u;i<size;i++){
            //
            temp=mesh->polygons[i];
            if(temp){
                if(temp==mesh->selected){
                    select=i;
                }
                id=this->addPolygon(*temp);

                //test the animation
                animTemp = temp->framesGetAnimation();
                if(animTemp){
                    //test if already have the animation on the tree
                    if(tree.haveAnimation(animTemp)){
                        //set the animation to the polygon in the mesh
                        this->copyAnimationFramesToPolygon(tree.getAnimationID(animTemp),id);
                    }
                    else{
                        //add the animation on the tree
                        if(tree.addAnimations(animTemp,id)){
                            //create a new animation in the polygon
                            if(this->newAnimationFramesToPolygon(id)){
                                //copy the animation
                                this->copyThisAnimationFramesToPolygon(animTemp,id);
                            }
                        }
                    }
                }
            }
        }
        this->selectPolygon(select);
        //test if have animation selected
        if(mesh->haveSelectedAnimation()){
            //Set the ID of the animation selected
            this->selectAnimationFramesFromPolygon(mesh->getAnimationFramesSelectedID());
        }
        mesh->cantDeleteList();

        this->material = mesh->material;
        return true;
    }
    return false;
}
