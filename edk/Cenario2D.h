#ifndef EDK_CENARIO2D_H
#define EDK_CENARIO2D_H

#pragma once
#include "TypeDefines.h"
#include "physics2D/World2D.h"
#include "tiles/TileMap2D.h"
#include "vector/BinaryTree.h"
#include "animation/ActionGroup.h"

namespace edk{
class Cenario2D : public edk::physics2D::ContactCallback2D , public edk::tiles::tileCallback{
public:
    Cenario2D();
    virtual ~Cenario2D();
    //CALLBACKS
    virtual void contact2DBegin(edk::physics2D::Contact2D* contact);
    virtual void contact2DEnd(edk::physics2D::Contact2D* contact);
    virtual void contact2DKeepBegin(edk::physics2D::Contact2D* contact);
    virtual void contact2DKeepEnd(edk::physics2D::Contact2D* contact);
    //contact sensors
    virtual void sensor2DBegin(edk::physics2D::Contact2D* contact);
    virtual void sensor2DEnd(edk::physics2D::Contact2D* contact);
    virtual void sensor2DKeeping(edk::physics2D::Contact2D* contact);
    //CALLBACKS TILE
    virtual void contact2DTileBegin(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact);
    virtual void contact2DTileEnd(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact);
    virtual void contact2DTileKeepBegin(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact);
    virtual void contact2DTileKeepEnd(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact);
    //contact sensors
    virtual void sensor2DTileBegin(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact);
    virtual void sensor2DTileEnd(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact);
    virtual void sensor2DTileKeeping(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact);

    //TILEMAP
    edk::tiles::TileMap2D* newTileMapInPosition(edk::uint32 position,edk::size2ui32 size);
    edk::tiles::TileMap2D* newTileMapInPosition(edk::uint32 position,edk::uint32 width,edk::uint32 height);
    edk::uint32 newTileMap(edk::size2ui32 size);
    edk::uint32 newTileMap(edk::uint32 width,edk::uint32 height);
    edk::uint32 getTileMapID(edk::tiles::TileMap2D* tileMap);
    edk::tiles::TileMap2D* getTileMap(edk::uint32 position);
    bool deleteTileMap(edk::tiles::TileMap2D* tileMap);
    bool deleteTileMap(edk::uint32 position);
    void deleteAllTileMaps();

    //tileMapFunctions
    void cleanSelectedTileMap();
    //select the map
    bool selectTileMap(edk::uint32 position);
    //set a tile in the tileMap
    bool selectedTileMapSetTile(edk::uint32 tileID,edk::vec2ui32 position);
    bool selectedTileMapSetTile(edk::uint32 tileID,edk::uint32 positionX,edk::uint32 positionY);
    //set the tileMap position
    bool  selectedTileMapSetPosition(edk::vec2f32 position);
    bool  selectedTileMapSetPosition(edk::float32 positionX,edk::float32 positionY);
    edk::vec2f32 selectedTileMapGetTileWorldPosition(edk::vec2ui32 position);
    edk::vec2f32 selectedTileMapGetTileWorldPosition(edk::uint32 positionX,edk::uint32 positionY);
    //Set scale the map
    bool selectedTileMapSetScaleMap(edk::size2f32 scale);
    bool selectedTileMapSetScaleMap(edk::float32 width,edk::float32 height );
    //delete physicObjects
    bool selectedTileDeletePhysicsTiles();
    bool selectedTileDeletePhysicTile(edk::vec2ui32 position);
    bool selectedTileDeletePhysicTile(edk::uint32 positionX,edk::uint32 positionY);
    //add physics tiles
    bool selectedTileLoadPhysicsTiles();
    bool selectedTileLoadPhysicTile(edk::vec2ui32 position);
    bool selectedTileLoadPhysicTile(edk::uint32 positionX,edk::uint32 positionY);

