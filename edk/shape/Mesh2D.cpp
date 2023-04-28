#include "Mesh2D.h"

/*
Library Mesh2D - Draw a 2D Mesh in EDK Game Engine
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
#pragma message "            Inside Mesh2D.cpp"
#endif

edk::shape::Mesh2D::Mesh2D()
{
    //ctor
    this->polygons.clean(2u);edkEnd();
    //clean the selected
    this->freeSelected();edkEnd();
    this->canDeleteMesh=true;edkEnd();
}

edk::shape::Mesh2D::~Mesh2D()
{
    if(this->canDeleteMesh){
        this->clean();edkEnd();
    }
    else{
        this->material.cantDelete();edkEnd();
        this->cantDeleteList();edkEnd();
    }
    this->canDeleteMesh=true;edkEnd();
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
           );edkEnd();
*/
    edk::vec2f32 pStart,pEnd;edkEnd();
    if(lineStart.x < lineEnd.x){
        pStart.x = lineStart.x;edkEnd();
        pEnd.x = lineEnd.x;edkEnd();
    }
    else{
        pStart.x = lineEnd.x;edkEnd();
        pEnd.x = lineStart.x;edkEnd();
    }
    if(lineStart.y < lineEnd.y){
        pStart.y = lineStart.y;edkEnd();
        pEnd.y = lineEnd.y;edkEnd();
    }
    else{
        pStart.y = lineEnd.y;edkEnd();
        pEnd.y = lineStart.y;edkEnd();
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
           );edkEnd();
*/
    if(edk::collision::MathCollision::pointStraigh2D(point,lineStart,lineEnd,0.01f)
            &&
            point.x>=pStart.x && point.x<=pEnd.x
            &&
            point.y>=pStart.y && point.y<=pEnd.y
            ){
        /*
        printf(" TRUE");edkEnd();
*/
        return true;
    }
    /*
    printf(" FALSE");edkEnd();
*/
    return false;
}

//clean Mesh
void edk::shape::Mesh2D::clean(){
    this->cleanTextures();edkEnd();
    this->cleanPolygons();edkEnd();
}
//remove the rextures
void edk::shape::Mesh2D::cleanTextures(){
    this->material.removeAllTextures();edkEnd();
}
//remove the texture
bool edk::shape::Mesh2D::removeTexture(edk::uint32 position){
    return this->material.removeTexture(position);edkEnd();
}

//DRAW
//print the mesh
void edk::shape::Mesh2D::print(){
    //
    this->printPolygons();edkEnd();
}
//draw the mesh
void edk::shape::Mesh2D::drawWithoutMaterial(){
    this->drawPolygons();edkEnd();
}
void edk::shape::Mesh2D::drawNoTexture(){
    this->material.drawNoTexture();edkEnd();
    this->drawPolygons();edkEnd();
}
void edk::shape::Mesh2D::drawOneTexture(){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture();edkEnd();
        //Draw the mesh
        this->drawPolygons();edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        this->drawPolygons();edkEnd();
    }
}
void edk::shape::Mesh2D::drawOneTexture(edk::uint32 position){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture(position);edkEnd();
        //Draw the mesh
        this->drawPolygons();edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        this->drawPolygons();edkEnd();
    }
}
bool edk::shape::Mesh2D::selectedDrawOneTexture(){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture();edkEnd();
            //Draw the polygon
            this->selected->draw();edkEnd();

            this->material.drawEndWithTexture();edkEnd();
        }
        else{
            this->material.drawNoTexture();edkEnd();
            //else just draw the polygon
            this->selected->draw();edkEnd();
        }
        return true;
    }
    return false;
}
bool edk::shape::Mesh2D::selectedDrawOneTexture(edk::uint32 position){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture(position);edkEnd();
            //Draw the polygon
            this->selected->draw();edkEnd();

            this->material.drawEndWithTexture();edkEnd();
        }
        else{
            this->material.drawNoTexture();edkEnd();
            //else just draw the polygon
            this->selected->draw();edkEnd();
        }
        return true;
    }
    return false;
}

//draw the mesh
void edk::shape::Mesh2D::drawMultiTexture(){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithMultiTexture();edkEnd();
        //Draw the mesh
        this->drawPolygons();edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        this->drawPolygons();edkEnd();
    }
}
bool edk::shape::Mesh2D::selectedDrawMultiTexture(){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithMultiTexture();edkEnd();
            //Draw the mesh
            this->selected->draw();edkEnd();

            this->material.drawEndWithTexture();edkEnd();
        }
        else{
            this->material.drawNoTexture();edkEnd();
            //else just draw the mesh
            this->selected->draw();edkEnd();
        }
        return true;
    }
    return false;
}
void edk::shape::Mesh2D::drawWire(){
    this->material.drawNoTexture();edkEnd();
    //else just draw the mesh
    this->drawWirePolygons();edkEnd();
}
bool edk::shape::Mesh2D::drawPolygonWithoutMaterial(edk::uint32 polygon){
    //
    return this->drawPolygon(polygon);edkEnd();
}
bool edk::shape::Mesh2D::drawPolygonNoTexture(edk::uint32 polygon){
    this->material.drawNoTexture();edkEnd();
    return this->drawPolygon(polygon);edkEnd();
}
bool edk::shape::Mesh2D::drawPolygonOneTexture(edk::uint32 polygon){
    bool ret = false;edkEnd();
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture();edkEnd();
        //Draw the mesh
        ret = this->drawPolygon(polygon);edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        ret = this->drawPolygon(polygon);edkEnd();
    }
    return ret;
}
bool edk::shape::Mesh2D::drawPolygonOneTexture(edk::uint32 polygon, edk::uint32 position){
    bool ret = false;edkEnd();
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture(position);edkEnd();
        //Draw the mesh
        ret = this->drawPolygon(polygon);edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        ret = this->drawPolygon(polygon);edkEnd();
    }
    return ret;
}
bool edk::shape::Mesh2D::drawPolygonMultiTexture(edk::uint32 polygon){
    bool ret = false;edkEnd();
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithMultiTexture();edkEnd();
        //Draw the mesh
        ret = this->drawPolygon(polygon);edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        ret = this->drawPolygon(polygon);edkEnd();
    }
    return ret;
}
bool edk::shape::Mesh2D::drawPolygonWire(edk::uint32 polygon){
    this->material.drawNoTexture();edkEnd();
    //else just draw the mesh
    return this->drawWirePolygon(polygon);edkEnd();
}

