#ifndef MESH3D_H
#define MESH3D_H

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
#pragma message "Inside Mesh3D"
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
#pragma message "    Compiling Mesh3D"
#endif

namespace edk{
namespace shape{
class Mesh3D{
public:
    Mesh3D();
    virtual ~Mesh3D();

    void cleanVertexes();
    void cleanNormals();
    void cleanUVs();
    void cleanPolygons();
    void cleanMesh();

    edk::uint32 getVertexSize();
    edk::uint32 getUVSize();
    edk::uint32 getNormalSize();
    edk::uint32 getPolygonSize();

    //Set polygons color
    bool setPolygonsColor(edk::color4f32 color);
    bool setPolygonsColor(edk::color3f32 color);
    bool setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b);
    bool setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    //set polygons smooth
    bool setPolygonsSmooth(bool smooth);
    bool setPolygonsSmoothOn();
    bool setPolygonsSmoothOff();
    //update polygons normals
    bool updatePolygonsNormals();

    //VERTEXES
    edk::uint32 newVertex(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 r,edk::float32 g,edk::float32 b);
    edk::uint32 newVertex(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    edk::uint32 newVertex(edk::vec3f32 position,edk::color4f32 color);
    edk::uint32 newVertex(edk::shape::Vertex3D vert);
    //NORMALS
    edk::uint32 newNormal(edk::float32 x,edk::float32 y,edk::float32 z);
    edk::uint32 newNormal(edk::vec3f32 vector);
    edk::uint32 newNormal(edk::shape::Vector3D vector);
    //UVS
    edk::uint32 newUV(edk::float32 x,edk::float32 y);
    edk::uint32 newUV(edk::vec2f32 vector);
    edk::uint32 newUV(edk::shape::UV2D uv);

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

    //POLYGONS
    edk::uint32 newPolygon(edk::uint32 vertexes);
    //select the polygon
    bool selectPolygon(edk::uint32 position);
    //set polygon vertexes normals and UV
    bool selectedPolygonSetVertex(edk::uint32 position,edk::uint32 vertex);
    bool selectedPolygonSetNormal(edk::uint32 position,edk::uint32 normal);
    bool selectedPolygonSetUV(edk::uint32 position,edk::uint32 uv);
    bool selectedPolygonSetNormalFlat(edk::shape::Vector3D normal);
    bool selectedPolygonSetSmooth(bool smooth);
    bool selectedPolygonSmoothOn();
    bool selectedPolygonSmoothOff();
    bool selectedPolygonUpdateNormal();

    //DRAW
    //print the mesh
    virtual void printPolygons();
    //draw the mesh
    virtual void drawPolygons();
    virtual void drawPolygonsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    //draw the polygons in wireframe
    virtual void drawWirePolygons();
    virtual void drawWirePolygonsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    virtual void drawWirePolygonsWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));
    virtual void drawWirePolygonsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color=edk::color4f32(1,1,1,1));
    virtual void drawVertexs(edk::color3f32 color = edk::color3f32(1,1,1));
    virtual void drawVertexsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color3f32 color = edk::color3f32(1,1,1));
    virtual void drawPolygonsNormals();
    virtual void drawPolygonsNormalsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    virtual void drawPolygonsNormalsWithColor(edk::color3f32 color = edk::color3f32(1,1,1));
    virtual void drawPolygonsNormalsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color3f32 color = edk::color3f32(1,1,1));


    //draw the mesh
    virtual void drawOneTexture();
    virtual void drawOneTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    virtual void drawOneTexture(edk::uint32 position);
    virtual void drawOneTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::uint32 position);
    virtual bool selectedDrawOneTexture();
    virtual bool selectedDrawOneTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    virtual bool selectedDrawOneTexture(edk::uint32 position);
    virtual bool selectedDrawOneTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::uint32 position);
    virtual void drawMultiTexture();
    virtual void drawMultiTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    virtual bool selectedDrawMultiTexture();
    virtual bool selectedDrawMultiTextureWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
    virtual void drawWire();
    virtual void drawWireWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);

    //Material used for the mesh
    edk::material::Material material;

    //mesh angles
    edk::vec3f32 angles;
    //mesh size
    edk::size3f32 size;
    //mesh position inside the object
    edk::vec3f32 position;
