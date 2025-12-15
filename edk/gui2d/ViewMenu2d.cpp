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

#ifdef printMessages
#pragma message "            Inside ViewMenu2d.cpp"
#endif


edk::gui2d::MenuObj::MenuObj(){
    this->classThis=NULL;
    this->Constructor();
}
edk::gui2d::MenuObj::~MenuObj(){
    this->Destructor();
}

void edk::gui2d::MenuObj::Constructor(){
    if(this->classThis!=this){
        this->classThis=this;

        this->obj.Constructor();
        this->meshObj.Constructor();
        this->sprite.Constructor();
        this->text1.Constructor();
        this->str1.Constructor();
        this->text2.Constructor();
        this->str2.Constructor();

        this->active = false;
        this->id = 0u;
        this->status = edk::gui2d::gui2dTextureNormal;
        this->saveStatus = edk::gui2d::gui2dTextureSize;
        edk::uint8 size = edk::gui2d::gui2dTextureSize;
        for(edk::uint8 i=0u;i<size;i++){
            this->color[i] = edk::color4f32(1,1,1,1);
        }
        //load the mesh
        this->obj.addMesh(&this->meshObj);
        {
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            rect.setPolygonColor(0,0,0,1);
            this->meshObj.addPolygon(rect);
            this->meshObj.material.setEmission(1,1,1,1);
        }
    }
}
void edk::gui2d::MenuObj::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->str1.cleanName();
        this->str2.cleanName();

        this->obj.Destructor();
        this->meshObj.Destructor();
        this->sprite.Destructor();
        this->text1.Destructor();
        this->str1.Destructor();
        this->text2.Destructor();
        this->str2.Destructor();
    }
}

//get the type
edk::gui2d::gui2dTypes edk::gui2d::MenuObj::getType(){
    return edk::gui2d::gui2dTypeMenu;
}

void edk::gui2d::MenuObj::updatePositions(){
    //set the objects position based on the full size of the button

    this->sprite.position.x = this->obj.position.x - (this->obj.size.width * 0.5f) + this->sprite.size.width*0.5f + edkGui2dInsideBorder
            ;
    this->sprite.position.y = this->obj.position.y;

    //set the object in the position
    this->text1.setPosition(this->obj.position.x - (this->obj.size.width * 0.5f) + (this->text1.getMapScaleWidth() * 0.5f) + this->positionText1
                            ,this->obj.position.y
                            );
    //set the object in the position
    this->text2.setPosition(this->obj.position.x - (this->obj.size.width * 0.5f) + (this->text2.getMapScaleWidth() * 0.5f) + this->positionText2
                            ,this->obj.position.y
                            );
}

