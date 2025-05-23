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

edk::shape::Mesh2D::Mesh2D(){
    this->classThis=NULL;
    this->Constructor();
}

edk::shape::Mesh2D::~Mesh2D(){
    this->Destructor();
}

void edk::shape::Mesh2D::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->material.Constructor();

        this->polygons.clean(2u);
        //clean the selected
        this->freeSelected();
    }
}
void edk::shape::Mesh2D::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->clean();

        this->material.Destructor();
    }
}

inline bool edk::shape::Mesh2D::floatDifferent(edk::float32 f1,edk::float32 f2){
    if((f1<f2-0.0001f || f1>f2+0.0001f)){
        return true;
    }
    return false;
}
bool edk::shape::Mesh2D::pointInsideLine(edk::vec2f32 point,edk::vec2f32 lineStart,edk::vec2f32 lineEnd){
    //printf("\n%u %s %s point %.2f %.2f lineStart %.2f %.2f lineEnd %.2f %.2f pointStraigh2D %s"
    //       ,__LINE__,__FILE__,__func__
    //       ,point.x
    //       ,point.y
    //       ,lineStart.x
    //       ,lineStart.y
    //       ,lineEnd.x
    //       ,lineEnd.y
    //       ,edk::collision::MathCollision::pointStraigh2D(point,lineStart,lineEnd,0.01f)?"true":"false"
    //       );

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

    //printf("\n%u %s %s point %.2f %.2f pStart %.2f %.2f pEnd %.2f %.2f"
    //       ,__LINE__,__FILE__,__func__
    //       ,point.x
    //       ,point.y
    //       ,pStart.x
    //       ,pStart.y
    //       ,pEnd.x
    //       ,pEnd.y
    //       );

    if(edk::collision::MathCollision::pointStraigh2D(point,lineStart,lineEnd,0.01f)
            &&
            point.x>=pStart.x && point.x<=pEnd.x
            &&
            point.y>=pStart.y && point.y<=pEnd.y
            ){
        /*
        printf(" TRUE");
*/
        return true;
    }
    /*
    printf(" FALSE");
*/
    return false;
}

//clean Mesh
void edk::shape::Mesh2D::clean(){
    this->cleanTextures();
    this->cleanPolygons();
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
void edk::shape::Mesh2D::drawWithoutMaterial(){
    this->drawPolygons();
}
void edk::shape::Mesh2D::drawNoTexture(){
    this->material.drawNoTexture();
    this->drawPolygons();
}
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
bool edk::shape::Mesh2D::selectedDrawMultiTexture(){
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
void edk::shape::Mesh2D::drawWire(){
    this->material.drawNoTexture();
    //else just draw the mesh
    this->drawWirePolygons();
}
bool edk::shape::Mesh2D::drawPolygonWithoutMaterial(edk::uint32 polygon){
    //
    return this->drawPolygon(polygon);
}
bool edk::shape::Mesh2D::drawPolygonNoTexture(edk::uint32 polygon){
    this->material.drawNoTexture();
    return this->drawPolygon(polygon);
}
bool edk::shape::Mesh2D::drawPolygonOneTexture(edk::uint32 polygon){
    bool ret = false;
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture();
        //Draw the mesh
        ret = this->drawPolygon(polygon);

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        ret = this->drawPolygon(polygon);
    }
    return ret;
}
bool edk::shape::Mesh2D::drawPolygonOneTexture(edk::uint32 polygon, edk::uint32 position){
    bool ret = false;
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture(position);
        //Draw the mesh
        ret = this->drawPolygon(polygon);

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        ret = this->drawPolygon(polygon);
    }
    return ret;
}
bool edk::shape::Mesh2D::drawPolygonMultiTexture(edk::uint32 polygon){
    bool ret = false;
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithMultiTexture();
        //Draw the mesh
        ret = this->drawPolygon(polygon);

        this->material.drawEndWithTexture();
    }
    else{
        this->material.drawNoTexture();
        //else just draw the mesh
        ret = this->drawPolygon(polygon);
    }
    return ret;
}
bool edk::shape::Mesh2D::drawPolygonWire(edk::uint32 polygon){
    this->material.drawNoTexture();
    //else just draw the mesh
    return this->drawWirePolygon(polygon);
}

