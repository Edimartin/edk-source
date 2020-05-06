#ifndef EDK_VECTOR_BINARYTREE_H
#define EDK_VECTOR_BINARYTREE_H

/*
Library binaryTree - Create a binaryTree in EDK Game Engine
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
#warning "Inside BinaryTree"
#endif

#pragma once
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
class treeInt:public edk::vector::BinaryTree<obj*>{
public:
    treeInt(){}
    virtual ~treeInt(){}
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
    //UPDATE
    virtual void updateElement(obj* value){
        //update the value
        value++;
    }
};

*/


//namespaces
namespace edk{
namespace vector{
template <class typeTemplate>
class UnaryLeaf{
    //Construtor
public:
    UnaryLeaf(){
        //
        next=NULL;
        value=0u;
    }
    //Destrutor
    ~UnaryLeaf(){
        //
        next=NULL;
        value=0u;
    }
    //LEFT
    UnaryLeaf* next;

    //Value of the leaf
    typeTemplate value;
};
template <class typeTemplate>
class BinaryLeaf{
    //Construtor
public:
    BinaryLeaf(){
        //
        left=NULL;
        right=NULL;
        value=(typeTemplate)0u;
    }
    //Destrutor
    ~BinaryLeaf(){
        //
        left=NULL;
        right=NULL;
        value=(typeTemplate)0u;
    }
    //RIGHT
    BinaryLeaf* left;
    BinaryLeaf* right;

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
        this->root=NULL;
        this->errorCode=0u;
        this->sizeTree=0u;
        this->dontDestruct = false;
    }
    //Destrutor
    virtual ~BinaryTree(){
        //
        if(!this->dontDestruct){
            this->clean();
            this->root=NULL;
            this->sizeTree=0u;
        }
        this->dontDestruct=false;
    }
    //Add a value on the tree
    bool add(typeTemplate value){
        //Test if is the root element
        if(!this->root){
            //then add the root element
            this->root = new BinaryLeaf<typeTemplate>;
            if(this->root){
                //set the value
                this->root->value = value;
                //increment the sizeTree
                this->incrementSize();
                //then return true
                return true;
            }
        }
        else{
            //Find the position to add the object
            BinaryLeaf<typeTemplate>* temp=this->root;
            //create the value
            BinaryLeaf<typeTemplate>* newValue = new BinaryLeaf<typeTemplate>;
            //Test if create the newValue
            if(newValue){
                newValue->value=value;
                //Find the position
                //test if the temp exist
                while(temp){
                    //then test if the value is equal
                    if(this->firstEqualSecond(temp->value, newValue->value)){
                        //The tree have the value. Delete the new value and return the tree value.
                        delete newValue;
                        newValue=NULL;
                        //
                        this->errorCode=EDK_ERROR_HAVE_VALUE;
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
                                temp->right = newValue; newValue=NULL;
                                //increment the sizeTree
                                this->incrementSize();
                                //return the right
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
                                temp->left = newValue; newValue=NULL;
                                //increment the sizeTree
                                this->incrementSize();
                                //return tempLeft
                                return true;
                            }
                        }
                    }
                }
                delete newValue;
            }
        }
        //else return false
        this->errorCode=EDK_ERROR_HAVE_VALUE;
        return false;
    }

    //Print the elements
    void print(){
        //test if have root
        if(this->root){
            //
            this->printRecursively(this->root);
        }
    }
    //render the elements
    void render(){
        //test if have root
        if(this->root){
            //
            this->renderRecursively(this->root);
        }
    }
    void update(){
        //test if have root
        if(this->root){
            //then update recursively
            this->updateRecursively(this->root);
        }
    }

    //Remove the element
    bool remove(typeTemplate value){
        //first find the element mother
        BinaryLeaf<typeTemplate>* mother = this->findMother(value);
        BinaryLeaf<typeTemplate> element;
        element.value=value;
        if(mother){
            //if find the mother search who is the element
            if(mother->left){
                //test if it's left
                if(this->firstEqualSecond(mother->left->value,element.value)){
                    BinaryLeaf<typeTemplate>* leaf = NULL;
                    //test if the element (mother->left) have childrens
                    if(mother->left->right){
                        //then get the left leaf
                        //save the element
                        BinaryLeaf<typeTemplate>* temp = mother->left;
                        if((leaf = this->findMotherLeftLeaf(mother->left->right))){
                            //then pull the leaf to the mother->left
                            mother->left = leaf->left;
                            //arrage the leaf
                            leaf->left = leaf->left->right;
                            //then the new mother->left receive the two temps.
                            mother->left->left = temp->left;
                            mother->left->right = temp->right;
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->left=mother->left->right;
                            mother->left->left = temp->left;
                        }
                        //delete the element
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
                        BinaryLeaf<typeTemplate>* temp = mother->left;
                        if((leaf = this->findMotherRightLeaf(mother->left->left))){
                            //then pull the leaf to the mother->left
                            mother->left = leaf->right;
                            //arrage the leaf
                            leaf->right = leaf->right->left;
                            //then the new mother->left receive the two temps.
                            mother->left->left = temp->left;
                            mother->left->right = temp->right;
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->left=mother->left->left;
                            mother->left->right = temp->right;
                        }
                        //delete the element
                        delete temp;
                        temp=NULL;
                        //decrement the sizeTree
                        this->decrementSize();
                        //return true
                        return true;
                    }
                    //He dont have childrens

                    //just delete;
                    //delete the element
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
                    BinaryLeaf<typeTemplate>* leaf = NULL;
                    //test if the element (mother->right) have childrens
                    if(mother->right->right){
                        //then get the left leaf
                        //save the element
                        BinaryLeaf<typeTemplate>* temp = mother->right;
                        if((leaf = this->findMotherLeftLeaf(mother->right->right))){
                            //then pull the leaf to the mother->right
                            mother->right = leaf->left;
                            //arrage the leaf
                            leaf->left = leaf->left->right;
                            //then the new mother->right receive the two temps.
                            mother->right->left = temp->left;
                            mother->right->right = temp->right;
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->right=mother->right->right;
                            mother->right->left = temp->left;
                        }
                        //delete the element
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
                        BinaryLeaf<typeTemplate>* temp = mother->right;
                        if((leaf = this->findMotherRightLeaf(mother->right->left))){
                            //then pull the leaf to the mother->right
                            mother->right = leaf->right;
                            //arrage the leaf
                            leaf->right = leaf->right->left;
                            //then the new mother->right receive the two temps.
                            mother->right->left = temp->left;
                            mother->right->right = temp->right;
                        }
                        else{
                            //else just get the right
                            //pull the right
                            mother->right=mother->right->left;
                            mother->right->right = temp->right;
                        }
                        //delete the element
                        delete temp;
                        temp=NULL;
                        //decrement the sizeTree
                        this->decrementSize();
                        //return true
                        return true;
                    }
                    //He dont have childrens

                    //just delete;
                    delete mother->right;
                    mother->right=NULL;
                    //decrement the sizeTree
                    this->decrementSize();
                    return true;
                }
            }




            if(mother==this->root){
                //
                BinaryLeaf<typeTemplate>* leaf = NULL;
                //test if have a left or right
                if(this->root->right){
                    //then get the left leaf
                    //save the element
                    BinaryLeaf<typeTemplate>* temp = this->root;
                    if((leaf = this->findMotherLeftLeaf(this->root->right))){
                        //then pull the leaf to the this->root
                        this->root = leaf->left;
                        //arrage the leaf
                        leaf->left = leaf->left->right;
                        //then the new this->root receive the two temps.
                        this->root->left = temp->left;
                        this->root->right = temp->right;
                    }
                    else{
                        //else just get the right
                        //pull the right
                        this->root=this->root->right;
                        this->root->left = temp->left;
                    }
                    //delete the element
                    delete temp;
                    temp=NULL;
                    //decrement the sizeTree
                    this->decrementSize();
                    //return true
                    return true;
                }
                if(this->root->left){
                    //then get the right leaf
                    //save the element
                    BinaryLeaf<typeTemplate>* temp = this->root;
                    if((leaf = this->findMotherRightLeaf(this->root->left))){
                        //then pull the leaf to the this->root
                        this->root = leaf->right;
                        //arrage the leaf
                        leaf->right = leaf->right->left;
                        //then the new this->root receive the two temps.
                        this->root->left = temp->left;
                        this->root->right = temp->right;
                    }
                    else{
                        //else just get the right
                        //pull the right
                        this->root=this->root->left;
                        this->root->right = temp->right;
                    }
                    //delete the element
                    delete temp;
                    temp=NULL;
                    //decrement the sizeTree
                    this->decrementSize();
                    //return true
                    return true;
                }

                //remove the root
                delete this->root;
                this->root=NULL;
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
            return (typeTemplate)this->root->value;
        }
        else{
            //
            return (typeTemplate)0u;
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
            return (this->root->left || this->root->right);
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
        BinaryLeaf<typeTemplate>* ret = this->find(value);
        //test if the element is founded
        if(ret){
            //return the value
            return ret->value;
        }
        //else return zero
        return (typeTemplate)0u;
    }
    //return the element in the Position
    typeTemplate getElementInPosition(edk::uint32 position){
        //first test if the position exist in the tree
        if(position < this->size()){
            //then find the element pointer
            //create a count
            edk::uint32 count = 0u;
            BinaryLeaf<typeTemplate>* ret = this->getRecursively(this->root,&count,position);
            //test if the element is founded
            if(ret){
                //return the value
                return ret->value;
            }
        }
        //else return zero
        return (typeTemplate)0u;
    }

    //return the size
    edk::uint32 getSize(){
        //
        return this->sizeTree;
    }
    edk::uint32 size(){
        //
        return this->getSize();
    }

    //Clean the tree
    virtual void clean(){
        if(this->root){
            //
            this->sizeTree=0u;
            this->cleanRecursively(this->root);
        }
        this->root=NULL;
    }
    //set to cant Destruct
    void cantDestruct(){
        //
        this->dontDestruct=true;
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
    //Print
    virtual void printElement(typeTemplate){}
    //created for draw the object
    virtual void renderElement(typeTemplate){}
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
            BinaryLeaf<typeTemplate> element;
            element.value=value;
            //find the mother
            BinaryLeaf<typeTemplate>* temp = this->findMother(value);
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
    //Find the elementMother
    BinaryLeaf<typeTemplate>* findMother(typeTemplate value){
        //first test if have a root
        if(this->root){
            //then create a temporary element
            BinaryLeaf<typeTemplate> element;
            element.value=value;
            //tets if is equal root
            if(this->firstEqualSecond(this->root->value,element.value)){
                //the return root
                return this->root;
            }
            //else search the element mother
            BinaryLeaf<typeTemplate>* temp = this->root;
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
    //Find the Last left
    BinaryLeaf<typeTemplate>* findMotherLeftLeaf(BinaryLeaf<typeTemplate>* root){
        //test if the root is alloc
        if(root){
            BinaryLeaf<typeTemplate>* mother = NULL;
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
    BinaryLeaf<typeTemplate>* findMotherRightLeaf(BinaryLeaf<typeTemplate>* root){
        //test if the root is alloc
        if(root){
            BinaryLeaf<typeTemplate>* mother = NULL;
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
        this->sizeTree+=1u;
    }
    bool decrementSize(){
        //
        if(this->sizeTree){
            //
            this->sizeTree-=1u;

            //return true
            return true;
        }
        //else return false
        return false;
    }

    //update the values runing the update function
    void updateRecursively(BinaryLeaf<typeTemplate>* temp){
        //test if have temp
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
    //recursively to print
    void printRecursively(BinaryLeaf<typeTemplate>* temp){
        //
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
    //recursively to print
    void renderRecursively(BinaryLeaf<typeTemplate>* temp){
        //
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
    //set if find it
    BinaryLeaf<typeTemplate>*  getRecursively(BinaryLeaf<typeTemplate>* temp,edk::uint32* count, edk::uint32 pos){
        //the return
        BinaryLeaf<typeTemplate>* ret=NULL;
        if(temp){
            if(temp->left){
                //
                ret=this->getRecursively(temp->left,count,pos);
                //test if find
                if(ret) return ret;
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
                if(ret) return ret;
            }
        }
        //return the ret
        return ret;
    }
    //clean recursively
    void cleanRecursively(BinaryLeaf<typeTemplate>* temp){
        //
        if(temp){
            //
            if(temp->right){
                //
                this->cleanRecursively(temp->right);
            }
            temp->right=NULL;
            if(temp->left){
                //
                this->cleanRecursively(temp->left);
            }
            temp->left=NULL;
            delete temp;
            //temp=NULL;
        }
    }
};

/*
//Class with name to save in the nameTree
class Name{
public:
    Name(){
        //
        this->_name=NULL;
        this->canDelete=true;
    }
    Name(edk::char8* _name){
        //
        this->_name=NULL;
        this->setName(_name);
        this->canDelete=true;
    }
    Name(const edk::char8* _name){
        //
        this->_name=NULL;
        this->setName(_name);
        this->canDelete=true;
    }
    virtual ~Name(){
        //
        if(this->canDelete){
            this->deleteName();
        }
        else{
            this->canDelete=true;
        }
    }
    //clean the name
    void cleanName(){
        this->setName((edk::char8*)NULL);
    }
    bool setName(const edk::char8* _name){
        return this->setName((edk::char8*) _name);
    }
    //set the name
    bool setName(edk::char8* _name){
        //delete the lastName
        this->deleteName();
        //test the new name
        if(_name){
            //copy the name
            this->_name = edk::String::strCopy(_name);
            if(this->_name) return true;
        }
        //else return false
        return false;
    }
    //get the name
    edk::char8* getName(){
        //
        return this->_name;
    }
    edk::char8* name(){
        //
        return this->_name;
    }
    bool nameEqual(edk::char8* _name){
        return edk::vector::Name::stringEqual(this->_name,_name);
    }
    bool nameEqual(const edk::char8* _name){
        return this->nameEqual((edk::char8*) _name);
    }
    bool nameBiggerThan(edk::char8* _name){
        return edk::vector::Name::firstNameBiggerSecond(this->_name,_name);
    }
    bool nameBiggerThan(const edk::char8* _name){
        return nameBiggerThan((edk::char8*) _name);
    }

    //compare the names
    static bool firstNameBiggerSecond(edk::char8* name1,edk::char8* name2){
        //test the strings
        if(name1 && name2){
            //test if name1 is bigger
            while(*name1!='\0' || *name2!='\0'){
                //test if the first is bigger then second
                if(*name1>*name2){
                    //the return true
                    return true;
                }
                else if(*name2>*name1){
                    //
                    break;
                }
                //else equal increment i
                name2++;
                name1++;
            }
        }
        //else return false
        return false;
    }
    static bool stringEqual(edk::char8* name1,edk::char8* name2){
        //test the two strings
        if(name1 && name2){
            //compare the two strings
            while(*name1!='\0' || *name2!='\0'){
                //test if the first is bigger then second
                if(*name1!=*name2){
                    //the return true
                    return false;
                }
                //else equal increment i
                name1++;
                name2++;
            }
            //test if are equal
            if(*name1==*name2){
                //return true
                return true;
            }
        }
        //else return false
        return false;
    }
    virtual void cantDelete(){
        this->canDelete=false;
    }
protected:
    //delete the name
    void deleteName(){
        //
        if(this->_name){
            delete[] this->_name;
            this->_name=NULL;
        }
    }

private:
    //have just one string with one name
    edk::char8* _name;
    bool canDelete;
};
*/

//String TREE
class NameTree:public BinaryTree<edk::Name*>{
public:
    //Construtor
    NameTree(){
        //
        this->canDeleteNames=true;
    }
    //Destrutor
    ~NameTree(){
        if(this->canDeleteNames){
            this->deleteAllNames();
        }
        else{
            this->cantDestruct();
        }
        this->canDeleteNames=false;
    }
    //Functions in const
    //ADD
    bool addName(const edk::char8* value){
        return this->addName((edk::char8*) value);
    }
    bool addName(edk::char8* value){
        //
        edk::Name* temp = new edk::Name(value);
        if(temp){
            //
            if(edk::vector::BinaryTree<edk::Name*>::add(temp)){
                //
                return true;
            }
            //delete the temp
            delete temp;
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
        return edk::vector::BinaryTree<edk::Name*>::remove(&find);
    }
    //REMOVE THE ELEMENT IN POSITION
    bool removeNameInPosition(edk::uint32 position){
        //get the element
        edk::Name* temp = this->getElementInPosition(position);
        if(temp){
            return edk::vector::BinaryTree<edk::Name*>::remove(temp);
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
        edk::Name *temp =  edk::vector::BinaryTree<edk::Name*>::getElement(&find);
        if(edk::vector::BinaryTree<edk::Name*>::remove(temp)){
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
            if(edk::vector::BinaryTree<edk::Name*>::remove(temp)){
                delete temp;
                return true;
            }
        }
        return false;
    }
    //DELETE ALL THE NAMES
    void deleteAllNames(){
        for(edk::uint32 i=0u;i<edk::vector::BinaryTree<edk::Name*>::size();i++){
            edk::Name* temp = this->getElementInPosition(i);
            if(temp){
                delete temp;
                temp=NULL;
            }
        }
        edk::vector::BinaryTree<edk::Name*>::clean();
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
        return edk::vector::BinaryTree<edk::Name*>::haveElement(&temp);
    }
    //GET ELEMENT
    edk::Name* getElementByName(const edk::char8* value){
        //
        return getElementByName((edk::char8*) value);
    }
    edk::Name* getElementByName(edk::char8* value){
        //
        edk::Name temp(value);
        return edk::vector::BinaryTree<edk::Name*>::getElement(&temp);
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

    void cantDeleteNames(){
        this->canDeleteNames=false;
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
    bool canDeleteNames;
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
};
}
}

#endif // BinaryTree_H
