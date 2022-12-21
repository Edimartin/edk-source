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

edk::gui2d::ViewGui2d::ViewGui2d(){
    //
    this->idCounter = 0u;edkEnd();
    this->mouseStatus = edk::gui2d::gui2dMouseNothing;edkEnd();
    this->objPressed = NULL;edkEnd();
    this->objSelected = NULL;edkEnd();
    this->idSelected = 0u;edkEnd();
    this->selectTree = &this->tree1;edkEnd();
    this->selectTreeS = &this->tree2;edkEnd();
    this->shift = false;edkEnd();
    //press quote
    this->pressQuote=false;edkEnd();
    this->pressTilde=false;edkEnd();
    //start the distances
    this->distanceClick.start();edkEnd();
    this->distanceDoubleClick.start();edkEnd();
    //run doubleClick
    this->doubleClick=false;edkEnd();

    this->enableMouse();edkEnd();
}
edk::gui2d::ViewGui2d::~ViewGui2d(){
    //
    this->tree1.clean();edkEnd();
    this->tree2.clean();edkEnd();
    this->volume.cleanMeshes();edkEnd();
}
//return true if have the element on the callback list
bool edk::gui2d::ViewGui2d::haveCallback(edk::gui2d::ObjectGui2dCallback* callback){
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
void edk::gui2d::ViewGui2d::processMousePressed(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton){
    //get the list size
    edk::uint32 size = this->listCallback.size();edkEnd();
    edk::gui2d::ObjectGui2dCallback* pointer = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);edkEnd();
        if(pointer){
            //process the function
            pointer->mousePressed(button,mouseButton);edkEnd();
        }
    }
}
void edk::gui2d::ViewGui2d::processMouseRelease(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton,bool isInside){
    //get the list size
    edk::uint32 size = this->listCallback.size();edkEnd();
    edk::gui2d::ObjectGui2dCallback* pointer = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);edkEnd();
        if(pointer){
            //process the function
            pointer->mouseRelease(button,mouseButton,isInside);edkEnd();
        }
    }
}
void edk::gui2d::ViewGui2d::processMouseHolded(edk::gui2d::ObjectGui2d* button,edk::uint32 mouseButton){
    //get the list size
    edk::uint32 size = this->listCallback.size();edkEnd();
    edk::gui2d::ObjectGui2dCallback* pointer = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);edkEnd();
        if(pointer){
            //process the function
            pointer->mouseHolded(button,mouseButton);edkEnd();
        }
    }
}
void edk::gui2d::ViewGui2d::processReturnPressed(edk::gui2d::ObjectGui2d* textField){
    //get the list size
    edk::uint32 size = this->listCallback.size();edkEnd();
    edk::gui2d::ObjectGui2dCallback* pointer = NULL;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        pointer = this->listCallback.get(i);edkEnd();
        if(pointer){
            //process the function
            pointer->returnPressed(textField);edkEnd();
        }
    }
}

void edk::gui2d::ViewGui2d::drawSelectionScene(){
    //
    this->list.print();edkEnd();
}
edk::uint32 gui2dIdCounter=0u;
void edk::gui2d::ViewGui2d::selectObject(edk::uint32 ,edk::int32 ,edk::float32 ,edk::float32 ,edk::vector::Stack<edk::uint32>* names){
    //
    edk::uint32 id=0u;
    edk::gui2d::ObjectGui2d* obj=NULL;edkEnd();
    edk::uint32 size = 0u;edkEnd();


    size = names->size();edkEnd();
    if(size){
        id = names->get(0u);edkEnd();
        //get the object
        obj = this->list.getPointerByID(id);edkEnd();
        if(obj){
            //add the id to the select tree
            this->selectTree->add(id);edkEnd();
            //remove it from the last tree
            this->selectTreeS->remove(id);edkEnd();
        }

        //test if have the second name
        if(size>1u){
            //
            this->idSelected = names->get(1u);edkEnd();
        }
        else{
            this->idSelected = 0u;edkEnd();
        }
    }
}

