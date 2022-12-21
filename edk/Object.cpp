#include "Object.h"

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
#warning "            Inside Object.cpp"
#endif

edk::ObjectWithName::ObjectWithName(){
    //
    this->objectName=NULL;edkEnd();
}
//construtor
edk::ObjectWithName::ObjectWithName(edk::char8* name){
    //
    this->objectName=NULL;edkEnd();
    this->setName(name);edkEnd();
}
//construtor
edk::ObjectWithName::ObjectWithName(const edk::char8* name){
    //
    this->objectName=NULL;edkEnd();
    this->setName(name);edkEnd();
}

//destructor
edk::ObjectWithName::~ObjectWithName(){
    //
    this->deleteName();edkEnd();
    //else remove all
    this->removeAll();edkEnd();
}
bool edk::ObjectWithName::setName(edk::char8* name)
{
    //delete the last name
    this->deleteName();edkEnd();

    //test if the name is alloc
    if(name){
        //then copy the name
        this->objectName = edk::String::strCopy(name);edkEnd();
        return true;
    }
    //else return false
    return false;
}
bool edk::ObjectWithName::setName(const edk::char8* name)
{
    //
    //else return false
    return this->setName((edk::char8*) name);edkEnd();
}
edk::char8* edk::ObjectWithName::getName(){
    //
    return this->objectName;edkEnd();
}
edk::char8* edk::ObjectWithName::name(){
    //
    return this->getName();edkEnd();
}
void edk::ObjectWithName::deleteName(){
    //
    if(this->objectName){
        //
        delete[] this->objectName;edkEnd();
    }
    this->objectName=NULL;edkEnd();
}






//NAMES TREE
//VIRTUAL
bool edk::ObjectNameTree::addElement(edk::ObjectWithName* value,edk::ObjectWithName** objRetain){
    //test the value
    if(value){
        if(objRetain){
            //get the object on the tree
            edk::ObjectWithName* temp = this->getElement(value);edkEnd();
            //test if the object is in on the tree
            if(temp){
                //then retain the object
                return temp->retainObject(objRetain);edkEnd();
            }
            else{
                //then add the object
                if(edk::vector::BinaryTree<edk::ObjectWithName*>::add(value)){
                    //save the temp to retain
                    return value->retainObject(objRetain);edkEnd();
                }
            }
            temp=NULL;edkEnd();
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
            edk::ObjectWithName* temp = this->getElement(value);edkEnd();
            if(temp){
                //then test if the temp have just one retain
                if(temp->haveOneRetain()){
                    //remove the temp
                    edk::vector::BinaryTree<edk::ObjectWithName*>::remove(temp);edkEnd();
                    //release the objRetain
                    if(temp->releaseObject(objRetain)){
                        return true;
                    }
                }
                else{
                    //else just release the object
                    return temp->releaseObject(objRetain);edkEnd();
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
        edk::ObjectWithName* temp = this->getElement(value);edkEnd();
        //test if the value is in the tree
        if(temp){
            //then remove the value of the tree
            if(edk::vector::BinaryTree<edk::ObjectWithName*>::remove(temp)){
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
edk::ObjectWithName* edk::ObjectNameTree::getElement(edk::ObjectWithName* value){
    //
    return edk::vector::BinaryTree<edk::ObjectWithName*>::getElement(value);edkEnd();
}
bool edk::ObjectNameTree::haveElement(edk::ObjectWithName* value){
    //
    return edk::vector::BinaryTree<edk::ObjectWithName*>::haveElement(value);edkEnd();
}
//compare if the value is bigger
bool edk::ObjectNameTree::firstBiggerSecond(edk::ObjectWithName* first,
                                            edk::ObjectWithName* second){
    //test the objects
    if(first!=NULL && second!=NULL){
        //test the names
        return this->firstNameBiggerSecond(first->getName(),
                                           second->getName()
                                           );edkEnd();
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
                               );edkEnd();
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
                break;edkEnd();
            }
            //else equal increment i
            i++;edkEnd();
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
            i++;edkEnd();
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
                   );edkEnd();
        }
        else{
            //
            printf("\nName NULL");edkEnd();
        }
    }
    else{
        //
        printf("\nName NULL");edkEnd();
    }
}
