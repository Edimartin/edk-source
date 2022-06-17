#include "TileMap2D.h"

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


edk::tiles::tileContact2D::tileContact2D(){
    //
    this->tileA=this->tileB=0u;
}

edk::tiles::tileContact2D::~tileContact2D(){
    //
}

edk::tiles::TileMap2D::TileMap2D(){
    //
    this->tileSet=NULL;
    this->tileMap=NULL;
    this->colorMap=NULL;
    this->world=NULL;
    this->sizeMap = edk::size2ui32(0u,0u);
    this->color = 1.f;
}
edk::tiles::TileMap2D::TileMap2D(edk::tiles::TileSet2D* tileSet){
    this->world=NULL;
    this->tileMap=NULL;
    this->colorMap=NULL;
    this->sizeMap = edk::size2ui32(0u,0u);
    this->color = 1.f;
    this->setTileSet(tileSet);
}
edk::tiles::TileMap2D::~TileMap2D(){
    //
    this->deletePhysicsTiles();
    this->deleteTileMap();
    this->cleanWorldPointer();
}

//get the static object from tile with just one rectangle
edk::physics2D::PhysicObject2D* edk::tiles::TileMap2D::getStaticTile(edk::vec2ui32 position){
    edk::physics2D::PhysicObject2D* ret=NULL;
    //test if have a tileSet
    if(this->tileSet){
        //

        //then load the tiles
        edk::uint32 tileID = 0u;
        edk::physics2D::PhysicObject2D* temp2 = NULL;

        if(position.y < this->sizeMap.height
                &&
                position.x < this->sizeMap.width
                ){
            //load the tileID
            tileID = this->tileMap[position.y][position.x];
            if(tileID){
                //get the tilePhysicsObject
                temp2 = this->tileSet->getTilePhysicsObject(tileID);
                if(temp2){
                    //test if the temp2 is a dynamic physics tile
                    if(temp2->getType() == edk::physics::StaticBody){
                        //test if the tile have a physics rectangle object
                        if(temp2->physicMesh.getPolygonSize() == 1u){
                            //now test if the polygon is an rectangle
                            if(temp2->physicMesh.selectPolygon(0u)){
                                if(temp2->physicMesh.selectedGetVertexCount()==2u){
                                    edk::vec2f32 vertex = temp2->physicMesh.selectedGetVertexPosition(0u);
                                    if(vertex.x > +0.49f && vertex.x < +0.51f && vertex.y > +0.49f && vertex.y < +0.51f){
                                        vertex = temp2->physicMesh.selectedGetVertexPosition(1u);
                                        if(vertex.x < -0.49f && vertex.x > -0.51f && vertex.y < -0.49f && vertex.y > -0.51f){
                                            ret = temp2;
                                        }
                                    }
                                    else if(vertex.x < -0.49f && vertex.x > -0.51f && vertex.y < -0.49f && vertex.y > -0.51f){
                                        vertex = temp2->physicMesh.selectedGetVertexPosition(1u);
                                        if(vertex.x > +0.49f && vertex.x < +0.51f && vertex.y > +0.49f && vertex.y < +0.51f){
                                            ret = temp2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return ret;
}
edk::physics2D::PhysicObject2D* edk::tiles::TileMap2D::getStaticTile(edk::uint32 positionX,edk::uint32 positionY){
    return this->getStaticTile(edk::vec2ui32(positionX,positionY));
}
//compare two static objects
bool edk::tiles::TileMap2D::compareStaticTile(edk::physics2D::PhysicObject2D* tile1,edk::physics2D::PhysicObject2D* tile2){
    bool ret=false;
    //test if have the two objects
    if(tile1 && tile2){
        //test if the tiles are the same
        if(tile1 == tile2) return true;

        //test if the two objects are the same type
        if(tile1->getType() == tile2->getType()){
            ret=true;
            //test the physics mesh of the tile
            if(tile1->physicMesh.getPolygonSize() == tile2->physicMesh.getPolygonSize()){
                //test if have the polygons with the same vertex positions
                edk::uint32 size = tile1->physicMesh.getPolygonSize();
                edk::vec2f32 position1,position2,position3,position4;
                edk::uint32 sizeVertex = 0u;
                edk::float32 value1,value2;

                for(edk::uint32 i=0u;i<size;i++){
                    //select the polygon
                    if(tile1->physicMesh.selectPolygon(i) && tile2->physicMesh.selectPolygon(i)){
                        //compare the vertexes size of the polygon
                        if(tile1->physicMesh.selectedGetVertexCount() == tile2->physicMesh.selectedGetVertexCount()){
                            //test the vertexes
                            sizeVertex = tile1->physicMesh.selectedGetVertexCount();
                            if(sizeVertex==2u){
                                //compare the vertexes
                                position1 = tile1->physicMesh.selectedGetVertexPosition(0u);
                                position2 = tile1->physicMesh.selectedGetVertexPosition(1u);
                                position3 = tile2->physicMesh.selectedGetVertexPosition(0u);
                                position4 = tile2->physicMesh.selectedGetVertexPosition(1u);

                                //compare the cactangle
                                if(!(((position1.x>position3.x-0.01 && position1.x<position3.x+0.01
                                       &&
                                       position1.y>position3.y-0.01 && position1.y<position3.y+0.01)
                                      &&
                                      (position2.x>position4.x-0.01 && position2.x<position4.x+0.01
                                       &&
                                       position2.y>position4.y-0.01 && position2.y<position4.y+0.01))
                                     ||
                                     ((position1.x>position4.x-0.01 && position1.x<position4.x+0.01
                                       &&
                                       position1.y>position4.y-0.01 && position1.y<position4.y+0.01)
                                      &&
                                      (position2.x>position3.x-0.01 && position2.x<position3.x+0.01
                                       &&
                                       position2.y>position3.y-0.01 && position2.y<position3.y+0.01)))
                                        ){
                                    //
                                    ret=false;
                                    break;
                                }
                            }
                            else{
                                for(edk::uint32 j=0u;j<sizeVertex;j++){
                                    //test the vertex position
                                    position1 = tile1->physicMesh.selectedGetVertexPosition(i);
                                    position2 = tile2->physicMesh.selectedGetVertexPosition(i);
                                    //compare the vertexes
                                    if(!(position1.x-0.01>position2.x && position1.x+0.01<position2.x
                                         &&
                                         position1.y-0.01>position2.y && position1.y+0.01<position2.y)){
                                        //
                                        ret=false;
                                        break;
                                    }
                                }
                                if(!ret) break;
                            }
                        }
                        else{
                            ret=false;
                            break;
                        }

                        //compare the physics variables
                        value1 = tile1->physicMesh.selectedGetDensity();
                        value2 = tile2->physicMesh.selectedGetDensity();
                        if(!(value1>value2-0.01 && value1<value2+0.01)){
                            ret=false;
                            break;
                        }
                        value1 = tile1->physicMesh.selectedGetFriction();
                        value2 = tile2->physicMesh.selectedGetFriction();
                        if(!(value1>value2-0.01 && value1<value2+0.01)){
                            ret=false;
                            break;
                        }
                        value1 = tile1->physicMesh.selectedGetRestitution();
                        value2 = tile2->physicMesh.selectedGetDensity();
                        if(!(value1>value2-0.01 && value1<value2+0.01)){
                            ret=false;
                            break;
                        }
                    }
                    else{
                        ret=false;
                        break;
                    }
                }
            }
            else ret=false;
        }
    }
    return ret;
}

//set the tileSet
bool edk::tiles::TileMap2D::setTileSet(edk::tiles::TileSet2D* tileSet){
    //remove all physics objects
    this->deletePhysicsTiles();
    this->treePhysics.setTileSet(tileSet);
    this->treeStaticPhysics.setTileSet(tileSet);
    return (this->tileSet = tileSet);
}
edk::tiles::TileSet2D* edk::tiles::TileMap2D::getTileSet(){
    return this->tileSet;
}
void edk::tiles::TileMap2D::removeTileSet(){
    this->deletePhysicsTiles();
    this->treePhysics.setTileSet(NULL);
    this->treeStaticPhysics.setTileSet(NULL);
    this->tileSet=NULL;
}
//set a tile in the tileMap
bool edk::tiles::TileMap2D::setTile(edk::uint32 tileID,edk::vec2ui32 position){
    //test the position
    if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
        //set the position
        this->tileMap[position.y][position.x] = tileID;
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileMap2D::setTile(edk::uint32 tileID,edk::uint32 positionX,edk::uint32 positionY){
    //
    return this->setTile(tileID,edk::vec2ui32(positionX,positionY));
}
bool edk::tiles::TileMap2D::setTile(edk::uint32 tileID,edk::uint32 position){
    if(position){
        position--;
        return this->setTile(tileID,edk::vec2ui32(position%this->sizeMap.width,position/this->sizeMap.width));
    }
    return false;
}
//set a color in the colorMap
bool edk::tiles::TileMap2D::setTileColor(edk::color4f32 color,edk::vec2ui32 position){
    //test the position
    if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
        //set the position
        this->colorMap[position.y][position.x] = color;
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::vec2ui32 position){
    return this->setTileColor(edk::color4f32(r,g,b,a),position);
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::vec2ui32 position){
    return this->setTileColor(r,g,b,1.f,position);
}
bool edk::tiles::TileMap2D::setTileColor(edk::color4f32 color,edk::uint32 positionX,edk::uint32 positionY){
    return this->setTileColor(color,edk::vec2ui32 (positionX,positionY));
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::uint32 positionX,edk::uint32 positionY){
    return this->setTileColor(edk::color4f32 (r,g,b,a),positionX,positionY);
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::uint32 positionX,edk::uint32 positionY){
    return this->setTileColor(r,g,b,1.f,positionX,positionY);
}
bool edk::tiles::TileMap2D::setTileColor(edk::color4f32 color,edk::uint32 position){
    if(position){
        position--;
        return this->setTileColor(color,edk::vec2ui32(position%this->sizeMap.width,position/this->sizeMap.width));
    }
    return false;
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::uint32 position){
    return this->setTileColor(edk::color4f32 (r,g,b,a),position);
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::uint32 position){
    return this->setTileColor(r,g,b,1.f,position);
}
//set the color of all tiles
void edk::tiles::TileMap2D::setColor(edk::color4f32 color){
    this->color = color;
    if(this->colorMap){
        for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                this->colorMap[y][x] = color;
            }
        }
    }
}
void edk::tiles::TileMap2D::setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setColor(edk::color4f32 (r,g,b,a));
}
void edk::tiles::TileMap2D::setColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setColor(edk::color4f32 (r,g,b,1.f));
}
void edk::tiles::TileMap2D::setAlpha(edk::float32 a){
    this->color.a = a;
    if(this->colorMap){
        for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                this->colorMap[y][x].a = a;
            }
        }
    }
}
//set the tileMap position
void edk::tiles::TileMap2D::setPosition(edk::vec2f32 position){
    //scale the position
    position.x = position.x * (1.f/this->scaleMap.width);
    position.y = position.y * (1.f/this->scaleMap.height);
    //
    edk::vec2f32 translate = position - this->positionMap;
    this->positionMap = position;

    if(this->world && (translate.x || translate.y)){
        //scale the physics
        edk::physics2D::PhysicObject2D*  temp=NULL;
        edk::uint32 size = this->treePhysics.size();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->treePhysics.getObjectInPosition(i);
            if(temp){
                //scale the object and position
                temp->position+=translate;
                //update to the world
                this->world->updateObjectStatus(temp);
            }
        }
        size = this->treeStaticPhysics.size();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->treeStaticPhysics.getObjectInPosition(i);
            if(temp){
                //scale the object and position
                temp->position+=translate;
                //update to the world
                this->world->updateObjectStatus(temp);
            }
        }

    }
}
void edk::tiles::TileMap2D::setPosition(edk::float32 positionX,edk::float32 positionY){
    //
    this->setPosition(edk::vec2f32(positionX,positionY));
}
edk::vec2f32 edk::tiles::TileMap2D::getTileWorldPosition(edk::vec2ui32 position){
    return edk::vec2f32(((edk::float32)position.x + this->positionMap.x) * this->scaleMap.width,
                        ((this->sizeMap.height-1 - (edk::float32)position.y) + this->positionMap.y) * this->scaleMap.height
                        );
}
edk::vec2f32 edk::tiles::TileMap2D::getTileWorldPosition(edk::uint32 positionX,edk::uint32 positionY){
    return edk::vec2f32((positionX + this->positionMap.x) * this->scaleMap.width,
                        ((this->sizeMap.height-1 - positionY) + this->positionMap.y) * this->scaleMap.height
                        );
}
//Set scale the map
bool edk::tiles::TileMap2D::setScaleMap(edk::size2f32 scale){
    if(scale.width != 0.f && scale.height!=0.f){
        //get the position
        edk::vec2f32 positionTemp = this->getPosition();


        this->scaleMap = scale;

        if(this->world){
            //scale the physics
            edk::physics2D::PhysicObject2D*  temp=NULL;
            edk::uint32 size = this->treePhysics.size();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->treePhysics.getObjectInPosition(i);
                if(temp){
                    //scale the object and position
                    temp->position.x*=this->scaleMap.width;
                    temp->position.y*=this->scaleMap.height;
                    temp->size = this->scaleMap;
                    //update to the world
                    this->world->updateObjectStatus(temp);
                }
            }
            size = this->treeStaticPhysics.size();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->treeStaticPhysics.getObjectInPosition(i);
                if(temp){
                    //scale the object and position
                    temp->position.x*=this->scaleMap.width;
                    temp->position.y*=this->scaleMap.height;
                    temp->size = this->scaleMap;
                    //update to the world
                    this->world->updateObjectStatus(temp);
                }
            }
        }

        //scale the position
        this->setPosition(positionTemp);

        return true;
    }
    return false;
}
bool edk::tiles::TileMap2D::setScaleMap(edk::float32 width,edk::float32 height ){
    return this->setScaleMap(edk::size2f32(width,height));
}
//Set World pointer
bool edk::tiles::TileMap2D::setWorld(edk::physics2D::World2D* world){
    this->cleanWorldPointer();
    this->world=world;
    if(this->world){
        this->world->addContactCallback(this);
        return true;
    }
    //else
    return false;
}
void edk::tiles::TileMap2D::cleanWorldPointer(){
    if(this->world){
        //remove callback
        this->world->removeContactCallback(this);
        //remove physics objects
        this->deletePhysicsTiles();
    }
    //delete all physics objects
    this->treePhysics.deleteAll();
    this->treeStaticPhysics.deleteAll();
    this->world=NULL;
}
//cleanTiles
void edk::tiles::TileMap2D::cleanTiles(){
    if(this->tileMap){
        for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                this->tileMap[y][x] = 0u;
                this->colorMap[y][x] = this->color;
            }
        }
    }
}
//Create a new tileMap
bool edk::tiles::TileMap2D::newTileMap(edk::size2ui32 size){
    //delete the last tileMap
    this->deleteTileMap();
    //test the size
    if(size.width && size.height){
        //delete the last tileMap
        bool alloc=false;

        //create a new tileMap
        this->tileMap = new edk::uint32*[size.height];
        if(this->tileMap){
            alloc=true;
            //create the width's
            for(edk::uint32 i=0u;i<size.height;i++){
                //
                this->tileMap[i]=new edk::uint32[size.width];
                if(tileMap[i]){
                    //clean the vector
                    for(edk::uint32 j=0u;j<size.width;j++){
                        this->tileMap[i][j]=0u;
                    }
                }
                else{
                    alloc=false;
                }
            }
        }

        if(alloc){
            //create a new colorMap
            this->colorMap = new edk::color4f32*[size.height];
            if(this->colorMap){
                //create the width's
                for(edk::uint32 i=0u;i<size.height;i++){
                    //
                    this->colorMap[i]=new edk::color4f32[size.width];
                    if(tileMap[i]){
                        //clean the vector
                        for(edk::uint32 j=0u;j<size.width;j++){
                            this->colorMap[i][j] = this->color;
                        }
                    }
                    else{
                        alloc=false;
                    }
                }
                //test if is alloc
                if(!alloc){
                    this->deleteTileMap();
                }
                else{
                    this->sizeMap=size;
                    return true;
                }
            }
        }
        else{
            this->deleteTileMap();
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileMap2D::newTileMap(edk::uint32 width,edk::uint32 heigth){
    //
    return this->newTileMap(edk::size2ui32(width,heigth));
}
//delete tileMap
void edk::tiles::TileMap2D::deleteTileMap(){
    //Delete all tileMaps
    if(this->tileMap){
        //remove all physics objects
        this->deletePhysicsTiles();
        for(edk::uint32 i=0u;i<this->sizeMap.height;i++){
            if(this->tileMap[i]){
                delete[] this->tileMap[i];
            }
        }
        delete[] this->tileMap;
        this->sizeMap = edk::size2ui32(0u,0u);
    }
    this->tileMap=NULL;
    //delete the colorMap
    if(this->colorMap){
        //remove all physics objects
        for(edk::uint32 i=0u;i<this->sizeMap.height;i++){
            if(this->colorMap[i]){
                delete[] this->colorMap[i];
            }
        }
        delete[] this->colorMap;
        this->sizeMap = edk::size2ui32(0u,0u);
    }
    this->colorMap=NULL;
}
//return true if have a tileMap
bool edk::tiles::TileMap2D::haveTileMap(){
    if(this->tileMap){
        return true;
    }
    return false;
}
//delete physicObjects
void edk::tiles::TileMap2D::deletePhysicsTiles(){
    if(this->world){
        //remove all the physics objects
        edk::uint32 size = this->treePhysics.size();
        edk::tiles::TileMap2D::PhysicsTiles* temp = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->treePhysics.getElementInPosition(i);
            if(temp){
                if(temp->position.x<this->sizeMap.width
                        &&
                        temp->position.y<this->sizeMap.height){
                    //set the map
                    this->tileMap[temp->position.y][temp->position.x] = temp->tile;
                }
                this->world->removeObject(temp->object);
                temp=NULL;
            }
        }
        this->treePhysics.deleteAll();

        edk::tiles::TileMap2D::StaticTileObjects* temp2=NULL;
        //remove all the physics static objects
        size = this->treeStaticPhysics.size();
        for(edk::uint32 i=0u;i<size;i++){
            temp2 = this->treeStaticPhysics.getElementInPosition(i);
            if(temp2){
                this->world->removeObject(temp2->object);
                temp2=NULL;
            }
        }
        this->treeStaticPhysics.deleteAll();
    }
}
bool edk::tiles::TileMap2D::deletePhysicTile(edk::vec2ui32 position){
    if(this->world){
        bool ret=false;
        //load the physics object
        edk::tiles::TileMap2D::PhysicsTiles* temp = this->treePhysics.getPhysicsTileInPosition(position);
        if(temp){
            //remove the object from the world
            this->world->removeObject(temp->object);
            //clean the tile in the map
            if(temp->position.x<this->sizeMap.width
                    &&
                    temp->position.y<this->sizeMap.height){
                //set the map
                this->tileMap[temp->position.y][temp->position.x] = temp->tile;
            }
            //delete the tilePhysics
            this->treePhysics.deleteObject(temp->object);
            ret=true;
        }
        edk::tiles::TileMap2D::StaticTileObjects* temp2 = this->treeStaticPhysics.getPhysicsTileInPosition(position);
        if(temp2){
            //remove the object from the world
            this->world->removeObject(temp2->object);
            //delete the object
            this->treeStaticPhysics.deleteObject(temp2->object);
            ret=true;
        }
    }
    return false;
}
bool edk::tiles::TileMap2D::deletePhysicTile(edk::uint32 positionX,edk::uint32 positionY){
    return this->deletePhysicTile(edk::vec2ui32(positionX,positionY));
}
//add physics tiles
bool edk::tiles::TileMap2D::loadPhysicsTiles(){
    //remove world objects
    this->deletePhysicsTiles();
    //test if have the world
    if(this->world){
        //test if have a tileSet
        if(this->tileSet){
            //then load the tiles
            edk::uint32 tileID = 0u;
            edk::physics2D::PhysicObject2D* temp2 = NULL;
            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                    //load the tileID
                    tileID = this->tileMap[y][x];
                    if(tileID){
                        //get the tilePhysicsObject
                        temp2 = this->tileSet->getTilePhysicsObject(tileID);
                        if(temp2){
                            //

                            //create the physics object
                            edk::physics2D::PhysicObject2D* temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(x,y),tileID,temp2->getType(),temp2->isSensor());

                            if(temp){
                                //copy the tileSet object to te temp
                                temp->cloneFrom(temp2);

                                temp->position = edk::vec2f32((edk::float32)x,((edk::float32)this->sizeMap.height-1.f) - y)
                                        + this->positionMap;
                                temp->position.x *= this->scaleMap.width;
                                temp->position.y *= this->scaleMap.height;
                                temp->size = this->scaleMap;
                                //add the new object to the physics world
                                //temp->size = this->sizeMap;
                                this->world->addObject(temp);
                                //remove the ID from the tileMap
                                this->tileMap[y][x] = 0u;
                            }
                            else{
                                this->treePhysics.deleteObject(temp);
                            }
                        }
                    }
                }
            }
            return true;
        }
    }
    return false;
}
bool edk::tiles::TileMap2D::loadPhysicTile(edk::vec2ui32 position){
    this->deletePhysicTile(position);
    //test if habe a world
    if(this->world){
        //test if have a tileSet
        if(this->tileSet){
            //test if have the position
            if(position.x<this->sizeMap.width
                    &&
                    position.y<this->sizeMap.height){
                //load the tileID
                edk::uint32 tileID = this->tileMap[position.y][position.x];
                if(tileID){
                    edk::physics2D::PhysicObject2D* object = this->tileSet->getTilePhysicsObject(tileID);
                    if(object){
                        //create the physics object
                        edk::physics2D::PhysicObject2D* temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(position.x,position.y),tileID,object->getType(),object->isSensor());
                        if(temp){
                            //copy the tileSet object to te temp
                            temp->cloneFrom(object);

                            temp->position = edk::vec2f32((edk::float32)position.x,((edk::float32)this->sizeMap.height-1.f) - position.y)
                                    + this->positionMap;
                            temp->position.x *= this->scaleMap.width;
                            temp->position.y *= this->scaleMap.height;
                            temp->size = this->scaleMap;
                            //add the new object to the physics world
                            //temp->size = this->sizeMap;
                            this->world->addObject(temp);
                            //remove the ID from the tileMap
                            this->tileMap[position.y][position.x] = 0u;
                            return true;
                        }
                        else{
                            this->treePhysics.deleteObject(temp);
                        }
                    }
                }
            }
        }
    }
    return false;
}
bool edk::tiles::TileMap2D::loadPhysicTile(edk::uint32 positionX,edk::uint32 positionY){
    //
    return this->loadPhysicTile(edk::vec2ui32(positionX,positionY));
}
//load static physics tiles merged to generate boxes
bool edk::tiles::TileMap2D::loadPhysicsTilesStaticMerged(){
    //test if have the world
    if(this->world){
        //test if have a tileSet
        if(this->tileSet){
            edk::uint32 width,height;
            //then load the tiles
            edk::uint32 tileID = 0u;
            edk::physics2D::PhysicObject2D* temp = NULL;
            edk::physics2D::PhysicObject2D* temp1 = NULL;
            edk::physics2D::PhysicObject2D* temp2 = NULL;
            edk::physics2D::PhysicObject2D* temp3 = NULL;
            bool canContinue=true;
            //rect for the polygon positions in the map
            edk::rectui32 rect;
            edk::rectf32 rectf;
            edk::vector::Stack<edk::vec2ui32> positions;
            edk::vec2ui32 position;
            edk::vec2f32 positionf;
            edk::size2f32 sizef;
            //vertexes
            edk::vec2f32 v1,v2;

            //create the rectangle
            edk::shape::Rectangle2D rectangle;
            rectangle.setPivoToCenter();
            //
            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                    //If aready have the position in physics objects. Then it not create another object
                    if(this->treeStaticPhysics.havePosition(edk::vec2ui32(x,y))) continue;

                    //test if the object is a valid static with one rectangle
                    if((temp1 = this->getStaticTile(x,y))){
                        positions.clean();

                        width=x;
                        height=y;
                        //set rect
                        rect.origin.x=x;
                        rect.origin.y=y;

                        rect.size.width=width;
                        rect.size.height=height;

                        position.x = x;
                        position.y = y;
                        positions.pushBack(position);


                        temp3=temp1;


                        //search for the neibors in X
                        do{
                            temp2=NULL;
                            width++;
                            //height++;
                            if(height<this->sizeMap.height && width<this->sizeMap.width){
                                if(!this->treeStaticPhysics.havePosition(edk::vec2ui32(width,height))){
                                    temp2 = this->getStaticTile(width,height);
                                    if(temp2){
                                        //compare if the temp1 and temp2 are equal
                                        if(this->compareStaticTile(temp1,temp2)){
                                            //copy the last values
                                            rect.size.width=width;
                                            rect.size.height=height;
                                            temp3=temp2;

                                            position.x = width;
                                            position.y = height;
                                            positions.pushBack(position);
                                        }
                                        else{
                                            temp2=NULL;
                                        }
                                    }
                                }
                            }
                        }while(temp2);

                        canContinue=true;
                        //
                        //search for other neibors in Y
                        for(edk::uint32 j=y+1u;j<this->sizeMap.height;j++){
                            for(edk::uint32 i=x;i<width;i++){
                                if(!this->treeStaticPhysics.havePosition(edk::vec2ui32(i,j))){
                                    //search for all objects as like the temp1
                                    temp2 = this->getStaticTile(i,j);
                                    if(temp2){
                                        //test if the temp2 is equal temp1
                                        if(!this->compareStaticTile(temp1,temp2)){
                                            canContinue=false;
                                            break;
                                        }
                                    }
                                    else{
                                        //else there is a hole in the tile.
                                        canContinue=false;
                                        break;
                                    }
                                }
                                else{
                                    canContinue=false;
                                    break;
                                }
                            }
                            //
                            if(!canContinue) break;
                            else{
                                for(edk::uint32 i=x;i<width;i++){
                                    //push back the positions
                                    position.x = i;
                                    position.y = j;
                                    positions.pushBack(position);

                                    rect.size.width=i;
                                    rect.size.height=j;

                                    temp3=temp2;
                                }
                            }
                        }

                        //test if the rect size is different than origin
                        if(rect.size.width>rect.origin.x
                                ||
                                rect.size.height>rect.origin.y
                                ){
                            //generate the new physics object
                            positionf = this->getTileWorldPosition(rect.origin.x,rect.origin.y);
                            temp1->physicMesh.selectPolygon(0u);
                            v1 = temp1->physicMesh.selectedGetVertexPosition(0u);
                            v2 = temp1->physicMesh.selectedGetVertexPosition(1u);
                            if(v2.x < v1.x) v1.x=v2.x;
                            if(v2.y > v1.y) v1.y=v2.y;
                            rectf.origin.x = positionf.x + (v1.x * this->getScaleMap().width);
                            rectf.origin.y = positionf.y + (v1.y * this->getScaleMap().height);

                            temp3->physicMesh.selectPolygon(0u);
                            positionf = this->getTileWorldPosition(rect.size.width,rect.size.height);
                            v1 = temp3->physicMesh.selectedGetVertexPosition(0u);
                            v2 = temp3->physicMesh.selectedGetVertexPosition(1u);
                            if(v2.x > v1.x) v1.x=v2.x;
                            if(v2.y < v1.y) v1.y=v2.y;
                            rectf.size.width = positionf.x + (v1.x * this->getScaleMap().width);
                            rectf.size.height = positionf.y + (v1.y * this->getScaleMap().height);

                            sizef.width = rectf.size.width - rectf.origin.x;
                            sizef.height = rectf.size.height - rectf.origin.y;

                            //calculate the object position
                            positionf.x = sizef.width*0.5f + (rectf.origin.x);
                            positionf.y = sizef.height*0.5f + (rectf.origin.y);

                            //create the object
                            temp = this->treeStaticPhysics.newObjectInPositions(&positions,tileID,edk::physics::StaticBody,false);

                            if(temp){
                                //copy the tileSet object to te temp
                                temp->physicMesh.addPolygon(rectangle);

                                temp->position = positionf;
                                temp->size.width = edk::Math::module(sizef.width);
                                temp->size.height = edk::Math::module(sizef.height);
                                //add the new object to the physics world
                                if(!this->world->addObject(temp)){
                                    this->treeStaticPhysics.deleteObject(temp);
                                }
                            }
                            else{
                                this->treeStaticPhysics.deleteObject(temp);
                            }
                        }
                        else{
                            //else just clone the object
                            positionf = this->getTileWorldPosition(rect.origin.x,rect.origin.y);

                            //create the object
                            temp = this->treeStaticPhysics.newObjectInPositions(&positions,tileID,edk::physics::StaticBody,false);

                            if(temp){
                                //copy the tileSet object to te temp
                                temp->physicMesh.addPolygon(rectangle);

                                temp->position = positionf;
                                temp->size = this->scaleMap;
                                //add the new object to the physics world
                                if(!this->world->addObject(temp)){
                                    this->treeStaticPhysics.deleteObject(temp);
                                }
                            }
                            else{
                                this->treeStaticPhysics.deleteObject(temp);
                            }
                        }
                        //it create the object in to the treeStaticOhysics. Then it don't need make an object in treePhysics
                        continue;
                    }

                    //IF it din't create the object in treeStaticPhysics. Then it make the tile as a object in the old way. But only for static bodies

                    //load the tileID
                    tileID = this->tileMap[y][x];
                    if(tileID){
                        //get the tilePhysicsObject
                        temp1 = this->tileSet->getTilePhysicsObject(tileID);
                        if(temp1){
                            //test if the temp1 is a dynamic physics tile
                            if(temp1->getType() == edk::physics::StaticBody){
                                //create the physics object
                                temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(x,y),tileID,temp1->getType(),temp1->isSensor());

                                if(temp){
                                    //copy the tileSet object to te temp
                                    temp->cloneFrom(temp1);

                                    temp->position = edk::vec2f32((edk::float32)x,((edk::float32)this->sizeMap.height-1.f) - y)
                                            + this->positionMap;
                                    temp->position.x *= this->scaleMap.width;
                                    temp->position.y *= this->scaleMap.height;
                                    temp->size = this->scaleMap;
                                    //add the new object to the physics world
                                    //temp->size = this->sizeMap;
                                    this->world->addObject(temp);
                                    //remove the ID from the tileMap
                                    this->tileMap[y][x] = 0u;
                                }
                                else{
                                    this->treePhysics.deleteObject(temp);
                                }
                            }
                        }
                    }
                }
            }
            positions.clean();
            return true;
        }
    }
    return false;
}
//load dynamic and kinematic into the world
bool edk::tiles::TileMap2D::loadPhysicsTilesDynamic(){
    //test if have the world
    if(this->world){
        //test if have a tileSet
        if(this->tileSet){
            //then load the tiles
            edk::uint32 tileID = 0u;
            edk::physics2D::PhysicObject2D* temp2 = NULL;
            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                    //load the tileID
                    tileID = this->tileMap[y][x];
                    if(tileID){
                        //get the tilePhysicsObject
                        temp2 = this->tileSet->getTilePhysicsObject(tileID);
                        if(temp2){
                            //test if the temp2 is a dynamic physics tile
                            if(temp2->getType() == edk::physics::DynamicBody){

                                //create the physics object
                                edk::physics2D::PhysicObject2D* temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(x,y),tileID,temp2->getType(),temp2->isSensor());

                                if(temp){
                                    //copy the tileSet object to te temp
                                    temp->cloneFrom(temp2);

                                    temp->position = edk::vec2f32((edk::float32)x,((edk::float32)this->sizeMap.height-1.f) - y)
                                            + this->positionMap;
                                    temp->position.x *= this->scaleMap.width;
                                    temp->position.y *= this->scaleMap.height;
                                    temp->size = this->scaleMap;
                                    //add the new object to the physics world
                                    //temp->size = this->sizeMap;
                                    this->world->addObject(temp);
                                    //remove the ID from the tileMap
                                    this->tileMap[y][x] = 0u;
                                }
                                else{
                                    this->treePhysics.deleteObject(temp);
                                }
                            }
                        }
                    }
                }
            }
            return true;
        }
    }
    return false;
}
bool edk::tiles::TileMap2D::loadPhysicsTilesKinematic(){
    //test if have the world
    if(this->world){
        //test if have a tileSet
        if(this->tileSet){
            //then load the tiles
            edk::uint32 tileID = 0u;
            edk::physics2D::PhysicObject2D* temp2 = NULL;
            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                    //load the tileID
                    tileID = this->tileMap[y][x];
                    if(tileID){
                        //get the tilePhysicsObject
                        temp2 = this->tileSet->getTilePhysicsObject(tileID);
                        if(temp2){
                            //test if the temp2 is a dynamic physics tile
                            if(temp2->getType() == edk::physics::KinematicBody){

                                //create the physics object
                                edk::physics2D::PhysicObject2D* temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(x,y),tileID,temp2->getType(),temp2->isSensor());

                                if(temp){
                                    //copy the tileSet object to te temp
                                    temp->cloneFrom(temp2);

                                    temp->position = edk::vec2f32((edk::float32)x,((edk::float32)this->sizeMap.height-1.f) - y)
                                            + this->positionMap;
                                    temp->position.x *= this->scaleMap.width;
                                    temp->position.y *= this->scaleMap.height;
                                    temp->size = this->scaleMap;
                                    //add the new object to the physics world
                                    //temp->size = this->sizeMap;
                                    this->world->addObject(temp);
                                    //remove the ID from the tileMap
                                    this->tileMap[y][x] = 0u;
                                }
                                else{
                                    this->treePhysics.deleteObject(temp);
                                }
                            }
                        }
                    }
                }
            }
            return true;
        }
    }
    return false;
}
bool edk::tiles::TileMap2D::loadPhysicsTilesKinematicAndDynamic(){
    //test if have the world
    if(this->world){
        //test if have a tileSet
        if(this->tileSet){
            //then load the tiles
            edk::uint32 tileID = 0u;
            edk::physics2D::PhysicObject2D* temp2 = NULL;
            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                    //load the tileID
                    tileID = this->tileMap[y][x];
                    if(tileID){
                        //get the tilePhysicsObject
                        temp2 = this->tileSet->getTilePhysicsObject(tileID);
                        if(temp2){
                            //test if the temp2 is a dynamic physics tile
                            if(temp2->getType() == edk::physics::KinematicBody || temp2->getType() == edk::physics::DynamicBody){

                                //create the physics object
                                edk::physics2D::PhysicObject2D* temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(x,y),tileID,temp2->getType(),temp2->isSensor());

                                if(temp){
                                    //copy the tileSet object to te temp
                                    temp->cloneFrom(temp2);

                                    temp->position = edk::vec2f32((edk::float32)x,((edk::float32)this->sizeMap.height-1.f) - y)
                                            + this->positionMap;
                                    temp->position.x *= this->scaleMap.width;
                                    temp->position.y *= this->scaleMap.height;
                                    temp->size = this->scaleMap;
                                    //add the new object to the physics world
                                    //temp->size = this->sizeMap;
                                    this->world->addObject(temp);
                                    //remove the ID from the tileMap
                                    this->tileMap[y][x] = 0u;
                                }
                                else{
                                    this->treePhysics.deleteObject(temp);
                                }
                            }
                        }
                    }
                }
            }
            return true;
        }
    }
    return false;
}

