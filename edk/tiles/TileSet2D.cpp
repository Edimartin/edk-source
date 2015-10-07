#include "TileSet2D.h"

/*
Library TileSet2D - Save 2D Tiles as a TileSet in EDK Game Engine
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

edk::tiles::TileSet2D::TileSet2D(){
    //set the stack for tiles
    this->tiles.clean(tileStack);
    this->tileSize = edk::size2f32(1,1);
}

edk::tiles::TileSet2D::~TileSet2D(){
    //
    this->deleteTiles();
}

//Delete all tiles
void edk::tiles::TileSet2D::deleteTiles(){
    this->treeAnimated.clean();
    //test if have tiles
    if(this->tiles.size()){
        edk::tiles::Tile2D* temp = NULL;
        for(unsigned int i=0u;i<this->tiles.size();i++){
            if(this->tiles.havePos(i)){
                temp = this->tiles[i];
                if(temp){
                    delete temp;
                    temp=NULL;
                }
            }
        }
        //clean the tileSet
        this->tiles.clean();
    }
}
//delete one tile
bool edk::tiles::TileSet2D::deleteTile(edk::uint32 position){
    if(position){
        position--;
        if(this->tiles.havePos(position)){
            edk::tiles::Tile2D* tile = this->tiles.remove(position);
            if(tile){
                delete tile;
                return true;
            }
        }
    }
    //else return false
    return false;
}
//delete one tile
bool edk::tiles::TileSet2D::deleteTilePosition(edk::uint32 position){
    if(position){
        position--;
        if(this->tiles.havePos(position)){
            edk::uint32 temp = this->tiles.size()-1u;
            //swap the position to be last
            this->tiles.bringPositionTo(position,temp);
            edk::tiles::Tile2D* tile = this->tiles.remove(temp);
            if(tile){
                delete tile;
                return true;
            }
        }
    }
    //else return false
    return false;
}
//test if have the tile
bool edk::tiles::TileSet2D::haveTile(edk::uint32 position){
    if(position){
        position--;
        if(this->tiles.havePos(position)){
            return true;
        }
    }
    //else return false
    return false;
}

//set the size of the tiles
bool edk::tiles::TileSet2D::setSizeOfTiles(edk::size2f32 size){
    if(size.width!=0.f && size.height!=0.f){
        //save the size
        this->tileSize = size;

        for(unsigned int i=0u;i<this->tiles.size();i++){
            if(this->tiles.havePos(i)){
                edk::tiles::Tile2D* temp = this->tiles.get(i);
                if(temp){
                    temp->setRect(0,0,size.width,size.height);
                }
            }
        }

        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setSizeOfTiles(edk::float32 width,edk::float32 height){
    //
    return this->setSizeOfTiles(edk::size2f32(width,height));
}

//return the size of tiles
edk::size2f32 edk::tiles::TileSet2D::getSizeOfTiles(){
    return this->tileSize;
}
//return the tileSize
edk::uint32 edk::tiles::TileSet2D::getTileSize(){
    return this->tiles.size();
}

//load the tiles from an image
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTiles(const char* image,
                                                                              edk::uint32 x,
                                                                              edk::uint32 y,
                                                                              edk::uint32 filter,
                                                                              edk::color4f32 color
                                                                              ){
    //
    return this->loadImageTiles((edk::char8*)image,edk::vec2ui32(x,y),filter,color);
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTiles(const char* image,
                                                                              edk::vec2ui32 frames,
                                                                              edk::uint32 filter,
                                                                              edk::color4f32 color
                                                                              ){
    return this->loadImageTiles((edk::char8*)image,frames,filter,color);
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTiles(edk::char8* image,
                                                                              edk::uint32 x,
                                                                              edk::uint32 y,
                                                                              edk::uint32 filter,
                                                                              edk::color4f32 color
                                                                              ){
    return this->loadImageTiles(image,edk::vec2ui32(x,y),filter,color);
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTiles(edk::char8* image,
                                                                              edk::vec2ui32 frames,
                                                                              edk::uint32 filter,
                                                                              edk::color4f32 color
                                                                              ){
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;

    //test the imageName
    if(image){
        //load the tiles
        edk::uint32 tempX = frames.x;
        edk::uint32 tempY = frames.y;
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTile(image,filter,color);
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTile(image,filter,color);
                }
                else{
                    //else just load the tile
                    position = this->newTile(image,filter,color);
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);
                //set the tile position
                this->setTileFrameUV(position,x,y);
            }
        }
    }

    return ret;
}
//Load the tiles from mamory
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromMemory(const char* name,
                                                                                        edk::uint8* image,
                                                                                        edk::uint32 size,
                                                                                        edk::uint32 x,
                                                                                        edk::uint32 y,
                                                                                        edk::uint32 filter,
                                                                                        edk::color4f32 color
                                                                                        ){
    //
    return this->loadImageTilesFromMemory((edk::char8*) name,image,size,edk::vec2ui32(x,y),filter,color);
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromMemory(const char* name,
                                                                                        edk::uint8* image,
                                                                                        edk::uint32 size,
                                                                                        edk::vec2ui32 frames,
                                                                                        edk::uint32 filter,
                                                                                        edk::color4f32 color
                                                                                        ){
    //
    return this->loadImageTilesFromMemory((edk::char8*) name,image,size,frames,filter,color);
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromMemory(edk::char8* name,
                                                                                        edk::uint8* image,
                                                                                        edk::uint32 size,
                                                                                        edk::uint32 x,
                                                                                        edk::uint32 y,
                                                                                        edk::uint32 filter,
                                                                                        edk::color4f32 color
                                                                                        ){
    //
    return this->loadImageTilesFromMemory(name,image,size,edk::vec2ui32(x,y),filter,color);
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromMemory(edk::char8* name,
                                                                                        edk::uint8* image,
                                                                                        edk::uint32 size,
                                                                                        edk::vec2ui32 frames,
                                                                                        edk::uint32 filter,
                                                                                        edk::color4f32 color
                                                                                        ){
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;

    //test the imageName
    if(image){
        //load the tiles
        edk::uint32 tempX = frames.x;
        edk::uint32 tempY = frames.y;
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTileFromMemory(name,image,size,filter,color);
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTileFromMemory(name,image,size,filter,color);
                }
                else{
                    //else just load the tile
                    position = this->newTileFromMemory(name,image,size,filter,color);
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);
                //set the tile position
                this->setTileFrameUV(position,x,y);
            }
        }
    }

    return ret;
}

//create a new tile
edk::uint32 edk::tiles::TileSet2D::newTile(const char* image,edk::uint32 filter,edk::color4f32 color){
    //
    return this->newTile((edk::char8*) image,filter,color);
}
edk::uint32 edk::tiles::TileSet2D::newTile(edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    if(image){
        //new tile with white color
        edk::uint32 position = this->newTile(color);
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);
                if(temp){
                    //
                    if(temp->loadImage(image,filter)){
                        //return the position
                        return position;
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);
                    }
                    delete temp;
                }
            }
        }
    }
    //else return minus one
    return 0u;
}
edk::uint32 edk::tiles::TileSet2D::newTile(edk::color4f32 color){
    //create the new tile
    edk::tiles::Tile2D* tileTemp = new edk::tiles::Tile2D;
    if(tileTemp){
        //set the size of the tile
        tileTemp->setFrame(0,0,this->tileSize.width,this->tileSize.height);
        //set the color
        tileTemp->setColor(color);
        //save the stackSize
        edk::uint32 size = this->tiles.size();
        //add the tile in the stack
        edk::uint32 position = this->tiles.pushBack(tileTemp);
        if(size<this->tiles.size() || position){
            return position + 1u;
        }
        delete tileTemp;
    }
    //else return -1
    return 0;
}
edk::uint32 edk::tiles::TileSet2D::newTileFromMemory(const char* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    return this->newTileFromMemory((edk::char8*) name,image,size,filter,color);
}
edk::uint32 edk::tiles::TileSet2D::newTileFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    if(name && image){
        //new tile with white color
        edk::uint32 position = this->newTile(color);
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);
                if(temp){
                    //
                    if(temp->loadImageFromMemory(name,image,size,filter)){
                        //return the position
                        return position;
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);
                    }
                    delete temp;
                }
            }
        }
    }
    //else return minus one
    return 0u;
}
//set the tile UVFrames
bool edk::tiles::TileSet2D::setTileFramesUV(edk::uint32 tile,edk::vec2ui32 frames){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->setFramesUV(frames);
            }
        }
        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setTileFramesUV(edk::uint32 tile,edk::uint32 x,edk::uint32 y){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->setFramesUV(x,y);
            }
        }
        return true;
    }
    //else return false
    return false;
}
//use the tile UV frame
bool edk::tiles::TileSet2D::setTileFrameUV(edk::uint32 tile,edk::vec2ui32 frame){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->useFrameUV(frame);
            }
        }
        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setTileFrameUV(edk::uint32 tile,edk::uint32 x,edk::uint32 y){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->useFrameUV(x,y);
            }
        }
        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setTileFrameUVinPosition(edk::uint32 tile,edk::uint32 position){
    if(tile && position){
        tile--;
        position--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->useFrameUVinPosition(position);
            }
        }
        return true;
    }
    //else return false
    return false;
}

//Add a interpolation to the animation
bool edk::tiles::TileSet2D::addFrameInterpolation(edk::uint32 tile,edk::float32 second,edk::float32 frame){
    if(tile && frame>=1.f){
        tile--;
        frame-=1.f;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                this->treeAnimated.add(temp);
                return temp->addFrameInterpolation(second,frame);
            }
        }
    }
    //else return false
    return false;
}
//return the interpolationSize
edk::uint32 edk::tiles::TileSet2D::getInterpolationSize(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->getInterpolationSize();
            }
        }
        return true;
    }
    //else return false
    return false;
}
//clean
bool edk::tiles::TileSet2D::cleanFrames(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                this->treeAnimated.remove(temp);
                temp->cleanFames();
            }
        }
        return true;
    }
    //else return false
    return false;
}

//controls
bool edk::tiles::TileSet2D::playForward(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->playForward();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playForwardIn(edk::uint32 tile,edk::float32 second){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->playForwardIn(second);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playRewind(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->playRewind();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playRewindIn(edk::uint32 tile,edk::float32 second){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->playRewindIn(second);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::pause(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->pause();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::stop(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->stop();
            }
        }
    }
    //else return false
    return false;
}
//set loop
bool edk::tiles::TileSet2D::setLoop(edk::uint32 tile,bool loop){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->setLoop(loop);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::loopOn(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->loopOn();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::loopOff(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->loopOff();
            }
        }
    }
    //else return false
    return false;
}
//get the second
edk::float32 edk::tiles::TileSet2D::getSecond(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->getSecond();
            }
        }
    }
    //else return false
    return 0.f;
}
//return if are playing
bool edk::tiles::TileSet2D::isPlaying(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->isPlaying();
            }
        }
    }
    //else return false
    return false;
}
//animationNames
bool edk::tiles::TileSet2D::addAnimationName(edk::uint32 tile,const char* name, edk::float32 start,edk::float32 end){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->addAnimationName(name,start,end);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::addAnimationName(edk::uint32 tile,edk::char8* name, edk::float32 start,edk::float32 end){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->addAnimationName(name,start,end);
            }
        }
    }
    //else return false
    return false;
}
//test if have the animationName
bool edk::tiles::TileSet2D::haveAnimationName(edk::uint32 tile,const char* name){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->haveAnimationName(name);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::haveAnimationName(edk::uint32 tile,edk::char8* name){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->haveAnimationName(name);
            }
        }
    }
    //else return false
    return false;
}
//Play the animationName
bool edk::tiles::TileSet2D::playNameForward(edk::uint32 tile,const char* name){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->playNameForward(name);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playNameForward(edk::uint32 tile,edk::char8* name){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->playNameForward(name);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playNameRewind(edk::uint32 tile,const char* name){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->playNameRewind(name);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playNameRewind(edk::uint32 tile,edk::char8* name){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->playNameRewind(name);
            }
        }
    }
    //else return false
    return false;
}
//remove the animationName
bool edk::tiles::TileSet2D::removeAnimationName(edk::uint32 tile,const char* name){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->removeAnimationName(name);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::removeAnimationName(edk::uint32 tile,edk::char8* name){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->removeAnimationName(name);
            }
        }
    }
    //else return false
    return false;
}

//Set one interpolation X as a curve
bool edk::tiles::TileSet2D::setCurveX(edk::uint32 tile,edk::uint32 position){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->setCurveX(position);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setNotCurveX(edk::uint32 tile,edk::uint32 position){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->setNotCurveX(position);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::getIsCurveX(edk::uint32 tile,edk::uint32 position){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->getIsCurveX(position);
            }
        }
    }
    //else return false
    return false;
}
//Set the interpolation curve points
bool edk::tiles::TileSet2D::setCurveP1X(edk::uint32 tile,edk::uint32 position,edk::float32 second,edk::float32 x){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->setCurveP1X(position,second,x);
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setCurveP2X(edk::uint32 tile,edk::uint32 position,edk::float32 second,edk::float32 x){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->setCurveP2X(position,second,x);
            }
        }
    }
    //else return false
    return false;
}

//update the animations
bool edk::tiles::TileSet2D::updateAnimations(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->updateAnimation();
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::updateAnimations(){
    edk::uint32 size = this->treeAnimated.size();
    if(size){
        edk::tiles::Tile2D* temp = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->treeAnimated.getElementInPosition(i);
            if(temp){
                temp->updateAnimation();
            }
        }
        return true;
    }
    return false;
}

//create a new object physics
bool edk::tiles::TileSet2D::setTilePhysics(edk::uint32 tile,edk::physics::bodyType type){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->setPhysics(type);
            }
        }
    }
    //else return false
    return false;
}
//add a polygon to the physics Object
bool edk::tiles::TileSet2D::addTilePhysicsPolygon(edk::uint32 tile,edk::shape::Polygon2D poly){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                poly.cantDeletePolygon();
                return temp->addPhysicsPolygon(poly);
            }
        }
    }
    //else return false
    poly.cantDeletePolygon();
    return false;
}
bool edk::tiles::TileSet2D::cleanTilePhysicsPolygons(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->cleanPhysicsPolygons();
            }
        }
    }
    //else return false
    return false;
}
//get the tilePhysicsMesh
edk::physics2D::PhysicsMesh2D* edk::tiles::TileSet2D::getTilePhysicsMeshPointer(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->getPhysicsMeshPointer();
            }
        }
    }
    //else return false
    return false;
}
//return the tileMesh
edk::shape::Mesh2D* edk::tiles::TileSet2D::getTileMeshPointer(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->getMeshPointer();
            }
        }
    }
    //else return false
    return false;
}

//delete the objectPhysics
bool edk::tiles::TileSet2D::deleteTilePhysics(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->deletePhysics();
                return true;
            }
        }
    }
    //else return false
    return false;
}
//return the physicsObject
edk::physics2D::PhysicObject2D* edk::tiles::TileSet2D::getTilePhysicsObject(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                return temp->getPhysicsObject();
            }
        }
    }
    //else return false
    return NULL;
}

//Draw the tile from the tileSet
bool edk::tiles::TileSet2D::drawTile(edk::uint32 tile,edk::vec2f32 position,edk::float32 angle,edk::size2f32 size,edk::color4f32 color){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->setColor(color);
                temp->setPosition(position.x * temp->getWidth(),position.y * temp->getHeight());
                temp->draw(angle,size);
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::drawTile(edk::uint32 tile,edk::float32 positionX, edk::float32 positionY,edk::float32 angle,edk::size2f32 size,edk::color4f32 color){
    //
    return this->drawTile(tile,edk::vec2f32( positionX,positionY),angle,size,color);
}
void edk::tiles::TileSet2D::drawTileWire(edk::vec2f32 position,edk::float32 angle,edk::size2f32 size,edk::color4f32 color){
    this->tileTemp.setColor(color);
    this->tileTemp.setPosition(position.x * this->tileTemp.getWidth(),position.y * this->tileTemp.getHeight());
    this->tileTemp.drawWire(angle,size);
}
void edk::tiles::TileSet2D::drawTileWire(edk::float32 positionX, edk::float32 positionY,edk::float32 angle,edk::size2f32 size,edk::color4f32 color){
    return this->drawTileWire(edk::vec2f32( positionX,positionY),angle,size,color);
}
void edk::tiles::TileSet2D::drawTileSelection(edk::vec2f32 position,edk::float32 angle,edk::size2f32 size){
    this->tileTemp.setPosition(position.x * this->tileTemp.getWidth(),position.y * this->tileTemp.getHeight());
    this->tileTemp.drawSelection(angle,size);
}
void edk::tiles::TileSet2D::drawTileSelection(edk::float32 positionX, edk::float32 positionY,edk::float32 angle,edk::size2f32 size){
    //
    return this->drawTileSelection(edk::vec2f32( positionX,positionY),angle,size);
}
bool edk::tiles::TileSet2D::drawTileInWorld(edk::uint32 tile,edk::vec2f32 position,edk::float32 angle,edk::size2f32 size,edk::color4f32 color){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->setPosition(position.x,position.y);
                temp->setColor(color);
                temp->draw(angle,size);
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::drawTileInWorld(edk::uint32 tile,edk::float32 positionX, edk::float32 positionY,edk::float32 angle,edk::size2f32 size,edk::color4f32 color){
    //
    return this->drawTileInWorld(tile,edk::vec2f32( positionX,positionY),angle,size,color);
}
void edk::tiles::TileSet2D::drawTileSelectionInWorld(edk::vec2f32 position,edk::float32 angle,edk::size2f32 size){
    this->tileTemp.setPosition(position.x,position.y);
    this->tileTemp.drawSelection(angle,size);
}
void edk::tiles::TileSet2D::drawTileSelectionInWorld(edk::float32 positionX, edk::float32 positionY,edk::float32 angle,edk::size2f32 size){
    //
    this->drawTileSelectionInWorld(edk::vec2f32( positionX,positionY),angle,size);
}

bool edk::tiles::TileSet2D::drawTilePhysics(edk::uint32 tile,edk::vec2f32 position,edk::float32 angle,edk::size2f32 size,edk::color4f32 color){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->setColor(color);
                temp->setPosition(position.x * temp->getWidth(),position.y * temp->getHeight());
                temp->drawPhysic(angle,size);
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::drawTilePhysics(edk::uint32 tile,edk::float32 positionX, edk::float32 positionY,edk::float32 angle,edk::size2f32 size,edk::color4f32 color){
    return this->drawTilePhysics(tile,edk::vec2f32( positionX,positionY),angle,size,color);
}
bool edk::tiles::TileSet2D::drawTilePhysicsInWorld(edk::uint32 tile,edk::vec2f32 position,edk::float32 angle,edk::size2f32 size,edk::color4f32 color){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                temp->setPosition(position.x,position.y);
                temp->setColor(color);
                temp->drawPhysic(angle,size);
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::drawTilePhysicsInWorld(edk::uint32 tile,edk::float32 positionX, edk::float32 positionY,edk::float32 angle,edk::size2f32 size,edk::color4f32 color){
    //
    return this->drawTilePhysicsInWorld(tile,edk::vec2f32( positionX,positionY),angle,size,color);
}
bool edk::tiles::TileSet2D::printTile(edk::uint32 tile){
    if(tile){
        tile--;
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);
            if(temp){
                printf("\nPosition %.2f %.2f size %.2f %.2f"
                       ,temp->getPositionX()
                       ,temp->getPositionY()
                       ,temp->getWidth()
                       ,temp->getHeight()
                       );
                return true;
            }
        }
    }
    //else return false
    return false;
}

//XML
bool edk::tiles::TileSet2D::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tileSet_",nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::char8* temp;
                        //write tileSize
                        temp = edk::String::float32ToStr(this->tileSize.width);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeW",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->tileSize.height);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeH",temp);
                            delete[] temp;
                        }
                        //write the position
                        temp = edk::String::float32ToStr(this->tilesPosition.x);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"posX",temp);
                            delete[] temp;
                        }
                        temp = edk::String::float32ToStr(this->tilesPosition.y);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"posY",temp);
                            delete[] temp;
                        }
                        //write the tiles
                        edk::uint32 size = this->tiles.size();
                        //write size
                        temp = edk::String::int64ToStr(size);
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"tileSize",temp);
                            delete[] temp;
                        }
                        edk::tiles::Tile2D* tileTemp;
                        for(edk::uint32 i=0u;i<=size;i++){
                            if(this->tiles.havePos(i)){
                                tileTemp = tiles[i];
                                if(tileTemp){
                                    //write the tile
                                    tileTemp->writeToXML(xml,i+1u);
                                }
                            }
                        }
                        edk::char8* nameTemp;
                        edk::char8* iTemp;
                        //write the animatedTiles
                        for(edk::uint32 i=0u;i<size;i++){
                            tileTemp = tiles[i];
                            if(tileTemp){
                                //test if have the tile in animatedTree
                                if(this->treeAnimated.haveElement(tileTemp)){
                                    //set the tile as animated
                                    iTemp = edk::String::int64ToStr(i+1u);
                                    if(iTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"anim_",iTemp);
                                        if(nameTemp){
                                            //add the animated
                                            if(xml->addSelectedNextChild(nameTemp)){
                                                if(xml->selectChild(nameTemp)){
                                                    xml->selectFather();
                                                }
                                            }
                                            delete[] nameTemp;
                                        }
                                        delete[] iTemp;
                                    }
                                }
                            }
                        }
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
bool edk::tiles::TileSet2D::readFromXML(edk::XML* xml,edk::uint32 id){
    this->treeRemoveXML.clean();
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tileSet_",nameID);
            if(name){
                //select the name
                if(xml->selectChild(name)){
                    this->deleteTiles();
                    ret=true;
                    //read the size
                    this->tileSize = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH"))
                                                   );
                    //read the position
                    this->tilesPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("posX")),
                                                       edk::String::strToFloat32(xml->getSelectedAttributeValueByName("posY"))
                                                       );

                    //read tiles
                    edk::tiles::Tile2D* tileTemp;
                    //                    edk::int32 i = 0u;
                    edk::char8* nameTemp;
                    edk::char8* iTemp;
                    edk::uint32 size = edk::String::strToInt64(xml->getSelectedAttributeValueByName("tileSize"));
                    edk::uint32 sizeStack;
                    for(edk::uint32 i=1u;i<=size;i++){
                        tileTemp = new edk::tiles::Tile2D;
                        if(tileTemp){
                            //add the tile
                            sizeStack = this->tiles.size();
                            this->tiles.pushBack(tileTemp);
                            if(sizeStack<this->tiles.size()){
                                //load the tile
                                if(tileTemp->readFromXML(xml,i)){
                                    //test if the tile is animated
                                    iTemp = edk::String::int64ToStr(i);
                                    if(iTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"anim_",iTemp);
                                        if(nameTemp){
                                            //test the animated
                                            if(xml->selectChild(nameTemp)){
                                                //add the tile to the animatedTree
                                                this->treeAnimated.add(tileTemp);
                                                xml->selectFather();
                                            }
                                            delete[] nameTemp;
                                        }
                                        delete[] iTemp;
                                    }
                                }
                                else{
                                    //else remove the tile after
                                    this->treeRemoveXML.add(i);
                                    //
                                }
                            }
                            else{
                                //
                                delete tileTemp;
                                ret=false;
                                break;
                            }
                        }
                    }
                    //remove the tiles
                    size = this->treeRemoveXML.size();
                    for(edk::uint32 i=0u;i<size;i++){
                        this->deleteTile(this->treeRemoveXML.getElementInPosition(i));
                    }
                    xml->selectFather();
                }
                delete[] name;
            }
            delete[] nameID;
        }
        this->treeRemoveXML.clean();
        return ret;
    }
    return false;
}
