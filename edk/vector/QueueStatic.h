#ifndef QUEUESTATIC_H
#define QUEUESTATIC_H

/*
Library QueueStatic - Create and generate a QueueStatic in EDK Game Engine
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
#pragma message "Inside Array"
#endif

#pragma once
#include <stdio.h>
#include <string.h>
#include "../TypeVars.h"
#include "ArrayStatic.h"

#ifdef printMessages
#pragma message "    Compiling Array"
#endif

//Size of the arrays in the Stack
#define PatternArraySize 10u

namespace edk{
namespace vector{


//NEXT CEL
template <class typeTemplate>
class QueueStaticCel : public edk::vector::ArrayStatic<typeTemplate>{
    //
public:
    //Construtor
    QueueStaticCel(){}
    //Destrutor
    virtual ~QueueStaticCel(){
        this->Destructor();
    }


    //construtor
    void Constructor(){
        edk::vector::ArrayStatic<typeTemplate>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            //clean the next
            this->next=NULL;
        }
    }
    void Constructor(edk::uint32 size){
        edk::vector::ArrayStatic<typeTemplate>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            //clean the next
            this->next=NULL;
            //
            this->createArray(size);
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            //clean the next
            this->next=NULL;
            edk::vector::ArrayStatic<typeTemplate>::Destructor();
        }
        edk::vector::ArrayStatic<typeTemplate>::Destructor();
    }

    //Next array
    edk::vector::QueueStaticCel<typeTemplate>* next;
private:
    edk::classID classThis;
};
//Use a template to alloc whatever
template <class typeTemplate>
//The arrayClass

class QueueStatic{
public:
    QueueStatic(){
        this->classThis=NULL;
        this->Constructor();
    }
    QueueStatic(edk::uint32 size){
        this->classThis=NULL;
        this->Constructor(size);
    }
    virtual ~QueueStatic(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->first = this->last = NULL;
            this->arraySize = PatternArraySize;
            this->start = this->end = 0u;
            this->_size = 0u;

            //Have the first cel
            this->firstPointer=&this->first;
            this->lastPointer=&this->last;
            this->arraySizePointer=&this->arraySize;
            this->startPointer=&this->start;
            this->endPointer=&this->end;
            this->_sizePointer=&this->_size;
        }
    }
    void Constructor(edk::uint32 size){
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->first = this->last = NULL;
            if(size){
                this->arraySize = size;
            }
            else{
                this->arraySize = PatternArraySize;
            }
            this->start = this->end = 0u;
            this->_size = 0u;

            //Have the first cel
            this->firstPointer=&this->first;
            this->lastPointer=&this->last;
            this->arraySizePointer=&this->arraySize;
            this->startPointer=&this->start;
            this->endPointer=&this->end;
            this->_sizePointer=&this->_size;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->clean(10u);
        }
    }

    //clean the queue
    void clean(edk::uint32 size){
        //test the arraySiIze
        if(size){
            //set the arraySize
            (*this->arraySizePointer)=size;
        }
        else{
            (*this->arraySizePointer)=PatternArraySize;
        }

        //clean the vectors
        edk::vector::QueueStaticCel<typeTemplate>* temp = NULL;
        edk::vector::QueueStaticCel<typeTemplate>* tempDelete = (*this->firstPointer);
        while(tempDelete){
            //
            if(tempDelete->next){
                temp=tempDelete->next;
            }
            else{
                temp=NULL;
            }
            //delete the tempDelete
            tempDelete->Destructor();
            delete tempDelete;
            tempDelete = temp;
        }
        (*this->firstPointer)=(*this->lastPointer)=NULL;
    }
    void clean(){
        this->clean((*this->arraySizePointer));
    }

    //push back a value
    bool pushBack(typeTemplate value){
        //test if have the end
        if(!(*this->lastPointer)){
            //create a new first and last
            (*this->firstPointer) = new edk::vector::QueueStaticCel<typeTemplate>();
            if((*this->firstPointer)){
                (*this->firstPointer)->Constructor((*this->arraySizePointer));
                //set the last
                (*this->lastPointer) = (*this->firstPointer);
            }
            (*this->startPointer) = (*this->endPointer) = 0u;
            (*this->_sizePointer) = 0u;
        }
        if((*this->lastPointer)){
            //add the value
            (*this->lastPointer)->set((*this->endPointer),value);
            //increment the end
            (*this->endPointer)++;
            //test if the increment is passing the size
            if((*this->endPointer)>=(*this->arraySizePointer)){
                //create the next last
                (*this->lastPointer)->next = new edk::vector::QueueStaticCel<typeTemplate>();
                if((*this->lastPointer)->next){
                    (*this->lastPointer)->next->Constructor((*this->arraySizePointer));
                    (*this->lastPointer) = (*this->lastPointer)->next;
                }
                (*this->endPointer)=0u;
            }
            (*this->_sizePointer)++;
#if defined(EDK_DEBUG_VECTOR)
            edkWriteClassDebugNoPosition(this,this->generateDebugValue(&value),true);
#endif
            return true;
        }
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebugNoPosition(this,this->generateDebugValue(&value),false);
#endif
        return false;
    }

    //pop front
    typeTemplate popFront(){
        typeTemplate ret;
        memset(&ret,0,sizeof(typeTemplate));
        //test if have the first
        if((*this->firstPointer)){
            //test if the first and the last are equal
            if((*this->firstPointer)==(*this->lastPointer)){
                //only get the value if the start is smaller then the end
                if((*this->startPointer)<(*this->endPointer)){
                    //get the value
                    ret = (*this->firstPointer)->get((*this->startPointer));
                    //increment the start
                    (*this->startPointer)++;
                    if((*this->_sizePointer)){
                        (*this->_sizePointer)--;
                    }
                }
                if((*this->startPointer)>=(*this->endPointer)){
                    //get the last value. Delete the cel's
                    (*this->firstPointer)->Destructor();
                    delete (*this->firstPointer);
                    (*this->firstPointer) = (*this->lastPointer) = NULL;
                    (*this->startPointer) = (*this->endPointer) = 0u;
                    (*this->_sizePointer) = 0u;
                }
            }
            else{
                //get the value
                ret = (*this->firstPointer)->get((*this->startPointer));
                //increment the start
                (*this->startPointer)++;
                if((*this->_sizePointer)){
                    (*this->_sizePointer)--;
                }

                //test if reach the end
                if((*this->startPointer)>=(*this->arraySizePointer)){
                    //delete the first and go to the next
                    edk::vector::QueueStaticCel<typeTemplate>* temp = (*this->firstPointer);
                    (*this->firstPointer) = (*this->firstPointer)->next;
                    temp->Destructor();
                    delete temp;
                    (*this->startPointer) = 0u;


                    //tes if reach the last
                    if((*this->firstPointer)==(*this->lastPointer) && !(*this->endPointer)){
                        //delete the first and last
                        (*this->firstPointer)->Destructor();
                        delete (*this->firstPointer);
                        (*this->firstPointer) = (*this->lastPointer) = NULL;
                        (*this->startPointer) = (*this->endPointer) = 0u;
                        (*this->_sizePointer) = 0u;
                    }
                }
            }
        }
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebugNoPosition(this,this->generateDebugValue(&ret),true);
#endif
        return ret;
    }

    //GETTERS
    //return the vector size
    edk::uint32  size(){
        return (*this->_sizePointer);
    }
    edk::uint32  getSize(){
        return this->size();
    }
    //return the value in a position
    typeTemplate get(edk::uint32 pos){
        typeTemplate ret;
        memset(&ret,0,sizeof(typeTemplate));
        //first test if have the first cell
        if((*this->firstPointer) && pos<(*this->_sizePointer)){
            //test if the position is in the first cel
            if((pos+(*this->startPointer))<(*this->arraySizePointer)){
                //get the value
                memcpy(&ret,(edk::classID)&(*this->firstPointer)->getPointer()[(*this->startPointer)+pos],sizeof(typeTemplate));
            }
            else{
                pos-=(*this->arraySizePointer)-(*this->startPointer);
                //else search for the value in other cel's
                edk::vector::QueueStaticCel<typeTemplate>* temp = (*this->firstPointer)->next;
                while(temp){
                    //test if the value is in this cel
                    if(pos<(*this->arraySizePointer)){
                        if(temp==(*this->lastPointer)){
                            if(pos<(*this->endPointer)){
                                memcpy(&ret,(edk::classID)&temp->getPointer()[pos],sizeof(typeTemplate));
                                break;
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            memcpy(&ret,(edk::classID)&temp->getPointer()[pos],sizeof(typeTemplate));
                            break;
                        }
                    }
                    else{
                        //else go to the next
                        temp=temp->next;
                        pos-=(*this->arraySizePointer);
                    }
                }
            }
        }
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebug(this,pos,this->generateDebugValue(&ret),true);
#endif
        return ret;
    }

protected:
private:
    //Have the first cel
    edk::vector::QueueStaticCel<typeTemplate>** firstPointer;
    edk::vector::QueueStaticCel<typeTemplate>* first;
    //Have the next cel
    edk::vector::QueueStaticCel<typeTemplate>** lastPointer;
    edk::vector::QueueStaticCel<typeTemplate>* last;
    //save the array size
    edk::uint32 *arraySizePointer;
    edk::uint32 arraySize;
    //positions in the vector
    edk::uint32 *startPointer,*endPointer;
    edk::uint32 start,end;

    //save the queue size
    edk::uint32* _sizePointer;
    edk::uint32 _size;
private:
#if defined(EDK_DEBUG_VECTOR)
    inline edk::uint64 generateDebugValue(typeTemplate* value){
        edk::uint64 newValue=0uL;
        if(sizeof(typeTemplate)>=sizeof(newValue)){
            memcpy((void*)&newValue,(void*)value,sizeof(newValue));
        }
        else{
            memcpy((void*)&newValue,(void*)value,sizeof(typeTemplate));
        }
        return newValue;
    }
#endif
private:
    edk::classID classThis;
};

}//end namespace vector
}//end namespace edk

#endif // QUEUESTATIC_H
