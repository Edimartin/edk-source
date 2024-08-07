#include "InfiniteHorizontal.h"

/*
Library C++ InfiniteHorizontal - Draw an infinite horizontal object map.
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
#pragma message "            Inside InfiniteHorizontal.cpp"
#endif

bool edk::InfiniteHorizontal::tileWorldObject2D::templateConstructNeed=true;
edk::Object2D edk::InfiniteHorizontal::tileWorldObject2D::staticObj;

edk::InfiniteHorizontal::InfiniteHorizontal(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}
edk::InfiniteHorizontal::~InfiniteHorizontal(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->clean();edkEnd();
    }
}

void edk::InfiniteHorizontal::Constructor(bool /*runFather*/){
    if(edk::InfiniteHorizontal::tileWorldObject2D::templateConstructNeed){
        edk::InfiniteHorizontal::tileWorldObject2D::staticObj.Constructor();
        edk::InfiniteHorizontal::tileWorldObject2D::templateConstructNeed=false;
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->time.Constructor();
        this->rand.Constructor();
        this->tree.Constructor();
        this->buffer.Constructor();
        this->queue.Constructor();

        this->speed=1.f;edkEnd();
        this->position = 0.f;edkEnd();
        this->time.start();edkEnd();
        this->lastObject=NULL;edkEnd();
    }
}

//increment the tile position
edk::vec2f32 edk::InfiniteHorizontal::incrementTilePosition(edk::float32 seconds,edk::vec2f32 position){
    position.x+=this->speed*seconds;edkEnd();
    return position;
}
//set the object first position
edk::vec2f32 edk::InfiniteHorizontal::firstPositionObject(edk::rectf32 rect,edk::Object2D* obj){
    edk::vec2f32 position;edkEnd();
    edk::size2f32 size = obj->size;
    if(size.width<0.f){
        size.width*=-1.f;edkEnd();
    }
    if(size.height<0.f){
        size.height*=-1.f;edkEnd();
    }
    position = this->tree.getObjectPosition(obj);edkEnd();
    if(this->speed>=0.f){
        position.x = rect.size.width - size.width*0.5f - this->tree.getObjectDistance(obj);edkEnd();
    }
    else{
        position.x = rect.origin.x + size.width*0.5f + this->tree.getObjectDistance(obj);edkEnd();
    }
    return position;
}
//
edk::rectf32 edk::InfiniteHorizontal::incrementRectObject(edk::rectf32 rect,edk::float32 distance){
    if(distance>0.f){
        if(this->speed>=0.f){
            //RIGHT
            rect.size.width+=distance;
        }
        else{
            //LEFT
            rect.origin.x-=distance;
        }
    }
    return rect;
}
//return a new object to be on the map
edk::Object2D* edk::InfiniteHorizontal::getNextObject(){
    edk::uint32 treeSize = this->tree.size();
    if(treeSize>1u){
        return this->tree.getObjectInPosition(this->rand.getRandNumber(treeSize));edkEnd();
    }
    return this->tree.getObjectInPosition(0u);edkEnd();
}

//clean wallpapers
void edk::InfiniteHorizontal::clean(){
    this->tree.cleanTiles();edkEnd();
    this->time.start();edkEnd();
}

//create the buffer
bool edk::InfiniteHorizontal::newBuffer(edk::uint32 lenght){
    this->time.start();edkEnd();
    //this->buffer.clean();
    if(lenght){
        edk::InfiniteHorizontal::tileWorldObject2D** temp = (edk::InfiniteHorizontal::tileWorldObject2D**)malloc(sizeof(edk::InfiniteHorizontal::tileWorldObject2D*)*lenght);edkEnd();
        if(temp){
            bool ret=true;edkEnd();
            edkMemSet(temp,0u,sizeof(edk::InfiniteHorizontal::tileWorldObject2D*)*lenght);edkEnd();
            //create a new objects
            for(edk::uint32 i=0u;i<lenght;i++){
                //create a new tileWorldObject
                temp[i]=new edk::InfiniteHorizontal::tileWorldObject2D;edkEnd();
                if(!temp[i]){
                    ret=false;edkEnd();
                    break;
                }
            }
            if(ret){
                this->buffer.writeToBuffer(temp,lenght);edkEnd();
            }
            else{
                //clean all memory
                for(edk::uint32 i=0u;i<lenght;i++){
                    //create a new tileWorldObject
                    if(temp[i]){
                        delete temp[i];edkEnd();
                    }
                }
            }
            free(temp);edkEnd();
            return ret;
        }
    }
    return false;
}

