#ifndef STACKSTATIC_H
#define STACKSTATIC_H

/*
Library StackStatic - Create a StackStatic in EDK Game Engine
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
#pragma message "Inside StackStatic"
#endif

#pragma once
//Include the array
#include "ArrayStatic.h"
#include "BinaryTreeStatic.h"
#include "../NameClass.h"

#ifdef printMessages
#pragma message "    Compiling StackStatic"
#endif

//Size of the arrays in the Stack
#define PatternArrayStaticSize 10u

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


void loadElementWithID(typeTemplate value,edk::uint32 id){
    //
}
void unloadElementWithID(typeTemplate value,edk::uint32 id){
    //
}
void updateElementWithID(typeTemplate value,edk::uint32 id){
    //
}
void printElementWithID(typeTemplate value,edk::uint32 id){
    //
}
void renderElementWithID(typeTemplate value,edk::uint32 id){
    //
}

bool load(){
    return edk::vector::StackStatic<typeTemplate>::load();
}
bool unload(){
    return edk::vector::StackStatic<typeTemplate>::unload();
}
bool update(){
    return edk::vector::StackStatic<typeTemplate>::update();
}
bool print(){
    return edk::vector::StackStatic<typeTemplate>::print();
}
bool render(){
    return edk::vector::StackStatic<typeTemplate>::render();
}


bool loadWithID(){
    return edk::vector::StackStatic<typeTemplate>::loadWithID();
}
bool unloadWithID(){
    return edk::vector::StackStatic<typeTemplate>::unloadWithID();
}
bool updateWithID(){
    return edk::vector::StackStatic<typeTemplate>::updateWithID();
}
bool printWithID(){
    return edk::vector::StackStatic<typeTemplate>::printWithID();
}
bool renderWithID(){
    return edk::vector::StackStatic<typeTemplate>::renderWithID();
}
*/

namespace edk{
namespace vector{
template <class typeTemplate>
class StackStaticCellLeaf : public edk::vector::ArrayStatic<edk::vector::ArrayStatic<typeTemplate>*>{
public:
    //construtor
    StackStaticCellLeaf(){
        edk::vector::ArrayStatic<edk::vector::ArrayStatic<typeTemplate>*>::Constructor();
        this->classThis=NULL;
        this->Constructor();
    }
    StackStaticCellLeaf(edk::uint32 size){
        edk::vector::ArrayStatic<edk::vector::ArrayStatic<typeTemplate>*>::Constructor();
        this->classThis=NULL;
        this->Constructor(size);
    }
    //Destrutor
    virtual ~StackStaticCellLeaf(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::ArrayStatic<edk::vector::ArrayStatic<typeTemplate>*>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Constructor(edk::uint32 size){
        edk::vector::ArrayStatic<edk::vector::ArrayStatic<typeTemplate>*>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->createArray(size);
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            edk::vector::ArrayStatic<edk::vector::ArrayStatic<typeTemplate>*>::Destructor();
        }
        edk::vector::ArrayStatic<edk::vector::ArrayStatic<typeTemplate>*>::Destructor();
    }
private:
    edk::classID classThis;
};

class StackStaticCell : public edk::vector::ArrayStatic<edk::classID>{
public:
    //construtor
    StackStaticCell(){
        edk::vector::ArrayStatic<edk::classID>::Constructor();
        this->classThis=NULL;
        this->Constructor();
    }
    StackStaticCell(edk::uint32 level){
        edk::vector::ArrayStatic<edk::classID>::Constructor();
        this->classThis=NULL;
        this->Constructor(level);
    }
    StackStaticCell(edk::vector::StackStaticCell* father,edk::uint32 level){
        edk::vector::ArrayStatic<edk::classID>::Constructor();
        this->classThis=NULL;
        this->Constructor(father,level);
    }
    StackStaticCell(edk::uint32 size,edk::uint32 level){
        edk::vector::ArrayStatic<edk::classID>::Constructor();
        this->classThis=NULL;
        this->Constructor(size,level);
    }
    StackStaticCell(edk::vector::StackStaticCell* father,edk::uint32 size,edk::uint32 level){
        edk::vector::ArrayStatic<edk::classID>::Constructor();
        this->classThis=NULL;
        this->Constructor(father,size,level);
    }
    //Destrutor
    virtual ~StackStaticCell(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::ArrayStatic<edk::classID>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->level = 0u;
            this->father=NULL;
            this->position=0u;
            this->readPosition=0u;
        }
    }
    void Constructor(edk::uint32 level){
        edk::vector::ArrayStatic<edk::classID>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->level = level;
            this->father=NULL;
            this->position=0u;
            this->readPosition=0u;
        }
    }
    void Constructor(edk::vector::StackStaticCell* father,edk::uint32 level){
        edk::vector::ArrayStatic<edk::classID>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->level = level;
            this->father=father;
            this->position=0u;
            this->readPosition=0u;
        }
    }
    void Constructor(edk::uint32 size,edk::uint32 level){
        edk::vector::ArrayStatic<edk::classID>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->father=NULL;
            this->level = level;
            this->position=0u;
            this->readPosition=0u;
            this->createArray(size);
        }
    }
    void Constructor(edk::vector::StackStaticCell* father,edk::uint32 size,edk::uint32 level){
        edk::vector::ArrayStatic<edk::classID>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->father=father;
            this->level = level;
            this->createArray(size);
            this->position=0u;
            this->readPosition=0u;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->clean();
            edk::vector::ArrayStatic<edk::classID>::Destructor();
        }
        edk::vector::ArrayStatic<edk::classID>::Destructor();
    }

    bool isLeaf(){return this->level==1u;}
    edk::uint32 getLevel(){return this->level;}
    edk::uint32 position;
    edk::uint32 readPosition;
    edk::vector::StackStaticCell* father;
