#ifndef MEMORYBUFFER_H
#define MEMORYBUFFER_H

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

#ifdef printMessages
#pragma message "Inside MemoryBuffer"
#endif

#pragma once
#include "DebugFile.h"
#include "TypeVars.h"
#include "String.h"

#ifdef printMessages
#pragma message "    Compiling MemoryBuffer"
#endif

namespace edk{
template <class typeTemplate>
class MemoryBuffer{
public:
    MemoryBuffer(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~MemoryBuffer(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->buffer=NULL;
            this->bufferSize=0u;
            this->bufferWritedSize=0u;
            this->lenghtToReturn=8u;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->clean();
        }
    }

    //clean the buffer
    void clean(){
        if(this->buffer && this->bufferSize){
            free(this->buffer);
            this->buffer=NULL;
            this->bufferSize=0u;
            this->bufferWritedSize=0u;
        }
    }
    //clean the write into the buffer
    bool cleanWrite(){
        if(this->buffer && this->bufferSize){
            this->bufferWritedSize=0u;
            return true;
        }
        return false;
    }

    //save some bytes into the buffer
    bool writeToBuffer(typeTemplate c){
        return this->writeToBuffer((typeTemplate*)&c,1u);
    }
    bool writeToBuffer(typeTemplate* vector,edk::uint64 size){
        if(vector && size){
            this->allocBuffer(size);
            if(this->buffer && this->bufferSize >= size){
                //copy the vector to buffer
                edkMemCpy(this->buffer,vector,sizeof(typeTemplate)*size);
                this->bufferWritedSize=size;
                if(this->bufferSize>this->bufferWritedSize){
                    this->buffer[this->bufferWritedSize]=0u;
                }
                return true;
            }
        }
        return false;
    }
    bool writeFileFullToBuffer(edk::File* file){
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
    bool writeFileToBuffer(edk::File* file){
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
    bool writeFileToBuffer(edk::File* file,edk::uint64 size){
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

    //push some bytes into the buffer
    bool pushToBuffer(typeTemplate c){
        return this->pushToBuffer((typeTemplate*)&c,1u);
    }
    bool pushToBuffer(typeTemplate* vector,edk::uint64 size){
        if(vector && size){
            this->reallocBuffer(size);
            if(this->buffer && this->bufferSize >= size){
                //copy the vector to buffer
                edkMemCpy(&this->buffer[this->bufferWritedSize],vector,sizeof(typeTemplate)*size);
                this->bufferWritedSize+=size;
                if(this->bufferSize>this->bufferWritedSize){
                    this->buffer[this->bufferWritedSize]=0u;
                }
                return true;
            }
        }
        return false;
    }
    bool pushFileFullToBuffer(edk::File* file){
        if(file){
            edk::uint64 size = file->getFileSize();
            if(size){
                edk::uint64 seek = file->getSeek64();
                bool ret=false;
                file->seekStart64();
                if(this->pushFileToBuffer(file,size)){
                    ret=true;
                }
                file->seek(seek);
                return ret;
            }
        }
        return false;
    }
    bool pushFileToBuffer(edk::File* file){
        if(file){
            edk::uint64 size = file->getFileSize() - file->getSeek64();
            if(size){
                if(this->pushFileToBuffer(file,size)){
                    return true;
                }
            }
        }
        return false;
    }
    bool pushFileToBuffer(edk::File* file,edk::uint64 size){
        if(file && size){
            //create the new buffer
            edk::uint64 seek = file->getSeek64();
            if((file->getFileSize() - seek) >= size){
                this->reallocBuffer(size);
                if(this->buffer && this->bufferSize >= size){
                    //copy the vector to buffer
                    if(file->readBin(&this->buffer[this->bufferWritedSize],size)){
                        this->bufferWritedSize+=size;
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
    void setLenghtToReturn(edk::uint8 lenght){
        this->lenghtToReturn=lenght;
    }
    edk::uint8 getLenghtToReturn(){
        return this->lenghtToReturn;
    }

    //return true if have the buffer
    bool haveBuffer(){
        return (this->buffer && this->bufferSize);
    }
    //return the buffer pointer
    edk::classID getPointer(){
        return (edk::classID)this->buffer;
    }
    edk::classID pointer(){
        return (edk::classID)this->buffer;
    }
    typeTemplate* getPointerStr(){
        return (edk::char8*)this->buffer;
    }
    typeTemplate* pointerStr(){
        return (edk::char8*)this->buffer;
    }
    //return the size of the buffer writed
    edk::uint64 getSize(){
        return this->bufferWritedSize;
    }
    edk::uint64 size(){
        return this->bufferWritedSize;
    }

    //copy from buffer
    edk::uint64 memCopy(edk::classID dest,edk::uint64 position,edk::uint64 size){
        if(dest && size && position<this->bufferSize){
            if(size<this->bufferSize-position){
                edkMemCpy(dest,&this->buffer[position],sizeof(typeTemplate)*size);
                return size;
            }
        }
        return 0u;
    }
    edk::uint64 memCopy(edk::classID dest,edk::uint64 size){
        return this->memCopy(dest,0u,size);
    }
    edk::uint64 memCopy(edk::classID dest){
        return this->memCopy(dest,0u,this->getSize());
    }
    edk::uint64 memCopy(edk::MemoryBuffer<typeTemplate>* dest,edk::uint64 position,edk::uint64 size){
        if(dest && position<this->getSize()){
            if(size<=this->getSize()-position){
                //alloc the buffer
                dest->allocBuffer(size);
                if(dest->haveBuffer()){
                    edkMemCpy(dest->buffer,&this->buffer[position],sizeof(typeTemplate)*size);
                    dest->bufferWritedSize=size;
                    return size;
                }
            }
        }
        return 0u;
    }
    edk::uint64 memCopy(edk::MemoryBuffer<typeTemplate>* dest,edk::uint64 size){
        return memCopy(dest,0u,size);
    }
    edk::uint64 memCopy(edk::MemoryBuffer<typeTemplate>* dest){
        return memCopy(dest,0u,this->getSize());
    }

    //print the buffer
    bool printHex(edk::uint64 size){
        if(size && size<=this->bufferWritedSize && this->haveBuffer()){
            typeTemplate temp;
            edk::uint8 lenght = 0u;
            for(edk::uint64 i=0u;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));
                this->printElementHEX(temp);
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;
                    printf("\n");
                }
                else{
                    lenght++;
                }
            }
            fflush(stdout);
            return true;
        }
        return false;
    }
    bool printHex(){
        return this->printHex(this->getSize());
    }
    bool printHexFromPosition(edk::uint64 position,edk::uint64 size){
        if(size && (size+position)<=this->bufferWritedSize && this->haveBuffer()){
            typeTemplate temp;
            edk::uint8 lenght = 0u;
            size += position;
            for(edk::uint64 i=position;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));
                this->printElementHEX(temp);
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;
                    printf("\n");
                }
                else{
                    lenght++;
                }
            }
            fflush(stdout);
            return true;
        }
        return false;
    }
    bool printHexFromPosition(edk::uint64 position){
        if(position<this->bufferWritedSize){
            return this->printHexFromPosition(position,this->getSize() - position);
        }
        return false;
    }
    bool printChar(edk::uint64 size){
        if(size && size<=this->bufferWritedSize && this->haveBuffer()){
            typeTemplate temp;
            edk::uint8 lenght = 0u;
            for(edk::uint64 i=0u;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));
                this->printElementChar(temp);
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;
                    printf("\n");
                }
                else{
                    lenght++;
                }
            }
            fflush(stdout);
            return true;
        }
        return false;
    }
    bool printChar(){
        return this->printChar(this->getSize());
    }
    bool printCharFromPosition(edk::uint64 position,edk::uint64 size){
        if(size && (size+position)<=this->bufferWritedSize && this->haveBuffer()){
            typeTemplate temp;
            edk::uint8 lenght = 0u;
            size += position;
            for(edk::uint64 i=position;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));
                this->printElementChar(temp);
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;
                    printf("\n");
                }
                else{
                    lenght++;
                }
            }
            fflush(stdout);
            return true;
        }
        return false;
    }
    bool printCharFromPosition(edk::uint64 position){
        return this->printCharFromPosition(position,this->getSize() - position);
    }
    bool printLetters(edk::uint64 size){
        if(size && size<=this->bufferWritedSize && this->haveBuffer()){
            typeTemplate temp;
            edk::uint8 lenght = 0u;
            for(edk::uint64 i=0u;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));
                this->printElementLetter(temp);
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;
                    printf("\n");
                }
                else{
                    lenght++;
                }
            }
            fflush(stdout);
            return true;
        }
        return false;
    }
    bool printLetters(){
        return this->printLetters(this->getSize());
    }
    bool printLettersFromPosition(edk::uint64 position,edk::uint64 size){
        if(size && (size+position)<=this->bufferWritedSize && this->haveBuffer()){
            typeTemplate temp;
            edk::uint8 lenght = 0u;
            size += position;
            for(edk::uint64 i=position;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));
                this->printElementLetter(temp);
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;
                    printf("\n");
                }
                else{
                    lenght++;
                }
            }
            fflush(stdout);
            return true;
        }
        return false;
    }
    bool printLettersFromPosition(edk::uint64 position){
        return this->printLettersFromPosition(position,this->getSize() - position);
    }
    bool printStr(){
        if(this->bufferWritedSize){
            printf("%s",this->buffer);fflush(stdout);
            return true;
        }
        return false;
    }
    //operator to return the value in position
    virtual inline typeTemplate operator[](edk::uint64 index){
        if(index < this->bufferSize){
            return this->buffer[index];
        }
        typeTemplate ret;
        memset(&ret,0u,sizeof(typeTemplate));
        return ret;
    }
