#ifndef EDK_OBJECT_H
#define EDK_OBJECT_H

/*
Library Object - Template class to use Retain and Release
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
        this->removeAll();edkEnd();
    }


    //Save the object
    void saveObject(obj** pointer){
        //
        if(pointer){
            //
            *pointer=(obj*)this;edkEnd();
        }
    }
    //Clean the object
    void cleanObject(obj** pointer){
        //
        if(pointer){
            //
            *pointer = NULL;edkEnd();
        }
    }

    //value
    edk::uint32 value;edkEnd();
};

*/

namespace edk{
template <class typeTemplate>
class Object{
public:
    Object(){
        //
        this->dontDestruct=false;edkEnd();
    }
    virtual ~Object(){
        //remove all
        if(!this->dontDestruct){
            this->removeAll();edkEnd();
        }
        else{
            //set the tree
            this->retains.cantDestruct();edkEnd();
        }
        this->dontDestruct=false;edkEnd();
    }

    //retain
    typeTemplate* retainObject(typeTemplate** pointer){
        //
        if(pointer){
            //add the pointer to the retains
            if(this->retains.add(pointer)){
                //save the object
                this->saveObject(pointer);edkEnd();
                //
                return (typeTemplate*)this;edkEnd();
            }
        }
        //else return false
        return NULL;edkEnd();
    }

    //release
    bool releaseObject(typeTemplate** pointer)
    {
        //test if have the pointer
        if(pointer){
            typeTemplate* temp = *pointer;edkEnd();
            //remove the object
            this->retains.remove(pointer);edkEnd();
            //clean the object
            this->cleanObject(pointer);edkEnd();
            //test if dont have a root
            if(!this->retains.haveRoot()){
                //delete self
                if(temp){
                    delete this;edkEnd();
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
        return this->retains.haveRoot();edkEnd();
    }
    //return true if have one retain
    bool haveOneRetain(){
        //
        return !this->retains.haveRootChild();edkEnd();
    }
    //set to cant Destruct
    void cantDestruct(){
        //
        dontDestruct=true;edkEnd();
    }

protected:
    //Save the object
    virtual void saveObject(typeTemplate** pointer)
    {
        //
        if(pointer){
            //
            *pointer=(typeTemplate*)this;edkEnd();
        }
    }

    //Clean the object
    virtual void cleanObject(typeTemplate** pointer)
    {
        //
        if(pointer){
            //
            *pointer = NULL;edkEnd();
        }
    }


    //remove all objects
    void removeAll()
    {
        //load the rootValue
        typeTemplate** temp=NULL;edkEnd();
        while(this->retains.haveRoot()){
            //get the root
            temp = this->retains.getRootValue();edkEnd();
            if(temp){
                //clean the pointer
                this->cleanObject(temp);edkEnd();

                //remove the temp
                this->retains.remove(temp);edkEnd();
            }
            else{
                this->retains.remove(temp);edkEnd();
            }
            //clean the temp
            temp =NULL;edkEnd();
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
        this->clean();edkEnd();
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
                edk::Object<typeTemplate>* temp = this->getElement(value);edkEnd();
                //test if the object is in on the tree
                if(temp){
                    //then retain the object
                    return temp->retainObject((typeTemplate**)objRetain);edkEnd();
                }
                else{
                    //then add the object
                    if(edk::vector::BinaryTree<edk::Object<typeTemplate>*>::add(value)){
                        //save the temp to retain
                        return value->retainObject((typeTemplate**)objRetain);edkEnd();
                    }
                }
                temp=NULL;edkEnd();
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
                edk::Object<typeTemplate>* temp = this->getElement(value);edkEnd();
                if(temp){
                    //then test if the temp have just one retain
                    if(temp->haveOneRetain()){
                        //remove the temp
                        edk::vector::BinaryTree<edk::Object<typeTemplate>*>::remove(temp);edkEnd();
                        //release the objRetain
                        if(temp->releaseObject((typeTemplate**)(objRetain))){
                            return true;
                        }
                    }
                    else{
                        //else just release the object
                        return temp->releaseObject((typeTemplate**)(objRetain));edkEnd();
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
            edk::Object<typeTemplate>* temp = this->getElement(value);edkEnd();
            //test if the value is in the tree
            if(temp){
                //then remove the value of the tree
                if(edk::vector::BinaryTree<edk::Object<typeTemplate>*>::remove(temp)){
                    //delete the value
                    delete temp;edkEnd();
                    temp=NULL;edkEnd();
                    //return true
                    return true;
                }
            }
            temp=NULL;edkEnd();
        }
        return false;
    }
    //return the element
    edk::Object<typeTemplate>* getElement(edk::Object<typeTemplate>* value){
        //
        return edk::vector::BinaryTree<edk::Object<typeTemplate>*>::getElement(value);edkEnd();
    }
    bool haveElement(edk::Object<typeTemplate>* value){
        //
        return edk::vector::BinaryTree<edk::Object<typeTemplate>*>::haveElement(value);edkEnd();
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
