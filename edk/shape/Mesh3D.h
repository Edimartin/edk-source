#ifndef MESH3D_H
#define MESH3D_H

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

#ifdef printMessages
#warning "Inside Mesh3D"
#endif

#pragma once
#include "../vector/Stack.h"
#include "../vector/BinaryTree.h"
#include "Polygon3D.h"
#include "../Texture2DList.h"
#include "../material/Material.h"
//#include "../collision/MathCollision.h"
#include "../pack/FilePackage.h"

#ifdef printMessages
#warning "    Compiling Mesh3D"
#endif

namespace edk{
namespace shape{
class Mesh3D{
public:
    Mesh3D();
    ~Mesh3D();

    //VERTEXES
    bool newVertex(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 r,edk::float32 g,edk::float32 b);
    bool newVertex(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    bool newVertex(edk::vec3f32 position,edk::color4f32 color);
    bool newVertex(edk::shape::Vertex3D vert);
    //NORMALS
    bool newNormal(edk::float32 x,edk::float32 y,edk::float32 z);
    bool newNormal(edk::vec3f32 vector);
    bool newNormal(edk::shape::Vector3D vector);
    //UVS
    bool newUV(edk::float32 x,edk::float32 y);
    bool newUV(edk::vec2f32 vector);
    bool newUV(edk::shape::UV2D uv);

    //get a vertex in a position
    edk::shape::Vertex3D getVertex(edk::uint32 position);
    //get a vertex position
    edk::vec3f32 getVertexPosition(edk::uint32 position);
    edk::color4f32 getVertexColor(edk::uint32 position);
    //remove a vertex in a position
    bool removeVertex(edk::uint32 position);

    //get a normal in a position
    edk::shape::Vector3D getNormal(edk::uint32 position);
    //get a normal vector
    edk::vec3f32 getNormalPosition(edk::uint32 position);
    //remove a normal in a position
    bool removeNormal(edk::uint32 position);

    //get the UV in a position
    edk::shape::UV2D getUV(edk::uint32 position);
    //get a UV position
    edk::vec2f32 getUVPosition(edk::uint32 position);
    //remove a UV in a position
    bool removeIV(edk::uint32 position);
private:
    //Class to save all the vertexes from the polygon
    class MeshVertex{
    public:
        MeshVertex(){
            this->use = 0u;
            this->pointer = &this->vertex;
        }
        void incrementUse(){
            this->use++;
        }
        bool decrementUse(){
            if(this->use){
                this->use--;
            }
            if(this->use){
                return true;
            }
            return false;
        }
        edk::shape::Vertex3D vertex;
        edk::shape::Vertex3D* pointer;
        edk::uint32 use;
    };

    class StackVertex{
    public:
        StackVertex();
        ~StackVertex();

        //clean all vertexes
        void cleanVertexes();
        //get the size of the vertexes
        edk::uint32 size();
        edk::uint32 getSize();

        //create a new vertex in to the stack
        edk::uint32 newVertex(edk::float32 x,edk::float32 y,edk::float32 z);
        edk::uint32 newVertex(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 r,edk::float32 g,edk::float32 b);
        edk::uint32 newVertex(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
        edk::uint32 newVertex(edk::vec3f32 position,edk::color4f32 color);
        edk::uint32 newVertex(edk::shape::Vertex3D vert);

        edk::shape::Vertex3D* getVertex(edk::uint32 position);
        bool haveVertex(edk::uint32 position);
        bool deleteVertex(edk::uint32 position);
        bool incrementVertex(edk::uint32 position);
        bool decrementVertex(edk::uint32 position);
    private:
        edk::vector::Stack<edk::shape::Mesh3D::MeshVertex*> stack;
    }vertexes;

    //Class to save all the normals from the polygon
    class MeshNormal{
    public:
        MeshNormal(){
            this->use = 0u;
            this->pointer = &this->normal;
        }
        void incrementUse(){
            this->use++;
        }
        bool decrementUse(){
            if(this->use){
                this->use--;
            }
            if(this->use){
                return true;
            }
            return false;
        }
        edk::shape::Vector3D normal;
        edk::shape::Vector3D* pointer;
        edk::uint32 use;
    };

    class StackNormal{
    public:
        StackNormal();
        ~StackNormal();

        //clean all normals
        void cleanNormals();
        //get the size of the normals
        edk::uint32 size();
        edk::uint32 getSize();

        //create a new normal in to the stack
        edk::uint32 newNormal(edk::float32 x,edk::float32 y,edk::float32 z);
        edk::uint32 newNormal(edk::vec3f32 position);
        edk::uint32 newNormal(edk::shape::Vector3D vert);

        edk::shape::Vector3D* getNormal(edk::uint32 position);
        bool haveNormal(edk::uint32 position);
        bool deleteNormal(edk::uint32 position);
        bool incrementNormal(edk::uint32 position);
        bool decrementNormal(edk::uint32 position);
    private:
        edk::vector::Stack<edk::shape::Mesh3D::MeshNormal*> stack;
    }normals;

    //Class to save all the normals from the polygon
    class MeshUV{
    public:
        MeshUV(){
            this->use = 0u;
            this->pointer = &this->uv;
        }
        void incrementUse(){
            this->use++;
        }
        bool decrementUse(){
            if(this->use){
                this->use--;
            }
            if(this->use){
                return true;
            }
            return false;
        }
        edk::shape::UV2D uv;
        edk::shape::UV2D* pointer;
        edk::uint32 use;
    };

    class StackUV{
    public:
        StackUV();
        ~StackUV();

        //clean all uvs
        void cleanUVS();
        //get the size of the uvs
        edk::uint32 size();
        edk::uint32 getSize();

        //create a new uv in to the stack
        edk::uint32 newUV(edk::float32 u,edk::float32 x);
        edk::uint32 newUV(edk::vec2f32 position);
        edk::uint32 newUV(edk::shape::UV2D vert);

        edk::shape::UV2D* getUV(edk::uint32 position);
        bool haveUV(edk::uint32 position);
        bool deleteUV(edk::uint32 position);
        bool incrementUV(edk::uint32 position);
        bool decrementUV(edk::uint32 position);
    private:
        edk::vector::Stack<edk::shape::Mesh3D::MeshUV*> stack;
    }uvs;
};
}//end namespace shape
}//end namespace edk

#endif // MESH3D_H
