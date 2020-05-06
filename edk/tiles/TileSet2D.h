#ifndef TILESET2D_H
#define TILESET2D_H

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

#ifdef printMessages
#warning "Inside TileSet2D"
#endif

#pragma once
#include "Tile2D.h"
#include "TileIsometric2D.h"
#include "TileIsometricFlat2D.h"
#include "../vector/Stack.h"
#include "../vector/BinaryTree.h"
#include "../pack/FilePackage.h"

#ifdef printMessages
#warning "    Compiling TileSet2D"
#endif

namespace edk{
namespace tiles{

#define tileStack 10u

class TileSet2D{
public:
    TileSet2D();
    ~TileSet2D();

    //Class to return two positions of te tiles
    class Tile2Positions2D{
    public:
        Tile2Positions2D(){this->first = this->last = 0u;}
        ~Tile2Positions2D(){}
        //
        edk::uint32 first;
        edk::uint32 last;
    };

    //Delete all tiles
    void deleteTiles();
    //delete one tile
    bool deleteTile(edk::uint32 position);
    //delete one tile
    bool deleteTilePosition(edk::uint32 position);
    //test if have the tile
    bool haveTile(edk::uint32 position);

    //set the size of the tiles
    bool setSizeOfTiles(edk::size2f32 size);
    bool setSizeOfTiles(edk::float32 width,edk::float32 height);

    //return the size of tiles
    edk::size2f32 getSizeOfTiles();
    //return the tileSize
    edk::uint32 getTileSize();

