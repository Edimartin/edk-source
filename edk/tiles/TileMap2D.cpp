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
    this->tileSet=NULL;edkEnd();
    this->tileMap=NULL;edkEnd();
    this->colorMap=NULL;edkEnd();
    this->world=NULL;edkEnd();
    this->sizeMap = edk::size2ui32(0u,0u);edkEnd();
    this->color = 1.f;edkEnd();
    this->saveOrigin = edk::vec2ui32(0u,0u);edkEnd();
    this->saveLast = edk::size2ui32(0u,0u);edkEnd();
}
edk::tiles::TileMap2D::TileMap2D(edk::tiles::TileSet2D* tileSet){
    this->world=NULL;edkEnd();
    this->tileMap=NULL;edkEnd();
    this->colorMap=NULL;edkEnd();
    this->sizeMap = edk::size2ui32(0u,0u);edkEnd();
    this->color = 1.f;edkEnd();
    this->setTileSet(tileSet);edkEnd();
}
edk::tiles::TileMap2D::~TileMap2D(){
    //
    this->deletePhysicsTiles();edkEnd();
    this->deleteTileMap();edkEnd();
    this->cleanWorldPointer();edkEnd();
}

//get the static object from tile with just one rectangle
edk::physics2D::PhysicObject2D* edk::tiles::TileMap2D::getStaticTile(edk::vec2ui32 position){
    edk::physics2D::PhysicObject2D* ret=NULL;edkEnd();
    //test if have a tileSet
    if(this->tileSet){
        //

        //then load the tiles
        edk::uint32 tileID = 0u;edkEnd();
        edk::physics2D::PhysicObject2D* temp2 = NULL;edkEnd();

        if(position.y < this->sizeMap.height
                &&
                position.x < this->sizeMap.width
                ){
            //load the tileID
            tileID = this->tileMap[position.y][position.x];edkEnd();
            if(tileID){
                //get the tilePhysicsObject
                temp2 = this->tileSet->getTilePhysicsObject(tileID);edkEnd();
                if(temp2){
                    //test if the temp2 is a dynamic physics tile
                    if(temp2->getType() == edk::physics::StaticBody){
                        //test if the tile have a physics rectangle object
                        if(temp2->physicMesh.getPolygonSize() == 1u){
                            //now test if the polygon is an rectangle
                            if(temp2->physicMesh.selectPolygon(0u)){
                                if(temp2->physicMesh.selectedGetVertexCount()==2u){
                                    edk::vec2f32 vertex = temp2->physicMesh.selectedGetVertexPosition(0u);edkEnd();
                                    if(vertex.x > +0.49f && vertex.x < +0.51f && vertex.y > +0.49f && vertex.y < +0.51f){
                                        vertex = temp2->physicMesh.selectedGetVertexPosition(1u);edkEnd();
                                        if(vertex.x < -0.49f && vertex.x > -0.51f && vertex.y < -0.49f && vertex.y > -0.51f){
                                            ret = temp2;edkEnd();
                                        }
                                    }
                                    else if(vertex.x < -0.49f && vertex.x > -0.51f && vertex.y < -0.49f && vertex.y > -0.51f){
                                        vertex = temp2->physicMesh.selectedGetVertexPosition(1u);edkEnd();
                                        if(vertex.x > +0.49f && vertex.x < +0.51f && vertex.y > +0.49f && vertex.y < +0.51f){
                                            ret = temp2;edkEnd();
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
    return this->getStaticTile(edk::vec2ui32(positionX,positionY));edkEnd();
}
//compare two static objects
bool edk::tiles::TileMap2D::compareStaticTile(edk::physics2D::PhysicObject2D* tile1,edk::physics2D::PhysicObject2D* tile2){
    bool ret=false;edkEnd();
    //test if have the two objects
    if(tile1 && tile2){
        //test if the tiles are the same
        if(tile1 == tile2){
            edkEnd();
            return true;
        }

        {
            edk::uint32 size = tile1->getNotCollisionGroupSize();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                if(!tile2->haveNotCollisionGroup(tile1->getNotCollisionGroupInPosition(i))){
                    return false;
                }
            }
            size = tile1->getCollisionGroupSize();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                if(!tile2->haveCollisionGroup(tile1->getCollisionGroupInPosition(i))){
                    return false;
                }
            }
        }

        //test if the two objects are the same type
        if(tile1->getType() == tile2->getType()){
            ret=true;edkEnd();
            //test the physics mesh of the tile
            if(tile1->physicMesh.getPolygonSize() == tile2->physicMesh.getPolygonSize()){
                //test if have the polygons with the same vertex positions
                edk::uint32 size = tile1->physicMesh.getPolygonSize();edkEnd();
                edk::vec2f32 position1,position2,position3,position4;edkEnd();
                edk::uint32 sizeVertex = 0u;edkEnd();
                edk::float32 value1,value2;edkEnd();

                for(edk::uint32 i=0u;i<size;i++){
                    //select the polygon
                    if(tile1->physicMesh.selectPolygon(i) && tile2->physicMesh.selectPolygon(i)){
                        //compare the vertexes size of the polygon
                        if(tile1->physicMesh.selectedGetVertexCount() == tile2->physicMesh.selectedGetVertexCount()){
                            //test the vertexes
                            sizeVertex = tile1->physicMesh.selectedGetVertexCount();edkEnd();
                            if(sizeVertex==2u){
                                //compare the vertexes
                                position1 = tile1->physicMesh.selectedGetVertexPosition(0u);edkEnd();
                                position2 = tile1->physicMesh.selectedGetVertexPosition(1u);edkEnd();
                                position3 = tile2->physicMesh.selectedGetVertexPosition(0u);edkEnd();
                                position4 = tile2->physicMesh.selectedGetVertexPosition(1u);edkEnd();

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
                                    ret=false;edkEnd();
                                    break;
                                }
                            }
                            else{
                                for(edk::uint32 j=0u;j<sizeVertex;j++){
                                    //test the vertex position
                                    position1 = tile1->physicMesh.selectedGetVertexPosition(i);edkEnd();
                                    position2 = tile2->physicMesh.selectedGetVertexPosition(i);edkEnd();
                                    //compare the vertexes
                                    if(!(position1.x-0.01>position2.x && position1.x+0.01<position2.x
                                         &&
                                         position1.y-0.01>position2.y && position1.y+0.01<position2.y)){
                                        //
                                        ret=false;edkEnd();
                                        break;
                                    }
                                }
                                if(!ret){
                                    edkEnd();
                                    break;
                                }
                            }
                        }
                        else{
                            ret=false;edkEnd();
                            break;
                        }

                        //compare the physics variables
                        value1 = tile1->physicMesh.selectedGetDensity();edkEnd();
                        value2 = tile2->physicMesh.selectedGetDensity();edkEnd();
                        if(!(value1>value2-0.01 && value1<value2+0.01)){
                            ret=false;edkEnd();
                            break;
                        }
                        value1 = tile1->physicMesh.selectedGetFriction();edkEnd();
                        value2 = tile2->physicMesh.selectedGetFriction();edkEnd();
                        if(!(value1>value2-0.01 && value1<value2+0.01)){
                            ret=false;edkEnd();
                            break;
                        }
                        value1 = tile1->physicMesh.selectedGetRestitution();edkEnd();
                        value2 = tile2->physicMesh.selectedGetDensity();edkEnd();
                        if(!(value1>value2-0.01 && value1<value2+0.01)){
                            ret=false;edkEnd();
                            break;
                        }
                    }
                    else{
                        ret=false;edkEnd();
                        break;
                    }
                }
            }
            else{
                ret=false;edkEnd();
            }
        }
    }
    return ret;
}
//update draw tiles to calculate which tile will start to draw and end to draw
void edk::tiles::TileMap2D::updateDrawTiles(edk::vec2ui32 origin,edk::size2ui32 last){
    //test if the tiles are the same
    if(this->saveOrigin.x == this->saveLast.width
            &&
            this->saveOrigin.y == this->saveLast.height
            ){
        //
        return;edkEnd();
    }
    else{
        //test which add and remove from draw
        if(origin.x <= this->saveOrigin.x){
            //add tiles in X
            if(origin.y <= this->saveOrigin.y){
                //add tiles in Y
                if(last.width <= this->saveOrigin.x){
                    //
                    //add all origin
                    this->startDrawTiles(origin,last);edkEnd();
                    //remove all save
                    this->endDrawTiles(this->saveOrigin,this->saveLast);edkEnd();
                }
                else{
                    //
                    if(last.height <= this->saveOrigin.y){
                        //
                        //add all origin
                        this->startDrawTiles(origin,last);edkEnd();
                        //remove all save
                        this->endDrawTiles(this->saveOrigin,this->saveLast);edkEnd();
                    }
                    else{
                        //
                        if(last.width <= this->saveLast.width){
                            //
                            if(last.height <= this->saveLast.height){
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(last.width,this->saveOrigin.y));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(origin.x,this->saveOrigin.y),edk::size2ui32(this->saveOrigin.x,last.height));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(last.width,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,last.height));edkEnd();
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,last.height),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                            }
                            else{
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(last.width,this->saveOrigin.y));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(origin.x,this->saveOrigin.y),edk::size2ui32(this->saveOrigin.x,this->saveLast.height));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(origin.x,this->saveLast.height),edk::size2ui32(last.width,last.height));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(last.width,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                            }
                        }
                        else{
                            if(last.height <= this->saveLast.height){
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(last.width,this->saveOrigin.y));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(origin.x,this->saveOrigin.y),edk::size2ui32(this->saveOrigin.x,last.height));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(this->saveLast.width,this->saveOrigin.y),edk::size2ui32(last.width,last.height));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,last.height),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                            }
                            else{
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(last.width,this->saveOrigin.y));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(origin.x,this->saveOrigin.y),edk::size2ui32(this->saveOrigin.x,this->saveLast.height));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(this->saveLast.width,this->saveOrigin.y),edk::size2ui32(last.width,this->saveLast.height));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(origin.x,this->saveLast.height),edk::size2ui32(last.width,last.height));edkEnd();
                            }
                        }
                    }
                }
            }
            else{
                //
                if(last.width <= this->saveOrigin.x){
                    //
                    //add all origin
                    this->startDrawTiles(origin,last);edkEnd();
                    //remove all save
                    this->endDrawTiles(this->saveOrigin,this->saveLast);edkEnd();
                }
                else{
                    //
                    if(origin.y <= this->saveLast.height){
                        //
                        if(last.width <= this->saveLast.width){
                            //
                            if(last.height <= this->saveLast.height){
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(this->saveOrigin.x,last.height));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,origin.y));edkEnd();
                                this->endDrawTiles(edk::vec2ui32(last.width,origin.y),edk::size2ui32(this->saveLast.width,last.height));edkEnd();
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,last.height),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                            }
                            else{
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(this->saveOrigin.x,this->saveLast.height));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(origin.x,this->saveLast.height),edk::size2ui32(last.width,last.height));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,origin.y));edkEnd();
                                this->endDrawTiles(edk::vec2ui32(last.width,origin.y),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                            }
                        }
                        else{
                            if(last.height <= this->saveLast.height){
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(this->saveOrigin.x,last.height));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(this->saveLast.width,origin.y),edk::size2ui32(last.width,last.height));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,origin.y));edkEnd();
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,last.height),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                            }
                            else{
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(this->saveOrigin.x,this->saveLast.height));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(this->saveLast.width,origin.y),edk::size2ui32(last.width,this->saveLast.height));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(origin.x,this->saveLast.height),edk::size2ui32(last.width,last.height));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,origin.y));edkEnd();
                            }
                        }
                    }
                    else{
                        //
                        //add all origin
                        this->startDrawTiles(origin,last);edkEnd();
                        //remove all save
                        this->endDrawTiles(this->saveOrigin,this->saveLast);edkEnd();
                    }
                }
            }
        }
        else{
            if(origin.x <= this->saveLast.width){
                //remove tiles in X
                if(origin.y <= this->saveOrigin.y){
                    //
                    if(last.height<=this->saveOrigin.y){
                        //
                        //add all origin
                        this->startDrawTiles(origin,last);edkEnd();
                        //remove all save
                        this->endDrawTiles(this->saveOrigin,this->saveLast);edkEnd();
                    }
                    else{
                        //
                        if(last.height<=this->saveLast.height){
                            //
                            if(last.width<=this->saveLast.width){
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(last.width,this->saveOrigin.y));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(origin.x,last.height));edkEnd();
                                this->endDrawTiles(edk::vec2ui32(last.width,this->saveOrigin.y),edk::size2ui32(last.width,last.height));edkEnd();
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,last.height),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                            }
                            else{
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(last.width,this->saveOrigin.y));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(this->saveLast.width,this->saveOrigin.y),edk::size2ui32(last.width,last.height));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(origin.x,last.height));edkEnd();
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,last.height),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                            }
                        }
                        else{
                            if(last.width<=this->saveLast.width){
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(last.width,this->saveOrigin.y));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(origin.x,this->saveLast.height),edk::size2ui32(last.width,last.height));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(origin.x,this->saveLast.height));edkEnd();
                                this->endDrawTiles(edk::vec2ui32(last.width,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                            }
                            else{
                                //
                                this->startDrawTiles(edk::vec2ui32(origin.x,origin.y),edk::size2ui32(last.width,this->saveOrigin.y));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(this->saveLast.width,this->saveOrigin.y),edk::size2ui32(last.width,this->saveLast.height));edkEnd();
                                this->startDrawTiles(edk::vec2ui32(origin.x,this->saveLast.height),edk::size2ui32(last.width,last.height));edkEnd();
                                //
                                this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(origin.x,this->saveLast.height));edkEnd();
                            }
                        }
                    }
                }
                else{
                    //
                    if(last.width <= this->saveLast.width){
                        //
                        if(last.height <= this->saveLast.height){
                            //
                            this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,origin.y));edkEnd();
                            this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,origin.y),edk::size2ui32(origin.x,last.height));edkEnd();
                            this->endDrawTiles(edk::vec2ui32(last.width,origin.y),edk::size2ui32(this->saveLast.width,last.height));edkEnd();
                            this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,last.height),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                        }
                        else{
                            //
                            this->startDrawTiles(edk::vec2ui32(origin.x,this->saveLast.height),edk::size2ui32(last.width,last.height));edkEnd();
                            //
                            this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,origin.y));edkEnd();
                            this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,origin.y),edk::size2ui32(origin.x,this->saveLast.height));edkEnd();
                            this->endDrawTiles(edk::vec2ui32(last.width,origin.y),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                        }
                    }
                    else{
                        //
                        if(last.height <= this->saveLast.height){
                            //
                            this->startDrawTiles(edk::vec2ui32(this->saveLast.width,origin.y),edk::size2ui32(last.width,last.height));edkEnd();
                            //
                            this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,origin.y));edkEnd();
                            this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,origin.y),edk::size2ui32(origin.x,last.height));edkEnd();
                            this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,last.height),edk::size2ui32(this->saveLast.width,this->saveLast.height));edkEnd();
                        }
                        else{
                            //
                            this->startDrawTiles(edk::vec2ui32(this->saveLast.width,origin.y),edk::size2ui32(last.width,this->saveLast.height));edkEnd();
                            this->startDrawTiles(edk::vec2ui32(origin.x,this->saveLast.height),edk::size2ui32(last.width,last.height));edkEnd();
                            //
                            this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,this->saveOrigin.y),edk::size2ui32(this->saveLast.width,origin.y));edkEnd();
                            this->endDrawTiles(edk::vec2ui32(this->saveOrigin.x,origin.y),edk::size2ui32(origin.x,this->saveLast.height));edkEnd();
                        }
                    }
                }
            }
            else{
                //
                //add all origin
                this->startDrawTiles(origin,last);edkEnd();
                //remove all save
                this->endDrawTiles(this->saveOrigin,this->saveLast);edkEnd();
            }
        }
    }

    //save the new origind and size
    this->saveOrigin=origin;edkEnd();
    this->saveLast=last;edkEnd();
}
//start and end the draw tiles
void edk::tiles::TileMap2D::startDrawTiles(edk::vec2ui32 origin,edk::size2ui32 last){
    edk::vec2f32 positionTemp = this->getPosition();edkEnd();
    for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
        for(edk::uint32 x=origin.x;x<last.width;x++){
            //run Start Draw Tile
            this->tileSet->runStartDraw(this->tileMap[y][x]
                                        ,edk::vec2ui32(x,y),
                                        edk::vec2f32((x*this->scaleMap.width) + positionTemp.x,
                                                     (y2*this->scaleMap.height) + positionTemp.y
                                                     )
                                        );edkEnd();
        }
    }
}
void edk::tiles::TileMap2D::endDrawTiles(edk::vec2ui32 origin,edk::size2ui32 last){
    edk::vec2f32 positionTemp = this->getPosition();edkEnd();
    for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
        for(edk::uint32 x=origin.x;x<last.width;x++){
            //run End Draw Tile
            this->tileSet->runEndDraw(this->tileMap[y][x]
                                      ,edk::vec2ui32(x,y),
                                      edk::vec2f32((x*this->scaleMap.width) + positionTemp.x,
                                                   (y2*this->scaleMap.height) + positionTemp.y
                                                   )
                                      );edkEnd();
        }
    }
}