bool edk::shape::Mesh2D::triangularizateFromVertex(edk::vector::Stack<edk::vec2f32>* vertexes){
    return edk::shape::Mesh2D::vertexTriangularization(vertexes,this);
}
bool edk::shape::Mesh2D::triangularizateFromPolygon(edk::shape::Polygon2D polygon){
    bool ret = edk::shape::Mesh2D::polygonTriangularization(polygon,this);
    return ret;
}
bool edk::shape::Mesh2D::putHoleInPolygon(edk::shape::Polygon2D outside,edk::shape::Polygon2D inside){
    bool ret = false;

    //test if have some polygon as rectanble with 2 vertexes
    edk::shape::Polygon2D* out = &outside;
    edk::shape::Polygon2D* in = &inside;
    edk::shape::Polygon2D outTemp;
    bool haveOut=false;
    edk::shape::Polygon2D inTemp;
    bool haveIn=false;
    //test the outside
    if(outside.getVertexCount()==2u && outside.isRect()){
        //create a new polygon with 4 vertexes
        if(outTemp.createPolygon(4u)){
            //
            outTemp.setVertexPosition(0u,outside.getVertexPosition(0u));
            outTemp.setVertexUV(0u,outside.getVertexUV(0u));
            outTemp.setVertexColor(0u,outside.getVertexColor(0u));
            //
            outTemp.setVertexPosition(1u,outside.getVertexPosition(1u).x,outside.getVertexPosition(0u).y);
            outTemp.setVertexUV(1u,outside.getVertexUV(1u).x,outside.getVertexUV(0u).y);
            outTemp.setVertexColor(1u,outside.getVertexColor(0u));
            //
            outTemp.setVertexPosition(2u,outside.getVertexPosition(1u));
            outTemp.setVertexUV(2u,outside.getVertexUV(1u));
            outTemp.setVertexColor(2u,outside.getVertexColor(1u));
            //
            outTemp.setVertexPosition(3u,outside.getVertexPosition(0u).x,outside.getVertexPosition(1u).y);
            outTemp.setVertexUV(3u,outside.getVertexUV(0u).x,outside.getVertexUV(1u).y);
            outTemp.setVertexColor(3u,outside.getVertexColor(1u));
            //
            outTemp.setScale(outside.getScale());
            outTemp.setAngle(outside.getAngle());
            outTemp.setTranslate(outside.getTranslate());
            haveOut=true;
            out = &outTemp;
        }
    }
    //test the inside
    if(inside.getVertexCount()==2u && inside.isRect()){
        //create a new polygon with 4 vertexes
        if(inTemp.createPolygon(4u)){
            //
            inTemp.setVertexPosition(0u,inside.getVertexPosition(0u));
            inTemp.setVertexUV(0u,inside.getVertexUV(0u));
            inTemp.setVertexColor(0u,inside.getVertexColor(0u));
            //
            inTemp.setVertexPosition(1u,inside.getVertexPosition(1u).x,inside.getVertexPosition(0u).y);
            inTemp.setVertexUV(1u,inside.getVertexUV(1u).x,inside.getVertexUV(0u).y);
            inTemp.setVertexColor(1u,inside.getVertexColor(0u));
            //
            inTemp.setVertexPosition(2u,inside.getVertexPosition(1u));
            inTemp.setVertexUV(2u,inside.getVertexUV(1u));
            inTemp.setVertexColor(2u,inside.getVertexColor(1u));
            //
            inTemp.setVertexPosition(3u,inside.getVertexPosition(0u).x,inside.getVertexPosition(1u).y);
            inTemp.setVertexUV(3u,inside.getVertexUV(0u).x,inside.getVertexUV(1u).y);
            inTemp.setVertexColor(3u,inside.getVertexColor(1u));
            //
            inTemp.setScale(inside.getScale());
            inTemp.setAngle(inside.getAngle());
            inTemp.setTranslate(inside.getTranslate());
            haveIn=true;
            in = &inTemp;
        }
    }

    //test the size of the polygons
    edk::uint32 countOutside = out->getVertexCount();
    edk::uint32 countInside = in->getVertexCount();

    if(countOutside>=3u && countInside>=3u){
        //create a new polygon to be triangulated
        edk::shape::Lines2D poly;
        if(poly.createPolygon(countOutside + countInside + 2u)){
            //get the position of the first inside vertex with the lowest angle
            edk::uint32 j;
            edk::uint32 size;
            edk::uint32 insideFirstPosition = 0u;
            edk::uint32 outsideFirstPosition = 0u;
            edk::float32 angle = 360.f;
            edk::float32 angleNew = 360.f;
            angle = edk::Math::getAngle(in->getVertexPositionTransformed(insideFirstPosition));
            size = countInside;
            for(edk::uint32 i=1u;i<size;i++){
                //test the other vertexes
                if((angleNew = edk::Math::getAngle(in->getVertexPositionTransformed(i)))<angle){
                    angle = angleNew;
                    insideFirstPosition = i;
                }
            }

            //then get the outside last position
            angle = edk::Math::getAngle(out->getVertexPositionTransformed(outsideFirstPosition));
            size = countOutside;
            for(edk::uint32 i=1u;i<size;i++){
                //test the other vertexes
                if((angleNew = edk::Math::getAngle(out->getVertexPositionTransformed(i)))<angle){
                    angle = angleNew;
                    outsideFirstPosition = i;
                }
            }
            //copy the inside vertexes in to the new polygon
            j=insideFirstPosition;
            size = countInside;
            if(in->isCounterclockwise()){
                for(edk::uint32 i=0u;i<size;i++){
                    //copy yhe vertex
                    poly.setVertexPosition(i,in->getVertexPositionTransformed(j));
                    poly.setVertexUV(i,in->getVertexUV(j));
                    poly.setVertexColor(i,in->getVertexColor(j));
                    if(!j){
                        j=countInside;
                    }
                    j--;
                }
            }
            else{
                for(edk::uint32 i=0u;i<size;i++){
                    //copy yhe vertex
                    poly.setVertexPosition(i,in->getVertexPositionTransformed(j));
                    poly.setVertexUV(i,in->getVertexUV(j));
                    poly.setVertexColor(i,in->getVertexColor(j));
                    j++;
                    if(j>=countInside){
                        j=0u;
                    }
                }
            }
            //copy the first vertex inside
            poly.setVertexPosition(size,in->getVertexPositionTransformed(insideFirstPosition)+vertexDistanceIncrement);
            poly.setVertexUV(size,in->getVertexUV(insideFirstPosition)+vertexDistanceIncrement);
            poly.setVertexColor(size,in->getVertexColor(insideFirstPosition));

            //Now it will copy the outside polygons in decresent order
            j=outsideFirstPosition;
            size = countInside+1u+countOutside;
            if(out->isCounterclockwise()){
                for(edk::uint32 i=countInside+1u;i<size;i++){
                    //copy yhe vertex
                    poly.setVertexPosition(i,out->getVertexPositionTransformed(j));
                    poly.setVertexUV(i,out->getVertexUV(j));
                    poly.setVertexColor(i,out->getVertexColor(j));
                    j++;
                    if(j>=countOutside){
                        j=0u;
                    }
                }
            }
            else{
                for(edk::uint32 i=countInside+1u;i<size;i++){
                    //copy yhe vertex
                    poly.setVertexPosition(i,out->getVertexPositionTransformed(j));
                    poly.setVertexUV(i,out->getVertexUV(j));
                    poly.setVertexColor(i,out->getVertexColor(j));
                    if(!j){
                        j=countOutside;
                    }
                    j--;
                }
            }

            //in the end it copy the past vertex for outside
            poly.setVertexPosition(size,out->getVertexPositionTransformed(outsideFirstPosition)+vertexDistanceIncrement);
            poly.setVertexUV(size,out->getVertexUV(outsideFirstPosition)+vertexDistanceIncrement);
            poly.setVertexColor(size,out->getVertexColor(outsideFirstPosition));

            //then generate the triangularization for the polygon
            ret = edk::shape::Mesh2D::polygonTriangularization(poly,this);

            //delete the polygon
            poly.deletePolygon();
        }
    }
    if(haveIn){
        inTemp.deletePolygon();
    }
    if(haveOut){
        outTemp.deletePolygon();
    }
    return ret;
}

