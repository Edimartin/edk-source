#ifndef BINARYTREESTATIC_H
#define BINARYTREESTATIC_H
/*
Library binaryTree - Create a binaryTree in EDK Game Engine
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
#pragma message "Inside BinaryTree"
#endif

#pragma once
#include <stdio.h>
#include <string.h>
#include "../TypeVars.h"
#include "../NameClass.h"
#include "../String.h"
#include "./QueueStatic.h"

#ifdef printMessages
#pragma message "    Compiling BinaryTree"
#endif

#define EDK_ERROR_HAVE_VALUE 100u
#define EDK_ERROR_ALLOC_VALUE 102u

/*

binaryTree was created to order elements in the memory

*/

/*

//code sample

//Binary Tree
class treeObj:public edk::vector::BinaryTreeStatic<obj*>{
public:
    treeObj(){}
    virtual ~treeObj(){}
    //compare if the value is bigger
    virtual bool firstBiggerSecond(obj* first,obj* second){
        //
        if(first>second){
            //
            return true;
        }
        return false;
    }
    //compare if the value is equal
    virtual bool firstEqualSecond(obj* first,obj* second){
        //
        if(first==second){
            //
            return true;
        }
        return false;
    }
    //Load
    virtual void loadElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );
    }
    //Unload
    virtual void unloadElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );
    }
    //Print
    virtual void printElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );
    }
    virtual void renderElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );
    }
    virtual void renderWireElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );
    }
    virtual void drawElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );
    }
    virtual void drawWireElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );
    }
    //UPDATE
    virtual void updateElement(obj* value){
        //update the value
        value++;
    }

    //Load the elements
    virtual void load(){
        edk::vector::BinaryTreeStatic<obj*>::load();
    }
    //Unload the elements
    virtual void unload(){
        edk::vector::BinaryTreeStatic<obj*>::unload();
    }
    //Print the elements
    virtual void print(){
        edk::vector::BinaryTreeStatic<obj*>::print();
    }
    //render the elements
    virtual void render(){
        edk::vector::BinaryTreeStatic<obj*>::render();
    }
    virtual void renderWire(){
        edk::vector::BinaryTreeStatic<obj*>::renderWire();
    }
    //draw the elements
    virtual void draw(){
        edk::vector::BinaryTreeStatic<obj*>::draw();
    }
    virtual void drawWire(){
        edk::vector::BinaryTreeStatic<obj*>::drawWire();
    }
    //update the elements
    virtual void update(){
        edk::vector::BinaryTreeStatic<obj*>::update();
    }
};

*/


//namespaces
namespace edk{
namespace vector{
//Tree callbacks
template <class typeTemplate>
class BinaryTreeStaticCallback{
public:
    BinaryTreeStaticCallback(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~BinaryTreeStaticCallback(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
    }

    virtual void callbackLoadElement(typeTemplate){}
    virtual void callbackUnloadElement(typeTemplate){}
    virtual void callbackPrintElement(typeTemplate){}
    virtual void callbackRenderElement(typeTemplate){}
    virtual void callbackRenderWireElement(typeTemplate){}
    virtual void callbackDrawElement(typeTemplate){}
    virtual void callbackDrawWireElement(typeTemplate){}
    virtual void callbackUpdateElement(typeTemplate){}
private:
    edk::classID classThis;
};
template <class typeTemplate>
class UnaryLeafStatic{
    //Construtor
public:
    UnaryLeafStatic(){
        this->classThis=NULL;
        this->Constructor();
    }
    //Destrutor
    virtual ~UnaryLeafStatic(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
            this->next=NULL;
            this->father=NULL;
            this->position=0u;
            memset(&this->value,0u,sizeof(typeTemplate));
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
    }

    //LEFT
    UnaryLeafStatic* next;
    //add the father
    UnaryLeafStatic* father;

    //Value of the leaf
    typeTemplate value;
    //position of the leaf in the tree
    edk::uint32 position;
private:
    edk::classID classThis;
};
template <class typeTemplate>
class BinaryLeafStatic{
    //Construtor
public:
    BinaryLeafStatic(){
        this->classThis=NULL;
        this->Constructor();
    }
    //Destrutor
    virtual ~BinaryLeafStatic(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
            this->left=NULL;
            this->right=NULL;
            this->father=NULL;
            this->counter=0;
            this->readed=0u;
            memset((void*)&this->value,0u,sizeof(typeTemplate));
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
    }

    //RIGHT
    BinaryLeafStatic* left;
    BinaryLeafStatic* right;
    //add the father
    BinaryLeafStatic* father;

    //counter to balance the tree
    edk::int32 counter;
    edk::uint8 readed;

    //Value of the leaf
    typeTemplate value;
    //position of the leaf in the tree
    edk::uint32 position;
private:
    edk::classID classThis;
};
template <class typeTemplate>
class BinaryTreeStatic{
public:
    //errorCode
    edk::uint16 errorCode;
    //Construtor
    BinaryTreeStatic(){
        this->classThis=NULL;
        this->Constructor();
    }
    //Destrutor
    virtual ~BinaryTreeStatic(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;
            this->updateElementsPositions=false;
            this->root=NULL;
            this->errorCode=0u;
            this->sizeTree=0u;

            this->errorCodePointer = &this->errorCode;
            this->rootPointer = &this->root;
            this->updateElementsPositionsPointer = &this->updateElementsPositions;
            this->sizeTreePointer = &this->sizeTree;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->clean();
            this->root=NULL;
            this->sizeTree=0u;
        }
    }

    //Add a value on the tree
    bool add(typeTemplate value){
        //Test if is the root element
        if(!(*this->rootPointer)){
            //then add the root element
            (*this->rootPointer) = new BinaryLeafStatic<typeTemplate>;
            if((*this->rootPointer)){
                (*this->rootPointer)->Constructor();
                //set the value
                memcpy((void*)&(*this->rootPointer)->value,(void*)&value,sizeof(typeTemplate));
                //increment the sizeTree
                this->incrementSize();
                //then return true
                return true;
            }
        }
        else{
            //Find the position to add the object
            BinaryLeafStatic<typeTemplate>* temp=(*this->rootPointer);
            //create the value
            BinaryLeafStatic<typeTemplate>* newValue = new BinaryLeafStatic<typeTemplate>;
            //Test if create the newValue
            if(newValue){
                newValue->Constructor();
                memcpy((void*)&newValue->value,(void*)&value,sizeof(typeTemplate));
                //Find the position
                //test if the temp exist
                while(temp){
                    //then test if the value is equal
                    if(this->firstEqualSecond(temp->value, newValue->value)){
                        //The tree have the value. Delete the new value and return the tree value.
                        newValue->Destructor();
                        delete newValue;
                        newValue=NULL;
                        //
                        (*this->errorCodePointer)=EDK_ERROR_HAVE_VALUE;
                        return false;
                    }
                    else{
                        //else test if the first is bigger
                        if(this->firstBiggerSecond(newValue->value ,temp->value) ){
                            //then test if have a right
                            if(temp->right){
                                //temp receive the right
                                temp = temp->right;
                            }
                            else{
                                //else add the value in right
                                temp->right = newValue;  newValue=NULL;
                                temp->right->father = temp;
                                //increment the sizeTree
                                this->incrementSize();
                                //balance the tree
                                ///TODO - Fix the balance function in the future
                                //this->balance(temp->right);
                                //return true
                                return true;
                            }
                        }
                        else{
                            //then test if have a left
                            if(temp->left){
                                //temp receive the left
                                temp=temp->left;
                            }
                            else{
                                //else add the value in left
                                temp->left = newValue;
                                newValue=NULL;
                                temp->left->father = temp;
                                //increment the sizeTree
                                this->incrementSize();
                                //balance the tree
                                ///TODO - Fix the balance function in the future
                                //this->balance(temp->left);
                                //return true
                                return true;
                            }
                        }
                    }
                }
                newValue->Destructor();
                delete newValue;
            }
        }
        //else return false
        (*this->errorCodePointer)=EDK_ERROR_HAVE_VALUE;
        return false;
    }

