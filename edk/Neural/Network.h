#ifndef NETWORK_H
#define NETWORK_H

/*
Network - Neural Netword using a collection of neurons.
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
#warning "Inside neural::Network"
#endif

#pragma once
#include "Neuron.h"

#ifdef printMessages
#warning "    Compiling neural::Network"
#endif

namespace edk{
namespace neural{
//Use a template to alloc whatever
template <class typeTemplate>
class Network{
public:
    Network(){this->runProcess=false;}
    ~Network(){}

    //clean the sums of all neurons
    void cleanSums(){
        edk::uint32 size = this->tree.size();
        edk::neural::Neuron<typeTemplate>* temp = NULL;
        for(edk::uint32 i=0u;i<size;i++){
            temp = (edk::neural::Neuron<typeTemplate>*)this->tree.getElementInPosition(i);
            if(temp){
                temp->cleanSum();
            }
        }
    }
    //create a new neuron
    bool newNeuron(const edk::char8* name){
        return this->newNeuron((edk::char8*) name);
    }
    bool newNeuron(edk::char8* name){
        //test if have the name
        if(name){
            //test if don't have the neuron
            if(!this->tree.haveName(name)){
                //create a new neuron
                edk::neural::Neuron<typeTemplate>* temp = (edk::neural::Neuron<typeTemplate>*)new edk::neural::Neuron<typeTemplate>;
                if(temp){
                    if(temp->setName(name)){
                        //add the temp to the network
                        if(this->tree.add(temp)){
                            temp->tree = &this->values;
                            //then return true
                            return true;
                        }
                        delete temp;
                    }
                }
            }
        }
        return false;
    }
    //set the weight in a position
    bool setNeuronWeight(const edk::char8* name,edk::char8* wName,typeTemplate weight){
        return this->setNeuronWeight((edk::char8*) name, wName,weight);
    }
    bool setNeuronWeight(edk::char8* name,const edk::char8* wName,typeTemplate weight){
        return this->setNeuronWeight(name,(edk::char8*) wName,weight);
    }
    bool setNeuronWeight(const edk::char8* name,const edk::char8* wName,typeTemplate weight){
        return this->setNeuronWeight((edk::char8*) name,(edk::char8*) wName,weight);
    }
    bool setNeuronWeight(edk::char8* name,edk::char8* wName,typeTemplate weight){
        //test the names
        if(name && wName){
            //get the neuron
            edk::neural::Neuron<typeTemplate>* temp = (edk::neural::Neuron<typeTemplate>*)this->tree.getElementByName(name);
            if(temp){
                //set the weight
                return temp->setWeight(wName,weight);
            }
        }
        return false;
    }//set the neuron connection
    bool setNeuronConnection(const edk::char8* name,const edk::char8* nName,const edk::char8* wName){
        return this->setNeuronConnection((edk::char8*) name,(edk::char8*) nName,(edk::char8*) wName);
    }
    bool setNeuronConnection(const edk::char8* name,edk::char8* nName,edk::char8* wName){
        return this->setNeuronConnection((edk::char8*) name,nName, wName);
    }
    bool setNeuronConnection(edk::char8* name,const edk::char8* nName,edk::char8* wName){
        return this->setNeuronConnection(name,(edk::char8*) nName,wName);
    }
    bool setNeuronConnection(edk::char8* name,edk::char8* nName,const edk::char8* wName){
        return this->setNeuronConnection(name, nName,(edk::char8*) wName);
    }
    bool setNeuronConnection(const edk::char8* name,const edk::char8* nName,edk::char8* wName){
        return this->setNeuronConnection((edk::char8*) name,(edk::char8*) nName,wName);
    }
    bool setNeuronConnection(edk::char8* name,const edk::char8* nName,const edk::char8* wName){
        return this->setNeuronConnection( name,(edk::char8*) nName,(edk::char8*) wName);
    }
    bool setNeuronConnection(const edk::char8* name,edk::char8* nName,const edk::char8* wName){
        return this->setNeuronConnection((edk::char8*) name, nName,(edk::char8*) wName);
    }
    bool setNeuronConnection(edk::char8* name,edk::char8* nName,edk::char8* wName){
        if(name && nName && wName){
            //get the neuron
            edk::neural::Neuron<typeTemplate>* temp = (edk::neural::Neuron<typeTemplate>*)this->tree.getElementByName(name);
            edk::neural::Neuron<typeTemplate>* temp2 = (edk::neural::Neuron<typeTemplate>*)this->tree.getElementByName(nName);
            if(temp && temp2 && temp != temp2){
                //set the weight
                return temp->setConnected(wName,temp2);
            }
        }
        return false;
    }
    //add a entrance value in to the neurons
    bool setValue(const edk::char8* nName,const edk::char8* wName,typeTemplate value){
        return this->setValue((edk::char8*) nName,(edk::char8*) wName,value);
    }
    bool setValue(const edk::char8* nName, edk::char8* wName,typeTemplate value){
        return this->setValue((edk::char8*) nName,wName,value);
    }
    bool setValue(edk::char8* nName,const edk::char8* wName,typeTemplate value){
        return this->setValue(nName,(edk::char8*) wName,value);
    }
    bool setValue(edk::char8* nName,edk::char8* wName,typeTemplate value){
        //test if runProcess to clean sums
        if(this->runProcess){
            this->runProcess=false;
            this->cleanSums();
            this->values.clean();
        }
        //validate the values
        if(nName && wName){
            //test if have the neuron
            edk::neural::Neuron<typeTemplate>* temp = (edk::neural::Neuron<typeTemplate>*)this->tree.getElementByName(nName);
            if(temp){
                //add the value
                return this->values.add(wName,value,temp);
            }
        }
        return false;
    }

    //return true if have the neuron
    bool haveNeuron(edk::char8* nName){
        //validate the values
        if(nName){
            //test if have the neuron
            return this->tree.haveName(nName);
        }
        return false;
    }
    //get the neuron bool
    bool getNeuronBool(edk::char8* nName){
        //validate the values
        if(nName){
            //test if have the neuron
            edk::neural::Neuron<typeTemplate>* temp = (edk::neural::Neuron<typeTemplate>*)this->tree.getElementByName(nName);
            if(temp){
                //add the value
                return temp->getBool();
            }
        }
        return false;
    }

    //process the network passing the name of the neuron
    bool process(const edk::char8* nName, bool *on=NULL){
        return this->process((edk::char8*) nName,on);
    }
    bool process(edk::char8* nName, bool *on=NULL){
        //validate the name
        if(nName){
            this->runProcess=true;
            //get the neuron
            edk::neural::Neuron<typeTemplate>* temp = (edk::neural::Neuron<typeTemplate>*)this->tree.getElementByName(nName);
            if(temp){
                //process the temp
                temp->process();
                if(on){
                    *on = temp->getBool();
                }
            }
        }
        return false;
    }

    //print the network
    bool print(){
        edk::uint32 size = this->tree.size();
        if(size){
            edk::neural::Neuron<typeTemplate>* temp = NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp = (edk::neural::Neuron<typeTemplate>*)this->tree.getElementInPosition(i);
                if(temp){
                    temp->print();
                }
            }
            return true;
        }
        return false;
    }
    bool printSums(){
        edk::uint32 size = this->tree.size();
        if(size){
            edk::neural::Neuron<typeTemplate>* temp = NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp = (edk::neural::Neuron<typeTemplate>*)this->tree.getElementInPosition(i);
                if(temp){
                    temp->printSum();
                }
            }
            return true;
        }
        return false;
    }
    bool printWeights(){
        edk::uint32 size = this->tree.size();
        if(size){
            edk::neural::Neuron<typeTemplate>* temp = NULL;
            for(edk::uint32 i=0u;i<size;i++){
                temp = (edk::neural::Neuron<typeTemplate>*)this->tree.getElementInPosition(i);
                if(temp){
                    temp->printWeights();
                }
            }
            return true;
        }
        return false;
    }
private:
    edk::neural::NameValues<typeTemplate> values;
    //neuron tree
    edk::vector::NameTree tree;
    //save if run the process
    bool runProcess;
};
}//end namespace neural
}//end namespace edk

#endif // NETWORK_H
