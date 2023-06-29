#include "MemoryBuffer.h"

/*
Library C++ MemoryBuffer - Use a buffer in RAM memory
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

edk::MemoryBuffer::MemoryBuffer(){
    //
    this->buffer=NULL;
    this->bufferSize=0u;
    this->bufferWritedSize=0u;
}
edk::MemoryBuffer::~MemoryBuffer(){
    this->clean();
}

//clean the buffer
void edk::MemoryBuffer::clean(){
    if(this->buffer && this->bufferSize){
        free(this->buffer);
        this->buffer=NULL;
        this->bufferSize=0u;
        this->bufferWritedSize=0u;
    }
}

//save some bytes in the buffer
bool edk::MemoryBuffer::writeToBuffer(edk::uint8* vector,edk::uint64 size){
    if(vector && size){
        //test if the size is bigger then biffer size
        if(size>this->bufferSize){
            //clean the buffer and create another
            this->clean();
            this->buffer = (edk::uint8*)malloc((size+1u) * sizeof(edk::uint8));
            if(!this->buffer){
                //if it's null then return false
                return false;
            }
            //else set the size
            this->bufferSize = size;
        }
        if(this->buffer && this->bufferSize >= size){
            //copy the vector to buffer
            edkMemCpy(this->buffer,vector,size);
            this->bufferWritedSize=size;
            if(this->bufferSize>this->bufferWritedSize){
                this->buffer[this->bufferWritedSize]=0u;
            }
            return true;
        }
    }
    return false;
}

//return the buffer pointer
edk::classID edk::MemoryBuffer::getPointer(){
    return (edk::classID)this->buffer;
}
edk::classID edk::MemoryBuffer::pointer(){
    return (edk::classID)this->buffer;
}
//return the size of the buffer writed
edk::uint64 edk::MemoryBuffer::getSize(){
    return this->bufferWritedSize;
}
edk::uint64 edk::MemoryBuffer::size(){
    return this->bufferWritedSize;
}
