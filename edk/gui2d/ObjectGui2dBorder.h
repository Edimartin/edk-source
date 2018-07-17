#ifndef OBJECTBORDER_H
#define OBJECTBORDER_H

/*
ObjectBorder - Border used for the GUI 2D library
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
#warning "Inside ObjectBorder"
#endif

#pragma once
#include "../TypeDefines.h"
#include "../GU/GU.h"
#include "../vector/BinaryTree.h"
#include "../shape/Mesh2D.h"

#ifdef printMessages
#warning "    Compiling ObjectBorder"
#endif



namespace edk{
namespace gui2d{
enum gui2dTexture{
    gui2dTextureNormal=0u,
    gui2dTextureUp,
    gui2dTexturePressed,
    //
    gui2dTextureSize,
};
class ObjectGui2dBorder{
    public:
    ObjectGui2dBorder();
    ~ObjectGui2dBorder();

    //LOAD SPRITES
    bool loadSpriteNormal(const char* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteNormal(edk::char8* name,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteNormalFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    bool loadSpriteNormalFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter = GU_NEAREST);
    void removeSpriteNormal();
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

    //load the polygons
    bool updatePolygons(edk::size2f32 size);

    //set the borderSize
    bool setBorderSize(edk::float32 size);

    //return the center rectangle
    edk::shape::Rectangle2D* getCenter();


    //load the objectBorder
    bool load(edk::size2f32 size);
    //unload the objectBorder
    void unload();

    //draw the object
    void drawNormal();
    void drawUp();
    void drawPressed();
    private:
    edk::shape::Mesh2D mesh;
    edk::shape::Rectangle2D center;
    edk::float32 border;
};
}//end namespace gui2d
}//end namespace edk

#endif // OBJECTBORDER_H
