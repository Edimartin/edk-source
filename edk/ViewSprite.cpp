#include "ViewSprite.h"

/*
Library C++ viewSprite - Render an image inside this view in Edk Game Engine
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
#pragma message "            Inside ViewSprite.cpp"
#endif

edk::ViewSprite::ViewSprite(){
    this->classThis=NULL;
    this->Constructor();
}

edk::ViewSprite::~ViewSprite(){
    this->Destructor();
}

void edk::ViewSprite::Constructor(){
    edk::View::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        this->spriteCode=0u;
        this->spriteFilter=0u;
        this->spriteSize = edk::size2ui32(0u,0u);
        this->spriteUV = 1.f;
    }
}
void edk::ViewSprite::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //remove the texture
        this->deleteSprite();
    }
    edk::View::Destructor();
}

//create a new sprite
bool edk::ViewSprite::createSprite(const edk::char8* name,edk::size2ui32 size, edk::uint32 mode,edk::uint32 filter){
    return this->createSprite((edk::char8*) name,size, mode,filter);
}
bool edk::ViewSprite::createSprite(edk::char8* name,edk::size2ui32 size, edk::uint32 mode,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();
    //test the name
    if(name && size.width && size.height){
        //then load the texture
        this->spriteCode = this->list.createTexture(name,size,mode,filter);
        this->spriteFilter=filter;
        if(this->spriteCode){
            this->spriteSize = this->list.getTextureSize(this->spriteCode);
            return true;
        }
    }

    //else return false
    return false;
}
bool edk::ViewSprite::createSprite(const edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode,edk::uint32 filter){
    return this->createSprite((edk::char8*)name,width,height,mode,filter);
}
bool edk::ViewSprite::createSprite(edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode,edk::uint32 filter){
    return this->createSprite(name,edk::size2ui32(width,height), mode,filter);
}
//draw sprite
bool edk::ViewSprite::drawSprite(edk::uint8* sprite,edk::uint32 filter){
    //test if have the sprite
    if(this->spriteCode){
        //draw the sprite
        return this->list.drawTexture(this->spriteCode,sprite,filter);
    }
    return false;
}
//load the sprite
bool edk::ViewSprite::loadSprite(const edk::char8* name,edk::uint32 filter){
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
bool edk::ViewSprite::loadSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
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
//set sprite from memory
bool edk::ViewSprite::setSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();
    //test the name
    if(name && sprite && width && height){
        //then load the texture
        this->spriteCode = this->list.setTextureFromMemory(name,sprite,width,height,channels,filter);
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
bool edk::ViewSprite::setSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter){
    return setSpriteFromMemory((edk::char8*) name,sprite,width,height,channels,filter);
}
//load the sprite
bool edk::ViewSprite::loadSpriteFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSpriteFromPack(pack,(edk::char8*) name,filter);
}
bool edk::ViewSprite::loadSpriteFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();
    //test the name
    if(name && pack){
        //then load the texture
        this->spriteCode = this->list.loadTextureFromPack(pack,name,filter);
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

//Set UV
bool edk::ViewSprite::setSpriteUV(edk::vec2f32 uv){
    if(uv.x>0.f && uv.y>0.f){
        this->spriteUV = uv;
        return true;
    }
    return false;
}
bool edk::ViewSprite::setSpriteUV(edk::float32 u,edk::float32 v){
    return this->setSpriteUV(edk::vec2f32(u,v));
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
    edk::GU::guVertexTex2f32(0.f, this->spriteUV.y);
    edk::GU::guVertex3f32(0.f, 0.f, 0.f);

    edk::GU::guVertexTex2f32(0.f, 0.f);
    edk::GU::guVertex3f32(0.f, 1.f, 0.f);

    edk::GU::guVertexTex2f32(this->spriteUV.x, 0.f);
    edk::GU::guVertex3f32(1.f, 1.f, 0.f);

    edk::GU::guVertexTex2f32(this->spriteUV.x, this->spriteUV.y);
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