bool edk::shape::Mesh2D::putHoleInRectangle(edk::rectf32 rect,edk::shape::Polygon2D inside){
    bool ret = false;
    //create the rectangle
    edk::shape::Polygon2D poly;
    if(poly.createPolygon(4u)){
        //
        //set the vertexes
        poly.setVertexPosition(0u,rect.origin.x,rect.origin.y);
        poly.setVertexPosition(1u,rect.size.width,rect.origin.y);
        poly.setVertexPosition(2u,rect.size.width,rect.size.height);
        poly.setVertexPosition(3u,rect.origin.x,rect.size.height);

        //run the function to put a hole inside the polygon
        ret = this->putHoleInPolygon(poly,inside);

        poly.deletePolygon();
    }
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
        edk::shape::Triangle2D triPoint;
        edk::uint8 goContinue=0u;
        edk::vec2f32 p1;
        edk::vec2f32 p2;
        edk::vec2f32 t1;
        edk::vec2f32 t2;
        edk::collision::Vecs2f32 collision;
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
                    printf("\nTri %u %u %u",i,j,k);
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
                                if(l==i){
                                    continue;
                                }
                                if(l==j){
                                    continue;
                                }
                                if(l==k){
                                    continue;
                                }
                                triPoint.setVertexPosition(0u,vertexes->get(i));
                                triPoint.setVertexPosition(1u,vertexes->get(j));
                                triPoint.setVertexPosition(2u,vertexes->get(l));
                                if(triPoint.isCounterclockwise()){
                                    //
                                    triPoint.setVertexPosition(0u,vertexes->get(j));
                                    triPoint.setVertexPosition(1u,vertexes->get(k));
                                    triPoint.setVertexPosition(2u,vertexes->get(l));
                                    if(triPoint.isCounterclockwise()){
                                        //
                                        triPoint.setVertexPosition(0u,vertexes->get(k));
                                        triPoint.setVertexPosition(1u,vertexes->get(i));
                                        triPoint.setVertexPosition(2u,vertexes->get(l));
                                        if(triPoint.isCounterclockwise()){
                                            //
                                            goContinue=false;
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
                                if(vsize){
                                    vsize--;
                                }
                                for(edk::uint32 n=0u;n<vsize;n++){
                                    //
                                    p1 = mesh->selectedGetVertexPosition(n);
                                    p2 = mesh->selectedGetVertexPosition(n+1u);

                                    //test intersection with all

                                    //0 1
                                    t1 = tri.getVertexPosition(0u);
                                    t2 = tri.getVertexPosition(1u);

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,n,p1.x,p1.y
                                    //       ,n+1u,p2.x,p2.y
                                    //       ,0u,t1.x,t1.y
                                    //       ,1u,t2.x,t2.y
                                    //       );

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );

                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);

                                        //printf("\nCollision size %u",collision.size());

                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){

                                                //printf("\n        %u %.2f %.2f"
                                                //       ,c
                                                //       ,collision.get(c).x
                                                //       ,collision.get(c).y
                                                //       );

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

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,n,p1.x,p1.y
                                    //       ,n+1u,p2.x,p2.y
                                    //       ,1u,t1.x,t1.y
                                    //       ,2u,t2.x,t2.y
                                    //       );

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );

                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);
                                        /*
                                        printf("\nCollision size %u",collision.size());
*/
                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );
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

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,n,p1.x,p1.y
                                    //       ,n+1u,p2.x,p2.y
                                    //       ,2u,t1.x,t1.y
                                    //       ,0u,t2.x,t2.y
                                    //       );

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );

                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);

                                        //printf("\nCollision size %u",collision.size());

                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );
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

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,vsize,p1.x,p1.y
                                    //       ,0u,p2.x,p2.y
                                    //       ,0u,t1.x,t1.y
                                    //       ,1u,t2.x,t2.y
                                    //       );

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );

                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);

                                        //printf("\nCollision size %u",collision.size());

                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );
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

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,vsize,p1.x,p1.y
                                    //       ,0u,p2.x,p2.y
                                    //       ,1u,t1.x,t1.y
                                    //       ,2u,t2.x,t2.y
                                    //       );

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );

                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);

                                        //printf("\nCollision size %u",collision.size());

                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );
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
                                                       );
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

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,vsize,p1.x,p1.y
                                    //       ,0u,p2.x,p2.y
                                    //       ,2u,t1.x,t1.y
                                    //       ,0u,t2.x,t2.y
                                    //       );

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight2D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );

                                        edk::collision::MathCollision::straightStraight2D(p1,p2,t1,t2,&collision);

                                        //printf("\nCollision size %u",collision.size());

                                        if(collision.size()){
                                            csize = collision.size();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       );
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

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);

                                                    goContinue++;
                                                    break;
                                                }
                                            }
                                            collision.clean();
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
                            printf("\n    Create %u %u %u",i,j,k);
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
    edk::shape::Triangle2D triPoint;
    edk::vector::Stack<edk::vec2f32> pConcaves;
    edk::uint32 concaveActual=0u;
    edk::uint32 concaveFirst=0u;
    edk::shape::Polygon2D polyTemp;
    edk::uint32 sizeVertexes = polygon.getVertexCount();
    edk::uint32 size = sizeVertexes;
    edk::float32 angle = 0.f;
    if(size>=3u && mesh){
        //search for the concave vertexes
        size-=2u;
        //calculate if the point is inside the triangle
        angle = edk::Math::getAngle(polygon.getVertexPosition(0u)-polygon.getVertexPosition(size+1u)) -
                edk::Math::getAngle(polygon.getVertexPosition(1u)-polygon.getVertexPosition(size+1u));
        if(angle<0.f){
            angle+=360.f;
        }
        /*
        printf("\nvertex 0u Angle == %.2f"
               ,angle
               );
*/
        if(angle<=180.f){
            /*
            printf(" concave");
*/
            if(!pConcaves.size()){
                concaveFirst = 0u;
            }
            pConcaves.pushBack(polygon.getVertexPosition(0u));
            concaveActual = 0u;
        }
        /*
        else{
            printf(" convex");
        }
*/
        bool goBreak=false;
        for(edk::uint32 i=0u;i<size;i++){
            //test the two lines
            //calculate if the point is inside the triangle
            angle = edk::Math::getAngle(polygon.getVertexPosition(i+1u)-polygon.getVertexPosition(i)) -
                    edk::Math::getAngle(polygon.getVertexPosition(i+2u)-polygon.getVertexPosition(i));
            if(angle<0.f){
                angle+=360.f;
            }
            /*
            printf("\nvertex %uu Angle == %.2f"
                   ,i+1u
                   ,angle
                   );
*/
            if(angle<=180.f){
                /*
                printf(" concave");
*/
                if(!pConcaves.size()){
                    concaveFirst = i+1u;
                }
                pConcaves.pushBack(polygon.getVertexPosition(i+1u));
                concaveActual = i+1u;
            }
            else{
                /*
                printf(" convex");
*/
                //then create the triangle
                if(pConcaves.size()){
                    //join the concave, the convex and the next vertex to create a triangle
                    /*
                    printf("\n%u Create triangle %u %u %u",__LINE__
                           ,concaveActual
                           ,i+1u
                           ,i+2u
                           );
*/
                    tri.setVertexPosition(0u,polygon.getVertexPosition(concaveActual).x,polygon.getVertexPosition(concaveActual).y);
                    tri.setVertexPosition(1u,polygon.getVertexPosition(i+1u).x,polygon.getVertexPosition(i+1u).y);
                    tri.setVertexPosition(2u,polygon.getVertexPosition(i+2u).x,polygon.getVertexPosition(i+2u).y);
                    if(tri.isCounterclockwise()){
                        /*
                        printf(" isCounterClockwise");
*/
                        //test if the triangle have a vertex inside
                        bool goContinue = true;
                        for(edk::uint32 l=0u;l<sizeVertexes;l++){
                            if(l!=concaveActual && l!= i+1u && l!=i+2u){

                                triPoint.setVertexPosition(0u,tri.getVertexPosition(0u));
                                triPoint.setVertexPosition(1u,tri.getVertexPosition(1u));
                                triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));
                                if(triPoint.isCounterclockwise()){
                                    //
                                    triPoint.setVertexPosition(0u,tri.getVertexPosition(1u));
                                    triPoint.setVertexPosition(1u,tri.getVertexPosition(2u));
                                    triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));
                                    if(triPoint.isCounterclockwise()){
                                        //
                                        triPoint.setVertexPosition(0u,tri.getVertexPosition(2u));
                                        triPoint.setVertexPosition(1u,tri.getVertexPosition(0u));
                                        triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));
                                        if(triPoint.isCounterclockwise()){
                                            //
                                            goContinue=false;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if(goContinue){
                            mesh->addPolygon(tri);
                            /*
                            printf(" addPolygon");
*/
                        }
                        else{
                            /*
                            printf(" notAddPolygon");
*/
                            //add the vertex as a concave
                            if(!pConcaves.size()){
                                concaveFirst = i+1u;
                            }
                            pConcaves.pushBack(polygon.getVertexPosition(i+1u));
                            concaveActual = i+1u;
                        }
                    }
                    else{
                        /*
                        printf(" isNOTCounterClockwise");
*/
                        goBreak=true;
                        break;
                    }
                }


            }
        }

        if(!goBreak){
            //calculate if the point is inside the triangle
            angle = edk::Math::getAngle(polygon.getVertexPosition(size+1u)-polygon.getVertexPosition(size)) -
                    edk::Math::getAngle(polygon.getVertexPosition(0u)-polygon.getVertexPosition(size));
            if(angle<0.f){
                angle+=360.f;
            }
            /*
            printf("\nvertex %uu Angle == %.2f"
                   ,size+1u
                   ,angle
                   );
*/
            if(angle<=180.f){
                /*
                printf(" concave");
*/
                if(!pConcaves.size()){
                    concaveFirst = size+1u;
                }
                pConcaves.pushBack(polygon.getVertexPosition(size+1u));
                concaveActual = size+1u;
            }
            else{
                /*
                printf(" convex");
*/

                //then create the triangle
                if(pConcaves.size()){
                    //join the concave, the convex and the next vertex to create a triangle
                    /*
                    printf("\n%u Create triangle %u %u %u",__LINE__
                           ,concaveActual
                           ,size+1u
                           ,0u
                           );
*/
                    tri.setVertexPosition(0u,polygon.getVertexPosition(concaveActual).x,polygon.getVertexPosition(concaveActual).y);
                    tri.setVertexPosition(1u,polygon.getVertexPosition(size+1u).x,polygon.getVertexPosition(size+1u).y);
                    tri.setVertexPosition(2u,polygon.getVertexPosition(0u).x,polygon.getVertexPosition(0u).y);
                    if(tri.isCounterclockwise()){
                        /*
                        printf(" isCounterClockwise");
*/
                        //test if the triangle have a vertex inside
                        bool goContinue = true;
                        for(edk::uint32 l=0u;l<sizeVertexes;l++){
                            if(l!=concaveActual && l!= size+1u && l!=0u){

                                triPoint.setVertexPosition(0u,tri.getVertexPosition(0u));
                                triPoint.setVertexPosition(1u,tri.getVertexPosition(1u));
                                triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));
                                if(triPoint.isCounterclockwise()){
                                    //
                                    triPoint.setVertexPosition(0u,tri.getVertexPosition(1u));
                                    triPoint.setVertexPosition(1u,tri.getVertexPosition(2u));
                                    triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));
                                    if(triPoint.isCounterclockwise()){
                                        //
                                        triPoint.setVertexPosition(0u,tri.getVertexPosition(2u));
                                        triPoint.setVertexPosition(1u,tri.getVertexPosition(0u));
                                        triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));
                                        if(triPoint.isCounterclockwise()){
                                            //
                                            goContinue=false;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if(goContinue){
                            mesh->addPolygon(tri);
                            /*
                            printf(" addPolygon");
*/
                        }
                        else{
                            /*
                            printf(" notAddPolygon");
*/
                            //add the vertex as a concave
                            if(!pConcaves.size()){
                                concaveFirst = size+1u;
                            }
                            pConcaves.pushBack(polygon.getVertexPosition(size+1u));
                            concaveActual = size+1u;
                        }
                    }
                    else{
                        /*
                        printf(" isNOTCounterClockwise");
*/
                        goBreak=true;
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
                           );
*/
                    tri.setVertexPosition(0u,polygon.getVertexPosition(concaveActual).x,polygon.getVertexPosition(concaveActual).y);
                    tri.setVertexPosition(1u,polygon.getVertexPosition(i).x,polygon.getVertexPosition(i).y);
                    tri.setVertexPosition(2u,polygon.getVertexPosition(i+1u).x,polygon.getVertexPosition(i+1u).y);
                    if(tri.isCounterclockwise()){

                        /*
                        printf(" isCounterClockwise");
*/
                        //test if the triangle have a vertex inside
                        bool goContinue = true;
                        for(edk::uint32 l=0u;l<sizeVertexes;l++){
                            if(l!=concaveActual && l!= i && l!=i+1u){

                                triPoint.setVertexPosition(0u,tri.getVertexPosition(0u));
                                triPoint.setVertexPosition(1u,tri.getVertexPosition(1u));
                                triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));
                                if(triPoint.isCounterclockwise()){
                                    //
                                    triPoint.setVertexPosition(0u,tri.getVertexPosition(1u));
                                    triPoint.setVertexPosition(1u,tri.getVertexPosition(2u));
                                    triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));
                                    if(triPoint.isCounterclockwise()){
                                        //
                                        triPoint.setVertexPosition(0u,tri.getVertexPosition(2u));
                                        triPoint.setVertexPosition(1u,tri.getVertexPosition(0u));
                                        triPoint.setVertexPosition(2u,polygon.getVertexPosition(l));
                                        if(triPoint.isCounterclockwise()){
                                            //
                                            goContinue=false;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        if(goContinue){
                            mesh->addPolygon(tri);
                            /*
                            printf(" addPolygon");
*/
                        }
                        else{
                            /*
                            printf(" notAddPolygon");
*/
                            //add the vertex as a concave
                            if(!pConcaves.size()){
                                concaveFirst = i;
                            }
                            pConcaves.pushBack(polygon.getVertexPosition(i));
                            concaveActual = i;
                        }
                    }
                    else{
                        /*
                        printf(" isNOTCounterClockwise");
*/
                        goBreak=true;
                    }
                }
            }
        }

        if(!goBreak){
            ret = true;
            size = pConcaves.size();
            //test if have concaves
            if(size){
                //draw a polyTemp with the concaves
                polyTemp.createPolygon(size);
                for(edk::uint32 i=0u;i<size;i++){
                    polyTemp.setVertexPosition(i,pConcaves.get(i).x,pConcaves.get(i).y);
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
    return ret;
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
                free(name);
            }
            free(nameID);
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
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
bool edk::shape::Mesh2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
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
                    this->material.readFromXMLFromPack(pack,xml,0u);
                    ret=true;
                    xml->selectFather();
                }
                free(name);
            }
            free(nameID);
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
#if defined(edkCPPversion17)
        edk::uint32 size = mesh->polygons.size();
#else
        register edk::uint32 size = mesh->polygons.size();
#endif
        edk::uint32 select=0u;
        edk::shape::Polygon2D* temp = NULL;
        edk::uint32 id;
        edk::animation::Interpolation1DGroup* animTemp=NULL;
        for(edk::uint32 i=0u;i<size;i++){
            //
            temp=mesh->polygons.get(i);
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
                            if(this->setAnimationFramesToPolygon(id)){
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

        this->material.cloneFrom(&mesh->material);
        return true;
    }
    return false;
}
