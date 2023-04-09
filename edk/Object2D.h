#ifndef EDK_OBJECT2D_H
#define EDK_OBJECT2D_H

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
#pragma message "Inside Object2D"
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
#include "animation/Interpolation2DTracks.h"
#include "animation/ActionGroup.h"

#include "pack/FilePackage.h"

#ifdef printMessages
#pragma message "    Compiling Object2D"
#endif

namespace edk{
class Object2D: public edk::Object2DValues{
public:
    Object2D();
    virtual ~Object2D();

    //clean the obect
    virtual void clean();

    //create a new mesh and add to the meshs stack
    edk::shape::Mesh2D* newMesh(edk::uint32* position=NULL);
    //Add a list to the Object2D
    edk::uint32 addMesh(edk::shape::Mesh2D* mesh);
    //remove a polygonlist
    bool removeMesh(edk::uint32 position);
    //remove all meshes
    virtual void cleanMeshes();

    //function to calculate boundingBox
    bool calculateBoundingBox();
    bool calculateBoundingBox(edk::vector::Matrix<edk::float32,3,3>* transformMat);
    bool generateBoundingBox();
    bool generateBoundingBox(edk::vector::Matrix<edk::float32,3,3>* transformMat);
    //return a copy of the boundingBox
    edk::rectf32 getBoundingBox();

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
    void setPolygonsColorR(edk::float32 r);
    void setPolygonsColorG(edk::float32 g);
    void setPolygonsColorB(edk::float32 b);
    void setPolygonsColorA(edk::float32 a);

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
    void updateMeshAnimations(edk::float32 seconds);
    bool updateMeshAnimationsFromPosition(edk::uchar32 position);
    bool updateMeshAnimationsFromPosition(edk::uchar32 position,edk::float32 seconds);
    //update all animations
    virtual bool updateAnimations();
    virtual bool updateAnimations(edk::float32 seconds);

    //ACTIONS
    //play actions
    void playForwardActions();
    void playForwardInActions(edk::float32 second);
    //void playRewind();
    //void playRewindIn(edk::float32 second);
    void pauseActions();
    void stopActions();
    //set loop
    void setLoopActions(bool loop);
    void loopOnActions();
    void loopOffActions();

