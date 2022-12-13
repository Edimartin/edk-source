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
#warning "Inside QuadTree"
#endif

#pragma once
#include <stdio.h>
#include <string.h>
#include "../TypeRect.h"
#include "BinaryTree.h"

#ifdef EDK_QUADTREE_GU
#include "../GU/GU.h"
#endif

#ifdef printMessages
#warning "    Compiling QuadTree"
#endif


/*
//code sample

//QuadTree

class QuadtreePoints:public edk::vector::QuadTree32<edk::vec2f32>{
public:
    QuadtreePoints(){}
    virtual ~QuadtreePoints(){}

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
class QuadtreeRectangles:public edk::vector::QuadTree32<edk::rectf32>{
public:
    QuadtreeRectangles(){}
    virtual ~QuadtreeRectangles(){}

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
                )
            return true;
        return false;
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

class QuadtreePoints:public edk::vector::QuadTree64<edk::vec2f64>{
public:
    QuadtreePoints(){}
    virtual ~QuadtreePoints(){}

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
class QuadtreeRectangles:public edk::vector::QuadTree64<edk::rectf64>{
public:
    QuadtreeRectangles(){}
    virtual ~QuadtreeRectangles(){}

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
                )
            return true;
        return false;
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
        this->father=NULL;
        //start the values
        this->origin = rect.origin;
        this->size = rect.size;
        this->counter=0u;
        //
        this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;

        //add a callback in to the tree
        this->setTree(NULL);
    }
    QuadLeaf32(QuadLeaf32* father,edk::rectf32 rect = edk::rectf32(0,0,1,1)){
        this->father=father;
        //start the values
        this->origin = rect.origin;
        this->size = rect.size;
        this->counter=0u;
        //
        this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;

        //add a callback in to the tree
        this->setTree(NULL);
    }
    ~QuadLeaf32(){
        this->clean();
    }
    void clean(){
        this->father=NULL;
        if(this->tree != &this->treeThis)
            this->treeThis.clean();
        this->tree->clean();
        this->deleteQuads();
    }
    //new quads
    bool newQuads(edk::vector::BinaryTree<typeTemplate>* tree0,
                  edk::vector::BinaryTree<typeTemplate>* tree1,
                  edk::vector::BinaryTree<typeTemplate>* tree2,
                  edk::vector::BinaryTree<typeTemplate>* tree3
                  ){
        this->deleteQuads();

        edk::rectf32 rect;
        rect.origin.x = this->origin.x;
        rect.origin.y = this->origin.y;
        rect.size.width = this->origin.x+((this->size.width - this->origin.x)*0.5);
        rect.size.height = this->origin.y+((this->size.height - this->origin.y)*0.5);
        if((this->quad[0u] = new edk::vector::QuadLeaf32<typeTemplate>(this,rect))){
            rect.origin.x = this->origin.x+((this->size.width - this->origin.x)*0.5);
            rect.origin.y = this->origin.y;
            rect.size.width = this->size.width;
            rect.size.height = this->origin.y+((this->size.height - this->origin.y)*0.5);
            if((this->quad[1u] = new edk::vector::QuadLeaf32<typeTemplate>(this,rect))){
                rect.origin.x = this->origin.x+((this->size.width - this->origin.x)*0.5);
                rect.origin.y = this->origin.y+((this->size.height - this->origin.y)*0.5);
                rect.size.width = this->size.width;
                rect.size.height = this->size.height;
                if((this->quad[2u] = new edk::vector::QuadLeaf32<typeTemplate>(this,rect))){
                    rect.origin.x = this->origin.x;
                    rect.origin.y = this->origin.y+((this->size.height - this->origin.y)*0.5);
                    rect.size.width = this->origin.x+((this->size.width - this->origin.x)*0.5);
                    rect.size.height = this->size.height;
                    if((this->quad[3u] = new edk::vector::QuadLeaf32<typeTemplate>(this,rect))){
                        this->quad[0u]->setTree(tree0);
                        this->quad[1u]->setTree(tree1);
                        this->quad[2u]->setTree(tree2);
                        this->quad[3u]->setTree(tree3);
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
        return (bool)(this->quad[0u]);
    }
    //get the quad in position
    edk::vector::QuadLeaf32<typeTemplate>* getQuad(edk::uint8 position){
        if(position<4u){
            return this->quad[position];
        }
        return NULL;
    }



    void drawQUADS(){
#ifdef EDK_QUADTREE_GU
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
        if(this->quad[0u])
            delete this->quad[0u];
        this->quad[0u]=NULL;
        if(this->quad[1u])
            delete this->quad[1u];
        this->quad[1u]=NULL;
        if(this->quad[2u])
            delete this->quad[2u];
        this->quad[2u]=NULL;
        if(this->quad[3u])
            delete this->quad[3u];
        this->quad[3u]=NULL;
    }
    //counter used to set what quad is testing
    edk::uint8 counter;
private:
    //RIGHT
    edk::vector::QuadLeaf32<typeTemplate>* quad[4u];
    edk::vector::QuadLeaf32<typeTemplate>* father;
    //tree with values
    edk::vector::BinaryTree<typeTemplate> treeThis;
    edk::vector::BinaryTree<typeTemplate>* tree;

};
//LEAF64
template <class typeTemplate>
class QuadLeaf64 : public edk::rectf64{
public:
    QuadLeaf64(edk::rectf64 rect = edk::rectf64(0,0,1,1)){
        this->father=NULL;
        //start the values
        this->origin = rect.origin;
        this->size = rect.size;
        this->counter=0u;
        //
        this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;

        //add a callback in to the tree
        this->setTree(NULL);
    }
    QuadLeaf64(QuadLeaf64* father,edk::rectf64 rect = edk::rectf64(0,0,1,1)){
        this->father=father;
        //start the values
        this->origin = rect.origin;
        this->size = rect.size;
        this->counter=0u;
        //
        this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;

        //add a callback in to the tree
        this->setTree(NULL);
    }
    ~QuadLeaf64(){
        this->clean();
    }
    void clean(){
        this->father=NULL;
        if(this->tree != &this->treeThis)
            this->treeThis.clean();
        this->tree->clean();
        this->deleteQuads();
    }
    //new quads
    bool newQuads(edk::vector::BinaryTree<typeTemplate>* tree0,
                  edk::vector::BinaryTree<typeTemplate>* tree1,
                  edk::vector::BinaryTree<typeTemplate>* tree2,
                  edk::vector::BinaryTree<typeTemplate>* tree3
                  ){
        this->deleteQuads();

        edk::rectf64 rect;
        rect.origin.x = this->origin.x;
        rect.origin.y = this->origin.y;
        rect.size.width = this->origin.x+((this->size.width - this->origin.x)*0.5);
        rect.size.height = this->origin.y+((this->size.height - this->origin.y)*0.5);
        if((this->quad[0u] = new edk::vector::QuadLeaf64<typeTemplate>(this,rect))){
            rect.origin.x = this->origin.x+((this->size.width - this->origin.x)*0.5);
            rect.origin.y = this->origin.y;
            rect.size.width = this->size.width;
            rect.size.height = this->origin.y+((this->size.height - this->origin.y)*0.5);
            if((this->quad[1u] = new edk::vector::QuadLeaf64<typeTemplate>(this,rect))){
                rect.origin.x = this->origin.x+((this->size.width - this->origin.x)*0.5);
                rect.origin.y = this->origin.y+((this->size.height - this->origin.y)*0.5);
                rect.size.width = this->size.width;
                rect.size.height = this->size.height;
                if((this->quad[2u] = new edk::vector::QuadLeaf64<typeTemplate>(this,rect))){
                    rect.origin.x = this->origin.x;
                    rect.origin.y = this->origin.y+((this->size.height - this->origin.y)*0.5);
                    rect.size.width = this->origin.x+((this->size.width - this->origin.x)*0.5);
                    rect.size.height = this->size.height;
                    if((this->quad[3u] = new edk::vector::QuadLeaf64<typeTemplate>(this,rect))){
                        this->quad[0u]->setTree(tree0);
                        this->quad[1u]->setTree(tree1);
                        this->quad[2u]->setTree(tree2);
                        this->quad[3u]->setTree(tree3);
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
        return (bool)(this->quad[0u]);
    }
    //get the quad in position
    edk::vector::QuadLeaf64<typeTemplate>* getQuad(edk::uint8 position){
        if(position<4u){
            return this->quad[position];
        }
        return NULL;
    }



    void drawQUADS(){
#ifdef EDK_QUADTREE_GU
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
        if(this->quad[0u])
            delete this->quad[0u];
        this->quad[0u]=NULL;
        if(this->quad[1u])
            delete this->quad[1u];
        this->quad[1u]=NULL;
        if(this->quad[2u])
            delete this->quad[2u];
        this->quad[2u]=NULL;
        if(this->quad[3u])
            delete this->quad[3u];
        this->quad[3u]=NULL;
    }
    //counter used to set what quad is testing
    edk::uint8 counter;
private:
    //RIGHT
    edk::vector::QuadLeaf64<typeTemplate>* quad[4u];
    edk::vector::QuadLeaf64<typeTemplate>* father;
    //tree with values
    edk::vector::BinaryTree<typeTemplate> treeThis;
    edk::vector::BinaryTree<typeTemplate>* tree;

};

//QUADTREE32
template <class typeTemplate>
class QuadTree32 : public edk::vector::BinaryTreeCallback<typeTemplate>{
public:
    QuadTree32(){
        this->selected=&this->root;
    }
    virtual ~QuadTree32(){
        this->clean();
    }
    //set the quadtree position and size
    void setPositionAndSize(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height){
        this->setRect(edk::rectf32(x,y,width + x,height + y));
    }
    void setPositionAndSize(edk::vec2f32 position,edk::size2f32 size){
        this->setRect(edk::rectf32(position.x,position.y,size.width + position.x,size.height + position.y));
    }
    void setPoints(edk::float32 position1X,edk::float32 position1Y,edk::float32 position2X,edk::float32 position2Y){
        this->setRect(edk::rectf32(position1X,position1Y,position2X,position2Y));
    }
    void setPoints(edk::vec2f32 point1,edk::vec2f32 point2){
        this->setRect(edk::rectf32(point1.x,point1.y,point2.x,point2.y));
    }
    //set the quadTree rectangle
    void setRect(edk::rectf32 rect){
        this->clean(rect);
    }
    void setRect(edk::vec2f32 position,edk::size2f32 size){
        this->clean(edk::rectf32(position,size));
    }
    void setRect(edk::float32 positionX,edk::float32 positionY,edk::float32 width,edk::float32 height){
        this->clean(edk::rectf32(positionX,positionY,width,height));
    }

    //add a object
    bool add(typeTemplate value, edk::uint32 depthLimit=0xFFFFFFFF){
        edk::vector::QuadLeaf32<typeTemplate>* temp = &this->root;
        edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
        bool goInside=false;
        bool deleteQuads=false;
        edk::uint32 depth=0u;
        edk::vector::BinaryTree<typeTemplate>* tree;
        edk::uint32 size = 0u;
        typeTemplate valueTemp;
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
            while(temp){
                //add the value in to the temp
                temp->addToTree(value);

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
                                                      tree4
                                                      )){
                                        //
                                        tree1=tree2=tree3=tree4=NULL;
                                    }
                                    if(tree4)
                                        delete tree4;
                                }
                                if(tree3)
                                    delete tree3;
                            }
                            if(tree2)
                                delete tree2;
                        }
                        if(tree1)
                            delete tree1;
                    }
                }

                //test if have the quads
                if(temp->haveQuads()){
                    deleteQuads=true;
                    goInside=false;
                    //get the temp tree
                    tree = temp->getTreePointer();
                    if(tree){
                        size = tree->size();
                        for(edk::uint8 j=0u;j<size;j++){
                            valueTemp = tree->getElementInPosition(j);
                            for(edk::uint8 i=0u;i<4u;i++){
                                tempQuad = temp->getQuad(i);
                                //test if is colliding with the quads to just add in the tree
                                if(this->isElementColliding(valueTemp,
                                                            edk::vec2f32(this->root.origin.x,
                                                                         this->root.origin.y
                                                                         ),
                                                            edk::vec2f32(this->root.size.width,
                                                                         this->root.size.height
                                                                         )
                                                            )
                                        ){
                                    tempQuad->addToTree(valueTemp);
                                }
                            }
                        }
                    }
                    //test if the value is inside some quad
                    for(edk::uint8 i=0u;i<4u;i++){
                        tempQuad = temp->getQuad(i);
                        //test if is inside the quads
                        if(this->isElementInside(value,
                                                 edk::vec2f32(tempQuad->origin.x,
                                                              tempQuad->origin.y
                                                              ),
                                                 edk::vec2f32(tempQuad->size.width,
                                                              tempQuad->size.height
                                                              )
                                                 )
                                ){
                            temp = tempQuad;
                            goInside=true;
                            break;
                        }
                        else{
                            //test if the tempQuad have some inside the tree
                            if(tempQuad->getTreeSize()){
                                //don't delete the quads
                                deleteQuads=false;
                            }
                        }
                    }
                    if(!goInside){
                        //test if need delete the quads
                        if(deleteQuads){
                            temp->deleteQuads();
                        }
                        temp=NULL;
                    }
                    else{
                        depth++;
                        if(depth>=depthLimit){
                            temp=NULL;
                        }
                    }
                }
                else{
                    temp=NULL;
                }

            }
            return true;
        }
        return false;
    }
    //remove a value from de quadTree
    bool remove(typeTemplate value){
        bool ret=false;
        edk::vector::QuadLeaf32<typeTemplate>* temp = &this->root;
        edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
        bool deleteQuads;
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
            while(temp){
                //remove from it
                if(temp->haveInTree(value)){
                    temp->removeFromTree(value);
                }

                //search for the quads
                if(temp->haveQuads()){
                    if(temp->counter<4u){
                        temp=temp->getQuad(++temp->counter);
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
                        break;
                    }
                }
                else{
                    temp=temp->getFather();
                }
            }
        }
        return ret;
    }

    //select a leaf
    bool selectLeafIWithValue(typeTemplate value){
        this->selected = &this->root;
        bool ret=false;
        if(this->isRectColliding(value,
                                 edk::vec2f32(this->root.origin.x,
                                              this->root.origin.y
                                              ),
                                 edk::vec2f32(this->root.size.width,
                                              this->root.size.height
                                              )
                                 )
                ){
            edk::vector::QuadLeaf32<typeTemplate>* temp = &this->root;
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
            while(temp){
                counter=0u;
                //test the collision with all quads
                if(temp->haveQuads()){
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
                            counter++;
                            nextID = i;
                        }
                    }
                    //test if have one next
                    if(counter==1u){
                        //then get the next
                        this->selected = temp = temp->getQuad(nextID);
                    }
                    else{
                        temp=NULL;
                    }
                }
                else{
                    temp=NULL;
                }
            }
            if(this->selected){
                if(!this->selected->getTreeSize()){
                    if(this->selected->getFather()){
                        this->selected = this->selected->getFather();
                    }
                }
            }
        }
        if(ret){
            this->updateGets();
        }
        return ret;
    }
    bool selectLeafInPoint(edk::vec2f32 point){
        this->selected = &this->root;
        bool ret=false;
        if(this->isPointInside(point,
                               edk::vec2f32(this->root.origin.x,
                                            this->root.origin.y
                                            ),
                               edk::vec2f32(this->root.size.width,
                                            this->root.size.height
                                            )
                               )
                ){
            edk::vector::QuadLeaf32<typeTemplate>* temp = &this->root;
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
            bool needContinue=false;
            while(temp){
                counter=0u;
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
                            this->selected = temp = temp->getQuad(nextID);
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
            if(this->selected){
                if(!this->selected->getTreeSize()){
                    if(this->selected->getFather()){
                        this->selected = this->selected->getFather();
                    }
                }
            }
        }
        if(ret){
            this->updateGets(edk::rectf32(point.x,point.y,point.x,point.y));
        }
        return ret;
    }
    bool selectLeafInRect(edk::rectf32 rect){
        this->selected = &this->root;
        bool ret=false;
        if(this->isRectColliding(rect,
                                 edk::vec2f32(this->root.origin.x,
                                              this->root.origin.y
                                              ),
                                 edk::vec2f32(this->root.size.width,
                                              this->root.size.height
                                              )
                                 )
                ){
            edk::vector::QuadLeaf32<typeTemplate>* temp = &this->root;
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf32<typeTemplate>* tempQuad;
            while(temp){
                counter=0u;
                //test the collision with all quads
                if(temp->haveQuads()){
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
                            counter++;
                            nextID = i;
                        }
                    }
                    //test if have one next
                    if(counter==1u){
                        //then get the next
                        this->selected = temp = temp->getQuad(nextID);
                    }
                    else{
                        temp=NULL;
                    }
                }
                else{
                    temp=NULL;
                }
            }
            if(this->selected){
                if(!this->selected->getTreeSize()){
                    if(this->selected->getFather()){
                        this->selected = this->selected->getFather();
                    }
                }
            }
        }
        if(ret){
            this->updateGets(rect);
        }
        return ret;
    }

    //clean the tree
    void clean(edk::rectf32 rect = edk::rectf32(0.f,0.f,1.f,1.f)){
        this->root.clean();
        this->root.setTree(this->newTree());
        this->root.origin = rect.origin;
        this->root.size = rect.size;
        this->selected=&this->root;
    }

    //SELECTED FUNCTIONS
    bool haveSelected(){
        if(this->selected){
            if(this->selected != &this->root){
                return true;
            }
        }
        return false;
    }
    edk::uint32 selectedGetTreeSize(){
        return this->selected->getTreeSize();
    }
    typeTemplate selectedGetElementInPosition(edk::uint32 position){
        return this->selected->getValueFromTreeInPosition(position);
    }
    edk::vector::BinaryTree<typeTemplate>* selectedGetTreePointer(){
        return this->selected->getTreePointer();
    }
    //Load the elements
    virtual void selectedLoad(){
        this->treeGets.load();
    }
    //Unload the elements
    virtual void selectedUnload(){
        this->treeGets.unload();
    }
    //Print the elements
    virtual void selectedPrint(){
        this->treeGets.print();
    }
    //render the elements
    virtual void selectedRender(){
        this->treeGets.render();
    }
    virtual void selectedRenderWire(){
        this->treeGets.renderWire();
    }
    //draw the elements
    virtual void selectedDraw(){
        this->treeGets.draw();
    }
    virtual void selectedDrawWire(){
        this->treeGets.drawWire();
    }
    //update the elements
    virtual void selectedUpdate(){
        this->treeGets.update();
    }

    void drawQuads(){
#ifdef EDK_QUADTREE_GU
        //
        edk::GU::guColor4f32(this->color);
        edk::GU::guPushMatrix();
        edk::GU::guBegin(GU_LINES);
        this->root.drawQUADS();
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

private:
    //quadtree Root
    edk::vector::QuadLeaf32<typeTemplate> root;
    edk::vector::QuadLeaf32<typeTemplate>* selected;
    //binary tree to test if the objects getIn or getOut
    edk::vector::BinaryTree<typeTemplate> treeGets;

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
        if(point1.x <= rect.size.width
                &&
                point2.x>= rect.origin.x
                &&
                point1.y <= rect.size.height
                &&
                point2.y >= rect.origin.y
                )
            return true;
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
    void updateGets(edk::rectf32 rect){
        edk::vector::BinaryTree<typeTemplate>* tree = this->selected->getTreePointer();
        if(tree){
            //first remove the last objects
            edk::uint32 size;
            typeTemplate temp;
            bool decrement = false;
            size = this->treeGets.size();
            for(edk::uint32 i=0u;i<size;i++){
                if(decrement){
                    decrement=false;
                    i--;
                    size--;
                }
                temp = this->treeGets.getElementInPosition(i);
                //test if DON'T have the object inside the temp
                if(!tree->haveElement(temp)
                        &&
                        !this->isElementColliding(temp,
                                                  edk::vec2f32(rect.origin.x,rect.origin.y),
                                                  edk::vec2f32(rect.size.width,rect.size.height)
                                                  )
                        ){
                    //remove the object from the treeGets
                    if(this->treeGets.remove(temp)){
                        //decrement
                        decrement=true;

                        ///RUN GETOUT
                        this->elementGetOut(temp);
                    }
                }
            }
            size = this->treeGets.size();
            decrement = false;
            for(edk::uint32 i=0u;i<size;i++){
                if(decrement){
                    decrement=false;
                    i--;
                    size--;
                }
                temp = this->treeGets.getElementInPosition(i);
                if(temp){
                    if(this->isElementColliding(temp,
                                                edk::vec2f32(rect.origin.x,rect.origin.y),
                                                edk::vec2f32(rect.size.width,rect.size.height)
                                                )
                            ){
                        ///RUN UPDATING
                        this->elementUpdating(temp);
                    }
                    else{
                        //remove the object from the treeGets
                        if(this->treeGets.remove(temp)){
                            //decrement
                            decrement=true;

                            ///RUN GETOUT
                            this->elementGetOut(temp);
                        }
                    }
                }
            }
            size = tree->size();
            for(edk::uint32 i=0u;i<size;i++){
                temp = tree->getElementInPosition(i);
                //test if have the object inside the temp
                if(!this->treeGets.haveElement(temp)
                        &&
                        this->isElementColliding(temp,
                                                 edk::vec2f32(rect.origin.x,rect.origin.y),
                                                 edk::vec2f32(rect.size.width,rect.size.height)
                                                 )
                        ){
                    //add the element
                    if(this->treeGets.add(temp)){
                        ///RUN GETIN
                        this->elementGetIn(temp);
                    }
                }
            }
        }
    }
    void updateGets(){
        edk::vector::BinaryTree<typeTemplate>* tree = this->selected->getTreePointer();
        if(tree){
            //first remove the last objects
            edk::uint32 size;
            typeTemplate temp;
            bool decrement = false;
            size = this->treeGets.size();
            for(edk::uint32 i=0u;i<size;i++){
                if(decrement){
                    decrement=false;
                    i--;
                    size--;
                }
                temp = this->treeGets.getElementInPosition(i);
                //test if DON'T have the object inside the temp
                if(!tree->haveElement(temp)){
                    //remove the object from the treeGets
                    if(this->treeGets.remove(temp)){
                        //decrement
                        decrement=true;

                        ///RUN GETOUT
                        this->elementGetOut(temp);
                    }
                }
            }
            size = this->treeGets.size();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->treeGets.getElementInPosition(i);
                if(temp){
                    ///RUN UPDATING
                    this->elementUpdating(temp);
                }
            }
            size = tree->size();
            for(edk::uint32 i=0u;i<size;i++){
                temp = tree->getElementInPosition(i);
                //test if have the object inside the temp
                if(!this->treeGets.haveElement(temp)){
                    //add the element
                    if(this->treeGets.add(temp)){
                        ///RUN GETIN
                        this->elementGetIn(temp);
                    }
                }
            }
        }
    }
};
//QUADTREE64
template <class typeTemplate>
class QuadTree64 : public edk::vector::BinaryTreeCallback<typeTemplate>{
public:
    QuadTree64(){
        this->selected=&this->root;
    }
    virtual ~QuadTree64(){
        this->clean();
    }
    //set the quadtree position and size
    void setPositionAndSize(edk::float64 x,edk::float64 y,edk::float64 width,edk::float64 height){
        this->setRect(edk::rectf64(x,y,width + x,height + y));
    }
    void setPositionAndSize(edk::vec2f64 position,edk::size2f64 size){
        this->setRect(edk::rectf64(position.x,position.y,size.width + position.x,size.height + position.y));
    }
    void setPoints(edk::float64 position1X,edk::float64 position1Y,edk::float64 position2X,edk::float64 position2Y){
        this->setRect(edk::rectf64(position1X,position1Y,position2X,position2Y));
    }
    void setPoints(edk::vec2f64 point1,edk::vec2f64 point2){
        this->setRect(edk::rectf64(point1.x,point1.y,point2.x,point2.y));
    }
    //set the quadTree rectangle
    void setRect(edk::rectf64 rect){
        this->clean(rect);
    }
    void setRect(edk::vec2f64 position,edk::size2f64 size){
        this->clean(edk::rectf64(position,size));
    }
    void setRect(edk::float64 positionX,edk::float64 positionY,edk::float64 width,edk::float64 height){
        this->clean(edk::rectf64(positionX,positionY,width,height));
    }

    //add a object
    bool add(typeTemplate value, edk::uint64 depthLimit=0xFFFFFFFF){
        edk::vector::QuadLeaf64<typeTemplate>* temp = &this->root;
        edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
        bool goInside=false;
        bool deleteQuads=false;
        edk::uint64 depth=0u;
        edk::vector::BinaryTree<typeTemplate>* tree;
        edk::uint64 size = 0u;
        typeTemplate valueTemp;
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
            while(temp){
                //add the value in to the temp
                temp->addToTree(value);

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
                                                      tree4
                                                      )){
                                        //
                                        tree1=tree2=tree3=tree4=NULL;
                                    }
                                    if(tree4)
                                        delete tree4;
                                }
                                if(tree3)
                                    delete tree3;
                            }
                            if(tree2)
                                delete tree2;
                        }
                        if(tree1)
                            delete tree1;
                    }
                }

                //test if have the quads
                if(temp->haveQuads()){
                    deleteQuads=true;
                    goInside=false;
                    //get the temp tree
                    tree = temp->getTreePointer();
                    if(tree){
                        size = tree->size();
                        for(edk::uint8 j=0u;j<size;j++){
                            valueTemp = tree->getElementInPosition(j);
                            for(edk::uint8 i=0u;i<4u;i++){
                                tempQuad = temp->getQuad(i);
                                //test if is colliding with the quads to just add in the tree
                                if(this->isElementColliding(valueTemp,
                                                            edk::vec2f64(this->root.origin.x,
                                                                         this->root.origin.y
                                                                         ),
                                                            edk::vec2f64(this->root.size.width,
                                                                         this->root.size.height
                                                                         )
                                                            )
                                        ){
                                    tempQuad->addToTree(valueTemp);
                                }
                            }
                        }
                    }
                    //test if the value is inside some quad
                    for(edk::uint8 i=0u;i<4u;i++){
                        tempQuad = temp->getQuad(i);
                        //test if is inside the quads
                        if(this->isElementInside(value,
                                                 edk::vec2f64(tempQuad->origin.x,
                                                              tempQuad->origin.y
                                                              ),
                                                 edk::vec2f64(tempQuad->size.width,
                                                              tempQuad->size.height
                                                              )
                                                 )
                                ){
                            temp = tempQuad;
                            goInside=true;
                            break;
                        }
                        else{
                            //test if the tempQuad have some inside the tree
                            if(tempQuad->getTreeSize()){
                                //don't delete the quads
                                deleteQuads=false;
                            }
                        }
                    }
                    if(!goInside){
                        //test if need delete the quads
                        if(deleteQuads){
                            temp->deleteQuads();
                        }
                        temp=NULL;
                    }
                    else{
                        depth++;
                        if(depth>=depthLimit){
                            temp=NULL;
                        }
                    }
                }
                else{
                    temp=NULL;
                }

            }
            return true;
        }
        return false;
    }
    //remove a value from de quadTree
    bool remove(typeTemplate value){
        bool ret=false;
        edk::vector::QuadLeaf64<typeTemplate>* temp = &this->root;
        edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
        bool deleteQuads;
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
            while(temp){
                //remove from it
                if(temp->haveInTree(value)){
                    temp->removeFromTree(value);
                }

                //search for the quads
                if(temp->haveQuads()){
                    if(temp->counter<4u){
                        temp=temp->getQuad(++temp->counter);
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
                        break;
                    }
                }
                else{
                    temp=temp->getFather();
                }
            }
        }
        return ret;
    }

    //select a leaf
    bool selectLeafIWithValue(typeTemplate value){
        this->selected = &this->root;
        bool ret=false;
        if(this->isRectColliding(value,
                                 edk::vec2f64(this->root.origin.x,
                                              this->root.origin.y
                                              ),
                                 edk::vec2f64(this->root.size.width,
                                              this->root.size.height
                                              )
                                 )
                ){
            edk::vector::QuadLeaf64<typeTemplate>* temp = &this->root;
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
            while(temp){
                counter=0u;
                //test the collision with all quads
                if(temp->haveQuads()){
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
                            counter++;
                            nextID = i;
                        }
                    }
                    //test if have one next
                    if(counter==1u){
                        //then get the next
                        this->selected = temp = temp->getQuad(nextID);
                    }
                    else{
                        temp=NULL;
                    }
                }
                else{
                    temp=NULL;
                }
            }
            if(this->selected){
                if(!this->selected->getTreeSize()){
                    if(this->selected->getFather()){
                        this->selected = this->selected->getFather();
                    }
                }
            }
        }
        if(ret){
            this->updateGets();
        }
        return ret;
    }
    bool selectLeafInPoint(edk::vec2f64 point){
        this->selected = &this->root;
        bool ret=false;
        if(this->isPointInside(point,
                               edk::vec2f64(this->root.origin.x,
                                            this->root.origin.y
                                            ),
                               edk::vec2f64(this->root.size.width,
                                            this->root.size.height
                                            )
                               )
                ){
            edk::vector::QuadLeaf64<typeTemplate>* temp = &this->root;
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
            bool needContinue=false;
            while(temp){
                counter=0u;
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
                            this->selected = temp = temp->getQuad(nextID);
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
            if(this->selected){
                if(!this->selected->getTreeSize()){
                    if(this->selected->getFather()){
                        this->selected = this->selected->getFather();
                    }
                }
            }
        }
        if(ret){
            this->updateGets(edk::rectf64(point.x,point.y,point.x,point.y));
        }
        return ret;
    }
    bool selectLeafInRect(edk::rectf64 rect){
        this->selected = &this->root;
        bool ret=false;
        if(this->isRectColliding(rect,
                                 edk::vec2f64(this->root.origin.x,
                                              this->root.origin.y
                                              ),
                                 edk::vec2f64(this->root.size.width,
                                              this->root.size.height
                                              )
                                 )
                ){
            edk::vector::QuadLeaf64<typeTemplate>* temp = &this->root;
            ret=true;
            edk::uint8 counter;
            edk::uint8 nextID;
            edk::vector::QuadLeaf64<typeTemplate>* tempQuad;
            while(temp){
                counter=0u;
                //test the collision with all quads
                if(temp->haveQuads()){
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
                            counter++;
                            nextID = i;
                        }
                    }
                    //test if have one next
                    if(counter==1u){
                        //then get the next
                        this->selected = temp = temp->getQuad(nextID);
                    }
                    else{
                        temp=NULL;
                    }
                }
                else{
                    temp=NULL;
                }
            }
            if(this->selected){
                if(!this->selected->getTreeSize()){
                    if(this->selected->getFather()){
                        this->selected = this->selected->getFather();
                    }
                }
            }
        }
        if(ret){
            this->updateGets(rect);
        }
        return ret;
    }

    //clean the tree
    void clean(edk::rectf64 rect = edk::rectf64(0.f,0.f,1.f,1.f)){
        this->root.clean();
        this->root.setTree(this->newTree());
        this->root.origin = rect.origin;
        this->root.size = rect.size;
        this->selected=&this->root;
    }

    //SELECTED FUNCTIONS
    bool haveSelected(){
        if(this->selected){
            if(this->selected != &this->root){
                return true;
            }
        }
        return false;
    }
    edk::uint64 selectedGetTreeSize(){
        return this->selected->getTreeSize();
    }
    typeTemplate selectedGetElementInPosition(edk::uint64 position){
        return this->selected->getValueFromTreeInPosition(position);
    }
    edk::vector::BinaryTree<typeTemplate>* selectedGetTreePointer(){
        return this->selected->getTreePointer();
    }
    //Load the elements
    virtual void selectedLoad(){
        this->treeGets.load();
    }
    //Unload the elements
    virtual void selectedUnload(){
        this->treeGets.unload();
    }
    //Print the elements
    virtual void selectedPrint(){
        this->treeGets.print();
    }
    //render the elements
    virtual void selectedRender(){
        this->treeGets.render();
    }
    virtual void selectedRenderWire(){
        this->treeGets.renderWire();
    }
    //draw the elements
    virtual void selectedDraw(){
        this->treeGets.draw();
    }
    virtual void selectedDrawWire(){
        this->treeGets.drawWire();
    }
    //update the elements
    virtual void selectedUpdate(){
        this->treeGets.update();
    }

    void drawQuads(){
#ifdef EDK_QUADTREE_GU
        //
        edk::GU::guColor4f64(this->color);
        edk::GU::guPushMatrix();
        edk::GU::guBegin(GU_LINES);
        this->root.drawQUADS();
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

private:
    //quadtree Root
    edk::vector::QuadLeaf64<typeTemplate> root;
    edk::vector::QuadLeaf64<typeTemplate>* selected;
    //binary tree to test if the objects getIn or getOut
    edk::vector::BinaryTree<typeTemplate> treeGets;

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
        if(point1.x <= rect.size.width
                &&
                point2.x>= rect.origin.x
                &&
                point1.y <= rect.size.height
                &&
                point2.y >= rect.origin.y
                )
            return true;
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
    void updateGets(edk::rectf64 rect){
        edk::vector::BinaryTree<typeTemplate>* tree = this->selected->getTreePointer();
        if(tree){
            //first remove the last objects
            edk::uint64 size;
            typeTemplate temp;
            bool decrement = false;
            size = this->treeGets.size();
            for(edk::uint64 i=0u;i<size;i++){
                if(decrement){
                    decrement=false;
                    i--;
                    size--;
                }
                temp = this->treeGets.getElementInPosition(i);
                //test if DON'T have the object inside the temp
                if(!tree->haveElement(temp)
                        &&
                        !this->isElementColliding(temp,
                                                  edk::vec2f64(rect.origin.x,rect.origin.y),
                                                  edk::vec2f64(rect.size.width,rect.size.height)
                                                  )
                        ){
                    //remove the object from the treeGets
                    if(this->treeGets.remove(temp)){
                        //decrement
                        decrement=true;

                        ///RUN GETOUT
                        this->elementGetOut(temp);
                    }
                }
            }
            size = this->treeGets.size();
            decrement = false;
            for(edk::uint64 i=0u;i<size;i++){
                if(decrement){
                    decrement=false;
                    i--;
                    size--;
                }
                temp = this->treeGets.getElementInPosition(i);
                if(temp){
                    if(this->isElementColliding(temp,
                                                edk::vec2f64(rect.origin.x,rect.origin.y),
                                                edk::vec2f64(rect.size.width,rect.size.height)
                                                )
                            ){
                        ///RUN UPDATING
                        this->elementUpdating(temp);
                    }
                    else{
                        //remove the object from the treeGets
                        if(this->treeGets.remove(temp)){
                            //decrement
                            decrement=true;

                            ///RUN GETOUT
                            this->elementGetOut(temp);
                        }
                    }
                }
            }
            size = tree->size();
            for(edk::uint64 i=0u;i<size;i++){
                temp = tree->getElementInPosition(i);
                //test if have the object inside the temp
                if(!this->treeGets.haveElement(temp)
                        &&
                        this->isElementColliding(temp,
                                                 edk::vec2f64(rect.origin.x,rect.origin.y),
                                                 edk::vec2f64(rect.size.width,rect.size.height)
                                                 )
                        ){
                    //add the element
                    if(this->treeGets.add(temp)){
                        ///RUN GETIN
                        this->elementGetIn(temp);
                    }
                }
            }
        }
    }
    void updateGets(){
        edk::vector::BinaryTree<typeTemplate>* tree = this->selected->getTreePointer();
        if(tree){
            //first remove the last objects
            edk::uint64 size;
            typeTemplate temp;
            bool decrement = false;
            size = this->treeGets.size();
            for(edk::uint64 i=0u;i<size;i++){
                if(decrement){
                    decrement=false;
                    i--;
                    size--;
                }
                temp = this->treeGets.getElementInPosition(i);
                //test if DON'T have the object inside the temp
                if(!tree->haveElement(temp)){
                    //remove the object from the treeGets
                    if(this->treeGets.remove(temp)){
                        //decrement
                        decrement=true;

                        ///RUN GETOUT
                        this->elementGetOut(temp);
                    }
                }
            }
            size = this->treeGets.size();
            for(edk::uint64 i=0u;i<size;i++){
                temp = this->treeGets.getElementInPosition(i);
                if(temp){
                    ///RUN UPDATING
                    this->elementUpdating(temp);
                }
            }
            size = tree->size();
            for(edk::uint64 i=0u;i<size;i++){
                temp = tree->getElementInPosition(i);
                //test if have the object inside the temp
                if(!this->treeGets.haveElement(temp)){
                    //add the element
                    if(this->treeGets.add(temp)){
                        ///RUN GETIN
                        this->elementGetIn(temp);
                    }
                }
            }
        }
    }
};

}//edn namespace vector
}//end namespace edk

#endif // QUADTREE_H