//calculate the draw position from worldRect
edk::rectui32 edk::tiles::TileMap2D::calculateDrawPosition(edk::rectf32 rect){
    edk::rectui32 ret;edkEnd();
    edk::vec2f32 position = this->getPosition();edkEnd();
    //first translate the rect
    rect.origin-=position;edkEnd();
    rect.size.width-=position.x;edkEnd();
    rect.size.height-=position.y;edkEnd();

    rect.origin.x += this->scaleMap.width*0.5f;edkEnd();
    rect.origin.y += this->scaleMap.height*0.5f;edkEnd();
    rect.size.width += this->scaleMap.width*0.5f;edkEnd();
    rect.size.height += this->scaleMap.height*0.5f;edkEnd();

    //now normalize the rect to fit inside the tileMap
    rect.origin.x /= this->scaleMap.width;edkEnd();
    rect.origin.y /= this->scaleMap.height;edkEnd();
    rect.size /= this->scaleMap;edkEnd();

    //rect.origin += 0.5f;edkEnd();
    //rect.size += 0.5f;edkEnd();

    //convert it into positive values


    if(rect.size.width<0.f){
        rect.size.width=0.f;edkEnd();
        rect.origin.x=0.f;edkEnd();
    }
    else{
        if(rect.origin.x<0.f){
            rect.origin.x=0.f;edkEnd();
        }
    }
    if(rect.size.height<0.f){
        rect.size.height=0.f;edkEnd();
        rect.origin.y=0.f;edkEnd();
    }
    else{
        if(rect.origin.y<0.f){
            rect.origin.y=0.f;edkEnd();
        }
    }

    //convert it to unsigned int and return it
    ret.origin.x = (edk::uint32)rect.origin.x;edkEnd();
    ret.origin.y = (edk::uint32)rect.origin.y;edkEnd();
    ret.size.width = (edk::uint32)rect.size.width;edkEnd();
    ret.size.height = (edk::uint32)rect.size.height;edkEnd();

    //increment the size to draw the tileMap
    ret.size.width++;edkEnd();
    ret.size.height++;edkEnd();

    if(ret.size.width>this->sizeMap.width){
        ret.size.width=this->sizeMap.width;edkEnd();
    }
    if(ret.size.height>this->sizeMap.height){
        ret.size.height=this->sizeMap.height;edkEnd();
    }

    return ret;
}