//return the physicTileObject
edk::physics2D::PhysicObject2D* edk::tiles::TileMap2D::getPhysicTile(edk::vec2ui32 position){
    //test if have a world
    if(this->world){
        //test if have a tileSet
        if(this->tileSet){
            edk::physics2D::PhysicObject2D* ret=NULL;
            //load the physicsObject
            ret =  this->treePhysics.getPhysicsObjectInPosition(edk::vec2ui32(position.x,position.y));
            if(ret){
                return ret;
            }
            else{
                return this->treeStaticPhysics.getPhysicsObjectInPosition(edk::vec2ui32(position.x,position.y));
            }
        }
    }
    return NULL;
}
edk::physics2D::PhysicObject2D* edk::tiles::TileMap2D::getPhysicTile(edk::uint32 positionX,edk::uint32 positionY){
    return this->getPhysicTile(edk::vec2ui32 (positionX,positionY));
}
//test ih have the physicsObject
bool edk::tiles::TileMap2D::havePhysicObject(edk::physics2D::PhysicObject2D* object){
    if(this->treePhysics.haveObject(object)){
        return true;
    }
    //else return it from another tree
    return this->treeStaticPhysics.haveObject(object);
}
edk::vec2ui32 edk::tiles::TileMap2D::getPhysicObjectPosition(edk::physics2D::PhysicObject2D* object){
    if(this->treePhysics.haveObject(object)){
        return this->treePhysics.getPositionOfObject(object);
    }
    if(this->treeStaticPhysics.haveObject(object) && this->treeStaticPhysics.getPositionSizeOfObject(object)){
        return this->treeStaticPhysics.getPositionOfObject(object,0u);
    }
    return edk::vec2ui32(0u,0u);
}

