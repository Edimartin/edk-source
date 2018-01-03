#ifndef EDK_VECTOR_STACK_H
#define EDK_VECTOR_STACK_H

/*
Library Stack - Create a Stack in EDK Game Engine
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
#warning "Inside Stack"
#endif

#pragma once
//Include the array
#include "Array.h"
#include "BinaryTree.h"

#ifdef printMessages
#warning "    Compiling Stack"
#endif

//Size of the arrays in the Stack
#define PatternArraySize 10u

/*

Create a multiple array

*/

namespace edk{
namespace vector{


//NEXT CEL
template <class typeTemplate>
class StackCel : public edk::vector::Array<typeTemplate>{
    //
public:
    //construtor
    StackCel(){
        //clean the next
        this->next=NULL;
        this->previous=NULL;
    }
    StackCel(edk::uint32 size){
        //clean the next
        this->next=NULL;
        this->previous=NULL;
        //
        this->createArray(size);
    }
    //Destrutor
    ~StackCel(){
        //clean the next
        this->next=NULL;
        this->previous=NULL;
    }

    //Next array
    edk::vector::StackCel<typeTemplate>* next;
    edk::vector::StackCel<typeTemplate>* previous;
};

template <class typeTemplate>
class Stack{
public:
    //Construtor
    Stack(){
        //clean the vectors
        this->canDeleteVector=true;
        this->first=NULL;
        this->end=NULL;
        this->stackSize=0u;
        this->deleteLastCel=NULL;
        this->StackArraySize=PatternArraySize;
    }
    //Construtor with arraySize
    Stack(edk::uint32 arraySize){
        //clean the vectors
        this->canDeleteVector=true;
        this->first=NULL;
        this->end=NULL;
        this->stackSize=0u;
        this->deleteLastCel=NULL;
        //Test if the arraySize is bigger then zero
        if(arraySize){
            //
            this->StackArraySize=arraySize;
        }
        else{
            //else set the Pattern
            this->StackArraySize=PatternArraySize;
        }
    }
    //Destrutor
    ~Stack(){
        //delete the array
        if(this->canDeleteVector){
            //clean
            this->clean();
            //
            this->first=NULL;
            this->end=NULL;
            this->stackSize=0u;
            this->deleteLastCel=NULL;
            this->canDeleteVector=false;
        }
        else{
            this->removed.cantDestruct();
        }
        //
        this->canDeleteVector=true;
        /*
            //clean
            this->clean();
            //
            this->first=NULL;
            this->end=NULL;
            this->stackSize=0u;
            this->deleteLastCel=NULL;
            */
    }

    //ADDS
    //pushBack the object
    edk::uint32 pushBack(typeTemplate obj){
        //First test if need delete the last array
        if(this->deleteLastCel){
            //delete the array.
            delete this->deleteLastCel;
        }
        this->deleteLastCel=NULL;

        //test if have a removed
        if(this->removed.haveRoot()){
            //then set the obj in the root
            edk::uint32 tempRoot = this->removed.getRootValue();
            //test if can remove root
            if(this->removed.remove(tempRoot)){
                //then set the value
                this->set(tempRoot,obj);

                //return the pos
                return tempRoot;
            }
        }

        //else add in the end
        if(this->end){
            //get the position of the last obj
            edk::uint32 lastPos = this->stackSize%StackArraySize;
            if(!(lastPos)){
                //then create a new array
                if((this->createNewArray())){
                    //add the obj
                    this->end->set(lastPos,obj);
                    //increment the size
                    this->stackSize++;
                    return this->stackSize-1u;
                }
            }
            else{
                //add the obj in the position
                this->end->set(lastPos,obj);
                //increment the size
                this->stackSize++;
                return this->stackSize-1u;
            }
        }
        //test if have a first
        else if(this->first){
            //then corrige the end
            this->end=this->first;
        }
        else{
            //else create a new array
            if((this->createNewArray())){
                //test if have a end
                if(this->end){
                    //then add the obj
                    this->end->set(stackSize,obj);
                    //increment the size
                    this->stackSize++;
                    return 0u;
                }
                //else something is wrong
            }
        }
        //else return false
        return 0u;
    }

