#ifndef EDK_OBJECT2D_H
#define EDK_OBJECT2D_H

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
#warning "Inside Object2D"
#endif

#pragma once
#include "Object2DValues.h"
#include "GU/GU.h"
#include "vector/Stack.h"
#include "shape/Polygon2D.h"
#include "shape/Polygon2DList.h"
#include "shape/Mesh2D.h"

#include "light/Light.h"
#include "light/Light2D.h"

//Animations
#include "animation/InterpolationGroup.h"
#include "animation/Interpolation1DGroup.h"
#include "animation/Interpolation2DGroup.h"
#include "animation/Interpolation3DGroup.h"

#ifdef printMessages
#warning "    Compiling Object2D"
#endif

namespace edk{
class Object2D: public edk::Object2DValues{
public:
    Object2D();
    virtual ~Object2D();

    //create a new mesh and add to the meshs stack
    edk::shape::Mesh2D* newMesh(edk::uint32* position=NULL);
    //Add a list to the Object2D
    edk::uint32 addMesh(edk::shape::Mesh2D* mesh);
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
    edk::shape::Mesh2D* getMesh(edk::uint32 position);
    //remove all meshes
    virtual void removeAllMesh();
    //set the polygonsColor
    bool setPolygonColor(edk::uint32 position,edk::color4f32 color);
    bool setPolygonColor(edk::uint32 position,edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setPolygonsColor(edk::color4f32 color);
    void setPolygonsColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);

    //LIGHT
    bool setLight(edk::uint32 position,edk::light::Light light);
    bool cleanLight(edk::uint32 position);
    bool lightOn(edk::uint32 position);
    bool lightOff(edk::uint32 position);

    //play all mesh animations
    void playMeshAnimations();
    bool playMeshAnimations(edk::uchar32 position);
    //pause polygons animations
    void pauseMeshAnimations();
    bool pauseMeshAnimations(edk::uchar32 position);
    //update mesh animations
    void updateMeshAnimations();
    bool updateMeshAnimations(edk::uchar32 position);
    //update all animations
    virtual bool updateAnimations();

    //DRAW
    //print the mesh
    virtual void print();
    //draw the mesh
    virtual void draw();
    virtual void drawWithoutMaterial();
    virtual void drawWithoutMaterialWithLight();
    virtual void drawWire();
    //draw the pivo
    void drawPivo(edk::float32 size,edk::color3f32 color);

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    //cant delete
    void cantDeleteObject2D();

    //PolygonList selected
    edk::shape::Mesh2D *selected;
    //animarion position
    edk::animation::Interpolation2DGroup animationPosition;
    //Animation rotation
    edk::animation::Interpolation1DGroup animationRotation;
    //animationSize
    edk::animation::Interpolation2DGroup animationSize;
    //pivo point
    edk::vec2f32 pivo;
protected:

    class MeshAlloc{
    public:
        MeshAlloc(bool myMesh,edk::shape::Mesh2D* mesh){this->myMesh = myMesh;this->mesh=mesh;}
        ~MeshAlloc(){
            if(this->myMesh){
                delete this->mesh;
            }
        }
        //get the mesh
        edk::shape::Mesh2D* getMesh(){return this->mesh;}
        bool waCreated(){return this->myMesh;}
    private:
        bool myMesh;
        edk::shape::Mesh2D* mesh;
    };

    //Meshs class
    class MeshsStack: public edk::vector::Stack <edk::Object2D::MeshAlloc*>{
    public:
        MeshsStack(){}
        ~MeshsStack(){
            this->removeAllMeshes();
        }

        edk::uint32 pushBackMesh(edk::shape::Mesh2D* mesh,bool create){
            //test the mesh
            if(mesh){
                //create a new class to save the mesh
                edk::Object2D::MeshAlloc* temp = new edk::Object2D::MeshAlloc(create,mesh);
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
        edk::shape::Mesh2D* pushNewMesh(edk::uint32* position){
            //create a new mesh
            edk::shape::Mesh2D* mesh = new edk::shape::Mesh2D;
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
        edk::shape::Mesh2D* getMesh(edk::uint32 position){
            //test if have the position
            if(this->havePos(position)){
                //now he can get the mesh
                edk::Object2D::MeshAlloc* temp = this->get(position);
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
                edk::Object2D::MeshAlloc* temp = this->get(position);
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
            edk::Object2D::MeshAlloc* temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->get(i);
                if(temp){
                    //delete
                    delete temp;
                }
            }
            this->clean();
        }
    }meshes;

    bool canDeleteObject;

private:
    //Tree Static Vector
    edk::light::Light lights[EDK_LIGHT_LIMIT];
    edk::float32 lightPositions[EDK_LIGHT_LIMIT][4u];
    edk::float32 lightDirections[EDK_LIGHT_LIMIT][4u];
    bool lightIsOn[EDK_LIGHT_LIMIT];

public:

    edk::Object2D operator=(edk::Object2D obj){
        //copy the meshs
        edk::uint32 size = obj.meshes.size();
        edk::shape::Mesh2D* temp = NULL;
        edk::shape::Mesh2D* mesh = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp = obj.meshes.getMesh(i);
            if(temp){
                mesh = this->newMesh();
                if(mesh){
                    *mesh = *temp;
                }
            }
        }
        //copy pivo
        this->pivo = obj.pivo;
        //copy the animations
        this->animationPosition = obj.animationPosition;
        this->animationRotation = obj.animationRotation;
        this->animationSize = obj.animationSize;

        this->position=obj.position;
        this->angle=obj.angle;
        this->size=obj.size;

        obj.cantDeleteObject2D();
        return obj;
    }
};
}//end namespace

#endif // OBJECT2D_H