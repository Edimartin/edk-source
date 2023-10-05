#ifndef EDK_VECTOR_STACK_H
#define EDK_VECTOR_STACK_H

/*
Library Stack - Create a Stack in EDK Game Engine
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
#pragma message "Inside Stack"
#endif

#pragma once
//Include the array
#include "Array.h"
#include "BinaryTree.h"
#include "../NameClass.h"

#ifdef printMessages
#pragma message "    Compiling Stack"
#endif

//Size of the arrays in the Stack
#define PatternArraySize 10u

/*

Create a multiple array

*/

/*
void loadElement(typeTemplate value){
    //
}
void unloadElement(typeTemplate value){
    //
}
void updateElement(typeTemplate value){
    //
}
void printElement(typeTemplate value){
    //
}
void renderElement(typeTemplate value){
    //
}

bool load(){
    return edk::vector::Stack<typeTemplate>::load();edkEnd();
}
bool unload(){
    return edk::vector::Stack<typeTemplate>::unload();edkEnd();
}
bool update(){
    return edk::vector::Stack<typeTemplate>::update();edkEnd();
}
bool print(){
    return edk::vector::Stack<typeTemplate>::print();edkEnd();
}
bool render(){
    return edk::vector::Stack<typeTemplate>::render();edkEnd();
}
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
        this->next=NULL;edkEnd();
        this->previous=NULL;edkEnd();
    }
    StackCel(edk::uint32 size){
        //clean the next
        this->next=NULL;edkEnd();
        this->previous=NULL;edkEnd();
        //
        this->createArray(size);edkEnd();
    }
    //Destrutor
    ~StackCel(){
        //clean the next
        this->next=NULL;edkEnd();
        this->previous=NULL;edkEnd();
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
        this->canDeleteVector=true;edkEnd();
        this->first=NULL;edkEnd();
        this->end=NULL;edkEnd();
        this->stackSize=0u;edkEnd();
        this->deleteLastCel=NULL;edkEnd();
        this->StackArraySize=PatternArraySize;edkEnd();
    }
    //Construtor with arraySize
    Stack(edk::uint32 arraySize){
        //clean the vectors
        this->canDeleteVector=true;edkEnd();
        this->first=NULL;edkEnd();
        this->end=NULL;edkEnd();
        this->stackSize=0u;edkEnd();
        this->deleteLastCel=NULL;edkEnd();
        //Test if the arraySize is bigger then zero
        if(arraySize){
            //
            this->StackArraySize=arraySize;edkEnd();
        }
        else{
            //else set the Pattern
            this->StackArraySize=PatternArraySize;edkEnd();
        }
    }
    //Destrutor
    virtual ~Stack(){
        //delete the array
        if(this->canDeleteVector){
            //clean
            this->clean();edkEnd();
            //
            this->first=NULL;edkEnd();
            this->end=NULL;edkEnd();
            this->stackSize=0u;edkEnd();
            this->deleteLastCel=NULL;edkEnd();
            this->canDeleteVector=false;edkEnd();
        }
        else{
            this->removed.cantDestruct();edkEnd();
        }
        //
        this->canDeleteVector=true;edkEnd();
    }

    //ADDS
    //pushBack the object
    edk::uint32 pushBack(typeTemplate obj){
        //First test if need delete the last array
        if(this->deleteLastCel){
            //delete the array.
            delete this->deleteLastCel;edkEnd();
        }
        this->deleteLastCel=NULL;edkEnd();

        //test if have a removed
        if(this->removed.haveRoot()){
            //then set the obj in the root
            edk::uint32 tempRoot = this->removed.getRootValue();edkEnd();
            //test if can remove root
            if(this->removed.remove(tempRoot)){
                //then set the value
                this->set(tempRoot,obj);edkEnd();

                //return the pos
                return tempRoot;edkEnd();
            }
        }

        //else add in the end
        if(this->end){
            //get the position of the last obj
            edk::uint32 lastPos = this->stackSize%StackArraySize;edkEnd();
            if(!(lastPos)){
                //then create a new array
                if((this->createNewArray())){
                    //add the obj
                    this->end->set(lastPos,obj);edkEnd();
                    //increment the size
                    this->stackSize++;edkEnd();
                    return this->stackSize-1u;edkEnd();
                }
            }
            else{
                //add the obj in the position
                this->end->set(lastPos,obj);edkEnd();
                //increment the size
                this->stackSize++;edkEnd();
                return this->stackSize-1u;edkEnd();
            }
        }
        //test if have a first
        else if(this->first){
            //then corrige the end
            this->end=this->first;edkEnd();
        }
        else{
            //else create a new array
            if((this->createNewArray())){
                //test if have a end
                if(this->end){
                    //then add the obj
                    this->end->set(stackSize,obj);edkEnd();
                    //increment the size
                    this->stackSize++;edkEnd();
                    return 0u;edkEnd();
                }
                //else something is wrong
            }
        }
        //else return false
        return 0u;edkEnd();
    }

    //DELETE
    //Remove the top
    typeTemplate popBack(){
        //First test if need delete the last array
        if(this->deleteLastCel){
            //delete the array.
            delete this->deleteLastCel;edkEnd();
        }
        this->deleteLastCel=NULL;edkEnd();

        //the return
        typeTemplate ret;edkEnd(); memset((void*)&ret,0u,sizeof(typeTemplate));edkEnd();
        bool getRet=false;edkEnd();

        //test if have elements on the Stack
        //remove the last element
        do{
            if(this->stackSize){
                //decrement the stackSize to get the last position
                this->stackSize--;edkEnd();

                //calculate the position of the last element
                edk::uint32 arrayPos = this->stackSize%StackArraySize;edkEnd();
                //test if don't have the elements
                if(this->removed.haveElement(this->stackSize)){
                    //then remove
                    this->removed.remove(this->stackSize);edkEnd();
                }
                else{
                    //else return the element
                    if(!getRet){
                        //memcpy((void*)&ret,(void*)&this->get(arrayPos),sizeof(typeTemplate));edkEnd();
                        ret = this->get(arrayPos);edkEnd();
                        getRet = true;edkEnd();
                    }
                    else{
                        break;
                    }
                }
                //test if need delete the end
                if(!arrayPos){
                    edk::vector::StackCel<typeTemplate>* temp = end;edkEnd();
                    if(this->end->previous){
                        this->end = this->end->previous;edkEnd();
                        this->end->next = NULL;edkEnd();
                    }
                    else{
                        if(this->first != this->end){
                            delete this->first;edkEnd();
                        }
                        this->first = this->end = NULL;edkEnd();
                    }
                    delete temp;edkEnd();
                }
            }
            else{
                break;
            }
        }while(!this->havePos(this->stackSize-1u));edkEnd();

        //else return false
        return ret;
    }
    //delete all Stack
    void deleteStack(){
        //clean
        this->clean();edkEnd();
    }
    //Copy the values inside the stack to a vector
    bool copyToVector(typeTemplate* vector){
        if(vector){
            edk::uint32 increment=0u;edkEnd();
            edk::vector::StackCel<typeTemplate> *temp=this->first;edkEnd();
            if(temp){
                while(temp){
                    if(!temp->next){
                        edk::uint32 size = this->stackSize - increment;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            //test if have the element
                            if(!this->removed.haveElement(i)){
                                //copy the element
                                vector[0u] = temp->get(i);edkEnd();
                                vector++;edkEnd();
                            }
                        }
                    }
                    else{
                        for(edk::uint32 i=0u;i<this->StackArraySize;i++){
                            //test if have the element
                            if(!this->removed.haveElement(i)){
                                //copy the element
                                vector[0u] = temp->get(i);edkEnd();
                                vector++;edkEnd();
                            }
                        }
                    }
                    temp=temp->next;edkEnd();
                    increment+=this->StackArraySize;edkEnd();
                }
                return true;
            }
            return false;
        }
        return false;
    }
    //clean the Stack
    void clean(){
        //First test if need delete the last array
        if(this->deleteLastCel){
            //delete the array.
            delete this->deleteLastCel;edkEnd();
        }
        this->deleteLastCel=NULL;edkEnd();

        //Then clean
        this->stackSize=0u;edkEnd();
        //test if have a first
        if(this->first){
            //then clean from the first
            while(this->first){
                //create a temp
                edk::vector::StackCel<typeTemplate> *temp;edkEnd();
                //copy the next to the temp
                temp= this->first->next;edkEnd();
                //delete the first
                delete this->first;edkEnd();
                //set the first
                this->first=temp;edkEnd();
            }
        }
        //test if have a end
        else if(this->end){
            //then clean from the end
            while(this->end){
                //create a temp
                edk::vector::StackCel<typeTemplate> *temp;edkEnd();
                //copy the previous to the temp
                temp= this->end->previous;edkEnd();
                //delete the end
                delete this->end;edkEnd();
                //set the end
                this->end=temp;edkEnd();
            }
        }
        this->first=NULL;edkEnd();
        this->end=NULL;edkEnd();

        //clean the removed's
        this->removed.clean();edkEnd();
        //this->canDeleteVector=false;edkEnd();
    }
    //Clean changing the Stack ArraySize
    void clean(edk::uint32 arraySize){
        //
        this->clean();edkEnd();
        if(arraySize){
            //
            this->StackArraySize=arraySize;edkEnd();
        }
        else{
            //else set the Pattern
            this->StackArraySize=PatternArraySize;edkEnd();
        }
    }

    //remove the element
    typeTemplate remove(edk::uint32 pos){
        typeTemplate ret;edkEnd();
        //Test if don't have the element
        if(this->havePos(pos)){
            //tets if pos is the last
            if(pos==this->stackSize-1u){
                //then popBack
                return this->popBack();edkEnd();
            }
            //get the element value
            //memcpy((void*)&ret,(void*)&this->get(arrayPos),sizeof(typeTemplate));edkEnd();
            ret = this->get(pos);edkEnd();
            typeTemplate set;edkEnd(); memset((void*)&set,0u,sizeof(typeTemplate));edkEnd();
            //then clean the pos
            if(this->set(pos,set)){
                //and add the pos in to removed
                this->removed.add(pos);edkEnd();

                //return the ret
                return ret;
            }
            //else clean the ret
        }
        //else return false
        memset((void*)&ret,0u,sizeof(typeTemplate));edkEnd();
        return ret;
    }

    //SETTERS
    bool set(edk::uint32 pos,typeTemplate obj){
        //test if have the pos
        if(this->havePos(pos)){
            //get the position in the Stack
            edk::uint32 StackPos = pos/StackArraySize;edkEnd();
            edk::uint32 arrayPos = pos%StackArraySize;edkEnd();
            //create a temp
            edk::vector::StackCel<typeTemplate> *temp=this->first;edkEnd();
            //then find the value
            for(edk::uint32 i=0u;i<StackPos;i++){
                //
                if(temp->next){
                    temp=temp->next;edkEnd();
                }
                else{
                    break;
                }
            }
            //set the object
            if(temp){
                //
                return temp->set(arrayPos,obj);edkEnd();
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
            edk::uint32 StackPos = pos/this->StackArraySize;edkEnd();
            edk::uint32 arrayPos = pos%this->StackArraySize;edkEnd();
            //create a temp
            edk::vector::StackCel<typeTemplate> *temp=this->first;edkEnd();
            //then find the value
            for(edk::uint32 i=0u;i<StackPos;i++){
                //
                if(temp->next){
                    temp=temp->next;edkEnd();
                }
                else{
                    break;
                }
            }
            //return the object
            if(temp){
                //
                return temp->get(arrayPos);edkEnd();
            }
        }
        //else return false
        typeTemplate ret;edkEnd(); memset((void*)&ret,0u,sizeof(typeTemplate));edkEnd();
        return ret;
    }
    //load the objects inside the stack
    virtual bool load(){
        edk::uint32 increment=0u;edkEnd();
        edk::vector::StackCel<typeTemplate> *temp=this->first;edkEnd();
        if(temp){
            while(temp){
                if(!temp->next){
                    edk::uint32 size = this->stackSize - increment;edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        //test if have the element
                        if(!this->removed.haveElement(i)){
                            //update element
                            this->loadElement(temp->get(i));edkEnd();
                        }
                    }
                }
                else{
                    for(edk::uint32 i=0u;i<this->StackArraySize;i++){
                        //test if have the element
                        if(!this->removed.haveElement(i)){
                            //update element
                            this->loadElement(temp->get(i));edkEnd();
                        }
                    }
                }
                temp=temp->next;edkEnd();
                increment+=this->StackArraySize;edkEnd();
            }
            return true;
        }
        return false;
    }
    //unload
    //update the objects inside the stack
    virtual bool unload(){
        edk::uint32 increment=0u;edkEnd();
        edk::vector::StackCel<typeTemplate> *temp=this->first;edkEnd();
        if(temp){
            while(temp){
                if(!temp->next){
                    edk::uint32 size = this->stackSize - increment;edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        //test if have the element
                        if(!this->removed.haveElement(i)){
                            //update element
                            this->unloadElement(temp->get(i));edkEnd();
                        }
                    }
                }
                else{
                    for(edk::uint32 i=0u;i<this->StackArraySize;i++){
                        //test if have the element
                        if(!this->removed.haveElement(i)){
                            //update element
                            this->unloadElement(temp->get(i));edkEnd();
                        }
                    }
                }
                temp=temp->next;edkEnd();
                increment+=this->StackArraySize;edkEnd();
            }
            return true;
        }
        return false;
    }
    //UPDATE
    //update the objects inside the stack
    virtual bool update(){
        edk::uint32 increment=0u;edkEnd();
        edk::vector::StackCel<typeTemplate> *temp=this->first;edkEnd();
        if(temp){
            while(temp){
                if(!temp->next){
                    edk::uint32 size = this->stackSize - increment;edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        //test if have the element
                        if(!this->removed.haveElement(i)){
                            //update element
                            this->updateElement(temp->get(i));edkEnd();
                        }
                    }
                }
                else{
                    for(edk::uint32 i=0u;i<this->StackArraySize;i++){
                        //test if have the element
                        if(!this->removed.haveElement(i)){
                            //update element
                            this->updateElement(temp->get(i));edkEnd();
                        }
                    }
                }
                temp=temp->next;edkEnd();
                increment+=this->StackArraySize;edkEnd();
            }
            return true;
        }
        return false;
    }
    //print the objects inside the stack
    virtual bool print(){
        edk::uint32 increment=0u;edkEnd();
        edk::vector::StackCel<typeTemplate> *temp=this->first;edkEnd();
        if(temp){
            while(temp){
                if(!temp->next){
                    edk::uint32 size = this->stackSize - increment;edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        //test if have the element
                        if(!this->removed.haveElement(i)){
                            //update element
                            this->printElement(temp->get(i));edkEnd();
                        }
                    }
                }
                else{
                    for(edk::uint32 i=0u;i<this->StackArraySize;i++){
                        //test if have the element
                        if(!this->removed.haveElement(i)){
                            //update element
                            this->printElement(temp->get(i));edkEnd();
                        }
                    }
                }
                temp=temp->next;edkEnd();
                increment+=this->StackArraySize;edkEnd();
            }
            return true;
        }
        return false;
    }
    //render the objects inside the stack
    virtual bool render(){
        edk::uint32 increment=0u;edkEnd();
        edk::vector::StackCel<typeTemplate> *temp=this->first;edkEnd();
        if(temp){
            while(temp){
                if(!temp->next){
                    edk::uint32 size = this->stackSize - increment;edkEnd();
                    for(edk::uint32 i=0u;i<size;i++){
                        //test if have the element
                        if(!this->removed.haveElement(i)){
                            //update element
                            this->renderElement(temp->get(i));edkEnd();
                        }
                    }
                }
                else{
                    for(edk::uint32 i=0u;i<this->StackArraySize;i++){
                        //test if have the element
                        if(!this->removed.haveElement(i)){
                            //update element
                            this->renderElement(temp->get(i));edkEnd();
                        }
                    }
                }
                temp=temp->next;edkEnd();
                increment+=this->StackArraySize;edkEnd();
            }
            return true;
        }
        return false;
    }
    //get the size
    edk::uint32 getSize(){
        //
        return this->size();edkEnd();
    }
    //return the size
    edk::uint32 size(){
        //
        return this->stackSize;edkEnd();
    }
    edk::uint32 sizeRemoved(){
        return this->removed.size();edkEnd();
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
                    if(this->get(i)==obj){
                        //then return the i
                        return i;edkEnd();
                    }
                }
            }
        }
        //else return 0u;edkEnd();
        return 0u;edkEnd();
    }
    bool haveElement(typeTemplate obj){
        //test the size
        if(this->stackSize){
            //then find the object
            for(edk::uint32 i=0u;i<this->stackSize;i++){
                //test if have the object
                if(this->havePos(i)){
                    //test the obj
                    if(this->get(i)==obj){
                        //then return the i
                        return true;
                    }
                }
            }
        }
        //else return 0u;edkEnd();
        return false;
    }

    //SWAP two objects
    bool swap(edk::uint32 pos1,edk::uint32 pos2){
        //first test if have the two objects
        if(pos1<this->stackSize && pos2<this->stackSize){
            //then test if have the objects
            bool have1 = this->havePos(pos1);edkEnd();
            bool have2 = this->havePos(pos2);edkEnd();

            //remove the 1 and 2 from the removed's
            this->removed.remove(pos1);edkEnd();
            this->removed.remove(pos2);edkEnd();

            //then switch
            typeTemplate temp = this->get(pos1);edkEnd();
            this->set(pos1,this->get(pos2));edkEnd();
            this->set(pos2,temp);edkEnd();

            //put the new removed's
            if(!have1){
                //
                this->removed.add(pos2);edkEnd();
                if(!have2){
                    //
                    this->removed.add(pos1);edkEnd();
                }
            }
            else if(!have2){
                //
                this->removed.add(pos1);edkEnd();
            }
            return true;
        }
        //else return false
        return false;
    }

    //Move position object
    bool bringPositionPlusOne(edk::uint32 position){
        //test if have the position and if the position is plus zero
        if(this->havePos(position) && position<(this->stackSize-1u)){
            //then swap one front
            return this->swap(position,position+1u);edkEnd();
        }
        //else return false
        return false;
    }
    bool bringPositionMinusOne(edk::uint32 position){
        //test if have the position and if the position is plus zero
        if(this->havePos(position) && position>0u){
            //then swap one front
            return this->swap(position,position-1u);edkEnd();
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
                this->swap(i,i+1u);edkEnd();
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
                this->swap(i,i-1u);edkEnd();
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
            return this->bringPositionPlusTimes(position,position2-position);edkEnd();
        }
        else{
            //position2 is minus
            return this->bringPositionMinusTimes(position,position-position2);edkEnd();
        }
        //else return false
        return false;
    }

    //cant
    void cantDestroy(){
        //
        this->canDeleteVector=false;edkEnd();
    }

    //OPERATORS
    /*
    //[] //To return the object in the pos
    typeTemplate operator[](edk::uint32 pos){
        //
        return this->get(pos);edkEnd();
    }
    */
    virtual bool cloneFrom(edk::vector::Stack<typeTemplate>* ret){
        //clean the vector
        this->clean();edkEnd();
        if(ret){
            //copy the types from the ret
            for(edk::uint32 i=0u;i<ret->size();i++){
                //copy
                this->pushBack(ret->get(i));edkEnd();
            }
            return true;
        }
        return false;
    }
