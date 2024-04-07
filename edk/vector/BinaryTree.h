#ifndef EDK_VECTOR_BINARYTREE_H
#define EDK_VECTOR_BINARYTREE_H

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
#include "./Array.h"
#include "./Queue.h"

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
class treeObj:public edk::vector::BinaryTree<obj*>{
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
               );edkEnd();
    }
    //Unload
    virtual void unloadElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );edkEnd();
    }
    //Print
    virtual void printElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );edkEnd();
    }
    virtual void renderElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );edkEnd();
    }
    virtual void renderWireElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );edkEnd();
    }
    virtual void drawElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );edkEnd();
    }
    virtual void drawWireElement(obj* value){
        printf("\nElement %u"
               ,(edk::uint32)value
               );edkEnd();
    }
    //UPDATE
    virtual void updateElement(obj* value){
        //update the value
        value++;edkEnd();
    }

    //Load the elements
    virtual void load(){
        edk::vector::BinaryTree<obj*>::load();edkEnd();
    }
    //Unload the elements
    virtual void unload(){
        edk::vector::BinaryTree<obj*>::unload();edkEnd();
    }
    //Print the elements
    virtual void print(){
        edk::vector::BinaryTree<obj*>::print();edkEnd();
    }
    //render the elements
    virtual void render(){
        edk::vector::BinaryTree<obj*>::render();edkEnd();
    }
    virtual void renderWire(){
        edk::vector::BinaryTree<obj*>::renderWire();edkEnd();
    }
    //draw the elements
    virtual void draw(){
        edk::vector::BinaryTree<obj*>::draw();edkEnd();
    }
    virtual void drawWire(){
        edk::vector::BinaryTree<obj*>::drawWire();edkEnd();
    }
    //update the elements
    virtual void update(){
        edk::vector::BinaryTree<obj*>::update();edkEnd();
    }
};

*/


//namespaces
namespace edk{
namespace vector{
//Tree callbacks
template <class typeTemplate>
class BinaryTreeCallback{
public:
    BinaryTreeCallback(){}
    virtual void callbackLoadElement(typeTemplate){}
    virtual void callbackUnloadElement(typeTemplate){}
    virtual void callbackPrintElement(typeTemplate){}
    virtual void callbackRenderElement(typeTemplate){}
    virtual void callbackRenderWireElement(typeTemplate){}
    virtual void callbackDrawElement(typeTemplate){}
    virtual void callbackDrawWireElement(typeTemplate){}
    virtual void callbackUpdateElement(typeTemplate){}
};
template <class typeTemplate>
class UnaryLeaf{
    //Construtor
public:
    UnaryLeaf(){
        //
        this->next=NULL;edkEnd();
        this->father=NULL;edkEnd();
        this->position=0u;
        memset(&this->value,0u,sizeof(typeTemplate));edkEnd();
    }
    //Destrutor
    ~UnaryLeaf(){
        //
    }
    //LEFT
    UnaryLeaf* next;
    //add the father
    UnaryLeaf* father;

    //Value of the leaf
    typeTemplate value;
    //position of the leaf in the tree
    edk::uint32 position;
};
template <class typeTemplate>
class BinaryLeaf{
    //Construtor
public:
    BinaryLeaf(){
        //
        this->left=NULL;edkEnd();
        this->right=NULL;edkEnd();
        this->father=NULL;edkEnd();
        this->counter=0;edkEnd();
        this->readed=0u;edkEnd();
        memset((void*)&this->value,0u,sizeof(typeTemplate));edkEnd();
    }
    //Destrutor
    ~BinaryLeaf(){
        //
    }
    //RIGHT
    BinaryLeaf* left;
    BinaryLeaf* right;
    //add the father
    BinaryLeaf* father;

    //counter to balance the tree
    edk::int32 counter;
    edk::uint8 readed;

    //Value of the leaf
    typeTemplate value;
    //position of the leaf in the tree
    edk::uint32 position;
};
template <class typeTemplate>
class BinaryTree{
public:
    //errorCode
    edk::uint16 errorCode;
    //Construtor
    BinaryTree(){
        this->updateElementsPositions=false;
        this->root=NULL;edkEnd();
        this->errorCode=0u;edkEnd();
        this->sizeTree=0u;edkEnd();
        this->dontDestruct = false;edkEnd();

        this->errorCodePointer = &this->errorCode;edkEnd();
        this->rootPointer = &this->root;edkEnd();
        this->updateElementsPositionsPointer = &this->updateElementsPositions;edkEnd();
        this->sizeTreePointer = &this->sizeTree;edkEnd();
    }
    //Destrutor
    virtual ~BinaryTree(){
        //
        if(!this->dontDestruct){
            this->clean();edkEnd();
            this->root=NULL;edkEnd();
            this->sizeTree=0u;edkEnd();
        }
        this->dontDestruct=false;edkEnd();
    }
    //Add a value on the tree
    bool add(typeTemplate value){
        //Test if is the root element
        if(!(*this->rootPointer)){
            //then add the root element
            (*this->rootPointer) = new BinaryLeaf<typeTemplate>;edkEnd();
            if((*this->rootPointer)){
                //set the value
                memcpy((void*)&(*this->rootPointer)->value,(void*)&value,sizeof(typeTemplate));edkEnd();
                //increment the sizeTree
                this->incrementSize();edkEnd();
                //then return true
                return true;
            }
        }
        else{
            //Find the position to add the object
            BinaryLeaf<typeTemplate>* temp=(*this->rootPointer);edkEnd();
            //create the value
            BinaryLeaf<typeTemplate>* newValue = new BinaryLeaf<typeTemplate>;edkEnd();
            //Test if create the newValue
            if(newValue){
                memcpy((void*)&newValue->value,(void*)&value,sizeof(typeTemplate));edkEnd();
                //Find the position
                //test if the temp exist
                while(temp){
                    //then test if the value is equal
                    if(this->firstEqualSecond(temp->value, newValue->value)){
                        //The tree have the value. Delete the new value and return the tree value.
                        delete newValue;edkEnd();
                        newValue=NULL;edkEnd();
                        //
                        (*this->errorCodePointer)=EDK_ERROR_HAVE_VALUE;edkEnd();
                        return false;
                    }
                    else{
                        //else test if the first is bigger
                        if(this->firstBiggerSecond(newValue->value ,temp->value) ){
                            //then test if have a right
                            if(temp->right){
                                //temp receive the right
                                temp = temp->right;edkEnd();
                            }
                            else{
                                //else add the value in right
                                temp->right = newValue;edkEnd(); newValue=NULL;edkEnd();
                                temp->right->father = temp;edkEnd();
                                //increment the sizeTree
                                this->incrementSize();edkEnd();
                                //balance the tree
                                ///TODO - Fix the balance function in the future
                                //this->balance(temp->right);edkEnd();
                                //return true
                                return true;
                            }
                        }
                        else{
                            //then test if have a left
                            if(temp->left){
                                //temp receive the left
                                temp=temp->left;edkEnd();
                            }
                            else{
                                //else add the value in left
                                temp->left = newValue;edkEnd(); newValue=NULL;edkEnd();
                                temp->left->father = temp;edkEnd();
                                //increment the sizeTree
                                this->incrementSize();edkEnd();
                                //balance the tree
                                ///TODO - Fix the balance function in the future
                                //this->balance(temp->left);edkEnd();
                                //return true
                                return true;
                            }
                        }
                    }
                }
                delete newValue;edkEnd();
            }
        }
        //else return false
        (*this->errorCodePointer)=EDK_ERROR_HAVE_VALUE;edkEnd();
        return false;
    }

