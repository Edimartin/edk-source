#include "ViewGui2d.h"

/*
ViewGui2d - View to show the objects on the GUI 2D library
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
#pragma message "            Inside ViewGui2d.cpp"
#endif

edk::gui2d::ViewGui2d::ViewGui2d(){
    this->classThis=NULL;
    this->Constructor();
}
edk::gui2d::ViewGui2d::~ViewGui2d(){
    this->Destructor();
}

void edk::gui2d::ViewGui2d::Constructor(){
    edk::ViewGU2D::Constructor();
    if(this->classThis!=this){
        this->classThis=this;

        this->scrollH.Constructor();
        this->scrollV.Constructor();
        this->tree1.Constructor();
        this->tree2.Constructor();
        this->volume.Constructor();
        this->distanceClick.Constructor();
        this->distanceDoubleClick.Constructor();
        this->listCallback.Constructor();
        this->list.Constructor();

        this->setTablePoints(0.f,0.f,1.f,1.f);

        this->mouseMoving=false;
        this->objPressed=NULL;
        this->idCounter = 0u;
        this->mouseStatus = edk::gui2d::gui2dMouseNothing;
        this->objPressed = NULL;
        this->objSelected = NULL;
        this->idSelected = 0u;
        this->selectTree = &this->tree1;
        this->selectTreeS = &this->tree2;
        this->shift = false;
        //press quote
        this->pressQuote=false;
        this->pressTilde=false;
        //start the distances
        this->distanceClick.start();
        this->distanceDoubleClick.start();
        //run doubleClick
        this->doubleClick=false;
        this->tableMove=edk::gui2d::gui2dTableMoveNoWay;

        this->percentMoveCamera = 0.5f;
        this->percentMoveSpeed = edk::vec2f32(1.f,1.f);
        this->useScroll=0u;

        this->enableMouse();

        edk::shape::Mesh2D* mesh = this->objTable.newMesh(0u);
        if(mesh){
            edk::shape::Rectangle2D rect;
            rect.setPivoToCenter();
            mesh->addPolygon(rect);

            mesh->material.setAmbient (1.f,1.f,1.f,0.f);
            mesh->material.setEmission(1.f,1.f,1.f,0.f);
            mesh->material.setDiffuse (1.f,1.f,1.f,0.f);
        }
    }
}
void edk::gui2d::ViewGui2d::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->tree1.clean();
        this->tree2.clean();
        this->volume.cleanMeshes();

        this->scrollH.Destructor();
        this->scrollV.Destructor();
        this->tree1.Destructor();
        this->tree2.Destructor();
        this->volume.Destructor();
        this->distanceClick.Destructor();
        this->distanceDoubleClick.Destructor();
        this->listCallback.Destructor();
        this->list.Destructor();

        this->objTable.clean();
    }
    edk::ViewGU2D::Destructor();
}

void edk::gui2d::ViewGui2d::clean(){
    this->removeAllSubview();
    this->removeAllObjectGui2d();
    //
    this->setTablePoints(0.f,0.f,1.f,1.f);
    this->mouseMoving=false;
    this->objPressed=NULL;
    this->idCounter = 0u;
    this->mouseStatus = edk::gui2d::gui2dMouseNothing;
    this->objSelected = NULL;
    this->idSelected = 0u;
    this->selectTree = &this->tree1;
    this->selectTreeS = &this->tree2;
    this->shift = false;
    //press quote
    this->pressQuote=false;
    this->pressTilde=false;
    //start the distances
    this->distanceClick.start();
    this->distanceDoubleClick.start();
    //run doubleClick
    this->doubleClick=false;
    this->tableMove=edk::gui2d::gui2dTableMoveNoWay;
}

//return true if have the element on the callback list
bool edk::gui2d::ViewGui2d::haveCallback(edk::gui2d::ObjectGui2dCallback* callback){
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
void edk::gui2d::ViewGui2d::processMousePressed(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton){
    //get the list size
    edk::uint32 size = this->listCallback.size();
    edk::gui2d::ObjectGui2dCallback* pointer = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);
        if(pointer){
            //process the function
            pointer->mousePressed(button,mouseButton);
        }
    }
}
void edk::gui2d::ViewGui2d::processMouseRelease(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton,bool isInside){
    //get the list size
    edk::uint32 size = this->listCallback.size();
    edk::gui2d::ObjectGui2dCallback* pointer = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);
        if(pointer){
            //process the function
            pointer->mouseRelease(button,mouseButton,isInside);
        }
    }
}
void edk::gui2d::ViewGui2d::processMouseHolded(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton){
    //get the list size
    edk::uint32 size = this->listCallback.size();
    edk::gui2d::ObjectGui2dCallback* pointer = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);
        if(pointer){
            //process the function
            pointer->mouseHolded(button,mouseButton);
        }
    }
}
void edk::gui2d::ViewGui2d::processReturnPressed(edk::gui2d::ObjectGui2d* textField){
    //get the list size
    edk::uint32 size = this->listCallback.size();
    edk::gui2d::ObjectGui2dCallback* pointer = NULL;
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);
        if(pointer){
            //process the function
            pointer->returnPressed(textField);
        }
    }
}

//update the camera in view from the table
void edk::gui2d::ViewGui2d::updateCameraFromTable(){
    this->percentMoveSpeed = 1.f;
    this->rectMoveCamera = edk::rectf32(0.f,0.f,0.f,0.f);
    edk::rectf32 rect;
    edk::rectf32 rectTable;
    edk::rectf32 rectTemp;
    edk::float32 scrollPercent=0.05f;
    edk::uint8 saveUseScroll = this->useScroll;
    this->useScroll=0u;

    rectTable = this->table;
    rectTable.convertIntoPositionAndSize();
    this->objTable.position = rectTable.origin;
    this->objTable.size = rectTable.size;

    //
    switch(this->tableMove){
    default:
    case edk::gui2d::gui2dTableMoveNoWay:
        rect = this->frame;
        rect.size.width+=rect.origin.x;
        rect.size.height+=rect.origin.y;
        rect.convertIntoPositionAndSize();
        rect.origin = this->table.origin;

        rectTable = this->table;
        rectTable.convertIntoPositionAndSize();

        rectTemp = edk::Math::aspectRatioCorrect(rect,rectTable.size);

        if(!edk::Math::equal(rectTemp.size.width,0.f)){
            rect.size.width = (rect.size.width / rectTemp.size.width) * rectTable.size.width;
        }
        else return;
        if(!edk::Math::equal(rectTemp.size.height,0.f)){
            rect.size.height = (rect.size.height / rectTemp.size.height) * rectTable.size.height;
        }
        else return;
        rect.origin = rectTable.origin;

        //calculate the move line
        //X
        this->rectMoveCamera.origin.x = rectTable.origin.x;
        this->rectMoveCamera.size.width = rectTable.origin.x;
        //Y
        this->rectMoveCamera.origin.y = rectTable.origin.y;
        this->rectMoveCamera.size.height = rectTable.origin.y;

        rect.convertIntoPoints();
        this->camera.setRectPoints(rect);
        break;
    case edk::gui2d::gui2dTableMoveTwoWays:
        rect = this->frame;
        rect.size.width+=rect.origin.x;
        rect.size.height+=rect.origin.y;
        rect.convertIntoPositionAndSize();
        rect.origin = this->table.origin;

        rectTable = this->table;
        rectTable.convertIntoPositionAndSize();
        rectTemp = edk::Math::aspectRatioCorrect(rect,rectTable.size);

        if(!edk::Math::equal(rectTemp.size.width,0.f)){
            rect.size.width = (rect.size.width / rectTemp.size.width) * rectTable.size.width;
        }
        else return;

        if(!edk::Math::equal(rectTemp.size.height,0.f)){
            rect.size.height = (rect.size.height / rectTemp.size.height) * rectTable.size.height;
        }
        else return;
        rect.origin = rectTable.origin;

        //calculate the move line
        //X
        this->rectMoveCamera.origin.x = rectTable.origin.x;
        this->rectMoveCamera.size.width = rectTable.origin.x;
        //Y
        this->rectMoveCamera.origin.y = rectTable.origin.y;
        this->rectMoveCamera.size.height = rectTable.origin.y;

        rect.convertIntoPoints();
        this->camera.setRectPoints(rect);
        break;
    case edk::gui2d::gui2dTableMoveHorizontal:
        rect = this->frame;
        rect.size.width+=rect.origin.x;
        rect.size.height+=rect.origin.y;
        rect.convertIntoPositionAndSize();
        rect.origin = this->table.origin;

        rectTable = this->table;
        rectTable.convertIntoPositionAndSize();

        if(!edk::Math::equal(rect.size.height,0.f)){
            scrollPercent = (rectTable.size.height / rect.size.height) * (edk::float32)scrollSizePixels;
        }
        else return;

        if(!edk::Math::equal(rect.size.height,0.f)){
            rectTemp.size.width = (rect.size.width/rect.size.height) * rectTable.size.height;
        }
        else return;
        rectTemp.size.height = rectTable.size.height;

        if(rectTemp.size.height < rectTable.size.height){
            //calculate the move line
            //X
            this->rectMoveCamera.origin.x = rectTemp.origin.x
                    - (rectTable.size.width*0.5f) + (rectTemp.size.width*0.5f)
                    ;
            this->rectMoveCamera.size.width = rectTemp.origin.x
                    + (rectTable.size.width*0.5f) - (rectTemp.size.width*0.5f)
                    ;
            //Y
            this->rectMoveCamera.origin.y = this->rectMoveCamera.size.height = rectTemp.origin.y
                    - (rectTemp.size.height*scrollPercent * 0.5f)
                    ;
            rectTemp.size.height *= 1.f + scrollPercent;
            this->useScroll=1u;
        }
        else{
            //calculate the move line
            //X
            this->rectMoveCamera.origin.x = rectTemp.origin.x;
            this->rectMoveCamera.size.width = rectTemp.origin.x;
            //Y
            this->rectMoveCamera.origin.y = rectTemp.origin.y;
            this->rectMoveCamera.size.height = rectTemp.origin.y;
        }

        if(!edk::Math::equal(rectTemp.size.width,0.f)){
            this->percentMoveSpeed.x = rectTable.size.width / rectTemp.size.width;
        }

        rectTemp.convertIntoPoints();
        this->camera.setRectPoints(rectTemp);
        break;
    case edk::gui2d::gui2dTableMoveVertical:
        rect = this->frame;
        rect.size.width+=rect.origin.x;
        rect.size.height+=rect.origin.y;
        rect.convertIntoPositionAndSize();
        rect.origin = this->table.origin;

        rectTable = this->table;
        rectTable.convertIntoPositionAndSize();

        if(!edk::Math::equal(rect.size.width,0.f)){
            scrollPercent = (rectTable.size.width / rect.size.width) * (edk::float32)scrollSizePixels;
            scrollPercent = rectTable.size.width / rect.size.width;
        }
        else return;

        rectTemp.size.width = rectTable.size.width;
        if(!edk::Math::equal(rect.size.width,0.f)){
            rectTemp.size.height = (rect.size.height/rect.size.width) * rectTable.size.width;
        }
        else return;
        if(rectTemp.size.height < rectTable.size.height){
            //calculate the move line
            //X
            this->rectMoveCamera.origin.x = this->rectMoveCamera.size.width = rectTemp.origin.x
                    + (rectTemp.size.width * scrollPercent * 0.5f)
                    ;
            //Y
            this->rectMoveCamera.origin.y = rectTemp.origin.y
                    - (rectTable.size.height*0.5f) + (rectTemp.size.height*0.5f)
                    ;
            this->rectMoveCamera.size.height = rectTemp.origin.y
                    + (rectTable.size.height*0.5f) - (rectTemp.size.height*0.5f)
                    ;
            rectTemp.size.width *= 1.f + scrollPercent;
            this->useScroll=2u;
        }
        else{
            //calculate the move line
            //X
            this->rectMoveCamera.origin.x = rectTemp.origin.x;
            this->rectMoveCamera.size.width = rectTemp.origin.x;
            //Y
            this->rectMoveCamera.origin.y = rectTemp.origin.y;
            this->rectMoveCamera.size.height = rectTemp.origin.y;
        }

        if(!edk::Math::equal(rectTemp.size.height,0.f)){
            this->percentMoveSpeed.y = rectTable.size.height / rectTemp.size.height;
        }

        rectTemp.convertIntoPoints();
        this->camera.setRectPoints(rectTemp);

        break;
    }
    //update the view size
    switch(this->useScroll){
    default:
        //continue
        break;
    case 1u:
        //add horizontal
        this->scrollH.frame = edk::rectf32(0.f,
                                           this->frame.size.height - (edk::float32)scrollSizePixels,
                                           this->frame.size.width,
                                           (edk::float32)scrollSizePixels
                                           );
        this->scrollH.setBorderSize(scrollSizePixels*0.5f);
        this->scrollH.setFrontColor(0.5f,0.5f,0.5f);
        this->scrollH.setForegroundSize(this->camera.getSize().width / rectTable.size.width,1.f);
        break;
    case 2u:
        //add vertical
        this->scrollV.frame = edk::rectf32(this->frame.size.width - (edk::float32)scrollSizePixels,
                                           0.f,
                                           (edk::float32)scrollSizePixels,
                                           this->frame.size.height
                                           );
        this->scrollV.setBorderSize(scrollSizePixels*0.5f);
        this->scrollV.setFrontColor(0.5f,0.5f,0.5f);
        this->scrollV.setForegroundSize(1.f,this->camera.getSize().height / rectTable.size.height);
    }
    //test if need put or remove the scroll
    switch(saveUseScroll){
    default:
        //have norhing
        switch(this->useScroll){
        default:
            //continue
            break;
        case 1u:
            //add horizontal
            this->addSubview(&this->scrollH);
            break;
        case 2u:
            //add vertical
            this->addSubview(&this->scrollV);
            break;
        }
        break;
    case 1u:
        //have horizontal
        switch(this->useScroll){
        default:
            //remove horizontal
            this->removeSubview(&this->scrollH);
            break;
        case 1u:
            //continue
            break;
        case 2u:
            //remove horizontal
            this->removeSubview(&this->scrollH);
            //add vertical
            this->addSubview(&this->scrollV);
            break;
        }
        break;
    case 2u:
        //have vertical
        switch(this->useScroll){
        default:
            //remove vertical
            this->removeSubview(&this->scrollV);
            break;
        case 1u:
            //remove vertical
            this->removeSubview(&this->scrollV);
            //add horizontal
            this->addSubview(&this->scrollV);
            break;
        case 2u:
            //continue
            break;
        }
        break;
    }

    this->updateCameraPercentPosition();
}
void edk::gui2d::ViewGui2d::updateCameraPercentPosition(){
    this->camera.position.x = ((this->rectMoveCamera.size.width - this->rectMoveCamera.origin.x)
                               * this->percentMoveCamera.x) + this->rectMoveCamera.origin.x;
    this->camera.position.y = ((this->rectMoveCamera.size.height - this->rectMoveCamera.origin.y)
                               * this->percentMoveCamera.y) + this->rectMoveCamera.origin.y;
    //update the scroll percents
    //this->percentMoveCamera
    this->scrollH.setPercentX((this->percentMoveCamera.x*-1.f)+1.f);
    this->scrollV.setPercentY((this->percentMoveCamera.y*-1.f)+1.f);
    this->savePercentV = this->scrollV.getPercentY();
    this->savePercentH = this->scrollH.getPercentX();
}

void edk::gui2d::ViewGui2d::drawSelectionScene(){
    //
    this->list.print();
}
void edk::gui2d::ViewGui2d::selectObject(edk::uint32 ,edk::int32 ,edk::float32 ,edk::float32 ,edk::vector::Stack<edk::uint32>* names){
    //
    edk::uint32 id=0u;
    edk::gui2d::ObjectGui2d* obj=NULL;
    edk::uint32 size = 0u;


    size = names->size();
    if(size){
        id = names->get(0u);
        //get the object
        obj = this->list.getPointerByID(id);
        if(obj){
            //add the id to the select tree
            this->selectTree->add(id);
            //remove it from the last tree
            this->selectTreeS->remove(id);
        }

        //test if have the second name
        if(size>1u){
            //
            this->idSelected = names->get(1u);
        }
        else{
            this->idSelected = 0u;
        }
    }
}

//add the object
bool edk::gui2d::ViewGui2d::addObjectGui2d(edk::gui2d::ObjectGui2d* obj){
    if(obj){
        if(this->names.addName(obj)){
            if(!this->list.haveObjByPointer(obj)){
                edk::uint32 counter = 0u;
                //add the object to the tree
                while(!this->list.addNewObj(obj,this->idCounter)){
                    this->idCounter+=9u;
                    counter++;
                    if(counter>0xFFFFFFFE){
                        return false;
                    }
                }
                this->idCounter+=1u;
                obj->load();

                //load the volume object
                if(!this->volume.getMeshSize()){
                    edk::shape::Mesh2D* mesh = this->volume.newMesh();
                    if(mesh){
                        edk::shape::Rectangle2D rect;
                        rect.setPolygonColor(1.f,1.f,1.f,0.5f);
                        mesh->addPolygon(rect);
                    }
                }
                return true;
            }
        }
    }
    return false;
}
//remove the object
bool edk::gui2d::ViewGui2d::removeObjectGui2d(edk::gui2d::ObjectGui2d* obj){
    if(obj){
        //test if the obj is the same pressed
        if(this->objPressed == obj){
            this->objPressed=NULL;
        }
        if(this->objSelected == obj){
            this->objSelected->deselect();
            this->objSelected = NULL;
            this->idSelected = 0u;
        }
        this->names.remove(obj);
        return this->list.removeByPointer(obj);
    }
    return false;
}
//remove all objects
void edk::gui2d::ViewGui2d::removeAllObjectGui2d(){
    //test if the obj is the same pressed
    this->objPressed=NULL;
    if(this->objSelected){
        this->objSelected->deselect();
        this->objSelected = NULL;
        this->idSelected = 0u;
    }
    this->names.clean();
    this->list.removeAll();
}
void edk::gui2d::ViewGui2d::deleteAllObjectGui2d(){
    //test if the obj is the same pressed
    this->objPressed=NULL;
    if(this->objSelected){
        this->objSelected->deselect();
        this->objSelected = NULL;
        this->idSelected = 0u;
    }
    this->names.clean();
    this->list.deleteAll();
}
//get the size of objects inside the view
edk::uint32 edk::gui2d::ViewGui2d::getObjectGui2dSize(){
    return this->list.size();
}
//get the object
edk::gui2d::ObjectGui2d* edk::gui2d::ViewGui2d::getObjectInPosition(edk::uint32 position){
    edk::gui2d::ViewGui2d::ObjGui2dID* temp = this->list.getElementInPosition(position);
    if(temp){
        return temp->pointer;
    }
    return NULL;
}
//get object by name
edk::gui2d::ObjectGui2d* edk::gui2d::ViewGui2d::getObjectByName(const edk::char8* name){
    return this->edk::gui2d::ViewGui2d::getObjectByName((edk::char8*) name);
}
edk::gui2d::ObjectGui2d* edk::gui2d::ViewGui2d::getObjectByName(edk::char8* name){
    this->nameTemplate.setName(name);
    return this->names.getElement(&this->nameTemplate);
}
bool edk::gui2d::ViewGui2d::printAllObjectNames(){
    if(this->names.size()){
        printf("\nObjects[%u] names:",this->names.size());
        this->names.print();
        return true;
    }
    return false;
}
bool edk::gui2d::ViewGui2d::printAllObjectTypesAndNames(){
    if(this->names.size()){
        printf("\nObjects[%u] types : names:",this->names.size());
        this->names.render();
        return true;
    }
    return false;
}

//disable the mouse on the view (Can be used to have only one textField on the view).
void edk::gui2d::ViewGui2d::enableMouse(){
    this->mouseOn = true;
}
void edk::gui2d::ViewGui2d::disableMouse(){
    this->mouseOn = false;
}

//function used to select an object on the view
bool edk::gui2d::ViewGui2d::selectObject(edk::gui2d::ObjectGui2d* obj,edk::vec2f32 position){
    //delelect the object
    this->deselectObject(position);
    if(obj){
        obj->select();
        obj->clickStart(this->idSelected,position);
        //select the object
        this->objSelected = obj;
        this->endSelect = true;
    }
    return false;
}
void edk::gui2d::ViewGui2d::deselectObject(edk::vec2f32 position){
    if(this->objSelected){
        this->objSelected->deselect();
        if(this->endSelect){
            this->objSelected->clickEnd(this->idSelected,position,false,this->doubleClick);
        }
        this->endSelect = false;

        this->objSelected = NULL;
        this->idSelected = 0u;
    }
}

//set the table position and size
bool edk::gui2d::ViewGui2d::setTableColor(edk::color4f32 color){
    edk::shape::Mesh2D* mesh = this->objTable.getMesh(0u);
    if(mesh){
        mesh->material.setAmbient(color);
        mesh->material.setDiffuse(color);
        mesh->material.setEmission(color);
        return true;
    }
    return false;
}
bool edk::gui2d::ViewGui2d::setTableColor(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    return this->setTableColor(edk::color4f32(r,g,b,a));
}
bool edk::gui2d::ViewGui2d::setTableColor(edk::color3f32 color){
    return this->setTableColor(edk::color4f32(color.r,color.g,color.b,1.f));
}
bool edk::gui2d::ViewGui2d::setTableColor(edk::float32 r,edk::float32 g,edk::float32 b){
    return this->setTableColor(edk::color4f32(r,g,b,1.f));
}
bool edk::gui2d::ViewGui2d::setTableRectPointsFromCamera(){
    return this->setTableRectPoints(this->camera.getRectPoints());
}
bool edk::gui2d::ViewGui2d::setTableRectPoints(edk::rectf32 table){
    if(table.size.width > table.origin.x
            &&
            table.size.height > table.origin.y
            ){
        this->table=table;
        table.convertIntoPositionAndSize();
        this->tableSize=table.size;
        return true;
    }
    return false;
}
bool edk::gui2d::ViewGui2d::setTableRectPositionAndSize(edk::rectf32 table){
    table.convertIntoPoints();
    return this->setTableRectPoints(table);
}
bool edk::gui2d::ViewGui2d::setTablePositionAndSize(edk::vec2f32 position,edk::size2f32 size){
    edk::rectf32 rect(position.x,position.y,size.width,size.height);
    return this->setTableRectPositionAndSize(rect);
}
bool edk::gui2d::ViewGui2d::setTablePositionAndSize(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height){
    edk::rectf32 rect(x,y,width,height);
    return this->setTableRectPositionAndSize(rect);
}
bool edk::gui2d::ViewGui2d::setTablePoints(edk::vec2f32 point1,edk::vec2f32 point2){
    edk::rectf32 rect(point1.x,point1.y,point2.x,point2.y);
    return this->setTableRectPoints(rect);
}
bool edk::gui2d::ViewGui2d::setTablePoints(edk::float32 p1x,edk::float32 p1Y,edk::float32 p2X,edk::float32 p2Y){
    edk::rectf32 rect(p1x,p1Y,p2X,p2Y);
    return this->setTableRectPoints(rect);
}
edk::rectf32 edk::gui2d::ViewGui2d::getTableRectPoints(){
    return this->table;
}
edk::rectf32 edk::gui2d::ViewGui2d::getTableRectPostionAndSize(){
    edk::rectf32 rect = this->table;
    rect.convertIntoPositionAndSize();
    return rect;
}
//set the table way
bool edk::gui2d::ViewGui2d::setTableMoveWay(edk::gui2d::gui2dTableMove move){
    switch(move){
    case edk::gui2d::gui2dTableMoveNoWay:
        this->tableMove = move;
        return true;
    case edk::gui2d::gui2dTableMoveTwoWays:
        this->tableMove = move;
        return true;
    case edk::gui2d::gui2dTableMoveHorizontal:
        this->tableMove = move;
        return true;
    case edk::gui2d::gui2dTableMoveVertical:
        this->tableMove = move;
        return true;
    default:
        this->tableMove = edk::gui2d::gui2dTableMoveNoWay;
        break;
    }
    return false;
}
bool edk::gui2d::ViewGui2d::setTableMoveNoWay(){
    return this->setTableMoveWay(edk::gui2d::gui2dTableMoveNoWay);
}
bool edk::gui2d::ViewGui2d::setTableMoveTwoWays(){
    return this->setTableMoveWay(edk::gui2d::gui2dTableMoveTwoWays);
}
bool edk::gui2d::ViewGui2d::setTableMoveHorizontal(){
    return this->setTableMoveWay(edk::gui2d::gui2dTableMoveHorizontal);
}
bool edk::gui2d::ViewGui2d::setTableMoveVertical(){
    return this->setTableMoveWay(edk::gui2d::gui2dTableMoveVertical);
}
edk::gui2d::gui2dTableMove edk::gui2d::ViewGui2d::getTableMoveWay(){
    return this->tableMove;
}
bool edk::gui2d::ViewGui2d::haveTableMoveNoWay(){
    if(this->tableMove == edk::gui2d::gui2dTableMoveNoWay){
        return true;
    }
    return false;
}
bool edk::gui2d::ViewGui2d::haveTableMoveTwoWays(){
    if(this->tableMove == edk::gui2d::gui2dTableMoveTwoWays){
        return true;
    }
    return false;
}
bool edk::gui2d::ViewGui2d::haveTableMoveHorizontal(){
    if(this->tableMove == edk::gui2d::gui2dTableMoveHorizontal){
        return true;
    }
    return false;
}
bool edk::gui2d::ViewGui2d::haveTableMoveVertical(){
    if(this->tableMove == edk::gui2d::gui2dTableMoveVertical){
        return true;
    }
    return false;
}
//move the camera over the table
void edk::gui2d::ViewGui2d::moveCameraPercent(edk::vec2f32 percent){
    this->percentMoveCamera = percent;
    if(this->percentMoveCamera.x<0.f) this->percentMoveCamera.x=0.f;
    if(this->percentMoveCamera.x>1.f) this->percentMoveCamera.x=1.f;
    if(this->percentMoveCamera.y<0.f) this->percentMoveCamera.y=0.f;
    if(this->percentMoveCamera.y>1.f) this->percentMoveCamera.y=1.f;
}
void edk::gui2d::ViewGui2d::moveCameraPercentVertical(edk::float32 percentY){
    this->moveCameraPercent(edk::vec2f32(this->percentMoveCamera.x,percentY));
}
void edk::gui2d::ViewGui2d::moveCameraPercentHorizontal(edk::float32 percentX){
    this->moveCameraPercent(edk::vec2f32(percentX,this->percentMoveCamera.y));
}

//get the volume rect inside the menu
edk::rectf32 edk::gui2d::ViewGui2d::getVolume(){
    return this->list.volume;
}

void edk::gui2d::ViewGui2d::resize(edk::rectf32 /*outsideViewOrigin*/){
    this->updateCameraFromTable();
}

