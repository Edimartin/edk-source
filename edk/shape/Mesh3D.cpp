#include "Mesh3D.h"

/*
Library Mesh3D - Draw a 3D Mesh in EDK Game Engine
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
#pragma message "            Inside Mesh3D.cpp"
#endif

edk::shape::Mesh3D::Mesh3D(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::shape::Mesh3D::~Mesh3D(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->clean();edkEnd();
    }
}

void edk::shape::Mesh3D::Constructor(bool /*runFather*/){
    if(this->classThis!=this){
        this->classThis=this;

        this->material.Constructor();edkEnd();

        this->polygons.clean(2u);edkEnd();
        //clean the selected
        this->freeSelected();edkEnd();

    }
}

inline bool edk::shape::Mesh3D::floatDifferent(edk::float32 f1,edk::float32 f2){
    if((f1<f2-0.0001f || f1>f2+0.0001f)){
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::pointInsideLine(edk::vec3f32 point,edk::vec3f32 lineStart,edk::vec3f32 lineEnd){
    //printf("\n%u %s %s point %.2f %.2f lineStart %.2f %.2f lineEnd %.2f %.2f pointStraigh3D %s"
    //       ,__LINE__,__FILE__,__func__
    //       ,point.x
    //       ,point.y
    //       ,point.z
    //       ,lineStart.x
    //       ,lineStart.y
    //       ,lineStart.z
    //       ,lineEnd.x
    //       ,lineEnd.y
    //       ,lineEnd.z
    //       ,edk::collision::MathCollision::pointStraigh3D(point,lineStart,lineEnd,0.01f)?"true":"false"
    //       );edkEnd();

    edk::vec3f32 pStart,pEnd;edkEnd();
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
    if(lineStart.z < lineEnd.z){
        pStart.z = lineStart.z;edkEnd();
        pEnd.z = lineEnd.z;edkEnd();
    }
    else{
        pStart.z = lineEnd.z;edkEnd();
        pEnd.z = lineStart.z;edkEnd();
    }
    //

    //printf("\n%u %s %s point %.2f %.2f pStart %.2f %.2f pEnd %.2f %.2f"
    //       ,__LINE__,__FILE__,__func__
    //       ,point.x
    //       ,point.y
    //       ,point.z
    //       ,pStart.x
    //       ,pStart.y
    //       ,pStart.z
    //       ,pEnd.x
    //       ,pEnd.y
    //       ,pEnd.z
    //       );edkEnd();

    if(edk::collision::MathCollision::pointStraigh3D(point,lineStart,lineEnd,0.01f)
            &&
            point.x>=pStart.x && point.x<=pEnd.x
            &&
            point.y>=pStart.y && point.y<=pEnd.y
            &&
            point.z>=pStart.z && point.z<=pEnd.z
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
void edk::shape::Mesh3D::clean(){
    this->cleanTextures();edkEnd();
    this->cleanPolygons();edkEnd();
}
//remove the rextures
void edk::shape::Mesh3D::cleanTextures(){
    this->material.removeAllTextures();edkEnd();
}
//remove the texture
bool edk::shape::Mesh3D::removeTexture(edk::uint32 position){
    return this->material.removeTexture(position);edkEnd();
}

//DRAW
//print the mesh
void edk::shape::Mesh3D::print(){
    //
    this->printPolygons();edkEnd();
}
//draw the mesh
void edk::shape::Mesh3D::drawWithoutMaterial(){
    this->drawPolygons();edkEnd();
}
void edk::shape::Mesh3D::drawNoTexture(){
    this->material.drawNoTexture();edkEnd();
    this->drawPolygons();edkEnd();
}
void edk::shape::Mesh3D::drawOneTexture(){
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
void edk::shape::Mesh3D::drawOneTexture(edk::uint32 position){
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
bool edk::shape::Mesh3D::selectedDrawOneTexture(){
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
bool edk::shape::Mesh3D::selectedDrawOneTexture(edk::uint32 position){
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
void edk::shape::Mesh3D::drawMultiTexture(){
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
bool edk::shape::Mesh3D::selectedDrawMultiTexture(){
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
void edk::shape::Mesh3D::drawWire(){
    this->material.drawNoTexture();edkEnd();
    //else just draw the mesh
    this->drawWirePolygons();edkEnd();
}
void edk::shape::Mesh3D::drawWireWithColor(edk::color4f32 color){
    edk::GU::guColor4f32(color);
    //else just draw the mesh
    this->drawWirePolygons();edkEnd();
}
void edk::shape::Mesh3D::drawWireWithColor(edk::color3f32 color){
    edk::GU::guColor3f32(color);
    //else just draw the mesh
    this->drawWirePolygons();edkEnd();
}
bool edk::shape::Mesh3D::drawPolygonWithoutMaterial(edk::uint32 polygon){
    //
    return this->drawPolygon(polygon);edkEnd();
}
bool edk::shape::Mesh3D::drawPolygonNoTexture(edk::uint32 polygon){
    this->material.drawNoTexture();edkEnd();
    return this->drawPolygon(polygon);edkEnd();
}
bool edk::shape::Mesh3D::drawPolygonOneTexture(edk::uint32 polygon){
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
bool edk::shape::Mesh3D::drawPolygonOneTexture(edk::uint32 polygon, edk::uint32 position){
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
bool edk::shape::Mesh3D::drawPolygonMultiTexture(edk::uint32 polygon){
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
bool edk::shape::Mesh3D::drawPolygonWire(edk::uint32 polygon){
    this->material.drawNoTexture();edkEnd();
    //else just draw the mesh
    return this->drawWirePolygon(polygon);edkEnd();
}
bool edk::shape::Mesh3D::drawPolygonWireWithColor(edk::uint32 polygon,edk::color4f32 color){
    edk::GU::guColor4f32(color);
    //else just draw the mesh
    return this->drawWirePolygon(polygon);edkEnd();
}
bool edk::shape::Mesh3D::drawPolygonWireWithColor(edk::uint32 polygon,edk::color3f32 color){
    edk::GU::guColor3f32(color);
    //else just draw the mesh
    return this->drawWirePolygon(polygon);edkEnd();
}
//draw with matrix
void edk::shape::Mesh3D::drawWithoutMaterialWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                       edk::vector::Matrixf32<4u,4u>* matrixTemp
                                                       ){
    //
    this->drawPolygonsWithMatrix(matrix,matrixTemp);edkEnd();
}
void edk::shape::Mesh3D::drawNoTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                 edk::vector::Matrixf32<4u,4u>* matrixTemp
                                                 ){
    //
    this->material.drawNoTexture();edkEnd();
    this->drawPolygonsWithMatrix(matrix,matrixTemp);edkEnd();
}
void edk::shape::Mesh3D::drawOneTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                  edk::vector::Matrixf32<4u,4u>* matrixTemp
                                                  ){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture();edkEnd();
        //Draw the mesh
        this->drawPolygonsWithMatrix(matrix,matrixTemp);edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        this->drawPolygonsWithMatrix(matrix,matrixTemp);edkEnd();
    }
}
void edk::shape::Mesh3D::drawOneTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                  edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                  edk::uint32 position
                                                  ){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture(position);edkEnd();
        //Draw the mesh
        this->drawPolygonsWithMatrix(matrix,matrixTemp);edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        this->drawPolygonsWithMatrix(matrix,matrixTemp);edkEnd();
    }
}
bool edk::shape::Mesh3D::selectedDrawOneTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                          edk::vector::Matrixf32<4u,4u>* matrixTemp
                                                          ){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture();edkEnd();
            //Draw the polygon
            this->selected->drawWithMatrix(matrix,matrixTemp);edkEnd();

            this->material.drawEndWithTexture();edkEnd();
        }
        else{
            this->material.drawNoTexture();edkEnd();
            //else just draw the polygon
            this->selected->drawWithMatrix(matrix,matrixTemp);edkEnd();
        }
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::selectedDrawOneTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                          edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                          edk::uint32 position
                                                          ){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithOneTexture(position);edkEnd();
            //Draw the polygon
            this->selected->drawWithMatrix(matrix,matrixTemp);edkEnd();

            this->material.drawEndWithTexture();edkEnd();
        }
        else{
            this->material.drawNoTexture();edkEnd();
            //else just draw the polygon
            this->selected->drawWithMatrix(matrix,matrixTemp);edkEnd();
        }
        return true;
    }
    return false;
}
void edk::shape::Mesh3D::drawMultiTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                    edk::vector::Matrixf32<4u,4u>* matrixTemp
                                                    ){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithMultiTexture();edkEnd();
        //Draw the mesh
        this->drawPolygonsWithMatrix(matrix,matrixTemp);

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        this->drawPolygonsWithMatrix(matrix,matrixTemp);
    }
}
bool edk::shape::Mesh3D::selectedDrawMultiTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                            edk::vector::Matrixf32<4u,4u>* matrixTemp
                                                            ){
    if(this->selected){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithMultiTexture();edkEnd();
            //Draw the mesh
            this->selected->drawWithMatrix(matrix,matrixTemp);edkEnd();

            this->material.drawEndWithTexture();edkEnd();
        }
        else{
            this->material.drawNoTexture();edkEnd();
            //else just draw the mesh
            this->selected->drawWithMatrix(matrix,matrixTemp);edkEnd();
        }
        return true;
    }
    return false;
}
void edk::shape::Mesh3D::drawWireWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                            edk::vector::Matrixf32<4u,4u>* matrixTemp
                                            ){
    this->material.drawNoTexture();edkEnd();
    //else just draw the mesh
    this->drawWirePolygonsWithMatrix(matrix,matrixTemp);
}
void edk::shape::Mesh3D::drawWireWithColorWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                     edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                     edk::color4f32 color
                                                     ){
    edk::GU::guColor4f32(color);
    //else just draw the mesh
    this->drawWirePolygonsWithMatrix(matrix,matrixTemp);edkEnd();
}
void edk::shape::Mesh3D::drawWireWithColorWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                     edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                     edk::color3f32 color
                                                     ){
    edk::GU::guColor3f32(color);
    //else just draw the mesh
    this->drawWirePolygonsWithMatrix(matrix,matrixTemp);edkEnd();
}
bool edk::shape::Mesh3D::drawPolygonWithoutMaterialWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                              edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                              edk::uint32 polygon
                                                              ){
    return this->drawPolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();
}
bool edk::shape::Mesh3D::drawPolygonNoTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                        edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                        edk::uint32 polygon
                                                        ){
    this->material.drawNoTexture();edkEnd();
    return this->drawPolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();
}
bool edk::shape::Mesh3D::drawPolygonOneTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                         edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                         edk::uint32 polygon
                                                         ){
    bool ret = false;edkEnd();
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture();edkEnd();
        //Draw the mesh
        ret = this->drawPolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        ret = this->drawPolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();
    }
    return ret;
}
bool edk::shape::Mesh3D::drawPolygonOneTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                         edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                         edk::uint32 polygon,
                                                         edk::uint32 position
                                                         ){
    bool ret = false;edkEnd();
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture(position);edkEnd();
        //Draw the mesh
        ret = this->drawPolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        ret = this->drawPolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();
    }
    return ret;
}
bool edk::shape::Mesh3D::drawPolygonMultiTextureWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                           edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                           edk::uint32 polygon
                                                           ){
    bool ret = false;edkEnd();
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithMultiTexture();edkEnd();
        //Draw the mesh
        ret = this->drawPolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        ret = this->drawPolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();
    }
    return ret;
}
bool edk::shape::Mesh3D::drawPolygonWireWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                   edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                   edk::uint32 polygon
                                                   ){
    this->material.drawNoTexture();edkEnd();
    //else just draw the mesh
    return this->drawWirePolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();
}
bool edk::shape::Mesh3D::drawPolygonWireWithColorWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                            edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                            edk::uint32 polygon,
                                                            edk::color4f32 color
                                                            ){
    edk::GU::guColor4f32(color);
    //else just draw the mesh
    return this->drawWirePolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();
}
bool edk::shape::Mesh3D::drawPolygonWireWithColorWithMatrix(edk::vector::Matrixf32<4u,4u>* matrix,
                                                            edk::vector::Matrixf32<4u,4u>* matrixTemp,
                                                            edk::uint32 polygon,
                                                            edk::color3f32 color
                                                            ){
    edk::GU::guColor3f32(color);
    //else just draw the mesh
    return this->drawWirePolygonWithMatrix(matrix,matrixTemp,polygon);edkEnd();
}
//VBO
void edk::shape::Mesh3D::drawVBOOneTexture(){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture();edkEnd();
        //Draw the mesh
        this->drawVBOPolygons();edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        this->drawVBOPolygons();edkEnd();
    }
}
void edk::shape::Mesh3D::drawVBOOneTexture(edk::uint32 position){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithOneTexture(position);edkEnd();
        //Draw the mesh
        this->drawVBOPolygons();edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        this->drawVBOPolygons();edkEnd();
    }
}
void edk::shape::Mesh3D::drawVBOMultiTexture(){
    //set the texture if have one
    if(this->material.haveTexture()){
        this->material.drawStartWithMultiTexture();edkEnd();
        //Draw the mesh
        this->drawVBOPolygons();edkEnd();

        this->material.drawEndWithTexture();edkEnd();
    }
    else{
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        this->drawVBOPolygons();edkEnd();
    }
}

