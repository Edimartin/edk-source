#include "ObjectGui2d.h"

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

edk::gui2d::ObjectGui2d::ObjectGui2d(){
    //
    this->percent1=this->percent2=this->resize=0.f;
    for(edk::uint32 i = 0u;i<edk::gui2d::gui2dTextureSize;i++){
        this->spriteSize[i].width = this->spriteSize[i].height = 0.f;
    }
    this->textSize = edk::size2f32(1,2);
    this->setStatus(edk::gui2d::gui2dTextureNormal);
    this->saveStatus = this->status;
    this->pressed = false;
    this->drawText = false;
}
edk::gui2d::ObjectGui2d::~ObjectGui2d(){
    //
}
void edk::gui2d::ObjectGui2d::drawStart(){
    //
    //put the transformation on a stack
    edk::GU::guPushMatrix();

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    //edk::GU::guScale2f32(this->size);
}
void edk::gui2d::ObjectGui2d::drawEnd(){
    //
    edk::GU::guPopMatrix();
}
void edk::gui2d::ObjectGui2d::updateTextSize(){
    //test if have the text
    if(this->text.haveText()){
        //get the text size
        edk::size2f32 sizeText = edk::size2f32(this->text.getMapSizeWidth() * this->textSize.width
                                               ,this->text.getMapSizeHeight() * this->textSize.height
                                               );


        //calculate the centerSize
        edk::size2f32 centerSize(edk::Math::moduleFloat(this->center.getVertexPosition(1u).x)
                                 +
                                 edk::Math::moduleFloat(this->center.getVertexPosition(0u).x),
                                 edk::Math::moduleFloat(this->center.getVertexPosition(1u).y)
                                 +
                                 edk::Math::moduleFloat(this->center.getVertexPosition(0u).y)
                                 );
        if(centerSize.width>0.f && centerSize.height>0.f){
            this->drawText = true;

            if(centerSize.width>centerSize.height){
                //center size width bigger than height
                this->percent1 = (edk::float32)centerSize.width/(edk::float32)centerSize.height;
                this->percent2 = sizeText.width/sizeText.height;
                if(this->percent1>this->percent2){
                    //
                    this->text.setScale((centerSize.height * (this->percent2))/(edk::float32)this->text.getMapSizeWidth(),
                                        (centerSize.height)/(edk::float32)this->text.getMapSizeHeight()
                                        );
                }
                else if(this->percent2>this->percent1){
                    //
                    this->percent2 = sizeText.height/sizeText.width;
                    this->text.setScale(centerSize.width/(edk::float32)this->text.getMapSizeWidth(),
                                        (centerSize.width * this->percent2)/(edk::float32)this->text.getMapSizeHeight()
                                        );
                }
                else{
                    //
                    this->text.setScale(centerSize.width/(edk::float32)this->text.getMapSizeWidth(),
                                        centerSize.height/(edk::float32)this->text.getMapSizeHeight()
                                        );
                }
            }
            else if(centerSize.height>centerSize.width){
                //center size height bigger than width
                this->percent1 = (edk::float32)centerSize.height/(edk::float32)centerSize.width;
                this->percent2 = sizeText.height/sizeText.width;
                if(this->percent1>this->percent2){
                    //
                    this->text.setScale((centerSize.width)/(edk::float32)this->text.getMapSizeWidth(),
                                        (centerSize.width * this->percent2)/(edk::float32)this->text.getMapSizeHeight()
                                        );
                }
                else if(this->percent2>this->percent1){
                    //
                    this->percent2 = sizeText.width/sizeText.height;
                    this->text.setScale((centerSize.height * this->percent2)/(edk::float32)this->text.getMapSizeWidth(),
                                        centerSize.height/(edk::float32)this->text.getMapSizeHeight()
                                        );
                }
                else{
                    //
                    this->text.setScale(centerSize.height/(edk::float32)this->text.getMapSizeHeight(),
                                        centerSize.width/(edk::float32)this->text.getMapSizeWidth()
                                        );
                }
            }
            else{
                //center size equal
                if(sizeText.width>sizeText.height){
                    this->percent2 = sizeText.height/sizeText.width;
                    //
                    this->text.setScale((centerSize.width)/(edk::float32)this->text.getMapSizeWidth(),
                                        (centerSize.width * this->percent2)/(edk::float32)this->text.getMapSizeHeight()
                                        );
                }
                else if(sizeText.height>sizeText.width){
                    this->percent2 = sizeText.width/sizeText.height;
                    //
                    this->text.setScale((centerSize.height * this->percent2)/(edk::float32)this->text.getMapSizeWidth(),
                                        (centerSize.height)/(edk::float32)this->text.getMapSizeHeight()
                                        );
                }
                else{
                    //
                    this->text.setScale(centerSize.height/(edk::float32)this->text.getMapSizeHeight(),
                                        centerSize.width/(edk::float32)this->text.getMapSizeWidth()
                                        );
                }
            }
            //set the text position
            sizeText = edk::size2f32(this->text.getMapSizeWidth() * this->text.getMapScaleWidth()
                                     ,this->text.getMapSizeHeight() * this->text.getMapScaleHeight()
                                     );
            //set the text position
            this->text.setPosition((sizeText.width*-0.5f)
                                   + (this->text.getMapScaleWidth()*0.5f)
                                   ,
                                   0.f
                                   );
        }
        else{
            this->drawText = false;
            this->text.setScale(0.01f,0.01f);
        }
    }
    else{
        this->drawText = false;
        this->text.setScale(0.01f,0.01f);
    }
}

