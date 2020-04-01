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

edk::shape::Mesh3D::Mesh3D(){
    //
}
edk::shape::Mesh3D::~Mesh3D(){
    //
}

//VERTEXES
bool edk::shape::Mesh3D::newVertex(edk::float32 x,
                                   edk::float32 y,
                                   edk::float32 z,
                                   edk::float32 r,
                                   edk::float32 g,
                                   edk::float32 b
                                   ){
    return this->vertexes.newVertex(x,y,z,r,g,b);
}
bool edk::shape::Mesh3D::newVertex(edk::float32 x,
                                   edk::float32 y,
                                   edk::float32 z,
                                   edk::float32 r,
                                   edk::float32 g,
                                   edk::float32 b,
                                   edk::float32 a
                                   ){
    return this->vertexes.newVertex(x,y,z,r,g,b,a);
}
bool edk::shape::Mesh3D::newVertex(edk::vec3f32 position,edk::color4f32 color){
    return this->vertexes.newVertex(position,color);
}
bool edk::shape::Mesh3D::newVertex(edk::shape::Vertex3D vert){
    return this->vertexes.newVertex(vert);
}

//get a vertex in a position
edk::shape::Vertex3D edk::shape::Mesh3D::getVertex(edk::uint32 position){
    edk::shape::Vertex3D ret;
    edk::shape::Vertex3D* temp = this->vertexes.getVertexInPosition(position);
    if(temp){
        ret = *temp;
    }
    return ret;
}
//get a vertex position
edk::vec3f32 edk::shape::Mesh3D::getVertexPosition(edk::uint32 position){
    edk::vec3f32 ret;
    edk::shape::Vertex3D* temp = this->vertexes.getVertexInPosition(position);
    if(temp){
        ret.x = temp->x;
        ret.y = temp->y;
        ret.z = temp->z;
    }
    return ret;
}
edk::color4f32 edk::shape::Mesh3D::getVertexColor(edk::uint32 position){
    edk::color4f32 ret;
    edk::shape::Vertex3D* temp = this->vertexes.getVertexInPosition(position);
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
    if(this->vertexes.havePosition(position)){
        //remove all polygons where the vertex appears

        return this->vertexes.deletePosition(position);
    }
}
