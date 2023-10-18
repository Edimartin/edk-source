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

edk::shape::Mesh3D::StackVertex::StackVertex(){
    //
}
edk::shape::Mesh3D::StackVertex::~StackVertex(){
    //
    this->cleanVertexes();edkEnd();
}

//clean all vertexes
void edk::shape::Mesh3D::StackVertex::cleanVertexes(){
    edk::uint32 size=this->stack.size();edkEnd();
    edk::shape::Mesh3D::MeshVertex* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);edkEnd();
        if(temp){
            delete temp;edkEnd();
        }
    }
    this->stack.clean();edkEnd();
}
//get the size of the vertexes
edk::uint32 edk::shape::Mesh3D::StackVertex::size(){
    return this->stack.size();edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackVertex::getSize(){
    return this->stack.size();edkEnd();
}

//create a new vertex in to the stack
edk::uint32 edk::shape::Mesh3D::StackVertex::newVertex(edk::float32 x,edk::float32 y,edk::float32 z){
    return this->newVertex(x,y,z,1.f,1.f,1.f,1.f);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackVertex::newVertex(edk::float32 x,
                                                       edk::float32 y,
                                                       edk::float32 z,
                                                       edk::float32 r,
                                                       edk::float32 g,
                                                       edk::float32 b
                                                       ){
    return this->newVertex(x,y,z,r,g,b,1.f);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackVertex::newVertex(edk::float32 x,
                                                       edk::float32 y,
                                                       edk::float32 z,
                                                       edk::float32 r,
                                                       edk::float32 g,
                                                       edk::float32 b,
                                                       edk::float32 a
                                                       ){
    edk::shape::Mesh3D::MeshVertex* vert = new edk::shape::Mesh3D::MeshVertex;edkEnd();
    if(vert){
        vert->vertex.x = x;edkEnd();
        vert->vertex.y = y;edkEnd();
        vert->vertex.z = z;edkEnd();
        vert->vertex.r = r;edkEnd();
        vert->vertex.g = g;edkEnd();
        vert->vertex.b = b;edkEnd();
        vert->vertex.a = a;edkEnd();
        edk::uint32 size = this->stack.size();edkEnd();
        edk::uint32 ret = this->stack.pushBack(vert);edkEnd();
        //add this vert in to
        if(size<this->stack.size()){
            return ret;
        }
        delete vert;edkEnd();
    }
    return 0u;edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackVertex::newVertex(edk::vec3f32 position,edk::color4f32 color){
    return this->newVertex(position.x,position.y,position.z,color.r,color.g,color.b,color.a);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackVertex::newVertex(edk::shape::Vertex3D vert){
    return this->newVertex(vert.x,vert.y,vert.z,vert.r,vert.g,vert.b,vert.a);edkEnd();
}
edk::shape::Vertex3D* edk::shape::Mesh3D::StackVertex::getVertex(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshVertex* temp = this->stack.get(position);edkEnd();
        if(temp){
            return temp->pointer;edkEnd();
        }
    }
    return NULL;
}
bool edk::shape::Mesh3D::StackVertex::haveVertex(edk::uint32 position){
    return this->stack.havePos(position);edkEnd();
}
bool edk::shape::Mesh3D::StackVertex::deleteVertex(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshVertex* temp = this->stack.get(position);edkEnd();
        if(temp){
            if(this->stack.remove(position)){
                delete temp;edkEnd();
                return true;
            }
        }
    }
    return false;
}
bool edk::shape::Mesh3D::StackVertex::incrementVertex(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshVertex* temp = this->stack.get(position);edkEnd();
        if(temp){
            temp->incrementUse();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::shape::Mesh3D::StackVertex::decrementVertex(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshVertex* temp = this->stack.get(position);edkEnd();
        if(temp){
            return temp->decrementUse();edkEnd();
        }
    }
    return false;
}

edk::shape::Mesh3D::StackNormal::StackNormal(){
    //
}
edk::shape::Mesh3D::StackNormal::~StackNormal(){
    //
    this->cleanNormals();edkEnd();
}

//clean all normals
void edk::shape::Mesh3D::StackNormal::cleanNormals(){
    edk::uint32 size=this->stack.size();edkEnd();
    edk::shape::Mesh3D::MeshNormal* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->stack.havePos(i)){
            temp = this->stack.get(i);edkEnd();
            if(temp){
                delete temp;edkEnd();
            }
        }
    }
    this->stack.clean();edkEnd();
}
//get the size of the normals
edk::uint32 edk::shape::Mesh3D::StackNormal::size(){
    return this->stack.size();edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackNormal::getSize(){
    return this->stack.size();edkEnd();
}

//create a new normals in to the stack
edk::uint32 edk::shape::Mesh3D::StackNormal::newNormal(edk::float32 x,
                                                       edk::float32 y,
                                                       edk::float32 z
                                                       ){
    edk::shape::Mesh3D::MeshNormal* vert = new edk::shape::Mesh3D::MeshNormal;edkEnd();
    if(vert){
        vert->normal.x = x;edkEnd();
        vert->normal.y = y;edkEnd();
        vert->normal.z = z;edkEnd();
        edk::uint32 size = this->stack.size();edkEnd();
        edk::uint32 ret = this->stack.pushBack(vert);edkEnd();
        //add this vert in to
        if(size<this->stack.size()){
            return ret;
        }
        delete vert;edkEnd();
    }
    return 0u;edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackNormal::newNormal(edk::vec3f32 position){
    return this->newNormal(position.x,position.y,position.z);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackNormal::newNormal(edk::shape::Vector3D vert){
    return this->newNormal(vert.x,vert.y,vert.z);edkEnd();
}
edk::shape::Vector3D* edk::shape::Mesh3D::StackNormal::getNormal(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshNormal* temp = this->stack.get(position);edkEnd();
        if(temp){
            return temp->pointer;edkEnd();
        }
    }
    return NULL;
}
bool edk::shape::Mesh3D::StackNormal::haveNormal(edk::uint32 position){
    return this->stack.havePos(position);edkEnd();
}
bool edk::shape::Mesh3D::StackNormal::deleteNormal(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshNormal* temp = this->stack.get(position);edkEnd();
        if(temp){
            if(this->stack.remove(position)){
                delete temp;edkEnd();
                return true;
            }
        }
    }
    return false;
}
bool edk::shape::Mesh3D::StackNormal::incrementNormal(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshNormal* temp = this->stack.get(position);edkEnd();
        if(temp){
            temp->incrementUse();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::shape::Mesh3D::StackNormal::decrementNormal(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshNormal* temp = this->stack.get(position);edkEnd();
        if(temp){
            return temp->decrementUse();edkEnd();
        }
    }
    return false;
}

edk::shape::Mesh3D::StackUV::StackUV(){
    //
}
edk::shape::Mesh3D::StackUV::~StackUV(){
    //
    this->cleanUVS();edkEnd();
}

//clean all uvs
void edk::shape::Mesh3D::StackUV::cleanUVS(){
    edk::uint32 size=this->stack.size();edkEnd();
    edk::shape::Mesh3D::MeshUV* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        if(this->stack.havePos(i)){
            temp = this->stack.get(i);edkEnd();
            if(temp){
                delete temp;edkEnd();
            }
        }
    }
    this->stack.clean();edkEnd();
}
//get the size of the uvs
edk::uint32 edk::shape::Mesh3D::StackUV::size(){
    return this->stack.size();edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackUV::getSize(){
    return this->stack.size();edkEnd();
}

//create a new uv in to the stack
edk::uint32 edk::shape::Mesh3D::StackUV::newUV(edk::float32 u,
                                               edk::float32 v
                                               ){
    edk::shape::Mesh3D::MeshUV* vert = new edk::shape::Mesh3D::MeshUV;edkEnd();
    if(vert){
        vert->uv.u = u;edkEnd();
        vert->uv.v = v;edkEnd();
        edk::uint32 size = this->stack.size();edkEnd();
        edk::uint32 ret = this->stack.pushBack(vert);edkEnd();
        //add this vert in to
        if(size<this->stack.size()){
            return ret;
        }
        delete vert;edkEnd();
    }
    return 0u;edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackUV::newUV(edk::vec2f32 position){
    return this->newUV(position.x,position.y);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackUV::newUV(edk::shape::UV2D vert){
    return this->newUV(vert.u,vert.v);edkEnd();
}
edk::shape::UV2D* edk::shape::Mesh3D::StackUV::getUV(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshUV* temp = this->stack.get(position);edkEnd();
        if(temp){
            return temp->pointer;edkEnd();
        }
    }
    return NULL;
}
bool edk::shape::Mesh3D::StackUV::haveUV(edk::uint32 position){
    return this->stack.havePos(position);edkEnd();
}
bool edk::shape::Mesh3D::StackUV::deleteUV(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshUV* temp = this->stack.get(position);edkEnd();
        if(temp){
            if(this->stack.remove(position)){
                delete temp;edkEnd();
                return true;
            }
        }
    }
    return false;
}
bool edk::shape::Mesh3D::StackUV::incrementUV(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshUV* temp = this->stack.get(position);edkEnd();
        if(temp){
            temp->incrementUse();edkEnd();
            return true;
        }
    }
    return false;
}
bool edk::shape::Mesh3D::StackUV::decrementUV(edk::uint32 position){
    if(this->stack.havePos(position)){
        edk::shape::Mesh3D::MeshUV* temp = this->stack.get(position);edkEnd();
        if(temp){
            return temp->decrementUse();edkEnd();
        }
    }
    return false;
}

edk::shape::Mesh3D::StackPolygon::StackPolygon(){
    //
}
edk::shape::Mesh3D::StackPolygon::~StackPolygon(){
    //
    this->cleanPolygons();edkEnd();
}

edk::uint32 edk::shape::Mesh3D::StackPolygon::size(){
    return this->list.size();edkEnd();
}
edk::uint32 edk::shape::Mesh3D::StackPolygon::getSize(){
    return this->list.size();edkEnd();
}

//clean the polygon list
void edk::shape::Mesh3D::StackPolygon::cleanPolygons(){
    edk::uint32 size = this->list.size();edkEnd();
    edk::shape::Polygon3D* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->list.get(i);edkEnd();
        if(temp){
            delete temp;edkEnd();
        }
    }
    this->list.clean();edkEnd();
}
//create a new polygon
edk::uint32 edk::shape::Mesh3D::StackPolygon::newPolygon(edk::uint32 vertexes){
    //create a new polygon
    edk::shape::Polygon3D* poly = new edk::shape::Polygon3D;edkEnd();
    if(poly){
        if(poly->createPolygon(vertexes)){
            edk::uint32 ret=0u;
            edk::uint32 size = this->list.size();edkEnd();
            ret = this->list.pushBack(poly);edkEnd();
            if(size<this->list.size()){
                return ret;
            }
        }
        delete poly;edkEnd();
    }
    return 0u;edkEnd();
}
//return the polygon in a position
edk::shape::Polygon3D* edk::shape::Mesh3D::StackPolygon::getPolygon(edk::uint32 position){
    return this->list.get(position);edkEnd();
}
//print the polygons
void edk::shape::Mesh3D::StackPolygon::printPolygons(){
    this->list.print();edkEnd();
}
//draw the polygons
void edk::shape::Mesh3D::StackPolygon::drawPolygons(){
    this->list.render();edkEnd();
}
void edk::shape::Mesh3D::StackPolygon::drawPolygonsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
        edk::uint32 size = this->list.size();
        edk::shape::Polygon3D* poly;
        for(edk::uint32 i=0u;i<size;i++){
            poly=this->list.get(i);
            poly->drawWithMatrix(matrix,matrixTemp);
        }
    }
}
//Draw the polygon with lines
void edk::shape::Mesh3D::StackPolygon::drawWire(){
    this->list.drawWire();edkEnd();
}
void edk::shape::Mesh3D::StackPolygon::drawWireWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
        this->list.drawWireWithMatrix(matrix,matrixTemp);edkEnd();
    }
}
//Draw the polygon with lines
void edk::shape::Mesh3D::StackPolygon::drawWireWithColor(edk::color4f32 color){
    this->list.drawWireWithColor(color);edkEnd();
}
void edk::shape::Mesh3D::StackPolygon::drawWireWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color){
    if(matrix){
        this->list.drawWireWithMatrixWithColor(matrix,matrixTemp,color);edkEnd();
    }
}
//Draw the polygon with lines
void edk::shape::Mesh3D::StackPolygon::drawPolygonVertexs(edk::color4f32 color){
    this->list.drawPolygonVertexs(color);edkEnd();
}
void edk::shape::Mesh3D::StackPolygon::drawPolygonVertexsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color){
    if(matrix){
        this->list.drawPolygonVertexsWithMatrix(matrix,matrixTemp,color);edkEnd();
    }
}
//Draw the polygon normals lines
void edk::shape::Mesh3D::StackPolygon::drawPolygonNormals(){
    this->list.drawPolygonNormals();edkEnd();
}
void edk::shape::Mesh3D::StackPolygon::drawPolygonNormalsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
        this->list.drawPolygonNormalsWithMatrix(matrix,matrixTemp);edkEnd();
    }
}
//Draw the polygon normals lines
void edk::shape::Mesh3D::StackPolygon::drawPolygonNormalsWithColor(edk::color3f32 color){
    this->list.drawPolygonNormalsWithColor(color);edkEnd();
}
void edk::shape::Mesh3D::StackPolygon::drawPolygonNormalsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color3f32 color){
    if(matrix){
        this->list.drawPolygonNormalsWithMatrixWithColor(matrix,matrixTemp,color);edkEnd();
    }
}