bool edk::shape::Mesh2D::triangularizateFromVertex(edk::vector::Stack<edk::vec2f32>* vertexes){
    return edk::shape::Mesh2D::vertexTriangularization(vertexes,this);edkEnd();
}
bool edk::shape::Mesh2D::triangularizateFromPolygon(edk::shape::Polygon2D polygon){
    bool ret = edk::shape::Mesh2D::polygonTriangularization(polygon,this);edkEnd();
    polygon.cantDeletePolygon();edkEnd();
    return ret;
}
bool edk::shape::Mesh2D::putHoleInPolygon(edk::shape::Polygon2D outside,edk::shape::Polygon2D inside){
    bool ret = false;edkEnd();

    //test if have some polygon as rectanble with 2 vertexes
    edk::shape::Polygon2D* out = &outside;edkEnd();
    edk::shape::Polygon2D* in = &inside;edkEnd();
    edk::shape::Polygon2D outTemp;edkEnd();
    bool haveOut=false;edkEnd();
    edk::shape::Polygon2D inTemp;edkEnd();
    bool haveIn=false;edkEnd();
    //test the outside
    if(outside.getVertexCount()==2u && outside.isRect()){
        //create a new polygon with 4 vertexes
        if(outTemp.createPolygon(4u)){
            //
            outTemp.setVertexPosition(0u,outside.getVertexPosition(0u));edkEnd();
            outTemp.setVertexUV(0u,outside.getVertexUV(0u));edkEnd();
            outTemp.setVertexColor(0u,outside.getVertexColor(0u));edkEnd();
            //
            outTemp.setVertexPosition(1u,outside.getVertexPosition(1u).x,outside.getVertexPosition(0u).y);edkEnd();
            outTemp.setVertexUV(1u,outside.getVertexUV(1u).x,outside.getVertexUV(0u).y);edkEnd();
            outTemp.setVertexColor(1u,outside.getVertexColor(0u));edkEnd();
            //
            outTemp.setVertexPosition(2u,outside.getVertexPosition(1u));edkEnd();
            outTemp.setVertexUV(2u,outside.getVertexUV(1u));edkEnd();
            outTemp.setVertexColor(2u,outside.getVertexColor(1u));edkEnd();
            //
            outTemp.setVertexPosition(3u,outside.getVertexPosition(0u).x,outside.getVertexPosition(1u).y);edkEnd();
            outTemp.setVertexUV(3u,outside.getVertexUV(0u).x,outside.getVertexUV(1u).y);edkEnd();
            outTemp.setVertexColor(3u,outside.getVertexColor(1u));edkEnd();
            //
            outTemp.setScale(outside.getScale());edkEnd();
            outTemp.setAngle(outside.getAngle());edkEnd();
            outTemp.setTranslate(outside.getTranslate());edkEnd();
            haveOut=true;edkEnd();
            out = &outTemp;edkEnd();
        }
    }
    //test the inside
    if(inside.getVertexCount()==2u && inside.isRect()){
        //create a new polygon with 4 vertexes
        if(inTemp.createPolygon(4u)){
            //
            inTemp.setVertexPosition(0u,inside.getVertexPosition(0u));edkEnd();
            inTemp.setVertexUV(0u,inside.getVertexUV(0u));edkEnd();
            inTemp.setVertexColor(0u,inside.getVertexColor(0u));edkEnd();
            //
            inTemp.setVertexPosition(1u,inside.getVertexPosition(1u).x,inside.getVertexPosition(0u).y);edkEnd();
            inTemp.setVertexUV(1u,inside.getVertexUV(1u).x,inside.getVertexUV(0u).y);edkEnd();
            inTemp.setVertexColor(1u,inside.getVertexColor(0u));edkEnd();
            //
            inTemp.setVertexPosition(2u,inside.getVertexPosition(1u));edkEnd();
            inTemp.setVertexUV(2u,inside.getVertexUV(1u));edkEnd();
            inTemp.setVertexColor(2u,inside.getVertexColor(1u));edkEnd();
            //
            inTemp.setVertexPosition(3u,inside.getVertexPosition(0u).x,inside.getVertexPosition(1u).y);edkEnd();
            inTemp.setVertexUV(3u,inside.getVertexUV(0u).x,inside.getVertexUV(1u).y);edkEnd();
            inTemp.setVertexColor(3u,inside.getVertexColor(1u));edkEnd();
            //
            inTemp.setScale(inside.getScale());edkEnd();
            inTemp.setAngle(inside.getAngle());edkEnd();
            inTemp.setTranslate(inside.getTranslate());edkEnd();
            haveIn=true;edkEnd();
            in = &inTemp;edkEnd();
        }
    }

    //test the size of the polygons
    edk::uint32 countOutside = out->getVertexCount();edkEnd();
    edk::uint32 countInside = in->getVertexCount();edkEnd();

    if(countOutside>=3u && countInside>=3u){
        //create a new polygon to be triangulated
        edk::shape::Lines2D poly;edkEnd();
        if(poly.createPolygon(countOutside + countInside + 2u)){
            //get the position of the first inside vertex with the lowest angle
            edk::uint32 j;edkEnd();
            edk::uint32 size;edkEnd();
            edk::uint32 insideFirstPosition = 0u;edkEnd();
            edk::uint32 outsideFirstPosition = 0u;edkEnd();
            edk::float32 angle = 360.f;edkEnd();
            edk::float32 angleNew = 360.f;edkEnd();
            angle = edk::Math::getAngle(in->getVertexPositionTransformed(insideFirstPosition));edkEnd();
            size = countInside;edkEnd();
            for(edk::uint32 i=1u;i<size;i++){
                //test the other vertexes
                if((angleNew = edk::Math::getAngle(in->getVertexPositionTransformed(i)))<angle){
                    angle = angleNew;edkEnd();
                    insideFirstPosition = i;edkEnd();
                }
            }

            //then get the outside last position
            angle = edk::Math::getAngle(out->getVertexPositionTransformed(outsideFirstPosition));edkEnd();
            size = countOutside;edkEnd();
            for(edk::uint32 i=1u;i<size;i++){
                //test the other vertexes
                if((angleNew = edk::Math::getAngle(out->getVertexPositionTransformed(i)))<angle){
                    angle = angleNew;edkEnd();
                    outsideFirstPosition = i;edkEnd();
                }
            }
            //copy the inside vertexes in to the new polygon
            j=insideFirstPosition;edkEnd();
            size = countInside;edkEnd();
            if(in->isCounterclockwise()){
                for(edk::uint32 i=0u;i<size;i++){
                    //copy yhe vertex
                    poly.setVertexPosition(i,in->getVertexPositionTransformed(j));edkEnd();
                    poly.setVertexUV(i,in->getVertexUV(j));edkEnd();
                    poly.setVertexColor(i,in->getVertexColor(j));edkEnd();
                    if(!j){
                        j=countInside;edkEnd();
                    }
                    j--;edkEnd();
                }
            }
            else{
                for(edk::uint32 i=0u;i<size;i++){
                    //copy yhe vertex
                    poly.setVertexPosition(i,in->getVertexPositionTransformed(j));edkEnd();
                    poly.setVertexUV(i,in->getVertexUV(j));edkEnd();
                    poly.setVertexColor(i,in->getVertexColor(j));edkEnd();
                    j++;edkEnd();
                    if(j>=countInside){
                        j=0u;
                    }
                }
            }
            //copy the first vertex inside
            poly.setVertexPosition(size,in->getVertexPositionTransformed(insideFirstPosition)+vertexDistanceIncrement);edkEnd();
            poly.setVertexUV(size,in->getVertexUV(insideFirstPosition)+vertexDistanceIncrement);edkEnd();
            poly.setVertexColor(size,in->getVertexColor(insideFirstPosition));edkEnd();

            //Now it will copy the outside polygons in decresent order
            j=outsideFirstPosition;edkEnd();
            size = countInside+1u+countOutside;edkEnd();
            if(out->isCounterclockwise()){
                for(edk::uint32 i=countInside+1u;i<size;i++){
                    //copy yhe vertex
                    poly.setVertexPosition(i,out->getVertexPositionTransformed(j));edkEnd();
                    poly.setVertexUV(i,out->getVertexUV(j));edkEnd();
                    poly.setVertexColor(i,out->getVertexColor(j));edkEnd();
                    j++;edkEnd();
                    if(j>=countOutside){
                        j=0u;
                    }
                }
            }
            else{
                for(edk::uint32 i=countInside+1u;i<size;i++){
                    //copy yhe vertex
                    poly.setVertexPosition(i,out->getVertexPositionTransformed(j));edkEnd();
                    poly.setVertexUV(i,out->getVertexUV(j));edkEnd();
                    poly.setVertexColor(i,out->getVertexColor(j));edkEnd();
                    if(!j){
                        j=countOutside;edkEnd();
                    }
                    j--;edkEnd();
                }
            }

            //in the end it copy the past vertex for outside
            poly.setVertexPosition(size,out->getVertexPositionTransformed(outsideFirstPosition)+vertexDistanceIncrement);edkEnd();
            poly.setVertexUV(size,out->getVertexUV(outsideFirstPosition)+vertexDistanceIncrement);edkEnd();
            poly.setVertexColor(size,out->getVertexColor(outsideFirstPosition));edkEnd();

            //then generate the triangularization for the polygon
            ret = edk::shape::Mesh2D::polygonTriangularization(poly,this);edkEnd();

            //delete the polygon
            poly.deletePolygon();edkEnd();
        }
    }
    if(haveIn){
        inTemp.deletePolygon();edkEnd();
    }
    if(haveOut){
        outTemp.deletePolygon();edkEnd();
    }
    outside.cantDeletePolygon();edkEnd();
    inside.cantDeletePolygon();edkEnd();
    return ret;
}

