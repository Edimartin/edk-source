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

        this->activate=true;
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
                edk::size2ui32 texSize = mesh->material.getTextureSize(0u).widthHeight();
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
                edk::size2ui32 texSize = mesh->material.getTextureSize(0u).widthHeight();
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
    if(status < edk::gui2d::gui2dTextureSize){
        //set the status
        this->status = status;
        return true;
    }
    return false;
}

//set hide or show
void edk::gui2d::MenuObj::setBackgroundHide(){
    this->obj.hide();
}
void edk::gui2d::MenuObj::setBackgroundUnhide(){
    this->obj.unhide();
}
bool edk::gui2d::MenuObj::getBackgroundHided(){
    return this->obj.getHided();
}
void edk::gui2d::MenuObj::setBackgroundColor(edk::color4f32 color){
    edk::shape::Mesh2D* mesh = this->obj.getMesh(0u);
    if(mesh){
        mesh->material.setEmission(color);
        mesh->material.setAmbient(color);
        mesh->material.setDiffuse(color);
    }
}
void edk::gui2d::MenuObj::setBackgroundColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setBackgroundColor(edk::color4f32(r,g,b,a));
}
void edk::gui2d::MenuObj::setBackgroundColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setBackgroundColor(edk::color4f32(r,g,b,1.f));
}
void edk::gui2d::MenuObj::setBackgroundAlpha(edk::float32 alpha){
    edk::shape::Mesh2D* mesh = this->obj.getMesh(0u);
    if(mesh){
        mesh->material.setEmissionA(alpha);
        mesh->material.setAmbientA(alpha);
        mesh->material.setDiffuseA(alpha);
    }
}
void edk::gui2d::MenuObj::setTextColor(edk::color4f32 color){
    this->text1.setColor(color);
    this->text2.setColor(color);
}
void edk::gui2d::MenuObj::setTextColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    this->setTextColor(edk::color4f32(r,g,b,a));
}
void edk::gui2d::MenuObj::setTextColor(edk::float32 r,edk::float32 g,edk::float32 b){
    this->setTextColor(edk::color4f32(r,g,b,1.f));
}
void edk::gui2d::MenuObj::setTextAlpha(edk::float32 alpha){
    this->text1.setAlpha(alpha);
    this->text2.setAlpha(alpha);
}

void edk::gui2d::MenuObj::setActivate(bool can){
    this->activate = can;
}
void edk::gui2d::MenuObj::setCanActivate(){
    this->setActivate(true);
}
void edk::gui2d::MenuObj::setCantActivate(){
    this->setActivate(false);
}
bool edk::gui2d::MenuObj::getActivate(){
    return this->activate;
}

bool edk::gui2d::MenuObj::calculateBoundingBox(){
    return this->obj.calculateBoundingBox();
}
bool edk::gui2d::MenuObj::calculateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->obj.calculateBoundingBox(transformMat);
}
bool edk::gui2d::MenuObj::generateBoundingBox(){
    return this->obj.generateBoundingBox();
}
bool edk::gui2d::MenuObj::generateBoundingBox(edk::vector::Matrixf32<3u,3u>* transformMat){
    return this->obj.generateBoundingBox(transformMat);
}

//return a copy of the boundingBox
edk::rectf32 edk::gui2d::MenuObj::getBoundingBox(){
    return this->obj.getBoundingBox();
}

//XML
bool edk::gui2d::MenuObj::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_VIEWMENU,nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //WRITE
                        //write the mesh

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
bool edk::gui2d::MenuObj::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_VIEWMENU,nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //this->cleanMeshes();

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
bool edk::gui2d::MenuObj::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_VIEWMENU,nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    //this->cleanMeshes();

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

        this->percentCamera=0.f;
        this->setBarPercent(0u);
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

        this->cleanObjects();

        this->tree1.Destructor();
        this->tree2.Destructor();
        this->listCallback.Destructor();
        this->objs.Destructor();
    }
    edk::ViewGU2D::Destructor();
}

