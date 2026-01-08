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

#ifdef printMessages
#pragma message "            Inside ObjectGui2d.cpp"
#endif

edk::char8 gui2dTypeString[edk::gui2d::gui2dTypeSize][128u] = {
    "gui2dTypeObject",
    "gui2dTypeButton",
    "gui2dTypeScrollBar",
    "gui2dTypeMenu",
    "gui2dTypeText",
    "gui2dTypeTextField"
};

edk::char8 gui2dSymbolsString[edk::gui2d::gui2dTextureSize][128u] = {
    "gui2dTextureNormal",
    "gui2dTextureUp",
    "gui2dTexturePressed",
    "gui2dTexturePressedUp"
};

edk::gui2d::ObjectGui2d::ObjectGui2d(){
    this->classThis=NULL;
    this->Constructor();
}
edk::gui2d::ObjectGui2d::~ObjectGui2d(){
    this->Destructor();
}

void edk::gui2d::ObjectGui2d::Constructor(){
    edk::Object2DValues::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->obj.Constructor();
        this->sprite.Constructor();
        this->center.Constructor();
        this->centerS.Constructor();
        this->spritePolygon.Constructor();
        this->text.Constructor();
        this->matrixPosition.Constructor();
        this->matrixPivo.Constructor();
        this->matrixAngle.Constructor();
        this->matrixSize.Constructor();
        this->matrixTransform.Constructor();

        this->type=edk::TypeObject2DGui;
        this->percent1=this->percent2=this->resize=0.f;
        for(edk::uint32 i = 0u;i<edk::gui2d::gui2dTextureSize;i++){
            this->spriteSize[i].width = this->spriteSize[i].height = 0.f;
        }
        this->textSize = this->getTextTemplateScale();
        this->setStatus(edk::gui2d::gui2dTextureNormal);
        this->saveStatus = this->status;
        this->pressed = false;
        this->drawText = false;
        this->selected=false;
    }
}
void edk::gui2d::ObjectGui2d::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->obj.Destructor();
        this->sprite.Destructor();
        this->center.Destructor();
        this->centerS.Destructor();
        this->spritePolygon.Destructor();
        this->text.Destructor();
        this->matrixPosition.Destructor();
        this->matrixPivo.Destructor();
        this->matrixAngle.Destructor();
        this->matrixSize.Destructor();
        this->matrixTransform.Destructor();
    }
    edk::Object2DValues::Destructor();
}

bool edk::gui2d::ObjectGui2d::writeBoundingBox(edk::rectf32* rect){
    //multiply the matrix by
    this->matrixTransform.setIdentity(1.f,0.f);
    //first copy the matrix
    //generate transform matrices
    edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
    edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
    edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
    edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
    //translate
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
    //angle
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
    //scale
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
    //Pivo
    this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

    return this->obj.calculateMeshBoundingBox(rect,&this->matrixTransform);
}
bool edk::gui2d::ObjectGui2d::writeBoundingBox(edk::rectf32* rect,edk::vector::Matrixf32<3u,3u>* transformMat){
    //first copy the matrix
    if(this->matrixTransform.cloneFrom(transformMat)){
        //generate transform matrices
        edk::Math::generateTranslateMatrix(this->position,&this->matrixPosition);
        edk::Math::generateRotateMatrixZ(this->angle,&this->matrixAngle);
        edk::Math::generateScaleMatrix(this->size,&this->matrixSize);
        edk::Math::generateTranslateMatrix(this->pivo*-1.0f,&this->matrixPivo);
        //multiply the matrix by
        //translate
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPosition);
        //angle
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixAngle);
        //scale
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixSize);
        //Pivo
        this->matrixTransform.multiplyThisWithMatrix(&this->matrixPivo);

        return this->obj.calculateMeshBoundingBox(rect,&this->matrixTransform);
    }
    return true;
}