void edk::gui2d::ViewGui2d::update(edk::WindowEvents* events){
    //
    bool runSelection=false;
    this->list.update();
    edk::uint32 size = 0u;

    this->mouseStatus = edk::gui2d::gui2dMouseNothing;

    //calculate the mouse position in the world view
    edk::vec2f32 mousePercent = edk::vec2f32((edk::float32)events->mousePosView.x / this->frame.size.width
                                             ,(edk::float32)events->mousePosView.y / this->frame.size.height
                                             );
    edk::vec2f32 mousePosition = edk::vec2f32((this->camera.getSize().width * mousePercent.x)
                                              - (this->camera.getSize().width*0.5f)
                                              + this->camera.position.x
                                              ,(this->camera.getSize().height * (mousePercent.y * -1.f + 1.f))
                                              - (this->camera.getSize().height*0.5f)
                                              + this->camera.position.y
                                              );
    this->mousePositionInside = mousePosition;
    size = events->mousePressed.size();
    for(edk::uint32 i = 0u;i<size;i++){
        switch(events->mousePressed.get(i)){
        case edk::mouse::left:
            //start the click
            this->distanceClick.start();

            this->mouseStatus = edk::gui2d::gui2dMousePressed;
            runSelection = true;
            //save the cursor position to move the object
            this->saveMousePosition = mousePosition;

            this->mouseMoving = true;
            break;
        case edk::mouse::right:
            //press the right button to cancel the oject move
            if(this->mouseMoving){
                this->mouseMoving = false;

                //move the object to the position before
                if(this->objPressed){
                    if(this->objPressed->canMove()){
                        this->objPressed->cancelMove();
                    }
                    this->objPressed->forceUpdate();
                }
            }
            break;
        }
    }
    size = events->mouseHolded.size();
    for(edk::uint32 i = 0u;i<size;i++){
        switch(events->mouseHolded.get(i)){
        case edk::mouse::left:
            if(!runSelection){
                this->mouseStatus = edk::gui2d::gui2dMouseHolded;
                runSelection = true;
            }

            //test if are moving the mouse and if have an object pressed
            if(events->mouseMoved && this->objPressed){
                //update the object to be mouse moved (will be implemented in the future)
            }
            break;
        }
    }
    size = events->mouseRelease.size();
    for(edk::uint32 i = 0u;i<size;i++){
        switch(events->mouseRelease.get(i)){
        case edk::mouse::left:
            //start the click
            if(this->distanceClick.getMicroseconds()<edk::watch::second*0.2){
                //mouse click. Test if is doubleClick
                if(this->distanceDoubleClick.getMicroseconds()<edk::watch::second*0.2){
                    //run doubleClick
                    this->doubleClick=true;
                    if(this->objSelected){
                        //run the doubleClick
                    }
                }
                //start the doubleClick distance
                this->distanceDoubleClick.start();
            }

            runSelection = true;

            this->mouseStatus = edk::gui2d::gui2dMouseRelease;

            if(this->mouseMoving){
                this->mouseMoving = false;
                if(this->objPressed){
                    this->objPressed->forceUpdate();
                }
            }
            //test if have a pressed obj
            if(this->objPressed){
                //test the object status to see if the mouse is inside
                switch(this->objPressed->getStatus()){
                case edk::gui2d::gui2dTexturePressedUp:
                    //the mouse was inside the object
                    break;
                case edk::gui2d::gui2dTexturePressed:
                    //the mouse was not inside the object
                    break;
                case edk::gui2d::gui2dTextureNormal:
                case edk::gui2d::gui2dTextureUp:
                case edk::gui2d::gui2dTextureSize:
                default:
                    break;
                }
                //set the pressed obj to normal
                this->objPressed->setStatus(edk::gui2d::gui2dTextureNormal);
                //clean the objPressed pointer to receive another object when click the mouse again
                this->objPressed->pressed = false;
            }
            break;
        }
    }
    //calculate the mouse distance
    this->mouseDistance = mousePosition - this->saveMousePosition;

    //MOVE THE OBJECT
    //test if need move some object
    if(this->mouseMoving && this->objPressed){
        //test if can move object
        if(this->objPressed->canMove()){
            //move the objPressed
            this->objPressed->moveTo(this->mouseDistance);
            //update the object
            this->objPressed->forceUpdate();
        }
    }

    //test if the mouse was moved or pressed
    if((events->mouseMoved || runSelection) && this->mouseInside && this->mouseOn){
        this->selectionExec = true;

        //change the tree's
        if(this->selectTree == &this->tree1){
            this->selectTree = &this->tree2;
            this->selectTreeS = &this->tree1;
        }
        else{
            this->selectTree = &this->tree1;
            this->selectTreeS = &this->tree2;
        }

        //run the selection
        this->testSelection(events->mousePosView);
    }
    else{
        this->selectionExec = false;
    }

    if(this->isMouseInside()){
        //mouse scroll
        if(events->mouseScrollWheelHorizontal){
            //move the camera horizontal
            if(!edk::Math::equal(this->tableSize.width,0.f)){
                this->moveCameraPercentHorizontal(
                            this->percentMoveCamera.x + (events->mouseScrollWheelHorizontal
                                                         * (1.f / this->tableSize.width) * this->percentMoveSpeed.x
                                                         )
                            );
            }
            this->updateCameraPercentPosition();
        }
        if(events->mouseScrollWheelVertical){
            //move the camera vertical
            if(!edk::Math::equal(this->tableSize.height,0.f)){
                this->moveCameraPercentVertical(
                            this->percentMoveCamera.y + (events->mouseScrollWheelVertical
                                                         * (1.f / this->tableSize.height) * this->percentMoveSpeed.y
                                                         )
                            );
            }
            this->updateCameraPercentPosition();
        }
    }
    //test if move the scroll
    if(!edk::Math::equal(this->savePercentV,this->scrollV.getPercentY())){
        this->moveCameraPercentVertical((this->scrollV.getPercentY() * -1.f)+1.f);
        this->updateCameraPercentPosition();
    }
    if(!edk::Math::equal(this->savePercentH,this->scrollH.getPercentX())){
        this->moveCameraPercentHorizontal((this->scrollH.getPercentX() * -1.f)+1.f);
        this->updateCameraPercentPosition();
    }


    //test the keyboard
    size = events->keyHolded.size();
    if(size){
        //test if is holding the shift
        for(edk::uint32 i=0u;i<size;i++){
            switch(events->keyHolded.get(i)){
            case edk::key::lShift:
            case edk::key::rShift:
                this->shift=true;
                break;
            }
        }
    }
    else{
        this->shift=false;
    }

    //test the keyboard
    size = events->keyPressed.size();
    if(size){
        if(this->objSelected){
            if(this->objSelected->getTypeGUI() == edk::gui2d::gui2dTypeTextField){
                edk::gui2d::TextField2d* field = (edk::gui2d::TextField2d*)this->objSelected;
                edk::uint32 keyPressed = 0u;

                for(edk::uint32 i=0u;i<size;i++){
                    //load the keyPressed
                    keyPressed = events->keyPressed.get(i);

                    switch(keyPressed){
                    case edk::key::left:
                        //back the writer position
                        if(this->shift){
                            field->decrementCursorWithSelect();
                        }
                        else{
                            field->decrementCursor();
                        }
                        break;
                    case edk::key::right:
                        if(this->shift){
                            field->incrementCursorWithSelect();
                        }
                        else{
                            field->incrementCursor();
                        }
                        break;
                    case edk::key::home:
                        if(this->shift){
                            field->moveCursorToStartWithSelect();
                        }
                        else{
                            field->moveCursorToStart();
                        }
                        //
                        break;
                    case edk::key::end:
                        if(this->shift){
                            field->moveCursorToEndWithSelect();
                        }
                        else{
                            field->moveCursorToEnd();
                        }
                        //
                        break;
                    }
                }
            }
        }
    }

    //get keyText
    size = events->keyText.size();
    if(size){
        if(this->objSelected){
            if(this->objSelected->getTypeGUI() == edk::gui2d::gui2dTypeTextField){
                edk::gui2d::TextField2d* field = (edk::gui2d::TextField2d*)this->objSelected;
                edk::uchar32 c;
                for(edk::uint32 i=0u;i<size;i++){
                    c = events->keyText.get(i);
                    //
                    switch(c){
                    case 0x1b:
                        break;
                    case 0x08:
                        field->removeCharacter();
                        break;
                    case 0x7f:
                        field->deleteCharacter();
                        break;
                    case 0x0d:
                    case 0x0a:
                        if(this->objSelected){
                            if(this->objSelected->getTypeGUI() == edk::gui2d::gui2dTypeTextField){
                                edk::gui2d::TextField2d* temp = (edk::gui2d::TextField2d*)this->objSelected;
                                temp->setPressReturn();
                                this->processReturnPressed(this->objSelected);
                            }
                        }
                        break;
                    default:
                        field->addCharacter(events->keyText.get(i));
                    }
                }
            }
        }
    }


    this->list.cleanPressed=false;


    //update the volume inside the view
    this->list.startUpdateVolume = true;
    this->list.update();
    //set the volume object
    this->volume.position = this->list.volume.origin;
    this->volume.size = this->list.volume.size;

    if(!this->mouseInside){
        edk::gui2d::ObjectGui2d* obj=NULL;
        edk::uint32 size = this->list.size();
        for(edk::uint32 i=0u;i<size;i++){
            obj = this->list.getPointerInPosition(i);
            if(obj){
                if(obj->getStatus() == edk::gui2d::gui2dTextureUp){
                    obj->setStatus(edk::gui2d::gui2dTextureNormal);
                }
            }
        }
    }

    //this->objTable.position = this->table.origin;
    //this->objTable.size = this->table.size;
}

