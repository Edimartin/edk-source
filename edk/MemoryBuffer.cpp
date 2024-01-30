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
    this->lenghtToReturn=8u;
}
edk::MemoryBuffer::~MemoryBuffer(){
    this->clean();
}

//function to alloc or realloc the buffer
void edk::MemoryBuffer::allocBuffer(edk::uint64 size){
    //test if the size is bigger then biffer size
    if(size>this->bufferSize){
        //clean the buffer and create another
        this->clean();
        this->buffer = (edk::uint8*)malloc((size+1u) * sizeof(edk::uint8));
        if(!this->buffer){
            //if it's null then return false
            return;
        }
        //else set the size
        this->bufferSize = size;
    }
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
        this->allocBuffer(size);
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
bool edk::MemoryBuffer::writeFileFullToBuffer(edk::File* file){
    if(file){
        edk::uint64 size = file->getFileSize();
        if(size){
            edk::uint64 seek = file->getSeek64();
            bool ret=false;
            file->seekStart64();
            if(this->writeFileToBuffer(file,size)){
                ret=true;
            }
            file->seek(seek);
            return ret;
        }
    }
    return false;
}
bool edk::MemoryBuffer::writeFileToBuffer(edk::File* file){
    if(file){
        edk::uint64 size = file->getFileSize() - file->getSeek64();
        if(size){
            if(this->writeFileToBuffer(file,size)){
                return true;
            }
        }
    }
    return false;
}
bool edk::MemoryBuffer::writeFileToBuffer(edk::File* file,edk::uint64 size){
    if(file && size){
        //create the new buffer
        edk::uint64 seek = file->getSeek64();
        if((file->getFileSize() - seek) >= size){
            this->allocBuffer(size);
            if(this->buffer && this->bufferSize >= size){
                //copy the vector to buffer
                if(file->readBin(this->buffer,size)){
                    this->bufferWritedSize=size;
                    if(this->bufferSize>this->bufferWritedSize){
                        this->buffer[this->bufferWritedSize]=0u;
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

//lenght to return
void edk::MemoryBuffer::setLenghtToReturn(edk::uint8 lenght){
    this->lenghtToReturn=lenght;
}
edk::uint8 edk::MemoryBuffer::getLenghtToReturn(){
    return this->lenghtToReturn;
}

//return true if have the buffer
bool edk::MemoryBuffer::haveBuffer(){
    return (this->buffer && this->bufferSize);
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

//copy from buffer
edk::uint64 edk::MemoryBuffer::memCopy(edk::classID dest,edk::uint64 position,edk::uint64 size){
    if(dest && size && position<this->bufferSize){
        if(size<this->bufferSize-position){
            edkMemCpy(dest,&this->buffer[position],size);
            return size;
        }
    }
    return 0u;
}
edk::uint64 edk::MemoryBuffer::memCopy(edk::classID dest,edk::uint64 size){
    return this->memCopy(dest,0u,size);
}
edk::uint64 edk::MemoryBuffer::memCopy(edk::classID dest){
    return this->memCopy(dest,0u,this->getSize());
}
edk::uint64 edk::MemoryBuffer::memCopy(edk::MemoryBuffer* dest,edk::uint64 position,edk::uint64 size){
    if(dest && position<this->getSize()){
        if(size<=this->getSize()-position){
            //alloc the buffer
            dest->allocBuffer(size);
            if(dest->haveBuffer()){
                edkMemCpy(dest->buffer,&this->buffer[position],size);
                dest->bufferWritedSize=size;
                return size;
            }
        }
    }
    return 0u;
}
edk::uint64 edk::MemoryBuffer::memCopy(edk::MemoryBuffer* dest,edk::uint64 size){
    return memCopy(dest,0u,size);
}
edk::uint64 edk::MemoryBuffer::memCopy(edk::MemoryBuffer* dest){
    return memCopy(dest,0u,this->getSize());
}

//print the buffer
bool edk::MemoryBuffer::printHex(edk::uint64 size){
    if(size && this->haveBuffer()){
        edk::uint8* temp=this->buffer;
        edk::uchar8 n;
        edk::uint8 lenght = 0u;
        for(edk::uint64 i=0u;i<size;i++){
            edkMemCpy(&n,temp,sizeof(edk::uchar8));
            printf("%02x ",n);fflush(stdout);
            temp++;
            lenght++;
            if(lenght>=this->lenghtToReturn){
                lenght=0u;
                printf("\n");
            }
        }
        return true;
    }
    return false;
}
bool edk::MemoryBuffer::printHex(){
    return this->printHex(this->getSize());
}
bool edk::MemoryBuffer::printChar(edk::uint64 size){
    if(size && this->bufferSize){
        edk::uint8* temp=this->buffer;
        edk::char8 c;
        edk::uint8 lenght = 0u;
        for(edk::uint64 i=0u;i<size;i++){
            edkMemCpy(&c,temp,sizeof(edk::char8));
            printf("%c ",c);fflush(stdout);
            temp++;
            lenght++;
            if(lenght>=this->lenghtToReturn){
                lenght=0u;
                printf("\n");
            }
        }
        return true;
    }
    return false;
}
bool edk::MemoryBuffer::printChar(){
    return this->printChar(this->getSize());
}