//load the object
bool edk::gui2d::MenuObj::loadObject(edk::uint32 id,edk::char8* spriteName,edk::char8* text1,edk::char8* text2){
    this->id = id;
    this->sprite.cleanMeshes();
    this->text1.deleteMap();
    this->str1.cleanName();
    this->text2.deleteMap();
    this->str2.cleanName();
    bool ret = true;
    this->positionText1 = this->positionText2 = 0.f;
    //set the object size
    this->obj.size = edk::size2f32(0,1);
    this->sprite.size = edkGui2dInsideHeight;


    this->obj.size.width += edkGui2dInsideBorder;
    if(spriteName){
        //
        edk::shape::Mesh2D* mesh = this->sprite.newMesh();
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            mesh->addPolygon(rect);
            //load the texture
            if(mesh->material.loadTexture(spriteName,0u)){
                edk::size2ui32 texSize = mesh->material.getTextureSize(0u);
                if(texSize.width && texSize.height){
                    //test the size to set the sprite new size
                    if(texSize.width > texSize.height){
                        //
                        this->sprite.size.height = this->sprite.size.width * ((edk::float32)texSize.height / (edk::float32)texSize.width);
                    }
                    else{
                        this->sprite.size.width = this->sprite.size.height * ((edk::float32)texSize.width / (edk::float32)texSize.height);
                    }
                    this->obj.size.width += this->sprite.size.width;
                    this->obj.size.width += edkGui2dInsideBorder;
                }
                else{
                    this->sprite.removeAllMesh();
                    ret = false;
                }
            }
            else{
                this->sprite.removeAllMesh();
                ret = false;
            }
        }
    }
    else{
        this->sprite.size.width = 0.f;
    }
    if(text1){
        //test the size of the text
        if(edk::String::strSize(text1)){
            //create the fontMap
            this->text1.deleteMap();
            this->text1.setScale(edkGui2dInsideHeight*0.5f,edkGui2dInsideHeight);
            this->positionText1 = this->obj.size.width;
            if(this->text1.createStringMap(text1)){
                this->str1.setName(text1);
                this->obj.size.width += this->text1.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;
            }
            else{
                ret = false;
            }
        }
        this->obj.size.width += edkGui2dInsideBorder;
    }
    if(text2){

        //test the size of the text
        if(edk::String::strSize(text2)){
            //
            //create the fontMap
            this->text2.deleteMap();
            this->text2.setScale(edkGui2dInsideHeight*0.5f,edkGui2dInsideHeight);
            this->positionText2 = this->obj.size.width;
            if(this->text2.createStringMap(text2)){
                this->str2.setName(text2);
                this->obj.size.width += this->text2.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;
            }
            else{
                ret = false;
            }
        }
        this->obj.size.width += edkGui2dInsideBorder;

    }

    this->updatePositions();

    return ret;
}
bool edk::gui2d::MenuObj::loadObject(edk::uint32 id,const edk::char8* spriteName,edk::char8* text1,edk::char8* text2){
    return this->loadObject(id,(edk::char8*) spriteName,text1,text2);
}
bool edk::gui2d::MenuObj::loadObjectFromPack(edk::pack::FilePackage* pack,edk::uint32 id,edk::char8* spriteName,edk::char8* text1,edk::char8* text2){
    this->id = id;
    this->sprite.cleanMeshes();
    this->text1.deleteMap();
    this->str1.cleanName();
    this->text2.deleteMap();
    this->str2.cleanName();
    bool ret = true;
    this->positionText1 = this->positionText2 = 0.f;
    //set the object size
    this->obj.size = edk::size2f32(0,1);
    this->sprite.size = edkGui2dInsideHeight;


    this->obj.size.width += edkGui2dInsideBorder;
    if(spriteName && pack){
        //
        edk::shape::Mesh2D* mesh = this->sprite.newMesh();
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            mesh->addPolygon(rect);
            //load the texture
            if(mesh->material.loadTextureFromPack(pack,spriteName,0u)){
                edk::size2ui32 texSize = mesh->material.getTextureSize(0u);
                if(texSize.width && texSize.height){
                    //test the size to set the sprite new size
                    if(texSize.width > texSize.height){
                        //
                        this->sprite.size.height = this->sprite.size.width * ((edk::float32)texSize.height / (edk::float32)texSize.width);
                    }
                    else{
                        this->sprite.size.width = this->sprite.size.height * ((edk::float32)texSize.width / (edk::float32)texSize.height);
                    }
                    this->obj.size.width += this->sprite.size.width;
                    this->obj.size.width += edkGui2dInsideBorder;
                }
                else{
                    this->sprite.removeAllMesh();
                    ret = false;
                }
            }
            else{
                this->sprite.removeAllMesh();
                ret = false;
            }
        }
    }
    else{
        this->sprite.size.width = 0.f;
    }
    if(text1){
        //test the size of the text
        if(edk::String::strSize(text1)){
            //create the fontMap
            this->text1.deleteMap();
            this->text1.setScale(edkGui2dInsideHeight*0.5f,edkGui2dInsideHeight);
            this->positionText1 = this->obj.size.width;
            if(this->text1.createStringMap(text1)){
                this->str1.setName(text1);
                this->obj.size.width += this->text1.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;
            }
            else{
                ret = false;
            }
        }
        this->obj.size.width += edkGui2dInsideBorder;
    }
    if(text2){

        //test the size of the text
        if(edk::String::strSize(text2)){
            //
            //create the fontMap
            this->text2.deleteMap();
            this->text2.setScale(edkGui2dInsideHeight*0.5f,edkGui2dInsideHeight);
            this->positionText2 = this->obj.size.width;
            if(this->text2.createStringMap(text2)){
                this->str2.setName(text2);
                this->obj.size.width += this->text2.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;
            }
            else{
                ret = false;
            }
        }
        this->obj.size.width += edkGui2dInsideBorder;

    }

    this->updatePositions();

    return ret;
}
bool edk::gui2d::MenuObj::loadObjectFromPack(edk::pack::FilePackage* pack,edk::uint32 id,const edk::char8* spriteName,edk::char8* text1,edk::char8* text2){
    return this->loadObjectFromPack(pack,id,(edk::char8*) spriteName,text1,text2);
}
//set the button position
void edk::gui2d::MenuObj::setPosition(edk::float32 x,edk::float32 y){
    this->setPosition(edk::vec2f32 (x,y));
}
void edk::gui2d::MenuObj::setPosition(edk::vec2f32 position){
    //
    this->obj.position = position;
    //update the positions
    this->updatePositions();
}
//set size
bool edk::gui2d::MenuObj::setSize(edk::size2f32 size){
    //
    if(size.width>0.f && size.height>0.f){
        //
        this->obj.size = size;
        this->updatePositions();
        return true;
    }
    return false;
}
bool edk::gui2d::MenuObj::setSize(edk::float32 width,edk::float32 height){
    //
    return this->setSize(edk::size2f32(width,height));
}

