#include "MemoryManager.h"

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

#ifdef printMessages
#pragma message "            Inside MemoryManager.cpp"
#endif

edk::classID edk::MemoryManager::classThis=NULL;
edk::classID edk::MemoryManager::buffer=NULL;
edk::classID edk::MemoryManager::positionLast=NULL;
edk::uint64 edk::MemoryManager::bufferSize=0uL;
edk::vector::BinaryTree<edk::MemoryManager::MemoryPointer> edk::MemoryManager::treeAlloc;
edk::MemoryManager::TreeSizes edk::MemoryManager::treeRemoved;

edk::MemoryManager::MemoryManager(edk::uint64 size){
    if(!edk::MemoryManager::classThis){
        edk::MemoryManager::classThis=this;
        if(size){
            this->saveHaveBuffer = edk::MemoryManager::newBuffer(size);
        }
        else{
            this->saveHaveBuffer = edk::MemoryManager::newBuffer(1024uL);
        }
        if(this->saveHaveBuffer){
            edk::MemoryManager::setZeros();
        }
    }
}
edk::MemoryManager::~MemoryManager(){
    if(edk::MemoryManager::classThis==this){
        //delete the buffer
        if(this->saveHaveBuffer){
            edk::MemoryManager::deleteBuffer();
        }
        edk::MemoryManager::classThis=NULL;
    }
}

bool edk::MemoryManager::haveBuffer(){
    return this->saveHaveBuffer;
}

//alloc a new memory inside the buffer
edk::classID edk::MemoryManager::privateAlloc(edk::uint64 size,edk::classID pointer){
    edk::classID ret=NULL;
    if(pointer){
        //test if have some memory removed
        if(edk::MemoryManager::treeRemoved.size()){
            //test if can alloc from a removed

            //calculate the size if have the size inside the tree
            if(edk::MemoryManager::treeRemoved.haveSize(size)){
                //
            }
            else{
                //else test if have a size after
                edk::uint64 newSize = edk::MemoryManager::treeRemoved.getSizeAfter(size);
                if(newSize){
                    if(size<newSize){
                        //pop the position from a size
                        edk::MemoryManager::MemoryPositions pos = edk::MemoryManager::treeRemoved.popPosInPosition(newSize,0u);
                        ret = (edk::classID)pos.start;
                        //increment start
                        pos.start+=size;
                        //add the new position into the tree
                        edk::MemoryManager::treeRemoved.newPosition(pos);
                    }
                }
            }
        }
        if(!ret){
            //test if can alloc in the end of the memory
            if(size<((edk::uint64)edk::MemoryManager::positionLast
                     - (edk::uint64)edk::MemoryManager::buffer
                     + (edk::uint64)edk::MemoryManager::bufferSize
                     )
                    ){
                //allod the memory and return the buffer
                edk::MemoryManager::MemoryPointer newAlloc;
                newAlloc.start = (edk::uint64)edk::MemoryManager::positionLast;
                newAlloc.end = (edk::uint64)edk::MemoryManager::positionLast+size;
                newAlloc.pointer = pointer;
                if(edk::MemoryManager::treeAlloc.add(newAlloc)){
                    edk::MemoryManager::positionLast=(edk::classID)newAlloc.end;
                    ret = (edk::classID)newAlloc.start;
                }
            }
        }
    }
    //test what is the last position
    return ret;
}

//create a new buffer
bool edk::MemoryManager::newBuffer(edk::uint64 size){
    edk::MemoryManager::cleanBuffer();
    if(size){
        //create a new buffer
        edk::MemoryManager::buffer = (edk::uint8*)malloc(size);
        if(edk::MemoryManager::buffer){
            edk::MemoryManager::positionLast = edk::MemoryManager::buffer;
            edk::MemoryManager::bufferSize=size;
            return true;
        }
    }
    return false;
}
bool edk::MemoryManager::cleanBuffer(){
    if(edk::MemoryManager::bufferSize && edk::MemoryManager::buffer){
        free(edk::MemoryManager::buffer);
        edk::MemoryManager::bufferSize=0uL;
        edk::MemoryManager::positionLast=0uL;
        edk::MemoryManager::treeAlloc.clean();
        edk::MemoryManager::treeRemoved.cleanSizes();
        return true;
    }
    return false;
}
bool edk::MemoryManager::deleteBuffer(){
    if(edk::MemoryManager::bufferSize && edk::MemoryManager::buffer){
        free(edk::MemoryManager::buffer);
        edk::MemoryManager::bufferSize=0uL;
        edk::MemoryManager::treeAlloc.clean();
        edk::MemoryManager::treeRemoved.cleanSizes();
        return true;
    }
    return false;
}
edk::uint64 edk::MemoryManager::size(){
    return edk::MemoryManager::bufferSize;
}

//set the memory with zeros
bool edk::MemoryManager::setZeros(){
    if(edk::MemoryManager::buffer && edk::MemoryManager::bufferSize){
        edkMemSet(edk::MemoryManager::buffer,0,edk::MemoryManager::bufferSize);
        return true;
    }
    return false;
}

//free the memory
bool edk::MemoryManager::freeMemory(edk::classID pointer){
    if(pointer){
        //test if have the pointer
        edk::MemoryManager::MemoryPointer objTemplate;
        objTemplate.pointer = pointer;
        //test if have the element in the tree
        edk::MemoryManager::MemoryPointer temp = edk::MemoryManager::treeAlloc.getElement(objTemplate);
        if(temp.pointer == pointer){
            //remove it from the tree alloc
            edk::MemoryManager::MemoryPositions pos;
            pos.start = temp.start;
            pos.end = temp.end;
            if(edk::MemoryManager::treeRemoved.newPosition(pos)){
                if(edk::MemoryManager::treeAlloc.remove(temp)){
                    //add it into the tree removed
                    return true;
                }
            }
        }
    }
    return false;
}
