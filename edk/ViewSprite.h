#ifndef EDK_VIEWSPRITE_H
#define EDK_VIEWSPRITE_H

/*
Library C++ viewSprite - Render an image inside this view in Edk Game Engine
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
#warning "Inside ViewSprite"
#endif

//ViewSprite draw a texture in a view
#pragma once
#include "View.h"
#include "Texture2DList.h"
#include "pack/FilePackage.h"

#ifdef printMessages
#warning "    Compiling ViewSprite"
#endif

namespace edk{
class ViewSprite :public edk::View{
public:
    ViewSprite();
    virtual ~ViewSprite();

    //create a new sprite
    bool createSprite(const edk::char8* name,edk::size2ui32 size, edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool createSprite(edk::char8* name,edk::size2ui32 size, edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool createSprite(const edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    bool createSprite(edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode = GU_RGB,edk::uint32 filter = GU_NEAREST);
    //draw sprite
    bool drawSprite(edk::uint8* sprite,edk::uint32 filter = GU_NEAREST);
    //load the sprite
    bool loadSprite(const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSprite(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    //load the sprite from memory
    bool loadSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    //set sprite from memory
    bool setSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter = GU_NEAREST);
    bool setSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter = GU_NEAREST);
    //load the sprite
    bool loadSpriteFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter = GU_NEAREST);

    //Delete the sprite
    void deleteSprite();
    //return the spriteSize
    edk::size2ui32 getSpriteSize();

    //draw
    virtual void draw(rectf32 outsideViewOrigin);
protected:
    //Draw Functions
    //draw viewPort
    //virtual void drawViewport(rectf32 outsideViewOrigin);
    //draw Camera
    //virtual void drawCamera();
    //draw the polygon on the scene
    virtual void drawPolygon(rectf32 outsideViewOrigin);
    //get the spriteCode
    edk::uint32 getSpriteCode();
private:
    //textures list
    edk::Texture2DList list;
    //sprite
    edk::uint32 spriteCode;
    edk::uint32 spriteFilter;
    edk::size2ui32 spriteSize;
};
}//end namespace edk

#endif // VIEWSPRITE_H