    //Load the elements
    virtual void load(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->loadNoRecursively((*this->rootPointer));
        }
    }
    //Unload the elements
    virtual void unload(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->unloadNoRecursively((*this->rootPointer));
        }
    }
    //Print the elements
    virtual void print(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->printNoRecursively((*this->rootPointer));
        }
    }
    //render the elements
    virtual void render(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->renderNoRecursively((*this->rootPointer));
        }
    }
    //render the elements in wire mode
    virtual void renderWire(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->renderWireNoRecursively((*this->rootPointer));
        }
    }
    //draw the elements
    virtual void draw(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->drawNoRecursively((*this->rootPointer));
        }
    }
    //draw the elements in wire mode
    virtual void drawWire(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->drawWireNoRecursively((*this->rootPointer));
        }
    }
    virtual void update(){
        //test if have root
        if((*this->rootPointer)){
            //then update
            this->updateNoRecursively((*this->rootPointer));
        }
    }

    //Remove the element
    bool remove(typeTemplate value){
        //first find the element mother
        BinaryLeafStatic<typeTemplate>* mother = this->findMother(value);
        BinaryLeafStatic<typeTemplate> element;
        memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));
        if(mother){
            //if find the mother search who is the element
            if(mother->left){
                //test if it's left
                if(this->firstEqualSecond(mother->left->value,element.value)){
                    BinaryLeafStatic<typeTemplate>* leaf = NULL;
                    //test if the element (mother->left) have childrens
                    if(mother->left->right){
                        //then get the left leaf
                        //save the element
                        BinaryLeafStatic<typeTemplate>* temp = mother->left;
                        if((leaf = this->findMotherLeftLeaf(mother->left->right))){
                            //then pull the leaf to the mother->left
                            mother->left = leaf->left;
                            if(mother->left){
                                mother->left->father = mother;
                            }
                            //arrage the leaf
                            leaf->left = leaf->left->right;
                            if(leaf->left){
                                leaf->left->father = leaf;
                            }
                            //then the new mother->left receive the two temps.
                            mother->left->left = temp->left;
                            if(mother->left->left){
                                mother->left->left->father = mother->left;
                            }
                            mother->left->right = temp->right;
                            if(mother->left->right){
                                mother->left->right->father = mother->left;
                            }
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->left=mother->left->right;
                            if(mother->left){
                                mother->left->father = mother;
                            }
                            mother->left->left = temp->left;
                            if(mother->left->left){
                                mother->left->left->father = mother->left;
                            }
                        }
                        //delete the element
                        temp->Destructor();
                        delete temp;
                        temp=NULL;
                        //decrement the sizeTree
                        this->decrementSize();
                        //return true
                        return true;
                    }
                    if(mother->left->left){
                        //then get the right leaf
                        //save the element
                        BinaryLeafStatic<typeTemplate>* temp = mother->left;
                        if((leaf = this->findMotherRightLeaf(mother->left->left))){
                            //then pull the leaf to the mother->left
                            mother->left = leaf->right;
                            if(mother->left){
                                mother->left->father = mother;
                            }
                            //arrage the leaf
                            leaf->right = leaf->right->left;
                            if(leaf->right){
                                leaf->right->father = leaf;
                            }
                            //then the new mother->left receive the two temps.
                            mother->left->left = temp->left;
                            if(mother->left->left){
                                mother->left->left->father = mother->left;
                            }
                            mother->left->right = temp->right;
                            if(mother->left->right){
                                mother->left->right->father = mother->left;
                            }
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->left=mother->left->left;
                            if(mother->left){
                                mother->left->father = mother;
                            }
                            mother->left->right = temp->right;
                            if(mother->left->right){
                                mother->left->right->father = mother->left;
                            }
                        }
                        //delete the element
                        temp->Destructor();
                        delete temp;
                        temp=NULL;
                        //decrement the sizeTree
                        this->decrementSize();
                        //return true
                        return true;
                    }
                    //He dont have childrens

                    //delete the element
                    mother->left->Destructor();
                    delete mother->left;
                    mother->left=NULL;
                    //decrement the sizeTree
                    this->decrementSize();
                    return true;
                }
            }




            if(mother->right){
                //test if it's left
                if(this->firstEqualSecond(mother->right->value,element.value)){
                    BinaryLeafStatic<typeTemplate>* leaf = NULL;
                    //test if the element (mother->right) have childrens
                    if(mother->right->right){
                        //then get the left leaf
                        //save the element
                        BinaryLeafStatic<typeTemplate>* temp = mother->right;
                        if((leaf = this->findMotherLeftLeaf(mother->right->right))){
                            //then pull the leaf to the mother->right
                            mother->right = leaf->left;
                            if(mother->right){
                                mother->right->father = mother;
                            }
                            //arrage the leaf
                            leaf->left = leaf->left->right;
                            if(leaf->left){
                                leaf->left->father = leaf;
                            }
                            //then the new mother->right receive the two temps.
                            mother->right->left = temp->left;
                            if(mother->right->left){
                                mother->right->left->father = mother->right;
                            }
                            mother->right->right = temp->right;
                            if(mother->right->right){
                                mother->right->right->father = mother->right;
                            }
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->right=mother->right->right;
                            if(mother->right){
                                mother->right->father = mother;
                            }
                            mother->right->left = temp->left;
                            if(mother->right->left){
                                mother->right->left->father = mother->right;
                            }
                        }
                        //delete the element
                        temp->Destructor();
                        delete temp;
                        temp=NULL;
                        //decrement the sizeTree
                        this->decrementSize();
                        //return true
                        return true;
                    }
                    if(mother->right->left){
                        //then get the right leaf
                        //save the element
                        BinaryLeafStatic<typeTemplate>* temp = mother->right;
                        if((leaf = this->findMotherRightLeaf(mother->right->left))){
                            //then pull the leaf to the mother->right
                            mother->right = leaf->right;
                            if(mother->right){
                                mother->right->father = mother;
                            }
                            //arrage the leaf
                            leaf->right = leaf->right->left;
                            if(leaf->right){
                                leaf->right->father = leaf;
                            }
                            //then the new mother->right receive the two temps.
                            mother->right->left = temp->left;
                            if(mother->right->left){
                                mother->right->left->father = mother->right;
                            }
                            mother->right->right = temp->right;
                            if(mother->right->right){
                                mother->right->right->father = mother->right;
                            }
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->right=mother->right->left;
                            if(mother->right){
                                mother->right->father = mother;
                            }
                            mother->right->right = temp->right;
                            if(mother->right->right){
                                mother->right->right->father = mother->right;
                            }
                        }
                        //delete the element
                        temp->Destructor();
                        delete temp;
                        temp=NULL;
                        //decrement the sizeTree
                        this->decrementSize();
                        //return true
                        return true;
                    }
                    //He dont have childrens

                    //just delete;
                    mother->right->Destructor();
                    delete mother->right;
                    mother->right=NULL;
                    //decrement the sizeTree
                    this->decrementSize();
                    return true;
                }
            }




            if(mother==(*this->rootPointer)){
                //
                BinaryLeafStatic<typeTemplate>* leaf = NULL;
                //test if have a left or right
                if((*this->rootPointer)->right){
                    //then get the left leaf
                    //save the element
                    BinaryLeafStatic<typeTemplate>* temp = (*this->rootPointer);
                    if((leaf = this->findMotherLeftLeaf((*this->rootPointer)->right))){
                        //then pull the leaf to the (*this->rootPointer)
                        (*this->rootPointer) = leaf->left;
                        if((*this->rootPointer)){
                            (*this->rootPointer)->father=NULL;
                        }
                        //arrage the leaf
                        leaf->left = leaf->left->right;
                        if(leaf->left){
                            leaf->left->father = leaf;
                        }
                        //then the new (*this->rootPointer) receive the two temps.
                        (*this->rootPointer)->left = temp->left;
                        if((*this->rootPointer)->left){
                            (*this->rootPointer)->left->father = (*this->rootPointer);
                        }
                        (*this->rootPointer)->right = temp->right;
                        if((*this->rootPointer)->right){
                            (*this->rootPointer)->right->father = (*this->rootPointer);
                        }
                    }
                    else{
                        //else just get the right
                        //pull the right
                        (*this->rootPointer)=(*this->rootPointer)->right;
                        if((*this->rootPointer)){
                            (*this->rootPointer)->father=NULL;
                        }
                        (*this->rootPointer)->left = temp->left;
                        if((*this->rootPointer)->left){
                            (*this->rootPointer)->left->father = (*this->rootPointer);
                        }
                    }
                    //delete the element
                    temp->Destructor();
                    delete temp;
                    temp=NULL;
                    //decrement the sizeTree
                    this->decrementSize();
                    //return true
                    return true;
                }
                if((*this->rootPointer)->left){
                    //then get the right leaf
                    //save the element
                    BinaryLeafStatic<typeTemplate>* temp = (*this->rootPointer);
                    if((leaf = this->findMotherRightLeaf((*this->rootPointer)->left))){
                        //then pull the leaf to the (*this->rootPointer)
                        (*this->rootPointer) = leaf->right;
                        if((*this->rootPointer)){
                            (*this->rootPointer)->father=NULL;
                        }
                        //arrage the leaf
                        leaf->right = leaf->right->left;
                        if(leaf->right){
                            leaf->right->father = leaf;
                        }
                        //then the new (*this->rootPointer) receive the two temps.
                        (*this->rootPointer)->left = temp->left;
                        if((*this->rootPointer)->left){
                            (*this->rootPointer)->left->father = (*this->rootPointer);
                        }
                        (*this->rootPointer)->right = temp->right;
                        if((*this->rootPointer)->right){
                            (*this->rootPointer)->right->father = (*this->rootPointer);
                        }
                    }
                    else{
                        //else just get the right
                        //pull the right
                        (*this->rootPointer)=(*this->rootPointer)->left;
                        if((*this->rootPointer)){
                            (*this->rootPointer)->father = NULL;
                        }
                        (*this->rootPointer)->right = temp->right;
                        if((*this->rootPointer)->right){
                            (*this->rootPointer)->right->father = (*this->rootPointer);
                        }
                    }
                    //delete the element
                    temp->Destructor();
                    delete temp;
                    temp=NULL;
                    //decrement the sizeTree
                    this->decrementSize();
                    //return true
                    return true;
                }

                //remove the root
                (*this->rootPointer)->Destructor();
                delete (*this->rootPointer);
                (*this->rootPointer)=NULL;
                //decrement the sizeTree
                this->decrementSize();
                //return true
                return true;
            }
        }
        //else return false
        return false;
    }

    //Get the rootValue
    typeTemplate getRootValue(){
        //
        if(this->haveRoot()){
            //
            return (typeTemplate)(*this->rootPointer)->value;
        }
        else{
            //
            return (typeTemplate)0u;
        }
    }
    //Return true if have a root
    bool haveRoot(){
        //
        if((*this->rootPointer)){
            //
            return true;
        }
        //else return false
        return false;
    }
    bool haveRootChild(){
        //
        if(this->haveRoot()){
            //test the childs
            return ((*this->rootPointer)->left || (*this->rootPointer)->right);
        }
        //else return false
        return false;
    }

    //test if have the element
    bool haveElement(typeTemplate value){
        //test if have the value
        if(this->find(value)){
            //return true
            return true;
        }
        //else return false
        return false;
    }

    //return the element
    typeTemplate getElement(typeTemplate value){
        //find the element pointer
        BinaryLeafStatic<typeTemplate>* ret = this->find(value);
        //test if the element is founded
        if(ret){
            //return the value
            return ret->value;
        }
        //else return zero
        typeTemplate retZero;
        memset((void*)&retZero,0u,sizeof(typeTemplate));
        return retZero;
    }
    typeTemplate getElementBefore(typeTemplate value){
        //find the element pointer
        BinaryLeafStatic<typeTemplate>* ret = this->findBefore(value);
        //test if the element is founded
        if(ret){
            //return the value
            return ret->value;
        }
        //else return zero
        typeTemplate retZero;
        memset((void*)&retZero,0u,sizeof(typeTemplate));
        return retZero;
    }
    typeTemplate getElementAfter(typeTemplate value){
        //find the element pointer
        BinaryLeafStatic<typeTemplate>* ret = this->findAfter(value);
        //test if the element is founded
        if(ret){
            //return the value
            return ret->value;
        }
        //else return zero
        typeTemplate retZero;
        memset((void*)&retZero,0u,sizeof(typeTemplate));
        return retZero;
    }
    //return the element position in the tree
    edk::uint32 getElementPosition(typeTemplate value){
        //test if need calculate the elementsPosition
        if(!(*this->updateElementsPositionsPointer)){
            this->updatePositionsNoRecursively((*this->rootPointer));
            (*this->updateElementsPositionsPointer)=true;
        }
        //find the element pointer
        BinaryLeafStatic<typeTemplate>* ret = this->find(value);
        //test if the element is founded
        if(ret){
            //return the value
            return ret->position;
        }
        //else return zero
        return 0u;
    }
    //return the element in the Position
    typeTemplate getElementInPosition(edk::uint32 position){
        //first test if the position exist in the tree
        if(position < this->size()){
            //test if need update the positions
            if(!(*this->updateElementsPositionsPointer) && position>10u){
                this->updatePositionsNoRecursively((*this->rootPointer));
                (*this->updateElementsPositionsPointer)=true;
            }
            if((*this->updateElementsPositionsPointer)){
                //then find the element pointer
                BinaryLeafStatic<typeTemplate>* ret = this->findPosition(position);
                //test if the element is founded
                if(ret){
                    //return the value
                    return ret->value;
                }
            }
            else{
                //then find the element pointer
                BinaryLeafStatic<typeTemplate>* ret = this->getNoRecursively((*this->rootPointer)/*,&count*/,position);
                //test if the element is founded
                if(ret){
                    //return the value
                    return ret->value;
                }
            }
        }
        typeTemplate ret;  memset((void*)&ret,0u,sizeof(typeTemplate));
        //else return zero
        return ret;
    }
    //force update positions
    void updatePositions(){
        if(!(*this->updateElementsPositionsPointer)){
            this->updatePositionsNoRecursively((*this->rootPointer));
            (*this->updateElementsPositionsPointer)=true;
        }
    }

    //return the size
    inline edk::uint32 getSize(){
        //
        return (*this->sizeTreePointer);
    }
    inline edk::uint32 size(){
        //
        return this->getSize();
    }

    //Clean the tree
    virtual void clean(){
        (*this->updateElementsPositionsPointer)=false;
        if((*this->rootPointer)){
            //
            (*this->sizeTreePointer)=0u;
            this->cleanNoRecursively((*this->rootPointer));
        }
        (*this->rootPointer)=NULL;
    }

