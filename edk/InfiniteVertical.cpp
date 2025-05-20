#include "InfiniteVertical.h"

/*
Library C++ InfiniteVertical - Draw an infinite Vertical object map.
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
#pragma message "            Inside InfiniteVertical.cpp"
#endif

bool edk::InfiniteVertical::tileWorldObject2D::templateConstructNeed=true;
edk::Object2D edk::InfiniteVertical::tileWorldObject2D::staticObj;

edk::InfiniteVertical::InfiniteVertical(){
    this->classThis=NULL;
    this->Constructor();
}
edk::InfiniteVertical::~InfiniteVertical(){
    this->Destructor();
}

void edk::InfiniteVertical::Constructor(){
    if(edk::InfiniteVertical::tileWorldObject2D::templateConstructNeed){
        edk::InfiniteVertical::tileWorldObject2D::staticObj.Constructor();
        edk::InfiniteVertical::tileWorldObject2D::templateConstructNeed=false;
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->time.Constructor();
        this->rand.Constructor();
        this->tree.Constructor();
        this->buffer.Constructor();
        this->queue.Constructor();

        this->speed=1.f;
        this->position = 0.f;
        this->time.start();
        this->lastObject=NULL;
    }
}
void edk::InfiniteVertical::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->clean();

        this->time.Destructor();
        this->rand.Destructor();
        this->tree.Destructor();
        this->buffer.Destructor();
        this->queue.Destructor();
    }
    edk::InfiniteVertical::tileWorldObject2D::staticObj.Destructor();
}

//increment the tile position
edk::vec2f32 edk::InfiniteVertical::incrementTilePosition(edk::float32 seconds,edk::vec2f32 position){
    position.y+=this->speed*seconds;
    return position;
}
//set the object first position
edk::vec2f32 edk::InfiniteVertical::firstPositionObject(edk::rectf32 rect,edk::Object2D* obj){
    edk::vec2f32 position;
    edk::size2f32 size = obj->size;
    if(size.width<0.f){
        size.width*=-1.f;
    }
    if(size.height<0.f){
        size.height*=-1.f;
    }
    position = this->tree.getObjectPosition(obj);
    if(this->speed>=0.f){
        position.y = rect.size.height - size.height*0.5f - this->tree.getObjectDistance(obj);
    }
    else{
        position.y = rect.origin.y + size.height*0.5f + this->tree.getObjectDistance(obj);
    }
    return position;
}
//
edk::rectf32 edk::InfiniteVertical::incrementRectObject(edk::rectf32 rect,edk::float32 distance){
    if(distance>0.f){
        if(this->speed>=0.f){
            //RIGHT
            rect.size.height+=distance;
        }
        else{
            //LEFT
            rect.origin.y-=distance;
        }
    }
    return rect;
}
//return a new object to be on the map
edk::Object2D* edk::InfiniteVertical::getNextObject(){
    edk::uint32 treeSize = this->tree.size();
    if(treeSize>1u){
        return this->tree.getObjectInPosition(this->rand.getRandNumber(treeSize));
    }
    return this->tree.getObjectInPosition(0u);
}

//clean wallpapers
void edk::InfiniteVertical::clean(){
    this->tree.cleanTiles();
    this->time.start();
}

//create the buffer
bool edk::InfiniteVertical::newBuffer(edk::uint32 lenght){
    this->time.start();
    //this->buffer.clean();
    if(lenght){
        edk::InfiniteVertical::tileWorldObject2D** temp = (edk::InfiniteVertical::tileWorldObject2D**)malloc(sizeof(edk::InfiniteVertical::tileWorldObject2D*)*lenght);
        if(temp){
            bool ret=true;
            edkMemSet(temp,0u,sizeof(edk::InfiniteVertical::tileWorldObject2D*)*lenght);
            //create a new objects
            for(edk::uint32 i=0u;i<lenght;i++){
                //create a new tileWorldObject
                temp[i]=new edk::InfiniteVertical::tileWorldObject2D;
                if(!temp[i]){
                    ret=false;
                    break;
                }
            }
            if(ret){
                this->buffer.writeToBuffer(temp,lenght);
            }
            else{
                //clean all memory
                for(edk::uint32 i=0u;i<lenght;i++){
                    //create a new tileWorldObject
                    if(temp[i]){
                        delete temp[i];
                    }
                }
            }
            free(temp);
            return ret;
        }
    }
    return false;
}

//add new wallpaper
//filters
//GU_NEAREST
//GU_LINEAR
//GU_NEAREST_MIPMAP_NEAREST
//GU_NEAREST_MIPMAP_LINEAR
//GU_LINEAR_MIPMAP_NEAREST
//GU_LINEAR_MIPMAP_LINEAR
bool edk::InfiniteVertical::newObject(edk::char8* name,edk::float32 distance,edk::uint32 minFilter,edk::uint32 magFilter){
    this->time.start();
    if(name){
        edk::Object2D* obj = this->tree.newObject(distance);
        if(obj){
            edk::shape::Mesh2D* mesh = obj->newMesh();
            if(mesh){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                mesh->addPolygon(rect);
                if(mesh->material.loadTexture(name,0u,minFilter,magFilter)){
                    this->lastObject = obj;
                    return true;
                }
                obj->cleanMeshes();
            }
            this->tree.removeObject(obj);
        }
    }
    return false;
}
bool edk::InfiniteVertical::newObject(const edk::char8* name,edk::float32 distance,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->newObject((edk::char8*) name,distance,minFilter,magFilter);
}
bool edk::InfiniteVertical::newObjectFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::float32 distance,edk::uint32 minFilter,edk::uint32 magFilter){
    this->time.start();
    if(name){
        edk::Object2D* obj = this->tree.newObject(distance);
        if(obj){
            edk::shape::Mesh2D* mesh = obj->newMesh();
            if(mesh){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                mesh->addPolygon(rect);
                if(mesh->material.loadTextureFromMemory(name,image,size,0u,minFilter,magFilter)){
                    this->lastObject = obj;
                    return true;
                }
                obj->cleanMeshes();
            }
            this->tree.removeObject(obj);
        }
    }
    return false;
}
bool edk::InfiniteVertical::newObjectFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::float32 distance,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->newObjectFromMemory((edk::char8*) name,image,size,distance,minFilter,magFilter);
}
bool edk::InfiniteVertical::newObjectFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::float32 distance,edk::uint32 minFilter,edk::uint32 magFilter){
    this->time.start();
    if(name){
        edk::Object2D* obj = this->tree.newObject(distance);
        if(obj){
            edk::shape::Mesh2D* mesh = obj->newMesh();
            if(mesh){
                edk::shape::Rectangle2D rect;
                rect.setPivoToCenter();
                mesh->addPolygon(rect);
                if(mesh->material.loadTextureFromPack(pack,name,0u,minFilter,magFilter)){
                    this->lastObject = obj;
                    return true;
                }
                obj->cleanMeshes();
            }
            this->tree.removeObject(obj);
        }
    }
    return false;
}
bool edk::InfiniteVertical::newObjectFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::float32 distance,edk::uint32 minFilter,edk::uint32 magFilter){
    return newObjectFromPack(pack,(edk::char8*) name,distance,minFilter,magFilter);
}
//clone a wallpaper from an object
bool edk::InfiniteVertical::newObjectFromObject2D(edk::Object2D* obj,edk::float32 distance){
    this->time.start();
    this->lastObject = this->tree.addObjectFromObject(obj,distance);
    if(this->lastObject){
        return true;
    }
    return false;
}
bool edk::InfiniteVertical::newObjectFromObject2D(edk::physics2D::PhysicObject2D* obj,edk::float32 distance){
    this->time.start();
    this->lastObject = (edk::Object2D*)this->tree.addObjectPhysicFromObject(obj,distance);
    if(this->lastObject){
        return true;
    }
    return false;
}

//test if have some object inside the queue
bool edk::InfiniteVertical::haveObjectInQueue(edk::Object2D* obj){
    edk::uint32 size = this->queue.size();
    edk::InfiniteVertical::tileWorldObject2D* tile;
    for(edk::uint32 i=0u;i<size;i++){
        tile = this->queue.get(i);
        if(tile){
            if(tile->objPointer == obj){
                return true;
            }
        }
    }
    return false;
}

//get the last object added
edk::Object2D* edk::InfiniteVertical::getLastAddedObject(){
    return this->lastObject;
}

void edk::InfiniteVertical::updateInsideRect(edk::float32 seconds,edk::rectf32 rect){
    rect.convertIntoPoints();
    this->updateInsideRectPoints(seconds,rect);
}
void edk::InfiniteVertical::updateInsideRectPoints(edk::float32 seconds,edk::rectf32 rect){
    edk::Object2D* obj=NULL;
    edk::InfiniteVertical::tileWorldObject2D* tile = NULL;
    //test if have some object in the queue
    if(!this->queue.size()){
        if(this->buffer.size()){
            //add a new object in the queue
            tile = this->buffer[0u];
            this->buffer.incrementOrigin();
            if(tile){
                //add a new object
                obj = this->getNextObject();
                if(obj){
                    tile->objPointer=obj;
                    tile->position = this->firstPositionObject(rect,tile->objPointer);
                    this->queue.pushBack(tile);
                }
            }
        }
        else{
            //else create a new buffer
            this->newBuffer(this->tree.size());
        }
    }
    if(this->queue.size()){
        //update the objects speed
        edk::uint32 size = this->queue.size();
        for(edk::uint32 i=0u;i<size;i++){
            tile = this->queue.get(i);
            if(tile){
                tile->position = this->incrementTilePosition(seconds,tile->position);
            }
        }
        //test if need remove the begginins
        while(true){
            tile = this->queue.get(0u);
            if(tile){
                tile->objPointer->position = tile->position + this->position;
                //calculate the bounding box
                tile->objPointer->calculateBoundingBox();
                if(!this->aabbPoints(incrementRectObject(tile->objPointer->getBoundingBox(),this->tree.getObjectDistance(tile->objPointer)),rect)){
                    //remove the tile
                    this->queue.popFront();
                    continue;
                }
            }
            //else break
            break;
        }
        if(this->queue.size()){
            //add a new object in the queue if need
            edk::uint32 pos = this->queue.size()-1u;
            edk::rectf32 newRect;
            while(true){
                tile = this->queue.get(pos);
                if(tile){
                    tile->objPointer->position = tile->position + this->position;
                    //calculate the bounding box
                    tile->objPointer->calculateBoundingBox();
                    if(this->aabbPoints(incrementRectObject(tile->objPointer->getBoundingBox(),this->tree.getObjectDistance(tile->objPointer)),rect)){
                        edk::size2f32 size = tile->objPointer->size;
                        if(size.width<0.f){
                            size.width*=-1.f;
                        }
                        if(size.height<0.f){
                            size.height*=-1.f;
                        }
                        newRect.origin.x = tile->position.x + size.width*0.5f;
                        newRect.size.width = tile->position.x - size.width*0.5f;
                        newRect.origin.y = tile->position.y + size.height*0.5f;
                        newRect.size.height = tile->position.y - size.height*0.5f;
                        //add a new tile
                        tile = this->buffer[0u];
                        this->buffer.incrementOrigin();
                        if(tile){
                            obj = this->getNextObject();
                            if(obj){
                                tile->objPointer=obj;
                                tile->position = this->firstPositionObject(newRect,tile->objPointer);
                                this->queue.pushBack(tile);
                                pos++;
                                continue;
                            }
                        }
                    }
                }
                //else break
                break;
            }
        }
    }
}
void edk::InfiniteVertical::updateInsideSize(edk::float32 seconds,edk::vec2f32 position,edk::size2f32 size){
    edk::rectf32 rect;
    rect.origin = position;
    rect.size = size;
    rect.convertIntoPoints();
    this->updateInsideRectPoints(seconds,rect);
}
void edk::InfiniteVertical::updateInsidePoints(edk::float32 seconds,edk::vec2f32 point1,edk::vec2f32 point2){
    edk::rectf32 rect;
    rect.origin = point1;
    rect.size.width = point2.x;
    rect.size.height = point2.y;
    this->updateInsideRectPoints(seconds,rect);
}

//draw the wallpaper
void edk::InfiniteVertical::draw(){
    edk::uint32 size = this->queue.size();
    edk::InfiniteVertical::tileWorldObject2D* tile;
    for(edk::uint32 i=0u;i<size;i++){
        tile = this->queue.get(i);
        if(tile){
            tile->objPointer->position = tile->position + this->position;
            tile->objPointer->draw();
        }
    }
}
void edk::InfiniteVertical::drawWire(){
    edk::uint32 size = this->queue.size();
    edk::InfiniteVertical::tileWorldObject2D* tile;
    for(edk::uint32 i=0u;i<size;i++){
        tile = this->queue.get(i);
        if(tile){
            tile->objPointer->position = tile->position + this->position;
            tile->objPointer->drawWire();
        }
    }
}
