#include "TreeContactObjects.h"

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
#pragma message "            Inside TreeContactObjects.cpp"
#endif

edk::physics2D::TreeContactObjects::TreeContactObjects()
    :search(NULL,NULL)
{
    this->classThis=NULL;
    this->Constructor();
}
edk::physics2D::TreeContactObjects::~TreeContactObjects(){
    this->Destructor();
}

void edk::physics2D::TreeContactObjects::Constructor(){
    //
    if(this->classThis!=this){
        this->classThis=this;

        this->treeFirst.Constructor();
        this->treeSecond.Constructor();
    }
}
void edk::physics2D::TreeContactObjects::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class

        this->treeFirst.Destructor();
        this->treeSecond.Destructor();
    }
}

//get the contact
inline edk::physics2D::ContactObjects* edk::physics2D::TreeContactObjects::getContactFirst(edk::physics2D::PhysicObject2D* objectA,
                                                                                           edk::physics2D::PhysicObject2D* objectB
                                                                                           ){
    //
    this->search.objectA = objectA;
    this->search.objectB = objectB;
    return this->treeFirst.getElement(&search);
}
inline edk::physics2D::ContactObjects* edk::physics2D::TreeContactObjects::getContactSecond(edk::physics2D::PhysicObject2D* objectA,
                                                                                            edk::physics2D::PhysicObject2D* objectB
                                                                                            ){
    //
    this->search.objectA = objectB;
    this->search.objectB = objectA;
    return this->treeSecond.getElement(&search);
}

//clean the tree
void edk::physics2D::TreeContactObjects::cleanContacts(){
    edk::uint32 size = this->treeFirst.size();
    edk::physics2D::ContactObjects* temp;
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->treeFirst.getElementInPosition(i);
        if(temp){
            delete temp;
        }
    }
    this->treeFirst.clean();
    size = this->treeSecond.size();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->treeSecond.getElementInPosition(i);
        if(temp){
            delete temp;
        }
    }
    this->treeSecond.clean();
}
//add new contact
bool edk::physics2D::TreeContactObjects::addContact(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB){
    //test the objects
    if(objectA && objectB){
        //search for the objects on the tree
        edk::physics2D::ContactObjects* temp = this->getContactFirst(objectA,objectB);
        if(!temp){
            //else the tree don't have the objects

            //add two contacts
            edk::physics2D::ContactObjects* first = new edk::physics2D::ContactObjects(objectA,objectB);
            if(first){
                if(this->treeFirst.add(first)){
                    //create the second object
                    edk::physics2D::ContactObjects* second = new edk::physics2D::ContactObjects(objectB,objectA);
                    if(second){
                        if(this->treeSecond.add(second)){
                            return true;
                        }
                        delete second;
                    }
                    this->treeFirst.remove(first);
                }
                delete first;
            }
        }
    }
    return false;
}
//return true if have the objects in the tree
bool edk::physics2D::TreeContactObjects::haveContact(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB){
    edk::physics2D::ContactObjects* temp = this->getContactFirst(objectA,objectB);
    if(temp){
        return true;
    }
    temp = this->getContactSecond(objectA,objectB);
    if(temp){
        return true;
    }
    return false;
}
//return true if have removed the contact from two objects
bool edk::physics2D::TreeContactObjects::removeContact(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB){
    bool ret=false;
    edk::physics2D::ContactObjects* temp = this->getContactFirst(objectA,objectB);
    if(temp){
        if(this->treeFirst.remove(temp)){
            delete temp;
            ret = true;
        }
    }
    temp = this->getContactFirst(objectB,objectA);
    if(temp){
        if(this->treeFirst.remove(temp)){
            delete temp;
            ret = true;
        }
    }
    temp = this->getContactSecond(objectA,objectB);
    if(temp){
        if(this->treeSecond.remove(temp)){
            delete temp;
            ret = true;
        }
    }
    temp = this->getContactSecond(objectB,objectA);
    if(temp){
        if(this->treeSecond.remove(temp)){
            delete temp;
            ret = true;
        }
    }
    return ret;
}