    //load the tiles from an image
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTiles(const edk::char8* image,
                                                           edk::uint32 x,
                                                           edk::uint32 y,
                                                           edk::uint32 filter = GU_NEAREST,
                                                           edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTiles(const edk::char8* image,
                                                           edk::vec2ui32 frames,
                                                           edk::uint32 filter = GU_NEAREST,
                                                           edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTiles(edk::char8* image,
                                                           edk::uint32 x,
                                                           edk::uint32 y,
                                                           edk::uint32 filter = GU_NEAREST,
                                                           edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTiles(edk::char8* image,
                                                           edk::vec2ui32 frames,
                                                           edk::uint32 filter = GU_NEAREST,
                                                           edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    //Load the tiles from mamory
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesFromMemory(const edk::char8* name,
                                                                     edk::uint8* image,
                                                                     edk::uint32 size,
                                                                     edk::uint32 x,
                                                                     edk::uint32 y,
                                                                     edk::uint32 filter = GU_NEAREST,
                                                                     edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesFromMemory(const edk::char8* name,
                                                                     edk::uint8* image,
                                                                     edk::uint32 size,
                                                                     edk::vec2ui32 frames,
                                                                     edk::uint32 filter = GU_NEAREST,
                                                                     edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesFromMemory(edk::char8* name,
                                                                     edk::uint8* image,
                                                                     edk::uint32 size,
                                                                     edk::uint32 x,
                                                                     edk::uint32 y,
                                                                     edk::uint32 filter = GU_NEAREST,
                                                                     edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesFromMemory(edk::char8* name,
                                                                     edk::uint8* image,
                                                                     edk::uint32 size,
                                                                     edk::vec2ui32 frames,
                                                                     edk::uint32 filter = GU_NEAREST,
                                                                     edk::color4f32 color = edk::color4f32(1,1,1,1)
            );

    //load the tiles from an image
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometric(const edk::char8* image,
                                                                    edk::uint32 x,
                                                                    edk::uint32 y,
                                                                    edk::uint32 filter = GU_NEAREST,
                                                                    edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometric(const edk::char8* image,
                                                                    edk::vec2ui32 frames,
                                                                    edk::uint32 filter = GU_NEAREST,
                                                                    edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometric(edk::char8* image,
                                                                    edk::uint32 x,
                                                                    edk::uint32 y,
                                                                    edk::uint32 filter = GU_NEAREST,
                                                                    edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometric(edk::char8* image,
                                                                    edk::vec2ui32 frames,
                                                                    edk::uint32 filter = GU_NEAREST,
                                                                    edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    //Load the tiles from mamory
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFromMemory(const edk::char8* name,
                                                                              edk::uint8* image,
                                                                              edk::uint32 size,
                                                                              edk::uint32 x,
                                                                              edk::uint32 y,
                                                                              edk::uint32 filter = GU_NEAREST,
                                                                              edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFromMemory(const edk::char8* name,
                                                                              edk::uint8* image,
                                                                              edk::uint32 size,
                                                                              edk::vec2ui32 frames,
                                                                              edk::uint32 filter = GU_NEAREST,
                                                                              edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFromMemory(edk::char8* name,
                                                                              edk::uint8* image,
                                                                              edk::uint32 size,
                                                                              edk::uint32 x,
                                                                              edk::uint32 y,
                                                                              edk::uint32 filter = GU_NEAREST,
                                                                              edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFromMemory(edk::char8* name,
                                                                              edk::uint8* image,
                                                                              edk::uint32 size,
                                                                              edk::vec2ui32 frames,
                                                                              edk::uint32 filter = GU_NEAREST,
                                                                              edk::color4f32 color = edk::color4f32(1,1,1,1)
            );

    //load the tiles from an image
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFlat(const edk::char8* image,
                                                                        edk::uint32 x,
                                                                        edk::uint32 y,
                                                                        edk::uint32 filter = GU_NEAREST,
                                                                        edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFlat(const edk::char8* image,
                                                                        edk::vec2ui32 frames,
                                                                        edk::uint32 filter = GU_NEAREST,
                                                                        edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFlat(edk::char8* image,
                                                                        edk::uint32 x,
                                                                        edk::uint32 y,
                                                                        edk::uint32 filter = GU_NEAREST,
                                                                        edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFlat(edk::char8* image,
                                                                        edk::vec2ui32 frames,
                                                                        edk::uint32 filter = GU_NEAREST,
                                                                        edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    //Load the tiles from mamory
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFlatFromMemory(const edk::char8* name,
                                                                                  edk::uint8* image,
                                                                                  edk::uint32 size,
                                                                                  edk::uint32 x,
                                                                                  edk::uint32 y,
                                                                                  edk::uint32 filter = GU_NEAREST,
                                                                                  edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFlatFromMemory(const edk::char8* name,
                                                                                  edk::uint8* image,
                                                                                  edk::uint32 size,
                                                                                  edk::vec2ui32 frames,
                                                                                  edk::uint32 filter = GU_NEAREST,
                                                                                  edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFlatFromMemory(edk::char8* name,
                                                                                  edk::uint8* image,
                                                                                  edk::uint32 size,
                                                                                  edk::uint32 x,
                                                                                  edk::uint32 y,
                                                                                  edk::uint32 filter = GU_NEAREST,
                                                                                  edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    edk::tiles::TileSet2D::Tile2Positions2D loadImageTilesIsometricFlatFromMemory(edk::char8* name,
                                                                                  edk::uint8* image,
                                                                                  edk::uint32 size,
                                                                                  edk::vec2ui32 frames,
                                                                                  edk::uint32 filter = GU_NEAREST,
                                                                                  edk::color4f32 color = edk::color4f32(1,1,1,1)
            );

    //create a new tile
    edk::uint32 newTile(const edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTile(edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTile(edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTileFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTileFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    //create a new Isometric tile
    edk::uint32 newTileIsometric(const edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTileIsometric(edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTileIsometric(edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTileIsometricFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTileIsometricFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    //create a new IsometricFlat tile
    edk::uint32 newTileIsometricFlat(const edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTileIsometricFlat(edk::char8* image,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTileIsometricFlat(edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTileIsometricFlatFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    edk::uint32 newTileIsometricFlatFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    //set the tile UVFrames
    bool setTileFramesUV(edk::uint32 tile,edk::vec2ui32 frames);
    bool setTileFramesUV(edk::uint32 tile,edk::uint32 x,edk::uint32 y);
    //use the tile UV frame
    bool setTileFrameUV(edk::uint32 tile,edk::vec2ui32 frame);
    bool setTileFrameUV(edk::uint32 tile,edk::uint32 x,edk::uint32 y);
    bool setTileFrameUVinPosition(edk::uint32 tile,edk::uint32 position);

    //Add a interpolation to the animation
    bool addFrameInterpolation(edk::uint32 tile,edk::float32 second,edk::float32 frame);
    //return the interpolationSize
    edk::uint32 getInterpolationSize(edk::uint32 tile);
    //clean
    bool cleanFrames(edk::uint32 tile);
    //controls
    bool playForward(edk::uint32 tile);
    bool playForwardIn(edk::uint32 tile,edk::float32 second);
    bool playRewind(edk::uint32 tile);
    bool playRewindIn(edk::uint32 tile,edk::float32 second);
    bool pause(edk::uint32 tile);
    bool stop(edk::uint32 tile);
    //set loop
    bool setLoop(edk::uint32 tile,bool loop);
    bool loopOn(edk::uint32 tile);
    bool loopOff(edk::uint32 tile);
    //get the second
    edk::float32 getSecond(edk::uint32 tile);
    //return if are playing
    bool isPlaying(edk::uint32 tile);
    //animationNames
    bool addAnimationName(edk::uint32 tile,const edk::char8* name, edk::float32 start,edk::float32 end);
    bool addAnimationName(edk::uint32 tile,edk::char8* name, edk::float32 start,edk::float32 end);
    //test if have the animationName
    bool haveAnimationName(edk::uint32 tile,const edk::char8* name);
    bool haveAnimationName(edk::uint32 tile,edk::char8* name);
    //Play the animationName
    bool playNameForward(edk::uint32 tile,const edk::char8* name);
    bool playNameForward(edk::uint32 tile,edk::char8* name);
    bool playNameRewind(edk::uint32 tile,const edk::char8* name);
    bool playNameRewind(edk::uint32 tile,edk::char8* name);
    //remove the animationName
    bool removeAnimationName(edk::uint32 tile,const edk::char8* name);
    bool removeAnimationName(edk::uint32 tile,edk::char8* name);

    //Set one interpolation X as a curve
    bool setCurveX(edk::uint32 tile,edk::uint32 position);
    bool setNotCurveX(edk::uint32 tile,edk::uint32 position);
    bool getIsCurveX(edk::uint32 tile,edk::uint32 position);
    //Set the interpolation curve points
    bool setCurveP1X(edk::uint32 tile,edk::uint32 position,edk::float32 second,edk::float32 x);
    bool setCurveP2X(edk::uint32 tile,edk::uint32 position,edk::float32 second,edk::float32 x);

    //update the animations
    bool updateAnimations(edk::uint32 tile);
    bool updateAnimations(edk::uint32 tile,edk::float32 seconds);
    bool updateAnimations();
    bool updateAnimations(edk::float32 seconds);

    //create a new object physics
    bool setTilePhysics(edk::uint32 tile,edk::physics::bodyType type);
    //add a polygon to the physics Object
    bool addTilePhysicsPolygon(edk::uint32 tile,edk::shape::Polygon2D poly);
    bool cleanTilePhysicsPolygons(edk::uint32 tile);
    //get the tilePhysicsMesh
    edk::physics2D::PhysicsMesh2D* getTilePhysicsMeshPointer(edk::uint32 tile);
    //return the tileMesh
    edk::shape::Mesh2D* getTileMeshPointer(edk::uint32 tile);
    //delete the objectPhysics
    bool deleteTilePhysics(edk::uint32 tile);
    //return the physicsObject
    edk::physics2D::PhysicObject2D* getTilePhysicsObject(edk::uint32 tile);
    //return true if the tile is physics
    bool isTilePhysics(edk::uint32 tile);

    //Draw the tile from the tileSet
    bool drawTile(edk::uint32 tile,
                  edk::vec2f32 position,
                  edk::float32 angle=0.f,
                  edk::size2f32 size = edk::size2f32(1,1),
                  edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    bool drawTile(edk::uint32 tile,
                  edk::float32 positionX,
                  edk::float32 positionY,
                  edk::float32 angle=0.f,
                  edk::size2f32 size = edk::size2f32(1,1),
                  edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    void drawTileSelection(edk::vec2f32 position,
                           edk::float32 angle=0.f,
                           edk::size2f32 size = edk::size2f32(1,1)
            );
    void drawTileWire(edk::vec2f32 position,
                      edk::float32 angle=0.f,
                      edk::size2f32 size = edk::size2f32(1,1),
                      edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    void drawTileWire(edk::float32 positionX,
                      edk::float32 positionY,
                      edk::float32 angle=0.f,
                      edk::size2f32 size = edk::size2f32(1,1),
                      edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    void drawTileIsometricWire(edk::vec2f32 position,
                               edk::float32 angle=0.f,
                               edk::size2f32 size = edk::size2f32(1,1),
                               edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    void drawTileIsometricWire(edk::float32 positionX,
                               edk::float32 positionY,
                               edk::float32 angle=0.f,
                               edk::size2f32 size = edk::size2f32(1,1),
                               edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    void drawTileSelection(edk::float32 positionX,
                           edk::float32 positionY,
                           edk::float32 angle=0.f,
                           edk::size2f32 size = edk::size2f32(1,1)
            );
    bool drawTileInWorld(edk::uint32 tile,
                         edk::vec2f32 position,
                         edk::float32 angle=0.f,
                         edk::size2f32 size = edk::size2f32(1,1),
                         edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    bool drawTileInWorld(edk::uint32 tile,
                         edk::float32 positionX,
                         edk::float32 positionY,
                         edk::float32 angle=0.f,
                         edk::size2f32 size = edk::size2f32(1,1),
                         edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    void drawTileSelectionInWorld(edk::vec2f32 position,
                                  edk::float32 angle=0.f,
                                  edk::size2f32 size = edk::size2f32(1,1)
            );
    void drawTileSelectionInWorld(edk::float32 positionX,
                                  edk::float32 positionY,
                                  edk::float32 angle=0.f,
                                  edk::size2f32 size = edk::size2f32(1,1)
            );
    bool drawTilePhysics(edk::uint32 tile,
                         edk::vec2f32 position,
                         edk::float32 angle=0.f,
                         edk::size2f32 size = edk::size2f32(1,1),
                         edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    bool drawTilePhysics(edk::uint32 tile,
                         edk::float32 positionX,
                         edk::float32 positionY,
                         edk::float32 angle=0.f,
                         edk::size2f32 size = edk::size2f32(1,1),
                         edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    bool drawTilePhysicsInWorld(edk::uint32 tile,
                                edk::vec2f32 position,
                                edk::float32 angle=0.f,
                                edk::size2f32 size = edk::size2f32(1,1),
                                edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    bool drawTilePhysicsInWorld(edk::uint32 tile,
                                edk::float32 positionX,
                                edk::float32 positionY,
                                edk::float32 angle=0.f,
                                edk::size2f32 size = edk::size2f32(1,1),
                                edk::color4f32 color=edk::color4f32(1,1,1,1)
            );
    bool printTile(edk::uint32 tile);

    //XML
    bool writeToXML(edk::XML* xml,edk::uint32 id);
    bool readFromXML(edk::XML* xml,edk::uint32 id);
    bool readFromXMLWithPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);
private:
    edk::vector::Stack<edk::tiles::Tile2D*> tiles;
    //animated tiles
    edk::vector::BinaryTree<edk::tiles::Tile2D*> treeAnimated;
    //tiles size
    edk::size2f32 tileSize;
    //position of the tileSet
    edk::vec2f32 tilesPosition;
    //tree XML to remove the tile
    edk::vector::BinaryTree<edk::uint32> treeRemoveXML;
    //tileTemp to draw the selection
    edk::tiles::Tile2D tileTemp;
    //tileTemp to draw the selection
    edk::tiles::TileIsometric2D tileIsometricTemp;
};
}//end namespace tiles
}//end namespace edk

#endif // TILESET2D_H
