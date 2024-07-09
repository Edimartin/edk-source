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

edk::vector::BinaryTreeStatic<edk::MemoryManager::MemoryPointer> edk::MemoryManager::treeAlloc;
edk::vector::StackStatic<edk::MemoryManager::MemoryBuffer> edk::MemoryManager::stackBuffers;
edk::MemoryManager::TreeSizes edk::MemoryManager::treeRemoved;
edk::multi::Mutex edk::MemoryManager::mut;
edk::classID edk::MemoryManager::classThis=NULL;
edk::uint64 edk::MemoryManager::bufferSize=0uL;
edk::uint32 edk::MemoryManager::bufferLastPosition=0u;

edk::MemoryManager::MemoryManager(edk::uint64 size){
    if(!edk::MemoryManager::classThis){
        edk::MemoryManager::classThis=this;
        edk::MemoryManager::treeRemoved.construct();
        edk::MemoryManager::treeAlloc.construct();
        edk::MemoryManager::stackBuffers.construct();
        if(size){
            this->saveHaveBuffer = edk::MemoryManager::cleanAndNewBuffer(size);
        }
        else{
            this->saveHaveBuffer = edk::MemoryManager::cleanAndNewBuffer(1024uL);
        }
        if(this->saveHaveBuffer){
            edk::MemoryManager::setZerosAllBuffers();
        }
    }
}
edk::MemoryManager::~MemoryManager(){
    if(edk::MemoryManager::classThis==this){
        //delete the buffer
        if(this->saveHaveBuffer){
            edk::MemoryManager::deleteBuffers();
        }
        edk::MemoryManager::treeRemoved.destruct();
        edk::MemoryManager::treeAlloc.destruct();
        edk::MemoryManager::stackBuffers.destruct();
        edk::MemoryManager::classThis=NULL;
    }
}

bool edk::MemoryManager::haveBuffer(){
    return this->saveHaveBuffer;
}

//alloc a new memory inside the buffer
edk::classID edk::MemoryManager::privateAlloc(edk::uint64 size,edk::classID pointer,edk::uint8 recursive){
    edk::classID ret=NULL;
    if(pointer){
        //test if have some memory removed
        if(edk::MemoryManager::treeRemoved.size()){
            //test if can alloc from a removed

            //calculate the size if have the size inside the tree
            if(edk::MemoryManager::treeRemoved.haveSize(size)){
                //pop the position from a size
                edk::MemoryManager::MemoryBuffer buffer = edk::MemoryManager::treeRemoved.getBufferInPosition(size,0u);
                edk::MemoryManager::MemoryPositions pos = edk::MemoryManager::treeRemoved.popPosInPosition(size,0u);
                //
                edk::MemoryManager::MemoryPointer newAlloc;
                newAlloc.start = pos.start;
                newAlloc.end = pos.end;
                newAlloc.pointer = pointer;
                newAlloc.buffer = buffer;
                if(edk::MemoryManager::treeAlloc.add(newAlloc)){
                    ret = (edk::classID)newAlloc.start;
                }
            }
            else{
                //else test if have a size after
                edk::uint64 newSize = edk::MemoryManager::treeRemoved.getSizeAfter(size);
                if(newSize){
                    if(size<newSize){
                        edk::MemoryManager::MemoryPointer newAlloc;
                        //pop the position from a size
                        edk::MemoryManager::MemoryBuffer buffer = edk::MemoryManager::treeRemoved.getBufferInPosition(newSize,0u);
                        edk::MemoryManager::MemoryPositions pos = edk::MemoryManager::treeRemoved.popPosInPosition(newSize,0u);
                        //create the new alloc
                        newAlloc.start = pos.start;
                        newAlloc.end = pos.start+size;
                        newAlloc.pointer = pointer;
                        newAlloc.buffer = buffer;
                        if(edk::MemoryManager::treeAlloc.add(newAlloc)){
                            ret = (edk::classID)newAlloc.start;
                            //increment start
                            pos.start+=size;
                            pos.buffer = buffer;
                            //add the new position into the tree
                            edk::MemoryManager::treeRemoved.newPosition(pos);
                        }
                    }
                }
            }
        }
        if(!ret){
            //get the buffer from the stack
            edk::MemoryManager::MemoryBuffer buffer = edk::MemoryManager::stackBuffers.get(edk::MemoryManager::bufferLastPosition);
            if(buffer.buffer && buffer.positionLast){
                if(size<((edk::uint64)edk::MemoryManager::bufferSize -
                         ((edk::uint64)buffer.positionLast
                          - (edk::uint64)buffer.buffer)
                         )
                        ){
                    //allod the memory and return the buffer
                    edk::MemoryManager::MemoryPointer newAlloc;
                    newAlloc.start = (edk::uint64)buffer.positionLast;
                    newAlloc.end = (edk::uint64)buffer.positionLast+size;
                    newAlloc.pointer = pointer;
                    if(edk::MemoryManager::treeAlloc.add(newAlloc)){
                        buffer.positionLast=(edk::classID)newAlloc.end;
                        ret = (edk::classID)newAlloc.start;
                    }
                }
                else if(recursive){
                    //set the last memory ass removed in the tree
                    edk::MemoryManager::MemoryPositions pos;
                    pos.start = (edk::uint64)buffer.positionLast;
                    buffer.positionLast = (edk::classID)((edk::uint64)buffer.buffer + edk::MemoryManager::bufferSize);
                    pos.end = (edk::uint64)buffer.positionLast;
                    pos.buffer = buffer;
                    //add the new position into the tree
                    edk::MemoryManager::treeRemoved.newPosition(pos);

                    //neeed realloc the memory
                    if(edk::MemoryManager::newBuffer()){
                        //alloc the new image
                        ret = edk::MemoryManager::privateAlloc(size,pointer,--recursive);
                    }
                }
            }
        }
    }
    //test what is the last position
    return ret;
}

