#ifndef QUADTREE_H
#define QUADTREE_H

/*
Library QuadTree - Create a quadTree in EDK Game Engine
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
#pragma message "Inside QuadTree"
#endif

#pragma once
#include <stdio.h>
#include <string.h>
#include "../TypeRect.h"
#include "../TypeColor.h"
#include "BinaryTree.h"
#include "Queue.h"

#if defined(EDK_QUADTREE_GU)
#include "../GU/GU.h"
#endif

#ifdef printMessages
#pragma message "    Compiling QuadTree"
#endif

#define edkQuadSelectedSize 4u

#define edkQuadMinimumSize 1.0f

/*
//code sample

//QuadTree

class QuadtreePoints32:public edk::vector::QuadTree32<edk::vec2f32>{
public:
    QuadtreePoints32(){}
    virtual ~QuadtreePoints32(){}

    virtual bool isElementInside(edk::vec2f32 element,edk::vec2f32 point1,edk::vec2f32 point2){
        if(element.x >= point1.x
                &&
                element.y >= point1.y
                &&
                element.x <= point2.x
                &&
                element.y <= point2.y
                ){
            return true;
        }
        return false;
    }
    //test if the element is just colliding
    virtual bool isElementColliding(edk::vec2f32 element,edk::vec2f32 point1,edk::vec2f32 point2){
        return isElementInside(element,point1,point2);
    }
    //returh the rectangle of the element
    virtual edk::rectf32 getElementRectangle(edk::vec2f32 element){
        return edk::rectf32(element.x,element.y,element.x+1,element.y+1);
    }
    //function to create a new tree
    virtual edk::vector::BinaryTree<edk::vec2f32>* newTree(){
        return new edk::vector::BinaryTree<edk::vec2f32>;
    }
    virtual void elementGetIn(edk::vec2f32 element){
        //elementGetIn
    }
    virtual void elementUpdating(edk::vec2f32 element){
        //elementUpdating
    }
    virtual void elementGetOut(edk::vec2f32 element){
        //elementGetOut
    }
};
class QuadtreeRectangles32:public edk::vector::QuadTree32<edk::rectf32>{
public:
    QuadtreeRectangles32(){}
    virtual ~QuadtreeRectangles32(){}

    virtual bool isElementInside(edk::rectf32 element,edk::vec2f32 point1,edk::vec2f32 point2){
        if(element.origin.x >= point1.x
                &&
                element.origin.y >= point1.y
                &&
                element.origin.x <= point2.x
                &&
                element.origin.y <= point2.y
                &&
                element.size.width >= point1.x
                &&
                element.size.height >= point1.y
                &&
                element.size.width <= point2.x
                &&
                element.size.height <= point2.y
                ){
            return true;
        }
        return false;
    }
    //test if the element is just colliding
    virtual bool isElementColliding(edk::rectf32 element,edk::vec2f32 point1,edk::vec2f32 point2){
        if(point1.x <= element.size.width
                &&
                point2.x>= element.origin.x
                &&
                point1.y <= element.size.height
                &&
                point2.y >= element.origin.y
                ){
            return true;
            }
        return false;
    }
    //returh the rectangle of the element
    virtual edk::rectf32 getElementRectangle(edk::rectf32 element){
        return edk::rectf32(element.origin.x,element.origin.y,element.size.width,element.size.height);
    }
    //function to create a new tree
    virtual edk::vector::BinaryTree<edk::rectf32>* newTree(){
        return new edk::vector::BinaryTree<edk::rectf32>;
    }
    virtual void elementGetIn(edk::rectf32 element){
        //elementGetIn
    }
    virtual void elementUpdating(edk::rectf32 element){
        //elementUpdating
    }
    virtual void elementGetOut(edk::rectf32 element){
        //elementGetOut
    }
};

class QuadtreePoints64:public edk::vector::QuadTree64<edk::vec2f64>{
public:
    QuadtreePoints64(){}
    virtual ~QuadtreePoints64(){}

    virtual bool isElementInside(edk::vec2f64 element,edk::vec2f64 point1,edk::vec2f64 point2){
        if(element.x >= point1.x
                &&
                element.y >= point1.y
                &&
                element.x <= point2.x
                &&
                element.y <= point2.y
                ){
            return true;
        }
        return false;
    }
    //test if the element is just colliding
    virtual bool isElementColliding(edk::vec2f64 element,edk::vec2f64 point1,edk::vec2f64 point2){
        return isElementInside(element,point1,point2);
    }
    //returh the rectangle of the element
    virtual edk::rectf64 getElementRectangle(edk::vec2f64 element){
        return edk::rectf64(element.x,element.y,element.x+1,element.y+1);
    }
    //function to create a new tree
    virtual edk::vector::BinaryTree<edk::vec2f64>* newTree(){
        return new edk::vector::BinaryTree<edk::vec2f64>;
    }
    virtual void elementGetIn(edk::vec2f64 element){
        //elementGetIn
    }
    virtual void elementUpdating(edk::vec2f64 element){
        //elementUpdating
    }
    virtual void elementGetOut(edk::vec2f64 element){
        //elementGetOut
    }
};
class QuadtreeRectangles64:public edk::vector::QuadTree64<edk::rectf64>{
public:
    QuadtreeRectangles64(){}
    virtual ~QuadtreeRectangles64(){}

    virtual bool isElementInside(edk::rectf64 element,edk::vec2f64 point1,edk::vec2f64 point2){
        if(element.origin.x >= point1.x
                &&
                element.origin.y >= point1.y
                &&
                element.origin.x <= point2.x
                &&
                element.origin.y <= point2.y
                &&
                element.size.width >= point1.x
                &&
                element.size.height >= point1.y
                &&
                element.size.width <= point2.x
                &&
                element.size.height <= point2.y
                ){
            return true;
        }
        return false;
    }
    //test if the element is just colliding
    virtual bool isElementColliding(edk::rectf64 element,edk::vec2f64 point1,edk::vec2f64 point2){
        if(point1.x <= element.size.width
                &&
                point2.x>= element.origin.x
                &&
                point1.y <= element.size.height
                &&
                point2.y >= element.origin.y
                ){
            return true;
            }
        return false;
    }
    //returh the rectangle of the element
    virtual edk::rectf64 getElementRectangle(edk::rectf64 element){
        return edk::rectf64(element.origin.x,element.origin.y,element.size.width,element.size.height);
    }
    //function to create a new tree
    virtual edk::vector::BinaryTree<edk::rectf64>* newTree(){
        return new edk::vector::BinaryTree<edk::rectf64>;
    }
    virtual void elementGetIn(edk::rectf64 element){
        //elementGetIn
    }
    virtual void elementUpdating(edk::rectf64 element){
        //elementUpdating
    }
    virtual void elementGetOut(edk::rectf64 element){
        //elementGetOut
    }
};
*/


namespace edk{
namespace vector{
//LEAF32
template <class typeTemplate>
class QuadLeaf32 : public edk::rectf32{
public:
    QuadLeaf32(edk::rectf32 rect = edk::rectf32(0,0,1,1)){
        this->classThis=NULL;
        this->Constructor(rect);
    }
    QuadLeaf32(QuadLeaf32* father,edk::rectf32 rect = edk::rectf32(0,0,1,1)){
        this->classThis=NULL;
        this->Constructor(father,rect);
    }
    virtual ~QuadLeaf32(){
        this->Destructor();
    }

    void Constructor(edk::rectf32 rect = edk::rectf32(0,0,1,1)){
        this->origin = rect.origin;
        this->size = rect.size;
        if(this->classThis!=this){
            this->classThis=this;

            this->treeThis.Constructor();

            this->depth=0u;
            this->father=NULL;
            //start the values
            this->origin = rect.origin;
            this->size = rect.size;
            this->counter=0u;
            this->tree=NULL;
            //
            this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;

            //add a callback in to the tree
            this->setTree(NULL);
        }
    }
    void Constructor(QuadLeaf32* father,edk::rectf32 rect = edk::rectf32(0,0,1,1)){
        this->origin = rect.origin;
        this->size = rect.size;
        if(this->classThis!=this){
            this->classThis=this;

            this->treeThis.Constructor();

            this->depth=0u;
            this->father=father;
            //start the values
            this->origin = rect.origin;
            this->size = rect.size;
            this->counter=0u;
            this->tree=NULL;
            //
            this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;

            //add a callback in to the tree
            this->setTree(NULL);
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->clean();
            //delete the tree
            this->setTree(NULL);

            this->treeThis.Destructor();
        }
    }

    void clean(){
        this->father=NULL;
        if(this->tree){
            if(this->tree == &this->treeThis){
                this->treeThis.clean();
            }
            else{
                this->tree->clean();
            }
        }
        this->deleteQuads();
    }
    //new quads
    bool newQuads(edk::vector::BinaryTree<typeTemplate>* tree0,
                  edk::vector::BinaryTree<typeTemplate>* tree1,
                  edk::vector::BinaryTree<typeTemplate>* tree2,
                  edk::vector::BinaryTree<typeTemplate>* tree3,
                  edk::float32 minimumQuadSize
                  ){
        this->deleteQuads();

        edk::rectf32 rect;
        rect.origin.x = this->origin.x;
        rect.origin.y = this->origin.y;
        rect.size.width = this->origin.x+((this->size.width - this->origin.x)*0.5);
        rect.size.height = this->origin.y+((this->size.height - this->origin.y)*0.5);

        //test if the size is smaller than the minimum
        if((rect.size.width - rect.origin.x) <= minimumQuadSize
                || (rect.size.height - rect.origin.y) <= minimumQuadSize
                ){
            return false;
        }
        //else create all the quads
        this->quad[0u] = new edk::vector::QuadLeaf32<typeTemplate>(this,rect);
        if(this->quad[0u]){
            rect.origin.x = this->origin.x+((this->size.width - this->origin.x)*0.5);
            rect.origin.y = this->origin.y;
            rect.size.width = this->size.width;
            rect.size.height = this->origin.y+((this->size.height - this->origin.y)*0.5);
            this->quad[1u] = new edk::vector::QuadLeaf32<typeTemplate>(this,rect);
            if(this->quad[1u]){
                rect.origin.x = this->origin.x+((this->size.width - this->origin.x)*0.5);
                rect.origin.y = this->origin.y+((this->size.height - this->origin.y)*0.5);
                rect.size.width = this->size.width;
                rect.size.height = this->size.height;
                this->quad[2u] = new edk::vector::QuadLeaf32<typeTemplate>(this,rect);
                if(this->quad[2u]){
                    rect.origin.x = this->origin.x;
                    rect.origin.y = this->origin.y+((this->size.height - this->origin.y)*0.5);
                    rect.size.width = this->origin.x+((this->size.width - this->origin.x)*0.5);
                    rect.size.height = this->size.height;
                    this->quad[3u] = new edk::vector::QuadLeaf32<typeTemplate>(this,rect);
                    if(this->quad[3u]){
                        this->quad[0u]->setTree(tree0);
                        this->quad[1u]->setTree(tree1);
                        this->quad[2u]->setTree(tree2);
                        this->quad[3u]->setTree(tree3);
                        //
                        this->quad[0u]->depth = this->depth+1u;
                        this->quad[1u]->depth = this->depth+1u;
                        this->quad[2u]->depth = this->depth+1u;
                        this->quad[3u]->depth = this->depth+1u;
                        //
                        return true;
                    }
                    //
                    delete this->quad[2u];
                    this->quad[2u]=NULL;
                }
                //
                delete this->quad[1u];
                this->quad[1u]=NULL;
            }
            //
            delete this->quad[0u];
            this->quad[0u]=NULL;
        }
        return false;
    }

    //set the tree new pointer
    bool setTree(edk::vector::BinaryTree<typeTemplate>* tree){
        //delete the last tree
        if(this->tree){
            if(this->tree != &this->treeThis){
                delete this->tree;
            }
        }
        if(tree){
            this->tree = tree;
            this->treeThis.clean();
            return true;
        }
        this->tree = &this->treeThis;
        return false;
    }
    //get the tree pointer
    edk::vector::BinaryTree<typeTemplate>* getTreePointer(){
        return this->tree;
    }
    //add an element into the tree
    bool addToTree(typeTemplate value){
        return this->tree->add(value);
    }
    bool removeFromTree(typeTemplate value){
        return this->tree->remove(value);
    }
    bool haveInTree(typeTemplate value){
        return this->tree->haveElement(value);
    }
    //get value in position
    typeTemplate getValueFromTreeInPosition(edk::uint32 position){
        return this->tree->getElementInPosition(position);
    }
    //get the tree size
    edk::uint32 getTreeSize(){
        return this->tree->size();
    }

    //run tree functions
    void treeLoad(){
        this->tree->load();
    }
    void treeUnload(){
        this->tree->unload();
    }
    void treePrint(){
        this->tree->print();
    }
    void treeRender(){
        this->tree->render();
    }
    void treeRenderWire(){
        this->tree->renderWire();
    }
    void treeDraw(){
        this->tree->draw();
    }
    void treeDrawWire(){
        this->tree->drawWire();
    }
    void treeUpdate(){
        this->tree->update();
    }

    //return the father
    edk::vector::QuadLeaf32<typeTemplate>* getFather(){
        return this->father;
    }
    //return true if have the quads
    bool haveQuads(){
        if(this->quad[0u]
                && this->quad[1u]
                && this->quad[2u]
                && this->quad[3u]
                ){
            return true;
        }
        return false;
    }
    edk::uint32 getQuadSize(edk::uint8 position){
        if(position<4u){
            this->quad[0u]->getTreeSize();
        }
        return 0u;
    }
    edk::uint32 getQuadsSize(){
        return this->quad[0u]->getTreeSize()
                + this->quad[1u]->getTreeSize()
                + this->quad[2u]->getTreeSize()
                + this->quad[3u]->getTreeSize();
    }
    //get the quad in position
    edk::vector::QuadLeaf32<typeTemplate>* getQuad(edk::uint8 position){
        if(position<4u){
            return this->quad[position];
        }
        return NULL;
    }



    void drawQUADS(){
#if defined(EDK_QUADTREE_GU)
        //draw the rect
        edk::GU::guVertex2f32(this->origin);
        edk::GU::guVertex2f32(this->origin.x,this->size.height);
        //
        edk::GU::guVertex2f32(this->origin.x,this->size.height);
        edk::GU::guVertex2f32(this->size.width,this->size.height);
        //
        edk::GU::guVertex2f32(this->size.width,this->size.height);
        edk::GU::guVertex2f32(this->size.width,this->origin.y);
        //
        edk::GU::guVertex2f32(this->size.width,this->origin.y);
        edk::GU::guVertex2f32(this->origin);

        //go to the others quads
        if(this->quad[0u]){
            for(edk::uint8 i=0u;i<4u;i++){
                this->quad[i]->drawQUADS();
            }
        }
#endif
    }
    //destroi the quads
    void deleteQuads(){
        this->counter=0u;
        if(this->quad[0u]){
            delete this->quad[0u];
        }
        this->quad[0u]=NULL;
        if(this->quad[1u]){
            delete this->quad[1u];
        }
        this->quad[1u]=NULL;
        if(this->quad[2u]){
            delete this->quad[2u];
        }
        this->quad[2u]=NULL;
        if(this->quad[3u]){
            delete this->quad[3u];
        }
        this->quad[3u]=NULL;
    }
    //counter used to set what quad is testing
    edk::uint8 counter;
    edk::uint32 depth;
private:
    edk::vector::QuadLeaf32<typeTemplate>* quad[4u];
    edk::vector::QuadLeaf32<typeTemplate>* father;
    //tree with values
    edk::vector::BinaryTree<typeTemplate> treeThis;
    edk::vector::BinaryTree<typeTemplate>* tree;
private:
    edk::classID classThis;
};
//LEAF64
template <class typeTemplate>
class QuadLeaf64 : public edk::rectf64{
public:
    QuadLeaf64(edk::rectf64 rect = edk::rectf64(0,0,1,1)){
        this->classThis=NULL;
        this->Constructor(rect);
    }
    QuadLeaf64(QuadLeaf64* father,edk::rectf64 rect = edk::rectf64(0,0,1,1)){
        this->classThis=NULL;
        this->Constructor(father,rect);
    }
    virtual ~QuadLeaf64(){
        this->Destructor();
    }