//set the tileSet
bool edk::tiles::TileMap2D::setTileSet(edk::tiles::TileSet2D* tileSet){
    //remove all physics objects
    this->deletePhysicsTiles();edkEnd();
    this->treePhysics.setTileSet(tileSet);edkEnd();
    this->treeStaticPhysics.setTileSet(tileSet);edkEnd();
    return (this->tileSet = tileSet);edkEnd();
}
edk::tiles::TileSet2D* edk::tiles::TileMap2D::getTileSet(){
    return this->tileSet;edkEnd();
}
void edk::tiles::TileMap2D::removeTileSet(){
    this->deletePhysicsTiles();edkEnd();
    this->treePhysics.setTileSet(NULL);edkEnd();
    this->treeStaticPhysics.setTileSet(NULL);edkEnd();
    this->tileSet=NULL;edkEnd();
}
//set a tile in the tileMap
bool edk::tiles::TileMap2D::setTile(edk::uint32 tileID,edk::vec2ui32 position){
    //test the position
    if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
        //set the position
        this->tileMap[position.y][position.x] = tileID;edkEnd();
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileMap2D::setTile(edk::uint32 tileID,edk::uint32 positionX,edk::uint32 positionY){
    //
    return this->setTile(tileID,edk::vec2ui32(positionX,positionY));edkEnd();
}
bool edk::tiles::TileMap2D::setTile(edk::uint32 tileID,edk::uint32 position){
    if(position){
        position--;edkEnd();
        return this->setTile(tileID,edk::vec2ui32(position%this->sizeMap.width,position/this->sizeMap.width));edkEnd();
    }
    return false;
}
//set a color in the colorMap
bool edk::tiles::TileMap2D::setTileColor(edk::color4f32 color,edk::vec2ui32 position){
    //test the position
    if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
        //set the position
        this->colorMap[position.y][position.x] = color;edkEnd();
        //then return true
        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::vec2ui32 position){
    return this->setTileColor(edk::color4f32(r,g,b,a),position);edkEnd();
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::vec2ui32 position){
    return this->setTileColor(r,g,b,1.f,position);edkEnd();
}
bool edk::tiles::TileMap2D::setTileColor(edk::color4f32 color,edk::uint32 positionX,edk::uint32 positionY){
    return this->setTileColor(color,edk::vec2ui32 (positionX,positionY));edkEnd();
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::uint32 positionX,edk::uint32 positionY){
    return this->setTileColor(edk::color4f32 (r,g,b,a),positionX,positionY);edkEnd();
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::uint32 positionX,edk::uint32 positionY){
    return this->setTileColor(r,g,b,1.f,positionX,positionY);edkEnd();
}
bool edk::tiles::TileMap2D::setTileColor(edk::color4f32 color,edk::uint32 position){
    if(position){
        position--;edkEnd();
        return this->setTileColor(color,edk::vec2ui32(position%this->sizeMap.width,position/this->sizeMap.width));edkEnd();
    }
    return false;
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a,edk::uint32 position){
    return this->setTileColor(edk::color4f32 (r,g,b,a),position);edkEnd();
}
bool edk::tiles::TileMap2D::setTileColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::uint32 position){
    return this->setTileColor(r,g,b,1.f,position);edkEnd();
}
//set the color of all tiles
void edk::tiles::TileMap2D::setColor(edk::color4f32 color){
    this->color = color;edkEnd();
    if(this->colorMap){
        for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                this->colorMap[y][x] = color;edkEnd();
            }
        }
    }
}
void edk::tiles::TileMap2D::setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setColor(edk::color4f32 (r,g,b,a));edkEnd();
}
void edk::tiles::TileMap2D::setColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setColor(edk::color4f32 (r,g,b,1.f));edkEnd();
}
void edk::tiles::TileMap2D::setAlpha(edk::float32 a){
    this->color.a = a;edkEnd();
    if(this->colorMap){
        for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                this->colorMap[y][x].a = a;edkEnd();
            }
        }
    }
}
//set the tileMap position
void edk::tiles::TileMap2D::setPosition(edk::vec2f32 position){
    //scale the position
    position.x = position.x * (1.f/this->scaleMap.width);edkEnd();
    position.y = position.y * (1.f/this->scaleMap.height);edkEnd();
    //
    edk::vec2f32 translate = position - this->positionMap;edkEnd();
    this->positionMap = position;edkEnd();

    if(this->world && (translate.x || translate.y)){
        //scale the physics
        edk::physics2D::PhysicObject2D*  temp=NULL;edkEnd();
        edk::uint32 size = this->treePhysics.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->treePhysics.getObjectInPosition(i);edkEnd();
            if(temp){
                //scale the object and position
                temp->position+=translate;edkEnd();
                //update to the world
                this->world->updateObjectStatus(temp);edkEnd();
            }
        }
        size = this->treeStaticPhysics.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->treeStaticPhysics.getObjectInPosition(i);edkEnd();
            if(temp){
                //scale the object and position
                temp->position+=translate;edkEnd();
                //update to the world
                this->world->updateObjectStatus(temp);edkEnd();
            }
        }

    }
}
void edk::tiles::TileMap2D::setPosition(edk::float32 positionX,edk::float32 positionY){
    //
    this->setPosition(edk::vec2f32(positionX,positionY));edkEnd();
}
edk::vec2f32 edk::tiles::TileMap2D::getTileWorldPosition(edk::vec2ui32 position){
    return edk::vec2f32(((edk::float32)position.x + this->positionMap.x) * this->scaleMap.width,
                        ((this->sizeMap.height-1 - (edk::float32)position.y) + this->positionMap.y) * this->scaleMap.height
                        );edkEnd();
}
edk::vec2f32 edk::tiles::TileMap2D::getTileWorldPosition(edk::uint32 positionX,edk::uint32 positionY){
    return edk::vec2f32((positionX + this->positionMap.x) * this->scaleMap.width,
                        ((this->sizeMap.height-1 - positionY) + this->positionMap.y) * this->scaleMap.height
                        );edkEnd();
}
//Set scale the map
bool edk::tiles::TileMap2D::setScaleMap(edk::size2f32 scale){
    if(scale.width != 0.f && scale.height!=0.f){
        //get the position
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();


        this->scaleMap = scale;edkEnd();

        if(this->world){
            //scale the physics
            edk::physics2D::PhysicObject2D*  temp=NULL;edkEnd();
            edk::uint32 size = this->treePhysics.size();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->treePhysics.getObjectInPosition(i);edkEnd();
                if(temp){
                    //scale the object and position
                    temp->position.x*=this->scaleMap.width;edkEnd();
                    temp->position.y*=this->scaleMap.height;edkEnd();
                    temp->size = this->scaleMap;edkEnd();
                    //update to the world
                    this->world->updateObjectStatus(temp);edkEnd();
                }
            }
            size = this->treeStaticPhysics.size();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->treeStaticPhysics.getObjectInPosition(i);edkEnd();
                if(temp){
                    //scale the object and position
                    temp->position.x*=this->scaleMap.width;edkEnd();
                    temp->position.y*=this->scaleMap.height;edkEnd();
                    temp->size = this->scaleMap;edkEnd();
                    //update to the world
                    this->world->updateObjectStatus(temp);edkEnd();
                }
            }
        }

        //scale the position
        this->setPosition(positionTemp);edkEnd();

        return true;
    }
    return false;
}
bool edk::tiles::TileMap2D::setScaleMap(edk::float32 width,edk::float32 height ){
    return this->setScaleMap(edk::size2f32(width,height));edkEnd();
}
//Set World pointer
bool edk::tiles::TileMap2D::setWorld(edk::physics2D::World2D* world){
    this->cleanWorldPointer();edkEnd();
    this->world=world;edkEnd();
    if(this->world){
        this->world->addContactCallback(this);edkEnd();
        return true;
    }
    //else
    return false;
}
void edk::tiles::TileMap2D::cleanWorldPointer(){
    if(this->world){
        //remove callback
        this->world->removeContactCallback(this);edkEnd();
        //remove physics objects
        this->deletePhysicsTiles();edkEnd();
    }
    //delete all physics objects
    this->treePhysics.deleteAll();edkEnd();
    this->treeStaticPhysics.deleteAll();edkEnd();
    this->world=NULL;edkEnd();
}
//cleanTiles
void edk::tiles::TileMap2D::cleanTiles(){
    if(this->tileMap){
        for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                this->tileMap[y][x] = 0u;edkEnd();
                this->colorMap[y][x] = this->color;edkEnd();
            }
        }
    }
}
//Create a new tileMap
bool edk::tiles::TileMap2D::newTileMap(edk::size2ui32 size){
    //delete the last tileMap
    this->deleteTileMap();edkEnd();
    //test the size
    if(size.width && size.height){
        //delete the last tileMap
        bool alloc=false;edkEnd();

        //create a new tileMap
        this->tileMap = new edk::uint32*[size.height];edkEnd();
        if(this->tileMap){
            alloc=true;edkEnd();
            //create the width's
            for(edk::uint32 i=0u;i<size.height;i++){
                //
                this->tileMap[i]=new edk::uint32[size.width];edkEnd();
                if(tileMap[i]){
                    //clean the vector
                    for(edk::uint32 j=0u;j<size.width;j++){
                        this->tileMap[i][j]=0u;
                    }
                }
                else{
                    alloc=false;edkEnd();
                }
            }
        }

        if(alloc){
            //create a new colorMap
            this->colorMap = new edk::color4f32*[size.height];edkEnd();
            if(this->colorMap){
                //create the width's
                for(edk::uint32 i=0u;i<size.height;i++){
                    //
                    this->colorMap[i]=new edk::color4f32[size.width];edkEnd();
                    if(tileMap[i]){
                        //clean the vector
                        for(edk::uint32 j=0u;j<size.width;j++){
                            this->colorMap[i][j] = this->color;edkEnd();
                        }
                    }
                    else{
                        alloc=false;edkEnd();
                    }
                }
                //test if is alloc
                if(!alloc){
                    this->deleteTileMap();edkEnd();
                }
                else{
                    this->sizeMap=size;edkEnd();
                    return true;
                }
            }
        }
        else{
            this->deleteTileMap();edkEnd();
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileMap2D::newTileMap(edk::uint32 width,edk::uint32 heigth){
    //
    return this->newTileMap(edk::size2ui32(width,heigth));edkEnd();
}
//delete tileMap
void edk::tiles::TileMap2D::deleteTileMap(){
    //Delete all tileMaps
    if(this->tileMap){
        //remove all physics objects
        this->deletePhysicsTiles();edkEnd();
        for(edk::uint32 i=0u;i<this->sizeMap.height;i++){
            if(this->tileMap[i]){
                free(this->tileMap[i]);edkEnd();
            }
        }
        free(this->tileMap);edkEnd();
        this->sizeMap = edk::size2ui32(0u,0u);edkEnd();
    }
    this->tileMap=NULL;edkEnd();
    //delete the colorMap
    if(this->colorMap){
        //remove all physics objects
        for(edk::uint32 i=0u;i<this->sizeMap.height;i++){
            if(this->colorMap[i]){
                free(this->colorMap[i]);edkEnd();
            }
        }
        free(this->colorMap);edkEnd();
        this->sizeMap = edk::size2ui32(0u,0u);edkEnd();
    }
    this->colorMap=NULL;edkEnd();
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
        edk::uint32 size = this->treePhysics.size();edkEnd();
        edk::tiles::TileMap2D::PhysicsTiles* temp = NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->treePhysics.getElementInPosition(i);edkEnd();
            if(temp){
                if(temp->position.x<this->sizeMap.width
                        &&
                        temp->position.y<this->sizeMap.height){
                    //set the map
                    this->tileMap[temp->position.y][temp->position.x] = temp->tile;edkEnd();
                }
                this->world->removeObject(temp->object);edkEnd();
                temp=NULL;edkEnd();
            }
        }
        this->treePhysics.deleteAll();edkEnd();

        edk::tiles::TileMap2D::StaticTileObjects* temp2=NULL;edkEnd();
        //remove all the physics static objects
        size = this->treeStaticPhysics.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp2 = this->treeStaticPhysics.getElementInPosition(i);edkEnd();
            if(temp2){
                this->world->removeObject(temp2->object);edkEnd();
                temp2=NULL;edkEnd();
            }
        }
        this->treeStaticPhysics.deleteAll();edkEnd();
    }
}
bool edk::tiles::TileMap2D::deletePhysicTile(edk::vec2ui32 position){
    if(this->world){
        bool ret=false;edkEnd();
        //load the physics object
        edk::tiles::TileMap2D::PhysicsTiles* temp = this->treePhysics.getPhysicsTileInPosition(position);edkEnd();
        if(temp){
            //remove the object from the world
            this->world->removeObject(temp->object);edkEnd();
            //clean the tile in the map
            if(temp->position.x<this->sizeMap.width
                    &&
                    temp->position.y<this->sizeMap.height){
                //set the map
                this->tileMap[temp->position.y][temp->position.x] = temp->tile;edkEnd();
            }
            //delete the tilePhysics
            this->treePhysics.deleteObject(temp->object);edkEnd();
            ret=true;edkEnd();
        }
        edk::tiles::TileMap2D::StaticTileObjects* temp2 = this->treeStaticPhysics.getPhysicsTileInPosition(position);edkEnd();
        if(temp2){
            //remove the object from the world
            this->world->removeObject(temp2->object);edkEnd();
            //delete the object
            this->treeStaticPhysics.deleteObject(temp2->object);edkEnd();
            ret=true;edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::tiles::TileMap2D::deletePhysicTile(edk::uint32 positionX,edk::uint32 positionY){
    return this->deletePhysicTile(edk::vec2ui32(positionX,positionY));edkEnd();
}
//add physics tiles
bool edk::tiles::TileMap2D::loadPhysicsTiles(){
    //remove world objects
    this->deletePhysicsTiles();edkEnd();
    //test if have the world
    if(this->world){
        //test if have a tileSet
        if(this->tileSet){
            //then load the tiles
            edk::uint32 tileID = 0u;edkEnd();
            edk::physics2D::PhysicObject2D* temp2 = NULL;edkEnd();
            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                    //load the tileID
                    tileID = this->tileMap[y][x];edkEnd();
                    if(tileID){
                        //get the tilePhysicsObject
                        temp2 = this->tileSet->getTilePhysicsObject(tileID);edkEnd();
                        if(temp2){
                            //

                            //create the physics object
                            edk::physics2D::PhysicObject2D* temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(x,y),tileID,temp2->getType(),temp2->isSensor());edkEnd();

                            if(temp){
                                //copy the tileSet object to te temp
                                temp->cloneFrom(temp2);edkEnd();

                                temp->position = edk::vec2f32((edk::float32)x,((edk::float32)this->sizeMap.height-1.f) - y)
                                        + this->positionMap;edkEnd();
                                temp->position.x *= this->scaleMap.width;edkEnd();
                                temp->position.y *= this->scaleMap.height;edkEnd();
                                temp->size = this->scaleMap;edkEnd();
                                //add the new object to the physics world
                                //temp->size = this->sizeMap;edkEnd();
                                this->world->addObject(temp);edkEnd();
                                //remove the ID from the tileMap
                                this->tileMap[y][x] = 0u;edkEnd();
                            }
                            else{
                                this->treePhysics.deleteObject(temp);edkEnd();
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
    this->deletePhysicTile(position);edkEnd();
    //test if habe a world
    if(this->world){
        //test if have a tileSet
        if(this->tileSet){
            //test if have the position
            if(position.x<this->sizeMap.width
                    &&
                    position.y<this->sizeMap.height){
                //load the tileID
                edk::uint32 tileID = this->tileMap[position.y][position.x];edkEnd();
                if(tileID){
                    edk::physics2D::PhysicObject2D* object = this->tileSet->getTilePhysicsObject(tileID);edkEnd();
                    if(object){
                        //create the physics object
                        edk::physics2D::PhysicObject2D* temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(position.x,position.y),tileID,object->getType(),object->isSensor());edkEnd();
                        if(temp){
                            //copy the tileSet object to te temp
                            temp->cloneFrom(object);edkEnd();

                            temp->position = edk::vec2f32((edk::float32)position.x,((edk::float32)this->sizeMap.height-1.f) - position.y)
                                    + this->positionMap;edkEnd();
                            temp->position.x *= this->scaleMap.width;edkEnd();
                            temp->position.y *= this->scaleMap.height;edkEnd();
                            temp->size = this->scaleMap;edkEnd();
                            //add the new object to the physics world
                            //temp->size = this->sizeMap;edkEnd();
                            this->world->addObject(temp);edkEnd();
                            //remove the ID from the tileMap
                            this->tileMap[position.y][position.x] = 0u;edkEnd();
                            return true;
                        }
                        else{
                            this->treePhysics.deleteObject(temp);edkEnd();
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
    return this->loadPhysicTile(edk::vec2ui32(positionX,positionY));edkEnd();
}
//load static physics tiles merged to generate boxes
bool edk::tiles::TileMap2D::loadPhysicsTilesStaticMerged(){
    //test if have the world
    if(this->world){
        //test if have a tileSet
        if(this->tileSet){
            edk::uint32 width,height;edkEnd();
            //then load the tiles
            edk::uint32 tileID = 0u;edkEnd();
            edk::physics2D::PhysicObject2D* temp = NULL;edkEnd();
            edk::physics2D::PhysicObject2D* temp1 = NULL;edkEnd();
            edk::physics2D::PhysicObject2D* temp2 = NULL;edkEnd();
            edk::physics2D::PhysicObject2D* temp3 = NULL;edkEnd();
            bool canContinue=true;edkEnd();
            //rect for the polygon positions in the map
            edk::rectui32 rect;edkEnd();
            edk::rectf32 rectf;edkEnd();
            edk::vector::Stack<edk::vec2ui32> positions;edkEnd();
            edk::vec2ui32 position;edkEnd();
            edk::vec2f32 positionf;edkEnd();
            edk::size2f32 sizef;edkEnd();
            //vertexes
            edk::vec2f32 v1,v2;edkEnd();

            //create the rectangle
            edk::shape::Rectangle2D rectangle;edkEnd();
            rectangle.setPivoToCenter();edkEnd();
            //
            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                    //If aready have the position in physics objects. Then it not create another object
                    if(this->treeStaticPhysics.havePosition(edk::vec2ui32(x,y))){
                        continue;
                    }

                    //test if the object is a valid static with one rectangle
                    if((temp1 = this->getStaticTile(x,y))){
                        positions.clean();edkEnd();

                        width=x;edkEnd();
                        height=y;edkEnd();
                        //set rect
                        rect.origin.x=x;edkEnd();
                        rect.origin.y=y;edkEnd();

                        rect.size.width=width;edkEnd();
                        rect.size.height=height;edkEnd();

                        position.x = x;edkEnd();
                        position.y = y;edkEnd();
                        positions.pushBack(position);edkEnd();


                        temp3=temp1;edkEnd();


                        //search for the neibors in X
                        do{
                            temp2=NULL;edkEnd();
                            width++;edkEnd();
                            //height++;edkEnd();
                            if(height<this->sizeMap.height && width<this->sizeMap.width){
                                if(!this->treeStaticPhysics.havePosition(edk::vec2ui32(width,height))){
                                    temp2 = this->getStaticTile(width,height);edkEnd();
                                    if(temp2){
                                        //compare if the temp1 and temp2 are equal
                                        if(this->compareStaticTile(temp1,temp2)){
                                            //copy the last values
                                            rect.size.width=width;edkEnd();
                                            rect.size.height=height;edkEnd();
                                            temp3=temp2;edkEnd();

                                            position.x = width;edkEnd();
                                            position.y = height;edkEnd();
                                            positions.pushBack(position);edkEnd();
                                        }
                                        else{
                                            temp2=NULL;edkEnd();
                                        }
                                    }
                                }
                            }
                        }while(temp2);edkEnd();

                        canContinue=true;edkEnd();
                        //
                        //search for other neibors in Y
                        for(edk::uint32 j=y+1u;j<this->sizeMap.height;j++){
                            for(edk::uint32 i=x;i<width;i++){
                                if(!this->treeStaticPhysics.havePosition(edk::vec2ui32(i,j))){
                                    //search for all objects as like the temp1
                                    temp2 = this->getStaticTile(i,j);edkEnd();
                                    if(temp2){
                                        //test if the temp2 is equal temp1
                                        if(!this->compareStaticTile(temp1,temp2)){
                                            canContinue=false;edkEnd();
                                            break;
                                        }
                                    }
                                    else{
                                        //else there is a hole in the tile.
                                        canContinue=false;edkEnd();
                                        break;
                                    }
                                }
                                else{
                                    canContinue=false;edkEnd();
                                    break;
                                }
                            }
                            //
                            if(!canContinue){
                                break;
                            }
                            else{
                                for(edk::uint32 i=x;i<width;i++){
                                    //push back the positions
                                    position.x = i;edkEnd();
                                    position.y = j;edkEnd();
                                    positions.pushBack(position);edkEnd();

                                    rect.size.width=i;edkEnd();
                                    rect.size.height=j;edkEnd();

                                    temp3=temp2;edkEnd();
                                }
                            }
                        }

                        //test if the rect size is different than origin
                        if(rect.size.width>rect.origin.x
                                ||
                                rect.size.height>rect.origin.y
                                ){
                            //generate the new physics object
                            positionf = this->getTileWorldPosition(rect.origin.x,rect.origin.y);edkEnd();
                            temp1->physicMesh.selectPolygon(0u);edkEnd();
                            v1 = temp1->physicMesh.selectedGetVertexPosition(0u);edkEnd();
                            v2 = temp1->physicMesh.selectedGetVertexPosition(1u);edkEnd();
                            if(v2.x < v1.x){
                                v1.x=v2.x;edkEnd();
                            }
                            if(v2.y > v1.y){
                                v1.y=v2.y;edkEnd();
                            }
                            rectf.origin.x = positionf.x + (v1.x * this->getScaleMap().width);edkEnd();
                            rectf.origin.y = positionf.y + (v1.y * this->getScaleMap().height);edkEnd();

                            temp3->physicMesh.selectPolygon(0u);edkEnd();
                            positionf = this->getTileWorldPosition(rect.size.width,rect.size.height);edkEnd();
                            v1 = temp3->physicMesh.selectedGetVertexPosition(0u);edkEnd();
                            v2 = temp3->physicMesh.selectedGetVertexPosition(1u);edkEnd();
                            if(v2.x > v1.x){
                                v1.x=v2.x;edkEnd();
                            }
                            if(v2.y < v1.y){
                                v1.y=v2.y;edkEnd();
                            }
                            rectf.size.width = positionf.x + (v1.x * this->getScaleMap().width);edkEnd();
                            rectf.size.height = positionf.y + (v1.y * this->getScaleMap().height);edkEnd();

                            sizef.width = rectf.size.width - rectf.origin.x;edkEnd();
                            sizef.height = rectf.size.height - rectf.origin.y;edkEnd();

                            //calculate the object position
                            positionf.x = sizef.width*0.5f + (rectf.origin.x);edkEnd();
                            positionf.y = sizef.height*0.5f + (rectf.origin.y);edkEnd();

                            //create the object
                            temp = this->treeStaticPhysics.newObjectInPositions(&positions,tileID,edk::physics::StaticBody,false);edkEnd();

                            if(temp){
                                //copy the tileSet object to te temp
                                temp->physicMesh.addPolygon(rectangle);edkEnd();

                                //copy the groups
                                {
                                    edk::uint32 sizeGroup = temp1->getCollisionGroupSize();edkEnd();
                                    for(edk::uint32 i=0u;i<sizeGroup;i++){
                                        temp->addCollisionGroup(temp1->getCollisionGroupInPosition(i));edkEnd();
                                    }
                                    sizeGroup = temp1->getNotCollisionGroupSize();edkEnd();
                                    for(edk::uint32 i=0u;i<sizeGroup;i++){
                                        temp->addNotCollisionGroup(temp1->getNotCollisionGroupInPosition(i));edkEnd();
                                    }
                                }

                                temp->position = positionf;edkEnd();
                                temp->size.width = edk::Math::module(sizef.width);edkEnd();
                                temp->size.height = edk::Math::module(sizef.height);edkEnd();
                                //add the new object to the physics world
                                if(!this->world->addObject(temp)){
                                    this->treeStaticPhysics.deleteObject(temp);edkEnd();
                                }
                            }
                            else{
                                this->treeStaticPhysics.deleteObject(temp);edkEnd();
                            }
                        }
                        else{
                            //else just clone the object
                            positionf = this->getTileWorldPosition(rect.origin.x,rect.origin.y);edkEnd();

                            //create the object
                            temp = this->treeStaticPhysics.newObjectInPositions(&positions,tileID,edk::physics::StaticBody,false);edkEnd();

                            if(temp){
                                //copy the tileSet object to te temp
                                temp->physicMesh.addPolygon(rectangle);edkEnd();

                                //copy the groups
                                {
                                    edk::uint32 sizeGroup = temp1->getCollisionGroupSize();edkEnd();
                                    for(edk::uint32 i=0u;i<sizeGroup;i++){
                                        temp->addCollisionGroup(temp1->getCollisionGroupInPosition(i));edkEnd();
                                    }
                                    sizeGroup = temp1->getNotCollisionGroupSize();edkEnd();
                                    for(edk::uint32 i=0u;i<sizeGroup;i++){
                                        temp->addNotCollisionGroup(temp1->getNotCollisionGroupInPosition(i));edkEnd();
                                    }
                                }

                                temp->position = positionf;edkEnd();
                                temp->size = this->scaleMap;edkEnd();
                                //add the new object to the physics world
                                if(!this->world->addObject(temp)){
                                    this->treeStaticPhysics.deleteObject(temp);edkEnd();
                                }
                            }
                            else{
                                this->treeStaticPhysics.deleteObject(temp);edkEnd();
                            }
                        }
                        //it create the object in to the treeStaticOhysics. Then it don't need make an object in treePhysics
                        continue;
                    }

                    //IF it din't create the object in treeStaticPhysics. Then it make the tile as a object in the old way. But only for static bodies

                    //load the tileID
                    tileID = this->tileMap[y][x];edkEnd();
                    if(tileID){
                        //get the tilePhysicsObject
                        temp1 = this->tileSet->getTilePhysicsObject(tileID);edkEnd();
                        if(temp1){
                            //test if the temp1 is a dynamic physics tile
                            if(temp1->getType() == edk::physics::StaticBody){
                                //create the physics object
                                temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(x,y),tileID,temp1->getType(),temp1->isSensor());edkEnd();

                                if(temp){
                                    //copy the tileSet object to te temp
                                    temp->cloneFrom(temp1);edkEnd();

                                    temp->position = edk::vec2f32((edk::float32)x,((edk::float32)this->sizeMap.height-1.f) - y)
                                            + this->positionMap;edkEnd();
                                    temp->position.x *= this->scaleMap.width;edkEnd();
                                    temp->position.y *= this->scaleMap.height;edkEnd();
                                    temp->size = this->scaleMap;edkEnd();
                                    //add the new object to the physics world
                                    //temp->size = this->sizeMap;edkEnd();
                                    this->world->addObject(temp);edkEnd();
                                    //remove the ID from the tileMap
                                    this->tileMap[y][x] = 0u;edkEnd();
                                }
                                else{
                                    this->treePhysics.deleteObject(temp);edkEnd();
                                }
                            }
                        }
                    }
                }
            }
            positions.clean();edkEnd();
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
            edk::uint32 tileID = 0u;edkEnd();
            edk::physics2D::PhysicObject2D* temp2 = NULL;edkEnd();
            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                    //load the tileID
                    tileID = this->tileMap[y][x];edkEnd();
                    if(tileID){
                        //get the tilePhysicsObject
                        temp2 = this->tileSet->getTilePhysicsObject(tileID);edkEnd();
                        if(temp2){
                            //test if the temp2 is a dynamic physics tile
                            if(temp2->getType() == edk::physics::DynamicBody){

                                //create the physics object
                                edk::physics2D::PhysicObject2D* temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(x,y),tileID,temp2->getType(),temp2->isSensor());edkEnd();

                                if(temp){
                                    //copy the tileSet object to te temp
                                    temp->cloneFrom(temp2);edkEnd();

                                    temp->position = edk::vec2f32((edk::float32)x,((edk::float32)this->sizeMap.height-1.f) - y)
                                            + this->positionMap;edkEnd();
                                    temp->position.x *= this->scaleMap.width;edkEnd();
                                    temp->position.y *= this->scaleMap.height;edkEnd();
                                    temp->size = this->scaleMap;edkEnd();
                                    //add the new object to the physics world
                                    //temp->size = this->sizeMap;edkEnd();
                                    this->world->addObject(temp);edkEnd();
                                    //remove the ID from the tileMap
                                    this->tileMap[y][x] = 0u;edkEnd();
                                }
                                else{
                                    this->treePhysics.deleteObject(temp);edkEnd();
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
            edk::uint32 tileID = 0u;edkEnd();
            edk::physics2D::PhysicObject2D* temp2 = NULL;edkEnd();
            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                    //load the tileID
                    tileID = this->tileMap[y][x];edkEnd();
                    if(tileID){
                        //get the tilePhysicsObject
                        temp2 = this->tileSet->getTilePhysicsObject(tileID);edkEnd();
                        if(temp2){
                            //test if the temp2 is a dynamic physics tile
                            if(temp2->getType() == edk::physics::KinematicBody){

                                //create the physics object
                                edk::physics2D::PhysicObject2D* temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(x,y),tileID,temp2->getType(),temp2->isSensor());edkEnd();

                                if(temp){
                                    //copy the tileSet object to te temp
                                    temp->cloneFrom(temp2);edkEnd();

                                    temp->position = edk::vec2f32((edk::float32)x,((edk::float32)this->sizeMap.height-1.f) - y)
                                            + this->positionMap;edkEnd();
                                    temp->position.x *= this->scaleMap.width;edkEnd();
                                    temp->position.y *= this->scaleMap.height;edkEnd();
                                    temp->size = this->scaleMap;edkEnd();
                                    //add the new object to the physics world
                                    //temp->size = this->sizeMap;edkEnd();
                                    this->world->addObject(temp);edkEnd();
                                    //remove the ID from the tileMap
                                    this->tileMap[y][x] = 0u;edkEnd();
                                }
                                else{
                                    this->treePhysics.deleteObject(temp);edkEnd();
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
            edk::uint32 tileID = 0u;edkEnd();
            edk::physics2D::PhysicObject2D* temp2 = NULL;edkEnd();
            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                    //load the tileID
                    tileID = this->tileMap[y][x];edkEnd();
                    if(tileID){
                        //get the tilePhysicsObject
                        temp2 = this->tileSet->getTilePhysicsObject(tileID);edkEnd();
                        if(temp2){
                            //test if the temp2 is a dynamic physics tile
                            if(temp2->getType() == edk::physics::KinematicBody || temp2->getType() == edk::physics::DynamicBody){

                                //create the physics object
                                edk::physics2D::PhysicObject2D* temp = this->treePhysics.newObjectInPosition(edk::vec2ui32(x,y),tileID,temp2->getType(),temp2->isSensor());edkEnd();

                                if(temp){
                                    //copy the tileSet object to te temp
                                    temp->cloneFrom(temp2);edkEnd();

                                    temp->position = edk::vec2f32((edk::float32)x,((edk::float32)this->sizeMap.height-1.f) - y)
                                            + this->positionMap;edkEnd();
                                    temp->position.x *= this->scaleMap.width;edkEnd();
                                    temp->position.y *= this->scaleMap.height;edkEnd();
                                    temp->size = this->scaleMap;edkEnd();
                                    //add the new object to the physics world
                                    //temp->size = this->sizeMap;edkEnd();
                                    this->world->addObject(temp);edkEnd();
                                    //remove the ID from the tileMap
                                    this->tileMap[y][x] = 0u;edkEnd();
                                }
                                else{
                                    this->treePhysics.deleteObject(temp);edkEnd();
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
            edk::physics2D::PhysicObject2D* ret=NULL;edkEnd();
            //load the physicsObject
            ret =  this->treePhysics.getPhysicsObjectInPosition(edk::vec2ui32(position.x,position.y));edkEnd();
            if(ret){
                return ret;
            }
            else{
                return this->treeStaticPhysics.getPhysicsObjectInPosition(edk::vec2ui32(position.x,position.y));edkEnd();
            }
        }
    }
    return NULL;
}
edk::physics2D::PhysicObject2D* edk::tiles::TileMap2D::getPhysicTile(edk::uint32 positionX,edk::uint32 positionY){
    return this->getPhysicTile(edk::vec2ui32 (positionX,positionY));edkEnd();
}
//test ih have the physicsObject
bool edk::tiles::TileMap2D::havePhysicObject(edk::physics2D::PhysicObject2D* object){
    if(this->treePhysics.haveObject(object)){
        return true;
    }
    //else return it from another tree
    return this->treeStaticPhysics.haveObject(object);edkEnd();
}
edk::vec2ui32 edk::tiles::TileMap2D::getPhysicObjectPosition(edk::physics2D::PhysicObject2D* object){
    if(this->treePhysics.haveObject(object)){
        return this->treePhysics.getPositionOfObject(object);edkEnd();
    }
    if(this->treeStaticPhysics.haveObject(object) && this->treeStaticPhysics.getPositionSizeOfObject(object)){
        return this->treeStaticPhysics.getPositionOfObject(object,0u);edkEnd();
    }
    return edk::vec2ui32(0u,0u);edkEnd();
}

//GETTERS
//return the tileID
edk::uint32 edk::tiles::TileMap2D::getTileID(edk::vec2ui32 position){
    //test the position
    if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
        //set the position
        return this->tileMap[position.y][position.x];edkEnd();
    }
    return 0u;edkEnd();
}
edk::uint32 edk::tiles::TileMap2D::getTileID(edk::uint32 positionX,edk::uint32 positionY){
    return this->getTileID(edk::vec2ui32(positionX,positionY));edkEnd();
}
edk::uint32 edk::tiles::TileMap2D::getTileID(edk::uint32 position){
    if(position){
        if(this->sizeMap.width && this->sizeMap.height){
            position--;edkEnd();
            return this->getTileID(edk::vec2ui32(position%this->sizeMap.width,position/this->sizeMap.width));edkEnd();
        }
    }
    return 0u;edkEnd();
}
//return the tileColor
edk::color4f32 edk::tiles::TileMap2D::getTileColor(edk::vec2ui32 position){
    edk::color4f32 ret;edkEnd();
    //test the position
    if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
        //set the position
        ret=this->colorMap[position.y][position.x];edkEnd();
    }
    return ret;
}
edk::color4f32 edk::tiles::TileMap2D::getTileColor(edk::uint32 positionX,edk::uint32 positionY){
    return this->getTileColor(edk::vec2ui32(positionX,positionY));edkEnd();
}
edk::color4f32 edk::tiles::TileMap2D::getTileColor(edk::uint32 position){
    edk::color4f32 ret;edkEnd();
    if(position){
        if(this->sizeMap.width && this->sizeMap.height){
            position--;edkEnd();
            ret=this->getTileColor(edk::vec2ui32(position%this->sizeMap.width,position/this->sizeMap.width));edkEnd();
        }
    }
    return ret;
}
//return the size of the map
edk::size2ui32 edk::tiles::TileMap2D::getMapSize(){
    return this->sizeMap;edkEnd();
}
//return the scale of the map
edk::size2f32 edk::tiles::TileMap2D::getScaleMap(){
    return this->scaleMap;edkEnd();
}
//return the position
edk::vec2f32 edk::tiles::TileMap2D::getPosition(){
    return edk::vec2f32(this->positionMap.x * this->scaleMap.width,
                        this->positionMap.y * this->scaleMap.height
                        );edkEnd();
}
edk::float32 edk::tiles::TileMap2D::getPositionX(){
    return this->positionMap.x * this->scaleMap.width;edkEnd();
}
edk::float32 edk::tiles::TileMap2D::getPositionY(){
    return this->positionMap.y * this->scaleMap.height;edkEnd();
}
//get the tile position in the position
edk::vec2ui32 edk::tiles::TileMap2D::getPointPosition(edk::vec2f32 point,bool* inside){
    edk::vec2ui32 ret(0u,0u);edkEnd();
    //scale the points
    point.x /= this->scaleMap.width;edkEnd();
    point.y /= this->scaleMap.height;edkEnd();

    point.y+=0.5f-this->positionMap.x;edkEnd();
    point.x+=0.5f-this->positionMap.x;edkEnd();

    if(point.x>0.f && point.y>0.f){
        //convert to the ret
        ret = edk::vec2ui32((edk::uint32)point.x,(edk::uint32)point.y);edkEnd();
        //test the size
        if(ret.x<this->sizeMap.width && ret.y<this->sizeMap.height){
            //mirror the y
            ret.y = (edk::uint32)(((edk::int32)ret.y*-1) + this->sizeMap.height-1u);edkEnd();
            if(inside){
                *inside = true;edkEnd();
            }
            //return ret
            return ret;
        }
    }
    if(inside){
        *inside = false;edkEnd();
    }
    return edk::vec2ui32(0u,0u);edkEnd();
}

//Desenha o tileMap
void edk::tiles::TileMap2D::draw(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTile( this->tileMap[y][x]
                                         ,(x*this->scaleMap.width) + positionTemp.x
                                         ,(y2*this->scaleMap.height) + positionTemp.y
                                         ,0.f,this->scaleMap,color
                                         );edkEnd();
            }
        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::draw(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTile( this->tileMap[y][x]
                                             ,(x*this->scaleMap.width) + positionTemp.x
                                             ,(y2*this->scaleMap.height) + positionTemp.y
                                             ,0.f,this->scaleMap,color
                                             );edkEnd();
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWithoutMaterial(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileWithoutMaterial(this->tileMap[y][x]
                                                       ,(x*this->scaleMap.width) + positionTemp.x
                                                       ,(y2*this->scaleMap.height) + positionTemp.y
                                                       ,0.f,this->scaleMap,color
                                                       );edkEnd();
            }
        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWithoutMaterial(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileWithoutMaterial( this->tileMap[y][x]
                                                            ,(x*this->scaleMap.width) + positionTemp.x
                                                            ,(y2*this->scaleMap.height) + positionTemp.y
                                                            ,0.f,this->scaleMap,color
                                                            );edkEnd();
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawInsideWorldRect(edk::rectf32 rect,edk::color4f32 color){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->draw(newRect.origin,edk::size2ui32(newRect.origin.x+newRect.size.width,newRect.origin.y+newRect.size.height),color);edkEnd();
}
void edk::tiles::TileMap2D::drawInsideWorldRectPoints(edk::rectf32 rect,edk::color4f32 color){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->draw(newRect.origin,newRect.size,color);edkEnd();
}
void edk::tiles::TileMap2D::drawIsometric(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTile( this->tileMap[y][x]
                                         ,(x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                         ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                         ,0.f,this->scaleMap,color
                                         );edkEnd();
            }
        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometric(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTile( this->tileMap[y][x]
                                             ,(x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                             ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                             ,0.f,this->scaleMap,color
                                             );edkEnd();
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometricInsideWorldRect(edk::rectf32 /*rect*/,edk::color4f32 /*color*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;edkEnd();
    rect.origin.y /= this->scaleMap.height;edkEnd();
    rect.size.width /= this->scaleMap.width;edkEnd();
    rect.size.height /= this->scaleMap.height;edkEnd();

    rect.origin.y+=0.5;edkEnd();
    rect.origin.x+=0.5;edkEnd();

    edk::vec2f32 first = rect.origin;edkEnd();
    //
    rect.origin.x +=rect.size.width;edkEnd();
    first.y +=rect.size.height;edkEnd();

    //translate the origin
    rect.origin.x -= (this->positionMap.x);edkEnd();
    rect.origin.y -= (this->positionMap.y);edkEnd();
    first.x -= (this->positionMap.x);edkEnd();
    first.y -= (this->positionMap.y);edkEnd();

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;edkEnd();
    first.y= (first.y*-1.f) + this->sizeMap.height;edkEnd();

    //increment the last pointer
    rect.origin+=1.f;edkEnd();

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width){
rect.origin.x=this->sizeMap.width;edkEnd();
}
    if(rect.origin.y>this->sizeMap.height){
 rect.origin.y=this->sizeMap.height;edkEnd();
}
    //filter the first pointer
    if(first.x<0.f){
 first.x=0.f;edkEnd();
}
    if(first.y<0.f){
first.y=0.f;edkEnd();
}

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );edkEnd();
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );edkEnd();

    this->drawIsometric(origin,size,color);edkEnd();
*/
}
//Draw tileMap without passing a color
void edk::tiles::TileMap2D::draw(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTile( this->tileMap[y][x]
                                         ,(x*this->scaleMap.width) + positionTemp.x
                                         ,(y2*this->scaleMap.height) + positionTemp.y
                                         ,0.f,this->scaleMap,this->colorMap[y][x]
                                         );edkEnd();
            }
        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::draw(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTile( this->tileMap[y][x]
                                             ,(x*this->scaleMap.width) + positionTemp.x
                                             ,(y2*this->scaleMap.height) + positionTemp.y
                                             ,0.f,this->scaleMap,this->colorMap[y][x]
                                             );edkEnd();
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWithoutMaterial(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileWithoutMaterial(this->tileMap[y][x]
                                                       ,(x*this->scaleMap.width) + positionTemp.x
                                                       ,(y2*this->scaleMap.height) + positionTemp.y
                                                       ,0.f,this->scaleMap,this->colorMap[y][x]
                                                       );edkEnd();
            }
        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWithoutMaterial(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileWithoutMaterial( this->tileMap[y][x]
                                                            ,(x*this->scaleMap.width) + positionTemp.x
                                                            ,(y2*this->scaleMap.height) + positionTemp.y
                                                            ,0.f,this->scaleMap,this->colorMap[y][x]
                                                            );edkEnd();
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawInsideWorldRect(edk::rectf32 rect){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->draw(newRect.origin,newRect.size);edkEnd();
}
void edk::tiles::TileMap2D::drawInsideWorldRectPoints(edk::rectf32 rect){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->draw(newRect.origin,edk::size2ui32(newRect.origin.x+newRect.size.width,newRect.origin.y+newRect.size.height));edkEnd();
}
void edk::tiles::TileMap2D::drawIsometric(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTile( this->tileMap[y][x]
                                         ,(x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                         ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                         ,0.f,this->scaleMap,this->colorMap[y][x]
                                         );edkEnd();
            }
        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometric(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTile( this->tileMap[y][x]
                                             ,(x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                             ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                             ,0.f,this->scaleMap,this->colorMap[y][x]
                                             );edkEnd();
                }
            }

        }

        //draw physics objects
        this->treePhysics.render();edkEnd();
        //this->treeStaticPhysics.render();edkEnd();

        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometricInsideWorldRect(edk::rectf32 /*rect*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;edkEnd();
    rect.origin.y /= this->scaleMap.height;edkEnd();
    rect.size.width /= this->scaleMap.width;edkEnd();
    rect.size.height /= this->scaleMap.height;edkEnd();

    rect.origin.y+=0.5;edkEnd();
    rect.origin.x+=0.5;edkEnd();

    edk::vec2f32 first = rect.origin;edkEnd();
    //
    rect.origin.x +=rect.size.width;edkEnd();
    first.y +=rect.size.height;edkEnd();

    //translate the origin
    rect.origin.x -= (this->positionMap.x);edkEnd();
    rect.origin.y -= (this->positionMap.y);edkEnd();
    first.x -= (this->positionMap.x);edkEnd();
    first.y -= (this->positionMap.y);edkEnd();

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;edkEnd();
    first.y= (first.y*-1.f) + this->sizeMap.height;edkEnd();

    //increment the last pointer
    rect.origin+=1.f;edkEnd();

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width){
rect.origin.x=this->sizeMap.width;edkEnd();
}
    if(rect.origin.y>this->sizeMap.height){
rect.origin.y=this->sizeMap.height;edkEnd();
}
    //filter the first pointer
    if(first.x<0.f){
first.x=0.f;edkEnd();
}
    if(first.y<0.f){
first.y=0.f;edkEnd();
}

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );edkEnd();
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );edkEnd();

    this->drawIsometric(origin,size);edkEnd();
*/
}

//draw wireTiles
void edk::tiles::TileMap2D::drawWire(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                            ,(y2*this->scaleMap.height) + positionTemp.y
                                            ,0.f,this->scaleMap,color
                                            );edkEnd();
            }
        }
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWire(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,color
                                                );edkEnd();
                }
            }
        }
        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        //this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWireInsideWorldRect(edk::rectf32 rect,edk::color4f32 color){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->drawWire(newRect.origin,newRect.size,color);edkEnd();
}
void edk::tiles::TileMap2D::drawIsometricWire(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileIsometricWire((x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                     ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                     ,0.f,this->scaleMap,color
                                                     );edkEnd();
            }
        }
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometricWire(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileIsometricWire((x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                         ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                         ,0.f,this->scaleMap,color
                                                         );edkEnd();
                }
            }
        }
        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        //this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometricWireInsideWorldRect(edk::rectf32 /*rect*/,edk::color4f32 /*color*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;edkEnd();
    rect.origin.y /= this->scaleMap.height;edkEnd();
    rect.size /= this->scaleMap;edkEnd();

    rect.origin.y+=0.5;edkEnd();
    rect.origin.x+=0.5;edkEnd();

    edk::vec2f32 first = rect.origin;edkEnd();
    //
    rect.origin.x +=rect.size.width;edkEnd();
    first.y +=rect.size.height;edkEnd();

    //translate the origin
    rect.origin.x -= (this->positionMap.x);edkEnd();
    rect.origin.y -= (this->positionMap.y);edkEnd();
    first.x -= (this->positionMap.x);edkEnd();
    first.y -= (this->positionMap.y);edkEnd();

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;edkEnd();
    first.y= (first.y*-1.f) + this->sizeMap.height;edkEnd();

    //increment the last pointer
    rect.origin+=1.f;edkEnd();

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width){
 rect.origin.x=this->sizeMap.width;edkEnd();
 }
    if(rect.origin.y>this->sizeMap.height){
rect.origin.y=this->sizeMap.height;edkEnd();
}
    //filter the first pointer
    if(first.x<0.f){
 first.x=0.f;edkEnd();
 }
    if(first.y<0.f){
first.y=0.f;edkEnd();
}

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );edkEnd();
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );edkEnd();

    this->drawIsometricWire(origin,size,color);edkEnd();
    */
}
//draw wireTiles without passing a color
void edk::tiles::TileMap2D::drawWire(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                            ,(y2*this->scaleMap.height) + positionTemp.y
                                            ,0.f,this->scaleMap,this->colorMap[y][x]
                                            );edkEnd();
            }
        }
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWire(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,this->colorMap[y][x]
                                                );edkEnd();
                }
            }
        }
        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        //this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWireInsideWorldRect(edk::rectf32 rect){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->drawWire(newRect.origin,newRect.size);edkEnd();
}
void edk::tiles::TileMap2D::drawIsometricWire(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                this->tileSet->drawTileIsometricWire((x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                     ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                     ,0.f,this->scaleMap,this->colorMap[y][x]
                                                     );edkEnd();
            }
        }
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometricWire(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    this->tileSet->drawTileIsometricWire((x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                         ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                         ,0.f,this->scaleMap,this->colorMap[y][x]
                                                         );edkEnd();
                }
            }
        }
        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        //this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometricWireInsideWorldRect(edk::rectf32 /*rect*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;edkEnd();
    rect.origin.y /= this->scaleMap.height;edkEnd();
    rect.size /= this->scaleMap;edkEnd();

    rect.origin.y+=0.5;edkEnd();
    rect.origin.x+=0.5;edkEnd();

    edk::vec2f32 first = rect.origin;edkEnd();
    //
    rect.origin.x +=rect.size.width;edkEnd();
    first.y +=rect.size.height;edkEnd();

    //translate the origin
    rect.origin.x -= (this->positionMap.x);edkEnd();
    rect.origin.y -= (this->positionMap.y);edkEnd();
    first.x -= (this->positionMap.x);edkEnd();
    first.y -= (this->positionMap.y);edkEnd();

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;edkEnd();
    first.y= (first.y*-1.f) + this->sizeMap.height;edkEnd();

    //increment the last pointer
    rect.origin+=1.f;edkEnd();

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width){
 rect.origin.x=this->sizeMap.width;edkEnd();
 }
    if(rect.origin.y>this->sizeMap.height){
 rect.origin.y=this->sizeMap.height;edkEnd();
 }
    //filter the first pointer
    if(first.x<0.f){
 first.x=0.f;edkEnd();
 }
    if(first.y<0.f){
 first.y=0.f;edkEnd();
 }

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );edkEnd();
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );edkEnd();

    this->drawIsometricWire(origin,size);edkEnd();
    */
}

//draw wireTiles
void edk::tiles::TileMap2D::drawWirePhysics(edk::color4f32 color){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,color
                                                );edkEnd();
                }
            }
        }
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWirePhysics(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                        this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                    ,(y2*this->scaleMap.height) + positionTemp.y
                                                    ,0.f,this->scaleMap,color
                                                    );edkEnd();
                    }
                }
            }
        }
        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        //this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWirePhysicsInsideWorldRect(edk::rectf32 rect,edk::color4f32 color){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->drawWirePhysics(newRect.origin,newRect.size,color);edkEnd();
}
//draw wireTiles without passing a color
void edk::tiles::TileMap2D::drawWirePhysics(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,this->colorMap[y][x]
                                                );edkEnd();
                }
            }
        }
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWirePhysics(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                        this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                    ,(y2*this->scaleMap.height) + positionTemp.y
                                                    ,0.f,this->scaleMap,this->colorMap[y][x]
                                                    );edkEnd();
                    }
                }
            }
        }
        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        //this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWirePhysicsInsideWorldRect(edk::rectf32 rect){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->drawWirePhysics(newRect.origin,newRect.size);edkEnd();
}

