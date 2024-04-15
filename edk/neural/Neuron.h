#ifndef NEURON_H
#define NEURON_H

/*
Neuron - Neuron used in the Neural Network.
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
#pragma message "Inside neural::Neuron"
#endif

#pragma once
#include "stdio.h"
#include "../NameClass.h"
#include "../vector/BinaryTree.h"

#ifdef printMessages
#pragma message "    Compiling neural::Neuron"
#endif


namespace edk{
namespace neural{
//Use a template to alloc whatever
template <class typeTemplate>
class Neuron;
template <class typeTemplate>
class Value: public edk::Name{
public:
    Value(){this->classThis=NULL;edkEnd();
            this->Constructor(false);edkEnd();}
    ~Value(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            this->cleanName();edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::Name::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
            this->value = (typeTemplate)0u;edkEnd();
            this->neuron = NULL;edkEnd();
        }
    }
    typeTemplate value;
    edk::neural::Neuron<typeTemplate> *neuron;
private:
    edk::classID classThis;
};
template <class typeTemplate>
class NameValues: private edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>{
public:
    NameValues(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    ~NameValues(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            this->clean();edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;
        }
    }

    //clean the values
    void clean(){
        edk::neural::Value<typeTemplate>* temp;edkEnd();
        edk::uint32 sizeV = this->size();edkEnd();
        for(edk::uint32 i=0u;i<sizeV;i++){
            //
            temp = edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::getElementInPosition(i);edkEnd();
            if(temp){
                delete temp;edkEnd();
            }
        }
        edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::clean();edkEnd();
    }
    bool remove(const edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        return this->remove((edk::char8*) name,neuron);edkEnd();
    }
    bool remove(edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        //get the element
        edk::neural::Value<typeTemplate>* temp = this->getElement(name,neuron);edkEnd();
        if(temp){
            //remove the element
            edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::remove(temp);edkEnd();
            delete temp;edkEnd();
            return true;
        }
        return false;
    }
    edk::uint32 size(){return edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::size();edkEnd();}
    edk::uint32 getSize(){return edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::size();edkEnd();}
    //add a new values
    bool add(const edk::char8* name,typeTemplate value,edk::neural::Neuron<typeTemplate> *neuron){
        return this->add((edk::char8*) name,value,neuron);edkEnd();
    }
    bool add(edk::char8* name,typeTemplate value,edk::neural::Neuron<typeTemplate> *neuron){
        //validate the pointers
        if(name && neuron){
            //test if don't have this values
            edk::neural::Value<typeTemplate>* temp;edkEnd();
            if(!(temp = this->getElement(name,neuron))){
                //create a new values
                temp = new edk::neural::Value<typeTemplate>;edkEnd();
                if(temp){
                    //set the values
                    if(temp->setName(name)){
                        temp->value = value;edkEnd();
                        temp->neuron = neuron;edkEnd();
                        if(edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::add(temp)){
                            return true;
                        }
                    }
                    delete temp;edkEnd();
                }
            }
            else{
                //else just set the values
                if(temp->setName(name)){
                    temp->value = value;edkEnd();
                    temp->neuron = neuron;edkEnd();
                    if(edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::add(temp)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool haveElement(const edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        return this->haveElement((edk::char8*) name,neuron);edkEnd();
    }
    bool haveElement(edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        if(this->getElement(name,neuron)){
            return true;
        }
        return false;
    }
    //get the values from the tree
    edk::neural::Value<typeTemplate>* getElement(const edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        this->getElement((edk::char8*) name,neuron);edkEnd();
    }
    edk::neural::Value<typeTemplate>* getElement(edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        //
        edk::neural::Value<typeTemplate> temp;edkEnd();
        temp.setName(name);edkEnd();
        temp.neuron = neuron;edkEnd();
        return edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::getElement(&temp);
    }
    edk::neural::Value<typeTemplate>* getElementInPosition(edk::uint32 position){
        return edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::getElementInPosition(position);edkEnd();
    }
    typeTemplate getValue(edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        //
        edk::neural::Value<typeTemplate>* temp = this->getElement(name,neuron);edkEnd();
        if(temp){
            return temp->value;edkEnd();
        }
        return (typeTemplate)0u;edkEnd();
    }
private:
    //Virtual Functions
    bool firstBiggerSecond(edk::neural::Value<typeTemplate>* first,edk::neural::Value<typeTemplate>* second){
        //test the values
        if(first && second){
            if(first->neuron>second->neuron){
                return true;
            }
            else if(first->neuron==second->neuron && first->nameBiggerThan(second->getName())){
                return true;
            }
        }
        return false;
    }
    bool firstEqualSecond(edk::neural::Value<typeTemplate>* first,edk::neural::Value<typeTemplate>* second){
        //test the values
        if(first && second){
            //then thes the strings
            if(first->nameEqual(second->getName()) && first->neuron==second->neuron){
                return true;
            }
        }
        return false;
    }
private:
    edk::classID classThis;
};
template <class typeTemplate>
class Network;
//Use a template to alloc whatever
template <class typeTemplate>
class Neuron: public edk::Name{
public:
    Neuron(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);edkEnd();
    }
    ~Neuron(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
            this->cleanWeights();edkEnd();
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){
            edk::Name::Constructor();edkEnd();
        }
        if(this->classThis!=this){
            this->classThis=this;

            //the sum of all values inside the neuron
            this->treeWeights.Constructor();edkEnd();

            this->haveSum=false;edkEnd();
            this->sum=0;edkEnd();
        }
    }

    //friend class is a class who can access the private values from another class
    friend edk::neural::Network<typeTemplate>;

    //clean the values
    inline void cleanWeights(){
        edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp;edkEnd();
        edk::uint32 size = this->treeWeights.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp=(edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementInPosition(i);edkEnd();
            if(temp){
                delete temp;edkEnd();
            }
        }
        this->treeWeights.clean();edkEnd();
    }
    //connect the entrance by the name
    bool setConnected(const edk::char8* name,edk::neural::Neuron<typeTemplate>* n){
        return this->setConnected((edk::char8*) name,n);edkEnd();
    }
    inline bool setConnected(edk::char8* name,edk::neural::Neuron<typeTemplate>* n){
        return this->privateSetConnected(name,n);edkEnd();
    }
    bool removeConnected(const edk::char8* name){
        return this->removeConnected((edk::char8*) name);edkEnd();
    }
    inline bool removeConnected(edk::char8* name){
        if(name){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);edkEnd();
            if(temp){
                //remove the connected
                temp->connected = NULL;edkEnd();
                return true;
            }
        }
        return false;
    }
    bool newWeight(const edk::char8* name,edk::int32 Weight){
        return this->newWeight((edk::char8*) name,Weight);edkEnd();
    }
    inline bool newWeight(edk::char8* name){
        if(name){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);edkEnd();
            if(!temp){
                temp = new edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>;edkEnd();
                if(temp->setName(name)){
                    //add to the tree
                    if(this->treeWeights.add(temp)){
                        temp->weight = 0.f;edkEnd();
                        return true;
                    }
                }
                //else delete the temp
                delete temp;edkEnd();
                temp=NULL;edkEnd();
            }
        }
        return false;
    }
    bool setWeight(const edk::char8* name,edk::int32 Weight){
        return this->setWeight((edk::char8*) name,Weight);edkEnd();
    }
    inline bool setWeight(edk::char8* name,edk::int32 Weight){
        if(name){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);edkEnd();
            if(!temp){
                temp = new edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>;edkEnd();
                if(temp->setName(name)){
                    //add to the tree
                    if(this->treeWeights.add(temp)){
                        temp->weight = Weight;edkEnd();
                        return true;
                    }
                }
                //else delete the temp
                delete temp;edkEnd();
                temp=NULL;edkEnd();
            }
            if(temp){
                temp->weight = Weight;edkEnd();
                return true;
            }
        }
        return false;
    }
    typeTemplate getWeightValue(const edk::char8* name){
        return this->getWeightValue((edk::char8*) name);edkEnd();
    }
    inline typeTemplate getWeightValue(edk::char8* name){
        typeTemplate ret;
        if(name){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);edkEnd();
            if(temp){
                return temp->weight;
            }
        }
        memset(&ret,0u,sizeof(typeTemplate));
        return ret;edkEnd();
    }
    bool getWeightValue(const edk::char8* name,typeTemplate* dest){
        return this->getWeightValue((edk::char8*) name,dest);edkEnd();
    }
    inline bool getWeightValue(edk::char8* name,typeTemplate* dest){
        if(name && dest){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);edkEnd();
            if(temp){
                memcpy(dest,&temp->weight,sizeof(typeTemplate));
            }
        }
        return false;edkEnd();
    }
    edk::neural::Neuron<typeTemplate> * getWeightConnection(const edk::char8* name){
        return this->getWeightConnection((edk::char8*) name);edkEnd();
    }
    inline edk::neural::Neuron<typeTemplate> * getWeightConnection(edk::char8* name){
        if(name){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);edkEnd();
            if(temp){
                return temp->connected;
            }
        }
        return NULL;
    }
    edk::char8* getWeightNameInPosition(edk::uint32 position){
        edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementInPosition(position);edkEnd();
        if(temp){
            return temp->getName();
        }
        return NULL;
    }
    inline edk::uint32 getWeightSize(){return this->treeWeights.size();edkEnd();}
    //MATH functions
    inline void setSum(typeTemplate value){
        this->haveSum=true;edkEnd();
        memcpy(&this->sum,&value,sizeof(typeTemplate));edkEnd();
    }
    inline void cleanSum(){
        this->haveSum=false;edkEnd();
        memset(&this->sum,0u,sizeof(typeTemplate));edkEnd();
    }
    inline typeTemplate getSum(){
        return this->sum;edkEnd();
    }
    inline bool getSum(typeTemplate* dest){
        if(dest){
            memcpy(dest,&this->sum,sizeof(typeTemplate));edkEnd();
            return true;
        }
        return false;
    }
    inline virtual bool getBool(){
        return this->isSumBiggetThanZero();
    }
    virtual bool process(){
        edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp;edkEnd();
        edk::uint32 size = this->treeWeights.size();edkEnd();
        if(size){
            for(edk::uint32 i=0u;i<size;i++){
                temp=(edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementInPosition(i);edkEnd();
                if(temp){
                    //test if have the value in another neuron
                    if(temp->connected){
                        //test if don't have processed the sum
                        if(!temp->connected->haveSum){
                            //process the neuron
                            if(!temp->connected->process()){
                                //the neuron is broken
                                this->cleanSum();edkEnd();return false;
                            }
                        }
                        //test if have processed the sum
                        if(temp->connected->haveSum){
                            //test if the value will run on the neuron
                            this->sum += temp->weight * temp->connected->getSum();edkEnd();
                        }
                        else{
                            this->cleanSum();edkEnd();return false;
                        }
                    }
                }
                else{
                    this->cleanSum();edkEnd();return false;
                }
            }
            //test the sum
            if(this->sum<0){
                this->sum=0;edkEnd();
            }
        }
        return this->haveSum = true;edkEnd();
    }
    //print the neuron
    inline virtual void print(){
        printf("\nNeuron \"%s\""
               ,this->getName()?this->getName():"noName"
                                );edkEnd();
        this->printWeights();edkEnd();
        this->printSum();edkEnd();
    }
    inline virtual void printWeights(){
        edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp;edkEnd();
        edk::uint32 size = this->treeWeights.size();edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            temp=(edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementInPosition(i);edkEnd();
            if(temp){
                printf("\n%u Name %s Weight %d "
                       ,i
                       ,temp->getName()?temp->getName():"noName"
                                        ,temp->weight
                       );edkEnd();
                if(temp->connected){
                    printf(" connected \"%s\"",temp->connected->getName()?temp->connected->getName():"noName");edkEnd();
                }
                else{
                    printf(" notConnected");edkEnd();
                }
            }
        }
        fflush(stdout);edkEnd();
    }
    inline virtual void printSum(){
        //write the sum
        printf("\nSUM == %.2lf bool %s"
               ,(edk::float64)this->sum
               ,this->sum?"true":"false"
                          );edkEnd();
        fflush(stdout);edkEnd();
    }
    //function used to clone the neuron values
    bool cloneFrom(edk::neural::Neuron<typeTemplate>* n){
        if(n){
            this->cleanWeights();edkEnd();
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp;edkEnd();
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *tempN;edkEnd();
            edk::uint32 size = n->treeWeights.size();edkEnd();
            for(edk::uint32 i=0u;i<size;i++){
                tempN=(edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)n->treeWeights.getElementInPosition(i);edkEnd();
                if(tempN){
                    //
                    temp = new edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>;edkEnd();
                    if(temp){
                        if(temp->cloneFrom(tempN)){
                            //add this new temp to the tree
                            if(!this->treeWeights.add(temp)){
                                delete temp;edkEnd();
                            }
                        }
                        else{
                            delete temp;edkEnd();
                        }
                    }
                }
            }
            this->sum = n->sum;edkEnd();
            this->haveSum = n->haveSum;edkEnd();

            return true;
        }
        return false;
    }
protected:
    virtual bool isSumBiggetThanZero(){
        return this->sum>0?true:false;edkEnd();
    }
private:
    //set the connected neuron
    inline bool privateSetConnected(edk::char8* name,edk::neural::Neuron<typeTemplate>* n){
        if(n){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);edkEnd();
            if(temp){
                temp->connected = n;edkEnd();
                return true;
            }
        }
        return false;
    }
    //the sum of all values inside the neuron
    typeTemplate sum;
    //save if have process the sum
    bool haveSum;

    template <class tempTemplate>
    class Weights: public edk::Name{
    public:
        Weights(){
            this->classThis=NULL;edkEnd();
            this->Constructor(false);edkEnd();
        }
        ~Weights(){
            if(this->classThis==this){
                this->classThis=NULL;edkEnd();
                //can destruct the class
            }
        }

        void Constructor(bool runFather=true){
            if(runFather){
                edk::Name::Constructor();edkEnd();
            }
            if(this->classThis!=this){
                this->classThis=this;
                this->weight=(typeTemplate)0u;edkEnd();
                this->connected=NULL;edkEnd();
            }
        }
        bool cloneFrom(edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp){
            if(temp){
                if(this->setName(temp->getName())){
                    this->weight=temp->weight;edkEnd();
                    this->connected = temp->connected;edkEnd();
                    return true;
                }
            }
            return false;
        }
        //Weight values inside the neuron
        edk::int32 weight;
        //neuron connecteds
        edk::neural::Neuron<typeTemplate> *connected;
    private:
        edk::classID classThis;
    };
    //values tree
    edk::vector::NameTree treeWeights;
private:
    edk::classID classThis;
};
}//end neural
}//end edk

#endif // NEURON_H
