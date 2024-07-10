#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

/*
Library C++ MemoryManager - Alloc memory to be used by edk
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

#pragma once
#include <stdio.h>

#ifdef printMessages
#pragma message "Inside MemoryManager"
#endif

#include "DebugFile.h"
#include "vector/BinaryTreeStatic.h"
#include "vector/StackStatic.h"
#include "thread/Mutex.h"

#ifdef printMessages
#pragma message "    Compiling MemoryManager"
#endif

namespace edk{
class MemoryManager{
public:
    MemoryManager(edk::uint64 size);
    virtual ~MemoryManager();

    bool haveBuffer();

    //create a new buffer
    static bool cleanAndNewBuffer(edk::uint64 size);
    static bool newBuffer();
    static bool cleanBuffers();
    static inline bool deleteBuffers(){return edk::MemoryManager::cleanBuffers();}
    static edk::uint64 size();

    //set the memory with zeros
    static bool setZeros(edk::uint32 position);
    static bool setZerosAllBuffers();

    //function to alloc new memory
    template <class typeTemplate>
    inline static bool allocMemory(typeTemplate** pointer,edk::uint64 size=1uL){
        if(size && pointer){
            //alloc the memory
            *pointer = (typeTemplate*)edk::MemoryManager::privateAlloc(size*sizeof(typeTemplate),pointer);
            if(*pointer) return true;
        }
        return false;
    }

    //free the memory
    static bool freeMemory(edk::classID pointer);
    template <class typeTemplate>
    inline static bool freeMemory(typeTemplate** pointer){
        if(pointer){
            return edk::MemoryManager::freeMemory((edk::classID )pointer);
        }
        return false;
    }

    //update the connecteds
    static bool connectAllRemoveds();
    static bool connectOneRemoved();

    //print all the positions removed's
    static void printRemoveds();
private:
    static edk::classID classThis;

    //mutex for threads
    static edk::multi::Mutex mut;

    class MemoryBuffer{
    public:
        MemoryBuffer(){
            this->buffer=NULL;
            this->positionLast=0uL;
        }
        virtual ~MemoryBuffer(){}
        MemoryBuffer operator=(MemoryBuffer m){
            this->buffer=m.buffer;
            this->positionLast=m.positionLast;
            return m;
        }
        bool operator>(MemoryBuffer m){
            if(this->buffer > m.buffer){
                return true;
            }
            return false;
        }
        bool operator==(MemoryBuffer m){
            if(this->buffer == m.buffer){
                return true;
            }
            return false;
        }
        edk::classID buffer;
        edk::classID positionLast;
    };
    class MemoryPositions{
    public:
        MemoryPositions(){}
        virtual ~MemoryPositions(){}
        void construct(){}
        MemoryPositions operator=(MemoryPositions m){
            this->start=m.start;
            this->end=m.end;
            this->buffer=m.buffer;
            return m;
        }
        bool operator>(MemoryPositions m){
            if(this->start > m.start
                    //&& this->end > m.end
                    ){
                return true;
            }
            return false;
        }
        bool operator==(MemoryPositions m){
            if(this->start == m.start
                    && this->end == m.end
                    ){
                return true;
            }
            return false;
        }
        edk::uint64 start,end;
        edk::MemoryManager::MemoryBuffer buffer;
    };
    class MemorySizes{
    public:
        MemorySizes(){}
        virtual ~MemorySizes(){}

        virtual void construct(){
            this->size=0u;
            this->tree.construct();
        }

        virtual void destruct(){
            this->tree.destruct();
        }

        edk::uint64 size;
        edk::vector::BinaryTreeStatic<edk::MemoryManager::MemoryPositions> tree;
    };
    class MemoryPointer : public edk::MemoryManager::MemoryPositions{
    public:
        MemoryPointer(){this->pointer=NULL;}
        virtual ~MemoryPointer(){}
        MemoryPointer operator=(MemoryPointer m){
            this->start=m.start;
            this->end=m.end;
            this->pointer=m.pointer;
            this->buffer=m.buffer;
            return m;
        }
        bool operator>(MemoryPointer m){
            if(this->pointer > m.pointer){
                return true;
            }
            return false;
        }
        bool operator==(MemoryPointer m){
            if(this->pointer == m.pointer){
                return true;
            }
            return false;
        }
        edk::classID pointer;
        edk::MemoryManager::MemoryBuffer buffer;
    };

    //class to save equally positions
    class MemoryConnected{
    public:
        MemoryConnected(){}
        virtual ~MemoryConnected(){}

        virtual void construct(){
            this->buffer=NULL;
            this->stack.construct();
        }
        virtual void destruct(){
            this->stack.destruct();
        }

        edk::classID buffer;
        edk::vector::StackStatic<edk::MemoryManager::MemoryPositions> stack;
    };

    static edk::uint64 bufferSize;
    static edk::vector::BinaryTreeStatic<edk::MemoryManager::MemoryPointer> treeAlloc;

    //tree sizes
    class TreeSizes : public edk::vector::BinaryTreeStatic<edk::MemoryManager::MemorySizes*>{
    public:
        TreeSizes(){}
        virtual ~TreeSizes(){
        }
        virtual void construct(){
            this->objTemplate.construct();
            edk::vector::BinaryTreeStatic<edk::MemoryManager::MemorySizes*>::construct();
        }

        virtual void destruct(){
            this->cleanSizes();
            this->objTemplate.destruct();
            edk::vector::BinaryTreeStatic<edk::MemoryManager::MemorySizes*>::destruct();
        }

        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::MemoryManager::MemorySizes* first,edk::MemoryManager::MemorySizes* second){
            //
            if(first->size>second->size){
                //
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::MemoryManager::MemorySizes* first,edk::MemoryManager::MemorySizes* second){
            //
            if(first->size==second->size){
                //
                return true;
            }
            return false;
        }

        //clean the sizes
        void cleanSizes(){
            edk::uint32 size=this->size();
            edk::MemoryManager::MemorySizes* temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    temp->destruct();
                    delete temp;
                }
            }
            this->clean();
        }
        //create a new size
        bool newPosition(edk::MemoryManager::MemoryBuffer buffer,edk::uint64 size,edk::uint64 start,edk::uint64 end){
            if(size){
                //test if DON'T have the size
                edk::MemoryManager::MemorySizes* temp = this->tempGetSize(size);
                if(!temp){
                    //create a new temp
                    temp = new edk::MemoryManager::MemorySizes;
                    if(temp){
                        temp->construct();
                        temp->size=size;
                        if(!this->add(temp)){
                            temp->destruct();
                            delete temp;
                            temp=NULL;
                        }
                    }
                }
                //test if have the temp
                if(temp){
                    edk::MemoryManager::MemoryPositions position;
                    position.construct();
                    position.start = start;
                    position.end = end;
                    position.buffer = buffer;
                    //add the position
                    if(temp->tree.add(position)){
                        return true;
                    }
                    else{
                        //else test if the tree size are zero
                        if(!temp->tree.size()){
                            //remove it
                            if(this->remove(temp)){
                                temp->destruct();
                                delete temp;
                            }
                        }
                    }
                }
            }
            return false;
        }
        bool newPosition(edk::MemoryManager::MemoryBuffer buffer,edk::uint64 start,edk::uint64 end){
            return this->newPosition(buffer,end-start,start,end);
        }
        bool newPosition(edk::MemoryManager::MemoryBuffer buffer,edk::MemoryManager::MemoryPositions pos){
            return this->newPosition(buffer,pos.end - pos.start,pos.start,pos.end);
        }
        bool newPosition(edk::MemoryManager::MemoryPositions pos){
            return this->newPosition(pos.buffer,pos.end - pos.start,pos.start,pos.end);
        }
        //remove a position from the tree
        bool removePosition(edk::uint64 size,edk::uint64 start,edk::uint64 end){
            edk::MemoryManager::MemorySizes* temp = this->tempGetSize(size);
            if(temp){
                edk::MemoryManager::MemoryPositions position;
                position.start = start;
                position.end = end;
                //remove a position inside the size
                if(temp->tree.remove(position)){
                    //test if have the size zero in the tree
                    if(!temp->tree.size()){
                        //remove it
                        if(this->remove(temp)){
                            temp->destruct();
                            delete temp;
                        }
                    }
                    return true;
                }
            }
            return false;
        }
        bool removePosition(edk::uint64 start,edk::uint64 end){
            return this->removePosition(end-start,start,end);
        }
        bool removePosition(edk::MemoryManager::MemoryPositions pos){
            return this->removePosition(pos.end-pos.start,pos.start,pos.end);
        }

        //return if have one size in the tree
        bool haveSize(edk::uint64 size){
            this->objTemplate.size = size;
            return this->haveElement(&this->objTemplate);
        }
        bool haveSize(edk::uint64 start,edk::uint64 end){
            return this->haveSize(end-start);
        }
        bool haveSize(edk::MemoryManager::MemoryPositions pos){
            return this->haveSize(pos.end-pos.start);
        }
        edk::MemoryManager::MemoryPositions getPosInPosition(edk::uint64 size,edk::uint32 position){
            edk::MemoryManager::MemoryPositions ret;
            ret.start=0u;
            ret.end=0u;
            edk::MemoryManager::MemorySizes* temp = this->tempGetSize(size);
            if(temp){
                if(position < temp->tree.size()){
                    ret = temp->tree.getElementInPosition(position);
                }
            }
            return ret;
        }
        edk::MemoryManager::MemoryBuffer getBufferInPosition(edk::uint64 size,edk::uint32 position){
            edk::MemoryManager::MemoryBuffer ret;
            edk::MemoryManager::MemorySizes* temp = this->tempGetSize(size);
            if(temp){
                if(position < temp->tree.size()){
                    edk::MemoryManager::MemoryPositions pos = temp->tree.getElementInPosition(position);
                    ret = pos.buffer;
                }
            }
            return ret;
        }
        bool removePosInPosition(edk::uint64 size,edk::uint32 position){
            edk::MemoryManager::MemorySizes* temp = this->tempGetSize(size);
            if(temp){
                if(position < temp->tree.size()){
                    edk::MemoryManager::MemoryPositions pos = temp->tree.getElementInPosition(position);
                    if(temp->tree.remove(pos)){
                        return true;
                    }
                }
            }
            return false;
        }
        edk::MemoryManager::MemoryPositions popPosInPosition(edk::uint64 size,edk::uint32 position){
            edk::MemoryManager::MemoryPositions ret;
            ret.start=0u;
            ret.end=0u;
            edk::MemoryManager::MemorySizes* temp = this->tempGetSize(size);
            if(temp){
                if(position < temp->tree.size()){
                    ret = temp->tree.getElementInPosition(position);
                    if(temp->tree.remove(ret)){
                        //test if don't have sizes on the tree
                        if(!temp->tree.size()){
                            //remove it
                            if(this->remove(temp)){
                                temp->destruct();
                                delete temp;
                            }
                        }
                    }
                    else{
                        ret.start=0u;
                        ret.end=0u;
                    }
                }
            }
            return ret;
        }

        //get a size after or before
        edk::uint64 getSizeBefore(edk::uint64 size){
            this->objTemplate.size = size;
            edk::MemoryManager::MemorySizes* temp = this->getElementBefore(&this->objTemplate);
            if(temp){
                return temp->size;
            }
            return 0uL;
        }
        edk::uint64 getSizeAfter(edk::uint64 size){
            this->objTemplate.size = size;
            edk::MemoryManager::MemorySizes* temp = this->getElementAfter(&this->objTemplate);
            if(temp){
                return temp->size;
            }
            return 0uL;
        }
    private:
        edk::MemoryManager::MemorySizes objTemplate;
        edk::MemoryManager::MemorySizes* tempGetSize(edk::uint64 size){
            this->objTemplate.size = size;
            return this->getElement(&this->objTemplate);
        }
    }static treeSizeRemoved;
    class TreePosRemoved: public edk::vector::BinaryTreeStatic<edk::MemoryManager::MemoryPositions>{
    public:
        TreePosRemoved(){}
        ~TreePosRemoved(){}

        virtual void construct(){
            this->stackConnecteds.construct();
            edk::vector::BinaryTreeStatic<edk::MemoryManager::MemoryPositions>::construct();
        }
        virtual void destruct(){
            edk::vector::BinaryTreeStatic<edk::MemoryManager::MemoryPositions>::destruct();
            this->stackConnecteds.destruct();
        }
        //UPDATE
        virtual void updateElement(edk::MemoryManager::MemoryPositions value){
            //update the value
            if(this->havePos){
                //test if the buffer are the same
                if(this->posLast.buffer.buffer == value.buffer.buffer){
                    //test if they are connected
                    if(this->posLast.end == value.start){
                        this->stackConnecteds.addNewPosition(value.buffer.buffer,value);
                        this->posLast = value;
                    }
                    else{
                        //else force create a new connected
                        this->stackConnecteds.forceAddNewPosition(value.buffer.buffer,value);
                        this->posLast = value;
                    }
                }
                else{
                    //else finish the posStack
                    this->stackConnecteds.forceAddNewPosition(value.buffer.buffer,value);
                    this->posLast = value;
                }
            }
            else{
                this->havePos=true;
                this->posLast = value;
                //add the new position
                this->stackConnecteds.forceAddNewPosition(value.buffer.buffer,value);
            }
        }
        //update the elements
        virtual void update(){
            this->havePos=false;
            edk::vector::BinaryTreeStatic<edk::MemoryManager::MemoryPositions>::update();
        }

        //get connecteds
        edk::uint32 getConnectedsSize(){
            return this->stackConnecteds.size();
        }
        edk::uint32 getConnectedsSizeInPosition(edk::uint32 position){
            return this->stackConnecteds.getSizeInPosition(position);
        }
        edk::MemoryManager::MemoryPositions getConnectedInPosition(edk::uint32 positionConnected,edk::uint32 position){
            return this->stackConnecteds.getPosInPosition(positionConnected,position);
        }

        void cleanConnecteds(){
            this->stackConnecteds.destruct();
            this->stackConnecteds.construct();
        }
    private:
        bool havePos;
        edk::MemoryManager::MemoryPositions posLast;

        //class to save the connected positions
        class StackConnecteds: public edk::vector::StackStatic<edk::MemoryManager::MemoryConnected*>{
        public:
            StackConnecteds(){}
            ~StackConnecteds(){}

            virtual void construct(){
                edk::vector::StackStatic<edk::MemoryManager::MemoryConnected*>::construct();
            }
            virtual void destruct(){
                this->cleanPos();
                edk::vector::StackStatic<edk::MemoryManager::MemoryConnected*>::destruct();
            }

            //clean all memoryConnected in the stack
            void cleanPos(){
                edk::uint32 size = this->size();
                edk::MemoryManager::MemoryConnected* pos;
                for(edk::uint32 i=0u;i<size;i++){
                    pos = this->get(i);
                    if(pos){
                        pos->destruct();
                        delete pos;
                    }
                }
                this->clean();
            }

            //add a new position
            bool addNewPosition(edk::classID buffer,edk::MemoryManager::MemoryPositions pos){
                if(buffer){
                    edk::MemoryManager::MemoryConnected* connected = NULL;

                    //test if have the connected with the same buffer inside the stack
                    if(this->size()){
                        connected = this->get(this->size()-1u);
                        if(connected){
                            //test if the buffer aren't the same
                            if(connected->buffer != buffer){
                                //need create a new connected
                                connected=NULL;
                            }
                        }
                    }
                    if(!connected){
                        //create a new connected
                        connected = new edk::MemoryManager::MemoryConnected;
                        if(connected){
                            connected->construct();
                            connected->buffer=buffer;
                            this->pushBack(connected);
                        }
                    }
                    if(connected){
                        //add the position into the connected
                        connected->stack.pushBack(pos);
                        return true;
                    }
                }
                return false;
            }
            bool forceAddNewPosition(edk::classID buffer,edk::MemoryManager::MemoryPositions pos){
                edk::MemoryManager::MemoryConnected* connected = NULL;
                //create a new connected
                connected = new edk::MemoryManager::MemoryConnected;
                if(connected){
                    connected->construct();
                    connected->buffer=buffer;
                    this->pushBack(connected);
                }
                return this->addNewPosition(buffer,pos);
            }

            //return the size in a stack in a position
            edk::uint32 getSizeInPosition(edk::uint32 positionStack){
                if(this->havePos(positionStack)){
                    edk::MemoryManager::MemoryConnected* connected = this->get(positionStack);
                    if(connected){
                        return connected->stack.size();
                    }
                }
                return 0u;
            }
            //get a position in a position
            edk::MemoryManager::MemoryPositions getPosInPosition(edk::uint32 positionStack,edk::uint32 positionInStack){
                edk::MemoryManager::MemoryPositions pos;
                pos.buffer.buffer=NULL;
                if(this->havePos(positionStack)){
                    edk::MemoryManager::MemoryConnected* connected = this->get(positionStack);
                    if(connected){
                        if(connected->stack.havePos(positionInStack)){
                            pos = connected->stack.get(positionInStack);
                        }
                    }
                }
                return pos;
            }
        }stackConnecteds;
    }static treePositionsRemoved;

    //tree memoryBuffers
    static edk::vector::StackStatic<edk::MemoryManager::MemoryBuffer> stackBuffers;
    static edk::uint32 bufferLastPosition;

    //save if have the buffer
    bool saveHaveBuffer;

    //alloc a new memory inside the buffer
    static edk::classID privateAlloc(edk::uint64 size,edk::classID pointer,edk::uint8 recursive=1u);
};
}
#endif // MEMORYMANAGER_H