private:
    edk::vector::Matrix<edk::float32,4u,4u> matrixTranslate;
    edk::vector::Matrix<edk::float32,4u,4u> matrixRotate;
    edk::vector::Matrix<edk::float32,4u,4u> matrixScale;
    edk::vector::Matrix<edk::float32,4u,4u> matrixTransform;

    void calculateMatrices();

    //Class to save all the vertexes from the polygon
    class MeshVertex{
    public:
        MeshVertex(){
            this->use = 0u;edkEnd();
            this->pointer = &this->vertex;edkEnd();
        }
        void incrementUse(){
            this->use++;edkEnd();
        }
        bool decrementUse(){
            if(this->use){
                this->use--;edkEnd();
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
            this->use = 0u;edkEnd();
            this->pointer = &this->normal;edkEnd();
        }
        void incrementUse(){
            this->use++;edkEnd();
        }
        bool decrementUse(){
            if(this->use){
                this->use--;edkEnd();
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
            this->use = 0u;edkEnd();
            this->pointer = &this->uv;edkEnd();
        }
        void incrementUse(){
            this->use++;edkEnd();
        }
        bool decrementUse(){
            if(this->use){
                this->use--;edkEnd();
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


protected:
    class PolygonList: public edk::vector::Stack<edk::shape::Polygon3D*>{
    public:
        PolygonList(){}
        ~PolygonList(){}
        void updateElement(edk::shape::Polygon3D* value){
            this->func(this,value);edkEnd();
        }
        void loadElement(edk::shape::Polygon3D* value){
            this->funcWithMatrix(this->matrixPointer,this->matrixPointer2,this,value);edkEnd();
        }
        void printElement(edk::shape::Polygon3D* value){
            value->print();edkEnd();
        }
        void renderElement(edk::shape::Polygon3D* value){
            value->draw();edkEnd();
        }

        //Draw the polygon with lines
        //WithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix)
        void drawWire(){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawWire;edkEnd();
            this->update();edkEnd();
        }
        void drawWireWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->matrixPointer = matrix;
                this->matrixPointer2 = matrixTemp;
                this->funcWithMatrix = edk::shape::Mesh3D::PolygonList::runDrawWireWithMatrix;edkEnd();
                this->load();edkEnd();
            }
        }
        static void runDrawWire(edk::shape::Mesh3D::PolygonList*,edk::shape::Polygon3D* value){
            value->drawWire();edkEnd();
        }
        static void runDrawWireWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::shape::Mesh3D::PolygonList*,edk::shape::Polygon3D* value){
            value->drawWireWithMatrix(matrix,matrixTemp);edkEnd();
        }
        /*
        void drawWireWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));edkEnd();
        */
        //Draw the polygon with lines
        void drawWireWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1)){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawWireWithColor;edkEnd();
            this->color = color;edkEnd();
            this->update();edkEnd();
        }
        void drawWireWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color=edk::color4f32(1,1,1,1)){
            if(matrix){
                this->matrixPointer = matrix;
                this->matrixPointer2 = matrixTemp;
                this->funcWithMatrix = edk::shape::Mesh3D::PolygonList::runDrawWireWithMatrixWithColor;edkEnd();
                this->color = color;edkEnd();
                this->load();edkEnd();
            }
        }
        static void runDrawWireWithColor(edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value){
            value->drawWireWithColor(list->color);edkEnd();
        }
        static void runDrawWireWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value){
            value->drawWithWireWithMatrixWithColor(matrix,matrixTemp,list->color);edkEnd();
        }
        //Draw the polygon with lines
        void drawPolygonVertexs(edk::color4f32 color=edk::color4f32(1,1,1,1)){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawPolygonVertexs;edkEnd();
            this->color = color;edkEnd();
            this->update();edkEnd();
        }
        void drawPolygonVertexsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color=edk::color4f32(1,1,1,1)){
            if(matrix){
                this->matrixPointer = matrix;
                this->matrixPointer2 = matrixTemp;
                this->funcWithMatrix = edk::shape::Mesh3D::PolygonList::runDrawPolygonVertexsWithMatrix;edkEnd();
                this->color = color;edkEnd();
                this->load();edkEnd();
            }
        }
        static void runDrawPolygonVertexs(edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value){
            value->drawPolygonVertexs(list->color);edkEnd();
        }
        static void runDrawPolygonVertexsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value){
            value->drawPolygonVertexsWithMatrix(matrix,matrixTemp,list->color);edkEnd();
        }

        //Draw the polygon normals
        void drawPolygonNormals(){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawPolygonNormals;edkEnd();
            this->update();edkEnd();
        }
        void drawPolygonNormalsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp){
            if(matrix){
                this->matrixPointer = matrix;
                this->matrixPointer2 = matrixTemp;
                this->funcWithMatrix = edk::shape::Mesh3D::PolygonList::runDrawPolygonNormalsWithMatrix;edkEnd();
                this->load();edkEnd();
            }
        }
        static void runDrawPolygonNormals(edk::shape::Mesh3D::PolygonList*,edk::shape::Polygon3D* value){
            value->drawPolygonNormals();edkEnd();
        }
        static void runDrawPolygonNormalsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::shape::Mesh3D::PolygonList*,edk::shape::Polygon3D* value){
            value->drawPolygonNormalsWithMatrix(matrix,matrixTemp);edkEnd();
        }
        //Draw the polygon with lines
        void drawPolygonNormalsWithColor(edk::color3f32 color=edk::color3f32(1,1,1)){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawPolygonNormalsWithColor;edkEnd();
            this->color = color;edkEnd();
            this->update();edkEnd();
        }
        void drawPolygonNormalsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color3f32 color=edk::color3f32(1,1,1)){
            if(matrix){
                this->matrixPointer = matrix;
                this->matrixPointer2 = matrixTemp;
                this->funcWithMatrix = edk::shape::Mesh3D::PolygonList::runDrawPolygonNormalsWithMatrixWithColor;edkEnd();
                this->color = color;edkEnd();
                this->load();edkEnd();
            }
        }
        static void runDrawPolygonNormalsWithColor(edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value){
            value->drawPolygonNormalsWithColor(list->color);edkEnd();
        }
        static void runDrawPolygonNormalsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value){
            value->drawPolygonNormalsWithMatrixWithColor(matrix,matrixTemp,list->color);edkEnd();
        }

        void (*func)(edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value);
        void (*funcWithMatrix)(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value);
        edk::color4f32 color;
        edk::float32 lightPositions[EDK_LIGHT_LIMIT][4u];
        edk::float32 lightDirections[EDK_LIGHT_LIMIT][4u];
        bool lightIsOn[EDK_LIGHT_LIMIT];
        edk::vector::Matrix<edk::float32,4u,4u>* matrixPointer;
        edk::vector::Matrix<edk::float32,4u,4u>* matrixPointer2;
    };
    //Polygon List
    class StackPolygon{
    public:
        StackPolygon();
        ~StackPolygon();

        edk::uint32 size();
        edk::uint32 getSize();

        //clean the polygon list
        void cleanPolygons();
        //create a new polygon
        edk::uint32 newPolygon(edk::uint32 vertexes);
        //return the polygon in a position
        edk::shape::Polygon3D* getPolygon(edk::uint32 position);

        //print the polygons
        void printPolygons();
        //draw the polygons
        void drawPolygons();
        void drawPolygonsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
        //Draw the polygon with lines
        void drawWire();
        void drawWireWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
        //Draw the polygon with lines
        void drawWireWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));
        void drawWireWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color=edk::color4f32(1,1,1,1));
        //Draw the polygon with lines
        void drawPolygonVertexs(edk::color4f32 color=edk::color4f32(1,1,1,1));
        void drawPolygonVertexsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color4f32 color=edk::color4f32(1,1,1,1));
        //Draw the polygon normals lines
        void drawPolygonNormals();
        void drawPolygonNormalsWithMatrix(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp);
        //Draw the polygon normals lines
        void drawPolygonNormalsWithColor(edk::color3f32 color=edk::color3f32(1,1,1));
        void drawPolygonNormalsWithMatrixWithColor(edk::vector::Matrix<edk::float32,4u,4u>* matrix,edk::vector::Matrix<edk::float32,4u,4u>* matrixTemp,edk::color3f32 color=edk::color3f32(1,1,1));
    private:
        //list of polygons
        edk::shape::Mesh3D::PolygonList list;
    }polygons;
    //mesh selected
    edk::shape::Polygon3D* selected;
};
}//end namespace shape
}//end namespace edk

#endif // MESH3D_H
