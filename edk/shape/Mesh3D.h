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
    bool selectedPolygonSetSmooth(bool smooth);
    bool selectedPolygonSmoothOn();
    bool selectedPolygonSmoothOff();
    bool selectedPolygonUpdateNormal();

    //DRAW
    //print the mesh
    virtual void printPolygons();
    //draw the mesh
    virtual void drawPolygons();
    //draw the mesh with lights
    virtual void drawPolygonsWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
    edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
    bool lightIsOn[][EDK_LIGHT_LIMIT]
    );
    //draw the polygons in wireframe
    virtual void drawWirePolygons();
    virtual void drawWirePolygonsWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));
    virtual void drawVertexs(edk::color3f32 color = edk::color3f32(1,1,1));
    virtual void drawPolygonsNormals();
    virtual void drawPolygonsNormalsWithColor(edk::color3f32 color = edk::color3f32(1,1,1));


    //draw the mesh
    virtual void drawOneTexture();
    virtual void drawOneTexture(edk::uint32 position);
    virtual bool selectedDrawOneTexture();
    virtual bool selectedDrawOneTexture(edk::uint32 position);
    virtual void drawOneTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
    edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
    bool lightIsOn[][EDK_LIGHT_LIMIT]);
    virtual void drawOneTextureWithLight(edk::uint32 position,edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
    edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
    bool lightIsOn[][EDK_LIGHT_LIMIT]);
    virtual bool selectedDrawOneTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
    edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
    bool lightIsOn[][EDK_LIGHT_LIMIT]);
    virtual bool selectedDrawOneTextureWithLight(edk::uint32 position,edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
    edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
    bool lightIsOn[][EDK_LIGHT_LIMIT]);
    virtual void drawMultiTexture();
    virtual bool selectedDrawMultiTexture();
    virtual void drawMultiTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
    edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
    bool lightIsOn[][EDK_LIGHT_LIMIT]);
    virtual bool selectedDrawMultiTextureWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
    edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
    bool lightIsOn[][EDK_LIGHT_LIMIT]);
    virtual void drawWire();

    //Material used for the mesh
    edk::material::Material material;
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


protected:
    class PolygonList: public edk::vector::Stack<edk::shape::Polygon3D*>{
    public:
        PolygonList(){}
        ~PolygonList(){}
        void updateElement(edk::shape::Polygon3D* value){
            this->func(this,value);
        }
        void printElement(edk::shape::Polygon3D* value){
            value->print();
        }
        void renderElement(edk::shape::Polygon3D* value){
            value->draw();
        }
        void drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
        edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
        bool lightIsOn[][EDK_LIGHT_LIMIT]
        ){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawWithLight;
            for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
                this->lightPositions[i][0u] = *lightPositions[i][0u];
                this->lightPositions[i][1u] = *lightPositions[i][1u];
                this->lightPositions[i][2u] = *lightPositions[i][2u];
                this->lightPositions[i][3u] = *lightPositions[i][3u];

                this->lightDirections[i][0u] = *lightDirections[i][0u];
                this->lightDirections[i][1u] = *lightDirections[i][1u];
                this->lightDirections[i][2u] = *lightDirections[i][2u];
                this->lightDirections[i][3u] = *lightDirections[i][3u];

                this->lightIsOn[i] = *lightIsOn[i];
            }

            this->update();
        }
        static void runDrawWithLight(edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value){
            value->drawWithLight(&list->lightPositions,&list->lightDirections,&list->lightIsOn);
        }
        //Draw the polygon with lines
        void drawWire(){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawWire;
            this->update();
        }
        static void runDrawWire(edk::shape::Mesh3D::PolygonList*,edk::shape::Polygon3D* value){
            value->drawWire();
        }
        /*
        void drawWireWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));
        */
        //Draw the polygon with lines
        void drawWireWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1)){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawWireWithColor;
            this->color = color;
            this->update();
        }
        static void runDrawWireWithColor(edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value){
            value->drawWireWithColor(list->color);
        }
        //Draw the polygon with lines
        void drawPolygonVertexs(edk::color4f32 color=edk::color4f32(1,1,1,1)){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawPolygonVertexs;
            this->color = color;
            this->update();
        }
        static void runDrawPolygonVertexs(edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value){
            value->drawPolygonVertexs(list->color);
        }

        //Draw the polygon normals
        void drawPolygonNormals(){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawPolygonNormals;
            this->update();
        }
        static void runDrawPolygonNormals(edk::shape::Mesh3D::PolygonList*,edk::shape::Polygon3D* value){
            value->drawPolygonNormals();
        }
        //Draw the polygon with lines
        void drawPolygonNormalsWithColor(edk::color3f32 color=edk::color3f32(1,1,1)){
            this->func = edk::shape::Mesh3D::PolygonList::runDrawPolygonNormalsWithColor;
            this->color = color;
            this->update();
        }
        static void runDrawPolygonNormalsWithColor(edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value){
            value->drawPolygonNormalsWithColor(list->color);
        }

        void (*func)(edk::shape::Mesh3D::PolygonList* list,edk::shape::Polygon3D* value);
        edk::color4f32 color;
        edk::float32 lightPositions[EDK_LIGHT_LIMIT][4u];
        edk::float32 lightDirections[EDK_LIGHT_LIMIT][4u];
        bool lightIsOn[EDK_LIGHT_LIMIT];
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
        void drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
        edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
        bool lightIsOn[][EDK_LIGHT_LIMIT]
        );
        //Draw the polygon with lines
        void drawWire();
        //Draw the polygon with lines
        void drawWireWithColor(edk::color4f32 color=edk::color4f32(1,1,1,1));
        //Draw the polygon with lines
        void drawPolygonVertexs(edk::color4f32 color=edk::color4f32(1,1,1,1));
        //Draw the polygon normals lines
        void drawPolygonNormals();
        //Draw the polygon normals lines
        void drawPolygonNormalsWithColor(edk::color3f32 color=edk::color3f32(1,1,1));
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
