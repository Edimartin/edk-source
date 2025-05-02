#ifndef INFINITEVERTICAL_H
#define INFINITEVERTICAL_H

/*
Library C++ InfiniteVertical - Draw an infinite vertical object map.
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
#pragma message "Inside InfiniteVertical"
#endif

#pragma once

#include "edk/vector/BinaryTree.h"
#include "edk/vector/Queue.h"
#include "edk/MemoryBufferCircular.h"
#include "edk/watch/Time.h"
#include "edk/Object2D.h"
#include "edk/physics2D/PhysicObject2D.h"

#ifdef printMessages
#pragma message "    Compiling InfiniteVertical"
#endif

namespace edk{
class InfiniteVertical{
public:
    InfiniteVertical();
    virtual ~InfiniteVertical();

    void Constructor();
    void Destructor();

    //clean wallpapers
    void clean();

    //create the buffer
    bool newBuffer(edk::uint32 lenght);

    //add new wallpaper
    //filter
    //GU_NEAREST
    //GU_LINEAR
    //GU_NEAREST_MIPMAP_NEAREST
    //GU_NEAREST_MIPMAP_LINEAR
    //GU_LINEAR_MIPMAP_NEAREST
    //GU_LINEAR_MIPMAP_LINEAR
    bool newObject(edk::char8* name,edk::float32 distance=0.f,edk::uint32 filter = GU_NEAREST);
    bool newObject(const edk::char8* name,edk::float32 distance=0.f,edk::uint32 filter = GU_NEAREST);
    bool newObjectFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::float32 distance=0.f,edk::uint32 filter = GU_NEAREST);
    bool newObjectFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::float32 distance=0.f,edk::uint32 filter = GU_NEAREST);
    bool newObjectFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::float32 distance=0.f,edk::uint32 filter = GU_NEAREST);
    bool newObjectFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::float32 distance=0.f,edk::uint32 filter = GU_NEAREST);
    //clone a wallpaper from an object
    bool newObjectFromObject2D(edk::Object2D* obj,edk::float32 distance=0.f);
    bool newObjectFromObject2D(edk::physics2D::PhysicObject2D* obj,edk::float32 distance=0.f);

    //test if have some object inside the queue
    bool haveObjectInQueue(edk::Object2D* obj);

    //get the last object added
    edk::Object2D* getLastAddedObject();

    void inline updateInsideRect(edk::rectf32 rect){return this->updateInsideRect(this->getSeconds(),rect);}
    void updateInsideRect(edk::float32 seconds,edk::rectf32 rect);
    void inline updateInsideRectPoints(edk::rectf32 rect){return this->updateInsideRect(this->getSeconds(),rect);}
    virtual void updateInsideRectPoints(edk::float32 seconds,edk::rectf32 rect);
    void inline updateInsideSize(edk::vec2f32 position,edk::size2f32 size){return this->updateInsideSize(this->getSeconds(),position,size);}
    void updateInsideSize(edk::float32 seconds,edk::vec2f32 position,edk::size2f32 size);
    void inline updateInsidePoints(edk::vec2f32 point1,edk::vec2f32 point2){return this->updateInsidePoints(this->getSeconds(),point1,point2);}
    void updateInsidePoints(edk::float32 seconds,edk::vec2f32 point1,edk::vec2f32 point2);

    //draw the wallpaper
    void draw();
    void drawWire();

    //tiles position
    edk::vec2f32 position;
    edk::float32 speed;
protected:
    //increment the tile position
    virtual edk::vec2f32 incrementTilePosition(edk::float32 seconds,edk::vec2f32 position);
    //set the object first position
    virtual edk::vec2f32 firstPositionObject(edk::rectf32 rect,edk::Object2D* obj);
    //
    virtual edk::rectf32 incrementRectObject(edk::rectf32 rect,edk::float32 distance);
    //return a new object to be on the map
    virtual edk::Object2D* getNextObject();
    //calculate the aabb
    inline bool aabbPoints(edk::rectf32 rect1,edk::rectf32 rect2){
        return edk::collision::MathCollision::aabbPointsY(rect1,rect2);
    }
private:
    //time counter
    edk::watch::Time time;
    edk::Random rand;

    //save the last object added
    edk::Object2D* lastObject;

    //get the seconds
    inline edk::float32 getSeconds(){
        edk::float32 seconds = this->time.getSeconds();
        this->time.start();
        return seconds;
    }

    //objects for the tile with the distance
    class tileObject2D{
    public:
        tileObject2D(bool isPhysic){
            this->classThis=NULL;
            this->Constructor(isPhysic);
        }
        virtual ~tileObject2D(){
            this->Destructor();
        }

        void Constructor(bool isPhysic){
            if(this->classThis!=this){
                this->classThis=this;

                this->obj.Constructor();
                this->objPhys.Constructor();

                this->distance=0.f;
                if(isPhysic){
                    this->objPointer = &this->objPhys;
                }
                else{
                    this->objPointer = &this->obj;
                }
                this->position=this->objPointer->position;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->obj.clean();

                this->obj.Destructor();
                this->objPhys.Destructor();
            }
        }

        //return true if the object is physic
        inline bool isPhysic(){return (this->objPointer==(edk::Object2D*)&this->objPhys);}
        edk::Object2D obj;
        edk::physics2D::PhysicObject2D objPhys;
        edk::Object2D* objPointer;
        edk::float32 distance;
        edk::vec2f32 position;
    private:
        edk::classID classThis;
    };
    //Binary tree with all possible tiles
    class treeObj:public edk::vector::BinaryTree<edk::InfiniteVertical::tileObject2D*>{
    public:
        treeObj()
            :tileTemplate(false)
        {
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~treeObj(){
            this->Destructor();
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::InfiniteVertical::tileObject2D*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;

                this->tileTemplate.Constructor(false);
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->tileTemplate.Destructor();
            }
            edk::vector::BinaryTree<edk::InfiniteVertical::tileObject2D*>::Destructor();
        }
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::InfiniteVertical::tileObject2D* first,edk::InfiniteVertical::tileObject2D* second){
            if(first->objPointer>second->objPointer){
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::InfiniteVertical::tileObject2D* first,edk::InfiniteVertical::tileObject2D* second){
            if(first->objPointer==second->objPointer){
                return true;
            }
            return false;
        }

        //remove the object
        bool removeObject(edk::Object2D* obj){
            edk::InfiniteVertical::tileObject2D* tile = this->getTileByObject(obj);
            if(tile){
                if(this->remove(tile)){
                    delete tile;
                    return true;
                }
            }
            return false;
        }
        bool removeObject(edk::physics2D::PhysicObject2D* obj){
            edk::InfiniteVertical::tileObject2D* tile = this->getTileByObject(obj);
            if(tile){
                if(this->remove(tile)){
                    delete tile;
                    return true;
                }
            }
            return false;
        }
        //clean tiles
        void cleanTiles(){
            edk::InfiniteVertical::tileObject2D* tile;
            edk::uint32 size = this->size();
            for(edk::uint32 i=0u;i<size;i++){
                tile = this->getElementInPosition(i);
                if(tile){
                    delete tile;
                }
            }
            this->clean();
        }
        //add the new object
        bool addObject(edk::Object2D* obj,edk::float32 distance){
            edk::InfiniteVertical::tileObject2D* tile = this->getTileByObject(obj);
            if(!tile){
                tile = new edk::InfiniteVertical::tileObject2D(false);
                if(tile){
                    //clone the object
                    if(tile->obj.cloneFrom(obj)){
                        tile->position=obj->position;
                        tile->distance=distance;
                        //add into the tree
                        if(this->add(tile)){
                            return true;
                        }
                    }
                    delete tile;
                }
            }
            return false;
        }
        bool addObjectPhysic(edk::physics2D::PhysicObject2D* obj,edk::float32 distance){
            edk::InfiniteVertical::tileObject2D* tile = this->getTileByObject(obj);
            if(!tile){
                tile = new edk::InfiniteVertical::tileObject2D(true);
                if(tile){
                    //clone the object
                    if(tile->objPhys.cloneFrom(obj)){
                        tile->position=obj->position;
                        tile->distance=distance;
                        //add into the tree
                        if(this->add(tile)){
                            return true;
                        }
                    }
                    delete tile;
                }
            }
            return false;
        }
        edk::Object2D* newObject(edk::float32 distance){
            edk::InfiniteVertical::tileObject2D* tile = new edk::InfiniteVertical::tileObject2D(false);
            if(tile){
                //add into the tree
                if(this->add(tile)){
                    tile->distance=distance - 0.1f;
                    return &tile->obj;
                }
                delete tile;
            }
            return NULL;
        }
        edk::physics2D::PhysicObject2D* newObjectPhysic(edk::float32 distance){
            edk::InfiniteVertical::tileObject2D* tile = new edk::InfiniteVertical::tileObject2D(true);
            if(tile){
                //add into the tree
                if(this->add(tile)){
                    tile->distance=distance - 0.1f;
                    return &tile->objPhys;
                }
                delete tile;
            }
            return NULL;
        }
        edk::Object2D* addObjectFromObject(edk::Object2D* obj,edk::float32 distance){
            edk::InfiniteVertical::tileObject2D* tile = this->getTileByObject(obj);
            if(!tile){
                tile = new edk::InfiniteVertical::tileObject2D(false);
                if(tile){
                    //clone the object
                    if(tile->obj.cloneFrom(obj)){
                        tile->position=obj->position;
                        tile->distance=distance - 0.01f;
                        //add into the tree
                        if(this->add(tile)){
                            return &tile->obj;
                        }
                    }
                    delete tile;
                }
            }
            return NULL;
        }
        edk::physics2D::PhysicObject2D* addObjectPhysicFromObject(edk::physics2D::PhysicObject2D* obj,edk::float32 distance){
            edk::InfiniteVertical::tileObject2D* tile = this->getTileByObject(obj);
            if(!tile){
                tile = new edk::InfiniteVertical::tileObject2D(true);
                if(tile){
                    //clone the object
                    if(tile->objPhys.cloneFrom(obj)){
                        tile->position=obj->position;
                        tile->distance=distance - 0.1f;
                        //add into the tree
                        if(this->add(tile)){
                            return &tile->objPhys;
                        }
                    }
                    delete tile;
                }
            }
            return NULL;
        }
        //get an object in a position
        bool isObjectPhysicInPosition(edk::uint32 position){
            edk::InfiniteVertical::tileObject2D* tile = this->getElementInPosition(position);
            if(tile){
                return tile->isPhysic();
            }
            return false;
        }
        edk::Object2D* getObjectInPosition(edk::uint32 position){
            edk::InfiniteVertical::tileObject2D* tile = this->getElementInPosition(position);
            if(tile){
                return &tile->obj;
            }
            return NULL;
        }
        edk::physics2D::PhysicObject2D* getObjectPhysicInPosition(edk::uint32 position){
            edk::InfiniteVertical::tileObject2D* tile = this->getElementInPosition(position);
            if(tile){
                return &tile->objPhys;
            }
            return NULL;
        }
        edk::float32 getDisttanceInPosition(edk::uint32 position){
            edk::InfiniteVertical::tileObject2D* tile = this->getElementInPosition(position);
            if(tile){
                return tile->distance;
            }
            return 0.f;
        }
        edk::vec2f32 getPositionInPosition(edk::uint32 position){
            edk::InfiniteVertical::tileObject2D* tile = this->getElementInPosition(position);
            if(tile){
                return tile->position;
            }
            return edk::vec2f32(0.f,0.f);
        }
        edk::float32 getObjectDistance(edk::Object2D* obj){
            edk::InfiniteVertical::tileObject2D* tile = this->getTileByObject(obj);
            if(tile){
                return tile->distance;
            }
            return 0.f;
        }
        edk::vec2f32 getObjectPosition(edk::Object2D* obj){
            edk::InfiniteVertical::tileObject2D* tile = this->getTileByObject(obj);
            if(tile){
                return tile->position;
            }
            return edk::vec2f32(0.f,0.f);
        }
    private:
        //get the tile by the object
        edk::InfiniteVertical::tileObject2D* getTileByObject(edk::Object2D* obj){
            this->tileTemplate.objPointer=obj;
            return this->getElement(&this->tileTemplate);
        }
        edk::InfiniteVertical::tileObject2D* getTileByObject(edk::physics2D::PhysicObject2D* obj){
            this->tileTemplate.objPointer=(edk::Object2D*)obj;
            return this->getElement(&this->tileTemplate);
        }
        edk::InfiniteVertical::tileObject2D tileTemplate;
    private:
        edk::classID classThis;
    }tree;

    class tileWorldObject2D{
    public:
        tileWorldObject2D(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~tileWorldObject2D(){
            this->Destructor();
        }

        void Constructor(){
            if(this->classThis!=this){
                this->classThis=this;
                this->position=0.f;
                this->objPointer = &edk::InfiniteVertical::tileWorldObject2D::staticObj;
                this->objPointer->Constructor();
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
                this->objPointer->Destructor();
            }
        }
        static edk::Object2D staticObj;
        static bool templateConstructNeed;
        edk::Object2D* objPointer;
        edk::vec2f32 position;
    private:
        edk::classID classThis;
    };
    //memory buffer to create the objects
    edk::MemoryBufferCircular<edk::InfiniteVertical::tileWorldObject2D*> buffer;
    //queue used to draw the objects
    edk::vector::Queue<edk::InfiniteVertical::tileWorldObject2D*> queue;
private:
    edk::classID classThis;
};
}

#endif // INFINITEVERTICAL_H
