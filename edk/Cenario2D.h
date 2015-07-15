#ifndef EDK_CENARIO2D_H
#define EDK_CENARIO2D_H

#pragma once
#include "physics2D/World2D.h"
#include "tiles/TileMap2D.h"
#include "vector/BinaryTree.h"

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
    edk::vec2f32 selectedTileMapGetTileWorldPosition(edk::vec2f32 position);
    edk::vec2f32 selectedTileMapGetTileWorldPosition(edk::uint32 positionX,edk::uint32 positionY);
    //Set scale the map
    bool selectedTileMapSetScaleMap(edk::size2f32 scale);
    bool selectedTileMapSetScaleMap(edk::float32 width,edk::float32 height );
    //delete physicObjects
    bool  selectedTileDeletePhysicsTiles();
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
    //get the object
    edk::Object2D* getObject(edk::uint32 levelPosition,edk::float32 depth);
    edk::Object2D* getObject(edk::uint32 levelPosition,edk::uint32 position);
    //delete the object
    bool deleteObject(edk::uint32 levelPosition,edk::Object2D* obj);
    void deleteAllObjects(edk::uint32 levelPosition);
    void deleteAllObjects();

    //OBJECTS_PHYSICS
    //add a object to the tree
    edk::physics2D::PhysicObject2D* newPhysycObject(edk::uint32 levelPosition,edk::physics::bodyType physicType);
    edk::physics2D::PhysicObject2D* newPhysycObject(edk::uint32 levelPosition,edk::physics::bodyType physicType,edk::float32 depth);
    edk::physics2D::PhysicObject2D* newPhysycSensor(edk::uint32 levelPosition,edk::physics::bodyType physicType);
    edk::physics2D::PhysicObject2D* newPhysycSensor(edk::uint32 levelPosition,edk::physics::bodyType physicType,edk::float32 depth);
    bool addPhysycObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool addPhysycObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj,edk::float32 depth);
    bool addPhysycSensor(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* sensor);
    bool addPhysycSensor(edk::uint32 levelPosition,edk::physics2D::StaticSensor2D* obj,edk::float32 sensor);
    //get the object
    edk::physics2D::PhysicObject2D* getPhysycObject(edk::uint32 levelPosition,edk::float32 depth);
    edk::physics2D::PhysicObject2D* getPhysycObject(edk::uint32 levelPosition,edk::uint32 position);
    //load the physicsObjects
    bool loadPhysicObjectToWorld(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool loadPhysicObjectsToWorld(edk::uint32 levelPosition);
    void loadPhysicObjectsToWorld();
    //delete the object
    bool deletePhysycObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    void deleteAllPhysycObjects(edk::uint32 levelPosition);
    void deleteAllPhysycObjects();


    //DELETE ALL LEVELS
    void deleteLevel(edk::uint32 levelPosition);
    void deleteAllLevels();

    //World
    void worldSetClockScale(edk::float32 scale);
    //clockStart
    void worldClockStart();


    //update the physics and collisions
    void updatePhysics(edk::int32 velocityIterations, edk::int32 positionIterations);
    //update animations
    bool updateAnimation(edk::uint32 position);
    void updateAnimations();
    //draw the cenario with all the objects
    void draw();

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);

    edk::physics2D::World2D world;
    edk::tiles::TileSet2D tileSet;
protected:
private:
    edk::tiles::TileMap2D* mapSelected;

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

    //objects class
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

    //Binary Tree
    class TreeObjDepth:public edk::vector::BinaryTree<ObjClass*>{
    public:
        TreeObjDepth(){
            //
        }
        ~TreeObjDepth(){
            edk::uint32 size = this->size();
            for(edk::uint32 i=0u;i<size;i++){
                this->deleteObjInPosition(0u);
            }
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

    class LevelObj{
    public:
        LevelObj(edk::Cenario2D::TreeObjDepth* objs,edk::Cenario2D::TreePhysObjDepth* objsPhys){this->clean();this->objs = objs;this->objsPhys = objsPhys;}
        LevelObj(edk::tiles::TileMap2D* tileMap){this->clean();this->tileMap = tileMap;}
        LevelObj(){this->clean();}
        ~LevelObj(){}
        //XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        bool readFromXML(edk::XML* xml,edk::uint32 id,edk::tiles::TileSet2D* tileSet,edk::physics2D::World2D* world);

        void draw(){
            if(this->objs){
                edk::GU::guEnable(GU_LIGHTING);
                this->objs->render();
                edk::GU::guDisable(GU_LIGHTING);
            }
            else if(this->objsPhys){
                edk::GU::guEnable(GU_LIGHTING);
                this->objsPhys->render();
                edk::GU::guDisable(GU_LIGHTING);
            }
            else if(this->tileMap){
                this->tileMap->draw();
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
    };


    edk::vector::Stack<edk::Cenario2D::LevelObj*> levels;
};
}//end namespace edk

#endif // CENARIO2D_H