private:
    edk::uint32 level;
private:
    edk::classID classThis;
};

template <class typeTemplate>
class StackStatic{
public:
    //Construtor
    StackStatic(){
        this->classThis=NULL;
        this->Constructor();
    }
    //Construtor with arraySize
    StackStatic(edk::uint32 arraySize){
        this->removed.Constructor();
        this->classThis=NULL;
        this->Constructor(arraySize);
    }
    //Destrutor
    virtual ~StackStatic(){
        this->Destructor();
    }

    //Construtor
    void Constructor(){
        this->removed.Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            //clean the vectors
            this->StackArraySize=PatternArraySize;
            this->stackSize=0u;

            this->root=NULL;

            this->rootPointer=&this->root;
            this->removedPointer=&this->removed;
            this->stackSizePointer=&this->stackSize;
            this->stackArraySizePointer=&this->StackArraySize;
        }
    }
    //Construtor with arraySize
    void Constructor(edk::uint32 arraySize){
        if(this->classThis!=this){
            this->classThis=this;

            this->removed.Constructor();

            //Test if the arraySize is bigger then zero
            if(arraySize){
                //
                this->StackArraySize=arraySize;
            }
            else{
                //else set the Pattern
                this->StackArraySize=PatternArraySize;
            }
            this->stackSize=0u;

            this->root=NULL;

            this->rootPointer=&this->root;
            this->removedPointer=&this->removed;
            this->stackSizePointer=&this->stackSize;
            this->stackArraySizePointer=&this->StackArraySize;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            //delete the array
            this->clean();
            //this->removed.cantDestructor();
            (*this->removedPointer).Destructor();

            this->removed.Destructor();
        }
    }

    //ADDS
    //pushBack the object
    edk::uint32 pushBack(typeTemplate obj){
        edk::uint32 ret=0u;
        //test if don't have the root
        if(!(*this->rootPointer)){
            //create a new root with the first array
            (*this->rootPointer)=new edk::vector::StackStaticCell();
            if(*this->rootPointer){
                (*this->rootPointer)->Constructor((*this->stackArraySizePointer),1u);
                //create the first array
                edk::vector::ArrayStatic<typeTemplate>* temp = new edk::vector::ArrayStatic<typeTemplate>();
                if(temp){
                    temp->Constructor((*this->stackArraySizePointer));
                    (*this->rootPointer)->set((*this->rootPointer)->position++,(edk::classID)temp);
                }
                else{
                    //else delete the root because we have a problem
                    (*this->rootPointer)->Destructor();
                    delete (*this->rootPointer);
                    (*this->rootPointer)=NULL;
                }
            }
        }
        //test if have the root
        if(*this->rootPointer){
            //first get the new position of the element
            edk::uint32 pos = 0u;
            edk::uint32 rest = 0u;

            edk::vector::StackStaticCell* temp = (*this->rootPointer);
            edk::vector::ArrayStatic<typeTemplate>* newStack;
            edk::vector::StackStaticCell* newCell;

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
                    pos+=searchPos*(*this->stackArraySizePointer)*temp->getLevel();

                    //test if are a leaf
                    if(temp->isLeaf()){
                        pos = ((*this->stackSizePointer))-pos;
                        rest = pos%(*this->stackArraySizePointer);
                        pos = searchPos;
                        edk::vector::ArrayStatic<typeTemplate>* leaf = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(pos);
                        if(temp){
                            leaf->set(rest,obj);
                            ret = (*this->stackSizePointer);
                            ((*this->stackSizePointer))++;

                            //test if need create a new stack
                            if(rest>=(*this->stackArraySizePointer)-1u){
                                while(temp){
                                    //have set the last in the array
                                    if(temp->position>=(*this->stackArraySizePointer)){
                                        //test uf have a father
                                        if(temp->father){
                                            //go into the father
                                            temp=temp->father;
                                        }
                                        else{
                                            //else is root
                                            (*this->rootPointer)=new edk::vector::StackStaticCell();
                                            if(*this->rootPointer){
                                                (*this->rootPointer)->Constructor((*this->stackArraySizePointer),temp->getLevel()*(*this->stackArraySizePointer));
                                                //
                                                temp->father=(*this->rootPointer);
                                                (*this->rootPointer)->set((*this->rootPointer)->position++,temp);
                                                temp=(*this->rootPointer);
                                            }
                                            else{
                                                //else it crash
                                                (*this->rootPointer)=temp;
                                                break;
                                            }
                                        }
                                    }
                                    else{
                                        //else just create a new cell or create a new array
                                        if(temp->isLeaf()){
                                            //create a new stack
                                            newStack = new edk::vector::ArrayStatic<typeTemplate>();
                                            if(newStack){
                                                newStack->Constructor((*this->stackArraySizePointer));
                                                temp->set(temp->position++,(edk::classID)newStack);
                                            }
                                            break;
                                        }
                                        else{
                                            //
                                            newCell = new edk::vector::StackStaticCell();
                                            if(newCell){
                                                newCell->Constructor((*this->stackArraySizePointer),temp->getLevel()/(*this->stackArraySizePointer));
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
                        temp=(edk::vector::StackStaticCell*)temp->get(searchPos);
                    }
                }
                else{
                }
            }
        }
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebug(this,ret,this->generateDebugValue(&obj),true);
#endif
        return ret;
    }

    //DELETE
    //Remove the top
    typeTemplate popBack(){
        typeTemplate ret;
        typeTemplate retTemp;
        memset(&ret,0u,sizeof(typeTemplate));

        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::vector::ArrayStatic<typeTemplate>* tempArray;
        edk::uint32 pos=0u;
        edk::uint32 positionRemove;
        edk::uint32 increment;
        //test if have root
        while(temp){
            if(temp->isLeaf()){
                if((*this->removedPointer).haveElement((*this->stackSizePointer))){
                    while(true){
                        positionRemove=(*this->stackSizePointer)-(pos + (*this->stackArraySizePointer)*temp->getLevel()*(temp->position-1u));
                        if(positionRemove){
                            //decrement the size
                            if((*this->stackSizePointer)){
                                (*this->stackSizePointer)--;
                            }
                        }
                        else{
                            tempArray = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->position-1u);
                            if(tempArray){
                                tempArray->Destructor();
                                delete tempArray;
                                temp->set(temp->position-1u,NULL);
                                temp->position--;
                                if(!temp->position){
                                    temp2 = temp;
                                    temp->father=temp;
                                    temp2->Destructor();
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
                    increment = (*this->stackArraySizePointer)*temp->getLevel()*(temp->position-1u);
                    pos += increment;

                    if(pos>=(*this->stackSizePointer)){
                        //remove the right
                        tempArray = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->position-1u);
                        if(tempArray){
                            temp->position--;
                            temp->set(temp->position,NULL);
                            tempArray->Destructor();
                            delete tempArray;
                            pos -= increment;

                            if(!temp->position){
                                //delete this temp
                                temp2 = temp;
                                temp=temp->father;
                                pos -= (*this->stackArraySizePointer)*temp->getLevel()*(temp->position-1u);
                                temp->set(temp->position-1u,NULL);
                                temp->position--;
                                temp2->Destructor();
                                delete temp2;
                            }
                        }
                    }
                    else{
                        if(!pos){
                            if((*this->stackSizePointer) && (*this->stackSizePointer)<=(*this->stackArraySizePointer)){
                                positionRemove=(*this->stackSizePointer)-1u;
                                tempArray = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->position-1u);
                                if(tempArray){
                                    retTemp = tempArray->get(positionRemove);
                                    //remove
                                    tempArray->set(positionRemove,ret);
                                    //
                                    memcpy(&ret,&retTemp,sizeof(typeTemplate));
                                    if((*this->stackSizePointer)){
                                        (*this->stackSizePointer)--;
                                    }
                                    if(!(*this->stackSizePointer)){
                                        //delete the array inside the root
                                        edk::uint32 size = (*this->rootPointer)->size();
                                        edk::vector::ArrayStatic<typeTemplate>* tempID;
                                        for(edk::uint32 i=0u;i<size;i++){
                                            tempID = (edk::vector::ArrayStatic<typeTemplate>*)(*this->rootPointer)->get(i);
                                            if(tempID){
                                                tempID->Destructor();
                                                delete tempID;
                                            }
                                        }
                                        (*this->rootPointer)->clean();
                                        (*this->rootPointer)->Destructor();
                                        delete (*this->rootPointer);
                                        (*this->rootPointer)=NULL;
                                    }
                                    break;
                                }
                            }
                        }
                        else{
                            pos++;
                            if(pos){
                                //test if have position
                                positionRemove = ((*this->stackSizePointer)-pos)%(*this->stackArraySizePointer);
                            }
                            else{
                                positionRemove = 0u;
                            }
                            tempArray = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->position-1u);
                            if(tempArray){
                                retTemp = tempArray->get(positionRemove);
                                //remove
                                tempArray->set(positionRemove,ret);
                                //
                                memcpy(&ret,&retTemp,sizeof(typeTemplate));
                                if((*this->stackSizePointer)){
                                    (*this->stackSizePointer)--;
                                }
                                if(!((*this->stackSizePointer))){
                                    (*this->rootPointer)->Destructor();
                                    delete (*this->rootPointer);
                                    (*this->rootPointer)=NULL;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            else if(temp->position){
                if(pos>=(*this->stackSizePointer)){
                    //test if have right
                    if(temp->position){
                        //go to right
                        pos += (*this->stackArraySizePointer)*temp->getLevel()*(temp->position-1u);
                        temp = (edk::vector::StackStaticCell*)temp->get(temp->position-1u);
                    }
                    else{
                        //remove the right
                        tempArray = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->position-1u);
                        if(tempArray){
                            temp->position--;
                            temp->set(temp->position,NULL);
                            tempArray->Destructor();
                            delete tempArray;
                            pos -= increment;

                            if(!temp->position){
                                //delete this temp
                                pos -= (*this->stackArraySizePointer)*temp->getLevel()*(temp->position-1u);
                                temp2 = temp;
                                temp=temp->father;
                                pos -= (*this->stackArraySizePointer)*temp->getLevel()*(temp->position-1u);
                                temp2->Destructor();
                                delete temp2;
                            }
                        }
                    }
                }
                else{
                    if(temp->position==1u && temp==(*this->rootPointer)){
                        //remove the root
                        (*this->rootPointer)=(edk::vector::StackStaticCell*)temp->get(temp->position-1u);
                        temp->Destructor();
                        delete temp;
                        temp=(*this->rootPointer);
                    }
                    else{
                        pos += (*this->stackArraySizePointer)*temp->getLevel()*(temp->position-1u);
                        temp = (edk::vector::StackStaticCell*)temp->get(temp->position-1u);
                    }
                }
            }
            else{
                //remove the cell
                temp2 = temp;
                temp=temp->father;
                pos -= (*this->stackArraySizePointer)*temp->getLevel()*(temp->position-1u);
                temp->set(temp->position-1u,NULL);
                temp->position--;
                temp2->Destructor();
                delete temp2;
            }
        }

#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebugNoPosition(this,this->generateDebugValue(&ret),false);
#endif
        return ret;
    }
    //delete all Stack
    void deleteStack(){
        //clean
        this->clean();
    }
    //Copy the values inside the stack to a vector
    bool copyToVector(typeTemplate* vector){
        if(vector){
            edk::vector::StackStaticCell* temp = (*this->rootPointer);
            edk::vector::StackStaticCell* temp2;
            edk::uint32 position=0u;
            edk::uint32 size;
            edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
            edk::uint32 i=0u;
            if(temp){
                temp->readPosition=0u;
                if((*this->removedPointer).size()){
                    while(temp){
                        //test if are a leaf
                        if(temp->isLeaf()){
                            if(temp->readPosition<(*this->stackArraySizePointer)){
                                if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                    arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                    if(arrayTemp){
                                        size = (*this->stackSizePointer);
                                        i=0u;
                                        while(position<size){
                                            if(!(*this->removedPointer).haveElement(position)){
                                                vector[0u] = arrayTemp->get(i);
                                                vector++;
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
                                    arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                    if(arrayTemp){
                                        for(i=0u;i<(*this->stackArraySizePointer);i++){
                                            if(!(*this->removedPointer).haveElement(position)){
                                                vector[0u] = arrayTemp->get(i);
                                                vector++;
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
                            if(temp->readPosition>=(*this->stackArraySizePointer)){
                                //else go to the father
                                temp = temp->father;
                            }
                            else {
                                temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                            if(temp->readPosition<(*this->stackArraySizePointer)){
                                if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                    arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                    if(arrayTemp){
                                        size = (*this->stackSizePointer);
                                        i=0u;
                                        while(position<size){
                                            vector[0u] = arrayTemp->get(i);
                                            vector++;
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
                                    arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                    if(arrayTemp){
                                        for(i=0u;i<(*this->stackArraySizePointer);i++){
                                            vector[0u] = arrayTemp->get(i);
                                            vector++;
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
                            if(temp->readPosition>=(*this->stackArraySizePointer)){
                                //else go to the father
                                temp = temp->father;
                            }
                            else {
                                temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::vector::ArrayStatic<typeTemplate>* tempArray;
        while(temp){
            if(temp->isLeaf()){
                while(temp->position){
                    tempArray = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->position-1u);
                    if(tempArray){
                        tempArray->Destructor();
                        delete tempArray;
                        temp->position--;
                    }
                }
                //delete the leaf
                if(temp->father){
                    temp2=temp->father;
                    temp->Destructor();
                    delete temp;
                    temp2->set(temp2->position-1u,NULL);
                    temp2->position--;
                    temp=temp2;
                }
                else if((*this->rootPointer) == temp){
                    (*this->rootPointer)->Destructor();
                    delete (*this->rootPointer);
                    (*this->rootPointer)=NULL;
                    temp=NULL;
                }
                else{
                    //it's broked
                    break;
                }
            }
            else if(temp->position>=1u){
                //
                temp = (edk::vector::StackStaticCell*)temp->get(temp->position-1u);
            }
            else{
                //delete the leaf
                if(temp->father){
                    temp2=temp->father;
                    temp->Destructor();
                    delete temp;
                    temp2->set(temp2->position-1u,NULL);
                    temp2->position--;
                    temp=temp2;
                }
                else if((*this->rootPointer) == temp){
                    (*this->rootPointer)->Destructor();
                    delete (*this->rootPointer);
                    (*this->rootPointer)=NULL;
                    temp=NULL;
                }
                else{
                    //it's broked
                    break;
                }
            }
        }
        (*this->stackSizePointer)=0u;
    }
    //Clean changing the Stack ArraySize
    void clean(edk::uint32 arraySize){
        //
        this->clean();
        if(arraySize){
            //
            (*this->stackArraySizePointer)=arraySize;
        }
        else{
            //else set the Pattern
            (*this->stackArraySizePointer)=PatternArraySize;
        }
    }

    //remove the element
    typeTemplate remove(edk::uint32 pos){
        typeTemplate ret;
        //Test if don't have the element
        if(this->havePos(pos)){
            //tets if pos is the last
            if(pos==((*this->stackSizePointer))-1u){
                //then popBack
                ret = this->popBack();

#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebug(this,pos,this->generateDebugValue(&ret),true);
#endif
                return ret;
            }
            //get the element value
            //memcpy((void*)&ret,(void*)&this->get(arrayPos),sizeof(typeTemplate));
            ret = this->get(pos);
            typeTemplate set;  memset((void*)&set,0u,sizeof(typeTemplate));
            //then clean the pos
            if(this->set(pos,set)){
                //and add the pos in to removed
                (*this->removedPointer).add(pos);

                //return the ret

#if defined(EDK_DEBUG_VECTOR)
                edkWriteClassDebug(this,pos,this->generateDebugValue(&ret),true);
#endif
                return ret;
            }
            //else clean the ret
        }
        //else return false
        memset((void*)&ret,0u,sizeof(typeTemplate));
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebug(this,pos,this->generateDebugValue(&ret),false);
#endif
        return ret;
    }

    //SETTERS
    bool set(edk::uint32 pos,typeTemplate obj){
        //test if have the pos
        if(this->havePos(pos)){
            edk::vector::StackStaticCell* temp = root;
            edk::vector::ArrayStatic<typeTemplate>* tempArray;
            edk::uint32 posNew;
            edk::uint32 rest;
            edk::uint32 increment;
            while(temp){
                //test if are leaf
                if(temp->isLeaf()){
                    //get the position
                    posNew = pos/(*this->stackArraySizePointer);
                    rest = pos%(*this->stackArraySizePointer);

                    //test if have the position
                    if(posNew<temp->position){
                        tempArray = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(posNew);
                        if(tempArray){
                            bool ret = tempArray->set(rest,obj);
#if defined(EDK_DEBUG_VECTOR)
                            edkWriteClassDebug(this,pos,this->generateDebugValue(&obj),ret);
#endif
                            return ret;
                        }
                    }
                }
                else{
                    //else search
                    for(edk::uint32 i=temp->position;i>0u;--i){
                        increment = (i-1u)*(*this->stackArraySizePointer)*temp->getLevel();
                        if(pos>=increment){
                            //find it
                            pos-=increment;
                            temp=(edk::vector::StackStaticCell*)temp->get(i-1u);
                            break;
                        }
                    }
                }
            }
        }
        //else return NULL
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebug(this,pos,this->generateDebugValue(&obj),false);
#endif
        return false;
    }

    //GETTERS
    //get the object
    typeTemplate get(edk::uint32 pos){
        //test if have the pos
        if(this->havePos(pos)){
            edk::vector::StackStaticCell* temp = root;
            edk::vector::ArrayStatic<typeTemplate>* tempArray;
            edk::uint32 posNew;
            edk::uint32 rest;
            edk::uint32 increment;
            while(temp){
                //test if are leaf
                if(temp->isLeaf()){
                    //get the position
                    posNew = pos/(*this->stackArraySizePointer);
                    rest = pos%(*this->stackArraySizePointer);

                    //test if have the position
                    if(posNew<temp->position){
                        tempArray = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(posNew);
                        if(tempArray){
                            typeTemplate ret = tempArray->get(rest);
#if defined(EDK_DEBUG_VECTOR)
                            edkWriteClassDebug(this,pos,this->generateDebugValue(&ret),true);
#endif
                            return ret;
                        }
                    }
                }
                else{
                    //else search
                    for(edk::uint32 i=temp->position;i>0u;--i){
                        increment = (i-1u)*(*this->stackArraySizePointer)*temp->getLevel();
                        if(pos>=increment){
                            //find it
                            pos-=increment;
                            temp=(edk::vector::StackStaticCell*)temp->get(i-1u);
                            break;
                        }
                    }
                }
            }
        }
        //else return false
        typeTemplate ret;  memset((void*)&ret,0u,sizeof(typeTemplate));
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebug(this,pos,this->generateDebugValue(&ret),false);
#endif
        return ret;
    }
    //load the objects inside the stack
    virtual bool load(){
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->loadElement(arrayTemp->get(i));
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->loadElement(arrayTemp->get(i));
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        this->loadElement(arrayTemp->get(i));
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        this->loadElement(arrayTemp->get(i));
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->unloadElement(arrayTemp->get(i));
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->unloadElement(arrayTemp->get(i));
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        this->unloadElement(arrayTemp->get(i));
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        this->unloadElement(arrayTemp->get(i));
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->updateElement(arrayTemp->get(i));
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->updateElement(arrayTemp->get(i));
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        this->updateElement(arrayTemp->get(i));
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        this->updateElement(arrayTemp->get(i));
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->printElement(arrayTemp->get(i));
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->printElement(arrayTemp->get(i));
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        this->printElement(arrayTemp->get(i));
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        this->printElement(arrayTemp->get(i));
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->renderElement(arrayTemp->get(i));
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->renderElement(arrayTemp->get(i));
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        this->renderElement(arrayTemp->get(i));
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        this->renderElement(arrayTemp->get(i));
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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

    //load the objects inside the stack
    virtual bool loadWithID(){
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->loadElementWithID(arrayTemp->get(i),position);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->loadElementWithID(arrayTemp->get(i),position);
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        this->loadElementWithID(arrayTemp->get(i),position);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        this->loadElementWithID(arrayTemp->get(i),position);
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
    virtual bool unloadWithID(){
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->unloadElementWithID(arrayTemp->get(i),position);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->unloadElementWithID(arrayTemp->get(i),position);
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        this->unloadElementWithID(arrayTemp->get(i),position);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        this->unloadElementWithID(arrayTemp->get(i),position);
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
    virtual bool updateWithID(){
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->updateElementWithID(arrayTemp->get(i),position);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->updateElementWithID(arrayTemp->get(i),position);
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        this->updateElementWithID(arrayTemp->get(i),position);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        this->updateElementWithID(arrayTemp->get(i),position);
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
    virtual bool printWithID(){
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->printElementWithID(arrayTemp->get(i),position);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->printElementWithID(arrayTemp->get(i),position);
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        this->printElementWithID(arrayTemp->get(i),position);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        this->printElementWithID(arrayTemp->get(i),position);
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
    virtual bool renderWithID(){
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->renderElementWithID(arrayTemp->get(i),position);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
                                            this->renderElementWithID(arrayTemp->get(i),position);
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        this->renderElementWithID(arrayTemp->get(i),position);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        this->renderElementWithID(arrayTemp->get(i),position);
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
        return this->size();
    }
    //return the size
    inline edk::uint32 size(){
        return (*this->stackSizePointer);
    }
    edk::uint32 sizeRemoved(){
        return (*this->removedPointer).size();
    }

    //test if have the pos
    bool havePos(edk::uint32 pos){
        //test if the pos is less then size
        if(pos<(*this->stackSizePointer)){
            //then test if don't have the pos in removed
            if(!(*this->removedPointer).haveElement(pos)){
                //then return true
                return true;
            }
        }
        //else return false
        return false;
    }
    //find the position of the object
    edk::uint32 find(typeTemplate obj){
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
        edk::vector::StackStaticCell* temp = (*this->rootPointer);
        edk::vector::StackStaticCell* temp2;
        edk::uint32 position=0u;
        edk::uint32 size;
        edk::vector::ArrayStatic<typeTemplate>* arrayTemp;
        edk::uint32 i=0u;
        if(temp){
            temp->readPosition=0u;
            if((*this->removedPointer).size()){
                while(temp){
                    //test if are a leaf
                    if(temp->isLeaf()){
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
                                    i=0u;
                                    while(position<size){
                                        if(!(*this->removedPointer).haveElement(position)){
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
                                        if(!(*this->removedPointer).haveElement(position)){
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
                        if(temp->readPosition<(*this->stackArraySizePointer)){
                            if(position+(*this->stackArraySizePointer)>(*this->stackSizePointer)){
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    size = (*this->stackSizePointer);
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
                                arrayTemp=(edk::vector::ArrayStatic<typeTemplate>*)temp->get(temp->readPosition++);
                                if(arrayTemp){
                                    for(i=0u;i<(*this->stackArraySizePointer);i++){
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
                        if(temp->readPosition>=(*this->stackArraySizePointer)){
                            //else go to the father
                            temp = temp->father;
                        }
                        else {
                            temp2 = (edk::vector::StackStaticCell*)temp->get(temp->readPosition++);
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
        if(pos1<(*this->stackSizePointer) && pos2<(*this->stackSizePointer)){
            //bool getPosition2(edk::uint32 pos,edk::vector::ArrayStatic<typeTemplate>* array[],edk::uint32* posArray);
            edk::vector::ArrayStatic<typeTemplate>* array1=NULL;
            edk::uint32 posArray1=0u;
            edk::vector::ArrayStatic<typeTemplate>* array2=NULL;
            edk::uint32 posArray2=0u;

            if(this->getPosition(pos1,&array1,&posArray1)
                    &&
                    this->getPosition(pos2,&array2,&posArray2)
                    ){
                //change the position
                typeTemplate type = array2->get(posArray2);
                array2->set(posArray2,array1->get(posArray1));
                array1->set(posArray1,type);
                bool have1=(*this->removedPointer).haveElement(posArray1),have2=(*this->removedPointer).haveElement(posArray2);
                if(have1!=have2){
                    if(have1){
                        (*this->removedPointer).remove(have1);
                        (*this->removedPointer).add(have2);
                    }
                    else{
                        (*this->removedPointer).remove(have2);
                        (*this->removedPointer).add(have1);
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
        if(this->havePos(position) && position<((*this->stackSizePointer)-1u)){
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

    //OPERATORS
    /*
    //[] //To return the object in the pos
    typeTemplate operator[](edk::uint32 pos){
        //
        return this->get(pos);
    }
    */
    virtual bool cloneFrom(edk::vector::StackStatic<typeTemplate>* ret){
        //clean the vector
        this->clean();
        if(ret){
            //copy the types from the ret
            for(edk::uint32 i=0u;i<ret->size();i++){
                //copy
                this->pushBack(ret->get(i));
            }
            return true;
        }
        return false;
    }
protected:
    virtual void loadElement(typeTemplate){}
    virtual void loadElementWithID(typeTemplate,edk::uint32){}
    virtual void unloadElement(typeTemplate){}
    virtual void unloadElementWithID(typeTemplate,edk::uint32){}
    virtual void updateElement(typeTemplate){}
    virtual void updateElementWithID(typeTemplate,edk::uint32){}
    virtual void printElement(typeTemplate){}
    virtual void printElementWithID(typeTemplate,edk::uint32){}
    virtual void renderElement(typeTemplate){}
    virtual void renderElementWithID(typeTemplate,edk::uint32){}
    virtual bool elementEqual(typeTemplate ,typeTemplate ){return false;}
private:
    //Have the first cel
    edk::vector::StackStaticCell** rootPointer;
    edk::vector::StackStaticCell* root;

    //Have a binary of the removed positions
    edk::vector::BinaryTreeStatic<edk::uint32>* removedPointer;
    edk::vector::BinaryTreeStatic<edk::uint32> removed;

    //size of the Stack
#if defined(__arch64__) || defined(_LP64)
    edk::uint64* stackSizePointer;
    edk::uint64 stackSize;
#elif defined(__arch32__) || defined(_LP32)
    edk::uint32* stackSizePointer;
    edk::uint32 stackSize;
#else
    //another system
    edk::uint32* stackSizePointer;
    edk::uint32 stackSize;
#endif

    //Size of the array on the stack
    edk::uint32* stackArraySizePointer;
    edk::uint32 StackArraySize;

    //get the position in the stack
    bool getPosition(edk::uint32 pos,edk::vector::ArrayStatic<typeTemplate>* array[],edk::uint32* posArray){
        if(array && posArray){



            //test if have the pos
            if(this->havePos(pos)){
                edk::vector::StackStaticCell* temp = root;
                edk::vector::ArrayStatic<typeTemplate>* tempArray;
                edk::uint32 posNew;
                edk::uint32 rest;
                edk::uint32 increment;
                while(temp){
                    //test if are leaf
                    if(temp->isLeaf()){
                        //get the position
                        posNew = pos/(*this->stackArraySizePointer);
                        rest = pos%(*this->stackArraySizePointer);

                        //test if have the position
                        if(posNew<temp->position){
                            tempArray = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(posNew);
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
                            increment = (i-1u)*(*this->stackArraySizePointer)*temp->getLevel();
                            if(pos>=increment){
                                //find it
                                pos-=increment;
                                temp=(edk::vector::StackStaticCell*)temp->get(i-1u);
                                break;
                            }
                        }
                    }
                }
            }








            //test if have the pos
            if(this->havePos(pos)){
                edk::vector::StackStaticCell* temp = root;
                edk::vector::ArrayStatic<typeTemplate>* tempArray;
                edk::uint32 posNew;
                edk::uint32 rest;
                edk::uint32 increment;
                while(temp){
                    //test if are leaf
                    if(temp->isLeaf()){
                        //get the position
                        posNew = pos/(*this->stackArraySizePointer);
                        rest = pos%(*this->stackArraySizePointer);

                        //test if have the position
                        if(posNew<temp->position){
                            tempArray = (edk::vector::ArrayStatic<typeTemplate>*)temp->get(posNew);
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
                            increment = (i-1u)*(*this->stackArraySizePointer)*temp->getLevel();
                            if(pos>=increment){
                                //find it
                                pos-=increment;
                                temp=(edk::vector::StackStaticCell*)temp->get(i-1u);
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
    edk::vector::StackStatic<typeTemplate> operator=(edk::vector::StackStatic<typeTemplate> ret){
        return ret;
    }
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

class StackStaticNames: private edk::vector::StackStatic<edk::Name*>{
public:
    StackStaticNames(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~StackStaticNames(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::StackStatic<edk::Name*>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;

            this->tree.Constructor();

            this->treePointer=&this->tree;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->clean();

            this->tree.Destructor();
        }
        edk::vector::StackStatic<edk::Name*>::Destructor();
    }

    //ADDS
    //pushBack the object
    edk::uint32 pushBack(const edk::char8* str){
        return this->pushBack((edk::char8*) str);
    }
    edk::uint32 pushBack(edk::char8* str){
        //test the string
        if(str){
            //create a new Name
            edk::Name* name = new edk::Name;
            if(name){
                //set the name
                if(name->setName(str)){
                    edk::uint32 size = edk::vector::StackStatic<edk::Name*>::size();
                    edk::uint32 pos= edk::vector::StackStatic<edk::Name*>::pushBack(name);
                    if(size<edk::vector::StackStatic<edk::Name*>::size()){
                        //push the position
                        (*this->treePointer).add(pos);
                        return pos;
                    }
                }
                delete name;
            }
        }
        //else return false
        return 0u;
    }
    edk::uint32 pushBack(edk::Name* name){
        return edk::vector::StackStatic<edk::Name*>::pushBack(name);
    }

    //DELETE
    //Remove the top
    bool popBack(){
        if(edk::vector::StackStatic<edk::Name*>::size()){
            edk::Name* name = edk::vector::StackStatic<edk::Name*>::popBack();
            if(name){
                //test if need remove the name
                if((*this->treePointer).haveElement(edk::vector::StackStatic<edk::Name*>::size())){
                    (*this->treePointer).remove(edk::vector::StackStatic<edk::Name*>::size());
                    //delete the last name removed
                    delete name;
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
        this->clean();
    }
    //clean the Stack
    void clean(){
        //delete all the names
        this->_deleteAllNames();
        //in the end it need clean the stack with deleted pointers
        edk::vector::StackStatic<edk::Name*>::clean();
    }
    //Clean changing the Stack ArraySize
    void clean(edk::uint32 arraySize){
        //delete all the names
        this->_deleteAllNames();
        //in the end it need clean the stack with deleted pointers
        edk::vector::StackStatic<edk::Name*>::clean(arraySize);
    }

    //remove the element
    bool remove(edk::uint32 pos){
        //get the name in the position
        edk::Name* name = edk::vector::StackStatic<edk::Name*>::get(pos);
        if(name){
            //remove
            if(edk::vector::StackStatic<edk::Name*>::remove(pos)){
                //test if have the name position to delete
                if((*this->treePointer).haveElement(pos)){
                    (*this->treePointer).remove(pos);
                    //delete the name
                    delete name;
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
            edk::Name* name = edk::vector::StackStatic<edk::Name*>::get(pos);
            if(name){
                //test if have the position in the tree
                if((*this->treePointer).haveElement(pos)){
                    //set the new string
                    return name->setName(str);
                }
            }
        }
        //else return NULL
        return false;
    }
    bool set(edk::uint32 pos,edk::Name* nameObject){
        if(nameObject){
            //get the name in the position
            edk::Name* name = edk::vector::StackStatic<edk::Name*>::get(pos);
            if(name){
                //test if have the position in the tree
                if((*this->treePointer).haveElement(pos)){
                    (*this->treePointer).remove(pos);
                    //set the new object
                    if(edk::vector::StackStatic<edk::Name*>::set(pos,nameObject)){
                        //delete the temp
                        delete name;
                    }
                }
                else{
                    //else just set the object
                    return edk::vector::StackStatic<edk::Name*>::set(pos,nameObject);
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
            edk::Name* name = edk::vector::StackStatic<edk::Name*>::get(pos);
            if(name){
                //return the string
                return name;
            }
        }
        //else return NULL
        return NULL;
    }
    //get the object
    edk::char8* getName(edk::uint32 pos){
        //else return false
        edk::char8* ret=NULL;
        if(this->havePos(pos)){
            //get the name in the position
            edk::Name* name = edk::vector::StackStatic<edk::Name*>::get(pos);
            if(name){
                //return the string
                ret = name->getName();
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
        return edk::vector::StackStatic<edk::Name*>::getSize();
    }
    //return the size
    edk::uint32 size(){
        //
        return edk::vector::StackStatic<edk::Name*>::size();
    }
    edk::uint32 sizeRemoved(){
        return edk::vector::StackStatic<edk::Name*>::sizeRemoved();
    }

    //test if have the pos
    bool havePos(edk::uint32 pos){
        if(pos<this->size()){
            //get the name in the position
            edk::Name* name = edk::vector::StackStatic<edk::Name*>::get(pos);
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
        return this->find((edk::char8*) str);
    }
    edk::uint32 find(edk::char8* str){
        //find the string in the stack
        edk::Name* name=NULL;
        edk::uint32 size = edk::vector::StackStatic<edk::Name*>::size();
        for(edk::uint32 i=0u;i<size;i++){
            name = edk::vector::StackStatic<edk::Name*>::get(i);
            if(name){
                if(edk::String::strCompare(name->getName(),str)){
                    return i;
                }
            }
        }
        return 0u;
    }
    bool haveString(const edk::char8* str){
        return this->haveString((edk::char8*) str);
    }
    bool haveString(edk::char8* str){
        //find the string in the stack
        edk::Name* name=NULL;
        edk::uint32 size = edk::vector::StackStatic<edk::Name*>::size();
        for(edk::uint32 i=0u;i<size;i++){
            name = edk::vector::StackStatic<edk::Name*>::get(i);
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
        if((*this->treePointer).haveElement(pos1) && !(*this->treePointer).haveElement(pos2)){
            if(edk::vector::StackStatic<edk::Name*>::swap(pos1,pos2)){
                //swap the positions in the tree
                (*this->treePointer).remove(pos1);
                (*this->treePointer).add(pos2);
                return true;
            }
        }
        else if((*this->treePointer).haveElement(pos2)){
            if(edk::vector::StackStatic<edk::Name*>::swap(pos1,pos2)){
                //swap the positions in the tree
                (*this->treePointer).remove(pos2);
                (*this->treePointer).add(pos1);
                return true;
            }
        }
        //else just swap
        return edk::vector::StackStatic<edk::Name*>::swap(pos1,pos2);
    }

    //Move position object
    bool bringPositionPlusOne(edk::uint32 position){
        if(edk::vector::StackStatic<edk::Name*>::size()>position+1u){
            //test if have created some position
            if((*this->treePointer).haveElement(position) && !(*this->treePointer).haveElement(position+1u)){
                if(edk::vector::StackStatic<edk::Name*>::bringPositionPlusOne(position)){
                    //swap the positions in the tree
                    (*this->treePointer).remove(position);
                    (*this->treePointer).add(position+1u);
                    return true;
                }
            }
            else if((*this->treePointer).haveElement(position+1u)){
                if(edk::vector::StackStatic<edk::Name*>::bringPositionPlusOne(position)){
                    //swap the positions in the tree
                    (*this->treePointer).remove(position+1u);
                    (*this->treePointer).add(position);
                    return true;
                }
            }
        }
        //else just swap
        return edk::vector::StackStatic<edk::Name*>::bringPositionPlusOne(position);
    }
    bool bringPositionMinusOne(edk::uint32 position){
        if(position && edk::vector::StackStatic<edk::Name*>::size()>position){
            //test if have created some position
            if((*this->treePointer).haveElement(position) && !(*this->treePointer).haveElement(position-1u)){
                if(edk::vector::StackStatic<edk::Name*>::bringPositionMinusOne(position)){
                    //swap the positions in the tree
                    (*this->treePointer).remove(position);
                    (*this->treePointer).add(position-1u);
                    return true;
                }
            }
            else if((*this->treePointer).haveElement(position-1u)){
                if(edk::vector::StackStatic<edk::Name*>::bringPositionMinusOne(position)){
                    //swap the positions in the tree
                    (*this->treePointer).remove(position-1u);
                    (*this->treePointer).add(position);
                    return true;
                }
            }
        }
        //else just swap
        return edk::vector::StackStatic<edk::Name*>::bringPositionMinusOne(position);
    }
    //Move a count
    bool bringPositionPlusTimes(edk::uint32 position,edk::uint32 times){
        if(edk::vector::StackStatic<edk::Name*>::size()>position+times){
            edk::uint32 size = position+times;
            for(edk::uint32 i=position;i<size;i++){
                this->bringPositionPlusOne(i);
            }
            return true;
        }
        return false;
    }
    bool bringPositionMinusTimes(edk::uint32 position,edk::uint32 times){
        if(position>times && edk::vector::StackStatic<edk::Name*>::size()>position){
            edk::uint32 limit = position - times;
            for(edk::uint32 i=position;i>limit;i--){
                this->bringPositionMinusOne(i-1u);
            }
            return true;
        }
        return false;
    }
    bool bringPositionTo(edk::uint32 position,edk::uint32 position2){
        if(position>position2){
            return this->bringPositionMinusTimes(position2,position-position2);
        }
        else if(position<position2){
            return this->bringPositionPlusTimes(position,position2-position);
        }
        return false;
    }

    //OPERATORS
    /*
    //[] //To return the object in the pos
    edk::Name* operator[](edk::uint32 pos){
        //
        return this->get(pos);
    }
    */
    virtual bool cloneFrom(edk::vector::StackStaticNames* ret){
        //clean the vector
        this->clean();
        if(ret){
            //copy the types from the ret
            for(edk::uint32 i=0u;i<ret->size();i++){
                //copy
                this->pushBack(ret->get(i));
            }
            return true;
        }
        return false;
    }
private:
    void _deleteAllNames(){
        //remove all the names on the stack
        edk::Name* name=NULL;
        edk::uint32 size = edk::vector::StackStatic<edk::Name*>::size();
        for(edk::uint32 i=0u;i<size;i++){
            name = edk::vector::StackStatic<edk::Name*>::get(i);
            if(name){
                //test if need delete the name
                if((*this->treePointer).haveElement(i)){
                    delete name;
                }
            }
        }
        //delete all positions
        (*this->treePointer).clean();
    }
    //tree with the positions created by the stack
    edk::vector::BinaryTreeStatic<edk::uint32>*treePointer;
    edk::vector::BinaryTreeStatic<edk::uint32>tree;
private:
    edk::classID classThis;
};

}//end namespace vector
}//end namespace edk

#endif // STACKSTATIC_H