//add the object
bool edk::gui2d::ViewGui2d::addObjectGui2d(edk::gui2d::ObjectGui2d* obj){
    if(obj && !this->list.haveObjByPointer(obj)){
        edk::uint32 counter = 0u;edkEnd();
        //add the object to the tree
        while(!this->list.addNewObj(obj,this->idCounter)){
            this->idCounter+=9u;edkEnd();
            counter++;edkEnd();
            if(counter>0xFFFFFFFE){
                return false;
            }
        }
        this->idCounter+=1u;edkEnd();
        obj->load();edkEnd();

        //load the volume object
        if(!this->volume.getMeshSize()){
            edk::shape::Mesh2D* mesh = this->volume.newMesh();edkEnd();
            if(mesh){
                edk::shape::Rectangle2D rect;edkEnd();
                rect.setPolygonColor(1.f,1.f,1.f,0.5f);edkEnd();
                mesh->addPolygon(rect);edkEnd();
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
            this->objPressed=NULL;edkEnd();
        }
        if(this->objSelected == obj){
            this->objSelected->deselect();edkEnd();
            this->objSelected = NULL;edkEnd();
            this->idSelected = 0u;edkEnd();
        }
        return this->list.removeByPointer(obj);edkEnd();
    }
    return false;
}
//remove all objects
void edk::gui2d::ViewGui2d::removeAllObjectGui2d(){
    //test if the obj is the same pressed
    this->objPressed=NULL;edkEnd();
    if(this->objSelected){
        this->objSelected->deselect();edkEnd();
        this->objSelected = NULL;edkEnd();
        this->idSelected = 0u;edkEnd();
    }
    this->list.removeAll();edkEnd();
}

//disable the mouse on the view (Can be used to have only one textField on the view).
void edk::gui2d::ViewGui2d::enableMouse(){
    this->mouseOn = true;edkEnd();
}
void edk::gui2d::ViewGui2d::disableMouse(){
    this->mouseOn = false;edkEnd();
}

//function used to select an object on the view
bool edk::gui2d::ViewGui2d::selectObject(edk::gui2d::ObjectGui2d* obj){
    //delelect the object
    this->deselectObject();edkEnd();
    if(obj){
        obj->select();edkEnd();
        obj->clickStart(this->idSelected);edkEnd();
        //select the object
        this->objSelected = obj;edkEnd();
        this->endSelect = true;edkEnd();
    }
    return false;
}
void edk::gui2d::ViewGui2d::deselectObject(){
    if(this->objSelected){
        this->objSelected->deselect();edkEnd();
        if(this->endSelect){
            this->objSelected->clickEnd(this->idSelected,false,this->doubleClick);edkEnd();
        }
        this->endSelect = false;edkEnd();

        this->objSelected = NULL;edkEnd();
        this->idSelected = 0u;edkEnd();
    }
}

//get the volume rect inside the menu
edk::rectf32 edk::gui2d::ViewGui2d::getVolume(){
    return this->list.volume;edkEnd();
}

void edk::gui2d::ViewGui2d::update(edk::WindowEvents* events){
    //
    bool runSelection=false;edkEnd();
    this->list.update();edkEnd();
    edk::uint32 size = 0u;edkEnd();

    this->mouseStatus = edk::gui2d::gui2dMouseNothing;edkEnd();

    //calculate the mouse position in the world view
    edk::vec2f32 mousePercent = edk::vec2f32((edk::float32)events->mousePos.x / this->frame.size.width
                                             ,(edk::float32)events->mousePos.y / this->frame.size.height
                                             );edkEnd();
    edk::vec2f32 mousePosition = edk::vec2f32((this->camera.getSize().width * mousePercent.x)
                                              - (this->camera.getSize().width*0.5f)
                                              + this->camera.position.x
                                              ,(this->camera.getSize().height * (mousePercent.y * -1.f + 1.f))
                                              - (this->camera.getSize().height*0.5f)
                                              + this->camera.position.y
                                              );edkEnd();
    size = events->mousePressed.size();edkEnd();
    for(edk::uint32 i = 0u;i<size;i++){
        if(events->mousePressed[i] == edk::mouse::left){
            //start the click
            this->distanceClick.start();edkEnd();

            this->mouseStatus = edk::gui2d::gui2dMousePressed;edkEnd();
            runSelection = true;edkEnd();
            //save the cursor position to move the object
            this->saveMousePosition = mousePosition;edkEnd();

            this->mouseMoving = true;edkEnd();
        }
        else if(events->mousePressed[i] == edk::mouse::right){
            //press the right button to cancel the oject move
            if(this->mouseMoving){
                this->mouseMoving = false;edkEnd();

                //move the object to the position before
                if(this->objPressed){
                    if(this->objPressed->canMove()){
                        this->objPressed->cancelMove();edkEnd();
                    }
                    this->objPressed->forceUpdate();edkEnd();
                }
            }
        }
    }
    size = events->mouseHolded.size();edkEnd();
    for(edk::uint32 i = 0u;i<size;i++){
        if(events->mouseHolded[i] == edk::mouse::left){
            if(!runSelection){
                this->mouseStatus = edk::gui2d::gui2dMouseHolded;edkEnd();
                runSelection = true;edkEnd();
            }

            //test if are moving the mouse and if have an object pressed
            if(events->mouseMoved && this->objPressed){
                //update the object to be mouse moved (will be implemented in the future)
            }
        }
    }
    size = events->mouseRelease.size();edkEnd();
    for(edk::uint32 i = 0u;i<size;i++){
        if(events->mouseRelease[i] == edk::mouse::left){
            //start the click
            if(this->distanceClick.getMicroseconds()<edk::watch::second*0.2){
                //mouse click. Test if is doubleClick
                if(this->distanceDoubleClick.getMicroseconds()<edk::watch::second*0.2){
                    //run doubleClick
                    this->doubleClick=true;edkEnd();
                    if(this->objSelected){
                        //run the doubleClick
                    }
                }
                //start the doubleClick distance
                this->distanceDoubleClick.start();edkEnd();
            }

            runSelection = true;edkEnd();

            this->mouseStatus = edk::gui2d::gui2dMouseRelease;edkEnd();

            if(this->mouseMoving){
                this->mouseMoving = false;edkEnd();
                if(this->objPressed){
                    this->objPressed->forceUpdate();edkEnd();
                }
            }
            //test if have a pressed obj
            if(this->objPressed){
                //test the object status to see if the mouse is inside
                switch(this->objPressed->getStatus()){
                case edk::gui2d::gui2dTexturePressedUp:
                    //the mouse was inside the object
                    break;edkEnd();
                case edk::gui2d::gui2dTexturePressed:
                    //the mouse was not inside the object
                    break;edkEnd();
                case edk::gui2d::gui2dTextureNormal:
                case edk::gui2d::gui2dTextureUp:
                case edk::gui2d::gui2dTextureSize:
                default:
                    break;edkEnd();
                }
                //set the pressed obj to normal
                this->objPressed->setStatus(edk::gui2d::gui2dTextureNormal);edkEnd();
                //clean the objPressed pointer to receive another object when click the mouse again
                this->objPressed->pressed = false;edkEnd();
            }
        }
    }
    //calculate the mouse distance
    this->mouseDistance = mousePosition - this->saveMousePosition;edkEnd();

    //MOVE THE OBJECT
    //test if need move some object
    if(this->mouseMoving && this->objPressed){
        //test if can move object
        if(this->objPressed->canMove()){
            //move the objPressed
            this->objPressed->moveTo(this->mouseDistance);edkEnd();
            //update the object
            this->objPressed->forceUpdate();edkEnd();
        }
    }

    //test if the mouse was moved or pressed
    if((events->mouseMoved || runSelection) && this->mouseInside && this->mouseOn){
        this->selectionExec = true;edkEnd();

        //change the tree's
        if(this->selectTree == &this->tree1){
            this->selectTree = &this->tree2;edkEnd();
            this->selectTreeS = &this->tree1;edkEnd();
        }
        else{
            this->selectTree = &this->tree1;edkEnd();
            this->selectTreeS = &this->tree2;edkEnd();
        }

        //run the selection
        this->testSelection(events->mousePos);edkEnd();
    }
    else{
        this->selectionExec = false;edkEnd();
    }


    //test the keyboard
    size = events->keyHolded.size();edkEnd();
    if(size){
        //test if is holding the shift
        for(edk::uint32 i=0u;i<size;i++){
            switch(events->keyHolded[i]){
            case edk::key::lShift:
            case edk::key::rShift:
                this->shift=true;edkEnd();
                break;edkEnd();
            }
        }
    }
    else{
        this->shift=false;edkEnd();
    }

    //test the keyboard
    size = events->keyPressed.size();edkEnd();
    if(size){
        if(this->objSelected){
            if(this->objSelected->getType() == edk::gui2d::gui2dTypeTextField){
                edk::gui2d::TextField2d* field = (edk::gui2d::TextField2d*)this->objSelected;edkEnd();
                edk::uint32 keyPressed = 0u;edkEnd();

                for(edk::uint32 i=0u;i<size;i++){
                    //load the keyPressed
                    keyPressed = events->keyPressed[i];edkEnd();

                    switch(keyPressed){
                    case edk::key::left:
                        //back the writer position
                        if(this->shift){
                            field->decrementCursorWithSelect();edkEnd();
                        }
                        else{
                            field->decrementCursor();edkEnd();
                        }
                        break;edkEnd();
                    case edk::key::right:
                        if(this->shift){
                            field->incrementCursorWithSelect();edkEnd();
                        }
                        else{
                            field->incrementCursor();edkEnd();
                        }
                        break;edkEnd();
                    case edk::key::home:
                        if(this->shift){
                            field->moveCursorToStartWithSelect();edkEnd();
                        }
                        else{
                            field->moveCursorToStart();edkEnd();
                        }
                        //
                        break;edkEnd();
                    case edk::key::end:
                        if(this->shift){
                            field->moveCursorToEndWithSelect();edkEnd();
                        }
                        else{
                            field->moveCursorToEnd();edkEnd();
                        }
                        //
                        break;edkEnd();
                    }
                }
            }
        }
    }

    //get keyText
    size = events->keyText.size();edkEnd();
    if(size){
        if(this->objSelected){
            if(this->objSelected->getType() == edk::gui2d::gui2dTypeTextField){
                edk::gui2d::TextField2d* field = (edk::gui2d::TextField2d*)this->objSelected;edkEnd();
                edk::uchar32 c;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    c = events->keyText[i];edkEnd();
                    //
                    switch(c){
                    case 0x1b:
                        break;edkEnd();
                    case 0x08:
                        field->removeCharacter();edkEnd();
                        break;edkEnd();
                    case 0x7f:
                        field->deleteCharacter();edkEnd();
                        break;edkEnd();
                    case 0x0d:
                    case 0x0a:
                        if(this->objSelected){
                            if(this->objSelected->getType() == edk::gui2d::gui2dTypeTextField){
                                this->processReturnPressed(this->objSelected);edkEnd();
                            }
                        }
                        break;edkEnd();
                    default:
                        field->addCharacter(events->keyText[i]);edkEnd();
                    }
                }
            }
        }
    }


    this->list.cleanPressed=false;edkEnd();


    //update the volume inside the view
    this->list.startUpdateVolume = true;edkEnd();
    this->list.update();edkEnd();
    //set the volume object
    this->volume.position = this->list.volume.origin;edkEnd();
    this->volume.size = this->list.volume.size;edkEnd();

    if(!this->mouseInside){
        edk::gui2d::ObjectGui2d* obj=NULL;edkEnd();
        edk::uint32 size = this->list.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            obj = this->list.getPointerInPosition(i);edkEnd();
            if(obj){
                if(obj->getStatus() == edk::gui2d::gui2dTextureUp){
                    obj->setStatus(edk::gui2d::gui2dTextureNormal);edkEnd();
                }
            }
        }
    }
}

