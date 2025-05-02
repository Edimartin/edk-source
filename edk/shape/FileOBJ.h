#ifndef FILEOBJ_H
#define FILEOBJ_H

/*
Library FileOBJ - read and Write OBJ files in EDK Game Engine
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
#pragma message "Inside FileOBJ"
#endif

#pragma once
#include "../vector/Stack.h"
#include "../vector/BinaryTree.h"
//list of polygons
#include "../Texture2DList.h"
#include "../material/Material.h"
#include "../collision/MathCollision.h"
#include "../pack/FilePackage.h"
#include "../material/Material.h"
#include "Mesh3D.h"

#ifdef printMessages
#pragma message "    Compiling FileOBJ"
#endif

namespace edk{
namespace shape{
class FileOBJ{
public:
    FileOBJ();
    ~FileOBJ();

    void Constructor();
    void Destructor();

    virtual edk::shape::Mesh3D* allocMeshForOBJ()=0;

protected:
    //OBJ
    bool objAddFile(const edk::char8* fileName);
    bool objAddFile(edk::char8* fileName);
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
        virtual ~StackVertex();

        void Constructor();
        void Destructor();

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
        edk::vector::Stack<edk::shape::FileOBJ::MeshVertex*> stack;
    private:
        edk::classID classThis;
    }vertexes;

    //Class to save all the normals from the polygon
    class MeshNormal{
    public:
        MeshNormal(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~MeshNormal(){
            this->Destructor();
        }

        void Constructor(){
            if(this->classThis!=this){
                this->classThis=this;

                this->normal.Constructor();

                this->use = 0u;
                this->pointer = &this->normal;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class

                this->normal.Destructor();
            }
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
    private:
        edk::classID classThis;
    };

    class StackNormal{
    public:
        StackNormal();
        virtual ~StackNormal();

        void Constructor();
        void Destructor();

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
        edk::vector::Stack<edk::shape::FileOBJ::MeshNormal*> stack;
    private:
        edk::classID classThis;
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
        virtual ~StackUV();

        void Constructor();
        void Destructor();

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
        edk::vector::Stack<edk::shape::FileOBJ::MeshUV*> stack;
    private:
        edk::classID classThis;
    }uvs;

    class MeshPolygon{
    public:
        MeshPolygon(){}
        ~MeshPolygon(){
            this->vertexes.clean();
            this->uvs.clean();
            this->normals.clean();
        }

        //stacks
        edk::vector::Stack<edk::shape::FileOBJ::MeshVertex*> vertexes;
        edk::vector::Stack<edk::shape::FileOBJ::MeshUV*> uvs;
        edk::vector::Stack<edk::shape::FileOBJ::MeshNormal*> normals;
    };

    class StackPolygons{
    public:
        StackPolygons();
        ~StackPolygons();

        void Constructor(bool runFather);

        void cleanPolygons();
        //add a new polygon
        bool newPolygon();
        edk::uint32 getSize();
        edk::uint32 size();
        bool havePolygon(edk::uint32 position);
        bool selectPolygon(edk::uint32 position);
        bool selectedAddVertex(edk::shape::FileOBJ::MeshVertex* vertex);

        //edk::vector::Stack<edk::shape::FileOBJ::MeshVertex*> vertexes;
        //edk::vector::Stack<edk::shape::FileOBJ::MeshUV*> uvs;
        //edk::vector::Stack<edk::shape::FileOBJ::MeshNormal*> normals;
    private:
        edk::vector::Stack<edk::shape::FileOBJ::MeshPolygon*> stack;
        edk::shape::FileOBJ::MeshPolygon* polygonSelected;
        edk::uint32 idPolygon;
    private:
        edk::classID classThis;
    }polygons;

    class MeshMaterial : public edk::Name{
    public:
        MeshMaterial(){}
        ~MeshMaterial(){}
        edk::material::Material material;
    };

    class TreeMaterials: public edk::vector::NameTree{
    public:
        TreeMaterials();
        ~TreeMaterials();

        void Constructor(bool runFather);

        //clean all materials
        void cleanMaterials();
        bool newMaterial(const edk::char8* name);
        bool newMaterial(edk::char8* name);
        bool selectMaterialByName(const edk::char8* name);
        bool selectMaterialByName(edk::char8* name);
        void unselectMaterial();
        edk::material::Material* getMaterialInPosition(edk::uint32 position);
        edk::material::Material* getMaterialByName(edk::char8* name);
        edk::material::Material* getMaterialByName(const edk::char8* name);

        edk::material::Material* selected;
    private:
        edk::classID classThis;
    }materials;

    //load the mtlFile
    bool loadMTL(const edk::char8* fileName,edk::shape::FileOBJ::TreeMaterials* materials);
    bool loadMTL(edk::char8* fileName,edk::shape::FileOBJ::TreeMaterials* materials);
private:
    edk::classID classThis;
};
}//end namespace shape
}//end namespace edk

#endif // FILEOBJ_H