protected:
    virtual void loadElement(typeTemplate){}
    virtual void unloadElement(typeTemplate){}
    virtual void updateElement(typeTemplate){}
    virtual void printElement(typeTemplate){}
    virtual void renderElement(typeTemplate){}
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
            delete this->deleteLastCel;edkEnd();
        }
        this->deleteLastCel=NULL;edkEnd();

        //test if have a end
        if(this->end){
            //then create a next in the end
            if((this->end->next =new edk::vector::StackCel<typeTemplate>(StackArraySize))){
                //set the previous
                this->end->next->previous=this->end;edkEnd();
                this->end->next->next=NULL;edkEnd();
                //set the end
                this->end = this->end->next;edkEnd();
                //return true
                return true;
            }
            //else clean the next
            this->end->next=NULL;edkEnd();
        }
        else{
            //else create the first
            if(this->first){
                //Clean the Stack to make a new Stack
                this->clean();edkEnd();
            }
            if((this->first = new edk::vector::StackCel<typeTemplate>(StackArraySize))){
                //set the end
                this->end=this->first;edkEnd();

                this->first->next=NULL;edkEnd();
                this->first->previous=NULL;edkEnd();

                //return true
                return true;
            }
            //clean the first
            this->first=NULL;edkEnd();
        }
        //else return false
        return false;
    }
