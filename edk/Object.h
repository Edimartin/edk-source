#ifndef EDK_OBJECT_H
#define EDK_OBJECT_H

/*
Library Object - Template class to use Retain and Release
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
#warning "Inside Object"
#endif

//Include the binaryTree to save the elements
#pragma once
#include "vector/BinaryTree.h"
#include "String.h"

#ifdef printMessages
#warning "    Compiling Object"
#endif

/*

//code sample

class obj: public edk::Object<obj>{
    //
    public:
    obj(){
        //consturtor
    }
    //Construtor virtual precisa chamar a funcao protegida
    ~obj(){
        //destrutor
        this->removeAll();
    }


    //Save the object
    void saveObject(obj** pointer){
        //
        if(pointer){
            //
            *pointer=(obj*)this;
        }
    }
    //Clean the object
    void cleanObject(obj** pointer){
        //
        if(pointer){
            //
            *pointer = NULL;
        }
    }

    //value
    edk::uint32 value;
};

*/

namespace edk{
template <class typeTemplate>
class Object{
public:
    Object(){
        //
        this->dontDestruct=false;
    }
    virtual ~Object(){
        //remove all
        if(!this->dontDestruct)
            this->removeAll();
        else{
            //set the tree
            this->retains.cantDestruct();
        }
        this->dontDestruct=false;
    }

    //retain
    typeTemplate* retainObject(typeTemplate** pointer){
        //
        if(pointer){
            //add the pointer to the retains
            if(this->retains.add(pointer)){
                //save the object
                this->saveObject(pointer);
                //
                return (typeTemplate*)this;
            }
        }
        //else return false
        return NULL;
    }

    //release
    bool releaseObject(typeTemplate** pointer)
    {
        //test if have the pointer
        if(pointer){
            typeTemplate* temp = *pointer;
            //remove the object
            this->retains.remove(pointer);
            //clean the object
            this->cleanObject(pointer);
            //test if dont have a root
            if(!this->retains.haveRoot()){
                //delete self
                if(temp){
                    delete this;
                    return true;
                }
            }
            return true;
        }
        //else return false
        return false;
    }

    //Return true if have retains
    bool haveRetains(){
        //
        return this->retains.haveRoot();
    }
    //return true if have one retain
    bool haveOneRetain(){
        //
        return !this->retains.haveRootChild();
    }
    //set to cant Destruct
    void cantDestruct(){
        //
        dontDestruct=true;
    }

protected:
    //Save the object
    virtual void saveObject(typeTemplate** pointer)
    {
        //
        if(pointer){
            //
            *pointer=(typeTemplate*)this;
        }
    }

    //Clean the object
    virtual void cleanObject(typeTemplate** pointer)
    {
        //
        if(pointer){
            //
            *pointer = NULL;
        }
    }


    //remove all objects
    void removeAll()
    {
        //load the rootValue
        typeTemplate** temp=NULL;
        while(this->retains.haveRoot()){
            //get the root
            temp = this->retains.getRootValue();
            if(temp){
                //clean the pointer
                this->cleanObject(temp);

                //remove the temp
                this->retains.remove(temp);
            }
            else{
                this->retains.remove(temp);
            }
            //clean the temp
            temp =NULL;
        }
    }
private:
    //binaryTree
    edk::vector::BinaryTree<typeTemplate**> retains;
    //set if cant run the destructor
    bool dontDestruct;
};

//Create a object with name
class ObjectWithName : public edk::Object<edk::ObjectWithName>{
public:
    //construtor
    ObjectWithName();
    //construtor
    ObjectWithName(edk::char8* name);
    //construtor
    ObjectWithName(const edk::char8* name);
    //destructor
    virtual ~ObjectWithName();

    //Set the name
    bool setName(edk::char8* name);
    bool setName(const edk::char8* name);
    //get the name
    edk::char8* getName();
    edk::char8* name();

