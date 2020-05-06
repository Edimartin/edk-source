#include "Object.h"

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
#warning "            Inside Object.cpp"
#endif

edk::ObjectWithName::ObjectWithName(){
    //
    this->objectName=NULL;
}
//construtor
edk::ObjectWithName::ObjectWithName(edk::char8* name){
    //
    this->objectName=NULL;
    this->setName(name);
}
//construtor
edk::ObjectWithName::ObjectWithName(const edk::char8* name){
    //
    this->objectName=NULL;
    this->setName(name);
}

//destructor
edk::ObjectWithName::~ObjectWithName(){
    //
    this->deleteName();
    //else remove all
    this->removeAll();
}
bool edk::ObjectWithName::setName(edk::char8* name)
{
    //delete the last name
    this->deleteName();

    //test if the name is alloc
    if(name){
        //then copy the name
        this->objectName = edk::String::strCopy(name);
        return true;
    }
    //else return false
    return false;
}
bool edk::ObjectWithName::setName(const edk::char8* name)
{
    //
    //else return false
    return this->setName((edk::char8*) name);
}
edk::char8* edk::ObjectWithName::getName(){
    //
    return this->objectName;
}
edk::char8* edk::ObjectWithName::name(){
    //
    return this->getName();
}
void edk::ObjectWithName::deleteName(){
    //
    if(this->objectName){
        //
        delete[] this->objectName;
    }
    this->objectName=NULL;
}






//NAMES TREE
//VIRTUAL
bool edk::ObjectNameTree::addElement(edk::ObjectWithName* value,edk::ObjectWithName** objRetain){
    //test the value
    if(value){
        if(objRetain){
            //get the object on the tree
            edk::ObjectWithName* temp = this->getElement(value);
            //test if the object is in on the tree
            if(temp){
                //then retain the object
                return temp->retainObject(objRetain);
            }
            else{
                //then add the object
                if(edk::vector::BinaryTree<edk::ObjectWithName*>::add(value)){
                    //save the temp to retain
                    return value->retainObject(objRetain);
                }
            }
            temp=NULL;
        }
    }
    //else return false
    return false;
}
bool edk::ObjectNameTree::releaseElement(edk::ObjectWithName* value,edk::ObjectWithName** objRetain){
    //test the *objRetain
    if(value){
        if(objRetain){
            //then test if have the *objRetain on the tree
            edk::ObjectWithName* temp = this->getElement(value);
            if(temp){
                //then test if the temp have just one retain
                if(temp->haveOneRetain()){
                    //remove the temp
                    edk::vector::BinaryTree<edk::ObjectWithName*>::remove(temp);
                    //release the objRetain
                    if(temp->releaseObject(objRetain)){
                        return true;
                    }
                }
                else{
                    //else just release the object
                    return temp->releaseObject(objRetain);
                }
            }
        }
    }
    //else return false
    return false;
}
bool edk::ObjectNameTree::deleteElement(edk::ObjectWithName* value){
    //
    //test if the value exist
    if(value){
        //then test if have the *objRetain on the tree
        edk::ObjectWithName* temp = this->getElement(value);
        //test if the value is in the tree
        if(temp){
            //then remove the value of the tree
            if(edk::vector::BinaryTree<edk::ObjectWithName*>::remove(temp)){
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
edk::ObjectWithName* edk::ObjectNameTree::getElement(edk::ObjectWithName* value){
    //
    return edk::vector::BinaryTree<edk::ObjectWithName*>::getElement(value);
}
bool edk::ObjectNameTree::haveElement(edk::ObjectWithName* value){
    //
    return edk::vector::BinaryTree<edk::ObjectWithName*>::haveElement(value);
}
//compare if the value is bigger
bool edk::ObjectNameTree::firstBiggerSecond(edk::ObjectWithName* first,
                                            edk::ObjectWithName* second){
    //test the objects
    if(first!=NULL && second!=NULL){
        //test the names
        return this->firstNameBiggerSecond(first->getName(),
                                           second->getName()
                                           );
    }
    //else return false
    return false;
}
bool edk::ObjectNameTree::firstEqualSecond(edk::ObjectWithName* first,
                                           edk::ObjectWithName* second){
    //test the objects
    if(first!=NULL && second!=NULL){
        //test the names
        return this->nameEqual(first->getName(),
                               second->getName()
                               );
    }
    //else return false
    return false;
}
//compare the names
bool edk::ObjectNameTree::firstNameBiggerSecond(edk::char8* name1,edk::char8* name2){
    //test the strings
    if(name1 && name2){
        //test if name1 is bigger
        edk::uint32 i=0u;
        while(name1[i]!='\0' || name2[i]!='\0'){
            //test if the first is bigger then second
            if(name1[i]>name2[i]){
                //the return true
                return true;
            }
            else if(name2[i]>name1[i]){
                //
                break;
            }
            //else equal increment i
            i++;
        }
    }
    //else return false
    return false;
}
bool edk::ObjectNameTree::nameEqual(edk::char8* name1,edk::char8* name2){
    //test the two strings
    if(name1 && name2){
        edk::uint32 i=0u;
        //compare the two strings
        while(name1[i]!='\0' || name2[i]!='\0'){
            //test if the first is bigger then second
            if(name1[i]!=name2[i]){
                //the return true
                return false;
            }
            //else equal increment i
            i++;
        }
        //test if are equal
        if(name1[i]==name2[i]){
            //return true
            return true;
        }
    }
    //else return false
    return false;
}
void edk::ObjectNameTree::printElement(edk::ObjectWithName* value){
    //
    if(value){
        //
        if(value->name()){
            //
            printf("\nName %s"
                   ,value->name()
                   );
        }
        else{
            //
            printf("\nName NULL");
        }
    }
    else{
        //
        printf("\nName NULL");
    }
}
