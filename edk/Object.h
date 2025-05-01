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
#pragma message "Inside Object"
#endif

//Include the binaryTree to save the elements
#pragma once
#include "TypeVars.h"
#include "vector/BinaryTree.h"
#include "String.h"

#ifdef printMessages
#pragma message "    Compiling Object"
#endif

namespace edk{
class PointerObject{
public:
    PointerObject(edk::classID pointer);
    ~PointerObject();
    void* pointer;
    inline bool operator==(edk::PointerObject object){
        if(this->pointer==object.pointer){
            return true;
        }
        return false;
    }
    inline bool operator>(edk::PointerObject object){
        if(this->pointer>object.pointer){
            return true;
        }
        return false;
    }

    inline bool retain(edk::classID pointerClass){
        if(pointerClass){
            return this->tree.add(pointerClass);
        }
        return false;
    }
    inline bool release(edk::classID pointerClass){
        if(pointerClass){
            return this->tree.remove(pointerClass);
        }
        return false;
    }
    inline edk::uint32 size(){
        return this->tree.size();
    }
private:
    edk::vector::BinaryTree<edk::classID> tree;
private:
    edk::classID classThis;
};
class Pointer{
public:
    Pointer();
    ~Pointer();
    template <class typeTemplate>
    static bool newVec(typeTemplate** pointer,edk::uint64 lenght){
        if(pointer && lenght){
            typeTemplate* temp = (typeTemplate*)malloc(sizeof(typeTemplate)*lenght);
            if(temp){
                edk::PointerObject* tempObj = new edk::PointerObject(temp);
                if(tempObj){
                    if(edk::Pointer::tree.add(tempObj)){
                        *pointer = temp;
                        if(edk::Pointer::retain((edk::classID**)pointer,temp)){
                            return true;
                        }
                        *pointer = NULL;
                        edk::Pointer::tree.remove(tempObj);
                    }
                    delete tempObj;
                }
                free(temp);
            }
            return true;
        }
        return false;
    }
    template <class typeTemplate>
    static bool retain(typeTemplate** pointerClass,edk::classID pointer){
        return edk::Pointer::retain((edk::classID*) pointerClass,pointer);
    }
    static bool retain(edk::classID* pointerClass,edk::classID pointer);
    template <class typeTemplate>
    static bool release(typeTemplate** pointerClass){
        return edk::Pointer::release((edk::classID*) pointerClass);
    }
    static bool release(edk::classID* pointerClass);
private:
    class TreeObjects : public edk::vector::BinaryTree<edk::PointerObject*>{
    public:
        TreeObjects(){}
        ~TreeObjects(){}
        //compare if the value is bigger
        virtual bool firstBiggerSecond(edk::PointerObject* first,edk::PointerObject* second){
            if(*first>*second){
                //
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(edk::PointerObject* first,edk::PointerObject* second){
            if(*first==*second){
                //
                return true;
            }
            return false;
        }
    }
    static tree;
    static edk::PointerObject templatePointer;
};
template <class typeTemplate>
class Object{
public:
    inline Object(){
        this->classThis=this;
    }
    virtual inline ~Object(){}

