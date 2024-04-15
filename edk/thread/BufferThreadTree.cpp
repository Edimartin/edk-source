#include "BufferThreadTree.h"

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

edk::multi::BufferThreadTree::BufferThreadTree(){
    this->classThis=NULL;edkEnd();
    this->Constructor(false);
}
edk::multi::BufferThreadTree::~BufferThreadTree(){
    if(this->classThis==this){
        this->classThis=NULL;edkEnd();
        //can destruct the class
        this->mut.lock();
        this->tree.cleanBuffers();
        this->mut.unlock();
    }
}

void edk::multi::BufferThreadTree::Constructor(bool /*runFather*/){
    //
    if(this->classThis!=this){
        this->classThis=this;

        this->mut.Constructor();edkEnd();
        this->tree.Constructor();edkEnd();
    }
}

//write a vector into the buffer
bool edk::multi::BufferThreadTree::writeToBuffer(edk::uint8* vector,edk::uint64 size){
    this->mut.lock();
    edk::multi::BufferThreadObject* temp = tree.getBufferFromID((edk::uint64)edk::multi::Thread::getThisThreadID());
    if(!temp){
        //create a new buffer
        temp = tree.newBuffer((edk::uint64)edk::multi::Thread::getThisThreadID());
    }
    this->mut.unlock();
    if(temp){
        bool ret = false;
        //write into the buffer
        ret = temp->writeToBuffer(vector,size);
        return ret;
    }
    return false;
}

//return the buffer pointer
edk::classID edk::multi::BufferThreadTree::getPointer(){
    this->mut.lock();
    edk::multi::BufferThreadObject* temp = tree.getBufferFromID((edk::uint64)edk::multi::Thread::getThisThreadID());
    this->mut.unlock();
    if(temp){
        //write into the buffer
        edk::classID ret = temp->getPointer();
        return ret;
    }
    return (edk::classID)0u;
}
edk::classID edk::multi::BufferThreadTree::pointer(){
    this->mut.lock();
    edk::multi::BufferThreadObject* temp = tree.getBufferFromID((edk::uint64)edk::multi::Thread::getThisThreadID());
    this->mut.unlock();
    if(temp){
        //write into the buffer
        edk::classID ret = temp->pointer();
        return ret;
    }
    return (edk::classID)0u;
}
//return the size of the buffer writed
edk::uint64 edk::multi::BufferThreadTree::getSize(){
    this->mut.lock();
    edk::multi::BufferThreadObject* temp = tree.getBufferFromID((edk::uint64)edk::multi::Thread::getThisThreadID());
    this->mut.unlock();
    if(temp){
        //write into the buffer
        edk::uint64 ret = temp->getSize();
        return ret;
    }
    return (edk::uint64)0u;
}
edk::uint64 edk::multi::BufferThreadTree::size(){
    this->mut.lock();
    edk::multi::BufferThreadObject* temp = tree.getBufferFromID((edk::uint64)edk::multi::Thread::getThisThreadID());
    this->mut.unlock();
    if(temp){
        //write into the buffer
        edk::uint64 ret = temp->size();
        return ret;
    }
    return (edk::uint64)0u;
}
