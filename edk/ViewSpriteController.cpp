#include "ViewSpriteController.h"

/*
Library C++ viewSpriteControler - Render an image, and other views, inside this view in Edk Game Engine
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
#pragma message "            Inside ViewSpriteController.cpp"
#endif

edk::ViewSpriteController::ViewSpriteController(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);edkEnd();
}

edk::ViewSpriteController::~ViewSpriteController(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->deleteSprite();edkEnd();
    }
}

void edk::ViewSpriteController::Constructor(bool runFather){
    if(runFather){
        edk::ViewController::Constructor();edkEnd();
    }
    if(this->classThis!=this){
        this->classThis=this;

        this->list.Constructor();edkEnd();

        this->spriteCode=0u;
        this->spriteFilter=0u;
        this->spriteSize = edk::size2ui32(0u,0u);edkEnd();
    }
}

//create a new sprite
bool edk::ViewSpriteController::createSprite(const edk::char8* name,edk::size2ui32 size, edk::uint32 mode,edk::uint32 filter){
    return this->createSprite((edk::char8*) name,size,mode,filter);edkEnd();
}
bool edk::ViewSpriteController::createSprite(edk::char8* name,edk::size2ui32 size, edk::uint32 mode,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();edkEnd();
    //test the name
    if(name && size.width && size.height){
        //then load the texture
        this->spriteCode = this->list.createTexture(name,size,mode,filter);edkEnd();
        this->spriteFilter=filter;edkEnd();
        if(this->spriteCode){
            this->spriteSize = this->list.getTextureSize(this->spriteCode);edkEnd();
            return true;
        }
    }

    //else return false
    return false;
}
bool edk::ViewSpriteController::createSprite(const edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode,edk::uint32 filter){
    return this->createSprite((edk::char8*) name,width,height, mode,filter);edkEnd();
}
bool edk::ViewSpriteController::createSprite(edk::char8* name,edk::uint32 width,edk::uint32 height, edk::uint32 mode,edk::uint32 filter){
    return this->createSprite(name,edk::size2ui32(width,height), mode,filter);edkEnd();
}
//draw sprite
bool edk::ViewSpriteController::drawSprite(edk::uint8* sprite,edk::uint32 filter){
    //test if have the sprite
    if(this->spriteCode){
        //draw the sprite
        return this->list.drawTexture(this->spriteCode,sprite,filter);edkEnd();
    }
    return false;
}
//load the sprite
bool edk::ViewSpriteController::loadSprite(const edk::char8* name,edk::uint32 filter){
    //
    return this->loadSprite((edk::char8*) name,filter);edkEnd();
}
bool edk::ViewSpriteController::loadSprite(edk::char8* name,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();edkEnd();
    //test the name
    if(name){
        //then load the texture
        this->spriteCode = this->list.loadTexture(name,filter);edkEnd();
        this->spriteFilter=filter;edkEnd();
        if(this->spriteCode){
            this->spriteSize = this->list.getTextureSize(this->spriteCode);edkEnd();
            return true;
        }
    }

    //else return false
    return false;
}
//load the sprite from memory
bool edk::ViewSpriteController::loadSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpriteFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::ViewSpriteController::loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();edkEnd();
    //test the name
    if(name && sprite && size){
        //then load the texture
        this->spriteCode = this->list.loadTextureFromMemory(name,sprite,size,filter);edkEnd();
        this->spriteFilter=filter;edkEnd();
        if(this->spriteCode){
            this->spriteSize = this->list.getTextureSize(this->spriteCode);edkEnd();
            return true;
        }
    }

    //else return false
    return false;
}
//set sprite from memory
bool edk::ViewSpriteController::setTextureFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();edkEnd();
    //test the name
    if(name && sprite && width && height){
        //then load the texture
        this->spriteCode = this->list.setTextureFromMemory(name,sprite,width,height,channels,filter);edkEnd();
        this->spriteFilter = filter;edkEnd();
        if(this->spriteCode){
            this->spriteSize = this->list.getTextureSize(this->spriteCode);edkEnd();
            return true;
        }
    }
    this->spriteFilter = 0u;edkEnd();

    //else return false
    return false;
}
bool edk::ViewSpriteController::setTextureFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 width,edk::uint32 height,edk::uint32 channels,edk::uint32 filter){
    return setTextureFromMemory((edk::char8*) name,sprite,width,height,channels,filter);edkEnd();
}
//load the sprite
bool edk::ViewSpriteController::loadSpriteFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSpriteFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::ViewSpriteController::loadSpriteFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    //delete the sprite
    this->deleteSprite();edkEnd();
    //test the name
    if(name && pack){
        //then load the texture
        this->spriteCode = this->list.loadTextureFromPack(pack,name,filter);edkEnd();
        this->spriteFilter=filter;edkEnd();
        if(this->spriteCode){
            this->spriteSize = this->list.getTextureSize(this->spriteCode);edkEnd();
            return true;
        }
    }

    //else return false
    return false;
}

//Delete the sprite
void edk::ViewSpriteController::deleteSprite(){
    //
    if(this->spriteCode){
        //
        this->list.removeTexture(this->spriteCode);edkEnd();
    }
    this->spriteCode = 0u;edkEnd();
    this->spriteFilter = 0u;edkEnd();
}
//return the spriteSize
edk::size2ui32 edk::ViewSpriteController::getSpriteSize(){
    return this->spriteSize;edkEnd();
}

//draw the polygon on the scene
void edk::ViewSpriteController::drawPolygon(rectf32 /*outsideViewOrigin*/){
    //
    //edk::View::drawPolygon();edkEnd();

    //draw the polygon with UV Map
    edk::GU::guUseMatrix(GU_MODELVIEW);edkEnd();

    //texture
    edk::GU::guEnable(GU_TEXTURE_2D);edkEnd();

    edk::GU::guUseTexture2D(this->spriteCode);edkEnd();

    //Draw a quadrangle
    edk::GU::guBegin(GU_QUADS);edkEnd();
    edk::GU::guVertexTex2f32(0.f, 1.f);edkEnd();
    edk::GU::guVertex3f32(0.f, 0.f, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(1.f, 1.f);edkEnd();
    edk::GU::guVertex3f32(1.f, 0.f, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(1.f, 0.f);edkEnd();
    edk::GU::guVertex3f32(1.f, 1.f, 0.f);edkEnd();

    edk::GU::guVertexTex2f32(0.f, 0.f);edkEnd();
    edk::GU::guVertex3f32(0.f, 1.f, 0.f);edkEnd();
    edk::GU::guEnd();edkEnd();

    edk::GU::guUseTexture2D(0u);edkEnd();
    edk::GU::guDisable(GU_TEXTURE_2D);edkEnd();
}

//draw
void edk::ViewSpriteController::draw(rectf32 outsideViewOrigin){
    //
    edk::ViewController::draw(outsideViewOrigin);edkEnd();
}
