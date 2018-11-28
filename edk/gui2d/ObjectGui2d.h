#ifndef OBJECT_H
#define OBJECT_H

/*
ObjectGui2d - Object for the GUI 2D library
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
#warning "Inside gui2d::ObjectGui2d"
#endif

#pragma once
#include "../Object2DValues.h"
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../ViewSprite.h"
#include "../vector/BinaryTree.h"
#include "../fonts/FontMap.h"
#include "../NameClass.h"
#include "ObjectGui2dBorder.h"

#ifdef printMessages
#warning "    Compiling gui2d::ObjectGui2d"
#endif

namespace edk{
namespace gui2d{
class ObjectGui2d: public edk::Object2DValues{
public:
    ObjectGui2d();
    ~ObjectGui2d();

    //LOAD SPRITES
    bool loadSprite(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSprite(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    void removeSprite();
    //load pressed sprite
    bool loadSpritePressed(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressed(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    void removeSpritePressed();
    //load UP sprite
    bool loadSpriteUp(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUpFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    void removeSpriteUp();
    //load UP sprite
    bool loadSpritePressedUp(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUpFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    void removeSpritePressedUp();

    //Load button symbol normal
    bool loadSymbol(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbol(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    void removeSymbol();
    //Load button symbol pressed
    bool loadSymbolPressed(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressed(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    void removeSymbolPressed();
    //Load button symbol up
    bool loadSymbolUp(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolUpFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    void removeSymbolUp();
    //Load button symbol pressedUp
    bool loadSymbolPressedUp(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedUpFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    void removeSymbolPressedUp();
    //Load button symbolAllStatus normal
    bool loadSymbolAllStatus(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllStatus(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllStatusFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    //Load button symbolAllUPStatus normal
    bool loadSymbolAllUPStatus(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllUPStatus(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllUPStatusFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllUPStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    //Load button symbolAllUPStatus normal
    bool loadSymbolAllNormalAndPressedStatus(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatus(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatusFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);

    bool writeText(const char* text);
    bool writeText(edk::char8* text);
    bool writeText(const char* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool writeText(const char* text,edk::size2f32 scale);
    bool writeText(edk::char8* text,edk::size2f32 scale);
    void cleanText();

    //load the button textures and meshes
    virtual bool load();
    virtual void unload();
    virtual void update();
    virtual bool setStatus(edk::gui2d::gui2dTexture status);
    void forceUpdate();
    edk::gui2d::gui2dTexture getStatus();

    //set border size
    bool setBorderSize(edk::float32 size);

    //draw the button
    virtual void draw();
    virtual void drawSelection();
    //return true if the object can be moved
    virtual bool canMove();
    //button frame in the world
    edk::rectf32 frame;
    bool pressed;
protected:
    void drawStart();
    void drawEnd();
    void updateTextSize();
    edk::gui2d::ObjectGui2dBorder obj;
    //image inside the button
    edk::shape::Mesh2D sprite;
    //save the size
    edk::size2f32 sizeS;
    edk::float32 borderSizeS;
    edk::shape::Rectangle2D center;
    edk::shape::Rectangle2D centerS;
    edk::shape::Rectangle2D spritePolygon;
    //text to be printed in front
    edk::fonts::FontMap text;
    bool drawText;
    edk::size2f32 textSize;
    //sprite size
    edk::size2ui32 spriteSize[edk::gui2d::gui2dTextureSize];
    //temp
    edk::float32 percent1;
    edk::float32 percent2;
    edk::float32 resize;
    //object status
    edk::gui2d::gui2dTexture status;
    //save the object status to compare in update function
    edk::gui2d::gui2dTexture saveStatus;
private:
};
}//end namespace gui2d
}//end namespace edk

#endif // OBJECT_H