edk::shape::Mesh3D::Mesh3D(){
    //mesh angles
    this->angles = edk::vec3f32(0,0,0);edkEnd();
    //mesh size
    this->size = edk::size3f32(1,1,1);edkEnd();
    //mesh position inside the object
    this->position = edk::vec3f32(0,0,0);edkEnd();
}
edk::shape::Mesh3D::~Mesh3D(){
    //
    this->cleanMesh();edkEnd();
}

void edk::shape::Mesh3D::calculateMatrices(){
    //generate the matrices
    this->matrixTransform.setIdentity(1.f,0.f);edkEnd();
    edk::Math::generateTranslateMatrix(this->position,&this->matrixTranslate);edkEnd();
    edk::Math::generateRotateMatrix(this->angles.x,this->angles.y,this->angles.z,&this->matrixRotate);edkEnd();
    edk::Math::generateScaleMatrix(this->size,&this->matrixScale);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixTranslate);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixRotate);edkEnd();
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixScale);edkEnd();
}

void edk::shape::Mesh3D::cleanVertexes(){
    this->vertexes.cleanVertexes();edkEnd();
}
void edk::shape::Mesh3D::cleanNormals(){
    this->normals.cleanNormals();edkEnd();
}
void edk::shape::Mesh3D::cleanUVs(){
    this->uvs.cleanUVS();edkEnd();
}
void edk::shape::Mesh3D::cleanPolygons(){
    this->polygons.cleanPolygons();edkEnd();
}
void edk::shape::Mesh3D::cleanMesh(){
    this->cleanPolygons();edkEnd();
    this->cleanVertexes();edkEnd();
    this->cleanNormals();edkEnd();
    this->cleanUVs();edkEnd();
}