//get the size
edk::size2f32 edk::gui2d::MenuObj::getSize(){
    return this->obj.size;
}
//return the object strings pointer
edk::char8* edk::gui2d::MenuObj::getStr1(){
    if(this->str1.getSize()){
        return this->str1.getName();
    }
    return NULL;
}
edk::char8* edk::gui2d::MenuObj::getStr2(){
    if(this->str2.getSize()){
        return this->str2.getName();
    }
    return NULL;
}
void edk::gui2d::MenuObj::updateSizes(){
    this->positionText1 = this->positionText2 = 0.f;
    //set the object size
    this->obj.size = edk::size2f32(0,1);
    this->obj.size.width += edkGui2dInsideBorder;

    if(this->sprite.size.width>0.f){
        this->sprite.size = edkGui2dInsideHeight;
        this->obj.size.width += this->sprite.size.width;
        this->obj.size.width += edkGui2dInsideBorder;
    }
    else{
        this->sprite.size.height = edkGui2dInsideHeight;
    }

    if(this->text1.haveText()){
        this->positionText1 = this->obj.size.width;
        this->obj.size.width += this->text1.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;
        this->obj.size.width += edkGui2dInsideBorder;
    }
    if(this->text2.haveText()){
        this->positionText2 = this->obj.size.width;
        this->obj.size.width += this->text2.getMapSizeWidth() * edkGui2dInsideHeight * 0.5f;
        this->obj.size.width += edkGui2dInsideBorder;

    }
}
//set the status of the object to be draw
bool edk::gui2d::MenuObj::setStatus(edk::gui2d::gui2dTexture status){
    //
    if(status < edk::gui2d::gui2dTextureSize){
        //set the status
        this->status = status;
        return true;
    }
    return false;
}

void edk::gui2d::MenuObj::draw(){
    //test if the status is different
    if(this->saveStatus!=this->status){
        //set the color
        this->saveStatus=this->status;
        this->meshObj.material.setEmission(this->color[this->status]);
    }
    //
    this->obj.draw();
    this->obj.drawWire();

    this->sprite.draw();
    this->text1.draw();
    this->text2.draw();
    /*
    this->obj.drawPivo(1.f,edk::color3f32(1,0,0));
    this->sprite.drawPivo(this->sprite.size.width,edk::color3f32(1,0,0));
    this->text1.drawPivo(this->text1.getMapScaleWidth(),edk::color3f32(1,0,0));
    this->text2.drawPivo(this->text1.getMapScaleWidth(),edk::color3f32(1,0,0));
*/
}
void edk::gui2d::MenuObj::drawSelection(){
    //
    this->obj.draw();
}