    //OBJECTS
    //add a object to the tree
    edk::Object2D* newObject(edk::uint32 levelPosition);
    edk::Object2D* newObject(edk::uint32 levelPosition,edk::float32 depth);
    bool addObject(edk::uint32 levelPosition,edk::Object2D* obj);
    bool addObject(edk::uint32 levelPosition,edk::Object2D* obj,edk::float32 depth);
    bool addObjectCreated(edk::uint32 levelPosition,edk::Object2D* obj);
    bool addObjectCreated(edk::uint32 levelPosition,edk::Object2D* obj,edk::float32 depth);
    //get the object
    edk::Object2D* getObject(edk::uint32 levelPosition,edk::float32 depth);
    edk::Object2D* getObject(edk::uint32 levelPosition,edk::uint32 position);
    //get the objectDepth
    edk::float32 getObjectDepth(edk::uint32 levelPosition,edk::uint32 position);
    edk::float32 getObjectDepth(edk::uint32 levelPosition,edk::Object2D* obj);
    //delete the object
    bool deleteObject(edk::uint32 levelPosition,edk::Object2D* obj);
    void deleteAllObjects(edk::uint32 levelPosition);
    void deleteAllObjects();
    //dont delete the object
    bool removeObject(edk::uint32 levelPosition,edk::Object2D* obj);
    //set object to be animated
    bool setObjectAnimated(edk::uint32 levelPosition,edk::Object2D* obj);
    bool setObjectAnimated(edk::uint32 levelPosition,edk::uint32 position);
    bool setObjectAnimated(edk::uint32 levelPosition,edk::float32 depth);

