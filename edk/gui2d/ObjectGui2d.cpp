#include "ObjectGui2d.h"

/*
ObjectGui2d - Object for the GUI 2D library
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

edk::gui2d::ObjectGui2d::ObjectGui2d(){
    //
    this->percent1=this->percent2=this->resize=0.f;edkEnd();
    for(edk::uint32 i = 0u;i<edk::gui2d::gui2dTextureSize;i++){
        this->spriteSize[i].width = this->spriteSize[i].height = 0.f;edkEnd();
    }
    this->textSize = edk::size2f32(1,2);edkEnd();
    this->setStatus(edk::gui2d::gui2dTextureNormal);edkEnd();
    this->saveStatus = this->status;edkEnd();
    this->pressed = false;edkEnd();
    this->drawText = false;edkEnd();
    this->selected=false;edkEnd();
}
edk::gui2d::ObjectGui2d::~ObjectGui2d(){
    //
}

//get the type
edk::gui2d::gui2dTypes edk::gui2d::ObjectGui2d::getType(){
    //
    return edk::gui2d::gui2dTypeObject;edkEnd();
}

void edk::gui2d::ObjectGui2d::drawStart(){
    //
    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    //add translate
    edk::GU::guTranslate2f32(this->position);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    //edk::GU::guScale2f32(this->size);edkEnd();
}
void edk::gui2d::ObjectGui2d::drawEnd(){
    //
    edk::GU::guPopMatrix();edkEnd();
}
void edk::gui2d::ObjectGui2d::runTextSize(){
    //test if have the text
    //get the text size
    edk::size2f32 sizeText = edk::size2f32(this->text.getMapSizeWidth() * this->textSize.width
                                           ,this->text.getMapSizeHeight() * this->textSize.height
                                           );edkEnd();

    //calculate the centerSize
    edk::size2f32 centerSize = edk::size2f32(edk::Math::module(this->center.getVertexPosition(1u).x)
                                             +
                                             edk::Math::module(this->center.getVertexPosition(0u).x),
                                             edk::Math::module(this->center.getVertexPosition(1u).y)
                                             +
                                             edk::Math::module(this->center.getVertexPosition(0u).y)
                                             );edkEnd();
    if(centerSize.width>0.f && centerSize.height>0.f){
        this->drawText = true;edkEnd();
        //
        this->updateTextSize(sizeText,centerSize,this->text.getMapSize());edkEnd();
    }
    else{
        this->drawText = false;edkEnd();
        this->text.setScale(0.01f,0.01f);edkEnd();
    }
}
void edk::gui2d::ObjectGui2d::updateTextSize(edk::size2f32 sizeText,edk::size2f32 centerSize,edk::size2ui32 mapSize){
    if(centerSize.width>centerSize.height){
        //center size width bigger than height
        this->percent1 = (edk::float32)centerSize.width/(edk::float32)centerSize.height;edkEnd();
        this->percent2 = sizeText.width/sizeText.height;edkEnd();
        if(this->percent1>this->percent2){
            //
            this->text.setScale((centerSize.height * (this->percent2))/(edk::float32)mapSize.width,
                                (centerSize.height)/(edk::float32)mapSize.height
                                );edkEnd();
        }
        else if(this->percent2>this->percent1){
            //
            this->percent2 = sizeText.height/sizeText.width;edkEnd();
            this->text.setScale(centerSize.width/(edk::float32)mapSize.width,
                                (centerSize.width * this->percent2)/(edk::float32)mapSize.height
                                );edkEnd();
        }
        else{
            //
            this->text.setScale(centerSize.width/(edk::float32)mapSize.width,
                                centerSize.height/(edk::float32)mapSize.height
                                );edkEnd();
        }
    }
    else if(centerSize.height>centerSize.width){
        //center size height bigger than width
        this->percent1 = (edk::float32)centerSize.height/(edk::float32)centerSize.width;edkEnd();
        this->percent2 = sizeText.height/sizeText.width;edkEnd();
        if(this->percent1>this->percent2){
            //
            this->text.setScale((centerSize.width)/(edk::float32)mapSize.width,
                                (centerSize.width * this->percent2)/(edk::float32)mapSize.height
                                );edkEnd();
        }
        else if(this->percent2>this->percent1){
            //
            this->percent2 = sizeText.width/sizeText.height;edkEnd();
            this->text.setScale((centerSize.height * this->percent2)/(edk::float32)mapSize.width,
                                centerSize.height/(edk::float32)mapSize.height
                                );edkEnd();
        }
        else{
            //
            this->text.setScale(centerSize.height/(edk::float32)mapSize.height,
                                centerSize.width/(edk::float32)mapSize.width
                                );edkEnd();
        }
    }
    else{
        //center size equal
        if(sizeText.width>sizeText.height){
            this->percent2 = sizeText.height/sizeText.width;edkEnd();
            //
            this->text.setScale((centerSize.width)/(edk::float32)mapSize.width,
                                (centerSize.width * this->percent2)/(edk::float32)mapSize.height
                                );edkEnd();
        }
        else if(sizeText.height>sizeText.width){
            this->percent2 = sizeText.width/sizeText.height;edkEnd();
            //
            this->text.setScale((centerSize.height * this->percent2)/(edk::float32)mapSize.width,
                                (centerSize.height)/(edk::float32)mapSize.height
                                );edkEnd();
        }
        else{
            //
            this->text.setScale(centerSize.height/(edk::float32)mapSize.height,
                                centerSize.width/(edk::float32)mapSize.width
                                );edkEnd();
        }
    }
    //set the text position
    sizeText = edk::size2f32(mapSize.width * this->text.getMapScaleWidth()
                             ,mapSize.height * this->text.getMapScaleHeight()
                             );edkEnd();
    //set the text position
    this->text.setPosition((sizeText.width*-0.5f)
                           + (this->text.getMapScaleWidth()*0.5f)
                           ,
                           0.f
                           );edkEnd();
}

//LOAD SPRITES
bool edk::gui2d::ObjectGui2d::loadSprite(const edk::char8* name,edk::uint32 filter){
    return this->loadSprite((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSprite(edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpriteNormal(name,filter);edkEnd();
}

bool edk::gui2d::ObjectGui2d::loadSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpriteFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->obj.loadSpriteNormalFromMemory(name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpriteFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSpriteFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpriteFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpriteNormalFromPack(pack,name,filter);edkEnd();
}
void edk::gui2d::ObjectGui2d::removeSprite(){
    this->obj.removeSpriteNormal();edkEnd();
}
//load pressed sprite
bool edk::gui2d::ObjectGui2d::loadSpritePressed(const edk::char8* name,edk::uint32 filter){
    return this->loadSpritePressed((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressed(edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpritePressed(name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpritePressedFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->obj.loadSpritePressedFromMemory(name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSpritePressedFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpritePressedFromPack(pack,name,filter);edkEnd();
}
void edk::gui2d::ObjectGui2d::removeSpritePressed(){
    this->obj.removeSpritePressed();edkEnd();
}
//load UP sprite
bool edk::gui2d::ObjectGui2d::loadSpriteUp(const edk::char8* name,edk::uint32 filter){
    return this->loadSpriteUp((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpriteUp(edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpriteUp(name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpriteUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpriteUpFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpriteUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->obj.loadSpriteUpFromMemory(name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpriteUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSpriteUpFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpriteUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpriteUpFromPack(pack,name,filter);edkEnd();
}
void edk::gui2d::ObjectGui2d::removeSpriteUp(){
    this->obj.removeSpriteUp();edkEnd();
}
//load UP sprite
bool edk::gui2d::ObjectGui2d::loadSpritePressedUp(const edk::char8* name,edk::uint32 filter){
    return this->loadSpritePressedUp((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUp(edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpritePressedUp(name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpritePressedUpFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->obj.loadSpritePressedUpFromMemory(name,sprite,size,filter);edkEnd();
}
void edk::gui2d::ObjectGui2d::removeSpritePressedUp(){
    this->obj.removeSpritePressedUp();edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSpritePressedUpFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpritePressedUpFromPack(pack,name,filter);edkEnd();
}

//Load button symbol normal
bool edk::gui2d::ObjectGui2d::loadSymbol(const edk::char8* name,edk::uint32 filter){
    return this->loadSymbol((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbol(edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTextureNormal,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureNormal] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureNormal);edkEnd();
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTextureNormal,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureNormal] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureNormal);edkEnd();
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromPack(pack,name,edk::gui2d::gui2dTextureNormal,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureNormal] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureNormal);edkEnd();
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::removeSymbol(){
    this->sprite.material.removeTexture(edk::gui2d::gui2dTextureNormal);edkEnd();
    this->spriteSize[edk::gui2d::gui2dTextureNormal].width = this->spriteSize[edk::gui2d::gui2dTextureNormal].height = 0.f;edkEnd();
}
//Load button symbol pressed
bool edk::gui2d::ObjectGui2d::loadSymbolPressed(const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolPressed((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressed(edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTexturePressed,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressed] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressed);edkEnd();
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolPressedFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTexturePressed,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressed] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressed);edkEnd();
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolPressedFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromPack(pack,name,edk::gui2d::gui2dTexturePressed,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressed] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressed);edkEnd();
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::removeSymbolPressed(){
    this->sprite.material.removeTexture(edk::gui2d::gui2dTexturePressed);edkEnd();
    this->spriteSize[edk::gui2d::gui2dTexturePressed].width = this->spriteSize[edk::gui2d::gui2dTexturePressed].height = 0.f;edkEnd();
}
//Load button symbol up
bool edk::gui2d::ObjectGui2d::loadSymbolUp(const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolUp((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolUp(edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTextureUp,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureUp);edkEnd();
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolUpFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTextureUp,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureUp);edkEnd();
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolUpFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromPack(pack,name,edk::gui2d::gui2dTextureUp,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureUp);edkEnd();
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::removeSymbolUp(){
    this->sprite.material.removeTexture(edk::gui2d::gui2dTextureUp);edkEnd();
    this->spriteSize[edk::gui2d::gui2dTextureUp].width = this->spriteSize[edk::gui2d::gui2dTextureUp].height = 0.f;edkEnd();
}
//Load button symbol pressedUp
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUp(const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolPressedUp((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUp(edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTexturePressedUp,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressedUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressedUp);edkEnd();
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolPressedUpFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTexturePressedUp,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressedUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressedUp);edkEnd();
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolPressedUpFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromPack(pack,name,edk::gui2d::gui2dTexturePressedUp,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressedUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressedUp);edkEnd();
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::removeSymbolPressedUp(){
    this->sprite.material.removeTexture(edk::gui2d::gui2dTexturePressedUp);edkEnd();
    this->spriteSize[edk::gui2d::gui2dTexturePressedUp].width = this->spriteSize[edk::gui2d::gui2dTexturePressedUp].height = 0.f;edkEnd();
}
//Load button symbolAllStatus
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatus(const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolAllStatus((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatus(edk::char8* name,edk::uint32 filter){
    bool ret=true;edkEnd();
    if(!this->loadSymbol(name,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolUp(name,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressed(name,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressedUp(name,filter)){
        ret = false;edkEnd();
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolAllStatusFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    bool ret=true;edkEnd();
    if(!this->loadSymbolFromMemory(name,sprite,size,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolUpFromMemory(name,sprite,size,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressedFromMemory(name,sprite,size,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressedUpFromMemory(name,sprite,size,filter)){
        ret = false;edkEnd();
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolAllStatusFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    bool ret=true;edkEnd();
    if(!this->loadSymbolFromPack(pack,name,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolUpFromPack(pack,name,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressedFromPack(pack,name,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressedUpFromPack(pack,name,filter)){
        ret = false;edkEnd();
    }
    return ret;
}
//Load button symbolAllUPStatus
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatus(const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolAllUPStatus((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatus(edk::char8* name,edk::uint32 filter){
    bool ret=true;edkEnd();
    if(!this->loadSymbolUp(name,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressedUp(name,filter)){
        ret = false;edkEnd();
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolAllUPStatusFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    bool ret=true;edkEnd();
    if(!this->loadSymbolUpFromMemory(name,sprite,size,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressedUpFromMemory(name,sprite,size,filter)){
        ret = false;edkEnd();
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolAllUPStatusFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    bool ret=true;edkEnd();
    if(!this->loadSymbolUpFromPack(pack,name,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressedUpFromPack(pack,name,filter)){
        ret = false;edkEnd();
    }
    return ret;
}
//Load button symbolAllNormalAndPressedStatus
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatus(const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolAllNormalAndPressedStatus((edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatus(edk::char8* name,edk::uint32 filter){
    bool ret=true;edkEnd();
    if(!this->loadSymbol(name,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressed(name,filter)){
        ret = false;edkEnd();
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolAllNormalAndPressedStatusFromMemory((edk::char8*) name,sprite,size,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    bool ret=true;edkEnd();
    if(!this->loadSymbolFromMemory(name,sprite,size,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressedFromMemory(name,sprite,size,filter)){
        ret = false;edkEnd();
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 filter){
    return this->loadSymbolAllNormalAndPressedStatusFromPack(pack,(edk::char8*) name,filter);edkEnd();
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 filter){
    bool ret=true;edkEnd();
    if(!this->loadSymbolFromPack(pack,name,filter)){
        ret = false;edkEnd();
    }
    if(!this->loadSymbolPressedFromPack(pack,name,filter)){
        ret = false;edkEnd();
    }
    return ret;
}

//set the color
void edk::gui2d::ObjectGui2d::setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->obj.setColor(r,g,b,a);edkEnd();
}
void edk::gui2d::ObjectGui2d::setColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->obj.setColor(r,g,b);edkEnd();
}
void edk::gui2d::ObjectGui2d::setColor(edk::color4f32 color){
    this->obj.setColor(color);edkEnd();
}
void edk::gui2d::ObjectGui2d::setColor(edk::color3f32 color){
    this->obj.setColor(color);edkEnd();
}

bool edk::gui2d::ObjectGui2d::writeText(const edk::char8* text){
    //
    return this->writeText((edk::char8*) text);edkEnd();
}
bool edk::gui2d::ObjectGui2d::writeText(edk::char8* text){
    return this->writeText(text,edk::size2f32(1,2));edkEnd();
}
bool edk::gui2d::ObjectGui2d::writeText(const edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    return this->writeText((edk::char8*) text,scaleWidth,scaleHeight);edkEnd();
}
bool edk::gui2d::ObjectGui2d::writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    return this->writeText(text,edk::size2f32(scaleWidth,scaleHeight));edkEnd();
}
bool edk::gui2d::ObjectGui2d::writeText(const edk::char8* text,edk::size2f32 scale){
    return this->writeText((edk::char8*) text,scale);edkEnd();
}
bool edk::gui2d::ObjectGui2d::writeText(edk::char8* text,edk::size2f32 scale){
    this->cleanText();edkEnd();
    //test if receive a text
    if(text){
        //write the text
        if(this->text.createStringMapOneLine(text)){
            //set the scale
            this->textSize = scale;edkEnd();

            //filter the texSize
            if(this->textSize.width>0.f && this->textSize.height>0.f){
                if(this->textSize.width>this->textSize.height){
                    this->textSize.height = this->textSize.height/this->textSize.width;edkEnd();
                    this->textSize.width = 1.f;edkEnd();
                }
                else{
                    this->textSize.width = this->textSize.width/this->textSize.height;edkEnd();
                    this->textSize.height = 1.f;edkEnd();
                }
            }

            this->runTextSize();edkEnd();

            return true;
        }
    }
    return false;
}
void edk::gui2d::ObjectGui2d::cleanText(){
    this->text.deleteMap();edkEnd();
}

//load the button textures and meshes
bool edk::gui2d::ObjectGui2d::load(){
    this->selected=false;edkEnd();
    if(this->obj.load(this->size)){
        //
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::unload(){
    this->selected=false;edkEnd();
    //unload the meshes
    this->obj.unload();edkEnd();
}
void edk::gui2d::ObjectGui2d::update(){
    //test if the size os different
    if(this->sizeS!=this->size
            ||
            this->borderSizeS!=this->obj.getBorderSize()
            ){
        //save the size
        this->sizeS = this->size;edkEnd();
        this->borderSizeS=this->obj.getBorderSize();edkEnd();

        //update the polygons
        this->obj.updatePolygons(this->size);edkEnd();
    }

    //get the center rectangle from obj
    //this->center = this->obj.getCenter();edkEnd();
    this->center.cloneFrom(this->obj.getCenter());edkEnd();

    if(this->centerS.getVertexPosition(0u)!= this->center.getVertexPosition(0u)
            ||
            this->centerS.getVertexPosition(1u)!= this->center.getVertexPosition(1u)
            ||
            this->saveStatus != this->status
            ){
        this->spritePolygon.cloneFrom(&this->center);edkEnd();
        if(this->status>=edk::gui2d::gui2dTextureSize){
            this->status = edk::gui2d::gui2dTextureNormal;edkEnd();
        }
        this->saveStatus = this->status;edkEnd();

        //calculate the centerSize
        edk::size2f32 centerSize(edk::Math::module(this->center.getVertexPosition(1u).x)
                                 +
                                 edk::Math::module(this->center.getVertexPosition(0u).x),
                                 edk::Math::module(this->center.getVertexPosition(1u).y)
                                 +
                                 edk::Math::module(this->center.getVertexPosition(0u).y)
                                 );edkEnd();

        if(this->spriteSize[this->status].width > this->spriteSize[this->status].height){
            //
            //test the button size
            if(centerSize.width>centerSize.height){
                //width>height
                this->percent1 = (edk::float32)centerSize.width / (edk::float32)centerSize.height;edkEnd();
                this->percent2 = (edk::float32)this->spriteSize[this->status].width /
                        (edk::float32)this->spriteSize[this->status].height;edkEnd();
                this->resize = 0.f;edkEnd();
                if(this->percent1>this->percent2){
                    //resize height
                    this->resize = this->percent2 * centerSize.height * 0.5f;edkEnd();
                    this->spritePolygon.setVertexPosition(0u,-this->resize,this->spritePolygon.getVertexPosition(0u).y);edkEnd();
                    this->spritePolygon.setVertexPosition(1u,+this->resize,this->spritePolygon.getVertexPosition(1u).y);edkEnd();
                }
                else if(this->percent2>this->percent1){
                    //resize width
                    this->percent2 = (edk::float32)this->spriteSize[this->status].height /
                            (edk::float32)this->spriteSize[this->status].width;edkEnd();
                    this->resize = this->percent2 * centerSize.width * 0.5;edkEnd();
                    this->spritePolygon.setVertexPosition(0u,this->spritePolygon.getVertexPosition(0u).x,+this->resize);edkEnd();
                    this->spritePolygon.setVertexPosition(1u,this->spritePolygon.getVertexPosition(1u).x,-this->resize);edkEnd();
                }
                else{
                    // ==
                }
            }
            else if(centerSize.height>centerSize.width){
                //height>width

                //resize height
                this->percent2 = (edk::float32)this->spriteSize[this->status].height /
                        (edk::float32)this->spriteSize[this->status].width;edkEnd();
                this->resize = this->percent2 * centerSize.width * 0.5;edkEnd();
                this->spritePolygon.setVertexPosition(0u,this->spritePolygon.getVertexPosition(0u).x,+this->resize);edkEnd();
                this->spritePolygon.setVertexPosition(1u,this->spritePolygon.getVertexPosition(1u).x,-this->resize);edkEnd();
            }
            else{
                //height==width

                //resize height
                this->percent2 = (edk::float32)this->spriteSize[this->status].height /
                        (edk::float32)this->spriteSize[this->status].width;edkEnd();
                this->resize = this->percent2 * centerSize.width * 0.5;edkEnd();
                this->spritePolygon.setVertexPosition(0u,this->spritePolygon.getVertexPosition(0u).x,+this->resize);edkEnd();
                this->spritePolygon.setVertexPosition(1u,this->spritePolygon.getVertexPosition(1u).x,-this->resize);edkEnd();
            }
        }
        else if(this->spriteSize[this->status].height > this->spriteSize[this->status].width){
            //test the button size
            if(centerSize.width>centerSize.height){
                //width>height

                //resize width
                this->percent2 = (edk::float32)this->spriteSize[this->status].width /
                        (edk::float32)this->spriteSize[this->status].height;edkEnd();
                this->resize = this->percent2 * centerSize.height * 0.5;edkEnd();
                this->spritePolygon.setVertexPosition(0u,-this->resize,this->spritePolygon.getVertexPosition(0u).y);edkEnd();
                this->spritePolygon.setVertexPosition(1u,+this->resize,this->spritePolygon.getVertexPosition(1u).y);edkEnd();
            }
            else if(centerSize.height>centerSize.width){
                //height>width
                this->percent1 = (edk::float32)centerSize.height / (edk::float32)centerSize.width;edkEnd();
                this->percent2 = (edk::float32)this->spriteSize[this->status].height /
                        (edk::float32)this->spriteSize[this->status].width;edkEnd();
                this->resize = 0.f;edkEnd();
                if(this->percent1>this->percent2){
                    //resize height
                    this->resize = this->percent2 * centerSize.width * 0.5f;edkEnd();
                    this->spritePolygon.setVertexPosition(0u,this->spritePolygon.getVertexPosition(0u).x,+this->resize);edkEnd();
                    this->spritePolygon.setVertexPosition(1u,this->spritePolygon.getVertexPosition(1u).x,-this->resize);edkEnd();
                }
                else if(this->percent2>this->percent1){
                    //resize width
                    this->percent2 = (edk::float32)this->spriteSize[this->status].width /
                            (edk::float32)this->spriteSize[this->status].height;edkEnd();
                    this->resize = this->percent2 * centerSize.height * 0.5;edkEnd();
                    this->spritePolygon.setVertexPosition(0u,-this->resize,this->spritePolygon.getVertexPosition(0u).y);edkEnd();
                    this->spritePolygon.setVertexPosition(1u,+this->resize,this->spritePolygon.getVertexPosition(1u).y);edkEnd();
                }
                else{
                    // ==
                    this->resize = 0.f;edkEnd();
                }
            }
            else{
                //height==width

                //resize width
                this->percent2 = (edk::float32)this->spriteSize[this->status].width /
                        (edk::float32)this->spriteSize[this->status].height;edkEnd();
                this->resize = this->percent2 * centerSize.height * 0.5;edkEnd();
                this->spritePolygon.setVertexPosition(0u,-this->resize,this->spritePolygon.getVertexPosition(0u).y);edkEnd();
                this->spritePolygon.setVertexPosition(1u,+this->resize,this->spritePolygon.getVertexPosition(1u).y);edkEnd();
            }
        }
        else{
            //test the button size
            if(centerSize.width>centerSize.height){
                //width>height

                //resize width
                this->percent2 = (edk::float32)this->spriteSize[this->status].width /
                        (edk::float32)this->spriteSize[this->status].height;edkEnd();
                this->resize = this->percent2 * centerSize.height * 0.5;edkEnd();
                this->spritePolygon.setVertexPosition(0u,-this->resize,this->spritePolygon.getVertexPosition(0u).y);edkEnd();
                this->spritePolygon.setVertexPosition(1u,+this->resize,this->spritePolygon.getVertexPosition(1u).y);edkEnd();
            }
            else if(centerSize.height>centerSize.width){
                //height>width

                //resize height
                this->percent2 = (edk::float32)this->spriteSize[this->status].height /
                        (edk::float32)this->spriteSize[this->status].width;edkEnd();
                this->resize = this->percent2 * centerSize.width * 0.5;edkEnd();
                this->spritePolygon.setVertexPosition(0u,this->spritePolygon.getVertexPosition(0u).x,+this->resize);edkEnd();
                this->spritePolygon.setVertexPosition(1u,this->spritePolygon.getVertexPosition(1u).x,-this->resize);edkEnd();
            }
            else{
                //height==width
            }
        }

        this->sprite.cleanPolygons();edkEnd();
        this->sprite.addPolygon(this->spritePolygon);edkEnd();

        //update the text
        this->runTextSize();edkEnd();

        //update the polygon
        //this->centerS = this->center;edkEnd();
        this->centerS.cloneFrom(&this->center);edkEnd();
    }
}
void edk::gui2d::ObjectGui2d::startMove(edk::vec2f32){
    this->savePosition = this->position;edkEnd();
}
void edk::gui2d::ObjectGui2d::moveTo(edk::vec2f32 position){
    //set the position
    this->position = this->savePosition + position;edkEnd();
}
void edk::gui2d::ObjectGui2d::cancelMove(){
    //
    this->position = this->savePosition;edkEnd();
}
bool edk::gui2d::ObjectGui2d::setStatus(edk::gui2d::gui2dTexture status){
    switch(status){
    case edk::gui2d::gui2dTexture::gui2dTextureNormal:
        this->status = edk::gui2d::gui2dTexture::gui2dTextureNormal;edkEnd();
        return true;
        break;edkEnd();
    case edk::gui2d::gui2dTexture::gui2dTextureUp:
        this->status = edk::gui2d::gui2dTexture::gui2dTextureUp;edkEnd();
        return true;
        break;edkEnd();
    case edk::gui2d::gui2dTexture::gui2dTexturePressedUp:
        this->status = edk::gui2d::gui2dTexture::gui2dTexturePressedUp;edkEnd();
        return true;
        break;edkEnd();
    case edk::gui2d::gui2dTexture::gui2dTexturePressed:
        this->status = edk::gui2d::gui2dTexture::gui2dTexturePressed;edkEnd();
        return true;
        break;edkEnd();
    case edk::gui2d::gui2dTexture::gui2dTextureSize:
        break;edkEnd();
    }
    return false;
}
void edk::gui2d::ObjectGui2d::forceUpdate(){
    this->saveStatus = edk::gui2d::gui2dTextureSize;edkEnd();
}
edk::gui2d::gui2dTexture edk::gui2d::ObjectGui2d::getStatus(){
    return this->status;edkEnd();
}
//select functions
void edk::gui2d::ObjectGui2d::select(){
    this->selected = true;edkEnd();
}
void edk::gui2d::ObjectGui2d::deselect(){
    this->selected = false;edkEnd();
}
bool edk::gui2d::ObjectGui2d::isSelected(){
    return this->selected;edkEnd();
}
//click to select an polygon inside the object
void edk::gui2d::ObjectGui2d::clickStart(edk::uint32){
    //
}
void edk::gui2d::ObjectGui2d::clickMove(edk::uint32,bool){
    //
}
void edk::gui2d::ObjectGui2d::clickEnd(edk::uint32,bool,bool){
    //
}

//set border size
bool edk::gui2d::ObjectGui2d::setBorderSize(edk::float32 size){
    //
    return this->obj.setBorderSize(size);edkEnd();
}

//draw the button
void edk::gui2d::ObjectGui2d::draw(){
    this->drawStart();edkEnd();


    edk::GU::guEnable(GU_LIGHTING);edkEnd();

    switch(this->status){
    case edk::gui2d::gui2dTexture::gui2dTextureUp:
        //draw the border
        this->obj.drawUp();edkEnd();
        break;edkEnd();
    case edk::gui2d::gui2dTexture::gui2dTexturePressed:
        //draw the border
        this->obj.drawPressed();edkEnd();
        break;edkEnd();
    case edk::gui2d::gui2dTexture::gui2dTexturePressedUp:
        //draw the border
        this->obj.drawPressedUp();edkEnd();
        break;edkEnd();
    case edk::gui2d::gui2dTexture::gui2dTextureNormal:
    case edk::gui2d::gui2dTexture::gui2dTextureSize:
    default:
        //draw the border
        this->obj.drawNormal();edkEnd();
        break;edkEnd();
    }
    edk::GU::guDisable(GU_LIGHTING);edkEnd();

    //test if have the texture
    if(this->sprite.material.getTexture(this->status)){
        //draw the srite on the button
        this->sprite.drawOneTexture(this->status);edkEnd();
    }

    if(this->text.haveText() && this->drawText){
        //
        this->text.draw(edk::color4f32(0,0,0,1));edkEnd();
    }

    this->drawEnd();edkEnd();
}
void edk::gui2d::ObjectGui2d::drawSelection(){
    this->drawStart();edkEnd();
    //draw the border
    this->obj.drawSelection();edkEnd();
    //
    this->drawEnd();edkEnd();
}
//return true if the object can be moved
bool edk::gui2d::ObjectGui2d::canMove(){
    return false;
}