bool edk::shape::Mesh2D::putHoleInRectangle(edk::rectf32 rect,edk::shape::Polygon2D inside){
    bool ret = false;edkEnd();
    //create the rectangle
    edk::shape::Polygon2D poly;edkEnd();
    if(poly.createPolygon(4u)){
        //
        //set the vertexes
        poly.setVertexPosition(0u,rect.origin.x,rect.origin.y);edkEnd();
        poly.setVertexPosition(1u,rect.size.width,rect.origin.y);edkEnd();
        poly.setVertexPosition(2u,rect.size.width,rect.size.height);edkEnd();
        poly.setVertexPosition(3u,rect.origin.x,rect.size.height);edkEnd();

        //run the function to put a hole inside the polygon
        ret = this->putHoleInPolygon(poly,inside);edkEnd();

        poly.deletePolygon();edkEnd();
    }
    inside.cantDeletePolygon();edkEnd();
    return ret;
}

//vertexTriangularization the mesh with the triangles
bool edk::shape::Mesh2D::vertexTriangularization(edk::vector::Stack<edk::vec2f32>* vertexes,edk::shape::Mesh2D *mesh){
    bool ret=false;edkEnd();
    if(vertexes && mesh){
        treeTriangles tree;edkEnd();
        //test all the vertex to create all the polygons
        edk::uint32 size = vertexes->size();edkEnd();
        edk::uint32 psize = 0u;edkEnd();
        edk::uint32 vsize = 0u;edkEnd();
        edk::uint32 csize = 0u;edkEnd();
        edk::shape::Triangle2D tri;edkEnd();
        edk::shape::Triangle2D triPoint;edkEnd();
        edk::uint8 goContinue=0u;
        edk::vec2f32 p1;edkEnd();
        edk::vec2f32 p2;edkEnd();
        edk::vec2f32 t1;edkEnd();
        edk::vec2f32 t2;edkEnd();
        edk::collision::Vecs2f32 collision;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            for(edk::uint32 j=0u;j<size;j++){
                if(j==i){
                    continue;
                }
                for(edk::uint32 k=0u;k<size;k++){
                    if(k==i){
                        continue;
                    }
                    if(k==j){
                        continue;
                    }
                    /*
                    printf("\nTri %u %u %u",i,j,k);edkEnd();
*/
                    //test if aready have the triangle on the tree
                    if(!tree.haveTriangle(i,j,k)){
                        //if not then test the new poligon internesctions

                        //create the triangle and test if it's counter clockwise
                        tri.setVertexPosition(0u,vertexes->get(i).x,vertexes->get(i).y);edkEnd();
                        tri.setVertexPosition(1u,vertexes->get(j).x,vertexes->get(j).y);edkEnd();
                        tri.setVertexPosition(2u,vertexes->get(k).x,vertexes->get(k).y);edkEnd();

                        if(tri.isCounterclockwise()){

                            //test if the triangle have a vertex inside
                            for(edk::uint32 l=0u;l<size;l++){
                                if(l==i){
                                    continue;
                                }
                                if(l==j){
                                    continue;
                                }
                                if(l==k){
                                    continue;
                                }
                                triPoint.setVertexPosition(0u,vertexes->get(i));edkEnd();
                                triPoint.setVertexPosition(1u,vertexes->get(j));edkEnd();
                                triPoint.setVertexPosition(2u,vertexes->get(l));edkEnd();
                                if(triPoint.isCounterclockwise()){
                                    //
                                    triPoint.setVertexPosition(0u,vertexes->get(j));edkEnd();
                                    triPoint.setVertexPosition(1u,vertexes->get(k));edkEnd();
                                    triPoint.setVertexPosition(2u,vertexes->get(l));edkEnd();
                                    if(triPoint.isCounterclockwise()){
                                        //
                                        triPoint.setVertexPosition(0u,vertexes->get(k));edkEnd();
                                        triPoint.setVertexPosition(1u,vertexes->get(i));edkEnd();
                                        triPoint.setVertexPosition(2u,vertexes->get(l));edkEnd();
                                        if(triPoint.isCounterclockwise()){
                                            //
                                            goContinue=false;edkEnd();
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
                            psize = mesh->getPolygonSize();edkEnd();
                            for(edk::uint32 m=0u;m<psize;m++){
                                mesh->selectPolygon(m);edkEnd();
                                vsize = mesh->selectedGetVertexCount();edkEnd();
                                if(vsize){
                                    vsize--;edkEnd();
                                }
                                for(edk::uint32 n=0u;n<vsize;n++){
                                    //
                                    p1 = mesh->selectedGetVertexPosition(n);edkEnd();
                                    p2 = mesh->selectedGetVertexPosition(n+1u);edkEnd();

                                    //test intersection with all

                                    //0 1
                                    t1 = tri.getVertexPosition(0u);edkEnd();
                                    t2 = tri.getVertexPosition(1u);edkEnd();
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,n,p1.x,p1.y
                                           ,n+1u,p2.x,p2.y
                                           ,0u,t1.x,t1.y
                                           ,1u,t2.x,t2.y
                                           );edkEnd();
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );edkEnd();
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);edkEnd();
                                        /*
                                        printf("\nCollision size %u",collision.size());edkEnd();
*/
                                        if(collision.size()){
                                            csize = collision.size();edkEnd();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );edkEnd();
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
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();
*/
                                                    goContinue++;edkEnd();
                                                    break;
                                                }
                                            }
                                            collision.clean();edkEnd();
                                        }
                                    }

                                    //1 2
                                    t1 = tri.getVertexPosition(1u);edkEnd();
                                    t2 = tri.getVertexPosition(2u);edkEnd();
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,n,p1.x,p1.y
                                           ,n+1u,p2.x,p2.y
                                           ,1u,t1.x,t1.y
                                           ,2u,t2.x,t2.y
                                           );edkEnd();
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );edkEnd();
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);edkEnd();
                                        /*
                                        printf("\nCollision size %u",collision.size());edkEnd();
*/
                                        if(collision.size()){
                                            csize = collision.size();edkEnd();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );edkEnd();
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
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();
*/
                                                    goContinue++;edkEnd();
                                                    break;
                                                }
                                            }
                                            collision.clean();edkEnd();
                                        }
                                    }

                                    //2 0
                                    t1 = tri.getVertexPosition(2u);edkEnd();
                                    t2 = tri.getVertexPosition(0u);edkEnd();
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,n,p1.x,p1.y
                                           ,n+1u,p2.x,p2.y
                                           ,2u,t1.x,t1.y
                                           ,0u,t2.x,t2.y
                                           );edkEnd();
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );edkEnd();
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);edkEnd();
                                        /*
                                        printf("\nCollision size %u",collision.size());edkEnd();
*/
                                        if(collision.size()){
                                            csize = collision.size();edkEnd();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );edkEnd();
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
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();
*/
                                                    goContinue++;edkEnd();
                                                    break;
                                                }
                                            }
                                            collision.clean();edkEnd();
                                        }
                                    }
                                }
                                //test the last internection
                                if(!goContinue){
                                    //
                                    p1 = mesh->selectedGetVertexPosition(vsize);edkEnd();
                                    p2 = mesh->selectedGetVertexPosition(0u);edkEnd();

                                    //test intersection with all

                                    //0 1
                                    t1 = tri.getVertexPosition(0u);edkEnd();
                                    t2 = tri.getVertexPosition(1u);edkEnd();
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,vsize,p1.x,p1.y
                                           ,0u,p2.x,p2.y
                                           ,0u,t1.x,t1.y
                                           ,1u,t2.x,t2.y
                                           );edkEnd();
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );edkEnd();
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);edkEnd();
                                        /*
                                        printf("\nCollision size %u",collision.size());edkEnd();
*/
                                        if(collision.size()){
                                            csize = collision.size();edkEnd();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );edkEnd();
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
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();
*/
                                                    goContinue++;edkEnd();
                                                    break;
                                                }
                                            }
                                            collision.clean();edkEnd();
                                        }
                                    }

                                    //1 2
                                    t1 = tri.getVertexPosition(1u);edkEnd();
                                    t2 = tri.getVertexPosition(2u);edkEnd();
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,vsize,p1.x,p1.y
                                           ,0u,p2.x,p2.y
                                           ,1u,t1.x,t1.y
                                           ,2u,t2.x,t2.y
                                           );edkEnd();
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );edkEnd();
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);edkEnd();
                                        /*
                                        printf("\nCollision size %u",collision.size());edkEnd();
*/
                                        if(collision.size()){
                                            csize = collision.size();edkEnd();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );edkEnd();
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
                                                       );edkEnd();
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
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();
*/
                                                    goContinue++;edkEnd();
                                                    break;
                                                }
                                            }
                                            collision.clean();edkEnd();
                                        }
                                    }

                                    //2 0
                                    t1 = tri.getVertexPosition(2u);edkEnd();
                                    t2 = tri.getVertexPosition(0u);edkEnd();
                                    /*
                                    printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                           "p2 == [%u] %.2f %.2f "
                                           "t1 == [%u] %.2f %.2f "
                                           "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                           ,vsize,p1.x,p1.y
                                           ,0u,p2.x,p2.y
                                           ,2u,t1.x,t1.y
                                           ,0u,t2.x,t2.y
                                           );edkEnd();
*/
                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){
                                        /*
                                        printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                               ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                               );edkEnd();
*/
                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);edkEnd();
                                        /*
                                        printf("\nCollision size %u",collision.size());edkEnd();
*/
                                        if(collision.size()){
                                            csize = collision.size();edkEnd();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );edkEnd();
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
                                                    printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();