//draw wireWitPhysics
void edk::tiles::TileMap2D::drawWireWithPhysics(edk::color4f32 color,edk::color4f32 physColor){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();
        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,physColor
                                                );edkEnd();
                }
                else{
                    this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                ,(y2*this->scaleMap.height) + positionTemp.y
                                                ,0.f,this->scaleMap,color
                                                );edkEnd();
                }
            }
        }
        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWireWithPhysics(edk::vec2ui32 origin,edk::size2ui32 last,edk::color4f32 color,edk::color4f32 physColor){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();

            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    if(this->tileSet->isTilePhysics(this->tileMap[y][x])){
                        this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                    ,(y2*this->scaleMap.height) + positionTemp.y
                                                    ,0.f,this->scaleMap,physColor
                                                    );edkEnd();
                    }
                    else{
                        this->tileSet->drawTileWire((x*this->scaleMap.width) + positionTemp.x
                                                    ,(y2*this->scaleMap.height) + positionTemp.y
                                                    ,0.f,this->scaleMap,color
                                                    );edkEnd();
                    }
                }
            }
        }
        edk::GU::guPopMatrix();edkEnd();

        //set the draw tiles to start or end
        //this->updateDrawTiles(origin,last);edkEnd();
    }
}
void edk::tiles::TileMap2D::drawWireWithPhysicsInsideWorldRect(edk::rectf32 rect,edk::color4f32 color,edk::color4f32 physColor){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->drawWireWithPhysics(newRect.origin,newRect.size,color,physColor);edkEnd();
}
//draw one especific tile in wirte
bool edk::tiles::TileMap2D::drawTileWire(edk::vec2ui32 position,edk::color4f32 color){
    if(this->tileSet){
        //test the position
        if(position.x < this->sizeMap.width && position.y < this->sizeMap.height){
            //draw the tile
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            edk::int64 y2 = (position.y*-1) + this->sizeMap.height-1u;edkEnd();
            //draw the tile
            this->tileSet->drawTileWire((position.x*this->scaleMap.width) + positionTemp.x
                                        ,(y2*this->scaleMap.height) + positionTemp.y
                                        ,0.f,this->scaleMap,color
                                        );edkEnd();
            edk::GU::guPopMatrix();edkEnd();
            //then return true
            return true;
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileMap2D::drawTileWire(edk::uint32 positionX,edk::uint32 positionY,edk::color4f32 color){
    return this->drawTileWire(edk::vec2ui32(positionX,positionY),color);edkEnd();
}
bool edk::tiles::TileMap2D::drawTileWire(edk::uint32 position,edk::color4f32 color){
    if(position){
        if(this->sizeMap.width && this->sizeMap.height){
            position--;edkEnd();
            return this->drawTileWire(edk::vec2ui32(position%this->sizeMap.width,position/this->sizeMap.width),color);edkEnd();
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
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            edk::int64 y2 = (position.y*-1) + this->sizeMap.height-1u;edkEnd();
            //draw the tile
            this->tileSet->drawTileWire((position.x*this->scaleMap.width) + positionTemp.x
                                        ,(y2*this->scaleMap.height) + positionTemp.y
                                        ,0.f,this->scaleMap,this->colorMap[position.y][position.x]
                    );edkEnd();
            edk::GU::guPopMatrix();edkEnd();
            //then return true
            return true;
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileMap2D::drawTileWire(edk::uint32 positionX,edk::uint32 positionY){
    return this->drawTileWire(edk::vec2ui32(positionX,positionY));edkEnd();
}
bool edk::tiles::TileMap2D::drawTileWire(edk::uint32 position){
    if(position){
        if(this->sizeMap.width && this->sizeMap.height){
            position--;edkEnd();
            edk::vec2ui32 vec(position%this->sizeMap.width,position/this->sizeMap.width);edkEnd();
            return this->drawTileWire(vec,this->colorMap[vec.y][vec.x]);edkEnd();
        }
    }
    return false;
}

//draw the tile for selection
void edk::tiles::TileMap2D::drawSelectionWithID(edk::uint8 id){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();

        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                edk::GU::guPushName(edk::BinaryConverter::joinBits(id,((this->sizeMap.width * y) + x)+1u,24));edkEnd();
                this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x
                                                  ,(y2*this->scaleMap.height) + positionTemp.y
                                                  ,0.f,this->scaleMap
                                                  );edkEnd();
                edk::GU::guPopName();edkEnd();
            }
        }

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawSelectionWithID(edk::vec2ui32 origin,edk::size2ui32 last,edk::uint8 id){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();
            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    edk::GU::guPushName(edk::BinaryConverter::joinBits(id,((this->sizeMap.width * y) + x)+1u,24));edkEnd();
                    this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x
                                                      ,(y2*this->scaleMap.height) + positionTemp.y
                                                      ,0.f,this->scaleMap
                                                      );edkEnd();
                    edk::GU::guPopName();edkEnd();
                }
            }
        }

        //this->treePhysics.print();edkEnd();
        //this->treeStaticPhysics.printf();edkEnd();

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawSelection(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();

        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                edk::GU::guPushName(((this->sizeMap.width * y) + x)+1u);edkEnd();
                this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x
                                                  ,(y2*this->scaleMap.height) + positionTemp.y
                                                  ,0.f,this->scaleMap
                                                  );edkEnd();
                edk::GU::guPopName();edkEnd();
            }
        }

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawSelection(edk::vec2ui32 origin,edk::size2ui32 last){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();
            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    edk::GU::guPushName(((this->sizeMap.width * y) + x)+1u);edkEnd();
                    this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x
                                                      ,(y2*this->scaleMap.height) + positionTemp.y
                                                      ,0.f,this->scaleMap
                                                      );edkEnd();
                    edk::GU::guPopName();edkEnd();
                }
            }
        }

        //this->treePhysics.print();edkEnd();
        //this->treeStaticPhysics.printf();edkEnd();

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawInsideWorldRectSelectionWithID(edk::rectf32 rect,edk::uint8 id){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->drawSelectionWithID(newRect.origin,newRect.size,id);edkEnd();
}
void edk::tiles::TileMap2D::drawInsideWorldRectPointsSelectionWithID(edk::rectf32 rect,edk::uint8 id){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->drawSelectionWithID(newRect.origin,edk::size2ui32(newRect.origin.x+newRect.size.width,newRect.origin.y+newRect.size.height));edkEnd();
}
void edk::tiles::TileMap2D::drawInsideWorldRectSelection(edk::rectf32 rect){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->drawSelection(newRect.origin,newRect.size);edkEnd();
}
void edk::tiles::TileMap2D::drawInsideWorldRectPointsSelection(edk::rectf32 rect){
    edk::rectui32 newRect = this->calculateDrawPosition(rect);edkEnd();
    this->drawSelection(newRect.origin,edk::size2ui32(newRect.origin.x+newRect.size.width,newRect.origin.y+newRect.size.height));edkEnd();
}
void edk::tiles::TileMap2D::drawIsometricSelectionWithID(edk::uint8 id){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();

        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                edk::GU::guPushName(edk::BinaryConverter::joinBits(id,((this->sizeMap.width * y) + x)+1u,24));edkEnd();
                this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                  ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                  ,0.f,this->scaleMap
                                                  );edkEnd();

                edk::GU::guPopName();edkEnd();
            }
        }

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometricSelectionWithID(edk::vec2ui32 origin,edk::size2ui32 last,edk::uint8 id){
    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();
            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    edk::GU::guPushName(edk::BinaryConverter::joinBits(id,((this->sizeMap.width * y) + x)+1u,24));edkEnd();
                    this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                      ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                      ,0.f,this->scaleMap
                                                      );edkEnd();

                    edk::GU::guPopName();edkEnd();
                }
            }
        }

        //this->treePhysics.print();edkEnd();
        //this->treeStaticPhysics.printf();edkEnd();

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometricSelection(){
    if(this->tileSet){
        edk::vec2f32 positionTemp = this->getPosition();edkEnd();
        //set the transformation
        edk::GU::guPushMatrix();edkEnd();

        for(edk::uint32 y=0u,y2=this->sizeMap.height-1u;y<this->sizeMap.height;y++,y2--){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                edk::GU::guPushName(((this->sizeMap.width * y) + x)+1u);edkEnd();
                this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                  ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                  ,0.f,this->scaleMap
                                                  );edkEnd();
                edk::GU::guPopName();edkEnd();
            }
        }

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometricSelection(edk::vec2ui32 origin,edk::size2ui32 last){

    if(this->tileSet){
        if(last.width>this->sizeMap.width){
            last.width=this->sizeMap.width;edkEnd();
        }
        if(last.height>this->sizeMap.height){
            last.height=this->sizeMap.height;edkEnd();
        }
        if(origin.x < this->sizeMap.width
                &&
                origin.y < this->sizeMap.height
                &&
                origin.x<=last.width
                &&
                origin.y<=last.height
                ){
            edk::vec2f32 positionTemp = this->getPosition();edkEnd();
            //set the transformation
            edk::GU::guPushMatrix();edkEnd();
            //last.height++;edkEnd();
            //last.width++;edkEnd();
            for(edk::uint32 y=origin.y,y2=this->sizeMap.height-origin.y-1u;y<last.height;y++,y2--){
                for(edk::uint32 x=origin.x;x<last.width;x++){
                    //draw the tile
                    edk::GU::guPushName(((this->sizeMap.width * y) + x)+1u);edkEnd();
                    this->tileSet->drawTileSelection( (x*this->scaleMap.width) + positionTemp.x + ((y%2u)*this->scaleMap.width*0.5f)
                                                      ,((y2*this->scaleMap.height)*0.25f) + positionTemp.y
                                                      ,0.f,this->scaleMap
                                                      );edkEnd();
                    edk::GU::guPopName();edkEnd();
                }
            }
        }

        //this->treePhysics.print();edkEnd();
        //this->treeStaticPhysics.printf();edkEnd();

        edk::GU::guPopMatrix();edkEnd();
    }
}
void edk::tiles::TileMap2D::drawIsometricInsideWorldRectSelectionWithID(edk::rectf32 /*rect*/,edk::uint8 /*id*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;edkEnd();
    rect.origin.y /= this->scaleMap.height;edkEnd();
    rect.size /= this->scaleMap;edkEnd();

    rect.origin.y+=0.5;edkEnd();
    rect.origin.x+=0.5;edkEnd();

    edk::vec2f32 first = rect.origin;edkEnd();
    //
    rect.origin.x +=rect.size.width;edkEnd();
    first.y +=rect.size.height;edkEnd();

    //translate the origin
    rect.origin.x -= (this->positionMap.x);edkEnd();
    rect.origin.y -= (this->positionMap.y);edkEnd();
    first.x -= (this->positionMap.x);edkEnd();
    first.y -= (this->positionMap.y);edkEnd();

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;edkEnd();
    first.y= (first.y*-1.f) + this->sizeMap.height;edkEnd();

    //increment the last pointer
    rect.origin+=1.f;edkEnd();

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width){
 rect.origin.x=this->sizeMap.width;edkEnd();
 }
    if(rect.origin.y>this->sizeMap.height){
 rect.origin.y=this->sizeMap.height;edkEnd();
 }
    //filter the first pointer
    if(first.x<0.f){
 first.x=0.f;edkEnd();
 }
    if(first.y<0.f){
 first.y=0.f;edkEnd();
 }

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );edkEnd();
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );edkEnd();

    this->drawIsometricSelectionWithID(origin,size,id);edkEnd();
    */
}
void edk::tiles::TileMap2D::drawIsometricInsideWorldRectSelection(edk::rectf32 /*rect*/){
    /*
    //scale the points
    rect.origin.x /= this->scaleMap.width;edkEnd();
    rect.origin.y /= this->scaleMap.height;edkEnd();
    rect.size /= this->scaleMap;edkEnd();

    rect.origin.y+=0.5;edkEnd();
    rect.origin.x+=0.5;edkEnd();

    edk::vec2f32 first = rect.origin;edkEnd();
    //
    rect.origin.x +=rect.size.width;edkEnd();
    first.y +=rect.size.height;edkEnd();

    //translate the origin
    rect.origin.x -= (this->positionMap.x);edkEnd();
    rect.origin.y -= (this->positionMap.y);edkEnd();
    first.x -= (this->positionMap.x);edkEnd();
    first.y -= (this->positionMap.y);edkEnd();

    //mirror the y
    rect.origin.y= (rect.origin.y*-1.f) + this->sizeMap.height;edkEnd();
    first.y= (first.y*-1.f) + this->sizeMap.height;edkEnd();

    //increment the last pointer
    rect.origin+=1.f;edkEnd();

    //filter the last pointer
    if(rect.origin.x>this->sizeMap.width){
 rect.origin.x=this->sizeMap.width;edkEnd();
 }
    if(rect.origin.y>this->sizeMap.height){
 rect.origin.y=this->sizeMap.height;edkEnd();
 }
    //filter the first pointer
    if(first.x<0.f){
 first.x=0.f;edkEnd();
 }
    if(first.y<0.f){
 first.y=0.f;edkEnd();
 }

    //generate origin only if it was bigger then zero
    edk::vec2ui32 origin = edk::vec2ui32(first.x>0.f?(edk::uint32)first.x:0u,
                                         first.y>0.f?(edk::uint32)first.y:0u
                                                     );edkEnd();
    //generate the size only if it was bigger then zero
    edk::size2ui32 size = edk::size2ui32(rect.origin.x>0.f?(edk::uint32)rect.origin.x:0u,
                                         rect.origin.y>0.f?(edk::uint32)rect.origin.y:0u
                                                           );edkEnd();

    this->drawIsometricSelection(origin,size);edkEnd();
*/
}

