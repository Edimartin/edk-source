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

    //load the button textures and meshes
    virtual bool load();
    virtual void unload();
    virtual void update();

    //set border size
    bool setBorderSize(edk::float32 size);

    //draw the button
    virtual void draw();
    //button frame in the world
    edk::rectf32 frame;
protected:
    void drawStart();
    void drawEnd();
    edk::gui2d::ObjectGui2dBorder obj;
    //image inside the button
    edk::shape::Mesh2D sprite;
    //save the size
    edk::size2f32 sizeS;
    edk::shape::Rectangle2D center;
    edk::shape::Rectangle2D centerS;
    edk::shape::Rectangle2D spritePolygon;
    //sprite size
    edk::size2ui32 spriteSize[edk::gui2d::gui2dTextureSize];
    //temp
    edk::float32 percent1;
    edk::float32 percent2;
    edk::float32 resize;
private:
};
}//end namespace gui2d
}//end namespace edk

#endif // OBJECT_H
