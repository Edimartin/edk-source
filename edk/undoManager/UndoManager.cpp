#include "UndoManager.h"

/*
Library C++ UndoManager - Use the undo and redo in edk.
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
#pragma message "            Inside UndoManager.cpp"
#endif

edk::UndoManager::UndoManager(){
    //
}
edk::UndoManager::~UndoManager(){
    //
}
//remove all values in the front stack
bool edk::UndoManager::cleanAllFront(){
    edk::uint32 size = this->front.size();
    if(size){
        edk::UndoManagerFunctions* temp = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->front.get(i);
            if(temp){
                if(temp == this->selected){
                    this->selected=NULL;
                }
                temp->processDelete();
                delete temp;
            }
        }
        this->front.clean();
        return true;
    }
    return false;
}

//add the new functions
bool edk::UndoManager::newFunction(void (edk::UndoManagerFunctions::*functionPointerUndo)(edk::UndoManagerFunctions::TreeValues* tree),
                                   void (edk::UndoManagerFunctions::*functionPointerRedo)(edk::UndoManagerFunctions::TreeValues* tree),
                                   void (edk::UndoManagerFunctions::*functionPointerDelete)(edk::UndoManagerFunctions::TreeValues* tree)
                                   ){
    //clean all front values
    this->cleanAllFront();
    //create new
    this->selected = new edk::UndoManagerFunctions(functionPointerUndo,functionPointerRedo,functionPointerDelete);
    if(this->selected){
        //add the function into the queue
        edk::uint32 size = this->back.size();
        this->back.pushBack(this->selected);
        if(size<this->back.size()){
            return true;
        }
        delete this->selected;
    }
    this->selected=NULL;
    return false;
}
void edk::UndoManager::finishFunction(){
    this->selected=NULL;
}
bool edk::UndoManager::newDataBegin(edk::classID pointer,edk::classID value,edk::uint32 valueSize){
    if(this->selected){
        if(pointer && value && valueSize){
            edk::UndoManagerFunctions::Values* temp = this->selected->tree.newValue(pointer);
            if(temp){
                temp->bufferUndo.writeToBuffer((edk::uint8*)value,valueSize);
                return true;
            }
        }
    }
    return false;
}
bool edk::UndoManager::newDataEnd(edk::classID pointer,edk::classID value,edk::uint32 valueSize){
    if(this->selected){
        if(pointer && value && valueSize){
            edk::UndoManagerFunctions::Values* temp = this->selected->tree.newValue(pointer);
            if(temp){
                temp->bufferRedo.writeToBuffer((edk::uint8*)value,valueSize);
                return true;
            }
        }
    }
    return false;
}

//UNDO
bool edk::UndoManager::undo(){
    bool ret = false;
    if(this->back.size()){
        edk::UndoManagerFunctions* temp;
        //pop the element
        temp = this->back.popBack();
        if(temp){
            //process the undo
            ret = temp->processUndo();
            if(ret){
                edk::uint32 size = this->front.size();
                this->front.pushBack(temp);
                if(size<this->front.size()){
                    ret=true;
                }
                else{
                    //delete the temp
                    temp->processDelete();
                    delete temp;
                    ret=false;
                }
            }
            else{
                //delete the temp
                temp->processDelete();
                delete temp;
                ret=false;
            }
        }
    }
    return ret;
}
//REDO
bool edk::UndoManager::redo(){
    bool ret = false;
    if(this->front.size()){
        edk::UndoManagerFunctions* temp;
        //pop the element
        temp = this->front.popBack();
        if(temp){
            //process the undo
            ret = temp->processRedo();
            if(ret){
                edk::uint32 size = this->back.size();
                this->back.pushBack(temp);
                if(size<this->back.size()){
                    ret=true;
                }
                else{
                    //delete the temp
                    temp->processDelete();
                    delete temp;
                    ret=false;
                }
            }
            else{
                //delete the temp
                temp->processDelete();
                delete temp;
                ret=false;
            }
        }
    }
    return ret;
}