private:
    //= //To create a copy of the Stack
    edk::vector::Stack<typeTemplate> operator=(edk::vector::Stack<typeTemplate> ret){
        //clean the vector
        this->clean();edkEnd();
        //copy the types from the ret
        for(edk::uint32 i=0u;i<ret.size();i++){
            //copy
            this->pushBack(ret[i]);edkEnd();
        }
        ret.cantDestroy();edkEnd();
        return ret;
    }
};

class StackNames: private edk::vector::Stack<edk::Name*>{
public:
    StackNames(){}
    ~StackNames(){
        this->clean();edkEnd();
    }

    //ADDS
    //pushBack the object
    edk::uint32 pushBack(const edk::char8* str){
        return this->pushBack((edk::char8*) str);edkEnd();
    }
    edk::uint32 pushBack(edk::char8* str){
        //test the string
        if(str){
            //create a new Name
            edk::Name* name = new edk::Name;edkEnd();
            if(name){
                //set the name
                if(name->setName(str)){
                    edk::uint32 size = edk::vector::Stack<edk::Name*>::size();edkEnd();
                    edk::uint32 pos= edk::vector::Stack<edk::Name*>::pushBack(name);edkEnd();
                    if(size<edk::vector::Stack<edk::Name*>::size()){
                        //push the position
                        this->tree.add(pos);edkEnd();
                        return pos;edkEnd();
                    }
                }
                delete name;edkEnd();
            }
        }
        //else return false
        return 0u;edkEnd();
    }
    edk::uint32 pushBack(edk::Name* name){
        return edk::vector::Stack<edk::Name*>::pushBack(name);edkEnd();
    }

