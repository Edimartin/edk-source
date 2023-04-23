#include "ViewMenu2d.h"

/*
ViewMenu2d - View to show a menu on GUI 2D library
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


edk::gui2d::MenuObj::MenuObj(){
    //
    this->active = false;edkEnd();
    this->id = 0u;edkEnd();
    this->status = edk::gui2d::gui2dTextureNormal;edkEnd();
    this->saveStatus = edk::gui2d::gui2dTextureSize;edkEnd();
    edk::uint8 size = edk::gui2d::gui2dTextureSize;edkEnd();
    for(edk::uint8 i=0u;i<size;i++){
        this->color[i] = edk::color4f32(1,1,1,1);edkEnd();
    }
    //load the mesh
    this->obj.addMesh(&this->meshObj);edkEnd();
    {
        edk::shape::Rectangle2D rect;edkEnd();
        rect.setPivoToCenter();edkEnd();
        rect.setPolygonColor(0,0,0,1);edkEnd();
        this->meshObj.addPolygon(rect);edkEnd();
        this->meshObj.material.setEmission(1,1,1,1);edkEnd();
    }
}
edk::gui2d::MenuObj::~MenuObj(){
    //
    this->str1.cleanName();edkEnd();
    this->str2.cleanName();edkEnd();
}

//get the type
edk::gui2d::gui2dTypes edk::gui2d::MenuObj::getType(){
    return edk::gui2d::gui2dTypeMenu;edkEnd();
}

void edk::gui2d::MenuObj::updatePositions(){
    //set the objects position based on the full size of the button

    this->sprite.position.x = this->obj.position.x - (this->obj.size.width * 0.5f) + this->sprite.size.width*0.5f + edkGui2dInsideBorder
            ;edkEnd();
    this->sprite.position.y = this->obj.position.y;edkEnd();

    //set the object in the position
    this->text1.setPosition(this->obj.position.x - (this->obj.size.width * 0.5f) + (this->text1.getMapScaleWidth() * 0.5f) + this->positionText1
                            ,this->obj.position.y
                            );edkEnd();
    //set the object in the position
    this->text2.setPosition(this->obj.position.x - (this->obj.size.width * 0.5f) + (this->text2.getMapScaleWidth() * 0.5f) + this->positionText2
                            ,this->obj.position.y
                            );edkEnd();
}

//load the object
bool edk::gui2d::MenuObj::loadObject(edk::uint32 id,edk::char8* spriteName,edk::char8* text1,edk::char8* text2){
    this->id = id;edkEnd();
    this->sprite.cleanMeshes();edkEnd();
    this->text1.deleteMap();edkEnd();
    this->str1.cleanName();edkEnd();
    this->text2.deleteMap();edkEnd();
    this->str2.cleanName();edkEnd();
    bool ret = true;edkEnd();
    this->positionText1 = this->positionText2 = 0.f;edkEnd();
    //set the object size
    this->obj.size = edk::size2f32(0,1);edkEnd();
    this->sprite.size = edkGui2dInsideHeight;edkEnd();


    this->obj.size.width += edkGui2dInsideBorder;edkEnd();
    if(spriteName){
        //
        edk::shape::Mesh2D* mesh = this->sprite.newMesh();edkEnd();
        if(mesh){
            edk::shape::Rectangle2D rect;edkEnd();
            rect.setPivoToCenter();edkEnd();
            mesh->addPolygon(rect);edkEnd();
            //load the texture
            if(mesh->material.loadTexture(spriteName,0u)){
                edk::size2ui32 texSize = mesh->material.getTextureSize(0u);edkEnd();
                if(texSize.width && texSize.height){
                    //test the size to set the sprite new size
                    if(texSize.width > texSize.height){
                        //
                        this->sprite.size.height = this->sprite.size.width * ((edk::float32)texSize.height / (edk::float32)texSize.width);edkEnd();
                    }
                    else{
                        this->sprite.size.width = this->sprite.size.height * ((edk::float32)texSize.width / (edk::float32)texSize.height);edkEnd();
                    }
                    this->obj.size.width += this->sprite.size.width;edkEnd();
                    this->obj.size.width += edkGui2dInsideBorder;edkEnd();
                }
                else{
                    this->sprite.removeAllMesh();edkEnd();
                    ret = false;edkEnd();
                }
            }
            else{
                this->sprite.removeAllMesh();edkEnd();
                ret = false;edkEnd();
            }
        }
    }
    else{
        this->sprite.size.width = 0.f;edkEnd();
    }
    if(text1){
        //test the size of the text
        if(edk::String::strSize(text1)){
            //create the fontMap
            this->text1.deleteMap();edkEnd();
            this->text1.setScale(edkGui2dInsideHeight*0.5f,edkGui2dInsideHeight);edkEnd();
            this->positionText1 = this->obj.size.width;edkEnd();
            if(this->text1.createStringMap(text1)){
                this->str1.setName(text1);edkEnd();
                this->obj.size.width += this->text1.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;edkEnd();
            }
            else{
                ret = false;edkEnd();
            }
        }
        this->obj.size.width += edkGui2dInsideBorder;edkEnd();
    }
    if(text2){

        //test the size of the text
        if(edk::String::strSize(text2)){
            //
            //create the fontMap
            this->text2.deleteMap();edkEnd();
            this->text2.setScale(edkGui2dInsideHeight*0.5f,edkGui2dInsideHeight);edkEnd();
            this->positionText2 = this->obj.size.width;edkEnd();
            if(this->text2.createStringMap(text2)){
                this->str2.setName(text2);edkEnd();
                this->obj.size.width += this->text2.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;edkEnd();
            }
            else{
                ret = false;edkEnd();
            }
        }
        this->obj.size.width += edkGui2dInsideBorder;edkEnd();

    }

    this->updatePositions();edkEnd();

    return ret;
}
bool edk::gui2d::MenuObj::loadObject(edk::uint32 id,const edk::char8* spriteName,edk::char8* text1,edk::char8* text2){
    return this->loadObject(id,(edk::char8*) spriteName,text1,text2);edkEnd();
}
bool edk::gui2d::MenuObj::loadObjectFromPack(edk::pack::FilePackage* pack,edk::uint32 id,edk::char8* spriteName,edk::char8* text1,edk::char8* text2){
    this->id = id;edkEnd();
    this->sprite.cleanMeshes();edkEnd();
    this->text1.deleteMap();edkEnd();
    this->str1.cleanName();edkEnd();
    this->text2.deleteMap();edkEnd();
    this->str2.cleanName();edkEnd();
    bool ret = true;edkEnd();
    this->positionText1 = this->positionText2 = 0.f;edkEnd();
    //set the object size
    this->obj.size = edk::size2f32(0,1);edkEnd();
    this->sprite.size = edkGui2dInsideHeight;edkEnd();


    this->obj.size.width += edkGui2dInsideBorder;edkEnd();
    if(spriteName && pack){
        //
        edk::shape::Mesh2D* mesh = this->sprite.newMesh();edkEnd();
        if(mesh){
            edk::shape::Rectangle2D rect;edkEnd();
            rect.setPivoToCenter();edkEnd();
            mesh->addPolygon(rect);edkEnd();
            //load the texture
            if(mesh->material.loadTextureFromPack(pack,spriteName,0u)){
                edk::size2ui32 texSize = mesh->material.getTextureSize(0u);edkEnd();
                if(texSize.width && texSize.height){
                    //test the size to set the sprite new size
                    if(texSize.width > texSize.height){
                        //
                        this->sprite.size.height = this->sprite.size.width * ((edk::float32)texSize.height / (edk::float32)texSize.width);edkEnd();
                    }
                    else{
                        this->sprite.size.width = this->sprite.size.height * ((edk::float32)texSize.width / (edk::float32)texSize.height);edkEnd();
                    }
                    this->obj.size.width += this->sprite.size.width;edkEnd();
                    this->obj.size.width += edkGui2dInsideBorder;edkEnd();
                }
                else{
                    this->sprite.removeAllMesh();edkEnd();
                    ret = false;edkEnd();
                }
            }
            else{
                this->sprite.removeAllMesh();edkEnd();
                ret = false;edkEnd();
            }
        }
    }
    else{
        this->sprite.size.width = 0.f;edkEnd();
    }
    if(text1){
        //test the size of the text
        if(edk::String::strSize(text1)){
            //create the fontMap
            this->text1.deleteMap();edkEnd();
            this->text1.setScale(edkGui2dInsideHeight*0.5f,edkGui2dInsideHeight);edkEnd();
            this->positionText1 = this->obj.size.width;edkEnd();
            if(this->text1.createStringMap(text1)){
                this->str1.setName(text1);edkEnd();
                this->obj.size.width += this->text1.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;edkEnd();
            }
            else{
                ret = false;edkEnd();
            }
        }
        this->obj.size.width += edkGui2dInsideBorder;edkEnd();
    }
    if(text2){

        //test the size of the text
        if(edk::String::strSize(text2)){
            //
            //create the fontMap
            this->text2.deleteMap();edkEnd();
            this->text2.setScale(edkGui2dInsideHeight*0.5f,edkGui2dInsideHeight);edkEnd();
            this->positionText2 = this->obj.size.width;edkEnd();
            if(this->text2.createStringMap(text2)){
                this->str2.setName(text2);edkEnd();
                this->obj.size.width += this->text2.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;edkEnd();
            }
            else{
                ret = false;edkEnd();
            }
        }
        this->obj.size.width += edkGui2dInsideBorder;edkEnd();

    }

    this->updatePositions();edkEnd();

    return ret;
}
bool edk::gui2d::MenuObj::loadObjectFromPack(edk::pack::FilePackage* pack,edk::uint32 id,const edk::char8* spriteName,edk::char8* text1,edk::char8* text2){
    return this->loadObjectFromPack(pack,id,(edk::char8*) spriteName,text1,text2);edkEnd();
}
//set the button position
void edk::gui2d::MenuObj::setPosition(edk::float32 x,edk::float32 y){
    this->setPosition(edk::vec2f32 (x,y));edkEnd();
}
void edk::gui2d::MenuObj::setPosition(edk::vec2f32 position){
    //
    this->obj.position = position;edkEnd();
    //update the positions
    this->updatePositions();edkEnd();
}
//set size
bool edk::gui2d::MenuObj::setSize(edk::size2f32 size){
    //
    if(size.width>0.f && size.height>0.f){
        //
        this->obj.size = size;edkEnd();
        this->updatePositions();edkEnd();
        return true;
    }
    return false;
}
bool edk::gui2d::MenuObj::setSize(edk::float32 width,edk::float32 height){
    //
    return this->setSize(edk::size2f32(width,height));edkEnd();
}

//get the size
edk::size2f32 edk::gui2d::MenuObj::getSize(){
    return this->obj.size;edkEnd();
}
//return the object strings pointer
edk::char8* edk::gui2d::MenuObj::getStr1(){
    if(this->str1.getSize()){
        return this->str1.getName();edkEnd();
    }
    return NULL;
}
edk::char8* edk::gui2d::MenuObj::getStr2(){
    if(this->str2.getSize()){
        return this->str2.getName();edkEnd();
    }
    return NULL;
}
void edk::gui2d::MenuObj::updateSizes(){
    this->positionText1 = this->positionText2 = 0.f;edkEnd();
    //set the object size
    this->obj.size = edk::size2f32(0,1);edkEnd();
    this->obj.size.width += edkGui2dInsideBorder;edkEnd();

    if(this->sprite.size.width>0.f){
        this->sprite.size = edkGui2dInsideHeight;edkEnd();
        this->obj.size.width += this->sprite.size.width;edkEnd();
        this->obj.size.width += edkGui2dInsideBorder;edkEnd();
    }
    else{
        this->sprite.size.height = edkGui2dInsideHeight;edkEnd();
    }

    if(this->text1.haveText()){
        this->positionText1 = this->obj.size.width;edkEnd();
        this->obj.size.width += this->text1.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;edkEnd();
        this->obj.size.width += edkGui2dInsideBorder;edkEnd();
    }
    if(this->text2.haveText()){
        this->positionText2 = this->obj.size.width;edkEnd();
        this->obj.size.width += this->text2.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;edkEnd();
        this->obj.size.width += edkGui2dInsideBorder;edkEnd();

    }
}
//set the status of the object to be draw
bool edk::gui2d::MenuObj::setStatus(edk::gui2d::gui2dTexture status){
    //
    if(status < edk::gui2d::gui2dTextureSize){
        //set the status
        this->status = status;edkEnd();
        return true;
    }
    return false;
}

void edk::gui2d::MenuObj::draw(){
    //test if the status is different
    if(this->saveStatus!=this->status){
        //set the color
        this->saveStatus=this->status;edkEnd();
        this->meshObj.material.setEmission(this->color[this->status]);edkEnd();
    }
    //
    this->obj.draw();edkEnd();
    this->obj.drawWire();edkEnd();

    this->sprite.draw();edkEnd();
    this->text1.draw();edkEnd();
    this->text2.draw();edkEnd();
    /*
    this->obj.drawPivo(1.f,edk::color3f32(1,0,0));edkEnd();
    this->sprite.drawPivo(this->sprite.size.width,edk::color3f32(1,0,0));edkEnd();
    this->text1.drawPivo(this->text1.getMapScaleWidth(),edk::color3f32(1,0,0));edkEnd();
    this->text2.drawPivo(this->text1.getMapScaleWidth(),edk::color3f32(1,0,0));edkEnd();
*/
}
void edk::gui2d::MenuObj::drawSelection(){
    //
    this->obj.draw();edkEnd();
}

