#ifndef UNDOMANAGER_H
#define UNDOMANAGER_H

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
#pragma message "Inside UndoManager"
#endif

#pragma once
#include "../vector/Queue.h"
#include "../vector/Stack.h"
#include "../MemoryBuffer.h"

#ifdef printMessages
#pragma message "    Compiling UndoManager"
#endif

#define LIMIT_SIZE_UNDO 30u

namespace edk{
class UndoManagerFunctions{
public:
    class TreeValues;
    class Values;

    UndoManagerFunctions(){}
    UndoManagerFunctions(void (edk::UndoManagerFunctions::*functionPointerUndo)(edk::UndoManagerFunctions::TreeValues* tree),
                         void (edk::UndoManagerFunctions::*functionPointerRedo)(edk::UndoManagerFunctions::TreeValues* tree),
                         void (edk::UndoManagerFunctions::*functionPointerDelete)(edk::UndoManagerFunctions::TreeValues* tree)
                         ){
        this->functionPointerUndo = functionPointerUndo;
        this->functionPointerRedo = functionPointerRedo;
        this->functionPointerDelete = functionPointerDelete;
    }
    virtual ~UndoManagerFunctions(){}

    class Values{
    public:
        Values(){
            this->pointer = NULL;
        }
        ~Values(){}
        edk::classID pointer;
        edk::MemoryBuffer<edk::uint8> bufferUndo;
        edk::MemoryBuffer<edk::uint8> bufferRedo;

        bool processUndo(){
            if(this->pointer){
                //write the value into the pointer
                if(this->bufferUndo.size() == this->bufferRedo.size()){
                    //write the value
                    edk::uint8* buffer = this->bufferUndo.getPointer();
                    edkMemCpy(this->pointer,buffer,this->bufferUndo.size());
                    return true;
                }
            }
            return false;
        }
        bool processRedo(){
            if(this->pointer){
                //write the value into the pointer
                if(this->bufferUndo.size() == this->bufferRedo.size()){
                    //write the value
                    edk::uint8* buffer = this->bufferRedo.getPointer();
                    edkMemCpy(this->pointer,buffer,this->bufferRedo.size());
                    return true;
                }
            }
            return false;
        }
    };
    //Tree with all pointers
    class TreeValues : public edk::vector::BinaryTree<edk::UndoManagerFunctions::Values*>{
    public:
        TreeValues(){}
        ~TreeValues(){
            this->cleanValues();
        }
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::UndoManagerFunctions::Values* first,edk::UndoManagerFunctions::Values* second){
            if(first->pointer>second->pointer){
                //
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::UndoManagerFunctions::Values* first,edk::UndoManagerFunctions::Values* second){
            if(first->pointer==second->pointer){
                //
                return true;
            }
            return false;
        }

        void cleanValues(){
            edk::uint32 size = this->size();
            edk::UndoManagerFunctions::Values* temp=NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    delete temp;
                }
            }
            this->clean();
        }

        //newValue
        edk::UndoManagerFunctions::Values* newValue(edk::classID pointer){
            edk::UndoManagerFunctions::Values* ret = this->getValueByPointer(pointer);
            if(!ret){
                //create a new value
                ret = new edk::UndoManagerFunctions::Values;
                if(ret){
                    ret->pointer = pointer;
                    if(!this->add(ret)){
                        delete ret;
                        ret=NULL;
                    }
                }
            }
            //test if have one value
            return ret;
        }
    private:
        edk::UndoManagerFunctions::Values* getValueByPointer(edk::classID pointer){
            this->templateValue.pointer = pointer;
            return this->getElement(&this->templateValue);
        }
        edk::UndoManagerFunctions::Values templateValue;
    }tree;

    void (edk::UndoManagerFunctions::*functionPointerUndo)(edk::UndoManagerFunctions::TreeValues* tree);
    void (edk::UndoManagerFunctions::*functionPointerRedo)(edk::UndoManagerFunctions::TreeValues* tree);
    void (edk::UndoManagerFunctions::*functionPointerDelete)(edk::UndoManagerFunctions::TreeValues* tree);

    //process the undo and redo
    bool processUndo(){
        bool ret=false;
        if(this->functionPointerUndo){
            //tun the function
            (this->*functionPointerUndo)(&this->tree);
            ret=true;
        }
        else{
            //else change the pointers
            edk::UndoManagerFunctions::Values* temp;
            edk::uint32 size = this->tree.size();
            if(size){
                ret=true;
                for(edk::uint32 i=0u;i<size;i++){
                    temp = this->tree.getElementInPosition(i);
                    if(temp){
                        if(!temp->processUndo()){
                            ret=false;
                        }
                    }
                }
            }
        }
        return ret;
    }
    bool processRedo(){
        bool ret=false;
        if(this->functionPointerRedo){
            //tun the function
            (this->*functionPointerRedo)(&this->tree);
            ret=true;
        }
        else{
            //else change the pointers
            edk::UndoManagerFunctions::Values* temp;
            edk::uint32 size = this->tree.size();
            if(size){
                ret=true;
                for(edk::uint32 i=0u;i<size;i++){
                    temp = this->tree.getElementInPosition(i);
                    if(temp){
                        if(!temp->processRedo()){
                            ret=false;
                        }
                    }
                }
            }
        }
        return ret;
    }
    bool processDelete(){
        bool ret = false;
        if(this->functionPointerDelete){
            //tun the function
            (this->*functionPointerDelete)(&this->tree);
            ret = true;
        }
        //delete all values in the tree
        this->tree.cleanValues();
        return ret;
    }
};
class UndoManager{
public:
    UndoManager();
    ~UndoManager();

    void Constructor();
    void Destructor();

    void cleanAll();

    bool setLimitSize(edk::uint32 size);

    //add the new functions
    bool newFunction(void (edk::UndoManagerFunctions::*functionPointerUndo)(edk::UndoManagerFunctions::TreeValues* tree),
                     void (edk::UndoManagerFunctions::*functionPointerRedo)(edk::UndoManagerFunctions::TreeValues* tree),
                     void (edk::UndoManagerFunctions::*functionPointerDelete)(edk::UndoManagerFunctions::TreeValues* tree)
                     );
    void finishFunction();
    bool newDataBegin(edk::classID pointer,edk::classID value,edk::uint32 valueSize);
    bool newDataEnd(edk::classID pointer,edk::classID value,edk::uint32 valueSize);

    //UNDO
    bool undo();
    //REDO
    bool redo();
private:
    edk::vector::Stack<edk::UndoManagerFunctions*> back,front;
    edk::UndoManagerFunctions* selected;
    //size limit for the stack
    edk::uint32 limitSize;
    //remove all values in the front stack
    bool cleanAllFront();
    bool cleanBackAndFrontSize();
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // UNDOMANAGER_H