//XML
bool edk::gui2d::ViewGui2d::writeToXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_VIEW,nameID);
            if(name){
                //create the name
                if(xml->addSelectedNextChild(name)){
                    if(xml->selectChild(name)){
                        //WRITE
                        //write the table
                        edk::char8* tempID = NULL;
                        edk::char8* strTemp = NULL;

                        tempID = edk::String::int64ToStr(id);
                        if(tempID){
                            //concat
                            strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_TABLE,tempID);
                            if(strTemp){
                                if(xml->addSelectedNextChild(strTemp)){
                                    if(xml->selectChild(strTemp)){
                                        xml->addSelectedNextAttribute("X",this->table.origin.x);
                                        xml->addSelectedNextAttribute("Y",this->table.origin.y);
                                        xml->addSelectedNextAttribute("W",this->table.size.width);
                                        xml->addSelectedNextAttribute("H",this->table.size.height);
                                        xml->addSelectedNextAttribute(EDK_GUI2D_XML_TABLE_MOVE,(edk::uint8)this->tableMove);
                                        xml->selectFather();
                                    }
                                }
                                free(strTemp);
                            }
                        }

                        edk::gui2d::ObjectGui2d* obj=NULL;
                        edk::uint32 size = this->list.size();
                        for(edk::uint32 i=0u;i<size;i++){
                            obj = this->list.getPointerInPosition(i);
                            if(obj){
                                //save the objects in the XML
                                obj->writeToXML(xml,i);
                            }
                        }

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
bool edk::gui2d::ViewGui2d::readFromXML(edk::XML* xml,edk::uint32 id){
    if(xml){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_VIEW,nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->clean();
                    //READ
                    bool haveObject=false;

                    edk::char8* tempID = NULL;
                    edk::char8* strTemp = NULL;
                    edk::char8* strType = NULL;
                    edk::gui2d::ObjectGui2d* obj=NULL;

                    edk::gui2d::gui2dTypes type = edk::gui2d::gui2dTypeSize;
                    edk::uint32 counterID = 0u;

                    edk::rectf32 rect;

                    //read the table
                    tempID = edk::String::int64ToStr(id);
                    if(tempID){
                        //concat
                        strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_TABLE,tempID);
                        if(strTemp){
                            if(xml->selectChild(strTemp)){
                                edk::uint32 move=0u;
                                this->table.origin.x = xml->getSelectedAttributeValueAsFloat32ByName("X");
                                this->table.origin.y = xml->getSelectedAttributeValueAsFloat32ByName("Y");
                                this->table.size.width = xml->getSelectedAttributeValueAsFloat32ByName("W");
                                this->table.size.height = xml->getSelectedAttributeValueAsFloat32ByName("H");
                                rect = this->table;
                                rect.convertIntoPositionAndSize();
                                this->tableSize = rect.size;
                                move = xml->getSelectedAttributeValueAsUint32ByName(EDK_GUI2D_XML_TABLE_MOVE);
                                switch(move){
                                case (edk::uint32)edk::gui2d::gui2dTableMoveNoWay:
                                    this->tableMove = edk::gui2d::gui2dTableMoveNoWay;
                                    break;
                                case (edk::uint32)edk::gui2d::gui2dTableMoveTwoWays:
                                    this->tableMove = edk::gui2d::gui2dTableMoveTwoWays;
                                    break;
                                case (edk::uint32)edk::gui2d::gui2dTableMoveHorizontal:
                                    this->tableMove = edk::gui2d::gui2dTableMoveHorizontal;
                                    break;
                                case (edk::uint32)edk::gui2d::gui2dTableMoveVertical:
                                    this->tableMove = edk::gui2d::gui2dTableMoveVertical;
                                    break;
                                default:
                                    this->tableMove = edk::gui2d::gui2dTableMoveNoWay;
                                    break;
                                }
                                xml->selectFather();
                            }
                            free(strTemp);
                        }
                        free(tempID);
                    }

                    do{
                        haveObject=false;
                        tempID = NULL;
                        strTemp = NULL;
                        strType = NULL;
                        type = edk::gui2d::gui2dTypeSize;
                        tempID = edk::String::int64ToStr(counterID);
                        if(tempID){
                            //concat
                            strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_OBJ,tempID);
                            if(strTemp){
                                if(xml->selectChild(strTemp)){
                                    haveObject=true;
                                    //read the type
                                    strType = xml->getSelectedString();
                                    if(strType){
                                        if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeObject))){
                                            type = edk::gui2d::gui2dTypeObject;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeButton))){
                                            type = edk::gui2d::gui2dTypeButton;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeScrollBar))){
                                            type = edk::gui2d::gui2dTypeScrollBar;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeMenu))){
                                            type = edk::gui2d::gui2dTypeMenu;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeTextField))){
                                            type = edk::gui2d::gui2dTypeTextField;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeText))){
                                            type = edk::gui2d::gui2dTypeText;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeColorPicker))){
                                            type = edk::gui2d::gui2dTypeColorPicker;
                                        }
                                        //free(strType);
                                    }

                                    xml->selectFather();
                                }
                                free(strTemp);
                            }
                            free(tempID);
                        }

                        //create the object and add it into the list
                        switch(type){
                        case gui2dTypeObject:
                            obj = new edk::gui2d::ObjectGui2d;
                            break;
                        case gui2dTypeButton:
                            obj = new edk::gui2d::Button2D;
                            break;
                        case gui2dTypeScrollBar:
                            obj = new edk::gui2d::ScrollBar2d;
                            break;
                        case gui2dTypeText:
                            obj = new edk::gui2d::Text2D;
                            break;
                        case gui2dTypeTextField:
                            obj = new edk::gui2d::TextField2d;
                            break;
                        case gui2dTypeColorPicker:
                            obj = new edk::gui2d::ColorPicker2d;
                            break;
                        default:
                            obj = NULL;
                            break;
                        }

                        if(obj){
                            //load the object XML
                            if(obj->readFromXML(xml,counterID)){
                                if(!this->addObjectGui2d(obj)){
                                    delete obj;
                                }
                            }
                            else{
                                delete obj;
                            }
                        }

                        counterID++;
                    }while(haveObject);

                    ret=true;
                    xml->selectFather();

                    //update the camera to have the table
                    this->updateCameraFromTable();
                }
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
bool edk::gui2d::ViewGui2d::readFromXMLFromPack(edk::pack::FilePackage* pack,edk::XML* xml,edk::uint32 id){
    if(xml && pack){
        bool ret=false;
        //create the nameID
        edk::char8* nameID = edk::String::int64ToStr(id);
        if(nameID){
            //concat
            edk::char8* name = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_VIEW,nameID);
            if(name){
                //create the name
                if(xml->selectChild(name)){
                    this->clean();
                    //READ
                    bool haveObject=false;

                    edk::char8* tempID = NULL;
                    edk::char8* strTemp = NULL;
                    edk::char8* strType = NULL;
                    edk::gui2d::ObjectGui2d* obj=NULL;

                    edk::gui2d::gui2dTypes type = edk::gui2d::gui2dTypeSize;
                    edk::uint32 counterID = 0u;

                    edk::rectf32 rect;

                    //read the table
                    tempID = edk::String::int64ToStr(id);
                    if(tempID){
                        //concat
                        strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_TABLE,tempID);
                        if(strTemp){
                            if(xml->selectChild(strTemp)){
                                edk::uint32 move=0u;
                                this->table.origin.x = xml->getSelectedAttributeValueAsFloat32ByName("X");
                                this->table.origin.y = xml->getSelectedAttributeValueAsFloat32ByName("Y");
                                this->table.size.width = xml->getSelectedAttributeValueAsFloat32ByName("W");
                                this->table.size.height = xml->getSelectedAttributeValueAsFloat32ByName("H");
                                rect = this->table;
                                rect.convertIntoPositionAndSize();
                                this->tableSize = rect.size;
                                move = xml->getSelectedAttributeValueAsUint32ByName(EDK_GUI2D_XML_TABLE_MOVE);
                                switch(move){
                                case (edk::uint32)edk::gui2d::gui2dTableMoveNoWay:
                                    this->tableMove = edk::gui2d::gui2dTableMoveNoWay;
                                    break;
                                case (edk::uint32)edk::gui2d::gui2dTableMoveTwoWays:
                                    this->tableMove = edk::gui2d::gui2dTableMoveTwoWays;
                                    break;
                                case (edk::uint32)edk::gui2d::gui2dTableMoveHorizontal:
                                    this->tableMove = edk::gui2d::gui2dTableMoveHorizontal;
                                    break;
                                case (edk::uint32)edk::gui2d::gui2dTableMoveVertical:
                                    this->tableMove = edk::gui2d::gui2dTableMoveVertical;
                                    break;
                                default:
                                    this->tableMove = edk::gui2d::gui2dTableMoveNoWay;
                                    break;
                                }
                                xml->selectFather();
                            }
                            free(strTemp);
                        }
                    }

                    do{
                        haveObject=false;
                        tempID = NULL;
                        strTemp = NULL;
                        strType = NULL;
                        type = edk::gui2d::gui2dTypeSize;
                        tempID = edk::String::int64ToStr(counterID);
                        if(tempID){
                            //concat
                            strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_GUI2D_OBJ,tempID);
                            if(strTemp){
                                if(xml->selectChild(strTemp)){
                                    haveObject=true;
                                    //read the type
                                    strType = xml->getSelectedString();
                                    if(strType){
                                        if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeObject))){
                                            type = edk::gui2d::gui2dTypeObject;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeButton))){
                                            type = edk::gui2d::gui2dTypeButton;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeScrollBar))){
                                            type = edk::gui2d::gui2dTypeScrollBar;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeMenu))){
                                            type = edk::gui2d::gui2dTypeMenu;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeTextField))){
                                            type = edk::gui2d::gui2dTypeTextField;
                                        }
                                        else if(edk::String::strCompareInside(strType,edk::gui2d::ObjectGui2d::getStringTypeGUI(edk::gui2d::gui2dTypeText))){
                                            type = edk::gui2d::gui2dTypeText;
                                        }
                                        //free(strType);
                                    }

                                    xml->selectFather();
                                }
                                free(strTemp);
                            }
                            free(tempID);
                        }

                        //create the object and add it into the list
                        switch(type){
                        case gui2dTypeObject:
                            obj = new edk::gui2d::ObjectGui2d;
                            break;
                        case gui2dTypeButton:
                            obj = new edk::gui2d::Button2D;
                            break;
                        case gui2dTypeScrollBar:
                            obj = new edk::gui2d::ScrollBar2d;
                            break;
                        case gui2dTypeText:
                            obj = new edk::gui2d::Text2D;
                            break;
                        case gui2dTypeTextField:
                            obj = new edk::gui2d::TextField2d;
                            break;
                        default:
                            obj = NULL;
                            break;
                        }

                        if(obj){
                            //load the object XML
                            if(obj->readFromXMLFromPack(pack,xml,counterID)){
                                if(!this->addObjectGui2d(obj)){
                                    delete obj;
                                }
                            }
                            else{
                                delete obj;
                            }
                        }

                        counterID++;
                    }while(haveObject);

                    ret=true;
                    xml->selectFather();

                    //update the camera to have the table
                    this->updateCameraFromTable();
                }
                free(name);
            }
            free(nameID);
        }
        return ret;
    }
    return false;
}
bool edk::gui2d::ViewGui2d::writeToXML(const edk::char8* name,edk::uint32 id){
    return this->writeToXML((edk::char8*) name,id);
}
bool edk::gui2d::ViewGui2d::writeToXML(edk::char8* name,edk::uint32 id){
    if(name){
        edk::XML xml;
        if(this->writeToXML(&xml,id)){
            return xml.saveToFile(name);
        }
    }
    return false;
}
bool edk::gui2d::ViewGui2d::readFromXML(const edk::char8* name,edk::uint32 id){
    return this->readFromXML((edk::char8*) name,id);
}
bool edk::gui2d::ViewGui2d::readFromXML(edk::char8* name,edk::uint32 id){
    if(name){
        edk::XML xml;
        if(xml.loadFile(name)){
            return this->readFromXML(&xml,id);
        }
    }
    return false;
}