//draw the pivo
void edk::tiles::TileMap2D::drawPivo(edk::float32 size,edk::color3f32 color){
    edk::GU::guPushMatrix();edkEnd();
    //add translate
    edk::GU::guTranslate2f32(this->getPosition());edkEnd();
    //add scale
    edk::GU::guScale2f32(edk::size2f32(size,size));edkEnd();

    //lineSize
    edk::GU::guLineWidth(3);edkEnd();

    //set the colors
    edk::GU::guColor3f32(color);edkEnd();
    //draw the lines
    edk::GU::guBegin(GU_LINES);edkEnd();
    //LINE 1
    edk::GU::guVertex2f32(-0.5f,-0.5f);edkEnd();
    edk::GU::guVertex2f32( 0.5f, 0.5f);edkEnd();
    //LINE 2
    edk::GU::guVertex2f32(-0.5f, 0.5f);edkEnd();
    edk::GU::guVertex2f32( 0.5f,-0.5f);edkEnd();
    edk::GU::guEnd();edkEnd();

    //lineSize
    edk::GU::guLineWidth(1);edkEnd();
    edk::GU::guPopMatrix();edkEnd();
}

//print the tileMap ID's
void edk::tiles::TileMap2D::print(){
    if(this->tileSet){
        for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
            for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                //draw the tile
                printf("\n%.2f %.2f [%u] color [%.2f,%.2f,%.2f,%.2f] "
                       ,x + this->positionMap.x
                       ,y + this->positionMap.y
                       ,this->tileMap[y][x]
                       ,this->colorMap[y][x].r
                       ,this->colorMap[y][x].g
                       ,this->colorMap[y][x].b
                       ,this->colorMap[y][x].a
                       );edkEnd();
            }
        }
    }
}

