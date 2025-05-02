#ifndef TREECONTACTOBJECTS_H
#define TREECONTACTOBJECTS_H

/*
Library ContactObjects - A tree to save two objects where have contact to
se if have the same objects again.
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
#pragma message "Inside ContactObjects"
#endif

#pragma once
#include "PhysicObject2D.h"
#include "../vector/BinaryTree.h"

#ifdef printMessages
#pragma message "    Compiling ContactObjects"
#endif


namespace edk{
namespace physics2D{
class ContactObjects{
public:
    ContactObjects(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB){
        this->classThis=NULL;
        this->Constructor(objectA,objectB);
    }
    virtual ~ContactObjects(){
        this->Destructor();
    }

    void Constructor(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB){
        if(this->classThis!=this){
            this->classThis=this;
            this->objectA=objectA;
            this->objectB=objectB;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
    }

    edk::physics2D::PhysicObject2D* objectA;
    edk::physics2D::PhysicObject2D* objectB;
private:
    edk::classID classThis;
};
class ContactObject{
public:
    ContactObject(edk::physics2D::PhysicObject2D* object){
        this->classThis=NULL;
        this->Constructor(object);
    }
    virtual ~ContactObject(){
        this->Destructor();
    }

    void Constructor(edk::physics2D::PhysicObject2D* object){
        if(this->classThis!=this){
            this->classThis=this;
            this->object=object;
            this->pointers.Constructor();
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->pointers.clean();

            this->pointers.Destructor();
        }
    }

    edk::physics2D::PhysicObject2D* object;
    edk::vector::BinaryTree<edk::physics2D::ContactObjects*> pointers;
private:
    edk::classID classThis;
};
class TreeContactObjects{
public:
    TreeContactObjects();
    virtual ~TreeContactObjects();

    void Constructor();
    void Destructor();

    //clean the tree
    void cleanContacts();
    //add new contact
    bool addContact(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB);
    //return true if have the objects in the tree
    bool haveContact(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB);
    //return true if have removed the contact from two objects
    bool removeContact(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB);

private:
    edk::physics2D::ContactObjects search;
    //get the contact
    edk::physics2D::ContactObjects* getContactFirst(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB);
    edk::physics2D::ContactObjects* getContactSecond(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB);
    class TreeObjects : public edk::vector::BinaryTree<edk::physics2D::ContactObjects*>{
    public:
        TreeObjects(){
            this->classThis=NULL;
            this->Constructor();
        }
        virtual ~TreeObjects(){
        }

        void Constructor(){
            edk::vector::BinaryTree<edk::physics2D::ContactObjects*>::Constructor();
            if(this->classThis!=this){
                this->classThis=this;
            }
        }
        void Destructor(){
            if(this->classThis==this){
                this->classThis=NULL;
                //can destruct the class
            }
            edk::vector::BinaryTree<edk::physics2D::ContactObjects*>::Destructor();
        }

        //compare if the value is bigger
        bool firstBiggerSecond(edk::physics2D::ContactObjects* first,edk::physics2D::ContactObjects* second){
            if(first->objectA>second->objectA){
                //
                return true;
            }
            else if(first->objectA==second->objectA
                    &&
                    first->objectB>second->objectB
                    ){
                return true;
            }
            return false;
        }
        //compare if the value is equal
        bool firstEqualSecond(edk::physics2D::ContactObjects* first,edk::physics2D::ContactObjects* second){
            //
            if(first->objectA==second->objectA
                    &&
                    first->objectB==second->objectB){
                //
                return true;
            }
            return false;
        }
    private:
        edk::classID classThis;
    }treeFirst,treeSecond;
private:
    edk::classID classThis;
};
}//end namespace physics2D
}//end namespace edk

#endif // TREECONTACTOBJECTS_H
