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

        this->enableMouse();
    }
}
void edk::gui2d::ViewGui2d::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->tree1.clean();
        this->tree2.clean();
        this->volume.cleanMeshes();

        this->tree1.Destructor();
        this->tree2.Destructor();
        this->volume.Destructor();
        this->distanceClick.Destructor();
        this->distanceDoubleClick.Destructor();
        this->listCallback.Destructor();
        this->list.Destructor();
    }
    edk::ViewGU2D::Destructor();
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

void edk::gui2d::ViewGui2d::drawSelectionScene(){
    //
    this->list.print();
}
edk::uint32 gui2dIdCounter=0u;
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
    if(obj && !this->list.haveObjByPointer(obj)){
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

//disable the mouse on the view (Can be used to have only one textField on the view).
void edk::gui2d::ViewGui2d::enableMouse(){
    this->mouseOn = true;
}
void edk::gui2d::ViewGui2d::disableMouse(){
    this->mouseOn = false;
}

//function used to select an object on the view
bool edk::gui2d::ViewGui2d::selectObject(edk::gui2d::ObjectGui2d* obj){
    //delelect the object
    this->deselectObject();
    if(obj){
        obj->select();
        obj->clickStart(this->idSelected);
        //select the object
        this->objSelected = obj;
        this->endSelect = true;
    }
    return false;
}
void edk::gui2d::ViewGui2d::deselectObject(){
    if(this->objSelected){
        this->objSelected->deselect();
        if(this->endSelect){
            this->objSelected->clickEnd(this->idSelected,false,this->doubleClick);
        }
        this->endSelect = false;

        this->objSelected = NULL;
        this->idSelected = 0u;
    }
}

//set the table position and size
bool edk::gui2d::ViewGui2d::setTableRectPoints(edk::rectf32 table){
    if(table.size.width > table.origin.x
            &&
            table.size.height > table.origin.y
            ){
        this->table=table;
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

//get the volume rect inside the menu
edk::rectf32 edk::gui2d::ViewGui2d::getVolume(){
    return this->list.volume;
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
    size = events->mousePressed.size();
    for(edk::uint32 i = 0u;i<size;i++){
        if(events->mousePressed.get(i) == edk::mouse::left){
            //start the click
            this->distanceClick.start();

            this->mouseStatus = edk::gui2d::gui2dMousePressed;
            runSelection = true;
            //save the cursor position to move the object
            this->saveMousePosition = mousePosition;

            this->mouseMoving = true;
        }
        else if(events->mousePressed.get(i) == edk::mouse::right){
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
        }
    }
    size = events->mouseHolded.size();
    for(edk::uint32 i = 0u;i<size;i++){
        if(events->mouseHolded.get(i) == edk::mouse::left){
            if(!runSelection){
                this->mouseStatus = edk::gui2d::gui2dMouseHolded;
                runSelection = true;
            }

            //test if are moving the mouse and if have an object pressed
            if(events->mouseMoved && this->objPressed){
                //update the object to be mouse moved (will be implemented in the future)
            }
        }
    }
    size = events->mouseRelease.size();
    for(edk::uint32 i = 0u;i<size;i++){
        if(events->mouseRelease.get(i) == edk::mouse::left){
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
                    //READ
                    bool haveObject=false;

                    edk::char8* tempID = NULL;
                    edk::char8* strTemp = NULL;
                    edk::char8* strType = NULL;
                    edk::gui2d::ObjectGui2d* obj=NULL;

                    edk::gui2d::gui2dTypes type = edk::gui2d::gui2dTypeSize;
                    edk::uint32 counterID = 0u;

                    //read the table
                    tempID = edk::String::int64ToStr(id);
                    if(tempID){
                        //concat
                        strTemp = edk::String::strCat((edk::char8*)EDK_GUI2D_XML_TABLE,tempID);
                        if(strTemp){
                                if(xml->selectChild(strTemp)){
                                    this->table.origin.x = xml->getSelectedAttributeValueAsFloat32ByName("X");
                                    this->table.origin.y = xml->getSelectedAttributeValueAsFloat32ByName("Y");
                                    this->table.size.width = xml->getSelectedAttributeValueAsFloat32ByName("W");
                                    this->table.size.height = xml->getSelectedAttributeValueAsFloat32ByName("H");
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

//draw the GU scene
void edk::gui2d::ViewGui2d::drawScene(edk::rectf32){
    edk::uint32 size = 0u;
    edk::gui2d::ObjectGui2d* obj=NULL;
    edk::uint32 id=0u;
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
                            this->objSelected->clickEnd(this->idSelected,false,this->doubleClick);
                        }
                    }
                    obj->select();
                    obj->clickStart(this->idSelected);
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
                        obj->clickMove(this->idSelected,true);
                    }
                    else if(this->objSelected){
                        obj->clickMove(this->idSelected,false);
                    }
                    this->endSelect = true;
                }
                else if(this->mouseStatus == edk::gui2d::gui2dMouseRelease){
                    //test if have the object selected
                    if(this->objSelected == obj && this->endSelect){
                        obj->clickEnd(this->idSelected,true,this->doubleClick);
                    }
                    else if(this->objSelected){
                        obj->clickEnd(this->idSelected,false,this->doubleClick);
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
                    this->deselectObject();
                }
            }
        }
        else{
            //test if the mouse is pressed
            if(this->mouseStatus == edk::gui2d::gui2dMousePressed){
                //
                this->deselectObject();
            }
            else if(this->mouseStatus == edk::gui2d::gui2dMouseHolded){
                if(this->objSelected){
                    this->objSelected->clickMove(this->idSelected,false);
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


