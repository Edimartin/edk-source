#ifndef EDK_CENARIO2D_H
#define EDK_CENARIO2D_H

/*
Library C++ Cenario2D - 2D Cenario to draw objects, physic objects and tilemaps
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
#warning "Inside Cenario2D"
#endif

#pragma once
#include "TypeDefines.h"
#include "physics2D/World2D.h"
#include "tiles/TileMap2D.h"
#include "vector/BinaryTree.h"
#include "animation/ActionGroup.h"
#include "Object2DValues.h"
#include "pack/FilePackage.h"
#include "vector/QuadTree.h"

#ifdef printMessages
#warning "    Compiling Cenario2D"
#endif

namespace edk{
class Cenario2DCallback{
public:
    Cenario2DCallback(){}
    //OBJECTS 2D
    virtual void objectGetIn(edk::Object2D* /*obj*/,edk::uint32 /*levelID*/){}
    virtual void objectUpdating(edk::Object2D* /*obj*/,edk::uint32 /*levelID*/){}
    virtual void objectGetOut(edk::Object2D* /*obj*/,edk::uint32 /*levelID*/){}
    //PHYSICS
    virtual void physicObjectGetIn(edk::physics2D::PhysicObject2D* /*obj*/,edk::uint32 /*levelID*/){}
    virtual void physicObjectUpdating(edk::physics2D::PhysicObject2D* /*obj*/,edk::uint32 /*levelID*/){}
    virtual void physicObjectGetOut(edk::physics2D::PhysicObject2D* /*obj*/,edk::uint32 /*levelID*/){}
};
class Cenario2D : public edk::Object2DValues , public edk::physics2D::ContactCallback2D , public edk::tiles::tileCallback{
public:
    Cenario2D();
    Cenario2D(edk::physics2D::World2D* world);
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

    //set the world
    bool setWorld(edk::physics2D::World2D* world);
    static edk::physics2D::World2D* getWorldTemplate();

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
    edk::Object2D* getObjectInPosition(edk::uint32 levelPosition,edk::uint32 position);
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
    //remove object from be animated
    bool removeObjectAnimated(edk::uint32 levelPosition,edk::Object2D* obj);
    bool removeObjectAnimated(edk::uint32 levelPosition,edk::uint32 position);
    bool removeObjectAnimated(edk::uint32 levelPosition,edk::float32 depth);

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
    edk::physics2D::PhysicObject2D* getPhysicObjectInPosition(edk::uint32 levelPosition,edk::uint32 position);
    //return the depth of the physic object
    edk::float32 getPhysicObjectDepth(edk::uint32 levelPosition,edk::uint32 position);
    edk::float32 getPhysicObjectDepth(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    //load the physicsObjects to the world
    bool loadPhysicObjectToWorld(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool loadPhysicObjectsToWorld(edk::uint32 levelPosition);
    bool loadPhysicObjectsToWorld();
    //unload the physicsObjects from the world
    bool unloadPhysicObjectFromWorld(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool unloadPhysicObjectsFromWorld(edk::uint32 levelPosition);
    bool unloadPhysicObjectsFromWorld();
    //delete the object
    bool deletePhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    void deleteAllPhysicObjects(edk::uint32 levelPosition);
    void deleteAllPhysicObjects();
    //remove the object
    bool removePhysicObject(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool removePhysicObjects(edk::uint32 levelPosition);
    void removePhysicObjects();
    //set physic object to be animated
    bool setPhysicObjectAnimated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool setPhysicObjectAnimated(edk::uint32 levelPosition,edk::uint32 position);
    bool setPhysicObjectAnimated(edk::uint32 levelPosition,edk::float32 depth);
    //remove physic object from be animated
    bool removePhysicObjectAnimated(edk::uint32 levelPosition,edk::physics2D::PhysicObject2D* obj);
    bool removePhysicObjectAnimated(edk::uint32 levelPosition,edk::uint32 position);
    bool removePhysicObjectAnimated(edk::uint32 levelPosition,edk::float32 depth);


    //DELETE ALL LEVELS
    void deleteLevel(edk::uint32 levelPosition);
    void deleteAllLevels();

    //add a callback
    bool addCallback(edk::Cenario2DCallback* callback);
    bool removeCallback(edk::Cenario2DCallback* callback);

    //World
    void worldSetClockScale(edk::float32 scale);
    //clockStart
    void worldClockStart();

    //ACTIONS
    //play actions
    void playForwardActions();
    void playForwardActions(edk::float32 updateSeconds);
    void playForwardInActions(edk::float32 second);
    void playForwardInActions(edk::float32 second,edk::float32 updateSeconds);
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
    void updateActions(edk::float32 seconds);
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
    bool actionObjectPlayName(edk::float32 second,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,const edk::char8* name,bool loop=false);
    bool actionObjectPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,edk::char8* name);
    bool actionObjectPlayNameFor(edk::float32 second,edk::float32 duration,edk::uint32 levelPosition,edk::float32 depth,edk::uint32 id,const edk::char8* name);


    //update the physics and collisions
    void updatePhysics(edk::int32 velocityIterations, edk::int32 positionIterations);
    void updatePhysics(edk::float32 seconds, edk::int32 velocityIterations, edk::int32 positionIterations);
    //update the quads (update selection in quadtree)
    void updateQuadsInsideRect(edk::rectf32 rect);
    bool updateLevelQuadsInsideRect(edk::uint32 levelPosition,edk::rectf32 rect);
    bool updateLevelsQuadsInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect);
    //update animations
    bool updateAnimation(edk::uint32 position);
    bool updateAnimation(edk::uint32 position,edk::float32 seconds);
    bool updateAnimations();
    bool updateAnimations(edk::float32 seconds);
    //draw the cenario with all the objects
    void draw();
    void drawWire();
    void drawQuads();
    void drawBoxes();
    void drawInsideRect(edk::rectf32 rect);
    bool drawLevel(edk::uint32 levelPosition);
    bool drawLevelWire(edk::uint32 levelPosition);
    bool drawLevelQuads(edk::uint32 levelPosition);
    bool drawLevelBoxes(edk::uint32 levelPosition);
    bool drawLevelInsideRect(edk::uint32 levelPosition,edk::rectf32 rect);
    bool drawLevelWireInsideRect(edk::uint32 levelPosition,edk::rectf32 rect);
    //draw levels from start and end
    bool drawLevels(edk::uint32 startPosition,edk::uint32 endPosition);
    bool drawLevelsWire(edk::uint32 startPosition,edk::uint32 endPosition);
    bool drawLevelsQuads(edk::uint32 startPosition,edk::uint32 endPosition);
    bool drawLevelsBoxes(edk::uint32 startPosition,edk::uint32 endPosition);
    bool drawLevelsInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect);
    bool drawLevelsWireInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect);
    void drawSelection();
    bool drawSelectionLevel(edk::uint32 levelPosition);
    bool drawSelectionLevels(edk::uint32 startPosition,edk::uint32 endPosition);
    bool drawSelectionLevelsInsideRect(edk::uint32 startPosition,edk::uint32 endPosition,edk::rectf32 rect);

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
    edk::uint32 getLevelsSize();
    edk::uint32 getLevelSize(edk::uint32 levelPosition);
    //move the level to back
    bool moveLevelBack(edk::uint32 levelPosition);
    bool moveLevelFront(edk::uint32 levelPosition);

