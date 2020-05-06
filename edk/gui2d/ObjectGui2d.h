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
#include "../pack/FilePackage.h"
#include "ObjectGui2dBorder.h"

#ifdef printMessages
#warning "    Compiling gui2d::ObjectGui2d"
#endif

namespace edk{
namespace gui2d{
enum gui2dTypes{
    gui2dTypeObject=0u,
    gui2dTypeButton,
    gui2dTypeScrollBar,
    gui2dTypeMenu,
    gui2dTypeText,
    gui2dTypeTextField,
    //
    gui2dTypeSize,
};
class ObjectGui2d: public edk::Object2DValues{
public:
    ObjectGui2d();
    ~ObjectGui2d();

    //get the type
    virtual edk::gui2d::gui2dTypes getType();

    //LOAD SPRITES
    bool loadSprite(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSprite(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSprite();
    //load pressed sprite
    bool loadSpritePressed(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressed(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSpritePressed();
    //load UP sprite
    bool loadSpriteUp(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSpriteUp();
    //load UP sprite
    bool loadSpritePressedUp(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpritePressedUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSpritePressedUp();

    //Load button symbol normal
    bool loadSymbol(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbol(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSymbol();
    //Load button symbol pressed
    bool loadSymbolPressed(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressed(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSymbolPressed();
    //Load button symbol up
    bool loadSymbolUp(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSymbolUp();
    //Load button symbol pressedUp
    bool loadSymbolPressedUp(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedUp(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolPressedUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    void removeSymbolPressedUp();
    //Load button symbolAllStatus normal
    bool loadSymbolAllStatus(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllStatus(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    //Load button symbolAllUPStatus normal
    bool loadSymbolAllUPStatus(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllUPStatus(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllUPStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllUPStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllUPStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllUPStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);
    //Load button symbolAllUPStatus normal
    bool loadSymbolAllNormalAndPressedStatus(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatus(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSymbolAllNormalAndPressedStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);

    //set the color
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a);
    void setColor(edk::float32 r,edk::float32 g,edk::float32 b);
    void setColor(edk::color4f32 color);
    void setColor(edk::color3f32 color);

    bool writeText(const edk::char8* text);
    bool writeText(edk::char8* text);
    bool writeText(const edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight);
    bool writeText(const edk::char8* text,edk::size2f32 scale);
    bool writeText(edk::char8* text,edk::size2f32 scale);
    void cleanText();

    //load the button textures and meshes
    virtual bool load();
    virtual void unload();
    virtual void update();
    virtual void startMove(edk::vec2f32 mousePosition);
    virtual void moveTo(edk::vec2f32 position);
    virtual void cancelMove();
    virtual bool setStatus(edk::gui2d::gui2dTexture status);
    void forceUpdate();
    virtual edk::gui2d::gui2dTexture getStatus();
    //select functions
    virtual void select();
    virtual void deselect();
    bool isSelected();
    //click to select an polygon inside the object
    virtual void clickStart(edk::uint32 name);
    virtual void clickMove(edk::uint32 name,bool mouseInside);
    virtual void clickEnd(edk::uint32 name,bool mouseInside,bool doubleClick);

    //set border size
    virtual bool setBorderSize(edk::float32 size);

    //draw the button
    virtual void draw();
    virtual void drawSelection();
    //return true if the object can be moved
    virtual bool canMove();
    //button frame in the world
    bool pressed;
protected:
    void drawStart();
    void drawEnd();
    void runTextSize();
    virtual void updateTextSize(edk::size2f32 sizeText,edk::size2f32 centerSize,edk::size2ui32 mapSize);
    edk::gui2d::ObjectGui2dBorder obj;
    //save if the obj is selected
    bool selected;
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
    //save the position to move the object
    edk::vec2f32 savePosition;
private:
};
}//end namespace gui2d
}//end namespace edk

#endif // OBJECT_H