    //DELETE
    //Remove the top
    typeTemplate popBack(){
        //First test if need delete the last array
        if(this->deleteLastCel){
            //delete the array.
            delete this->deleteLastCel;
        }
        this->deleteLastCel=NULL;

        //the return
        typeTemplate ret=(typeTemplate)0u;
        bool getRet=false;

        //test if have elements on the Stack
        //remove the last element
        do{
            if(this->stackSize){
                //decrement the stackSize to get the last position
                this->stackSize--;

                //calculate the position of the last element
                edk::uint32 arrayPos = this->stackSize%StackArraySize;
                //test if don't have the elements
                if(this->removed.haveElement(this->stackSize)){
                    //then remove
                    this->removed.remove(this->stackSize);
                }
                else{
                    //else return the element
                    if(!getRet){
                        ret = this->end->get(arrayPos);
                        getRet = true;
                    }
                    else{
                        break;
                    }
                }
                //test if need delete the end
                if(!arrayPos){
                    edk::vector::StackCel<typeTemplate>* temp = end;
                    if(this->end->previous){
                        this->end = this->end->previous;
                        this->end->next = NULL;
                    }
                    else{
                        if(this->first != this->end){
                            delete this->first;
                        }
                        this->first = this->end = NULL;
                    }
                    delete temp;
                }
            }
            else break;
        }while(!this->havePos(this->stackSize-1u));

        //else return false
        return ret;
    }
    //delete all Stack
    void deleteStack(){
        //clean
        this->clean();
    }
    //clean the Stack
    void clean(){
        //First test if need delete the last array
        if(this->deleteLastCel){
            //delete the array.
            delete this->deleteLastCel;
        }
        this->deleteLastCel=NULL;

        //Then clean
        this->stackSize=0u;
        //test if have a first
        if(this->first){
            //then clean from the first
            while(this->first){
                //create a temp
                edk::vector::StackCel<typeTemplate> *temp;
                //copy the next to the temp
                temp= this->first->next;
                //delete the first
                delete this->first;
                //set the first
                this->first=temp;
            }
        }
        //test if have a end
        else if(this->end){
            //then clean from the end
            while(this->end){
                //create a temp
                edk::vector::StackCel<typeTemplate> *temp;
                //copy the previous to the temp
                temp= this->first->previous;
                //delete the end
                delete this->end;
                //set the end
                this->end=temp;
            }
        }
        this->first=NULL;
        this->end=NULL;

        //clean the removed's
        this->removed.clean();
        //this->canDeleteVector=false;
    }
    //Clean changing the Stack ArraySize
    void clean(edk::uint32 arraySize){
        //
        this->clean();
        if(arraySize){
            //
            this->StackArraySize=arraySize;
        }
        else{
            //else set the Pattern
            this->StackArraySize=PatternArraySize;
        }
    }

    //remove the element
    typeTemplate remove(edk::uint32 pos){
        //Test if don't have the element
        if(this->havePos(pos)){
            //tets if pos is the last
            if(pos==this->stackSize-1u){
                //then popBack
                return this->popBack();
            }
            //get the element value
            typeTemplate ret = this->get(pos);
            //then clean the pos
            if(this->set(pos,0u)){
                //and add the pos in to removed
                this->removed.add(pos);

                //return the ret
                return ret;
            }
        }
        //else return false
        typeTemplate ret;
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
        return ret;
        #pragma GCC diagnostic pop
    }

    //SETTERS
    bool set(edk::uint32 pos,typeTemplate obj){
        //test if have the pos
        if(this->havePos(pos)){
            //get the position in the Stack
            edk::uint32 StackPos = pos/StackArraySize;
            edk::uint32 arrayPos = pos%StackArraySize;
            //create a temp
            edk::vector::StackCel<typeTemplate> *temp=this->first;
            //then find the value
            for(edk::uint32 i=0u;i<StackPos;i++){
                //
                if(temp->next)
                    temp=temp->next;
                else
                    break;
            }
            //set the object
            if(temp){
                //
                return temp->set(arrayPos,obj);
            }
        }
        //else return NULL
        return false;
    }

    //GETTERS
    //get the object
    typeTemplate get(edk::uint32 pos){
        //test if have the pos
        if(this->havePos(pos)){
            //get the position in the Stack
            edk::uint32 StackPos = pos/StackArraySize;
            edk::uint32 arrayPos = pos%StackArraySize;
            //create a temp
            edk::vector::StackCel<typeTemplate> *temp=this->first;
            //then find the value
            for(edk::uint32 i=0u;i<StackPos;i++){
                //
                if(temp->next)
                    temp=temp->next;
                else
                    break;
            }
            //return the object
            if(temp){
                //
                return temp->get(arrayPos);
            }
        }
        //else return false
        typeTemplate ret;
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
        return ret;
        #pragma GCC diagnostic pop
    }
    //get the size
    edk::uint32 getSize(){
        //
        return this->size();
    }
    //return the size
    edk::uint32 size(){
        //
        return this->stackSize;
    }
    edk::uint32 sizeRemoved(){
        return this->removed.size();
    }

    //test if have the pos
    bool havePos(edk::uint32 pos){
        //test if the pos is less then size
        if(pos<this->stackSize){
            //then test if don't have the pos in removed
            if(!this->removed.haveElement(pos)){
                //then return true
                return true;
            }
        }
        //else return false
        return false;
    }
    //find the position of the object
    edk::uint32 find(typeTemplate obj){
        //Just find the object

        //test the size
        if(this->stackSize){
            //then find the object
            for(edk::uint32 i=0u;i<this->stackSize;i++){
                //test if have the object
                if(this->havePos(i)){
                    //test the obj
                    if(this->get(0u)==obj){
                        //then return the i
                        return i;
                    }
                }
            }
        }
        //else return 0u;
        return 0u;
    }