//draw the GU scene
void edk::gui2d::ViewGui2d::drawScene(edk::rectf32){
    edk::uint32 size = 0u;
    edk::gui2d::ObjectGui2d* obj=NULL;
    edk::uint32 id=0u;

    //draw the table
    this->objTable.draw();

    if(this->selectionExec){
        //

        //process the first tree with selectec objects
        size = this->selectTree->size();
        if(size){
            //get only the last objet
            size--;

            //clean the up from the saved objects
            for(edk::uint32 i=0u;i<size;i++){
                id = this->selectTree->getElementInPosition(0u);
                //up the object on the S tree
                this->selectTreeS->add(id);
                //remove it from the last tree
                this->selectTree->remove(id);
            }

            id = this->selectTree->getElementInPosition(0u);

            obj = this->list.getPointerByID(id);
            if(obj){
                //test if the mouse is pressed
                if(this->mouseStatus == edk::gui2d::gui2dMousePressed){
                    obj->setStatus(edk::gui2d::gui2dTexturePressedUp);
                    obj->pressed=true;
                    this->objPressed = obj;
                    if(this->objPressed->canMove()){
                        this->objPressed->startMove(this->saveMousePosition + this->mouseDistance);
                    }

                    //test if the object selected is different
                    if(this->objSelected){
                        //remove the selection
                        this->objSelected->deselect();
                        if(this->endSelect){
                            this->objSelected->clickEnd(this->idSelected,this->mousePositionInside,false,this->doubleClick);
                        }
                    }
                    obj->select();
                    obj->clickStart(this->idSelected,this->mousePositionInside);
                    //select the object
                    this->objSelected = obj;
                    this->endSelect = true;

                    //process the callback
                    this->processMousePressed(obj,edk::mouse::left);
                }
                else if(this->mouseStatus == edk::gui2d::gui2dMouseHolded){
                    if(obj->pressed){
                        //set the objStatus
                        obj->setStatus(edk::gui2d::gui2dTexturePressedUp);
                    }
                    else{
                        //set the objStatus
                        obj->setStatus(edk::gui2d::gui2dTextureUp);
                    }
                    if(this->objPressed){
                        //process the callback
                        this->processMouseHolded(this->objPressed,edk::mouse::left);
                    }
                    //test if have the object selected
                    if(this->objSelected == obj){
                        obj->clickMove(this->idSelected,this->mousePositionInside,true);
                    }
                    else if(this->objSelected){
                        obj->clickMove(this->idSelected,this->mousePositionInside,false);
                    }
                    this->endSelect = true;
                }
                else if(this->mouseStatus == edk::gui2d::gui2dMouseRelease){
                    //test if have the object selected
                    if(this->objSelected == obj && this->endSelect){
                        obj->clickEnd(this->idSelected,this->mousePositionInside,true,this->doubleClick);
                    }
                    else if(this->objSelected){
                        obj->clickEnd(this->idSelected,this->mousePositionInside,false,this->doubleClick);
                    }
                    this->endSelect = false;
                    obj->pressed=false;
                    //set the objStatus
                    obj->setStatus(edk::gui2d::gui2dTextureUp);
                }
                else{
                    obj->pressed=false;
                    //set the objStatus
                    obj->setStatus(edk::gui2d::gui2dTextureUp);
                }
            }
            else{
                //test if the mouse is pressed
                if(this->mouseStatus == edk::gui2d::gui2dMousePressed){
                    //
                    this->deselectObject(this->mousePositionInside);
                }
            }
        }
        else{
            //test if the mouse is pressed
            if(this->mouseStatus == edk::gui2d::gui2dMousePressed){
                //
                this->deselectObject(this->mousePositionInside);
            }
            else if(this->mouseStatus == edk::gui2d::gui2dMouseHolded){
                if(this->objSelected){
                    this->objSelected->clickMove(this->idSelected,this->mousePositionInside,false);
                }
            }
        }

        //test if release the mouse
        if(this->mouseStatus == edk::gui2d::gui2dMouseRelease){
            //clean the mouseRelease
            this->list.cleanPressed=true;
        }
    }

    //test if release the object
    if(this->mouseStatus == edk::gui2d::gui2dMouseRelease){
        //test if have the object pressed
        if(this->objPressed){
            //test if the mouse is inside the mouse pressed
            if(this->objPressed == obj){
                //process callback
                this->processMouseRelease(this->objPressed,edk::mouse::left,true);
            }
            else{
                //process callback
                this->processMouseRelease(this->objPressed,edk::mouse::left,false);
            }
            this->objPressed->pressed=false;
            this->objPressed = NULL;
        }
    }

    //process the second tree with last selected objects
    size = this->selectTreeS->size();
    //clean the up from the saved objects
    for(edk::uint32 i=0u;i<size;i++){
        //get the object
        obj = this->list.getPointerByID(this->selectTreeS->getElementInPosition(i));
        if(obj){
            if(obj->pressed){
                //set the object to pressed
                obj->setStatus(edk::gui2d::gui2dTexturePressed);
            }
            else{
                //set the object to normal
                obj->setStatus(edk::gui2d::gui2dTextureNormal);
            }
        }
    }
    //clean the last tree
    this->selectTreeS->clean();

    this->doubleClick=false;


    //clean the lights in the view
    edk::GU::guEnable(GU_LIGHTING);
    for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
        edk::GU::guDisable(GU_LIGHT0+i);
    }
    edk::GU::guDisable(GU_LIGHTING);

    //render the objects
    this->list.render();
}


//callback
bool edk::gui2d::ViewGui2d::addCallback(edk::gui2d::ObjectGui2dCallback* callback){
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
bool edk::gui2d::ViewGui2d::removeCallback(edk::gui2d::ObjectGui2dCallback* callback){
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
void edk::gui2d::ViewGui2d::cleanCallbacks(){
    this->listCallback.clean();
}

//clone the gui object from
bool edk::gui2d::ViewGui2d::cloneFrom(edk::gui2d::ViewGui2d* obj){
    if(obj){
        //
    }
    return false;
}


