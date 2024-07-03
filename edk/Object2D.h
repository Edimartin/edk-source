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
#include "GU/GU.h"
#include "Object2DValues.h"
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

    void Constructor(bool runFather=true);

    //clean the obect
    virtual void clean();

    //get the bodyType
    virtual edk::TypeObject getType();

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
    bool calculateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat);
    bool generateBoundingBox();
    bool generateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat);
    //functions to calculate a new boundingBox
    edk::rectf32 calculateNewBoundingBox();
    edk::rectf32 calculateNewBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat);
    edk::rectf32 generateNewBoundingBox();
    edk::rectf32 generateNewBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat);

    //function to calculate boundingBox
    bool calculateBoundingBoxNoChildrem();
    bool calculateBoundingBoxNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat);
    bool generateBoundingBoxNoChildrem();
    bool generateBoundingBoxNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat);
    //functions to calculate a new boundingBox
    edk::rectf32 calculateNewBoundingBoxNoChildrem();
    edk::rectf32 calculateNewBoundingBoxNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat);
    edk::rectf32 generateNewBoundingBoxNoChildrem();
    edk::rectf32 generateNewBoundingBoxNoChildrem(edk::vector::Matrixf32<3u,3u>* transformMat);

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

    //get world polygon
    bool getWorldPolygon(edk::shape::Polygon2D* dest,edk::uint32 meshPosition,edk::uint32 polygonPosition);
    bool getWorldPolygon(edk::shape::Polygon2D* dest,edk::uint32 meshPosition,edk::uint32 polygonPosition,edk::vector::Matrixf32<3u,3u>* transformMat);

    //LIGHT
    bool setLight(edk::uint32 position,edk::light::Light light);
    bool cleanLight(edk::uint32 position);
    bool lightOn(edk::uint32 position);
    bool lightOff(edk::uint32 position);

    //HIDE
    bool hide();
    //UNHIDE
    bool unhide();

    bool isHided();
    bool areHided();

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
    virtual void drawWirePolygon(edk::uint32 meshPosition,edk::uint32 polygon);
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
    void drawPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
    static void drawPivoInPosition(edk::vec2f32 position,edk::float32 size,edk::color3f32 color);
    static void drawPivoInPosition(edk::float32 x,edk::float32 y,edk::float32 size,edk::color3f32 color);
    static void drawPivoInPosition(edk::float32 x,edk::float32 y,edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);

    //connect another object into this
    virtual bool connectObjectBack(edk::Object2D* obj);
    virtual bool updateConnectedObjectBackValues(edk::Object2D* obj);
    virtual edk::vec2f32 getConnectedObjectBackWorldPosition(edk::Object2D* obj);
    virtual bool haveConnectedObjectBack(edk::Object2D* obj);
    virtual bool disconnectObjectBack(edk::Object2D* obj);
    virtual void cleanConnectedObjectsBack();
    virtual bool connectObjectFront(edk::Object2D* obj);
    virtual bool updateConnectedObjectFrontValues(edk::Object2D* obj);
    virtual edk::vec2f32 getConnectedObjectFrontWorldPosition(edk::Object2D* obj);
    virtual bool haveConnectedObjectFront(edk::Object2D* obj);
    virtual bool disconnectObjectFront(edk::Object2D* obj);
    virtual void cleanConnectedObjectsFront();
    virtual bool updateConnectedObjectValues(edk::Object2D* obj);
    virtual edk::vec2f32 getConnectedObjectWorldPosition(edk::Object2D* obj);
    virtual bool haveConnectedObject(edk::Object2D* obj);
    virtual bool disconnectObject(edk::Object2D* obj);
    virtual void cleanConnectedObjects();

    virtual bool cloneFrom(edk::Object2D* obj);

    //PolygonList selected
    edk::shape::Mesh2D *selected;
