#ifndef TILE2D_H
#define TILE2D_H

/*
Library Tile2D - Draw 2D Tile in EDK Game Engine
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
#pragma message "Inside Tile2D"
#endif

#pragma once
#include "../Object2D.h"
#include "../collision/RectangleContact.h"
#include "../physics2D/PhysicObject2D.h"
#include "../physics2D/StaticObject2D.h"
#include "../physics2D/KinematicObject2D.h"
#include "../physics2D/DynamicObject2D.h"
#include "../xml/XML.h"
#include "../pack/FilePackage.h"
#include "../vector/BinaryTree.h"

#ifdef printMessages
#pragma message "    Compiling Tile2D"
#endif

namespace edk{
namespace tiles{
class DrawTile2DCallback{
public:
    DrawTile2DCallback(){}
    virtual void startDrawTile(edk::uint32 /*id*/,edk::vec2ui32 /*position*/,edk::vec2f32 /*worldPosition*/){}
    virtual void endDrawTile(edk::uint32 /*id*/,edk::vec2ui32 /*position*/,edk::vec2f32 /*worldPosition*/){}
};
enum tile2DType{
    tile2DTypeNormal=0u,
    tile2DTypeIsometric,
    tile2DTypeIsometricFlat,
    //
    tile2DTypeSize,
};
class Tile2D{
public:
    Tile2D();
    virtual ~Tile2D();

    void Constructor();
    void Destructor();

    //return the type of the tile to the tileSet know witch tile is before delete it
    virtual edk::tiles::tile2DType getType();

