#ifndef OBJECT3D_H
#define OBJECT3D_H

/*
Library Object2D - Object in the 2D world.
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
#warning "Inside Object3D"
#endif

#pragma once
#include "Object3DValues.h"
#include "GU/GU.h"
#include "vector/Stack.h"
#include "shape/Polygon3D.h"
#include "shape/Mesh3D.h"

#include "light/Light.h"
#include "light/Light3D.h"

//Animations
#include "animation/InterpolationGroup.h"
#include "animation/Interpolation1DGroup.h"
#include "animation/Interpolation2DGroup.h"
#include "animation/Interpolation3DGroup.h"
#include "animation/ActionGroup.h"

#include "pack/FilePackage.h"

#ifdef printMessages
#warning "    Compiling Object3D"
#endif

namespace edk{
class Object3D: public edk::Object3DValues{
public:
    Object3D();
    ~Object3D();

    //create a new mesh and add to the meshs stack
    edk::shape::Mesh3D* newMesh(edk::uint32* position=NULL);
    //Add a list to the Object2D
    edk::uint32 addMesh(edk::shape::Mesh3D* mesh);
    //remove a polygonlist
    bool removeMesh(edk::uint32 position);
    //remove all meshes
    virtual void cleanMeshes();

    //Select the polygonList
    bool selectMesh(edk::uint32 position);
    //return the selected textureID
    edk::uint32 selectedGetTextureID(edk::uint8 number);
    //free the selected
    void cleanSelected();
    //return the number of meshs
    edk::uint32 getMeshSize();
    //return the mesh pointer
    edk::shape::Mesh3D* getMesh(edk::uint32 position);
    //remove all meshes
    virtual void removeAllMesh();

    //set the polygonsColor
    bool setPolygonColor(edk::uint32 position,edk::color4f32 color);
    bool setPolygonColor(edk::uint32 position,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    bool setPolygonsColor(edk::color4f32 color);
    bool setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    //Set the polygons smooth
    bool setPolygonsSmooth(bool smooth);
    bool setPolygonsSmoothOn();
    bool setPolygonsSmoothOff();
    //update the polygons normals
    bool updatePolygonsNormals();

    //LIGHT
    bool setLight(edk::uint32 position,edk::light::Light light);
    bool cleanLight(edk::uint32 position);
    bool lightOn(edk::uint32 position);
    bool lightOff(edk::uint32 position);

    //OBJ
    bool addObj(const edk::char8* fileName);
    bool addObj(edk::char8* fileName);
    bool loadOBJ(const edk::char8* fileName);
    bool loadOBJ(edk::char8* fileName);

    //DRAW
    //print the mesh
    virtual void print();
    //draw the mesh
    virtual void draw();
    virtual void drawWithoutMaterial();
    virtual void drawWithoutMaterialWithLight();
    virtual void drawWire();
    virtual void drawNormals();
    virtual void drawNormalsWithColor(edk::color3f32 color = edk::color3f32(1,1,1));
    //draw the pivo
    void drawPivo(edk::float32 size,edk::color3f32 color);

    //PolygonList selected
    edk::shape::Mesh3D *selected;
    //animarion position
    edk::animation::Interpolation3DGroup animationPosition;
    //Animation rotation
    edk::animation::Interpolation3DGroup animationRotation;
    //animationSize
    edk::animation::Interpolation3DGroup animationSize;
    //pivo point
    edk::vec3f32 pivo;

protected:

    class MeshAlloc{
    public:
        MeshAlloc(bool myMesh,edk::shape::Mesh3D* mesh){this->myMesh = myMesh;this->mesh=mesh;}
        ~MeshAlloc(){
            if(this->myMesh){
                delete this->mesh;
            }
        }
        //get the mesh
        edk::shape::Mesh3D* getMesh(){return this->mesh;}
        bool waCreated(){return this->myMesh;}
    private:
        bool myMesh;
        edk::shape::Mesh3D* mesh;
    };

    //Meshs class
    class MeshsStack: public edk::vector::Stack <edk::Object3D::MeshAlloc*>{
    public:
        MeshsStack(){
            this->canDeleteMeshes=true;
            this->func = edk::Object3D::MeshsStack::runDrawWire;
        }
        ~MeshsStack(){
            if(this->canDeleteMeshes)
            this->removeAllMeshes();
            else{
                //
            }
            this->canDeleteMeshes=true;
        }

        void updateElement(edk::Object3D::MeshAlloc* value){
            this->func(this,value);
        }
        void printElement(edk::Object3D::MeshAlloc* value){
            value->getMesh()->printPolygons();
        }
        void renderElement(edk::Object3D::MeshAlloc* value){
            if(value->getMesh()->material.haveOneTexture()){
                value->getMesh()->drawOneTexture();
            }
            else{
                //
                value->getMesh()->drawMultiTexture();
            }
        }

        edk::uint32 pushBackMesh(edk::shape::Mesh3D* mesh,bool create){
            //test the mesh
            if(mesh){
                //create a new class to save the mesh
                edk::Object3D::MeshAlloc* temp = new edk::Object3D::MeshAlloc(create,mesh);
                if(temp){
                    //push back
                    edk::uint32 size = this->size();
                    edk::uint32 ret = this->pushBack(temp);
                    if(size<this->size()){
                        return ret;
                    }
                }
                //else delete temp
                delete temp;
            }
            return 0u;
        }
        //create a new mesh
        edk::shape::Mesh3D* pushNewMesh(edk::uint32* position){
            //create a new mesh
            edk::shape::Mesh3D* mesh = new edk::shape::Mesh3D;
            if(mesh){
                //push back this mesh
                edk::uint32 size = this->size();
                edk::uint32 pos = this->pushBackMesh(mesh,true);
                if(size<this->size()){
                    if(position)*position=pos;
                    return mesh;
                }
                if(position)*position=0u;
                delete mesh;
            }
            return NULL;
        }
        //get the mesh
        edk::shape::Mesh3D* getMesh(edk::uint32 position){
            //test if have the position
            if(this->havePos(position)){
                //now he can get the mesh
                edk::Object3D::MeshAlloc* temp = this->get(position);
                if(temp){
                    //return the mesh
                    return temp->getMesh();
                }
            }
            return NULL;
        }
        //return if have mesh
        bool haveMesh(edk::uint32 position){
            if(this->getMesh(position)) return true;
            return false;
        }
        //remove a mesh
        bool removeMesh(edk::uint32 position){
            //test if have the position
            if(this->havePos(position)){
                //now he can get the mesh
                edk::Object3D::MeshAlloc* temp = this->get(position);
                if(temp){
                    //remove the position
                    this->remove(position);
                    //delete temp
                    delete temp;
                    return true;
                }
            }
            return false;
        }
        //remove all meshes
        void removeAllMeshes(){
            edk::uint32 size = this->size();
            edk::Object3D::MeshAlloc* temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->get(i);
                if(temp){
                    //delete
                    delete temp;
                }
            }
            this->clean();
        }
        void cantDeleteMeshes(){
            this->canDeleteMeshes = false;
        }


        //Draw the polygon normals
        void drawWire(){
            this->func = edk::Object3D::MeshsStack::runDrawWire;
            this->update();
        }
        static void runDrawWire(edk::Object3D::MeshsStack*,edk::Object3D::MeshAlloc* value){
            value->getMesh()->drawWire();
        }

        //Draw the polygon normals
        void drawNormals(){
            this->func = edk::Object3D::MeshsStack::runDrawNormals;
            this->update();
        }
        static void runDrawNormals(edk::Object3D::MeshsStack*,edk::Object3D::MeshAlloc* value){
            value->getMesh()->drawPolygonsNormals();
        }

        //Draw the polygon normals
        void drawNormalsWithColor(edk::color3f32 color){
            this->func = edk::Object3D::MeshsStack::runDrawNormalsWithColor;
            this->color = color;
            this->update();
        }
        static void runDrawNormalsWithColor(edk::Object3D::MeshsStack* list,edk::Object3D::MeshAlloc* value){
            value->getMesh()->drawPolygonsNormalsWithColor(list->color);
        }

        void drawWithoutMaterial(){
            this->func = edk::Object3D::MeshsStack::runDrawWithoutMaterial;
            this->update();
        }
        static void runDrawWithoutMaterial(edk::Object3D::MeshsStack*,edk::Object3D::MeshAlloc* value){
            value->getMesh()->drawPolygons();
        }
        void drawWithoutMaterialWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
        edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
        bool lightIsOn[][EDK_LIGHT_LIMIT]
        ){
            this->func = edk::Object3D::MeshsStack::runDrawWithoutMaterialWithLight;
            for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
                this->lightIsOn[i] = *lightIsOn[i];
                if(this->lightIsOn[i]){
                    this->lightPositions[i][0u] = *lightPositions[i][0u];
                    this->lightPositions[i][1u] = *lightPositions[i][1u];
                    this->lightPositions[i][2u] = *lightPositions[i][2u];
                    this->lightPositions[i][3u] = *lightPositions[i][3u];

                    this->lightDirections[i][0u] = *lightDirections[i][0u];
                    this->lightDirections[i][1u] = *lightDirections[i][1u];
                    this->lightDirections[i][2u] = *lightDirections[i][2u];
                    this->lightDirections[i][3u] = *lightDirections[i][3u];
                }
            }
            this->update();
        }
        static void runDrawWithoutMaterialWithLight(edk::Object3D::MeshsStack* list,edk::Object3D::MeshAlloc* value){
            value->getMesh()->drawPolygonsWithLight(&list->lightPositions,&list->lightDirections,&list->lightIsOn);
        }

        void drawWithLight(edk::float32 lightPositions[][EDK_LIGHT_LIMIT][4u],
        edk::float32 lightDirections[][EDK_LIGHT_LIMIT][4u],
        bool lightIsOn[][EDK_LIGHT_LIMIT]
        ){
            this->func = edk::Object3D::MeshsStack::runDrawWithLight;
            for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
                this->lightIsOn[i] = *lightIsOn[i];
                if(this->lightIsOn[i]){
                    this->lightPositions[i][0u] = *lightPositions[i][0u];
                    this->lightPositions[i][1u] = *lightPositions[i][1u];
                    this->lightPositions[i][2u] = *lightPositions[i][2u];
                    this->lightPositions[i][3u] = *lightPositions[i][3u];

                    this->lightDirections[i][0u] = *lightDirections[i][0u];
                    this->lightDirections[i][1u] = *lightDirections[i][1u];
                    this->lightDirections[i][2u] = *lightDirections[i][2u];
                    this->lightDirections[i][3u] = *lightDirections[i][3u];
                }
            }
            this->update();
        }
        static void runDrawWithLight(edk::Object3D::MeshsStack* list,edk::Object3D::MeshAlloc* value){
            if(value->getMesh()->material.haveOneTexture()){
                value->getMesh()->drawOneTextureWithLight(&list->lightPositions,&list->lightDirections,&list->lightIsOn);
            }
            else{
                //
                value->getMesh()->drawMultiTextureWithLight(&list->lightPositions,&list->lightDirections,&list->lightIsOn);
            }
        }



    private:
        bool canDeleteMeshes;

        void (*func)(edk::Object3D::MeshsStack* list,edk::Object3D::MeshAlloc* value);
        edk::float32 lightPositions[EDK_LIGHT_LIMIT][4u];
        edk::float32 lightDirections[EDK_LIGHT_LIMIT][4u];
        bool lightIsOn[EDK_LIGHT_LIMIT];
        edk::color3f32 color;
    }meshes;

private:
    //Tree Static Vector
    edk::light::Light lights[EDK_LIGHT_LIMIT];
    edk::float32 lightPositions[EDK_LIGHT_LIMIT][4u];
    edk::float32 lightDirections[EDK_LIGHT_LIMIT][4u];
    bool lightIsOn[EDK_LIGHT_LIMIT];
};
}//end namespace edk

#endif // OBJECT3D_H