protected:
    //buffer memory
    typeTemplate* buffer;
    edk::uint64 bufferSize;
    edk::uint64 bufferWritedSize;

    void printElement(typeTemplate element){
        edk::uint64 value=0uL;
        edk::uint32 size = sizeof(typeTemplate);
        if(sizeof(value)<size){
            size = sizeof(value);
        }
        edkMemCpy(&value,&element,size);
        printf("%08x",(edk::uint32)(((edk::uint32*)&value))[1u]);
        printf("%08x ",(edk::uint32)value);
    }
    void printElementHEX(typeTemplate element){
        edk::uint8 value=0uL;
        edkMemCpy(&value,&element,sizeof(value));
        printf("%02x ",(edk::uint32)value);
    }
    void printElementChar(typeTemplate element){
        edk::char8 value;
        edk::uint32 size = sizeof(typeTemplate);
        if(sizeof(value)<size){
            size = sizeof(value);
        }
        edkMemCpy(&value,&element,size);
        printf("%c",value);
    }
    void printElementLetter(typeTemplate element){
        edk::uint8 value=0uL;
        edkMemCpy(&value,&element,sizeof(value));
        if(value>31 && value<127){
            printf("%c",(edk::uint32)value);
        }
        else{
            printf(".");
        }
    }

private:
    //lenghtToReturn
    edk::uint8 lenghtToReturn;

    //function to alloc or realloc the buffer
    void allocBuffer(edk::uint64 size){
        //test if the size is bigger then biffer size
        if(size>this->bufferSize){
            //clean the buffer and create another
            this->clean();
            this->buffer = (typeTemplate*)malloc((size+1u) * sizeof(typeTemplate));
            if(!this->buffer){
                //if it's null then return false
                return;
            }
            this->buffer[size]=0u;
            //else set the size
            this->bufferSize = size;
        }
    }
    void reallocBuffer(edk::uint64 size){
        if(this->haveBuffer()){
            edk::uint64 newWritedSize = this->bufferWritedSize;
            edk::uint64 newSize = newWritedSize+size;
            //test if the size is bigger then biffer size
            if(newSize>this->bufferSize && this->buffer){
                typeTemplate* newBuffer;
                newBuffer = (typeTemplate*)malloc((newSize+1u) * sizeof(typeTemplate));
                if(!newBuffer){
                    //if it's null then return false
                    this->clean();
                    return;
                }
                newBuffer[newSize] = 0u;
                //copy the last buffer
                edkMemCpy(newBuffer,this->buffer,this->bufferWritedSize * sizeof(typeTemplate));
                this->clean();
                //copy the new pointer
                this->buffer = newBuffer;
                this->bufferSize = newSize;
                this->bufferWritedSize = newWritedSize;
            }
        }
        else{
            this->allocBuffer(size);
        }
    }
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // MEMORYBUFFER_H