//GETTERS
//return the tileID
edk::uint32 edk::tiles::TileMap2D::getTileID(edk::vec2ui32 position){
    //test the position
    if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
        //set the position
        return this->tileMap[position.y][position.x];
    }
    return 0u;
}
edk::uint32 edk::tiles::TileMap2D::getTileID(edk::uint32 positionX,edk::uint32 positionY){
    return this->getTileID(edk::vec2ui32(positionX,positionY));
}
edk::uint32 edk::tiles::TileMap2D::getTileID(edk::uint32 position){
    if(position){
        if(this->sizeMap.width && this->sizeMap.height){
            position--;
            return this->getTileID(edk::vec2ui32(position%this->sizeMap.width,position/this->sizeMap.width));
        }
    }
    return 0u;
}
//return the tileColor
edk::color4f32 edk::tiles::TileMap2D::getTileColor(edk::vec2ui32 position){
    edk::color4f32 ret;
    //test the position
    if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
        //set the position
        ret=this->colorMap[position.y][position.x];
    }
    return ret;
}
edk::color4f32 edk::tiles::TileMap2D::getTileColor(edk::uint32 positionX,edk::uint32 positionY){
    return this->getTileColor(edk::vec2ui32(positionX,positionY));
}
edk::color4f32 edk::tiles::TileMap2D::getTileColor(edk::uint32 position){
    edk::color4f32 ret;
    if(position){
        if(this->sizeMap.width && this->sizeMap.height){
            position--;
            ret=this->getTileColor(edk::vec2ui32(position%this->sizeMap.width,position/this->sizeMap.width));
        }
    }
    return ret;
}
//return the size of the map
edk::size2ui32 edk::tiles::TileMap2D::getMapSize(){
    return this->sizeMap;
}
//return the scale of the map
edk::size2f32 edk::tiles::TileMap2D::getScaleMap(){
    return this->scaleMap;
}
//return the position
edk::vec2f32 edk::tiles::TileMap2D::getPosition(){
    return edk::vec2f32(this->positionMap.x * this->scaleMap.width,
                        this->positionMap.y * this->scaleMap.height
                        );
}
edk::float32 edk::tiles::TileMap2D::getPositionX(){
    return this->positionMap.x * this->scaleMap.width;
}
edk::float32 edk::tiles::TileMap2D::getPositionY(){
    return this->positionMap.y * this->scaleMap.height;
}
//get the tile position in the position
edk::vec2ui32 edk::tiles::TileMap2D::getPointPosition(edk::vec2f32 point,bool* inside){
    edk::vec2ui32 ret(0u,0u);
    //scale the points
    point.x /= this->scaleMap.width;
    point.y /= this->scaleMap.height;

    point.y+=0.5f-this->positionMap.x;
    point.x+=0.5f-this->positionMap.x;

    if(point.x>0.f && point.y>0.f){
        //convert to the ret
        ret = edk::vec2ui32((edk::uint32)point.x,(edk::uint32)point.y);
        //test the size
        if(ret.x<this->sizeMap.width && ret.y<this->sizeMap.height){
            //mirror the y
            ret.y = (edk::uint32)(((edk::int32)ret.y*-1) + this->sizeMap.height-1u);
            if(inside)*inside = true;
            //return ret
            return ret;
        }
    }
    if(inside)*inside = false;
    return edk::vec2ui32(0u,0u);
}