    //delete the name
    void deleteName();

private:
    //private name
    edk::char8* objectName;
};



//TREE WITH OBJECTS
template <class typeTemplate>
class ObjectsTree :public edk::vector::BinaryTree<edk::Object<typeTemplate>*>{
    //
public:
    ObjectsTree(){
        //
    }
    virtual ~ObjectsTree(){
        //
        this->clean();
    }
    //Diferente Add to retain the object
    bool add(edk::Object<typeTemplate>* value){
        //
        return false;
    }
    bool addElement(edk::Object<typeTemplate>* value,edk::Object<typeTemplate>** objRetain){
        //test the value
        if(value){
            if(objRetain){
                //get the object on the tree
                edk::Object<typeTemplate>* temp = this->getElement(value);
                //test if the object is in on the tree
                if(temp){
                    //then retain the object
                    return temp->retainObject((typeTemplate**)objRetain);
                }
                else{
                    //then add the object
                    if(edk::vector::BinaryTree<edk::Object<typeTemplate>*>::add(value)){
                        //save the temp to retain
                        return value->retainObject((typeTemplate**)objRetain);
                    }
                }
                temp=NULL;
            }
        }
        //else return false
        return false;
    }
    bool remove(edk::Object<typeTemplate>* value){
        //
        return false;
    }
    bool releaseElement(edk::Object<typeTemplate>* value,edk::Object<typeTemplate>** objRetain){
        //test the *objRetain
        if(value){
            if(objRetain){
                //then test if have the *objRetain on the tree
                edk::Object<typeTemplate>* temp = this->getElement(value);
                if(temp){
                    //then test if the temp have just one retain
                    if(temp->haveOneRetain()){
                        //remove the temp
                        edk::vector::BinaryTree<edk::Object<typeTemplate>*>::remove(temp);
                        //release the objRetain
                        if(temp->releaseObject((typeTemplate**)(objRetain))){
                            return true;
                        }
                    }
                    else{
                        //else just release the object
                        return temp->releaseObject((typeTemplate**)(objRetain));
                    }
                }
            }
        }
        //else return false
        return false;
    }
    //delete the element of the tree
    bool deleteElement(edk::Object<typeTemplate>* value){
        //test if the value exist
        if(value){
            //then test if have the *objRetain on the tree
            edk::Object<typeTemplate>* temp = this->getElement(value);
            //test if the value is in the tree
            if(temp){
                //then remove the value of the tree
                if(edk::vector::BinaryTree<edk::Object<typeTemplate>*>::remove(temp)){
                    //delete the value
                    delete temp;
                    temp=NULL;
                    //return true
                    return true;
                }
            }
            temp=NULL;
        }
        return false;
    }
    //return the element
    edk::Object<typeTemplate>* getElement(edk::Object<typeTemplate>* value){
        //
        return edk::vector::BinaryTree<edk::Object<typeTemplate>*>::getElement(value);
    }
    bool haveElement(edk::Object<typeTemplate>* value){
        //
        return edk::vector::BinaryTree<edk::Object<typeTemplate>*>::haveElement(value);
    }
};


//TREE WITH NAMES
//textureTree
class ObjectNameTree: public edk::vector::BinaryTree<edk::ObjectWithName*>{
    //
public:
    ObjectNameTree(){
        //
    }
    virtual ~ObjectNameTree(){
        //
    }
    //Add
    //edk::Object<typeTemplate>* value,edk::Object<typeTemplate>** objRetain
    bool addElement(edk::ObjectWithName* value,edk::ObjectWithName** objRetain);
    bool releaseElement(edk::ObjectWithName* value,edk::ObjectWithName** objRetain);
    bool deleteElement(edk::ObjectWithName* value);
    edk::ObjectWithName* getElement(edk::ObjectWithName* value);
    bool haveElement(edk::ObjectWithName* value);

    //VIRTUAL
    //compare if the value is bigger
    bool firstBiggerSecond(edk::ObjectWithName* first,
                           edk::ObjectWithName* second);
    bool firstEqualSecond(edk::ObjectWithName* first,
                          edk::ObjectWithName* second);
    void printElement(edk::ObjectWithName* value);

private:
    //compare the names
    bool firstNameBiggerSecond(edk::char8* name1,edk::char8* name2);
    bool nameEqual(edk::char8* name1,edk::char8* name2);
};


}


#endif // OBJECT_H
