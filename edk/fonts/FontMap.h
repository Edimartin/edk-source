#ifndef FONTMAP_H
#define FONTMAP_H

/*
Library FontMap - Tile Map for Font Set to show text
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

#pragma once
#include "FontSet.h"
#include "../tiles/TileMap2D.h"
#include "../vector/Stack.h"
//Animation
#include "../animation/Interpolation1DGroup.h"

namespace edk{
namespace fonts{
class FontMap;
class FontCallback{
public:
    virtual void originFoundEnd()=0;
    virtual void lastFoundEnd()=0;
    virtual void animationEnd(edk::fonts::FontMap* text,bool isOrigin)=0;
};

class FontMap : public edk::animation::AnimationCallback{
public:
    FontMap();
    virtual ~FontMap();

    //SET
    void setPosition(edk::vec2f32 position);
    void setPosition(edk::float32 x,edk::float32 y);
    void setScale(edk::size2f32 scale);
    void setScale(edk::float32 width,edk::float32 height);

    //GET
    edk::vec2f32 getPosition();
    edk::float32 getPositionX();
    edk::float32 getPositionY();
    //get size of the map
    edk::size2ui32 getMapSize();
    edk::uint32 getMapSizeWidth();
    edk::uint32 getMapSizeHeight();
    //get the mapScale
    edk::size2f32 getMapScale();
    edk::float32 getMapScaleWidth();
    edk::float32 getMapScaleHeight();
    //return the last position
    edk::vec2ui32 getTheLastPosition();
    edk::uint32 getTheLastPositionX();
    edk::uint32 getTheLastPositionY();

    //load fontImage
    bool loadFontImage(const char* name,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    bool loadFontImage(edk::char8* name,edk::uint32 filter = GU_NEAREST,edk::color4f32 color = edk::color4f32(1,1,1,1));
    bool loadFontImageFromMemory(const char* name,
                                 edk::uint8* image,
                                 edk::uint32 size,
                                 edk::uint32 filter = GU_NEAREST,
                                 edk::color4f32 color = edk::color4f32(1,1,1,1)
            );
    bool loadFontImageFromMemory(edk::char8* name,
                                 edk::uint8* image,
                                 edk::uint32 size,
                                 edk::uint32 filter = GU_NEAREST,
                                 edk::color4f32 color = edk::color4f32(1,1,1,1)
            );

    //create the string
    bool createStringMap(const char* str,edk::uint32 width);
    bool createStringMap(edk::char8* str,edk::uint32 width);
    bool createStringMap(const char* str);
    bool createStringMap(edk::char8* str);

    //delete tileMap
    void deleteMap();
    //return true if have a text
    bool haveText();

    //add callback
    bool addCallback(edk::fonts::FontCallback* callback);
    bool removeCallback(edk::fonts::FontCallback* callback);
    //cleanCallacks
    void cleanCallbacks();

    //Select characters to draw
    void selectAll();

    //add animations
    bool addInterpolation(edk::float32 second,edk::uint32 originID, edk::uint32 lastID);
    bool addInterpolation(edk::float32 second,edk::vec2ui32 origin, edk::vec2ui32 last);
    bool addInterpolation(edk::float32 second,edk::uint32 originX,edk::uint32 originY,edk::uint32 lastX,edk::uint32 lastY);
    bool addInterpolationOrigin(edk::float32 second,edk::uint32 ID);
    bool addInterpolationOrigin(edk::float32 second,edk::vec2ui32 origin);
    bool addInterpolationOrigin(edk::float32 second,edk::uint32 originX,edk::uint32 originY);
    bool addInterpolationLast(edk::float32 second,edk::uint32 ID);
    bool addInterpolationLast(edk::float32 second,edk::vec2ui32 last);
    bool addInterpolationLast(edk::float32 second,edk::uint32 lastX,edk::uint32 lastY);

    //Set animation speed
    void setAnimationSpeedOrigin(edk::float32 speed);
    //set faster
    void setAtimationFasterSpeedOrigin(edk::float32 faster);
    //speed
    void setAnimationSpeedLast(edk::float32 speed);
    //set faster
    void setAtimationFasterSpeedLast(edk::float32 faster);

    //CONTROLS
    //animation controllers
    void playForward();
    void playForwardIn(edk::float32 second);
    void playRewind();
    void playRewindIn(edk::float32 second);
    void pause();
    void stop();
    //set loop
    void setLoop(bool loop);
    void loopOn();
    void loopOff();

    //Force speed for the next update
    void forceSpeedInOrigin(edk::float32 speed);
    void forceSpeedInLast(edk::float32 speed);
    //update animations
    bool updateAnimations();

    //draw the text
    void draw(edk::color4f32 color);
    void draw();

    //remove the fontImage
    void removeFontImage();

    void animationEnd(edk::animation::InterpolationGroup* animation);


    //animation position
    edk::animation::Interpolation2DGroup animationPosition;
    edk::animation::Interpolation2DGroup animationSize;
private:
    edk::tiles::TileMap2D map;
    edk::fonts::fontSetList list;
    edk::fonts::FontSet* set;

    edk::color4f32 color;

    //positions to draw
    edk::uint32 originID;
    edk::uint32 lastID;
    edk::vec2ui32 origin;
    edk::vec2ui32 last;
    //force animation speed
    bool forceSpeedOrigin;
    bool forceSpeedLast;
    float forceSpeedOriginValue;
    float forceSpeedLastValue;

    //interpolation to select what characters to draw
    edk::animation::Interpolation1DGroup animOrigin;
    edk::animation::Interpolation1DGroup animLast;
    edk::float32 speedOrigin;
    edk::float32 fasterOrigin;
    edk::float32 speedLast;
    edk::float32 fasterLast;
    //found enter in origin or last
    bool enterOrigin;
    bool enterLast;

    //FontsCallback tree
    edk::vector::BinaryTree<edk::fonts::FontCallback*> treeCallbacks;

    class FontLine{
    public:
        FontLine(edk::uint32 size);
        ~FontLine();

        //get the size
        edk::uint32 getSize();
        //return true if have the line
        bool haveLine();
        //set the value
        bool setValue(edk::uint32 position,edk::uint32 value);
        //get the value
        edk::uint32 getValue(edk::uint32 position);
        //test if have position
        bool havePosition(edk::uint32 position);
    private:
        edk::uint32 size;
        edk::uint32* line;
    };

    //stack with the lines
    edk::vector::Stack<edk::fonts::FontMap::FontLine *> lines;
    //maxLine
    edk::uint32 maxSizeLine;

    //gete the tileID
    edk::uint32 getTileID(edk::char8* str,edk::uint8* jump);
    //return the wordSize
    edk::uint32 wordSize(edk::char8* str);
    //return the lineSize
    edk::uint32 lineSize(edk::char8* str);
    //clean lines
    void cleanLines();
    //create new line
    edk::fonts::FontMap::FontLine* newLine(edk::uint32 size);
    //copy the text to the map
    bool copyLinesToMap();
    //test if have the ID
    bool haveID(edk::uint32 ID);
    //get position of the tile
    edk::vec2ui32 getCharacterPosition(edk::uint32 ID);
    edk::uint32 getCharacterID(edk::vec2ui32 position);

    //Draw
    void draw(edk::vec2ui32 origin,edk::vec2ui32 last,edk::color4f32 color=edk::color4f32(1,1,1,1));
    void draw(edk::uint32 originWidth,edk::uint32 originLine,edk::uint32 lastWidth,edk::uint32 lastLine,edk::color4f32 color=edk::color4f32(1,1,1,1));
    //draw the ID
    void draw(edk::uint32 originID,edk::uint32 lastID,edk::color4f32 color=edk::color4f32(1,1,1,1));
    void draw(edk::vec2ui32 origin,edk::uint32 lastID,edk::color4f32 color=edk::color4f32(1,1,1,1));
    void draw(edk::uint32 originID,edk::vec2ui32 last,edk::color4f32 color=edk::color4f32(1,1,1,1));
};
}//end namespace fonts
}//end namespace edk

#endif // FONTMAP_H