    //DELETE
    //Remove the top
    bool popBack(){
        if(edk::vector::Stack<edk::Name*>::size()){
            edk::Name* name = edk::vector::Stack<edk::Name*>::popBack();edkEnd();
            if(name){
                //test if need remove the name
                if(this->tree.haveElement(edk::vector::Stack<edk::Name*>::size())){
                    this->tree.remove(edk::vector::Stack<edk::Name*>::size());edkEnd();
                    //delete the last name removed
                    delete name;edkEnd();
                }
                return true;
            }
        }
        //else return false
        return false;
    }
    //delete all Stack
    void deleteStack(){
        //clean
        this->clean();edkEnd();
    }
    //clean the Stack
    void clean(){
        //delete all the names
        this->_deleteAllNames();edkEnd();
        //in the end it need clean the stack with deleted pointers
        edk::vector::Stack<edk::Name*>::clean();edkEnd();
    }
    //Clean changing the Stack ArraySize
    void clean(edk::uint32 arraySize){
        //delete all the names
        this->_deleteAllNames();edkEnd();
        //in the end it need clean the stack with deleted pointers
        edk::vector::Stack<edk::Name*>::clean(arraySize);edkEnd();
    }

    //remove the element
    bool remove(edk::uint32 pos){
        //get the name in the position
        edk::Name* name = edk::vector::Stack<edk::Name*>::get(pos);edkEnd();
        if(name){
            //remove
            if(edk::vector::Stack<edk::Name*>::remove(pos)){
                //test if have the name position to delete
                if(this->tree.haveElement(pos)){
                    this->tree.remove(pos);edkEnd();
                    //delete the name
                    delete name;edkEnd();
                }
                return true;
            }
        }
        //else return false
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
        return false;
#pragma GCC diagnostic pop
    }

