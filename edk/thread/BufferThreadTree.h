#ifndef BUFFERTHREADTREE_H
#define BUFFERTHREADTREE_H

/*
Library C++ BufferThreadTree - Save thread buffers into a tree to alloc buffers in memory
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
#pragma message "Inside BufferThreadTree"
#endif

#pragma once
#include "../DebugFile.h"
#include "../MemoryBuffer.h"
#include "../vector/BinaryTree.h"
#include "../thread/Thread.h"
#include "../thread/Mutex.h"

#ifdef printMessages
#pragma message "    Compiling BufferThreadTree"
#endif

namespace edk{
namespace multi{
//object to save the thread ID and the buffer
class BufferThreadObject : public edk::MemoryBuffer<edk::uint8>{
public:
    BufferThreadObject(){this->classThis=NULL;this->Constructor(false);edkEnd();}
    BufferThreadObject(edk::uint64 id){this->classThis=NULL;this->Constructor(id,false);edkEnd();}
    virtual ~BufferThreadObject(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            edk::MemoryBuffer<edk::uint8>::clean();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::MemoryBuffer<edk::uint8>::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->id=0u;
        }
    }
    void Constructor(edk::uint64 id,bool runFather=true){
        if(runFather){
            edk::MemoryBuffer<edk::uint8>::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->id=id;
        }
    }

    //thread ID
    edk::uint64 id;
private:
    edk::classID classThis;
};
class BufferThreadTree{
public:
    BufferThreadTree();
    virtual ~BufferThreadTree();

    void Constructor(bool runFather=true);

    //write a vector into the buffer
    bool writeToBuffer(edk::uint8* vector,edk::uint64 size);

    //return the buffer pointer
    edk::classID getPointer();
    edk::classID pointer();
    //return the size of the buffer writed
    edk::uint64 getSize();
    edk::uint64 size();
private:
    edk::multi::Mutex mut;
    //tree to save the buffer
    class TreeBuffers : public edk::vector::BinaryTree<edk::multi::BufferThreadObject*>{
    public:
        TreeBuffers(){this->classThis=NULL;this->Constructor(false);edkEnd();}
        virtual ~TreeBuffers(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
            }
        }

        void Constructor(bool runFather=true){
            if(runFather){edkEnd();}
            if(this->classThis!=this){
                this->classThis=this;

                this->templateBuffer.Constructor();edkEnd();
            }
        }

        //write a new buffer
        virtual bool firstBiggerSecond(edk::multi::BufferThreadObject* first,edk::multi::BufferThreadObject* second){
            if(first->id>second->id){
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::multi::BufferThreadObject* first,edk::multi::BufferThreadObject* second){
            if(first->id==second->id){
                return true;
            }
            return false;
        }
        void cleanBuffers(){
            edk::multi::BufferThreadObject* temp = NULL;
            edk::uint32 size = this->size();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    delete temp;
                }
            }
            this->clean();
        }
        //delete the buffer
        bool deleteBuffer(edk::uint64 id){
            edk::multi::BufferThreadObject* temp = this->getBufferFromID(id);
            if(temp){
                if(this->remove(temp)){
                    delete temp;
                    return true;
                }
            }
            return false;
        }
        //add a new buffer
        edk::multi::BufferThreadObject* newBuffer(edk::uint64 id){
            if(!this->haveBufferFromID(id)){
                edk::multi::BufferThreadObject* temp = new edk::multi::BufferThreadObject(id);
                if(temp){
                    if(this->add(temp)){
                        return temp;
                    }
                    else{
                        delete temp;
                    }
                }
            }
            return NULL;
        }
        //return if have the buffer
        bool haveBufferFromID(edk::uint64 id){
            this->templateBuffer.id = id;
            return this->haveElement(&this->templateBuffer);
        }
        //return the buffer
        edk::multi::BufferThreadObject* getBufferFromID(edk::uint64 id){
            this->templateBuffer.id = id;
            return this->getElement(&this->templateBuffer);
        }
    private:
        edk::multi::BufferThreadObject templateBuffer;
    private:
        edk::classID classThis;
    };
    edk::multi::BufferThreadTree::TreeBuffers tree;
private:
    edk::classID classThis;
};
}//end namespace multi
}//end namespace edk

#endif // BUFFERTHREADTREE_H