//Desenha o tileMap
void edk::tiles::TileMap2D::draw(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTile( this->tileMap[y][x]
                                         ,(x*this->scaleMap.width) + positionTemp.x
                                         ,(y2*this->scaleMap.height) + positionTemp.y
                                         ,0.f,this->scaleMap,color
                                         );
            }
        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::draw(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTile( this->tileMap[y][x]
                                             ,(x*this->scaleMap.width) + positionTemp.x
                                             ,(y2*this->scaleMap.height) + positionTemp.y
                                             ,0.f,this->scaleMap,color
                                             );
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWithoutMaterial(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileWithoutMaterial(this->tileMap[y][x]
                                                       ,(x*this->scaleMap.width) + positionTemp.x
                                                       ,(y2*this->scaleMap.height) + positionTemp.y
                                                       ,0.f,this->scaleMap,color
                                                       );
            }
        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWithoutMaterial(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileWithoutMaterial( this->tileMap[y][x]
                                                            ,(x*this->scaleMap.width) + positionTemp.x
                                                            ,(y2*this->scaleMap.height) + positionTemp.y
                                                            ,0.f,this->scaleMap,color
                                                            );
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawInsideWorldRect(edk::rectf32 rect,edk::color4f32 color){
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->draw(origin,size,color);
}
void edk::tiles::TileMap2D::drawIsometric(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTile( this->tileMap[y][x]
                                         ,(x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                         ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                         ,0.f,this->scaleMap,color
                                         );
            }
        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometric(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTile( this->tileMap[y][x]
                                             ,(x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                             ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                             ,0.f,this->scaleMap,color
                                             );
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometricInsideWorldRect(edk::rectf32 /*rect*/,edk::color4f32 /*color*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size.width /= this->scaleMap.width;
    rect.size.height /= this->scaleMap.height;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawIsometric(origin,size,color);
*/
}
//Draw tileMap without passing a color
void edk::tiles::TileMap2D::draw(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTile( this->tileMap[y][x]
                                         ,(x*this->scaleMap.width) + positionTemp.x
                                         ,(y2*this->scaleMap.height) + positionTemp.y
                                         ,0.f,this->scaleMap,this->colorMap[y][x]
                                         );
            }
        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::draw(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTile( this->tileMap[y][x]
                                             ,(x*this->scaleMap.width) + positionTemp.x
                                             ,(y2*this->scaleMap.height) + positionTemp.y
                                             ,0.f,this->scaleMap,this->colorMap[y][x]
                                             );
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWithoutMaterial(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileWithoutMaterial(this->tileMap[y][x]
                                                       ,(x*this->scaleMap.width) + positionTemp.x
                                                       ,(y2*this->scaleMap.height) + positionTemp.y
                                                       ,0.f,this->scaleMap,this->colorMap[y][x]
                                                       );
            }
        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWithoutMaterial(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileWithoutMaterial( this->tileMap[y][x]
                                                            ,(x*this->scaleMap.width) + positionTemp.x
                                                            ,(y2*this->scaleMap.height) + positionTemp.y
                                                            ,0.f,this->scaleMap,this->colorMap[y][x]
                                                            );
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawInsideWorldRect(edk::rectf32 rect){
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->draw(origin,size);
}
void edk::tiles::TileMap2D::drawIsometric(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTile( this->tileMap[y][x]
                                         ,(x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                         ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                         ,0.f,this->scaleMap,this->colorMap[y][x]
                                         );
            }
        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometric(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTile( this->tileMap[y][x]
                                             ,(x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                             ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                             ,0.f,this->scaleMap,this->colorMap[y][x]
                                             );
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();
        //this->treeStaticPhysics.render();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometricInsideWorldRect(edk::rectf32 /*rect*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size.width /= this->scaleMap.width;
    rect.size.height /= this->scaleMap.height;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawIsometric(origin,size);
*/
}

//draw wireTiles
void edk::tiles::TileMap2D::drawWire(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                            ,(y2*this->scaleMap.height) + positionTemp.y
                                            ,0.f,this->scaleMap,color
                                            );
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWire(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,color
                                                );
                }
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWireInsideWorldRect(edk::rectf32 rect,edk::color4f32 color){
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawWire(origin,size,color);
}
void edk::tiles::TileMap2D::drawIsometricWire(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileIsometricWire((x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                     ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                     ,0.f,this->scaleMap,color
                                                     );
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometricWire(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileIsometricWire((x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                         ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                         ,0.f,this->scaleMap,color
                                                         );
                }
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometricWireInsideWorldRect(edk::rectf32 /*rect*/,edk::color4f32 /*color*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawIsometricWire(origin,size,color);
    */
}
//draw wireTiles without passing a color
void edk::tiles::TileMap2D::drawWire(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                            ,(y2*this->scaleMap.height) + positionTemp.y
                                            ,0.f,this->scaleMap,this->colorMap[y][x]
                                            );
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWire(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,this->colorMap[y][x]
                                                );
                }
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWireInsideWorldRect(edk::rectf32 rect){
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawWire(origin,size);
}
void edk::tiles::TileMap2D::drawIsometricWire(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileIsometricWire((x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                     ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                     ,0.f,this->scaleMap,this->colorMap[y][x]
                                                     );
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometricWire(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileIsometricWire((x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                         ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                         ,0.f,this->scaleMap,this->colorMap[y][x]
                                                         );
                }
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometricWireInsideWorldRect(edk::rectf32 /*rect*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawIsometricWire(origin,size);
    */
}

//draw wireTiles
void edk::tiles::TileMap2D::drawWirePhysics(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,color
                                                );
                }
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWirePhysics(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                        this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                    ,(y2*this->scaleMap.height) + positionTemp.y
                                                    ,0.f,this->scaleMap,color
                                                    );
                    }
                }
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWirePhysicsInsideWorldRect(edk::rectf32 rect,edk::color4f32 color){
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawWirePhysics(origin,size,color);
}
//draw wireTiles without passing a color
void edk::tiles::TileMap2D::drawWirePhysics(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,this->colorMap[y][x]
                                                );
                }
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWirePhysics(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                        this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                    ,(y2*this->scaleMap.height) + positionTemp.y
                                                    ,0.f,this->scaleMap,this->colorMap[y][x]
                                                    );
                    }
                }
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWirePhysicsInsideWorldRect(edk::rectf32 rect){
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawWirePhysics(origin,size);
}

//draw wireWitPhysics
void edk::tiles::TileMap2D::drawWireWithPhysics(edk::color4f32 color,edk::color4f32 physColor){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,physColor
                                                );
                }
                else{
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,color
                                                );
                }
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWireWithPhysics(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color,edk::color4f32 physColor){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                        this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                    ,(y2*this->scaleMap.height) + positionTemp.y
                                                    ,0.f,this->scaleMap,physColor
                                                    );
                    }
                    else{
                        this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                    ,(y2*this->scaleMap.height) + positionTemp.y
                                                    ,0.f,this->scaleMap,color
                                                    );
                    }
                }
            }
        }
        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawWireWithPhysicsInsideWorldRect(edk::rectf32 rect,edk::color4f32 color,edk::color4f32 physColor){
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawWireWithPhysics(origin,size,color,physColor);
}
//draw one especific tile in wirte
bool edk::tiles::TileMap2D::drawTileWire(edk::vec2ui32 position,edk::color4f32 color){
    if(this->tileSet){
        //test the position
        if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
            //draw the tile
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            edk::int64 y2 = (position.y*-1) + this->sizeMap.height-1u;
            //draw the tile
            this->tileSet->drawTileWire((position.x*this->scaleMap.width) + positionTemp.x
                                        ,(y2*this->scaleMap.height) + positionTemp.y
                                        ,0.f,this->scaleMap,color
                                        );
            edk::GU::guPopMatrix();
            //then return true
            return true;
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileMap2D::drawTileWire(edk::uint32 positionX,edk::uint32 positionY,edk::color4f32 color){
    return this->drawTileWire(edk::vec2ui32(positionX,positionY),color);
}
bool edk::tiles::TileMap2D::drawTileWire(edk::uint32 position,edk::color4f32 color){
    if(position){
        if(this->sizeMap.width && this->sizeMap.height){
            position--;
            return this->drawTileWire(edk::vec2ui32(position%this->sizeMap.width,position/this->sizeMap.width),color);
        }
    }
    return false;
}
//draw one especific tile in wire without passing a color
bool drawTileWire(edk::vec2ui32 position);
bool drawTileWire(edk::uint32 positionX,edk::uint32 positionY);
bool drawTileWire(edk::uint32 position);


bool edk::tiles::TileMap2D::drawTileWire(edk::vec2ui32 position){
    if(this->tileSet){
        //test the position
        if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
            //draw the tile
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            edk::int64 y2 = (position.y*-1) + this->sizeMap.height-1u;
            //draw the tile
            this->tileSet->drawTileWire((position.x*this->scaleMap.width) + positionTemp.x
                                        ,(y2*this->scaleMap.height) + positionTemp.y
                                        ,0.f,this->scaleMap,this->colorMap[position.y][position.x]
                    );
            edk::GU::guPopMatrix();
            //then return true
            return true;
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileMap2D::drawTileWire(edk::uint32 positionX,edk::uint32 positionY){
    return this->drawTileWire(edk::vec2ui32(positionX,positionY));
}
bool edk::tiles::TileMap2D::drawTileWire(edk::uint32 position){
    if(position){
        if(this->sizeMap.width && this->sizeMap.height){
            position--;
            edk::vec2ui32 vec(position%this->sizeMap.width,position/this->sizeMap.width);
            return this->drawTileWire(vec,this->colorMap[vec.y][vec.x]);
        }
    }
    return false;
}

//draw the tile for selection
void edk::tiles::TileMap2D::drawSelectionWithID(edk::uint8 id){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();

        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                edk::GU::guPushName(edk::BinaryConverter::joinBits(id,((this->sizeMap.width * y) + x)+1u,24));
                this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x
                                                  ,(y2*this->scaleMap.height) + positionTemp.y
                                                  ,0.f,this->scaleMap
                                                  );
                edk::GU::guPopName();
            }
        }

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawSelectionWithID(edk::vec2ui32 origin,edk::size2ui32 last,edk::uint8 id){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;
            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    edk::GU::guPushName(edk::BinaryConverter::joinBits(id,((this->sizeMap.width * y) + x)+1u,24));
                    this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x
                                                      ,(y2*this->scaleMap.height) + positionTemp.y
                                                      ,0.f,this->scaleMap
                                                      );
                    edk::GU::guPopName();
                }
            }
        }

        //this->treePhysics.print();
        //this->treeStaticPhysics.printf();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawSelection(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();

        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                edk::GU::guPushName(((this->sizeMap.width * y) + x)+1u);
                this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x
                                                  ,(y2*this->scaleMap.height) + positionTemp.y
                                                  ,0.f,this->scaleMap
                                                  );
                edk::GU::guPopName();
            }
        }

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawSelection(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;
            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    edk::GU::guPushName(((this->sizeMap.width * y) + x)+1u);
                    this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x
                                                      ,(y2*this->scaleMap.height) + positionTemp.y
                                                      ,0.f,this->scaleMap
                                                      );
                    edk::GU::guPopName();
                }
            }
        }

        //this->treePhysics.print();
        //this->treeStaticPhysics.printf();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawInsideWorldRectSelectionWithID(edk::rectf32 rect,edk::uint8 id){
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawSelectionWithID(origin,size,id);
}
void edk::tiles::TileMap2D::drawInsideWorldRectSelection(edk::rectf32 rect){
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawSelection(origin,size);
}
void edk::tiles::TileMap2D::drawIsometricSelectionWithID(edk::uint8 id){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();

        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                edk::GU::guPushName(edk::BinaryConverter::joinBits(id,((this->sizeMap.width * y) + x)+1u,24));
                this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                  ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                  ,0.f,this->scaleMap
                                                  );

                edk::GU::guPopName();
            }
        }

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometricSelectionWithID(edk::vec2ui32 origin,edk::size2ui32 last,edk::uint8 id){
    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;
            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    edk::GU::guPushName(edk::BinaryConverter::joinBits(id,((this->sizeMap.width * y) + x)+1u,24));
                    this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                      ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                      ,0.f,this->scaleMap
                                                      );

                    edk::GU::guPopName();
                }
            }
        }

        //this->treePhysics.print();
        //this->treeStaticPhysics.printf();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometricSelection(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();
        //set the transformation
        edk::GU::guPushMatrix();

        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                edk::GU::guPushName(((this->sizeMap.width * y) + x)+1u);
                this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                  ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                  ,0.f,this->scaleMap
                                                  );
                edk::GU::guPopName();
            }
        }

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometricSelection(edk::vec2ui32 origin,edk::size2ui32 last){

    if(this->tileSet){
        if(last.width>this->sizeMap.width) last.width=this->sizeMap.width;
        if(last.height>this->sizeMap.height) last.height=this->sizeMap.height;
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();
            //set the transformation
            edk::GU::guPushMatrix();
            //last.height++;
            //last.width++;
            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    edk::GU::guPushName(((this->sizeMap.width * y) + x)+1u);
                    this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                      ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                      ,0.f,this->scaleMap
                                                      );
                    edk::GU::guPopName();
                }
            }
        }

        //this->treePhysics.print();
        //this->treeStaticPhysics.printf();

        edk::GU::guPopMatrix();
    }
}
void edk::tiles::TileMap2D::drawIsometricInsideWorldRectSelectionWithID(edk::rectf32 /*rect*/,edk::uint8 /*id*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawIsometricSelectionWithID(origin,size,id);
    */
}
void edk::tiles::TileMap2D::drawIsometricInsideWorldRectSelection(edk::rectf32 /*rect*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;
    rect.origin.y /= this->scaleMap.height;
    rect.size /= this->scaleMap;

    rect.origin.y+=0.5;
    rect.origin.x+=0.5;

    edk::vec2f32 first = rect.origin;
    //
    rect.origin.x +=rect.size.width;
    first.y +=rect.size.height;

    //translate the origin
    rect.origin.x -= (this->positionMap.x);
    rect.origin.y -= (this->positionMap.y);
    first.x -= (this->positionMap.x);
    first.y -= (this->positionMap.y);

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;
    first.y= (first.y*-1.f) + this->sizeMap.height;

    //increment the last pointer
    rect.origin+=1.f;

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width) rect.origin.x=this->sizeMap.width;
    if(rect.origin.y>this->sizeMap.height) rect.origin.y=this->sizeMap.height;
    //filter the first pointer
    if(first.x<0.f) first.x=0.f;
    if(first.y<0.f) first.y=0.f;

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );

    this->drawIsometricSelection(origin,size);
*/
}

