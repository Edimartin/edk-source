#ifndef QUEUE
#define QUEUE

/*
Library Queue - Create and generate a Queue in EDK Game Engine
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
#include "Array.h"

#ifdef printMessages
#pragma message "    Compiling Array"
#endif

//Size of the arrays in the Stack
#define PatternArraySize 10u

namespace edk{
namespace vector{


//NEXT CEL
template <class typeTemplate>
class QueueCel : public edk::vector::Array<typeTemplate>{
    //
public:
    //construtor
    QueueCel(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    QueueCel(edk::uint32 size){
        this->classThis=NULL;edkEnd();
        this->Constructor(size,false);edkEnd();
    }
    //Destrutor
    ~QueueCel(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            //clean the next
            this->next=NULL;edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::vector::Array<typeTemplate>::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            //clean the next
            this->next=NULL;edkEnd();
        }
    }
    void Constructor(edk::uint32 size,bool runFather=true){
        if(runFather){
            edk::vector::Array<typeTemplate>::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            //clean the next
            this->next=NULL;edkEnd();
            //
            this->createArray(size);edkEnd();
        }
    }

    //Next array
    edk::vector::QueueCel<typeTemplate>* next;
private:
    edk::classID classThis;
};
//Use a template to alloc whatever
template <class typeTemplate>
//The arrayClass

class Queue{
public:
    Queue(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);
    }
    Queue(edk::uint32 size){
        this->classThis=NULL;edkEnd();
        this->Constructor(size,false);
    }
    ~Queue(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            this->clean(10u);
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->first = this->last = NULL;edkEnd();
            this->arraySize = PatternArraySize;edkEnd();
            this->start = this->end = 0u;edkEnd();
            this->_size = 0u;edkEnd();

            //Have the first cel
            this->firstPointer=&this->first;
            this->lastPointer=&this->last;
            this->arraySizePointer=&this->arraySize;
            this->startPointer=&this->start;
            this->endPointer=&this->end;
            this->_sizePointer=&this->_size;
        }
    }
    void Constructor(edk::uint32 size,bool runFather=true){
        if(runFather){edkEnd();}
        if(this->classThis!=this){
            this->classThis=this;
            //
            this->first = this->last = NULL;edkEnd();
            if(size){
                this->arraySize = size;edkEnd();
            }
            else{
                this->arraySize = PatternArraySize;edkEnd();
            }
            this->start = this->end = 0u;edkEnd();
            this->_size = 0u;edkEnd();

            //Have the first cel
            this->firstPointer=&this->first;
            this->lastPointer=&this->last;
            this->arraySizePointer=&this->arraySize;
            this->startPointer=&this->start;
            this->endPointer=&this->end;
            this->_sizePointer=&this->_size;
        }
    }

    //clean the queue
    void clean(edk::uint32 size){
        //test the arraySiIze
        if(size){
            //set the arraySize
            (*this->arraySizePointer)=size;edkEnd();
        }
        else{
            (*this->arraySizePointer)=PatternArraySize;edkEnd();
        }

        //clean the vectors
        edk::vector::QueueCel<typeTemplate>* temp = NULL;edkEnd();
        edk::vector::QueueCel<typeTemplate>* tempDelete = (*this->firstPointer);edkEnd();
        while(tempDelete){
            //
            if(tempDelete->next){
                temp=tempDelete->next;edkEnd();
            }
            else{
                temp=NULL;edkEnd();
            }
            //delete the tempDelete
            delete tempDelete;edkEnd();
            tempDelete = temp;edkEnd();
        }
        (*this->firstPointer)=(*this->lastPointer)=NULL;edkEnd();
    }
    void clean(){
        this->clean((*this->arraySizePointer));
    }

    //push back a value
    bool pushBack(typeTemplate value){
        //test if have the end
        if(!(*this->lastPointer)){
            //create a new first and last
            (*this->firstPointer) = new edk::vector::QueueCel<typeTemplate>((*this->arraySizePointer));edkEnd();
            if((*this->firstPointer)){
                //set the last
                (*this->lastPointer) = (*this->firstPointer);edkEnd();
            }
            (*this->startPointer) = (*this->endPointer) = 0u;edkEnd();
            (*this->_sizePointer) = 0u;edkEnd();
        }
        if((*this->lastPointer)){
            //add the value
            (*this->lastPointer)->set((*this->endPointer),value);edkEnd();
            //increment the end
            (*this->endPointer)++;edkEnd();
            //test if the increment is passing the size
            if((*this->endPointer)>=(*this->arraySizePointer)){
                //create the next last
                (*this->lastPointer)->next = new edk::vector::QueueCel<typeTemplate>((*this->arraySizePointer));edkEnd();
                if((*this->lastPointer)->next){
                    (*this->lastPointer) = (*this->lastPointer)->next;edkEnd();
                }
                (*this->endPointer)=0u;edkEnd();
            }
            (*this->_sizePointer)++;edkEnd();
            return true;
        }
        return false;
    }

    //pop front
    typeTemplate popFront(){
        typeTemplate ret;edkEnd();
        memset(&ret,0,sizeof(typeTemplate));
        //test if have the first
        if((*this->firstPointer)){
            //test if the first and the last are equal
            if((*this->firstPointer)==(*this->lastPointer)){
                //only get the value if the start is smaller then the end
                if((*this->startPointer)<(*this->endPointer)){
                    //get the value
                    ret = (*this->firstPointer)->get((*this->startPointer));edkEnd();
                    //increment the start
                    (*this->startPointer)++;edkEnd();
                    if((*this->_sizePointer)){
                        (*this->_sizePointer)--;
                    }
                }
                if((*this->startPointer)>=(*this->endPointer)){
                    //get the last value. Delete the cel's
                    delete first;edkEnd();
                    (*this->firstPointer) = (*this->lastPointer) = NULL;edkEnd();
                    (*this->startPointer) = (*this->endPointer) = 0u;edkEnd();
                    (*this->_sizePointer) = 0u;edkEnd();
                }
            }
            else{
                //get the value
                ret = (*this->firstPointer)->get((*this->startPointer));edkEnd();
                //increment the start
                (*this->startPointer)++;edkEnd();
                (*this->_sizePointer)--;edkEnd();

                //test if reach the end
                if((*this->startPointer)>=(*this->arraySizePointer)){
                    //delete the first and go to the next
                    edk::vector::QueueCel<typeTemplate>* temp = (*this->firstPointer);edkEnd();
                    (*this->firstPointer) = (*this->firstPointer)->next;edkEnd();
                    delete temp;edkEnd();
                    (*this->startPointer) = 0u;edkEnd();


                    //tes if reach the last
                    if((*this->firstPointer)==(*this->lastPointer) && !(*this->endPointer)){
                        //delete the first and last
                        delete first;edkEnd();
                        (*this->firstPointer) = (*this->lastPointer) = NULL;edkEnd();
                        (*this->startPointer) = (*this->endPointer) = 0u;edkEnd();
                        (*this->_sizePointer) = 0u;edkEnd();
                    }
                }
            }
        }
        return ret;
    }

    //GETTERS
    //return the vector size
    edk::uint32  size(){
        return (*this->_sizePointer);edkEnd();
    }
    edk::uint32  getSize(){
        return this->size();edkEnd();
    }
    //return the value in a position
    typeTemplate get(edk::uint32 pos){
        typeTemplate ret;edkEnd();
        memset(&ret,0,sizeof(typeTemplate));
        //first test if have the first cell
        if((*this->firstPointer) && pos<(*this->_sizePointer)){
            //test if the position is in the first cel
            if((pos+(*this->startPointer))<(*this->arraySizePointer)){
                //get the value
                memcpy(&ret,(edk::classID)&(*this->firstPointer)->getPointer()[(*this->startPointer)+pos],sizeof(typeTemplate));
            }
            else{
                pos-=(*this->arraySizePointer)-(*this->startPointer);edkEnd();
                //else search for the value in other cel's
                edk::vector::QueueCel<typeTemplate>* temp = (*this->firstPointer)->next;edkEnd();
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
                        temp=temp->next;edkEnd();
                        pos-=(*this->arraySizePointer);edkEnd();
                    }
                }
            }
        }
        return ret;
    }

protected:
private:
    //Have the first cel
    edk::vector::QueueCel<typeTemplate>** firstPointer;
    edk::vector::QueueCel<typeTemplate>* first;
    //Have the next cel
    edk::vector::QueueCel<typeTemplate>** lastPointer;
    edk::vector::QueueCel<typeTemplate>* last;
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
    edk::classID classThis;
};

}//end namespace vector
}//end namespace edk

#endif // QUEUE

