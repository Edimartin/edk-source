#include "ViewGui2d.h"

edk::gui2d::ViewGui2d::ViewGui2d(){
    //
    this->idCounter = 0u;
    this->mouseHolded = false;
}
edk::gui2d::ViewGui2d::~ViewGui2d(){
    //
    this->tree1.clean();
    this->tree2.clean();

}
void edk::gui2d::ViewGui2d::drawSelectionScene(){
    //
    this->list.print();
}
edk::uint32 counter=0u;
void edk::gui2d::ViewGui2d::selectObject(edk::uint32 ,edk::int32 ,edk::float32 ,edk::float32 ,edk::vector::Stack<edk::uint32>* names){
    //
    edk::uint32 id=0u;
    edk::gui2d::ObjectGui2d* obj=NULL;
    edk::uint32 size = 0u;

    //change the tree's
    if(this->selectTree == &this->tree1){
        this->selectTree = &this->tree2;
        this->selectTreeS = &this->tree1;
    }
    else{
        this->selectTree = &this->tree1;
        this->selectTreeS = &this->tree2;
    }

    size = names->size();
    //get the objects where the mouse is inside
    for(edk::uint32 i=0u;i<size;i++){
        id = names->get(i);
        //get the object
        obj = this->list.getPointerByID(id);
        if(obj){
            //test if the mouse is pressed
            if(this->mousePressed){
                obj->setStatus(edk::gui2d::gui2dTexturePressed);
                obj->pressed=true;
            }
            if(this->mouseHolded){
                if(obj->pressed){
                    //set the objStatus
                    obj->setStatus(edk::gui2d::gui2dTexturePressed);
                    obj->pressed=true;
                }
                else{
                    //set the objStatus
                    obj->setStatus(edk::gui2d::gui2dTextureUp);
                }
            }
            else{
                obj->pressed=false;
                //set the objStatus
                obj->setStatus(edk::gui2d::gui2dTextureUp);
            }

            //add the id to the select tree
            this->selectTree->add(id);
            //remove it from the last tree
            this->selectTreeS->remove(id);
        }
    }
    size = this->selectTreeS->size();
    //clean the up from the saved objects
    for(edk::uint32 i=0u;i<size;i++){
        //get the object
        obj = this->list.getPointerByID(this->selectTreeS->getElementInPosition(i));
        if(obj){
            //set the objStatus
            obj->setStatus(edk::gui2d::gui2dTextureNormal);
        }
    }
    //clean the last tree
    this->selectTreeS->clean();

    //test if release the mouse
    if(this->mouseRelease){
        //clean the mouseRelease
        this->list.cleanPressed=true;
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
        return this->list.removeByPointer(obj);
    }
    return false;
}
//remove all objects
void edk::gui2d::ViewGui2d::removeAllObjectGui2d(){
    this->list.removeAll();
}

void edk::gui2d::ViewGui2d::update(edk::WindowEvents* events){
    //
    bool runSelection=false;
    this->list.update();
    edk::uint32 size = 0u;
    if(this->mouseHolded){
        runSelection = true;
    }
    this->mouseHolded = false;
    this->mousePressed = false;
    this->mouseRelease = false;
    size = events->mousePressed.size();
    for(edk::uint32 i = 0u;i<size;i++){
        if(events->mousePressed[i] == edk::mouse::left){
            this->mousePressed = true;
            runSelection = true;
        }
    }
    size = events->mouseHolded.size();
    for(edk::uint32 i = 0u;i<size;i++){
        if(events->mouseHolded[i] == edk::mouse::left){
            this->mouseHolded = true;
            runSelection = true;
        }
    }
    size = events->mouseRelease.size();
    for(edk::uint32 i = 0u;i<size;i++){
        if(events->mouseRelease[i] == edk::mouse::left){
            this->mouseHolded = true;
            runSelection = true;
            this->mouseRelease=true;
        }
    }

    //test if the mouse was moved or pressed
    if(events->mouseMoved || runSelection){
        //run the selection
        this->testSelection(events->mousePos);
    }

    this->list.cleanPressed=false;
}

//draw the GU scene
void edk::gui2d::ViewGui2d::drawScene(edk::rectf32){
    //render the objects
    this->list.render();
}