//draw the pivo
void edk::tiles::TileMap2D::drawPivo(edk::float32 size,edk::color3f32 color){
    edk::GU::guPushMatrix();
    //add translate
    edk::GU::guTranslate2f32(this->getPosition());
    //add scale
    edk::GU::guScale2f32(edk::size2f32(size,size));

    //lineSize
    edk::GU::guLineWidth(3);

    //set the colors
    edk::GU::guColor3f32(color);
    //draw the lines
    edk::GU::guBegin(GU_LINES);
    //LINE 1
    edk::GU::guVertex2f32(-0.5f,-0.5f);
    edk::GU::guVertex2f32( 0.5f, 0.5f);
    //LINE 2
    edk::GU::guVertex2f32(-0.5f, 0.5f);
    edk::GU::guVertex2f32( 0.5f,-0.5f);
    edk::GU::guEnd();

    //lineSize
    edk::GU::guLineWidth(1);
    edk::GU::guPopMatrix();
}

//print the tileMap ID's
void edk::tiles::TileMap2D::print(){
    if(this->tileSet){
        //set the transformation
        edk::GU::guPushMatrix();
        edk::GU::guTranslate2f32(this->positionMap.x,this->positionMap.y);
        for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                printf("\n%u %u [%u] color [%.2f,%.2f,%.2f,%.2f] "
                       ,x
                       ,y
                       ,this->tileMap[y][x]
                       ,this->colorMap[y][x].r
                       ,this->colorMap[y][x].g
                       ,this->colorMap[y][x].b
                       ,this->colorMap[y][x].a
                       );
            }
        }
        edk::GU::guPopMatrix();
    }
}

