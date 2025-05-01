#ifndef TILEMAP2D_H
#define TILEMAP2D_H

/*
Library TileMap2D - Use 2D Tiles from TileSet as a TileMap in EDK Game Engine
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
#pragma message "Inside TileMap2D"
#endif

#pragma once
//Include a tileSet
#include "TileSet2D.h"
#include "../vector/Array.h"
#include "../vector/BinaryTree.h"
#include "../vector/Stack.h"
#include "../physics2D/World2D.h"
#include "../BinaryConverter.h"

#ifdef printMessages
#pragma message "    Compiling TileMap2D"
#endif

namespace edk{
namespace tiles{
class tileContact2D{
public:
    tileContact2D();
    virtual ~tileContact2D();

    void Constructor();
    void Destructor();

    edk::uint32 tileA;
    edk::uint32 tileB;
    edk::vec2ui32 positionA;
    edk::vec2ui32 positionB;
private:
    edk::classID classThis;
};
class tileCallback{
public:
    tileCallback(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~tileCallback(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
    }

    virtual void contact2DTileBegin(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){
        if(contact){
            tiles.tileA++;
        }
    }
    virtual void contact2DTileEnd(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){
        if(contact){
            tiles.tileA++;
        }
    }
    virtual void contact2DTileKeepBegin(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){
        if(contact){
            tiles.tileA++;
        }
    }
    virtual void contact2DTileKeepEnd(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){
        if(contact){
            tiles.tileA++;
        }
    }
    //contact sensors
    virtual void sensor2DTileBegin(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){
        if(contact){
            tiles.tileA++;
        }
    }
    virtual void sensor2DTileEnd(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){
        if(contact){
            tiles.tileA++;
        }
    }
    virtual void sensor2DTileKeeping(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){
        if(contact){
            tiles.tileA++;
        }
    }
private:
    edk::classID classThis;
};

class TileMap2D : public edk::physics2D::ContactCallback2D{
public:
    //set the tileSet to use on the tileMap
    TileMap2D();
    TileMap2D(edk::tiles::TileSet2D* tileSet);
    virtual ~TileMap2D();

    void Constructor();
    void Constructor(edk::tiles::TileSet2D* tileSet);
    void Destructor();

    //set the tileSet
    bool setTileSet(edk::tiles::TileSet2D* tileSet);
    edk::tiles::TileSet2D* getTileSet();
    void removeTileSet();
    //set a tile in the tileMap
    bool setTile(edk::uint32 tileID,edk::vec2ui32 position);
    bool setTile(edk::uint32 tileID,edk::uint32 positionX,edk::uint32 positionY);
    bool setTile(edk::uint32 tileID,edk::uint32 position);
    //set a color in the colorMap
    bool setTileColor(edk::color4f32 color,edk::vec2ui32 position);
    bool setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::vec2ui32 position);
    bool setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::vec2ui32 position);
    bool setTileColor(edk::color4f32 color,edk::uint32 positionX,edk::uint32 positionY);
    bool setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::uint32 positionX,edk::uint32 positionY);
    bool setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::uint32 positionX,edk::uint32 positionY);
    bool setTileColor(edk::color4f32 color,edk::uint32 position);
    bool setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::uint32 position);
    bool setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::uint32 position);
    //set the color of all tiles
    void setColor(edk::color4f32 color);
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b);
    void setAlpha(edk::float32 a);
    //set the tileMap position
    void setPosition(edk::vec2f32 position);
    void setPosition(edk::float32 positionX,edk::float32 positionY);
    edk::vec2f32 getTileWorldPosition(edk::vec2ui32 position);
    edk::vec2f32 getTileWorldPosition(edk::uint32 positionX,edk::uint32 positionY);
    //Set scale the map
    bool setScaleMap(edk::size2f32 scale);
    bool setScaleMap(edk::float32 width,edk::float32 height );
    //Set World pointer
    bool setWorld(edk::physics2D::World2D* world);
    void cleanWorldPointer();
    //cleanTiles
    void cleanTiles();
    //Create a new tileMap
    bool newTileMap(edk::size2ui32 size);
    bool newTileMap(edk::uint32 width,edk::uint32 heigth);
    //delete tileMap
    void deleteTileMap();
    //return true if have a tileMap
    bool haveTileMap();
    //delete physicObjects
    void deletePhysicsTiles();
    bool deletePhysicTile(edk::vec2ui32 position);
    bool deletePhysicTile(edk::uint32 positionX,edk::uint32 positionY);
    //add physics tiles
    bool loadPhysicsTiles();
    bool loadPhysicTile(edk::vec2ui32 position);
    bool loadPhysicTile(edk::uint32 positionX,edk::uint32 positionY);
    //load static physics tiles merged to generate boxes
    bool loadPhysicsTilesStaticMerged();
    //load dynamic and kinematic into the world
    bool loadPhysicsTilesDynamic();
    bool loadPhysicsTilesKinematic();
    bool loadPhysicsTilesKinematicAndDynamic();
    //return the physicTileObject
    edk::physics2D::PhysicObject2D* getPhysicTile(edk::vec2ui32 position);
    edk::physics2D::PhysicObject2D* getPhysicTile(edk::uint32 positionX,edk::uint32 positionY);
    //test ih have the physicsObject
    bool havePhysicObject(edk::physics2D::PhysicObject2D* object);
    edk::vec2ui32 getPhysicObjectPosition(edk::physics2D::PhysicObject2D* object);

    //GETTERS
    //return the tileID
    edk::uint32 getTileID(edk::vec2ui32 position);
    edk::uint32 getTileID(edk::uint32 positionX,edk::uint32 positionY);
    edk::uint32 getTileID(edk::uint32 position);
    //return the tileColor
    edk::color4f32 getTileColor(edk::vec2ui32 position);
    edk::color4f32 getTileColor(edk::uint32 positionX,edk::uint32 positionY);
    edk::color4f32 getTileColor(edk::uint32 position);
    //return the size of the map
    edk::size2ui32 getMapSize();
    //return the scale of the map
    edk::size2f32 getScaleMap();
    //return the position
    edk::vec2f32 getPosition();
    edk::float32 getPositionX();
    edk::float32 getPositionY();
    //get the tile position in the position
    edk::vec2ui32 getPointPosition(edk::vec2f32 point,bool* inside=NULL);

    //Draw the tileMap
    void draw(edk::color4f32 color);
    void draw(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color);
    void drawWithoutMaterial(edk::color4f32 color);
    void drawWithoutMaterial(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color);
    void drawInsideWorldRect(edk::rectf32 rect,edk::color4f32 color);
    void drawInsideWorldRectPoints(edk::rectf32 rect,edk::color4f32 color);
    void drawIsometric(edk::color4f32 color);
    void drawIsometric(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color);
    void drawIsometricInsideWorldRect(edk::rectf32 rect,edk::color4f32 color);
    void drawIsometricInsideWorldRectPoints(edk::rectf32 rect,edk::color4f32 color);
    //Draw tileMap without passing a color
    void draw();
    void draw(edk::vec2ui32 origin,edk::size2ui32 last);
    void drawWithoutMaterial();
    void drawWithoutMaterial(edk::vec2ui32 origin,edk::size2ui32 last);
    void drawInsideWorldRect(edk::rectf32 rect);
    void drawInsideWorldRectPoints(edk::rectf32 rect);
    void drawIsometric();
    void drawIsometric(edk::vec2ui32 origin,edk::size2ui32 last);
    void drawIsometricInsideWorldRect(edk::rectf32 rect);
    void drawIsometricInsideWorldRectPoints(edk::rectf32 rect);
    //draw wireTiles
    void drawWire(edk::color4f32 color);
    void drawWire(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color);
    void drawWireInsideWorldRect(edk::rectf32 rect,edk::color4f32 color);
    void drawWireInsideWorldRectPoints(edk::rectf32 rect,edk::color4f32 color);
    void drawIsometricWire(edk::color4f32 color);
    void drawIsometricWire(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color);
    void drawIsometricWireInsideWorldRect(edk::rectf32 rect,edk::color4f32 color);
    void drawIsometricWireInsideWorldRectPoints(edk::rectf32 rect,edk::color4f32 color);
    //draw wireTiles without passing a color
    void drawWire();
    void drawWire(edk::vec2ui32 origin,edk::size2ui32 last);
    void drawWireInsideWorldRect(edk::rectf32 rect);
    void drawWireInsideWorldRectPoints(edk::rectf32 rect);
    void drawIsometricWire();
    void drawIsometricWire(edk::vec2ui32 origin,edk::size2ui32 last);
    void drawIsometricWireInsideWorldRect(edk::rectf32 rect);
    void drawIsometricWireInsideWorldRectPoints(edk::rectf32 rect);
    //draw wireTiles
    void drawWirePhysics(edk::color4f32 color);
    void drawWirePhysics(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color);
    void drawWirePhysicsInsideWorldRect(edk::rectf32 rect,edk::color4f32 color);
    void drawWirePhysicsInsideWorldRectPoints(edk::rectf32 rect,edk::color4f32 color);
    //draw wireTiles without passing a color
    void drawWirePhysics();
    void drawWirePhysics(edk::vec2ui32 origin,edk::size2ui32 last);
    void drawWirePhysicsInsideWorldRect(edk::rectf32 rect);
    void drawWirePhysicsInsideWorldRectPoints(edk::rectf32 rect);
    //draw wireWitPhysics
    void drawWireWithPhysics(edk::color4f32 color=edk::color4f32(1,1,1,1),edk::color4f32 physColor=edk::color4f32(0,0,0,1));
    void drawWireWithPhysics(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color=edk::color4f32(1,1,1,1),edk::color4f32 physColor=edk::color4f32(0,0,0,1));
    void drawWireWithPhysicsInsideWorldRect(edk::rectf32 rect,edk::color4f32 color=edk::color4f32(1,1,1,1),edk::color4f32 physColor=edk::color4f32(0,0,0,1));
    void drawWireWithPhysicsInsideWorldRectPoints(edk::rectf32 rect,edk::color4f32 color=edk::color4f32(1,1,1,1),edk::color4f32 physColor=edk::color4f32(0,0,0,1));
    //draw one especific tile in wire
    bool drawTileWire(edk::vec2ui32 position,edk::color4f32 color);
    bool drawTileWire(edk::uint32 positionX,edk::uint32 positionY,edk::color4f32 color);
    bool drawTileWire(edk::uint32 position,edk::color4f32 color);
    //draw one especific tile in wire without passing a color
    bool drawTileWire(edk::vec2ui32 position);
    bool drawTileWire(edk::uint32 positionX,edk::uint32 positionY);
    bool drawTileWire(edk::uint32 position);
    //draw the tile for selection
    void drawSelectionWithID(edk::uint8 id=0u);
    void drawSelectionWithID(edk::vec2ui32 origin,edk::size2ui32 last,edk::uint8 id=0u);
    void drawSelection();
    void drawSelection(edk::vec2ui32 origin,edk::size2ui32 last);
    void drawInsideWorldRectSelectionWithID(edk::rectf32 rect,edk::uint8 id=0u);
    void drawInsideWorldRectPointsSelectionWithID(edk::rectf32 rect,edk::uint8 id=0u);
    void drawInsideWorldRectSelection(edk::rectf32 rect);
    void drawInsideWorldRectPointsSelection(edk::rectf32 rect);
    void drawIsometricSelectionWithID(edk::uint8 id=0u);
    void drawIsometricSelectionWithID(edk::vec2ui32 origin,edk::size2ui32 last,edk::uint8 id=0u);
    void drawIsometricSelection();
    void drawIsometricSelection(edk::vec2ui32 origin,edk::size2ui32 last);
    void drawIsometricInsideWorldRectSelectionWithID(edk::rectf32 rect,edk::uint8 id=0u);
    void drawIsometricInsideWorldRectPointsSelectionWithID(edk::rectf32 rect,edk::uint8 id=0u);
    void drawIsometricInsideWorldRectSelection(edk::rectf32 rect);
    void drawIsometricInsideWorldRectPointsSelection(edk::rectf32 rect);
    //draw the pivo
    void drawPivo(edk::float32 size,edk::color3f32 color);
    //print the tileMap ID's
    void print();

    void contact2DBegin(edk::physics2D::Contact2D* contact);
    void contact2DEnd(edk::physics2D::Contact2D* contact);
    void contact2DKeepBegin(edk::physics2D::Contact2D* contact);
    void contact2DKeepEnd(edk::physics2D::Contact2D* contact);
    //contact sensors
    void sensor2DBegin(edk::physics2D::Contact2D* contact);
    void sensor2DEnd(edk::physics2D::Contact2D* contact);
    void sensor2DKeeping(edk::physics2D::Contact2D* contact);

    //add tileDrawCallback
    bool addDrawCallback(edk::uint32 tileID,edk::tiles::DrawTile2DCallback* callback);
    bool addDrawCallback(edk::vec2ui32 position,edk::tiles::DrawTile2DCallback* callback);
    bool addDrawCallback(edk::uint32 positionX,edk::uint32 positionY,edk::tiles::DrawTile2DCallback* callback);
    bool removeDrawCallback(edk::uint32 tileID,edk::tiles::DrawTile2DCallback* callback);
    bool removeDrawCallback(edk::vec2ui32 position,edk::tiles::DrawTile2DCallback* callback);
    bool removeDrawCallback(edk::uint32 positionX,edk::uint32 positionY,edk::tiles::DrawTile2DCallback* callback);

    //XML
    bool writeToXML(edk::XML* xml,edk::uint32 id);
    bool readFromXML(edk::XML* xml,edk::uint32 id);
private:
    //tileSet
    edk::tiles::TileSet2D* tileSet;
    //World pointer
    edk::physics2D::World2D* world;

    //contact callback tree
    edk::vector::BinaryTree<edk::tiles::tileCallback*> treeCallbacks;

    //tileMap matrix
    edk::uint32** tileMap;
    //color matrix
    edk::color4f32** colorMap;
    //size of the tileMap
    edk::size2ui32 sizeMap;
    //scale the tileMap
    edk::size2f32 scaleMap;
    //position of the tileMap
    edk::vec2f32 positionMap;

    //save draw positions
    edk::vec2ui32 saveOrigin;
    edk::size2ui32 saveLast;

    //color of the tiles. When tiles was created it will receive this color
    edk::color4f32 color;

    //get the static object from tile with just one rectangle
    edk::physics2D::PhysicObject2D* getStaticTile(edk::vec2ui32 position);
    edk::physics2D::PhysicObject2D* getStaticTile(edk::uint32 positionX,edk::uint32 positionY);
    //compare two static objects
    bool compareStaticTile(edk::physics2D::PhysicObject2D* tile1,edk::physics2D::PhysicObject2D* tile2);
    //update draw tiles to calculate which tile will start to draw and end to draw
    void updateDrawTiles(edk::vec2ui32 origin,edk::size2ui32 last);
    //start and end the draw tiles
    void startDrawTiles(edk::vec2ui32 origin,edk::size2ui32 last);
    void endDrawTiles(edk::vec2ui32 origin,edk::size2ui32 last);

    //calculate the draw position from worldRect
    edk::rectui32 calculateDrawPositionFromRect(edk::rectf32 rect);
    edk::rectui32 calculateDrawPositionFromRectPoints(edk::rectf32 rect);

    //PhysicsTiles
    class PhysicsTiles{
    public:
        PhysicsTiles(edk::physics2D::PhysicObject2D* object){
            this->classThis=NULL;
            this->Constructor(object);
        }
        virtual ~PhysicsTiles(){
        }

        void Constructor(edk::physics2D::PhysicObject2D* object){
            if(this->classThis!=this){
                this->classThis=this;
                this->object=object;
                this->tile=0u;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
        }

        edk::vec2ui32 position;
        edk::physics2D::PhysicObject2D* object;
        edk::uint32 tile;
    private:
        edk::classID classThis;
    };
    //Physics Objects Tree
    class TreePhysicsTiles:public edk::vector::BinaryTree<edk::tiles::TileMap2D::PhysicsTiles*>{
    public:
        TreePhysicsTiles(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~TreePhysicsTiles(){
            this->Destructor();
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::tiles::TileMap2D::PhysicsTiles*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;

                this->treePosition.Constructor();
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->deleteAll();
                this->tileSet=NULL;
            }
            edk::vector::BinaryTree<edk::tiles::TileMap2D::PhysicsTiles*>::Destructor();
        }

        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::tiles::TileMap2D::PhysicsTiles* first,edk::tiles::TileMap2D::PhysicsTiles* second){
            if(first->object>second->object){
                return true;
            }
            return false;
        }
        virtual bool firstEqualSecond(edk::tiles::TileMap2D::PhysicsTiles* first,edk::tiles::TileMap2D::PhysicsTiles* second){
            if(first->object==second->object){
                return true;
            }
            return false;
        }
        //UPDATE
        virtual void renderElement(edk::tiles::TileMap2D::PhysicsTiles* value){
            if(this->tileSet && value){
                //update the value drawing the tile from tileSet
                if(value->object && value->tile){
                    //draw the tile in object position
                    this->tileSet->drawTile(value->tile,value->object->position,value->object->angle,value->object->size);
                }
            }
        }
        //create a new physics object
        edk::physics2D::PhysicObject2D* newObjectInPosition(edk::vec2ui32 position,edk::uint32 tile, edk::uint8 type,bool sensor){
            //test if don't have an object in the position
            edk::tiles::TileMap2D::PhysicsTiles* temp = this->getPhysicsTileInPosition(position);
            if(!temp){
                //create the new object
                edk::physics2D::PhysicObject2D* object = NULL;
                switch(type){
                case edk::TypeObject2DStatic:
                    if(sensor){
                        object = new edk::physics2D::StaticSensor2D;
                    }
                    else{
                        object = new edk::physics2D::StaticObject2D;
                    }
                    break;
                case edk::TypeObject2DKinematic:
                    if(sensor){
                        object = new edk::physics2D::KinematicSensor2D;
                    }
                    else{
                        object = new edk::physics2D::KinematicObject2D;
                    }
                    break;
                case edk::TypeObject2DDynamic:
                    object = new edk::physics2D::DynamicObject2D;
                    break;
                }
                if(object){
                    temp = new edk::tiles::TileMap2D::PhysicsTiles(object);
                    if(temp){
                        if(temp->object){
                            //set the position
                            temp->position=position;
                            temp->tile = tile;

                            //add to the position tree
                            if(this->treePosition.add(temp)){
                                //add to the tree
                                if(this->add(temp)){
                                    return temp->object;
                                }
                                this->treePosition.remove(temp);
                            }
                        }
                        delete temp;
                    }
                    delete object;
                }
            }
            return NULL;
        }
        //test if have the object
        bool haveObject(edk::physics2D::PhysicObject2D* object){
            if(object){
                edk::tiles::TileMap2D::PhysicsTiles find(object);
                return this->haveElement(&find);
            }
            return false;
        }
        bool havePosition(edk::vec2ui32 position){
            edk::tiles::TileMap2D::PhysicsTiles find(NULL);
            find.position=position;
            return this->treePosition.haveElement(&find);
        }
        //return the position object
        edk::vec2ui32 getPositionOfObject(edk::physics2D::PhysicObject2D* object){
            edk::vec2ui32 ret;
            edk::tiles::TileMap2D::PhysicsTiles* temp = this->getPhysicsTileObject(object);
            if(temp){
                //save the position
                ret = temp->position;
            }
            return ret;
        }
        //get object
        edk::physics2D::PhysicObject2D* getObjectInPosition(edk::vec2ui32 position){
            edk::tiles::TileMap2D::PhysicsTiles* temp = this->getPhysicsTileInPosition(position);
            if(temp){
                return temp->object;
            }
            return NULL;
        }
        edk::physics2D::PhysicObject2D* getObjectInPosition(edk::uint32 position){
            edk::tiles::TileMap2D::PhysicsTiles* temp = this->getElementInPosition(position);
            if(temp){
                return temp->object;
            }
            return NULL;
        }
        //delete object
        bool deleteObject(edk::physics2D::PhysicObject2D* object){
            //load the object
            return this->deletePhysicsTiles(this->getPhysicsTileObject(object));
        }
        //delete object in position
        bool deleteObjectInPosition(edk::vec2ui32 position){
            //load the object
            return this->deletePhysicsTiles(this->getPhysicsTileInPosition(position));
        }
        //delete all objects
        void deleteAll(){
            edk::tiles::TileMap2D::PhysicsTiles* temp = NULL;
            for(edk::uint32 i=0u;i<this->size();i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    //this->treePosition.remove(temp);
                    delete temp;
                }
            }
            this->clean();
            /*
            for(edk::uint32 i=0u;i<this->treePosition.size();i++){
                temp = this->treePosition.getElementInPosition(i);
                if(temp){
                    delete temp;
                }
            }
            */
            this->treePosition.clean();
        }
        //set tileSet
        bool setTileSet(edk::tiles::TileSet2D *tileSet){
            this->tileSet=tileSet;
            if(this->tileSet){

                return true;
            }
            return false;
        }
        edk::tiles::TileMap2D::PhysicsTiles* getPhysicsTileObject(edk::physics2D::PhysicObject2D* object){
            edk::tiles::TileMap2D::PhysicsTiles find(object);
            return this->getElement(&find);
        }
        //get PhysicsTiles
        edk::tiles::TileMap2D::PhysicsTiles* getPhysicsTileInPosition(edk::vec2ui32 position){
            edk::tiles::TileMap2D::PhysicsTiles find(NULL);
            find.position = position;
            return this->treePosition.getElement(&find);
        }
        //get physicsObject
        edk::physics2D::PhysicObject2D* getPhysicsObjectInPosition(edk::vec2ui32 position){
            edk::tiles::TileMap2D::PhysicsTiles* temp = getPhysicsTileInPosition(position);
            if(temp){
                return temp->object;
            }
            return NULL;
        }
        //return the ID in position
        edk::uint32 getIDInPosition(edk::vec2ui32 position){
            edk::tiles::TileMap2D::PhysicsTiles* temp = getPhysicsTileInPosition(position);
            if(temp){
                return temp->tile;
            }
            return 0u;
        }

    private:
        //tileSet
        edk::tiles::TileSet2D *tileSet;
        //delete physicsObject
        bool deletePhysicsTiles(edk::tiles::TileMap2D::PhysicsTiles* physicTiles){
            if(physicTiles){
                edk::tiles::TileMap2D::PhysicsTiles* temp = this->getElement(physicTiles);
                if(temp){
                    //remove from the trees
                    if(this->remove(temp)){
                        if(this->treePosition.remove(temp)){
                            delete temp;
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        //Physics Objects Position Tree
        class TreePhysicsPosition:public edk::vector::BinaryTree<edk::tiles::TileMap2D::PhysicsTiles*>{
        public:
            //compare if the value is bigger
            virtual bool firstBiggerSecond(edk::tiles::TileMap2D::PhysicsTiles* first,edk::tiles::TileMap2D::PhysicsTiles* second){
                if(first->position.x>second->position.x){
                    return true;
                }
                else if(first->position.x==second->position.x){
                    if(first->position.y>second->position.y){
                        return true;
                    }
                }
                return false;
            }
            virtual bool firstEqualSecond(edk::tiles::TileMap2D::PhysicsTiles* first,edk::tiles::TileMap2D::PhysicsTiles* second){
                if(first->position==second->position){
                    return true;
                }
                return false;
            }
        }treePosition;
    private:
        edk::classID classThis;
    }treePhysics;




    //StaticTileObjects
    class StaticTileObjects{
    public:
        StaticTileObjects(edk::physics2D::PhysicObject2D* object){
            this->classThis=NULL;
            this->Constructor(object);
        }
        virtual ~StaticTileObjects(){
            this->Destructor();
        }

        void Constructor(edk::physics2D::PhysicObject2D* object){
            if(this->classThis!=this){
                this->classThis=this;

                this->positions.Constructor();

                this->object=object;
                this->tile=0u;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->positions.clean();
            }
        }

        edk::physics2D::PhysicObject2D* object;
        edk::uint32 tile;

        //tree with the positions
        class TreePositions:public edk::vector::BinaryTree<edk::vec2ui32>{
        public:
            TreePositions(){
                this->classThis=NULL;
                this->Constructor();
            }
            virtual ~TreePositions(){
                this->Destructor();
            }

            void Constructor(){
                edk::vector::BinaryTree<edk::vec2ui32>::Constructor();
                if(this->classThis!=this){
                    this->classThis=this;
                }
            }
            void Destructor(){
                if(this->classThis==this){
                    this->classThis=NULL;
                    //can destruct the class
                }
                edk::vector::BinaryTree<edk::vec2ui32>::Destructor();
            }

            //compare if the value is bigger
            bool firstBiggerSecond(edk::vec2ui32 first,edk::vec2ui32 second){
                //
                if(first.x>second.x){
                    return true;
                }
                else if(first.x==second.x
                        &&
                        first.y>second.y
                        ){
                    return true;
                }
                return false;
            }
            //compare if the value is equal
            bool firstEqualSecond(edk::vec2ui32 first,edk::vec2ui32 second){
                //
                if(first.x==second.x
                        &&
                        first.y==second.y
                        ){
                    return true;
                }
                return false;
            }
        private:
            edk::classID classThis;
        }positions;
    private:
        edk::classID classThis;
    };
    //Physics Objects Tree
    class TreeStaticTileObjects:public edk::vector::BinaryTree<edk::tiles::TileMap2D::StaticTileObjects*>{
    public:
        TreeStaticTileObjects(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~TreeStaticTileObjects(){
            this->Destructor();
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::tiles::TileMap2D::StaticTileObjects*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;

                this->treePosition.Constructor();
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->deleteAll();
                this->tileSet=NULL;
            }
            edk::vector::BinaryTree<edk::tiles::TileMap2D::StaticTileObjects*>::Destructor();
        }

        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::tiles::TileMap2D::StaticTileObjects* first,edk::tiles::TileMap2D::StaticTileObjects* second){
            if(first->object>second->object){
                return true;
            }
            return false;
        }
        virtual bool firstEqualSecond(edk::tiles::TileMap2D::StaticTileObjects* first,edk::tiles::TileMap2D::StaticTileObjects* second){
            if(first->object==second->object){
                return true;
            }
            return false;
        }
        //UPDATE
        virtual void renderElement(edk::tiles::TileMap2D::StaticTileObjects* value){
            if(this->tileSet && value){
                //update the value drawing the tile from tileSet
                if(value->object && value->tile){
                    //draw the tile in object position
                    this->tileSet->drawTile(value->tile,value->object->position,value->object->angle,value->object->size);
                }
            }
        }
        //create a new physics object
        edk::physics2D::PhysicObject2D* newObjectInPositions(edk::vector::Stack<edk::vec2ui32>* positions,edk::uint32 tile, edk::uint8 type,bool sensor){
            if(positions){
                //test if have the positions
                edk::uint32 size = positions->size();
                for(edk::uint32 i=0u;i<size;i++){
                    //test if have the position
                    if(this->havePosition(positions->get(i))){
                        return NULL;
                    }
                }

                edk::physics2D::PhysicObject2D* object = NULL;
                //create the new object
                if(type == edk::TypeObject2DStatic){
                    if(sensor){
                        object = new edk::physics2D::StaticSensor2D;
                    }
                    else{
                        object = new edk::physics2D::StaticObject2D;
                    }
                }
                if(object){
                    //create the staticTileObject to the tree
                    edk::tiles::TileMap2D::StaticTileObjects* temp = new edk::tiles::TileMap2D::StaticTileObjects(object);
                    if(temp){
                        if(temp->object){
                            bool canAdd=true;

                            //Add all positions on the positionTree
                            edk::tiles::TileMap2D::PhysicsTiles* tempPosition;
                            for(edk::uint32 i=0u;i<size;i++){
                                tempPosition = new edk::tiles::TileMap2D::PhysicsTiles(temp->object);
                                if(tempPosition){
                                    tempPosition->position = positions->get(i);
                                    //add to the position tree
                                    if(this->treePosition.add(tempPosition)){
                                        temp->positions.add(tempPosition->position);
                                    }
                                    else{
                                        delete tempPosition;
                                        //else can't add the position
                                        canAdd=false;
                                    }
                                }
                            }
                            if(canAdd){
                                temp->tile = tile;
                                //add to the tree
                                if(this->add(temp)){
                                    return temp->object;
                                }
                            }
                            //else remove all positions from the treePosition
                            edk::tiles::TileMap2D::PhysicsTiles find(NULL);
                            for(edk::uint32 i=0u;i<size;i++){
                                find.position = positions->get(i);
                                //add to the position tree
                                if((tempPosition = this->treePosition.getElement(&find))){
                                    if(this->treePosition.remove(tempPosition)){
                                        delete tempPosition;
                                    }
                                }
                            }
                        }
                        delete temp;
                    }
                    delete object;
                }
            }
            return NULL;
        }
        //test if have the object
        bool haveObject(edk::physics2D::PhysicObject2D* object){
            if(object){
                edk::tiles::TileMap2D::StaticTileObjects find(object);
                return this->haveElement(&find);
            }
            return false;
        }
        bool havePosition(edk::vec2ui32 position){
            edk::tiles::TileMap2D::PhysicsTiles find(NULL);
            find.position=position;
            return this->treePosition.haveElement(&find);
        }
        //return the position size of the object
        edk::uint32 getPositionSizeOfObject(edk::physics2D::PhysicObject2D* object){
            edk::uint32 ret=0u;
            edk::tiles::TileMap2D::StaticTileObjects* temp = this->getPhysicsTileObject(object);
            if(temp){
                //get the position size
                ret = temp->positions.size();
            }
            return ret;
        }
        //return the position object
        edk::vec2ui32 getPositionOfObject(edk::physics2D::PhysicObject2D* object, edk::uint32 position){
            edk::vec2ui32 ret;
            edk::tiles::TileMap2D::StaticTileObjects* temp = this->getPhysicsTileObject(object);
            if(temp){
                if(position < temp->positions.size()){
                    //get the position in position
                    ret = temp->positions.getElementInPosition(position);
                }
            }
            return ret;
        }
        //get object
        edk::physics2D::PhysicObject2D* getObjectInPosition(edk::vec2ui32 position){
            edk::tiles::TileMap2D::StaticTileObjects* temp = this->getPhysicsTileInPosition(position);
            if(temp){
                return temp->object;
            }
            return NULL;
        }
        edk::physics2D::PhysicObject2D* getObjectInPosition(edk::uint32 position){
            edk::tiles::TileMap2D::StaticTileObjects* temp = this->getElementInPosition(position);
            if(temp){
                return temp->object;
            }
            return NULL;
        }
        //delete object
        bool deleteObject(edk::physics2D::PhysicObject2D* object){
            //load the object
            return this->deleteStaticTileObjects(this->getPhysicsTileObject(object));
        }
        //delete object in position
        bool deleteObjectInPosition(edk::vec2ui32 position){
            //load the object
            return this->deleteStaticTileObjects(this->getPhysicsTileInPosition(position));
        }
        //delete all objects
        void deleteAll(){
            edk::tiles::TileMap2D::StaticTileObjects* temp = NULL;
            for(edk::uint32 i=0u;i<this->size();i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    //this->treePosition.remove(temp);
                    delete temp;
                }
            }
            this->clean();
            edk::tiles::TileMap2D::PhysicsTiles* temp2 = NULL;
            for(edk::uint32 i=0u;i<this->treePosition.size();i++){
                temp2 = this->treePosition.getElementInPosition(i);
                if(temp2){
                    delete temp2;
                }
            }
            this->treePosition.clean();
        }
        //set tileSet
        bool setTileSet(edk::tiles::TileSet2D *tileSet){
            this->tileSet=tileSet;
            if(this->tileSet){

                return true;
            }
            return false;
        }
        edk::tiles::TileMap2D::StaticTileObjects* getPhysicsTileObject(edk::physics2D::PhysicObject2D* object){
            edk::tiles::TileMap2D::StaticTileObjects find(object);
            return this->getElement(&find);
        }
        //get StaticTileObjects
        edk::tiles::TileMap2D::StaticTileObjects* getPhysicsTileInPosition(edk::vec2ui32 position){
            edk::tiles::TileMap2D::PhysicsTiles find(NULL);
            find.position = position;
            //get the object from the temp
            edk::tiles::TileMap2D::PhysicsTiles* temp = this->treePosition.getElement(&find);
            if(temp){
                edk::tiles::TileMap2D::StaticTileObjects findObject(temp->object);
                return this->getElement(&findObject);
            }
            return NULL;
        }
        //get physicsObject
        edk::physics2D::PhysicObject2D* getPhysicsObjectInPosition(edk::vec2ui32 position){
            edk::tiles::TileMap2D::StaticTileObjects* temp = getPhysicsTileInPosition(position);
            if(temp){
                return temp->object;
            }
            return NULL;
        }
        //return the ID in position
        edk::uint32 getIDInPosition(edk::vec2ui32 position){
            edk::tiles::TileMap2D::StaticTileObjects* temp = getPhysicsTileInPosition(position);
            if(temp){
                return temp->tile;
            }
            return 0u;
        }

    private:
        //tileSet
        edk::tiles::TileSet2D *tileSet;
        //delete physicsObject
        bool deleteStaticTileObjects(edk::tiles::TileMap2D::StaticTileObjects* physicTiles){
            if(physicTiles){
                edk::tiles::TileMap2D::StaticTileObjects* temp = this->getElement(physicTiles);
                if(temp){
                    //remove from the trees
                    edk::tiles::TileMap2D::PhysicsTiles find(NULL);
                    edk::tiles::TileMap2D::PhysicsTiles* tempRemove;
                    edk::uint32 size = temp->positions.size();
                    for(edk::uint32 i=0u;i<size;i++){
                        find.position = temp->positions.getElementInPosition(i);
                        tempRemove = this->treePosition.getElement(&find);
                        if(tempRemove){
                            if(tempRemove->object == temp->object){
                                if(this->treePosition.remove(tempRemove)){
                                    delete tempRemove;
                                }
                            }
                        }
                    }
                    delete temp;
                    return true;
                }
            }
            return false;
        }

        //Physics Objects Position Tree
        class TreeStaticPhysicsPosition:public edk::vector::BinaryTree<edk::tiles::TileMap2D::PhysicsTiles*>{
        public:
            //compare if the value is bigger
            virtual bool firstBiggerSecond(edk::tiles::TileMap2D::PhysicsTiles* first,edk::tiles::TileMap2D::PhysicsTiles* second){
                if(first->position.x>second->position.x){
                    return true;
                }
                else if(first->position.x==second->position.x){
                    if(first->position.y>second->position.y){
                        return true;
                    }
                }
                return false;
            }
            virtual bool firstEqualSecond(edk::tiles::TileMap2D::PhysicsTiles* first,edk::tiles::TileMap2D::PhysicsTiles* second){
                if(first->position==second->position){
                    return true;
                }
                return false;
            }
        }treePosition;
    private:
        edk::classID classThis;
    }treeStaticPhysics;
private:
    edk::classID classThis;
};
}//end namespace tiles
}//end namespace edk

#endif // TILEMAP2D_H