    void Constructor(edk::rectf64 rect = edk::rectf64(0,0,1,1)){
        this->origin = rect.origin;
        this->size = rect.size;
        if(this->classThis!=this){
            this->classThis=this;

            this->treeThis.Constructor();

            this->depth=0u;
            this->father=NULL;
            //start the values
            this->origin = rect.origin;
            this->size = rect.size;
            this->counter=0u;
            this->tree=NULL;
            //
            this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;

            //add a callback in to the tree
            this->setTree(NULL);
        }
    }
    void Constructor(QuadLeaf64* father,edk::rectf64 rect = edk::rectf64(0,0,1,1)){
        this->origin = rect.origin;
        this->size = rect.size;
        if(this->classThis!=this){
            this->classThis=this;

            this->treeThis.Constructor();

            this->depth=0u;
            this->father=father;
            //start the values
            this->origin = rect.origin;
            this->size = rect.size;
            this->counter=0u;
            this->tree=NULL;
            //
            this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;

            //add a callback in to the tree
            this->setTree(NULL);
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            this->clean();
            //delete the tree
            this->setTree(NULL);

            this->treeThis.Destructor();
        }
    }

    void clean(){
        this->father=NULL;
        if(this->tree){
            if(this->tree == &this->treeThis){
                this->treeThis.clean();
            }
            else{
                this->tree->clean();
            }
        }
        this->deleteQuads();
    }
    //new quads
    bool newQuads(edk::vector::BinaryTree<typeTemplate>* tree0,
                  edk::vector::BinaryTree<typeTemplate>* tree1,
                  edk::vector::BinaryTree<typeTemplate>* tree2,
                  edk::vector::BinaryTree<typeTemplate>* tree3,
                  edk::float64 minimumQuadSize
                  ){
        this->deleteQuads();

        edk::rectf64 rect;
        rect.origin.x = this->origin.x;
        rect.origin.y = this->origin.y;
        rect.size.width = this->origin.x+((this->size.width - this->origin.x)*0.5);
        rect.size.height = this->origin.y+((this->size.height - this->origin.y)*0.5);

        //test if the size is smaller than the minimum
        if((rect.size.width - rect.origin.x) <= minimumQuadSize
                || (rect.size.height - rect.origin.y) <= minimumQuadSize
                ){
            return false;
        }
        //else create all the quads
        this->quad[0u] = new edk::vector::QuadLeaf64<typeTemplate>(this,rect);
        if(this->quad[0u]){
            rect.origin.x = this->origin.x+((this->size.width - this->origin.x)*0.5);
            rect.origin.y = this->origin.y;
            rect.size.width = this->size.width;
            rect.size.height = this->origin.y+((this->size.height - this->origin.y)*0.5);
            this->quad[1u] = new edk::vector::QuadLeaf64<typeTemplate>(this,rect);
            if(this->quad[1u]){
                rect.origin.x = this->origin.x+((this->size.width - this->origin.x)*0.5);
                rect.origin.y = this->origin.y+((this->size.height - this->origin.y)*0.5);
                rect.size.width = this->size.width;
                rect.size.height = this->size.height;
                this->quad[2u] = new edk::vector::QuadLeaf64<typeTemplate>(this,rect);
                if(this->quad[2u]){
                    rect.origin.x = this->origin.x;
                    rect.origin.y = this->origin.y+((this->size.height - this->origin.y)*0.5);
                    rect.size.width = this->origin.x+((this->size.width - this->origin.x)*0.5);
                    rect.size.height = this->size.height;
                    this->quad[3u] = new edk::vector::QuadLeaf64<typeTemplate>(this,rect);
                    if(this->quad[3u]){
                        this->quad[0u]->setTree(tree0);
                        this->quad[1u]->setTree(tree1);
                        this->quad[2u]->setTree(tree2);
                        this->quad[3u]->setTree(tree3);
                        //
                        this->quad[0u]->depth = this->depth+1u;
                        this->quad[1u]->depth = this->depth+1u;
                        this->quad[2u]->depth = this->depth+1u;
                        this->quad[3u]->depth = this->depth+1u;
                        //
                        return true;
                    }
                    //
                    delete this->quad[2u];
                    this->quad[2u]=NULL;
                }
                //
                delete this->quad[1u];
                this->quad[1u]=NULL;
            }
            //
            delete this->quad[0u];
            this->quad[0u]=NULL;
        }
        return false;
    }

    //set the tree new pointer
    bool setTree(edk::vector::BinaryTree<typeTemplate>* tree){
        //delete the last tree
        if(this->tree){
            if(this->tree != &this->treeThis){
                delete this->tree;
            }
        }
        if(tree){
            this->tree = tree;
            this->treeThis.clean();
            return true;
        }
        this->tree = &this->treeThis;
        return false;
    }
    //get the tree pointer
    edk::vector::BinaryTree<typeTemplate>* getTreePointer(){
        return this->tree;
    }
    //add an element into the tree
    bool addToTree(typeTemplate value){
        return this->tree->add(value);
    }
    bool removeFromTree(typeTemplate value){
        return this->tree->remove(value);
    }
    bool haveInTree(typeTemplate value){
        return this->tree->haveElement(value);
    }
    //get value in position
    typeTemplate getValueFromTreeInPosition(edk::uint64 position){
        return this->tree->getElementInPosition(position);
    }
    //get the tree size
    edk::uint64 getTreeSize(){
        return this->tree->size();
    }

    //run tree functions
    void treeLoad(){
        this->tree->load();
    }
    void treeUnload(){
        this->tree->unload();
    }
    void treePrint(){
        this->tree->print();
    }
    void treeRender(){
        this->tree->render();
    }
    void treeRenderWire(){
        this->tree->renderWire();
    }
    void treeDraw(){
        this->tree->draw();
    }
    void treeDrawWire(){
        this->tree->drawWire();
    }
    void treeUpdate(){
        this->tree->update();
    }

    //return the father
    edk::vector::QuadLeaf64<typeTemplate>* getFather(){
        return this->father;
    }
    //return true if have the quads
    bool haveQuads(){
        if(this->quad[0u]
                && this->quad[1u]
                && this->quad[2u]
                && this->quad[3u]
                ){
            return true;
        }
        return false;
    }
    edk::uint64 getQuadSize(edk::uint8 position){
        if(position<4u){
            this->quad[0u]->getTreeSize();
        }
        return 0u;
    }
    edk::uint64 getQuadsSize(){
        return this->quad[0u]->getTreeSize()
                + this->quad[1u]->getTreeSize()
                + this->quad[2u]->getTreeSize()
                + this->quad[3u]->getTreeSize();
    }
    //get the quad in position
    edk::vector::QuadLeaf64<typeTemplate>* getQuad(edk::uint8 position){
        if(position<4u){
            return this->quad[position];
        }
        return NULL;
    }



    void drawQUADS(){
#if defined(EDK_QUADTREE_GU)
        //draw the rect
        edk::GU::guVertex2f64(this->origin);
        edk::GU::guVertex2f64(this->origin.x,this->size.height);
        //
        edk::GU::guVertex2f64(this->origin.x,this->size.height);
        edk::GU::guVertex2f64(this->size.width,this->size.height);
        //
        edk::GU::guVertex2f64(this->size.width,this->size.height);
        edk::GU::guVertex2f64(this->size.width,this->origin.y);
        //
        edk::GU::guVertex2f64(this->size.width,this->origin.y);
        edk::GU::guVertex2f64(this->origin);

        //go to the others quads
        if(this->quad[0u]){
            for(edk::uint8 i=0u;i<4u;i++){
                this->quad[i]->drawQUADS();
            }
        }
#endif
    }
    //destroi the quads
    void deleteQuads(){
        this->counter=0u;
        if(this->quad[0u]){
            delete this->quad[0u];
        }
        this->quad[0u]=NULL;
        if(this->quad[1u]){
            delete this->quad[1u];
        }
        this->quad[1u]=NULL;
        if(this->quad[2u]){
            delete this->quad[2u];
        }
        this->quad[2u]=NULL;
        if(this->quad[3u]){
            delete this->quad[3u];
        }
        this->quad[3u]=NULL;
    }
    //counter used to set what quad is testing
    edk::uint8 counter;
    edk::uint64 depth;
private:
    edk::vector::QuadLeaf64<typeTemplate>* quad[4u];
    edk::vector::QuadLeaf64<typeTemplate>* father;
    //tree with values
    edk::vector::BinaryTree<typeTemplate> treeThis;
    edk::vector::BinaryTree<typeTemplate>* tree;
private:
    edk::classID classThis;
};

//QUADTREE32
template <class typeTemplate>
class QuadTree32 : public edk::vector::BinaryTreeCallback<typeTemplate>{
public:
    QuadTree32(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~QuadTree32(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::BinaryTreeCallback<typeTemplate>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;

            this->root.Constructor();
            this->treeGets.Constructor();
            this->treeOutside.Constructor();
            this->treeValuesUpdate.Constructor();
            this->treeNULL.Constructor();

            this->selected = &this->treeNULL;
            this->selected1 = &this->treeNULL;
            this->selected2 = &this->treeNULL;
            this->selected3 = &this->treeNULL;
            this->treeTemp = &this->treeValuesUpdate;

            this->rootPointer = &this->root;
            this->treeGetsPointer = &this->treeGets;
            this->treeOutsidePointer = &this->treeOutside;
            this->treeValuesUpdatePointer = &this->treeValuesUpdate;
            this->treeNULLPointer = &this->treeNULL;

            this->selectedPointer = &this->selected;
            this->selected1Pointer = &this->selected1;
            this->selected2Pointer = &this->selected2;
            this->selected3Pointer = &this->selected3;
            this->treeTempPointer = &this->treeTemp;

            this->canObjectIn=true;

            //

            this->cleanWithRectPoints(edk::rectf32(0,0,1,1));
            this->minimumElementInQuads=1u;
            this->setMinimumElementInQuads(0u);
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            //the destructor don't call the getOut functions because is possible the element don't exist
            this->root.clean();
            this->treeNULL.clean();
            if(this->treeTemp!=&this->treeValuesUpdate){
                this->treeTemp->clean();
                delete this->treeTemp;
            }
            this->treeValuesUpdate.clean();
            this->treeGets.clean();
            this->treeOutside.clean();

            this->root.Destructor();
            this->treeGets.Destructor();
            this->treeOutside.Destructor();
            this->treeValuesUpdate.Destructor();
            this->treeNULL.Destructor();
        }
        edk::vector::BinaryTreeCallback<typeTemplate>::Destructor();
    }

    //set if can add an object in the scene
    void setCanAddObjectsInScene(bool canAdd){
        this->canObjectIn=canAdd;
    }
    void canAddObjectInScene(){
        this->setCanAddObjectsInScene(true);
    }
    void cantAddObjectInScene(){
        this->setCanAddObjectsInScene(false);
    }
    bool getCanAddObjectsInScene(){
        return this->canObjectIn;
    }

    //set the minimunQuadSize
    bool setMinimumQuadSize(edk::float32 minimumQuadSize){
        if(minimumQuadSize>0.f){
            this->minimumQuadSize = minimumQuadSize;
            return true;
        }
        this->minimumQuadSize=edkQuadMinimumSize;
        return false;
    }
    edk::float32 getMinimumQuadSize(){
        return this->minimumQuadSize;
    }
    //set the minimunObjectsInQuads
    bool setMinimumElementInQuads(edk::uint32 minimumElementInQuads){
        if(minimumElementInQuads){
            this->minimumElementInQuads=minimumElementInQuads;
            return true;
        }
        //else set 1
        this->minimumElementInQuads=1u;
        return false;
    }
    edk::uint32 getMinimumElementInQuads(){
        return this->minimumElementInQuads;
    }
    //set the quadtree position and size
    void setPositionAndSize(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->setRect(edk::rectf32(x,y,width + x,height + y),minimumQuadSize);
    }
    void setPositionAndSize(edk::vec2f32 position,edk::size2f32 size,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->setRect(edk::rectf32(position.x,position.y,size.width + position.x,size.height + position.y),minimumQuadSize);
    }
    void setPoints(edk::float32 position1X,edk::float32 position1Y,edk::float32 position2X,edk::float32 position2Y,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->setRect(edk::rectf32(position1X,position1Y,position2X,position2Y),minimumQuadSize);
    }
    void setPoints(edk::vec2f32 point1,edk::vec2f32 point2,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->setRect(edk::rectf32(point1.x,point1.y,point2.x,point2.y),minimumQuadSize);
    }
    //set the quadTree rectangle
    void setRect(edk::rectf32 rect,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(rect);
        this->minimumQuadSize=minimumQuadSize;
    }
    void setRect(edk::vec2f32 position1,edk::vec2f32 position2,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(edk::rectf32(position1.x,position1.y,position2.x,position2.y));
        this->minimumQuadSize=minimumQuadSize;
    }
    void setRect(edk::float32 pos1X,edk::float32 pos1Y,edk::float32 pos2X,edk::float32 pos2Y,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(edk::rectf32(pos1X,pos1Y,pos2X,pos2Y));
        this->minimumQuadSize=minimumQuadSize;
    }
    void setRectPoints(edk::rectf32 rect,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(rect);
        this->minimumQuadSize=minimumQuadSize;
    }
    void setRectPoints(edk::vec2f32 position1,edk::vec2f32 position2,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(edk::rectf32(position1.x,position1.y,position2.x,position2.y));
        this->minimumQuadSize=minimumQuadSize;
    }
    void setRectPoints(edk::float32 pos1X,edk::float32 pos1Y,edk::float32 pos2X,edk::float32 pos2Y,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(edk::rectf32(pos1X,pos1Y,pos2X,pos2Y));
        this->minimumQuadSize=minimumQuadSize;
    }
    //return the quadtree rectangle
    edk::rectf32 getRectangle(){
        return edk::rectf32((*this->rootPointer).origin.x+((*this->rootPointer).size.width*0.5f),
                            (*this->rootPointer).origin.y+((*this->rootPointer).size.height*0.5f),
                            (*this->rootPointer).origin.x-((*this->rootPointer).size.width*0.5f),
                            (*this->rootPointer).origin.y-((*this->rootPointer).size.height*0.5f)
                            );
    }
    edk::rectf32 getRectanglePoints(){
        return edk::rectf32((*this->rootPointer).origin,(*this->rootPointer).size);
    }
    void incrementRect(edk::rectf32 rect){
        if(rect.origin.x > (*this->rootPointer).origin.x){
            rect.origin.x = (*this->rootPointer).origin.x;
        }
        if(rect.origin.y > (*this->rootPointer).origin.y){
            rect.origin.y = (*this->rootPointer).origin.y;
        }
        if(rect.size.width < (*this->rootPointer).size.width){
            rect.size.width = (*this->rootPointer).size.width;
        }
        if(rect.size.height < (*this->rootPointer).size.height){
            rect.size.height = (*this->rootPointer).size.height;
        }
        if(rect.origin.x > (*this->treeNULLPointer).origin.x){
            rect.origin.x = (*this->treeNULLPointer).origin.x;
        }
        if(rect.origin.y > (*this->treeNULLPointer).origin.y){
            rect.origin.y = (*this->treeNULLPointer).origin.y;
        }
        if(rect.size.width < (*this->treeNULLPointer).size.width){
            rect.size.width = (*this->treeNULLPointer).size.width;
        }
        if(rect.size.height < (*this->treeNULLPointer).size.height){
            rect.size.height = (*this->treeNULLPointer).size.height;
        }
        this->cleanWithRectPoints(rect);
    }
    void incrementRect(edk::vec2f32 position,edk::size2f32 size){
        this->incrementRect(edk::rectf32(position,size));
    }
    void incrementRect(edk::float32 positionX,edk::float32 positionY,edk::float32 width,edk::float32 height){
        this->incrementRect(edk::rectf32(positionX,positionY,width,height));
    }

