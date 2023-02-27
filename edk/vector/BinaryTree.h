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
#warning "Inside BinaryTree"
#endif

#pragma once
#include <stdio.h>
#include <string.h>
#include "../TypeVars.h"
#include "../NameClass.h"
#include "../String.h"
#include "./Array.h"

#ifdef printMessages
#warning "    Compiling BinaryTree"
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
        edk::vector::BinaryTree<obj*>::render();edkEnd();
    }
    //draw the elements
    virtual void draw(){
        edk::vector::BinaryTree<obj*>::render();edkEnd();
    }
    virtual void drawWire(){
        edk::vector::BinaryTree<obj*>::render();edkEnd();
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
        memset(&this->value,0u,sizeof(typeTemplate));edkEnd();
    }
    //Destrutor
    ~UnaryLeaf(){
        //
        this->next=NULL;edkEnd();
        this->father=NULL;edkEnd();
        memset(&this->value,0u,sizeof(typeTemplate));edkEnd();
    }
    //LEFT
    UnaryLeaf* next;
    //add the father
    UnaryLeaf* father;

    //Value of the leaf
    typeTemplate value;
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
        this->left=NULL;edkEnd();
        this->right=NULL;edkEnd();
        this->father=NULL;edkEnd();
        this->counter=0;edkEnd();
        this->readed=0u;edkEnd();
        memset((void*)&this->value,0u,sizeof(typeTemplate));edkEnd();
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
};
template <class typeTemplate>
class BinaryTree{
public:
    //errorCode
    edk::uint16 errorCode;
    //Construtor
    BinaryTree(){
        //
        this->root=NULL;edkEnd();
        this->errorCode=0u;edkEnd();
        this->sizeTree=0u;edkEnd();
        this->dontDestruct = false;edkEnd();
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
        if(!this->root){
            //then add the root element
            this->root = new BinaryLeaf<typeTemplate>;edkEnd();
            if(this->root){
                //set the value
                memcpy((void*)&this->root->value,(void*)&value,sizeof(typeTemplate));edkEnd();
                //increment the sizeTree
                this->incrementSize();edkEnd();
                //then return true
                return true;
            }
        }
        else{
            //Find the position to add the object
            BinaryLeaf<typeTemplate>* temp=this->root;edkEnd();
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
                        this->errorCode=EDK_ERROR_HAVE_VALUE;edkEnd();
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
                                this->balance(temp->right);edkEnd();
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
                                this->balance(temp->left);edkEnd();
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
        this->errorCode=EDK_ERROR_HAVE_VALUE;edkEnd();
        return false;
    }

    //Load the elements
    virtual void load(){
        //test if have root
        if(this->root){
            //
            this->loadNoRecursively(this->root);edkEnd();
        }
    }
    //Unload the elements
    virtual void unload(){
        //test if have root
        if(this->root){
            //
            this->unloadNoRecursively(this->root);edkEnd();
        }
    }
    //Print the elements
    virtual void print(){
        //test if have root
        if(this->root){
            //
            this->printNoRecursively(this->root);edkEnd();
        }
    }
    //render the elements
    virtual void render(){
        //test if have root
        if(this->root){
            //
            this->renderNoRecursively(this->root);edkEnd();
        }
    }
    //render the elements in wire mode
    virtual void renderWire(){
        //test if have root
        if(this->root){
            //
            this->renderWireNoRecursively(this->root);edkEnd();
        }
    }
    //draw the elements
    virtual void draw(){
        //test if have root
        if(this->root){
            //
            this->drawNoRecursively(this->root);edkEnd();
        }
    }
    //draw the elements in wire mode
    virtual void drawWire(){
        //test if have root
        if(this->root){
            //
            this->drawWireNoRecursively(this->root);edkEnd();
        }
    }
    virtual void update(){
        //test if have root
        if(this->root){
            //then update
            this->updateNoRecursively(this->root);edkEnd();
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




            if(mother==this->root){
                //
                BinaryLeaf<typeTemplate>* leaf = NULL;edkEnd();
                //test if have a left or right
                if(this->root->right){
                    //then get the left leaf
                    //save the element
                    BinaryLeaf<typeTemplate>* temp = this->root;edkEnd();
                    if((leaf = this->findMotherLeftLeaf(this->root->right))){
                        //then pull the leaf to the this->root
                        this->root = leaf->left;edkEnd();
                        if(this->root){
                            this->root->father=NULL;edkEnd();
                        }
                        //arrage the leaf
                        leaf->left = leaf->left->right;edkEnd();
                        if(leaf->left){
                            leaf->left->father = leaf;edkEnd();
                        }
                        //then the new this->root receive the two temps.
                        this->root->left = temp->left;edkEnd();
                        if(this->root->left){
                            this->root->left->father = this->root;edkEnd();
                        }
                        this->root->right = temp->right;edkEnd();
                        if(this->root->right){
                            this->root->right->father = this->root;edkEnd();
                        }
                    }
                    else{
                        //else just get the right
                        //pull the right
                        this->root=this->root->right;edkEnd();
                        if(this->root){
                            this->root->father=NULL;edkEnd();
                        }
                        this->root->left = temp->left;edkEnd();
                        if(this->root->left){
                            this->root->left->father = this->root;edkEnd();
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
                if(this->root->left){
                    //then get the right leaf
                    //save the element
                    BinaryLeaf<typeTemplate>* temp = this->root;edkEnd();
                    if((leaf = this->findMotherRightLeaf(this->root->left))){
                        //then pull the leaf to the this->root
                        this->root = leaf->right;edkEnd();
                        if(this->root){
                            this->root->father=NULL;edkEnd();
                        }
                        //arrage the leaf
                        leaf->right = leaf->right->left;edkEnd();
                        if(leaf->right){
                            leaf->right->father = leaf;edkEnd();
                        }
                        //then the new this->root receive the two temps.
                        this->root->left = temp->left;edkEnd();
                        if(this->root->left){
                            this->root->left->father = this->root;edkEnd();
                        }
                        this->root->right = temp->right;edkEnd();
                        if(this->root->right){
                            this->root->right->father = this->root;edkEnd();
                        }
                    }
                    else{
                        //else just get the right
                        //pull the right
                        this->root=this->root->left;edkEnd();
                        if(this->root){
                            this->root->father = NULL;edkEnd();
                        }
                        this->root->right = temp->right;edkEnd();
                        if(this->root->right){
                            this->root->right->father = this->root;edkEnd();
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
                delete this->root;edkEnd();
                this->root=NULL;edkEnd();
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
            return (typeTemplate)this->root->value;edkEnd();
        }
        else{
            //
            return (typeTemplate)0u;edkEnd();
        }
    }
    //Return true if have a root
    bool haveRoot(){
        //
        if(this->root){
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
            return (this->root->left || this->root->right);edkEnd();
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
    //return the element in the Position
    typeTemplate getElementInPosition(edk::uint32 position){
        //first test if the position exist in the tree
        if(position < this->size()){
            //then find the element pointer
            //create a count
            //edk::uint32 count = 0u;edkEnd();
            BinaryLeaf<typeTemplate>* ret = this->getNoRecursively(this->root/*,&count*/,position);edkEnd();
            //test if the element is founded
            if(ret){
                //return the value
                return ret->value;edkEnd();
            }
        }
        typeTemplate ret;edkEnd(); memset((void*)&ret,0u,sizeof(typeTemplate));edkEnd();
        //else return zero
        return ret;
    }

    //return the size
    edk::uint32 getSize(){
        //
        return this->sizeTree;edkEnd();
    }
    edk::uint32 size(){
        //
        return this->getSize();edkEnd();
    }

    //Clean the tree
    virtual void clean(){
        if(this->root){
            //
            this->sizeTree=0u;edkEnd();
            this->cleanNoRecursively(this->root);edkEnd();
        }
        this->root=NULL;edkEnd();
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
    //The root element on the TREE
    BinaryLeaf<typeTemplate>* root;
    //size of the tree
    edk::uint32 sizeTree;
    //set if cant run the destructor
    bool dontDestruct;

    //Find the element
    BinaryLeaf<typeTemplate>* find(typeTemplate value){
        //test if habe a root
        if(this->root){
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
        if(this->root){
            //then create a temporary element
            BinaryLeaf<typeTemplate> element;edkEnd();
            memcpy((void*)&element.value,(void*)&value,sizeof(typeTemplate));edkEnd();
            //element.value=value;edkEnd();
            //tets if is equal root
            if(this->firstEqualSecond(this->root->value,element.value)){
                //the return root
                return this->root;edkEnd();
            }
            //else search the element mother
            BinaryLeaf<typeTemplate>* temp = this->root;edkEnd();
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
        this->sizeTree+=1u;edkEnd();
    }
    bool decrementSize(){
        //
        if(this->sizeTree){
            //
            this->sizeTree-=1u;edkEnd();

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
                    else if(temp == this->root){
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
                                    this->root = temp->right;edkEnd();
                                    this->root->father = NULL;edkEnd();
                                    this->root->counter--;edkEnd();
                                    //
                                    this->root->left = temp;edkEnd();
                                    this->root->left->father = this->root->right->father = this->root;edkEnd();
                                    temp->right=NULL;edkEnd();
                                    temp->counter--;edkEnd();
                                    //
                                    this->root->right->counter--;edkEnd();
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
                    else if(temp == this->root){
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
                                    this->root = temp->left;edkEnd();
                                    this->root->father = NULL;edkEnd();
                                    this->root->counter--;edkEnd();
                                    //
                                    this->root->right = temp;edkEnd();
                                    this->root->right->father = this->root->left->father = this->root;edkEnd();
                                    temp->left=NULL;edkEnd();
                                    temp->counter--;edkEnd();
                                    //
                                    this->root->left->counter--;edkEnd();
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
}
}

#endif // BinaryTree_H