void edk::tiles::TileMap2D::contact2DBegin(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;
            tileContact.tileA = objectA->tile;
            tileContact.positionA = objectA->position;
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;
                tileContact.positionB = objectB->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->contact2DTileBegin(tileContact,contact);
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;
            tileContact.tileB = objectB->tile;
            tileContact.positionB = objectB->position;
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;
                tileContact.positionA = objectA->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->contact2DTileBegin(tileContact,contact);
                }
            }
        }
    }
}
void edk::tiles::TileMap2D::contact2DEnd(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;
            tileContact.tileA = objectA->tile;
            tileContact.positionA = objectA->position;
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;
                tileContact.positionB = objectB->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->contact2DTileEnd(tileContact,contact);
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;
            tileContact.tileB = objectB->tile;
            tileContact.positionB = objectB->position;
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;
                tileContact.positionA = objectA->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->contact2DTileEnd(tileContact,contact);
                }
            }
        }
    }
}
void edk::tiles::TileMap2D::contact2DKeepBegin(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;
            tileContact.tileA = objectA->tile;
            tileContact.positionA = objectA->position;
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;
                tileContact.positionB = objectB->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->contact2DTileKeepBegin(tileContact,contact);
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;
            tileContact.tileB = objectB->tile;
            tileContact.positionB = objectB->position;
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;
                tileContact.positionA = objectA->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->contact2DTileKeepBegin(tileContact,contact);
                }
            }
        }
    }
}
void edk::tiles::TileMap2D::contact2DKeepEnd(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;
            tileContact.tileA = objectA->tile;
            tileContact.positionA = objectA->position;
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;
                tileContact.positionB = objectB->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->contact2DTileKeepEnd(tileContact,contact);
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;
            tileContact.tileB = objectB->tile;
            tileContact.positionB = objectB->position;
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;
                tileContact.positionA = objectA->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->contact2DTileKeepEnd(tileContact,contact);
                }
            }
        }
    }
}
//contact sensors
void edk::tiles::TileMap2D::sensor2DBegin(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;
            tileContact.tileA = objectA->tile;
            tileContact.positionA = objectA->position;
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;
                tileContact.positionB = objectB->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->sensor2DTileBegin(tileContact,contact);
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;
            tileContact.tileB = objectB->tile;
            tileContact.positionB = objectB->position;
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;
                tileContact.positionA = objectA->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->sensor2DTileBegin(tileContact,contact);
                }
            }
        }
    }
}
void edk::tiles::TileMap2D::sensor2DEnd(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;
            tileContact.tileA = objectA->tile;
            tileContact.positionA = objectA->position;
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;
                tileContact.positionB = objectB->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->sensor2DTileEnd(tileContact,contact);
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;
            tileContact.tileB = objectB->tile;
            tileContact.positionB = objectB->position;
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;
                tileContact.positionA = objectA->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->sensor2DTileEnd(tileContact,contact);
                }
            }
        }
    }
}
void edk::tiles::TileMap2D::sensor2DKeeping(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;
            tileContact.tileA = objectA->tile;
            tileContact.positionA = objectA->position;
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;
                tileContact.positionB = objectB->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->sensor2DTileKeeping(tileContact,contact);
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;
            tileContact.tileB = objectB->tile;
            tileContact.positionB = objectB->position;
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;
                tileContact.positionA = objectA->position;
            }
            edk::uchar32 size = this->treeCallbacks.size();
            edk::tiles::tileCallback* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);
                if(temp){
                    temp->sensor2DTileKeeping(tileContact,contact);
                }
            }
        }
    }
}

