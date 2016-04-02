#include "ViewSpriteController.h"

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
#warning "            Inside ViewSpriteController.cpp"
#endif

edk::ViewSpriteController::ViewSpriteController()
{
    //ctor
    this->spriteCode=0u;
    this->spriteFilter=0u;
}

edk::ViewSpriteController::~ViewSpriteController()
{
    //dtor
    this->deleteSprite();
}

//create a new sprite
bool edk::ViewSpriteController::createSprite(const char* name,edk::size2ui32 size, edk::uint32 mode,edk::uint32 filter){
    return this->createSprite((edk::char8*) name,size,mode,filter);
}
bool edk::ViewSpriteController::createSprite(edk::char8* name,edk::size2ui32 size, edk::uint32 mode,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();
    //test the name
    if(name && size.width && size.height){
        //then load the texture
        this->spriteCode = this->list.createTexture(name,size,mode,filter);
        this->spriteFilter=filter;
        if(this->spriteCode) return true;
    }

    //else return false
    return false;
}
bool edk::ViewSpriteController::createSprite(const char* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode,edk::uint32 filter){
    return this->createSprite((edk::char8*) name,width,height, mode,filter);
}
bool edk::ViewSpriteController::createSprite(edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode,edk::uint32 filter){
    return this->createSprite(name,edk::size2ui32(width,height), mode,filter);
}
//draw sprite
bool edk::ViewSpriteController::drawSprite(edk::uint8* sprite,edk::uint32 filter){
    //test if have the sprite
    if(this->spriteCode){
        //draw the sprite
        return this->list.drawTexture(this->spriteCode,sprite,filter);
    }
    return false;
}
//load the sprite
bool edk::ViewSpriteController::loadSprite(const char* name,edk::uint32 filter){
    //
    return this->loadSprite((edk::char8*) name,filter);
}
bool edk::ViewSpriteController::loadSprite(edk::char8* name,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();
    //test the name
    if(name){
        //then load the texture
        this->spriteCode = this->list.loadTexture(name,filter);
        this->spriteFilter=filter;
        if(this->spriteCode) return true;
    }

    //else return false
    return false;
}
//load the sprite from memory
bool edk::ViewSpriteController::loadSpriteFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpriteFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::ViewSpriteController::loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();
    //test the name
    if(name && sprite && size){
        //then load the texture
        this->spriteCode = this->list.loadTextureFromMemory(name,sprite,size,filter);
        this->spriteFilter=filter;
        if(this->spriteCode) return true;
    }

    //else return false
    return false;
}

//Delete the sprite
void edk::ViewSpriteController::deleteSprite(){
    //
    if(this->spriteCode){
        //
        this->list.removeTexture(this->spriteCode);
    }
    this->spriteCode = 0u;
    this->spriteFilter = 0u;
}

//draw the polygon on the scene
void edk::ViewSpriteController::drawPolygon(rectf32 outsideViewOrigin){
    //
    //edk::View::drawPolygon();

    //draw the polygon with UV Map
    edk::GU::guUseMatrix(GU_MODELVIEW);

    //texture
    edk::GU::guEnable(GU_TEXTURE_2D);

    edk::GU::guUseTexture2D(this->spriteCode);

    //Draw a quadrangle
    edk::GU::guBegin(GU_QUADS);
    edk::GU::guVertexTex2f32(0.f, 1.f);
    edk::GU::guVertex3f32(0.f, 0.f, 0.f);

    edk::GU::guVertexTex2f32(0.f, 0.f);
    edk::GU::guVertex3f32(0.f, 1.f, 0.f);

    edk::GU::guVertexTex2f32(1.f, 0.f);
    edk::GU::guVertex3f32(1.f, 1.f, 0.f);

    edk::GU::guVertexTex2f32(1.f, 1.f);
    edk::GU::guVertex3f32(1.f, 0.f, 0.f);
    edk::GU::guEnd();

    edk::GU::guUseTexture2D(0u);
    edk::GU::guDisable(GU_TEXTURE_2D);
}

//draw
void edk::ViewSpriteController::draw(rectf32 outsideViewOrigin){
    //
    edk::ViewController::draw(outsideViewOrigin);
}
