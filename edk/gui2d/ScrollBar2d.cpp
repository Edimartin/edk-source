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
    this->setBorderSize(0.05f);
    this->objPosition = 0.f;
    this->saveSize = 1.f;
    this->foregroundSize = 0.5f;
    this->saveSize = 0.f;
    //set the percents
    this->setPercent(50.0f,50.0f);

    this->saveStatusInside=this->statusInside=edk::gui2d::gui2dTextureNormal;
}
edk::gui2d::ScrollBar2d::~ScrollBar2d(){
    //clean the meshes
    this->unload();
}

//get the type
edk::gui2d::gui2dTypes edk::gui2d::ScrollBar2d::getType(){
    //
    return edk::gui2d::gui2dTypeScrollBar;
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
//function to calculate the percent values for X and Y
void edk::gui2d::ScrollBar2d::calculatePercents(){
    //
    edk::float32 div = 0.f;

    div = this->size.width - this->foregroundSize.width;
    if(div==0.f){
        this->percent.x = 1.f;
    }
    else{
        this->percent.x = (this->objPosition.x - this->position.x + this->size.width*0.5 - this->foregroundSize.width*0.5f)
                / (this->size.width - this->foregroundSize.width);
    }
    div = this->size.height - this->foregroundSize.height;
    if(div==0.f){
        this->percent.y = 1.f;
    }
    else{
        this->percent.y = (this->objPosition.y - this->position.y + this->size.height*0.5 - this->foregroundSize.height*0.5f)
                / (this->size.height - this->foregroundSize.height);
    }
    //change the percent to 0.f to 100.f
    this->percent.x *= 100.f;
    this->percent.y *= 100.f;
}
//calculate the position from the percents
void edk::gui2d::ScrollBar2d::calculatePositon(){
    this->objPosition.x = (this->position.x - this->size.width*0.5f + this->foregroundSize.width*0.5f) + (this->size.width - this->foregroundSize.width)
            * (this->percent.x * 0.01f);
    this->objPosition.y = (this->position.x - this->size.height*0.5f + this->foregroundSize.height*0.5f) + (this->size.height - this->foregroundSize.height)
            * (this->percent.y * 0.01f);
}

//Set the percent
void edk::gui2d::ScrollBar2d::setPercent(edk::vec2f32 percent){
    this->setPercent(percent.x,percent.y);
}
void edk::gui2d::ScrollBar2d::setPercent(edk::float32 x,edk::float32 y){
    this->percent.x = x;
    this->percent.y = y;

    //test the new percent
    if(this->percent.x<0.f)this->percent.x=0.f;
    if(this->percent.y<0.f)this->percent.y=0.f;
    if(this->percent.x>100.f)this->percent.x=100.f;
    if(this->percent.y>100.f)this->percent.y=100.f;

    this->calculatePositon();
}
void edk::gui2d::ScrollBar2d::setPercentX(edk::float32 x){
    this->percent.x = x;

    //test the new percent
    if(this->percent.x<0.f)this->percent.x=0.f;
    if(this->percent.y<0.f)this->percent.y=0.f;

    this->calculatePositon();
}
void edk::gui2d::ScrollBar2d::setPercentY(edk::float32 y){
    this->percent.y = y;

    //test the new percent
    if(this->percent.x>100.f)this->percent.x=100.f;
    if(this->percent.y>100.f)this->percent.y=100.f;

    this->calculatePositon();
}
//return the percent
edk::float32 edk::gui2d::ScrollBar2d::getPercentX(){
    return this->percent.x;
}
edk::float32 edk::gui2d::ScrollBar2d::getPercentY(){
    return this->percent.y;
}
edk::vec2f32 edk::gui2d::ScrollBar2d::getPercent(){
    return this->percent;
}

//load the button textures and meshes
bool edk::gui2d::ScrollBar2d::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        this->saveSize = this->size;
        this->objInside.load(edk::size2f32(this->foregroundSize * this->size));
        this->calculatePositon();
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
    this->saveSize.width = this->size.width+1.f;
    this->objInside.setBorderSize(size);
    return edk::gui2d::ObjectGui2d::setBorderSize(size);
}
//set the size
bool edk::gui2d::ScrollBar2d::setForegroundSize(edk::size2f32 size){
    //
    return this->setForegroundSize(size.width,size.height);
}
bool edk::gui2d::ScrollBar2d::setForegroundSize(edk::float32 width,edk::float32 height){
    bool ret = true;
    //test the size
    if(width<0.f){
        width=0.f;
        ret = false;
    }
    if(width>1.f){
        width=1.f;
        ret = false;
    }
    if(height<0.f){
        height=0.f;
        ret = false;
    }
    if(height>1.f){
        height=1.f;
        ret = false;
    }
    //set the size
    this->foregroundSize.width = width;
    this->foregroundSize.height = height;

    this->saveSize.width = this->saveSize.width+1.f;

    return ret;
}
//get the foregroundSize
edk::float32 edk::gui2d::ScrollBar2d::getForegroundWidth(){
    return this->foregroundSize.width;
}
edk::float32 edk::gui2d::ScrollBar2d::getForegroundHeight(){
    return this->foregroundSize.height;
}
edk::size2f32 edk::gui2d::ScrollBar2d::getForegroundSize(){
    return this->foregroundSize;
}

//set the color
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->objInside.setColor(r,g,b,a);
}
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->objInside.setColor(r,g,b);
}
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::color4f32 color){
    this->objInside.setColor(color);
}
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::color3f32 color){
    this->objInside.setColor(color);
}

//draw the button
void edk::gui2d::ScrollBar2d::draw(){
    edk::gui2d::ObjectGui2d::draw();

    //test if the size is different
    if(this->saveSize!=this->size){
        this->saveSize=this->size;
        //update the obj position
        this->objInside.updatePolygons(this->foregroundSize * this->size);
        this->calculatePositon();
        this->calculatePercents();
    }

    //put the transformation on a stack
    edk::GU::guPushMatrix();

    //add translate
    edk::GU::guTranslate2f32(this->position + this->objPosition);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    //edk::GU::guScale2f32(this->size);

    edk::GU::guEnable(GU_LIGHTING);

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
    edk::GU::guDisable(GU_LIGHTING);

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
        this->calculatePercents();
    }
    this->savePosition = this->objPosition;
}
void edk::gui2d::ScrollBar2d::moveTo(edk::vec2f32 position){
    this->objPosition = this->savePosition + position;

    //update the inside position
    this->updateObjPosition();
    this->calculatePercents();
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

