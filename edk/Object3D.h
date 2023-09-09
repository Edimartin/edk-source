#ifndef OBJECT3D_H
#define OBJECT3D_H

/*
Library Object2D - Object in the 2D world.
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
#pragma message "Inside Object3D"
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
#pragma message "    Compiling Object3D"
#endif

namespace edk{
class Object3D: public edk::Object3DValues{
public:
    Object3D();
    ~Object3D();

    void clean();

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

    //rotate the object to look at the camera
    void lookAtPoint(edk::float32 x,edk::float32 y,edk::float32 z);
    void lookAtPoint(edk::vec3f32 point);

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
    virtual void drawNormalsWithColor(edk::float32 r,edk::float32 g,edk::float32 b);
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
        MeshAlloc(bool myMesh,edk::shape::Mesh3D* mesh){this->myMesh = myMesh;edkEnd();this->mesh=mesh;edkEnd();}
        ~MeshAlloc(){
            if(this->myMesh){
                delete this->mesh;edkEnd();
            }
        }
        //get the mesh
        edk::shape::Mesh3D* getMesh(){return this->mesh;edkEnd();}
        bool waCreated(){return this->myMesh;edkEnd();}
    private:
        bool myMesh;
        edk::shape::Mesh3D* mesh;
    };

    //Meshs class
    class MeshsStack: public edk::vector::Stack <edk::Object3D::MeshAlloc*>{
    public:
        MeshsStack(){
            this->canDeleteMeshes=true;edkEnd();
            this->func = edk::Object3D::MeshsStack::runDrawWire;edkEnd();
        }
        ~MeshsStack(){
            if(this->canDeleteMeshes){
            this->removeAllMeshes();edkEnd();
            }
            else{
                //
            }
            this->canDeleteMeshes=true;edkEnd();
        }

        void updateElement(edk::Object3D::MeshAlloc* value){
            this->func(this,value);edkEnd();
        }
        void printElement(edk::Object3D::MeshAlloc* value){
            printf("\nMESH");
            value->getMesh()->printPolygons();edkEnd();
        }
        void renderElement(edk::Object3D::MeshAlloc* value){
            if(value->getMesh()->material.haveOneTexture()){
                value->getMesh()->drawOneTexture();edkEnd();
            }
            else{
                //
                value->getMesh()->drawMultiTexture();edkEnd();
            }
        }

        edk::uint32 pushBackMesh(edk::shape::Mesh3D* mesh,bool create){
            //test the mesh
            if(mesh){
                //create a new class to save the mesh
                edk::Object3D::MeshAlloc* temp = new edk::Object3D::MeshAlloc(create,mesh);edkEnd();
                if(temp){
                    //push back
                    edk::uint32 size = this->size();edkEnd();
                    edk::uint32 ret = this->pushBack(temp);edkEnd();
                    if(size<this->size()){
                        return ret;
                    }
                }
                //else delete temp
                delete temp;edkEnd();
            }
            return 0u;edkEnd();
        }
        //create a new mesh
        edk::shape::Mesh3D* pushNewMesh(edk::uint32* position){
            //create a new mesh
            edk::shape::Mesh3D* mesh = new edk::shape::Mesh3D;edkEnd();
            if(mesh){
                //push back this mesh
                edk::uint32 size = this->size();edkEnd();
                edk::uint32 pos = this->pushBackMesh(mesh,true);edkEnd();
                if(size<this->size()){
                    if(position){
                        *position=pos;edkEnd();
                    }
                    return mesh;edkEnd();
                }
                if(position){
                    *position=0u;edkEnd();
                }
                delete mesh;edkEnd();
            }
            return NULL;
        }
        //get the mesh
        edk::shape::Mesh3D* getMesh(edk::uint32 position){
            //test if have the position
            if(this->havePos(position)){
                //now he can get the mesh
                edk::Object3D::MeshAlloc* temp = this->get(position);edkEnd();
                if(temp){
                    //return the mesh
                    return temp->getMesh();edkEnd();
                }
            }
            return NULL;
        }
        //return if have mesh
        bool haveMesh(edk::uint32 position){
            if(this->getMesh(position)){
                return true;
            }
            return false;
        }
        //remove a mesh
        bool removeMesh(edk::uint32 position){
            //test if have the position
            if(this->havePos(position)){
                //now he can get the mesh
                edk::Object3D::MeshAlloc* temp = this->get(position);edkEnd();
                if(temp){
                    //remove the position
                    this->remove(position);edkEnd();
                    //delete temp
                    delete temp;edkEnd();
                    return true;
                }
            }
            return false;
        }
        //remove all meshes
        void removeAllMeshes(){
            edk::uint32 size = this->size();edkEnd();
            edk::Object3D::MeshAlloc* temp;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->get(i);edkEnd();
                if(temp){
                    //delete
                    delete temp;edkEnd();
                }
            }
            this->clean();edkEnd();
        }
        void cantDeleteMeshes(){
            this->canDeleteMeshes = false;edkEnd();
        }


        //Draw the polygon normals
        void drawWire(){
            this->func = edk::Object3D::MeshsStack::runDrawWire;edkEnd();
            this->update();edkEnd();
        }
        static void runDrawWire(edk::Object3D::MeshsStack*,edk::Object3D::MeshAlloc* value){
            value->getMesh()->drawWire();edkEnd();
        }

        //Draw the polygon normals
        void drawNormals(){
            this->func = edk::Object3D::MeshsStack::runDrawNormals;edkEnd();
            this->update();edkEnd();
        }
        static void runDrawNormals(edk::Object3D::MeshsStack*,edk::Object3D::MeshAlloc* value){
            value->getMesh()->drawPolygonsNormals();edkEnd();
        }

        //Draw the polygon normals
        void drawNormalsWithColor(edk::color3f32 color){
            this->func = edk::Object3D::MeshsStack::runDrawNormalsWithColor;edkEnd();
            this->color = color;edkEnd();
            this->update();edkEnd();
        }
        static void runDrawNormalsWithColor(edk::Object3D::MeshsStack* list,edk::Object3D::MeshAlloc* value){
            value->getMesh()->drawPolygonsNormalsWithColor(list->color);edkEnd();
        }

        void drawWithoutMaterial(){
            this->func = edk::Object3D::MeshsStack::runDrawWithoutMaterial;edkEnd();
            this->update();edkEnd();
        }
        static void runDrawWithoutMaterial(edk::Object3D::MeshsStack*,edk::Object3D::MeshAlloc* value){
            value->getMesh()->drawPolygons();edkEnd();
        }



    private:
        bool canDeleteMeshes;

        void (*func)(edk::Object3D::MeshsStack* list,edk::Object3D::MeshAlloc* value);
        edk::color3f32 color;
    }meshes;

private:
    //Tree Static Vector
    edk::light::Light lights[EDK_LIGHT_LIMIT];
};
}//end namespace edk

#endif // OBJECT3D_H
