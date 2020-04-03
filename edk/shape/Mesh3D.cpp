#include "Mesh3D.h"

/*
Library Mesh3D - Draw a 3D Mesh in EDK Game Engine
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

edk::shape::Mesh3D::StackVertex::StackVertex(){
    //
}
edk::shape::Mesh3D::StackVertex::~StackVertex(){
    //
    this->cleanVertexes();
}

//clean all vertexes
void edk::shape::Mesh3D::StackVertex::cleanVertexes(){
    edk::uint32 size=this->stack.size();
    edk::shape::Mesh3D::MeshVertex* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);
        if(temp) delete temp;
    }
    this->stack.clean();
}
//get the size of the vertexes
edk::uint32 edk::shape::Mesh3D::StackVertex::size(){
    return this->stack.size();
}
edk::uint32 edk::shape::Mesh3D::StackVertex::getSize(){
    return this->stack.size();
}

//create a new vertex in to the stack
edk::uint32 edk::shape::Mesh3D::StackVertex::newVertex(edk::float32 x,edk::float32 y,edk::float32 z){
    return this->newVertex(x,y,z,1.f,1.f,1.f,1.f);
}
edk::uint32 edk::shape::Mesh3D::StackVertex::newVertex(edk::float32 x,
                                                       edk::float32 y,
                                                       edk::float32 z,
                                                       edk::float32 r,
                                                       edk::float32 g,
                                                       edk::float32 b
                                                       ){
    return this->newVertex(x,y,z,r,g,b,1.f);
}
edk::uint32 edk::shape::Mesh3D::StackVertex::newVertex(edk::float32 x,
                                                       edk::float32 y,
                                                       edk::float32 z,
                                                       edk::float32 r,
                                                       edk::float32 g,
                                                       edk::float32 b,
                                                       edk::float32 a
                                                       ){
    edk::shape::Mesh3D::MeshVertex* vert = new edk::shape::Mesh3D::MeshVertex;
    if(vert){
        vert->vertex.x = x;
        vert->vertex.y = y;
        vert->vertex.z = z;
        vert->vertex.r = r;
        vert->vertex.g = g;
        vert->vertex.b = b;
        vert->vertex.a = a;
        edk::uint32 size = this->stack.size();
        edk::uint32 ret = this->stack.pushBack(vert);
        //add this vert in to
        if(size<this->stack.size()){
            return ret;
        }
        delete vert;
    }
    return 0u;
}
edk::uint32 edk::shape::Mesh3D::StackVertex::newVertex(edk::vec3f32 position,edk::color4f32 color){
    return this->newVertex(position.x,position.y,position.z,color.r,color.g,color.b,color.a);
}
edk::uint32 edk::shape::Mesh3D::StackVertex::newVertex(edk::shape::Vertex3D vert){
    return this->newVertex(vert.x,vert.y,vert.z,vert.r,vert.g,vert.b,vert.a);
}
edk::shape::Vertex3D* edk::shape::Mesh3D::StackVertex::getVertex(edk::uint32 position){
    edk::shape::Mesh3D::MeshVertex* temp = this->stack.get(position);
    if(temp){
        return temp->pointer;
    }
    return NULL;
}
bool edk::shape::Mesh3D::StackVertex::haveVertex(edk::uint32 position){
    return this->stack.havePos(position);
}
bool edk::shape::Mesh3D::StackVertex::deleteVertex(edk::uint32 position){
    edk::shape::Mesh3D::MeshVertex* temp = this->stack.get(position);
    if(temp){
        if(this->stack.remove(position)){
            delete temp;
            return true;
        }
    }
    return false;
}
bool edk::shape::Mesh3D::StackVertex::incrementVertex(edk::uint32 position){
    edk::shape::Mesh3D::MeshVertex* temp = this->stack.get(position);
    if(temp){
        temp->incrementUse();
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::StackVertex::decrementVertex(edk::uint32 position){
    edk::shape::Mesh3D::MeshVertex* temp = this->stack.get(position);
    if(temp){
        return temp->decrementUse();
    }
    return false;
}

edk::shape::Mesh3D::StackNormal::StackNormal(){
    //
}
edk::shape::Mesh3D::StackNormal::~StackNormal(){
    //
    this->cleanNormals();
}

//clean all normals
void edk::shape::Mesh3D::StackNormal::cleanNormals(){
    edk::uint32 size=this->stack.size();
    edk::shape::Mesh3D::MeshNormal* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);
        if(temp) delete temp;
    }
    this->stack.clean();
}
//get the size of the normals
edk::uint32 edk::shape::Mesh3D::StackNormal::size(){
    return this->stack.size();
}
edk::uint32 edk::shape::Mesh3D::StackNormal::getSize(){
    return this->stack.size();
}

//create a new normals in to the stack
edk::uint32 edk::shape::Mesh3D::StackNormal::newNormal(edk::float32 x,
                                                       edk::float32 y,
                                                       edk::float32 z
                                                       ){
    edk::shape::Mesh3D::MeshNormal* vert = new edk::shape::Mesh3D::MeshNormal;
    if(vert){
        vert->normal.x = x;
        vert->normal.y = y;
        vert->normal.z = z;
        edk::uint32 size = this->stack.size();
        edk::uint32 ret = this->stack.pushBack(vert);
        //add this vert in to
        if(size<this->stack.size()){
            return ret;
        }
        delete vert;
    }
    return 0u;
}
edk::uint32 edk::shape::Mesh3D::StackNormal::newNormal(edk::vec3f32 position){
    return this->newNormal(position.x,position.y,position.z);
}
edk::uint32 edk::shape::Mesh3D::StackNormal::newNormal(edk::shape::Vector3D vert){
    return this->newNormal(vert.x,vert.y,vert.z);
}
edk::shape::Vector3D* edk::shape::Mesh3D::StackNormal::getNormal(edk::uint32 position){
    edk::shape::Mesh3D::MeshNormal* temp = this->stack.get(position);
    if(temp){
        return temp->pointer;
    }
    return NULL;
}
bool edk::shape::Mesh3D::StackNormal::haveNormal(edk::uint32 position){
    return this->stack.havePos(position);
}
bool edk::shape::Mesh3D::StackNormal::deleteNormal(edk::uint32 position){
    edk::shape::Mesh3D::MeshNormal* temp = this->stack.get(position);
    if(temp){
        if(this->stack.remove(position)){
            delete temp;
            return true;
        }
    }
    return false;
}
bool edk::shape::Mesh3D::StackNormal::incrementNormal(edk::uint32 position){
    edk::shape::Mesh3D::MeshNormal* temp = this->stack.get(position);
    if(temp){
        temp->incrementUse();
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::StackNormal::decrementNormal(edk::uint32 position){
    edk::shape::Mesh3D::MeshNormal* temp = this->stack.get(position);
    if(temp){
        return temp->decrementUse();
    }
    return false;
}

edk::shape::Mesh3D::StackUV::StackUV(){
    //
}
edk::shape::Mesh3D::StackUV::~StackUV(){
    //
    this->cleanUVS();
}

//clean all uvs
void edk::shape::Mesh3D::StackUV::cleanUVS(){
    edk::uint32 size=this->stack.size();
    edk::shape::Mesh3D::MeshUV* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->stack.get(i);
        if(temp) delete temp;
    }
    this->stack.clean();
}
//get the size of the uvs
edk::uint32 edk::shape::Mesh3D::StackUV::size(){
    return this->stack.size();
}
edk::uint32 edk::shape::Mesh3D::StackUV::getSize(){
    return this->stack.size();
}

//create a new uv in to the stack
edk::uint32 edk::shape::Mesh3D::StackUV::newUV(edk::float32 u,
                                               edk::float32 v
                                               ){
    edk::shape::Mesh3D::MeshUV* vert = new edk::shape::Mesh3D::MeshUV;
    if(vert){
        vert->uv.u = u;
        vert->uv.v = v;
        edk::uint32 size = this->stack.size();
        edk::uint32 ret = this->stack.pushBack(vert);
        //add this vert in to
        if(size<this->stack.size()){
            return ret;
        }
        delete vert;
    }
    return 0u;
}
edk::uint32 edk::shape::Mesh3D::StackUV::newUV(edk::vec2f32 position){
    return this->newUV(position.x,position.y);
}
edk::uint32 edk::shape::Mesh3D::StackUV::newUV(edk::shape::UV2D vert){
    return this->newUV(vert.u,vert.v);
}
edk::shape::UV2D* edk::shape::Mesh3D::StackUV::getUV(edk::uint32 position){
    edk::shape::Mesh3D::MeshUV* temp = this->stack.get(position);
    if(temp){
        return temp->pointer;
    }
    return NULL;
}
bool edk::shape::Mesh3D::StackUV::haveUV(edk::uint32 position){
    return this->stack.havePos(position);
}
bool edk::shape::Mesh3D::StackUV::deleteUV(edk::uint32 position){
    edk::shape::Mesh3D::MeshUV* temp = this->stack.get(position);
    if(temp){
        if(this->stack.remove(position)){
            delete temp;
            return true;
        }
    }
    return false;
}
bool edk::shape::Mesh3D::StackUV::incrementUV(edk::uint32 position){
    edk::shape::Mesh3D::MeshUV* temp = this->stack.get(position);
    if(temp){
        temp->incrementUse();
        return true;
    }
    return false;
}
bool edk::shape::Mesh3D::StackUV::decrementUV(edk::uint32 position){
    edk::shape::Mesh3D::MeshUV* temp = this->stack.get(position);
    if(temp){
        return temp->decrementUse();
    }
    return false;
}

edk::shape::Mesh3D::StackPolygon::StackPolygon(){
    //
}
edk::shape::Mesh3D::StackPolygon::~StackPolygon(){
    //
    this->cleanPolygons();
}

edk::uint32 edk::shape::Mesh3D::StackPolygon::size(){
    return this->list.size();
}
edk::uint32 edk::shape::Mesh3D::StackPolygon::getSize(){
    return this->list.size();
}

//clean the polygon list
void edk::shape::Mesh3D::StackPolygon::cleanPolygons(){
    edk::uint32 size = this->list.size();
    edk::shape::Polygon3D* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->list.get(i);
        if(temp){
            delete temp;
        }
    }
    this->list.clean();
}
//create a new polygon
edk::uint32 edk::shape::Mesh3D::StackPolygon::newPolygon(edk::uint32 vertexes){
    //create a new polygon
    edk::shape::Polygon3D* poly = new edk::shape::Polygon3D;
    if(poly){
        if(poly->createPolygon(vertexes)){
            edk::uint32 ret=0u;
            edk::uint32 size = this->list.size();
            ret = this->list.pushBack(poly);
            if(size<this->list.size()){
                return ret;
            }
        }
        delete poly;
    }
    return 0u;
}
//return the polygon in a position
edk::shape::Polygon3D* edk::shape::Mesh3D::StackPolygon::getPolygon(edk::uint32 position){
    return this->list.get(position);
}
//print the polygons
void edk::shape::Mesh3D::StackPolygon::printPolygons(){
    this->list.print();
}
//draw the polygons
void edk::shape::Mesh3D::StackPolygon::drawPolygons(){
    this->list.render();
}
void edk::shape::Mesh3D::StackPolygon::drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]
){
    this->list.drawWithLight(lightPositions,lightDirections,lightIsOn);
}
//Draw the polygon with lines
void edk::shape::Mesh3D::StackPolygon::drawWire(){
    this->list.drawWire();
}
//Draw the polygon with lines
void edk::shape::Mesh3D::StackPolygon::drawWireWithColor(edk::color4f32 color){
    this->list.drawWireWithColor(color);
}
//Draw the polygon with lines
void edk::shape::Mesh3D::StackPolygon::drawPolygonVertexs(edk::color4f32 color){
    this->list.drawPolygonVertexs(color);
}

edk::shape::Mesh3D::Mesh3D(){
    //
}
edk::shape::Mesh3D::~Mesh3D(){
    //
}

//VERTEXES
edk::uint32 edk::shape::Mesh3D::newVertex(edk::float32 x,
                                          edk::float32 y,
                                          edk::float32 z,
                                          edk::float32 r,
                                          edk::float32 g,
                                          edk::float32 b
                                          ){
    return this->vertexes.newVertex(x,y,z,r,g,b);
}
edk::uint32 edk::shape::Mesh3D::newVertex(edk::float32 x,
                                          edk::float32 y,
                                          edk::float32 z,
                                          edk::float32 r,
                                          edk::float32 g,
                                          edk::float32 b,
                                          edk::float32 a
                                          ){
    return this->vertexes.newVertex(x,y,z,r,g,b,a);
}
edk::uint32 edk::shape::Mesh3D::newVertex(edk::vec3f32 position,edk::color4f32 color){
    return this->vertexes.newVertex(position,color);
}
edk::uint32 edk::shape::Mesh3D::newVertex(edk::shape::Vertex3D vert){
    return this->vertexes.newVertex(vert);
}
//NORMALS
edk::uint32 edk::shape::Mesh3D::newNormal(edk::float32 x,edk::float32 y,edk::float32 z){
    return this->normals.newNormal(x,y,z);
}
edk::uint32 edk::shape::Mesh3D::newNormal(edk::vec3f32 vector){
    return this->normals.newNormal(vector);
}
edk::uint32 edk::shape::Mesh3D::newNormal(edk::shape::Vector3D vector){
    return this->normals.newNormal(vector);
}
//UVS
edk::uint32 edk::shape::Mesh3D::newUV(edk::float32 x,edk::float32 y){
    return this->uvs.newUV(x,y);
}
edk::uint32 edk::shape::Mesh3D::newUV(edk::vec2f32 vector){
    return this->uvs.newUV(vector);
}
edk::uint32 edk::shape::Mesh3D::newUV(edk::shape::UV2D uv){
    return this->uvs.newUV(uv);
}

//get a vertex in a position
edk::shape::Vertex3D edk::shape::Mesh3D::getVertex(edk::uint32 position){
    edk::shape::Vertex3D ret;
    edk::shape::Vertex3D* temp = this->vertexes.getVertex(position);
    if(temp){
        ret = *temp;
    }
    return ret;
}
//get a vertex position
edk::vec3f32 edk::shape::Mesh3D::getVertexPosition(edk::uint32 position){
    edk::vec3f32 ret;
    edk::shape::Vertex3D* temp = this->vertexes.getVertex(position);
    if(temp){
        ret.x = temp->x;
        ret.y = temp->y;
        ret.z = temp->z;
    }
    return ret;
}
edk::color4f32 edk::shape::Mesh3D::getVertexColor(edk::uint32 position){
    edk::color4f32 ret;
    edk::shape::Vertex3D* temp = this->vertexes.getVertex(position);
    if(temp){
        ret.r = temp->r;
        ret.g = temp->g;
        ret.b = temp->b;
        ret.a = temp->a;
    }
    return ret;
}
//remove a vertex in a position
bool edk::shape::Mesh3D::removeVertex(edk::uint32 position){
    //test if have the vertex
    if(this->vertexes.haveVertex(position)){
        //remove all polygons where the vertex appears

        return this->vertexes.deleteVertex(position);
    }
    return false;
}

//get a normal in a position
edk::shape::Vector3D edk::shape::Mesh3D::getNormal(edk::uint32 position){
    edk::shape::Vector3D ret;
    edk::shape::Vector3D* temp = this->normals.getNormal(position);
    if(temp){
        ret = *temp;
    }
    return ret;
}
//get a normal vector
edk::vec3f32 edk::shape::Mesh3D::getNormalPosition(edk::uint32 position){
    edk::vec3f32 ret;
    edk::shape::Vector3D* temp = this->normals.getNormal(position);
    if(temp){
        ret.x = temp->x;
        ret.y = temp->y;
        ret.z = temp->z;
    }
    return ret;
}
//remove a normal in a position
bool edk::shape::Mesh3D::removeNormal(edk::uint32 position){
    //test if have the vertex
    if(this->normals.haveNormal(position)){
        //remove all polygons where the vertex appears

        return this->normals.deleteNormal(position);
    }
    return false;
}

//get the UV in a position
edk::shape::UV2D edk::shape::Mesh3D::getUV(edk::uint32 position){
    edk::shape::UV2D ret;
    edk::shape::UV2D* temp = this->uvs.getUV(position);
    if(temp){
        ret = *temp;
    }
    return ret;
}
//get a UV position
edk::vec2f32 edk::shape::Mesh3D::getUVPosition(edk::uint32 position){
    edk::vec2f32 ret;
    edk::shape::UV2D* temp = this->uvs.getUV(position);
    if(temp){
        ret.x = temp->u;
        ret.y = temp->v;
    }
    return ret;
}
//remove a UV in a position
bool edk::shape::Mesh3D::removeIV(edk::uint32 position){
    //test if have the vertex
    if(this->uvs.haveUV(position)){
        //remove all polygons where the vertex appears

        return this->uvs.deleteUV(position);
    }
    return false;
}
//POLYGONS
edk::uint32 edk::shape::Mesh3D::newPolygon(edk::uint32 vertexes){
    return this->polygons.newPolygon(vertexes);
}
//select the polygon
bool edk::shape::Mesh3D::selectPolygon(edk::uint32 position){
    this->selected = this->polygons.getPolygon(position);
    if(this->selected){
        return true;
    }
    return false;
}
//set polygon vertexes normals and UV
bool edk::shape::Mesh3D::selectedPolygonSetVertex(edk::uint32 position,edk::uint32 vertex){
    if(this->selected){
        //get the vertex
        edk::shape::Vertex3D* temp = this->vertexes.getVertex(vertex);
        if(temp){
            return this->selected->setVertex(position,temp,vertex);
        }
    }
    return false;
}
bool edk::shape::Mesh3D::selectedPolygonSetNormal(edk::uint32 position,edk::uint32 normal){
    if(this->selected){
        //get the vertex
        edk::shape::Vector3D* temp = this->normals.getNormal(normal);
        if(temp){
            return this->selected->setNormal(position,temp,normal);
        }
    }
    return false;
}
bool edk::shape::Mesh3D::selectedPolygonSetUV(edk::uint32 position,edk::uint32 uv){
    if(this->selected){
        //get the vertex
        edk::shape::UV2D* temp = this->uvs.getUV(uv);
        if(temp){
            return this->selected->setUV(position,temp,uv);
        }
    }
    return false;
}

//DRAW
//print the mesh
void edk::shape::Mesh3D::printPolygons(){
    this->polygons.printPolygons();
}
//draw the mesh
void edk::shape::Mesh3D::drawPolygons(){
    this->polygons.drawPolygons();
}
//draw the mesh with lights
void edk::shape::Mesh3D::drawPolygonsWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
bool lightIsOn[][EDK_LIGHT_LIMIT]
){
    this->polygons.drawWithLight(lightPositions,lightDirections,lightIsOn);
}
//draw the polygons in wireframe
void edk::shape::Mesh3D::drawWirePolygons(){
    this->polygons.drawWire();
}
void edk::shape::Mesh3D::drawWirePolygonsWithColor(edk::color4f32 color){
    this->polygons.drawWireWithColor(color);
}
void edk::shape::Mesh3D::drawVertexs(edk::color3f32 color){
    //
}