//LOAD SPRITES
bool edk::gui2d::ObjectGui2d::loadSprite(const char* name,edk::uint32 filter){
    return this->loadSprite((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSprite(edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpriteNormal(name,filter);
}

bool edk::gui2d::ObjectGui2d::loadSpriteFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpriteFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->obj.loadSpriteNormalFromMemory(name,sprite,size,filter);
}
void edk::gui2d::ObjectGui2d::removeSprite(){
    this->obj.removeSpriteNormal();
}
//load pressed sprite
bool edk::gui2d::ObjectGui2d::loadSpritePressed(const char* name,edk::uint32 filter){
    return this->loadSpritePressed((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressed(edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpritePressed(name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpritePressedFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->obj.loadSpritePressedFromMemory(name,sprite,size,filter);
}
void edk::gui2d::ObjectGui2d::removeSpritePressed(){
    this->obj.removeSpritePressed();
}
//load UP sprite
bool edk::gui2d::ObjectGui2d::loadSpriteUp(const char* name,edk::uint32 filter){
    return this->loadSpriteUp((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteUp(edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpriteUp(name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteUpFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpriteUpFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->obj.loadSpriteUpFromMemory(name,sprite,size,filter);
}
void edk::gui2d::ObjectGui2d::removeSpriteUp(){
    this->obj.removeSpriteUp();
}
//load UP sprite
bool edk::gui2d::ObjectGui2d::loadSpritePressedUp(const char* name,edk::uint32 filter){
    return this->loadSpritePressedUp((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUp(edk::char8* name,edk::uint32 filter){
    return this->obj.loadSpritePressedUp(name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUpFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSpritePressedUpFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->obj.loadSpritePressedUpFromMemory(name,sprite,size,filter);
}
void edk::gui2d::ObjectGui2d::removeSpritePressedUp(){
    this->obj.removeSpritePressedUp();
}

//Load button symbol normal
bool edk::gui2d::ObjectGui2d::loadSymbol(const char* name,edk::uint32 filter){
    return this->loadSymbol((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbol(edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTextureNormal,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureNormal] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureNormal);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTextureNormal,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureNormal] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureNormal);
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::removeSymbol(){
    this->sprite.material.removeTexture(edk::gui2d::gui2dTextureNormal);
    this->spriteSize[edk::gui2d::gui2dTextureNormal].width = this->spriteSize[edk::gui2d::gui2dTextureNormal].height = 0.f;
}
//Load button symbol pressed
bool edk::gui2d::ObjectGui2d::loadSymbolPressed(const char* name,edk::uint32 filter){
    return this->loadSymbolPressed((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressed(edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTexturePressed,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressed] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressed);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolPressedFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTexturePressed,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressed] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressed);
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::removeSymbolPressed(){
    this->sprite.material.removeTexture(edk::gui2d::gui2dTexturePressed);
    this->spriteSize[edk::gui2d::gui2dTexturePressed].width = this->spriteSize[edk::gui2d::gui2dTexturePressed].height = 0.f;
}
//Load button symbol up
bool edk::gui2d::ObjectGui2d::loadSymbolUp(const char* name,edk::uint32 filter){
    return this->loadSymbolUp((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolUp(edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTextureUp,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureUp);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolUpFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolUpFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTextureUp,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureUp);
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::removeSymbolUp(){
    this->sprite.material.removeTexture(edk::gui2d::gui2dTextureUp);
    this->spriteSize[edk::gui2d::gui2dTextureUp].width = this->spriteSize[edk::gui2d::gui2dTextureUp].height = 0.f;
}
//Load button symbol pressedUp
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUp(const char* name,edk::uint32 filter){
    return this->loadSymbolPressedUp((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUp(edk::char8* name,edk::uint32 filter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTexturePressedUp,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressedUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressedUp);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUpFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolPressedUpFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTexturePressedUp,filter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressedUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressedUp);
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::removeSymbolPressedUp(){
    this->sprite.material.removeTexture(edk::gui2d::gui2dTexturePressedUp);
    this->spriteSize[edk::gui2d::gui2dTexturePressedUp].width = this->spriteSize[edk::gui2d::gui2dTexturePressedUp].height = 0.f;
}
//Load button symbolAllStatus
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatus(const char* name,edk::uint32 filter){
    return this->loadSymbolAllStatus((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatus(edk::char8* name,edk::uint32 filter){
    bool ret=true;
    if(!this->loadSymbol(name,filter)){
        ret = false;
    }
    if(!this->loadSymbolUp(name,filter)){
        ret = false;
    }
    if(!this->loadSymbolPressed(name,filter)){
        ret = false;
    }
    if(!this->loadSymbolPressedUp(name,filter)){
        ret = false;
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatusFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolAllStatusFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    bool ret=true;
    if(!this->loadSymbolFromMemory(name,sprite,size,filter)){
        ret = false;
    }
    if(!this->loadSymbolUpFromMemory(name,sprite,size,filter)){
        ret = false;
    }
    if(!this->loadSymbolPressedFromMemory(name,sprite,size,filter)){
        ret = false;
    }
    if(!this->loadSymbolPressedUpFromMemory(name,sprite,size,filter)){
        ret = false;
    }
    return ret;
}
//Load button symbolAllUPStatus
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatus(const char* name,edk::uint32 filter){
    return this->loadSymbolAllUPStatus((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatus(edk::char8* name,edk::uint32 filter){
    bool ret=true;
    if(!this->loadSymbolUp(name,filter)){
        ret = false;
    }
    if(!this->loadSymbolPressedUp(name,filter)){
        ret = false;
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatusFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolAllUPStatusFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    bool ret=true;
    if(!this->loadSymbolUpFromMemory(name,sprite,size,filter)){
        ret = false;
    }
    if(!this->loadSymbolPressedUpFromMemory(name,sprite,size,filter)){
        ret = false;
    }
    return ret;
}
//Load button symbolAllNormalAndPressedStatus
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatus(const char* name,edk::uint32 filter){
    return this->loadSymbolAllNormalAndPressedStatus((edk::char8*) name,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatus(edk::char8* name,edk::uint32 filter){
    bool ret=true;
    if(!this->loadSymbol(name,filter)){
        ret = false;
    }
    if(!this->loadSymbolPressed(name,filter)){
        ret = false;
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatusFromMemory(const char* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    return this->loadSymbolAllNormalAndPressedStatusFromMemory((edk::char8*) name,sprite,size,filter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 filter){
    bool ret=true;
    if(!this->loadSymbolFromMemory(name,sprite,size,filter)){
        ret = false;
    }
    if(!this->loadSymbolPressedFromMemory(name,sprite,size,filter)){
        ret = false;
    }
    return ret;
}

//set the color
void edk::gui2d::ObjectGui2d::setColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->obj.setColor(r,g,b,a);
}
void edk::gui2d::ObjectGui2d::setColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->obj.setColor(r,g,b);
}
void edk::gui2d::ObjectGui2d::setColor(edk::color4f32 color){
    this->obj.setColor(color);
}
void edk::gui2d::ObjectGui2d::setColor(edk::color3f32 color){
    this->obj.setColor(color);
}

bool edk::gui2d::ObjectGui2d::writeText(const char* text){
    //
    return this->writeText((edk::char8*) text);
}
bool edk::gui2d::ObjectGui2d::writeText(edk::char8* text){
    return this->writeText(text,edk::size2f32(1,2));
}
bool edk::gui2d::ObjectGui2d::writeText(const char* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    return this->writeText((edk::char8*) text,scaleWidth,scaleHeight);
}
bool edk::gui2d::ObjectGui2d::writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    return this->writeText(text,edk::size2f32(scaleWidth,scaleHeight));
}
bool edk::gui2d::ObjectGui2d::writeText(const char* text,edk::size2f32 scale){
    return this->writeText((edk::char8*) text,scale);
}
bool edk::gui2d::ObjectGui2d::writeText(edk::char8* text,edk::size2f32 scale){
    this->cleanText();
    //test if receive a text
    if(text){
        //write the text
        if(this->text.createStringMap(text)){
            //set the scale
            this->textSize = scale;

            //filter the texSize
            if(this->textSize.width>0.f && this->textSize.height>0.f){
                if(this->textSize.width>this->textSize.height){
                    this->textSize.height = this->textSize.height/this->textSize.width;
                    this->textSize.width = 1.f;
                }
                else{
                    this->textSize.width = this->textSize.width/this->textSize.height;
                    this->textSize.height = 1.f;
                }
            }

            this->updateTextSize();

            return true;
        }
    }
    return false;
}
void edk::gui2d::ObjectGui2d::cleanText(){
    this->text.deleteMap();
}

//load the button textures and meshes
bool edk::gui2d::ObjectGui2d::load(){
    if(this->obj.load(this->size)){
        //
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::unload(){
    //unload the meshes
    this->obj.unload();
}
void edk::gui2d::ObjectGui2d::update(){
    //test if the size os different
    if(this->sizeS!=this->size
            ||
            this->borderSizeS!=this->obj.getBorderSize()
            ){
        //save the size
        this->sizeS = this->size;
        this->borderSizeS=this->obj.getBorderSize();

        //update the polygons
        this->obj.updatePolygons(this->size);
    }

    //get the center rectangle from obj
    //this->center = this->obj.getCenter();
    this->center.cloneFrom(this->obj.getCenter());

    if(this->centerS.getVertexPosition(0u)!= this->center.getVertexPosition(0u)
            ||
            this->centerS.getVertexPosition(1u)!= this->center.getVertexPosition(1u)
            ||
            this->saveStatus != this->status
            ){
        this->spritePolygon.cloneFrom(&this->center);
        if(this->status>=edk::gui2d::gui2dTextureSize)
            this->status = edk::gui2d::gui2dTextureNormal;
        this->saveStatus = this->status;

        //calculate the centerSize
        edk::size2f32 centerSize(edk::Math::moduleFloat(this->center.getVertexPosition(1u).x)
                                 +
                                 edk::Math::moduleFloat(this->center.getVertexPosition(0u).x),
                                 edk::Math::moduleFloat(this->center.getVertexPosition(1u).y)
                                 +
                                 edk::Math::moduleFloat(this->center.getVertexPosition(0u).y)
                                 );

        if(this->spriteSize[this->status].width > this->spriteSize[this->status].height){
            //
            //test the button size
            if(centerSize.width>centerSize.height){
                //width>height
                this->percent1 = (edk::float32)centerSize.width / (edk::float32)centerSize.height;
                this->percent2 = (edk::float32)this->spriteSize[this->status].width /
                        (edk::float32)this->spriteSize[this->status].height;
                this->resize = 0.f;
                if(this->percent1>this->percent2){
                    //resize height
                    this->resize = this->percent2 * centerSize.height * 0.5f;
                    this->spritePolygon.setVertexPosition(0u,-this->resize,this->spritePolygon.getVertexPosition(0u).y);
                    this->spritePolygon.setVertexPosition(1u,+this->resize,this->spritePolygon.getVertexPosition(1u).y);
                }
                else if(this->percent2>this->percent1){
                    //resize width
                    this->percent2 = (edk::float32)this->spriteSize[this->status].height /
                            (edk::float32)this->spriteSize[this->status].width;
                    this->resize = this->percent2 * centerSize.width * 0.5;
                    this->spritePolygon.setVertexPosition(0u,this->spritePolygon.getVertexPosition(0u).x,+this->resize);
                    this->spritePolygon.setVertexPosition(1u,this->spritePolygon.getVertexPosition(1u).x,-this->resize);
                }
                else{
                    // ==
                }
            }
            else if(centerSize.height>centerSize.width){
                //height>width

                //resize height
                this->percent2 = (edk::float32)this->spriteSize[this->status].height /
                        (edk::float32)this->spriteSize[this->status].width;
                this->resize = this->percent2 * centerSize.width * 0.5;
                this->spritePolygon.setVertexPosition(0u,this->spritePolygon.getVertexPosition(0u).x,+this->resize);
                this->spritePolygon.setVertexPosition(1u,this->spritePolygon.getVertexPosition(1u).x,-this->resize);
            }
            else{
                //height==width

                //resize height
                this->percent2 = (edk::float32)this->spriteSize[this->status].height /
                        (edk::float32)this->spriteSize[this->status].width;
                this->resize = this->percent2 * centerSize.width * 0.5;
                this->spritePolygon.setVertexPosition(0u,this->spritePolygon.getVertexPosition(0u).x,+this->resize);
                this->spritePolygon.setVertexPosition(1u,this->spritePolygon.getVertexPosition(1u).x,-this->resize);
            }
        }
        else if(this->spriteSize[this->status].height > this->spriteSize[this->status].width){
            //test the button size
            if(centerSize.width>centerSize.height){
                //width>height

                //resize width
                this->percent2 = (edk::float32)this->spriteSize[this->status].width /
                        (edk::float32)this->spriteSize[this->status].height;
                this->resize = this->percent2 * centerSize.height * 0.5;
                this->spritePolygon.setVertexPosition(0u,-this->resize,this->spritePolygon.getVertexPosition(0u).y);
                this->spritePolygon.setVertexPosition(1u,+this->resize,this->spritePolygon.getVertexPosition(1u).y);
            }
            else if(centerSize.height>centerSize.width){
                //height>width
                this->percent1 = (edk::float32)centerSize.height / (edk::float32)centerSize.width;
                this->percent2 = (edk::float32)this->spriteSize[this->status].height /
                        (edk::float32)this->spriteSize[this->status].width;
                this->resize = 0.f;
                if(this->percent1>this->percent2){
                    //resize height
                    this->resize = this->percent2 * centerSize.width * 0.5f;
                    this->spritePolygon.setVertexPosition(0u,this->spritePolygon.getVertexPosition(0u).x,+this->resize);
                    this->spritePolygon.setVertexPosition(1u,this->spritePolygon.getVertexPosition(1u).x,-this->resize);
                }
                else if(this->percent2>this->percent1){
                    //resize width
                    this->percent2 = (edk::float32)this->spriteSize[this->status].width /
                            (edk::float32)this->spriteSize[this->status].height;
                    this->resize = this->percent2 * centerSize.height * 0.5;
                    this->spritePolygon.setVertexPosition(0u,-this->resize,this->spritePolygon.getVertexPosition(0u).y);
                    this->spritePolygon.setVertexPosition(1u,+this->resize,this->spritePolygon.getVertexPosition(1u).y);
                }
                else{
                    // ==
                    this->resize = 0.f;
                }
            }
            else{
                //height==width

                //resize width
                this->percent2 = (edk::float32)this->spriteSize[this->status].width /
                        (edk::float32)this->spriteSize[this->status].height;
                this->resize = this->percent2 * centerSize.height * 0.5;
                this->spritePolygon.setVertexPosition(0u,-this->resize,this->spritePolygon.getVertexPosition(0u).y);
                this->spritePolygon.setVertexPosition(1u,+this->resize,this->spritePolygon.getVertexPosition(1u).y);
            }
        }
        else{
            //test the button size
            if(centerSize.width>centerSize.height){
                //width>height

                //resize width
                this->percent2 = (edk::float32)this->spriteSize[this->status].width /
                        (edk::float32)this->spriteSize[this->status].height;
                this->resize = this->percent2 * centerSize.height * 0.5;
                this->spritePolygon.setVertexPosition(0u,-this->resize,this->spritePolygon.getVertexPosition(0u).y);
                this->spritePolygon.setVertexPosition(1u,+this->resize,this->spritePolygon.getVertexPosition(1u).y);
            }
            else if(centerSize.height>centerSize.width){
                //height>width

                //resize height
                this->percent2 = (edk::float32)this->spriteSize[this->status].height /
                        (edk::float32)this->spriteSize[this->status].width;
                this->resize = this->percent2 * centerSize.width * 0.5;
                this->spritePolygon.setVertexPosition(0u,this->spritePolygon.getVertexPosition(0u).x,+this->resize);
                this->spritePolygon.setVertexPosition(1u,this->spritePolygon.getVertexPosition(1u).x,-this->resize);
            }
            else{
                //height==width
            }
        }

        this->sprite.cleanPolygons();
        this->sprite.addPolygon(this->spritePolygon);

        //update the text
        this->updateTextSize();

        //update the polygon
        //this->centerS = this->center;
        this->centerS.cloneFrom(&this->center);
    }
}
void edk::gui2d::ObjectGui2d::startMove(edk::vec2f32){
    this->savePosition = this->position;
}
void edk::gui2d::ObjectGui2d::moveTo(edk::vec2f32 position){
    //set the position
    this->position = this->savePosition + position;
}
void edk::gui2d::ObjectGui2d::cancelMove(){
    //
    this->position = this->savePosition;
}
bool edk::gui2d::ObjectGui2d::setStatus(edk::gui2d::gui2dTexture status){
    switch(status){
    case edk::gui2d::gui2dTexture::gui2dTextureNormal:
        this->status = edk::gui2d::gui2dTexture::gui2dTextureNormal;
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTextureUp:
        this->status = edk::gui2d::gui2dTexture::gui2dTextureUp;
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTexturePressedUp:
        this->status = edk::gui2d::gui2dTexture::gui2dTexturePressedUp;
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTexturePressed:
        this->status = edk::gui2d::gui2dTexture::gui2dTexturePressed;
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTextureSize:
        break;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::forceUpdate(){
    this->saveStatus = edk::gui2d::gui2dTextureSize;
}
edk::gui2d::gui2dTexture edk::gui2d::ObjectGui2d::getStatus(){
    return this->status;
}

//set border size
bool edk::gui2d::ObjectGui2d::setBorderSize(edk::float32 size){
    //
    return this->obj.setBorderSize(size);
}

//draw the button
void edk::gui2d::ObjectGui2d::draw(){
    this->drawStart();


    edk::GU::guEnable(GU_LIGHTING);

    switch(this->status){
    case edk::gui2d::gui2dTexture::gui2dTextureUp:
        //draw the border
        this->obj.drawUp();
        break;
    case edk::gui2d::gui2dTexture::gui2dTexturePressed:
        //draw the border
        this->obj.drawPressed();
        break;
    case edk::gui2d::gui2dTexture::gui2dTexturePressedUp:
        //draw the border
        this->obj.drawPressedUp();
        break;
    case edk::gui2d::gui2dTexture::gui2dTextureNormal:
    case edk::gui2d::gui2dTexture::gui2dTextureSize:
    default:
        //draw the border
        this->obj.drawNormal();
        break;
    }
    edk::GU::guDisable(GU_LIGHTING);

    //test if have the texture
    if(this->sprite.material.getTexture(this->status)){
        //draw the srite on the button
        this->sprite.drawOneTexture(this->status);
    }

    if(this->text.haveText() && this->drawText){
        //
        this->text.draw(edk::color4f32(0,0,0,1));
    }

    this->drawEnd();
}
void edk::gui2d::ObjectGui2d::drawSelection(){
    this->drawStart();
    //draw the border
    this->obj.drawSelection();
    //
    this->drawEnd();
}
//return true if the object can be moved
bool edk::gui2d::ObjectGui2d::canMove(){
    return false;
}