protected:

    class MeshAlloc{
    public:
        MeshAlloc(bool myMesh,edk::shape::Mesh2D* mesh){this->classThis=NULL;this->Constructor(myMesh,mesh,false);edkEnd();}
        ~MeshAlloc(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
                if(this->myMesh){
                    delete this->mesh;edkEnd();
                }
            }
        }

        void Constructor(bool myMesh,edk::shape::Mesh2D* mesh,bool runFather=true){
            if(runFather){edkEnd();}
            if(this->classThis!=this){
                this->classThis=this;
                this->myMesh = myMesh;edkEnd();
                this->mesh=mesh;edkEnd();
            }
        }
        //get the mesh
        edk::shape::Mesh2D* getMesh(){return this->mesh;edkEnd();}
        bool waCreated(){return this->myMesh;edkEnd();}
    private:
        bool myMesh;
        edk::shape::Mesh2D* mesh;
    private:
        edk::classID classThis;
    };

    //Meshs class
    class MeshsStack: public edk::vector::Stack <edk::Object2D::MeshAlloc*>{
    public:
        MeshsStack(){
            this->classThis=NULL;edkEnd();
            this->Constructor(false);edkEnd();
        }
        ~MeshsStack(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
                this->removeAllMeshes();edkEnd();
            }
        }

        void Constructor(bool runFather=true){
            if(runFather){
                edk::vector::Stack <edk::Object2D::MeshAlloc*>::Constructor();edkEnd();
            }
            if(this->classThis!=this){
                this->classThis=this;
            }
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
        bool haveCreateMesh(edk::uint32 position){
            if(this->havePos(position)){
                edk::Object2D::MeshAlloc* temp = this->get(position);edkEnd();
                if(temp){
                    return temp->waCreated();
                }
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

    private:
        edk::classID classThis;
    }meshes;

private:
    //Tree Static Vector
    edk::light::Light lights[EDK_LIGHT_LIMIT];
    /*
    //action group
    edk::animation::ActionGroup actions;
    */
    //transform matrices
    edk::vector::Matrixf32<3u,3u> matrixPosition;
    edk::vector::Matrixf32<3u,3u> matrixPivo;
    edk::vector::Matrixf32<3u,3u> matrixAngle;
    edk::vector::Matrixf32<3u,3u> matrixSize;
    edk::vector::Matrixf32<3u,3u> matrixTransform;

    //save the position to test if are connected
    edk::vec2f32  savePosition;
    edk::float32  saveAngle;
    edk::size2f32 saveSize;
    edk::vec2f32  savePivo;
    edk::size2f32 newSize;

    //connected objects tree
    edk::vector::BinaryTree<edk::Object2D*> childremsFront;
    edk::vector::BinaryTree<edk::Object2D*> childremsBack;
    edk::Object2D* father;


    //object boundingBox
    edk::rectf32 boundingBox;

    void writeFatherBoundingBox(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat);
    bool writeBoundingBox(edk::rectf32* rect);
    bool writeBoundingBox(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat);
    bool writeChildremBoundingBox(edk::rectf32* rect);
    bool writeChildremBoundingBox(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat);

    //Function to read the actions
    static edk::Action* readXMLAction(edk::classID thisPointer,edk::uint32 actionCode);

    //draw the mesh
    void drawChildremsBackBoundingBox();
    void drawChildBackBoundingBox();
    void drawChildremsFrontBoundingBox();
    void drawChildFrontBoundingBox();
    void drawChildremsBoundingBox();
    void drawChildBoundingBox();
    void drawChildremsBack(bool haveLight);
    void drawChildBack(bool haveLight);
    void drawChildremsFront(bool haveLight);
    void drawChildFront(bool haveLight);
    void drawChildrems(bool haveLight);
    void drawChild(bool haveLight);
    void drawChildremsBackOneTexture();
    void drawChildBackOneTexture();
    void drawChildremsFrontOneTexture();
    void drawChildFrontOneTexture();
    void drawChildremsOneTexture();
    void drawChildOneTexture();
    void drawChildremsBackOneTextureWithLight(bool haveLight);
    void drawChildBackOneTextureWithLight(bool haveLight);
    void drawChildremsFrontOneTextureWithLight(bool haveLight);
    void drawChildFrontOneTextureWithLight(bool haveLight);
    void drawChildremsOneTextureWithLight(bool haveLight);
    void drawChildOneTextureWithLight(bool haveLight);
    void drawChildremsBackWithoutMaterial();
    void drawChildBackWithoutMaterial();
    void drawChildremsFrontWithoutMaterial();
    void drawChildFrontWithoutMaterial();
    void drawChildremsWithoutMaterial();
    void drawChildWithoutMaterial();
    void drawChildremsBackWithoutMaterialWithLight(bool haveLight);
    void drawChildBackWithoutMaterialWithLight(bool haveLight);
    void drawChildremsFrontWithoutMaterialWithLight(bool haveLight);
    void drawChildFrontWithoutMaterialWithLight(bool haveLight);
    void drawChildremsWithoutMaterialWithLight(bool haveLight);
    void drawChildWithoutMaterialWithLight(bool haveLight);
    void drawChildremsBackWire();
    void drawChildBackWire();
    void drawChildremsFrontWire();
    void drawChildFrontWire();
    void drawChildremsWire();
    void drawChildWire();
    //draw the pivo
    void drawChildremsBackPivo(edk::float32 size,edk::color3f32 color);
    void drawChildBackPivo(edk::float32 size,edk::color3f32 color);
    void drawChildremsFrontPivo(edk::float32 size,edk::color3f32 color);
    void drawChildFrontPivo(edk::float32 size,edk::color3f32 color);
    void drawChildremsPivo(edk::float32 size,edk::color3f32 color);
    void drawChildPivo(edk::float32 size,edk::color3f32 color);
    void drawChildremsBackPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
    void drawChildBackPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
    void drawChildremsFrontPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
    void drawChildFrontPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
    void drawChildremsPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
    void drawChildPivo(edk::float32 size,edk::float32 r,edk::float32 g,edk::float32 b);
    //update animations
    void updateChildremsAnimations();
    void updateChildremsAnimations(edk::float32 seconds);
    //update the values from father
    bool updateValuesFromFather(edk::vector::Matrixf32<3u,3u>* matrixTransform);

    //load sve identity
    inline void loadSaveIdentityValues(){
        this->savePosition=0.f;
        this->saveAngle=0.f;
        this->saveSize=0.f;
        this->savePivo=0.f;
    }
    inline void saveTransformation(){
        this->savePosition = this->position;
        this->saveSize = this->size;
        this->saveAngle = this->angle;
        this->savePivo = this->pivo;
    }
    inline void savePositionValue(){
        this->savePosition = this->position;
    }
    inline void saveSizeValue(){
        this->saveSize = this->size;
    }
    inline void saveAngleValue(){
        this->saveAngle = this->angle;
    }
    inline void savePivoValue(){
        this->savePivo = this->pivo;
    }
    inline bool haveChangeTransformation(){
        if(!edk::Math::equal(this->savePosition.x,this->position.x)
                || !edk::Math::equal(this->savePosition.y,this->position.y)
                || !edk::Math::equal(this->saveSize.width,this->size.width)
                || !edk::Math::equal(this->saveSize.height,this->size.height)
                || !edk::Math::equal(this->saveAngle,this->angle)
                || !edk::Math::equal(this->savePivo.x,this->pivo.x)
                || !edk::Math::equal(this->savePivo.y,this->pivo.y)
                ){
            return true;
        }
        return false;
    }
    inline bool haveChangePosition(){
        if(!edk::Math::equal(this->savePosition.x,this->position.x)
                || !edk::Math::equal(this->savePosition.y,this->position.y)
                ){
            return true;
        }
        return false;
    }
    inline bool haveChangeSize(){
        if(!edk::Math::equal(this->saveSize.width,this->size.width)
                || !edk::Math::equal(this->saveSize.height,this->size.height)
                ){
            return true;
        }
        return false;
    }
    inline bool haveChangeAngle(){
        if(!edk::Math::equal(this->saveAngle,this->angle)){
            return true;
        }
        return false;
    }
    inline bool haveChangePivo(){
        if(!edk::Math::equal(this->savePivo.x,this->pivo.x)
                || !edk::Math::equal(this->savePivo.y,this->pivo.y)
                ){
            return true;
        }
        return false;
    }

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
        return obj;edkEnd();
    }

    //Draw function
    //HIDE
    void drawHideBoundingBox();
    void drawHide(bool haveLight);
    void drawHideOneTexture();
    void drawHideOneTextureWithLight(bool haveLight);
    void drawHideWithoutMaterial();
    void drawHideWithoutMaterialWithLight(bool haveLight);
    void drawHideWire();
    void drawHideWirePolygon(edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawHideMesh(bool haveLight,edk::uint32 meshPosition);
    bool drawHidePolygon(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawHideMeshOneTexture(edk::uint32 meshPosition);
    bool drawHidePolygonOneTexture(edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawHideMeshOneTextureWithLight(bool haveLight,edk::uint32 meshPosition);
    bool drawHidePolygonOneTextureWithLight(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawHideMeshWithoutMaterial(edk::uint32 meshPosition);
    bool drawHidePolygonWithoutMaterial(edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawHideMeshWithoutMaterialWithLight(bool haveLight,edk::uint32 meshPosition);
    bool drawHidePolygonWithoutMaterialWithLight(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawHideMeshWire(edk::uint32 meshPosition);
    bool drawHidePolygonWire(edk::uint32 meshPosition,edk::uint32 polygon);
    //UNHIDE
    void drawUnhideBoundingBox();
    void drawUnhide(bool haveLight);
    void drawUnhideOneTexture();
    void drawUnhideOneTextureWithLight(bool haveLight);
    void drawUnhideWithoutMaterial();
    void drawUnhideWithoutMaterialWithLight(bool haveLight);
    void drawUnhideWire();
    void drawUnhideWirePolygon(edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawUnhideMesh(bool haveLight,edk::uint32 meshPosition);
    bool drawUnhidePolygon(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawUnhideMeshOneTexture(edk::uint32 meshPosition);
    bool drawUnhidePolygonOneTexture(edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawUnhideMeshOneTextureWithLight(bool haveLight,edk::uint32 meshPosition);
    bool drawUnhidePolygonOneTextureWithLight(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawUnhideMeshWithoutMaterial(edk::uint32 meshPosition);
    bool drawUnhidePolygonWithoutMaterial(edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawUnhideMeshWithoutMaterialWithLight(bool haveLight,edk::uint32 meshPosition);
    bool drawUnhidePolygonWithoutMaterialWithLight(bool haveLight,edk::uint32 meshPosition,edk::uint32 polygon);
    bool drawUnhideMeshWire(edk::uint32 meshPosition);
    bool drawUnhidePolygonWire(edk::uint32 meshPosition,edk::uint32 polygon);
    //FUNCTIONS DRAW
    void (edk::Object2D::*functionDrawBoundingBox)();
    void (edk::Object2D::*functionDraw)(bool );
    void (edk::Object2D::*functionDrawOneTexture)();
    void (edk::Object2D::*functionDrawOneTextureWithLight)(bool );
    void (edk::Object2D::*functionDrawWithoutMaterial)();
    void (edk::Object2D::*functionDrawWithoutMaterialWithLight)(bool );
    void (edk::Object2D::*functionDrawWire)();
    void (edk::Object2D::*functionDrawWirePolygon)(edk::uint32 ,edk::uint32 );
    bool (edk::Object2D::*functionDrawMesh)(bool ,edk::uint32 );
    bool (edk::Object2D::*functionDrawPolygon)(bool ,edk::uint32 ,edk::uint32 );
    bool (edk::Object2D::*functionDrawMeshOneTexture)(edk::uint32 );
    bool (edk::Object2D::*functionDrawPolygonOneTexture)(edk::uint32 ,edk::uint32 );
    bool (edk::Object2D::*functionDrawMeshOneTextureWithLight)(bool ,edk::uint32 );
    bool (edk::Object2D::*functionDrawPolygonOneTextureWithLight)(bool ,edk::uint32 ,edk::uint32 );
    bool (edk::Object2D::*functionDrawMeshWithoutMaterial)(edk::uint32 );
    bool (edk::Object2D::*functionDrawPolygonWithoutMaterial)(edk::uint32 ,edk::uint32 );
    bool (edk::Object2D::*functionDrawMeshWithoutMaterialWithLight)(bool ,edk::uint32 );
    bool (edk::Object2D::*functionDrawPolygonWithoutMaterialWithLight)(bool ,edk::uint32 ,edk::uint32 );
    bool (edk::Object2D::*functionDrawMeshWire)(edk::uint32 );
    bool (edk::Object2D::*functionDrawPolygonWire)(edk::uint32 ,edk::uint32 );

    bool hided;
private:
    edk::classID classThis;
};
}//end namespace

#endif // OBJECT2D_H
