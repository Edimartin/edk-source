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
#include "vector/BinaryTree.h"
#include "vector/StackStatic.h"
#include "thread/Mutex.h"

#ifdef printMessages
#pragma message "    Compiling MemoryManager"
#endif


namespace edk{
enum MemoryValues{
    zero =0uL,
    kilo =1024uL,
    mega =1024uL*1024uL,
    giga =1024uL*1024uL*1024uL,
    tera =1024uL*1024uL*1024uL*1024uL,
    MemoryValueSize
};
class MemoryPiece{
public:
    MemoryPiece(){
        this->classThis=NULL;
        this->Constructor();
    }
    ~MemoryPiece(){
        this->Destructor();
    }
    void Constructor(){
        if(this->classThis!=this){
            this->classThis = this;
            this->bufferStart=0uL;
            this->bufferEnd=0uL;
            this->bufferSize=0uL;}
    }
    void Destructor(){
        if(this->classThis == this){
            this->classThis=NULL;
            this->tree.clean();
        }
    }

    inline bool operator==(edk::MemoryPiece memory){
        if(this->bufferStart == memory.bufferStart
                && this->bufferEnd == memory.bufferEnd
                ){
            return true;
        }
        return false;
    }
    inline bool operator>(edk::MemoryPiece memory){
        if(this->bufferStart > memory.bufferStart
                && this->bufferEnd > memory.bufferEnd
                ){
            return true;
        }
        return false;
    }

    inline bool retain(edk::classID pointerClass){
        if(pointerClass){
            return this->tree.add(pointerClass);
        }
        return false;
    }
    inline bool release(edk::classID pointerClass){
        if(pointerClass){
            return this->tree.remove(pointerClass);
        }
        return false;
    }
    inline edk::uint32 size(){
        return this->tree.size();
    }
    edk::uint64 bufferStart;
    edk::uint64 bufferEnd;
    edk::uint64 bufferSize;
private:
    edk::vector::BinaryTree<edk::classID> tree;
private:
    edk::classID classThis;
};
class MemoryUser{
public:
    MemoryUser(){
        this->pointer=NULL;
        this->user=0uL;
    }
    ~MemoryUser(){}
    inline bool operator==(edk::MemoryUser memory){
        if(this->user == memory.user){
            return true;
        }
        return false;
    }
    inline bool operator>(edk::MemoryUser memory){
        if(this->user > memory.user){
            return true;
        }
        return false;
    }
    edk::MemoryPiece* pointer;
    edk::classID user;
};
class MemoryManager{
public:
    MemoryManager();
    MemoryManager(edk::uint64 size);
    virtual ~MemoryManager();

    void constructor();
    void constructor(edk::uint64 size);
    void destructor();

    bool deleteBuffer();

    bool newBuffer(edk::uint64 size);

    bool haveBuffer();

    void cleanUsage();

    template <class typeTemplate>
    bool newVec(typeTemplate** pointer,edk::uint64 lenght){
        return this->newVec((edk::classID*)pointer,lenght);
    }
    bool newVec(edk::classID* pointer,edk::uint64 lenght);
    template <class typeTemplate>
    bool newObject(typeTemplate** pointer){
        if(pointer){
            if(this->newVec(pointer,sizeof(typeTemplate))){
                return true;
            }
        }
        return false;
    }
    template <class typeTemplate>
    bool retain(typeTemplate** pointerClassDest,typeTemplate** pointerClassSource){
        return this->retain((edk::classID*)pointerClassDest,(edk::classID*)pointerClassSource);
    }
    bool  retain(edk::classID* pointerClassDest,edk::classID* pointerClassSource);
    template <class typeTemplate>
    bool release(typeTemplate** pointerClass){
        return this->release((edk::classID*) pointerClass);
    }
    bool release(edk::classID* pointerClass);
protected:
    inline bool canDestroyThis(){
        if(this->classThis == this){
            return true;
        }
        return false;
    }
private:
    edk::uint8* buffer;
    edk::uint64 size;
    //positions
    edk::uint64 posStart,posEnd;

    //binaryTree with the memory

    class TreeMemorys : public edk::vector::BinaryTree<edk::MemoryPiece*>{
    public:
        TreeMemorys(){}
        ~TreeMemorys(){}
        void cleanMemorys(){
            edk::uint32 size = this->size();
            edk::MemoryPiece* temp;
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    delete temp;
                }
            }
            this->clean();
        }
        bool deleteMemory(edk::MemoryPiece* memory){
            if(memory){
                if(this->remove(memory)){
                    delete memory;
                    return true;
                }
            }
            return false;
        }
        bool deleteMemory(edk::uint64 bufferStart,edk::uint64 bufferEnd){
            edk::MemoryPiece* temp = this->getMemoryPiece(bufferStart,bufferEnd);
            if(temp){
                return this->deleteMemory(temp);
            }
            return false;
        }
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::MemoryPiece* first,edk::MemoryPiece* second){
            if(*first>*second){
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::MemoryPiece* first,edk::MemoryPiece* second){
            if(*first==*second){
                return true;
            }
            return false;
        }

        edk::MemoryPiece* newMemory(edk::uint64 bufferStart,edk::uint64 bufferEnd,edk::classID pointer){
            edk::MemoryPiece* temp = new edk::MemoryPiece;
            if(temp){
                temp->bufferStart=bufferStart;
                temp->bufferEnd=bufferEnd;
                temp->bufferSize=bufferEnd - bufferStart;
                temp->retain(pointer);
                if(this->add(temp)){
                    return temp;
                }
                delete temp;
            }
            return NULL;
        }
    private:
        edk::MemoryPiece* getMemoryPiece(edk::uint64 bufferStart,edk::uint64 bufferEnd){
            this->templatePointer.bufferStart = bufferStart;
            this->templatePointer.bufferEnd = bufferEnd;
            return this->getElement(&this->templatePointer);
        }
        edk::MemoryPiece templatePointer;
    }treeUsing,treeFree;
    //class to save the users
    class TreeUsers : public edk::vector::BinaryTree<edk::MemoryUser>{
    public:
        TreeUsers(){}
        ~TreeUsers(){}
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::MemoryUser first,edk::MemoryUser second){
            if(first>second){
                //
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::MemoryUser first,edk::MemoryUser second){
            if(first==second){
                //
                return true;
            }
            return false;
        }
        bool addUser(edk::classID user,edk::MemoryPiece* pointer){
            if(user && pointer){
                this->templateUser.user=user;
                this->templateUser.pointer=pointer;
                return this->add(this->templateUser);
            }
            return false;
        }
        bool removeUser(edk::classID user,edk::MemoryPiece* pointer){
            if(user && pointer){
                this->templateUser.user=user;
                this->templateUser.pointer=pointer;
                return this->remove(this->templateUser);
            }
            return false;
        }
        bool removeUser(edk::classID user){
            if(user){
                this->templateUser.user=user;
                this->templateUser.pointer=NULL;
                return this->remove(this->templateUser);
            }
            return false;
        }
        edk::MemoryPiece* getUserPointer(edk::classID user){
            if(user){
                this->templateUser.user=user;
                this->templateUser.pointer=NULL;
                this->templateUser = this->getElement(this->templateUser);
                return this->templateUser.pointer;
            }
            return NULL;
        }
        edk::MemoryUser templateUser;
    }treeUsers;
private:
    edk::classID classThis;
};
}
#endif // MEMORYMANAGER_H
