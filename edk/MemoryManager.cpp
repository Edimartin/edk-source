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


edk::MemoryManager::MemoryManager(){
    this->classThis = NULL;
    this->constructor();
}
edk::MemoryManager::MemoryManager(edk::uint64 size){
    this->classThis = NULL;
    this->constructor(size);
}
edk::MemoryManager::~MemoryManager(){
    this->destructor();
}


void edk::MemoryManager::constructor(){
    if(this->classThis!=this){
        this->classThis=this;
        this->buffer=NULL;
        this->posStart=0uL;
        this->posEnd=0uL;
        this->size=0uL;
    }
}
void edk::MemoryManager::constructor(edk::uint64 size){
    if(this->classThis!=this){
        this->constructor();
        this->newBuffer(size);
    }
}
void edk::MemoryManager::destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        this->deleteBuffer();
    }
}

bool edk::MemoryManager::deleteBuffer(){
    this->cleanUsage();
    if(this->buffer){
        free(this->buffer);
        this->buffer=NULL;
        return true;
    }
    return false;
}

bool edk::MemoryManager::newBuffer(edk::uint64 size){
    this->deleteBuffer();
    if(size){
        this->buffer = (edk::uint8*)malloc(size);
        if(this->buffer){
            this->size=size;
            this->posStart=0u;
            this->posEnd=this->size;
            //create a new free buffer
            this->treeFree.newMemory(this->posStart,this->posEnd,this);
            return true;
        }
    }
    return false;
}

bool edk::MemoryManager::haveBuffer(){
    if(this->buffer){
        return true;
    }
    return false;
}

void edk::MemoryManager::cleanUsage(){
    this->treeUsers.clean();
    this->treeUsing.cleanMemorys();
    this->treeFree.cleanMemorys();
}

bool edk::MemoryManager::newVec(edk::classID* pointer,edk::uint64 lenght){
    if(pointer && lenght){
        //get the memoryFree first in the positions
        edk::MemoryPiece* memFirst = NULL;
        edk::MemoryPiece* memSecond = NULL;
        edk::MemoryPiece memTemp1;
        edk::MemoryPiece memTemp2;
        edk::uint32 position=0u;
        do{
            //get the memoryFree first in the positions
            memFirst = this->treeFree.getElementInPosition(position);
            memSecond = NULL;
            if(memFirst){
                if(lenght<memFirst->bufferSize){
                    //can divide vemory
                    memTemp1.bufferStart = memFirst->bufferStart;
                    memTemp1.bufferEnd = memFirst->bufferStart + lenght;
                    memTemp2.bufferStart = memFirst->bufferStart + lenght;
                    memTemp2.bufferEnd = memFirst->bufferEnd;

                    this->treeFree.deleteMemory(memFirst);

                    //create the new memories
                    if(this->treeFree.newMemory(memTemp2.bufferStart,memTemp2.bufferEnd,this)){
                        memFirst = this->treeFree.newMemory(memTemp1.bufferStart,memTemp1.bufferEnd,this);
                    }
                }
                if(lenght==memFirst->bufferSize){
                    //can use the memory
                    memSecond = this->treeUsing.newMemory(memFirst->bufferStart,memFirst->bufferEnd,pointer);
                    if(memSecond){
                        memFirst->release(this);
                        this->treeFree.deleteMemory(memFirst);
                        //set the pointer
                        *pointer = (edk::classID)&this->buffer[memSecond->bufferStart];
                        //add the user
                        this->treeUsers.addUser(pointer,memSecond);
                        return true;
                    }
                }
                else{
                    //test if the next is connected
                    memSecond = this->treeFree.getElementInPosition(position+1u);
                    if(memSecond){
                        if(memFirst->bufferEnd == memSecond->bufferStart){
                            //connect the two memories
                            memTemp1.bufferStart = memFirst->bufferStart;
                            memTemp1.bufferEnd = memSecond->bufferEnd;
                            this->treeFree.deleteMemory(memFirst);
                            this->treeFree.deleteMemory(memSecond);
                            this->treeFree.newMemory(memTemp1.bufferStart,memTemp1.bufferEnd,this);
                            continue;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                break;
            }
            //else just go to the next memory
            position++;
        }while(true);
    }
    return false;
}
bool edk::MemoryManager::retain(edk::classID* pointerClassDest,edk::classID* pointerClassSource){
    if(pointerClassDest && pointerClassSource){
        edk::MemoryPiece* memFirst = this->treeUsers.getUserPointer(pointerClassSource);
        if(memFirst){
            if(memFirst->retain(pointerClassDest)){
                *pointerClassDest = *pointerClassSource;
                //add the user
                this->treeUsers.addUser(pointerClassDest,memFirst);
                return true;
            }
        }
    }
    return false;
}
bool edk::MemoryManager::release(edk::classID* pointerClass){
    if(pointerClass){
        //load the memoryUsing
        edk::MemoryPiece* memFirst = this->treeUsers.getUserPointer(pointerClass);
        if(memFirst){
            //remove the user from memory
            if(memFirst->release(pointerClass)){
                *pointerClass=NULL;
                //test if the memori have no users
                if(!memFirst->size()){
                    //delete the memory
                    if(this->treeFree.newMemory(memFirst->bufferStart,memFirst->bufferEnd,this)){
                        this->treeUsing.deleteMemory(memFirst);
                    }
                }
                this->treeUsers.removeUser(pointerClass);
                return true;
            }
        }
    }
    return false;
}