    //add a object
    bool add(typeTemplate value, edk::uint32 depthLimit=0xFFFFFFFF){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        //nexts quads to be tested
        edk::vector::Queue<edk::vector::QuadLeaf32<typeTemplate>*> nexts;
        edk::vector::QuadLeaf32<typeTemplate>* temp = &(*this->rootPointer);
        edk::vector::QuadLeaf32<typeTemplate>* temp2 = &(*this->rootPointer);
        edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
        edk::vector::BinaryTree<typeTemplate>* tree;
        edk::uint32 size = 0u;
        typeTemplate valueTemp;
        bool ret=false;
        bool push[edkQuadSelectedSize];
        edk::vector::QuadLeaf32<typeTemplate>* goInside[edkQuadSelectedSize];
        edk::uint8 k;
        edk::uint32 counterIn,counterQuads;

        //test if the value is inside the root
        if(this->isElementInside(value,
                                 edk::vec2f32(temp->origin.x,
                                              temp->origin.y
                                              ),
                                 edk::vec2f32(temp->size.width,
                                              temp->size.height
                                              )
                                 )
                ){
            //add the value in to the temp
            temp->addToTree(value);
            //add the root inside the queue
            nexts.pushBack(temp);
            while(temp){
                //get the text from the queue
                if(nexts.size()){
                    temp2 = nexts.popFront();
                }
                else{
                    temp2=NULL;
                }

                if(temp2){
                    temp=temp2;
                    ret=true;

                    //test if the temp have more than 1 value
                    if(temp->getTreeSize()>this->minimumElementInQuads){

                        if((temp->depth+1u)>=depthLimit){
                            //have the limit
                            break;
                        }

                        //create new quads
                        if(!temp->haveQuads()){
                            //create the trees
                            edk::vector::BinaryTree<typeTemplate>* tree1 = this->newTree();
                            if(tree1){
                                edk::vector::BinaryTree<typeTemplate>* tree2 = this->newTree();
                                if(tree2){
                                    edk::vector::BinaryTree<typeTemplate>* tree3 = this->newTree();
                                    if(tree3){
                                        edk::vector::BinaryTree<typeTemplate>* tree4 = this->newTree();
                                        if(tree4){
                                            //create new quads
                                            if(temp->newQuads(tree1,
                                                              tree2,
                                                              tree3,
                                                              tree4,
                                                              this->minimumQuadSize
                                                              )){
                                                //
                                                tree1=tree2=tree3=tree4=NULL;
                                            }
                                            if(tree4){
                                                delete tree4;
                                            }
                                        }
                                        if(tree3){
                                            delete tree3;
                                        }
                                    }
                                    if(tree2){
                                        delete tree2;
                                    }
                                }
                                if(tree1){
                                    delete tree1;
                                }
                            }
                        }



                        //test if have the quads
                        if(temp->haveQuads()){
                            push[0u]=false;
                            push[1u]=false;
                            push[2u]=false;
                            push[3u]=false;
                            goInside[0u]=NULL;
                            goInside[1u]=NULL;
                            goInside[2u]=NULL;
                            goInside[3u]=NULL;
                            counterIn=0u;
                            //get the temp tree
                            tree = temp->getTreePointer();
                            if(tree){
                                size = tree->size();
                                k=0u;
                                //test if the quads are new
                                if(temp->getQuadsSize()<size-1u){
                                    //else add the objects
                                    for(edk::uint32 j=0u;j<size;j++){
                                        valueTemp = tree->getElementInPosition(j);
                                        counterQuads=0u;
                                        for(edk::uint8 i=0u;i<4u;i++){
                                            tempQuad = temp->getQuad(i);
                                            //test if is colliding with the quads to just add in the tree
                                            if(this->isElementColliding(valueTemp,
                                                                        edk::vec2f32(tempQuad->origin.x,
                                                                                     tempQuad->origin.y
                                                                                     ),
                                                                        edk::vec2f32(tempQuad->size.width,
                                                                                     tempQuad->size.height
                                                                                     )
                                                                        )
                                                    ){
                                                counterQuads++;
                                                if(!tempQuad->haveInTree(valueTemp)){
                                                    tempQuad->addToTree(valueTemp);
                                                }
                                                if(!push[i]){
                                                    //add the quad into the queue
                                                    //nexts.pushBack(tempQuad);
                                                    goInside[k]=tempQuad;
                                                    k++;
                                                    push[i]=true;
                                                }
                                            }
                                        }
                                        if(counterQuads>=4u){
                                            counterIn++;
                                        }
                                    }
                                    //test if need go into the nexts quads
                                    if(counterIn<size){
                                        bool goPush=true;
                                        //test if have nextQuads
                                        for(edk::uint8 i=0u;i<4u;i++){
                                            if(goInside[i]){
                                                nexts.pushBack(goInside[i]);
                                                goPush=false;
                                            }
                                        }
                                        if(goPush){
                                            //go to the father
                                            temp = temp->getFather();
                                        }
                                    }
                                    else{
                                        //else go to the father
                                        temp = temp->getFather();
                                    }
                                }
                                else{
                                    //add just the first
                                    valueTemp = value;
                                    counterQuads=0u;
                                    for(edk::uint8 i=0u;i<4u;i++){
                                        tempQuad = temp->getQuad(i);
                                        //test if is colliding with the quads to just add in the tree
                                        if(this->isElementColliding(valueTemp,
                                                                    edk::vec2f32(tempQuad->origin.x,
                                                                                 tempQuad->origin.y
                                                                                 ),
                                                                    edk::vec2f32(tempQuad->size.width,
                                                                                 tempQuad->size.height
                                                                                 )
                                                                    )
                                                ){
                                            counterQuads++;
                                            if(!tempQuad->haveInTree(valueTemp)){
                                                tempQuad->addToTree(valueTemp);
                                            }
                                            if(!push[i]){
                                                //add the quad into the queue
                                                //nexts.pushBack(tempQuad);
                                                goInside[k]=tempQuad;
                                                k++;
                                                push[i]=true;
                                            }
                                        }
                                    }
                                    if(counterQuads<4u){
                                        bool goPush=true;
                                        //test if have nextQuads
                                        for(edk::uint8 i=0u;i<4u;i++){
                                            if(goInside[i]){
                                                nexts.pushBack(goInside[i]);
                                                goPush=false;
                                            }
                                        }
                                        if(goPush){
                                            //go to the father
                                            temp = temp->getFather();
                                        }
                                    }
                                    else{
                                        //else go to the father
                                        temp = temp->getFather();
                                    }
                                }
                            }
                        }
                        else{
                            //else go to the father
                            temp = temp->getFather();
                        }
                    }
                    else{
                        //else go to the father
                        temp = temp->getFather();
                    }
                }
                else{
                    //else go to the father
                    temp = temp->getFather();
                }
            }
        }
        nexts.clean();
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebugNoPosition(this,this->generateDebugValue(&value),ret);
#endif
        return ret;
    }
    //add objects from a tree
    bool addFromTree(edk::vector::BinaryTree<typeTemplate>* tree, edk::uint32 depthLimit=0xFFFFFFFF){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(tree){
            bool ret=true;
            edk::uint32 size = tree->size();
            for(edk::uint32 i=0u;i<size;i++){
                if(!this->add(tree->getElementInPosition(i),depthLimit)){
                    ret=false;
                }
            }
            return ret;
        }
        return false;
    }
    bool setRectFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(tree){
            edk::uint32 size = tree->size();
            edk::rectf32 rectangle = edk::rectf32(0,0,1,1);
            edk::rectf32 rectanglePoints = edk::rectf32(0,0,1,1);
            edk::rectf32 rectTemp;
            edk::rectf32 rectTempPoints;
            if(size){
                rectangle = this->getElementRectangle(tree->getElementInPosition(0u));
                rectanglePoints = edk::rectf32(rectangle.origin.x - rectangle.size.width,
                                               rectangle.origin.y - rectangle.size.height,
                                               rectangle.origin.x + rectangle.size.width,
                                               rectangle.origin.y + rectangle.size.height
                                               );
                for(edk::uint32 i=1u;i<size;i++){
                    rectTemp = this->getElementRectangle(tree->getElementInPosition(i));
                    rectTempPoints = edk::rectf32(rectTemp.origin.x - rectTemp.size.width,
                                                  rectTemp.origin.y - rectTemp.size.height,
                                                  rectTemp.origin.x + rectTemp.size.width,
                                                  rectTemp.origin.y + rectTemp.size.height
                                                  );
                    //test if need to update the rectangle
                    if(rectanglePoints.origin.x >= rectTempPoints.origin.x){
                        rectanglePoints.origin.x = rectTempPoints.origin.x;
                    }
                    if(rectanglePoints.origin.y >= rectTempPoints.origin.y){
                        rectanglePoints.origin.y = rectTempPoints.origin.y;
                    }
                    if(rectanglePoints.size.width <= rectTempPoints.size.width){
                        rectanglePoints.size.width = rectTempPoints.size.width;
                    }
                    if(rectanglePoints.size.height <= rectTempPoints.size.height){
                        rectanglePoints.size.height = rectTempPoints.size.height;
                    }
                }
                //increment the size of the rectangle
                rectanglePoints.origin.x -= (rectanglePoints.size.width - rectanglePoints.origin.x)*0.025f;
                rectanglePoints.origin.y -= (rectanglePoints.size.height - rectanglePoints.origin.y)*0.025f;
                rectanglePoints.size.width += (rectanglePoints.size.width - rectanglePoints.origin.x)*0.025f;
                rectanglePoints.size.height += (rectanglePoints.size.height - rectanglePoints.origin.y)*0.025f;
                //set the rectangle
                this->setRect(rectanglePoints);
                return true;
            }
            this->setRect(rectanglePoints);
        }
        return false;
    }
    bool incrementRectFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(tree){
            edk::uint32 size = tree->size();
            edk::rectf32 rectangle = edk::rectf32(0,0,1,1);
            edk::rectf32 rectanglePoints = edk::rectf32(0,0,1,1);
            edk::rectf32 rectTemp;
            edk::rectf32 rectTempPoints;
            if(size){
                rectangle = this->getElementRectangle(tree->getElementInPosition(0u));
                rectanglePoints = edk::rectf32(rectangle.origin.x - rectangle.size.width,
                                               rectangle.origin.y - rectangle.size.height,
                                               rectangle.origin.x + rectangle.size.width,
                                               rectangle.origin.y + rectangle.size.height
                                               );
                for(edk::uint32 i=0u;i<size;i++){
                    rectTemp = this->getElementRectangle(tree->getElementInPosition(i));
                    rectTempPoints = edk::rectf32(rectTemp.origin.x - rectTemp.size.width,
                                                  rectTemp.origin.y - rectTemp.size.height,
                                                  rectTemp.origin.x + rectTemp.size.width,
                                                  rectTemp.origin.y + rectTemp.size.height
                                                  );
                    //test if need to update the rectangle
                    if(rectanglePoints.origin.x >= rectTempPoints.origin.x){
                        rectanglePoints.origin.x = rectTempPoints.origin.x;
                    }
                    if(rectanglePoints.origin.y >= rectTempPoints.origin.y){
                        rectanglePoints.origin.y = rectTempPoints.origin.y;
                    }
                    if(rectanglePoints.size.width <= rectTempPoints.size.width){
                        rectanglePoints.size.width = rectTempPoints.size.width;
                    }
                    if(rectanglePoints.size.height <= rectTempPoints.size.height){
                        rectanglePoints.size.height = rectTempPoints.size.height;
                    }
                    //increment the size of the rectangle
                    rectanglePoints.origin.x -= (rectanglePoints.size.width - rectanglePoints.origin.x)*0.025f;
                    rectanglePoints.origin.y -= (rectanglePoints.size.height - rectanglePoints.origin.y)*0.025f;
                    rectanglePoints.size.width += (rectanglePoints.size.width - rectanglePoints.origin.x)*0.025f;
                    rectanglePoints.size.height += (rectanglePoints.size.height - rectanglePoints.origin.y)*0.025f;
                }
                //set the rectangle
                this->incrementRect(rectanglePoints);
                return true;
            }
        }
        return false;
    }
    bool setRectAndAddFromTree(edk::vector::BinaryTree<typeTemplate>* tree, edk::uint32 depthLimit=0xFFFFFFFF){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(this->setRectFromTree(tree)){
            if(this->addFromTree(tree,depthLimit)){
                return true;
            }
        }
        return false;
    }
    bool setRectPointsFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(tree){
            edk::uint32 size = tree->size();
            edk::rectf32 rectangle = edk::rectf32(0,0,1,1);
            edk::rectf32 rectTemp;
            if(size){
                rectangle = this->getElementRectangle(tree->getElementInPosition(0u));
                for(edk::uint32 i=1u;i<size;i++){
                    rectTemp = this->getElementRectangle(tree->getElementInPosition(i));
                    //test if need to update the rectangle
                    if(rectangle.origin.x >= rectTemp.origin.x){
                        rectangle.origin.x = rectTemp.origin.x;
                    }
                    if(rectangle.origin.y >= rectTemp.origin.y){
                        rectangle.origin.y = rectTemp.origin.y;
                    }
                    if(rectangle.size.width <= rectTemp.size.width){
                        rectangle.size.width = rectTemp.size.width;
                    }
                    if(rectangle.size.height <= rectTemp.size.height){
                        rectangle.size.height = rectTemp.size.height;
                    }
                }
                //increment the size of the rectangle
                rectangle.origin.x -= (rectangle.size.width - rectangle.origin.x)*0.025f;
                rectangle.origin.y -= (rectangle.size.height - rectangle.origin.y)*0.025f;
                rectangle.size.width += (rectangle.size.width - rectangle.origin.x)*0.025f;
                rectangle.size.height += (rectangle.size.height - rectangle.origin.y)*0.025f;
                //set the rectangle
                this->setRect(rectangle);
                return true;
            }
            this->setRect(rectangle);
        }
        return false;
    }
    bool incrementRectPointsFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(tree){
            edk::uint32 size = tree->size();
            edk::rectf32 rectangle = edk::rectf32(0,0,1,1);
            edk::rectf32 rectTemp;
            if(size){
                rectangle = this->getElementRectangle(tree->getElementInPosition(0u));
                for(edk::uint32 i=0u;i<size;i++){
                    rectTemp = this->getElementRectangle(tree->getElementInPosition(i));
                    //test if need to update the rectangle
                    if(rectangle.origin.x >= rectTemp.origin.x){
                        rectangle.origin.x = rectTemp.origin.x;
                    }
                    if(rectangle.origin.y >= rectTemp.origin.y){
                        rectangle.origin.y = rectTemp.origin.y;
                    }
                    if(rectangle.size.width <= rectTemp.size.width){
                        rectangle.size.width = rectTemp.size.width;
                    }
                    if(rectangle.size.height <= rectTemp.size.height){
                        rectangle.size.height = rectTemp.size.height;
                    }
                    //increment the size of the rectangle
                    rectangle.origin.x -= (rectangle.size.width - rectangle.origin.x)*0.025f;
                    rectangle.origin.y -= (rectangle.size.height - rectangle.origin.y)*0.025f;
                    rectangle.size.width += (rectangle.size.width - rectangle.origin.x)*0.025f;
                    rectangle.size.height += (rectangle.size.height - rectangle.origin.y)*0.025f;
                }
                //set the rectangle
                this->incrementRect(rectangle);
                return true;
            }
        }
        return false;
    }
    void incrementRectPointsFromValue(typeTemplate value){
#if defined(EDK_DONT_USE_QUADTREE)
        return;
#endif
        edk::rectf32 rectangle = edk::rectf32(0,0,1,1);
        edk::rectf32 rectTemp;
        rectangle = this->getRectangle();
        rectTemp = this->getElementRectangle(value);
        //test if need to update the rectangle
        if(rectangle.origin.x >= rectTemp.origin.x){
            rectangle.origin.x = rectTemp.origin.x;
        }
        if(rectangle.origin.y >= rectTemp.origin.y){
            rectangle.origin.y = rectTemp.origin.y;
        }
        if(rectangle.size.width <= rectTemp.size.width){
            rectangle.size.width = rectTemp.size.width;
        }
        if(rectangle.size.height <= rectTemp.size.height){
            rectangle.size.height = rectTemp.size.height;
        }
        //increment the size of the rectangle
        rectangle.origin.x -= (rectangle.size.width - rectangle.origin.x)*0.025f;
        rectangle.origin.y -= (rectangle.size.height - rectangle.origin.y)*0.025f;
        rectangle.size.width += (rectangle.size.width - rectangle.origin.x)*0.025f;
        rectangle.size.height += (rectangle.size.height - rectangle.origin.y)*0.025f;

        //set the rectangle
        this->incrementRect(rectangle);
    }
    bool setRectPointsAndAddFromTree(edk::vector::BinaryTree<typeTemplate>* tree, edk::uint32 depthLimit=0xFFFFFFFF){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(this->setRectPointsFromTree(tree)){
            if(this->addFromTree(tree,depthLimit)){
                return true;
            }
        }
        return false;
    }
    //remove a value from de quadTree
    bool remove(typeTemplate value){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        bool ret=false;
        edk::vector::QuadLeaf32<typeTemplate>* temp = &(*this->rootPointer);
        edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
        bool deleteQuads;
        edk::uint8 cTemp=0u;
        //test if the value is inside the root
        if(this->isElementInside(value,
                                 edk::vec2f32(temp->origin.x,
                                              temp->origin.y
                                              ),
                                 edk::vec2f32(temp->size.width,
                                              temp->size.height
                                              )
                                 )
                ){
            temp->counter=0u;
            while(temp){
                //remove from it
                if(temp->haveInTree(value)){
                    temp->removeFromTree(value);
                    ret=true;
                }

                //search for the quads
                if(temp->haveQuads()){
                    if(temp->counter<4u){
                        if(this->isElementColliding(value,
                                                    edk::vec2f32(temp->origin.x,
                                                                 temp->origin.y
                                                                 ),
                                                    edk::vec2f32(temp->size.width,
                                                                 temp->size.height
                                                                 )
                                                    )
                                ){
                            cTemp = temp->counter;
                            temp->counter++;
                            temp=temp->getQuad(cTemp);
                            temp->counter=0u;
                        }
                        else{
                            temp->counter=4u;
                        }
                    }
                    else{
                        deleteQuads=true;
                        //test if need delete the quads
                        for(edk::uint8 i=0u;i<4u;i++){
                            tempQuad = temp->getQuad(i);
                            //test if the tempQuad have some inside the tree
                            if(tempQuad->getTreeSize()){
                                //don't delete the quads
                                deleteQuads=false;
                            }
                        }
                        //test if need delete the quads
                        if(deleteQuads){
                            temp->deleteQuads();
                        }

                        temp=temp->getFather();
                    }
                }
                else{
                    temp=temp->getFather();
                }
            }
        }
        if((*this->treeTempPointer)->haveElement(value)){
            ret=true;
            if((*this->treeTempPointer)->remove(value)){
                this->elementGetOut(value);
            }
        }
        if((*this->treeOutsidePointer).haveElement(value)){
            ret=true;
            if((*this->treeOutsidePointer).remove(value)){
                //
            }
        }
        if((*this->treeGetsPointer).haveElement(value)){
            ret=true;
            if((*this->treeGetsPointer).remove(value)){
                //
            }
        }
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebugNoPosition(this,this->generateDebugValue(&value),ret);
#endif
        return ret;
    }

    //select a leaf
    virtual bool selectLeafWithValue(typeTemplate value){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        (*this->selectedPointer) = &(*this->treeNULLPointer);
        edk::vector::QuadLeaf32<typeTemplate>** tree[edkQuadSelectedSize];
        tree[0u] = &(*this->selectedPointer);
        tree[1u] = &(*this->selected1Pointer);
        tree[2u] = &(*this->selected2Pointer);
        tree[3u] = &(*this->selected3Pointer);
        bool ret=false;
        if(this->isRectColliding(getElementRectangle(value),
                                 edk::vec2f32((*this->rootPointer).origin.x,
                                              (*this->rootPointer).origin.y
                                              ),
                                 edk::vec2f32((*this->rootPointer).size.width,
                                              (*this->rootPointer).size.height
                                              )
                                 )
                ){
            (*this->selectedPointer) = &(*this->rootPointer);
            edk::vector::QuadLeaf32<typeTemplate>* temp = &(*this->rootPointer);
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
            while(temp){
                counter=0u;
                //test the collision with all quads
                if(temp->haveQuads()){
                    *tree[1u] = &(*this->treeNULLPointer);
                    *tree[2u] = &(*this->treeNULLPointer);
                    *tree[3u] = &(*this->treeNULLPointer);
                    for(edk::uint8 i=0u;i<4u;i++){
                        tempQuad = temp->getQuad(i);
                        if(this->isElementInside(value,
                                                 edk::vec2f32(tempQuad->origin.x,
                                                              tempQuad->origin.y
                                                              ),
                                                 edk::vec2f32(tempQuad->size.width,
                                                              tempQuad->size.height
                                                              )
                                                 )
                                ){
                            //
                            *tree[counter] = tempQuad;
                            counter++;
                            nextID = i;
                        }
                    }
                    //test if have one next
                    if(counter==1u){
                        //then get the next
                        (*this->selectedPointer) = temp = temp->getQuad(nextID);
                    }
                    else{
                        temp=NULL;
                    }
                }
                else{
                    temp=NULL;
                }
            }
            if((*this->selectedPointer) && (*this->selectedPointer)!=&(*this->treeNULLPointer)){
                if(!(*this->selectedPointer)->getTreeSize()
                        && !(*this->selected1Pointer)->getTreeSize()
                        && !(*this->selected2Pointer)->getTreeSize()
                        && !(*this->selected3Pointer)->getTreeSize()
                        ){
                    if((*this->selectedPointer)->getFather()){
                        (*this->selectedPointer) = (*this->selectedPointer)->getFather();
                        (*this->selected1Pointer) = &(*this->treeNULLPointer);
                        (*this->selected2Pointer) = &(*this->treeNULLPointer);
                        (*this->selected3Pointer) = &(*this->treeNULLPointer);
                    }
                }
            }
        }
        this->runUpdateGets();
        if(ret){
            ret = (bool)(*this->treeTempPointer)->size();
        }
        return ret;
    }
    virtual bool selectLeafInPoint(edk::vec2f32 point){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        (*this->selectedPointer) = &(*this->treeNULLPointer);
        (*this->selected1Pointer) = &(*this->treeNULLPointer);
        (*this->selected2Pointer) = &(*this->treeNULLPointer);
        (*this->selected3Pointer) = &(*this->treeNULLPointer);
        bool ret=false;
        if(this->isPointInside(point,
                               edk::vec2f32((*this->rootPointer).origin.x,
                                            (*this->rootPointer).origin.y
                                            ),
                               edk::vec2f32((*this->rootPointer).size.width,
                                            (*this->rootPointer).size.height
                                            )
                               )
                ){
            (*this->selectedPointer) = &(*this->rootPointer);
            edk::vector::QuadLeaf32<typeTemplate>* temp = &(*this->rootPointer);
            ret=true;
            //edk::uint8 counter;
            edk::uint8 nextID=0u;
            edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
            bool needContinue=false;
            while(temp){
                //test the collision with all quads
                if(temp->haveQuads()){
                    needContinue=false;
                    for(edk::uint8 i=0u;i<4u;i++){
                        tempQuad = temp->getQuad(i);
                        if(this->isPointInside(point,
                                               edk::vec2f32(tempQuad->origin.x,
                                                            tempQuad->origin.y
                                                            ),
                                               edk::vec2f32(tempQuad->size.width,
                                                            tempQuad->size.height
                                                            )
                                               )
                                ){
                            //
                            (*this->selectedPointer) = temp = temp->getQuad(nextID);
                            break;
                        }
                    }
                    if(needContinue){
                        continue;
                    }
                    temp=NULL;
                }
                else{
                    temp=NULL;
                }
            }
        }
        this->runUpdateGets(edk::rectf32(point.x,point.y,point.x,point.y));
        if(ret){
            ret = (bool)(*this->treeTempPointer)->size();
        }
        return ret;
    }
    virtual bool selectLeafInRect(edk::rectf32 rect){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        (*this->selectedPointer) = &(*this->treeNULLPointer);
        edk::vector::QuadLeaf32<typeTemplate>** tree[edkQuadSelectedSize];
        (*this->selectedPointer)  = &(*this->treeNULLPointer);
        (*this->selected1Pointer) = &(*this->treeNULLPointer);
        (*this->selected2Pointer) = &(*this->treeNULLPointer);
        (*this->selected3Pointer) = &(*this->treeNULLPointer);
        tree[0u] = &(*this->selectedPointer);
        tree[1u] = &(*this->selected1Pointer);
        tree[2u] = &(*this->selected2Pointer);
        tree[3u] = &(*this->selected3Pointer);
        bool ret=false;
        if(this->isRectColliding(rect,
                                 edk::vec2f32((*this->rootPointer).origin.x,
                                              (*this->rootPointer).origin.y
                                              ),
                                 edk::vec2f32((*this->rootPointer).size.width,
                                              (*this->rootPointer).size.height
                                              )
                                 )
                ){
            (*this->selectedPointer) = &(*this->rootPointer);
            edk::vector::QuadLeaf32<typeTemplate>* temp = &(*this->rootPointer);
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
            while(temp){
                //test if have quads inside
                if(temp->haveQuads()){
                    counter=0u;
                    for(edk::uint8 i=0u;i<4u;i++){
                        tempQuad = temp->getQuad(i);
                        if(this->isRectColliding(rect,
                                                 edk::vec2f32(tempQuad->origin.x,
                                                              tempQuad->origin.y
                                                              ),
                                                 edk::vec2f32(tempQuad->size.width,
                                                              tempQuad->size.height
                                                              )
                                                 )
                                ){
                            //
                            *tree[counter]=tempQuad;
                            counter++;
                            nextID = i;
                        }
                    }
                    //test if have just one colliding
                    if(counter==1u){
                        //select the next
                        (*this->selectedPointer) = temp = temp->getQuad(nextID);
                        *tree[1u] = &(*this->treeNULLPointer);
                        *tree[2u] = &(*this->treeNULLPointer);
                        *tree[3u] = &(*this->treeNULLPointer);
                    }
                    else if(counter==4u){
                        //select only the temp
                        (*this->selectedPointer) = temp;
                        *tree[1u] = &(*this->treeNULLPointer);
                        *tree[2u] = &(*this->treeNULLPointer);
                        *tree[3u] = &(*this->treeNULLPointer);
                        break;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        this->runUpdateGets(rect);
        if(ret){
            ret = (bool)(*this->treeTempPointer)->size();
        }
        return ret;
    }
    virtual bool selectLeafInRectPoints(edk::rectf32 rect){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        (*this->selectedPointer) = &(*this->treeNULLPointer);
        edk::vector::QuadLeaf32<typeTemplate>** tree[edkQuadSelectedSize];
        (*this->selectedPointer)  = &(*this->treeNULLPointer);
        (*this->selected1Pointer) = &(*this->treeNULLPointer);
        (*this->selected2Pointer) = &(*this->treeNULLPointer);
        (*this->selected3Pointer) = &(*this->treeNULLPointer);
        tree[0u] = &(*this->selectedPointer);
        tree[1u] = &(*this->selected1Pointer);
        tree[2u] = &(*this->selected2Pointer);
        tree[3u] = &(*this->selected3Pointer);
        bool ret=false;
        if(this->isRectPointsColliding(rect,
                                       edk::vec2f32((*this->rootPointer).origin.x,
                                                    (*this->rootPointer).origin.y
                                                    ),
                                       edk::vec2f32((*this->rootPointer).size.width,
                                                    (*this->rootPointer).size.height
                                                    )
                                       )
                ){
            (*this->selectedPointer) = &(*this->rootPointer);
            edk::vector::QuadLeaf32<typeTemplate>* temp = &(*this->rootPointer);
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
            while(temp){
                //test if have quads inside
                if(temp->haveQuads()){
                    counter=0u;
                    for(edk::uint8 i=0u;i<4u;i++){
                        tempQuad = temp->getQuad(i);
                        if(this->isRectPointsColliding(rect,
                                                       edk::vec2f32(tempQuad->origin.x,
                                                                    tempQuad->origin.y
                                                                    ),
                                                       edk::vec2f32(tempQuad->size.width,
                                                                    tempQuad->size.height
                                                                    )
                                                       )
                                ){
                            //
                            *tree[counter]=tempQuad;
                            counter++;
                            nextID = i;
                        }
                    }
                    //test if have just one colliding
                    if(counter==1u){
                        //select the next
                        (*this->selectedPointer) = temp = temp->getQuad(nextID);
                        *tree[1u] = &(*this->treeNULLPointer);
                        *tree[2u] = &(*this->treeNULLPointer);
                        *tree[3u] = &(*this->treeNULLPointer);
                    }
                    else if(counter==4u){
                        //select only the temp
                        (*this->selectedPointer) = temp;
                        *tree[1u] = &(*this->treeNULLPointer);
                        *tree[2u] = &(*this->treeNULLPointer);
                        *tree[3u] = &(*this->treeNULLPointer);
                        break;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        this->runUpdateGets(rect);
        if(ret){
            ret = (bool)(*this->treeTempPointer)->size();
        }
        return ret;
    }

    //clean the tree
    void cleanWithRect(edk::rectf32 rect,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        edk::rectf32 rectTemp = edk::rectf32(rect.origin.x - (rect.size.width*0.5f),
                                             rect.origin.y - (rect.size.height*0.5f),
                                             rect.origin.x + (rect.size.width*0.5f),
                                             rect.origin.y + (rect.size.height*0.5f)
                                             );
        this->releaseTreeTemp();
        (*this->rootPointer).clean();
        (*this->rootPointer).setTree(this->newTree());
        (*this->rootPointer).origin = rectTemp.origin;
        (*this->rootPointer).size = rectTemp.size;
        (*this->treeNULLPointer).clean();
        (*this->treeNULLPointer).setTree(this->newTree());
        (*this->treeNULLPointer).origin = rectTemp.origin;
        (*this->treeNULLPointer).size = rectTemp.size;
        (*this->selectedPointer)=&(*this->treeNULLPointer);
        (*this->selected1Pointer) = &(*this->treeNULLPointer);
        (*this->selected2Pointer) = &(*this->treeNULLPointer);
        (*this->selected3Pointer) = &(*this->treeNULLPointer);
        //GETS
        if((*this->treeTempPointer)!=&(*this->treeValuesUpdatePointer)){
            delete (*this->treeTempPointer);
        }
        (*this->treeValuesUpdatePointer).clean();
        //create a new tree
        (*this->treeTempPointer) = this->newTree();
        if(!(*this->treeTempPointer)){
            (*this->treeTempPointer) = &(*this->treeValuesUpdatePointer);
        }
        //REMOVED
        (*this->treeOutsidePointer).clean();

        (*this->treeGetsPointer).clean();

        this->minimumQuadSize=minimumQuadSize;
    }

    void cleanAndSetRectangleFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
        this->setRectFromTree(tree);
    }

    //clean the tree
    void cleanWithRectPoints(edk::rectf32 rect,edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->releaseTreeTemp();
        (*this->rootPointer).clean();
        (*this->rootPointer).setTree(this->newTree());
        (*this->rootPointer).origin = rect.origin;
        (*this->rootPointer).size = rect.size;
        (*this->treeNULLPointer).clean();
        (*this->treeNULLPointer).setTree(this->newTree());
        (*this->treeNULLPointer).origin = rect.origin;
        (*this->treeNULLPointer).size = rect.size;
        (*this->selectedPointer)=&(*this->treeNULLPointer);
        (*this->selected1Pointer) = &(*this->treeNULLPointer);
        (*this->selected2Pointer) = &(*this->treeNULLPointer);
        (*this->selected3Pointer) = &(*this->treeNULLPointer);
        //GETS
        if((*this->treeTempPointer)!=&(*this->treeValuesUpdatePointer)){
            delete (*this->treeTempPointer);
        }
        (*this->treeValuesUpdatePointer).clean();
        //create a new tree
        (*this->treeTempPointer) = this->newTree();
        if(!(*this->treeTempPointer)){
            (*this->treeTempPointer) = &(*this->treeValuesUpdatePointer);
        }
        //REMOVED
        (*this->treeOutsidePointer).clean();

        (*this->treeGetsPointer).clean();

        this->minimumQuadSize=minimumQuadSize;
    }
    void clean(edk::float32 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(edk::rectf32(0,0,1,1),minimumQuadSize);
    }

    void cleanAndSetRectanglePointsFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
        this->setRectPointsFromTree(tree);
    }

    void forceOutAll(){
        edk::uint32 size;
        typeTemplate temp;
        size = (*this->treeGetsPointer).size();
        for(edk::uint32 i=0u;i<size;i++){
            temp = (*this->treeGetsPointer).getElementInPosition(0u);
            if(temp){
                if((*this->treeGetsPointer).remove(temp)){
                    ///RUN GETOUT
                    this->elementGetOut(temp);
                    (*this->treeTempPointer)->remove(temp);
                    (*this->treeOutsidePointer).add(temp);
                }
            }
        }
        (*this->treeTempPointer)->clean();
    }

    //SELECTED FUNCTIONS
    bool haveSelected(){
        if((*this->selectedPointer)
                && (*this->selectedPointer)!=&(*this->treeNULLPointer)
                && (*this->selectedPointer) != &(*this->rootPointer)
                ){
            return true;
        }
        return false;
    }
    edk::uint32 selectedGetTreeSize(){
        return (*this->treeTempPointer)->size();
    }
    typeTemplate selectedGetElementInPosition(edk::uint32 position){
        return (*this->treeTempPointer)->getElementInPosition(position);
    }
    edk::vector::BinaryTree<typeTemplate>* selectedGetTreePointer(){
        return (*this->treeTempPointer);
    }
    //Load the elements
    virtual void selectedLoad(){
        (*this->treeTempPointer)->load();
    }
    //Unload the elements
    virtual void selectedUnload(){
        (*this->treeTempPointer)->unload();
    }
    //Print the elements
    virtual void selectedPrint(){
        (*this->treeTempPointer)->print();
    }
    //render the elements
    virtual void selectedRender(){
        (*this->treeTempPointer)->render();
    }
    virtual void selectedRenderWire(){
        (*this->treeTempPointer)->renderWire();
    }
    //draw the elements
    virtual void selectedDraw(){
        (*this->treeTempPointer)->draw();
    }
    virtual void selectedDrawWire(){
        (*this->treeTempPointer)->drawWire();
    }
    //update the elements
    virtual void selectedUpdate(){
        (*this->treeTempPointer)->update();
    }

    void drawQuads(){
#if defined(EDK_QUADTREE_GU)
        //
        edk::GU::guColor4f32(this->color);
        edk::GU::guPushMatrix();
        edk::GU::guBegin(GU_LINES);
        (*this->rootPointer).drawQUADS();
        edk::GU::guEnd();
        edk::GU::guPopMatrix();
#endif
    }
    edk::color4f32 color;

protected:
    //test if the object is inside the leaf
    virtual bool isElementInside(typeTemplate ,edk::vec2f32 ,edk::vec2f32 ){
        return false;
    }
    //test if the element is just colliding
    virtual bool isElementColliding(typeTemplate ,edk::vec2f32 ,edk::vec2f32 ){
        return false;
    }
    //returh the rectangle of the element
    virtual edk::rectf32 getElementRectangle(typeTemplate ){
        return edk::rectf32(0,0,1,1);
    }
    //function to create a new tree
    virtual edk::vector::BinaryTree<typeTemplate>* newTree(){
        return new edk::vector::BinaryTree<typeTemplate>;
    }
    virtual void elementGetIn(typeTemplate){
        //elementGetIn
    }
    virtual void elementUpdating(typeTemplate){
        //elementUpdating
    }
    virtual void elementGetOut(typeTemplate){
        //elementGetOut
    }

    //get the quadtree binaryTreePointer
    edk::vector::BinaryTree<typeTemplate>* getTreePointer(){return (*this->treeTempPointer); }

private:
    //quadtree Root
    edk::vector::QuadLeaf32<typeTemplate> root;
    edk::vector::QuadLeaf32<typeTemplate>* rootPointer;
    edk::vector::QuadLeaf32<typeTemplate>* selected;
    edk::vector::QuadLeaf32<typeTemplate>** selectedPointer;
    edk::vector::QuadLeaf32<typeTemplate>* selected1;
    edk::vector::QuadLeaf32<typeTemplate>** selected1Pointer;
    edk::vector::QuadLeaf32<typeTemplate>* selected2;
    edk::vector::QuadLeaf32<typeTemplate>** selected2Pointer;
    edk::vector::QuadLeaf32<typeTemplate>* selected3;
    edk::vector::QuadLeaf32<typeTemplate>** selected3Pointer;
    //binary tree to test if the objects getIn or getOut
    edk::vector::BinaryTree<typeTemplate>  treeGets;
    edk::vector::BinaryTree<typeTemplate>*  treeGetsPointer;
    edk::vector::BinaryTree<typeTemplate>  treeOutside;
    edk::vector::BinaryTree<typeTemplate>*  treeOutsidePointer;
    edk::vector::BinaryTree<typeTemplate>  treeValuesUpdate;
    edk::vector::BinaryTree<typeTemplate>*  treeValuesUpdatePointer;
    edk::vector::BinaryTree<typeTemplate>* treeTemp;
    edk::vector::BinaryTree<typeTemplate>** treeTempPointer;
    //three NULL
    edk::vector::QuadLeaf32<typeTemplate> treeNULL;
    edk::vector::QuadLeaf32<typeTemplate>* treeNULLPointer;

    bool canObjectIn;

    //minimumQuadSize
    edk::float32 minimumQuadSize;
    edk::float32* minimumQuadSizePointer;

    //minimun elements in a QUAD
    edk::uint32 minimumElementInQuads;
    edk::uint32* minimumElementInQuadsPointer;

    bool isRectInside(edk::rectf32 rect,edk::vec2f32 point1,edk::vec2f32 point2){
        if(rect.origin.x >= point1.x
                &&
                rect.origin.y >= point1.y
                &&
                rect.origin.x <= point2.x
                &&
                rect.origin.y <= point2.y
                &&
                rect.size.width >= point1.x
                &&
                rect.size.height >= point1.y
                &&
                rect.size.width <= point2.x
                &&
                rect.size.height <= point2.y
                ){
            return true;
        }
        return false;
    }
    bool isRectColliding(edk::rectf32 rect,edk::vec2f32 point1,edk::vec2f32 point2){
        if(point1.x <= rect.origin.x + rect.size.width
                &&
                point2.x>= rect.origin.x
                &&
                point1.y <= rect.origin.y + rect.size.height
                &&
                point2.y >= rect.origin.y
                ){
            return true;
        }
        return false;
    }
    bool isRectPointsColliding(edk::rectf32 rect,edk::vec2f32 point1,edk::vec2f32 point2){
        if(point1.x <= rect.size.width
                &&
                point2.x>= rect.origin.x
                &&
                point1.y <= rect.size.height
                &&
                point2.y >= rect.origin.y
                ){
            return true;
        }
        return false;
    }
    bool isPointInside(edk::vec2f32 point,edk::vec2f32 point1,edk::vec2f32 point2){
        if(point.x >= point1.x
                &&
                point.y >= point1.y
                &&
                point.x < point2.x
                &&
                point.y < point2.y
                ){
            return true;
        }
        return false;
    }
    //update the gets
    void runUpdateGets(edk::rectf32 rect){
#if defined(EDK_DONT_USE_QUADTREE)
        return;
#endif
        edk::vector::BinaryTree<typeTemplate>* tree[edkQuadSelectedSize];
        tree[0u] = (*this->selectedPointer)->getTreePointer();
        tree[1u] = (*this->selected1Pointer)->getTreePointer();
        tree[2u] = (*this->selected2Pointer)->getTreePointer();
        tree[3u] = (*this->selected3Pointer)->getTreePointer();
        /*if(tree && tree2 && tree3)*/{
            //first remove the last objects
            edk::uint32 size;
            typeTemplate temp;
            bool decrement = false;

            //add or remove elements from the trees
            size = (*this->treeGetsPointer).size();
            for(edk::uint32 i=0u;i<size;i++){
                if(decrement){
                    decrement=false;
                    i--;
                    size--;
                }
                temp = (*this->treeGetsPointer).getElementInPosition(i);

                if(this->isElementColliding(temp,
                                            edk::vec2f32(rect.origin.x,rect.origin.y),
                                            edk::vec2f32(rect.size.width,rect.size.height)
                                            )
                        ){
                    if(this->canObjectIn){
                        //test if was in the treeOutside
                        if((*this->treeOutsidePointer).haveElement(temp)){
                            //remove the element from outside
                            if((*this->treeOutsidePointer).remove(temp)){
                                this->elementGetIn(temp);
                                (*this->treeTempPointer)->add(temp);
                            }
                        }
                    }
                }
                else{
                    for(edk::uint8 t=0u;t<edkQuadSelectedSize;t++){
                        if(tree[t]->haveElement(temp)){
                            //test if wasn't in the treeOutside
                            if(!(*this->treeOutsidePointer).haveElement(temp)){
                                //add the temp into the removed tree
                                if((*this->treeOutsidePointer).add(temp)){
                                    //element is out of the rectangle
                                    ///RUN GETOUT
                                    this->elementGetOut(temp);
                                    (*this->treeTempPointer)->remove(temp);
                                }
                            }
                        }
                        else{
                            if((*this->treeGetsPointer).remove(temp)){
                                ///RUN GETOUT
                                this->elementGetOut(temp);
                                (*this->treeTempPointer)->remove(temp);
                                (*this->treeOutsidePointer).add(temp);
                                //decrement
                                decrement=true;
                            }
                        }
                    }
                }
            }
            //update the elements
            size = (*this->treeTempPointer)->size();
            for(edk::uint32 i=0u;i<size;i++){
                this->elementUpdating((*this->treeTempPointer)->getElementInPosition(i));
            }
            //add new elements.
            for(edk::uint8 t=0u;t<edkQuadSelectedSize;t++){
                size = tree[t]->size();
                for(edk::uint32 i=0u;i<size;i++){
                    temp = tree[t]->getElementInPosition(i);
                    //test if have the object inside the temp
                    if(!(*this->treeGetsPointer).haveElement(temp)){
                        //add the element
                        if(this->isElementColliding(temp,
                                                    edk::vec2f32(rect.origin.x,rect.origin.y),
                                                    edk::vec2f32(rect.size.width,rect.size.height)
                                                    )){
                            if(this->canObjectIn){
                                if((*this->treeGetsPointer).add(temp)){
                                    ///RUN GETIN
                                    this->elementGetIn(temp);
                                    (*this->treeTempPointer)->add(temp);
                                    (*this->treeOutsidePointer).remove(temp);
                                }
                            }
                        }
                        else{
                            //else add in to the outside
                            (*this->treeOutsidePointer).add(temp);
                        }
                    }
                }
            }
        }
    }
    void runUpdateGets(){
#if defined(EDK_DONT_USE_QUADTREE)
        return;
#endif
        edk::vector::BinaryTree<typeTemplate>* tree[edkQuadSelectedSize];
        tree[0u] = (*this->selectedPointer)->getTreePointer();
        tree[1u] = (*this->selected1Pointer)->getTreePointer();
        tree[2u] = (*this->selected2Pointer)->getTreePointer();
        tree[3u] = (*this->selected3Pointer)->getTreePointer();
        /*if(tree && tree2 && tree3)*/{
            //first remove the last objects
            edk::uint32 size;
            typeTemplate temp;
            bool decrement = false;
            size = (*this->treeGetsPointer).size();
            for(edk::uint32 i=0u;i<size;i++){
                if(decrement){
                    decrement=false;
                    i--;
                    size--;
                }
                temp = (*this->treeGetsPointer).getElementInPosition(i);
                //test if DON'T have the object inside the temp
                for(edk::uint8 t=0u;t<edkQuadSelectedSize;t++){
                    if(!tree[t]->haveElement(temp)){
                        //remove the object from the treeGets
                        if((*this->treeGetsPointer).remove(temp)){
                            //decrement
                            decrement=true;

                            ///RUN GETOUT
                            this->elementGetOut(temp);
                            (*this->treeTempPointer)->remove(temp);
                        }
                    }
                }
            }
            size = (*this->treeGetsPointer).size();
            for(edk::uint32 i=0u;i<size;i++){
                this->elementUpdating((*this->treeGetsPointer).getElementInPosition(i));
            }
            for(edk::uint8 t=0u;t<edkQuadSelectedSize;t++){
                size = tree[t]->size();
                for(edk::uint32 i=0u;i<size;i++){
                    temp = tree[t]->getElementInPosition(i);
                    //test if have the object inside the temp
                    if(!(*this->treeGetsPointer).haveElement(temp)){
                        //add the element
                        if((*this->treeGetsPointer).add(temp)){
                            ///RUN GETIN
                            this->elementGetIn(temp);
                            (*this->treeTempPointer)->add(temp);
                        }
                    }
                }
            }
        }
    }
    void releaseTreeTemp(){
        edk::uint32 size = (*this->treeTempPointer)->size();
        for(edk::uint32 i=0u;i<size;i++){
            this->elementGetOut((*this->treeTempPointer)->getElementInPosition(i));
        }
        (*this->treeTempPointer)->clean();
    }
private:
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
//QUADTREE64
template <class typeTemplate>
class QuadTree64 : public edk::vector::BinaryTreeCallback<typeTemplate>{
public:
    QuadTree64(){
        this->classThis=NULL;
        this->Constructor();
    }
    virtual ~QuadTree64(){
        this->Destructor();
    }

    void Constructor(){
        edk::vector::BinaryTreeCallback<typeTemplate>::Constructor();
        if(this->classThis!=this){
            this->classThis=this;

            this->root.Constructor();
            this->treeGets.Constructor();
            this->treeOutside.Constructor();
            this->treeValuesUpdate.Constructor();
            this->treeNULL.Constructor();

            this->selected = &this->treeNULL;
            this->selected1 = &this->treeNULL;
            this->selected2 = &this->treeNULL;
            this->selected3 = &this->treeNULL;
            this->treeTemp = &this->treeValuesUpdate;

            this->rootPointer = &this->root;
            this->treeGetsPointer = &this->treeGets;
            this->treeOutsidePointer = &this->treeOutside;
            this->treeValuesUpdatePointer = &this->treeValuesUpdate;
            this->treeNULLPointer = &this->treeNULL;

            this->selectedPointer = &this->selected;
            this->selected1Pointer = &this->selected1;
            this->selected2Pointer = &this->selected2;
            this->selected3Pointer = &this->selected3;
            this->treeTempPointer = &this->treeTemp;

            this->canObjectIn=true;

            //

            this->cleanWithRectPoints(edk::rectf64(0,0,1,1));
            this->minimumElementInQuads=1u;
            this->setMinimumElementInQuads(0u);
        }
    }
    void Destructor(){
        if(this->classThis==this){
            this->classThis=NULL;
            //can destruct the class
            //the destructor don't call the getOut functions because is possible the element don't exist
            this->root.clean();
            this->treeNULL.clean();
            if(this->treeTemp!=&this->treeValuesUpdate){
                this->treeTemp->clean();
                delete this->treeTemp;
            }
            this->treeValuesUpdate.clean();
            this->treeGets.clean();
            this->treeOutside.clean();

            this->root.Destructor();
            this->treeGets.Destructor();
            this->treeOutside.Destructor();
            this->treeValuesUpdate.Destructor();
            this->treeNULL.Destructor();
        }
        edk::vector::BinaryTreeCallback<typeTemplate>::Destructor();
    }

    //set if can add an object in the scene
    void setCanAddObjectsInScene(bool canAdd){
        this->canObjectIn=canAdd;
    }
    void canAddObjectInScene(){
        this->setCanAddObjectsInScene(true);
    }
    void cantAddObjectInScene(){
        this->setCanAddObjectsInScene(false);
    }
    bool getCanAddObjectsInScene(){
        return this->canObjectIn;
    }

    //set the minimunQuadSize
    bool setMinimumQuadSize(edk::float64 minimumQuadSize){
        if(minimumQuadSize>0.f){
            this->minimumQuadSize = minimumQuadSize;
            return true;
        }
        this->minimumQuadSize=edkQuadMinimumSize;
        return false;
    }
    edk::float64 getMinimumQuadSize(){
        return this->minimumQuadSize;
    }
    //set the minimunObjectsInQuads
    bool setMinimumElementInQuads(edk::uint64 minimumElementInQuads){
        if(minimumElementInQuads){
            this->minimumElementInQuads=minimumElementInQuads;
            return true;
        }
        //else set 1
        this->minimumElementInQuads=1u;
        return false;
    }
    edk::uint64 getMinimumElementInQuads(){
        return this->minimumElementInQuads;
    }
    //set the quadtree position and size
    void setPositionAndSize(edk::float64 x,edk::float64 y,edk::float64 width,edk::float64 height,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->setRect(edk::rectf64(x,y,width + x,height + y),minimumQuadSize);
    }
    void setPositionAndSize(edk::vec2f64 position,edk::size2f64 size,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->setRect(edk::rectf64(position.x,position.y,size.width + position.x,size.height + position.y),minimumQuadSize);
    }
    void setPoints(edk::float64 position1X,edk::float64 position1Y,edk::float64 position2X,edk::float64 position2Y,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->setRect(edk::rectf64(position1X,position1Y,position2X,position2Y),minimumQuadSize);
    }
    void setPoints(edk::vec2f64 point1,edk::vec2f64 point2,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->setRect(edk::rectf64(point1.x,point1.y,point2.x,point2.y),minimumQuadSize);
    }
    //set the quadTree rectangle
    void setRect(edk::rectf64 rect,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(rect);
        this->minimumQuadSize=minimumQuadSize;
    }
    void setRect(edk::vec2f64 position1,edk::vec2f64 position2,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(edk::rectf64(position1.x,position1.y,position2.x,position2.y));
        this->minimumQuadSize=minimumQuadSize;
    }
    void setRect(edk::float64 pos1X,edk::float64 pos1Y,edk::float64 pos2X,edk::float64 pos2Y,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(edk::rectf64(pos1X,pos1Y,pos2X,pos2Y));
        this->minimumQuadSize=minimumQuadSize;
    }
    void setRectPoints(edk::rectf64 rect,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(rect);
        this->minimumQuadSize=minimumQuadSize;
    }
    void setRectPoints(edk::vec2f64 position1,edk::vec2f64 position2,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(edk::rectf64(position1.x,position1.y,position2.x,position2.y));
        this->minimumQuadSize=minimumQuadSize;
    }
    void setRectPoints(edk::float64 pos1X,edk::float64 pos1Y,edk::float64 pos2X,edk::float64 pos2Y,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(edk::rectf64(pos1X,pos1Y,pos2X,pos2Y));
        this->minimumQuadSize=minimumQuadSize;
    }
    //return the quadtree rectangle
    edk::rectf64 getRectangle(){
        return edk::rectf64((*this->rootPointer).origin.x+((*this->rootPointer).size.width*0.5f),
                            (*this->rootPointer).origin.y+((*this->rootPointer).size.height*0.5f),
                            (*this->rootPointer).origin.x-((*this->rootPointer).size.width*0.5f),
                            (*this->rootPointer).origin.y-((*this->rootPointer).size.height*0.5f)
                            );
    }
    edk::rectf64 getRectanglePoints(){
        return edk::rectf64((*this->rootPointer).origin,(*this->rootPointer).size);
    }
    void incrementRect(edk::rectf64 rect){
        if(rect.origin.x > (*this->rootPointer).origin.x){
            rect.origin.x = (*this->rootPointer).origin.x;
        }
        if(rect.origin.y > (*this->rootPointer).origin.y){
            rect.origin.y = (*this->rootPointer).origin.y;
        }
        if(rect.size.width < (*this->rootPointer).size.width){
            rect.size.width = (*this->rootPointer).size.width;
        }
        if(rect.size.height < (*this->rootPointer).size.height){
            rect.size.height = (*this->rootPointer).size.height;
        }
        if(rect.origin.x > (*this->treeNULLPointer).origin.x){
            rect.origin.x = (*this->treeNULLPointer).origin.x;
        }
        if(rect.origin.y > (*this->treeNULLPointer).origin.y){
            rect.origin.y = (*this->treeNULLPointer).origin.y;
        }
        if(rect.size.width < (*this->treeNULLPointer).size.width){
            rect.size.width = (*this->treeNULLPointer).size.width;
        }
        if(rect.size.height < (*this->treeNULLPointer).size.height){
            rect.size.height = (*this->treeNULLPointer).size.height;
        }
        this->cleanWithRectPoints(rect);
    }
    void incrementRect(edk::vec2f64 position,edk::size2f64 size){
        this->incrementRect(edk::rectf64(position,size));
    }
    void incrementRect(edk::float64 positionX,edk::float64 positionY,edk::float64 width,edk::float64 height){
        this->incrementRect(edk::rectf64(positionX,positionY,width,height));
    }

    //add a object
    bool add(typeTemplate value, edk::uint64 depthLimit=0xFFFFFFFF){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        //nexts quads to be tested
        edk::vector::Queue<edk::vector::QuadLeaf64<typeTemplate>*> nexts;
        edk::vector::QuadLeaf64<typeTemplate>* temp = &(*this->rootPointer);
        edk::vector::QuadLeaf64<typeTemplate>* temp2 = &(*this->rootPointer);
        edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
        edk::vector::BinaryTree<typeTemplate>* tree;
        edk::uint64 size = 0u;
        typeTemplate valueTemp;
        bool ret=false;
        bool push[edkQuadSelectedSize];
        edk::vector::QuadLeaf64<typeTemplate>* goInside[edkQuadSelectedSize];
        edk::uint8 k;
        edk::uint64 counterIn,counterQuads;

        //test if the value is inside the root
        if(this->isElementInside(value,
                                 edk::vec2f64(temp->origin.x,
                                              temp->origin.y
                                              ),
                                 edk::vec2f64(temp->size.width,
                                              temp->size.height
                                              )
                                 )
                ){
            //add the value in to the temp
            temp->addToTree(value);
            //add the root inside the queue
            nexts.pushBack(temp);
            while(temp){
                //get the text from the queue
                if(nexts.size()){
                    temp2 = nexts.popFront();
                }
                else{
                    temp2=NULL;
                }

                if(temp2){
                    temp=temp2;
                    ret=true;

                    //test if the temp have more than 1 value
                    if(temp->getTreeSize()>this->minimumElementInQuads){

                        if((temp->depth+1u)>=depthLimit){
                            //have the limit
                            break;
                        }

                        //create new quads
                        if(!temp->haveQuads()){
                            //create the trees
                            edk::vector::BinaryTree<typeTemplate>* tree1 = this->newTree();
                            if(tree1){
                                edk::vector::BinaryTree<typeTemplate>* tree2 = this->newTree();
                                if(tree2){
                                    edk::vector::BinaryTree<typeTemplate>* tree3 = this->newTree();
                                    if(tree3){
                                        edk::vector::BinaryTree<typeTemplate>* tree4 = this->newTree();
                                        if(tree4){
                                            //create new quads
                                            if(temp->newQuads(tree1,
                                                              tree2,
                                                              tree3,
                                                              tree4,
                                                              this->minimumQuadSize
                                                              )){
                                                //
                                                tree1=tree2=tree3=tree4=NULL;
                                            }
                                            if(tree4){
                                                delete tree4;
                                            }
                                        }
                                        if(tree3){
                                            delete tree3;
                                        }
                                    }
                                    if(tree2){
                                        delete tree2;
                                    }
                                }
                                if(tree1){
                                    delete tree1;
                                }
                            }
                        }



                        //test if have the quads
                        if(temp->haveQuads()){
                            push[0u]=false;
                            push[1u]=false;
                            push[2u]=false;
                            push[3u]=false;
                            goInside[0u]=NULL;
                            goInside[1u]=NULL;
                            goInside[2u]=NULL;
                            goInside[3u]=NULL;
                            counterIn=0u;
                            //get the temp tree
                            tree = temp->getTreePointer();
                            if(tree){
                                size = tree->size();
                                k=0u;
                                //test if the quads are new
                                if(temp->getQuadsSize()<size-1u){
                                    //else add the objects
                                    for(edk::uint64 j=0u;j<size;j++){
                                        valueTemp = tree->getElementInPosition(j);
                                        counterQuads=0u;
                                        for(edk::uint8 i=0u;i<4u;i++){
                                            tempQuad = temp->getQuad(i);
                                            //test if is colliding with the quads to just add in the tree
                                            if(this->isElementColliding(valueTemp,
                                                                        edk::vec2f64(tempQuad->origin.x,
                                                                                     tempQuad->origin.y
                                                                                     ),
                                                                        edk::vec2f64(tempQuad->size.width,
                                                                                     tempQuad->size.height
                                                                                     )
                                                                        )
                                                    ){
                                                counterQuads++;
                                                if(!tempQuad->haveInTree(valueTemp)){
                                                    tempQuad->addToTree(valueTemp);
                                                }
                                                if(!push[i]){
                                                    //add the quad into the queue
                                                    //nexts.pushBack(tempQuad);
                                                    goInside[k]=tempQuad;
                                                    k++;
                                                    push[i]=true;
                                                }
                                            }
                                        }
                                        if(counterQuads>=4u){
                                            counterIn++;
                                        }
                                    }
                                    //test if need go into the nexts quads
                                    if(counterIn<size){
                                        bool goPush=true;
                                        //test if have nextQuads
                                        for(edk::uint8 i=0u;i<4u;i++){
                                            if(goInside[i]){
                                                nexts.pushBack(goInside[i]);
                                                goPush=false;
                                            }
                                        }
                                        if(goPush){
                                            //go to the father
                                            temp = temp->getFather();
                                        }
                                    }
                                    else{
                                        //else go to the father
                                        temp = temp->getFather();
                                    }
                                }
                                else{
                                    //add just the first
                                    valueTemp = value;
                                    counterQuads=0u;
                                    for(edk::uint8 i=0u;i<4u;i++){
                                        tempQuad = temp->getQuad(i);
                                        //test if is colliding with the quads to just add in the tree
                                        if(this->isElementColliding(valueTemp,
                                                                    edk::vec2f64(tempQuad->origin.x,
                                                                                 tempQuad->origin.y
                                                                                 ),
                                                                    edk::vec2f64(tempQuad->size.width,
                                                                                 tempQuad->size.height
                                                                                 )
                                                                    )
                                                ){
                                            counterQuads++;
                                            if(!tempQuad->haveInTree(valueTemp)){
                                                tempQuad->addToTree(valueTemp);
                                            }
                                            if(!push[i]){
                                                //add the quad into the queue
                                                //nexts.pushBack(tempQuad);
                                                goInside[k]=tempQuad;
                                                k++;
                                                push[i]=true;
                                            }
                                        }
                                    }
                                    if(counterQuads<4u){
                                        bool goPush=true;
                                        //test if have nextQuads
                                        for(edk::uint8 i=0u;i<4u;i++){
                                            if(goInside[i]){
                                                nexts.pushBack(goInside[i]);
                                                goPush=false;
                                            }
                                        }
                                        if(goPush){
                                            //go to the father
                                            temp = temp->getFather();
                                        }
                                    }
                                    else{
                                        //else go to the father
                                        temp = temp->getFather();
                                    }
                                }
                            }
                        }
                        else{
                            //else go to the father
                            temp = temp->getFather();
                        }
                    }
                    else{
                        //else go to the father
                        temp = temp->getFather();
                    }
                }
                else{
                    //else go to the father
                    temp = temp->getFather();
                }
            }
        }
        nexts.clean();
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebugNoPosition(this,this->generateDebugValue(&value),ret);
#endif
        return ret;
    }
    //add objects from a tree
    bool addFromTree(edk::vector::BinaryTree<typeTemplate>* tree, edk::uint64 depthLimit=0xFFFFFFFF){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(tree){
            bool ret=true;
            edk::uint64 size = tree->size();
            for(edk::uint64 i=0u;i<size;i++){
                if(!this->add(tree->getElementInPosition(i),depthLimit)){
                    ret=false;
                }
            }
            return ret;
        }
        return false;
    }
    bool setRectFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(tree){
            edk::uint64 size = tree->size();
            edk::rectf64 rectangle = edk::rectf64(0,0,1,1);
            edk::rectf64 rectanglePoints = edk::rectf64(0,0,1,1);
            edk::rectf64 rectTemp;
            edk::rectf64 rectTempPoints;
            if(size){
                rectangle = this->getElementRectangle(tree->getElementInPosition(0u));
                rectanglePoints = edk::rectf64(rectangle.origin.x - rectangle.size.width,
                                               rectangle.origin.y - rectangle.size.height,
                                               rectangle.origin.x + rectangle.size.width,
                                               rectangle.origin.y + rectangle.size.height
                                               );
                for(edk::uint64 i=1u;i<size;i++){
                    rectTemp = this->getElementRectangle(tree->getElementInPosition(i));
                    rectTempPoints = edk::rectf64(rectTemp.origin.x - rectTemp.size.width,
                                                  rectTemp.origin.y - rectTemp.size.height,
                                                  rectTemp.origin.x + rectTemp.size.width,
                                                  rectTemp.origin.y + rectTemp.size.height
                                                  );
                    //test if need to update the rectangle
                    if(rectanglePoints.origin.x >= rectTempPoints.origin.x){
                        rectanglePoints.origin.x = rectTempPoints.origin.x;
                    }
                    if(rectanglePoints.origin.y >= rectTempPoints.origin.y){
                        rectanglePoints.origin.y = rectTempPoints.origin.y;
                    }
                    if(rectanglePoints.size.width <= rectTempPoints.size.width){
                        rectanglePoints.size.width = rectTempPoints.size.width;
                    }
                    if(rectanglePoints.size.height <= rectTempPoints.size.height){
                        rectanglePoints.size.height = rectTempPoints.size.height;
                    }
                }
                //increment the size of the rectangle
                rectanglePoints.origin.x -= (rectanglePoints.size.width - rectanglePoints.origin.x)*0.025f;
                rectanglePoints.origin.y -= (rectanglePoints.size.height - rectanglePoints.origin.y)*0.025f;
                rectanglePoints.size.width += (rectanglePoints.size.width - rectanglePoints.origin.x)*0.025f;
                rectanglePoints.size.height += (rectanglePoints.size.height - rectanglePoints.origin.y)*0.025f;
                //set the rectangle
                this->setRect(rectanglePoints);
                return true;
            }
            this->setRect(rectanglePoints);
        }
        return false;
    }
    bool incrementRectFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(tree){
            edk::uint64 size = tree->size();
            edk::rectf64 rectangle = edk::rectf64(0,0,1,1);
            edk::rectf64 rectanglePoints = edk::rectf64(0,0,1,1);
            edk::rectf64 rectTemp;
            edk::rectf64 rectTempPoints;
            if(size){
                rectangle = this->getElementRectangle(tree->getElementInPosition(0u));
                rectanglePoints = edk::rectf64(rectangle.origin.x - rectangle.size.width,
                                               rectangle.origin.y - rectangle.size.height,
                                               rectangle.origin.x + rectangle.size.width,
                                               rectangle.origin.y + rectangle.size.height
                                               );
                for(edk::uint64 i=0u;i<size;i++){
                    rectTemp = this->getElementRectangle(tree->getElementInPosition(i));
                    rectTempPoints = edk::rectf64(rectTemp.origin.x - rectTemp.size.width,
                                                  rectTemp.origin.y - rectTemp.size.height,
                                                  rectTemp.origin.x + rectTemp.size.width,
                                                  rectTemp.origin.y + rectTemp.size.height
                                                  );
                    //test if need to update the rectangle
                    if(rectanglePoints.origin.x >= rectTempPoints.origin.x){
                        rectanglePoints.origin.x = rectTempPoints.origin.x;
                    }
                    if(rectanglePoints.origin.y >= rectTempPoints.origin.y){
                        rectanglePoints.origin.y = rectTempPoints.origin.y;
                    }
                    if(rectanglePoints.size.width <= rectTempPoints.size.width){
                        rectanglePoints.size.width = rectTempPoints.size.width;
                    }
                    if(rectanglePoints.size.height <= rectTempPoints.size.height){
                        rectanglePoints.size.height = rectTempPoints.size.height;
                    }
                    //increment the size of the rectangle
                    rectanglePoints.origin.x -= (rectanglePoints.size.width - rectanglePoints.origin.x)*0.025f;
                    rectanglePoints.origin.y -= (rectanglePoints.size.height - rectanglePoints.origin.y)*0.025f;
                    rectanglePoints.size.width += (rectanglePoints.size.width - rectanglePoints.origin.x)*0.025f;
                    rectanglePoints.size.height += (rectanglePoints.size.height - rectanglePoints.origin.y)*0.025f;
                }
                //set the rectangle
                this->incrementRect(rectanglePoints);
                return true;
            }
        }
        return false;
    }
    bool setRectAndAddFromTree(edk::vector::BinaryTree<typeTemplate>* tree, edk::uint64 depthLimit=0xFFFFFFFF){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(this->setRectFromTree(tree)){
            if(this->addFromTree(tree,depthLimit)){
                return true;
            }
        }
        return false;
    }
    bool setRectPointsFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(tree){
            edk::uint64 size = tree->size();
            edk::rectf64 rectangle = edk::rectf64(0,0,1,1);
            edk::rectf64 rectTemp;
            if(size){
                rectangle = this->getElementRectangle(tree->getElementInPosition(0u));
                for(edk::uint64 i=1u;i<size;i++){
                    rectTemp = this->getElementRectangle(tree->getElementInPosition(i));
                    //test if need to update the rectangle
                    if(rectangle.origin.x >= rectTemp.origin.x){
                        rectangle.origin.x = rectTemp.origin.x;
                    }
                    if(rectangle.origin.y >= rectTemp.origin.y){
                        rectangle.origin.y = rectTemp.origin.y;
                    }
                    if(rectangle.size.width <= rectTemp.size.width){
                        rectangle.size.width = rectTemp.size.width;
                    }
                    if(rectangle.size.height <= rectTemp.size.height){
                        rectangle.size.height = rectTemp.size.height;
                    }
                }
                //increment the size of the rectangle
                rectangle.origin.x -= (rectangle.size.width - rectangle.origin.x)*0.025f;
                rectangle.origin.y -= (rectangle.size.height - rectangle.origin.y)*0.025f;
                rectangle.size.width += (rectangle.size.width - rectangle.origin.x)*0.025f;
                rectangle.size.height += (rectangle.size.height - rectangle.origin.y)*0.025f;
                //set the rectangle
                this->setRect(rectangle);
                return true;
            }
            this->setRect(rectangle);
        }
        return false;
    }
    bool incrementRectPointsFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(tree){
            edk::uint64 size = tree->size();
            edk::rectf64 rectangle = edk::rectf64(0,0,1,1);
            edk::rectf64 rectTemp;
            if(size){
                rectangle = this->getElementRectangle(tree->getElementInPosition(0u));
                for(edk::uint64 i=0u;i<size;i++){
                    rectTemp = this->getElementRectangle(tree->getElementInPosition(i));
                    //test if need to update the rectangle
                    if(rectangle.origin.x >= rectTemp.origin.x){
                        rectangle.origin.x = rectTemp.origin.x;
                    }
                    if(rectangle.origin.y >= rectTemp.origin.y){
                        rectangle.origin.y = rectTemp.origin.y;
                    }
                    if(rectangle.size.width <= rectTemp.size.width){
                        rectangle.size.width = rectTemp.size.width;
                    }
                    if(rectangle.size.height <= rectTemp.size.height){
                        rectangle.size.height = rectTemp.size.height;
                    }
                    //increment the size of the rectangle
                    rectangle.origin.x -= (rectangle.size.width - rectangle.origin.x)*0.025f;
                    rectangle.origin.y -= (rectangle.size.height - rectangle.origin.y)*0.025f;
                    rectangle.size.width += (rectangle.size.width - rectangle.origin.x)*0.025f;
                    rectangle.size.height += (rectangle.size.height - rectangle.origin.y)*0.025f;
                }
                //set the rectangle
                this->incrementRect(rectangle);
                return true;
            }
        }
        return false;
    }
    void incrementRectPointsFromValue(typeTemplate value){
#if defined(EDK_DONT_USE_QUADTREE)
        return;
#endif
        edk::rectf64 rectangle = edk::rectf64(0,0,1,1);
        edk::rectf64 rectTemp;
        rectangle = this->getRectangle();
        rectTemp = this->getElementRectangle(value);
        //test if need to update the rectangle
        if(rectangle.origin.x >= rectTemp.origin.x){
            rectangle.origin.x = rectTemp.origin.x;
        }
        if(rectangle.origin.y >= rectTemp.origin.y){
            rectangle.origin.y = rectTemp.origin.y;
        }
        if(rectangle.size.width <= rectTemp.size.width){
            rectangle.size.width = rectTemp.size.width;
        }
        if(rectangle.size.height <= rectTemp.size.height){
            rectangle.size.height = rectTemp.size.height;
        }
        //increment the size of the rectangle
        rectangle.origin.x -= (rectangle.size.width - rectangle.origin.x)*0.025f;
        rectangle.origin.y -= (rectangle.size.height - rectangle.origin.y)*0.025f;
        rectangle.size.width += (rectangle.size.width - rectangle.origin.x)*0.025f;
        rectangle.size.height += (rectangle.size.height - rectangle.origin.y)*0.025f;

        //set the rectangle
        this->incrementRect(rectangle);
    }
    bool setRectPointsAndAddFromTree(edk::vector::BinaryTree<typeTemplate>* tree, edk::uint64 depthLimit=0xFFFFFFFF){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        if(this->setRectPointsFromTree(tree)){
            if(this->addFromTree(tree,depthLimit)){
                return true;
            }
        }
        return false;
    }
    //remove a value from de quadTree
    bool remove(typeTemplate value){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        bool ret=false;
        edk::vector::QuadLeaf64<typeTemplate>* temp = &(*this->rootPointer);
        edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
        bool deleteQuads;
        edk::uint8 cTemp=0u;
        //test if the value is inside the root
        if(this->isElementInside(value,
                                 edk::vec2f64(temp->origin.x,
                                              temp->origin.y
                                              ),
                                 edk::vec2f64(temp->size.width,
                                              temp->size.height
                                              )
                                 )
                ){
            temp->counter=0u;
            while(temp){
                //remove from it
                if(temp->haveInTree(value)){
                    temp->removeFromTree(value);
                    ret=true;
                }

                //search for the quads
                if(temp->haveQuads()){
                    if(temp->counter<4u){
                        if(this->isElementColliding(value,
                                                    edk::vec2f64(temp->origin.x,
                                                                 temp->origin.y
                                                                 ),
                                                    edk::vec2f64(temp->size.width,
                                                                 temp->size.height
                                                                 )
                                                    )
                                ){
                            cTemp = temp->counter;
                            temp->counter++;
                            temp=temp->getQuad(cTemp);
                            temp->counter=0u;
                        }
                        else{
                            temp->counter=4u;
                        }
                    }
                    else{
                        deleteQuads=true;
                        //test if need delete the quads
                        for(edk::uint8 i=0u;i<4u;i++){
                            tempQuad = temp->getQuad(i);
                            //test if the tempQuad have some inside the tree
                            if(tempQuad->getTreeSize()){
                                //don't delete the quads
                                deleteQuads=false;
                            }
                        }
                        //test if need delete the quads
                        if(deleteQuads){
                            temp->deleteQuads();
                        }

                        temp=temp->getFather();
                    }
                }
                else{
                    temp=temp->getFather();
                }
            }
        }
        if((*this->treeTempPointer)->haveElement(value)){
            ret=true;
            if((*this->treeTempPointer)->remove(value)){
                this->elementGetOut(value);
            }
        }
        if((*this->treeOutsidePointer).haveElement(value)){
            ret=true;
            if((*this->treeOutsidePointer).remove(value)){
                //
            }
        }
        if((*this->treeGetsPointer).haveElement(value)){
            ret=true;
            if((*this->treeGetsPointer).remove(value)){
                //
            }
        }
#if defined(EDK_DEBUG_VECTOR)
        edkWriteClassDebugNoPosition(this,this->generateDebugValue(&value),ret);
#endif
        return ret;
    }

    //select a leaf
    virtual bool selectLeafWithValue(typeTemplate value){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        (*this->selectedPointer) = &(*this->treeNULLPointer);
        edk::vector::QuadLeaf64<typeTemplate>** tree[edkQuadSelectedSize];
        tree[0u] = &(*this->selectedPointer);
        tree[1u] = &(*this->selected1Pointer);
        tree[2u] = &(*this->selected2Pointer);
        tree[3u] = &(*this->selected3Pointer);
        bool ret=false;
        if(this->isRectColliding(getElementRectangle(value),
                                 edk::vec2f64((*this->rootPointer).origin.x,
                                              (*this->rootPointer).origin.y
                                              ),
                                 edk::vec2f64((*this->rootPointer).size.width,
                                              (*this->rootPointer).size.height
                                              )
                                 )
                ){
            (*this->selectedPointer) = &(*this->rootPointer);
            edk::vector::QuadLeaf64<typeTemplate>* temp = &(*this->rootPointer);
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
            while(temp){
                counter=0u;
                //test the collision with all quads
                if(temp->haveQuads()){
                    *tree[1u] = &(*this->treeNULLPointer);
                    *tree[2u] = &(*this->treeNULLPointer);
                    *tree[3u] = &(*this->treeNULLPointer);
                    for(edk::uint8 i=0u;i<4u;i++){
                        tempQuad = temp->getQuad(i);
                        if(this->isElementInside(value,
                                                 edk::vec2f64(tempQuad->origin.x,
                                                              tempQuad->origin.y
                                                              ),
                                                 edk::vec2f64(tempQuad->size.width,
                                                              tempQuad->size.height
                                                              )
                                                 )
                                ){
                            //
                            *tree[counter] = tempQuad;
                            counter++;
                            nextID = i;
                        }
                    }
                    //test if have one next
                    if(counter==1u){
                        //then get the next
                        (*this->selectedPointer) = temp = temp->getQuad(nextID);
                    }
                    else{
                        temp=NULL;
                    }
                }
                else{
                    temp=NULL;
                }
            }
            if((*this->selectedPointer) && (*this->selectedPointer)!=&(*this->treeNULLPointer)){
                if(!(*this->selectedPointer)->getTreeSize()
                        && !(*this->selected1Pointer)->getTreeSize()
                        && !(*this->selected2Pointer)->getTreeSize()
                        && !(*this->selected3Pointer)->getTreeSize()
                        ){
                    if((*this->selectedPointer)->getFather()){
                        (*this->selectedPointer) = (*this->selectedPointer)->getFather();
                        (*this->selected1Pointer) = &(*this->treeNULLPointer);
                        (*this->selected2Pointer) = &(*this->treeNULLPointer);
                        (*this->selected3Pointer) = &(*this->treeNULLPointer);
                    }
                }
            }
        }
        this->runUpdateGets();
        if(ret){
            ret = (bool)(*this->treeTempPointer)->size();
        }
        return ret;
    }
    virtual bool selectLeafInPoint(edk::vec2f64 point){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        (*this->selectedPointer) = &(*this->treeNULLPointer);
        (*this->selected1Pointer) = &(*this->treeNULLPointer);
        (*this->selected2Pointer) = &(*this->treeNULLPointer);
        (*this->selected3Pointer) = &(*this->treeNULLPointer);
        bool ret=false;
        if(this->isPointInside(point,
                               edk::vec2f64((*this->rootPointer).origin.x,
                                            (*this->rootPointer).origin.y
                                            ),
                               edk::vec2f64((*this->rootPointer).size.width,
                                            (*this->rootPointer).size.height
                                            )
                               )
                ){
            (*this->selectedPointer) = &(*this->rootPointer);
            edk::vector::QuadLeaf64<typeTemplate>* temp = &(*this->rootPointer);
            ret=true;
            //edk::uint8 counter;
            edk::uint8 nextID=0u;
            edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
            bool needContinue=false;
            while(temp){
                //test the collision with all quads
                if(temp->haveQuads()){
                    needContinue=false;
                    for(edk::uint8 i=0u;i<4u;i++){
                        tempQuad = temp->getQuad(i);
                        if(this->isPointInside(point,
                                               edk::vec2f64(tempQuad->origin.x,
                                                            tempQuad->origin.y
                                                            ),
                                               edk::vec2f64(tempQuad->size.width,
                                                            tempQuad->size.height
                                                            )
                                               )
                                ){
                            //
                            (*this->selectedPointer) = temp = temp->getQuad(nextID);
                            break;
                        }
                    }
                    if(needContinue){
                        continue;
                    }
                    temp=NULL;
                }
                else{
                    temp=NULL;
                }
            }
        }
        this->runUpdateGets(edk::rectf64(point.x,point.y,point.x,point.y));
        if(ret){
            ret = (bool)(*this->treeTempPointer)->size();
        }
        return ret;
    }
    virtual bool selectLeafInRect(edk::rectf64 rect){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        (*this->selectedPointer) = &(*this->treeNULLPointer);
        edk::vector::QuadLeaf64<typeTemplate>** tree[edkQuadSelectedSize];
        (*this->selectedPointer)  = &(*this->treeNULLPointer);
        (*this->selected1Pointer) = &(*this->treeNULLPointer);
        (*this->selected2Pointer) = &(*this->treeNULLPointer);
        (*this->selected3Pointer) = &(*this->treeNULLPointer);
        tree[0u] = &(*this->selectedPointer);
        tree[1u] = &(*this->selected1Pointer);
        tree[2u] = &(*this->selected2Pointer);
        tree[3u] = &(*this->selected3Pointer);
        bool ret=false;
        if(this->isRectColliding(rect,
                                 edk::vec2f64((*this->rootPointer).origin.x,
                                              (*this->rootPointer).origin.y
                                              ),
                                 edk::vec2f64((*this->rootPointer).size.width,
                                              (*this->rootPointer).size.height
                                              )
                                 )
                ){
            (*this->selectedPointer) = &(*this->rootPointer);
            edk::vector::QuadLeaf64<typeTemplate>* temp = &(*this->rootPointer);
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
            while(temp){
                //test if have quads inside
                if(temp->haveQuads()){
                    counter=0u;
                    for(edk::uint8 i=0u;i<4u;i++){
                        tempQuad = temp->getQuad(i);
                        if(this->isRectColliding(rect,
                                                 edk::vec2f64(tempQuad->origin.x,
                                                              tempQuad->origin.y
                                                              ),
                                                 edk::vec2f64(tempQuad->size.width,
                                                              tempQuad->size.height
                                                              )
                                                 )
                                ){
                            //
                            *tree[counter]=tempQuad;
                            counter++;
                            nextID = i;
                        }
                    }
                    //test if have just one colliding
                    if(counter==1u){
                        //select the next
                        (*this->selectedPointer) = temp = temp->getQuad(nextID);
                        *tree[1u] = &(*this->treeNULLPointer);
                        *tree[2u] = &(*this->treeNULLPointer);
                        *tree[3u] = &(*this->treeNULLPointer);
                    }
                    else if(counter==4u){
                        //select only the temp
                        (*this->selectedPointer) = temp;
                        *tree[1u] = &(*this->treeNULLPointer);
                        *tree[2u] = &(*this->treeNULLPointer);
                        *tree[3u] = &(*this->treeNULLPointer);
                        break;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        this->runUpdateGets(rect);
        if(ret){
            ret = (bool)(*this->treeTempPointer)->size();
        }
        return ret;
    }
    virtual bool selectLeafInRectPoints(edk::rectf64 rect){
#if defined(EDK_DONT_USE_QUADTREE)
        return false;
#endif
        (*this->selectedPointer) = &(*this->treeNULLPointer);
        edk::vector::QuadLeaf64<typeTemplate>** tree[edkQuadSelectedSize];
        (*this->selectedPointer)  = &(*this->treeNULLPointer);
        (*this->selected1Pointer) = &(*this->treeNULLPointer);
        (*this->selected2Pointer) = &(*this->treeNULLPointer);
        (*this->selected3Pointer) = &(*this->treeNULLPointer);
        tree[0u] = &(*this->selectedPointer);
        tree[1u] = &(*this->selected1Pointer);
        tree[2u] = &(*this->selected2Pointer);
        tree[3u] = &(*this->selected3Pointer);
        bool ret=false;
        if(this->isRectPointsColliding(rect,
                                       edk::vec2f64((*this->rootPointer).origin.x,
                                                    (*this->rootPointer).origin.y
                                                    ),
                                       edk::vec2f64((*this->rootPointer).size.width,
                                                    (*this->rootPointer).size.height
                                                    )
                                       )
                ){
            (*this->selectedPointer) = &(*this->rootPointer);
            edk::vector::QuadLeaf64<typeTemplate>* temp = &(*this->rootPointer);
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
            while(temp){
                //test if have quads inside
                if(temp->haveQuads()){
                    counter=0u;
                    for(edk::uint8 i=0u;i<4u;i++){
                        tempQuad = temp->getQuad(i);
                        if(this->isRectPointsColliding(rect,
                                                       edk::vec2f64(tempQuad->origin.x,
                                                                    tempQuad->origin.y
                                                                    ),
                                                       edk::vec2f64(tempQuad->size.width,
                                                                    tempQuad->size.height
                                                                    )
                                                       )
                                ){
                            //
                            *tree[counter]=tempQuad;
                            counter++;
                            nextID = i;
                        }
                    }
                    //test if have just one colliding
                    if(counter==1u){
                        //select the next
                        (*this->selectedPointer) = temp = temp->getQuad(nextID);
                        *tree[1u] = &(*this->treeNULLPointer);
                        *tree[2u] = &(*this->treeNULLPointer);
                        *tree[3u] = &(*this->treeNULLPointer);
                    }
                    else if(counter==4u){
                        //select only the temp
                        (*this->selectedPointer) = temp;
                        *tree[1u] = &(*this->treeNULLPointer);
                        *tree[2u] = &(*this->treeNULLPointer);
                        *tree[3u] = &(*this->treeNULLPointer);
                        break;
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        this->runUpdateGets(rect);
        if(ret){
            ret = (bool)(*this->treeTempPointer)->size();
        }
        return ret;
    }

    //clean the tree
    void cleanWithRect(edk::rectf64 rect,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        edk::rectf64 rectTemp = edk::rectf64(rect.origin.x - (rect.size.width*0.5f),
                                             rect.origin.y - (rect.size.height*0.5f),
                                             rect.origin.x + (rect.size.width*0.5f),
                                             rect.origin.y + (rect.size.height*0.5f)
                                             );
        this->releaseTreeTemp();
        (*this->rootPointer).clean();
        (*this->rootPointer).setTree(this->newTree());
        (*this->rootPointer).origin = rectTemp.origin;
        (*this->rootPointer).size = rectTemp.size;
        (*this->treeNULLPointer).clean();
        (*this->treeNULLPointer).setTree(this->newTree());
        (*this->treeNULLPointer).origin = rectTemp.origin;
        (*this->treeNULLPointer).size = rectTemp.size;
        (*this->selectedPointer)=&(*this->treeNULLPointer);
        (*this->selected1Pointer) = &(*this->treeNULLPointer);
        (*this->selected2Pointer) = &(*this->treeNULLPointer);
        (*this->selected3Pointer) = &(*this->treeNULLPointer);
        //GETS
        if((*this->treeTempPointer)!=&(*this->treeValuesUpdatePointer)){
            delete (*this->treeTempPointer);
        }
        (*this->treeValuesUpdatePointer).clean();
        //create a new tree
        (*this->treeTempPointer) = this->newTree();
        if(!(*this->treeTempPointer)){
            (*this->treeTempPointer) = &(*this->treeValuesUpdatePointer);
        }
        //REMOVED
        (*this->treeOutsidePointer).clean();

        (*this->treeGetsPointer).clean();

        this->minimumQuadSize=minimumQuadSize;
    }

    void cleanAndSetRectangleFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
        this->setRectFromTree(tree);
    }

    //clean the tree
    void cleanWithRectPoints(edk::rectf64 rect,edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->releaseTreeTemp();
        (*this->rootPointer).clean();
        (*this->rootPointer).setTree(this->newTree());
        (*this->rootPointer).origin = rect.origin;
        (*this->rootPointer).size = rect.size;
        (*this->treeNULLPointer).clean();
        (*this->treeNULLPointer).setTree(this->newTree());
        (*this->treeNULLPointer).origin = rect.origin;
        (*this->treeNULLPointer).size = rect.size;
        (*this->selectedPointer)=&(*this->treeNULLPointer);
        (*this->selected1Pointer) = &(*this->treeNULLPointer);
        (*this->selected2Pointer) = &(*this->treeNULLPointer);
        (*this->selected3Pointer) = &(*this->treeNULLPointer);
        //GETS
        if((*this->treeTempPointer)!=&(*this->treeValuesUpdatePointer)){
            delete (*this->treeTempPointer);
        }
        (*this->treeValuesUpdatePointer).clean();
        //create a new tree
        (*this->treeTempPointer) = this->newTree();
        if(!(*this->treeTempPointer)){
            (*this->treeTempPointer) = &(*this->treeValuesUpdatePointer);
        }
        //REMOVED
        (*this->treeOutsidePointer).clean();

        (*this->treeGetsPointer).clean();

        this->minimumQuadSize=minimumQuadSize;
    }
    void clean(edk::float64 minimumQuadSize=edkQuadMinimumSize){
        this->cleanWithRectPoints(edk::rectf64(0,0,1,1),minimumQuadSize);
    }

    void cleanAndSetRectanglePointsFromTree(edk::vector::BinaryTree<typeTemplate>* tree){
        this->setRectPointsFromTree(tree);
    }

    void forceOutAll(){
        edk::uint64 size;
        typeTemplate temp;
        size = (*this->treeGetsPointer).size();
        for(edk::uint64 i=0u;i<size;i++){
            temp = (*this->treeGetsPointer).getElementInPosition(0u);
            if(temp){
                if((*this->treeGetsPointer).remove(temp)){
                    ///RUN GETOUT
                    this->elementGetOut(temp);
                    (*this->treeTempPointer)->remove(temp);
                    (*this->treeOutsidePointer).add(temp);
                }
            }
        }
        (*this->treeTempPointer)->clean();
    }

    //SELECTED FUNCTIONS
    bool haveSelected(){
        if((*this->selectedPointer)
                && (*this->selectedPointer)!=&(*this->treeNULLPointer)
                && (*this->selectedPointer) != &(*this->rootPointer)
                ){
            return true;
        }
        return false;
    }
    edk::uint64 selectedGetTreeSize(){
        return (*this->treeTempPointer)->size();
    }
    typeTemplate selectedGetElementInPosition(edk::uint64 position){
        return (*this->treeTempPointer)->getElementInPosition(position);
    }
    edk::vector::BinaryTree<typeTemplate>* selectedGetTreePointer(){
        return (*this->treeTempPointer);
    }
    //Load the elements
    virtual void selectedLoad(){
        (*this->treeTempPointer)->load();
    }
    //Unload the elements
    virtual void selectedUnload(){
        (*this->treeTempPointer)->unload();
    }
    //Print the elements
    virtual void selectedPrint(){
        (*this->treeTempPointer)->print();
    }
    //render the elements
    virtual void selectedRender(){
        (*this->treeTempPointer)->render();
    }
    virtual void selectedRenderWire(){
        (*this->treeTempPointer)->renderWire();
    }
    //draw the elements
    virtual void selectedDraw(){
        (*this->treeTempPointer)->draw();
    }
    virtual void selectedDrawWire(){
        (*this->treeTempPointer)->drawWire();
    }
    //update the elements
    virtual void selectedUpdate(){
        (*this->treeTempPointer)->update();
    }

    void drawQuads(){
#if defined(EDK_QUADTREE_GU)
        //
        edk::GU::guColor4f64(this->color);
        edk::GU::guPushMatrix();
        edk::GU::guBegin(GU_LINES);
        (*this->rootPointer).drawQUADS();
        edk::GU::guEnd();
        edk::GU::guPopMatrix();
#endif
    }
    edk::color4f64 color;

protected:
    //test if the object is inside the leaf
    virtual bool isElementInside(typeTemplate ,edk::vec2f64 ,edk::vec2f64 ){
        return false;
    }
    //test if the element is just colliding
    virtual bool isElementColliding(typeTemplate ,edk::vec2f64 ,edk::vec2f64 ){
        return false;
    }
    //returh the rectangle of the element
    virtual edk::rectf64 getElementRectangle(typeTemplate ){
        return edk::rectf64(0,0,1,1);
    }
    //function to create a new tree
    virtual edk::vector::BinaryTree<typeTemplate>* newTree(){
        return new edk::vector::BinaryTree<typeTemplate>;
    }
    virtual void elementGetIn(typeTemplate){
        //elementGetIn
    }
    virtual void elementUpdating(typeTemplate){
        //elementUpdating
    }
    virtual void elementGetOut(typeTemplate){
        //elementGetOut
    }

    //get the quadtree binaryTreePointer
    edk::vector::BinaryTree<typeTemplate>* getTreePointer(){return (*this->treeTempPointer); }

private:
    //quadtree Root
    edk::vector::QuadLeaf64<typeTemplate> root;
    edk::vector::QuadLeaf64<typeTemplate>* rootPointer;
    edk::vector::QuadLeaf64<typeTemplate>* selected;
    edk::vector::QuadLeaf64<typeTemplate>** selectedPointer;
    edk::vector::QuadLeaf64<typeTemplate>* selected1;
    edk::vector::QuadLeaf64<typeTemplate>** selected1Pointer;
    edk::vector::QuadLeaf64<typeTemplate>* selected2;
    edk::vector::QuadLeaf64<typeTemplate>** selected2Pointer;
    edk::vector::QuadLeaf64<typeTemplate>* selected3;
    edk::vector::QuadLeaf64<typeTemplate>** selected3Pointer;
    //binary tree to test if the objects getIn or getOut
    edk::vector::BinaryTree<typeTemplate>  treeGets;
    edk::vector::BinaryTree<typeTemplate>*  treeGetsPointer;
    edk::vector::BinaryTree<typeTemplate>  treeOutside;
    edk::vector::BinaryTree<typeTemplate>*  treeOutsidePointer;
    edk::vector::BinaryTree<typeTemplate>  treeValuesUpdate;
    edk::vector::BinaryTree<typeTemplate>*  treeValuesUpdatePointer;
    edk::vector::BinaryTree<typeTemplate>* treeTemp;
    edk::vector::BinaryTree<typeTemplate>** treeTempPointer;
    //three NULL
    edk::vector::QuadLeaf64<typeTemplate> treeNULL;
    edk::vector::QuadLeaf64<typeTemplate>* treeNULLPointer;

    bool canObjectIn;

    //minimumQuadSize
    edk::float64 minimumQuadSize;
    edk::float64* minimumQuadSizePointer;

    //minimun elements in a QUAD
    edk::uint64 minimumElementInQuads;
    edk::uint64* minimumElementInQuadsPointer;

    bool isRectInside(edk::rectf64 rect,edk::vec2f64 point1,edk::vec2f64 point2){
        if(rect.origin.x >= point1.x
                &&
                rect.origin.y >= point1.y
                &&
                rect.origin.x <= point2.x
                &&
                rect.origin.y <= point2.y
                &&
                rect.size.width >= point1.x
                &&
                rect.size.height >= point1.y
                &&
                rect.size.width <= point2.x
                &&
                rect.size.height <= point2.y
                ){
            return true;
        }
        return false;
    }
    bool isRectColliding(edk::rectf64 rect,edk::vec2f64 point1,edk::vec2f64 point2){
        if(point1.x <= rect.origin.x + rect.size.width
                &&
                point2.x>= rect.origin.x
                &&
                point1.y <= rect.origin.y + rect.size.height
                &&
                point2.y >= rect.origin.y
                ){
            return true;
        }
        return false;
    }
    bool isRectPointsColliding(edk::rectf64 rect,edk::vec2f64 point1,edk::vec2f64 point2){
        if(point1.x <= rect.size.width
                &&
                point2.x>= rect.origin.x
                &&
                point1.y <= rect.size.height
                &&
                point2.y >= rect.origin.y
                ){
            return true;
        }
        return false;
    }
    bool isPointInside(edk::vec2f64 point,edk::vec2f64 point1,edk::vec2f64 point2){
        if(point.x >= point1.x
                &&
                point.y >= point1.y
                &&
                point.x < point2.x
                &&
                point.y < point2.y
                ){
            return true;
        }
        return false;
    }
    //update the gets
    void runUpdateGets(edk::rectf64 rect){
#if defined(EDK_DONT_USE_QUADTREE)
        return;
#endif
        edk::vector::BinaryTree<typeTemplate>* tree[edkQuadSelectedSize];
        tree[0u] = (*this->selectedPointer)->getTreePointer();
        tree[1u] = (*this->selected1Pointer)->getTreePointer();
        tree[2u] = (*this->selected2Pointer)->getTreePointer();
        tree[3u] = (*this->selected3Pointer)->getTreePointer();
        /*if(tree && tree2 && tree3)*/{
            //first remove the last objects
            edk::uint64 size;
            typeTemplate temp;
            bool decrement = false;

            //add or remove elements from the trees
            size = (*this->treeGetsPointer).size();
            for(edk::uint64 i=0u;i<size;i++){
                if(decrement){
                    decrement=false;
                    i--;
                    size--;
                }
                temp = (*this->treeGetsPointer).getElementInPosition(i);

                if(this->isElementColliding(temp,
                                            edk::vec2f64(rect.origin.x,rect.origin.y),
                                            edk::vec2f64(rect.size.width,rect.size.height)
                                            )
                        ){
                    if(this->canObjectIn){
                        //test if was in the treeOutside
                        if((*this->treeOutsidePointer).haveElement(temp)){
                            //remove the element from outside
                            if((*this->treeOutsidePointer).remove(temp)){
                                this->elementGetIn(temp);
                                (*this->treeTempPointer)->add(temp);
                            }
                        }
                    }
                }
                else{
                    for(edk::uint8 t=0u;t<edkQuadSelectedSize;t++){
                        if(tree[t]->haveElement(temp)){
                            //test if wasn't in the treeOutside
                            if(!(*this->treeOutsidePointer).haveElement(temp)){
                                //add the temp into the removed tree
                                if((*this->treeOutsidePointer).add(temp)){
                                    //element is out of the rectangle
                                    ///RUN GETOUT
                                    this->elementGetOut(temp);
                                    (*this->treeTempPointer)->remove(temp);
                                }
                            }
                        }
                        else{
                            if((*this->treeGetsPointer).remove(temp)){
                                ///RUN GETOUT
                                this->elementGetOut(temp);
                                (*this->treeTempPointer)->remove(temp);
                                (*this->treeOutsidePointer).add(temp);
                                //decrement
                                decrement=true;
                            }
                        }
                    }
                }
            }
            //update the elements
            size = (*this->treeTempPointer)->size();
            for(edk::uint64 i=0u;i<size;i++){
                this->elementUpdating((*this->treeTempPointer)->getElementInPosition(i));
            }
            //add new elements.
            for(edk::uint8 t=0u;t<edkQuadSelectedSize;t++){
                size = tree[t]->size();
                for(edk::uint64 i=0u;i<size;i++){
                    temp = tree[t]->getElementInPosition(i);
                    //test if have the object inside the temp
                    if(!(*this->treeGetsPointer).haveElement(temp)){
                        //add the element
                        if(this->isElementColliding(temp,
                                                    edk::vec2f64(rect.origin.x,rect.origin.y),
                                                    edk::vec2f64(rect.size.width,rect.size.height)
                                                    )){
                            if(this->canObjectIn){
                                if((*this->treeGetsPointer).add(temp)){
                                    ///RUN GETIN
                                    this->elementGetIn(temp);
                                    (*this->treeTempPointer)->add(temp);
                                    (*this->treeOutsidePointer).remove(temp);
                                }
                            }
                        }
                        else{
                            //else add in to the outside
                            (*this->treeOutsidePointer).add(temp);
                        }
                    }
                }
            }
        }
    }
    void runUpdateGets(){
#if defined(EDK_DONT_USE_QUADTREE)
        return;
#endif
        edk::vector::BinaryTree<typeTemplate>* tree[edkQuadSelectedSize];
        tree[0u] = (*this->selectedPointer)->getTreePointer();
        tree[1u] = (*this->selected1Pointer)->getTreePointer();
        tree[2u] = (*this->selected2Pointer)->getTreePointer();
        tree[3u] = (*this->selected3Pointer)->getTreePointer();
        /*if(tree && tree2 && tree3)*/{
            //first remove the last objects
            edk::uint64 size;
            typeTemplate temp;
            bool decrement = false;
            size = (*this->treeGetsPointer).size();
            for(edk::uint64 i=0u;i<size;i++){
                if(decrement){
                    decrement=false;
                    i--;
                    size--;
                }
                temp = (*this->treeGetsPointer).getElementInPosition(i);
                //test if DON'T have the object inside the temp
                for(edk::uint8 t=0u;t<edkQuadSelectedSize;t++){
                    if(!tree[t]->haveElement(temp)){
                        //remove the object from the treeGets
                        if((*this->treeGetsPointer).remove(temp)){
                            //decrement
                            decrement=true;

                            ///RUN GETOUT
                            this->elementGetOut(temp);
                            (*this->treeTempPointer)->remove(temp);
                        }
                    }
                }
            }
            size = (*this->treeGetsPointer).size();
            for(edk::uint64 i=0u;i<size;i++){
                this->elementUpdating((*this->treeGetsPointer).getElementInPosition(i));
            }
            for(edk::uint8 t=0u;t<edkQuadSelectedSize;t++){
                size = tree[t]->size();
                for(edk::uint64 i=0u;i<size;i++){
                    temp = tree[t]->getElementInPosition(i);
                    //test if have the object inside the temp
                    if(!(*this->treeGetsPointer).haveElement(temp)){
                        //add the element
                        if((*this->treeGetsPointer).add(temp)){
                            ///RUN GETIN
                            this->elementGetIn(temp);
                            (*this->treeTempPointer)->add(temp);
                        }
                    }
                }
            }
        }
    }
    void releaseTreeTemp(){
        edk::uint64 size = (*this->treeTempPointer)->size();
        for(edk::uint64 i=0u;i<size;i++){
            this->elementGetOut((*this->treeTempPointer)->getElementInPosition(i));
        }
        (*this->treeTempPointer)->clean();
    }
private:
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
}//end namespace vector
}//end namespace edk

#endif // QUADTREE_H
