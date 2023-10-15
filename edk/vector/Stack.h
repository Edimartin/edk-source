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
template <class typeTemplate>
class StackCellLeaf : public edk::vector::Array<edk::vector::Array<typeTemplate>*>{
public:
    //construtor
    StackCellLeaf(){}
    StackCellLeaf(edk::uint32 size){
        this->createArray(size);edkEnd();
    }
    //Destrutor
    ~StackCellLeaf(){}
};

class StackCell : public edk::vector::Array<edk::classID>{
public:
    //construtor
    StackCell(edk::uint32 level){
        this->level = level;
        this->father=NULL;
        this->position=0u;
        this->readPosition=0u;
    }
    StackCell(edk::vector::StackCell* father,edk::uint32 level){
        this->level = level;
        this->father=father;
        this->position=0u;
        this->readPosition=0u;
    }
    StackCell(edk::uint32 size,edk::uint32 level){
        this->father=NULL;
        this->level = level;
        this->createArray(size);edkEnd();
        this->position=0u;
        this->readPosition=0u;
    }
    StackCell(edk::vector::StackCell* father,edk::uint32 size,edk::uint32 level){
        this->father=father;
        this->level = level;
        this->createArray(size);edkEnd();
        this->position=0u;
        this->readPosition=0u;
    }
    //Destrutor
    ~StackCell(){}
    bool isLeaf(){return this->level==1u;}
    edk::uint32 getLevel(){return this->level;}
    edk::uint32 position;
    edk::uint32 readPosition;
    edk::vector::StackCell* father;
private:
    edk::uint32 level;
};

template <class typeTemplate>
class Stack{
public:
    //Construtor
    Stack(){
        //clean the vectors
        this->canDeleteVector=true;edkEnd();
        this->StackArraySize=PatternArraySize;edkEnd();
        this->stackSize=0u;

        this->root=NULL;
    }
    //Construtor with arraySize
    Stack(edk::uint32 arraySize){
        //clean the vectors
        this->canDeleteVector=true;edkEnd();
        //Test if the arraySize is bigger then zero
        if(arraySize){
            //
            this->StackArraySize=arraySize;edkEnd();
        }
        else{
            //else set the Pattern
            this->StackArraySize=PatternArraySize;edkEnd();
        }
        this->stackSize=0u;

        this->root=NULL;
    }
    //Destrutor
    virtual ~Stack(){
        //delete the array
        if(this->canDeleteVector){
            //clean
            this->clean();edkEnd();
            this->canDeleteVector=false;edkEnd();
        }
        else{
            this->removed.cantDestruct();edkEnd();
        }
        this->stackSize=0u;
        //
        this->canDeleteVector=true;edkEnd();
    }