edk::uint32 edk::shape::Mesh3D::getVertexSize(){
    return this->vertexes.size();edkEnd();
}
edk::uint32 edk::shape::Mesh3D::getUVSize(){
    return this->uvs.size();edkEnd();
}
edk::uint32 edk::shape::Mesh3D::getNormalSize(){
    return this->normals.size();edkEnd();
}
edk::uint32 edk::shape::Mesh3D::getPolygonSize(){
    return this->polygons.size();edkEnd();
}

//Set polygons color
bool edk::shape::Mesh3D::setPolygonsColor(edk::color4f32 color){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->setPolygonColor(color);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::setPolygonsColor(edk::color3f32 color){
    return setPolygonsColor(color.r,color.g,color.b);edkEnd();
}
bool edk::shape::Mesh3D::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->setPolygonColor(r,g,b);edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->setPolygonColor(r,g,b,a);edkEnd();
            }
        }
        return true;
    }
    return false;
}
//set polygons smooth
bool edk::shape::Mesh3D::setPolygonsSmooth(bool smooth){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->smooth=smooth;edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::setPolygonsSmoothOn(){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->smooth=true;edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::setPolygonsSmoothOff(){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->smooth=false;edkEnd();
            }
        }
        return true;
    }
    return false;
}
//update polygons normals
bool edk::shape::Mesh3D::updatePolygonsNormals(){
    //test if have polygons
    if(this->polygons.size()){
        edk::shape::Polygon3D* polygon=NULL;edkEnd();
        //set the polygonColors
        for(edk::uint32 i=0u;i<this->polygons.size();i++){
            polygon = this->polygons.getPolygon(i);edkEnd();
            if(polygon){
                polygon->updateNormal();edkEnd();
            }
        }
        return true;
    }
    return false;
}