//create a new buffer
bool edk::MemoryManager::cleanAndNewBuffer(edk::uint64 size){
    edk::MemoryManager::cleanBuffers();
    edk::MemoryManager::mut.lock();
    if(size){
        //create a new buffer
        edk::MemoryManager::MemoryBuffer buffer;
        buffer.buffer = (edk::classID)malloc(size);
        if(buffer.buffer){
            buffer.positionLast = buffer.buffer;
            edk::uint32 stackSize = edk::MemoryManager::stackBuffers.size();
            edk::MemoryManager::stackBuffers.pushBack(buffer);
            if(stackSize<edk::MemoryManager::stackBuffers.size()){
                edk::MemoryManager::bufferSize=size;
                edk::MemoryManager::bufferLastPosition = stackSize;
                edk::MemoryManager::mut.unlock();
                return true;
            }
            free(buffer.buffer);
        }
    }
    edk::MemoryManager::mut.unlock();
    return false;
}
bool edk::MemoryManager::newBuffer(){
    edk::MemoryManager::mut.lock();
    if(edk::MemoryManager::bufferSize){
        //create a new buffer
        edk::MemoryManager::MemoryBuffer buffer;
        buffer.buffer = (edk::classID)malloc(edk::MemoryManager::bufferSize);
        if(buffer.buffer){
            buffer.positionLast = buffer.buffer;
            edk::uint32 stackSize = edk::MemoryManager::stackBuffers.size();
            edk::MemoryManager::stackBuffers.pushBack(buffer);
            if(stackSize<edk::MemoryManager::stackBuffers.size()){
                edk::MemoryManager::bufferLastPosition = stackSize;
                edk::MemoryManager::mut.unlock();
                return true;
            }
            free(buffer.buffer);
        }
    }
    edk::MemoryManager::mut.unlock();
    return false;
}
bool edk::MemoryManager::cleanBuffers(){
    edk::MemoryManager::mut.lock();
    if(edk::MemoryManager::bufferSize){
        //can clean buffers
        edk::MemoryManager::MemoryBuffer buffer;
        edk::uint32 size = edk::MemoryManager::stackBuffers.size();
        for(edk::uint32 i=0u;i<size;i++){
            buffer = edk::MemoryManager::stackBuffers.get(i);
            if(buffer.buffer){
                free(buffer.buffer);
            }
        }
        edk::MemoryManager::stackBuffers.clean();
        edk::MemoryManager::mut.unlock();
        return true;
    }
    edk::MemoryManager::mut.unlock();
    return false;
}
edk::uint64 edk::MemoryManager::size(){
    edk::uint64 ret;
    edk::MemoryManager::mut.lock();
    ret = edk::MemoryManager::bufferSize * edk::MemoryManager::stackBuffers.size();
    edk::MemoryManager::mut.unlock();
    return ret;
}

//set the memory with zeros
bool edk::MemoryManager::setZeros(edk::uint32 position){
    edk::MemoryManager::mut.lock();
    if(position < edk::MemoryManager::stackBuffers.size() && edk::MemoryManager::bufferSize){
        //
        edk::MemoryManager::MemoryBuffer buffer = edk::MemoryManager::stackBuffers.get(position);
        if(buffer.buffer){
            edkMemSet(buffer.buffer,0,edk::MemoryManager::bufferSize);
            edk::MemoryManager::mut.unlock();
            return true;
        }
    }
    edk::MemoryManager::mut.unlock();
    return false;
}
bool edk::MemoryManager::setZerosAllBuffers(){
    edk::MemoryManager::mut.lock();
    if(edk::MemoryManager::stackBuffers.size() && edk::MemoryManager::bufferSize){
        edk::MemoryManager::mut.unlock();
        edk::MemoryManager::MemoryBuffer buffer;
        edk::uint32 size = edk::MemoryManager::stackBuffers.size();
        for(edk::uint32 i=0u;i<size;i++){
            buffer = edk::MemoryManager::stackBuffers.get(i);
            if(buffer.buffer){
                edkMemSet(buffer.buffer,0,edk::MemoryManager::bufferSize);
            }
        }
        edk::MemoryManager::mut.unlock();
        return true;
    }
    edk::MemoryManager::mut.unlock();
    return false;
}

//free the memory
bool edk::MemoryManager::freeMemory(edk::classID pointer){
    edk::MemoryManager::mut.lock();
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
            pos.buffer = temp.buffer;
            if(edk::MemoryManager::treeRemoved.newPosition(pos)){
                if(edk::MemoryManager::treeAlloc.remove(temp)){
                    //add it into the tree removed
                    edk::MemoryManager::mut.unlock();
                    return true;
                }
            }
        }
    }
    edk::MemoryManager::mut.unlock();
    return false;
}