    //ADDS
    //pushBack the object
    edk::uint32 pushBack(typeTemplate obj){
        edk::uint32 ret=0u;
        //test if don't have the root
        if(!this->root){
            //create a new root with the first array
            this->root=new edk::vector::StackCell(this->StackArraySize,1u);
            if(this->root){
                //create the first array
                edk::vector::Array<typeTemplate>* temp = new edk::vector::Array<typeTemplate>(this->StackArraySize);
                if(temp){
                    this->root->set(this->root->position++,(edk::classID)temp);
                }
                else{
                    //else delete the root because we have a problem
                    delete this->root;
                    this->root=NULL;
                }
            }
        }
        //test if have the root
        if(this->root){
            //first get the new position of the element
            edk::uint32 pos = 0u;
            edk::uint32 rest = 0u;

            edk::vector::StackCell* temp = this->root;
            edk::vector::Array<typeTemplate>* newStack;
            edk::vector::StackCell* newCell;

            edk::uint32 searchPos;

            while(temp){
                //test if the temp is a leaf
                searchPos=0u;
                //search for the last position
                while(temp->get(searchPos)){
                    ++searchPos;
                }
                if(searchPos){
                    //else go to the cell
                    searchPos--;
                    pos+=searchPos*this->StackArraySize*temp->getLevel();

                    //test if are a leaf
                    if(temp->isLeaf()){
                        pos = this->stackSize-pos;
                        rest = pos%this->StackArraySize;
                        pos = searchPos;
                        edk::vector::Array<typeTemplate>* leaf = (edk::vector::Array<typeTemplate>*)temp->get(pos);
                        if(temp){
                            leaf->set(rest,obj);
                            ret = this->stackSize;
                            this->stackSize++;

                            //test if need create a new stack
                            if(rest>=this->StackArraySize-1u){
                                while(temp){
                                    //have set the last in the array
                                    if(temp->position>=this->StackArraySize){
                                        //test uf have a father
                                        if(temp->father){
                                            //go into the father
                                            temp=temp->father;
                                        }
                                        else{
                                            //else is root
                                            this->root=new edk::vector::StackCell(this->StackArraySize,temp->getLevel()*this->StackArraySize);
                                            if(this->root){
                                                //
                                                temp->father=this->root;
                                                this->root->set(this->root->position++,temp);
                                                temp=this->root;
                                            }
                                            else{
                                                //else it crash
                                                this->root=temp;
                                                break;
                                            }
                                        }
                                    }
                                    else{
                                        //else just create a new cell or create a new array
                                        if(temp->isLeaf()){
                                            //create a new stack
                                            newStack = new edk::vector::Array<typeTemplate>(this->StackArraySize);
                                            if(newStack){
                                                temp->set(temp->position++,(edk::classID)newStack);
                                            }
                                            break;
                                        }
                                        else{
                                            //
                                            newCell = new edk::vector::StackCell(this->StackArraySize,temp->getLevel()/this->StackArraySize);
                                            if(newCell){
                                                temp->set(temp->position++,newCell);
                                                newCell->father=temp;
                                                temp=newCell;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    else{
                        temp=(edk::vector::StackCell*)temp->get(searchPos);
                    }
                }
                else{
                }
            }
        }
        return ret;
    }

    //DELETE
    //Remove the top
    typeTemplate popBack(){
        typeTemplate ret;
        typeTemplate retTemp;
        memset(&ret,0u,sizeof(typeTemplate));

        edk::vector::StackCell* temp = this->root;
        edk::vector::StackCell* temp2;
        edk::vector::Array<typeTemplate>* tempArray;
        edk::uint32 pos=0u;
        edk::uint32 positionRemove;
        edk::uint32 increment;
        //test if have root
        while(temp){
            if(temp->isLeaf()){

                if(this->removed.haveElement(this->stackSize)){
                    while(true){
                        positionRemove=this->stackSize-(pos + this->StackArraySize*temp->getLevel()*(temp->position-1u));
                        if(positionRemove){
                            //decrement the size
                            this->stackSize--;
                        }
                        else{
                            tempArray = (edk::vector::Array<typeTemplate>*)temp->get(temp->position-1u);
                            if(tempArray){
                                delete tempArray;
                                temp->set(temp->position-1u,NULL);
                                temp->position--;
                                if(!temp->position){
                                    temp2 = temp;
                                    temp->father=temp;
                                    delete temp2;
                                    temp->set(temp->position-1u,NULL);
                                    temp->position--;
                                }
                            }
                        }
                    }
                    continue;
                }
                else{
                    increment = this->StackArraySize*temp->getLevel()*(temp->position-1u);
                    pos += increment;

                    if(pos>=this->stackSize){
                        //remove the right
                        tempArray = (edk::vector::Array<typeTemplate>*)temp->get(temp->position-1u);
                        if(tempArray){
                            temp->position--;
                            temp->set(temp->position,NULL);
                            delete tempArray;
                            pos -= increment;

                            if(!temp->position){
                                //delete this temp
                                temp2 = temp;
                                temp=temp->father;
                                pos -= this->StackArraySize*temp->getLevel()*(temp->position-1u);
                                temp->set(temp->position-1u,NULL);
                                temp->position--;
                                delete temp2;
                            }
                        }
                    }
                    else{
                        if(!pos){
                            if(this->stackSize && this->stackSize<=this->StackArraySize){
                                positionRemove=this->stackSize-1u;
                                tempArray = (edk::vector::Array<typeTemplate>*)temp->get(temp->position-1u);
                                if(tempArray){
                                    retTemp = tempArray->get(positionRemove);
                                    //remove
                                    tempArray->set(positionRemove,ret);
                                    //
                                    memcpy(&ret,&retTemp,sizeof(typeTemplate));
                                    this->stackSize--;
                                    if(!this->stackSize){
                                        delete this->root;
                                        this->root=NULL;
                                    }
                                    break;
                                }
                            }
                        }
                        else{
                            pos++;
                            if(pos){
                                //test if have position
                                positionRemove = (this->stackSize-pos)%this->StackArraySize;
                            }
                            else{
                                positionRemove = 0u;
                            }
                            tempArray = (edk::vector::Array<typeTemplate>*)temp->get(temp->position-1u);
                            if(tempArray){
                                retTemp = tempArray->get(positionRemove);
                                //remove
                                tempArray->set(positionRemove,ret);
                                //
                                memcpy(&ret,&retTemp,sizeof(typeTemplate));
                                this->stackSize--;
                                if(!this->stackSize){
                                    delete this->root;
                                    this->root=NULL;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            else if(temp->position){
                if(pos>=this->stackSize){
                    //test if have right
                    if(temp->position){
                        //go to right
                        pos += this->StackArraySize*temp->getLevel()*(temp->position-1u);
                        temp = (edk::vector::StackCell*)temp->get(temp->position-1u);
                    }
                    else{
                        //remove the right
                        tempArray = (edk::vector::Array<typeTemplate>*)temp->get(temp->position-1u);
                        if(tempArray){
                            temp->position--;
                            temp->set(temp->position,NULL);
                            delete tempArray;
                            pos -= increment;

                            if(!temp->position){
                                //delete this temp
                                pos -= this->StackArraySize*temp->getLevel()*(temp->position-1u);
                                temp2 = temp;
                                temp=temp->father;
                                pos -= this->StackArraySize*temp->getLevel()*(temp->position-1u);
                                delete temp2;
                            }
                        }
                    }
                }
                else{
                    if(temp->position==1u && temp==this->root){
                        //remove the root
                        this->root=(edk::vector::StackCell*)temp->get(temp->position-1u);
                        delete temp;
                        temp=this->root;
                    }
                    else{
                        pos += this->StackArraySize*temp->getLevel()*(temp->position-1u);
                        temp = (edk::vector::StackCell*)temp->get(temp->position-1u);
                    }
                }
            }
            else{
                //remove the cell
                temp2 = temp;
                temp=temp->father;
                pos -= this->StackArraySize*temp->getLevel()*(temp->position-1u);
                temp->set(temp->position-1u,NULL);
                temp->position--;
                delete temp2;
            }
        }

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
            edk::vector::StackCell* temp = this->root;
            edk::vector::StackCell* temp2;
            edk::uint32 position=0u;
            edk::uint32 size;
            edk::vector::Array<typeTemplate>* arrayTemp;
            edk::uint32 i=0u;
            if(temp){
                temp->readPosition=0u;
                if(this->removed.size()){
                    while(temp){
                        //test if are a leaf
                        if(temp->isLeaf()){
                            if(temp->readPosition<this->StackArraySize){
                                if(position+this->StackArraySize>this->stackSize){
                                    arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                    if(arrayTemp){
                                        size = this->stackSize;
                                        i=0u;
                                        while(position<size){
                                            if(!this->removed.haveElement(position)){
                                                vector[0u] = arrayTemp->get(i);edkEnd();
                                                vector++;edkEnd();
                                            }
                                            position++;
                                            i++;
                                        }
                                    }
                                    else{
                                        //else return false
                                        return false;
                                    }
                                    //find the end
                                    return true;
                                }
                                else{
                                    arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                    if(arrayTemp){
                                        for(i=0u;i<this->StackArraySize;i++){
                                            if(!this->removed.haveElement(position)){
                                                vector[0u] = arrayTemp->get(i);edkEnd();
                                                vector++;edkEnd();
                                            }
                                            position++;
                                        }
                                    }
                                    else{
                                        //else return false
                                        return false;
                                    }
                                }
                            }
                            else{
                                //go to the father
                                temp=temp->father;
                            }
                        }
                        else{
                            //else search for the next cell
                            if(temp->readPosition>=this->StackArraySize){
                                //else go to the father
                                temp = temp->father;
                            }
                            else {
                                temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                                if(temp2){
                                    temp=temp2;
                                    temp->readPosition=0u;
                                }
                                else{
                                    //else go to the father
                                    temp = temp->father;
                                }
                            }
                        }
                    }
                }
                else{
                    //without removed
                    while(temp){
                        //test if are a leaf
                        if(temp->isLeaf()){
                            if(temp->readPosition<this->StackArraySize){
                                if(position+this->StackArraySize>this->stackSize){
                                    arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                    if(arrayTemp){
                                        size = this->stackSize;
                                        i=0u;
                                        while(position<size){
                                            vector[0u] = arrayTemp->get(i);edkEnd();
                                            vector++;edkEnd();
                                            position++;
                                            i++;
                                        }
                                    }
                                    else{
                                        //else return false
                                        return false;
                                    }
                                    //find the end
                                    return true;
                                }
                                else{
                                    arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                    if(arrayTemp){
                                        for(i=0u;i<this->StackArraySize;i++){
                                            vector[0u] = arrayTemp->get(i);edkEnd();
                                            vector++;edkEnd();
                                            position++;
                                        }
                                    }
                                    else{
                                        //else return false
                                        return false;
                                    }
                                }
                            }
                            else{
                                //go to the father
                                temp=temp->father;
                            }
                        }
                        else{
                            //else search for the next cell
                            if(temp->readPosition>=this->StackArraySize){
                                //else go to the father
                                temp = temp->father;
                            }
                            else {
                                temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                                if(temp2){
                                    temp=temp2;
                                    temp->readPosition=0u;
                                }
                                else{
                                    //else go to the father
                                    temp = temp->father;
                                }
                            }
                        }
                    }
                }
                return true;
            }
        }
        return false;
    }
    //clean the Stack
    void clean(){
        edk::vector::StackCell* temp = root;
        edk::vector::StackCell* temp2;
        edk::vector::Array<typeTemplate>* tempArray;
        while(temp){
            if(temp->isLeaf()){
                while(temp->position){
                    tempArray = (edk::vector::Array<typeTemplate>*)temp->get(temp->position-1u);
                    if(tempArray){
                        delete tempArray;
                        temp->position--;
                    }
                }
                //delete the leaf
                if(temp->father){
                    temp2=temp->father;
                    delete temp;
                    temp2->set(temp2->position-1u,NULL);
                    temp2->position--;
                    temp=temp2;
                }
                else if(this->root == temp){
                    delete this->root;
                    this->root=NULL;
                    temp=NULL;
                }
            }
            else if(temp->position>1u){
                //go right
                temp = (edk::vector::StackCell*)temp->get(temp->position-1u);
            }
            else if(temp->position==1u){
                //else go left
                temp = (edk::vector::StackCell*)temp->get(temp->position-1u);
            }
            else{
                //delete the leaf
                if(temp->father){
                    temp2=temp->father;
                    delete temp;
                    temp2->set(temp2->position-1u,NULL);
                    temp2->position--;
                    temp=temp2;
                }
                else if(this->root == temp){
                    delete this->root;
                    this->root=NULL;
                    temp=NULL;
                }
            }
        }
        this->stackSize=0u;
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
            edk::vector::StackCell* temp = root;
            edk::vector::Array<typeTemplate>* tempArray;
            edk::uint32 posNew;
            edk::uint32 rest;
            edk::uint32 increment;
            while(temp){
                //test if are leaf
                if(temp->isLeaf()){
                    //get the position
                    posNew = pos/this->StackArraySize;
                    rest = pos%this->StackArraySize;

                    //test if have the position
                    if(posNew<temp->position){
                        tempArray = (edk::vector::Array<typeTemplate>*)temp->get(posNew);
                        if(tempArray){
                            return tempArray->set(rest,obj);
                        }
                    }
                }
                else{
                    //else search
                    for(edk::uint32 i=temp->position;i>0u;--i){
                        increment = (i-1u)*this->StackArraySize*temp->getLevel();
                        if(pos>=increment){
                            //find it
                            pos-=increment;
                            temp=(edk::vector::StackCell*)temp->get(i-1u);
                            break;
                        }
                    }
                }
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
            edk::vector::StackCell* temp = root;
            edk::vector::Array<typeTemplate>* tempArray;
            edk::uint32 posNew;
            edk::uint32 rest;
            edk::uint32 increment;
            while(temp){
                //test if are leaf
                if(temp->isLeaf()){
                    //get the position
                    posNew = pos/this->StackArraySize;
                    rest = pos%this->StackArraySize;

                    //test if have the position
                    if(posNew<temp->position){
                        tempArray = (edk::vector::Array<typeTemplate>*)temp->get(posNew);
                        if(tempArray){
                            return tempArray->get(rest);
                        }
                    }
                }
                else{
                    //else search
                    for(edk::uint32 i=temp->position;i>0u;--i){
                        increment = (i-1u)*this->StackArraySize*temp->getLevel();
                        if(pos>=increment){
                            //find it
                            pos-=increment;
                            temp=(edk::vector::StackCell*)temp->get(i-1u);
                            break;
                        }
                    }
                }
            }
        }
        //else return false
        typeTemplate ret;edkEnd(); memset((void*)&ret,0u,sizeof(typeTemplate));edkEnd();
        return ret;
    }
    //load the objects inside the stack
    virtual bool load(){
        edk::vector::StackCell* temp = this->root;
        edk::vector::StackCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::Array<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if(this->removed.size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        if(!this->removed.haveElement(position)){
                                            this->loadElement(arrayTemp->get(i));edkEnd();
                                        }
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        if(!this->removed.haveElement(position)){
                                            this->loadElement(arrayTemp->get(i));edkEnd();
                                        }
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            else{
                //without removed
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        this->loadElement(arrayTemp->get(i));edkEnd();
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        this->loadElement(arrayTemp->get(i));edkEnd();
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }
    //unload
    //update the objects inside the stack
    virtual bool unload(){
        edk::vector::StackCell* temp = this->root;
        edk::vector::StackCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::Array<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if(this->removed.size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        if(!this->removed.haveElement(position)){
                                            this->unloadElement(arrayTemp->get(i));edkEnd();
                                        }
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        if(!this->removed.haveElement(position)){
                                            this->unloadElement(arrayTemp->get(i));edkEnd();
                                        }
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            else{
                //without removed
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        this->unloadElement(arrayTemp->get(i));edkEnd();
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        this->unloadElement(arrayTemp->get(i));edkEnd();
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }
    //UPDATE
    //update the objects inside the stack
    virtual bool update(){
        edk::vector::StackCell* temp = this->root;
        edk::vector::StackCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::Array<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if(this->removed.size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        if(!this->removed.haveElement(position)){
                                            this->updateElement(arrayTemp->get(i));edkEnd();
                                        }
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        if(!this->removed.haveElement(position)){
                                            this->updateElement(arrayTemp->get(i));edkEnd();
                                        }
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            else{
                //without removed
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        this->updateElement(arrayTemp->get(i));edkEnd();
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        this->updateElement(arrayTemp->get(i));edkEnd();
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }
    //print the objects inside the stack
    virtual bool print(){
        edk::vector::StackCell* temp = this->root;
        edk::vector::StackCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::Array<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if(this->removed.size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        if(!this->removed.haveElement(position)){
                                            this->printElement(arrayTemp->get(i));edkEnd();
                                        }
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        if(!this->removed.haveElement(position)){
                                            this->printElement(arrayTemp->get(i));edkEnd();
                                        }
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            else{
                //without removed
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        this->printElement(arrayTemp->get(i));edkEnd();
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        this->printElement(arrayTemp->get(i));edkEnd();
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            return true;
        }
        return false;
    }
    //render the objects inside the stack
    virtual bool render(){
        edk::vector::StackCell* temp = this->root;
        edk::vector::StackCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::Array<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if(this->removed.size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        if(!this->removed.haveElement(position)){
                                            this->renderElement(arrayTemp->get(i));edkEnd();
                                        }
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        if(!this->removed.haveElement(position)){
                                            this->renderElement(arrayTemp->get(i));edkEnd();
                                        }
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            else{
                //without removed
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        this->renderElement(arrayTemp->get(i));edkEnd();
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        this->renderElement(arrayTemp->get(i));edkEnd();
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
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
    inline edk::uint32 size(){
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
        edk::vector::StackCell* temp = this->root;
        edk::vector::StackCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::Array<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if(this->removed.size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        if(!this->removed.haveElement(position)){
                                            if(this->elementEqual(arrayTemp->get(i),obj)){
                                                return position;
                                            }
                                        }
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        if(!this->removed.haveElement(position)){
                                            if(this->elementEqual(arrayTemp->get(i),obj)){
                                                return position;
                                            }
                                        }
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            else{
                //without removed
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        if(this->elementEqual(arrayTemp->get(i),obj)){
                                            return position;
                                        }
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        if(this->elementEqual(arrayTemp->get(i),obj)){
                                            return position;
                                        }
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
        }
        return 0u;
    }
    bool haveElement(typeTemplate obj){
        edk::vector::StackCell* temp = this->root;
        edk::vector::StackCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::Array<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if(this->removed.size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        if(!this->removed.haveElement(position)){
                                            if(this->elementEqual(arrayTemp->get(i),obj)){
                                                return true;
                                            }
                                        }
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        if(!this->removed.haveElement(position)){
                                            if(this->elementEqual(arrayTemp->get(i),obj)){
                                                return true;
                                            }
                                        }
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
            else{
                //without removed
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<this->StackArraySize){
                            if(position+this->StackArraySize>this->stackSize){
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = this->stackSize;
                                    i=0u;
                                    while(position<size){
                                        if(this->elementEqual(arrayTemp->get(i),obj)){
                                            return true;
                                        }
                                        position++;
                                        i++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                                //find the end
                                return true;
                            }
                            else{
                                arrayTemp=(edk::vector::Array<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<this->StackArraySize;i++){
                                        if(this->elementEqual(arrayTemp->get(i),obj)){
                                            return true;
                                        }
                                        position++;
                                    }
                                }
                                else{
                                    //else return false
                                    return false;
                                }
                            }
                        }
                        else{
                            //go to the father
                            temp=temp->father;
                        }
                    }
                    else{
                        //else search for the next cell
                        if(temp->readPosition>=this->StackArraySize){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackCell*)temp->get(temp->readPosition++);
                            if(temp2){
                                temp=temp2;
                                temp->readPosition=0u;
                            }
                            else{
                                //else go to the father
                                temp = temp->father;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    //SWAP two objects
    bool swap(edk::uint32 pos1,edk::uint32 pos2){
        //first test if have the two objects
        if(pos1<this->stackSize && pos2<this->stackSize){
            //bool getPosition2(edk::uint32 pos,edk::vector::Array<typeTemplate>* array[],edk::uint32* posArray);
            edk::vector::Array<typeTemplate>* array1=NULL;
            edk::uint32 posArray1=0u;
            edk::vector::Array<typeTemplate>* array2=NULL;
            edk::uint32 posArray2=0u;

            if(this->getPosition(pos1,&array1,&posArray1)
                    &&
                    this->getPosition(pos2,&array2,&posArray2)
                    ){
                //change the position
                typeTemplate type = array2->get(posArray2);
                array2->set(posArray2,array1->get(posArray1));
                array1->set(posArray1,type);
                bool have1=this->removed.haveElement(posArray1),have2=this->removed.haveElement(posArray2);
                if(have1!=have2){
                    if(have1){
                        this->removed.remove(have1);
                        this->removed.add(have2);
                    }
                    else{
                        this->removed.remove(have2);
                        this->removed.add(have1);
                    }
                }
                return true;
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
    virtual bool elementEqual(typeTemplate ,typeTemplate ){return false;}
private:
    //Have the first cel
    edk::vector::StackCell* root;

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

    //get the position in the stack
    bool getPosition(edk::uint32 pos,edk::vector::Array<typeTemplate>* array[],edk::uint32* posArray){
        if(array && posArray){



            //test if have the pos
            if(this->havePos(pos)){
                edk::vector::StackCell* temp = root;
                edk::vector::Array<typeTemplate>* tempArray;
                edk::uint32 posNew;
                edk::uint32 rest;
                edk::uint32 increment;
                while(temp){
                    //test if are leaf
                    if(temp->isLeaf()){
                        //get the position
                        posNew = pos/this->StackArraySize;
                        rest = pos%this->StackArraySize;

                        //test if have the position
                        if(posNew<temp->position){
                            tempArray = (edk::vector::Array<typeTemplate>*)temp->get(posNew);
                            if(tempArray){
                                *array=tempArray;
                                *posArray=rest;
                                return true;
                            }
                        }
                    }
                    else{
                        //else search
                        for(edk::uint32 i=temp->position;i>0u;--i){
                            increment = (i-1u)*this->StackArraySize*temp->getLevel();
                            if(pos>=increment){
                                //find it
                                pos-=increment;
                                temp=(edk::vector::StackCell*)temp->get(i-1u);
                                break;
                            }
                        }
                    }
                }
            }








            //test if have the pos
            if(this->havePos(pos)){
                edk::vector::StackCell* temp = root;
                edk::vector::Array<typeTemplate>* tempArray;
                edk::uint32 posNew;
                edk::uint32 rest;
                edk::uint32 increment;
                while(temp){
                    //test if are leaf
                    if(temp->isLeaf()){
                        //get the position
                        posNew = pos/this->StackArraySize;
                        rest = pos%this->StackArraySize;

                        //test if have the position
                        if(posNew<temp->position){
                            tempArray = (edk::vector::Array<typeTemplate>*)temp->get(posNew);
                            if(tempArray){
                                *array=tempArray;
                                *posArray=rest;
                                return true;
                            }
                        }
                    }
                    else{
                        //else search
                        for(edk::uint32 i=temp->position;i>0u;--i){
                            increment = (i-1u)*this->StackArraySize*temp->getLevel();
                            if(pos>=increment){
                                //find it
                                pos-=increment;
                                temp=(edk::vector::StackCell*)temp->get(i-1u);
                                break;
                            }
                        }
                    }
                }
            }
        }
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