    //return if are playing
    bool isPlayingActions();
    bool isPausedActions();
    //update actions
    void updateActions();
    //remove actions
    void removeAllActions();
    void cleanAllActions();
    bool removeActionSecond(edk::float32 second);
    //Add zero action
    bool actionZero(edk::float32 second);
    //add move action
    bool actionSetPosition(edk::float32 second,edk::vec2f32 position);
    bool actionSetPosition(edk::float32 second,edk::float32 x,edk::float32 y);
    //add move action
    bool actionMove(edk::float32 second,edk::float32 duration, edk::vec2f32 position);
    bool actionMove(edk::float32 second,edk::float32 duration, edk::float32 x,edk::float32 y);
    bool actionMoveTo(edk::float32 start,edk::float32 end, edk::vec2f32 position);
    bool actionMoveTo(edk::float32 start,edk::float32 end, edk::float32 x,edk::float32 y);
    //add scale action
    bool actionSetSize(edk::float32 second,edk::size2f32 size);
    bool actionSetSize(edk::float32 second,edk::float32 width,edk::float32 height);
    bool actionSetSize(edk::float32 second,edk::float32 size);
    //add scale action
    bool actionScale(edk::float32 second,edk::float32 duration, edk::size2f32 size);
    bool actionScale(edk::float32 second,edk::float32 duration, edk::float32 width,edk::float32 height);
    bool actionScale(edk::float32 second,edk::float32 duration, edk::float32 size);
    bool actionScaleTo(edk::float32 start,edk::float32 end, edk::size2f32 size);
    bool actionScaleTo(edk::float32 start,edk::float32 end, edk::float32 width,edk::float32 height);
    bool actionScaleTo(edk::float32 start,edk::float32 end, edk::float32 size);
    //add angle action
    bool actionSetAngle(edk::float32 second,edk::float32 angle);
    //add angle action
    bool actionRotateFor(edk::float32 second,edk::float32 duration, edk::float32 angle);
    bool actionRotateTo(edk::float32 start,edk::float32 end, edk::float32 angle);
    //MESH SPRITE SHEET
    bool actionPlayName(edk::float32 second,edk::uint32 id,edk::char8* name,bool loop=false);
    bool actionPlayName(edk::float32 second,edk::uint32 id,const edk::char8* name,bool loop=false);
    bool actionPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 id,edk::char8* name);
    bool actionPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 id,const edk::char8* name);

    //DRAW
    //print the mesh
    virtual void print();
    //draw the mesh
    virtual void drawBoundingBox();
    virtual void draw();
    virtual void drawOneTexture();
    virtual void drawOneTextureWithLight();
    virtual void drawWithoutMaterial();
    virtual void drawWithoutMaterialWithLight();
    virtual void drawWire();
    virtual bool drawMesh(edk::uint32 meshPosition);
    virtual bool drawPolygon(edk::uint32 meshPosition,edk::uint32 polygon);
    virtual bool drawMeshOneTexture(edk::uint32 meshPosition);
    virtual bool drawPolygonOneTexture(edk::uint32 meshPosition,edk::uint32 polygon);
    virtual bool drawMeshOneTextureWithLight(edk::uint32 meshPosition);
    virtual bool drawPolygonOneTextureWithLight(edk::uint32 meshPosition,edk::uint32 polygon);
    virtual bool drawMeshWithoutMaterial(edk::uint32 meshPosition);
    virtual bool drawPolygonWithoutMaterial(edk::uint32 meshPosition,edk::uint32 polygon);
    virtual bool drawMeshWithoutMaterialWithLight(edk::uint32 meshPosition);
    virtual bool drawPolygonWithoutMaterialWithLight(edk::uint32 meshPosition,edk::uint32 polygon);
    virtual bool drawMeshWire(edk::uint32 meshPosition);
    virtual bool drawPolygonWire(edk::uint32 meshPosition,edk::uint32 polygon);
    //draw the pivo
    void drawPivo(edk::float32 size,edk::color3f32 color);

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);

    //cant delete
    void cantDeleteObject2D();

    virtual bool cloneFrom(edk::Object2D* obj);

    //PolygonList selected
    edk::shape::Mesh2D *selected;