void edk::gui2d::ObjectGui2d::drawStart(){
    //
    //put the transformation on a stack
    edk::GU::guUseMatrix(GU_MODELVIEW);
    edk::GU::guPushMatrix();

    //add translate
    edk::GU::guTranslate2f32(this->position);
    //add rotation
    edk::GU::guRotateZf32(this->angle);
    //add scale
    //edk::GU::guScale2f32(this->size);
}
void edk::gui2d::ObjectGui2d::drawObject(){
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
}
void edk::gui2d::ObjectGui2d::drawObjectSelection(){
    this->obj.drawSelection();
}
void edk::gui2d::ObjectGui2d::drawSprite(){
    //test if have the texture
    if(this->sprite.material.getTexture(this->status)){
        //draw the srite on the button
        this->sprite.drawOneTexture(this->status);
    }
}
void edk::gui2d::ObjectGui2d::drawTextFont(){
    if(this->text.haveText() && this->drawText){
        this->text.draw(edk::color4f32(0,0,0,1));
    }
}
void edk::gui2d::ObjectGui2d::drawTextFontWire(){
    if(this->text.haveText() && this->drawText){
        this->text.drawWire(edk::color4f32(0,0,0,1));
        this->text.drawPivo(1.f,edk::color3f32(0.f,0.f,0.f));
    }
}
void edk::gui2d::ObjectGui2d::drawEnd(){
    //
    edk::GU::guUseMatrix(GU_MODELVIEW);
    edk::GU::guPopMatrix();
}
void edk::gui2d::ObjectGui2d::runTextSize(){
    //test if have the text
    //get the text size
    edk::size2f32 sizeText = edk::size2f32(this->text.getMapSizeWidth() * this->textSize.width
                                           ,this->text.getMapSizeHeight() * this->textSize.height
                                           );

    //calculate the centerSize
    edk::size2f32 centerSize = edk::size2f32(edk::Math::module(this->center.getVertexPosition(1u).x)
                                             +
                                             edk::Math::module(this->center.getVertexPosition(0u).x),
                                             edk::Math::module(this->center.getVertexPosition(1u).y)
                                             +
                                             edk::Math::module(this->center.getVertexPosition(0u).y)
                                             );
    if(centerSize.width>0.f && centerSize.height>0.f){
        this->drawText = true;
        //
        this->updateTextSize(sizeText,centerSize,this->text.getMapSize());
    }
    else{
        this->drawText = false;
        this->text.setScale(0.01f,0.01f);
    }
}
void edk::gui2d::ObjectGui2d::calculateTextScale(edk::size2f32 scale){
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

    this->runTextSize();
}
//get the text scale template
edk::size2f32 edk::gui2d::ObjectGui2d::getTextTemplateScale(){
    return edk::size2f32(1.f,2.f);
}
void edk::gui2d::ObjectGui2d::updateTextSize(edk::size2f32 sizeText,edk::size2f32 centerSize,edk::size2ui32 mapSize){
    if(centerSize.width>centerSize.height){
        //center size width bigger than height
        this->percent1 = (edk::float32)centerSize.width/(edk::float32)centerSize.height;
        this->percent2 = sizeText.width/sizeText.height;
        if(this->percent1>this->percent2){
            //
            this->text.setScale((centerSize.height * (this->percent2))/(edk::float32)mapSize.width,
                                (centerSize.height)/(edk::float32)mapSize.height
                                );
        }
        else if(this->percent2>this->percent1){
            //
            this->percent2 = sizeText.height/sizeText.width;
            this->text.setScale(centerSize.width/(edk::float32)mapSize.width,
                                (centerSize.width * this->percent2)/(edk::float32)mapSize.height
                                );
        }
        else{
            //
            this->text.setScale(centerSize.width/(edk::float32)mapSize.width,
                                centerSize.height/(edk::float32)mapSize.height
                                );
        }
    }
    else if(centerSize.height>centerSize.width){
        //center size height bigger than width
        this->percent1 = (edk::float32)centerSize.height/(edk::float32)centerSize.width;
        this->percent2 = sizeText.height/sizeText.width;
        if(this->percent1>this->percent2){
            //
            this->text.setScale((centerSize.width)/(edk::float32)mapSize.width,
                                (centerSize.width * this->percent2)/(edk::float32)mapSize.height
                                );
        }
        else if(this->percent2>this->percent1){
            //
            this->percent2 = sizeText.width/sizeText.height;
            this->text.setScale((centerSize.height * this->percent2)/(edk::float32)mapSize.width,
                                centerSize.height/(edk::float32)mapSize.height
                                );
        }
        else{
            //
            this->text.setScale(centerSize.height/(edk::float32)mapSize.height,
                                centerSize.width/(edk::float32)mapSize.width
                                );
        }
    }
    else{
        //center size equal
        if(sizeText.width>sizeText.height){
            this->percent2 = sizeText.height/sizeText.width;
            //
            this->text.setScale((centerSize.width)/(edk::float32)mapSize.width,
                                (centerSize.width * this->percent2)/(edk::float32)mapSize.height
                                );
        }
        else if(sizeText.height>sizeText.width){
            this->percent2 = sizeText.width/sizeText.height;
            //
            this->text.setScale((centerSize.height * this->percent2)/(edk::float32)mapSize.width,
                                (centerSize.height)/(edk::float32)mapSize.height
                                );
        }
        else{
            //
            this->text.setScale(centerSize.height/(edk::float32)mapSize.height,
                                centerSize.width/(edk::float32)mapSize.width
                                );
        }
    }
    //set the text position
    sizeText = edk::size2f32(mapSize.width * this->text.getMapScaleWidth()
                             ,mapSize.height * this->text.getMapScaleHeight()
                             );
    //set the text position
    this->text.setPosition((sizeText.width*-0.5f)
                           + (this->text.getMapScaleWidth()*0.5f)
                           ,
                           (sizeText.height*-0.5f)
                           + (this->text.getMapScaleHeight()*0.5f)
                           );
}

