#ifndef MEMORYBUFFERCIRCULAR_H
#define MEMORYBUFFERCIRCULAR_H

/*
Library C++ MemoryBufferCircular - Use a circular buffer in RAM memory
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
#pragma message "Inside MemoryBufferCircular"
#endif

#pragma once
#include "MemoryBuffer.h"

#ifdef printMessages
#pragma message "    Compiling MemoryBufferCircular"
#endif

namespace edk{
template <class typeTemplate>
class MemoryBufferCircular : public edk::MemoryBuffer<typeTemplate>{
public:
    MemoryBufferCircular(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~MemoryBufferCircular(){
        this->Destructor();
    }

    void Constructor(){
        edk::MemoryBuffer<typeTemplate>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->origin=0u;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
        edk::MemoryBuffer<typeTemplate>::Destructor();
    }

    //increment the origin position
    void incrementOrigin(edk::uint32 position=1u){
        this->origin+=position;
        if(this->origin >= this->bufferSize){
            this->origin-=this->bufferSize;
        }
    }

    //operator to return the value in position
    virtual inline typeTemplate operator[](edk::uint64 index){
        if(index < this->bufferSize){
            //calculate the new position
            index += this->origin;
            if(index >= this->bufferSize){
                index-=this->bufferSize;
            }
            return this->buffer[index];
        }
        typeTemplate ret;
        memset(&ret,0u,sizeof(typeTemplate));
        return ret;
    }
private:
    //position where is the origin
    edk::uint32 origin;
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // MEMORYBUFFERCIRCULAR_H