//add new wallpaper
//filter
//GU_NEAREST
//GU_LINEAR
//GU_NEAREST_MIPMAP_NEAREST
//GU_NEAREST_MIPMAP_LINEAR
//GU_LINEAR_MIPMAP_NEAREST
//GU_LINEAR_MIPMAP_LINEAR
bool edk::InfiniteHorizontal::newObject(edk::char8* name,edk::float32 distance,edk::uint32 filter){
    this->time.start();edkEnd();
    if(name){
        edk::Object2D* obj = this->tree.newObject(distance);edkEnd();
        if(obj){
            edk::shape::Mesh2D* mesh = obj->newMesh();edkEnd();
            if(mesh){
                edk::shape::Rectangle2D rect;edkEnd();
                rect.setPivoToCenter();edkEnd();
                mesh->addPolygon(rect);edkEnd();
                if(mesh->material.loadTexture(name,0u,filter)){
                    this->lastObject = obj;
                    return true;
                }
                obj->cleanMeshes();edkEnd();
            }
            this->tree.removeObject(obj);edkEnd();
        }
    }
    return false;
}
bool edk::InfiniteHorizontal::newObject(const edk::char8* name,edk::float32 distance,edk::uint32 filter){
    return this->newObject((edk::char8*) name,distance,filter);
}
bool edk::InfiniteHorizontal::newObjectFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::float32 distance,edk::uint32 filter){
    this->time.start();edkEnd();
    if(name){
        edk::Object2D* obj = this->tree.newObject(distance);edkEnd();
        if(obj){
            edk::shape::Mesh2D* mesh = obj->newMesh();edkEnd();
            if(mesh){
                edk::shape::Rectangle2D rect;edkEnd();
                rect.setPivoToCenter();edkEnd();
                mesh->addPolygon(rect);edkEnd();
                if(mesh->material.loadTextureFromMemory(name,image,size,0u,filter)){
                    this->lastObject = obj;
                    return true;
                }
                obj->cleanMeshes();edkEnd();
            }
            this->tree.removeObject(obj);edkEnd();
        }
    }
    return false;
}
bool edk::InfiniteHorizontal::newObjectFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::float32 distance,edk::uint32 filter){
    return this->newObjectFromMemory((edk::char8*) name,image,size,distance,filter);
}
bool edk::InfiniteHorizontal::newObjectFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::float32 distance,edk::uint32 filter){
    this->time.start();edkEnd();
    if(name){
        edk::Object2D* obj = this->tree.newObject(distance);edkEnd();
        if(obj){
            edk::shape::Mesh2D* mesh = obj->newMesh();edkEnd();
            if(mesh){
                edk::shape::Rectangle2D rect;edkEnd();
                rect.setPivoToCenter();edkEnd();
                mesh->addPolygon(rect);edkEnd();
                if(mesh->material.loadTextureFromPack(pack,name,0u,filter)){
                    this->lastObject = obj;
                    return true;
                }
                obj->cleanMeshes();edkEnd();
            }
            this->tree.removeObject(obj);edkEnd();
        }
    }
    return false;
}
bool edk::InfiniteHorizontal::newObjectFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::float32 distance,edk::uint32 filter){
    return newObjectFromPack(pack,(edk::char8*) name,distance,filter);
}
//clone a wallpaper from an object
bool edk::InfiniteHorizontal::newObjectFromObject2D(edk::Object2D* obj,edk::float32 distance){
    this->time.start();
    this->lastObject = this->tree.addObjectFromObject(obj,distance);
    if(this->lastObject){
        return true;
    }
    return false;
}
bool edk::InfiniteHorizontal::newObjectFromObject2D(edk::physics2D::PhysicObject2D* obj,edk::float32 distance){
    this->time.start();
    this->lastObject = (edk::Object2D*)this->tree.addObjectPhysicFromObject(obj,distance);
    if(this->lastObject){
        return true;
    }
    return false;
}

//test if have some object inside the queue
bool edk::InfiniteHorizontal::haveObjectInQueue(edk::Object2D* obj){
    edk::uint32 size = this->queue.size();edkEnd();
    edk::InfiniteHorizontal::tileWorldObject2D* tile;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        tile = this->queue.get(i);edkEnd();
        if(tile){
            if(tile->objPointer == obj){
                return true;
            }
        }
    }
    return false;
}

//get the last object added
edk::Object2D* edk::InfiniteHorizontal::getLastAddedObject(){
    return this->lastObject;
}

