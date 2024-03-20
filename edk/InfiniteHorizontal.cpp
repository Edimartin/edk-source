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

edk::Object2D edk::InfiniteHorizontal::tileWorldObject2D::staticObj;

edk::InfiniteHorizontal::InfiniteHorizontal(){
    this->speed=1.f;edkEnd();
    this->position = 0.f;edkEnd();
    this->time.start();edkEnd();
}
edk::InfiniteHorizontal::~InfiniteHorizontal(){
    //
    this->clean();edkEnd();
}

//increment the tile position
edk::vec2f32 edk::InfiniteHorizontal::incrementTilePosition(edk::float32 seconds,edk::vec2f32 position){
    position.x+=this->speed*seconds;edkEnd();
    return position;
}
//set the object first position
edk::vec2f32 edk::InfiniteHorizontal::firstPositionObject(edk::rectf32 rect,edk::Object2D* obj){
    edk::vec2f32 position;edkEnd();
    position = this->tree.getObjectPosition(obj);edkEnd();
    if(this->speed>=0.f){
        position.x = rect.size.width - obj->size.width*0.5f - this->tree.getObjectDistance(obj);edkEnd();
    }
    else{
        position.x = rect.origin.x + obj->size.width*0.5f + this->tree.getObjectDistance(obj);edkEnd();
    }
    return position;
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
    return this->tree.addObject(obj,distance);
}

void edk::InfiniteHorizontal::updateInsideRect(edk::float32 seconds,edk::rectf32 rect){
    rect.convertIntoPoints();edkEnd();
    this->updateInsideRectPoints(seconds,rect);edkEnd();
}
void edk::InfiniteHorizontal::updateInsideRectPoints(edk::float32 seconds,edk::rectf32 rect){
    edk::Object2D* obj=NULL;edkEnd();
    edk::InfiniteHorizontal::tileWorldObject2D* tile = NULL;edkEnd();
    edk::uint32 treeSize = this->tree.size();edkEnd();
    //test if have some object in the queue
    if(!this->queue.size()){
        if(this->buffer.size()){
            //add a new object in the queue
            tile = this->buffer[0u];edkEnd();
            this->buffer.incrementOrigin();edkEnd();
            if(tile){
                if(treeSize){
                    obj=this->tree.getObjectInPosition(this->rand.getRandNumber(treeSize));edkEnd();
                }
                else{
                    obj=this->tree.getObjectInPosition(0u);edkEnd();
                }
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
                if(!edk::collision::MathCollision::aabbPoints(tile->objPointer->getBoundingBox(),rect)){
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
                if(edk::collision::MathCollision::aabbPoints(tile->objPointer->getBoundingBox(),rect)){
                    newRect.origin.x = tile->position.x + tile->objPointer->size.width*0.5f;edkEnd();
                    newRect.size.width = tile->position.x - tile->objPointer->size.width*0.5f;edkEnd();
                    newRect.origin.y = tile->position.y + tile->objPointer->size.height*0.5f;edkEnd();
                    newRect.size.height = tile->position.y - tile->objPointer->size.height*0.5f;edkEnd();
                    //add a new tile
                    tile = this->buffer[0u];edkEnd();
                    this->buffer.incrementOrigin();edkEnd();
                    if(tile){
                        if(treeSize){
                            obj=this->tree.getObjectInPosition(this->rand.getRandNumber(treeSize));edkEnd();
                        }
                        else{
                            obj=this->tree.getObjectInPosition(0u);edkEnd();
                        }
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