*/
                                                    goContinue++;edkEnd();
                                                    break;
                                                }
                                            }
                                            collision.clean();edkEnd();
                                        }
                                    }
                                }
                                if(goContinue>1u){
                                    break;
                                }
                            }
                            if(goContinue>0u){
                                goContinue=0u;
                                continue;
                            }

                            //create the polygon
                            /*
                            printf("\n    Create %u %u %u",i,j,k);edkEnd();
*/

                            //add to the tree
                            tree.newTriangle(i,j,k);edkEnd();

                            //add the tri on the mesh
                            mesh->addPolygon(tri);edkEnd();

                            ret=true;edkEnd();
                        }
                    }
                }
            }
        }
    }
    return ret;
}
bool edk::shape::Mesh2D::polygonTriangularization(edk::shape::Polygon2D polygon,edk::shape::Mesh2D *mesh){
    bool ret=false;edkEnd();
    edk::shape::Triangle2D tri;edkEnd();
    edk::shape::Triangle2D triPoint;edkEnd();
    edk::vector::Stack<edk::vec2f32> pConcaves;edkEnd();
    edk::uint32 concaveActual=0u;
    edk::uint32 concaveFirst=0u;
    edk::shape::Polygon2D polyTemp;edkEnd();
    edk::uint32 sizeVertexes = polygon.getVertexCount();edkEnd();
    edk::uint32 size = sizeVertexes;edkEnd();
    edk::float32 angle = 0.f;edkEnd();
    if(size>=3u && mesh){
        //search for the concave vertexes
        size-=2u;edkEnd();
        //calculate if the point is inside the triangle
        angle = edk::Math::getAngle(polygon.getVertexPosition(0u)-polygon.getVertexPosition(size+1u)) -
                edk::Math::getAngle(polygon.getVertexPosition(1u)-polygon.getVertexPosition(size+1u));edkEnd();
        if(angle<0.f){
            angle+=360.f;edkEnd();
        }
        /*
        printf("\nvertex 0u Angle == %.2f"
               ,angle
               );edkEnd();
*/
        if(angle<=180.f){
            /*
            printf(" concave");edkEnd();
*/
            if(!pConcaves.size()){
                concaveFirst = 0u;edkEnd();
            }
            pConcaves.pushBack(polygon.getVertexPosition(0u));edkEnd();
            concaveActual = 0u;edkEnd();
        }
        /*
        else{
            printf(" convex");edkEnd();
        }
*/
        bool goBreak=false;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //test the two lines
            //calculate if the point is inside the triangle
            angle = edk::Math::getAngle(polygon.getVertexPosition(i+1u)-polygon.getVertexPosition(i)) -
                    edk::Math::getAngle(polygon.getVertexPosition(i+2u)-polygon.getVertexPosition(i));edkEnd();
            if(angle<0.f){
                angle+=360.f;edkEnd();
            }
            /*
            printf("\nvertex %uu Angle == %.2f"
                   ,i+1u
                   ,angle
                   );edkEnd();
*/
            if(angle<=180.f){
                /*
                printf(" concave");edkEnd();
*/
                if(!pConcaves.size()){
                    concaveFirst = i+1u;edkEnd();
                }
                pConcaves.pushBack(polygon.getVertexPosition(i+1u));edkEnd();
                concaveActual = i+1u;edkEnd();
            }
            else{
                /*
                printf(" convex");edkEnd();
*/
                //then create the triangle
                if(pConcaves.size()){
                    //join the concave, the convex and the next vertex to create a triangle
                    /*
                    printf("\n%u Create triangle %u %u %u",__LINE__
                           ,concaveActual
                           ,i+1u
                           ,i+2u
                           );edkEnd();
*/
                    tri.setVertexPosition(0u,polygon.getVertexPosition(concaveActual).x,polygon.getVertexPosition(concaveActual).y);edkEnd();
                    tri.setVertexPosition(1u,polygon.getVertexPosition(i+1u).x,polygon.getVertexPosition(i+1u).y);edkEnd();
                    tri.setVertexPosition(2u,polygon.getVertexPosition(i+2u).x,polygon.getVertexPosition(i+2u).y);edkEnd();
                    if(tri.isCounterclockwise()){
                        /*
                        printf(" isCounterClockwise");edkEnd();
*/
                        //test if the triangle have a vertex inside
                        bool goContinue = true;edkEnd();
                        for(edk::uint32 l=0u;l<sizeVertexes;l++){
                            if(l!=concaveActual && l!= i+1u && l!=i+2u){

                                triPoint.setVertexPosition(0u,tri.getVertexPosition(0u));edkEnd();
                                triPoint.setVertexPosition(1u,tri.getVertexPosition(1u));edkEnd();
                                triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));edkEnd();
                                if(triPoint.isCounterclockwise()){
                                    //
                                    triPoint.setVertexPosition(0u,tri.getVertexPosition(1u));edkEnd();
                                    triPoint.setVertexPosition(1u,tri.getVertexPosition(2u));edkEnd();
                                    triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));edkEnd();
                                    if(triPoint.isCounterclockwise()){
                                        //
                                        triPoint.setVertexPosition(0u,tri.getVertexPosition(2u));edkEnd();
                                        triPoint.setVertexPosition(1u,tri.getVertexPosition(0u));edkEnd();
                                        triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));edkEnd();
                                        if(triPoint.isCounterclockwise()){
                                            //
                                            goContinue=false;edkEnd();
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if(goContinue){
                            mesh->addPolygon(tri);edkEnd();
                            /*
                            printf(" addPolygon");edkEnd();
*/
                        }
                        else{
                            /*
                            printf(" notAddPolygon");edkEnd();
*/
                            //add the vertex as a concave
                            if(!pConcaves.size()){
                                concaveFirst = i+1u;edkEnd();
                            }
                            pConcaves.pushBack(polygon.getVertexPosition(i+1u));edkEnd();
                            concaveActual = i+1u;edkEnd();
                        }
                    }
                    else{
                        /*
                        printf(" isNOTCounterClockwise");edkEnd();
*/
                        goBreak=true;edkEnd();
                        break;
                    }
                }


            }
        }

        if(!goBreak){
            //calculate if the point is inside the triangle
            angle = edk::Math::getAngle(polygon.getVertexPosition(size+1u)-polygon.getVertexPosition(size)) -
                    edk::Math::getAngle(polygon.getVertexPosition(0u)-polygon.getVertexPosition(size));edkEnd();
            if(angle<0.f){
                angle+=360.f;edkEnd();
            }
            /*
            printf("\nvertex %uu Angle == %.2f"
                   ,size+1u
                   ,angle
                   );edkEnd();
*/
            if(angle<=180.f){
                /*
                printf(" concave");edkEnd();
*/
                if(!pConcaves.size()){
                    concaveFirst = size+1u;edkEnd();
                }
                pConcaves.pushBack(polygon.getVertexPosition(size+1u));edkEnd();
                concaveActual = size+1u;edkEnd();
            }
            else{
                /*
                printf(" convex");edkEnd();
*/

                //then create the triangle
                if(pConcaves.size()){
                    //join the concave, the convex and the next vertex to create a triangle
                    /*
                    printf("\n%u Create triangle %u %u %u",__LINE__
                           ,concaveActual
                           ,size+1u
                           ,0u
                           );edkEnd();
*/
                    tri.setVertexPosition(0u,polygon.getVertexPosition(concaveActual).x,polygon.getVertexPosition(concaveActual).y);edkEnd();
                    tri.setVertexPosition(1u,polygon.getVertexPosition(size+1u).x,polygon.getVertexPosition(size+1u).y);edkEnd();
                    tri.setVertexPosition(2u,polygon.getVertexPosition(0u).x,polygon.getVertexPosition(0u).y);edkEnd();
                    if(tri.isCounterclockwise()){
                        /*
                        printf(" isCounterClockwise");edkEnd();
*/
                        //test if the triangle have a vertex inside
                        bool goContinue = true;edkEnd();
                        for(edk::uint32 l=0u;l<sizeVertexes;l++){
                            if(l!=concaveActual && l!= size+1u && l!=0u){

                                triPoint.setVertexPosition(0u,tri.getVertexPosition(0u));edkEnd();
                                triPoint.setVertexPosition(1u,tri.getVertexPosition(1u));edkEnd();
                                triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));edkEnd();
                                if(triPoint.isCounterclockwise()){
                                    //
                                    triPoint.setVertexPosition(0u,tri.getVertexPosition(1u));edkEnd();
                                    triPoint.setVertexPosition(1u,tri.getVertexPosition(2u));edkEnd();
                                    triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));edkEnd();
                                    if(triPoint.isCounterclockwise()){
                                        //
                                        triPoint.setVertexPosition(0u,tri.getVertexPosition(2u));edkEnd();
                                        triPoint.setVertexPosition(1u,tri.getVertexPosition(0u));edkEnd();
                                        triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));edkEnd();
                                        if(triPoint.isCounterclockwise()){
                                            //
                                            goContinue=false;edkEnd();
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if(goContinue){
                            mesh->addPolygon(tri);edkEnd();
                            /*
                            printf(" addPolygon");edkEnd();
*/
                        }
                        else{
                            /*
                            printf(" notAddPolygon");edkEnd();
*/
                            //add the vertex as a concave
                            if(!pConcaves.size()){
                                concaveFirst = size+1u;edkEnd();
                            }
                            pConcaves.pushBack(polygon.getVertexPosition(size+1u));edkEnd();
                            concaveActual = size+1u;edkEnd();
                        }
                    }
                    else{
                        /*
                        printf(" isNOTCounterClockwise");edkEnd();
*/
                        goBreak=true;edkEnd();
                    }
                }
            }
        }




        if(!goBreak){
            //test if have vertexes before the first concave
            if(concaveFirst){
                //test the vertexes
                for(edk::uint32 i=0u;i<concaveFirst;i++){
                    //
                    /*
                    printf("\n%u Create triangle %u %u %u",__LINE__
                           ,concaveActual
                           ,i
                           ,i+1u
                           );edkEnd();
*/
                    tri.setVertexPosition(0u,polygon.getVertexPosition(concaveActual).x,polygon.getVertexPosition(concaveActual).y);edkEnd();
                    tri.setVertexPosition(1u,polygon.getVertexPosition(i).x,polygon.getVertexPosition(i).y);edkEnd();
                    tri.setVertexPosition(2u,polygon.getVertexPosition(i+1u).x,polygon.getVertexPosition(i+1u).y);edkEnd();
                    if(tri.isCounterclockwise()){

                        /*
                        printf(" isCounterClockwise");edkEnd();
*/
                        //test if the triangle have a vertex inside
                        bool goContinue = true;edkEnd();
                        for(edk::uint32 l=0u;l<sizeVertexes;l++){
                            if(l!=concaveActual && l!= i && l!=i+1u){

                                triPoint.setVertexPosition(0u,tri.getVertexPosition(0u));edkEnd();
                                triPoint.setVertexPosition(1u,tri.getVertexPosition(1u));edkEnd();
                                triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));edkEnd();
                                if(triPoint.isCounterclockwise()){
                                    //
                                    triPoint.setVertexPosition(0u,tri.getVertexPosition(1u));edkEnd();
                                    triPoint.setVertexPosition(1u,tri.getVertexPosition(2u));edkEnd();
                                    triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));edkEnd();
                                    if(triPoint.isCounterclockwise()){
                                        //
                                        triPoint.setVertexPosition(0u,tri.getVertexPosition(2u));edkEnd();
                                        triPoint.setVertexPosition(1u,tri.getVertexPosition(0u));edkEnd();
                                        triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));edkEnd();
                                        if(triPoint.isCounterclockwise()){
                                            //
                                            goContinue=false;edkEnd();
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if(goContinue){
                            mesh->addPolygon(tri);edkEnd();
                            /*
                            printf(" addPolygon");edkEnd();
*/
                        }
                        else{
                            /*
                            printf(" notAddPolygon");edkEnd();
*/
                            //add the vertex as a concave
                            if(!pConcaves.size()){
                                concaveFirst = i;edkEnd();
                            }
                            pConcaves.pushBack(polygon.getVertexPosition(i));edkEnd();
                            concaveActual = i;edkEnd();
                        }
                    }
                    else{
                        /*
                        printf(" isNOTCounterClockwise");edkEnd();
*/
                        goBreak=true;edkEnd();
                    }
                }
            }
        }

        if(!goBreak){
            ret = true;edkEnd();
            size = pConcaves.size();edkEnd();
            //test if have concaves
            if(size){
                //draw a polyTemp with the concaves
                polyTemp.createPolygon(size);edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    polyTemp.setVertexPosition(i,pConcaves.get(i).x,pConcaves.get(i).y);edkEnd();
                }
                //run the same function with the polyTemp
                edk::shape::Mesh2D::polygonTriangularization(polyTemp,mesh);edkEnd();
            }
            else{
                //run the simple vertex triangularization
                edk::vector::Stack<edk::vec2f32> vertexes;edkEnd();
                edk::uint32 size = polygon.getVertexCount();edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    vertexes.pushBack(edk::vec2f32(polygon.getVertexPosition(i)));edkEnd();
                }
                edk::shape::Mesh2D::vertexTriangularization(&vertexes,mesh);edkEnd();
            }
        }
    }
    polygon.cantDeletePolygon();edkEnd();
    return ret;
}

