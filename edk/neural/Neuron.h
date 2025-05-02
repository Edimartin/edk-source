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
    Value(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~Value(){
        this->Destructor();
    }

    void Constructor(){
        edk::Name::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
            this->value = (typeTemplate)0u;
            this->neuron = NULL;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->cleanName();
        }
        edk::Name::Destructor();
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
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~NameValues(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->clean();
        }
        edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::Destructor();
    }

    //clean the values
    void clean(){
        edk::neural::Value<typeTemplate>* temp;
        edk::uint32 sizeV = this->size();
        for(edk::uint32 i=0u;i<sizeV;i++){
            //
            temp = edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::getElementInPosition(i);
            if(temp){
                delete temp;
            }
        }
        edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::clean();
    }
    bool remove(const edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        return this->remove((edk::char8*) name,neuron);
    }
    bool remove(edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        //get the element
        edk::neural::Value<typeTemplate>* temp = this->getElement(name,neuron);
        if(temp){
            //remove the element
            edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::remove(temp);
            delete temp;
            return true;
        }
        return false;
    }
    edk::uint32 size(){return edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::size(); }
    edk::uint32 getSize(){return edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::size(); }
    //add a new values
    bool add(const edk::char8* name,typeTemplate value,edk::neural::Neuron<typeTemplate> *neuron){
        return this->add((edk::char8*) name,value,neuron);
    }
    bool add(edk::char8* name,typeTemplate value,edk::neural::Neuron<typeTemplate> *neuron){
        //validate the pointers
        if(name && neuron){
            //test if don't have this values
            edk::neural::Value<typeTemplate>* temp;
            if(!(temp = this->getElement(name,neuron))){
                //create a new values
                temp = new edk::neural::Value<typeTemplate>;
                if(temp){
                    //set the values
                    if(temp->setName(name)){
                        temp->value = value;
                        temp->neuron = neuron;
                        if(edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::add(temp)){
                            return true;
                        }
                    }
                    delete temp;
                }
            }
            else{
                //else just set the values
                if(temp->setName(name)){
                    temp->value = value;
                    temp->neuron = neuron;
                    if(edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::add(temp)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool haveElement(const edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        return this->haveElement((edk::char8*) name,neuron);
    }
    bool haveElement(edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        if(this->getElement(name,neuron)){
            return true;
        }
        return false;
    }
    //get the values from the tree
    edk::neural::Value<typeTemplate>* getElement(const edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        this->getElement((edk::char8*) name,neuron);
    }
    edk::neural::Value<typeTemplate>* getElement(edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        //
        edk::neural::Value<typeTemplate> temp;
        temp.setName(name);
        temp.neuron = neuron;
        return edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::getElement(&temp);
    }
    edk::neural::Value<typeTemplate>* getElementInPosition(edk::uint32 position){
        return edk::vector::BinaryTree<edk::neural::Value<typeTemplate>*>::getElementInPosition(position);
    }
    typeTemplate getValue(edk::char8* name,edk::neural::Neuron<typeTemplate> *neuron){
        //
        edk::neural::Value<typeTemplate>* temp = this->getElement(name,neuron);
        if(temp){
            return temp->value;
        }
        return (typeTemplate)0u;
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
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~Neuron(){
    }

    void Constructor(){
        edk::Name::Constructor();
        if(this->classThis!=this){
            this->classThis=this;

            //the sum of all values inside the neuron
            this->treeWeights.Constructor();

            this->haveSum=false;
            this->sum=0;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->cleanWeights();

            this->treeWeights.Destructor();
        }
        edk::Name::Destructor();
    }

    //friend class is a class who can access the private values from another class
    friend edk::neural::Network<typeTemplate>;

    //clean the values
    inline void cleanWeights(){
        edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp;
        edk::uint32 size = this->treeWeights.size();
        for(edk::uint32 i=0u;i<size;i++){
            temp=(edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementInPosition(i);
            if(temp){
                delete temp;
            }
        }
        this->treeWeights.clean();
    }
    //connect the entrance by the name
    bool setConnected(const edk::char8* name,edk::neural::Neuron<typeTemplate>* n){
        return this->setConnected((edk::char8*) name,n);
    }
    inline bool setConnected(edk::char8* name,edk::neural::Neuron<typeTemplate>* n){
        return this->privateSetConnected(name,n);
    }
    bool removeConnected(const edk::char8* name){
        return this->removeConnected((edk::char8*) name);
    }
    inline bool removeConnected(edk::char8* name){
        if(name){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);
            if(temp){
                //remove the connected
                temp->connected = NULL;
                return true;
            }
        }
        return false;
    }
    bool newWeight(const edk::char8* name,edk::int32 Weight){
        return this->newWeight((edk::char8*) name,Weight);
    }
    inline bool newWeight(edk::char8* name){
        if(name){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);
            if(!temp){
                temp = new edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>;
                if(temp->setName(name)){
                    //add to the tree
                    if(this->treeWeights.add(temp)){
                        temp->weight = 0.f;
                        return true;
                    }
                }
                //else delete the temp
                delete temp;
                temp=NULL;
            }
        }
        return false;
    }
    bool setWeight(const edk::char8* name,edk::int32 Weight){
        return this->setWeight((edk::char8*) name,Weight);
    }
    inline bool setWeight(edk::char8* name,edk::int32 Weight){
        if(name){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);
            if(!temp){
                temp = new edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>;
                if(temp->setName(name)){
                    //add to the tree
                    if(this->treeWeights.add(temp)){
                        temp->weight = Weight;
                        return true;
                    }
                }
                //else delete the temp
                delete temp;
                temp=NULL;
            }
            if(temp){
                temp->weight = Weight;
                return true;
            }
        }
        return false;
    }
    typeTemplate getWeightValue(const edk::char8* name){
        return this->getWeightValue((edk::char8*) name);
    }
    inline typeTemplate getWeightValue(edk::char8* name){
        typeTemplate ret;
        if(name){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);
            if(temp){
                return temp->weight;
            }
        }
        memset(&ret,0u,sizeof(typeTemplate));
        return ret;
    }
    bool getWeightValue(const edk::char8* name,typeTemplate* dest){
        return this->getWeightValue((edk::char8*) name,dest);
    }
    inline bool getWeightValue(edk::char8* name,typeTemplate* dest){
        if(name && dest){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);
            if(temp){
                memcpy(dest,&temp->weight,sizeof(typeTemplate));
            }
        }
        return false;
    }
    edk::neural::Neuron<typeTemplate> * getWeightConnection(const edk::char8* name){
        return this->getWeightConnection((edk::char8*) name);
    }
    inline edk::neural::Neuron<typeTemplate> * getWeightConnection(edk::char8* name){
        if(name){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);
            if(temp){
                return temp->connected;
            }
        }
        return NULL;
    }
    edk::char8* getWeightNameInPosition(edk::uint32 position){
        edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementInPosition(position);
        if(temp){
            return temp->getName();
        }
        return NULL;
    }
    inline edk::uint32 getWeightSize(){return this->treeWeights.size(); }
    //MATH functions
    inline void setSum(typeTemplate value){
        this->haveSum=true;
        memcpy(&this->sum,&value,sizeof(typeTemplate));
    }
    inline void cleanSum(){
        this->haveSum=false;
        memset(&this->sum,0u,sizeof(typeTemplate));
    }
    inline typeTemplate getSum(){
        return this->sum;
    }
    inline bool getSum(typeTemplate* dest){
        if(dest){
            memcpy(dest,&this->sum,sizeof(typeTemplate));
            return true;
        }
        return false;
    }
    inline virtual bool getBool(){
        return this->isSumBiggetThanZero();
    }
    virtual bool process(){
        edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp;
        edk::uint32 size = this->treeWeights.size();
        if(size){
            for(edk::uint32 i=0u;i<size;i++){
                temp=(edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementInPosition(i);
                if(temp){
                    //test if have the value in another neuron
                    if(temp->connected){
                        //test if don't have processed the sum
                        if(!temp->connected->haveSum){
                            //process the neuron
                            if(!temp->connected->process()){
                                //the neuron is broken
                                this->cleanSum(); return false;
                            }
                        }
                        //test if have processed the sum
                        if(temp->connected->haveSum){
                            //test if the value will run on the neuron
                            this->sum += temp->weight * temp->connected->getSum();
                        }
                        else{
                            this->cleanSum(); return false;
                        }
                    }
                }
                else{
                    this->cleanSum(); return false;
                }
            }
            //test the sum
            if(this->sum<0){
                this->sum=0;
            }
        }
        return this->haveSum = true;
    }
    //print the neuron
    inline virtual void print(){
        printf("\nNeuron \"%s\""
               ,this->getName()?this->getName():"noName"
                                );
        this->printWeights();
        this->printSum();
    }
    inline virtual void printWeights(){
        edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp;
        edk::uint32 size = this->treeWeights.size();
        for(edk::uint32 i=0u;i<size;i++){
            temp=(edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementInPosition(i);
            if(temp){
                printf("\n%u Name %s Weight %d "
                       ,i
                       ,temp->getName()?temp->getName():"noName"
                                        ,temp->weight
                       );
                if(temp->connected){
                    printf(" connected \"%s\"",temp->connected->getName()?temp->connected->getName():"noName");
                }
                else{
                    printf(" notConnected");
                }
            }
        }
        fflush(stdout);
    }
    inline virtual void printSum(){
        //write the sum
        printf("\nSUM == %.2lf bool %s"
               ,(edk::float64)this->sum
               ,this->sum?"true":"false"
                          );
        fflush(stdout);
    }
    //function used to clone the neuron values
    bool cloneFrom(edk::neural::Neuron<typeTemplate>* n){
        if(n){
            this->cleanWeights();
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp;
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *tempN;
            edk::uint32 size = n->treeWeights.size();
            for(edk::uint32 i=0u;i<size;i++){
                tempN=(edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)n->treeWeights.getElementInPosition(i);
                if(tempN){
                    //
                    temp = new edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>;
                    if(temp){
                        if(temp->cloneFrom(tempN)){
                            //add this new temp to the tree
                            if(!this->treeWeights.add(temp)){
                                delete temp;
                            }
                        }
                        else{
                            delete temp;
                        }
                    }
                }
            }
            this->sum = n->sum;
            this->haveSum = n->haveSum;

            return true;
        }
        return false;
    }
protected:
    virtual bool isSumBiggetThanZero(){
        return this->sum>0?true:false;
    }
private:
    //set the connected neuron
    inline bool privateSetConnected(edk::char8* name,edk::neural::Neuron<typeTemplate>* n){
        if(n){
            edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp = (edk::neural::Neuron<typeTemplate>::Weights<typeTemplate>*)this->treeWeights.getElementByName(name);
            if(temp){
                temp->connected = n;
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
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~Weights(){
        }

        void Constructor(){
            edk::Name::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
                this->weight=(typeTemplate)0u;
                this->connected=NULL;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
            edk::Name::Destructor();
        }
        bool cloneFrom(edk::neural::Neuron<typeTemplate>::Weights<typeTemplate> *temp){
            if(temp){
                if(this->setName(temp->getName())){
                    this->weight=temp->weight;
                    this->connected = temp->connected;
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