    //SWAP two objects
    bool swap(edk::uint32 pos1,edk::uint32 pos2){
        //first test if have the two objects
        if(pos1<this->stackSize && pos2<this->stackSize){
            //then test if have the objects
            bool have1 = this->havePos(pos1);
            bool have2 = this->havePos(pos2);

            //remove the 1 and 2 from the removed's
            this->removed.remove(pos1);
            this->removed.remove(pos2);

            //then switch
            typeTemplate temp = this->get(pos1);
            this->set(pos1,this->get(pos2));
            this->set(pos2,temp);

            //put the new removed's
            if(!have1){
                //
                this->removed.add(pos2);
                if(!have2){
                    //
                    this->removed.add(pos1);
                }
            }
            else if(!have2){
                //
                this->removed.add(pos1);
            }
        }
        //else return false
        return false;
    }

    //Move position object
    bool bringPositionPlusOne(edk::uint32 position){
        //test if have the position and if the position is plus zero
        if(this->havePos(position) && position<(this->stackSize-1u)){
            //then swap one front
            return this->swap(position,position+1u);
        }
        //else return false
        return false;
    }
    bool bringPositionMinusOne(edk::uint32 position){
        //test if have the position and if the position is plus zero
        if(this->havePos(position) && position>0u){
            //then swap one front
            return this->swap(position,position-1u);
        }
        //else return false
        return false;
    }
    //Move a count
    bool bringPositionPlusTimes(edk::uint32 position,edk::uint32 times){
        //
        if(this->havePos(position) && this->havePos(position+times)){
            //swap all the positions on the way
            for(edk::uint32 i=position;i<position+times;i++){
                //swap the positions
                this->swap(i,i+1u);
            }
            //return true
            return true;
        }
        //else return false;
        return false;
    }
    bool bringPositionMinusTimes(edk::uint32 position,edk::uint32 times){
        //
        if(this->havePos(position) && position>=times
                && this->havePos(position-times)){
            //swap all the positions on the way
            for(edk::uint32 i=position;i>position-times;i--){
                //swap the positions
                this->swap(i,i-1u);
            }
            //return true
            return true;
        }
        //else return false;
        return false;
    }
    bool bringPositionTo(edk::uint32 position,edk::uint32 position2){
        //test if the position is plus or minus
        if(position2>position){
            //position2 is plus
            return this->bringPositionPlusTimes(position,position2-position);
        }
        else{
            //position2 is minus
            return this->bringPositionMinusTimes(position,position-position2);
        }
        //else return false
        return false;
    }

    //cant
    void cantDestroy(){
        //
        this->canDeleteVector=false;
    }

    //OPERATORS
    //[] //To return the object in the pos
    typeTemplate operator[](edk::uint32 pos){
        //
        return this->get(pos);
    }
    //= //To create a copy of the Stack
    edk::vector::Stack<typeTemplate> operator=(edk::vector::Stack<typeTemplate> ret){
        //clean the vector
        this->clean();
        //copy the types from the ret
        for(edk::uint32 i=0u;i<ret.size();i++){
            //copy
            this->pushBack(ret[i]);
        }
        ret.cantDestroy();
        return ret;
    }


protected:
private:
    //Have the first cel
    edk::vector::StackCel<typeTemplate>* first;
    //Have the next cel
    edk::vector::StackCel<typeTemplate>* end;
    //set to delete the last Cel
    edk::vector::StackCel<typeTemplate>* deleteLastCel;

    //Have a binary of the removed positions
    edk::vector::BinaryTree<edk::uint32> removed;

    //size of the Stack
#if defined(__arch64__) || defined(_LP64)
    edk::uint64 stackSize;
#elif defined(__arch32__) || defined(_LP32)
    edk::uint32 stackSize;
#else
    //another system
    edk::uint32 stackSize;
#endif

    //Size of the array on the stack
    edk::uint32 StackArraySize;
    //test if can delete the vector
    bool canDeleteVector;

    //Create a new array
    bool createNewArray(){
        //First test if need delete the last array
        if(this->deleteLastCel){
            //delete the array.
            delete this->deleteLastCel;
        }
        this->deleteLastCel=NULL;

        //test if have a end
        if(this->end){
            //then create a next in the end
            if((this->end->next =new edk::vector::StackCel<typeTemplate>(StackArraySize))){
                //set the previous
                this->end->next->previous=this->end;
                //set the end
                this->end = this->end->next;
                //return true
                return true;
            }
            //else clean the next
            this->end->next=NULL;
        }
        else{
            //else create the first
            if(this->first){
                //Clean the Stack to make a new Stack
                this->clean();
            }
            if((this->first = new edk::vector::StackCel<typeTemplate>(StackArraySize))){
                //set the end
                this->end=this->first;
                //this->canDeleteVector=true;
                //return true
                return true;
            }
            //clean the first
            this->first=NULL;
        }
        //else return false
        return false;
    }
};
}//end namespace vector
}//end namespace edk

#endif // MUTABLEARRAY_H