    bool retain(typeTemplate** obj){
        if(obj){
            printf("\n%u %s %s this == [%lu] obj == [%lu]",__LINE__,__FILE__,__func__
                   ,(edk::uint64)this
                   ,(edk::uint64)obj
                   );fflush(stdout);
            return this->tree.add(obj);
        }
        return false;
    }
    bool release(typeTemplate** obj){
        if(obj){
            printf("\n%u %s %s this == [%lu] obj == [%lu]",__LINE__,__FILE__,__func__
                   ,(edk::uint64)this
                   ,(edk::uint64)obj
                   );fflush(stdout);
            if(this->tree.remove(obj)){
                //test if need delete the pointer
                if(!this->tree.size()){
                    typeTemplate* temp = (typeTemplate*)this;
                    //delete the object
                    delete temp;
                    //clean the pointer
                    *obj=NULL;
                }
                return true;
            }
        }
        return false;
    }
    static typeTemplate* newObject(){
        typeTemplate* ret = new typeTemplate;
        return ret;
    }
protected:
    bool canDelete(){
        if(this->classThis == this){
            return true;
        }
        return false;
    }
private:
    edk::classID classThis;
    edk::vector::BinaryTree<typeTemplate**> tree;
};
}





/*

//code sample

class obj: public edk::Object<obj>{
    //
    public:
    obj(){
        //consturtor
    }
    //Construtor virtual precisa chamar a funcao protegida
    virtual ~obj(){
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
class ObjectSmart{
public:
    ObjectSmart(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~ObjectSmart(){
        this->Destructor();
    }

    void Constructor(){
        //
        if(this->classThis!=this){
            this->classThis=this;

            this->retains.Constructor();
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            //remove all
            this->removeAll();
        }
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
private:
    edk::classID classThis;
};

//Create a object with name
class ObjectWithName : public edk::ObjectSmart<edk::ObjectWithName>{
public:
    //construtor
    ObjectWithName();
    //construtor
    ObjectWithName(edk::char8* name);
    //construtor
    ObjectWithName(const edk::char8* name);
    //destructor
    virtual ~ObjectWithName();

    void Constructor();
    void Constructor(edk::char8* name);
    void Constructor(const edk::char8* name);
    void Destructor();

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
private:
    edk::classID classThis;
};



//TREE WITH OBJECTS
template <class typeTemplate>
class ObjectsTree :public edk::vector::BinaryTree<edk::ObjectSmart<typeTemplate>*>{
    //
public:
    ObjectsTree(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~ObjectsTree(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::BinaryTree<edk::ObjectSmart<typeTemplate>*>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->clean();
        }
        edk::vector::BinaryTree<edk::ObjectSmart<typeTemplate>*>::Destructor();
    }

    //Diferente Add to retain the object
    bool add(edk::ObjectSmart<typeTemplate>* value){
        //
        return false;
    }
    bool addElement(edk::ObjectSmart<typeTemplate>* value,edk::ObjectSmart<typeTemplate>** objRetain){
        //test the value
        if(value){
            if(objRetain){
                //get the object on the tree
                edk::ObjectSmart<typeTemplate>* temp = this->getElement(value);
                //test if the object is in on the tree
                if(temp){
                    //then retain the object
                    return temp->retainObject((typeTemplate**)objRetain);
                }
                else{
                    //then add the object
                    if(edk::vector::BinaryTree<edk::ObjectSmart<typeTemplate>*>::add(value)){
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
    bool remove(edk::ObjectSmart<typeTemplate>* value){
        //
        return false;
    }
    bool releaseElement(edk::ObjectSmart<typeTemplate>* value,edk::ObjectSmart<typeTemplate>** objRetain){
        //test the *objRetain
        if(value){
            if(objRetain){
                //then test if have the *objRetain on the tree
                edk::ObjectSmart<typeTemplate>* temp = this->getElement(value);
                if(temp){
                    //then test if the temp have just one retain
                    if(temp->haveOneRetain()){
                        //remove the temp
                        edk::vector::BinaryTree<edk::ObjectSmart<typeTemplate>*>::remove(temp);
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
    bool deleteElement(edk::ObjectSmart<typeTemplate>* value){
        //test if the value exist
        if(value){
            //then test if have the *objRetain on the tree
            edk::ObjectSmart<typeTemplate>* temp = this->getElement(value);
            //test if the value is in the tree
            if(temp){
                //then remove the value of the tree
                if(edk::vector::BinaryTree<edk::ObjectSmart<typeTemplate>*>::remove(temp)){
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
    edk::ObjectSmart<typeTemplate>* getElement(edk::ObjectSmart<typeTemplate>* value){
        //
        return edk::vector::BinaryTree<edk::ObjectSmart<typeTemplate>*>::getElement(value);
    }
    bool haveElement(edk::ObjectSmart<typeTemplate>* value){
        //
        return edk::vector::BinaryTree<edk::ObjectSmart<typeTemplate>*>::haveElement(value);
    }
private:
    edk::classID classThis;
};


//TREE WITH NAMES
//textureTree
class ObjectNameTree: public edk::vector::BinaryTree<edk::ObjectWithName*>{
    //
public:
    ObjectNameTree(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~ObjectNameTree(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::BinaryTree<edk::ObjectWithName*>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
        edk::vector::BinaryTree<edk::ObjectWithName*>::Destructor();
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
private:
    edk::classID classThis;
};
}

#endif // OBJECT_H