void edk::gui2d::ViewMenu2d::cleanObjects(){
    edk::uint32 size = this->objs.size();
    edk::gui2d::MenuObj* obj = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);
        if(obj){
            delete obj;
        }
    }
    this->objs.clean();
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
void edk::gui2d::ViewMenu2d::processExec(edk::gui2d::MenuObj* obj,edk::uint32 mouseButton){
    //get the list size
    edk::uint32 size = this->listCallback.size();
    edk::gui2d::Menu2dCallback* pointer = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);
        if(pointer){
            //process the function
            pointer->exec(this,obj,mouseButton);
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
    edk::size2f32 sizeCamera;
    bool useBar=false;
    if(!edk::Math::equal(0.f,this->positions.x)
            && !edk::Math::equal(0.f,this->positions.y)
            && !edk::Math::equal(0.f,this->frame.size.width)
            && !edk::Math::equal(0.f,this->frame.size.height)
            ){
        if(this->xOrder){
            //
            sizeCamera = edk::size2f32(this->positions.y *
                                       (edk::float32)this->frame.size.width / (edk::float32)this->frame.size.height,
                                       this->positions.y
                                       );

            //test if the box is bigger than camera
            if(sizeCamera.width < this->box.size.width){
                useBar=true;
                //increment the height
                sizeCamera.height*=1.0f + (this->percentBar*2.0f);
                if(!this->haveSubview(&this->bar)){
                    this->addSubview(&this->bar);
                }
                //update the bar size
                this->bar.frame = edk::rectf32(-2.f,//X
                                               (this->frame.size.height-(this->frame.size.height * this->percentBar * 1.75f)),//Y
                                               this->frame.size.width-2.f,//W
                                               (this->frame.size.height * this->percentBar * 1.75f)//H
                                               );
                //set the bar orientation
                this->bar.setBorderSize(1.f);
                this->bar.setForegroundSize(sizeCamera.width / this->box.size.width,1.f);
                this->bar.setBackColor(0.f,0.f,0.f,0.f);
                this->bar.setFrontColor(0.5,0.5,0.5,1.0);
                this->bar.setPercentX(this->percentCamera);
            }
            else{
                if(this->haveSubview(&this->bar)){
                    this->removeSubview(&this->bar);
                }
            }

            //this->frame.size;
            this->camera.setRectPoints(0,0
                                       ,sizeCamera.width
                                       ,sizeCamera.height
                                       );
            this->cameraStartPos=0.f;
            if(useBar){
                this->cameraEndPos = this->cameraStartPos + (this->box.size.width - sizeCamera.width);
            }
            else{
                this->cameraEndPos = this->cameraStartPos;
            }
        }
        else{
            sizeCamera = edk::size2f32(this->positions.x,
                                       (this->positions.x *
                                        this->frame.size.height / this->frame.size.width)
                                       );

            //test if the box is bigger than camera
            if(sizeCamera.height < this->box.size.height){
                useBar=true;
                //increment the width
                sizeCamera.width*=1.0f + (this->percentBar*2.0f);
                if(!this->haveSubview(&this->bar)){
                    this->addSubview(&this->bar);
                }
                //update the bar size
                this->bar.frame = edk::rectf32((this->frame.size.width-(this->frame.size.width * this->percentBar * 1.75f)),//X
                                               -2.f,//Y
                                               (this->frame.size.width * this->percentBar * 1.75f),//W
                                               this->frame.size.height-2.f //H
                                               );
                //set the bar orientation
                this->bar.setBorderSize(1.f);
                this->bar.setForegroundSize(1.f,sizeCamera.height / this->box.size.height);
                this->bar.setBackColor(0.f,0.f,0.f,0.f);
                this->bar.setFrontColor(0.5,0.5,0.5,1.0);
                this->bar.setPercentY(this->percentCamera);
            }
            else{
                if(this->haveSubview(&this->bar)){
                    this->removeSubview(&this->bar);
                }
            }

            //
            this->camera.setRectPoints(0,0
                                       ,sizeCamera.width
                                       ,sizeCamera.height
                                       );
            this->cameraStartPos = 0.f + this->positions.y - this->camera.getSize().height*0.5f;
            if(useBar){
                this->cameraEndPos = this->cameraStartPos - (this->box.size.height - sizeCamera.height);
            }
            else{
                this->cameraEndPos = this->cameraStartPos;
            }
        }

    }
    this->moveCamera(this->percentCamera);
}
void edk::gui2d::ViewMenu2d::moveCamera(edk::float32 percent){
    if(this->xOrder){
        //X
        this->camera.position.x = ((this->cameraEndPos - this->cameraStartPos) * percent) + this->cameraStartPos;
    }
    else{
        //Y
        this->camera.position.y = ((this->cameraEndPos - this->cameraStartPos) * percent) + this->cameraStartPos;
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

    //update the box
    this->box = this->updateBoundingBox();
}
//update the scene boundingBox
edk::rectf32 edk::gui2d::ViewMenu2d::updateBoundingBox(){
    edk::rectf32 ret;
    edk::uint32 size = this->objs.size();
    edk::gui2d::MenuObj* obj = NULL;
    if(size){
        obj = this->objs.get(0u);
        if(obj){
            obj->calculateBoundingBox();
            ret = obj->getBoundingBox();
        }
        for(edk::uint32 i=1u;i<size;i++){
            obj = this->objs.get(i);
            if(obj){
                obj->calculateBoundingBox();
                ret.merge(obj->getBoundingBox());
            }
        }
    }
    return ret;
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
                obj->setActivate(false);

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
//get the bounding box size in screen
edk::rectf32 edk::gui2d::ViewMenu2d::getBoxScreen(){
    edk::rectf32 ret;
    edk::vec2f32 vec;
    vec = this->convertPositionWorldToScreen(this->box.origin.x,this->box.origin.y);
    ret.origin.x = vec.x;
    ret.origin.y = vec.y;
    vec = this->convertPositionWorldToScreen(this->box.size.width,this->box.size.height);
    ret.size.width  = vec.x;
    ret.size.height = vec.y;
    return ret;
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

//get the object in position
edk::gui2d::MenuObj* edk::gui2d::ViewMenu2d::getObjectInPosition(edk::uint32 position){
    return this->objs.get(position);
}
edk::gui2d::MenuObj* edk::gui2d::ViewMenu2d::getObjectById(edk::uint32 id){
    edk::gui2d::MenuObj* obj = NULL;
    edk::uint32 size = this->objs.size();
    for(edk::uint32 i=0u;i<size;i++){
        obj = this->objs.get(i);
        if(obj){
            if(obj->id == id){
                return obj;
            }
        }
    }
    return NULL;
}

bool edk::gui2d::ViewMenu2d::setBarPercent(edk::float32 percent){
    if(percent){
        this->percentBar = percent;
        return true;
    }
    this->percentBar = edkGui2dPercentBar;
    return false;
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

bool edk::gui2d::ViewMenu2d::isMouseInside(){
    if(edk::View::isMouseInside()){
        return true;
    }
    else if(this->bar.isMouseInside()){
        return true;
    }
    return false;
}

void edk::gui2d::ViewMenu2d::load(edk::rectf32){
    this->treeButtonsMouse.clean();
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
    this->treeButtonsMouse.clean();
    //
}
void edk::gui2d::ViewMenu2d::update(edk::WindowEvents* events){
    this->treeButtonsMouse.clean();
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
            if(!this->xOrder && this->objSelected && this->isMouseInside()){
                //then activate button
                this->processExec(this->objSelected,edk::mouse::left);
            }
            this->treeButtonsMouse.add(edk::mouse::left);
            break;
        case edk::mouse::right:
            this->mouseStatus = edk::gui2d::gui2dMouseRelease;
            this->runSelection = true;
            if(!this->xOrder && this->objSelected && this->isMouseInside()){
                //then activate button
                this->processExec(this->objSelected,edk::mouse::right);
            }
            this->treeButtonsMouse.add(edk::mouse::right);
            break;
        case edk::mouse::middle:
            this->mouseStatus = edk::gui2d::gui2dMouseRelease;
            this->runSelection = true;
            if(!this->xOrder && this->objSelected && this->isMouseInside()){
                //then activate button
                this->processExec(this->objSelected,edk::mouse::middle);
            }
            this->treeButtonsMouse.add(edk::mouse::middle);
            break;
        case edk::mouse::xButton1:
            this->mouseStatus = edk::gui2d::gui2dMouseRelease;
            this->runSelection = true;
            if(!this->xOrder && this->objSelected && this->isMouseInside()){
                //then activate button
                this->processExec(this->objSelected,edk::mouse::xButton1);
            }
            this->treeButtonsMouse.add(edk::mouse::xButton1);
            break;
        case edk::mouse::xButton2:
            this->mouseStatus = edk::gui2d::gui2dMouseRelease;
            this->runSelection = true;
            if(!this->xOrder && this->objSelected && this->isMouseInside()){
                //then activate button
                this->processExec(this->objSelected,edk::mouse::xButton2);
            }
            this->treeButtonsMouse.add(edk::mouse::xButton2);
            break;
        }
    }

    if(events->mouseMoved || this->runSelection){
        //
        this->runSelection = true;
        this->testSelection(events->mousePosView);
    }


    //process the scroll
    if(events->mouseScrollWheelVertical){
        if(this->haveSubview(&this->bar)){
            if(this->isMouseInside() || this->bar.isMouseInside()){
                this->percentCamera+=(events->mouseScrollWheelVertical * -0.1f);
                if(this->percentCamera<0.f){this->percentCamera=0.f;}
                if(this->percentCamera>1.f){this->percentCamera=1.f;}
                //set the bar percent
                if(this->xOrder){
                    this->bar.setPercentX(this->percentCamera);
                }
                else{
                    this->bar.setPercentY(this->percentCamera);
                }
                this->moveCamera(this->percentCamera);
                //process the selection when move the camera
                this->runSelection = true;
                this->testSelection(events->mousePosView);
            }
        }
    }


    //update the camera position using the percent

    if(this->haveSubview(&this->bar)){
        if(this->xOrder){
            if(!edk::Math::equal(this->percentCamera,this->bar.getPercentX())){
                //move camera
                this->percentCamera = this->bar.getPercentX();
                this->moveCamera(this->percentCamera);
                //process the selection when move the camera
                this->runSelection = true;
                this->testSelection(events->mousePosView);
            }
        }
        else{
            if(!edk::Math::equal(this->percentCamera,this->bar.getPercentY())){
                //move camera
                this->percentCamera = this->bar.getPercentY();
                this->moveCamera(this->percentCamera);
                //process the selection when move the camera
                this->runSelection = true;
                this->testSelection(events->mousePosView);
            }
        }
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
void edk::gui2d::ViewMenu2d::finishSelection(){
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
                            edk::uint32 size = this->treeButtonsMouse.size();
                            for(edk::uint32 i=0u;i<size;i++){
                                this->processExec(this->objSelected,this->treeButtonsMouse.getElementInPosition(i));
                            }
                        }
                        break;
                    case edk::gui2d::gui2dMouseRelease:
                        //test if is NOT xOrder
                        if(!this->xOrder){
                            //run button action
                            /*
                            edk::uint32 size = this->treeButtonsMouse.size();
                            for(edk::uint32 i=0u;i<size;i++){
                                this->processExec(this->objSelected,this->treeButtonsMouse.getElementInPosition(i));
                            }
                            */
                        }
                        break;
                    case edk::gui2d::gui2dMouseHolded:
                    case edk::gui2d::gui2dMouseNothing:
                    default:
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
                        if(obj->active && obj->getActivate()){
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
                            this->processDisable(obj);
                        }
                    }
                }
            }
        }
    }
}
void edk::gui2d::ViewMenu2d::drawScene(edk::rectf32){
    if(this->saveFrame!=this->frame){
        this->saveFrame=this->frame;
        this->updateCamera();
    }
    edk::uint32 size = 0u;
    edk::gui2d::MenuObj* obj = NULL;

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

