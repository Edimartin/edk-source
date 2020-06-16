#ifndef QUEUE
#define QUEUE

/*
Library Queue - Create and generate a Queue in EDK Game Engine
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "Inside Array"
#endif

#pragma once
#include <stdio.h>
#include "../TypeVars.h"
#include "Array.h"

#ifdef printMessages
#warning "    Compiling Array"
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
        //clean the next
        this->next=NULL;
    }
    QueueCel(edk::uint32 size){
        //clean the next
        this->next=NULL;
        //
        this->createArray(size);
    }
    //Destrutor
    ~QueueCel(){
        //clean the next
        this->next=NULL;
    }

    //Next array
    edk::vector::QueueCel<typeTemplate>* next;
};
//Use a template to alloc whatever
template <class typeTemplate>
//The arrayClass

class Queue{
public:
    Queue(){
        //
        this->first = this->last = NULL;
        this->arraySize = PatternArraySize;
        this->start = this->end = 0u;
        this->_size = 0u;
    }
    Queue(edk::uint32 size){
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
    }
    ~Queue(){
    }

    //clean the queue
    void clean(edk::uint32 size){
        //test the arraySiIze
        if(size){
            //set the arraySize
            this->arraySize=size;
        }
        else{
            this->arraySize=PatternArraySize;
        }

        //clean the vectors
        edk::vector::QueueCel<typeTemplate>* temp = NULL;
        edk::vector::QueueCel<typeTemplate>* tempDelete = this->first;
        while(tempDelete){
            //
            if(tempDelete->next){
                temp=tempDelete->next;
            }

            //delete the tempDelete
            delete tempDelete;
            tempDelete = temp;
        }
    }

    //push back a value
    bool pushBack(typeTemplate value){
        //test if have the end
        if(!this->last){
            //create a new first and last
            this->first = new edk::vector::QueueCel<typeTemplate>(this->arraySize);
            if(this->first){
                //set the last
                this->last = this->first;
            }
            this->start = this->end = 0u;
            this->_size = 0u;
        }
        if(this->last){
            //add the value
            this->last->set(this->end,value);
            //increment the end
            this->end++;
            //test if the increment is passing the size
            if(this->end>=this->arraySize){
                //create the next last
                this->last->next = new edk::vector::QueueCel<typeTemplate>(this->arraySize);
                if(this->last->next){
                    this->last = this->last->next;
                }
                this->end=0u;
            }
            this->_size++;
            return true;
        }
        return false;
    }

    //pop front
    typeTemplate popFront(){
        typeTemplate ret;
        //test if have the first
        if(this->first){
            //test if the first and the last are equal
            if(this->first==this->last){
                //only get the value if the start is smaller then the end
                if(this->start<this->end){
                    //get the value
                    ret = this->first->get(this->start);
                    //increment the start
                    this->start++;
                }
                if(this->start>=this->end){
                    //get the last value. Delete the cel's
                    delete first;
                    this->first = this->last = NULL;
                    this->start = this->end = 0u;
                    this->_size = 0u;
                }
            }
            else{
                //get the value
                ret = this->first->get(this->start);
                //increment the start
                this->start++;
                this->_size--;

                //test if reach the end
                if(this->start>=this->arraySize){
                    //delete the first and go to the next
                    edk::vector::QueueCel<typeTemplate>* temp = this->first;
                    this->first = this->first->next;
                    delete temp;
                    this->start = 0u;


                    //tes if reach the last
                    if(this->first==this->last && !this->end){
                        //delete the first and last
                        delete first;
                        this->first = this->last = NULL;
                        this->start = this->end = 0u;
                        this->_size = 0u;
                    }
                }
            }
        }
        return ret;
    }

    //GETTERS
    //returrn the vector size
    edk::uint32  size(){
        return this->_size;
    }
    edk::uint32  getSize(){
        return this->size();
    }
    //return the object
    typeTemplate get(edk::uint32 pos){
        typeTemplate ret;
        //first test if have the first cell
        if(this->first && pos<this->_size){
            //test if the position is in the first cel
            if(pos+this->start<this->arraySize){
                //get the value
                ret = this->first->get(this->start+pos);
            }
            else{
                pos-=this->arraySize-this->start;
                //else search for the value in other cel's
                edk::vector::QueueCel<typeTemplate>* temp = this->first->next;
                while(temp){
                    //test if the value is in this cel
                    if(pos<this->arraySize){
                        if(temp==this->last){
                            if(pos<this->end){
                                ret = temp->get(pos);
                                break;
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            ret = temp->get(pos);
                            break;
                        }
                    }
                    else{
                        //else go to the next
                        temp=temp->next;
                        ret+=this->arraySize;
                        pos-=this->arraySize;
                    }
                }
            }
        }
        return ret;
    }

protected:
private:
    //Have the first cel
    edk::vector::QueueCel<typeTemplate>* first;
    //Have the next cel
    edk::vector::QueueCel<typeTemplate>* last;
    //save the array size
    edk::uint32 arraySize;
    //positions in the vector
    edk::uint32 start,end;

    //save the queue size
    edk::uint32 _size;
};

}//end namespace vector
}//end namespace edk

#endif // QUEUE