void edk::tiles::TileMap2D::contact2DBegin(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;edkEnd();
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;edkEnd();
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileA = objectA->tile;edkEnd();
            tileContact.positionA = objectA->position;edkEnd();
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;edkEnd();
                tileContact.positionB = objectB->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->contact2DTileBegin(tileContact,contact);edkEnd();
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileB = objectB->tile;edkEnd();
            tileContact.positionB = objectB->position;edkEnd();
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;edkEnd();
                tileContact.positionA = objectA->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->contact2DTileBegin(tileContact,contact);edkEnd();
                }
            }
        }
    }
}
void edk::tiles::TileMap2D::contact2DEnd(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;edkEnd();
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;edkEnd();
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileA = objectA->tile;edkEnd();
            tileContact.positionA = objectA->position;edkEnd();
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;edkEnd();
                tileContact.positionB = objectB->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->contact2DTileEnd(tileContact,contact);edkEnd();
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileB = objectB->tile;edkEnd();
            tileContact.positionB = objectB->position;edkEnd();
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;edkEnd();
                tileContact.positionA = objectA->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->contact2DTileEnd(tileContact,contact);edkEnd();
                }
            }
        }
    }
}
void edk::tiles::TileMap2D::contact2DKeepBegin(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;edkEnd();
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;edkEnd();
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileA = objectA->tile;edkEnd();
            tileContact.positionA = objectA->position;edkEnd();
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;edkEnd();
                tileContact.positionB = objectB->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->contact2DTileKeepBegin(tileContact,contact);edkEnd();
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileB = objectB->tile;edkEnd();
            tileContact.positionB = objectB->position;edkEnd();
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;edkEnd();
                tileContact.positionA = objectA->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->contact2DTileKeepBegin(tileContact,contact);edkEnd();
                }
            }
        }
    }
}
void edk::tiles::TileMap2D::contact2DKeepEnd(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;edkEnd();
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;edkEnd();
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileA = objectA->tile;edkEnd();
            tileContact.positionA = objectA->position;edkEnd();
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;edkEnd();
                tileContact.positionB = objectB->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->contact2DTileKeepEnd(tileContact,contact);edkEnd();
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileB = objectB->tile;edkEnd();
            tileContact.positionB = objectB->position;edkEnd();
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;edkEnd();
                tileContact.positionA = objectA->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->contact2DTileKeepEnd(tileContact,contact);edkEnd();
                }
            }
        }
    }
}
//contact sensors
void edk::tiles::TileMap2D::sensor2DBegin(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;edkEnd();
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;edkEnd();
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileA = objectA->tile;edkEnd();
            tileContact.positionA = objectA->position;edkEnd();
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;edkEnd();
                tileContact.positionB = objectB->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->sensor2DTileBegin(tileContact,contact);edkEnd();
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileB = objectB->tile;edkEnd();
            tileContact.positionB = objectB->position;edkEnd();
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;edkEnd();
                tileContact.positionA = objectA->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->sensor2DTileBegin(tileContact,contact);edkEnd();
                }
            }
        }
    }
}
void edk::tiles::TileMap2D::sensor2DEnd(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;edkEnd();
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;edkEnd();
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileA = objectA->tile;edkEnd();
            tileContact.positionA = objectA->position;edkEnd();
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;edkEnd();
                tileContact.positionB = objectB->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->sensor2DTileEnd(tileContact,contact);edkEnd();
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileB = objectB->tile;edkEnd();
            tileContact.positionB = objectB->position;edkEnd();
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;edkEnd();
                tileContact.positionA = objectA->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->sensor2DTileEnd(tileContact,contact);edkEnd();
                }
            }
        }
    }
}
void edk::tiles::TileMap2D::sensor2DKeeping(edk::physics2D::Contact2D* contact){
    if(contact){
        edk::tiles::TileMap2D::PhysicsTiles* objectA = NULL;edkEnd();
        edk::tiles::TileMap2D::PhysicsTiles* objectB = NULL;edkEnd();
        //fins the objects in the tree
        if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
            //load the objectB
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileA = objectA->tile;edkEnd();
            tileContact.positionA = objectA->position;edkEnd();
            if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
                tileContact.tileB = objectB->tile;edkEnd();
                tileContact.positionB = objectB->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->sensor2DTileKeeping(tileContact,contact);edkEnd();
                }
            }
        }
        else if((objectB = this->treePhysics.getPhysicsTileObject(contact->objectB))){
            //load the objectA
            edk::tiles::tileContact2D tileContact;edkEnd();
            tileContact.tileB = objectB->tile;edkEnd();
            tileContact.positionB = objectB->position;edkEnd();
            if((objectA = this->treePhysics.getPhysicsTileObject(contact->objectA))){
                tileContact.tileA = objectA->tile;edkEnd();
                tileContact.positionA = objectA->position;edkEnd();
            }
            edk::uchar32 size = this->treeCallbacks.size();edkEnd();
            edk::tiles::tileCallback* temp=NULL;edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                temp=this->treeCallbacks.getElementInPosition(i);edkEnd();
                if(temp){
                    temp->sensor2DTileKeeping(tileContact,contact);edkEnd();
                }
            }
        }
    }
}