protected:
    //compare if the value is bigger
    virtual bool firstBiggerSecond(typeTemplate first,typeTemplate second){
        //
        if(first>second){
            //
            return true;
        }
        return false;
    }
    virtual bool firstEqualSecond(typeTemplate first,typeTemplate second){
        //
        if(first==second){
            //
            return true;
        }
        return false;
    }
    //Load
    virtual void loadElement(typeTemplate){}
    //Unload
    virtual void unloadElement(typeTemplate){}
    //Print
    virtual void printElement(typeTemplate){}
    //created for render the object
    virtual void renderElement(typeTemplate){}
    //created for render the object in wire mode
    virtual void renderWireElement(typeTemplate){}
    //created for draw the object
    virtual void drawElement(typeTemplate){}
    //created for draw the object in wire mode
    virtual void drawWireElement(typeTemplate){}
    //UPDATE
    virtual void updateElement(typeTemplate){}
private:
    //errorCode
    edk::uint16* errorCodePointer;
    //The root element on the TREE
    BinaryLeafStatic<typeTemplate>* root;
    BinaryLeafStatic<typeTemplate>** rootPointer;
    //save if need update the positions
    bool updateElementsPositions;
    bool* updateElementsPositionsPointer;
    //size of the tree
    edk::uint32 sizeTree;
    edk::uint32* sizeTreePointer;

    //compare if the value is bigger
    virtual bool firstPositionBiggerSecond(edk::uint32 first,edk::uint32 second){
        if(first>second){return true;}
        return false;
    }
    virtual bool firstPositionEqualSecond(edk::uint32 first,edk::uint32 second){
        if(first==second){return true;}
        return false;
    }
    //Find the position
    BinaryLeafStatic<typeTemplate>* findPosition(edk::uint32 position){
        //test if habe a root
        if((*this->rootPointer)){
            //find the position mother
            BinaryLeafStatic<typeTemplate>* temp = this->findPositionMother(position);
            if(temp){
                //test if the mother is the element
                if(this->firstPositionEqualSecond(temp->position,position)){
                    //return the mother
                    return temp;
                }
                else{
                    if(temp->left){
                        //test if the element is the left or right
                        if(this->firstPositionEqualSecond(temp->left->position,position)){
                            //return this left
                            return temp->left;
                        }
                    }
                    if(temp->right){
                        if(this->firstPositionEqualSecond(temp->right->position,position)){
                            //return the right
                            return temp->right;
                        }
                    }
                    //else it dont have the element in the tree
                }
            }
        }
        //else return NULL
        return NULL;
    }
    //Find the positionMother
    BinaryLeafStatic<typeTemplate>* findPositionMother(edk::uint32 position){
        //first test if have a root
        if((*this->rootPointer)){
            //tets if is equal root
            if(this->firstPositionEqualSecond((*this->rootPointer)->position,position)){
                //the return root
                return (*this->rootPointer);
            }
            //else search the element mother
            BinaryLeafStatic<typeTemplate>* temp = (*this->rootPointer);
            while(temp){
                //tets if the value is bigger the temp
                if(this->firstPositionBiggerSecond(position,temp->position)){
                    //then the next maybe is the RIGHT
                    if(temp->right){
                        //test if the value is equal
                        if(this->firstPositionEqualSecond(temp->right->position,position)){
                            //then find the element return the mother
                            return temp;
                        }
                        else{
                            //else the temp'receive the right
                            temp = temp->right;
                        }
                    }
                    else{
                        //else he dont have the element
                        break;
                    }
                }
                else{
                    //then the next maybe is the LEFT
                    //test if the left exist
                    if(temp->left){
                        //test if the value is equal
                        if(this->firstPositionEqualSecond(temp->left->position,position)){
                            //find the element. return the temp
                            return temp;
                        }
                        else{
                            //else the temp receive the left
                            temp=temp->left;
                        }
                    }
                    else{
                        //else it dont have the element
                        break;
                    }
                }
            }
        }
        //else return NULL
        return NULL;
    }

    //Find the element
    BinaryLeafStatic<typeTemplate>* find(typeTemplate value){
        //test if habe a root
        if((*this->rootPointer)){
            //then create a temporary element
            BinaryLeafStatic<typeTemplate> element;
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));
            //element.value=value;
            //find the mother
            BinaryLeafStatic<typeTemplate>* temp = this->findMother(value);
            if(temp){
                //test if the mother is the element
                if(this->firstEqualSecond(temp->value,element.value)){
                    //return the mother
                    return temp;
                }
                else{
                    if(temp->left){
                        //test if the element is the left or right
                        if(this->firstEqualSecond(temp->left->value,element.value)){
                            //return this left
                            return temp->left;
                        }
                    }
                    if(temp->right){
                        if(this->firstEqualSecond(temp->right->value,element.value)){
                            //return the right
                            return temp->right;
                        }
                    }
                    //else it dont have the element in the tree
                }
            }
        }
        //else return NULL
        return NULL;
    }
    BinaryLeafStatic<typeTemplate>* findBefore(typeTemplate value){
        //test if habe a root
        if((*this->rootPointer)){
            //then create a temporary element
            BinaryLeafStatic<typeTemplate> element;
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));
            //element.value=value;
            //find the mother
            BinaryLeafStatic<typeTemplate>* temp = this->findMotherBefore(value);
            if(temp){
                //test if the mother is the element
                if(this->firstEqualSecond(temp->value,element.value)){
                    if(temp->left){
                        return temp->left;
                    }
                }
                else{
                    //test if the element is the left or right
                    if(this->firstBiggerSecond(element.value,temp->value)){
                        //return this left
                        return temp;
                    }
                }
            }
        }
        //else return NULL
        return NULL;
    }
    BinaryLeafStatic<typeTemplate>* findAfter(typeTemplate value){
        //test if habe a root
        if((*this->rootPointer)){
            //then create a temporary element
            BinaryLeafStatic<typeTemplate> element;
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));
            //element.value=value;
            //find the mother
            BinaryLeafStatic<typeTemplate>* temp = this->findMotherAfter(value);
            if(temp){
                //test if the mother is the element
                if(this->firstEqualSecond(temp->value,element.value)){
                    if(temp->right){
                        return temp->right;
                    }
                }
                else{
                    //test if the element is the left or right
                    if(this->firstBiggerSecond(temp->value,element.value)){
                        //return this left
                        return temp;
                    }
                }
            }
        }
        //else return NULL
        return NULL;
    }
    //Find the elementMother
    BinaryLeafStatic<typeTemplate>* findMother(typeTemplate value){
        //first test if have a root
        if((*this->rootPointer)){
            //then create a temporary element
            BinaryLeafStatic<typeTemplate> element;
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));
            //element.value=value;
            //tets if is equal root
            if(this->firstEqualSecond((*this->rootPointer)->value,element.value)){
                //the return root
                return (*this->rootPointer);
            }
            //else search the element mother
            BinaryLeafStatic<typeTemplate>* temp = (*this->rootPointer);
            while(temp){
                //tets if the value is bigger the temp
                if(this->firstBiggerSecond(element.value,temp->value)){
                    //then the next maybe is the RIGHT
                    if(temp->right){
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->right->value,element.value)){
                            //then find the element return the mother
                            return temp;
                        }
                        else{
                            //else the temp'receive the right
                            temp = temp->right;
                        }
                    }
                    else{
                        //else he dont have the element
                        break;
                    }
                }
                else{
                    //then the next maybe is the LEFT
                    //test if the left exist
                    if(temp->left){
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->left->value,element.value)){
                            //find the element. return the temp
                            return temp;
                        }
                        else{
                            //else the temp receive the left
                            temp=temp->left;
                        }
                    }
                    else{
                        //else it dont have the element
                        break;
                    }
                }
            }
        }
        //else return NULL
        return NULL;
    }
    BinaryLeafStatic<typeTemplate>* findMotherBefore(typeTemplate value){
        //first test if have a root
        if((*this->rootPointer)){
            //then create a temporary element
            BinaryLeafStatic<typeTemplate> element;
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));
            //element.value=value;
            //tets if is equal root
            if(this->firstEqualSecond((*this->rootPointer)->value,element.value)){

                //then return root->left
                return (*this->rootPointer)->left;
            }
            //else search the element mother
            BinaryLeafStatic<typeTemplate>* temp = (*this->rootPointer);
            BinaryLeafStatic<typeTemplate>* tempFather = (*this->rootPointer);
            while(temp){
                //tets if the value is bigger the temp
                if(this->firstBiggerSecond(element.value,temp->value)){
                    //then the next maybe is the RIGHT
                    if(temp->right){
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->right->value,element.value)){
                            if(temp->left){
                                return temp->left;
                            }
                            else{
                                return tempFather;
                            }
                        }
                        else{
                            //else the temp'receive the right
                            tempFather=temp;
                            temp = temp->right;
                        }
                    }
                    else{
                        return temp;
                    }
                }
                else{
                    //then the next maybe is the LEFT
                    //test if the left exist
                    if(temp->left){
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->left->value,element.value)){
                            if(temp->left){
                                return temp->left;
                            }
                            else{
                                return tempFather;
                            }
                        }
                        else{
                            //else the temp receive the left
                            temp=temp->left;
                        }
                    }
                    else{
                        return tempFather;
                    }
                }
            }
        }
        //else return NULL
        return NULL;
    }
    BinaryLeafStatic<typeTemplate>* findMotherAfter(typeTemplate value){
        //first test if have a root
        if((*this->rootPointer)){
            //then create a temporary element
            BinaryLeafStatic<typeTemplate> element;
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));
            //element.value=value;
            //tets if is equal root
            if(this->firstEqualSecond((*this->rootPointer)->value,element.value)){
                //the return root
                return (*this->rootPointer)->right;
            }
            //else search the element mother
            BinaryLeafStatic<typeTemplate>* temp = (*this->rootPointer);
            BinaryLeafStatic<typeTemplate>* tempFather = (*this->rootPointer);
            while(temp){
                //tets if the value is bigger the temp
                if(this->firstBiggerSecond(element.value,temp->value)){
                    //then the next maybe is the RIGHT
                    if(temp->right){
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->right->value,element.value)){
                            if(temp->right){
                                return temp->right;
                            }
                            else{
                                return tempFather;
                            }
                        }
                        else{
                            //else the temp'receive the right
                            temp = temp->right;
                        }
                    }
                    else{
                        return tempFather;
                    }
                }
                else{
                    //then the next maybe is the LEFT
                    //test if the left exist
                    if(temp->left){
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->left->value,element.value)){
                            if(temp->right){
                                return temp->right;
                            }
                            else{
                                return tempFather;
                            }
                        }
                        else{
                            //else the temp receive the left
                            tempFather=temp;
                            temp=temp->left;
                        }
                    }
                    else{
                        return temp;
                    }
                }
            }
        }
        //else return NULL
        return NULL;
    }
    //Find the Last left
    BinaryLeafStatic<typeTemplate>* findMotherLeftLeaf(BinaryLeafStatic<typeTemplate>* root){
        //test if the root is alloc
        if(root){
            BinaryLeafStatic<typeTemplate>* mother = NULL;
            //then find the last left
            while(root->left){
                mother=root;
                //get the left
                root=root->left;
            }
            //return the last left
            return mother;
        }
        //else return NULL
        return NULL;
    }
    //Find the Last right
    BinaryLeafStatic<typeTemplate>* findMotherRightLeaf(BinaryLeafStatic<typeTemplate>* root){
        //test if the root is alloc
        if(root){
            BinaryLeafStatic<typeTemplate>* mother = NULL;
            //then find the last right
            while(root->right){
                mother=root;
                //get the right
                root=root->right;
            }
            //return the last right
            return mother;
        }
        //else return NULL
        return NULL;
    }

    //increment and decrement the size
    void incrementSize(){
        //
        (*this->updateElementsPositionsPointer)=false;
        (*this->sizeTreePointer)+=1u;
    }
    bool decrementSize(){
        //
        if((*this->sizeTreePointer)){
            //
            (*this->sizeTreePointer)-=1u;

            (*this->updateElementsPositionsPointer)=false;
            //return true
            return true;
        }
        //else return false
        return false;
    }

    //recursively to load
    void updatePositionsRecursively(BinaryLeafStatic<typeTemplate>* temp,edk::uint32 *position=NULL){
        if(temp){
            //
            if(temp->left){
                this->updatePositionsRecursively(temp->left,position);
            }
            //update the position
            if(position){
                temp->position = *position;
                *position++;
            }
            if(temp->right){
                this->updatePositionsRecursively(temp->right);
            }
        }
    }
    void updatePositionsNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        edk::uint32 position=0u;
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //load
                temp->position = position;
                position++;
                //run the callback functions
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }

    //recursively to load
    void loadRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->loadRecursively(temp->left);
            }
            //update
            this->loadElement(temp->value);
            if(temp->right){
                this->loadRecursively(temp->right);
            }
        }
    }
    void loadNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //load
                this->loadElement(temp->value);
                //run the callback functions
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to unload
    void unloadRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->unloadRecursively(temp->left);
            }
            //update
            this->unloadElement(temp->value);
            if(temp->right){
                this->unloadRecursively(temp->right);
            }
        }
    }
    void unloadNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //unload
                this->unloadElement(temp->value);
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //update the values runing the update function
    void updateRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->updateRecursively(temp->left);
            }
            //update
            this->updateElement(temp->value);
            if(temp->right){
                this->updateRecursively(temp->right);
            }
        }
    }
    void updateNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //update
                this->updateElement(temp->value);
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to print
    void printRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->printRecursively(temp->left);
            }
            //print
            this->printElement(temp->value);
            if(temp->right){
                //
                this->printRecursively(temp->right);
            }
        }
    }
    void printNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //print
                this->printElement(temp->value);
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to render
    void renderRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);
            }
            //print
            this->renderElement(temp->value);
            if(temp->right){
                //
                this->renderRecursively(temp->right);
            }
        }
    }
    void renderNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                this->renderElement(temp->value);
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to renderWire
    void renderWireRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);
            }
            //print
            this->renderElement(temp->value);
            if(temp->right){
                //
                this->renderRecursively(temp->right);
            }
        }
    }
    void renderWireNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                this->renderWireElement(temp->value);
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to draw
    void drawRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);
            }
            //print
            this->drawElement(temp->value);
            if(temp->right){
                //
                this->renderRecursively(temp->right);
            }
        }
    }
    void drawNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                this->drawElement(temp->value);
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to drawWire
    void drawWireRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);
            }
            //print
            this->drawWireElement(temp->value);
            if(temp->right){
                //
                this->renderRecursively(temp->right);
            }
        }
    }
    void drawWireNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                this->drawWireElement(temp->value);
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //set if find it
    BinaryLeafStatic<typeTemplate>* getRecursively(BinaryLeafStatic<typeTemplate>* temp,edk::uint32* count, edk::uint32 pos){
        //the return
        BinaryLeafStatic<typeTemplate>* ret=NULL;
        if(temp){
            if(temp->left){
                //
                ret=this->getRecursively(temp->left,count,pos);
                //test if find
                if(ret){
                    return ret;
                }
            }
            //test if count is == position
            if(*count==pos){
                //then return the typeTemplate
                return temp;
            }
            else{
                //increment count
                count[0]++;
            }
            //print
            if(temp->right){
                //
                ret=this->getRecursively(temp->right,count,pos);
                //test if find
                if(ret){
                    return ret;
                }
            }
        }
        //return the ret
        return ret;
    }
    BinaryLeafStatic<typeTemplate>* getNoRecursively(BinaryLeafStatic<typeTemplate>* temp,edk::uint32 pos){
        edk::uint32 count = 0u;
        BinaryLeafStatic<typeTemplate>* ret = NULL;
        bool find=false;
        //test if have temp
        while(temp){
            if(!find){
                if(temp->readed==0u){
                    temp->readed=1u;
                    if(temp->left){
                        temp = temp->left;
                        continue;
                    }
                }
                if(temp->readed==1u){
                    //test if count is == position
                    if(count==pos){
                        //then return the typeTemplate
                        ret = temp;
                        find=true;
                    }
                    else{
                        //increment count
                        ++count;
                    }
                    temp->readed=2u;
                    if(temp->right){
                        temp = temp->right;
                        continue;
                    }
                }
                if(temp->readed==2u){
                    temp->readed=0u;
                    temp = temp->father;
                }
            }
            else{
                temp->readed=0u;
                temp = temp->father;
            }
        }
        return ret;
    }
    //clean recursively
    void cleanRecursively(BinaryLeafStatic<typeTemplate>* temp){
        //
        if(temp){
            //
            if(temp->right){
                this->cleanRecursively(temp->right);
            }
            temp->right=NULL;
            if(temp->left){
                this->cleanRecursively(temp->left);
            }
            temp->left=NULL;
            temp->Destructor();
            delete temp;
        }
    }
    void cleanNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        BinaryLeafStatic<typeTemplate>* tempDelete;
        //test if have temp
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                temp->left=NULL;
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->right=NULL;
                temp->readed=0u;
                tempDelete = temp;
                temp = temp->father;
                tempDelete->Destructor();
                delete tempDelete;
            }
        }
    }
    //balance the tree starting from a new leaf
    void balance(BinaryLeafStatic<typeTemplate>* leaf){
        //test the temp
        if(leaf){
            BinaryLeafStatic<typeTemplate>* temp = leaf;
            //increment the counters
            while(temp){
                //test if havethe father
                if(temp->father){
                    //test witch side is the temp
                    if(temp->father->left == temp){
                        //increment the counter
                        temp->father->counter--;
                    }
                    else if(temp->father->right == temp){
                        //decrement the counter
                        temp->father->counter++;
                    }
                }
                //then select the father
                temp = temp->father;
            }
            //now balance the tree
            temp = leaf;
            BinaryLeafStatic<typeTemplate>* temp2;
            BinaryLeafStatic<typeTemplate>* father;
            bool continuing = false;
            while(temp){
                //test if the counter is bigger then 1 or -1
                if(temp->counter>1){
                    //test if have the father
                    if(temp->father){
                        //need balance the leaf
                        if(temp->right){
                            //have only the right
                            temp2 = temp->right;
                            if(temp2->right){
                                if(temp2->left){
                                    //do nothing
                                }
                                else{
                                    //have only the right2
                                    //rotate left
                                    father = temp->father;
                                    //left right
                                    if(father->left == temp){
                                        //
                                        father->left = temp->right;
                                        father->left->counter--;
                                        father->left->left = temp;
                                        father->left->left->father = father->left->right->father = father->left;
                                        father->left->father = father;
                                        father->left->right->counter--;
                                    }
                                    else if(father->right == temp){
                                        //
                                        father->right = temp->right;
                                        father->right->counter--;
                                        father->right->left = temp;
                                        father->right->left->father = father->right->right->father = father->right;
                                        father->right->father = father;
                                        father->right->right->counter--;
                                    }
                                    temp->right=NULL;
                                    temp->counter--;
                                }
                            }
                            else if(temp2->left){
                                BinaryLeafStatic<typeTemplate>*  newRoot = temp2;
                                temp2 = temp2->left;
                                if(temp2->right){
                                    //do nothing
                                }
                                else{
                                    //
                                    //rotate right
                                    temp2->right = newRoot;
                                    newRoot->father = temp2;
                                    newRoot->left = NULL;
                                    newRoot->counter--;
                                    //
                                    temp->right = temp2;
                                    temp2->father=temp;
                                    temp2->counter--;
                                    if(!continuing){
                                        continuing = true;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    else if(temp == (*this->rootPointer)){
                        //need change the root
                        if(temp->right){
                            //have only the right
                            temp2 = temp->right;
                            if(temp2->right){
                                if(temp2->left){
                                    //do nothing
                                }
                                else{
                                    //have only the right2
                                    //rotate left
                                    (*this->rootPointer) = temp->right;
                                    (*this->rootPointer)->father = NULL;
                                    (*this->rootPointer)->counter--;
                                    //
                                    (*this->rootPointer)->left = temp;
                                    (*this->rootPointer)->left->father = (*this->rootPointer)->right->father = (*this->rootPointer);
                                    temp->right=NULL;
                                    temp->counter--;
                                    //
                                    (*this->rootPointer)->right->counter--;
                                }
                            }
                            else if(temp2->left){
                                BinaryLeafStatic<typeTemplate>*  newRoot = temp2;
                                temp2 = temp2->left;
                                if(temp2->right){
                                    //do nothing
                                }
                                else{
                                    //
                                    //rotate right
                                    temp2->right = newRoot;
                                    newRoot->father = temp2;
                                    newRoot->left = NULL;
                                    newRoot->counter--;
                                    //
                                    temp->right = temp2;
                                    temp2->father=temp;
                                    temp2->counter--;
                                    if(!continuing){
                                        continuing = true;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }
                else if(temp->counter<-1){
                    //test if have the father
                    if(temp->father){
                        //need balance the leaf
                        if(temp->left){
                            //have only the left
                            temp2 = temp->left;
                            if(temp2->left){
                                if(temp2->right){
                                    //do nothing
                                }
                                else{
                                    //have only the left2
                                    //rotate right
                                    father = temp->father;
                                    //right left
                                    if(father->right == temp){
                                        //
                                        father->right = temp->left;
                                        father->right->counter--;
                                        father->right->right = temp;
                                        father->right->right->father = father->right->left->father = father->right;
                                        father->right->father = father;
                                        father->right->left->counter--;
                                    }
                                    else if(father->left == temp){
                                        //
                                        father->left = temp->left;
                                        father->left->counter--;
                                        father->left->right = temp;
                                        father->left->right->father = father->left->left->father = father->left;
                                        father->left->father = father;
                                        father->left->left->counter--;
                                    }
                                    temp->left=NULL;
                                    temp->counter--;
                                }
                            }
                            else if(temp2->right){
                                BinaryLeafStatic<typeTemplate>*  newRoot = temp2;
                                temp2 = temp2->right;
                                if(temp2->left){
                                    //do nothing
                                }
                                else{
                                    //
                                    //rotate left
                                    temp2->left = newRoot;
                                    newRoot->father = temp2;
                                    newRoot->right = NULL;
                                    newRoot->counter--;
                                    //
                                    temp->left = temp2;
                                    temp2->father=temp;
                                    temp2->counter--;
                                    if(!continuing){
                                        continuing = true;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                    else if(temp == (*this->rootPointer)){
                        //need change the root
                        if(temp->left){
                            //have only the left
                            temp2 = temp->left;
                            if(temp2->left){
                                if(temp2->right){
                                    //do nothing
                                }
                                else{
                                    //have only the left2
                                    //rotate right
                                    (*this->rootPointer) = temp->left;
                                    (*this->rootPointer)->father = NULL;
                                    (*this->rootPointer)->counter--;
                                    //
                                    (*this->rootPointer)->right = temp;
                                    (*this->rootPointer)->right->father = (*this->rootPointer)->left->father = (*this->rootPointer);
                                    temp->left=NULL;
                                    temp->counter--;
                                    //
                                    (*this->rootPointer)->left->counter--;
                                }
                            }
                            else if(temp2->right){
                                BinaryLeafStatic<typeTemplate>*  newRoot = temp2;
                                temp2 = temp2->right;
                                if(temp2->left){
                                    //do nothing
                                }
                                else{
                                    //
                                    //rotate left
                                    temp2->left = newRoot;
                                    newRoot->father = temp2;
                                    newRoot->right = NULL;
                                    newRoot->counter--;
                                    //
                                    temp->left = temp2;
                                    temp2->father=temp;
                                    temp2->counter--;
                                    if(!continuing){
                                        continuing = true;
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }

                //then select the father
                temp = temp->father;
                continuing = false;
            }
        }
    }
#if defined(EDK_DEBUG_VECTOR)
    inline edk::uint64 generateDebugValue(typeTemplate* value){
        edk::uint64 newValue=0uL;
        if(sizeof(typeTemplate)>=sizeof(newValue)){
            memcpy((void*)&newValue,(void*)value,sizeof(newValue));
        }
        else{
            memcpy((void*)&newValue,(void*)value,sizeof(typeTemplate));
        }
        return newValue;
    }
#endif
private:
    edk::classID classThis;
};
//String TREE
class NameTreeStatic:public edk::vector::BinaryTreeStatic<edk::Name*>{
public:
    //Construtor
    NameTreeStatic(){
        this->classThis=NULL;
        this->Constructor();
    }
    //Destrutor
    virtual ~NameTreeStatic(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::BinaryTreeStatic<edk::Name*>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->deleteAllNames();
        }
        edk::vector::BinaryTreeStatic<edk::Name*>::Destructor();
    }

    //Functions in const
    //ADD
    bool addName(const edk::char8* value){
        return this->addName((edk::char8*) value);
    }
    bool addName(edk::char8* value){
        //
        if(value){
            edk::Name* temp = new edk::Name(value);
            if(temp){
                //
                if(edk::vector::BinaryTreeStatic<edk::Name*>::add(temp)){
                    //
                    return true;
                }
                //delete the temp
                delete temp;
            }
        }
        return false;
    }
    //REMOVE
    bool removeName(const edk::char8* value){
        //
        return this->removeName((edk::char8*) value);
    }
    bool removeName(edk::char8* value){
        //
        edk::Name find(value);
        return edk::vector::BinaryTreeStatic<edk::Name*>::remove(&find);
    }
    //REMOVE THE ELEMENT IN POSITION
    bool removeNameInPosition(edk::uint32 position){
        //get the element
        edk::Name* temp = this->getElementInPosition(position);
        if(temp){
            return edk::vector::BinaryTreeStatic<edk::Name*>::remove(temp);
        }
        return false;
    }
    //DELETE
    bool deleteName(const edk::char8* value){
        //
        return this->deleteName((edk::char8*) value);
    }
    bool deleteName(edk::char8* value){
        //
        edk::Name find(value);
        edk::Name *temp =  edk::vector::BinaryTreeStatic<edk::Name*>::getElement(&find);
        if(edk::vector::BinaryTreeStatic<edk::Name*>::remove(temp)){
            delete temp;
            return true;
        }
        return false;
    }
    //DELETE THE ELEMENT IN POSITION
    bool deleteNameInPosition(edk::uint32 position){
        //get the element
        edk::Name* temp = this->getElementInPosition(position);
        if(temp){
            if(edk::vector::BinaryTreeStatic<edk::Name*>::remove(temp)){
                delete temp;
                return true;
            }
        }
        return false;
    }
    //DELETE ALL THE NAMES
    void deleteAllNames(){
        for(edk::uint32 i=0u;i<edk::vector::BinaryTreeStatic<edk::Name*>::size();i++){
            edk::Name* temp = this->getElementInPosition(i);
            if(temp){
                delete temp;
                temp=NULL;
            }
        }
        edk::vector::BinaryTreeStatic<edk::Name*>::clean();
    }
    //remove all names
    //HAVE ELEMENT
    bool haveName(const edk::char8* value){
        //
        return this->haveName((edk::char8*)value);
    }
    bool haveName(edk::char8* value){
        //
        edk::Name temp(value);
        return edk::vector::BinaryTreeStatic<edk::Name*>::haveElement(&temp);
    }
    //GET ELEMENT
    edk::Name* getElementByName(const edk::char8* value){
        //
        return getElementByName((edk::char8*) value);
    }
    edk::Name* getElementByName(edk::char8* value){
        //
        edk::Name temp(value);
        return edk::vector::BinaryTreeStatic<edk::Name*>::getElement(&temp);
    }
    //GET NAME IN POSITION
    edk::char8* getNameInPosition(edk::uint32 position){
        //get the position in the TREE
        edk::Name* temp = this->getElementInPosition(position);
        //if have the position
        if(temp){
            //return the name
            return temp->getName();
        }
        //else return NULL
        return NULL;
    }

protected:
    //Virtual Functions
    bool firstBiggerSecond(edk::Name* first,edk::Name* second){
        //test the values
        if(first && second){
            //then thes the strings
            //return this->firstNameBiggerSecond(first->getName(),second->getName());
            return first->nameBiggerThan(second->getName());
        }
        return false;
    }
    bool firstEqualSecond(edk::Name* first,edk::Name* second){
        //test the values
        if(first && second){
            //then thes the strings
            //return this->stringEqual(first->getName(),second->getName());
            return first->nameEqual(second->getName());
        }
        return false;
    }
    //Print
    void printElement(edk::char8* value){
        //
        edk::Name* temp = (edk::Name*)value;
        if(temp){
            //
            printf("\nString '%s'"
                   ,temp->getName()
                   );
        }
        else{
            //
            printf("\nString NULL");
        }
    }

private:
    //compare the names
    bool firstNameBiggerSecond(edk::char8* name1,edk::char8* name2){
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
    bool stringEqual(edk::char8* name1,edk::char8* name2){
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
private:
    edk::classID classThis;
};

//enum with the map to go into the value
enum edkLeafsStaticMap{
    edkLeafStaticNULL=0u,
    edkLeaftStaticLEFT,
    edkLeaftStaticRIGHT,
    //
    edkLeaftStaticSize
};
//treeMAPPING
class TreeMapStatic: public edk::vector::QueueStatic<edk::vector::edkLeafsStaticMap>{
public:
    TreeMapStatic(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~TreeMapStatic(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::QueueStatic<edk::vector::edkLeafsStaticMap>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
        }
        edk::vector::QueueStatic<edk::vector::edkLeafsStaticMap>::Destructor();
    }
private:
    edk::classID classThis;
};

template <class typeTemplate>
class LeafsOnlyTreeStatic{
public:
    //errorCode
    edk::uint16 errorCode;
    //Construtor
    LeafsOnlyTreeStatic(){
        this->classThis=NULL;
        this->Constructor();
    }
    //Destrutor
    virtual ~LeafsOnlyTreeStatic(){
        this->Destructor();
    }

    void Constructor(){
        if(this->classThis!=this){
            this->classThis=this;

            this->map.Constructor();

            this->root=NULL;
            this->errorCode=0u;
            this->sizeTree=0u;
            this->dontDestruct = false;

            this->errorCodePointer = &this->errorCode;
            this->rootPointer = &this->root;
            this->sizeTreePointer = &this->sizeTree;
            this->mapPointer = &this->map;
            this->elementSelectedPointer = &this->elementSelected;
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            if(!this->dontDestruct){
                this->clean();
                this->root=NULL;
                this->sizeTree=0u;
            }
            this->dontDestruct=false;

            this->map.Destructor();
        }
    }

    //Add a value on the tree
    bool add(typeTemplate value){
        //Test if is the root element
        if(!(*this->rootPointer)){
            //then add the root element
            (*this->rootPointer) = new BinaryLeafStatic<typeTemplate>;
            if((*this->rootPointer)){
                (*this->rootPointer)->Constructor();
                //set the value
                memcpy((void*)&(*this->rootPointer)->value,(void*)&value,sizeof(typeTemplate));
                //increment the sizeTree
                this->incrementSize();
                //then return true
                return true;
            }
        }
        else{
            //Find the position to add the object
            BinaryLeafStatic<typeTemplate>* temp=(*this->rootPointer);
            //create the value
            BinaryLeafStatic<typeTemplate>* newValue = new BinaryLeafStatic<typeTemplate>;
            BinaryLeafStatic<typeTemplate>* newSecondValue = new BinaryLeafStatic<typeTemplate>;
            //Test if create the newValue
            if(newValue && newSecondValue){
                newValue->Constructor();
                newSecondValue->Constructor();
                memcpy((void*)&newValue->value,(void*)&value,sizeof(typeTemplate));
                //Find the position
                //test if the temp exist
                while(temp){
                    //then test if the value is equal
                    if(this->firstEqualSecond(temp->value, newValue->value)
                            &&(!(*this->rootPointer)->left && !(*this->rootPointer)->right)
                            ){
                        //The tree have the value. Delete the new value and return the tree value.
                        newValue->Destructor();
                        delete newValue;
                        newValue=NULL;
                        newSecondValue->Destructor();
                        delete newSecondValue;
                        newSecondValue=NULL;
                        //
                        (*this->errorCodePointer)=EDK_ERROR_HAVE_VALUE;
                        return false;
                    }
                    else{
                        //else test if the first is bigger
                        if(this->firstBiggerSecond(newValue->value ,temp->value) ){
                            //then test if have a right
                            if(temp->right){
                                //temp receive the right
                                temp = temp->right;
                            }
                            else{
                                //else add the value in right
                                if(temp->left){
                                    BinaryLeafStatic<typeTemplate>* newThirdValue = new BinaryLeafStatic<typeTemplate>;
                                    if(newThirdValue){
                                        newThirdValue->Constructor();
                                        memcpy((void*)&newThirdValue->value,(void*)&temp->value,sizeof(typeTemplate));
                                        temp->right = newThirdValue;
                                        temp->right->father = temp;
                                        temp=temp->right;
                                    }
                                }
                                temp->right = newValue;  newValue=NULL;
                                temp->right->father = temp;
                                //set the secondValue
                                memcpy((void*)&newSecondValue->value,(void*)&temp->value,sizeof(typeTemplate));
                                temp->left = newSecondValue;
                                temp->left->father = temp;
                                //increment the sizeTree
                                this->incrementSize();
                                //return true
                                return true;
                            }
                        }
                        else{
                            //then test if have a left
                            if(temp->left){
                                //temp receive the left
                                temp=temp->left;
                            }
                            else{
                                //else add the value in left
                                if(temp->right){
                                    BinaryLeafStatic<typeTemplate>* newThirdValue = new BinaryLeafStatic<typeTemplate>;
                                    if(newThirdValue){
                                        newThirdValue->Constructor();
                                        memcpy((void*)&newThirdValue->value,(void*)&temp->value,sizeof(typeTemplate));
                                        temp->left = newThirdValue;
                                        temp->left->father = temp;
                                        temp=temp->left;
                                    }
                                }
                                temp->left = newValue;  newValue=NULL;
                                temp->left->father = temp;
                                //set the secondValue
                                memcpy((void*)&newSecondValue->value,(void*)&temp->value,sizeof(typeTemplate));
                                temp->right = newSecondValue;
                                temp->right->father = temp;
                                //increment the sizeTree
                                this->incrementSize();
                                //return true
                                return true;
                            }
                        }
                    }
                }
                newValue->Destructor();
                delete newValue;
                newSecondValue->Destructor();
                delete newSecondValue;
            }
        }
        //else return false
        (*this->errorCodePointer)=EDK_ERROR_HAVE_VALUE;
        return false;
    }

    //Load the elements
    virtual void load(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->loadNoRecursively((*this->rootPointer));
        }
    }
    //Unload the elements
    virtual void unload(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->unloadNoRecursively((*this->rootPointer));
        }
    }
    //Print the elements
    virtual void print(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->printNoRecursively((*this->rootPointer));
        }
    }
    //render the elements
    virtual void render(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->renderNoRecursively((*this->rootPointer));
        }
    }
    //render the elements in wire mode
    virtual void renderWire(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->renderWireNoRecursively((*this->rootPointer));
        }
    }
    //draw the elements
    virtual void draw(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->drawNoRecursively((*this->rootPointer));
        }
    }
    //draw the elements in wire mode
    virtual void drawWire(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->drawWireNoRecursively((*this->rootPointer));
        }
    }
    virtual void update(){
        //test if have root
        if((*this->rootPointer)){
            //then update
            this->updateNoRecursively((*this->rootPointer));
        }
    }
    //print all the tree
    virtual void printTree(){
        //test if have root
        if((*this->rootPointer)){
            //then update
            this->printTreeNoRecursively((*this->rootPointer));
        }
    }

    //Get the rootValue
    typeTemplate getRootValue(){
        if(this->haveRoot()){
            return (typeTemplate)(*this->rootPointer)->value;
        }
        else{
            return (typeTemplate)0u;
        }
    }
    //Return true if have a root
    bool haveRoot(){
        if((*this->rootPointer)){
            return true;
        }
        //else return false
        return false;
    }
    bool haveRootChild(){
        if(this->haveRoot()){
            //test the childs
            return ((*this->rootPointer)->left || (*this->rootPointer)->right);
        }
        //else return false
        return false;
    }

    //test if have the element
    bool haveElement(typeTemplate value){
        //test if have the value
        if(this->find(value)){
            //return true
            return true;
        }
        //else return false
        return false;
    }

    //get the element map
    bool getElementMap(typeTemplate value,edk::vector::TreeMapStatic *map){
        if(map){
            //find the value and generate the map
            return this->find(value,map);
        }
        return false;
    }

    //return the element
    typeTemplate getElement(typeTemplate value){
        //find the element pointer
        BinaryLeafStatic<typeTemplate>* ret = this->find(value);
        //test if the element is founded
        if(ret){
            //return the value
            return ret->value;
        }
        //else return zero
        typeTemplate retZero;
        memset((void*)&retZero,0u,sizeof(typeTemplate));
        return retZero;
    }

    //return the size
    edk::uint32 getSize(){
        return (*this->sizeTreePointer);
    }
    edk::uint32 size(){
        return this->getSize();
    }

    //select an element by turns
    bool selectRoot(){
        (*this->elementSelectedPointer)=NULL;
        if((*this->rootPointer)){
            (*this->elementSelectedPointer)=(*this->rootPointer);
            return true;
        }
        return false;
    }
    //return true if the selected is a leaf
    bool selectIsLeaf(){
        if((*this->elementSelectedPointer)){
            return (!(*this->elementSelectedPointer)->left && !(*this->elementSelectedPointer)->right);
        }
        return false;
    }
    //turn the select
    bool selectTurnLeft(){
        if((*this->elementSelectedPointer)){
            if((*this->elementSelectedPointer)->left){
                (*this->elementSelectedPointer) = (*this->elementSelectedPointer)->left;
                return true;
            }
        }
        return false;
    }
    bool selectTurnRight(){
        if((*this->elementSelectedPointer)){
            if((*this->elementSelectedPointer)->right){
                (*this->elementSelectedPointer) = (*this->elementSelectedPointer)->right;
                return true;
            }
        }
        return false;
    }
    //get the selectValue
    typeTemplate selectGetValue(){
        typeTemplate ret;
        memset(&ret,0,sizeof(typeTemplate));
        if((*this->elementSelectedPointer)){
            //get the value
            memcpy(&ret,&(*this->elementSelectedPointer)->value,sizeof(typeTemplate));
        }
        return ret;
    }

    //Clean the tree
    virtual void clean(){
        if((*this->rootPointer)){
            (*this->sizeTreePointer)=0u;
            this->cleanNoRecursively((*this->rootPointer));
        }
        (*this->rootPointer)=NULL;
    }
    //set to cant Destruct
    void cantDestructor(){
        this->dontDestruct=true;
    }
protected:
    //compare if the value is bigger
    virtual bool firstBiggerSecond(typeTemplate first,typeTemplate second){
        if(first>second){
            return true;
        }
        return false;
    }
    virtual bool firstEqualSecond(typeTemplate first,typeTemplate second){
        if(first==second){
            return true;
        }
        return false;
    }
    //Load
    virtual void loadElement(typeTemplate){}
    //Unload
    virtual void unloadElement(typeTemplate){}
    //Print
    virtual void printElement(typeTemplate){}
    //created for render the object
    virtual void renderElement(typeTemplate){}
    //created for render the object in wire mode
    virtual void renderWireElement(typeTemplate){}
    //created for draw the object
    virtual void drawElement(typeTemplate){}
    //created for draw the object in wire mode
    virtual void drawWireElement(typeTemplate){}
    //UPDATE
    virtual void updateElement(typeTemplate){}
private:
    edk::uint16* errorCodePointer;
    //The root element on the TREE
    BinaryLeafStatic<typeTemplate>** rootPointer;
    BinaryLeafStatic<typeTemplate>* root;
    //size of the tree
    edk::uint32* sizeTreePointer;
    edk::uint32 sizeTree;
    //set if cant run the destructor
    bool dontDestruct;

    //temporary map
    edk::vector::TreeMapStatic* mapPointer;
    edk::vector::TreeMapStatic map;

    BinaryLeafStatic<typeTemplate>** elementSelectedPointer;
    BinaryLeafStatic<typeTemplate>* elementSelected;

    //Find the element
    bool find(typeTemplate value,edk::vector::TreeMapStatic *map=NULL){
        if(!map){
            map=&this->map;
        }
        //first test if have a root
        if((*this->rootPointer)){
            //then create a temporary element
            BinaryLeafStatic<typeTemplate> element;
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));
            //tets if is equal root
            if(this->firstEqualSecond((*this->rootPointer)->value,element.value)
                    && (!(*this->rootPointer)->left && !(*this->rootPointer)->right)
                    ){
                //the return root
                return false;
            }
            //else search the element
            BinaryLeafStatic<typeTemplate>* temp = (*this->rootPointer);
            while(temp){
                //test if the value is equal
                if(this->firstEqualSecond(temp->value,element.value)){
                    edk::uchar8 dontHave=2u;
                    if(temp->left || temp->right){
                        //find it. Then calculate the map
                        while(true){
                            dontHave=0u;
                            if(temp->left){
                                if(this->firstEqualSecond(temp->left->value,element.value)){
                                    temp = temp->left;
                                    map->pushBack(edk::vector::edkLeaftStaticLEFT);

                                    continue;
                                }
                            }
                            else{
                                dontHave++;
                            }
                            if(temp->right){
                                if(this->firstEqualSecond(temp->right->value,element.value)){
                                    temp = temp->right;
                                    map->pushBack(edk::vector::edkLeaftStaticRIGHT);

                                    continue;
                                }
                            }
                            else{
                                dontHave++;
                            }

                            break;
                        }
                    }
                    if(dontHave>1u){

                        return true;
                    }

                    return false;
                }
                //tets if the value is bigger the temp
                else if(this->firstBiggerSecond(element.value,temp->value)){
                    //then the next maybe is the RIGHT
                    if(temp->right){
                        map->pushBack(edk::vector::edkLeaftStaticRIGHT);
                        //Go RIGHT
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->right->value,element.value)){
                            edk::uchar8 dontHave=2u;
                            temp = temp->right;
                            if(temp->left || temp->right){
                                //find it. Then calculate the map
                                while(true){
                                    dontHave=0u;
                                    if(temp->left){
                                        if(this->firstEqualSecond(temp->left->value,element.value)){
                                            temp = temp->left;
                                            map->pushBack(edk::vector::edkLeaftStaticLEFT);

                                            continue;
                                        }
                                    }
                                    else{
                                        dontHave++;
                                    }
                                    if(temp->right){
                                        if(this->firstEqualSecond(temp->right->value,element.value)){
                                            temp = temp->right;
                                            map->pushBack(edk::vector::edkLeaftStaticRIGHT);

                                            continue;
                                        }
                                    }
                                    else{
                                        dontHave++;
                                    }

                                    break;
                                }
                            }
                            if(dontHave>1u){

                                return true;
                            }

                            return false;
                        }
                        else{
                            //else the temp'receive the right
                            temp=temp->right;
                        }
                    }
                    else{
                        //else he dont have the element
                        break;
                    }
                }
                else{
                    //then the next maybe is the LEFT
                    //test if the left exist
                    if(temp->left){
                        map->pushBack(edk::vector::edkLeaftStaticLEFT);
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->left->value,element.value)){
                            edk::uchar8 dontHave=2u;
                            temp = temp->left;
                            if(temp->left || temp->right){
                                //find it. Then calculate the map
                                while(true){
                                    dontHave=0u;
                                    if(temp->left){
                                        if(this->firstEqualSecond(temp->left->value,element.value)){
                                            temp = temp->left;
                                            map->pushBack(edk::vector::edkLeaftStaticLEFT);

                                            continue;
                                        }
                                    }
                                    else{
                                        dontHave++;
                                    }
                                    if(temp->right){
                                        if(this->firstEqualSecond(temp->right->value,element.value)){
                                            temp = temp->right;
                                            map->pushBack(edk::vector::edkLeaftStaticRIGHT);

                                            continue;
                                        }
                                    }
                                    else{
                                        dontHave++;
                                    }

                                    break;
                                }
                            }
                            if(dontHave>1u){

                                return true;
                            }

                            return false;
                        }
                        else{
                            //else the temp receive the left
                            temp=temp->left;
                        }
                    }
                    else{
                        //else it dont have the element
                        break;
                    }
                }
            }
        }
        //else return false
        return false;
    }

    //increment and decrement the size
    void incrementSize(){
        //
        (*this->sizeTreePointer)+=1u;
    }
    bool decrementSize(){
        //
        if((*this->sizeTreePointer)){
            //
            (*this->sizeTreePointer)-=1u;

            //return true
            return true;
        }
        //else return false
        return false;
    }

    //recursively to load
    void loadRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->loadRecursively(temp->left);
            }
            //update
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->loadElement(temp->value);
            }
            if(temp->right){
                this->loadRecursively(temp->right);
            }
        }
    }
    void loadNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //load
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->loadElement(temp->value);
                }
                //run the callback functions
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to unload
    void unloadRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->unloadRecursively(temp->left);
            }
            //update
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->unloadElement(temp->value);
            }
            if(temp->right){
                this->unloadRecursively(temp->right);
            }
        }
    }
    void unloadNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //unload
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->unloadElement(temp->value);
                }
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //update the values runing the update function
    void updateRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->updateRecursively(temp->left);
            }
            //update
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->updateElement(temp->value);
            }
            if(temp->right){
                this->updateRecursively(temp->right);
            }
        }
    }
    void updateNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //update
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->updateElement(temp->value);
                }
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to print
    void printRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->printRecursively(temp->left);
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->printElement(temp->value);
            }
            if(temp->right){
                //
                this->printRecursively(temp->right);
            }
        }
    }
    void printNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //print
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->printElement(temp->value);
                }
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to render
    void renderRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->renderElement(temp->value);
            }
            if(temp->right){
                //
                this->renderRecursively(temp->right);
            }
        }
    }
    void renderNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->renderElement(temp->value);
                }
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to renderWire
    void renderWireRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->renderElement(temp->value);
            }
            if(temp->right){
                //
                this->renderRecursively(temp->right);
            }
        }
    }
    void renderWireNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->renderWireElement(temp->value);
                }
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to draw
    void drawRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->drawElement(temp->value);
            }
            if(temp->right){
                //
                this->renderRecursively(temp->right);
            }
        }
    }
    void drawNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->drawElement(temp->value);
                }
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //recursively to drawWire
    void drawWireRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->drawWireElement(temp->value);
            }
            if(temp->right){
                //
                this->renderRecursively(temp->right);
            }
        }
    }
    void drawWireNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->drawWireElement(temp->value);
                }
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
            }
        }
    }
    //printTree
    void printTreeRecursively(BinaryLeafStatic<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                printf("\nGo->left");fflush(stdout);
                this->printElement(temp->value);
                this->renderRecursively(temp->left);
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                printf("\nPrint");fflush(stdout);
                this->printElement(temp->value);
            }
            if(temp->right){
                //
                printf("\nGo->right");fflush(stdout);
                this->printElement(temp->value);
                this->renderRecursively(temp->right);
            }
        }
    }
    void printTreeNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    printf("\nGo->left");fflush(stdout);
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                printf("\nPRINT");fflush(stdout);
                this->printElement(temp->value);
                temp->readed=2u;
                if(temp->right){
                    printf("\nGo->right");fflush(stdout);
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;
                temp = temp->father;
                printf("\nGo->father");fflush(stdout);
            }
        }
    }
    //set if find it
    BinaryLeafStatic<typeTemplate>* getRecursively(BinaryLeafStatic<typeTemplate>* temp,edk::uint32* count, edk::uint32 pos){
        //the return
        BinaryLeafStatic<typeTemplate>* ret=NULL;
        if(temp){
            if(temp->left){
                //
                ret=this->getRecursively(temp->left,count,pos);
                //test if find
                if(ret){
                    return ret;
                }
            }
            //test if count is == position
            if(*count==pos
                    && (!(*this->rootPointer)->left && !(*this->rootPointer)->right)
                    ){
                //then return the typeTemplate
                return temp;
            }
            else if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                //increment count
                count[0]++;
            }
            //print
            if(temp->right){
                //
                ret=this->getRecursively(temp->right,count,pos);
                //test if find
                if(ret){
                    return ret;
                }
            }
        }
        //return the ret
        return ret;
    }
    BinaryLeafStatic<typeTemplate>* getNoRecursively(BinaryLeafStatic<typeTemplate>* temp,edk::uint32 pos){
        edk::uint32 count = 0u;
        BinaryLeafStatic<typeTemplate>* ret = NULL;
        bool find=false;
        //test if have temp
        while(temp){
            if(!find){
                if(temp->readed==0u){
                    temp->readed=1u;
                    if(temp->left){
                        temp = temp->left;
                        continue;
                    }
                }
                if(temp->readed==1u){
                    //test if count is == position
                    if(count==pos
                            && (!(*this->rootPointer)->left && !(*this->rootPointer)->right)
                            ){
                        //then return the typeTemplate
                        ret = temp;
                        find=true;
                    }
                    else if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                        //increment count
                        ++count;
                    }
                    temp->readed=2u;
                    if(temp->right){
                        temp = temp->right;
                        continue;
                    }
                }
                if(temp->readed==2u){
                    temp->readed=0u;
                    temp = temp->father;
                }
            }
            else{
                temp->readed=0u;
                temp = temp->father;
            }
        }
        return ret;
    }
    //clean recursively
    void cleanRecursively(BinaryLeafStatic<typeTemplate>* temp){
        //
        if(temp){
            //
            if(temp->right){
                this->cleanRecursively(temp->right);
            }
            temp->right=NULL;
            if(temp->left){
                this->cleanRecursively(temp->left);
            }
            temp->left=NULL;
            temp->Destructor();
            delete temp;
        }
    }
    void cleanNoRecursively(BinaryLeafStatic<typeTemplate>* temp){
        BinaryLeafStatic<typeTemplate>* tempDelete;
        //test if have temp
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;
                if(temp->left){
                    temp = temp->left;
                    continue;
                }
            }
            if(temp->readed==1u){
                temp->left=NULL;
                temp->readed=2u;
                if(temp->right){
                    temp = temp->right;
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->right=NULL;
                temp->readed=0u;
                tempDelete = temp;
                temp = temp->father;
                tempDelete->Destructor();
                delete tempDelete;
            }
        }
    }
private:
    edk::classID classThis;
};
}
}

#endif // BINARYTREESTATIC_H