edk::gui2d::ViewMenu2d::ViewMenu2d(){
    //
    this->xOrder = true;edkEnd();
    this->positions = edk::vec2f32(0,0);edkEnd();
    this->mouseActivate = this->mouseOn = false;edkEnd();

    this->selectTree = &this->tree1;edkEnd();
    this->selectTreeS = &this->tree2;edkEnd();

    //set the obj paramerets
    this->color[edk::gui2d::gui2dTextureNormal] = edk::color4f32(0.5f,0.5f,0.5f,1.f);edkEnd();
    this->color[edk::gui2d::gui2dTextureUp] = edk::color4f32(0.75f,0.75f,0.75f,1.f);edkEnd();
    this->color[edk::gui2d::gui2dTexturePressed] = edk::color4f32(0.3f,0.3f,0.3f,1.f);edkEnd();
    this->color[edk::gui2d::gui2dTexturePressedUp] = edk::color4f32(0.4f,0.4f,0.4f,1.f);edkEnd();
}
edk::gui2d::ViewMenu2d::~ViewMenu2d(){
    //
}

//return true if have the element on the callback list
bool edk::gui2d::ViewMenu2d::haveCallback(edk::gui2d::Menu2dCallback* callback){
    //test the callback
    if(callback){
        //get the size and the pointer
        edk::uint32 size = this->listCallback.getSize();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            if(this->listCallback.get(i) == callback){
                return true;
            }
        }
    }
    return false;
}
//process the callbacks
void edk::gui2d::ViewMenu2d::processEnable(edk::gui2d::MenuObj* obj){
    //get the list size
    edk::uint32 size = this->listCallback.size();edkEnd();
    edk::gui2d::Menu2dCallback* pointer = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);edkEnd();
        if(pointer){
            //process the function
            pointer->enable(this,obj);edkEnd();
        }
    }
}
void edk::gui2d::ViewMenu2d::processExec(edk::gui2d::MenuObj* obj){
    //get the list size
    edk::uint32 size = this->listCallback.size();edkEnd();
    edk::gui2d::Menu2dCallback* pointer = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);edkEnd();
        if(pointer){
            //process the function
            pointer->exec(this,obj);edkEnd();
        }
    }
}
void edk::gui2d::ViewMenu2d::processDisable(edk::gui2d::MenuObj* obj){
    //get the list size
    edk::uint32 size = this->listCallback.size();edkEnd();
    edk::gui2d::Menu2dCallback* pointer = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);edkEnd();
        if(pointer){
            //process the function
            pointer->disable(this,obj);edkEnd();
        }
    }
}
//update camera size and position to have all the objects
void edk::gui2d::ViewMenu2d::updateCamera(){
    //
    if(this->positions.x!= 0.f && this->positions.y!=0.f){
        if(this->xOrder){
            //
            //this->frame.size;edkEnd();
            this->camera.setRect(0,0
                                 ,this->positions.y * (edk::float32)this->frame.size.width / (edk::float32)this->frame.size.height
                                 ,this->positions.y
                                 );edkEnd();
        }
        else{
            //
            this->camera.setRect(0
                                 ,0
                                 ,this->positions.x
                                 ,(this->positions.x * (edk::float32)this->frame.size.height / (edk::float32)this->frame.size.width)
                                 );edkEnd();
            //this->camera.setRect(0,0,this->positions.x,this->positions.y);edkEnd();
            //update the objects be on top
            this->camera.position.y = 0.f + this->positions.y - this->camera.getSize().height*0.5f;edkEnd();
        }
    }
}
//update the objects positions
void edk::gui2d::ViewMenu2d::updatePositions(){
    //update the positions of the objects
    this->positions = 0.f;edkEnd();
    edk::gui2d::MenuObj* obj = NULL;edkEnd();
    edk::uint32 size = this->objs.size();edkEnd();
    if(this->xOrder){
        for(edk::uint32 i=0u;i<size;i++){
            //
            obj = this->objs.get(i);edkEnd();
            if(obj){
                //
                obj->updateSizes();edkEnd();
                //set the object position
                obj->setPosition(this->positions.x + obj->getSize().width*0.5f,obj->getSize().height*0.5f);edkEnd();
                //increment the positions
                this->positions.x += obj->getSize().width;edkEnd();
                if(obj->getSize().height>this->positions.y){
                    this->positions.y = obj->getSize().height;edkEnd();
                }

            }
        }
    }
    else{
        edk::float32 width = 0.f;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            //
            obj = this->objs.get(i);edkEnd();
            if(obj){
                //
                //increment the positions
                if(obj->getSize().width>width){
                    width = obj->getSize().width;edkEnd();
                }
            }
        }

        //calculate the max width
        for(edk::uint32 i=size;i>0u;i--){
            //
            obj = this->objs.get(i-1u);edkEnd();
            if(obj){
                //

                //set the object size
                obj->setSize(width,obj->getSize().height);edkEnd();
                //set the object position
                obj->setPosition(width*0.5f,this->positions.y + obj->getSize().height*0.5f);edkEnd();
                //increment the positions
                this->positions.y += obj->getSize().height;edkEnd();
                if(obj->getSize().width>this->positions.x){
                    this->positions.x = obj->getSize().width;edkEnd();
                }
            }
        }
    }
}
//process the selection
void edk::gui2d::ViewMenu2d::selectObject(edk::uint32 ,edk::int32 ,edk::float32 ,edk::float32 ,edk::vector::Stack<edk::uint32>* names){
    //
    if(names->size()){
        //add to the select tree
        this->selectTree->add(names->get(0u));edkEnd();
        //remove from the treeS
        this->selectTreeS->remove(names->get(0u));edkEnd();
    }
}