    //set level translate
    bool setLevelPosition(edk::uint32 levelPosition,edk::vec2f32 position);
    bool setLevelPosition(edk::uint32 levelPosition,edk::float32 x,edk::float32 y);
    //set level rotate angle
    bool setLevelAngle(edk::uint32 levelPosition,edk::float32 angle);
    //set level size
    bool setLevelSize(edk::uint32 levelPosition,edk::size2f32 size);
    bool setLevelSize(edk::uint32 levelPosition,edk::float32 width,edk::float32 height);

    //XML
    virtual bool writeToXML(edk::XML* xml,edk::uint32 id);
    virtual bool writeToXML(const edk::char8* fileName,edk::uint32 id);
    virtual bool writeToXML(edk::char8* fileName,edk::uint32 id);
    //read from XML
    virtual bool readFromXML(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXML(const edk::char8* fileName,edk::uint32 id);
    virtual bool readFromXML(edk::char8* fileName,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 id);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 id);
    //read level from XML
    virtual bool readLevelFromXML(edk::XML* xml,edk::uint32 level,edk::uint32 id);
    virtual bool readLevelFromXML(const edk::char8* fileName,edk::uint32 level,edk::uint32 id);
    virtual bool readLevelFromXML(edk::char8* fileName,edk::uint32 level,edk::uint32 id);
    virtual bool readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level,edk::uint32 id);
    virtual bool readLevelFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level,edk::uint32 id);
    virtual bool readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level,edk::uint32 id);
    //read from XML without load physics objects in to the world
    virtual bool readFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 id);
    virtual bool readFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 id);
    virtual bool readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);
    virtual bool readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 id);
    virtual bool readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 id);
    //read level from XML without load physics objects in to the world
    virtual bool readLevelFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 level,edk::uint32 id);
    virtual bool readLevelFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 level,edk::uint32 id);
    virtual bool readLevelFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 level,edk::uint32 id);
    virtual bool readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level,edk::uint32 id);
    virtual bool readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level,edk::uint32 id);
    virtual bool readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level,edk::uint32 id);
    //Without id
    virtual bool writeToXML(edk::XML* xml);
    virtual bool writeToXML(const edk::char8* fileName);
    virtual bool writeToXML(edk::char8* fileName);
    //read from XML
    virtual bool readFromXML(edk::XML* xml);
    virtual bool readFromXML(const edk::char8* fileName);
    virtual bool readFromXML(edk::char8* fileName);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName);
    virtual bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName);
    //read level from XML
    virtual bool readLevelFromXML(edk::XML* xml,edk::uint32 level);
    virtual bool readLevelFromXML(const edk::char8* fileName,edk::uint32 level);
    virtual bool readLevelFromXML(edk::char8* fileName,edk::uint32 level);
    virtual bool readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level);
    virtual bool readLevelFromXMLFromPack(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level);
    virtual bool readLevelFromXMLFromPack(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level);
    //read from XML without load physics objects in to the world
    virtual bool readFromXMLWithoutLoadPhysics(edk::XML* xml);
    virtual bool readFromXMLWithoutLoadPhysics(const edk::char8* fileName);
    virtual bool readFromXMLWithoutLoadPhysics(edk::char8* fileName);
    virtual bool readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml);
    virtual bool readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName);
    virtual bool readFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName);
    //read level from XML without load physics objects in to the world
    virtual bool readLevelFromXMLWithoutLoadPhysics(edk::XML* xml,edk::uint32 level);
    virtual bool readLevelFromXMLWithoutLoadPhysics(const edk::char8* fileName,edk::uint32 level);
    virtual bool readLevelFromXMLWithoutLoadPhysics(edk::char8* fileName,edk::uint32 level);
    virtual bool readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 level);
    virtual bool readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,const edk::char8* fileName,edk::uint32 level);
    virtual bool readLevelFromXMLFromPackWithoutLoadPhysics(edk::pack::FilePackage* pack,edk::char8* fileName,edk::uint32 level);

    edk::physics2D::World2D* world;
    edk::tiles::TileSet2D tileSet;
