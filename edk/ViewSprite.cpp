#include "ViewSprite.h"

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
#warning "            Inside ViewSprite.cpp"
#endif

edk::ViewSprite::ViewSprite()
{
    //ctor
    this->spriteCode=0u;
    this->spriteFilter=0u;
    this->spriteSize = edk::size2ui32(0u,0u);
}

edk::ViewSprite::~ViewSprite()
{
    //remove the texture
    this->deleteSprite();
}

//load the sprite
bool edk::ViewSprite::loadSprite(const char* name,edk::uint32 filter){
    //
    return this->loadSprite((edk::char8*) name,filter);
}
bool edk::ViewSprite::loadSprite(edk::char8* name,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();
    //test the name
    if(name){
        //then load the texture
        this->spriteCode = this->list.loadTexture(name,filter);
        this->spriteFilter = filter;
        if(this->spriteCode){
            this->spriteSize = this->list.getTextureSize(this->spriteCode);
            return true;
        }
    }
    this->spriteFilter = 0u;

    //else return false
    return false;
}
//load the sprite from memory
bool edk::ViewSprite::loadSpriteFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpriteFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::ViewSprite::loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();
    //test the name
    if(name && sprite && size){
        //then load the texture
        this->spriteCode = this->list.loadTextureFromMemory(name,sprite,size,filter);
        this->spriteFilter = filter;
        if(this->spriteCode){
            this->spriteSize = this->list.getTextureSize(this->spriteCode);
            return true;
        }
    }
    this->spriteFilter = 0u;

    //else return false
    return false;
}

//Delete the sprite
void edk::ViewSprite::deleteSprite(){
    //
    if(this->spriteCode){
        //
        this->list.removeTexture(this->spriteCode);
    }
    this->spriteCode=0u;
    this->spriteFilter=0u;
    this->spriteSize = edk::size2ui32(0u,0u);
}
//return the spriteSize
edk::size2ui32 edk::ViewSprite::getSpriteSize(){
    return this->spriteSize;
}

//draw the polygon on the scene
void edk::ViewSprite::drawPolygon(rectf32){
    //
    //edk::View::drawPolygon();

    //draw the polygon with UV Map
    edk::GU::guUseMatrix(GU_MODELVIEW);

    //Set the polygon Color
    edk::GU::guColor4f32(this->backgroundColor);

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
//get the spriteCode
edk::uint32 edk::ViewSprite::getSpriteCode(){
    return this->spriteCode;
}

//draw
void edk::ViewSprite::draw(rectf32 outsideViewOrigin){
    //
    edk::View::draw(outsideViewOrigin);
}