edk::gui2d::ViewMenu2d::ViewMenu2d(){
    this->classThis=NULL;
    this->Constructor();
}
edk::gui2d::ViewMenu2d::~ViewMenu2d(){
    this->Destructor();
}

void edk::gui2d::ViewMenu2d::Constructor(){
    edk::ViewGU2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->tree1.Constructor();
        this->tree2.Constructor();
        this->listCallback.Constructor();
        this->objs.Constructor();

        this->xOrder = true;
        this->positions = edk::vec2f32(0,0);
        this->mouseActivate = this->mouseOn = false;

        this->selectTree = &this->tree1;
        this->selectTreeS = &this->tree2;

        //set the obj paramerets
        this->color[edk::gui2d::gui2dTextureNormal] = edk::color4f32(0.5f,0.5f,0.5f,1.f);
        this->color[edk::gui2d::gui2dTextureUp] = edk::color4f32(0.75f,0.75f,0.75f,1.f);
        this->color[edk::gui2d::gui2dTexturePressed] = edk::color4f32(0.3f,0.3f,0.3f,1.f);
        this->color[edk::gui2d::gui2dTexturePressedUp] = edk::color4f32(0.4f,0.4f,0.4f,1.f);
    }
}
void edk::gui2d::ViewMenu2d::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->tree1.Destructor();
        this->tree2.Destructor();
        this->listCallback.Destructor();
        this->objs.Destructor();
    }
    edk::ViewGU2D::Destructor();
}