private:
    //world template
    static edk::physics2D::World2D worldTemplate;

    edk::tiles::TileMap2D* mapSelected;
    //actions group animation
    edk::animation::ActionGroup actions;

    //callback tree
    edk::vector::BinaryTree<edk::Cenario2DCallback*> calls;

    //Function to read the actions
    static edk::Action* readXMLAction(edk::classID thisPointer,edk::uint32 actionCode);
    //transformBeggin
    void transformBeggin();
    void transformEnd();

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
        PhysicsPosition(){
            this->level=0u;edkEnd();this->levelID=EDK_LEVEL_NOTHING;edkEnd();this->depth=0.f;edkEnd();this->mapPosition = edk::vec2ui32(0u,0u);edkEnd();
        }
        ~PhysicsPosition(){}
        edk::uint32 level;
        edk::uint8 levelID;
        //they have a objectID or a mapPosition
        edk::float32 depth;
        edk::vec2ui32 mapPosition;
        PhysicsPosition operator=(PhysicsPosition position){
            this->level = position.level;edkEnd();
            this->levelID = position.levelID;edkEnd();
            this->depth = position.depth;edkEnd();
            this->mapPosition = position.mapPosition;edkEnd();
            return position;edkEnd();
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
        //ObjClass(){this->created=false;edkEnd();this->obj=NULL;edkEnd();}
        ObjClass(bool created,edk::Object2D* obj,edk::float64 depth){
            this->created=created;edkEnd();this->obj=obj;edkEnd();this->depth = depth;edkEnd();this->animating=false;edkEnd();this->boundingBox=0.f;edkEnd();
        }
        ~ObjClass(){}
        ObjClass operator =(ObjClass objClass){
            this->created=objClass.created;edkEnd();
            this->obj=objClass.obj;edkEnd();
            this->depth = objClass.depth;edkEnd();
            return objClass;edkEnd();
        }
        bool haveCreated(){return this->created;edkEnd();}
        edk::Object2D* getObject(){return this->obj;edkEnd();}
        //function to calculate the boundingBox
        edk::rectf32 calculateBoundingBox(edk::vector::Matrix<edk::float32,3,3>* transformMat){
            if(this->obj){
                this->obj->calculateBoundingBox(transformMat);edkEnd();
                this->boundingBox = this->obj->getBoundingBox();edkEnd();
                return this->boundingBox;edkEnd();
            }
            return edk::rectf32(0.f,0.f,0.f,0.f);edkEnd();
        }
        edk::rectf32 calculateBoundingBox(){
            if(this->obj){
                this->obj->calculateBoundingBox();edkEnd();
                this->boundingBox = this->obj->getBoundingBox();edkEnd();
                return this->boundingBox;edkEnd();
            }
            return edk::rectf32(0.f,0.f,0.f,0.f);edkEnd();
        }
        //get the boundingBox
        edk::rectf32 getBoundingBox(){return this->boundingBox;edkEnd();}
        edk::vec2f32 getBoundingBoxPoint1(){return this->boundingBox.origin;edkEnd();}
        edk::vec2f32 getBoundingBoxPoint2(){return edk::vec2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();}

        //draw the boundingBox
        void drawBoundingBox(){
            edk::GU::guVertex2f32(this->boundingBox.origin.x,this->boundingBox.origin.y);edkEnd();
            edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y);edkEnd();
            edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.origin.y);edkEnd();
            edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
            edk::GU::guVertex2f32(this->boundingBox.size.width,this->boundingBox.size.height);edkEnd();
            edk::GU::guVertex2f32(this->boundingBox.origin.x,this->boundingBox.size.height);edkEnd();
            edk::GU::guVertex2f32(this->boundingBox.origin.x,this->boundingBox.size.height);edkEnd();
            edk::GU::guVertex2f32(this->boundingBox.origin.x,this->boundingBox.origin.y);edkEnd();
        }

        edk::float64 depth;
        bool animating;
    private:
        bool created;
        edk::Object2D* obj;
        //bounding box of the object
        edk::rectf32 boundingBox;
    };

    //Binary Tree save objects in a level
    class TreeObjDepth : public edk::vector::BinaryTree<edk::Cenario2D::ObjClass*> , public edk::vector::BinaryTreeCallback<edk::Cenario2D::ObjClass*>{
    public:
        TreeObjDepth(){
            //
            this->names=0u;edkEnd();
            this->selectionID =0u;edkEnd();
            this->seconds=0.f;edkEnd();
            this->time.start();edkEnd();
        }
        ~TreeObjDepth(){
            edk::uint32 size = this->size();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                this->deleteObjInPosition(0u);edkEnd();
            }
        }

        edk::uint8 selectionID;

        //clean names
        void cleanNames(){
            this->names = 0;edkEnd();
        }

        //XML
        bool writeToXML(edk::XML* xml,edk::uint32 id,bool isPhysics=false);
        bool readFromXML(edk::XML* xml,edk::uint32 id,bool isPhysics=false);
        bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id,bool isPhysics=false);

        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::Cenario2D::ObjClass* first,edk::Cenario2D::ObjClass* second){
            if(first->depth>second->depth){
                return true;
            }
            return false;
        }
        virtual bool firstEqualSecond(edk::Cenario2D::ObjClass* first,edk::Cenario2D::ObjClass* second){
            if(first->depth==second->depth){
                return true;
            }
            return false;
        }
        //Draw
        virtual void drawElement(edk::Cenario2D::ObjClass* value){
            if(value->getObject()){
                value->getObject()->draw();edkEnd();
            }
        }
        virtual void drawWireElement(edk::Cenario2D::ObjClass* value){
            if(value->getObject()){
                value->getObject()->drawWire();edkEnd();
            }
        }
        //UPDATE
        virtual void updateElement(edk::Cenario2D::ObjClass* value){
            if(value->getObject()){
                value->getObject()->updateAnimations(this->seconds);edkEnd();
            }
        }
        //Print
        virtual void printElement(edk::Cenario2D::ObjClass* value){
            if(value->getObject()){
                edk::GU::guPushName(this->selectionID);edkEnd();
                edk::GU::guPushName(this->names++);edkEnd();
                value->getObject()->drawWithoutMaterial();edkEnd();
                edk::GU::guPopName();edkEnd();
                edk::GU::guPopName();edkEnd();
            }
        }
        //render wire
        virtual void renderWireElement(edk::Cenario2D::ObjClass* value){
            if(value->getObject()){
                value->drawBoundingBox();edkEnd();
            }
        }

        virtual void callbackDrawElement(edk::Cenario2D::ObjClass* value){
            this->drawElement(value);edkEnd();
        }
        virtual void callbackDrawWireElement(edk::Cenario2D::ObjClass* value){
            this->drawWireElement(value);edkEnd();
        }
        virtual void callbackUpdateElement(edk::Cenario2D::ObjClass* value){
            this->updateElement(value);edkEnd();
        }
        virtual void callbackPrintElement(edk::Cenario2D::ObjClass* value){
            this->printElement(value);edkEnd();
        }

        //SET
        bool setSeconds(edk::float32 seconds){
            if(seconds>0.f){
                this->seconds=seconds;edkEnd();
                return true;
            }
            else{
                this->seconds=0.f;edkEnd();
            }
            return false;
        }
        bool loadSeconds(){
            bool ret = this->setSeconds(this->time.getSeconds());edkEnd();
            this->time.start();edkEnd();
            return ret;
        }
        //add object
        bool addObject(bool created,edk::Object2D* obj,edk::float64 depth){
            if(obj){
                edk::Cenario2D::ObjClass* temp = new edk::Cenario2D::ObjClass(created,obj,depth);edkEnd();
                if(temp){
                    if(this->add(temp)){
                        //add the object to the treeObj
                        if(this->treeObj.add(temp)){
                            //return true
                            return true;
                        }
                        //else remove temp;edkEnd();
                        this->remove(temp);edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
            return false;
        }
        //get the object from depth
        edk::Object2D* getObjectFromDepth(edk::float64 depth){
            edk::Cenario2D::ObjClass* objClass = this->getObjClassFromDepth(depth);edkEnd();
            if(objClass){
                return objClass->getObject();edkEnd();
            }
            return NULL;
        }
        edk::float32 getObjectDepthInPosition(edk::uint32 position){
            //get the object
            edk::Cenario2D::ObjClass* objClass = NULL;edkEnd();
            objClass = this->getElementInPosition(position);edkEnd();
            if(objClass){
                return objClass->depth;edkEnd();
            }
            return 0.f;
        }
        edk::float32 getObjectDepth(edk::Object2D* obj){
            if(obj){
                //get the object
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);edkEnd();
                if(objClass){
                    if(objClass->getObject() == obj){
                        return objClass->depth;edkEnd();
                    }
                }
            }
            return 0.f;
        }
        //return object in position
        edk::Object2D* getObjectInPosition(edk::uint32 position){
            //get the object
            edk::Cenario2D::ObjClass* objClass = NULL;edkEnd();
            objClass = this->getElementInPosition(position);edkEnd();
            if(objClass){
                return objClass->getObject();edkEnd();
            }
            return NULL;
        }
        //return the object
        edk::Object2D* getObject(edk::Object2D* obj){
            if(obj){
                //get the object
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);edkEnd();
                if(objClass){
                    if(objClass->getObject() == obj){
                        return objClass->getObject();edkEnd();
                    }
                }
            }
            return NULL;
        }
        edk::Cenario2D::ObjClass* getObjectClassFromDepth(edk::float64 depth){
            edk::Cenario2D::ObjClass* objClass = this->getObjClassFromDepth(depth);edkEnd();
            if(objClass){
                return objClass;edkEnd();
            }
            return NULL;
        }
        edk::Cenario2D::ObjClass* getObjectClassInPosition(edk::uint32 position){
            //get the object
            edk::Cenario2D::ObjClass* objClass = NULL;edkEnd();
            objClass = this->getElementInPosition(position);edkEnd();
            if(objClass){
                return objClass;edkEnd();
            }
            return NULL;
        }
        edk::Cenario2D::ObjClass* getObjectClassFromObject(edk::Object2D* obj){
            if(obj){
                //get the object
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);edkEnd();
                if(objClass){
                    if(objClass->getObject() == obj){
                        return objClass;edkEnd();
                    }
                }
            }
            return NULL;
        }
        //test if have the object
        bool haveObject(edk::Object2D* obj){
            if(obj){
                //get the object
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);edkEnd();
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
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);edkEnd();
                if(objClass){
                    if(objClass->getObject()){
                        //remove
                        if(this->treeObj.remove(objClass)){
                            this->remove(objClass);edkEnd();
                            //test if can deleteIt
                            if(objClass->haveCreated()){
                                delete objClass->getObject();edkEnd();
                            }
                            delete objClass;edkEnd();
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
                edk::Cenario2D::ObjClass* objClass = this->getObjClass(obj);edkEnd();
                if(objClass){
                    if(objClass->getObject()){
                        //remove
                        if(this->treeObj.remove(objClass)){
                            this->remove(objClass);edkEnd();
                            //
                            delete objClass;edkEnd();
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
            edk::Cenario2D::ObjClass* objClass = this->getObjClassFromDepth(depth);edkEnd();
            if(objClass){
                if(objClass->getObject()){
                    //remove
                    if(this->remove(objClass)){
                        this->treeObj.remove(objClass);edkEnd();
                        //test if can deleteIt
                        if(objClass->haveCreated()){
                            delete objClass->getObject();edkEnd();
                        }
                        delete objClass;edkEnd();
                        return true;
                    }
                }
            }
            return false;
        }
        bool deleteObjInPosition(edk::uint32 position){
            //get the object
            edk::Cenario2D::ObjClass* objClass = this->getElementInPosition(position);edkEnd();
            if(objClass){
                if(objClass->getObject()){
                    //remove
                    if(this->treeObj.remove(objClass)){
                        this->remove(objClass);edkEnd();
                        //test if can deleteIt
                        if(objClass->haveCreated()){
                            delete objClass->getObject();edkEnd();
                        }
                        delete objClass;edkEnd();
                        return true;
                    }
                }
            }
            return false;
        }
        //delete all objects
        void deleteAllObjects(){
            //clean treeObj;edkEnd();
            this->treeObj.clean();edkEnd();
            edk::uint32 size = this->size();edkEnd();
            edk::Cenario2D::ObjClass* temp = NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);edkEnd();
                if(temp){
                    if(temp->getObject() && temp->haveCreated()){
                        delete temp->getObject();edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
        }
        edk::float64 getLastLevel(){
            if(this->size()){
                edk::Cenario2D::ObjClass* objClass = this->getElementInPosition(this->size()-1u);edkEnd();
                if(objClass){
                    return objClass->depth;edkEnd();
                }
            }
            return 0.0;edkEnd();
        }
    protected:
        edk::float32 seconds;
        edk::watch::Time time;
    private:
        //object names
        edk::uint32 names;

        edk::Cenario2D::ObjClass* getObjClass(edk::Object2D* obj){
            edk::Cenario2D::ObjClass find(false,obj,0.f);edkEnd();
            return this->treeObj.getElement(&find);
        }
        edk::Cenario2D::ObjClass* getObjClassFromDepth(edk::float64 depth){
            edk::Cenario2D::ObjClass find(false,NULL,depth);edkEnd();
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

    class QuadObjs : public edk::vector::QuadTree32<edk::Cenario2D::ObjClass*>{
    public:
        QuadObjs(edk::vector::BinaryTree<edk::Cenario2DCallback*>* calls){
            this->levelId=0u;edkEnd();this->calls=calls;edkEnd();
        }
        ~QuadObjs(){}
        edk::uint32 levelId;
    protected:
        //test if the object is inside the leaf
        virtual bool isElementInside(edk::Cenario2D::ObjClass* obj,edk::vec2f32 point1,edk::vec2f32 point2){
            edk::rectf32 box = obj->getBoundingBox();edkEnd();
            if(box.origin.x >= point1.x
                    &&
                    box.origin.y >= point1.y
                    &&
                    box.origin.x <= point2.x
                    &&
                    box.origin.y <= point2.y
                    &&
                    box.size.width >= point1.x
                    &&
                    box.size.height >= point1.y
                    &&
                    box.size.width <= point2.x
                    &&
                    box.size.height <= point2.y
                    ){
                return true;
            }
            return false;
        }
        virtual bool isElementColliding(edk::Cenario2D::ObjClass* obj,edk::vec2f32 point1,edk::vec2f32 point2){
            edk::rectf32 box = obj->getBoundingBox();edkEnd();
            if(point1.x <= box.size.width
                    &&
                    point2.x>= box.origin.x
                    &&
                    point1.y <= box.size.height
                    &&
                    point2.y >= box.origin.y
                    ){
                return true;
            }
            return false;
        }
        //function to create a new tree
        virtual edk::vector::BinaryTree<edk::Cenario2D::ObjClass*>* newTree(){
            return (edk::vector::BinaryTree<edk::Cenario2D::ObjClass*>*)new edk::Cenario2D::TreeObjDepth;edkEnd();
        }
        virtual void elementGetIn(edk::Cenario2D::ObjClass* obj){
            //elementGetIn
            if(obj->getObject()){
                edk::uint32 size = this->calls->size();edkEnd();
                edk::Cenario2DCallback* call;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    call = this->calls->getElementInPosition(i);edkEnd();
                    call->objectGetIn(obj->getObject(),this->levelId);edkEnd();
                }
            }
        }
        virtual void elementUpdating(edk::Cenario2D::ObjClass* obj){
            //elementUpdating
            if(obj->getObject()){
                edk::uint32 size = this->calls->size();edkEnd();
                edk::Cenario2DCallback* call;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    call = this->calls->getElementInPosition(i);edkEnd();
                    call->objectUpdating(obj->getObject(),this->levelId);edkEnd();
                }
            }
        }
        virtual void elementGetOut(edk::Cenario2D::ObjClass* obj){
            //elementGetOut
            if(obj->getObject()){
                edk::uint32 size = this->calls->size();edkEnd();
                edk::Cenario2DCallback* call;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    call = this->calls->getElementInPosition(i);edkEnd();
                    call->objectGetOut(obj->getObject(),this->levelId);edkEnd();
                }
            }
        }
        //callback tree
        edk::vector::BinaryTree<edk::Cenario2DCallback*>* calls;
    };

    //Physics group to animate and update
    class TreePhysObjDepth:public edk::Cenario2D::TreeObjDepth{
    public:
        TreePhysObjDepth(edk::physics2D::World2D* world){
            this->world=world;edkEnd();
            this->seconds=0.f;edkEnd();
        }
        //UPDATE
        virtual void updateElement(edk::Cenario2D::ObjClass* value){
            edk::physics2D::PhysicObject2D* temp = (edk::physics2D::PhysicObject2D*)value->getObject();edkEnd();
            if(value->getObject()){
                if(value->getObject()->updateAnimations(this->seconds)){
                    //update the object in the physics world
                    this->world->updateObjectVelocity(temp);edkEnd();
                    value->animating=true;edkEnd();
                }
                else{
                    //test if was animating
                    if(value->animating){
                        //then test if is kinematic
                        if(temp->getType() == edk::physics::KinematicBody){
                            //clean the velocity
                            this->world->cleanObjectVelocity(temp);edkEnd();
                        }
                    }
                    value->animating=false;edkEnd();
                }
            }
        }
        virtual void callbackUpdateElement(edk::Cenario2D::ObjClass* value){
            this->updateElement(value);edkEnd();
        }
    private:
        edk::physics2D::World2D* world;
    };

    class QuadPhyicObjs : public edk::Cenario2D::QuadObjs{
    public:
        QuadPhyicObjs(edk::physics2D::World2D* world,edk::vector::BinaryTree<edk::Cenario2DCallback*>* calls)
            :edk::Cenario2D::QuadObjs(calls)
        {
            this->world=world;edkEnd();
        }
        ~QuadPhyicObjs(){}
    protected:
        //function to create a new tree
        virtual edk::vector::BinaryTree<edk::Cenario2D::ObjClass*>* newTree(){
            return (edk::vector::BinaryTree<edk::Cenario2D::ObjClass*>*)new edk::Cenario2D::TreePhysObjDepth(this->world);edkEnd();
        }
        virtual void elementGetIn(edk::Cenario2D::ObjClass* obj){
            //elementGetIn
            if(obj->getObject()){
                edk::uint32 size = this->calls->size();edkEnd();
                edk::Cenario2DCallback* call;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    call = this->calls->getElementInPosition(i);edkEnd();
                    call->physicObjectGetIn((edk::physics2D::PhysicObject2D*)obj->getObject(),this->levelId);edkEnd();
                }
            }
        }
        virtual void elementUpdating(edk::Cenario2D::ObjClass* obj){
            //elementUpdating
            if(obj->getObject()){
                edk::uint32 size = this->calls->size();edkEnd();
                edk::Cenario2DCallback* call;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    call = this->calls->getElementInPosition(i);edkEnd();
                    call->physicObjectUpdating((edk::physics2D::PhysicObject2D*)obj->getObject(),this->levelId);edkEnd();
                }
            }
        }
        virtual void elementGetOut(edk::Cenario2D::ObjClass* obj){
            //elementGetOut
            if(obj->getObject()){
                edk::uint32 size = this->calls->size();edkEnd();
                edk::Cenario2DCallback* call;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    call = this->calls->getElementInPosition(i);edkEnd();
                    call->physicObjectGetOut((edk::physics2D::PhysicObject2D*)obj->getObject(),this->levelId);edkEnd();
                }
            }
        }
    private:
        edk::physics2D::World2D* world;
    };

    //Save objects in a Level
    class LevelObj{
    public:
        LevelObj(edk::Cenario2D::TreeObjDepth* objs,edk::Cenario2D::TreePhysObjDepth* objsPhys,edk::vector::BinaryTree<edk::Cenario2DCallback*>* calls){
            this->clean();edkEnd();
            this->calls = calls;edkEnd();
            this->objs = objs;edkEnd();
            this->objsPhys = objsPhys;edkEnd();
            this->show=true;edkEnd();
            this->transform.position = 0.f;edkEnd();
            this->transform.angle = 0.f;edkEnd();
            this->transform.size = 1.f;edkEnd();
            this->saveTransform=this->transform;edkEnd();
            this->matrixNewPosition.createMatrix(1u,3u);edkEnd();
            this->matrixTransform.setIdentity(1.f,0.f);edkEnd();
            this->matrixTransformNegative.setIdentity(1.f,0.f);edkEnd();
        }
        LevelObj(edk::tiles::TileMap2D* tileMap,edk::vector::BinaryTree<edk::Cenario2DCallback*>* calls){
            this->clean();edkEnd();
            this->calls = calls;edkEnd();
            this->tileMap = tileMap;edkEnd();this->show=true;edkEnd();
            this->transform.position = 0.f;edkEnd();
            this->transform.angle = 0.f;edkEnd();
            this->transform.size = 1.f;edkEnd();
            this->saveTransform=this->transform;edkEnd();
            this->matrixNewPosition.createMatrix(1u,3u);edkEnd();
            this->matrixTransform.setIdentity(1.f,0.f);edkEnd();
            this->matrixTransformNegative.setIdentity(1.f,0.f);edkEnd();
        }
        LevelObj(edk::vector::BinaryTree<edk::Cenario2DCallback*>* calls){
            this->clean();edkEnd();
            this->calls = calls;edkEnd();
            this->show=true;edkEnd();
            this->transform.position = 0.f;edkEnd();
            this->transform.angle = 0.f;edkEnd();
            this->transform.size = 1.f;edkEnd();
            this->saveTransform=this->transform;edkEnd();
            this->matrixNewPosition.createMatrix(1u,3u);edkEnd();
            this->matrixTransform.setIdentity(1.f,0.f);edkEnd();
            this->matrixTransformNegative.setIdentity(1.f,0.f);edkEnd();
        }
        ~LevelObj(){}

        //update the matrices if need
        inline void updateMatrices(){
            if(this->saveTransform!=this->transform){
                this->saveTransform=this->transform;edkEnd();
                this->calculateMatrices();edkEnd();
            }
        }

        //XML
        bool writeToXML(edk::XML* xml,edk::uint32 id);
        bool readFromXML(edk::XML* xml,edk::uint32 id,edk::tiles::TileSet2D* tileSet,edk::physics2D::World2D* world);
        bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id,edk::tiles::TileSet2D* tileSet,edk::physics2D::World2D* world);

        void updateQuads(edk::rectf32 rect,edk::uint32 levelID){
            if(this->objs){
                rect = this->updateRect(rect);edkEnd();
                this->quadObjs->levelId = levelID;edkEnd();
                this->quadObjs->selectLeafInRect(rect);edkEnd();
            }
            else if(this->objsPhys){
                rect = this->updateRect(rect);edkEnd();
                this->quadPhysicObjs->levelId = levelID;edkEnd();
                this->quadPhysicObjs->selectLeafInRect(rect);edkEnd();
            }
        }
        void draw(){
            if(this->show){
                if(this->objs){
                    edk::GU::guEnable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->objs->cleanNames();edkEnd();
                    this->objs->draw();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                }
                else if(this->objsPhys){
                    edk::GU::guEnable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->objsPhys->cleanNames();edkEnd();
                    this->objsPhys->draw();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                }
                else if(this->tileMap){
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->tileMap->draw();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                }
            }
        }
        void drawWire(){
            if(this->show){
                if(this->objs){
                    edk::GU::guEnable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->objs->cleanNames();edkEnd();
                    this->objs->drawWire();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                }
                else if(this->objsPhys){
                    edk::GU::guEnable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->objsPhys->cleanNames();edkEnd();
                    this->objsPhys->drawWire();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                }
                else if(this->tileMap){
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->tileMap->drawWire();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                }
            }
        }
        void drawQuads(){
            if(this->show){
                if(this->quadObjs){
                    edk::GU::guEnable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->quadObjs->drawQuads();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                }
                else if(this->quadPhysicObjs){
                    edk::GU::guEnable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->quadPhysicObjs->drawQuads();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                }
                else if(this->tileMap){
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->tileMap->drawWire();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                }
            }
        }
        void drawBoxes(){
            if(this->show){
                if(this->objs){
                    edk::GU::guEnable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    edk::GU::guBegin(GU_LINES);edkEnd();
                    this->objs->renderWire();edkEnd();
                    edk::GU::guEnd();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                }
                else if(this->objsPhys){
                    edk::GU::guEnable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    edk::GU::guBegin(GU_LINES);edkEnd();
                    this->objsPhys->renderWire();edkEnd();
                    edk::GU::guEnd();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                }
                else if(this->tileMap){
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->tileMap->drawWire();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                }
            }
        }
        void drawInsideRect(edk::rectf32 rect,edk::uint32 levelID){
            if(this->show){
                if(this->objs){
                    rect = this->updateRect(rect);edkEnd();
                    this->quadObjs->levelId = levelID;edkEnd();
                    if(this->quadObjs->selectLeafInRect(rect)){
                        edk::GU::guEnable(GU_LIGHTING);edkEnd();
                        //apply tranformations
                        edk::GU::guPushMatrix();edkEnd();
                        //add translate
                        edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                        //add rotation
                        edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                        //add scale
                        edk::GU::guScale2f32(this->transform.size);edkEnd();
                        edk::Cenario2D::TreeObjDepth* temp = (edk::Cenario2D::TreeObjDepth*)this->quadObjs->selectedGetTreePointer();edkEnd();
                        temp->cleanNames();edkEnd();
                        temp->draw();edkEnd();
                        edk::GU::guPopMatrix();edkEnd();
                        edk::GU::guDisable(GU_LIGHTING);edkEnd();
                    }
                }
                else if(this->objsPhys){
                    rect = this->updateRect(rect);edkEnd();
                    this->quadPhysicObjs->levelId = levelID;edkEnd();
                    if(this->quadPhysicObjs->selectLeafInRect(rect)){
                        edk::GU::guEnable(GU_LIGHTING);edkEnd();
                        //apply tranformations
                        edk::GU::guPushMatrix();edkEnd();
                        //add translate
                        edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                        //add rotation
                        edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                        //add scale
                        edk::GU::guScale2f32(this->transform.size);edkEnd();
                        edk::Cenario2D::TreePhysObjDepth* temp = (edk::Cenario2D::TreePhysObjDepth*)this->quadPhysicObjs->selectedGetTreePointer();edkEnd();
                        temp->cleanNames();edkEnd();
                        temp->draw();edkEnd();
                        edk::GU::guPopMatrix();edkEnd();
                        edk::GU::guDisable(GU_LIGHTING);edkEnd();
                    }
                }
                else if(this->tileMap){
                    rect = this->updateRect(rect);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->tileMap->drawInsideWorldRect(rect);edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                }
            }
        }
        void drawWireInsideRect(edk::rectf32 rect,edk::uint32 levelID){
            if(this->show){
                if(this->objs){
                    rect = this->updateRect(rect);edkEnd();
                    this->quadObjs->levelId = levelID;edkEnd();
                    if(this->quadObjs->selectLeafInRect(rect)){
                        edk::GU::guEnable(GU_LIGHTING);edkEnd();
                        //apply tranformations
                        edk::GU::guPushMatrix();edkEnd();
                        //add translate
                        edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                        //add rotation
                        edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                        //add scale
                        edk::GU::guScale2f32(this->transform.size);edkEnd();
                        edk::Cenario2D::TreeObjDepth* temp = (edk::Cenario2D::TreeObjDepth*)this->quadObjs->selectedGetTreePointer();edkEnd();
                        temp->cleanNames();edkEnd();
                        temp->drawWire();edkEnd();
                        edk::GU::guPopMatrix();edkEnd();
                        edk::GU::guDisable(GU_LIGHTING);edkEnd();
                    }
                }
                else if(this->objsPhys){
                    rect = this->updateRect(rect);edkEnd();
                    this->quadPhysicObjs->levelId = levelID;edkEnd();
                    if(this->quadPhysicObjs->selectLeafInRect(rect)){
                        edk::GU::guEnable(GU_LIGHTING);edkEnd();
                        //apply tranformations
                        edk::GU::guPushMatrix();edkEnd();
                        //add translate
                        edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                        //add rotation
                        edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                        //add scale
                        edk::GU::guScale2f32(this->transform.size);edkEnd();
                        edk::Cenario2D::TreePhysObjDepth* temp = (edk::Cenario2D::TreePhysObjDepth*)this->quadPhysicObjs->selectedGetTreePointer();edkEnd();
                        temp->cleanNames();edkEnd();
                        temp->drawWire();edkEnd();
                        edk::GU::guPopMatrix();edkEnd();
                        edk::GU::guDisable(GU_LIGHTING);edkEnd();
                    }
                }
                else if(this->tileMap){
                    rect = this->updateRect(rect);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->tileMap->drawWireInsideWorldRect(rect);edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                }
            }
        }
        void drawSelection(edk::uint8 id=0u){
            if(this->show){
                if(this->objs){
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->objs->selectionID = id;edkEnd();
                    this->objs->print();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                }
                else if(this->objsPhys){
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->objsPhys->selectionID = id;edkEnd();
                    this->objsPhys->print();edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                }
                else if(this->tileMap){
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->tileMap->drawSelectionWithID(id);edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                }
            }
        }
        void drawSelectionInsideRect(edk::rectf32 rect,edk::uint32 levelID){
            if(this->show){
                if(this->objs){
                    rect = this->updateRect(rect);edkEnd();
                    this->quadObjs->levelId = levelID;edkEnd();
                    if(this->quadObjs->selectLeafInRect(rect)){
                        edk::GU::guDisable(GU_LIGHTING);edkEnd();
                        //apply tranformations
                        edk::GU::guPushMatrix();edkEnd();
                        //add translate
                        edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                        //add rotation
                        edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                        //add scale
                        edk::GU::guScale2f32(this->transform.size);edkEnd();
                        edk::Cenario2D::TreeObjDepth* temp = (edk::Cenario2D::TreeObjDepth*)this->quadObjs->selectedGetTreePointer();edkEnd();
                        temp->selectionID = levelID;edkEnd();
                        temp->print();edkEnd();
                        edk::GU::guPopMatrix();edkEnd();
                    }
                }
                else if(this->objsPhys){
                    rect = this->updateRect(rect);edkEnd();
                    this->quadPhysicObjs->levelId = levelID;edkEnd();
                    if(this->quadPhysicObjs->selectLeafInRect(rect)){
                        edk::GU::guDisable(GU_LIGHTING);edkEnd();
                        //apply tranformations
                        edk::GU::guPushMatrix();edkEnd();
                        //add translate
                        edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                        //add rotation
                        edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                        //add scale
                        edk::GU::guScale2f32(this->transform.size);edkEnd();
                        edk::Cenario2D::TreePhysObjDepth* temp = (edk::Cenario2D::TreePhysObjDepth*)this->quadPhysicObjs->selectedGetTreePointer();edkEnd();
                        temp->selectionID = levelID;edkEnd();
                        temp->print();edkEnd();
                        edk::GU::guPopMatrix();edkEnd();
                    }
                }
                else if(this->tileMap){
                    rect = this->updateRect(rect);edkEnd();
                    edk::GU::guDisable(GU_LIGHTING);edkEnd();
                    //apply tranformations
                    edk::GU::guPushMatrix();edkEnd();
                    //add translate
                    edk::GU::guTranslate2f32(this->transform.position);edkEnd();
                    //add rotation
                    edk::GU::guRotateZf32(this->transform.angle);edkEnd();
                    //add scale
                    edk::GU::guScale2f32(this->transform.size);edkEnd();
                    this->tileMap->drawInsideWorldRectSelectionWithID(rect,levelID);edkEnd();
                    edk::GU::guPopMatrix();edkEnd();
                }
            }
        }

        void clean(){this->objs = NULL;edkEnd();this->objsPhys = NULL;edkEnd();this->tileMap = NULL;edkEnd();this->quadObjs = NULL;edkEnd();this->quadPhysicObjs = NULL;edkEnd();}
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

        //update the rect with the matrices
        inline edk::rectf32 updateRect(edk::rectf32 rect){
            this->updateMatrices();edkEnd();
            if(this->matrixNewPosition.haveMatrix()){
                edk::vec2f32 newPosition;edkEnd();
                //
                this->matrixNewPosition.set(0u,0u,rect.origin.x);edkEnd();
                this->matrixNewPosition.set(0u,1u,rect.origin.y);edkEnd();
                this->matrixNewPosition.set(0u,2u,1.f);edkEnd();
                this->matrixNewPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransformNegative);edkEnd();
                newPosition.x = this->matrixNewPosition.get(0u,0u);edkEnd();
                newPosition.y = this->matrixNewPosition.get(0u,1u);edkEnd();
                if(rect.origin.x > newPosition.x){
                    rect.origin.x = newPosition.x;edkEnd();
                }
                if(rect.origin.y > newPosition.y){
                    rect.origin.y = newPosition.y;edkEnd();
                }
                //
                this->matrixNewPosition.set(0u,0u,rect.size.width);edkEnd();
                this->matrixNewPosition.set(0u,1u,rect.size.height);edkEnd();
                this->matrixNewPosition.set(0u,2u,1.f);edkEnd();
                this->matrixNewPosition.multiplyMatrixWithThis((edk::vector::MatrixDynamic<edk::float32>*)&this->matrixTransformNegative);edkEnd();
                newPosition.x = this->matrixNewPosition.get(0u,0u);edkEnd();
                newPosition.y = this->matrixNewPosition.get(0u,1u);edkEnd();
                if(rect.size.width > newPosition.x){
                    rect.size.width = newPosition.x;edkEnd();
                }
                if(rect.size.height > newPosition.y){
                    rect.size.height = newPosition.y;edkEnd();
                }
                return rect;edkEnd();
            }
            return rect;edkEnd();
        }

        //calculate matrices
        void calculateMatrices(){
            //generate transform matrices
            edk::Math::generateTranslateMatrix(this->transform.position,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrix(this->transform.angle,&this->matrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->transform.size,&this->matrixSize);edkEnd();

            this->matrixTransform.setIdentity(1.f,0.f);edkEnd();
            //multiply the matrix by
            //translate
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
            //scale
            this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);edkEnd();

            //generate negative transform matrices
            edk::Math::generateTranslateMatrix(this->transform.position*-1.f,&this->matrixPosition);edkEnd();
            edk::Math::generateRotateMatrix(this->transform.angle*-1.f,&this->matrixAngle);edkEnd();
            edk::Math::generateScaleMatrix(this->transform.size/1.f,&this->matrixSize);edkEnd();

            this->matrixTransformNegative.setIdentity(1.f,0.f);edkEnd();
            //multiply the matrix by
            //translate
            this->matrixTransformNegative.multiplyThisWithMatrix(&this->matrixPosition);edkEnd();
            //angle
            this->matrixTransformNegative.multiplyThisWithMatrix(&this->matrixAngle);edkEnd();
            //scale
            this->matrixTransformNegative.multiplyThisWithMatrix(&this->matrixSize);edkEnd();
        }

        //generate the level rectangle
        bool generateLevelRect(){
            if(this->objs){
                this->calculateMatrices();edkEnd();
                edk::uint32 size = this->objs->size();edkEnd();
                edk::Cenario2D::ObjClass* temp;edkEnd();
                edk::rectf32 rect,rectTemp;edkEnd();
                rect = 0.f;edkEnd();
                if(size){
                    edk::uint32 i=0u;edkEnd();
                    //get the first rectagle
                    for(;i<size;i++){
                        temp=this->objs->getElementInPosition(i);edkEnd();
                        if(temp){
                            rectTemp = temp->calculateBoundingBox();edkEnd();
                            rect=rectTemp;edkEnd();
                            i++;edkEnd();
                            break;
                        }
                    }
                    //get the other rectagles
                    for(;i<size;i++){
                        temp=this->objs->getElementInPosition(i);edkEnd();
                        if(temp){
                            rectTemp = temp->calculateBoundingBox();edkEnd();
                            if(rect.origin.x > rectTemp.origin.x){
                                rect.origin.x = rectTemp.origin.x;edkEnd();
                            }
                            if(rect.origin.y > rectTemp.origin.y){
                                rect.origin.y = rectTemp.origin.y;edkEnd();
                            }
                            if(rect.size.width < rectTemp.size.width){
                                rect.size.width = rectTemp.size.width;edkEnd();
                            }
                            if(rect.size.height < rectTemp.size.height){
                                rect.size.height = rectTemp.size.height;edkEnd();
                            }
                        }
                    }
                    //in the end set the level rectangle
                    //increment the rect
                    rect.origin.x -= (rect.size.width - rect.origin.x)*0.1f;edkEnd();
                    rect.origin.y -= (rect.size.height - rect.origin.y)*0.1f;edkEnd();
                    rect.size.width += (rect.size.width - rect.origin.x)*0.1f;edkEnd();
                    rect.size.height += (rect.size.height - rect.origin.y)*0.1f;edkEnd();
                    this->quadObjs->setRect(rect);edkEnd();
                }
                return true;
            }
            else if(this->objsPhys){
                this->calculateMatrices();edkEnd();
                edk::uint32 size = this->objsPhys->size();edkEnd();
                edk::Cenario2D::ObjClass* temp;edkEnd();
                edk::rectf32 rect,rectTemp;edkEnd();
                rect = 0.f;edkEnd();
                if(size){
                    edk::uint32 i=0u;edkEnd();
                    //get the first rectagle
                    for(;i<size;i++){
                        temp=this->objsPhys->getElementInPosition(i);edkEnd();
                        if(temp){
                            rectTemp = temp->calculateBoundingBox();edkEnd();
                            rect=rectTemp;edkEnd();
                            i++;edkEnd();
                            break;
                        }
                    }
                    //get the other rectagles
                    for(;i<size;i++){
                        temp=this->objsPhys->getElementInPosition(i);edkEnd();
                        if(temp){
                            rectTemp = temp->calculateBoundingBox();edkEnd();
                            if(rect.origin.x > rectTemp.origin.x){
                                rect.origin.x = rectTemp.origin.x;edkEnd();
                            }
                            if(rect.origin.y > rectTemp.origin.y){
                                rect.origin.y = rectTemp.origin.y;edkEnd();
                            }
                            if(rect.size.width < rectTemp.size.width){
                                rect.size.width = rectTemp.size.width;edkEnd();
                            }
                            if(rect.size.height < rectTemp.size.height){
                                rect.size.height = rectTemp.size.height;edkEnd();
                            }
                        }
                    }
                    //in the end set the level rectangle
                    //increment the rect
                    rect.origin.x -= (rect.size.width - rect.origin.x)*0.1f;edkEnd();
                    rect.origin.y -= (rect.size.height - rect.origin.y)*0.1f;edkEnd();
                    rect.size.width += (rect.size.width - rect.origin.x)*0.1f;edkEnd();
                    rect.size.height += (rect.size.height - rect.origin.y)*0.1f;edkEnd();
                    this->quadPhysicObjs->setRect(rect);edkEnd();
                }
                return true;
            }
            return false;
        }

        //add the objects into the quadtrees
        bool addObjectsToQuad(){
            //test if have the objects
            if(this->objs){
                //this->calculateMatrices();edkEnd();
                edk::uint32 size = this->objs->size();edkEnd();
                edk::Cenario2D::ObjClass* temp;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    temp=this->objs->getElementInPosition(i);edkEnd();
                    if(temp){
                        //add the temp into quad
                        this->quadObjs->add(temp,size);edkEnd();
                    }
                }
                return true;
            }
            else if(this->objsPhys){
                //this->calculateMatrices();edkEnd();
                edk::uint32 size = this->objsPhys->size();edkEnd();
                edk::Cenario2D::ObjClass* temp;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    temp=this->objsPhys->getElementInPosition(i);edkEnd();
                    if(temp){
                        //add the temp into quad
                        this->quadPhysicObjs->add(temp,size);edkEnd();
                    }
                }
                return true;
            }
            return false;
        }

        edk::Cenario2D::TreeObjDepth* objs;
        edk::Cenario2D::TreePhysObjDepth* objsPhys;
        edk::tiles::TileMap2D* tileMap;
        //add a transformation in to the level
        edk::Object2DValues transform;
        edk::Object2DValues saveTransform;
        //quadtree used for objects and physics objects
        edk::Cenario2D::QuadObjs* quadObjs;
        edk::Cenario2D::QuadPhyicObjs* quadPhysicObjs;
        //matrices used to generate the bounding box of the object
        edk::vector::Matrix<edk::float32,3u,3u> matrixPosition;
        edk::vector::Matrix<edk::float32,3u,3u> matrixAngle;
        edk::vector::Matrix<edk::float32,3u,3u> matrixSize;
        edk::vector::Matrix<edk::float32,3,3> matrixTransform;
        edk::vector::Matrix<edk::float32,3,3> matrixTransformNegative;
        edk::vector::MatrixDynamic<edk::float32> matrixNewPosition;
        bool show;
    private:
        edk::vector::BinaryTree<edk::Cenario2DCallback*>* calls;
    };

    //objects animation tree
    class TreeAnim: public edk::vector::BinaryTree<edk::Object2D*>{
    public:
        TreeAnim(){this->seconds=0.f;edkEnd();this->time.start();edkEnd();}
        ~TreeAnim(){this->seconds=0.f;edkEnd();}
        //SET
        bool setSeconds(edk::float32 seconds){
            if(seconds>0.f){
                this->seconds=seconds;edkEnd();
                return true;
            }
            else{
                this->seconds=0.f;edkEnd();
            }
            return false;
        }
        bool loadSeconds(){
            bool ret = this->setSeconds(this->time.getSeconds());edkEnd();
            this->time.start();edkEnd();
            return ret;
        }
        //UPDATE
        virtual void updateElement(edk::Object2D* value){
            //update the value
            value->updateAnimations(this->seconds);edkEnd();
        }
    private:
        edk::float32 seconds;
        edk::watch::Time time;
    }treeAnim;

    //objects animation tree
    class TreeAnimPhys: public edk::vector::BinaryTree<edk::physics2D::PhysicObject2D*>{
    public:
        TreeAnimPhys(edk::physics2D::World2D* world){
            if(world){
                this->world = world;edkEnd();
            }
            else{
                this->world = &edk::Cenario2D::worldTemplate;edkEnd();
            }
            this->seconds=0.f;edkEnd();
            this->time.start();edkEnd();
        }
        ~TreeAnimPhys(){}
        //SET
        bool setSeconds(edk::float32 seconds){
            if(seconds>0.f){
                this->seconds=seconds;edkEnd();
                return true;
            }
            else{
                this->seconds=0.f;edkEnd();
            }
            return false;
        }
        bool loadSeconds(){
            bool ret = this->setSeconds(this->time.getSeconds());edkEnd();
            this->time.start();edkEnd();
            return ret;
        }
        //UPDATE
        virtual void updateElement(edk::physics2D::PhysicObject2D* value){
            //update the value
            value->updateAnimations(this->seconds);edkEnd();
            this->world->updateObjectLinearVelocity(value);edkEnd();
        }
    private:
        edk::physics2D::World2D* world;
        edk::float32 seconds;
        edk::watch::Time time;
    }treeAnimPhys;

    edk::vector::Stack<edk::Cenario2D::LevelObj*> levels;
};
}//end namespace edk

#endif // CENARIO2D_H