//add tileDrawCallback
bool edk::tiles::TileMap2D::addDrawCallback(edk::uint32 tileID,edk::tiles::DrawTile2DCallback* callback){
    if(callback && this->tileSet && tileID){
        return this->tileSet->addDrawCallback(tileID,callback);edkEnd();
    }
    return false;
}
bool edk::tiles::TileMap2D::addDrawCallback(edk::vec2ui32 position,edk::tiles::DrawTile2DCallback* callback){
    return this->addDrawCallback(this->getTileID(position),callback);edkEnd();
}
bool edk::tiles::TileMap2D::addDrawCallback(edk::uint32 positionX,edk::uint32 positionY,edk::tiles::DrawTile2DCallback* callback){
    return this->addDrawCallback(this->getTileID(positionX,positionY),callback);edkEnd();
}
bool edk::tiles::TileMap2D::removeDrawCallback(edk::uint32 tileID,edk::tiles::DrawTile2DCallback* callback){
    if(callback && this->tileSet && tileID){
        return this->tileSet->removeDrawCallback(tileID,callback);edkEnd();
    }
    return false;
}
bool edk::tiles::TileMap2D::removeDrawCallback(edk::vec2ui32 position,edk::tiles::DrawTile2DCallback* callback){
    return this->removeDrawCallback(this->getTileID(position),callback);edkEnd();
}
bool edk::tiles::TileMap2D::removeDrawCallback(edk::uint32 positionX,edk::uint32 positionY,edk::tiles::DrawTile2DCallback* callback){
    return this->removeDrawCallback(this->getTileID(positionX,positionY),callback);edkEnd();
}