    //set the Tile Position
    void setPosition(edk::vec2f32 position);
    void setPosition(edk::float32 posX,edk::float32 posY);
    //set the color of the tile
    void setColor(edk::color4f32 color);
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    //set the material color
    void setAmbient(edk::color4f32 color);
    void setAmbient(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setDiffuse(edk::color4f32 color);
    void setDiffuse(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setSpecular(edk::color4f32 color);
    void setSpecular(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setEmission(edk::color4f32 color);
    void setEmission(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setShininess(edk::float32 shininess);

    //set the rectangle of the tile
    void setRect(edk::rectf32 rect);
    void setRect(edk::vec2f32 position, edk::size2f32 size);
    void setRect(edk::float32 posX,edk::float32 posY,edk::float32 sizeX,edk::float32 sizeY);

    //Set the UV map for the tile
    void setRectUV(edk::rectf32 rect);
    void setRectUV(edk::vec2f32 position, edk::size2f32 size);
    void setRectUV(edk::float32 posX,edk::float32 posY,edk::float32 sizeX,edk::float32 sizeY);

    //set the rectangle of the tile
    void setFrame(edk::rectf32 frame);
    void setFrame(edk::vec2f32 position, edk::size2f32 size);
    void setFrame(edk::float32 posX,edk::float32 posY,edk::float32 sizeX,edk::float32 sizeY);

    //Set the frame UV cut
    void setFramesUV(edk::vec2ui32 frames);
    void setFramesUV(edk::uint32 x,edk::uint32 y);
    //select frameUV
    void useFrameUV(edk::vec2ui32 frame);
    void useFrameUV(edk::uint32 x,edk::uint32 y);
    void useFrameUVinPosition(edk::uint32 position);

    //Set the tileImage
    bool loadImage(const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadImage(edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //set the tileImage from memory
    bool loadImageFromMemory(const edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadImageFromMemory(edk::char8* name,edk::uint8* image,edk::uint32 size,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    //set the tileImage from the pack
    bool loadImageFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);
    bool loadImageFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter = GU_LINEAR,edk::uint32 magFilter = GU_NEAREST);

    //Get the size of the Tile
    edk::size2f32 getSize();
    edk::float32 getWidth();
    edk::float32 getHeight();
    edk::vec2f32 getPosition();
    edk::float32 getPositionX();
    edk::float32 getPositionY();

    //callback to start and end draw tile
    bool addDrawCallback(edk::tiles::DrawTile2DCallback* callback);
    bool removeDrawCallback(edk::tiles::DrawTile2DCallback* callback);
    void runStartDraw(edk::uint32 id,edk::vec2ui32 position,edk::vec2f32 worldPosition);
    void runEndDraw(edk::uint32 id,edk::vec2ui32 position,edk::vec2f32 worldPosition);

    //Add a interpolation to the animation
    bool addFrameInterpolation(edk::float32 second,edk::float32 frame);
    //return the interpolation size
    edk::uint32 getInterpolationSize();
    //clean frames
    bool cleanFames();
    //controls
    bool playForward();
    bool playForwardIn(edk::float32 second);
    bool playRewind();
    bool playRewindIn(edk::float32 second);
    bool pause();
    bool pauseOn();
    bool pauseOff();
    bool stop();
    //set loop
    bool setLoop(bool loop);
    bool loopOn();
    bool loopOff();
    //get the second
    edk::float32 getSecond();
    //return if are playing
    bool isPlaying();
    bool isPlayingName(const edk::char8* name);
    bool isPlayingName(edk::char8* name);
    bool wasPlayingName(const edk::char8* name);
    bool wasPlayingName(edk::char8* name);
    //animationNames
    bool addAnimationName(const edk::char8* name, edk::float32 start,edk::float32 end);
    bool addAnimationName(edk::char8* name, edk::float32 start,edk::float32 end);
    //test if have the animationName
    bool haveAnimationName(const edk::char8* name);
    bool haveAnimationName(edk::char8* name);
    //Play the animationName
    bool playNameForward(const edk::char8* name);
    bool playNameForward(edk::char8* name);
    bool playNameRewind(const edk::char8* name);
    bool playNameRewind(edk::char8* name);
    //remove the animationName
    bool removeAnimationName(const edk::char8* name);
    bool removeAnimationName(edk::char8* name);

    //Set one interpolation X as a curve
    bool setCurveX(edk::uint32 position);
    bool setNotCurveX(edk::uint32 position);
    bool getIsCurveX(edk::uint32 position);
    //Set the interpolation curve points
    bool setCurveP1X(edk::uint32 position,edk::float32 second,edk::float32 x);
    bool setCurveP2X(edk::uint32 position,edk::float32 second,edk::float32 x);

    //get mesh pointer
    edk::shape::Mesh2D* getMeshPointer();

    //create a new object physics
    bool setPhysics(edk::TypeObject type);
    //add a polygon to the physics Object
    bool addPhysicsPolygon(edk::shape::Polygon2D poly);
    bool cleanPhysicsPolygons();
    //delete the objectPhysics
    void deletePhysics();
    //return the physicsObject
    edk::physics2D::PhysicObject2D* getPhysicsObject();
    //return the physicsMesh
    edk::physics2D::PhysicsMesh2D* getPhysicsMeshPointer();
    //return true if the tile is Physics
    bool isPhysics();


    //update the animation
    void updateAnimation();
    void updateAnimation(edk::float32 seconds);


    //XML
    bool writeToXML(edk::XML* xml,edk::uint32 id);
    bool readFromXML(edk::XML* xml,edk::uint32 id);
    bool readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id);

    //Draw the tile
    void draw(edk::float32 angle=0.f,edk::size2f32 size = edk::size2f32(1,1));
    void drawWithoutMaterial(edk::float32 angle=0.f,edk::size2f32 size = edk::size2f32(1,1));
    void drawWire(edk::float32 angle=0.f,edk::size2f32 size = edk::size2f32(1,1));
    void drawSelection(edk::float32 angle=0.f,edk::size2f32 size = edk::size2f32(1,1));
    void drawPhysic(edk::float32 angle=0.f,edk::size2f32 size = edk::size2f32(1,1));
protected:
    //A tile have an object
    edk::Object2D obj;
    //physics object
    edk::physics2D::PhysicObject2D* objPhys;
    //save the tile size
    edk::size2f32 tileSize;
    //save if add a polygon
    bool addedPhysicsPolygon;
    //and one mesh to draw
    edk::shape::Mesh2D mesh;
    //calcula o ponto medio do tile
    edk::vec2f32 middle;
    //select or create the animation for the polygon zero
    void selectAnimation();

    //binary tree to save the callback functions to init and end draw the tile
    class TreeTileDraw : public edk::vector::BinaryTree<edk::tiles::DrawTile2DCallback*>{
    public:
        TreeTileDraw(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~TreeTileDraw(){
            this->Destructor();
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::tiles::DrawTile2DCallback*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
            edk::vector::BinaryTree<edk::tiles::DrawTile2DCallback*>::Destructor();
        }

        //Print
        virtual void printElement(edk::tiles::DrawTile2DCallback* value){
            value->startDrawTile(this->id,this->position,this->worldPosition);
        }
        virtual void renderElement(edk::tiles::DrawTile2DCallback* value){
            value->endDrawTile(this->id,this->position,this->worldPosition);
        }
        void runStart(edk::uint32 id,edk::vec2ui32 position,edk::vec2f32 worldPosition){
            this->id=id;
            this->position=position;
            this->worldPosition=worldPosition;
            this->print();
        }
        void runEnd(edk::uint32 id,edk::vec2ui32 position,edk::vec2f32 worldPosition){
            this->id=id;
            this->position=position;
            this->worldPosition=worldPosition;
            this->render();
        }
        edk::uint32 id;
        edk::vec2ui32 position;
        edk::vec2f32 worldPosition;
    private:
        edk::classID classThis;
    }treeDraw;
private:
    edk::classID classThis;
};
}//end namespace tiles
}//end namespace edk

#endif // TILE2D_H