bool edk::shape::Mesh3D::triangularizateFromVertex(edk::vector::Stack<edk::vec3f32>* vertexes){
    return edk::shape::Mesh3D::vertexTriangularization(vertexes,this);edkEnd();
}
bool edk::shape::Mesh3D::triangularizateFromPolygon(edk::shape::Polygon3D polygon){
    bool ret = edk::shape::Mesh3D::polygonTriangularization(polygon,this);edkEnd();
    return ret;
}
bool edk::shape::Mesh3D::putHoleInPolygon(edk::shape::Polygon3D outside,edk::shape::Polygon3D inside){
    bool ret = false;edkEnd();

    //test if have some polygon as rectanble with 2 vertexes
    edk::shape::Polygon3D* out = &outside;edkEnd();
    edk::shape::Polygon3D* in = &inside;edkEnd();
    edk::shape::Polygon3D outTemp;edkEnd();
    bool haveOut=false;edkEnd();
    edk::shape::Polygon3D inTemp;edkEnd();
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
            outTemp.setVertexPosition(1u,outside.getVertexPosition(1u).x,
                                      outside.getVertexPosition(0u).y,
                                      outside.getVertexPosition(0u).z
                                      );edkEnd();
            outTemp.setVertexUV(1u,outside.getVertexUV(1u).x,
                                outside.getVertexUV(0u).y
                                );edkEnd();
            outTemp.setVertexColor(1u,outside.getVertexColor(0u));edkEnd();
            //
            outTemp.setVertexPosition(2u,outside.getVertexPosition(1u));edkEnd();
            outTemp.setVertexUV(2u,outside.getVertexUV(1u));edkEnd();
            outTemp.setVertexColor(2u,outside.getVertexColor(1u));edkEnd();
            //
            outTemp.setVertexPosition(3u,outside.getVertexPosition(0u).x,
                                      outside.getVertexPosition(1u).y,
                                      outside.getVertexPosition(1u).z
                                      );edkEnd();
            outTemp.setVertexUV(3u,outside.getVertexUV(0u).x,
                                outside.getVertexUV(1u).y
                                );edkEnd();
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
            inTemp.setVertexPosition(1u,inside.getVertexPosition(1u).x,
                                     inside.getVertexPosition(0u).y,
                                     inside.getVertexPosition(0u).z
                                     );edkEnd();
            inTemp.setVertexUV(1u,inside.getVertexUV(1u).x,
                               inside.getVertexUV(0u).y
                               );edkEnd();
            inTemp.setVertexColor(1u,inside.getVertexColor(0u));edkEnd();
            //
            inTemp.setVertexPosition(2u,inside.getVertexPosition(1u));edkEnd();
            inTemp.setVertexUV(2u,inside.getVertexUV(1u));edkEnd();
            inTemp.setVertexColor(2u,inside.getVertexColor(1u));edkEnd();
            //
            inTemp.setVertexPosition(3u,inside.getVertexPosition(0u).x,
                                     inside.getVertexPosition(1u).y,
                                     inside.getVertexPosition(1u).z
                                     );edkEnd();
            inTemp.setVertexUV(3u,inside.getVertexUV(0u).x,
                               inside.getVertexUV(1u).y
                               );edkEnd();
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
        edk::shape::Lines3D poly;edkEnd();
        if(poly.createPolygon(countOutside + countInside + 2u)){
            //get the position of the first inside vertex with the lowest angle
            edk::uint32 j;edkEnd();
            edk::uint32 size;edkEnd();
            edk::uint32 insideFirstPosition = 0u;edkEnd();
            edk::uint32 outsideFirstPosition = 0u;edkEnd();
            edk::float32 angle = 360.f;edkEnd();
            edk::float32 angleNew = 360.f;edkEnd();
            angle = edk::Math::getAngle(
                        edk::vec2f32(in->getVertexPositionTransformed(insideFirstPosition).x,
                                     in->getVertexPositionTransformed(insideFirstPosition).y
                                     )
                        );edkEnd();
            size = countInside;edkEnd();
            for(edk::uint32 i=1u;i<size;i++){
                //test the other vertexes
                if((angleNew = edk::Math::getAngle(edk::vec2f32(in->getVertexPositionTransformed(i).x,
                                                                in->getVertexPositionTransformed(i).y
                                                                )
                                                   ))<angle){
                    angle = angleNew;edkEnd();
                    insideFirstPosition = i;edkEnd();
                }
            }

            //then get the outside last position
            angle = edk::Math::getAngle(edk::vec2f32(out->getVertexPositionTransformed(outsideFirstPosition).x,
                                                     out->getVertexPositionTransformed(outsideFirstPosition).y
                                                     )
                                        );edkEnd();
            size = countOutside;edkEnd();
            for(edk::uint32 i=1u;i<size;i++){
                //test the other vertexes
                if((angleNew = edk::Math::getAngle(edk::vec2f32(out->getVertexPositionTransformed(i).x,
                                                                out->getVertexPositionTransformed(i).y
                                                                )
                                                   ))<angle){
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
            ret = edk::shape::Mesh3D::polygonTriangularization(poly,this);edkEnd();

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
    return ret;
}

bool edk::shape::Mesh3D::putHoleInRectangle(edk::cubef32 rect,edk::shape::Polygon3D inside){
    bool ret = false;edkEnd();
    //create the rectangle
    edk::shape::Polygon3D poly;edkEnd();
    if(poly.createPolygon(4u)){
        //
        //set the vertexes
        poly.setVertexPosition(0u,rect.origin.x,rect.origin.y,rect.origin.z);edkEnd();
        poly.setVertexPosition(1u,rect.size.width,rect.origin.y,rect.origin.z);edkEnd();
        poly.setVertexPosition(2u,rect.size.width,rect.size.height,rect.size.length);edkEnd();
        poly.setVertexPosition(3u,rect.origin.x,rect.size.height,rect.size.length);edkEnd();

        //run the function to put a hole inside the polygon
        ret = this->putHoleInPolygon(poly,inside);edkEnd();

        poly.deletePolygon();edkEnd();
    }
    return ret;
}

//vertexTriangularization the mesh with the triangles
bool edk::shape::Mesh3D::vertexTriangularization(edk::vector::Stack<edk::vec3f32>* vertexes,edk::shape::Mesh3D *mesh){
    bool ret=false;edkEnd();
    if(vertexes && mesh){
        treeTriangles tree;edkEnd();
        //test all the vertex to create all the polygons
        edk::uint32 size = vertexes->size();edkEnd();
        edk::uint32 psize = 0u;edkEnd();
        edk::uint32 vsize = 0u;edkEnd();
        edk::uint32 csize = 0u;edkEnd();
        edk::shape::Triangle3D tri;edkEnd();
        edk::shape::Triangle3D triPoint;edkEnd();
        edk::uint8 goContinue=0u;
        edk::vec3f32 p1;edkEnd();
        edk::vec3f32 p2;edkEnd();
        edk::vec3f32 t1;edkEnd();
        edk::vec3f32 t2;edkEnd();
        edk::collision::Vecs3f32 collision;edkEnd();
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
                        tri.setVertexPosition(0u,vertexes->get(i).x,vertexes->get(i).y,vertexes->get(i).z);edkEnd();
                        tri.setVertexPosition(1u,vertexes->get(j).x,vertexes->get(j).y,vertexes->get(j).z);edkEnd();
                        tri.setVertexPosition(2u,vertexes->get(k).x,vertexes->get(k).y,vertexes->get(k).z);edkEnd();

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,n,p1.x,p1.y
                                    //       ,n+1u,p2.x,p2.y
                                    //       ,0u,t1.x,t1.y
                                    //       ,1u,t2.x,t2.y
                                    //       );edkEnd();

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight3D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );edkEnd();

                                        edk::collision::MathCollision::straightStraight3D(p1,p2,t1,t2,&collision);edkEnd();

                                        //printf("\nCollision size %u",collision.size());edkEnd();

                                        if(collision.size()){
                                            csize = collision.size();edkEnd();
                                            for(edk::uint32 c=0u;c<csize;c++){

                                                //printf("\n        %u %.2f %.2f"
                                                //       ,c
                                                //       ,collision.get(c).x
                                                //       ,collision.get(c).y
                                                //       );edkEnd();

                                                if((floatDifferent(collision.get(c).x,p1.x)
                                                    ||
                                                    floatDifferent(collision.get(c).y,p1.y)
                                                    ||
                                                    floatDifferent(collision.get(c).z,p1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,p2.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t2.z))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,n,p1.x,p1.y
                                    //       ,n+1u,p2.x,p2.y
                                    //       ,1u,t1.x,t1.y
                                    //       ,2u,t2.x,t2.y
                                    //       );edkEnd();

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight3D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );edkEnd();

                                        edk::collision::MathCollision::straightStraight3D(p1,p2,t1,t2,&collision);edkEnd();
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
                                                       ,collision.get(c).z
                                                       );edkEnd();
*/
                                                if((floatDifferent(collision.get(c).x,p1.x)
                                                    ||
                                                    floatDifferent(collision.get(c).y,p1.y)
                                                    ||
                                                    floatDifferent(collision.get(c).z,p1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,p2.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t2.z))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,n,p1.x,p1.y
                                    //       ,n+1u,p2.x,p2.y
                                    //       ,2u,t1.x,t1.y
                                    //       ,0u,t2.x,t2.y
                                    //       );edkEnd();

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight3D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );edkEnd();

                                        edk::collision::MathCollision::straightStraight3D(p1,p2,t1,t2,&collision);edkEnd();

                                        //printf("\nCollision size %u",collision.size());edkEnd();

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
                                                    floatDifferent(collision.get(c).y,p1.y)
                                                    ||
                                                    floatDifferent(collision.get(c).z,p1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,p2.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t2.z))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,vsize,p1.x,p1.y
                                    //       ,0u,p2.x,p2.y
                                    //       ,0u,t1.x,t1.y
                                    //       ,1u,t2.x,t2.y
                                    //       );edkEnd();

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight3D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );edkEnd();

                                        edk::collision::MathCollision::straightStraight3D(p1,p2,t1,t2,&collision);edkEnd();

                                        //printf("\nCollision size %u",collision.size());edkEnd();

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
                                                    floatDifferent(collision.get(c).y,p1.y)
                                                    ||
                                                    floatDifferent(collision.get(c).z,p1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,p2.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t2.z))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,vsize,p1.x,p1.y
                                    //       ,0u,p2.x,p2.y
                                    //       ,1u,t1.x,t1.y
                                    //       ,2u,t2.x,t2.y
                                    //       );edkEnd();

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight3D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p2.x,p2.y,t1.x,t1.y,t2.x,t2.y
                                        //       );edkEnd();

                                        edk::collision::MathCollision::straightStraight3D(p1,p2,t1,t2,&collision);edkEnd();

                                        //printf("\nCollision size %u",collision.size());edkEnd();

                                        if(collision.size()){
                                            csize = collision.size();edkEnd();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       ,collision.get(c).z
                                                       );edkEnd();
                                                printf("\n((floatDifferent(collision.get(c).x[%.2f],p1.x[%.2f])%s"
                                                       "\n  &&"
                                                       "\n  floatDifferent(collision.get(c).y[%.2f],p1.y[%.2f])%s"
                                                       "\n  &&"
                                                       "\n  floatDifferent(collision.get(c).z[%.2f],p1.z[%.2f]))%s"
                                                       "\n      &&"
                                                       "\n      (floatDifferent(collision.get(c).x,p2.x)%s"
                                                       "\n       &&"
                                                       "\n       floatDifferent(collision.get(c).y,p2.y)%s"
                                                       "\n       &&"
                                                       "\n       floatDifferent(collision.get(c).z,p2.z))%s"
                                                       "\n      &&"
                                                       "\n      (floatDifferent(collision.get(c).x,t1.x)%s"
                                                       "\n       &&"
                                                       "\n       floatDifferent(collision.get(c).y,t1.y)%s"
                                                       "\n       &&"
                                                       "\n       floatDifferent(collision.get(c).z,t1.z))%s"
                                                       "\n      &&"
                                                       "\n      (floatDifferent(collision.get(c).x,t2.x)%s"
                                                       "\n       &&"
                                                       "\n       floatDifferent(collision.get(c).y,t2.y)%s"
                                                       "\n       &&"
                                                       "\n       floatDifferent(collision.get(c).z,t2.z))%s"

                                                       "\n      &&"
                                                       "\n      pointInsideLine(collision.get(c),p1,p2)%s &&"
                                                       "\n      pointInsideLine(collision.get(c),t1,t2)%s"

                                                       "\n      )"
                                                       ,collision.get(c).x,p1.x
                                                       ,floatDifferent(collision.get(c).x,p1.x)?"true":"false"
                                                       ,collision.get(c).y,p1.y
                                                       ,collision.get(c).z,p1.z
                                                       ,floatDifferent(collision.get(c).y,p1.y)?"true":"false"
                                                       ,floatDifferent(collision.get(c).z,p1.z)?"true":"false"
                                                       ,floatDifferent(collision.get(c).x,p2.x)?"true":"false"
                                                       ,floatDifferent(collision.get(c).y,p2.y)?"true":"false"
                                                       ,floatDifferent(collision.get(c).z,p2.z)?"true":"false"
                                                       ,floatDifferent(collision.get(c).x,t1.x)?"true":"false"
                                                       ,floatDifferent(collision.get(c).y,t1.y)?"true":"false"
                                                       ,floatDifferent(collision.get(c).z,t1.z)?"true":"false"
                                                       ,floatDifferent(collision.get(c).x,t2.x)?"true":"false"
                                                       ,floatDifferent(collision.get(c).y,t2.y)?"true":"false"
                                                       ,floatDifferent(collision.get(c).z,t2.z)?"true":"false"
                                                       ,pointInsideLine(collision.get(c),p1,p2)?"true":"false"
                                                       ,pointInsideLine(collision.get(c),t1,t2)?"true":"false"
                                                       );edkEnd();
*/
                                                if((floatDifferent(collision.get(c).x,p1.x)
                                                    ||
                                                    floatDifferent(collision.get(c).y,p1.y)
                                                    ||
                                                    floatDifferent(collision.get(c).z,p1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,p2.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t2.z))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();

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

                                    //printf("\n%u %s %s  p1 == [%u] %.2f %.2f "
                                    //       "p2 == [%u] %.2f %.2f "
                                    //       "t1 == [%u] %.2f %.2f "
                                    //       "t2 == [%u] %.2f %.2f",__LINE__,__FILE__,__func__
                                    //       ,vsize,p1.x,p1.y,p1.z
                                    //       ,0u,p2.x,p2.y,p2.z
                                    //       ,2u,t1.x,t1.y,t1.z
                                    //       ,0u,t2.x,t2.y,t2.z
                                    //       );edkEnd();

                                    if((p1!=t1 || p2!=t2) && (p2!=t1 || p1!=t2)){

                                        //printf("\n%u %s %s straightStraight3D(p1[%.2f,%.2f],p2[%.2f,%.2f],t1[%.2f,%.2f],t2[%.2f,%.2f],&collision)",__LINE__,__FILE__,__func__
                                        //       ,p1.x,p1.y,p1.z,p2.x,p2.y,p2.z,t1.x,t1.y,t1.z,t2.x,t2.y,t2.z
                                        //       );edkEnd();

                                        edk::collision::MathCollision::straightStraight3D(p1,p2,t1,t2,&collision);edkEnd();

                                        //printf("\nCollision size %u",collision.size());edkEnd();

                                        if(collision.size()){
                                            csize = collision.size();edkEnd();
                                            for(edk::uint32 c=0u;c<csize;c++){
                                                /*
                                                printf("\n        %u %.2f %.2f"
                                                       ,c
                                                       ,collision.get(c).x
                                                       ,collision.get(c).y
                                                       ,collision.get(c).z
                                                       );edkEnd();
*/
                                                if((floatDifferent(collision.get(c).x,p1.x)
                                                    ||
                                                    floatDifferent(collision.get(c).y,p1.y)
                                                    ||
                                                    floatDifferent(collision.get(c).z,p1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,p2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,p2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,p2.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t1.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t1.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t1.z))
                                                        &&
                                                        (floatDifferent(collision.get(c).x,t2.x)
                                                         ||
                                                         floatDifferent(collision.get(c).y,t2.y)
                                                         ||
                                                         floatDifferent(collision.get(c).z,t2.z))

                                                        &&
                                                        pointInsideLine(collision.get(c),p1,p2) &&
                                                        pointInsideLine(collision.get(c),t1,t2)

                                                        ){

                                                    //printf("\n%u %s %s      Intersect",__LINE__,__FILE__,__func__);edkEnd();

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
bool edk::shape::Mesh3D::polygonTriangularization(edk::shape::Polygon3D polygon,edk::shape::Mesh3D *mesh){
    bool ret=false;edkEnd();
    edk::shape::Triangle3D tri;edkEnd();
    edk::uint32 size = polygon.getVertexCount();edkEnd();
    if(size>=3u && mesh){
        if(size==4u){
            //
            tri.cloneVertexFrom(0u,polygon.getVertexPointerInPosition(0u));
            tri.cloneVertexFrom(1u,polygon.getVertexPointerInPosition(1u));
            tri.cloneVertexFrom(2u,polygon.getVertexPointerInPosition(2u));
            mesh->addPolygon(tri);
            tri.cloneVertexFrom(0u,polygon.getVertexPointerInPosition(2u));
            tri.cloneVertexFrom(1u,polygon.getVertexPointerInPosition(3u));
            tri.cloneVertexFrom(2u,polygon.getVertexPointerInPosition(0u));
            mesh->addPolygon(tri);
            ret = true;
        }
        else if(size==3u){
            mesh->addPolygon(polygon);
        }
        else{
            ///////////////////////////////////////
            //triangulate convex polygons with the first vertex
            size--;
            tri.cloneVertexFrom(0u,polygon.getVertexPointerInPosition(0u));
            for(edk::uint32 i=1u;i<size;i++){
                //generate the triangle
                tri.cloneVertexFrom(1u,polygon.getVertexPointerInPosition(i));
                tri.cloneVertexFrom(2u,polygon.getVertexPointerInPosition(i+1u));
                mesh->addPolygon(tri);
            }
            ret=true;
            ///////////////////////////////////////
        }
    }
    return ret;
}

//XML
bool edk::shape::Mesh3D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon3DList::writeToXML(xml,id)){
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
bool edk::shape::Mesh3D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon3DList::readFromXML(xml,id)){
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
bool edk::shape::Mesh3D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(edk::shape::Polygon3DList::readFromXML(xml,id)){
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

bool edk::shape::Mesh3D::cloneFrom(edk::shape::Mesh3D* mesh){
    if(mesh){
        //
        edk::shape::Mesh3D::TreeAnimations tree;edkEnd();

        //delete the polygons
        this->cleanPolygons();edkEnd();
        //read the polygons
#if defined(edkCPPversion17)
        edk::uint32 size = mesh->polygons.size();edkEnd();
#else
        register edk::uint32 size = mesh->polygons.size();edkEnd();
#endif
        edk::uint32 select=0u;
        edk::shape::Polygon3D* temp = NULL;edkEnd();
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

        this->material.cloneFrom(&mesh->material);edkEnd();
        return true;
    }
    return false;
}
