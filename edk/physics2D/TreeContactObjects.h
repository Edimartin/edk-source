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
#warning "Inside ContactObjects"
#endif

#pragma once
#include "PhysicObject2D.h"
#include "../vector/BinaryTree.h"

#ifdef printMessages
#warning "    Compiling ContactObjects"
#endif


namespace edk{
namespace physics2D{
class ContactObjects{
public:
    ContactObjects(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB){
        this->objectA=objectA;edkEnd();
        this->objectB=objectB;edkEnd();
    }
    ~ContactObjects(){}

    edk::physics2D::PhysicObject2D* objectA;
    edk::physics2D::PhysicObject2D* objectB;
};
class TreeContactObjects{
public:
    TreeContactObjects();
    ~TreeContactObjects();

    //clean the tree
    void clean();
    //add new contact
    bool add(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB);
    //return true if have the objects in the tree
    bool haveElement(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB);

private:
    //get the contact
    edk::physics2D::ContactObjects* getContact(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB);
    class TreeObjects : public edk::vector::BinaryTree<edk::physics2D::ContactObjects*>{
    public:
        TreeObjects(){}
        ~TreeObjects(){}

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
    }tree;
};
}//end namespace physics2D
}//end namespace edk

#endif // TREECONTACTOBJECTS_H