void edk::shape::Mesh2D::cantDeleteMesh(){
    canDeleteMesh=false;edkEnd();
}
//XML
bool edk::shape::Mesh2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon2DList::writeToXML(xml,id)){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //write the material
                    this->material.writeToXML(xml,0u);edkEnd();
                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::shape::Mesh2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon2DList::readFromXML(xml,id)){
        bool ret=true;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);edkEnd();
            if(name){
                //select the name
                if(xml->selectChild(name)){
                    //read the material
                    this->material.readFromXML(xml,0u);edkEnd();
                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::shape::Mesh2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon2DList::readFromXML(xml,id)){
        bool ret=true;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"mesh_",nameID);edkEnd();
            if(name){
                //select the name
                if(xml->selectChild(name)){
                    //read the material
                    this->material.readFromXMLFromPack(pack,xml,0u);edkEnd();
                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}

bool edk::shape::Mesh2D::cloneFrom(edk::shape::Mesh2D* mesh){
    if(mesh){
        //
        edk::shape::Mesh2D::TreeAnimations tree;edkEnd();

        //delete the polygons
        this->cleanPolygons();edkEnd();
        //read the polygons
        register edk::uint32 size = mesh->polygons.size();edkEnd();
        edk::uint32 select=0u;
        edk::shape::Polygon2D* temp = NULL;edkEnd();
        edk::uint32 id;edkEnd();
        edk::animation::Interpolation1DGroup* animTemp=NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            temp=mesh->polygons.get(i);edkEnd();
            if(temp){
                if(temp==mesh->selected){
                    select=i;edkEnd();
                }
                id=this->addPolygon(*temp);edkEnd();

                //test the animation
                animTemp = temp->framesGetAnimation();edkEnd();
                if(animTemp){
                    //test if already have the animation on the tree
                    if(tree.haveAnimation(animTemp)){
                        //set the animation to the polygon in the mesh
                        this->copyAnimationFramesToPolygon(tree.getAnimationID(animTemp),id);edkEnd();
                    }
                    else{
                        //add the animation on the tree
                        if(tree.addAnimations(animTemp,id)){
                            //create a new animation in the polygon
                            if(this->setAnimationFramesToPolygon(id)){
                                //copy the animation
                                this->copyThisAnimationFramesToPolygon(animTemp,id);edkEnd();
                            }
                        }
                    }
                }
            }
        }
        this->selectPolygon(select);edkEnd();
        //test if have animation selected
        if(mesh->haveSelectedAnimation()){
            //Set the ID of the animation selected
            this->selectAnimationFramesFromPolygon(mesh->getAnimationFramesSelectedID());edkEnd();
        }
        mesh->cantDeleteList();edkEnd();

        this->material = mesh->material;edkEnd();
        return true;
    }
    return false;
}