    //SETTERS
    bool set(edk::uint32 pos,edk::char8* str){
        if(str){
            //get the name in the position
            edk::Name* name = edk::vector::Stack<edk::Name*>::get(pos);edkEnd();
            if(name){
                //test if have the position in the tree
                if(this->tree.haveElement(pos)){
                    //set the new string
                    return name->setName(str);edkEnd();
                }
            }
        }
        //else return NULL
        return false;
    }
    bool set(edk::uint32 pos,edk::Name* nameObject){
        if(nameObject){
            //get the name in the position
            edk::Name* name = edk::vector::Stack<edk::Name*>::get(pos);edkEnd();
            if(name){
                //test if have the position in the tree
                if(this->tree.haveElement(pos)){
                    this->tree.remove(pos);edkEnd();
                    //set the new object
                    if(edk::vector::Stack<edk::Name*>::set(pos,nameObject)){
                        //delete the temp
                        delete name;edkEnd();
                    }
                }
                else{
                    //else just set the object
                    return edk::vector::Stack<edk::Name*>::set(pos,nameObject);edkEnd();
                }
            }
        }
        //else return NULL
        return false;
    }

    //GETTERS
    //get the object
    edk::Name* get(edk::uint32 pos){
        //else return false
        if(this->havePos(pos)){
            //get the name in the position
            edk::Name* name = edk::vector::Stack<edk::Name*>::get(pos);edkEnd();
            if(name){
                //return the string
                return name;edkEnd();
            }
        }
        //else return NULL
        return NULL;
    }
    //get the object
    edk::char8* getName(edk::uint32 pos){
        //else return false
        edk::char8* ret=NULL;edkEnd();
        if(this->havePos(pos)){
            //get the name in the position
            edk::Name* name = edk::vector::Stack<edk::Name*>::get(pos);edkEnd();
            if(name){
                //return the string
                ret = name->getName();edkEnd();
            }
        }
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
        return ret;
#pragma GCC diagnostic pop
    }

