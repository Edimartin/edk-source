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

    //get a vertex in a position
    edk::shape::Vertex3D getVertex(edk::uint32 position);
    //get a vertex position
    edk::vec3f32 getVertexPosition(edk::uint32 position);
    edk::color4f32 getVertexColor(edk::uint32 position);
    //remove a vertex in a position
    bool removeVertex(edk::uint32 position);
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

    class treeVertex:public edk::vector::BinaryTree<edk::shape::Mesh3D::MeshVertex*>{
    public:
        treeVertex(){}
        virtual ~treeVertex(){
            this->cleanVertexes();
        }
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::shape::Mesh3D::MeshVertex* first,edk::shape::Mesh3D::MeshVertex* second){
            if(first&&second){
                if(&first->pointer>&second->pointer){
                    return true;
                }
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::shape::Mesh3D::MeshVertex* first,edk::shape::Mesh3D::MeshVertex* second){
            if(first&&second){
                if(&first->pointer==&second->pointer){
                    return true;
                }
            }
            return false;
        }
        //Print
        virtual void printElement(edk::shape::Mesh3D::MeshVertex* value){
            //
        }
        virtual void renderElement(edk::shape::Mesh3D::MeshVertex* value){
            //
        }
        //UPDATE
        virtual void updateElement(edk::shape::Mesh3D::MeshVertex* value){
            //update the value
        }

        void cleanVertexes(){
            edk::uint32 size = this->size();
            edk::shape::Mesh3D::MeshVertex* temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    delete temp;
                }
            }
            this->clean();
        }

        //create a new vertex into the tree
        bool newVertex(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 r,edk::float32 g,edk::float32 b){
            return this->newVertex(x,y,z,r,g,b,1.f);
        }
        bool newVertex(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
            edk::shape::Mesh3D::MeshVertex* vert = new edk::shape::Mesh3D::MeshVertex;
            if(vert){
                vert->vertex.x = x;
                vert->vertex.y = y;
                vert->vertex.z = z;
                vert->vertex.r = r;
                vert->vertex.g = g;
                vert->vertex.b = b;
                vert->vertex.a = a;
                //add this vert in to
                if(this->add(vert)){
                    return true;
                }
                delete vert;
            }
            return false;
        }
        bool newVertex(edk::vec3f32 position,edk::color4f32 color){
            //
            return this->newVertex(position.x,position.y,position.z,color.r,color.g,color.b,color.a);
        }
        bool newVertex(edk::shape::Vertex3D vert){
            return this->newVertex(edk::vec3f32(vert.x,vert.y,vert.z),edk::color4f32(vert.r,vert.g,vert.b,vert.a));
        }
        edk::shape::Vertex3D* getVertexInPosition(edk::uint32 position){
            edk::shape::Mesh3D::MeshVertex* temp = this->getElementInPosition(position);
            if(temp){
                return temp->pointer;
            }
            return NULL;
        }
        //Delete vertex
        bool deleteVertex(edk::shape::Vertex3D* vert){
            edk::shape::Mesh3D::MeshVertex* temp = this->getMeshVertex(vert);
            if(temp){
                if(this->remove(temp)){
                    delete temp;
                    return true;
                }
            }
            return false;
        }
        //remove the vertex in a position
        bool deletePosition(edk::uint32 position){
            edk::shape::Mesh3D::MeshVertex* temp = this->getElementInPosition(position);
            if(temp){
                if(this->remove(temp)){
                    delete temp;
                    return true;
                }
            }
            return false;
        }
        //Increment and decrement the vertex use
        bool incrementVertex(edk::shape::Vertex3D* vert){
            edk::shape::Mesh3D::MeshVertex* temp = this->getMeshVertex(vert);
            if(temp){
                temp->incrementUse();
                return true;
            }
            return false;
        }
        bool incrementPosition(edk::uint32 position){
            edk::shape::Mesh3D::MeshVertex* temp = this->getElementInPosition(position);
            if(temp){
                temp->incrementUse();
                return true;
            }
            return false;
        }
        bool decrementVertex(edk::shape::Vertex3D* vert){
            edk::shape::Mesh3D::MeshVertex* temp = this->getMeshVertex(vert);
            if(temp){
                return temp->decrementUse();
            }
            return false;
        }
        bool decrementPosition(edk::uint32 position){
            edk::shape::Mesh3D::MeshVertex* temp = this->getElementInPosition(position);
            if(temp){
                return temp->decrementUse();
            }
            return false;
        }
        bool havePosition(edk::uint32 position){
            edk::shape::Mesh3D::MeshVertex* temp = this->getElementInPosition(position);
            if(temp){
                return true;
            }
            return false;
        }
    private:
        //get the vertex
        edk::shape::Mesh3D::MeshVertex* getMeshVertex(edk::shape::Vertex3D* vert){
            edk::shape::Mesh3D::MeshVertex temp;
            temp.pointer = vert;
            return this->getElement(&temp);
        }
    }vertexes;
};
}//end namespace shape
}//end namespace edk

#endif // MESH3D_H
