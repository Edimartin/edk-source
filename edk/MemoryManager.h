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
#include "vector/BinaryTree.h"
#include "vector/Stack.h"

#ifdef printMessages
#pragma message "    Compiling MemoryManager"
#endif

namespace edk{
class MemoryManager{
public:
    MemoryManager(edk::uint64 size);
    ~MemoryManager();

    bool haveBuffer();

    //create a new buffer
    static bool newBuffer(edk::uint64 size);
    static bool cleanBuffer();
    static bool deleteBuffer();
    static edk::uint64 size();

    //set the memory with zeros
    static bool setZeros();

    //function to alloc new memory
    template <class typeTemplate>
    inline static bool allocMemory(typeTemplate** pointer,edk::uint64 size=1uL){
        if(size && pointer){
            //alloc the memory
            *pointer = (typeTemplate*)edk::MemoryManager::privateAlloc(size*sizeof(typeTemplate),pointer);
            return true;
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
private:
    class MemoryPositions{
    public:
        MemoryPositions(){}
        ~MemoryPositions(){}
        MemoryPositions operator=(MemoryPositions m){
            this->start=m.start;
            this->end=m.end;
            return m;
        }
        bool operator>(MemoryPositions m){
            if(this->start > m.end
                    && this->end > m.end
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
    };
    class MemorySizes{
    public:
        MemorySizes(){this->size=0u;}
        ~MemorySizes(){}
        edk::uint64 size;
        edk::vector::BinaryTree<edk::MemoryManager::MemoryPositions> tree;
    };
    class MemoryPointer : public edk::MemoryManager::MemoryPositions{
    public:
        MemoryPointer(){this->pointer=NULL;}
        ~MemoryPointer(){}
        MemoryPointer operator=(MemoryPointer m){
            this->start=m.start;
            this->end=m.end;
            this->pointer=m.pointer;
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
    };

    static edk::classID classThis;

    static edk::classID buffer;
    static edk::classID positionLast;
    static edk::uint64 bufferSize;
    static edk::vector::BinaryTree<edk::MemoryManager::MemoryPointer> treeAlloc;

    //tree sizes
    class TreeSizes : public edk::vector::BinaryTree<edk::MemoryManager::MemorySizes*>{
    public:
        TreeSizes(){}
        ~TreeSizes(){
            this->cleanSizes();
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
                    delete temp;
                }
            }
            this->clean();
        }
        //create a new size
        bool newPosition(edk::uint64 size,edk::uint64 start,edk::uint64 end){
            if(size){
                //test if DON'T have the size
                edk::MemoryManager::MemorySizes* temp = this->tempGetSize(size);
                if(!temp){
                    //create a new temp
                    temp = new edk::MemoryManager::MemorySizes;
                    if(temp){
                        temp->size=size;
                        if(!this->add(temp)){
                            delete temp;
                            temp=NULL;
                        }
                    }
                }
                //test if have the temp
                if(temp){
                    edk::MemoryManager::MemoryPositions position;
                    position.start = start;
                    position.end = end;
                    //add the position
                    if(temp->tree.add(position)){
                        return true;
                    }
                    else{
                        //else test if the tree size are zero
                        if(!temp->tree.size()){
                            //remove it
                            if(this->remove(temp)){
                                delete temp;
                            }
                        }
                    }
                }
            }
            return false;
        }
        bool newPosition(edk::uint64 start,edk::uint64 end){
            return this->newPosition(end-start,start,end);
        }
        bool newPosition(edk::MemoryManager::MemoryPositions pos){
            return this->newPosition(pos.end - pos.start,pos.start,pos.end);
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
            edk::MemoryManager::MemorySizes objTemplate;
            objTemplate.size = size;
            return this->haveElement(&objTemplate);
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
            edk::MemoryManager::MemorySizes objTemplate;
            objTemplate.size = size;
            edk::MemoryManager::MemorySizes* temp = this->getElementBefore(&objTemplate);
            if(temp){
                return temp->size;
            }
            return 0uL;
        }
        edk::uint64 getSizeAfter(edk::uint64 size){
            edk::MemoryManager::MemorySizes objTemplate;
            objTemplate.size = size;
            edk::MemoryManager::MemorySizes* temp = this->getElementAfter(&objTemplate);
            if(temp){
                return temp->size;
            }
            return 0uL;
        }
    private:
        edk::MemoryManager::MemorySizes* tempGetSize(edk::uint64 size){
            edk::MemoryManager::MemorySizes objTemplate;
            objTemplate.size = size;
            return this->getElement(&objTemplate);
        }
    }static treeRemoved;

    //save if have the buffer
    bool saveHaveBuffer;

    //alloc a new memory inside the buffer
    static edk::classID privateAlloc(edk::uint64 size,edk::classID pointer);
};
}

#endif // MEMORYMANAGER_H