    //get the size
    edk::uint32 getSize(){
        //
        return edk::vector::Stack<edk::Name*>::getSize();edkEnd();
    }
    //return the size
    edk::uint32 size(){
        //
        return edk::vector::Stack<edk::Name*>::size();edkEnd();
    }
    edk::uint32 sizeRemoved(){
        return edk::vector::Stack<edk::Name*>::sizeRemoved();edkEnd();
    }

    //test if have the pos
    bool havePos(edk::uint32 pos){
        if(pos<this->size()){
            //get the name in the position
            edk::Name* name = edk::vector::Stack<edk::Name*>::get(pos);edkEnd();
            if(name){
                if(name->size()){
                    return true;
                }
            }
        }
        return false;
    }
    //find the position of the object
    edk::uint32 find(const edk::char8* str){
        return this->find((edk::char8*) str);edkEnd();
    }
    edk::uint32 find(edk::char8* str){
        //find the string in the stack
        edk::Name* name=NULL;edkEnd();
        edk::uint32 size = edk::vector::Stack<edk::Name*>::size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            name = edk::vector::Stack<edk::Name*>::get(i);edkEnd();
            if(name){
                if(edk::String::strCompare(name->getName(),str)){
                    return i;edkEnd();
                }
            }
        }
        return 0u;edkEnd();
    }
    bool haveString(const edk::char8* str){
        return this->haveString((edk::char8*) str);edkEnd();
    }
    bool haveString(edk::char8* str){
        //find the string in the stack
        edk::Name* name=NULL;edkEnd();
        edk::uint32 size = edk::vector::Stack<edk::Name*>::size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            name = edk::vector::Stack<edk::Name*>::get(i);edkEnd();
            if(name){
                if(edk::String::strCompare(name->getName(),str)){
                    return true;
                }
            }
        }
        return false;
    }

    //SWAP two objects
    bool swap(edk::uint32 pos1,edk::uint32 pos2){
        //test if have created some position
        if(this->tree.haveElement(pos1) && !this->tree.haveElement(pos2)){
            if(edk::vector::Stack<edk::Name*>::swap(pos1,pos2)){
                //swap the positions in the tree
                this->tree.remove(pos1);edkEnd();
                this->tree.add(pos2);edkEnd();
                return true;
            }
        }
        else if(this->tree.haveElement(pos2)){
            if(edk::vector::Stack<edk::Name*>::swap(pos1,pos2)){
                //swap the positions in the tree
                this->tree.remove(pos2);edkEnd();
                this->tree.add(pos1);edkEnd();
                return true;
            }
        }
        //else just swap
        return edk::vector::Stack<edk::Name*>::swap(pos1,pos2);edkEnd();
    }

    //Move position object
    bool bringPositionPlusOne(edk::uint32 position){
        if(edk::vector::Stack<edk::Name*>::size()>position+1u){
            //test if have created some position
            if(this->tree.haveElement(position) && !this->tree.haveElement(position+1u)){
                if(edk::vector::Stack<edk::Name*>::bringPositionPlusOne(position)){
                    //swap the positions in the tree
                    this->tree.remove(position);edkEnd();
                    this->tree.add(position+1u);edkEnd();
                    return true;
                }
            }
            else if(this->tree.haveElement(position+1u)){
                if(edk::vector::Stack<edk::Name*>::bringPositionPlusOne(position)){
                    //swap the positions in the tree
                    this->tree.remove(position+1u);edkEnd();
                    this->tree.add(position);edkEnd();
                    return true;
                }
            }
        }
        //else just swap
        return edk::vector::Stack<edk::Name*>::bringPositionPlusOne(position);edkEnd();
    }
    bool bringPositionMinusOne(edk::uint32 position){
        if(position && edk::vector::Stack<edk::Name*>::size()>position){
            //test if have created some position
            if(this->tree.haveElement(position) && !this->tree.haveElement(position-1u)){
                if(edk::vector::Stack<edk::Name*>::bringPositionMinusOne(position)){
                    //swap the positions in the tree
                    this->tree.remove(position);edkEnd();
                    this->tree.add(position-1u);edkEnd();
                    return true;
                }
            }
            else if(this->tree.haveElement(position-1u)){
                if(edk::vector::Stack<edk::Name*>::bringPositionMinusOne(position)){
                    //swap the positions in the tree
                    this->tree.remove(position-1u);edkEnd();
                    this->tree.add(position);edkEnd();
                    return true;
                }
            }
        }
        //else just swap
        return edk::vector::Stack<edk::Name*>::bringPositionMinusOne(position);edkEnd();
    }
    //Move a count
    bool bringPositionPlusTimes(edk::uint32 position,edk::uint32 times){
        if(edk::vector::Stack<edk::Name*>::size()>position+times){
            edk::uint32 size = position+times;edkEnd();
            for(edk::uint32 i=position;i<size;i++){
                this->bringPositionPlusOne(i);edkEnd();
            }
            return true;
        }
        return false;
    }
    bool bringPositionMinusTimes(edk::uint32 position,edk::uint32 times){
        if(position>times && edk::vector::Stack<edk::Name*>::size()>position){
            edk::uint32 limit = position - times;edkEnd();
            for(edk::uint32 i=position;i>limit;i--){
                this->bringPositionMinusOne(i-1u);edkEnd();
            }
            return true;
        }
        return false;
    }
    bool bringPositionTo(edk::uint32 position,edk::uint32 position2){
        if(position>position2){
            return this->bringPositionMinusTimes(position2,position-position2);edkEnd();
        }
        else if(position<position2){
            return this->bringPositionPlusTimes(position,position2-position);edkEnd();
        }
        return false;
    }

    //cant
    void cantDestroy(){
        edk::vector::Stack<edk::Name*>::cantDestroy();edkEnd();
    }

    //OPERATORS
    /*
    //[] //To return the object in the pos
    edk::Name* operator[](edk::uint32 pos){
        //
        return this->get(pos);edkEnd();
    }
    */
    virtual bool cloneFrom(edk::vector::StackNames* ret){
        //clean the vector
        this->clean();edkEnd();
        if(ret){
            //copy the types from the ret
            for(edk::uint32 i=0u;i<ret->size();i++){
                //copy
                this->pushBack(ret->get(i));edkEnd();
            }
            return true;
        }
        return false;
    }
private:
    void _deleteAllNames(){
        //remove all the names on the stack
        edk::Name* name=NULL;edkEnd();
        edk::uint32 size = edk::vector::Stack<edk::Name*>::size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            name = edk::vector::Stack<edk::Name*>::get(i);edkEnd();
            if(name){
                //test if need delete the name
                if(this->tree.haveElement(i)){
                    delete name;edkEnd();
                }
            }
        }
        //delete all positions
        this->tree.clean();edkEnd();
    }
    //tree with the positions created by the stack
    edk::vector::BinaryTree<edk::uint32>tree;
};

}//end namespace vector
}//end namespace edk

#endif // MUTABLEARRAY_H