//create a new object
edk::uint32 edk::gui2d::ViewMenu2d::newObject(edk::char8* spriteName,edk::char8* text1,edk::char8* text2,edk::uint32 id){
    //
    edk::gui2d::MenuObj* obj = new edk::gui2d::MenuObj;edkEnd();
    if(obj){
        if(obj->loadObject(id,spriteName,text1,text2)){
            edk::uint32 size = this->objs.size();edkEnd();
            //add the object to the stack
            edk::uint32 ret = this->objs.pushBack(obj);edkEnd();
            if(size != this->objs.size()){
                this->updatePositions();edkEnd();

                //set the obj paramerets
                obj->color[edk::gui2d::gui2dTextureNormal] = this->color[edk::gui2d::gui2dTextureNormal];edkEnd();
                obj->color[edk::gui2d::gui2dTextureUp] = this->color[edk::gui2d::gui2dTextureUp];edkEnd();
                obj->color[edk::gui2d::gui2dTexturePressed] = this->color[edk::gui2d::gui2dTexturePressed];edkEnd();
                obj->color[edk::gui2d::gui2dTexturePressedUp] = this->color[edk::gui2d::gui2dTexturePressedUp];edkEnd();

                return ret;
            }
        }
        delete obj;edkEnd();
    }
    return 0u;edkEnd();
}
edk::uint32 edk::gui2d::ViewMenu2d::newObject(const edk::char8* spriteName,const edk::char8* text1,const edk::char8* text2,edk::uint32 id){
    return newObject((edk::char8*) spriteName,(edk::char8*) text1,(edk::char8*) text2,id);edkEnd();
}
//return the object strings pointer
edk::char8* edk::gui2d::ViewMenu2d::getObjectStr1(edk::uint32 position){
    //test if have the object in position
    if(this->objs.havePos(position)){
        edk::gui2d::MenuObj* obj = this->objs.get(position);edkEnd();
        if(obj){
            return obj->getStr1();edkEnd();
        }
    }
    return NULL;
}
edk::char8* edk::gui2d::ViewMenu2d::getObjectStr2(edk::uint32 position){
    //test if have the object in position
    if(this->objs.havePos(position)){
        edk::gui2d::MenuObj* obj = this->objs.get(position);edkEnd();
        if(obj){
            return obj->getStr2();edkEnd();
        }
    }
    return NULL;
}