//draw the GU scene
void edk::gui2d::ViewGui2d::drawScene(edk::rectf32){
    edk::uint32 size = 0u;edkEnd();
    edk::gui2d::ObjectGui2d* obj=NULL;edkEnd();
    edk::uint32 id=0u;
    if(this->selectionExec){
        //

        //process the first tree with selectec objects
        size = this->selectTree->size();edkEnd();
        if(size){
            //get only the last objet
            size--;edkEnd();

            //clean the up from the saved objects
            for(edk::uint32 i=0u;i<size;i++){
                id = this->selectTree->getElementInPosition(0u);edkEnd();
                //up the object on the S tree
                this->selectTreeS->add(id);edkEnd();
                //remove it from the last tree
                this->selectTree->remove(id);edkEnd();
            }

            id = this->selectTree->getElementInPosition(0u);edkEnd();

            obj = this->list.getPointerByID(id);edkEnd();
            if(obj){
                //test if the mouse is pressed
                if(this->mouseStatus == edk::gui2d::gui2dMousePressed){
                    obj->setStatus(edk::gui2d::gui2dTexturePressedUp);edkEnd();
                    obj->pressed=true;edkEnd();
                    this->objPressed = obj;edkEnd();
                    if(this->objPressed->canMove()){
                        this->objPressed->startMove(this->saveMousePosition + this->mouseDistance);edkEnd();
                    }

                    //test if the object selected is different
                    if(this->objSelected){
                        //remove the selection
                        this->objSelected->deselect();edkEnd();
                        if(this->endSelect)
                            this->objSelected->clickEnd(this->idSelected,false,this->doubleClick);edkEnd();
                    }
                    obj->select();edkEnd();
                    obj->clickStart(this->idSelected);edkEnd();
                    //select the object
                    this->objSelected = obj;edkEnd();
                    this->endSelect = true;edkEnd();

                    //process the callback
                    this->processMousePressed(obj,edk::mouse::left);edkEnd();
                }
                else if(this->mouseStatus == edk::gui2d::gui2dMouseHolded){
                    if(obj->pressed){
                        //set the objStatus
                        obj->setStatus(edk::gui2d::gui2dTexturePressedUp);edkEnd();
                    }
                    else{
                        //set the objStatus
                        obj->setStatus(edk::gui2d::gui2dTextureUp);edkEnd();
                    }
                    if(this->objPressed){
                        //process the callback
                        this->processMouseHolded(this->objPressed,edk::mouse::left);edkEnd();
                    }
                    //test if have the object selected
                    if(this->objSelected == obj){
                        obj->clickMove(this->idSelected,true);edkEnd();
                    }
                    else if(this->objSelected){
                        obj->clickMove(this->idSelected,false);edkEnd();
                    }
                    this->endSelect = true;edkEnd();
                }
                else if(this->mouseStatus == edk::gui2d::gui2dMouseRelease){
                    //test if have the object selected
                    if(this->objSelected == obj && this->endSelect){
                        obj->clickEnd(this->idSelected,true,this->doubleClick);edkEnd();
                    }
                    else if(this->objSelected){
                        obj->clickEnd(this->idSelected,false,this->doubleClick);edkEnd();
                    }
                    this->endSelect = false;edkEnd();
                    obj->pressed=false;edkEnd();
                    //set the objStatus
                    obj->setStatus(edk::gui2d::gui2dTextureUp);edkEnd();
                }
                else{
                    obj->pressed=false;edkEnd();
                    //set the objStatus
                    obj->setStatus(edk::gui2d::gui2dTextureUp);edkEnd();
                }
            }
            else{
                //test if the mouse is pressed
                if(this->mouseStatus == edk::gui2d::gui2dMousePressed){
                    //
                    this->deselectObject();edkEnd();
                }
            }
        }
        else{
            //test if the mouse is pressed
            if(this->mouseStatus == edk::gui2d::gui2dMousePressed){
                //
                this->deselectObject();edkEnd();
            }
            else if(this->mouseStatus == edk::gui2d::gui2dMouseHolded){
                if(this->objSelected){
                    this->objSelected->clickMove(this->idSelected,false);edkEnd();
                }
            }
        }

        //test if release the mouse
        if(this->mouseStatus == edk::gui2d::gui2dMouseRelease){
            //clean the mouseRelease
            this->list.cleanPressed=true;edkEnd();
        }
    }

    //test if release the object
    if(this->mouseStatus == edk::gui2d::gui2dMouseRelease){
        //test if have the object pressed
        if(this->objPressed){
            //test if the mouse is inside the mouse pressed
            if(this->objPressed == obj){
                //process callback
                this->processMouseRelease(this->objPressed,edk::mouse::left,true);edkEnd();
            }
            else{
                //process callback
                this->processMouseRelease(this->objPressed,edk::mouse::left,false);edkEnd();
            }
            this->objPressed->pressed=false;edkEnd();
            this->objPressed = NULL;edkEnd();
        }
    }

    //process the second tree with last selected objects
    size = this->selectTreeS->size();edkEnd();
    //clean the up from the saved objects
    for(edk::uint32 i=0u;i<size;i++){
        //get the object
        obj = this->list.getPointerByID(this->selectTreeS->getElementInPosition(i));edkEnd();
        if(obj){
            if(obj->pressed){
                //set the object to pressed
                obj->setStatus(edk::gui2d::gui2dTexturePressed);edkEnd();
            }
            else{
                //set the object to normal
                obj->setStatus(edk::gui2d::gui2dTextureNormal);edkEnd();
            }
        }
    }
    //clean the last tree
    this->selectTreeS->clean();edkEnd();

    this->doubleClick=false;edkEnd();


    //clean the lights in the view
    edk::GU::guEnable(GU_LIGHTING);edkEnd();
    for(edk::uint32 i=0u;i<EDK_LIGHT_LIMIT;i++){
        edk::GU::guDisable(GU_LIGHT0+i);edkEnd();
    }
    edk::GU::guDisable(GU_LIGHTING);edkEnd();

    //render the objects
    this->list.render();edkEnd();
}


//callback
bool edk::gui2d::ViewGui2d::addCallback(edk::gui2d::ObjectGui2dCallback* callback){
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
bool edk::gui2d::ViewGui2d::removeCallback(edk::gui2d::ObjectGui2dCallback* callback){
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
void edk::gui2d::ViewGui2d::cleanCallbacks(){
    this->listCallback.clean();edkEnd();
}