void edk::InfiniteHorizontal::updateInsideRect(edk::float32 seconds,edk::rectf32 rect){
    rect.convertIntoPoints();edkEnd();
    this->updateInsideRectPoints(seconds,rect);edkEnd();
}
void edk::InfiniteHorizontal::updateInsideRectPoints(edk::float32 seconds,edk::rectf32 rect){
    edk::Object2D* obj=NULL;edkEnd();
    edk::InfiniteHorizontal::tileWorldObject2D* tile = NULL;edkEnd();
    //test if have some object in the queue
    if(!this->queue.size()){
        if(this->buffer.size()){
            //add a new object in the queue
            tile = this->buffer[0u];edkEnd();
            this->buffer.incrementOrigin();edkEnd();
            if(tile){
                //add a new object
                obj = this->getNextObject();
                if(obj){
                    tile->objPointer=obj;edkEnd();
                    tile->position = this->firstPositionObject(rect,tile->objPointer);edkEnd();
                    this->queue.pushBack(tile);edkEnd();
                }
            }
        }
        else{
            //else create a new buffer
            this->newBuffer(this->tree.size());edkEnd();
        }
    }
    if(this->queue.size()){
        //update the objects speed
        edk::uint32 size = this->queue.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            tile = this->queue.get(i);edkEnd();
            if(tile){
                tile->position = this->incrementTilePosition(seconds,tile->position);edkEnd();
            }
        }
        //test if need remove the begginins
        while(true){
            tile = this->queue.get(0u);edkEnd();
            if(tile){
                tile->objPointer->position = tile->position + this->position;edkEnd();
                //calculate the bounding box
                tile->objPointer->calculateBoundingBox();edkEnd();
                if(!this->aabbPoints(incrementRectObject(tile->objPointer->getBoundingBox(),this->tree.getObjectDistance(tile->objPointer)),rect)){
                    //remove the tile
                    this->queue.popFront();edkEnd();
                    continue;
                }
            }
            //else break
            break;
        }
        //add a new object in the queue if need
        edk::uint32 pos = this->queue.size()-1u;edkEnd();
        edk::rectf32 newRect;edkEnd();
        while(true){
            tile = this->queue.get(pos);edkEnd();
            if(tile){
                tile->objPointer->position = tile->position + this->position;edkEnd();
                //calculate the bounding box
                tile->objPointer->calculateBoundingBox();edkEnd();
                if(this->aabbPoints(incrementRectObject(tile->objPointer->getBoundingBox(),this->tree.getObjectDistance(tile->objPointer)),rect)){
                    edk::size2f32 size = tile->objPointer->size;
                    if(size.width<0.f){
                        size.width*=-1.f;edkEnd();
                    }
                    if(size.height<0.f){
                        size.height*=-1.f;edkEnd();
                    }
                    newRect.origin.x = tile->position.x + size.width*0.5f;edkEnd();
                    newRect.size.width = tile->position.x - size.width*0.5f;edkEnd();
                    newRect.origin.y = tile->position.y + size.height*0.5f;edkEnd();
                    newRect.size.height = tile->position.y - size.height*0.5f;edkEnd();
                    //add a new tile
                    tile = this->buffer[0u];edkEnd();
                    this->buffer.incrementOrigin();edkEnd();
                    if(tile){
                        obj = this->getNextObject();
                        if(obj){
                            tile->objPointer=obj;edkEnd();
                            tile->position = this->firstPositionObject(newRect,tile->objPointer);edkEnd();
                            this->queue.pushBack(tile);edkEnd();
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
void edk::InfiniteHorizontal::updateInsideSize(edk::float32 seconds,edk::vec2f32 position,edk::size2f32 size){
    edk::rectf32 rect;edkEnd();
    rect.origin = position;edkEnd();
    rect.size = size;edkEnd();
    rect.convertIntoPoints();edkEnd();
    this->updateInsideRectPoints(seconds,rect);edkEnd();
}
void edk::InfiniteHorizontal::updateInsidePoints(edk::float32 seconds,edk::vec2f32 point1,edk::vec2f32 point2){
    edk::rectf32 rect;edkEnd();
    rect.origin = point1;edkEnd();
    rect.size.width = point2.x;edkEnd();
    rect.size.height = point2.y;edkEnd();
    this->updateInsideRectPoints(seconds,rect);edkEnd();
}

//draw the wallpaper
void edk::InfiniteHorizontal::draw(){
    edk::uint32 size = this->queue.size();edkEnd();
    edk::InfiniteHorizontal::tileWorldObject2D* tile;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        tile = this->queue.get(i);edkEnd();
        if(tile){
            tile->objPointer->position = tile->position + this->position;edkEnd();
            tile->objPointer->draw();edkEnd();
        }
    }
}
void edk::InfiniteHorizontal::drawWire(){
    edk::uint32 size = this->queue.size();edkEnd();
    edk::InfiniteHorizontal::tileWorldObject2D* tile;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        tile = this->queue.get(i);edkEnd();
        if(tile){
            tile->objPointer->position = tile->position + this->position;edkEnd();
            tile->objPointer->drawWire();edkEnd();
        }
    }
}