//XML
bool edk::tiles::TileMap2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tileMap_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::char8* temp;edkEnd();
                        //write size of tileMap
                        temp = edk::String::int64ToStr(this->sizeMap.width);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeMapW",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::int64ToStr(this->sizeMap.height);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeMapH",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        //write the scaleMap
                        temp = edk::String::float32ToStr(this->scaleMap.width);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"scaleMapW",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->scaleMap.height);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"scaleMapH",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        //write the position
                        temp = edk::String::float32ToStr(this->getPositionX());edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"posMapX",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->getPositionY());edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"posMapY",temp);edkEnd();
                            free(temp);edkEnd();
                        }
                        //write the tileMap
                        if(this->tileMap){
                            if(xml->addSelectedNextChild("tileMap")){
                                if(xml->selectChild("tileMap")){
                                    //create a new vector
                                    edk::uint32 size = this->sizeMap.width * this->sizeMap.height;edkEnd();
                                    if(size){
                                        edk::uint32* vec = (edk::uint32*)malloc(sizeof(edk::uint32) * (size));edkEnd();
                                        if(vec){
                                            edk::uint32 count = 0u;edkEnd();
                                            edk::vec2ui32 position;edkEnd();
                                            //copy the mat to the vec
                                            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                                                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                                                    //test if XY is a physics object
                                                    position = edk::vec2ui32(x,y);edkEnd();
                                                    if(this->treePhysics.havePosition(position)){
                                                        vec[count] = this->treePhysics.getIDInPosition(position);edkEnd();
                                                    }
                                                    else{
                                                        vec[count] = this->tileMap[y][x];edkEnd();
                                                    }
                                                    count++;edkEnd();
                                                }
                                            }
                                            //create the string
                                            temp = edk::String::vecUint32toStr(vec,size);edkEnd();
                                            if(temp){
                                                xml->setSelectedString(temp);edkEnd();
                                                free(temp);edkEnd();
                                            }
                                            free(vec);edkEnd();
                                        }
                                    }
                                    xml->selectFather();edkEnd();
                                }
                            }
                        }
                        //write the colorMap
                        if(this->colorMap){
                            if(xml->addSelectedNextChild("colorMap")){
                                if(xml->selectChild("colorMap")){

                                    //create a new vector
                                    edk::uint32 size = this->sizeMap.width * this->sizeMap.height * 4u;edkEnd();
                                    if(size){
                                        edk::float32* vec = (edk::float32*)malloc(sizeof(edk::float32) * (size));edkEnd();
                                        if(vec){
                                            edk::uint32 count = 0u;edkEnd();
                                            //copy the mat to the vec
                                            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                                                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                                                    //test if XY is a physics object
                                                    vec[count+0u] = this->colorMap[y][x].a;edkEnd();
                                                    vec[count+1u] = this->colorMap[y][x].r;edkEnd();
                                                    vec[count+2u] = this->colorMap[y][x].g;edkEnd();
                                                    vec[count+3u] = this->colorMap[y][x].b;edkEnd();
                                                    count+=4u;edkEnd();
                                                }
                                            }
                                            //create the string
                                            temp = edk::String::vecfloat32toStr(vec,size);edkEnd();
                                            if(temp){
                                                xml->setSelectedString(temp);edkEnd();
                                                free(temp);edkEnd();
                                            }
                                            free(vec);edkEnd();
                                        }
                                    }
                                    xml->selectFather();edkEnd();
                                }
                            }
                        }
                        //
                        ret=true;edkEnd();
                        xml->selectFather();edkEnd();
                    }
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::tiles::TileMap2D::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tileMap_",nameID);edkEnd();
            if(name){
                //read the name
                if(xml->selectChild(name)){
                    //read size of tileMap
                    this->sizeMap = edk::size2ui32((edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("sizeMapW")),
                                                   (edk::uint32)edk::String::strToInt64(xml->getSelectedAttributeValueByName("sizeMapH"))
                                                   );edkEnd();
                    this->scaleMap = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleMapW")),
                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("scaleMapH"))
                                                   );edkEnd();
                    //read the tileMap
                    if(xml->selectChild("tileMap")){
                        //create the new tileMap
                        if(this->newTileMap(this->sizeMap.width,this->sizeMap.height)){
                            if(this->tileMap){
                                //create a new vector
                                edk::uint32 size = this->sizeMap.width * this->sizeMap.height;edkEnd();
                                if(size){
                                    //create the vector
                                    edk::uint32* vec = (edk::uint32*)malloc(sizeof(edk::uint32) * (size));edkEnd();
                                    if(vec){
                                        //convert the string
                                        if(edk::String::strToVecUint32(xml->getSelectedString(),vec,size)){
                                            edk::uint32 count = 0u;edkEnd();
                                            //copy the vec to the mat
                                            for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                                                for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                                                    this->tileMap[y][x] = vec[count];edkEnd();
                                                    count++;edkEnd();
                                                }
                                            }
                                        }
                                        free(vec);edkEnd();
                                    }
                                }
                            }
                            xml->selectFather();edkEnd();

                            //read the colorMap
                            if(xml->selectChild("colorMap")){
                                if(this->colorMap){
                                    //create a new vector
                                    edk::uint32 size = this->sizeMap.width * this->sizeMap.height * 4u;edkEnd();
                                    if(size){
                                        //create the vector
                                        edk::float32* vec = (edk::float32*)malloc(sizeof(edk::float32) * (size));edkEnd();
                                        if(vec){
                                            //convert the string
                                            if(edk::String::strToVecfloat32(xml->getSelectedString(),vec,size)){
                                                edk::uint32 count = 0u;edkEnd();
                                                //copy the vec to the mat
                                                for(edk::uint32 y=0u;y<this->sizeMap.height;y++){
                                                    for(edk::uint32 x=0u;x<this->sizeMap.width;x++){
                                                        this->colorMap[y][x].a = vec[count+0u];edkEnd();
                                                        this->colorMap[y][x].r = vec[count+1u];edkEnd();
                                                        this->colorMap[y][x].g = vec[count+2u];edkEnd();
                                                        this->colorMap[y][x].b = vec[count+3u];edkEnd();
                                                        count+=4u;edkEnd();
                                                    }
                                                }
                                            }
                                            free(vec);edkEnd();
                                        }
                                    }
                                }
                                xml->selectFather();edkEnd();
                            }
                        }
                        else{
                            xml->selectFather();edkEnd();
                        }
                    }



                    edk::vec2f32 positionTemp = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("posMapX")),
                                                             edk::String::strToFloat32(xml->getSelectedAttributeValueByName("posMapY"))
                                                             );edkEnd();
                    this->setPosition(positionTemp);edkEnd();

                    ret=true;edkEnd();
                    xml->selectFather();edkEnd();
                }
                free(name);edkEnd();
            }
            free(nameID);edkEnd();
        }
        return ret;
    }
    return false;
}
