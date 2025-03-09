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
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    virtual ~MemoryBuffer(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            this->clean();edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->buffer=NULL;edkEnd();
            this->bufferSize=0u;edkEnd();
            this->bufferWritedSize=0u;edkEnd();
            this->lenghtToReturn=8u;edkEnd();
        }
    }

    //clean the buffer
    void clean(){
        if(this->buffer && this->bufferSize){
            free(this->buffer);edkEnd();
            this->buffer=NULL;edkEnd();
            this->bufferSize=0u;edkEnd();
            this->bufferWritedSize=0u;edkEnd();
        }
    }
    //clean the write into the buffer
    bool cleanWrite(){
        if(this->buffer && this->bufferSize){
            this->bufferWritedSize=0u;edkEnd();
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
            this->allocBuffer(size);edkEnd();
            if(this->buffer && this->bufferSize >= size){
                //copy the vector to buffer
                edkMemCpy(this->buffer,vector,sizeof(typeTemplate)*size);edkEnd();
                this->bufferWritedSize=size;edkEnd();
                if(this->bufferSize>this->bufferWritedSize){
                    this->buffer[this->bufferWritedSize]=0u;edkEnd();
                }
                return true;
            }
        }
        return false;
    }
    bool writeFileFullToBuffer(edk::File* file){
        if(file){
            edk::uint64 size = file->getFileSize();edkEnd();
            if(size){
                edk::uint64 seek = file->getSeek64();edkEnd();
                bool ret=false;
                file->seekStart64();edkEnd();
                if(this->writeFileToBuffer(file,size)){
                    ret=true;edkEnd();
                }
                file->seek(seek);edkEnd();
                return ret;
            }
        }
        return false;
    }
    bool writeFileToBuffer(edk::File* file){
        if(file){
            edk::uint64 size = file->getFileSize() - file->getSeek64();edkEnd();
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
            edk::uint64 seek = file->getSeek64();edkEnd();
            if((file->getFileSize() - seek) >= size){
                this->allocBuffer(size);edkEnd();
                if(this->buffer && this->bufferSize >= size){
                    //copy the vector to buffer
                    if(file->readBin(this->buffer,size)){
                        this->bufferWritedSize=size;edkEnd();
                        if(this->bufferSize>this->bufferWritedSize){
                            this->buffer[this->bufferWritedSize]=0u;edkEnd();
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
            this->reallocBuffer(size);edkEnd();
            if(this->buffer && this->bufferSize >= size){
                //copy the vector to buffer
                edkMemCpy(&this->buffer[this->bufferWritedSize],vector,sizeof(typeTemplate)*size);edkEnd();
                this->bufferWritedSize+=size;edkEnd();
                if(this->bufferSize>this->bufferWritedSize){
                    this->buffer[this->bufferWritedSize]=0u;edkEnd();
                }
                return true;
            }
        }
        return false;
    }
    bool pushFileFullToBuffer(edk::File* file){
        if(file){
            edk::uint64 size = file->getFileSize();edkEnd();
            if(size){
                edk::uint64 seek = file->getSeek64();edkEnd();
                bool ret=false;edkEnd();
                file->seekStart64();edkEnd();
                if(this->pushFileToBuffer(file,size)){
                    ret=true;edkEnd();
                }
                file->seek(seek);edkEnd();
                return ret;
            }
        }
        return false;
    }
    bool pushFileToBuffer(edk::File* file){
        if(file){
            edk::uint64 size = file->getFileSize() - file->getSeek64();edkEnd();
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
            edk::uint64 seek = file->getSeek64();edkEnd();
            if((file->getFileSize() - seek) >= size){
                this->reallocBuffer(size);edkEnd();
                if(this->buffer && this->bufferSize >= size){
                    //copy the vector to buffer
                    if(file->readBin(&this->buffer[this->bufferWritedSize],size)){
                        this->bufferWritedSize+=size;edkEnd();
                        if(this->bufferSize>this->bufferWritedSize){
                            this->buffer[this->bufferWritedSize]=0u;edkEnd();
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
        this->lenghtToReturn=lenght;edkEnd();
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
                edkMemCpy(dest,&this->buffer[position],sizeof(typeTemplate)*size);edkEnd();
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
                dest->allocBuffer(size);edkEnd();
                if(dest->haveBuffer()){
                    edkMemCpy(dest->buffer,&this->buffer[position],sizeof(typeTemplate)*size);edkEnd();
                    dest->bufferWritedSize=size;edkEnd();
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
            typeTemplate temp;edkEnd();
            edk::uint8 lenght = 0u;edkEnd();
            for(edk::uint64 i=0u;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));edkEnd();
                this->printElementHEX(temp);edkEnd();
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;edkEnd();
                    printf("\n");edkEnd();
                }
                else{
                    lenght++;edkEnd();
                }
            }
            fflush(stdout);edkEnd();
            return true;
        }
        return false;
    }
    bool printHex(){
        return this->printHex(this->getSize());
    }
    bool printHexFromPosition(edk::uint64 position,edk::uint64 size){
        if(size && (size+position)<=this->bufferWritedSize && this->haveBuffer()){
            typeTemplate temp;edkEnd();
            edk::uint8 lenght = 0u;edkEnd();
            size += position;
            for(edk::uint64 i=position;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));edkEnd();
                this->printElementHEX(temp);edkEnd();
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;edkEnd();
                    printf("\n");edkEnd();
                }
                else{
                    lenght++;edkEnd();
                }
            }
            fflush(stdout);edkEnd();
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
            typeTemplate temp;edkEnd();
            edk::uint8 lenght = 0u;edkEnd();
            for(edk::uint64 i=0u;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));edkEnd();
                this->printElementChar(temp);edkEnd();
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;edkEnd();
                    printf("\n");edkEnd();
                }
                else{
                    lenght++;edkEnd();
                }
            }
            fflush(stdout);edkEnd();
            return true;
        }
        return false;
    }
    bool printChar(){
        return this->printChar(this->getSize());
    }
    bool printCharFromPosition(edk::uint64 position,edk::uint64 size){
        if(size && (size+position)<=this->bufferWritedSize && this->haveBuffer()){
            typeTemplate temp;edkEnd();
            edk::uint8 lenght = 0u;edkEnd();
            size += position;
            for(edk::uint64 i=position;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));edkEnd();
                this->printElementChar(temp);edkEnd();
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;edkEnd();
                    printf("\n");edkEnd();
                }
                else{
                    lenght++;edkEnd();
                }
            }
            fflush(stdout);edkEnd();
            return true;
        }
        return false;
    }
    bool printCharFromPosition(edk::uint64 position){
        return this->printCharFromPosition(position,this->getSize() - position);
    }
    bool printLetters(edk::uint64 size){
        if(size && size<=this->bufferWritedSize && this->haveBuffer()){
            typeTemplate temp;edkEnd();
            edk::uint8 lenght = 0u;edkEnd();
            for(edk::uint64 i=0u;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));edkEnd();
                this->printElementLetter(temp);edkEnd();
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;edkEnd();
                    printf("\n");edkEnd();
                }
                else{
                    lenght++;edkEnd();
                }
            }
            fflush(stdout);edkEnd();
            return true;
        }
        return false;
    }
    bool printLetters(){
        return this->printLetters(this->getSize());
    }
    bool printLettersFromPosition(edk::uint64 position,edk::uint64 size){
        if(size && (size+position)<=this->bufferWritedSize && this->haveBuffer()){
            typeTemplate temp;edkEnd();
            edk::uint8 lenght = 0u;edkEnd();
            size += position;
            for(edk::uint64 i=position;i<size;i++){
                edkMemCpy(&temp,&this->buffer[i],sizeof(typeTemplate));edkEnd();
                this->printElementLetter(temp);edkEnd();
                if(lenght>=this->lenghtToReturn){
                    lenght=0u;edkEnd();
                    printf("\n");edkEnd();
                }
                else{
                    lenght++;edkEnd();
                }
            }
            fflush(stdout);edkEnd();
            return true;
        }
        return false;
    }
    bool printLettersFromPosition(edk::uint64 position){
        return this->printLettersFromPosition(position,this->getSize() - position);
    }
    bool printStr(){
        if(this->bufferWritedSize){
            printf("%s",this->buffer);fflush(stdout);edkEnd();
            return true;
        }
        return false;
    }
    //operator to return the value in position
    virtual inline typeTemplate operator[](edk::uint64 index){
        if(index < this->bufferSize){
            return this->buffer[index];
        }
        typeTemplate ret;edkEnd();
        memset(&ret,0u,sizeof(typeTemplate));edkEnd();
        return ret;
    }
