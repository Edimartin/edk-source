#include "TileSet2D.h"

/*
Library TileSet2D - Save 2D Tiles as a TileSet in EDK Game Engine
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

edk::tiles::TileSet2D::TileSet2D(){
    //set the stack for tiles
    this->tiles.clean(tileStack);edkEnd();
    this->tileSize = edk::size2f32(1,1);edkEnd();
}

edk::tiles::TileSet2D::~TileSet2D(){
    //
    this->deleteTiles();edkEnd();
}

//Delete all tiles
void edk::tiles::TileSet2D::deleteTiles(){
    this->treeAnimated.clean();edkEnd();
    //test if have tiles
    if(this->tiles.size()){
        edk::tiles::Tile2D* temp = NULL;edkEnd();
        for(edk::uint32 i=0u;i<this->tiles.size();i++){
            if(this->tiles.havePos(i)){
                temp = this->tiles[i];edkEnd();
                if(temp){
                    switch(temp->getType()){
                    case edk::tiles::tile2DTypeIsometric:
                        delete (edk::tiles::TileIsometric2D*)temp;edkEnd();
                        break;
                    case edk::tiles::tile2DTypeIsometricFlat:
                        delete (edk::tiles::TileIsometricFlat2D*)temp;edkEnd();
                        break;
                    case edk::tiles::tile2DTypeSize:
                    case edk::tiles::tile2DTypeNormal:
                    default:
                        delete temp;edkEnd();
                        break;
                    }
                    temp=NULL;edkEnd();
                }
            }
        }
        //clean the tileSet
        this->tiles.clean();edkEnd();
    }
}
//delete one tile
bool edk::tiles::TileSet2D::deleteTile(edk::uint32 position){
    if(position){
        position--;edkEnd();
        if(this->tiles.havePos(position)){
            edk::tiles::Tile2D* tile = this->tiles.remove(position);edkEnd();
            if(tile){
                delete tile;edkEnd();
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
        position--;edkEnd();
        if(this->tiles.havePos(position)){
            edk::uint32 temp = this->tiles.size()-1u;edkEnd();
            //swap the position to be last
            this->tiles.bringPositionTo(position,temp);edkEnd();
            edk::tiles::Tile2D* tile = this->tiles.remove(temp);edkEnd();
            if(tile){
                delete tile;edkEnd();
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
        position--;edkEnd();
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
        this->tileSize = size;edkEnd();

        for(edk::uint32 i=0u;i<this->tiles.size();i++){
            if(this->tiles.havePos(i)){
                edk::tiles::Tile2D* temp = this->tiles.get(i);edkEnd();
                if(temp){
                    temp->setRect(0,0,size.width,size.height);edkEnd();
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
    return this->setSizeOfTiles(edk::size2f32(width,height));edkEnd();
}

//return the size of tiles
edk::size2f32 edk::tiles::TileSet2D::getSizeOfTiles(){
    return this->tileSize;edkEnd();
}
//return the tileSize
edk::uint32 edk::tiles::TileSet2D::getTileSize(){
    return this->tiles.size();edkEnd();
}

//load the tiles from an image
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTiles(const edk::char8* image,
                                                                              edk::uint32 x,
                                                                              edk::uint32 y,
                                                                              edk::uint32 filter,
                                                                              edk::color4f32 color
                                                                              ){
    //
    return this->loadImageTiles((edk::char8*)image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTiles(const edk::char8* image,
                                                                              edk::vec2ui32 frames,
                                                                              edk::uint32 filter,
                                                                              edk::color4f32 color
                                                                              ){
    return this->loadImageTiles((edk::char8*)image,frames,filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTiles(edk::char8* image,
                                                                              edk::uint32 x,
                                                                              edk::uint32 y,
                                                                              edk::uint32 filter,
                                                                              edk::color4f32 color
                                                                              ){
    return this->loadImageTiles(image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTiles(edk::char8* image,
                                                                              edk::vec2ui32 frames,
                                                                              edk::uint32 filter,
                                                                              edk::color4f32 color
                                                                              ){
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;edkEnd();

    //test the imageName
    if(image){
        //load the tiles
        edk::uint32 tempX = frames.x;edkEnd();
        edk::uint32 tempY = frames.y;edkEnd();
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTile(image,filter,color);edkEnd();
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTile(image,filter,color);edkEnd();
                }
                else{
                    //else just load the tile
                    position = this->newTile(image,filter,color);edkEnd();
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);edkEnd();
                //set the tile position
                this->setTileFrameUV(position,x,y);edkEnd();
            }
        }
    }

    return ret;
}
//Load the tiles from mamory
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromMemory(const edk::char8* name,
                                                                                        edk::uint8* image,
                                                                                        edk::uint32 size,
                                                                                        edk::uint32 x,
                                                                                        edk::uint32 y,
                                                                                        edk::uint32 filter,
                                                                                        edk::color4f32 color
                                                                                        ){
    //
    return this->loadImageTilesFromMemory((edk::char8*) name,image,size,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromMemory(const edk::char8* name,
                                                                                        edk::uint8* image,
                                                                                        edk::uint32 size,
                                                                                        edk::vec2ui32 frames,
                                                                                        edk::uint32 filter,
                                                                                        edk::color4f32 color
                                                                                        ){
    //
    return this->loadImageTilesFromMemory((edk::char8*) name,image,size,frames,filter,color);edkEnd();
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
    return this->loadImageTilesFromMemory(name,image,size,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromMemory(edk::char8* name,
                                                                                        edk::uint8* image,
                                                                                        edk::uint32 size,
                                                                                        edk::vec2ui32 frames,
                                                                                        edk::uint32 filter,
                                                                                        edk::color4f32 color
                                                                                        ){
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;edkEnd();

    //test the imageName
    if(image){
        //load the tiles
        edk::uint32 tempX = frames.x;edkEnd();
        edk::uint32 tempY = frames.y;edkEnd();
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTileFromMemory(name,image,size,filter,color);edkEnd();
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTileFromMemory(name,image,size,filter,color);edkEnd();
                }
                else{
                    //else just load the tile
                    position = this->newTileFromMemory(name,image,size,filter,color);edkEnd();
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);edkEnd();
                //set the tile position
                this->setTileFrameUV(position,x,y);edkEnd();
            }
        }
    }

    return ret;
}
//load the tiles from pack
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromPack(edk::pack::FilePackage* pack,
                                                                                      const edk::char8* image,
                                                                                      edk::uint32 x,
                                                                                      edk::uint32 y,
                                                                                      edk::uint32 filter,
                                                                                      edk::color4f32 color
        ){
    //
    return this->loadImageTilesFromPack(pack,(edk::char8*)image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromPack(edk::pack::FilePackage* pack,
                                                                                      const edk::char8* image,
                                                                                      edk::vec2ui32 frames,
                                                                                      edk::uint32 filter,
                                                                                      edk::color4f32 color
        ){
    //
    return this->loadImageTilesFromPack(pack,(edk::char8*)image,frames,filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromPack(edk::pack::FilePackage* pack,
                                                                                      edk::char8* image,
                                                                                      edk::uint32 x,
                                                                                      edk::uint32 y,
                                                                                      edk::uint32 filter,
                                                                                      edk::color4f32 color
        ){
    //
    return this->loadImageTilesFromPack(pack,image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesFromPack(edk::pack::FilePackage* pack,
                                                                                      edk::char8* image,
                                                                                      edk::vec2ui32 frames,
                                                                                      edk::uint32 filter,
                                                                                      edk::color4f32 color
        ){
    //
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;edkEnd();

    //test the imageName
    if(image && pack){
        //load the tiles
        edk::uint32 tempX = frames.x;edkEnd();
        edk::uint32 tempY = frames.y;edkEnd();
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTileFromPack(pack,image,filter,color);edkEnd();
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTileFromPack(pack,image,filter,color);edkEnd();
                }
                else{
                    //else just load the tile
                    position = this->newTileFromPack(pack,image,filter,color);edkEnd();
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);edkEnd();
                //set the tile position
                this->setTileFrameUV(position,x,y);edkEnd();
            }
        }
    }

    return ret;
}

//load the tiles from an image
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometric(const edk::char8* image,
                                                                                       edk::uint32 x,
                                                                                       edk::uint32 y,
                                                                                       edk::uint32 filter,
                                                                                       edk::color4f32 color
                                                                                       ){
    //
    return this->loadImageTilesIsometric((edk::char8*)image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometric(const edk::char8* image,
                                                                                       edk::vec2ui32 frames,
                                                                                       edk::uint32 filter,
                                                                                       edk::color4f32 color
                                                                                       ){
    return this->loadImageTilesIsometric((edk::char8*)image,frames,filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometric(edk::char8* image,
                                                                                       edk::uint32 x,
                                                                                       edk::uint32 y,
                                                                                       edk::uint32 filter,
                                                                                       edk::color4f32 color
                                                                                       ){
    return this->loadImageTilesIsometric(image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometric(edk::char8* image,
                                                                                       edk::vec2ui32 frames,
                                                                                       edk::uint32 filter,
                                                                                       edk::color4f32 color
                                                                                       ){
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;edkEnd();

    //test the imageName
    if(image){
        //load the tiles
        edk::uint32 tempX = frames.x;edkEnd();
        edk::uint32 tempY = frames.y;edkEnd();
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTileIsometric(image,filter,color);edkEnd();
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTileIsometric(image,filter,color);edkEnd();
                }
                else{
                    //else just load the tile
                    position = this->newTileIsometric(image,filter,color);edkEnd();
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);edkEnd();
                //set the tile position
                this->setTileFrameUV(position,x,y);edkEnd();
            }
        }
    }

    return ret;
}
//Load the tiles from mamory
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFromMemory(const edk::char8* name,
                                                                                                 edk::uint8* image,
                                                                                                 edk::uint32 size,
                                                                                                 edk::uint32 x,
                                                                                                 edk::uint32 y,
                                                                                                 edk::uint32 filter,
                                                                                                 edk::color4f32 color
                                                                                                 ){
    //
    return this->loadImageTilesIsometricFromMemory((edk::char8*) name,image,size,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFromMemory(const edk::char8* name,
                                                                                                 edk::uint8* image,
                                                                                                 edk::uint32 size,
                                                                                                 edk::vec2ui32 frames,
                                                                                                 edk::uint32 filter,
                                                                                                 edk::color4f32 color
                                                                                                 ){
    //
    return this->loadImageTilesIsometricFromMemory((edk::char8*) name,image,size,frames,filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFromMemory(edk::char8* name,
                                                                                                 edk::uint8* image,
                                                                                                 edk::uint32 size,
                                                                                                 edk::uint32 x,
                                                                                                 edk::uint32 y,
                                                                                                 edk::uint32 filter,
                                                                                                 edk::color4f32 color
                                                                                                 ){
    //
    return this->loadImageTilesIsometricFromMemory(name,image,size,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFromMemory(edk::char8* name,
                                                                                                 edk::uint8* image,
                                                                                                 edk::uint32 size,
                                                                                                 edk::vec2ui32 frames,
                                                                                                 edk::uint32 filter,
                                                                                                 edk::color4f32 color
                                                                                                 ){
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;edkEnd();

    //test the imageName
    if(image){
        //load the tiles
        edk::uint32 tempX = frames.x;edkEnd();
        edk::uint32 tempY = frames.y;edkEnd();
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTileIsometricFromMemory(name,image,size,filter,color);edkEnd();
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTileIsometricFromMemory(name,image,size,filter,color);edkEnd();
                }
                else{
                    //else just load the tile
                    position = this->newTileIsometricFromMemory(name,image,size,filter,color);edkEnd();
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);edkEnd();
                //set the tile position
                this->setTileFrameUV(position,x,y);edkEnd();
            }
        }
    }

    return ret;
}
//load the tiles from pack
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFromPack(edk::pack::FilePackage* pack,
                                                                                               const edk::char8* image,
                                                                                               edk::uint32 x,
                                                                                               edk::uint32 y,
                                                                                               edk::uint32 filter,
                                                                                               edk::color4f32 color
        ){
    return this->loadImageTilesIsometricFromPack(pack,(edk::char8*)image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFromPack(edk::pack::FilePackage* pack,
                                                                                               const edk::char8* image,
                                                                                               edk::vec2ui32 frames,
                                                                                               edk::uint32 filter,
                                                                                               edk::color4f32 color
        ){
    return this->loadImageTilesIsometricFromPack(pack,(edk::char8*)image,frames,filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFromPack(edk::pack::FilePackage* pack,
                                                                                               edk::char8* image,
                                                                                               edk::uint32 x,
                                                                                               edk::uint32 y,
                                                                                               edk::uint32 filter,
                                                                                               edk::color4f32 color
        ){
    return this->loadImageTilesIsometricFromPack(pack,image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFromPack(edk::pack::FilePackage* pack,
                                                                                               edk::char8* image,
                                                                                               edk::vec2ui32 frames,
                                                                                               edk::uint32 filter,
                                                                                               edk::color4f32 color
        ){
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;edkEnd();

    //test the imageName
    if(image && pack){
        //load the tiles
        edk::uint32 tempX = frames.x;edkEnd();
        edk::uint32 tempY = frames.y;edkEnd();
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTileIsometricFromPack(pack,image,filter,color);edkEnd();
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTileIsometricFromPack(pack,image,filter,color);edkEnd();
                }
                else{
                    //else just load the tile
                    position = this->newTileIsometricFromPack(pack,image,filter,color);edkEnd();
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);edkEnd();
                //set the tile position
                this->setTileFrameUV(position,x,y);edkEnd();
            }
        }
    }

    return ret;
}

//load the tiles from an image
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlat(const edk::char8* image,
                                                                                           edk::uint32 x,
                                                                                           edk::uint32 y,
                                                                                           edk::uint32 filter,
                                                                                           edk::color4f32 color
                                                                                           ){
    //
    return this->loadImageTilesIsometricFlat((edk::char8*)image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlat(const edk::char8* image,
                                                                                           edk::vec2ui32 frames,
                                                                                           edk::uint32 filter,
                                                                                           edk::color4f32 color
                                                                                           ){
    return this->loadImageTilesIsometricFlat((edk::char8*)image,frames,filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlat(edk::char8* image,
                                                                                           edk::uint32 x,
                                                                                           edk::uint32 y,
                                                                                           edk::uint32 filter,
                                                                                           edk::color4f32 color
                                                                                           ){
    return this->loadImageTilesIsometricFlat(image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlat(edk::char8* image,
                                                                                           edk::vec2ui32 frames,
                                                                                           edk::uint32 filter,
                                                                                           edk::color4f32 color
                                                                                           ){
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;edkEnd();

    //test the imageName
    if(image){
        //load the tiles
        edk::uint32 tempX = frames.x;edkEnd();
        edk::uint32 tempY = frames.y;edkEnd();
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTileIsometricFlat(image,filter,color);edkEnd();
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTileIsometricFlat(image,filter,color);edkEnd();
                }
                else{
                    //else just load the tile
                    position = this->newTileIsometricFlat(image,filter,color);edkEnd();
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);edkEnd();
                //set the tile position
                this->setTileFrameUV(position,x,y);edkEnd();
            }
        }
    }

    return ret;
}
//Load the tiles from mamory
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlatFromMemory(const edk::char8* name,
                                                                                                     edk::uint8* image,
                                                                                                     edk::uint32 size,
                                                                                                     edk::uint32 x,
                                                                                                     edk::uint32 y,
                                                                                                     edk::uint32 filter,
                                                                                                     edk::color4f32 color
                                                                                                     ){
    //
    return this->loadImageTilesIsometricFlatFromMemory((edk::char8*) name,image,size,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlatFromMemory(const edk::char8* name,
                                                                                                     edk::uint8* image,
                                                                                                     edk::uint32 size,
                                                                                                     edk::vec2ui32 frames,
                                                                                                     edk::uint32 filter,
                                                                                                     edk::color4f32 color
                                                                                                     ){
    //
    return this->loadImageTilesIsometricFlatFromMemory((edk::char8*) name,image,size,frames,filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlatFromMemory(edk::char8* name,
                                                                                                     edk::uint8* image,
                                                                                                     edk::uint32 size,
                                                                                                     edk::uint32 x,
                                                                                                     edk::uint32 y,
                                                                                                     edk::uint32 filter,
                                                                                                     edk::color4f32 color
                                                                                                     ){
    //
    return this->loadImageTilesIsometricFlatFromMemory(name,image,size,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlatFromMemory(edk::char8* name,
                                                                                                     edk::uint8* image,
                                                                                                     edk::uint32 size,
                                                                                                     edk::vec2ui32 frames,
                                                                                                     edk::uint32 filter,
                                                                                                     edk::color4f32 color
                                                                                                     ){
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;edkEnd();

    //test the imageName
    if(image){
        //load the tiles
        edk::uint32 tempX = frames.x;edkEnd();
        edk::uint32 tempY = frames.y;edkEnd();
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTileIsometricFlatFromMemory(name,image,size,filter,color);edkEnd();
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTileIsometricFlatFromMemory(name,image,size,filter,color);edkEnd();
                }
                else{
                    //else just load the tile
                    position = this->newTileIsometricFlatFromMemory(name,image,size,filter,color);edkEnd();
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);edkEnd();
                //set the tile position
                this->setTileFrameUV(position,x,y);edkEnd();
            }
        }
    }

    return ret;
}

//load the tiles from pack
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlatFromPack(edk::pack::FilePackage* pack,
                                                                            const edk::char8* image,
                                                                            edk::uint32 x,
                                                                            edk::uint32 y,
                                                                            edk::uint32 filter,
                                                                            edk::color4f32 color
        ){
    return this->loadImageTilesIsometricFlatFromPack(pack,(edk::char8*)image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlatFromPack(edk::pack::FilePackage* pack,
                                                                            const edk::char8* image,
                                                                            edk::vec2ui32 frames,
                                                                            edk::uint32 filter,
                                                                            edk::color4f32 color
        ){
    return this->loadImageTilesIsometricFlatFromPack(pack,(edk::char8*)image,frames,filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlatFromPack(edk::pack::FilePackage* pack,
                                                                            edk::char8* image,
                                                                            edk::uint32 x,
                                                                            edk::uint32 y,
                                                                            edk::uint32 filter,
                                                                            edk::color4f32 color
        ){
    return this->loadImageTilesIsometricFlatFromPack(pack,image,edk::vec2ui32(x,y),filter,color);edkEnd();
}
edk::tiles::TileSet2D::Tile2Positions2D edk::tiles::TileSet2D::loadImageTilesIsometricFlatFromPack(edk::pack::FilePackage* pack,
                                                                            edk::char8* image,
                                                                            edk::vec2ui32 frames,
                                                                            edk::uint32 filter,
                                                                            edk::color4f32 color
        ){
    //
    edk::tiles::TileSet2D::Tile2Positions2D ret;edkEnd();

    //test the imageName
    if(image && pack){
        //load the tiles
        edk::uint32 tempX = frames.x;edkEnd();
        edk::uint32 tempY = frames.y;edkEnd();
        //save the tile position
        edk::uint32 position=0u;
        for(edk::uint32 y=0u;y<tempY;y++){
            for(edk::uint32 x=0u;x<tempX;x++){
                //test if its the first
                if(!x && !y){
                    //load the first tile and set the ret
                    position = ret.first = this->newTileIsometricFlatFromPack(pack,image,filter,color);edkEnd();
                }
                //test if its the last
                else if(x==tempX-1u && y==tempY-1u){
                    //load the first tile and set the ret
                    position = ret.last = this->newTileIsometricFlatFromPack(pack,image,filter,color);edkEnd();
                }
                else{
                    //else just load the tile
                    position = this->newTileIsometricFlatFromPack(pack,image,filter,color);edkEnd();
                }
                //set the tile frames
                this->setTileFramesUV(position,tempX,tempY);edkEnd();
                //set the tile position
                this->setTileFrameUV(position,x,y);edkEnd();
            }
        }
    }

    return ret;
}

//create a new tile
edk::uint32 edk::tiles::TileSet2D::newTile(const edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    //
    return this->newTile((edk::char8*) image,filter,color);edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTile(edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    if(image){
        //new tile with white color
        edk::uint32 position = this->newTile(color);edkEnd();
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);edkEnd();
                if(temp){
                    //
                    if(temp->loadImage(image,filter)){
                        //return the position
                        return position;edkEnd();
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
        }
    }
    //else return minus one
    return 0u;edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTile(edk::color4f32 color){
    //create the new tile
    edk::tiles::Tile2D* tileTemp = new edk::tiles::Tile2D;edkEnd();
    if(tileTemp){
        //set the size of the tile
        tileTemp->setFrame(0,0,this->tileSize.width,this->tileSize.height);edkEnd();
        //set the color
        tileTemp->setColor(color);edkEnd();
        //save the stackSize
        edk::uint32 size = this->tiles.size();edkEnd();
        //add the tile in the stack
        edk::uint32 position = this->tiles.pushBack(tileTemp);edkEnd();
        if(size<this->tiles.size() || position){
            return position + 1u;edkEnd();
        }
        delete tileTemp;edkEnd();
    }
    //else return -1
    return 0;
}
edk::uint32 edk::tiles::TileSet2D::newTileFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    return this->newTileFromMemory((edk::char8*) name,image,size,filter,color);edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    if(name && image){
        //new tile with white color
        edk::uint32 position = this->newTile(color);edkEnd();
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);edkEnd();
                if(temp){
                    //
                    if(temp->loadImageFromMemory(name,image,size,filter)){
                        //return the position
                        return position;edkEnd();
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
        }
    }
    //else return minus one
    return 0u;edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileFromPack(edk::pack::FilePackage* pack,const edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    return this->newTileFromPack(pack,(edk::char8*) image,filter,color);edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileFromPack(edk::pack::FilePackage* pack,edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    if(image && pack){
        //new tile with white color
        edk::uint32 position = this->newTile(color);edkEnd();
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);edkEnd();
                if(temp){
                    //
                    if(temp->loadImageFromPack(pack,image,filter)){
                        //return the position
                        return position;edkEnd();
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
        }
    }
    //else return minus one
    return 0u;edkEnd();
}
//create a new Isometric tile
edk::uint32 edk::tiles::TileSet2D::newTileIsometric(const edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    //
    return this->newTileIsometric((edk::char8*) image,filter,color);edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometric(edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    if(image){
        //new tile with white color
        edk::uint32 position = this->newTileIsometric(color);edkEnd();
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);edkEnd();
                if(temp){
                    //
                    if(temp->loadImage(image,filter)){
                        //return the position
                        return position;edkEnd();
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
        }
    }
    //else return minus one
    return 0u;edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometric(edk::color4f32 color){
    //create the new tile
    edk::tiles::TileIsometric2D* tileTemp = new edk::tiles::TileIsometric2D;edkEnd();
    if(tileTemp){
        //set the size of the tile
        tileTemp->setFrame(0,0,this->tileSize.width,this->tileSize.height);edkEnd();
        //set the color
        tileTemp->setColor(color);edkEnd();
        //save the stackSize
        edk::uint32 size = this->tiles.size();edkEnd();
        //add the tile in the stack
        edk::uint32 position = this->tiles.pushBack(tileTemp);edkEnd();
        if(size<this->tiles.size() || position){
            return position + 1u;edkEnd();
        }
        delete tileTemp;edkEnd();
    }
    //else return -1
    return 0;
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    return this->newTileIsometricFromMemory((edk::char8*) name,image,size,filter,color);edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    if(name && image){
        //new tile with white color
        edk::uint32 position = this->newTileIsometric(color);edkEnd();
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);edkEnd();
                if(temp){
                    //
                    if(temp->loadImageFromMemory(name,image,size,filter)){
                        //return the position
                        return position;edkEnd();
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
        }
    }
    //else return minus one
    return 0u;edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFromPack(edk::pack::FilePackage* pack,const edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    return this->newTileIsometricFromPack(pack,(edk::char8*) image,filter,color);edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFromPack(edk::pack::FilePackage* pack,edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    if(image && pack){
        //new tile with white color
        edk::uint32 position = this->newTileIsometric(color);edkEnd();
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);edkEnd();
                if(temp){
                    //
                    if(temp->loadImageFromPack(pack,image,filter)){
                        //return the position
                        return position;edkEnd();
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
        }
    }
    //else return minus one
    return 0u;edkEnd();
}
//create a new Isometric tile
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFlat(const edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    //
    return this->newTileIsometricFlat((edk::char8*) image,filter,color);edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFlat(edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    if(image){
        //new tile with white color
        edk::uint32 position = this->newTileIsometricFlat(color);edkEnd();
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);edkEnd();
                if(temp){
                    //
                    if(temp->loadImage(image,filter)){
                        //return the position
                        return position;edkEnd();
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
        }
    }
    //else return minus one
    return 0u;edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFlat(edk::color4f32 color){
    //create the new tile
    edk::tiles::TileIsometricFlat2D* tileTemp = new edk::tiles::TileIsometricFlat2D;edkEnd();
    if(tileTemp){
        //set the size of the tile
        tileTemp->setFrame(0,0,this->tileSize.width,this->tileSize.height);edkEnd();
        //set the color
        tileTemp->setColor(color);edkEnd();
        //save the stackSize
        edk::uint32 size = this->tiles.size();edkEnd();
        //add the tile in the stack
        edk::uint32 position = this->tiles.pushBack(tileTemp);edkEnd();
        if(size<this->tiles.size() || position){
            return position + 1u;edkEnd();
        }
        delete tileTemp;edkEnd();
    }
    //else return -1
    return 0;
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFlatFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    return this->newTileIsometricFlatFromMemory((edk::char8*) name,image,size,filter,color);edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFlatFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter,edk::color4f32 color){
    if(name && image){
        //new tile with white color
        edk::uint32 position = this->newTileIsometricFlat(color);edkEnd();
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);edkEnd();
                if(temp){
                    //
                    if(temp->loadImageFromMemory(name,image,size,filter)){
                        //return the position
                        return position;edkEnd();
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
        }
    }
    //else return minus one
    return 0u;edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFlatFromPack(edk::pack::FilePackage* pack,const edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    return this->newTileIsometricFlatFromPack(pack,(edk::char8*) image,filter,color);edkEnd();
}
edk::uint32 edk::tiles::TileSet2D::newTileIsometricFlatFromPack(edk::pack::FilePackage* pack,edk::char8* image,edk::uint32 filter,edk::color4f32 color){
    if(image && pack){
        //new tile with white color
        edk::uint32 position = this->newTileIsometricFlat(color);edkEnd();
        if(position){
            //load the image
            if(this->tiles.havePos(position -1u)){
                edk::tiles::Tile2D* temp = this->tiles.get(position -1u);edkEnd();
                if(temp){
                    //
                    if(temp->loadImageFromPack(pack,image,filter)){
                        //return the position
                        return position;edkEnd();
                    }
                    else{
                        //else remove the tile
                        this->tiles.remove(position-1u);edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
        }
    }
    //else return minus one
    return 0u;edkEnd();
}
//set the tile UVFrames
bool edk::tiles::TileSet2D::setTileFramesUV(edk::uint32 tile,edk::vec2ui32 frames){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->setFramesUV(frames);edkEnd();
            }
        }
        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setTileFramesUV(edk::uint32 tile,edk::uint32 x,edk::uint32 y){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->setFramesUV(x,y);edkEnd();
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
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->useFrameUV(frame);edkEnd();
            }
        }
        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setTileFrameUV(edk::uint32 tile,edk::uint32 x,edk::uint32 y){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->useFrameUV(x,y);edkEnd();
            }
        }
        return true;
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setTileFrameUVinPosition(edk::uint32 tile,edk::uint32 position){
    if(tile && position){
        tile--;edkEnd();
        position--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->useFrameUVinPosition(position);edkEnd();
            }
        }
        return true;
    }
    //else return false
    return false;
}

//add tileDrawCallback
bool edk::tiles::TileSet2D::addDrawCallback(edk::uint32 tile,edk::tiles::DrawTile2DCallback* callback){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->addDrawCallback(callback);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::removeDrawCallback(edk::uint32 tile,edk::tiles::DrawTile2DCallback* callback){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->removeDrawCallback(callback);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::runStartDraw(edk::uint32 id,edk::vec2ui32 position,edk::vec2f32 worldPosition){
    if(id){
        edk::uint32 tile = id-1u;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->runStartDraw(id,position,worldPosition);edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::runEndDraw(edk::uint32 id,edk::vec2ui32 position,edk::vec2f32 worldPosition){
    if(id){
        edk::uint32 tile = id-1u;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->runEndDraw(id,position,worldPosition);edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}

//Add a interpolation to the animation
bool edk::tiles::TileSet2D::addFrameInterpolation(edk::uint32 tile,edk::float32 second,edk::float32 frame){
    if(tile && frame>=1.f){
        tile--;edkEnd();
        frame-=1.f;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                this->treeAnimated.add(temp);edkEnd();
                return temp->addFrameInterpolation(second,frame);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//return the interpolationSize
edk::uint32 edk::tiles::TileSet2D::getInterpolationSize(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->getInterpolationSize();edkEnd();
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
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                this->treeAnimated.remove(temp);edkEnd();
                temp->cleanFames();edkEnd();
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
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->playForward();edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playForwardIn(edk::uint32 tile,edk::float32 second){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->playForwardIn(second);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playRewind(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->playRewind();edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playRewindIn(edk::uint32 tile,edk::float32 second){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->playRewindIn(second);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::pause(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->pause();edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::stop(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->stop();edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//set loop
bool edk::tiles::TileSet2D::setLoop(edk::uint32 tile,bool loop){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->setLoop(loop);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::loopOn(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->loopOn();edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::loopOff(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->loopOff();edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//get the second
edk::float32 edk::tiles::TileSet2D::getSecond(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->getSecond();edkEnd();
            }
        }
    }
    //else return false
    return 0.f;
}
//return if are playing
bool edk::tiles::TileSet2D::isPlaying(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->isPlaying();edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::isPlayingName(edk::uint32 tile,const edk::char8* name){
    return this->isPlayingName(tile,(edk::char8*) name);edkEnd();
}
bool edk::tiles::TileSet2D::isPlayingName(edk::uint32 tile,edk::char8* name){
    if(tile && name){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->isPlayingName(name);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//animationNames
bool edk::tiles::TileSet2D::addAnimationName(edk::uint32 tile,const edk::char8* name, edk::float32 start,edk::float32 end){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->addAnimationName(name,start,end);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::addAnimationName(edk::uint32 tile,edk::char8* name, edk::float32 start,edk::float32 end){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->addAnimationName(name,start,end);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//test if have the animationName
bool edk::tiles::TileSet2D::haveAnimationName(edk::uint32 tile,const edk::char8* name){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->haveAnimationName(name);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::haveAnimationName(edk::uint32 tile,edk::char8* name){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->haveAnimationName(name);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//Play the animationName
bool edk::tiles::TileSet2D::playNameForward(edk::uint32 tile,const edk::char8* name){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->playNameForward(name);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playNameForward(edk::uint32 tile,edk::char8* name){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->playNameForward(name);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playNameRewind(edk::uint32 tile,const edk::char8* name){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->playNameRewind(name);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::playNameRewind(edk::uint32 tile,edk::char8* name){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->playNameRewind(name);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//remove the animationName
bool edk::tiles::TileSet2D::removeAnimationName(edk::uint32 tile,const edk::char8* name){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->removeAnimationName(name);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::removeAnimationName(edk::uint32 tile,edk::char8* name){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->removeAnimationName(name);edkEnd();
            }
        }
    }
    //else return false
    return false;
}

//Set one interpolation X as a curve
bool edk::tiles::TileSet2D::setCurveX(edk::uint32 tile,edk::uint32 position){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->setCurveX(position);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setNotCurveX(edk::uint32 tile,edk::uint32 position){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->setNotCurveX(position);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::getIsCurveX(edk::uint32 tile,edk::uint32 position){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->getIsCurveX(position);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//Set the interpolation curve points
bool edk::tiles::TileSet2D::setCurveP1X(edk::uint32 tile,edk::uint32 position,edk::float32 second,edk::float32 x){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->setCurveP1X(position,second,x);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::setCurveP2X(edk::uint32 tile,edk::uint32 position,edk::float32 second,edk::float32 x){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->setCurveP2X(position,second,x);edkEnd();
            }
        }
    }
    //else return false
    return false;
}

//update the animations
bool edk::tiles::TileSet2D::updateAnimations(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->updateAnimation();edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::updateAnimations(edk::uint32 tile,edk::float32 seconds){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->updateAnimation(seconds);edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::updateAnimations(){
    edk::uint32 size = this->treeAnimated.size();edkEnd();
    if(size){
        edk::tiles::Tile2D* temp = NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->treeAnimated.getElementInPosition(i);edkEnd();
            if(temp){
                temp->updateAnimation();edkEnd();
            }
        }
        return true;
    }
    return false;
}
bool edk::tiles::TileSet2D::updateAnimations(edk::float32 seconds){
    edk::uint32 size = this->treeAnimated.size();edkEnd();
    if(size){
        edk::tiles::Tile2D* temp = NULL;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->treeAnimated.getElementInPosition(i);edkEnd();
            if(temp){
                temp->updateAnimation(seconds);edkEnd();
            }
        }
        return true;
    }
    return false;
}

//create a new object physics
bool edk::tiles::TileSet2D::setTilePhysics(edk::uint32 tile,edk::physics::bodyType type){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->setPhysics(type);edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//add a polygon to the physics Object
bool edk::tiles::TileSet2D::addTilePhysicsPolygon(edk::uint32 tile,edk::shape::Polygon2D poly){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                poly.cantDeletePolygon();edkEnd();
                return temp->addPhysicsPolygon(poly);edkEnd();
            }
        }
    }
    //else return false
    poly.cantDeletePolygon();edkEnd();
    return false;
}
bool edk::tiles::TileSet2D::cleanTilePhysicsPolygons(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->cleanPhysicsPolygons();edkEnd();
            }
        }
    }
    //else return false
    return false;
}
//get the tilePhysicsMesh
edk::physics2D::PhysicsMesh2D* edk::tiles::TileSet2D::getTilePhysicsMeshPointer(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->getPhysicsMeshPointer();edkEnd();
            }
        }
    }
    //else return false
    return NULL;
}
//return the tileMesh
edk::shape::Mesh2D* edk::tiles::TileSet2D::getTileMeshPointer(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->getMeshPointer();edkEnd();
            }
        }
    }
    //else return false
    return NULL;
}

//delete the objectPhysics
bool edk::tiles::TileSet2D::deleteTilePhysics(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->deletePhysics();edkEnd();
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
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->getPhysicsObject();edkEnd();
            }
        }
    }
    //else return false
    return NULL;
}
//return true if the tile is physics
bool edk::tiles::TileSet2D::isTilePhysics(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                return temp->isPhysics();edkEnd();
            }
        }
    }
    //else return false
    return NULL;
}

//Draw the tile from the tileSet
bool edk::tiles::TileSet2D::drawTile(edk::uint32 tile,
                                     edk::vec2f32 position,
                                     edk::float32 angle,
                                     edk::size2f32 size,
                                     edk::color4f32 color
                                     ){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->setColor(color);edkEnd();
                temp->setDiffuse(color);edkEnd();
                temp->setEmission(color);edkEnd();
                temp->setPosition(position.x * temp->getWidth(),position.y * temp->getHeight());edkEnd();
                temp->draw(angle,size);edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::drawTile(edk::uint32 tile,
                                     edk::float32 positionX,
                                     edk::float32 positionY,
                                     edk::float32 angle,
                                     edk::size2f32 size,
                                     edk::color4f32 color
                                     ){
    //
    return this->drawTile(tile,
                          edk::vec2f32(positionX,
                                       positionY
                                       ),
                          angle,
                          size,
                          color
                          );edkEnd();
}
bool edk::tiles::TileSet2D::drawTileWithoutMaterial(edk::uint32 tile,
                                                    edk::vec2f32 position,
                                                    edk::float32 angle,
                                                    edk::size2f32 size,
                                                    edk::color4f32 color
                                                    ){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->setColor(color);edkEnd();
                temp->setDiffuse(color);edkEnd();
                temp->setEmission(color);edkEnd();
                temp->setPosition(position.x * temp->getWidth(),position.y * temp->getHeight());edkEnd();
                temp->drawWithoutMaterial(angle,size);edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::drawTileWithoutMaterial(edk::uint32 tile,
                                                    edk::float32 positionX,
                                                    edk::float32 positionY,
                                                    edk::float32 angle,
                                                    edk::size2f32 size,
                                                    edk::color4f32 color
                                                    ){
    return this->drawTileWithoutMaterial(tile,
                                         edk::vec2f32(positionX,
                                                      positionY
                                                      ),
                                         angle,
                                         size,
                                         color
                                         );edkEnd();
}
void edk::tiles::TileSet2D::drawTileWire(edk::vec2f32 position,
                                         edk::float32 angle,
                                         edk::size2f32 size,
                                         edk::color4f32 color
                                         ){
    this->tileTemp.setColor(color);edkEnd();
    this->tileTemp.setPosition(position.x * this->tileTemp.getWidth(),position.y * this->tileTemp.getHeight());edkEnd();
    this->tileTemp.drawWire(angle,size);edkEnd();
}
void edk::tiles::TileSet2D::drawTileWire(edk::float32 positionX,
                                         edk::float32 positionY,
                                         edk::float32 angle,
                                         edk::size2f32 size,
                                         edk::color4f32 color
                                         ){
    return this->drawTileWire(
                edk::vec2f32(
                    positionX,
                    positionY
                    ),
                angle,
                size,
                color);edkEnd();
}
void edk::tiles::TileSet2D::drawTileIsometricWire(edk::vec2f32 position,
                                                  edk::float32 angle,
                                                  edk::size2f32 size,
                                                  edk::color4f32 color
                                                  ){
    this->tileIsometricTemp.setColor(color);edkEnd();
    this->tileIsometricTemp.setPosition(position.x * this->tileTemp.getWidth(),position.y * this->tileTemp.getHeight());edkEnd();
    this->tileIsometricTemp.drawWire(angle,size);edkEnd();
}
void edk::tiles::TileSet2D::drawTileIsometricWire(edk::float32 positionX,
                                                  edk::float32 positionY,
                                                  edk::float32 angle,
                                                  edk::size2f32 size,
                                                  edk::color4f32 color
                                                  ){
    return this->drawTileIsometricWire(
                edk::vec2f32(
                    positionX,
                    positionY
                    ),
                angle,
                size,
                color);edkEnd();
}
void edk::tiles::TileSet2D::drawTileSelection(edk::vec2f32 position,
                                              edk::float32 angle,
                                              edk::size2f32 size
                                              ){
    this->tileTemp.setPosition(position.x * this->tileTemp.getWidth(),position.y * this->tileTemp.getHeight());edkEnd();
    this->tileTemp.drawSelection(angle,size);edkEnd();
}
void edk::tiles::TileSet2D::drawTileSelection(edk::float32 positionX,
                                              edk::float32 positionY,
                                              edk::float32 angle,
                                              edk::size2f32 size
                                              ){
    //
    return this->drawTileSelection(
                edk::vec2f32(
                    positionX,
                    positionY
                    ),
                angle,
                size
                );edkEnd();
}
bool edk::tiles::TileSet2D::drawTileInWorld(edk::uint32 tile,
                                            edk::vec2f32 position,
                                            edk::float32 angle,
                                            edk::size2f32 size,
                                            edk::color4f32 color
                                            ){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->setPosition(position.x,position.y);edkEnd();
                temp->setColor(color);edkEnd();
                temp->draw(angle,size);edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::drawTileInWorld(edk::uint32 tile,
                                            edk::float32 positionX,
                                            edk::float32 positionY,
                                            edk::float32 angle,
                                            edk::size2f32 size,
                                            edk::color4f32 color
                                            ){
    //
    return this->drawTileInWorld(tile,
                                 edk::vec2f32(positionX,
                                              positionY
                                              ),
                                 angle,
                                 size,
                                 color
                                 );edkEnd();
}
void edk::tiles::TileSet2D::drawTileSelectionInWorld(edk::vec2f32 position,
                                                     edk::float32 angle,
                                                     edk::size2f32 size
                                                     ){
    this->tileTemp.setPosition(position.x,position.y);edkEnd();
    this->tileTemp.drawSelection(angle,size);edkEnd();
}
void edk::tiles::TileSet2D::drawTileSelectionInWorld(edk::float32 positionX,
                                                     edk::float32 positionY,
                                                     edk::float32 angle,
                                                     edk::size2f32 size
                                                     ){
    //
    this->drawTileSelectionInWorld(edk::vec2f32(positionX,
                                                positionY
                                                ),
                                   angle,
                                   size
                                   );edkEnd();
}

bool edk::tiles::TileSet2D::drawTilePhysics(edk::uint32 tile,
                                            edk::vec2f32 position,
                                            edk::float32 angle,
                                            edk::size2f32 size,
                                            edk::color4f32 color
                                            ){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->setColor(color);edkEnd();
                temp->setPosition(position.x * temp->getWidth(),position.y * temp->getHeight());edkEnd();
                temp->drawPhysic(angle,size);edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::drawTilePhysics(edk::uint32 tile,
                                            edk::float32 positionX,
                                            edk::float32 positionY,
                                            edk::float32 angle,
                                            edk::size2f32 size,
                                            edk::color4f32 color
                                            ){
    return this->drawTilePhysics(tile,
                                 edk::vec2f32(positionX,
                                              positionY
                                              ),
                                 angle,
                                 size,
                                 color
                                 );edkEnd();
}
bool edk::tiles::TileSet2D::drawTilePhysicsInWorld(edk::uint32 tile,
                                                   edk::vec2f32 position,
                                                   edk::float32 angle,
                                                   edk::size2f32 size,
                                                   edk::color4f32 color
                                                   ){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                temp->setPosition(position.x,position.y);edkEnd();
                temp->setColor(color);edkEnd();
                temp->drawPhysic(angle,size);edkEnd();
                return true;
            }
        }
    }
    //else return false
    return false;
}
bool edk::tiles::TileSet2D::drawTilePhysicsInWorld(edk::uint32 tile,
                                                   edk::float32 positionX,
                                                   edk::float32 positionY,
                                                   edk::float32 angle,
                                                   edk::size2f32 size,
                                                   edk::color4f32 color
                                                   ){
    //
    return this->drawTilePhysicsInWorld(tile,
                                        edk::vec2f32(positionX,
                                                     positionY
                                                     ),
                                        angle,
                                        size,
                                        color
                                        );edkEnd();
}
bool edk::tiles::TileSet2D::printTile(edk::uint32 tile){
    if(tile){
        tile--;edkEnd();
        //load the tile from the stack
        if(this->tiles.havePos(tile)){
            edk::tiles::Tile2D* temp = this->tiles.get(tile);edkEnd();
            if(temp){
                printf("\nPosition %.2f %.2f size %.2f %.2f"
                       ,temp->getPositionX()
                       ,temp->getPositionY()
                       ,temp->getWidth()
                       ,temp->getHeight()
                       );edkEnd();
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
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tileSet_",nameID);edkEnd();
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        edk::char8* temp;edkEnd();
                        //write tileSize
                        temp = edk::String::float32ToStr(this->tileSize.width);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeW",temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->tileSize.height);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"sizeH",temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //write the position
                        temp = edk::String::float32ToStr(this->tilesPosition.x);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"posX",temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        temp = edk::String::float32ToStr(this->tilesPosition.y);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"posY",temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        //write the tiles
                        edk::uint32 size = this->tiles.size();edkEnd();
                        //write size
                        temp = edk::String::int64ToStr(size);edkEnd();
                        if(temp){
                            xml->addSelectedNextAttribute((edk::char8*)"tileSize",temp);edkEnd();
                            delete[] temp;edkEnd();
                        }
                        edk::tiles::Tile2D* tileTemp;edkEnd();
                        for(edk::uint32 i=0u;i<=size;i++){
                            if(this->tiles.havePos(i)){
                                tileTemp = tiles[i];edkEnd();
                                if(tileTemp){
                                    //write the tile
                                    tileTemp->writeToXML(xml,i+1u);edkEnd();
                                }
                            }
                        }
                        edk::char8* nameTemp;edkEnd();
                        edk::char8* iTemp;edkEnd();
                        //write the animatedTiles
                        for(edk::uint32 i=0u;i<size;i++){
                            tileTemp = tiles[i];edkEnd();
                            if(tileTemp){
                                //test if have the tile in animatedTree
                                if(this->treeAnimated.haveElement(tileTemp)){
                                    //set the tile as animated
                                    iTemp = edk::String::int64ToStr(i+1u);edkEnd();
                                    if(iTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"anim_",iTemp);edkEnd();
                                        if(nameTemp){
                                            //add the animated
                                            if(xml->addSelectedNextChild(nameTemp)){
                                                if(xml->selectChild(nameTemp)){
                                                    xml->selectFather();edkEnd();
                                                }
                                            }
                                            delete[] nameTemp;edkEnd();
                                        }
                                        delete[] iTemp;edkEnd();
                                    }
                                }
                            }
                        }
                        ret=true;edkEnd();
                        xml->selectFather();edkEnd();
                    }
                }
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
        return ret;
    }
    return false;
}
bool edk::tiles::TileSet2D::readFromXML(edk::XML* xml,edk::uint32 id){
    this->treeRemoveXML.clean();edkEnd();
    if(xml){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tileSet_",nameID);edkEnd();
            if(name){
                //select the name
                if(xml->selectChild(name)){
                    this->deleteTiles();edkEnd();
                    ret=true;edkEnd();
                    //read the size
                    this->tileSize = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH"))
                                                   );edkEnd();
                    //read the position
                    this->tilesPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("posX")),
                                                       edk::String::strToFloat32(xml->getSelectedAttributeValueByName("posY"))
                                                       );edkEnd();

                    //read tiles
                    edk::tiles::Tile2D* tileTemp;edkEnd();
                    //                    edk::int32 i = 0u;edkEnd();
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* iTemp;edkEnd();
                    edk::uint32 size = edk::String::strToInt64(xml->getSelectedAttributeValueByName("tileSize"));edkEnd();
                    edk::uint32 sizeStack;edkEnd();
                    for(edk::uint32 i=1u;i<=size;i++){
                        tileTemp = new edk::tiles::Tile2D;edkEnd();
                        if(tileTemp){
                            //add the tile
                            sizeStack = this->tiles.size();edkEnd();
                            this->tiles.pushBack(tileTemp);edkEnd();
                            if(sizeStack<this->tiles.size()){
                                //load the tile
                                if(tileTemp->readFromXML(xml,i)){
                                    //test if the tile is animated
                                    iTemp = edk::String::int64ToStr(i);edkEnd();
                                    if(iTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"anim_",iTemp);edkEnd();
                                        if(nameTemp){
                                            //test the animated
                                            if(xml->selectChild(nameTemp)){
                                                //add the tile to the animatedTree
                                                this->treeAnimated.add(tileTemp);edkEnd();
                                                xml->selectFather();edkEnd();
                                            }
                                            delete[] nameTemp;edkEnd();
                                        }
                                        delete[] iTemp;edkEnd();
                                    }
                                }
                                else{
                                    //else remove the tile after
                                    this->treeRemoveXML.add(i);edkEnd();
                                    //
                                }
                            }
                            else{
                                //
                                delete tileTemp;edkEnd();
                                ret=false;edkEnd();
                                break;
                            }
                        }
                    }
                    //remove the tiles
                    size = this->treeRemoveXML.size();edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        this->deleteTile(this->treeRemoveXML.getElementInPosition(i));edkEnd();
                    }
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
        this->treeRemoveXML.clean();edkEnd();
        return ret;
    }
    return false;
}
bool edk::tiles::TileSet2D::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    this->treeRemoveXML.clean();edkEnd();
    if(xml && pack){
        bool ret=false;edkEnd();
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);edkEnd();
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)"tileSet_",nameID);edkEnd();
            if(name){
                //select the name
                if(xml->selectChild(name)){
                    this->deleteTiles();edkEnd();
                    ret=true;edkEnd();
                    //read the size
                    this->tileSize = edk::size2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeW")),
                                                   edk::String::strToFloat32(xml->getSelectedAttributeValueByName("sizeH"))
                                                   );edkEnd();
                    //read the position
                    this->tilesPosition = edk::vec2f32(edk::String::strToFloat32(xml->getSelectedAttributeValueByName("posX")),
                                                       edk::String::strToFloat32(xml->getSelectedAttributeValueByName("posY"))
                                                       );edkEnd();

                    //read tiles
                    edk::tiles::Tile2D* tileTemp;edkEnd();
                    //                    edk::int32 i = 0u;edkEnd();
                    edk::char8* nameTemp;edkEnd();
                    edk::char8* iTemp;edkEnd();
                    edk::uint32 size = edk::String::strToInt64(xml->getSelectedAttributeValueByName("tileSize"));edkEnd();
                    edk::uint32 sizeStack;edkEnd();
                    for(edk::uint32 i=1u;i<=size;i++){
                        tileTemp = new edk::tiles::Tile2D;edkEnd();
                        if(tileTemp){
                            //add the tile
                            sizeStack = this->tiles.size();edkEnd();
                            this->tiles.pushBack(tileTemp);edkEnd();
                            if(sizeStack<this->tiles.size()){
                                //load the tile
                                if(tileTemp->readFromXMLFromPack(pack,xml,i)){
                                    //test if the tile is animated
                                    iTemp = edk::String::int64ToStr(i);edkEnd();
                                    if(iTemp){
                                        nameTemp = edk::String::strCat((edk::char8*)"anim_",iTemp);edkEnd();
                                        if(nameTemp){
                                            //test the animated
                                            if(xml->selectChild(nameTemp)){
                                                //add the tile to the animatedTree
                                                this->treeAnimated.add(tileTemp);edkEnd();
                                                xml->selectFather();edkEnd();
                                            }
                                            delete[] nameTemp;edkEnd();
                                        }
                                        delete[] iTemp;edkEnd();
                                    }
                                }
                                else{
                                    //else remove the tile after
                                    this->treeRemoveXML.add(i);edkEnd();
                                    //
                                }
                            }
                            else{
                                //
                                delete tileTemp;edkEnd();
                                ret=false;edkEnd();
                                break;
                            }
                        }
                    }
                    //remove the tiles
                    size = this->treeRemoveXML.size();edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        this->deleteTile(this->treeRemoveXML.getElementInPosition(i));edkEnd();
                    }
                    xml->selectFather();edkEnd();
                }
                delete[] name;edkEnd();
            }
            delete[] nameID;edkEnd();
        }
        this->treeRemoveXML.clean();edkEnd();
        return ret;
    }
    return false;
}
