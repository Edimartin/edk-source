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

#ifdef printMessages
#warning "    Compiling Array"
#endif

namespace edk{
namespace vector{
//Use a template to alloc whatever
template <class typeTemplate>
//The arrayClass
class Queue{
public:
    Queue(){
        //
        this->vector=NULL;
        this->deleteQueue();
    }
    Queue(edk::uint32 size){
        //
        this->vector=NULL;

        //create the array
        this->createQueue(size);
    }
    ~Queue(){
        //delete the array
        if(this->canDeleteVector){
            //
            this->deleteQueue();
            this->canDeleteVector=false;
        }
        else{
            //
            this->canDeleteVector=true;
        }
    }

    //create the array
    bool createQueue(edk::uint32 size){
        //first delete
        this->deleteQueue();

        //Test the size
        if(size){
            size++;
            //create the new array
            if( ( this->vector = new typeTemplate[size] ) ){
                //save the size of the vector
                this->vectorSize=size;
                //can delete the vector
                this->canDeleteVector=true;
                //return true
                return true;
            }
        }
        //else return false
        return false;
    }
    //clean the queue
    void clean(){
        this->start=this->end=0u;
    }

    //push back a value
    bool pushBack(typeTemplate value){
        if(this->vector){
            //set the position
            this->vector[this->end] = value;
            //increment the end
            this->end++;
            //test if reach the end
            if(this->end>=this->vectorSize){
                //end receive 0u
                this->end=0u;
            }
            //test if the end reach the start
            if(this->end==this->start){
                //remove the start value
                this->remove(this->vector[this->start]);
                //push the start
                this->start++;
                if(this->start>=this->vectorSize){
                    this->start=0u;
                }
            }
            return true;
        }
        return false;
    }

    //pop front
    bool popFront(){
        if(this->vector){
            //test if the start reach the end
            if(this->start==this->end){
                //return false
                return false;
            }
            //else remove the value
            this->remove(this->vector[this->start]);
            this->start++;
            //test if the start reach the end of the vector
            if(this->start>=this->vectorSize){
                //start receive zero
                this->start=0u;
            }
            return true;
        }
        return false;
    }

    //GETTERS
    //returrn the vector size
    edk::uint32  size(){
        if(this->end>this->start){
            return this->end - this->start;
        }
        else if(this->end<this->start){
            return (this->vectorSize - this->start) + this->end;
        }
        return 0;
    }
    edk::uint32  getSize(){
        //return the full size of the queue
        return this->size();
    }
    //test if have the object in the position
    bool have(edk::uint32 pos){
        if(this->vector && pos<this->getSize()){
            //return the variable
            return true;
        }
        return false;
    }
    //return the object
    typeTemplate get(edk::uint32 pos){
        typeTemplate ret;
        //test if have the position
        if(this->have(pos)){
            edk::uint32 position = this->start+pos;
            //test if reach the end
            if(position>=this->vectorSize){
                position-=this->vectorSize;
            }
            //return the value
            return this->vector[position];
        }
        return ret;
    }

    //delete the queue
    void deleteQueue(){
        this->clean();
        //test if is alloc
        if(this->vector){
            //
            delete[] vector;
        }
        vector=NULL;
        vectorSize=0u;
        this->canDeleteVector=false;
    }

    //cant
    void cantDeleteVector(){
        //
        this->canDeleteVector=false;
    }

    //remove the value
    virtual void remove(typeTemplate){
        //
    }

protected:
private:
    //the vector
    typeTemplate* vector;
    //size of the vector
    edk::uint32 vectorSize;
    //positions
    edk::uint32 start,end;
    //test if can delete the vector
    bool canDeleteVector;
};
}//end namespace vector
}//end namespace edk

#endif // QUEUE

