#include "ScrollBar2d.h"

/*
ScrollBar2d - ScrollBar for the GUI 2D library
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

edk::gui2d::ScrollBar2d::ScrollBar2d(){
    //
    this->setBorderSize(0.25f);
    this->objPosition = 0.f;
    this->saveSize = 1.f;
    this->foregroundSize = 0.5f;
    this->saveSize = 0.f;

    this->saveStatusInside=this->statusInside=edk::gui2d::gui2dTextureNormal;
}
edk::gui2d::ScrollBar2d::~ScrollBar2d(){
    //clean the meshes
    this->unload();
}
void edk::gui2d::ScrollBar2d::updateObjPosition(){
    //update X
    edk::vec2f32 position = this->objPosition-this->position;
    if(position.x + (this->foregroundSize.width*0.5)>(this->size.width*0.5)){
        //
        this->objPosition.x = this->position.x + (this->size.width*0.5) - (this->foregroundSize.width*0.5f);
    }
    if(position.x - (this->foregroundSize.width*0.5)<(this->size.width*-0.5)){
        //
        this->objPosition.x = this->position.x - (this->size.width*0.5) + (this->foregroundSize.width*0.5f);
    }
    //update Y
    if(position.y + (this->foregroundSize.height*0.5)>(this->size.height*0.5)){
        //
        this->objPosition.y = this->position.y + (this->size.height*0.5) - (this->foregroundSize.height*0.5f);
    }
    if(position.y - (this->foregroundSize.height*0.5)<(this->size.height*-0.5)){
        //
        this->objPosition.y = this->position.y - (this->size.height*0.5) + (this->foregroundSize.height*0.5f);
    }
}

//load the button textures and meshes
bool edk::gui2d::ScrollBar2d::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        this->saveSize = this->size;
        this->objInside.load(edk::size2f32(this->foregroundSize * this->size));
        return true;
    }
    return false;
}
void edk::gui2d::ScrollBar2d::unload(){
    this->obj.unload();
    edk::gui2d::ObjectGui2d::unload();
}
void edk::gui2d::ScrollBar2d::update(){
    edk::gui2d::ObjectGui2d::update();
}

//set border size
bool edk::gui2d::ScrollBar2d::setBorderSize(edk::float32 size){
    this->objInside.setBorderSize(size);
    return edk::gui2d::ObjectGui2d::setBorderSize(size);
}

//draw the button
void edk::gui2d::ScrollBar2d::draw(){
    edk::gui2d::ObjectGui2d::draw();

    //test if the size is different
    if(this->saveSize!=this->size){
        this->saveSize=this->size;
        //update the obj position
        this->objInside.updatePolygons(this->foregroundSize * this->size);
    }

    //put the transformation on a stack
    edk::GU::guPushMatrix();

    //add translate
    edk::GU::guTranslate2f32(this->position + this->objPosition);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    //edk::GU::guScale2f32(this->size);

    switch(this->statusInside){
    case gui2dTextureUp:
        this->objInside.drawUp();
        break;
    case gui2dTexturePressed:
        this->objInside.drawPressed();
        break;
    case gui2dTexturePressedUp:
        this->objInside.drawPressedUp();
        break;
    case gui2dTextureSize:
    case gui2dTextureNormal:
        this->objInside.drawNormal();
        break;
    }

    edk::GU::guPopMatrix();
}

//move functions
void edk::gui2d::ScrollBar2d::startMove(edk::vec2f32 mousePosition){
    //

    //test if the mousePosition is inside the objInside
    edk::size2f32 sizeTemp = this->foregroundSize * this->size;
    edk::vec2f32 position = mousePosition - this->objPosition;
    if(!(position.x<sizeTemp.width*0.5
            &&
            position.x>sizeTemp.width*-0.5
            &&
            position.y<sizeTemp.height*0.5
                        &&
                        position.y>sizeTemp.height*-0.5)
            ){
        //move the objPosition to mousePosition
        this->objPosition = mousePosition;

        //update the inside position
        this->updateObjPosition();
    }
    this->savePosition = this->objPosition;
}
void edk::gui2d::ScrollBar2d::moveTo(edk::vec2f32 position){
    this->objPosition = this->savePosition + position;

    //update the inside position
    this->updateObjPosition();
}
void edk::gui2d::ScrollBar2d::cancelMove(){
    this->objPosition = this->savePosition;
}
//return true if the object can be moved
bool edk::gui2d::ScrollBar2d::canMove(){
    return true;
}
bool edk::gui2d::ScrollBar2d::setStatus(edk::gui2d::gui2dTexture status){
    this->status = edk::gui2d::gui2dTexture::gui2dTextureNormal;
    switch(status){
    case edk::gui2d::gui2dTexture::gui2dTextureUp:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTextureUp;
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTexturePressedUp:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTexturePressedUp;
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTexturePressed:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTexturePressed;
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTextureSize:
    case edk::gui2d::gui2dTexture::gui2dTextureNormal:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTextureNormal;
        return true;
        break;
    }
    return false;
}
edk::gui2d::gui2dTexture edk::gui2d::ScrollBar2d::getStatus(){
    return this->statusInside;
}