//get GUI type
edk::gui2d::gui2dTypes edk::gui2d::ObjectGui2d::getTypeGUI(){
    return this->typeGUI;
}
edk::char8* edk::gui2d::ObjectGui2d::getStringTypeGUI(){
    return (edk::char8*)gui2dTypeString[this->getTypeGUI()];
}
edk::char8* edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypes type){
    if(type<edk::gui2d::gui2dTypeSize){
        return (edk::char8*)gui2dTypeString[type];
    }
    return (edk::char8*)gui2dTypeString[gui2dTypeObject];
}

//LOAD SPRITES
bool edk::gui2d::ObjectGui2d::loadSprite(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSprite((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSprite(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpriteNormal(name,minFilter,magFilter);
}

bool edk::gui2d::ObjectGui2d::loadSpriteFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpriteFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpriteNormalFromMemory(name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpriteFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpriteNormalFromPack(pack,name,minFilter,magFilter);
}
void edk::gui2d::ObjectGui2d::removeSprite(){
    this->obj.removeSpriteNormal();
}
//load pressed sprite
bool edk::gui2d::ObjectGui2d::loadSpritePressed(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpritePressed((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressed(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpritePressed(name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpritePressedFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpritePressedFromMemory(name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpritePressedFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpritePressedFromPack(pack,name,minFilter,magFilter);
}
void edk::gui2d::ObjectGui2d::removeSpritePressed(){
    this->obj.removeSpritePressed();
}
//load UP sprite
bool edk::gui2d::ObjectGui2d::loadSpriteUp(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpriteUp((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteUp(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpriteUp(name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpriteUpFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpriteUpFromMemory(name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpriteUpFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpriteUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpriteUpFromPack(pack,name,minFilter,magFilter);
}
void edk::gui2d::ObjectGui2d::removeSpriteUp(){
    this->obj.removeSpriteUp();
}
//load UP sprite
bool edk::gui2d::ObjectGui2d::loadSpritePressedUp(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpritePressedUp((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUp(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpritePressedUp(name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpritePressedUpFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpritePressedUpFromMemory(name,sprite,size,minFilter,magFilter);
}
void edk::gui2d::ObjectGui2d::removeSpritePressedUp(){
    this->obj.removeSpritePressedUp();
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSpritePressedUpFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSpritePressedUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->obj.loadSpritePressedUpFromPack(pack,name,minFilter,magFilter);
}

//Load button symbol normal
bool edk::gui2d::ObjectGui2d::loadSymbol(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbol((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbol(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTextureNormal,minFilter,magFilter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureNormal] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureNormal);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTextureNormal,minFilter,magFilter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureNormal] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureNormal);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTextureFromPack(pack,name,edk::gui2d::gui2dTextureNormal,minFilter,magFilter)){
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
bool edk::gui2d::ObjectGui2d::loadSymbolPressed(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolPressed((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressed(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTexturePressed,minFilter,magFilter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressed] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressed);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolPressedFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTexturePressed,minFilter,magFilter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressed] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressed);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolPressedFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTextureFromPack(pack,name,edk::gui2d::gui2dTexturePressed,minFilter,magFilter)){
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
bool edk::gui2d::ObjectGui2d::loadSymbolUp(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolUp((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolUp(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTextureUp,minFilter,magFilter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureUp);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolUpFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTextureUp,minFilter,magFilter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTextureUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTextureUp);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolUpFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTextureFromPack(pack,name,edk::gui2d::gui2dTextureUp,minFilter,magFilter)){
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
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUp(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolPressedUp((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUp(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTexture(name,edk::gui2d::gui2dTexturePressedUp,minFilter,magFilter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressedUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressedUp);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUpFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolPressedUpFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUpFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTextureFromMemory(name,sprite,size,edk::gui2d::gui2dTexturePressedUp,minFilter,magFilter)){
        //get the texture size
        this->spriteSize[edk::gui2d::gui2dTexturePressedUp] = this->sprite.material.getTextureSize(edk::gui2d::gui2dTexturePressedUp);
        return true;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUpFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolPressedUpFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolPressedUpFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    if(this->sprite.material.loadTextureFromPack(pack,name,edk::gui2d::gui2dTexturePressedUp,minFilter,magFilter)){
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
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatus(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolAllStatus((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatus(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    bool ret=true;
    if(!this->loadSymbol(name,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolUp(name,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressed(name,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressedUp(name,minFilter,magFilter)){
        ret = false;
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolAllStatusFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    bool ret=true;
    if(!this->loadSymbolFromMemory(name,sprite,size,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolUpFromMemory(name,sprite,size,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressedFromMemory(name,sprite,size,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressedUpFromMemory(name,sprite,size,minFilter,magFilter)){
        ret = false;
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolAllStatusFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    bool ret=true;
    if(!this->loadSymbolFromPack(pack,name,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolUpFromPack(pack,name,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressedFromPack(pack,name,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressedUpFromPack(pack,name,minFilter,magFilter)){
        ret = false;
    }
    return ret;
}
//Load button symbolAllUPStatus
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatus(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolAllUPStatus((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatus(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    bool ret=true;
    if(!this->loadSymbolUp(name,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressedUp(name,minFilter,magFilter)){
        ret = false;
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolAllUPStatusFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    bool ret=true;
    if(!this->loadSymbolUpFromMemory(name,sprite,size,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressedUpFromMemory(name,sprite,size,minFilter,magFilter)){
        ret = false;
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolAllUPStatusFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllUPStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    bool ret=true;
    if(!this->loadSymbolUpFromPack(pack,name,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressedUpFromPack(pack,name,minFilter,magFilter)){
        ret = false;
    }
    return ret;
}
//Load button symbolAllNormalAndPressedStatus
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatus(const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolAllNormalAndPressedStatus((edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatus(edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    bool ret=true;
    if(!this->loadSymbol(name,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressed(name,minFilter,magFilter)){
        ret = false;
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatusFromMemory(const edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolAllNormalAndPressedStatusFromMemory((edk::char8*) name,sprite,size,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatusFromMemory(edk::char8* name,edk::uint8* sprite,edk::uint32 size,edk::uint32 minFilter,edk::uint32 magFilter){
    bool ret=true;
    if(!this->loadSymbolFromMemory(name,sprite,size,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressedFromMemory(name,sprite,size,minFilter,magFilter)){
        ret = false;
    }
    return ret;
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatusFromPack(edk::pack::FilePackage* pack,const edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    return this->loadSymbolAllNormalAndPressedStatusFromPack(pack,(edk::char8*) name,minFilter,magFilter);
}
bool edk::gui2d::ObjectGui2d::loadSymbolAllNormalAndPressedStatusFromPack(edk::pack::FilePackage* pack,edk::char8* name,edk::uint32 minFilter,edk::uint32 magFilter){
    bool ret=true;
    if(!this->loadSymbolFromPack(pack,name,minFilter,magFilter)){
        ret = false;
    }
    if(!this->loadSymbolPressedFromPack(pack,name,minFilter,magFilter)){
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

bool edk::gui2d::ObjectGui2d::writeText(const edk::char8* text){
    return this->writeText((edk::char8*) text);
}
bool edk::gui2d::ObjectGui2d::writeText(edk::char8* text){
    return this->writeText(text,this->getTextTemplateScale());
}
bool edk::gui2d::ObjectGui2d::writeText(const edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    return this->writeText((edk::char8*) text,scaleWidth,scaleHeight);
}
bool edk::gui2d::ObjectGui2d::writeText(edk::char8* text,edk::float32 scaleWidth,edk::float32 scaleHeight){
    return this->writeText(text,edk::size2f32(scaleWidth,scaleHeight));
}
bool edk::gui2d::ObjectGui2d::writeText(const edk::char8* text,edk::size2f32 scale){
    return this->writeText((edk::char8*) text,scale);
}
bool edk::gui2d::ObjectGui2d::writeText(edk::char8* text,edk::size2f32 scale){
    this->cleanText();
    //test if receive a text
    if(text){
        //write the text
        if(this->text.createStringMapOneLine(text)){
            this->textString.setName(text);
            this->calculateTextScale(scale);
            return true;
        }
    }
    return false;
}
void edk::gui2d::ObjectGui2d::cleanText(){
    this->textString.cleanName();
    this->text.deleteMap();
}

//function to calculate boundingBox
bool edk::gui2d::ObjectGui2d::calculateBoundingBox(){
    return this->writeBoundingBox(&this->boundingBox);
}
bool edk::gui2d::ObjectGui2d::calculateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->writeBoundingBox(&this->boundingBox,transformMat);
}
bool edk::gui2d::ObjectGui2d::generateBoundingBox(){
    return this->writeBoundingBox(&this->boundingBox);
}
bool edk::gui2d::ObjectGui2d::generateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->writeBoundingBox(&this->boundingBox,transformMat);
}
//functions to calculate a new boundingBox
edk::rectf32 edk::gui2d::ObjectGui2d::calculateNewBoundingBox(){
    edk::rectf32 ret;
    this->writeBoundingBox(&ret);
    return ret;
}
edk::rectf32 edk::gui2d::ObjectGui2d::calculateNewBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    this->writeBoundingBox(&ret,transformMat);
    return ret;
}
edk::rectf32 edk::gui2d::ObjectGui2d::generateNewBoundingBox(){
    edk::rectf32 ret;
    this->writeBoundingBox(&ret);
    return ret;
}
edk::rectf32 edk::gui2d::ObjectGui2d::generateNewBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    edk::rectf32 ret;
    this->writeBoundingBox(&ret,transformMat);
    return ret;
}

//return a copy of the boundingBox
edk::rectf32 edk::gui2d::ObjectGui2d::getBoundingBox(){
    return this->boundingBox;
}

//load the button textures and meshes
bool edk::gui2d::ObjectGui2d::load(){
    this->selected=false;
    if(this->obj.load(this->size)){
        //
        return true;
    }
    return false;
}
void edk::gui2d::ObjectGui2d::unload(){
    this->selected=false;
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
        if(this->status>=edk::gui2d::gui2dTextureSize){
            this->status = edk::gui2d::gui2dTextureNormal;
        }
        this->saveStatus = this->status;

        //calculate the centerSize
        edk::size2f32 centerSize(edk::Math::module(this->center.getVertexPosition(1u).x)
                                 +
                                 edk::Math::module(this->center.getVertexPosition(0u).x),
                                 edk::Math::module(this->center.getVertexPosition(1u).y)
                                 +
                                 edk::Math::module(this->center.getVertexPosition(0u).y)
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
        this->runTextSize();

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
//select functions
void edk::gui2d::ObjectGui2d::select(){
    this->selected = true;
}
void edk::gui2d::ObjectGui2d::deselect(){
    this->selected = false;
}
bool edk::gui2d::ObjectGui2d::isSelected(){
    return this->selected;
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
    return this->obj.setBorderSize(size);
}

//return the object rectangle inside
edk::rectf32 edk::gui2d::ObjectGui2d::getInsideRect(){
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

    edk::rectf32 ret = this->obj.getRectCenter();
    ret.origin+=this->position;
    return ret;
}

//XML
bool edk::gui2d::ObjectGui2d::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_OBJ,nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //WRITE
                        //write the object type

                        xml->setSelectedString(this->getStringTypeGUI());

                        //
                        edk::char8* tempID = NULL;
                        edk::char8* strTemp = NULL;

                        tempID = edk::String::int64ToStr(id);
                        if(tempID){
                            //concat
                            strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_POSITION,tempID);
                            if(strTemp){
                                if(xml->addSelectedNextChild(strTemp)){
                                    if(xml->selectChild(strTemp)){
                                        xml->addSelectedNextAttribute("X",this->position.x);
                                        xml->addSelectedNextAttribute("Y",this->position.y);
                                        xml->selectFather();
                                    }
                                }
                                free(strTemp);
                            }
                        }
                        tempID = edk::String::int64ToStr(id);
                        if(tempID){
                            //concat
                            strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_ANGLE,tempID);
                            if(strTemp){
                                if(xml->addSelectedNextChild(strTemp)){
                                    if(xml->selectChild(strTemp)){
                                        xml->addSelectedNextAttribute("A",this->angle);
                                        xml->selectFather();
                                    }
                                }
                                free(strTemp);
                            }
                        }
                        tempID = edk::String::int64ToStr(id);
                        if(tempID){
                            //concat
                            strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_SIZE,tempID);
                            if(strTemp){
                                if(xml->addSelectedNextChild(strTemp)){
                                    if(xml->selectChild(strTemp)){
                                        xml->addSelectedNextAttribute("W",this->size.width);
                                        xml->addSelectedNextAttribute("H",this->size.height);
                                        xml->selectFather();
                                    }
                                }
                                free(strTemp);
                            }
                        }


                        //wrire the border values
                        this->obj.writeToXML(xml,id);


                        /*
    //sprite size
    edk::size2ui32 spriteSize[edk::gui2d::gui2dTextureSize];
    //temp
    edk::float32 percent1;
    edk::float32 percent2;
    edk::float32 resize;
    //object status
    edk::gui2d::gui2dTexture status;
    //save the object status to compare in update function
    edk::gui2d::gui2dTexture saveStatus;
    //save the position to move the object
    edk::vec2f32 savePosition;
*/

                        //gui2dTextureNormal;
                        xml->addSelectedNextAttribute(gui2dSymbolsString[edk::gui2d::gui2dTextureNormal],
                                this->sprite.material.getTextureName(edk::gui2d::gui2dTextureNormal)
                                );
                        //gui2dTextureUp;
                        xml->addSelectedNextAttribute(gui2dSymbolsString[edk::gui2d::gui2dTextureUp],
                                this->sprite.material.getTextureName(edk::gui2d::gui2dTextureUp)
                                );
                        //gui2dTexturePressed;
                        xml->addSelectedNextAttribute(gui2dSymbolsString[edk::gui2d::gui2dTexturePressed],
                                this->sprite.material.getTextureName(edk::gui2d::gui2dTexturePressed)
                                );
                        //gui2dTexturePressedUp;
                        xml->addSelectedNextAttribute(gui2dSymbolsString[edk::gui2d::gui2dTexturePressedUp],
                                this->sprite.material.getTextureName(edk::gui2d::gui2dTexturePressedUp)
                                );

                        xml->addSelectedNextAttribute(EDK_GUI2D_XML_GUI2D_STRING,this->textString.getName());

                        ret=true;
                        xml->selectFather();
                    }
                }
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_OBJ,nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //this->cleanMeshes();

                    edk::char8* tempID = NULL;
                    edk::char8* strTemp = NULL;

                    tempID = edk::String::int64ToStr(id);
                    if(tempID){
                        //concat
                        strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_POSITION,tempID);
                        if(strTemp){
                            if(xml->selectChild(strTemp)){
                                if(xml->haveAttributeName("X")){
                                    this->position.x = xml->getSelectedAttributeValueAsFloat32ByName("X");
                                }
                                if(xml->haveAttributeName("Y")){
                                    this->position.y = xml->getSelectedAttributeValueAsFloat32ByName("Y");
                                }
                                xml->selectFather();
                            }
                            free(strTemp);
                        }
                    }
                    tempID = edk::String::int64ToStr(id);
                    if(tempID){
                        //concat
                        strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_ANGLE,tempID);
                        if(strTemp){
                            if(xml->selectChild(strTemp)){
                                if(xml->haveAttributeName("A")){
                                    this->angle = xml->getSelectedAttributeValueAsFloat32ByName("A");
                                }
                                xml->selectFather();
                            }
                            free(strTemp);
                        }
                    }
                    tempID = edk::String::int64ToStr(id);
                    if(tempID){
                        //concat
                        strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_SIZE,tempID);
                        if(strTemp){
                            if(xml->selectChild(strTemp)){
                                if(xml->haveAttributeName("W")){
                                    this->size.width = xml->getSelectedAttributeValueAsFloat32ByName("W");
                                }
                                if(xml->haveAttributeName("H")){
                                    this->size.height = xml->getSelectedAttributeValueAsFloat32ByName("H");
                                }
                                xml->selectFather();
                            }
                            free(strTemp);
                        }
                    }

                    edk::char8* str=NULL;

                    //gui2dTextureNormal;
                    str = xml->getSelectedAttributeValueByName(gui2dSymbolsString[edk::gui2d::gui2dTextureNormal]);
                    if(str){
                        this->loadSymbol(str);
                        //free(str);
                    }
                    //gui2dTextureUp;
                    str = xml->getSelectedAttributeValueByName(gui2dSymbolsString[edk::gui2d::gui2dTextureUp]);
                    if(str){
                        this->loadSymbolUp(str);
                        //free(str);
                    }
                    //gui2dTexturePressed;
                    str = xml->getSelectedAttributeValueByName(gui2dSymbolsString[edk::gui2d::gui2dTexturePressed]);
                    if(str){
                        this->loadSymbolPressed(str);
                        //free(str);
                    }
                    //gui2dTexturePressedUp;
                    str = xml->getSelectedAttributeValueByName(gui2dSymbolsString[edk::gui2d::gui2dTexturePressedUp]);
                    if(str){
                        this->loadSymbolPressedUp(str);
                        //free(str);
                    }

                    str = xml->getSelectedAttributeValueByName(EDK_GUI2D_XML_GUI2D_STRING);
                    if(str){
                        this->writeText(str);
                        //free(str);
                    }

                    ret=true;
                    xml->selectFather();
                }
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
bool edk::gui2d::ObjectGui2d::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_OBJ,nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //this->cleanMeshes();

                    edk::char8* tempID = NULL;
                    edk::char8* strTemp = NULL;

                    tempID = edk::String::int64ToStr(id);
                    if(tempID){
                        //concat
                        strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_POSITION,tempID);
                        if(strTemp){
                            if(xml->selectChild(strTemp)){
                                if(xml->haveAttributeName("X")){
                                    this->position.x = xml->getSelectedAttributeValueAsFloat32ByName("X");
                                }
                                if(xml->haveAttributeName("Y")){
                                    this->position.y = xml->getSelectedAttributeValueAsFloat32ByName("Y");
                                }
                                xml->selectFather();
                            }
                            free(strTemp);
                        }
                    }
                    tempID = edk::String::int64ToStr(id);
                    if(tempID){
                        //concat
                        strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_ANGLE,tempID);
                        if(strTemp){
                            if(xml->selectChild(strTemp)){
                                if(xml->haveAttributeName("A")){
                                    this->angle = xml->getSelectedAttributeValueAsFloat32ByName("A");
                                }
                                xml->selectFather();
                            }
                            free(strTemp);
                        }
                    }
                    tempID = edk::String::int64ToStr(id);
                    if(tempID){
                        //concat
                        strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_SIZE,tempID);
                        if(strTemp){
                            if(xml->selectChild(strTemp)){
                                if(xml->haveAttributeName("W")){
                                    this->size.width = xml->getSelectedAttributeValueAsFloat32ByName("W");
                                }
                                if(xml->haveAttributeName("H")){
                                    this->size.height = xml->getSelectedAttributeValueAsFloat32ByName("H");
                                }
                                xml->selectFather();
                            }
                            free(strTemp);
                        }
                    }

                    edk::char8* str=NULL;

                    //gui2dTextureNormal;
                    str = xml->getSelectedAttributeValueByName(gui2dSymbolsString[edk::gui2d::gui2dTextureNormal]);
                    if(str){
                        this->loadSymbolFromPack(pack,str);
                        //free(str);
                    }
                    //gui2dTextureUp;
                    str = xml->getSelectedAttributeValueByName(gui2dSymbolsString[edk::gui2d::gui2dTextureUp]);
                    if(str){
                        this->loadSymbolUpFromPack(pack,str);
                        //free(str);
                    }
                    //gui2dTexturePressed;
                    str = xml->getSelectedAttributeValueByName(gui2dSymbolsString[edk::gui2d::gui2dTexturePressed]);
                    if(str){
                        this->loadSymbolPressedFromPack(pack,str);
                        //free(str);
                    }
                    //gui2dTexturePressedUp;
                    str = xml->getSelectedAttributeValueByName(gui2dSymbolsString[edk::gui2d::gui2dTexturePressedUp]);
                    if(str){
                        this->loadSymbolPressedUpFromPack(pack,str);
                        //free(str);
                    }

                    str = xml->getSelectedAttributeValueByName(EDK_GUI2D_XML_GUI2D_STRING);
                    if(str){
                        this->writeText(str);
                        //free(str);
                    }

                    ret=true;
                    xml->selectFather();
                }
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}

//draw the button
void edk::gui2d::ObjectGui2d::draw(){
    this->drawStart();

    this->drawObject();

    this->drawSprite();

    this->drawTextFont();

    this->drawEnd();
}
void edk::gui2d::ObjectGui2d::drawSelection(){
    this->drawStart();
    //draw the object
    this->drawObjectSelection();
    //
    this->drawEnd();
}
//return true if the object can be moved
bool edk::gui2d::ObjectGui2d::canMove(){
    return false;
}

//clone the gui object from
bool edk::gui2d::ObjectGui2d::cloneFrom(edk::gui2d::ObjectGui2d* obj){
    if(obj){
        this->obj.cloneFrom(&obj->obj);
        bool ret = edk::Object2DValues::cloneValuesFrom((edk::Object2DValues*)obj);
        this->loadSymbol(obj->sprite.material.getTextureName(edk::gui2d::gui2dTextureNormal));
        this->loadSymbolUp(obj->sprite.material.getTextureName(edk::gui2d::gui2dTextureUp));
        this->loadSymbolPressed(obj->sprite.material.getTextureName(edk::gui2d::gui2dTexturePressed));
        this->loadSymbolPressedUp(obj->sprite.material.getTextureName(edk::gui2d::gui2dTexturePressedUp));
        return ret;
    }
    return false;
}