//VERTEXES
edk::uint32 edk::shape::Mesh3D::newVertex(edk::float32 x,
                                          edk::float32 y,
                                          edk::float32 z,
                                          edk::float32 r,
                                          edk::float32 g,
                                          edk::float32 b
                                          ){
    return this->vertexes.newVertex(x,y,z,r,g,b);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::newVertex(edk::float32 x,
                                          edk::float32 y,
                                          edk::float32 z,
                                          edk::float32 r,
                                          edk::float32 g,
                                          edk::float32 b,
                                          edk::float32 a
                                          ){
    return this->vertexes.newVertex(x,y,z,r,g,b,a);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::newVertex(edk::vec3f32 position,edk::color4f32 color){
    return this->vertexes.newVertex(position,color);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::newVertex(edk::shape::Vertex3D vert){
    return this->vertexes.newVertex(vert);edkEnd();
}
//NORMALS
edk::uint32 edk::shape::Mesh3D::newNormal(edk::float32 x,edk::float32 y,edk::float32 z){
    return this->normals.newNormal(x,y,z);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::newNormal(edk::vec3f32 vector){
    return this->normals.newNormal(vector);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::newNormal(edk::shape::Vector3D vector){
    return this->normals.newNormal(vector);edkEnd();
}
//UVS
edk::uint32 edk::shape::Mesh3D::newUV(edk::float32 x,edk::float32 y){
    return this->uvs.newUV(x,y);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::newUV(edk::vec2f32 vector){
    return this->uvs.newUV(vector);edkEnd();
}
edk::uint32 edk::shape::Mesh3D::newUV(edk::shape::UV2D uv){
    return this->uvs.newUV(uv);edkEnd();
}

//get a vertex in a position
edk::shape::Vertex3D edk::shape::Mesh3D::getVertex(edk::uint32 position){
    edk::shape::Vertex3D ret;edkEnd();
    edk::shape::Vertex3D* temp = this->vertexes.getVertex(position);edkEnd();
    if(temp){
        ret = *temp;edkEnd();
    }
    return ret;
}
//get a vertex position
edk::vec3f32 edk::shape::Mesh3D::getVertexPosition(edk::uint32 position){
    edk::vec3f32 ret;edkEnd();
    edk::shape::Vertex3D* temp = this->vertexes.getVertex(position);edkEnd();
    if(temp){
        ret.x = temp->x;edkEnd();
        ret.y = temp->y;edkEnd();
        ret.z = temp->z;edkEnd();
    }
    return ret;
}
edk::color4f32 edk::shape::Mesh3D::getVertexColor(edk::uint32 position){
    edk::color4f32 ret;edkEnd();
    edk::shape::Vertex3D* temp = this->vertexes.getVertex(position);edkEnd();
    if(temp){
        ret.r = temp->r;edkEnd();
        ret.g = temp->g;edkEnd();
        ret.b = temp->b;edkEnd();
        ret.a = temp->a;edkEnd();
    }
    return ret;
}
//remove a vertex in a position
bool edk::shape::Mesh3D::removeVertex(edk::uint32 position){
    //test if have the vertex
    if(this->vertexes.haveVertex(position)){
        //remove all polygons where the vertex appears

        return this->vertexes.deleteVertex(position);edkEnd();
    }
    return false;
}

//get a normal in a position
edk::shape::Vector3D edk::shape::Mesh3D::getNormal(edk::uint32 position){
    edk::shape::Vector3D ret;edkEnd();
    edk::shape::Vector3D* temp = this->normals.getNormal(position);edkEnd();
    if(temp){
        ret = *temp;edkEnd();
    }
    return ret;
}
//get a normal vector
edk::vec3f32 edk::shape::Mesh3D::getNormalPosition(edk::uint32 position){
    edk::vec3f32 ret;edkEnd();
    edk::shape::Vector3D* temp = this->normals.getNormal(position);edkEnd();
    if(temp){
        ret.x = temp->x;edkEnd();
        ret.y = temp->y;edkEnd();
        ret.z = temp->z;edkEnd();
    }
    return ret;
}
//remove a normal in a position
bool edk::shape::Mesh3D::removeNormal(edk::uint32 position){
    //test if have the vertex
    if(this->normals.haveNormal(position)){
        //remove all polygons where the vertex appears

        return this->normals.deleteNormal(position);edkEnd();
    }
    return false;
}

//get the UV in a position
edk::shape::UV2D edk::shape::Mesh3D::getUV(edk::uint32 position){
    edk::shape::UV2D ret;edkEnd();
    edk::shape::UV2D* temp = this->uvs.getUV(position);edkEnd();
    if(temp){
        ret = *temp;edkEnd();
    }
    return ret;
}
//get a UV position
edk::vec2f32 edk::shape::Mesh3D::getUVPosition(edk::uint32 position){
    edk::vec2f32 ret;edkEnd();
    edk::shape::UV2D* temp = this->uvs.getUV(position);edkEnd();
    if(temp){
        ret.x = temp->u;edkEnd();
        ret.y = temp->v;edkEnd();
    }
    return ret;
}
//remove a UV in a position
bool edk::shape::Mesh3D::removeIV(edk::uint32 position){
    //test if have the vertex
    if(this->uvs.haveUV(position)){
        //remove all polygons where the vertex appears

        return this->uvs.deleteUV(position);edkEnd();
    }
    return false;
}
//POLYGONS
edk::uint32 edk::shape::Mesh3D::newPolygon(edk::uint32 vertexes){
    return this->polygons.newPolygon(vertexes);edkEnd();
}
//select the polygon
bool edk::shape::Mesh3D::selectPolygon(edk::uint32 position){
    this->selected = this->polygons.getPolygon(position);edkEnd();
    if(this->selected){
        return true;
    }
    return false;
}
//set polygon vertexes normals and UV
bool edk::shape::Mesh3D::selectedPolygonSetVertex(edk::uint32 position,edk::uint32 vertex){
    if(this->selected){
        //get the vertex
        edk::shape::Vertex3D* temp = this->vertexes.getVertex(vertex);edkEnd();
        if(temp){
            return this->selected->setVertex(position,temp,vertex);edkEnd();
        }
    }
    return false;
}
bool edk::shape::Mesh3D::selectedPolygonSetNormal(edk::uint32 position,edk::uint32 normal){
    if(this->selected){
        //get the vertex
        edk::shape::Vector3D* temp = this->normals.getNormal(normal);edkEnd();
        if(temp){
            return this->selected->setNormal(position,temp,normal);edkEnd();
        }
    }
    return false;
}
bool edk::shape::Mesh3D::selectedPolygonSetUV(edk::uint32 position,edk::uint32 uv){
    if(this->selected){
        //get the vertex
        edk::shape::UV2D* temp = this->uvs.getUV(uv);edkEnd();
        if(temp){
            return this->selected->setUV(position,temp,uv);edkEnd();
        }
    }
    return false;
}
bool edk::shape::Mesh3D::selectedPolygonSetNormalFlat(edk::shape::Vector3D normal){
    if(this->selected){
        //get the vertex
        this->selected->setNormalFlat(normal);edkEnd();
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::selectedPolygonSetSmooth(bool smooth){
    if(this->selected){
        this->selected->smooth=smooth;edkEnd();
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::selectedPolygonSmoothOn(){
    if(this->selected){
        this->selected->smooth=true;edkEnd();
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::selectedPolygonSmoothOff(){
    if(this->selected){
        this->selected->smooth=false;edkEnd();
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::selectedPolygonUpdateNormal(){
    if(this->selected){
        this->selected->updateNormal();edkEnd();
        return true;
    }
    return false;
}

//DRAW
//print the mesh
void edk::shape::Mesh3D::printPolygons(){
    this->polygons.printPolygons();edkEnd();
}
//draw the mesh
void edk::shape::Mesh3D::drawPolygons(){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angles.z);edkEnd();
    edk::GU::guRotateYf32(this->angles.y);edkEnd();
    edk::GU::guRotateXf32(this->angles.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    this->polygons.drawPolygons();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Mesh3D::drawPolygonsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
        //generate the matrices
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);
        this->polygons.drawPolygonsWithMatrix(matrix,matrixTemp);edkEnd();
    }
}
//draw the polygons in wireframe
void edk::shape::Mesh3D::drawWirePolygons(){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angles.z);edkEnd();
    edk::GU::guRotateYf32(this->angles.y);edkEnd();
    edk::GU::guRotateXf32(this->angles.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    this->polygons.drawWire();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Mesh3D::drawWirePolygonsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);
        this->polygons.drawWireWithMatrix(matrix,matrixTemp);edkEnd();
    }
}
void edk::shape::Mesh3D::drawWirePolygonsWithColor(edk::color4f32 color){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angles.z);edkEnd();
    edk::GU::guRotateYf32(this->angles.y);edkEnd();
    edk::GU::guRotateXf32(this->angles.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    this->polygons.drawWireWithColor(color);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Mesh3D::drawWirePolygonsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);
        this->polygons.drawWireWithMatrixWithColor(matrix,matrixTemp,color);edkEnd();
    }
}
void edk::shape::Mesh3D::drawVertexs(edk::color3f32 color){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angles.z);edkEnd();
    edk::GU::guRotateYf32(this->angles.y);edkEnd();
    edk::GU::guRotateXf32(this->angles.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    this->polygons.drawPolygonVertexs(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Mesh3D::drawVertexsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color3f32 color){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);
        this->polygons.drawPolygonVertexsWithMatrix(matrix,matrixTemp,edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
    }
}
void edk::shape::Mesh3D::drawPolygonsNormals(){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angles.z);edkEnd();
    edk::GU::guRotateYf32(this->angles.y);edkEnd();
    edk::GU::guRotateXf32(this->angles.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    this->polygons.drawPolygonNormals();edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Mesh3D::drawPolygonsNormalsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);
        this->polygons.drawPolygonNormalsWithMatrix(matrix,matrixTemp);edkEnd();
    }
}
void edk::shape::Mesh3D::drawPolygonsNormalsWithColor(edk::color3f32 color){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate3f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angles.z);edkEnd();
    edk::GU::guRotateYf32(this->angles.y);edkEnd();
    edk::GU::guRotateXf32(this->angles.x);edkEnd();
    //add scale
    edk::GU::guScale3f32(this->size);edkEnd();
    this->polygons.drawPolygonNormalsWithColor(color);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}
void edk::shape::Mesh3D::drawPolygonsNormalsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color3f32 color){
    if(matrix){
        this->calculateMatrices();edkEnd();
        //multiply with the matrix
        this->matrixTransform.multiplyThisWithMatrix(matrix);
        this->polygons.drawPolygonNormalsWithMatrixWithColor(matrix,matrixTemp,color);edkEnd();
    }
}

//draw the mesh
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
void edk::shape::Mesh3D::drawOneTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
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
void edk::shape::Mesh3D::drawOneTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::uint32 position){
    if(matrix){
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
bool edk::shape::Mesh3D::selectedDrawOneTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
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
bool edk::shape::Mesh3D::selectedDrawOneTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::uint32 position){
    if(matrix){
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
void edk::shape::Mesh3D::drawMultiTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
        //set the texture if have one
        if(this->material.haveTexture()){
            this->material.drawStartWithMultiTexture();edkEnd();
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
bool edk::shape::Mesh3D::selectedDrawMultiTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
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
    }
    return false;
}
void edk::shape::Mesh3D::drawWire(){
    this->material.drawNoTexture();edkEnd();
    //else just draw the mesh
    this->drawWirePolygons();edkEnd();
}
void edk::shape::Mesh3D::drawWireWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
    if(matrix){
        this->material.drawNoTexture();edkEnd();
        //else just draw the mesh
        this->drawWirePolygonsWithMatrix(matrix,matrixTemp);edkEnd();
    }
}