//XML
bool edk::tiles::TileMap2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tileMap_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::char8* temp;
                        //write size of tileMap
                        temp = edk::String::int64ToStr(this->sizeMap.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeMapW",temp);
                            delete[] temp;
                        }
                        temp = edk::String::int64ToStr(this->sizeMap.height);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeMapH",temp);
                            delete[] temp;
                        }
                        //write the scaleMap
                        temp = edk::String::float32ToStr(this->scaleMap.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"scaleMapW",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->scaleMap.height);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"scaleMapH",temp);
                            delete[] temp;
                        }
                        //write the position
                        temp = edk::String::float32ToStr(this->getPositionX());
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"posMapX",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->getPositionY());
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"posMapY",temp);
                            delete[] temp;
                        }
                        //write the tileMap
                        if(this->tileMap){
                            if(xml->addSelectedNextChild("tileMap")){
                                if(xml->selectChild("tileMap")){
                                    //create a new vector
                                    edk::uint32 size = this->sizeMap.width * this->sizeMap.height;
                                    if(size){
                                        edk::uint32* vec = new edk::uint32[size];
                                        if(vec){
                                            edk::uint32 count = 0u;
                                            edk::vec2ui32 position;
                                            //copy the mat to the vec
                                            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                                                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                                                    //test if XY is a physics object
                                                    position = edk::vec2ui32(x,y);
                                                    if(this->treePhysics.havePosition(position)){
                                                        vec[count] = this->treePhysics.getIDInPosition(position);
                                                    }
                                                    else{
                                                        vec[count] = this->tileMap[y][x];
                                                    }
                                                    count++;
                                                }
                                            }
                                            //create the string
                                            temp = edk::String::vecUint32toStr(vec,size);
                                            if(temp){
                                                xml->setSelectedString(temp);
                                                delete[] temp;
                                            }
                                            delete[] vec;
                                        }
                                    }
                                    xml->selectFather();
                                }
                            }
                        }
                        //write the colorMap
                        if(this->colorMap){
                            if(xml->addSelectedNextChild("colorMap")){
                                if(xml->selectChild("colorMap")){

                                    //create a new vector
                                    edk::uint32 size = this->sizeMap.width * this->sizeMap.height * 4u;
                                    if(size){
                                        edk::float32* vec = new edk::float32[size];
                                        if(vec){
                                            edk::uint32 count = 0u;
                                            //copy the mat to the vec
                                            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                                                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                                                    //test if XY is a physics object
                                                    vec[count+0u] = this->colorMap[y][x].a;
                                                    vec[count+1u] = this->colorMap[y][x].r;
                                                    vec[count+2u] = this->colorMap[y][x].g;
                                                    vec[count+3u] = this->colorMap[y][x].b;
                                                    count+=4u;
                                                }
                                            }
                                            //create the string
                                            temp = edk::String::vecfloat32toStr(vec,size);
                                            if(temp){
                                                xml->setSelectedString(temp);
                                                delete[] temp;
                                            }
                                            delete[] vec;
                                        }
                                    }
                                    xml->selectFather();
                                }
                            }
                        }
                        //
                        ret=true;
                        xml->selectFather();
                    }
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
bool edk::tiles::TileMap2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tileMap_",nameID);
            if(name){
                //read the name
                if(xml->selectChild(name)){
                    //read size of tileMap
                    this->sizeMap = edk::size2ui32((edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("sizeMapW")),
                                                   (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("sizeMapH"))
                                                   );
                    this->scaleMap = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleMapW")),
                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleMapH"))
                                                   );
                    //read the tileMap
                    if(xml->selectChild("tileMap")){
                        //create the new tileMap
                        if(this->newTileMap(this->sizeMap.width,this->sizeMap.height)){
                            if(this->tileMap){
                                //create a new vector
                                edk::uint32 size = this->sizeMap.width * this->sizeMap.height;
                                if(size){
                                    //create the vector
                                    edk::uint32* vec = new edk::uint32[size];
                                    if(vec){
                                        //convert the string
                                        if(edk::String::strToVecUint32(xml->getSelectedString(),vec,size)){
                                            edk::uint32 count = 0u;
                                            //copy the vec to the mat
                                            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                                                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                                                    this->tileMap[y][x] = vec[count];
                                                    count++;
                                                }
                                            }
                                        }
                                        delete[] vec;
                                    }
                                }
                            }
                            xml->selectFather();

                            //read the colorMap
                            if(xml->selectChild("colorMap")){
                                if(this->colorMap){
                                    //create a new vector
                                    edk::uint32 size = this->sizeMap.width * this->sizeMap.height * 4u;
                                    if(size){
                                        //create the vector
                                        edk::float32* vec = new edk::float32[size];
                                        if(vec){
                                            //convert the string
                                            if(edk::String::strToVecfloat32(xml->getSelectedString(),vec,size)){
                                                edk::uint32 count = 0u;
                                                //copy the vec to the mat
                                                for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                                                    for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                                                        this->colorMap[y][x].a = vec[count+0u];
                                                        this->colorMap[y][x].r = vec[count+1u];
                                                        this->colorMap[y][x].g = vec[count+2u];
                                                        this->colorMap[y][x].b = vec[count+3u];
                                                        count+=4u;
                                                    }
                                                }
                                            }
                                            delete[] vec;
                                        }
                                    }
                                }
                                xml->selectFather();
                            }
                        }
                        else{
                            xml->selectFather();
                        }
                    }



                    edk::vec2f32 positionTemp = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("posMapX")),
                                                             edk::String::strToFloat32(xml->getSelectedAttributeValueByName("posMapY"))
                                                             );
                    this->setPosition(positionTemp);

                    ret=true;
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
        return ret;
    }
    return false;
}