//return true if have the element on the callback list
bool edk::gui2d::ViewMenu2d::haveCallback(edk::gui2d::Menu2dCallback* callback){
    //test the callback
    if(callback){
        //get the size and the pointer
        edk::uint32 size = this->listCallback.getSize();
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
    edk::uint32 size = this->listCallback.size();
    edk::gui2d::Menu2dCallback* pointer = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);
        if(pointer){
            //process the function
            pointer->enable(this,obj);
        }
    }
}
void edk::gui2d::ViewMenu2d::processExec(edk::gui2d::MenuObj* obj){
    //get the list size
    edk::uint32 size = this->listCallback.size();
    edk::gui2d::Menu2dCallback* pointer = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);
        if(pointer){
            //process the function
            pointer->exec(this,obj);
        }
    }
}
void edk::gui2d::ViewMenu2d::processDisable(edk::gui2d::MenuObj* obj){
    //get the list size
    edk::uint32 size = this->listCallback.size();
    edk::gui2d::Menu2dCallback* pointer = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);
        if(pointer){
            //process the function
            pointer->disable(this,obj);
        }
    }
}
//update camera size and position to have all the objects
void edk::gui2d::ViewMenu2d::updateCamera(){
    //
    if(this->positions.x!= 0.f && this->positions.y!=0.f){
        if(this->xOrder){
            //
            //this->frame.size;
            this->camera.setRectPoints(0,0
                                       ,this->positions.y * (edk::float32)this->frame.size.width / (edk::float32)this->frame.size.height
                                       ,this->positions.y
                                       );
        }
        else{
            //
            this->camera.setRectPoints(0
                                       ,0
                                       ,this->positions.x
                                       ,(this->positions.x * (edk::float32)this->frame.size.height / (edk::float32)this->frame.size.width)
                                       );
            //this->camera.setRectPoints(0,0,this->positions.x,this->positions.y);
            //update the objects be on top
            this->camera.position.y = 0.f + this->positions.y - this->camera.getSize().height*0.5f;
        }
    }
}
//update the objects positions
void edk::gui2d::ViewMenu2d::updatePositions(){
    //update the positions of the objects
    this->positions = 0.f;
    edk::gui2d::MenuObj* obj = NULL;
    edk::uint32 size = this->objs.size();
    if(this->xOrder){
        for(edk::uint32 i=0u;i<size;i++){
            //
            obj = this->objs.get(i);
            if(obj){
                //
                obj->updateSizes();
                //set the object position
                obj->setPosition(this->positions.x + obj->getSize().width*0.5f,obj->getSize().height*0.5f);
                //increment the positions
                this->positions.x += obj->getSize().width;
                if(obj->getSize().height>this->positions.y){
                    this->positions.y = obj->getSize().height;
                }

            }
        }
    }
    else{
        edk::float32 width = 0.f;
        for(edk::uint32 i=0u;i<size;i++){
            //
            obj = this->objs.get(i);
            if(obj){
                //
                //increment the positions
                if(obj->getSize().width>width){
                    width = obj->getSize().width;
                }
            }
        }

        //calculate the max width
        for(edk::uint32 i=size;i>0u;i--){
            //
            obj = this->objs.get(i-1u);
            if(obj){
                //

                //set the object size
                obj->setSize(width,obj->getSize().height);
                //set the object position
                obj->setPosition(width*0.5f,this->positions.y + obj->getSize().height*0.5f);
                //increment the positions
                this->positions.y += obj->getSize().height;
                if(obj->getSize().width>this->positions.x){
                    this->positions.x = obj->getSize().width;
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
        this->selectTree->add(names->get(0u));
        //remove from the treeS
        this->selectTreeS->remove(names->get(0u));
    }
}

//create a new object
edk::uint32 edk::gui2d::ViewMenu2d::newObject(edk::char8* spriteName,edk::char8* text1,edk::char8* text2,edk::uint32 id){
    //
    edk::gui2d::MenuObj* obj = new edk::gui2d::MenuObj;
    if(obj){
        if(obj->loadObject(id,spriteName,text1,text2)){
            edk::uint32 size = this->objs.size();
            //add the object to the stack
            edk::uint32 ret = this->objs.pushBack(obj);
            if(size != this->objs.size()){
                this->updatePositions();

                //set the obj paramerets
                obj->color[edk::gui2d::gui2dTextureNormal] = this->color[edk::gui2d::gui2dTextureNormal];
                obj->color[edk::gui2d::gui2dTextureUp] = this->color[edk::gui2d::gui2dTextureUp];
                obj->color[edk::gui2d::gui2dTexturePressed] = this->color[edk::gui2d::gui2dTexturePressed];
                obj->color[edk::gui2d::gui2dTexturePressedUp] = this->color[edk::gui2d::gui2dTexturePressedUp];

                return ret;
            }
        }
        delete obj;
    }
    return 0u;
}
edk::uint32 edk::gui2d::ViewMenu2d::newObject(const edk::char8* spriteName,const edk::char8* text1,const edk::char8* text2,edk::uint32 id){
    return newObject((edk::char8*) spriteName,(edk::char8*) text1,(edk::char8*) text2,id);
}
//return the object strings pointer
edk::char8* edk::gui2d::ViewMenu2d::getObjectStr1(edk::uint32 position){
    //test if have the object in position
    if(this->objs.havePos(position)){
        edk::gui2d::MenuObj* obj = this->objs.get(position);
        if(obj){
            return obj->getStr1();
        }
    }
    return NULL;
}
edk::char8* edk::gui2d::ViewMenu2d::getObjectStr2(edk::uint32 position){
    //test if have the object in position
    if(this->objs.havePos(position)){
        edk::gui2d::MenuObj* obj = this->objs.get(position);
        if(obj){
            return obj->getStr2();
        }
    }
    return NULL;
}

//return the size of objects inside the stack
edk::uint32 edk::gui2d::ViewMenu2d::getObjectsSize(){
    //
    return this->objs.size();
}
//set the order to X
void edk::gui2d::ViewMenu2d::setOrderX(){
    this->xOrder = true;
    //update the position and the camera
    this->updatePositions();
    this->updateCamera();
}
//set the order to Y
void edk::gui2d::ViewMenu2d::setOrderY(){
    this->xOrder = false;
    //update the position and the camera
    this->updatePositions();
    this->updateCamera();
}
//return if is orderX
bool edk::gui2d::ViewMenu2d::isOrderX(){
    return xOrder;
}
bool edk::gui2d::ViewMenu2d::iOrderY(){
    return xOrder;
}

//set the menu colors
void edk::gui2d::ViewMenu2d::setColorNormal(edk::color3f32 color){
    this->setColorNormal(edk::color4f32(color.r,color.g,color.b,1.f));
}
void edk::gui2d::ViewMenu2d::setColorNormal(edk::color4f32 color){
    this->color[edk::gui2d::gui2dTextureNormal] = color;

    //set objects color
    edk::gui2d::MenuObj* obj = NULL;
    edk::uint32 size = this->objs.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);
        if(obj){
            obj->color[edk::gui2d::gui2dTextureNormal] = this->color[edk::gui2d::gui2dTextureNormal];
        }
    }
}
void edk::gui2d::ViewMenu2d::setColorNormal(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setColorNormal(edk::color4f32(r,g,b,1.f));
}
void edk::gui2d::ViewMenu2d::setColorNormal(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setColorNormal(edk::color4f32(r,g,b,a));
}
void edk::gui2d::ViewMenu2d::setColorUp(edk::color3f32 color){
    //
    this->setColorUp(edk::color4f32(color.r,color.g,color.b,1.f));
}
void edk::gui2d::ViewMenu2d::setColorUp(edk::color4f32 color){
    //
    this->color[edk::gui2d::gui2dTextureUp] = color;

    //set objects color
    edk::gui2d::MenuObj* obj = NULL;
    edk::uint32 size = this->objs.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);
        if(obj){
            obj->color[edk::gui2d::gui2dTextureUp] = this->color[edk::gui2d::gui2dTextureUp];
        }
    }
}
void edk::gui2d::ViewMenu2d::setColorUp(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setColorUp(edk::color4f32(r,g,b,1.f));
}
void edk::gui2d::ViewMenu2d::setColorUp(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setColorUp(edk::color4f32(r,g,b,a));
}
void edk::gui2d::ViewMenu2d::setColorPressed(edk::color3f32 color){
    //
    this->setColorPressed(edk::color4f32(color.r,color.g,color.b,1.f));
}
void edk::gui2d::ViewMenu2d::setColorPressed(edk::color4f32 color){
    //
    this->color[edk::gui2d::gui2dTexturePressed] = color;

    //set objects color
    edk::gui2d::MenuObj* obj = NULL;
    edk::uint32 size = this->objs.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);
        if(obj){
            obj->color[edk::gui2d::gui2dTexturePressed] = this->color[edk::gui2d::gui2dTexturePressed];
        }
    }
}
void edk::gui2d::ViewMenu2d::setColorPressed(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setColorPressed(edk::color4f32(r,g,b,1.f));
}
void edk::gui2d::ViewMenu2d::setColorPressed(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    this->setColorPressed(edk::color4f32(r,g,b,a));
}
void edk::gui2d::ViewMenu2d::setColorPressedUp(edk::color3f32 color){
    //
    this->setColorPressedUp(edk::color4f32(color.r,color.g,color.b,1.f));
}
void edk::gui2d::ViewMenu2d::setColorPressedUp(edk::color4f32 color){
    //
    this->color[edk::gui2d::gui2dTexturePressedUp] = color;

    //set objects color
    edk::gui2d::MenuObj* obj = NULL;
    edk::uint32 size = this->objs.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);
        if(obj){
            obj->color[edk::gui2d::gui2dTexturePressedUp] = this->color[edk::gui2d::gui2dTexturePressedUp];
        }
    }
}
void edk::gui2d::ViewMenu2d::setColorPressedUp(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setColorPressedUp(edk::color4f32(r,g,b,1.f));
}
void edk::gui2d::ViewMenu2d::setColorPressedUp(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    //
    this->setColorPressedUp(edk::color4f32(r,g,b,a));
}

