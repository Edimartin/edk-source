#include "ViewMenu2d.h"


edk::gui2d::MenuObj::MenuObj(){
    //
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
edk::gui2d::MenuObj::~MenuObj(){
    //
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
bool edk::gui2d::MenuObj::loadObject(edk::char8* spriteName,edk::char8* text1,edk::char8* text2){
    this->sprite.cleanMeshes();
    this->text1.deleteMap();
    this->text2.deleteMap();
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
    if(text1){
        //test the size of the text
        if(edk::String::strSize(text1)){
            //create the fontMap
            this->text1.deleteMap();
            this->text1.setScale(edkGui2dInsideHeight*0.5f,edkGui2dInsideHeight);
            this->positionText1 = this->obj.size.width;
            if(this->text1.createStringMap(text1)){
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
void edk::gui2d::MenuObj::updateSizes(){
    this->positionText1 = this->positionText2 = 0.f;
    //set the object size
    this->obj.size = edk::size2f32(0,1);
    this->sprite.size = edkGui2dInsideHeight;

    this->obj.size.width += edkGui2dInsideBorder;

    this->obj.size.width += this->sprite.size.width;
    this->obj.size.width += edkGui2dInsideBorder;

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

edk::gui2d::ViewMenu2d::ViewMenu2d(){
    //
    this->xOrder = true;
    this->positions = edk::vec2f32(0,0);
}
edk::gui2d::ViewMenu2d::~ViewMenu2d(){
    //
}

//update camera size and position to have all the objects
void edk::gui2d::ViewMenu2d::updateCamera(){
    //
    if(this->positions.x!= 0.f && this->positions.y!=0.f){
        if(this->xOrder){
            //
            //this->frame.size;
            this->camera.setRect(0,0
                                 ,this->positions.y * (edk::float32)this->frame.size.width / (edk::float32)this->frame.size.height
                                 ,this->positions.y
                                 );
        }
        else{
            //
            this->camera.setRect(0
                                 ,0
                                 ,this->positions.x
                                 ,(this->positions.x * (edk::float32)this->frame.size.height / (edk::float32)this->frame.size.width)
                                 );
            //this->camera.setRect(0,0,this->positions.x,this->positions.y);
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
            obj = this->objs[i];
            if(obj){
                //
                obj->updateSizes();
                //set the object position
                obj->setPosition(this->positions.x + obj->getSize().width*0.5f,obj->getSize().height*0.5f);
                //increment the positions
                this->positions.x += obj->getSize().width;
                if(obj->getSize().height>this->positions.y)
                    this->positions.y = obj->getSize().height;

            }
        }
    }
    else{
        edk::float32 width = 0.f;
        for(edk::uint32 i=0u;i<size;i++){
            //
            obj = this->objs[i];
            if(obj){
                //
                //increment the positions
                if(obj->getSize().width>width)
                    width = obj->getSize().width;
            }
        }

        //calculate the max width
        for(edk::uint32 i=size;i>0u;i--){
            //
            obj = this->objs[i-1u];
            if(obj){
                //

                //set the object size
                obj->setSize(width,obj->getSize().height);
                //set the object position
                obj->setPosition(width*0.5f,this->positions.y + obj->getSize().height*0.5f);
                //increment the positions
                this->positions.y += obj->getSize().height;
                if(obj->getSize().width>this->positions.x)
                    this->positions.x = obj->getSize().width;
            }
        }
    }
}

//create a new object
edk::uint32 edk::gui2d::ViewMenu2d::newObject(edk::char8* spriteName,edk::char8* text1,edk::char8* text2){
    //
    edk::gui2d::MenuObj* obj = new edk::gui2d::MenuObj;
    if(obj){
        if(obj->loadObject(spriteName,text1,text2)){
            edk::uint32 size = this->objs.size();
            //add the object to the stack
            edk::uint32 ret = this->objs.pushBack(obj);
            if(size != this->objs.size()){
                this->updatePositions();

                //set the obj paramerets
                obj->color[edk::gui2d::gui2dTextureNormal] = edk::color4f32(0.5f,0.5f,0.5f,1.f);

                return ret;
            }
        }
        delete obj;
    }
    return 0u;
}
edk::uint32 edk::gui2d::ViewMenu2d::newObject(const edk::char8* spriteName,const edk::char8* text1,const edk::char8* text2){
    return newObject((edk::char8*) spriteName,(edk::char8*) text1,(edk::char8*) text2);
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

void edk::gui2d::ViewMenu2d::load(edk::rectf32){
    //
    this->camera.setSize(20,20);
    //this->camera.setRect(0,0,10,10);
}
void edk::gui2d::ViewMenu2d::unload(){
    //
}
void edk::gui2d::ViewMenu2d::update(edk::WindowEvents*){
    //
}
void edk::gui2d::ViewMenu2d::drawScene(edk::rectf32){
    if(this->saveFrame!=this->frame){
        this->saveFrame=this->frame;
        this->updateCamera();
    }

    //draw the objects
    edk::uint32 size = this->objs.size();
    edk::gui2d::MenuObj* obj=NULL;
    for(edk::uint32 i=0u;i<size;i++){
        //
        obj = this->objs[i];
        obj->draw();
    }
}

