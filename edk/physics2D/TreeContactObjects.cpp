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

edk::physics2D::TreeContactObjects::TreeContactObjects(){
    //
}
edk::physics2D::TreeContactObjects::~TreeContactObjects(){
    //
}
//get the contact
inline edk::physics2D::ContactObjects* edk::physics2D::TreeContactObjects::getContact(edk::physics2D::PhysicObject2D* objectA,
                                                                                      edk::physics2D::PhysicObject2D* objectB
                                                                                      ){
    //
    edk::physics2D::ContactObjects search(objectA,objectB);edkEnd();
    return this->tree.getElement(&search);
}

//clean the tree
void edk::physics2D::TreeContactObjects::clean(){
    edk::uint32 size = this->tree.size();edkEnd();
    edk::physics2D::ContactObjects* temp;edkEnd();
    for(edk::uint32 i=0u;i<size;i++){
        temp = this->tree.getElementInPosition(i);edkEnd();
        if(temp){
            delete temp;edkEnd();
        }
    }
    this->tree.clean();edkEnd();
}
//add new contact
bool edk::physics2D::TreeContactObjects::add(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB){
    //test the objects
    if(objectA && objectB){
        //search for the objects on the tree
        edk::physics2D::ContactObjects* temp = this->getContact(objectA,objectB);edkEnd();
        if(!temp){
            //else the tree don't have the objects

            //add two contacts
            edk::physics2D::ContactObjects* first = new edk::physics2D::ContactObjects(objectA,objectB);edkEnd();
            if(first){
                if(this->tree.add(first)){
                    //create the second object
                    edk::physics2D::ContactObjects* second = new edk::physics2D::ContactObjects(objectB,objectA);edkEnd();
                    if(second){
                        if(this->tree.add(second)){
                            return true;
                        }
                        delete second;edkEnd();
                    }
                    this->tree.remove(first);edkEnd();
                }
                delete first;edkEnd();
            }
        }
    }
    return false;
}
//return true if have the objects in the tree
bool edk::physics2D::TreeContactObjects::haveElement(edk::physics2D::PhysicObject2D* objectA,edk::physics2D::PhysicObject2D* objectB){
    edk::physics2D::ContactObjects* temp = this->getContact(objectA,objectB);edkEnd();
    if(temp){
        return true;
    }
    return false;
}