void edk::gui2d::ViewMenu2d::load(edk::rectf32){
    this->objSelected = NULL;
    this->mouseStatus = edk::gui2d::gui2dMouseNothing;
    //
    this->saveFrame = edk::rectf32();
    this->camera.setSize(20,20);
    this->mouseOn = false;

    //clean the objects status
    edk::gui2d::MenuObj* obj = NULL;
    edk::uint32 size = this->objs.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);
        if(obj){
            obj->setStatus(edk::gui2d::gui2dTextureNormal);
        }
    }
}
void edk::gui2d::ViewMenu2d::unload(){
    //
}
void edk::gui2d::ViewMenu2d::update(edk::WindowEvents* events){
    //
    this->runSelection = false;
    edk::uint32 size = 0u;

    //change trees
    if(this->selectTree == &this->tree1){
        this->selectTree = &this->tree2;
        this->selectTreeS = &this->tree1;
    }
    else{
        this->selectTree = &this->tree1;
        this->selectTreeS = &this->tree2;
    }

    //save the mouse status
    this->mouseStatus = edk::gui2d::gui2dMouseNothing;

    size = events->mousePressed.size();
    //test the buttons
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mousePressed.get(i)){
        case edk::mouse::left:
            this->mouseStatus = edk::gui2d::gui2dMousePressed;
            this->runSelection = true;
            break;
        }
    }
    size = events->mouseHolded.size();
    //test the buttons
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mouseHolded.get(i)){
        case edk::mouse::left:
            if(this->mouseStatus != edk::gui2d::gui2dMousePressed){
                this->mouseStatus = edk::gui2d::gui2dMouseHolded;
            }
            this->runSelection = true;
            break;
        }
    }
    size = events->mouseRelease.size();
    //test the buttons
    for(edk::uint32 i=0u;i<size;i++){
        switch(events->mouseRelease.get(i)){
        case edk::mouse::left:
            this->mouseStatus = edk::gui2d::gui2dMouseRelease;
            this->runSelection = true;
            if(!this->xOrder && this->objSelected){
                //then activate button
                this->processExec(this->objSelected);
            }
            break;
        }
    }

    if(events->mouseMoved || this->runSelection){
        //
        this->runSelection = true;
        this->testSelection(events->mousePosView);
    }
}
void edk::gui2d::ViewMenu2d::drawSelectionScene(){
    //draw the objects
    edk::uint32 size = this->objs.size();
    edk::gui2d::MenuObj* obj=NULL;
    for(edk::uint32 i=0u;i<size;i++){
        //
        this->selectionPushName(i);
        obj = this->objs.get(i);
        obj->draw();
        this->selectionPopName();
    }
}
void edk::gui2d::ViewMenu2d::drawScene(edk::rectf32){
    if(this->saveFrame!=this->frame){
        this->saveFrame=this->frame;
        this->updateCamera();
    }

    edk::uint32 size = 0u;
    edk::uint32 sizeSelected = 0u;
    edk::gui2d::MenuObj* obj = NULL;
    if(this->runSelection){
        this->objSelected = NULL;
        sizeSelected = this->selectTree->size();
        if(sizeSelected){
            {
                //get the object
                this->objSelected = this->objs.get(this->selectTree->getElementInPosition(0u));
                if(this->objSelected){
                    //test the mouse status
                    switch(this->mouseStatus){
                    case edk::gui2d::gui2dMousePressed:
                        //change the mouse on
                        this->mouseOn=!this->mouseOn;

                        //test if is xOrder
                        if(this->xOrder && this->mouseOn){
                            //then activate button
                            this->processExec(this->objSelected);
                        }
                        break;
                    case edk::gui2d::gui2dMouseRelease:
                        //test if is NOT xOrder
                        if(!this->xOrder){
                            //run button action
                            this->processExec(this->objSelected);
                        }
                        break;
                    case edk::gui2d::gui2dMouseHolded:
                    case edk::gui2d::gui2dMouseNothing:
                    case edk::gui2d::gui2dMouseStatusSize:
                        break;
                    }

                    //test if the mouse is on
                    if(this->mouseOn || !this->xOrder){
                        this->mouseOn = true;
                        //set the button status to pressedUp
                        this->objSelected->setStatus(edk::gui2d::gui2dTexturePressedUp);
                        if(!this->objSelected->active){
                            this->objSelected->active = true;
                            processEnable(this->objSelected);
                        }
                    }
                    else{
                        //set the button status to op
                        this->objSelected->setStatus(edk::gui2d::gui2dTextureUp);
                        if(this->objSelected->active){
                            this->objSelected->active = false;
                            processDisable(this->objSelected);
                        }
                    }
                }
            }

            edk::uint32 n;
            for(edk::uint32 i=1u;i<sizeSelected;i++){
                //remove this position
                n = this->selectTree->getElementInPosition(1u);
                this->selectTreeS->add(n);
                this->selectTree->remove(n);

            }
        }
        else{
            if(this->mouseStatus==edk::gui2d::gui2dMouseRelease){
                this->mouseOn=false;
            }
        }
        size = this->selectTreeS->size();

        if(size){
            for(edk::uint32 i=0u;i<size;i++){
                //get the object
                obj = this->objs.get(this->selectTreeS->getElementInPosition(i));
                if(obj){
                    if(!this->mouseOn || sizeSelected){
                        obj->setStatus(edk::gui2d::gui2dTextureNormal);
                        if(obj->active){
                            //desactivate the button
                            obj->active = false;
                            processDisable(obj);
                        }
                    }
                    else{
                        if(obj->active){
                            obj->setStatus(edk::gui2d::gui2dTexturePressed);
                        }
                        else{
                            obj->setStatus(edk::gui2d::gui2dTextureNormal);
                        }
                    }
                }
            }
            this->selectTreeS->clean();
        }
        else{
            if(sizeSelected || this->mouseStatus==edk::gui2d::gui2dMouseRelease){
                //clean all objects on the list unless the selected
                size = this->objs.size();
                for(edk::uint32 i=0u;i<size;i++){
                    obj = this->objs.get(i);
                    if(obj && obj!=this->objSelected){
                        obj->setStatus(edk::gui2d::gui2dTextureNormal);
                        if(obj->active){
                            //desactivate the button
                            obj->active = false;
                            processDisable(obj);
                        }
                    }
                }
            }
        }
    }

    //draw the objects
    size = this->objs.size();
    obj=NULL;
    for(edk::uint32 i=0u;i<size;i++){
        //
        obj = this->objs.get(i);
        obj->draw();
    }
}

//callback
bool edk::gui2d::ViewMenu2d::addCallback(edk::gui2d::Menu2dCallback* callback){
    //test the callback
    if(callback){
        //test if have this callback inside the list
        if(!this->listCallback.haveElement(callback)){
            //add the callback to the list
            edk::uint32 size = this->listCallback.size();
            this->listCallback.pushBack(callback);
            if(size<this->listCallback.size()){
                return true;
            }
        }
    }
    return false;
}
bool edk::gui2d::ViewMenu2d::removeCallback(edk::gui2d::Menu2dCallback* callback){
    //test the callback
    if(callback){
        //test if have this callback inside the list
        edk::uint32 pos = this->listCallback.find(callback);
        if(!pos){
            if(this->listCallback.get(pos) != callback){
                return false;
            }
        }
        return this->listCallback.remove(pos);
    }
    return false;
}
void edk::gui2d::ViewMenu2d::cleanCallbacks(){
    this->listCallback.clean();
}