    //OBJECTS_PHYSICS
    //add a object to the tree
    edk::physics2D::PhysicObject2D* newPhysicObject(edk::uint32 levelPosition,edk::physics::bodyType physicType);
    edk::physics2D::PhysicObject2D* newPhysicObject(edk::uint32 levelPosition,edk::physics::bodyType physicType,edk::float32 depth);
    edk::physics2D::PhysicObject2D* newPhysicSensor(edk::uint32 levelPosition,edk::physics::bodyType physicType);
    edk::physics2D::PhysicObject2D* newPhysicSensor(edk::uint32 levelPosition,edk::physics::bodyType physicType,edk::float32 depth);
    bool addPhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool addPhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj,edk::float32 depth);
    bool addPhysicObjectCreated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool addPhysicObjectCreated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj,edk::float32 depth);
    bool addPhysicSensor(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor);
    bool addPhysicSensor(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor,edk::float32 depth);
    bool addPhysicSensorCreated(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor);
    bool addPhysicSensorCreated(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor,edk::float32 depth);
    //get the object
    edk::physics2D::PhysicObject2D* getPhysicObject(edk::uint32 levelPosition,edk::float32 depth);
    edk::physics2D::PhysicObject2D* getPhysicObject(edk::uint32 levelPosition,edk::uint32 position);
    //return the depth of the physic object
    edk::float32 getPhysicObjectDepth(edk::uint32 levelPosition,edk::uint32 position);
    edk::float32 getPhysicObjectDepth(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    //load the physicsObjects
    bool loadPhysicObjectToWorld(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool loadPhysicObjectsToWorld(edk::uint32 levelPosition);
    void loadPhysicObjectsToWorld();
    //delete the object
    bool deletePhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    void deleteAllPhysicObjects(edk::uint32 levelPosition);
    void deleteAllPhysicObjects();
    //remove the object
    bool removePhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool removePhysicObjects(edk::uint32 levelPosition);
    void removePhysicObjects();


    //DELETE ALL LEVELS
    void deleteLevel(edk::uint32 levelPosition);
    void deleteAllLevels();

    //World
    void worldSetClockScale(edk::float32 scale);
    //clockStart
    void worldClockStart();

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
    bool removeActionSecond(edk::float32 second);
    //Add zero action
    bool actionZero(edk::float32 second);
    //add position action
    bool actionObjectSetPosition(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::vec2f32 position);
    bool actionObjectSetPosition(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 x,edk::float32 y);
    //add move action
    bool actionObjectMove(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::vec2f32 position);
    bool actionObjectMove(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 x,edk::float32 y);
    bool actionObjectMoveTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::vec2f32 position);
    bool actionObjectMoveTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 x,edk::float32 y);
    //add Size action
    bool actionObjectSetSize(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::size2f32 size);
    bool actionObjectSetSize(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 width,edk::float32 height);
    bool actionObjectSetSize(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 size);
    //add scale action
    bool actionObjectScale(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::size2f32 size);
    bool actionObjectScale(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 width,edk::float32 height);
    bool actionObjectScale(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 size);
    bool actionObjectScaleTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::size2f32 size);
    bool actionObjectScaleTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 width,edk::float32 height);
    bool actionObjectScaleTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 size);
    //add angle action
    bool actionObjectSetAngle(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::float32 angle);
    //add angle action
    bool actionObjectRotateFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::float32 angle);
    bool actionObjectRotateTo(edk::float32 start,edk::float32 end,edk::uint32 levelPosition,edk::float32 depth,edk::float32 angle);
    //MESH SPRITE SHEET
    bool actionObjectPlayName(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,edk::char8* name,bool loop=false);
    bool actionObjectPlayName(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,const char* name,bool loop=false);
    bool actionObjectPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,edk::char8* name);
    bool actionObjectPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,const char* name);


    //update the physics and collisions
    void updatePhysics(edk::int32 velocityIterations, edk::int32 positionIterations);
    //update animations
    bool updateAnimation(edk::uint32 position);
    void updateAnimations();
    //draw the cenario with all the objects
    void draw();
    void drawInsideRect(edk::rectf32 rect);
    bool drawLevel(edk::uint32 levelPosition);
    bool drawLevelInsideRect(edk::uint32 levelPosition,edk::rectf32 rect);
    void drawSelection();
    bool drawSelectionLevel(edk::uint32 levelPosition);

    //SHOW/HIDE LEVEL
    bool hideLevel(edk::uint32 levelPosition);
    bool showLevel(edk::uint32 levelPosition);
    bool setShowLevel(edk::uint32 levelPosition,bool show);
    bool getShowLevel(edk::uint32 levelPosition);

    //get level type
    //EDK_LEVEL_NOTHING
    //EDK_LEVEL_OBJ
    //EDK_LEVEL_OBJ_PHYSICS
    //EDK_LEVEL_TILE_MAP
    edk::uint8 getLevelType(edk::uint32 levelPosition);
    //test if have the level
    bool haveLevel(edk::uint32 levelPosition);
    //return the levelSize
    edk::uint32 getLevelSize();
    //move the level to back
    bool moveLevelBack(edk::uint32 levelPosition);
    bool moveLevelFront(edk::uint32 levelPosition);

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    edk::physics2D::World2D world;
    edk::tiles::TileSet2D tileSet;
