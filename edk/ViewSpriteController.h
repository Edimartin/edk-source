#ifndef EDK_VIEWSPRITECONTROLLER_H
#define EDK_VIEWSPRITECONTROLLER_H

/*
Library C++ viewSpriteControler - Render an image, and other views, inside this view in Edk Game Engine
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
#warning "Inside ViewController"
#endif

#pragma once
#include "ViewController.h"
#include "Texture2DList.h"

#ifdef printMessages
#warning "    Compiling ViewController"
#endif

namespace edk{
class ViewSpriteController :public edk::ViewController{
public:
    ViewSpriteController();
    virtual ~ViewSpriteController();

    //load the sprite
    bool loadSprite(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSprite(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    //load the sprite from memory
    bool loadSpriteFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);

    //Delete the sprite
    void deleteSprite();

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
    //sprite
    edk::uint32 spriteCode;
private:
    //textures list
    edk::Texture2DList list;
    edk::uint32 spriteFilter;
};
}//end namespace

#endif // VIEWSPRITECONTROLLER_H