protected:

    class MeshAlloc{
    public:
        MeshAlloc(bool myMesh,edk::shape::Mesh2D* mesh){this->myMesh = myMesh;edkEnd();this->mesh=mesh;edkEnd();}
        ~MeshAlloc(){
            if(this->myMesh){
                delete this->mesh;edkEnd();
            }
        }
        //get the mesh
        edk::shape::Mesh2D* getMesh(){return this->mesh;edkEnd();}
        bool waCreated(){return this->myMesh;edkEnd();}
    private:
        bool myMesh;
        edk::shape::Mesh2D* mesh;
    };

    //Meshs class
    class MeshsStack: public edk::vector::Stack <edk::Object2D::MeshAlloc*>{
    public:
        MeshsStack(){
            this->canDeleteMeshes=true;edkEnd();
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

        edk::uint32 pushBackMesh(edk::shape::Mesh2D* mesh,bool create){
            //test the mesh
            if(mesh){
                //create a new class to save the mesh
                edk::Object2D::MeshAlloc* temp = new edk::Object2D::MeshAlloc(create,mesh);edkEnd();
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
        edk::shape::Mesh2D* pushNewMesh(edk::uint32* position){
            //create a new mesh
            edk::shape::Mesh2D* mesh = new edk::shape::Mesh2D;edkEnd();
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
        edk::shape::Mesh2D* getMesh(edk::uint32 position){
            //test if have the position
            if(this->havePos(position)){
                //now he can get the mesh
                edk::Object2D::MeshAlloc* temp = this->get(position);edkEnd();
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
                edk::Object2D::MeshAlloc* temp = this->get(position);edkEnd();
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
            edk::Object2D::MeshAlloc* temp;edkEnd();
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

    private:
        bool canDeleteMeshes;
    }meshes;

    bool canDeleteObject;

private:
    //Tree Static Vector
    edk::light::Light lights[EDK_LIGHT_LIMIT];
    /*
    //action group
    edk::animation::ActionGroup actions;
    */
    //transform matrices
    edk::vector::Matrix<edk::float32,3u,3u> matrixPosition;
    edk::vector::Matrix<edk::float32,3u,3u> matrixPivo;
    edk::vector::Matrix<edk::float32,3u,3u> matrixAngle;
    edk::vector::Matrix<edk::float32,3u,3u> matrixSize;
    edk::vector::Matrix<edk::float32,3,3> matrixTransform;

    //object boundingBox
    edk::rectf32 boundingBox;

    //Function to read the actions
    static edk::Action* readXMLAction(edk::classID thisPointer,edk::uint32 actionCode);

    //ACTIONS
    class ActionPosition:public edk::ActionZero{
    public:
        ActionPosition(edk::Object2D* object, edk::vec2f32 position);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        //GET
        edk::vec2f32 getPosition();
    private:
        edk::vec2f32 position;
        edk::Object2D* object;
    };
    class ActionMove:public edk::ActionZero{
    public:
        ActionMove(edk::Object2D* object,edk::float32 duration, edk::vec2f32 position);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        //GET
        edk::vec2f32 getPosition();
        edk::float32 getDuration();
    private:
        edk::vec2f32 position;
        edk::float32 duration;
        edk::Object2D* object;
    };
    class ActionSetSize:public edk::ActionZero{
    public:
        ActionSetSize(edk::Object2D* object, edk::size2f32 scale);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        //GET
        edk::size2f32 getSize();
    private:
        edk::size2f32 size;
        edk::Object2D* object;
    };
    class ActionSize:public edk::ActionZero{
    public:
        ActionSize(edk::Object2D* object,edk::float32 duration, edk::size2f32 size);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        //GET
        edk::size2f32 getSize();
        edk::float32 getDuration();
    private:
        edk::size2f32 size;
        edk::float32 duration;
        edk::Object2D* object;
    };
    class ActionSetAngle:public edk::ActionZero{
    public:
        ActionSetAngle(edk::Object2D* object, edk::float32 angle);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        //GET
        edk::float32 getAngle();
    private:
        edk::float32 angle;
        edk::Object2D* object;
    };
    class ActionAngle:public edk::ActionZero{
    public:
        ActionAngle(edk::Object2D* object,edk::float32 duration, edk::float32 angle);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        //GET
        edk::float32 getAngle();
        edk::float32 getDuration();
    private:
        edk::float32 angle;
        edk::float32 duration;
        edk::Object2D* object;
    };
    class ActionMeshName: public edk::ActionName{
    public:
        ActionMeshName(edk::Object2D* object,edk::uint32 id, edk::char8* name,bool loop);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        //GET
        edk::uint32 getId();
        bool getLoop();
    private:
        edk::uint32 id;
        bool loop;
        edk::Object2D* object;
    };
    class ActionMeshStop: public edk::ActionZero{
    public:
        ActionMeshStop(edk::Object2D* object,edk::uint32 id);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        //GET
        edk::uint32 getId();
    private:
        edk::uint32 id;
        edk::Object2D* object;
    };

private:

    virtual edk::Object2D operator=(edk::Object2D obj){
        //copy the meshs
        edk::uint32 size = obj.meshes.size();edkEnd();
        edk::shape::Mesh2D* temp = NULL;edkEnd();
        edk::shape::Mesh2D* mesh = NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = obj.meshes.getMesh(i);edkEnd();
            if(temp){
                mesh = this->newMesh();edkEnd();
                if(mesh){
                    //*mesh = *temp;edkEnd();
                    mesh->cloneFrom(temp);edkEnd();
                }
            }
        }
        //copy pivo
        this->pivo = obj.pivo;edkEnd();
        //copy the animations
        //this->animationPosition = obj.animationPosition;edkEnd();
        this->animationPosition.cloneFrom(&obj.animationPosition);edkEnd();
        //this->animationRotation = obj.animationRotation;edkEnd();
        this->animationRotation.cloneFrom(&obj.animationRotation);edkEnd();
        //this->animationSize = obj.animationSize;edkEnd();
        this->animationSize.cloneFrom(&obj.animationSize);edkEnd();

        this->position = obj.position;edkEnd();
        this->angle = obj.angle;edkEnd();
        this->size = obj.size;edkEnd();


    //class ActionPosition 1
    //class ActionMove     2
    //class ActionSetSize  3
    //class ActionSize     4
    //class ActionSetAngle 5
    //class ActionAngle    6
    //class ActionMeshName 7
    //class ActionMeshStop 8



        /*
        //copy the actions
        this->actions.clean();edkEnd();
        size = obj.actions.getKeySize();edkEnd();
        edk::uint32 actionSize = 0u;edkEnd();
        edk::float32 second=0.f;edkEnd();
        edk::uint64 code = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //load the kay second
            second = obj.actions.getKeySecond(i);edkEnd();
            //load the size of actions inside de key
            actionSize = obj.actions.getActionsSize(i);edkEnd();
            for(edk::uint32 j=0u;j<actionSize;j++){
                //get the action code
                code = obj.actions.getActionCode(i,j);edkEnd();

                switch(code){
                case 1u:
                {
                    //ActionPosition
                    edk::Object2D::ActionPosition* temp = (edk::Object2D::ActionPosition*)obj.actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionPosition(this,temp->getPosition()));edkEnd();
                    break;
                }
                case 2u:
                {
                    //ActionMove
                    edk::Object2D::ActionMove* temp = (edk::Object2D::ActionMove*)obj.actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionMove(this,temp->getDuration(),temp->getPosition()));edkEnd();
                    break;
                }
                case 3u:
                {
                    //ActionSetSize
                    edk::Object2D::ActionSetSize* temp = (edk::Object2D::ActionSetSize*)obj.actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionSetSize(this,temp->getSize()));edkEnd();
                    break;
                }
                case 4u:
                {
                    //ActionSize
                    edk::Object2D::ActionSize* temp = (edk::Object2D::ActionSize*)obj.actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionSize(this,temp->getDuration(),temp->getSize()));edkEnd();
                    break;
                }
                case 5u:
                {
                    //ActionSetAngle
                    edk::Object2D::ActionSetAngle* temp = (edk::Object2D::ActionSetAngle*)obj.actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionSetAngle(this,temp->getAngle()));edkEnd();
                    break;
                }
                case 6u:
                {
                    //ActionAngle
                    edk::Object2D::ActionAngle* temp = (edk::Object2D::ActionAngle*)obj.actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionAngle(this,temp->getDuration(),temp->getAngle()));edkEnd();
                    break;
                }
                case 7u:
                {
                    //ActionMeshName
                    edk::Object2D::ActionMeshName* temp = (edk::Object2D::ActionMeshName*)obj.actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionMeshName(this,temp->getId(),temp->getName(),temp->getLoop()));edkEnd();
                    break;
                }
                case 8u:
                {
                    //ActionMeshStop
                    edk::Object2D::ActionMeshStop* temp = (edk::Object2D::ActionMeshStop*)obj.actions.getActionInKey(i,j);edkEnd();
                    this->actions.addAction(second,new edk::Object2D::ActionMeshStop(this,temp->getId()));edkEnd();
                    break;
                }
                default:
                {
                    //actionZero
                    this->actions.addAction(second,new edk::ActionZero());edkEnd();
                }
                }
            }
        }
        */

        obj.cantDeleteObject2D();edkEnd();
        return obj;edkEnd();
    }
};
}//end namespace

#endif // OBJECT2D_H