protected:
    //buffer memory
    typeTemplate* buffer;
    edk::uint64 bufferSize;
    edk::uint64 bufferWritedSize;

    void printElement(typeTemplate element){
        edk::uint64 value=0uL;edkEnd();
        edk::uint32 size = sizeof(typeTemplate);edkEnd();
        if(sizeof(value)<size){
            size = sizeof(value);edkEnd();
        }
        edkMemCpy(&value,&element,size);edkEnd();
        printf("%08x",(edk::uint32)(((edk::uint32*)&value))[1u]);edkEnd();
        printf("%08x ",(edk::uint32)value);edkEnd();
    }
    void printElementHEX(typeTemplate element){
        edk::uint8 value=0uL;edkEnd();
        edkMemCpy(&value,&element,sizeof(value));edkEnd();
        printf("%02x ",(edk::uint32)value);edkEnd();
    }
    void printElementChar(typeTemplate element){
        edk::char8 value;edkEnd();
        edk::uint32 size = sizeof(typeTemplate);edkEnd();
        if(sizeof(value)<size){
            size = sizeof(value);edkEnd();
        }
        edkMemCpy(&value,&element,size);edkEnd();
        printf("%c",value);edkEnd();
    }
    void printElementLetter(typeTemplate element){
        edk::uint8 value=0uL;edkEnd();
        edkMemCpy(&value,&element,sizeof(value));edkEnd();
        if(value>31 && value<127){
            printf("%c",(edk::uint32)value);edkEnd();
        }
        else{
            printf(".");edkEnd();
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
            this->clean();edkEnd();
            this->buffer = (typeTemplate*)malloc((size+1u) * sizeof(typeTemplate));edkEnd();
            if(!this->buffer){
                //if it's null then return false
                return;
            }
            this->buffer[size]=0u;
            //else set the size
            this->bufferSize = size;edkEnd();
        }
    }
    void reallocBuffer(edk::uint64 size){
        if(this->haveBuffer()){
            edk::uint64 newWritedSize = this->bufferWritedSize;edkEnd();
            edk::uint64 newSize = newWritedSize+size;edkEnd();
            //test if the size is bigger then biffer size
            if(newSize>this->bufferSize && this->buffer){
                typeTemplate* newBuffer;edkEnd();
                newBuffer = (typeTemplate*)malloc((newSize+1u) * sizeof(typeTemplate));edkEnd();
                if(!newBuffer){
                    //if it's null then return false
                    this->clean();edkEnd();
                    return;
                }
                newBuffer[newSize] = 0u;edkEnd();
                //copy the last buffer
                edkMemCpy(newBuffer,this->buffer,this->bufferWritedSize * sizeof(typeTemplate));edkEnd();
                this->clean();edkEnd();
                //copy the new pointer
                this->buffer = newBuffer;edkEnd();
                this->bufferSize = newSize;edkEnd();
                this->bufferWritedSize = newWritedSize;edkEnd();
            }
        }
        else{
            this->allocBuffer(size);edkEnd();
        }
    }
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // MEMORYBUFFER_H
