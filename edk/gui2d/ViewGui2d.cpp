#include "ViewGui2d.h"

/*
ViewGui2d - View to show the objects on the GUI 2D library
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

edk::gui2d::ViewGui2d::ViewGui2d(){
    //
    this->idCounter = 0u;
    this->mouseStatus = edk::gui2d::gui2dMouseNothing;
    this->objPressed = NULL;
    this->selectTree = &this->tree1;
    this->selectTreeS = &this->tree2;
}
edk::gui2d::ViewGui2d::~ViewGui2d(){
    //
    this->tree1.clean();
    this->tree2.clean();
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

void edk::gui2d::ViewGui2d::drawSelectionScene(){
    //
    this->list.print();
}
edk::uint32 counter=0u;
void edk::gui2d::ViewGui2d::selectObject(edk::uint32 ,edk::uint32 ,edk::float32 ,edk::float32 ,edk::vector::Stack<edk::uint32>* names){
    //
    edk::uint32 id=0u;
    edk::gui2d::ObjectGui2d* obj=NULL;
    edk::uint32 size = 0u;


    size = names->size();
    //get the objects where the mouse is inside
    for(edk::uint32 i=0u;i<size;i++){
        id = names->get(i);
        //get the object
        obj = this->list.getPointerByID(id);
        if(obj){
            //add the id to the select tree
            this->selectTree->add(id);
            //remove it from the last tree
            this->selectTreeS->remove(id);
        }
    }
}

//add the object
bool edk::gui2d::ViewGui2d::addObjectGui2d(edk::gui2d::ObjectGui2d* obj){
    if(obj){
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
        return this->list.removeByPointer(obj);
    }
    return false;
}
//remove all objects
void edk::gui2d::ViewGui2d::removeAllObjectGui2d(){
    //test if the obj is the same pressed
    this->objPressed=NULL;
    this->list.removeAll();
}

void edk::gui2d::ViewGui2d::update(edk::WindowEvents* events){
    //
    bool runSelection=false;
    this->list.update();
    edk::uint32 size = 0u;

    this->mouseStatus = edk::gui2d::gui2dMouseNothing;
    bool mousePressed = false;

    //calculate the mouse position in the world view
    edk::vec2f32 mousePercent = edk::vec2f32((edk::float32)events->mousePos.x / (edk::float32)events->windowSize.width
                                             ,(edk::float32)events->mousePos.y / (edk::float32)events->windowSize.height
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
        if(events->mousePressed[i] == edk::mouse::left){
            this->mouseStatus = edk::gui2d::gui2dMousePressed;
            mousePressed = true;
            runSelection = true;
            //save the cursor position to move the object
            this->saveMousePosition = mousePosition;

            this->mouseMoving = true;
        }
        else if(events->mousePressed[i] == edk::mouse::right){
            //press the right button to cancel the oject move
            if(this->mouseMoving){
                this->mouseMoving = false;

                //move the object to the position before
                if(this->objPressed){
                    if(this->objPressed->canMove())
                        this->objPressed->cancelMove();
                    this->objPressed->forceUpdate();
                }
            }
        }
    }
    size = events->mouseHolded.size();
    for(edk::uint32 i = 0u;i<size;i++){
        if(events->mouseHolded[i] == edk::mouse::left){
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
        if(events->mouseRelease[i] == edk::mouse::left){
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
    if(events->mouseMoved || runSelection){
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
        this->testSelection(events->mousePos);
    }
    else{
        this->selectionExec = false;
    }

    this->list.cleanPressed=false;
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
                    if(this->objPressed->canMove())
                        this->objPressed->startMove(this->saveMousePosition + this->mouseDistance);

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
                }
                else{
                    obj->pressed=false;
                    //set the objStatus
                    obj->setStatus(edk::gui2d::gui2dTextureUp);
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
            return this->listCallback.pushBack(callback);
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


