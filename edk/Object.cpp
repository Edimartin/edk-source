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
#pragma message "            Inside Object.cpp"
#endif

edk::PointerObject::PointerObject(edk::classID pointer){
    this->classThis = this;
    this->pointer=pointer;
}
edk::PointerObject::~PointerObject(){
    if(this->classThis == this){
        if(this->pointer){
            free(this->pointer);
        }
    }
}

edk::PointerObject edk::Pointer::templatePointer(NULL);
edk::Pointer::TreeObjects edk::Pointer::tree;
edk::Pointer::Pointer(){}
edk::Pointer::~Pointer(){}
bool edk::Pointer::retain(edk::classID* pointerClass,edk::classID pointer){
    if(pointerClass){
        if(pointer){
            edk::Pointer::templatePointer.pointer = pointer;
            edk::PointerObject* tempObj = edk::Pointer::tree.getElement(&edk::Pointer::templatePointer);
            edk::Pointer::templatePointer.pointer = NULL;
            if(tempObj){
                if(tempObj->retain(pointerClass)){
                    *pointerClass = tempObj->pointer;
                    return true;
                }
            }
        }
    }
    return false;
}
bool edk::Pointer::release(edk::classID* pointerClass){
    if(pointerClass){
        edk::classID pointer = *pointerClass;
        if(pointer){
            edk::Pointer::templatePointer.pointer = pointer;
            edk::PointerObject* tempObj = edk::Pointer::tree.getElement(&edk::Pointer::templatePointer);
            edk::Pointer::templatePointer.pointer = NULL;
            if(tempObj){
                if(tempObj->release(pointerClass)){
                    //test if need delete the vector
                    if(!tempObj->size()){
                        //remove and delete the tempObj
                        if(edk::Pointer::tree.remove(tempObj)){
                            delete tempObj;
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

edk::ObjectWithName::ObjectWithName(){
    this->classThis=NULL;
    this->Constructor();
}
//construtor
edk::ObjectWithName::ObjectWithName(edk::char8* name){
    this->classThis=NULL;
    this->Constructor(name);
}
//construtor
edk::ObjectWithName::ObjectWithName(const edk::char8* name){
    this->classThis=NULL;
    this->Constructor(name);
}

//destructor
edk::ObjectWithName::~ObjectWithName(){
    this->Destructor();
}

void edk::ObjectWithName::Constructor(){
    edk::ObjectSmart<edk::ObjectWithName>::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        //
        this->objectName=NULL;
    }
}
void edk::ObjectWithName::Constructor(edk::char8* name){
    edk::ObjectSmart<edk::ObjectWithName>::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        //
        this->objectName=NULL;
        this->setName(name);
    }
}
void edk::ObjectWithName::Constructor(const edk::char8* name){
    edk::ObjectSmart<edk::ObjectWithName>::Constructor();
    if(this->classThis!=this){
        this->classThis=this;
        //
        this->objectName=NULL;
        this->setName(name);
    }
}
void edk::ObjectWithName::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
        //can destruct the class
        this->deleteName();
        //else remove all
        this->removeAll();
    }
    edk::ObjectSmart<edk::ObjectWithName>::Destructor();
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
        free(this->objectName);
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

