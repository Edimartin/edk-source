#ifndef TILEMAP2D_H
#define TILEMAP2D_H

/*
Library TileMap2D - Use 2D Tiles from TileSet as a TileMap in EDK Game Engine
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

#pragma once
//Include a tileSet
#include "TileSet2D.h"
#include "../vector/Array.h"
#include "../vector/BinaryTree.h"
#include "../physics2D/World2D.h"
#include "../BinaryConverter.h"

namespace edk{
namespace tiles{
class tileContact2D{
public:
    tileContact2D();
    ~tileContact2D();
    edk::uint32 tileA;
    edk::uint32 tileB;
    edk::vec2ui32 positionA;
    edk::vec2ui32 positionB;
};
class tileCallback{
public:
    tileCallback(){}
    virtual void contact2DTileBegin(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){if(contact){tiles.tileA++;}}
    virtual void contact2DTileEnd(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){if(contact){tiles.tileA++;}}
    virtual void contact2DTileKeepBegin(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){if(contact){tiles.tileA++;}}
    virtual void contact2DTileKeepEnd(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){if(contact){tiles.tileA++;}}
    //contact sensors
    virtual void sensor2DTileBegin(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){if(contact){tiles.tileA++;}}
    virtual void sensor2DTileEnd(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){if(contact){tiles.tileA++;}}
    virtual void sensor2DTileKeeping(edk::tiles::tileContact2D tiles,edk::physics2D::Contact2D* contact){if(contact){tiles.tileA++;}}
};

class TileMap2D : public edk::physics2D::ContactCallback2D{
public:
    //set the tileSet to use on the tileMap
    TileMap2D();
    TileMap2D(edk::tiles::TileSet2D* tileSet);
    virtual ~TileMap2D();

    //set the tileSet
    bool setTileSet(edk::tiles::TileSet2D* tileSet);
    void removeTileSet();
    //set a tile in the tileMap
    bool setTile(edk::uint32 tileID,edk::vec2ui32 position);
    bool setTile(edk::uint32 tileID,edk::uint32 positionX,edk::uint32 positionY);
    //set the tileMap position
    void setPosition(edk::vec2f32 position);
    void setPosition(edk::float32 positionX,edk::float32 positionY);
    edk::vec2f32 getTileWorldPosition(edk::vec2f32 position);
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
    //return the size of the map
    edk::size2ui32 getMapSize();
    //return the scale of the map
    edk::size2f32 getScaleMap();
    //return the position
    edk::vec2f32 getPosition();
    edk::float32 getPositionX();
    edk::float32 getPositionY();

    //Desenha o tileMap
    void draw(edk::color4f32 color=edk::color4f32(1,1,1,1));
    void draw(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color=edk::color4f32(1,1,1,1));
    void drawInsideWorldRect(edk::rectf32 rect,edk::color4f32 color=edk::color4f32(1,1,1,1));
    //draw the tile for selection
    void drawSelection(edk::uint8 id=0u,edk::color4f32 color=edk::color4f32(1,1,1,1));
    void drawSelection(edk::vec2ui32 origin,edk::size2ui32 last,edk::uint8 id=0u,edk::color4f32 color=edk::color4f32(1,1,1,1));
    void drawInsideWorldRectSelection(edk::rectf32 rect,edk::uint8 id=0u,edk::color4f32 color=edk::color4f32(1,1,1,1));
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
    //size of the tileMap
    edk::size2ui32 sizeMap;
    //scale the tileMap
    edk::size2f32 scaleMap;
    //position of the tileMap
    edk::vec2f32 positionMap;

    //PhysicsTiles
    class PhysicsTiles{
    public:
        PhysicsTiles(edk::physics2D::PhysicObject2D* object){this->object=object;this->tile=0u;}
        ~PhysicsTiles(){}
        edk::vec2ui32 position;
        edk::physics2D::PhysicObject2D* object;
        edk::uint32 tile;
    };
    //Physics Objects Tree
    class TreePhysicsTiles:public edk::vector::BinaryTree<edk::tiles::TileMap2D::PhysicsTiles*>{
    public:
        ~TreePhysicsTiles(){this->deleteAll();this->tileSet=NULL;}
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
        virtual void updateElement(edk::tiles::TileMap2D::PhysicsTiles* value){
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
                case edk::physics::StaticBody:
                    if(sensor){
                        object = new edk::physics2D::StaticSensor2D;
                    }
                    else{
                        object = new edk::physics2D::StaticObject2D;
                    }
                    break;
                case edk::physics::KinematicBody:
                    if(sensor){
                        object = new edk::physics2D::KinematicSensor2D;
                    }
                    else{
                        object = new edk::physics2D::KinematicObject2D;
                    }
                    break;
                case edk::physics::DynamicBody:
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
            if(this->tileSet) return true;
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
    }treePhysics;
};
}//end namespace tiles
}//end namespace edk

#endif // TILEMAP2D_H