//return the size of objects inside the stack
edk::uint32 edk::gui2d::ViewMenu2d::getObjectsSize(){
    //
    return this->objs.size();edkEnd();
}
//set the order to X
void edk::gui2d::ViewMenu2d::setOrderX(){
    this->xOrder = true;edkEnd();
    //update the position and the camera
    this->updatePositions();edkEnd();
    this->updateCamera();edkEnd();
}
//set the order to Y
void edk::gui2d::ViewMenu2d::setOrderY(){
    this->xOrder = false;edkEnd();
    //update the position and the camera
    this->updatePositions();edkEnd();
    this->updateCamera();edkEnd();
}
//return if is orderX
bool edk::gui2d::ViewMenu2d::isOrderX(){
    return xOrder;edkEnd();
}
bool edk::gui2d::ViewMenu2d::iOrderY(){
    return xOrder;edkEnd();
}

//set the menu colors
void edk::gui2d::ViewMenu2d::setColorNormal(edk::color3f32 color){
    this->setColorNormal(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorNormal(edk::color4f32 color){
    this->color[edk::gui2d::gui2dTextureNormal] = color;edkEnd();

    //set objects color
    edk::gui2d::MenuObj* obj = NULL;edkEnd();
    edk::uint32 size = this->objs.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);edkEnd();
        if(obj){
            obj->color[edk::gui2d::gui2dTextureNormal] = this->color[edk::gui2d::gui2dTextureNormal];edkEnd();
        }
    }
}
void edk::gui2d::ViewMenu2d::setColorNormal(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setColorNormal(edk::color4f32(r,g,b,1.f));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorNormal(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setColorNormal(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorUp(edk::color3f32 color){
    //
    this->setColorUp(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorUp(edk::color4f32 color){
    //
    this->color[edk::gui2d::gui2dTextureUp] = color;edkEnd();

    //set objects color
    edk::gui2d::MenuObj* obj = NULL;edkEnd();
    edk::uint32 size = this->objs.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);edkEnd();
        if(obj){
            obj->color[edk::gui2d::gui2dTextureUp] = this->color[edk::gui2d::gui2dTextureUp];edkEnd();
        }
    }
}
void edk::gui2d::ViewMenu2d::setColorUp(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setColorUp(edk::color4f32(r,g,b,1.f));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorUp(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setColorUp(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorPressed(edk::color3f32 color){
    //
    this->setColorPressed(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorPressed(edk::color4f32 color){
    //
    this->color[edk::gui2d::gui2dTexturePressed] = color;edkEnd();

    //set objects color
    edk::gui2d::MenuObj* obj = NULL;edkEnd();
    edk::uint32 size = this->objs.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);edkEnd();
        if(obj){
            obj->color[edk::gui2d::gui2dTexturePressed] = this->color[edk::gui2d::gui2dTexturePressed];edkEnd();
        }
    }
}
void edk::gui2d::ViewMenu2d::setColorPressed(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setColorPressed(edk::color4f32(r,g,b,1.f));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorPressed(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    this->setColorPressed(edk::color4f32(r,g,b,a));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorPressedUp(edk::color3f32 color){
    //
    this->setColorPressedUp(edk::color4f32(color.r,color.g,color.b,1.f));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorPressedUp(edk::color4f32 color){
    //
    this->color[edk::gui2d::gui2dTexturePressedUp] = color;edkEnd();

    //set objects color
    edk::gui2d::MenuObj* obj = NULL;edkEnd();
    edk::uint32 size = this->objs.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);edkEnd();
        if(obj){
            obj->color[edk::gui2d::gui2dTexturePressedUp] = this->color[edk::gui2d::gui2dTexturePressedUp];edkEnd();
        }
    }
}
void edk::gui2d::ViewMenu2d::setColorPressedUp(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setColorPressedUp(edk::color4f32(r,g,b,1.f));edkEnd();
}
void edk::gui2d::ViewMenu2d::setColorPressedUp(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    this->setColorPressedUp(edk::color4f32(r,g,b,a));edkEnd();
}

void edk::gui2d::ViewMenu2d::load(edk::rectf32){
    this->objSelected = NULL;edkEnd();
    this->mouseStatus = edk::gui2d::gui2dMouseNothing;edkEnd();
    //
    this->saveFrame = edk::rectf32();edkEnd();
    this->camera.setSize(20,20);edkEnd();
    this->mouseOn = false;edkEnd();

    //clean the objects status
    edk::gui2d::MenuObj* obj = NULL;edkEnd();
    edk::uint32 size = this->objs.size();edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);edkEnd();
        if(obj){
            obj->setStatus(edk::gui2d::gui2dTextureNormal);edkEnd();
        }
    }
}
void edk::gui2d::ViewMenu2d::unload(){
    //
}
void edk::gui2d::ViewMenu2d::update(edk::WindowEvents* events){
    //
    this->runSelection = false;edkEnd();
    edk::uint32 size = 0u;edkEnd();

    //change trees
    if(this->selectTree == &this->tree1){
        this->selectTree = &this->tree2;edkEnd();
        this->selectTreeS = &this->tree1;edkEnd();
    }
    else{
        this->selectTree = &this->tree1;edkEnd();
        this->selectTreeS = &this->tree2;edkEnd();
    }

    //save the mouse status
    this->mouseStatus = edk::gui2d::gui2dMouseNothing;edkEnd();

    size = events->mousePressed.size();edkEnd();
    //test the buttons
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mousePressed.get(i)){
        case edk::mouse::left:
            this->mouseStatus = edk::gui2d::gui2dMousePressed;edkEnd();
            this->runSelection = true;edkEnd();
            break;
        }
    }
    size = events->mouseHolded.size();edkEnd();
    //test the buttons
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mouseHolded.get(i)){
        case edk::mouse::left:
            if(this->mouseStatus != edk::gui2d::gui2dMousePressed){
                this->mouseStatus = edk::gui2d::gui2dMouseHolded;edkEnd();
            }
            this->runSelection = true;edkEnd();
            break;
        }
    }
    size = events->mouseRelease.size();edkEnd();
    //test the buttons
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mouseRelease.get(i)){
        case edk::mouse::left:
            this->mouseStatus = edk::gui2d::gui2dMouseRelease;edkEnd();
            this->runSelection = true;edkEnd();
            if(!this->xOrder && this->objSelected){
                //then activate button
                this->processExec(this->objSelected);edkEnd();
            }
            break;
        }
    }

    if(events->mouseMoved || this->runSelection){
        //
        this->runSelection = true;edkEnd();
        this->testSelection(events->mousePos);edkEnd();
    }
}
void edk::gui2d::ViewMenu2d::drawSelectionScene(){
    //draw the objects
    edk::uint32 size = this->objs.size();edkEnd();
    edk::gui2d::MenuObj* obj=NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //
        this->selectionPushName(i);edkEnd();
        obj = this->objs.get(i);edkEnd();
        obj->draw();edkEnd();
        this->selectionPopName();edkEnd();
    }
}
void edk::gui2d::ViewMenu2d::drawScene(edk::rectf32){
    if(this->saveFrame!=this->frame){
        this->saveFrame=this->frame;edkEnd();
        this->updateCamera();edkEnd();
    }

    edk::uint32 size = 0u;edkEnd();
    edk::uint32 sizeSelected = 0u;edkEnd();
    edk::gui2d::MenuObj* obj = NULL;edkEnd();
    if(this->runSelection){
        this->objSelected = NULL;edkEnd();
        sizeSelected = this->selectTree->size();edkEnd();
        if(sizeSelected){
            {
                //get the object
                this->objSelected = this->objs.get(this->selectTree->getElementInPosition(0u));edkEnd();
                if(this->objSelected){
                    //test the mouse status
                    switch(this->mouseStatus){
                    case edk::gui2d::gui2dMousePressed:
                        //change the mouse on
                        this->mouseOn=!this->mouseOn;edkEnd();

                        //test if is xOrder
                        if(this->xOrder && this->mouseOn){
                            //then activate button
                            this->processExec(this->objSelected);edkEnd();
                        }
                        break;
                    case edk::gui2d::gui2dMouseRelease:
                        //test if is NOT xOrder
                        if(!this->xOrder){
                            //run button action
                            this->processExec(this->objSelected);edkEnd();
                        }
                        break;
                    case edk::gui2d::gui2dMouseHolded:
                    case edk::gui2d::gui2dMouseNothing:
                    case edk::gui2d::gui2dMouseStatusSize:
                        break;
                    }

                    //test if the mouse is on
                    if(this->mouseOn || !this->xOrder){
                        this->mouseOn = true;edkEnd();
                        //set the button status to pressedUp
                        this->objSelected->setStatus(edk::gui2d::gui2dTexturePressedUp);edkEnd();
                        if(!this->objSelected->active){
                            this->objSelected->active = true;edkEnd();
                            processEnable(this->objSelected);edkEnd();
                        }
                    }
                    else{
                        //set the button status to op
                        this->objSelected->setStatus(edk::gui2d::gui2dTextureUp);edkEnd();
                        if(this->objSelected->active){
                            this->objSelected->active = false;edkEnd();
                            processDisable(this->objSelected);edkEnd();
                        }
                    }
                }
            }

            edk::uint32 n;edkEnd();
            for(edk::uint32 i=1u;i<sizeSelected;i++){
                //remove this position
                n = this->selectTree->getElementInPosition(1u);edkEnd();
                this->selectTreeS->add(n);edkEnd();
                this->selectTree->remove(n);edkEnd();

            }
        }
        else{
            if(this->mouseStatus==edk::gui2d::gui2dMouseRelease){
                this->mouseOn=false;edkEnd();
            }
        }
        size = this->selectTreeS->size();edkEnd();

        if(size){
            for(edk::uint32 i=0u;i<size;i++){
                //get the object
                obj = this->objs.get(this->selectTreeS->getElementInPosition(i));edkEnd();
                if(obj){
                    if(!this->mouseOn || sizeSelected){
                        obj->setStatus(edk::gui2d::gui2dTextureNormal);edkEnd();
                        if(obj->active){
                            //desactivate the button
                            obj->active = false;edkEnd();
                            processDisable(obj);edkEnd();
                        }
                    }
                    else{
                        if(obj->active){
                            obj->setStatus(edk::gui2d::gui2dTexturePressed);edkEnd();
                        }
                        else{
                            obj->setStatus(edk::gui2d::gui2dTextureNormal);edkEnd();
                        }
                    }
                }
            }
            this->selectTreeS->clean();edkEnd();
        }
        else{
            if(sizeSelected || this->mouseStatus==edk::gui2d::gui2dMouseRelease){
                //clean all objects on the list unless the selected
                size = this->objs.size();edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    obj = this->objs.get(i);edkEnd();
                    if(obj && obj!=this->objSelected){
                        obj->setStatus(edk::gui2d::gui2dTextureNormal);edkEnd();
                        if(obj->active){
                            //desactivate the button
                            obj->active = false;edkEnd();
                            processDisable(obj);edkEnd();
                        }
                    }
                }
            }
        }
    }

    //draw the objects
    size = this->objs.size();edkEnd();
    obj=NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        //
        obj = this->objs.get(i);edkEnd();
        obj->draw();edkEnd();
    }
}

//callback
bool edk::gui2d::ViewMenu2d::addCallback(edk::gui2d::Menu2dCallback* callback){
    //test the callback
    if(callback){
        //test if have this callback inside the list
        if(!this->listCallback.haveElement(callback)){
            //add the callback to the list
            return this->listCallback.pushBack(callback);edkEnd();
        }
    }
    return false;
}
bool edk::gui2d::ViewMenu2d::removeCallback(edk::gui2d::Menu2dCallback* callback){
    //test the callback
    if(callback){
        //test if have this callback inside the list
        edk::uint32 pos = this->listCallback.find(callback);edkEnd();
        if(!pos){
            if(this->listCallback.get(pos) != callback){
                return false;
            }
        }
        return this->listCallback.remove(pos);edkEnd();
    }
    return false;
}
void edk::gui2d::ViewMenu2d::cleanCallbacks(){
    this->listCallback.clean();edkEnd();
}