    //Load the elements
    virtual void load(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->loadNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //Unload the elements
    virtual void unload(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->unloadNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //Print the elements
    virtual void print(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->printNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //render the elements
    virtual void render(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->renderNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //render the elements in wire mode
    virtual void renderWire(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->renderWireNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //draw the elements
    virtual void draw(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->drawNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //draw the elements in wire mode
    virtual void drawWire(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->drawWireNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    virtual void update(){
        //test if have root
        if((*this->rootPointer)){
            //then update
            this->updateNoRecursively((*this->rootPointer));edkEnd();
        }
    }

    //Remove the element
    bool remove(typeTemplate value){
        //first find the element mother
        BinaryLeaf<typeTemplate>* mother = this->findMother(value);edkEnd();
        BinaryLeaf<typeTemplate> element;edkEnd();
        memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));edkEnd();
        if(mother){
            //if find the mother search who is the element
            if(mother->left){
                //test if it's left
                if(this->firstEqualSecond(mother->left->value,element.value)){
                    BinaryLeaf<typeTemplate>* leaf = NULL;edkEnd();
                    //test if the element (mother->left) have childrens
                    if(mother->left->right){
                        //then get the left leaf
                        //save the element
                        BinaryLeaf<typeTemplate>* temp = mother->left;edkEnd();
                        if((leaf = this->findMotherLeftLeaf(mother->left->right))){
                            //then pull the leaf to the mother->left
                            mother->left = leaf->left;edkEnd();
                            if(mother->left){
                                mother->left->father = mother;edkEnd();
                            }
                            //arrage the leaf
                            leaf->left = leaf->left->right;edkEnd();
                            if(leaf->left){
                                leaf->left->father = leaf;edkEnd();
                            }
                            //then the new mother->left receive the two temps.
                            mother->left->left = temp->left;edkEnd();
                            if(mother->left->left){
                                mother->left->left->father = mother->left;edkEnd();
                            }
                            mother->left->right = temp->right;edkEnd();
                            if(mother->left->right){
                                mother->left->right->father = mother->left;edkEnd();
                            }
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->left=mother->left->right;edkEnd();
                            if(mother->left){
                                mother->left->father = mother;edkEnd();
                            }
                            mother->left->left = temp->left;edkEnd();
                            if(mother->left->left){
                                mother->left->left->father = mother->left;edkEnd();
                            }
                        }
                        //delete the element
                        delete temp;edkEnd();
                        temp=NULL;edkEnd();
                        //decrement the sizeTree
                        this->decrementSize();edkEnd();
                        //return true
                        return true;
                    }
                    if(mother->left->left){
                        //then get the right leaf
                        //save the element
                        BinaryLeaf<typeTemplate>* temp = mother->left;edkEnd();
                        if((leaf = this->findMotherRightLeaf(mother->left->left))){
                            //then pull the leaf to the mother->left
                            mother->left = leaf->right;edkEnd();
                            if(mother->left){
                                mother->left->father = mother;edkEnd();
                            }
                            //arrage the leaf
                            leaf->right = leaf->right->left;edkEnd();
                            if(leaf->right){
                                leaf->right->father = leaf;edkEnd();
                            }
                            //then the new mother->left receive the two temps.
                            mother->left->left = temp->left;edkEnd();
                            if(mother->left->left){
                                mother->left->left->father = mother->left;edkEnd();
                            }
                            mother->left->right = temp->right;edkEnd();
                            if(mother->left->right){
                                mother->left->right->father = mother->left;edkEnd();
                            }
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->left=mother->left->left;edkEnd();
                            if(mother->left){
                                mother->left->father = mother;edkEnd();
                            }
                            mother->left->right = temp->right;edkEnd();
                            if(mother->left->right){
                                mother->left->right->father = mother->left;edkEnd();
                            }
                        }
                        //delete the element
                        delete temp;edkEnd();
                        temp=NULL;edkEnd();
                        //decrement the sizeTree
                        this->decrementSize();edkEnd();
                        //return true
                        return true;
                    }
                    //He dont have childrens

                    //delete the element
                    delete mother->left;edkEnd();
                    mother->left=NULL;edkEnd();
                    //decrement the sizeTree
                    this->decrementSize();edkEnd();
                    return true;
                }
            }




            if(mother->right){
                //test if it's left
                if(this->firstEqualSecond(mother->right->value,element.value)){
                    BinaryLeaf<typeTemplate>* leaf = NULL;edkEnd();
                    //test if the element (mother->right) have childrens
                    if(mother->right->right){
                        //then get the left leaf
                        //save the element
                        BinaryLeaf<typeTemplate>* temp = mother->right;edkEnd();
                        if((leaf = this->findMotherLeftLeaf(mother->right->right))){
                            //then pull the leaf to the mother->right
                            mother->right = leaf->left;edkEnd();
                            if(mother->right){
                                mother->right->father = mother;edkEnd();
                            }
                            //arrage the leaf
                            leaf->left = leaf->left->right;edkEnd();
                            if(leaf->left){
                                leaf->left->father = leaf;edkEnd();
                            }
                            //then the new mother->right receive the two temps.
                            mother->right->left = temp->left;edkEnd();
                            if(mother->right->left){
                                mother->right->left->father = mother->right;edkEnd();
                            }
                            mother->right->right = temp->right;edkEnd();
                            if(mother->right->right){
                                mother->right->right->father = mother->right;edkEnd();
                            }
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->right=mother->right->right;edkEnd();
                            if(mother->right){
                                mother->right->father = mother;edkEnd();
                            }
                            mother->right->left = temp->left;edkEnd();
                            if(mother->right->left){
                                mother->right->left->father = mother->right;edkEnd();
                            }
                        }
                        //delete the element
                        delete temp;edkEnd();
                        temp=NULL;edkEnd();
                        //decrement the sizeTree
                        this->decrementSize();edkEnd();
                        //return true
                        return true;
                    }
                    if(mother->right->left){
                        //then get the right leaf
                        //save the element
                        BinaryLeaf<typeTemplate>* temp = mother->right;edkEnd();
                        if((leaf = this->findMotherRightLeaf(mother->right->left))){
                            //then pull the leaf to the mother->right
                            mother->right = leaf->right;edkEnd();
                            if(mother->right){
                                mother->right->father = mother;edkEnd();
                            }
                            //arrage the leaf
                            leaf->right = leaf->right->left;edkEnd();
                            if(leaf->right){
                                leaf->right->father = leaf;edkEnd();
                            }
                            //then the new mother->right receive the two temps.
                            mother->right->left = temp->left;edkEnd();
                            if(mother->right->left){
                                mother->right->left->father = mother->right;edkEnd();
                            }
                            mother->right->right = temp->right;edkEnd();
                            if(mother->right->right){
                                mother->right->right->father = mother->right;edkEnd();
                            }
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->right=mother->right->left;edkEnd();
                            if(mother->right){
                                mother->right->father = mother;edkEnd();
                            }
                            mother->right->right = temp->right;edkEnd();
                            if(mother->right->right){
                                mother->right->right->father = mother->right;edkEnd();
                            }
                        }
                        //delete the element
                        delete temp;edkEnd();
                        temp=NULL;edkEnd();
                        //decrement the sizeTree
                        this->decrementSize();edkEnd();
                        //return true
                        return true;
                    }
                    //He dont have childrens

                    //just delete;edkEnd();
                    delete mother->right;edkEnd();
                    mother->right=NULL;edkEnd();
                    //decrement the sizeTree
                    this->decrementSize();edkEnd();
                    return true;
                }
            }




            if(mother==(*this->rootPointer)){
                //
                BinaryLeaf<typeTemplate>* leaf = NULL;edkEnd();
                //test if have a left or right
                if((*this->rootPointer)->right){
                    //then get the left leaf
                    //save the element
                    BinaryLeaf<typeTemplate>* temp = (*this->rootPointer);edkEnd();
                    if((leaf = this->findMotherLeftLeaf((*this->rootPointer)->right))){
                        //then pull the leaf to the (*this->rootPointer)
                        (*this->rootPointer) = leaf->left;edkEnd();
                        if((*this->rootPointer)){
                            (*this->rootPointer)->father=NULL;edkEnd();
                        }
                        //arrage the leaf
                        leaf->left = leaf->left->right;edkEnd();
                        if(leaf->left){
                            leaf->left->father = leaf;edkEnd();
                        }
                        //then the new (*this->rootPointer) receive the two temps.
                        (*this->rootPointer)->left = temp->left;edkEnd();
                        if((*this->rootPointer)->left){
                            (*this->rootPointer)->left->father = (*this->rootPointer);edkEnd();
                        }
                        (*this->rootPointer)->right = temp->right;edkEnd();
                        if((*this->rootPointer)->right){
                            (*this->rootPointer)->right->father = (*this->rootPointer);edkEnd();
                        }
                    }
                    else{
                        //else just get the right
                        //pull the right
                        (*this->rootPointer)=(*this->rootPointer)->right;edkEnd();
                        if((*this->rootPointer)){
                            (*this->rootPointer)->father=NULL;edkEnd();
                        }
                        (*this->rootPointer)->left = temp->left;edkEnd();
                        if((*this->rootPointer)->left){
                            (*this->rootPointer)->left->father = (*this->rootPointer);edkEnd();
                        }
                    }
                    //delete the element
                    delete temp;edkEnd();
                    temp=NULL;edkEnd();
                    //decrement the sizeTree
                    this->decrementSize();edkEnd();
                    //return true
                    return true;
                }
                if((*this->rootPointer)->left){
                    //then get the right leaf
                    //save the element
                    BinaryLeaf<typeTemplate>* temp = (*this->rootPointer);edkEnd();
                    if((leaf = this->findMotherRightLeaf((*this->rootPointer)->left))){
                        //then pull the leaf to the (*this->rootPointer)
                        (*this->rootPointer) = leaf->right;edkEnd();
                        if((*this->rootPointer)){
                            (*this->rootPointer)->father=NULL;edkEnd();
                        }
                        //arrage the leaf
                        leaf->right = leaf->right->left;edkEnd();
                        if(leaf->right){
                            leaf->right->father = leaf;edkEnd();
                        }
                        //then the new (*this->rootPointer) receive the two temps.
                        (*this->rootPointer)->left = temp->left;edkEnd();
                        if((*this->rootPointer)->left){
                            (*this->rootPointer)->left->father = (*this->rootPointer);edkEnd();
                        }
                        (*this->rootPointer)->right = temp->right;edkEnd();
                        if((*this->rootPointer)->right){
                            (*this->rootPointer)->right->father = (*this->rootPointer);edkEnd();
                        }
                    }
                    else{
                        //else just get the right
                        //pull the right
                        (*this->rootPointer)=(*this->rootPointer)->left;edkEnd();
                        if((*this->rootPointer)){
                            (*this->rootPointer)->father = NULL;edkEnd();
                        }
                        (*this->rootPointer)->right = temp->right;edkEnd();
                        if((*this->rootPointer)->right){
                            (*this->rootPointer)->right->father = (*this->rootPointer);edkEnd();
                        }
                    }
                    //delete the element
                    delete temp;edkEnd();
                    temp=NULL;edkEnd();
                    //decrement the sizeTree
                    this->decrementSize();edkEnd();
                    //return true
                    return true;
                }

                //remove the root
                delete (*this->rootPointer);edkEnd();
                (*this->rootPointer)=NULL;edkEnd();
                //decrement the sizeTree
                this->decrementSize();edkEnd();
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
            return (typeTemplate)(*this->rootPointer)->value;edkEnd();
        }
        else{
            //
            return (typeTemplate)0u;edkEnd();
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
            return ((*this->rootPointer)->left || (*this->rootPointer)->right);edkEnd();
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
        BinaryLeaf<typeTemplate>* ret = this->find(value);edkEnd();
        //test if the element is founded
        if(ret){
            //return the value
            return ret->value;edkEnd();
        }
        //else return zero
        typeTemplate retZero;edkEnd();
        memset((void*)&retZero,0u,sizeof(typeTemplate));edkEnd();
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
        BinaryLeaf<typeTemplate>* ret = this->find(value);edkEnd();
        //test if the element is founded
        if(ret){
            //return the value
            return ret->position;edkEnd();
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
                BinaryLeaf<typeTemplate>* ret = this->findPosition(position);edkEnd();
                //test if the element is founded
                if(ret){
                    //return the value
                    return ret->value;edkEnd();
                }
            }
            else{
                //then find the element pointer
                BinaryLeaf<typeTemplate>* ret = this->getNoRecursively((*this->rootPointer)/*,&count*/,position);edkEnd();
                //test if the element is founded
                if(ret){
                    //return the value
                    return ret->value;edkEnd();
                }
            }
        }
        typeTemplate ret;edkEnd(); memset((void*)&ret,0u,sizeof(typeTemplate));edkEnd();
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
        return (*this->sizeTreePointer);edkEnd();
    }
    inline edk::uint32 size(){
        //
        return this->getSize();edkEnd();
    }

    //Clean the tree
    virtual void clean(){
        (*this->updateElementsPositionsPointer)=false;
        if((*this->rootPointer)){
            //
            (*this->sizeTreePointer)=0u;edkEnd();
            this->cleanNoRecursively((*this->rootPointer));edkEnd();
        }
        (*this->rootPointer)=NULL;edkEnd();
    }
    //set to cant Destruct
    void cantDestruct(){
        //
        this->dontDestruct=true;edkEnd();
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
    BinaryLeaf<typeTemplate>** rootPointer;
    BinaryLeaf<typeTemplate>* root;
    //save if need update the positions
    bool* updateElementsPositionsPointer;
    bool updateElementsPositions;
    //size of the tree
    edk::uint32* sizeTreePointer;
    edk::uint32 sizeTree;
    //set if cant run the destructor
    bool dontDestruct;

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
    BinaryLeaf<typeTemplate>* findPosition(edk::uint32 position){
        //test if habe a root
        if((*this->rootPointer)){
            //find the position mother
            BinaryLeaf<typeTemplate>* temp = this->findPositionMother(position);edkEnd();
            if(temp){
                //test if the mother is the element
                if(this->firstPositionEqualSecond(temp->position,position)){
                    //return the mother
                    return temp;edkEnd();
                }
                else{
                    if(temp->left){
                        //test if the element is the left or right
                        if(this->firstPositionEqualSecond(temp->left->position,position)){
                            //return this left
                            return temp->left;edkEnd();
                        }
                    }
                    if(temp->right){
                        if(this->firstPositionEqualSecond(temp->right->position,position)){
                            //return the right
                            return temp->right;edkEnd();
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
    BinaryLeaf<typeTemplate>* findPositionMother(edk::uint32 position){
        //first test if have a root
        if((*this->rootPointer)){
            //tets if is equal root
            if(this->firstPositionEqualSecond((*this->rootPointer)->position,position)){
                //the return root
                return (*this->rootPointer);edkEnd();
            }
            //else search the element mother
            BinaryLeaf<typeTemplate>* temp = (*this->rootPointer);edkEnd();
            while(temp){
                //tets if the value is bigger the temp
                if(this->firstPositionBiggerSecond(position,temp->position)){
                    //then the next maybe is the RIGHT
                    if(temp->right){
                        //test if the value is equal
                        if(this->firstPositionEqualSecond(temp->right->position,position)){
                            //then find the element return the mother
                            return temp;edkEnd();
                        }
                        else{
                            //else the temp'receive the right
                            temp = temp->right;edkEnd();
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
                            return temp;edkEnd();
                        }
                        else{
                            //else the temp receive the left
                            temp=temp->left;edkEnd();
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
    BinaryLeaf<typeTemplate>* find(typeTemplate value){
        //test if habe a root
        if((*this->rootPointer)){
            //then create a temporary element
            BinaryLeaf<typeTemplate> element;edkEnd();
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));edkEnd();
            //element.value=value;edkEnd();
            //find the mother
            BinaryLeaf<typeTemplate>* temp = this->findMother(value);edkEnd();
            if(temp){
                //test if the mother is the element
                if(this->firstEqualSecond(temp->value,element.value)){
                    //return the mother
                    return temp;edkEnd();
                }
                else{
                    if(temp->left){
                        //test if the element is the left or right
                        if(this->firstEqualSecond(temp->left->value,element.value)){
                            //return this left
                            return temp->left;edkEnd();
                        }
                    }
                    if(temp->right){
                        if(this->firstEqualSecond(temp->right->value,element.value)){
                            //return the right
                            return temp->right;edkEnd();
                        }
                    }
                    //else it dont have the element in the tree
                }
            }
        }
        //else return NULL
        return NULL;
    }
    //Find the elementMother
    BinaryLeaf<typeTemplate>* findMother(typeTemplate value){
        //first test if have a root
        if((*this->rootPointer)){
            //then create a temporary element
            BinaryLeaf<typeTemplate> element;edkEnd();
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));edkEnd();
            //element.value=value;edkEnd();
            //tets if is equal root
            if(this->firstEqualSecond((*this->rootPointer)->value,element.value)){
                //the return root
                return (*this->rootPointer);edkEnd();
            }
            //else search the element mother
            BinaryLeaf<typeTemplate>* temp = (*this->rootPointer);edkEnd();
            while(temp){
                //tets if the value is bigger the temp
                if(this->firstBiggerSecond(element.value,temp->value)){
                    //then the next maybe is the RIGHT
                    if(temp->right){
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->right->value,element.value)){
                            //then find the element return the mother
                            return temp;edkEnd();
                        }
                        else{
                            //else the temp'receive the right
                            temp = temp->right;edkEnd();
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
                            return temp;edkEnd();
                        }
                        else{
                            //else the temp receive the left
                            temp=temp->left;edkEnd();
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
    //Find the Last left
    BinaryLeaf<typeTemplate>* findMotherLeftLeaf(BinaryLeaf<typeTemplate>* root){
        //test if the root is alloc
        if(root){
            BinaryLeaf<typeTemplate>* mother = NULL;edkEnd();
            //then find the last left
            while(root->left){
                mother=root;edkEnd();
                //get the left
                root=root->left;edkEnd();
            }
            //return the last left
            return mother;edkEnd();
        }
        //else return NULL
        return NULL;
    }
    //Find the Last right
    BinaryLeaf<typeTemplate>* findMotherRightLeaf(BinaryLeaf<typeTemplate>* root){
        //test if the root is alloc
        if(root){
            BinaryLeaf<typeTemplate>* mother = NULL;edkEnd();
            //then find the last right
            while(root->right){
                mother=root;edkEnd();
                //get the right
                root=root->right;edkEnd();
            }
            //return the last right
            return mother;edkEnd();
        }
        //else return NULL
        return NULL;
    }

    //increment and decrement the size
    void incrementSize(){
        //
        (*this->updateElementsPositionsPointer)=false;
        (*this->sizeTreePointer)+=1u;edkEnd();
    }
    bool decrementSize(){
        //
        if((*this->sizeTreePointer)){
            //
            (*this->sizeTreePointer)-=1u;edkEnd();

            (*this->updateElementsPositionsPointer)=false;
            //return true
            return true;
        }
        //else return false
        return false;
    }

    //recursively to load
    void updatePositionsRecursively(BinaryLeaf<typeTemplate>* temp,edk::uint32 *position=NULL){
        if(temp){
            //
            if(temp->left){
                this->updatePositionsRecursively(temp->left,position);edkEnd();
            }
            //update the position
            if(position){
                temp->position = *position;edkEnd();
                *position++;
            }
            if(temp->right){
                this->updatePositionsRecursively(temp->right);edkEnd();
            }
        }
    }
    void updatePositionsNoRecursively(BinaryLeaf<typeTemplate>* temp){
        edk::uint32 position=0u;
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //load
                temp->position = position;edkEnd();
                position++;
                //run the callback functions
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }

    //recursively to load
    void loadRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->loadRecursively(temp->left);edkEnd();
            }
            //update
            this->loadElement(temp->value);edkEnd();
            if(temp->right){
                this->loadRecursively(temp->right);edkEnd();
            }
        }
    }
    void loadNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //load
                this->loadElement(temp->value);edkEnd();
                //run the callback functions
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to unload
    void unloadRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->unloadRecursively(temp->left);edkEnd();
            }
            //update
            this->unloadElement(temp->value);edkEnd();
            if(temp->right){
                this->unloadRecursively(temp->right);edkEnd();
            }
        }
    }
    void unloadNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //unload
                this->unloadElement(temp->value);edkEnd();
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //update the values runing the update function
    void updateRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->updateRecursively(temp->left);edkEnd();
            }
            //update
            this->updateElement(temp->value);edkEnd();
            if(temp->right){
                this->updateRecursively(temp->right);edkEnd();
            }
        }
    }
    void updateNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //update
                this->updateElement(temp->value);edkEnd();
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to print
    void printRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->printRecursively(temp->left);edkEnd();
            }
            //print
            this->printElement(temp->value);edkEnd();
            if(temp->right){
                //
                this->printRecursively(temp->right);edkEnd();
            }
        }
    }
    void printNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //print
                this->printElement(temp->value);edkEnd();
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to render
    void renderRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);edkEnd();
            }
            //print
            this->renderElement(temp->value);edkEnd();
            if(temp->right){
                //
                this->renderRecursively(temp->right);edkEnd();
            }
        }
    }
    void renderNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                this->renderElement(temp->value);edkEnd();
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to renderWire
    void renderWireRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);edkEnd();
            }
            //print
            this->renderElement(temp->value);edkEnd();
            if(temp->right){
                //
                this->renderRecursively(temp->right);edkEnd();
            }
        }
    }
    void renderWireNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                this->renderWireElement(temp->value);edkEnd();
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to draw
    void drawRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);edkEnd();
            }
            //print
            this->drawElement(temp->value);edkEnd();
            if(temp->right){
                //
                this->renderRecursively(temp->right);edkEnd();
            }
        }
    }
    void drawNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                this->drawElement(temp->value);edkEnd();
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to drawWire
    void drawWireRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);edkEnd();
            }
            //print
            this->drawWireElement(temp->value);edkEnd();
            if(temp->right){
                //
                this->renderRecursively(temp->right);edkEnd();
            }
        }
    }
    void drawWireNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                this->drawWireElement(temp->value);edkEnd();
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //set if find it
    BinaryLeaf<typeTemplate>* getRecursively(BinaryLeaf<typeTemplate>* temp,edk::uint32* count, edk::uint32 pos){
        //the return
        BinaryLeaf<typeTemplate>* ret=NULL;edkEnd();
        if(temp){
            if(temp->left){
                //
                ret=this->getRecursively(temp->left,count,pos);edkEnd();
                //test if find
                if(ret){
                    return ret;
                }
            }
            //test if count is == position
            if(*count==pos){
                //then return the typeTemplate
                return temp;edkEnd();
            }
            else{
                //increment count
                count[0]++;edkEnd();
            }
            //print
            if(temp->right){
                //
                ret=this->getRecursively(temp->right,count,pos);edkEnd();
                //test if find
                if(ret){
                    return ret;
                }
            }
        }
        //return the ret
        return ret;
    }
    BinaryLeaf<typeTemplate>* getNoRecursively(BinaryLeaf<typeTemplate>* temp,edk::uint32 pos){
        edk::uint32 count = 0u;edkEnd();
        BinaryLeaf<typeTemplate>* ret = NULL;edkEnd();
        bool find=false;edkEnd();
        //test if have temp
        while(temp){
            if(!find){
                if(temp->readed==0u){
                    temp->readed=1u;edkEnd();
                    if(temp->left){
                        temp = temp->left;edkEnd();
                        continue;
                    }
                }
                if(temp->readed==1u){
                    //test if count is == position
                    if(count==pos){
                        //then return the typeTemplate
                        ret = temp;edkEnd();
                        find=true;edkEnd();
                    }
                    else{
                        //increment count
                        ++count;edkEnd();
                    }
                    temp->readed=2u;edkEnd();
                    if(temp->right){
                        temp = temp->right;edkEnd();
                        continue;
                    }
                }
                if(temp->readed==2u){
                    temp->readed=0u;edkEnd();
                    temp = temp->father;edkEnd();
                }
            }
            else{
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
        return ret;
    }
    //clean recursively
    void cleanRecursively(BinaryLeaf<typeTemplate>* temp){
        //
        if(temp){
            //
            if(temp->right){
                this->cleanRecursively(temp->right);edkEnd();
            }
            temp->right=NULL;edkEnd();
            if(temp->left){
                this->cleanRecursively(temp->left);edkEnd();
            }
            temp->left=NULL;edkEnd();
            delete temp;edkEnd();
        }
    }
    void cleanNoRecursively(BinaryLeaf<typeTemplate>* temp){
        BinaryLeaf<typeTemplate>* tempDelete;edkEnd();
        //test if have temp
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                temp->left=NULL;edkEnd();
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->right=NULL;edkEnd();
                temp->readed=0u;edkEnd();
                tempDelete = temp;edkEnd();
                temp = temp->father;edkEnd();
                delete tempDelete;edkEnd();
            }
        }
    }
    //balance the tree starting from a new leaf
    void balance(BinaryLeaf<typeTemplate>* leaf){
        //test the temp
        if(leaf){
            BinaryLeaf<typeTemplate>* temp = leaf;edkEnd();
            //increment the counters
            while(temp){
                //test if havethe father
                if(temp->father){
                    //test witch side is the temp
                    if(temp->father->left == temp){
                        //increment the counter
                        temp->father->counter--;edkEnd();
                    }
                    else if(temp->father->right == temp){
                        //decrement the counter
                        temp->father->counter++;edkEnd();
                    }
                }
                //then select the father
                temp = temp->father;edkEnd();
            }
            //now balance the tree
            temp = leaf;edkEnd();
            BinaryLeaf<typeTemplate>* temp2;edkEnd();
            BinaryLeaf<typeTemplate>* father;edkEnd();
            bool continuing = false;edkEnd();
            while(temp){
                //test if the counter is bigger then 1 or -1
                if(temp->counter>1){
                    //test if have the father
                    if(temp->father){
                        //need balance the leaf
                        if(temp->right){
                            //have only the right
                            temp2 = temp->right;edkEnd();
                            if(temp2->right){
                                if(temp2->left){
                                    //do nothing
                                }
                                else{
                                    //have only the right2
                                    //rotate left
                                    father = temp->father;edkEnd();
                                    //left right
                                    if(father->left == temp){
                                        //
                                        father->left = temp->right;edkEnd();
                                        father->left->counter--;edkEnd();
                                        father->left->left = temp;edkEnd();
                                        father->left->left->father = father->left->right->father = father->left;edkEnd();
                                        father->left->father = father;edkEnd();
                                        father->left->right->counter--;edkEnd();
                                    }
                                    else if(father->right == temp){
                                        //
                                        father->right = temp->right;edkEnd();
                                        father->right->counter--;edkEnd();
                                        father->right->left = temp;edkEnd();
                                        father->right->left->father = father->right->right->father = father->right;edkEnd();
                                        father->right->father = father;edkEnd();
                                        father->right->right->counter--;edkEnd();
                                    }
                                    temp->right=NULL;edkEnd();
                                    temp->counter--;edkEnd();
                                }
                            }
                            else if(temp2->left){
                                BinaryLeaf<typeTemplate>*  newRoot = temp2;edkEnd();
                                temp2 = temp2->left;edkEnd();
                                if(temp2->right){
                                    //do nothing
                                }
                                else{
                                    //
                                    //rotate right
                                    temp2->right = newRoot;edkEnd();
                                    newRoot->father = temp2;edkEnd();
                                    newRoot->left = NULL;edkEnd();
                                    newRoot->counter--;edkEnd();
                                    //
                                    temp->right = temp2;edkEnd();
                                    temp2->father=temp;edkEnd();
                                    temp2->counter--;edkEnd();
                                    if(!continuing){
                                        continuing = true;edkEnd();
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
                            temp2 = temp->right;edkEnd();
                            if(temp2->right){
                                if(temp2->left){
                                    //do nothing
                                }
                                else{
                                    //have only the right2
                                    //rotate left
                                    (*this->rootPointer) = temp->right;edkEnd();
                                    (*this->rootPointer)->father = NULL;edkEnd();
                                    (*this->rootPointer)->counter--;edkEnd();
                                    //
                                    (*this->rootPointer)->left = temp;edkEnd();
                                    (*this->rootPointer)->left->father = (*this->rootPointer)->right->father = (*this->rootPointer);edkEnd();
                                    temp->right=NULL;edkEnd();
                                    temp->counter--;edkEnd();
                                    //
                                    (*this->rootPointer)->right->counter--;edkEnd();
                                }
                            }
                            else if(temp2->left){
                                BinaryLeaf<typeTemplate>*  newRoot = temp2;edkEnd();
                                temp2 = temp2->left;edkEnd();
                                if(temp2->right){
                                    //do nothing
                                }
                                else{
                                    //
                                    //rotate right
                                    temp2->right = newRoot;edkEnd();
                                    newRoot->father = temp2;edkEnd();
                                    newRoot->left = NULL;edkEnd();
                                    newRoot->counter--;edkEnd();
                                    //
                                    temp->right = temp2;edkEnd();
                                    temp2->father=temp;edkEnd();
                                    temp2->counter--;edkEnd();
                                    if(!continuing){
                                        continuing = true;edkEnd();
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
                            temp2 = temp->left;edkEnd();
                            if(temp2->left){
                                if(temp2->right){
                                    //do nothing
                                }
                                else{
                                    //have only the left2
                                    //rotate right
                                    father = temp->father;edkEnd();
                                    //right left
                                    if(father->right == temp){
                                        //
                                        father->right = temp->left;edkEnd();
                                        father->right->counter--;edkEnd();
                                        father->right->right = temp;edkEnd();
                                        father->right->right->father = father->right->left->father = father->right;edkEnd();
                                        father->right->father = father;edkEnd();
                                        father->right->left->counter--;edkEnd();
                                    }
                                    else if(father->left == temp){
                                        //
                                        father->left = temp->left;edkEnd();
                                        father->left->counter--;edkEnd();
                                        father->left->right = temp;edkEnd();
                                        father->left->right->father = father->left->left->father = father->left;edkEnd();
                                        father->left->father = father;edkEnd();
                                        father->left->left->counter--;edkEnd();
                                    }
                                    temp->left=NULL;edkEnd();
                                    temp->counter--;edkEnd();
                                }
                            }
                            else if(temp2->right){
                                BinaryLeaf<typeTemplate>*  newRoot = temp2;edkEnd();
                                temp2 = temp2->right;edkEnd();
                                if(temp2->left){
                                    //do nothing
                                }
                                else{
                                    //
                                    //rotate left
                                    temp2->left = newRoot;edkEnd();
                                    newRoot->father = temp2;edkEnd();
                                    newRoot->right = NULL;edkEnd();
                                    newRoot->counter--;edkEnd();
                                    //
                                    temp->left = temp2;edkEnd();
                                    temp2->father=temp;edkEnd();
                                    temp2->counter--;edkEnd();
                                    if(!continuing){
                                        continuing = true;edkEnd();
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
                            temp2 = temp->left;edkEnd();
                            if(temp2->left){
                                if(temp2->right){
                                    //do nothing
                                }
                                else{
                                    //have only the left2
                                    //rotate right
                                    (*this->rootPointer) = temp->left;edkEnd();
                                    (*this->rootPointer)->father = NULL;edkEnd();
                                    (*this->rootPointer)->counter--;edkEnd();
                                    //
                                    (*this->rootPointer)->right = temp;edkEnd();
                                    (*this->rootPointer)->right->father = (*this->rootPointer)->left->father = (*this->rootPointer);edkEnd();
                                    temp->left=NULL;edkEnd();
                                    temp->counter--;edkEnd();
                                    //
                                    (*this->rootPointer)->left->counter--;edkEnd();
                                }
                            }
                            else if(temp2->right){
                                BinaryLeaf<typeTemplate>*  newRoot = temp2;edkEnd();
                                temp2 = temp2->right;edkEnd();
                                if(temp2->left){
                                    //do nothing
                                }
                                else{
                                    //
                                    //rotate left
                                    temp2->left = newRoot;edkEnd();
                                    newRoot->father = temp2;edkEnd();
                                    newRoot->right = NULL;edkEnd();
                                    newRoot->counter--;edkEnd();
                                    //
                                    temp->left = temp2;edkEnd();
                                    temp2->father=temp;edkEnd();
                                    temp2->counter--;edkEnd();
                                    if(!continuing){
                                        continuing = true;edkEnd();
                                        continue;
                                    }
                                }
                            }
                        }
                    }
                }

                //then select the father
                temp = temp->father;edkEnd();
                continuing = false;edkEnd();
            }
        }
    }
};

//String TREE
class NameTree:public BinaryTree<edk::Name*>{
public:
    //Construtor
    NameTree(){
        //
        this->canDeleteNames=true;edkEnd();
    }
    //Destrutor
    ~NameTree(){
        if(this->canDeleteNames){
            this->deleteAllNames();edkEnd();
        }
        else{
            this->cantDestruct();edkEnd();
        }
        this->canDeleteNames=false;edkEnd();
    }
    //Functions in const
    //ADD
    bool addName(const edk::char8* value){
        return this->addName((edk::char8*) value);edkEnd();
    }
    bool addName(edk::char8* value){
        //
        if(value){
            edk::Name* temp = new edk::Name(value);edkEnd();
            if(temp){
                //
                if(edk::vector::BinaryTree<edk::Name*>::add(temp)){
                    //
                    return true;
                }
                //delete the temp
                delete temp;edkEnd();
            }
        }
        return false;
    }
    //REMOVE
    bool removeName(const edk::char8* value){
        //
        return this->removeName((edk::char8*) value);edkEnd();
    }
    bool removeName(edk::char8* value){
        //
        edk::Name find(value);edkEnd();
        return edk::vector::BinaryTree<edk::Name*>::remove(&find);
    }
    //REMOVE THE ELEMENT IN POSITION
    bool removeNameInPosition(edk::uint32 position){
        //get the element
        edk::Name* temp = this->getElementInPosition(position);edkEnd();
        if(temp){
            return edk::vector::BinaryTree<edk::Name*>::remove(temp);edkEnd();
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
        edk::Name find(value);edkEnd();
        edk::Name *temp =  edk::vector::BinaryTree<edk::Name*>::getElement(&find);edkEnd();
        if(edk::vector::BinaryTree<edk::Name*>::remove(temp)){
            delete temp;edkEnd();
            return true;
        }
        return false;
    }
    //DELETE THE ELEMENT IN POSITION
    bool deleteNameInPosition(edk::uint32 position){
        //get the element
        edk::Name* temp = this->getElementInPosition(position);edkEnd();
        if(temp){
            if(edk::vector::BinaryTree<edk::Name*>::remove(temp)){
                delete temp;edkEnd();
                return true;
            }
        }
        return false;
    }
    //DELETE ALL THE NAMES
    void deleteAllNames(){
        for(edk::uint32 i=0u;i<edk::vector::BinaryTree<edk::Name*>::size();i++){
            edk::Name* temp = this->getElementInPosition(i);edkEnd();
            if(temp){
                delete temp;edkEnd();
                temp=NULL;edkEnd();
            }
        }
        edk::vector::BinaryTree<edk::Name*>::clean();edkEnd();
    }
    //remove all names
    //HAVE ELEMENT
    bool haveName(const edk::char8* value){
        //
        return this->haveName((edk::char8*)value);
    }
    bool haveName(edk::char8* value){
        //
        edk::Name temp(value);edkEnd();
        return edk::vector::BinaryTree<edk::Name*>::haveElement(&temp);
    }
    //GET ELEMENT
    edk::Name* getElementByName(const edk::char8* value){
        //
        return getElementByName((edk::char8*) value);
    }
    edk::Name* getElementByName(edk::char8* value){
        //
        edk::Name temp(value);edkEnd();
        return edk::vector::BinaryTree<edk::Name*>::getElement(&temp);
    }
    //GET NAME IN POSITION
    edk::char8* getNameInPosition(edk::uint32 position){
        //get the position in the TREE
        edk::Name* temp = this->getElementInPosition(position);edkEnd();
        //if have the position
        if(temp){
            //return the name
            return temp->getName();
        }
        //else return NULL
        return NULL;
    }

    void cantDeleteNames(){
        this->canDeleteNames=false;edkEnd();
    }

protected:
    //Virtual Functions
    bool firstBiggerSecond(edk::Name* first,edk::Name* second){
        //test the values
        if(first && second){
            //then thes the strings
            //return this->firstNameBiggerSecond(first->getName(),second->getName());edkEnd();
            return first->nameBiggerThan(second->getName());edkEnd();
        }
        return false;
    }
    bool firstEqualSecond(edk::Name* first,edk::Name* second){
        //test the values
        if(first && second){
            //then thes the strings
            //return this->stringEqual(first->getName(),second->getName());edkEnd();
            return first->nameEqual(second->getName());edkEnd();
        }
        return false;
    }
    //Print
    void printElement(edk::char8* value){
        //
        edk::Name* temp = (edk::Name*)value;edkEnd();
        if(temp){
            //
            printf("\nString '%s'"
                   ,temp->getName()
                   );edkEnd();
        }
        else{
            //
            printf("\nString NULL");edkEnd();
        }
    }

private:
    bool canDeleteNames;
    //compare the names
    bool firstNameBiggerSecond(edk::char8* name1,edk::char8* name2){
        //test the strings
        if(name1 && name2){
            //test if name1 is bigger
            edk::uint32 i=0u;edkEnd();
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
                i++;edkEnd();
            }
        }
        //else return false
        return false;
    }
    bool stringEqual(edk::char8* name1,edk::char8* name2){
        //test the two strings
        if(name1 && name2){
            edk::uint32 i=0u;edkEnd();
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
};

//enum with the map to go into the value
enum edkLeafsMap{
    edkLeafNULL=0u,
    edkLeaftLEFT,
    edkLeaftRIGHT,
    //
    edkLeaftSize
};
//treeMAPPING
class TreeMap: public edk::vector::Queue<edk::vector::edkLeafsMap>{
public:
    TreeMap(){}
    ~TreeMap(){}
};

template <class typeTemplate>
class LeafsOnlyTree{
public:
    //errorCode
    edk::uint16 errorCode;
    //Construtor
    LeafsOnlyTree(){
        this->root=NULL;edkEnd();
        this->errorCode=0u;edkEnd();
        this->sizeTree=0u;edkEnd();
        this->dontDestruct = false;edkEnd();

        this->errorCodePointer = &this->errorCode;
        this->rootPointer = &this->root;
        this->sizeTreePointer = &this->sizeTree;
        this->mapPointer = &this->map;
        this->elementSelectedPointer = &this->elementSelected;
    }
    //Destrutor
    virtual ~LeafsOnlyTree(){
        if(!this->dontDestruct){
            this->clean();edkEnd();
            this->root=NULL;edkEnd();
            this->sizeTree=0u;edkEnd();
        }
        this->dontDestruct=false;edkEnd();
    }
    //Add a value on the tree
    bool add(typeTemplate value){
        //Test if is the root element
        if(!(*this->rootPointer)){
            //then add the root element
            (*this->rootPointer) = new BinaryLeaf<typeTemplate>;edkEnd();
            if((*this->rootPointer)){
                //set the value
                memcpy((void*)&(*this->rootPointer)->value,(void*)&value,sizeof(typeTemplate));edkEnd();
                //increment the sizeTree
                this->incrementSize();edkEnd();
                //then return true
                return true;
            }
        }
        else{
            //Find the position to add the object
            BinaryLeaf<typeTemplate>* temp=(*this->rootPointer);edkEnd();
            //create the value
            BinaryLeaf<typeTemplate>* newValue = new BinaryLeaf<typeTemplate>;edkEnd();
            BinaryLeaf<typeTemplate>* newSecondValue = new BinaryLeaf<typeTemplate>;edkEnd();
            //Test if create the newValue
            if(newValue && newSecondValue){
                memcpy((void*)&newValue->value,(void*)&value,sizeof(typeTemplate));edkEnd();
                //Find the position
                //test if the temp exist
                while(temp){
                    //then test if the value is equal
                    if(this->firstEqualSecond(temp->value, newValue->value)
                            &&(!(*this->rootPointer)->left && !(*this->rootPointer)->right)
                            ){
                        //The tree have the value. Delete the new value and return the tree value.
                        delete newValue;edkEnd();
                        newValue=NULL;edkEnd();
                        delete newSecondValue;edkEnd();
                        newSecondValue=NULL;edkEnd();
                        //
                        (*this->errorCodePointer)=EDK_ERROR_HAVE_VALUE;edkEnd();
                        return false;
                    }
                    else{
                        //else test if the first is bigger
                        if(this->firstBiggerSecond(newValue->value ,temp->value) ){
                            //then test if have a right
                            if(temp->right){
                                //temp receive the right
                                temp = temp->right;edkEnd();
                            }
                            else{
                                //else add the value in right
                                if(temp->left){
                                    BinaryLeaf<typeTemplate>* newThirdValue = new BinaryLeaf<typeTemplate>;edkEnd();
                                    if(newThirdValue){
                                        memcpy((void*)&newThirdValue->value,(void*)&temp->value,sizeof(typeTemplate));edkEnd();
                                        temp->right = newThirdValue;edkEnd();
                                        temp->right->father = temp;edkEnd();
                                        temp=temp->right;edkEnd();
                                    }
                                }
                                temp->right = newValue;edkEnd(); newValue=NULL;edkEnd();
                                temp->right->father = temp;edkEnd();
                                //set the secondValue
                                memcpy((void*)&newSecondValue->value,(void*)&temp->value,sizeof(typeTemplate));edkEnd();
                                temp->left = newSecondValue;edkEnd();
                                temp->left->father = temp;edkEnd();
                                //increment the sizeTree
                                this->incrementSize();edkEnd();
                                //return true
                                return true;
                            }
                        }
                        else{
                            //then test if have a left
                            if(temp->left){
                                //temp receive the left
                                temp=temp->left;edkEnd();
                            }
                            else{
                                //else add the value in left
                                if(temp->right){
                                    BinaryLeaf<typeTemplate>* newThirdValue = new BinaryLeaf<typeTemplate>;edkEnd();
                                    if(newThirdValue){
                                        memcpy((void*)&newThirdValue->value,(void*)&temp->value,sizeof(typeTemplate));edkEnd();
                                        temp->left = newThirdValue;edkEnd();
                                        temp->left->father = temp;edkEnd();
                                        temp=temp->left;edkEnd();
                                    }
                                }
                                temp->left = newValue;edkEnd(); newValue=NULL;edkEnd();
                                temp->left->father = temp;edkEnd();
                                //set the secondValue
                                memcpy((void*)&newSecondValue->value,(void*)&temp->value,sizeof(typeTemplate));edkEnd();
                                temp->right = newSecondValue;edkEnd();
                                temp->right->father = temp;edkEnd();
                                //increment the sizeTree
                                this->incrementSize();edkEnd();
                                //return true
                                return true;
                            }
                        }
                    }
                }
                delete newValue;edkEnd();
                delete newSecondValue;edkEnd();
            }
        }
        //else return false
        (*this->errorCodePointer)=EDK_ERROR_HAVE_VALUE;edkEnd();
        return false;
    }

    //Load the elements
    virtual void load(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->loadNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //Unload the elements
    virtual void unload(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->unloadNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //Print the elements
    virtual void print(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->printNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //render the elements
    virtual void render(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->renderNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //render the elements in wire mode
    virtual void renderWire(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->renderWireNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //draw the elements
    virtual void draw(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->drawNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //draw the elements in wire mode
    virtual void drawWire(){
        //test if have root
        if((*this->rootPointer)){
            //
            this->drawWireNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    virtual void update(){
        //test if have root
        if((*this->rootPointer)){
            //then update
            this->updateNoRecursively((*this->rootPointer));edkEnd();
        }
    }
    //print all the tree
    virtual void printTree(){
        //test if have root
        if((*this->rootPointer)){
            //then update
            this->printTreeNoRecursively((*this->rootPointer));edkEnd();
        }
    }

    //Get the rootValue
    typeTemplate getRootValue(){
        if(this->haveRoot()){
            return (typeTemplate)(*this->rootPointer)->value;edkEnd();
        }
        else{
            return (typeTemplate)0u;edkEnd();
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
            return ((*this->rootPointer)->left || (*this->rootPointer)->right);edkEnd();
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
    bool getElementMap(typeTemplate value,edk::vector::TreeMap *map){
        if(map){
            //find the value and generate the map
            return this->find(value,map);
        }
        return false;
    }

    //return the element
    typeTemplate getElement(typeTemplate value){
        //find the element pointer
        BinaryLeaf<typeTemplate>* ret = this->find(value);edkEnd();
        //test if the element is founded
        if(ret){
            //return the value
            return ret->value;edkEnd();
        }
        //else return zero
        typeTemplate retZero;edkEnd();
        memset((void*)&retZero,0u,sizeof(typeTemplate));edkEnd();
        return retZero;
    }

    //return the size
    edk::uint32 getSize(){
        return (*this->sizeTreePointer);edkEnd();
    }
    edk::uint32 size(){
        return this->getSize();edkEnd();
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
            (*this->sizeTreePointer)=0u;edkEnd();
            this->cleanNoRecursively((*this->rootPointer));edkEnd();
        }
        (*this->rootPointer)=NULL;edkEnd();
    }
    //set to cant Destruct
    void cantDestruct(){
        this->dontDestruct=true;edkEnd();
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
    BinaryLeaf<typeTemplate>** rootPointer;
    BinaryLeaf<typeTemplate>* root;
    //size of the tree
    edk::uint32* sizeTreePointer;
    edk::uint32 sizeTree;
    //set if cant run the destructor
    bool dontDestruct;

    //temporary map
    edk::vector::TreeMap* mapPointer;
    edk::vector::TreeMap map;

    BinaryLeaf<typeTemplate>** elementSelectedPointer;
    BinaryLeaf<typeTemplate>* elementSelected;

    //Find the element
    bool find(typeTemplate value,edk::vector::TreeMap *map=NULL){
        if(!map){
            map=&this->map;edkEnd();
        }
        //first test if have a root
        if((*this->rootPointer)){
            //then create a temporary element
            BinaryLeaf<typeTemplate> element;edkEnd();
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));edkEnd();
            //tets if is equal root
            if(this->firstEqualSecond((*this->rootPointer)->value,element.value)
                    && (!(*this->rootPointer)->left && !(*this->rootPointer)->right)
                    ){
                //the return root
                return false;edkEnd();
            }
            //else search the element
            BinaryLeaf<typeTemplate>* temp = (*this->rootPointer);edkEnd();
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
                                    temp = temp->left;edkEnd();
                                    map->pushBack(edk::vector::edkLeaftLEFT);edkEnd();
                                    edkEnd();
                                    continue;
                                }
                            }
                            else{
                                dontHave++;
                            }
                            if(temp->right){
                                if(this->firstEqualSecond(temp->right->value,element.value)){
                                    temp = temp->right;edkEnd();
                                    map->pushBack(edk::vector::edkLeaftRIGHT);edkEnd();
                                    edkEnd();
                                    continue;
                                }
                            }
                            else{
                                dontHave++;
                            }
                            edkEnd();
                            break;
                        }
                    }
                    if(dontHave>1u){
                        edkEnd();
                        return true;
                    }
                    edkEnd();
                    return false;
                }
                //tets if the value is bigger the temp
                else if(this->firstBiggerSecond(element.value,temp->value)){
                    //then the next maybe is the RIGHT
                    if(temp->right){
                        map->pushBack(edk::vector::edkLeaftRIGHT);edkEnd();
                        //Go RIGHT
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->right->value,element.value)){
                            edk::uchar8 dontHave=2u;
                            temp = temp->right;edkEnd();
                            if(temp->left || temp->right){
                                //find it. Then calculate the map
                                while(true){
                                    dontHave=0u;
                                    if(temp->left){
                                        if(this->firstEqualSecond(temp->left->value,element.value)){
                                            temp = temp->left;edkEnd();
                                            map->pushBack(edk::vector::edkLeaftLEFT);edkEnd();
                                            edkEnd();
                                            continue;
                                        }
                                    }
                                    else{
                                        dontHave++;
                                    }
                                    if(temp->right){
                                        if(this->firstEqualSecond(temp->right->value,element.value)){
                                            temp = temp->right;edkEnd();
                                            map->pushBack(edk::vector::edkLeaftRIGHT);edkEnd();
                                            edkEnd();
                                            continue;
                                        }
                                    }
                                    else{
                                        dontHave++;
                                    }
                                    edkEnd();
                                    break;
                                }
                            }
                            if(dontHave>1u){
                                edkEnd();
                                return true;
                            }
                            edkEnd();
                            return false;
                        }
                        else{
                            //else the temp'receive the right
                            temp=temp->right;edkEnd();
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
                        map->pushBack(edk::vector::edkLeaftLEFT);edkEnd();
                        //test if the value is equal
                        if(this->firstEqualSecond(temp->left->value,element.value)){
                            edk::uchar8 dontHave=2u;
                            temp = temp->left;edkEnd();
                            if(temp->left || temp->right){
                                //find it. Then calculate the map
                                while(true){
                                    dontHave=0u;
                                    if(temp->left){
                                        if(this->firstEqualSecond(temp->left->value,element.value)){
                                            temp = temp->left;edkEnd();
                                            map->pushBack(edk::vector::edkLeaftLEFT);edkEnd();
                                            edkEnd();
                                            continue;
                                        }
                                    }
                                    else{
                                        dontHave++;
                                    }
                                    if(temp->right){
                                        if(this->firstEqualSecond(temp->right->value,element.value)){
                                            temp = temp->right;edkEnd();
                                            map->pushBack(edk::vector::edkLeaftRIGHT);edkEnd();
                                            edkEnd();
                                            continue;
                                        }
                                    }
                                    else{
                                        dontHave++;
                                    }
                                    edkEnd();
                                    break;
                                }
                            }
                            if(dontHave>1u){
                                edkEnd();
                                return true;
                            }
                            edkEnd();
                            return false;
                        }
                        else{
                            //else the temp receive the left
                            temp=temp->left;edkEnd();
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
        (*this->sizeTreePointer)+=1u;edkEnd();
    }
    bool decrementSize(){
        //
        if((*this->sizeTreePointer)){
            //
            (*this->sizeTreePointer)-=1u;edkEnd();

            //return true
            return true;
        }
        //else return false
        return false;
    }

    //recursively to load
    void loadRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->loadRecursively(temp->left);edkEnd();
            }
            //update
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->loadElement(temp->value);edkEnd();
            }
            if(temp->right){
                this->loadRecursively(temp->right);edkEnd();
            }
        }
    }
    void loadNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //load
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->loadElement(temp->value);edkEnd();
                }
                //run the callback functions
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to unload
    void unloadRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->unloadRecursively(temp->left);edkEnd();
            }
            //update
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->unloadElement(temp->value);edkEnd();
            }
            if(temp->right){
                this->unloadRecursively(temp->right);edkEnd();
            }
        }
    }
    void unloadNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //unload
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->unloadElement(temp->value);edkEnd();
                }
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //update the values runing the update function
    void updateRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                this->updateRecursively(temp->left);edkEnd();
            }
            //update
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->updateElement(temp->value);edkEnd();
            }
            if(temp->right){
                this->updateRecursively(temp->right);edkEnd();
            }
        }
    }
    void updateNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //update
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->updateElement(temp->value);edkEnd();
                }
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to print
    void printRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->printRecursively(temp->left);edkEnd();
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->printElement(temp->value);edkEnd();
            }
            if(temp->right){
                //
                this->printRecursively(temp->right);edkEnd();
            }
        }
    }
    void printNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //print
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->printElement(temp->value);edkEnd();
                }
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to render
    void renderRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);edkEnd();
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->renderElement(temp->value);edkEnd();
            }
            if(temp->right){
                //
                this->renderRecursively(temp->right);edkEnd();
            }
        }
    }
    void renderNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->renderElement(temp->value);edkEnd();
                }
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to renderWire
    void renderWireRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);edkEnd();
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->renderElement(temp->value);edkEnd();
            }
            if(temp->right){
                //
                this->renderRecursively(temp->right);edkEnd();
            }
        }
    }
    void renderWireNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->renderWireElement(temp->value);edkEnd();
                }
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to draw
    void drawRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);edkEnd();
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->drawElement(temp->value);edkEnd();
            }
            if(temp->right){
                //
                this->renderRecursively(temp->right);edkEnd();
            }
        }
    }
    void drawNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->drawElement(temp->value);edkEnd();
                }
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //recursively to drawWire
    void drawWireRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                this->renderRecursively(temp->left);edkEnd();
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                this->drawWireElement(temp->value);edkEnd();
            }
            if(temp->right){
                //
                this->renderRecursively(temp->right);edkEnd();
            }
        }
    }
    void drawWireNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                    this->drawWireElement(temp->value);edkEnd();
                }
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
    }
    //printTree
    void printTreeRecursively(BinaryLeaf<typeTemplate>* temp){
        if(temp){
            //
            if(temp->left){
                //
                printf("\nGo->left");fflush(stdout);edkEnd();
                this->printElement(temp->value);edkEnd();
                this->renderRecursively(temp->left);edkEnd();
            }
            //print
            if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                printf("\nPrint");fflush(stdout);edkEnd();
                this->printElement(temp->value);edkEnd();
            }
            if(temp->right){
                //
                printf("\nGo->right");fflush(stdout);edkEnd();
                this->printElement(temp->value);edkEnd();
                this->renderRecursively(temp->right);edkEnd();
            }
        }
    }
    void printTreeNoRecursively(BinaryLeaf<typeTemplate>* temp){
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    printf("\nGo->left");fflush(stdout);edkEnd();
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                //render
                printf("\nPRINT");fflush(stdout);edkEnd();
                this->printElement(temp->value);edkEnd();
                temp->readed=2u;edkEnd();
                if(temp->right){
                    printf("\nGo->right");fflush(stdout);edkEnd();
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
                printf("\nGo->father");fflush(stdout);edkEnd();
            }
        }
    }
    //set if find it
    BinaryLeaf<typeTemplate>* getRecursively(BinaryLeaf<typeTemplate>* temp,edk::uint32* count, edk::uint32 pos){
        //the return
        BinaryLeaf<typeTemplate>* ret=NULL;edkEnd();
        if(temp){
            if(temp->left){
                //
                ret=this->getRecursively(temp->left,count,pos);edkEnd();
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
                return temp;edkEnd();
            }
            else if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                //increment count
                count[0]++;edkEnd();
            }
            //print
            if(temp->right){
                //
                ret=this->getRecursively(temp->right,count,pos);edkEnd();
                //test if find
                if(ret){
                    return ret;
                }
            }
        }
        //return the ret
        return ret;
    }
    BinaryLeaf<typeTemplate>* getNoRecursively(BinaryLeaf<typeTemplate>* temp,edk::uint32 pos){
        edk::uint32 count = 0u;edkEnd();
        BinaryLeaf<typeTemplate>* ret = NULL;edkEnd();
        bool find=false;edkEnd();
        //test if have temp
        while(temp){
            if(!find){
                if(temp->readed==0u){
                    temp->readed=1u;edkEnd();
                    if(temp->left){
                        temp = temp->left;edkEnd();
                        continue;
                    }
                }
                if(temp->readed==1u){
                    //test if count is == position
                    if(count==pos
                            && (!(*this->rootPointer)->left && !(*this->rootPointer)->right)
                            ){
                        //then return the typeTemplate
                        ret = temp;edkEnd();
                        find=true;edkEnd();
                    }
                    else if(!(*this->rootPointer)->left && !(*this->rootPointer)->right){
                        //increment count
                        ++count;edkEnd();
                    }
                    temp->readed=2u;edkEnd();
                    if(temp->right){
                        temp = temp->right;edkEnd();
                        continue;
                    }
                }
                if(temp->readed==2u){
                    temp->readed=0u;edkEnd();
                    temp = temp->father;edkEnd();
                }
            }
            else{
                temp->readed=0u;edkEnd();
                temp = temp->father;edkEnd();
            }
        }
        return ret;
    }
    //clean recursively
    void cleanRecursively(BinaryLeaf<typeTemplate>* temp){
        //
        if(temp){
            //
            if(temp->right){
                this->cleanRecursively(temp->right);edkEnd();
            }
            temp->right=NULL;edkEnd();
            if(temp->left){
                this->cleanRecursively(temp->left);edkEnd();
            }
            temp->left=NULL;edkEnd();
            delete temp;edkEnd();
        }
    }
    void cleanNoRecursively(BinaryLeaf<typeTemplate>* temp){
        BinaryLeaf<typeTemplate>* tempDelete;edkEnd();
        //test if have temp
        while(temp){
            if(temp->readed==0u){
                temp->readed=1u;edkEnd();
                if(temp->left){
                    temp = temp->left;edkEnd();
                    continue;
                }
            }
            if(temp->readed==1u){
                temp->left=NULL;edkEnd();
                temp->readed=2u;edkEnd();
                if(temp->right){
                    temp = temp->right;edkEnd();
                    continue;
                }
            }
            if(temp->readed==2u){
                temp->right=NULL;edkEnd();
                temp->readed=0u;edkEnd();
                tempDelete = temp;edkEnd();
                temp = temp->father;edkEnd();
                delete tempDelete;edkEnd();
            }
        }
    }
};
}
}
#endif // BinaryTree_H