protected:
private:
    edk::tiles::TileMap2D* mapSelected;
    //actions group animation
    edk::animation::ActionGroup actions;

    //Function to read the actions
    static edk::Action* readXMLAction(edk::classID thisPointer,edk::uint32 actionCode);

    //ACTIONS
    class ActionObjectZero:public edk::ActionZero{
    public:
        ActionObjectZero(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth);
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        edk::uint32 getLevelPosition();
        edk::float32 getDepth();
    protected:
        edk::Cenario2D* cenario;
        edk::uint32 levelPosition;
        edk::float32 depth;
    };
    class ActionObjectZeroDuration:public edk::Cenario2D::ActionObjectZero{
    public:
        ActionObjectZeroDuration(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration);
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        edk::float32 getDuration();
    protected:
        edk::float32 duration;
    };
    class ActionObjectSetPosition:public edk::Cenario2D::ActionObjectZero{
    public:
        ActionObjectSetPosition(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth, edk::vec2f32 position);
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
    };
    class ActionObjectMove:public edk::Cenario2D::ActionObjectZeroDuration{
    public:
        ActionObjectMove(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration, edk::vec2f32 position);
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
    };
    class ActionObjectSetSize:public edk::Cenario2D::ActionObjectZero{
    public:
        ActionObjectSetSize(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth, edk::size2f32 size);
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
    };
    class ActionObjectScale:public edk::Cenario2D::ActionObjectZeroDuration{
    public:
        ActionObjectScale(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration, edk::size2f32 size);
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
    };
    class ActionObjectSetAngle:public edk::Cenario2D::ActionObjectZero{
    public:
        ActionObjectSetAngle(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth, edk::float32 angle);
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
    };
    class ActionObjectRotate:public edk::Cenario2D::ActionObjectZeroDuration{
    public:
        ActionObjectRotate(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::float32 duration, edk::float32 angle);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        //return the code
        edk::float32 getAngle();
    private:
        edk::float32 angle;
    };
    class ActionObjectMeshName: public edk::ActionName{
    public:
        ActionObjectMeshName(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id, edk::char8* name,bool loop);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        //GET
        edk::uint32 getLevelPosition();
        edk::float32 getDepth();
        edk::uint32 getId();
        bool getLoop();
    private:
        edk::uint32 id;
        bool loop;
        edk::Cenario2D* cenario;
        edk::uint32 levelPosition;
        edk::float32 depth;
    };
    class ActionObjectMeshStop: public edk::Cenario2D::ActionObjectZero{
    public:
        ActionObjectMeshStop(edk::Cenario2D* cenario,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id);
        //run action function
        void runAction();
        //write to XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        //read XML
        bool readFromXML(edk::XML* xml,edk::uint32 id);
        edk::uint32 getId();
    private:
        edk::uint32 id;
        edk::Cenario2D* cenario;
    };

    //get levels less position
    edk::uint32 getLevelsLessPosition();
    //Add a object to the level
    bool addObjectToLevel(edk::Object2D* obj,edk::Object2D* objPhys,edk::uint32 levelPosition,edk::float64 depth,bool created);
    //return the higher level in Objects
    edk::float64 getHigherLevel(edk::uint32 levelPosition);
    //get objectString for Joint
    bool getPhysicsObjectLevelDepth(edk::Object2D* obj,edk::uint32* level,edk::float32* depth);
    //Class to save the object position in level, tileMap or physicsObjects
    class PhysicsPosition{
    public:
        PhysicsPosition(){this->level=0u;this->levelID=EDK_LEVEL_NOTHING;this->depth=0.f;this->mapPosition = edk::vec2ui32(0u,0u);}
        ~PhysicsPosition(){}
        edk::uint32 level;
        edk::uint8 levelID;
        //they have a objectID or a mapPosition
        edk::float32 depth;
        edk::vec2ui32 mapPosition;
        PhysicsPosition operator=(PhysicsPosition position){
            this->level = position.level;
            this->levelID = position.levelID;
            this->depth = position.depth;
            this->mapPosition = position.mapPosition;
            return position;
        }
        //XML
        bool writeToXML(edk::XML* xml,bool id);
        bool readFromXML(edk::XML* xml,bool id);
    };
    bool getPhysicsLevelObject(edk::Object2D* obj,edk::Cenario2D::PhysicsPosition* objLevel);
    edk::physics2D::PhysicObject2D* getPhysicsObjectInLevel(edk::Cenario2D::PhysicsPosition objLevel);

    //objects class save one object with depth
    class ObjClass{
    public:
        //ObjClass(){this->created=false;this->obj=NULL;}
        ObjClass(bool created,edk::Object2D* obj,edk::float64 depth){this->created=created;this->obj=obj;this->depth = depth;this->animating=false;}
        ~ObjClass(){}
        ObjClass operator =(ObjClass objClass){
            this->created=objClass.created;
            this->obj=objClass.obj;
            this->depth = objClass.depth;
            return objClass;
        }
        bool haveCreated(){return this->created;}
        edk::Object2D* getObject(){return this->obj;}
        edk::float64 depth;
        bool animating;
    private:
        bool created;
        edk::Object2D* obj;
    };

    //Binary Tree save objects in a level
    class TreeObjDepth:public edk::vector::BinaryTree<ObjClass*>{
    public:
        TreeObjDepth(){
            //
            this->names=0u;
            this->selectionID =0u;
        }
        ~TreeObjDepth(){
            edk::uint32 size = this->size();
            for(edk::uint32 i=0u;i<size;i++){
                this->deleteObjInPosition(0u);
            }
        }

        edk::uint8 selectionID;

        //clean names
        void cleanNames(){
            this->names = 0;
        }

        //XML
        bool writeToXML(edk::XML* xml,edk::uint32 id,bool isPhysics=false);
        bool readFromXML(edk::XML* xml,edk::uint32 id,bool isPhysics=false);

        //compare if the value is bigger
        virtual bool firstBiggerSecond(ObjClass* first,ObjClass* second){
            if(first->depth>second->depth){
                return true;
            }
            return false;
        }
        virtual bool firstEqualSecond(ObjClass* first,ObjClass* second){
            if(first->depth==second->depth){
                return true;
            }
            return false;
        }
        //Print
        virtual void renderElement(ObjClass* value){
            if(value->getObject()){
                value->getObject()->drawWithoutMaterialWithLight();
            }
        }
        //UPDATE
        virtual void updateElement(ObjClass* value){
            if(value->getObject()){
                value->getObject()->updateAnimations();
            }
        }
        //Print
        virtual void printElement(ObjClass* value){
            if(value->getObject()){
                edk::GU::guPushName(edk::BinaryConverter::joinBits(this->selectionID,this->names++,24));
                value->getObject()->drawWithoutMaterial();
                edk::GU::guPopName();
            }
        }
        //add object
        bool addObject(bool created,edk::Object2D* obj,edk::float64 depth){
            if(obj){
                edk::Cenario2D::ObjClass* temp = new edk::Cenario2D::ObjClass(created,obj,depth);
                if(temp){
                    if(this->add(temp)){
                        //add the object to the treeObj
                        if(this->treeObj.add(temp)){
                            //return true
                            return true;
                        }
                        //else remove temp;
                        this->remove(temp);
                    }
                    delete temp;
                }
            }
            return false;
        }
        //get the object from depth
        edk::Object2D* getObjectFromDepth(edk::float64 depth){
            edk::Cenario2D::ObjClass* objClass = this->getObjClassFromDepth(depth);
            if(objClass){
                return objClass->getObject();
            }
            return NULL;
        }
        edk::float32 getObjectDepthInPosition(edk::uint32 position){
            //get the object
            edk::Cenario2D::ObjClass* objClass = NULL;
            objClass = this->getElementInPosition(position);
            if(objClass){
                return objClass->depth;
            }
            return 0.f;
        }
        edk::float32 getObjectDepth(edk::Object2D* obj){
            if(obj){
                //get the object
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);
                if(objClass){
                    if(objClass->getObject() == obj){
                        return objClass->depth;
                    }
                }
            }
            return 0.f;
        }
        //return object in position
        edk::Object2D* getObjectInPosition(edk::uint32 position){
            //get the object
            edk::Cenario2D::ObjClass* objClass = NULL;
            objClass = this->getElementInPosition(position);
            if(objClass){
                return objClass->getObject();
            }
            return NULL;
        }
        //return the object
        edk::Object2D* getObject(edk::Object2D* obj){
            if(obj){
                //get the object
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);
                if(objClass){
                    if(objClass->getObject() == obj){
                        return objClass->getObject();
                    }
                }
            }
            return NULL;
        }
        //test if have the object
        bool haveObject(edk::Object2D* obj){
            if(obj){
                //get the object
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);
                if(objClass){
                    if(objClass->getObject() == obj){
                        return true;
                    }
                }
            }
            return false;
        }

        //delete the obj
        bool deleteObj(edk::Object2D* obj){
            if(obj){
                //get the object
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);
                if(objClass){
                    if(objClass->getObject()){
                        //remove
                        if(this->treeObj.remove(objClass)){
                            this->remove(objClass);
                            //test if can deleteIt
                            if(objClass->haveCreated()){
                                delete objClass->getObject();
                            }
                            delete objClass;
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        //remove the obj
        bool removeObj(edk::Object2D* obj){
            if(obj){
                //get the object
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);
                if(objClass){
                    if(objClass->getObject()){
                        //remove
                        if(this->treeObj.remove(objClass)){
                            this->remove(objClass);
                            //
                            delete objClass;
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        //delete the depth
        bool deleteObjInDepth(edk::float64 depth){
            //get the object
            edk::Cenario2D::ObjClass* objClass = this->getObjClassFromDepth(depth);
            if(objClass){
                if(objClass->getObject()){
                    //remove
                    if(this->remove(objClass)){
                        this->treeObj.remove(objClass);
                        //test if can deleteIt
                        if(objClass->haveCreated()){
                            delete objClass->getObject();
                        }
                        delete objClass;
                        return true;
                    }
                }
            }
            return false;
        }
        bool deleteObjInPosition(edk::uint32 position){
            //get the object
            edk::Cenario2D::ObjClass* objClass = this->getElementInPosition(position);
            if(objClass){
                if(objClass->getObject()){
                    //remove
                    if(this->treeObj.remove(objClass)){
                        this->remove(objClass);
                        //test if can deleteIt
                        if(objClass->haveCreated()){
                            delete objClass->getObject();
                        }
                        delete objClass;
                        return true;
                    }
                }
            }
            return false;
        }
        //delete all objects
        void deleteAllObjects(){
            //clean treeObj;
            this->treeObj.clean();
            edk::uint32 size = this->size();
            edk::Cenario2D::ObjClass* temp = NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    if(temp->getObject() && temp->haveCreated()){
                        delete temp->getObject();
                    }
                    delete temp;
                }
            }
        }
        edk::float64 getLastLevel(){
            if(this->size()){
                edk::Cenario2D::ObjClass* objClass = this->getElementInPosition(this->size()-1u);
                if(objClass){
                    return objClass->depth;
                }
            }
            return 0.0;
        }
    private:
        //object names
        edk::uint32 names;

        edk::Cenario2D::ObjClass* getObjClass(edk::Object2D* obj){
            edk::Cenario2D::ObjClass find(false,obj,0.f);
            return this->treeObj.getElement(&find);
        }
        edk::Cenario2D::ObjClass* getObjClassFromDepth(edk::float64 depth){
            edk::Cenario2D::ObjClass find(false,NULL,depth);
            return this->getElement(&find);
        }

        class TreeObj:public edk::vector::BinaryTree<ObjClass*>{
        public:
            //compare if the value is bigger
            virtual bool firstBiggerSecond(ObjClass* first,ObjClass* second){
                if(first->getObject()>second->getObject()){
                    return true;
                }
                return false;
            }
            virtual bool firstEqualSecond(ObjClass* first,ObjClass* second){
                if(first->getObject()==second->getObject()){
                    return true;
                }
                return false;
            }
        }treeObj;
    };

    //Physics group to animate and update
    class TreePhysObjDepth:public edk::Cenario2D::TreeObjDepth{
    public:
        TreePhysObjDepth(edk::physics2D::World2D* world){this->world=world;}
        //UPDATE
        virtual void updateElement(ObjClass* value){
            edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)value->getObject();
            if(value->getObject()){
                if(value->getObject()->updateAnimations()){
                    //update the object in the physics world
                    this->world->updateObjectVelocity(temp);
                    value->animating=true;
                }
                else{
                    //test if was animating
                    if(value->animating){
                        //then test if is kinematic
                        if(temp->getType() == edk::physics::KinematicBody){
                            //clean the velocity
                            this->world->cleanObjectVelocity(temp);
                        }
                    }
                    value->animating=false;
                }
            }
        }
    private:
        edk::physics2D::World2D* world;
    };

    //Save objects in a Level
    class LevelObj{
    public:
        LevelObj(edk::Cenario2D::TreeObjDepth* objs,edk::Cenario2D::TreePhysObjDepth* objsPhys){this->clean();this->objs = objs;this->objsPhys = objsPhys;this->show=true;}
        LevelObj(edk::tiles::TileMap2D* tileMap){this->clean();this->tileMap = tileMap;this->show=true;}
        LevelObj(){this->clean();this->show=true;}
        ~LevelObj(){}
        //XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        bool readFromXML(edk::XML* xml,edk::uint32 id,edk::tiles::TileSet2D* tileSet,edk::physics2D::World2D* world);

        void draw(){
            if(this->show){
                if(this->objs){
                    edk::GU::guEnable(GU_LIGHTING);
                    this->objs->cleanNames();
                    this->objs->render();
                    edk::GU::guDisable(GU_LIGHTING);
                }
                else if(this->objsPhys){
                    edk::GU::guEnable(GU_LIGHTING);
                    this->objsPhys->cleanNames();
                    this->objsPhys->render();
                    edk::GU::guDisable(GU_LIGHTING);
                }
                else if(this->tileMap){
                    this->tileMap->draw();
                }
            }
        }
        void drawInsideRect(edk::rectf32 rect){
            if(this->show){
                if(this->objs){
                    edk::GU::guEnable(GU_LIGHTING);
                    this->objs->cleanNames();
                    this->objs->render();
                    edk::GU::guDisable(GU_LIGHTING);
                }
                else if(this->objsPhys){
                    edk::GU::guEnable(GU_LIGHTING);
                    this->objsPhys->cleanNames();
                    this->objsPhys->render();
                    edk::GU::guDisable(GU_LIGHTING);
                }
                else if(this->tileMap){
                    this->tileMap->drawInsideWorldRect(rect);
                }
            }
        }
        void drawSelection(edk::uint8 id=0u){
            if(this->show){
                if(this->objs){
                    edk::GU::guDisable(GU_LIGHTING);
                    this->objs->selectionID = id;
                    this->objs->print();
                }
                else if(this->objsPhys){
                    edk::GU::guDisable(GU_LIGHTING);
                    this->objsPhys->selectionID = id;
                    this->objsPhys->print();
                }
                else if(this->tileMap){
                    edk::GU::guDisable(GU_LIGHTING);
                    this->tileMap->drawSelection(id);
                }
            }
        }

        void clean(){this->objs = NULL;this->objsPhys = NULL;this->tileMap = NULL;}
        bool haveSome(){
            if(this->objs){
                return true;
            }
            else if(this->objsPhys){
                return true;
            }
            else if(this->tileMap){
                return true;
            }
            return false;
        }

        edk::Cenario2D::TreeObjDepth* objs;
        edk::Cenario2D::TreePhysObjDepth* objsPhys;
        edk::tiles::TileMap2D* tileMap;
        bool show;
    };

    //objects animation tree
    class TreeAnim: public edk::vector::BinaryTree<edk::Object2D*>{
    public:
        TreeAnim(){}
        ~TreeAnim(){}
        //UPDATE
        virtual void updateElement(edk::Object2D* value){
            //update the value
            value->updateAnimations();
        }
    }treeAnim;

    edk::vector::Stack<edk::Cenario2D::LevelObj*> levels;
};
}//end namespace edk

#endif // CENARIO2D_H
