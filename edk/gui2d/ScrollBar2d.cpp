#include "ScrollBar2d.h"

/*
ScrollBar2d - ScrollBar for the GUI 2D library
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

static edk::uint32 borderScrollUpSize = 1167u;
static edk::char8 borderScrollUpName[19] = "borderScrollUp.png";
static edk::uchar8 borderScrollUp[1167] = {
    137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,40,0,0 \
    ,0,40,8,6,0,0,0,140,254,184,109,0,0,0,6,98,75,71,68,0,255 \
    ,0,255,0,255,160,189,167,147,0,0,0,9,112,72,89,115,0,0,14,196,0 \
    ,0,14,196,1,149,43,14,27,0,0,0,7,116,73,77,69,7,227,10,31,19 \
    ,26,15,32,60,102,135,0,0,4,28,73,68,65,84,88,195,221,152,75,139,35 \
    ,85,20,199,127,167,242,174,60,186,82,186,18,21,5,157,30,31,224,3,100,212 \
    ,237,184,20,193,157,232,8,202,32,8,50,56,234,39,112,225,7,112,47,186,113 \
    ,220,185,82,87,62,150,142,168,61,162,206,52,163,184,16,21,9,104,135,74,165 \
    ,82,169,132,78,29,55,213,77,165,234,102,146,78,170,155,193,255,242,156,186,247 \
    ,254,239,121,220,58,231,192,77,14,89,119,161,170,62,4,156,5,30,7,182,129 \
    ,59,128,86,162,14,128,63,128,95,129,203,192,87,34,242,227,177,223,70,85,219 \
    ,170,250,150,170,238,234,209,113,77,85,223,84,213,214,113,16,43,171,234,27,170 \
    ,186,167,155,227,95,85,189,168,170,229,162,200,157,86,213,31,180,120,92,81,213 \
    ,237,141,98,80,85,159,1,46,165,98,107,14,147,201,132,40,138,152,78,167,204 \
    ,102,51,226,56,6,192,178,44,74,165,18,213,106,149,122,189,78,173,86,91,116 \
    ,196,16,120,65,68,62,57,50,65,85,125,17,120,31,40,103,228,4,65,64,16 \
    ,4,135,132,150,193,178,44,90,173,22,237,118,219,164,222,7,94,22,145,15,87 \
    ,38,152,88,238,227,44,185,241,120,140,231,121,43,19,203,162,84,42,177,181,181 \
    ,69,163,209,48,145,124,86,68,62,93,74,80,85,239,5,118,128,185,235,250,190 \
    ,207,112,56,44,36,174,155,205,38,142,227,100,197,1,240,152,136,92,95,72,48 \
    ,201,172,239,128,135,211,242,189,189,61,162,40,42,244,101,104,52,26,184,174,155 \
    ,21,95,1,206,136,200,254,129,32,155,234,23,178,228,6,131,193,66,114,34,130 \
    ,109,219,52,26,13,42,149,10,150,101,1,16,199,49,211,233,148,40,138,8,195 \
    ,16,85,205,173,29,143,199,248,190,79,167,211,73,139,31,5,94,3,222,205,89 \
    ,80,85,155,192,239,192,173,233,77,250,253,254,66,55,117,58,157,67,82,139,16 \
    ,199,49,190,239,51,26,141,140,122,215,117,179,49,185,7,220,45,34,67,128,244 \
    ,238,175,166,201,29,88,207,100,181,110,183,139,227,56,75,201,29,100,176,227,56 \
    ,116,187,93,68,242,57,233,121,94,214,194,183,0,175,28,174,79,41,206,207,61 \
    ,80,195,33,179,217,44,183,161,227,56,216,182,125,228,152,179,109,155,110,183,107 \
    ,180,112,16,4,89,241,249,57,130,201,143,255,190,185,148,202,47,162,217,108,174 \
    ,69,46,157,24,205,102,51,39,55,156,117,191,170,62,152,182,224,83,217,63,68 \
    ,246,173,19,145,108,64,175,133,78,167,147,115,117,28,199,76,38,147,236,167,103 \
    ,211,4,207,164,53,166,172,181,109,123,165,152,91,37,38,77,94,48,156,249,68 \
    ,154,224,233,180,102,58,157,26,221,83,20,234,245,122,78,102,56,115,59,77,240 \
    ,182,180,198,148,28,149,74,165,48,130,213,106,53,39,51,156,121,123,154,96,59 \
    ,27,19,38,215,20,5,203,178,140,113,152,65,59,251,204,156,40,76,127,23,227 \
    ,101,82,117,217,13,173,181,110,5,179,232,239,178,130,135,230,254,36,127,103,203 \
    ,162,21,130,120,109,152,246,50,156,249,87,154,224,245,101,65,92,100,53,99,218 \
    ,203,112,230,47,105,130,223,44,123,6,194,48,44,196,205,113,28,19,134,225,42 \
    ,207,216,215,105,130,95,164,53,181,90,45,23,19,170,138,239,251,27,19,28,12 \
    ,6,185,4,177,44,203,100,193,47,15,9,138,200,79,192,213,180,182,213,202,247 \
    ,73,163,209,200,120,251,85,17,134,161,113,189,225,172,93,17,185,150,125,102,62 \
    ,152,123,132,218,109,99,178,120,158,183,22,201,48,12,241,60,207,152,28,134,102 \
    ,234,189,19,45,88,7,131,193,194,75,45,40,88,239,18,145,96,206,130,34,50 \
    ,2,222,201,6,174,201,213,7,238,238,245,122,120,158,71,20,69,115,9,20,199 \
    ,49,81,20,225,121,30,189,94,111,33,185,118,187,109,74,142,183,15,200,45,106 \
    ,154,190,5,30,73,203,251,253,62,227,241,248,36,154,166,157,164,105,154,221,168 \
    ,237,188,39,249,176,115,51,180,157,150,161,231,248,13,56,151,52,211,115,133,166 \
    ,235,186,198,196,57,74,227,238,186,174,137,220,62,240,92,150,220,178,209,199,185 \
    ,36,179,115,83,168,225,112,88,244,232,227,37,17,185,180,206,240,232,105,224,163 \
    ,108,57,182,202,240,168,92,46,83,169,84,150,13,143,124,224,121,17,249,108,147 \
    ,178,232,148,170,238,28,195,248,237,251,100,204,82,216,0,243,245,100,248,184,41 \
    ,254,81,213,11,170,90,162,104,168,106,43,25,227,94,93,131,216,207,201,148,246 \
    ,72,35,224,77,134,232,15,36,237,234,147,192,41,224,206,212,160,115,8,252,153 \
    ,148,76,151,129,207,69,100,151,255,35,254,3,112,247,144,62,219,151,99,215,0 \
    ,0,0,0,73,69,78,68,174,66,96,130
};

edk::gui2d::ScrollBar2d::ScrollBar2d(){
    //
    this->setBorderSize(0.5f);edkEnd();
    this->objPosition = 0.f;edkEnd();
    this->saveSize = 1.f;edkEnd();
    this->foregroundSize = 0.5f;edkEnd();
    this->saveSize = 0.f;edkEnd();
    //set the percents
    this->setPercent(50.0f,50.0f);edkEnd();

    this->saveStatusInside=this->statusInside=edk::gui2d::gui2dTextureNormal;edkEnd();
}
edk::gui2d::ScrollBar2d::~ScrollBar2d(){
    //clean the meshes
    this->unload();edkEnd();
}

//get the type
edk::gui2d::gui2dTypes edk::gui2d::ScrollBar2d::getType(){
    //
    return edk::gui2d::gui2dTypeScrollBar;edkEnd();
}

void edk::gui2d::ScrollBar2d::updateObjPosition(){
    //update X
    edk::vec2f32 position = this->objPosition-this->position;edkEnd();
    if(position.x + (this->foregroundSize.width*(this->size.width*0.5))>(this->size.width*0.5)){
        //
        this->objPosition.x = this->position.x + (this->size.width*0.5) - (this->foregroundSize.width*(this->size.width*0.5));edkEnd();
    }
    if(position.x - (this->foregroundSize.width*(this->size.width*0.5))<(this->size.width*-0.5)){
        //
        this->objPosition.x = this->position.x - (this->size.width*0.5) + (this->foregroundSize.width*(this->size.width*0.5));edkEnd();
    }
    //update Y
    if(position.y + (this->foregroundSize.height*(this->size.height*0.5))>(this->size.height*0.5)){
        //
        this->objPosition.y = this->position.y + (this->size.height*0.5) - (this->foregroundSize.height*(this->size.height*0.5));edkEnd();
    }
    if(position.y - (this->foregroundSize.height*(this->size.height*0.5))<(this->size.height*-0.5)){
        //
        this->objPosition.y = this->position.y - (this->size.height*0.5) + (this->foregroundSize.height*(this->size.height*0.5));edkEnd();
    }
}
//function to calculate the percent values for X and Y
void edk::gui2d::ScrollBar2d::calculatePercents(){
    //
    edk::float32 div = 0.f;edkEnd();

    div = this->size.width - this->foregroundSize.width;edkEnd();
    if(div==0.f){
        this->percent.x = 1.f;edkEnd();
    }
    else{
        this->percent.x = (this->objPosition.x - this->position.x + this->size.width*0.5 - this->foregroundSize.width*0.5f)
                / (this->size.width - this->foregroundSize.width);edkEnd();
    }
    div = this->size.height - this->foregroundSize.height;edkEnd();
    if(div==0.f){
        this->percent.y = 1.f;edkEnd();
    }
    else{
        this->percent.y = (this->objPosition.y - this->position.y + this->size.height*0.5 - this->foregroundSize.height*0.5f)
                / (this->size.height - this->foregroundSize.height);edkEnd();
    }
    //change the percent to 0.f to 100.f
    this->percent.x *= 100.f;edkEnd();
    this->percent.y *= 100.f;edkEnd();
}
//calculate the position from the percents
void edk::gui2d::ScrollBar2d::calculatePosition(){
    this->objPosition.x = (this->position.x - this->size.width*0.5f + this->foregroundSize.width*0.5f) + (this->size.width - this->foregroundSize.width)
            * (this->percent.x * 0.01f);edkEnd();
    this->objPosition.y = (this->position.x - this->size.height*0.5f + this->foregroundSize.height*0.5f) + (this->size.height - this->foregroundSize.height)
            * (this->percent.y * 0.01f);edkEnd();
}

//Set the percent
void edk::gui2d::ScrollBar2d::setPercent(edk::vec2f32 percent){
    this->setPercent(percent.x,percent.y);edkEnd();
}
void edk::gui2d::ScrollBar2d::setPercent(edk::float32 x,edk::float32 y){
    this->percent.x = x;edkEnd();
    this->percent.y = y;edkEnd();

    //test the new percent
    if(this->percent.x<0.f){
        this->percent.x=0.f;edkEnd();
    }
    if(this->percent.y<0.f){
        this->percent.y=0.f;edkEnd();
    }
    if(this->percent.x>100.f){
        this->percent.x=100.f;edkEnd();
    }
    if(this->percent.y>100.f){
        this->percent.y=100.f;edkEnd();
    }

    this->calculatePosition();edkEnd();
}
void edk::gui2d::ScrollBar2d::setPercentX(edk::float32 x){
    this->percent.x = x;edkEnd();

    //test the new percent
    if(this->percent.x<0.f){
        this->percent.x=0.f;edkEnd();
    }
    if(this->percent.y<0.f){
        this->percent.y=0.f;edkEnd();
    }

    this->calculatePosition();edkEnd();
}
void edk::gui2d::ScrollBar2d::setPercentY(edk::float32 y){
    this->percent.y = y;edkEnd();

    //test the new percent
    if(this->percent.x>100.f){
        this->percent.x=100.f;edkEnd();
    }
    if(this->percent.y>100.f){
        this->percent.y=100.f;edkEnd();
    }

    this->calculatePosition();edkEnd();
}
//return the percent
edk::float32 edk::gui2d::ScrollBar2d::getPercentX(){
    return this->percent.x;edkEnd();
}
edk::float32 edk::gui2d::ScrollBar2d::getPercentY(){
    return this->percent.y;edkEnd();
}
edk::vec2f32 edk::gui2d::ScrollBar2d::getPercent(){
    return this->percent;edkEnd();
}

//load the button textures and meshes
bool edk::gui2d::ScrollBar2d::load(){
    if(edk::gui2d::ObjectGui2d::load()){
        this->saveSize = this->size;edkEnd();
        this->objInside.load(edk::size2f32(this->foregroundSize * this->size));edkEnd();
        //update the obj position
        this->calculatePosition();edkEnd();
        this->updateObjPosition();edkEnd();
        this->calculatePercents();edkEnd();

        this->loadSpriteFromMemory(borderScrollUpName,borderScrollUp,borderScrollUpSize);edkEnd();
        this->loadSpritePressedFromMemory(borderScrollUpName,borderScrollUp,borderScrollUpSize);edkEnd();
        this->loadSpriteUpFromMemory(borderScrollUpName,borderScrollUp,borderScrollUpSize);edkEnd();
        this->loadSpritePressedUpFromMemory(borderScrollUpName,borderScrollUp,borderScrollUpSize);edkEnd();

        return true;
    }
    return false;
}
void edk::gui2d::ScrollBar2d::unload(){
    this->obj.unload();edkEnd();
    edk::gui2d::ObjectGui2d::unload();edkEnd();
}
void edk::gui2d::ScrollBar2d::update(){
    edk::gui2d::ObjectGui2d::update();edkEnd();
}

//set border size
bool edk::gui2d::ScrollBar2d::setBorderSize(edk::float32 size){
    this->saveSize.width = this->size.width+1.f;edkEnd();
    this->objInside.setBorderSize(size);edkEnd();
    return edk::gui2d::ObjectGui2d::setBorderSize(size);edkEnd();
}
//set the size
bool edk::gui2d::ScrollBar2d::setForegroundSize(edk::size2f32 size){
    //
    return this->setForegroundSize(size.width,size.height);edkEnd();
}
bool edk::gui2d::ScrollBar2d::setForegroundSize(edk::float32 width,edk::float32 height){
    bool ret = true;edkEnd();
    //test the size
    if(width<0.f){
        width=0.f;edkEnd();
        ret = false;edkEnd();
    }
    if(width>1.f){
        width=1.f;edkEnd();
        ret = false;edkEnd();
    }
    if(height<0.f){
        height=0.f;edkEnd();
        ret = false;edkEnd();
    }
    if(height>1.f){
        height=1.f;edkEnd();
        ret = false;edkEnd();
    }
    //set the size
    this->foregroundSize.width = width;edkEnd();
    this->foregroundSize.height = height;edkEnd();

    this->saveSize.width = this->saveSize.width+1.f;edkEnd();

    return ret;
}
//get the foregroundSize
edk::float32 edk::gui2d::ScrollBar2d::getForegroundWidth(){
    return this->foregroundSize.width;edkEnd();
}
edk::float32 edk::gui2d::ScrollBar2d::getForegroundHeight(){
    return this->foregroundSize.height;edkEnd();
}
edk::size2f32 edk::gui2d::ScrollBar2d::getForegroundSize(){
    return this->foregroundSize;edkEnd();
}

//set the color
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->objInside.setColor(r,g,b,a);edkEnd();
}
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->objInside.setColor(r,g,b);edkEnd();
}
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::color4f32 color){
    this->objInside.setColor(color);edkEnd();
}
void edk::gui2d::ScrollBar2d::setForegroundColor(edk::color3f32 color){
    this->objInside.setColor(color);edkEnd();
}

//draw the button
void edk::gui2d::ScrollBar2d::draw(){
    edk::gui2d::ObjectGui2d::draw();edkEnd();

    //test if the size is different
    if(this->saveSize!=this->size){
        this->saveSize=this->size;edkEnd();
        //update the obj position
        this->objInside.updatePolygons(this->foregroundSize * this->size);edkEnd();
        this->calculatePosition();edkEnd();
        this->calculatePercents();edkEnd();
    }

    //put the transformation on a stack
    edk::GU::guPushMatrix();edkEnd();

    //add translate
    edk::GU::guTranslate2f32(this->objPosition);edkEnd();
    //add rotation
    edk::GU::guRotateZf32(this->angle);edkEnd();
    //add scale
    //edk::GU::guScale2f32(this->size);edkEnd();

    edk::GU::guEnable(GU_LIGHTING);edkEnd();

    switch(this->statusInside){
    case gui2dTextureUp:
        this->objInside.drawUp();edkEnd();
        break;
    case gui2dTexturePressed:
        this->objInside.drawPressed();edkEnd();
        break;
    case gui2dTexturePressedUp:
        this->objInside.drawPressedUp();edkEnd();
        break;
    case gui2dTextureSize:
    case gui2dTextureNormal:
        this->objInside.drawNormal();edkEnd();
        break;
    }
    edk::GU::guDisable(GU_LIGHTING);edkEnd();

    edk::GU::guPopMatrix();edkEnd();
}

//move functions
void edk::gui2d::ScrollBar2d::startMove(edk::vec2f32 mousePosition){
    //move the objPosition to mousePosition
    this->objPosition = mousePosition;edkEnd();
    //update the inside position
    this->updateObjPosition();edkEnd();
    this->calculatePercents();edkEnd();
    this->savePosition = this->objPosition;edkEnd();
}
void edk::gui2d::ScrollBar2d::moveTo(edk::vec2f32 position){
    this->objPosition = this->savePosition + position;edkEnd();
    //update the inside position
    this->updateObjPosition();edkEnd();
    this->calculatePercents();edkEnd();
}
void edk::gui2d::ScrollBar2d::cancelMove(){
    this->objPosition = this->savePosition;edkEnd();
}
//return true if the object can be moved
bool edk::gui2d::ScrollBar2d::canMove(){
    return true;
}
bool edk::gui2d::ScrollBar2d::setStatus(edk::gui2d::gui2dTexture status){
    this->status = edk::gui2d::gui2dTexture::gui2dTextureNormal;edkEnd();
    switch(status){
    case edk::gui2d::gui2dTexture::gui2dTextureUp:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTextureUp;edkEnd();
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTexturePressedUp:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTexturePressedUp;edkEnd();
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTexturePressed:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTexturePressed;edkEnd();
        return true;
        break;
    case edk::gui2d::gui2dTexture::gui2dTextureSize:
    case edk::gui2d::gui2dTexture::gui2dTextureNormal:
        this->statusInside = edk::gui2d::gui2dTexture::gui2dTextureNormal;edkEnd();
        return true;
        break;
    }
    return false;
}
edk::gui2d::gui2dTexture edk::gui2d::ScrollBar2d::getStatus(){
    return this->statusInside;edkEnd();
}

