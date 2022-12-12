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
};
*/






namespace edk{
namespace vector{
//LEAF32
template <class typeTemplate>
class QuadLeaf32 : public edk::rectf32{
public:
    QuadLeaf32(edk::rectf32 rect = edk::rectf32(0,0,1,1),edk::uint8 id=1u){
        this->father=NULL;
        //start the values
        this->origin = rect.origin;
        this->size = rect.size;
        this->id = id;
        //
        this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;

        //add a callback in to the tree
        this->setTree(NULL);
    }
    QuadLeaf32(QuadLeaf32* father,edk::rectf32 rect = edk::rectf32(0,0,1,1),edk::uint8 id=1u){
        this->father=father;
        //start the values
        this->origin = rect.origin;
        this->size = rect.size;
        this->id = id;
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

        if((this->quad[0u] = new edk::vector::QuadLeaf32<typeTemplate>(this,edk::rectf32(this->origin.x,
                                                                                         this->origin.y,
                                                                                         this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                         this->origin.y+((this->size.height - this->origin.y)*0.5)
                                                                                         ),1u
                                                                       )
            )
                ){
            if((this->quad[1u] = new edk::vector::QuadLeaf32<typeTemplate>(this,edk::rectf32(this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                             this->origin.y,
                                                                                             this->size.width,
                                                                                             this->origin.y+((this->size.height - this->origin.y)*0.5)
                                                                                             ),2u
                                                                           )
                )
                    ){
                if((this->quad[2u] = new edk::vector::QuadLeaf32<typeTemplate>(this,edk::rectf32(this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                                 this->origin.y+((this->size.height - this->origin.y)*0.5),
                                                                                                 this->size.width,
                                                                                                 this->size.height
                                                                                                 ),3u
                                                                               )
                    )
                        ){
                    if((this->quad[3u] = new edk::vector::QuadLeaf32<typeTemplate>(this,edk::rectf32(this->origin.x,
                                                                                                     this->origin.y+((this->size.height - this->origin.y)*0.5),
                                                                                                     this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                                     this->size.height
                                                                                                     ),4u
                                                                                   )
                        )
                            ){
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



#ifdef EDK_QUADTREE_GU
    void drawQUADS(){
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
    }
#endif
private:
    //RIGHT
    edk::vector::QuadLeaf32<typeTemplate>* quad[4u];
    edk::vector::QuadLeaf32<typeTemplate>* father;
    edk::uint8 id;
    //tree with values
    edk::vector::BinaryTree<typeTemplate> treeThis;
    edk::vector::BinaryTree<typeTemplate>* tree;

    //destroi the quads
    void deleteQuads(){
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
};
//LEAF64
template <class typeTemplate>
class QuadLeaf64 : public edk::rectf64{
public:
    QuadLeaf64(edk::rectf64 rect = edk::rectf64(0,0,1,1),edk::uint8 id=1u){
        this->father=NULL;
        //start the values
        this->origin = rect.origin;
        this->size = rect.size;
        this->id = id;
        //
        this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;

        //add a callback in to the tree
        this->setTree(NULL);
    }
    QuadLeaf64(QuadLeaf64* father,edk::rectf64 rect = edk::rectf64(0,0,1,1),edk::uint8 id=1u){
        this->father=father;
        //start the values
        this->origin = rect.origin;
        this->size = rect.size;
        this->id = id;
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

        if((this->quad[0u] = new edk::vector::QuadLeaf64<typeTemplate>(this,edk::rectf64(this->origin.x,
                                                                                         this->origin.y,
                                                                                         this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                         this->origin.y+((this->size.height - this->origin.y)*0.5)
                                                                                         ),1u
                                                                       )
            )
                ){
            if((this->quad[1u] = new edk::vector::QuadLeaf64<typeTemplate>(this,edk::rectf64(this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                             this->origin.y,
                                                                                             this->size.width,
                                                                                             this->origin.y+((this->size.height - this->origin.y)*0.5)
                                                                                             ),2u
                                                                           )
                )
                    ){
                if((this->quad[2u] = new edk::vector::QuadLeaf64<typeTemplate>(this,edk::rectf64(this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                                 this->origin.y+((this->size.height - this->origin.y)*0.5),
                                                                                                 this->size.width,
                                                                                                 this->size.height
                                                                                                 ),3u
                                                                               )
                    )
                        ){
                    if((this->quad[3u] = new edk::vector::QuadLeaf64<typeTemplate>(this,edk::rectf64(this->origin.x,
                                                                                                     this->origin.y+((this->size.height - this->origin.y)*0.5),
                                                                                                     this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                                     this->size.height
                                                                                                     ),4u
                                                                                   )
                        )
                            ){
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



#ifdef EDK_QUADTREE_GU
    void drawQUADS(){
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
    }
#endif
private:
    //RIGHT
    edk::vector::QuadLeaf64<typeTemplate>* quad[4u];
    edk::vector::QuadLeaf64<typeTemplate>* father;
    edk::uint8 id;
    //tree with values
    edk::vector::BinaryTree<typeTemplate> treeThis;
    edk::vector::BinaryTree<typeTemplate>* tree;

    //destroi the quads
    void deleteQuads(){
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
        //test if have quads inside
        edk::vector::QuadLeaf32<typeTemplate>* temp = &this->root;
        edk::uint8 id=0u;
        bool createNewQuads=true;
        bool ret=false;
        edk::uint32 depth=0u;
        while(temp){
            //test if the value is inside
            if(this->isElementInside(value,
                                     edk::vec2f32(temp->origin.x,
                                                  temp->origin.y
                                                  ),
                                     edk::vec2f32(temp->size.width,
                                                  temp->size.height
                                                  )
                                     )
                    ){
                //add the value in to the leaf
                temp->addToTree(value);
                id=0u;
                ret=true;
            }
            else{
                //test if the id is zero
                if(!id){
                    //finish the new quads
                    break;
                }
                createNewQuads=false;
            }
            //test if need create new quads
            if(createNewQuads){
                //test if don't have quads
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
            }
            else{
                createNewQuads=true;
            }
            //searh for the quads
            switch(id){
            case 0u:
                //go to the quad 0
                if(temp->haveQuads()){
                    temp = temp->getQuad(0u);
                    id++;
                    depth++;
                }
                else{
                    temp=NULL;
                }
                break;
            case 1u:
                //go to the quad 1
                temp = temp->getFather();
                depth--;
                if(temp){
                    temp = temp->getQuad(1u);
                    id++;
                    depth++;
                }
                break;
            case 2u:
                //go to the quad 2
                temp = temp->getFather();
                depth--;
                if(temp){
                    temp = temp->getQuad(2u);
                    id++;
                    depth++;
                }
                break;
            case 3u:
                //go to the quad 3
                temp = temp->getFather();
                depth--;
                if(temp){
                    temp = temp->getQuad(3u);
                    id=0u;
                    depth++;
                }
                break;
            }
            //test if the depth is bigger then limit
            if(depth>depthLimit){
                temp=NULL;
            }
        }
        return ret;
    }
    //remove a value from de quadTree
    bool remove(typeTemplate value){
        //test if have quads inside
        edk::vector::QuadLeaf32<typeTemplate>* temp = &this->root;
        edk::uint8 id=0u;
        bool ret=false;
        while(temp){
            //test if the value is inside
            if(this->isElementInside(value,
                                     edk::vec2f32(temp->origin.x,
                                                  temp->origin.y
                                                  ),
                                     edk::vec2f32(temp->size.width,
                                                  temp->size.height
                                                  )
                                     )
                    ){
                //remove the value from the tree
                if(temp->removeFromTree(value)){
                    ret=true;
                }
                id=0u;
            }
            else{
                //test if the id is zero
                if(!id){
                    //finish the new quads
                    break;
                }
            }
            //searh for the quads
            switch(id){
            case 0u:
                //go to the quad 0
                if(temp->haveQuads()){
                    temp = temp->getQuad(0u);
                    id++;
                }
                else{
                    temp=NULL;
                }
                break;
            case 1u:
                //go to the quad 1
                temp = temp->getFather();
                if(temp){
                    temp = temp->getQuad(1u);
                    id++;
                }
                break;
            case 2u:
                //go to the quad 2
                temp = temp->getFather();
                if(temp){
                    temp = temp->getQuad(2u);
                    id++;
                }
                break;
            case 3u:
                //go to the quad 3
                temp = temp->getFather();
                if(temp){
                    temp = temp->getQuad(3u);
                    id=0u;
                }
                break;
            }
        }
        return false;
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
        this->selected->treeLoad();
    }
    //Unload the elements
    virtual void selectedUnload(){
        this->selected->treeUnload();
    }
    //Print the elements
    virtual void selectedPrint(){
        this->selected->treePrint();
    }
    //render the elements
    virtual void selectedRender(){
        this->selected->treeRender();
    }
    virtual void selectedRenderWire(){
        this->selected->treeRenderWire();
    }
    //draw the elements
    virtual void selectedDraw(){
        this->selected->treeDraw();
    }
    virtual void selectedDrawWire(){
        this->selected->treeDrawWire();
    }
    //update the elements
    virtual void selectedUpdate(){
        this->selected->treeUpdate();
    }

#ifdef EDK_QUADTREE_GU
    void draw(){
        //
        edk::GU::guColor4f32(this->color);
        edk::GU::guPushMatrix();
        edk::GU::guBegin(GU_LINES);
        this->root.drawQUADS();
        edk::GU::guEnd();
        edk::GU::guPopMatrix();
    }
    edk::color4f32 color;
#endif

protected:
    //test if the object is inside the leaf
    virtual bool isElementInside(typeTemplate ,edk::vec2f32 ,edk::vec2f32 ){
        return false;
    }
    //function to create a new tree
    virtual edk::vector::BinaryTree<typeTemplate>* newTree(){
        return new edk::vector::BinaryTree<typeTemplate>;
    }

private:
    //quadtree Root
    edk::vector::QuadLeaf32<typeTemplate> root;
    edk::vector::QuadLeaf32<typeTemplate>* selected;

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
    bool add(typeTemplate value, edk::uint64 depthLimit=0xFFFFFFFFFFFFFFFF){
        //test if have quads inside
        edk::vector::QuadLeaf64<typeTemplate>* temp = &this->root;
        edk::uint8 id=0u;
        bool createNewQuads=true;
        bool ret=false;
        edk::uint64 depth=0u;
        while(temp){
            //test if the value is inside
            if(this->isElementInside(value,
                                     edk::vec2f64(temp->origin.x,
                                                  temp->origin.y
                                                  ),
                                     edk::vec2f64(temp->size.width,
                                                  temp->size.height
                                                  )
                                     )
                    ){
                //add the value in to the leaf
                temp->addToTree(value);
                id=0u;
                ret=true;
            }
            else{
                //test if the id is zero
                if(!id){
                    //finish the new quads
                    break;
                }
                createNewQuads=false;
            }
            //test if need create new quads
            if(createNewQuads){
                //test if don't have quads
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
            }
            else{
                createNewQuads=true;
            }
            //searh for the quads
            switch(id){
            case 0u:
                //go to the quad 0
                if(temp->haveQuads()){
                    temp = temp->getQuad(0u);
                    id++;
                    depth++;
                }
                else{
                    temp=NULL;
                }
                break;
            case 1u:
                //go to the quad 1
                temp = temp->getFather();
                depth--;
                if(temp){
                    temp = temp->getQuad(1u);
                    id++;
                    depth++;
                }
                break;
            case 2u:
                //go to the quad 2
                temp = temp->getFather();
                depth--;
                if(temp){
                    temp = temp->getQuad(2u);
                    id++;
                    depth++;
                }
                break;
            case 3u:
                //go to the quad 3
                temp = temp->getFather();
                depth--;
                if(temp){
                    temp = temp->getQuad(3u);
                    id=0u;
                    depth++;
                }
                break;
            }
            //test if the depth is bigger then limit
            if(depth>depthLimit){
                temp=NULL;
            }
        }
        return ret;
    }
    //remove a value from de quadTree
    bool remove(typeTemplate value){
        //test if have quads inside
        edk::vector::QuadLeaf64<typeTemplate>* temp = &this->root;
        edk::uint8 id=0u;
        bool ret=false;
        while(temp){
            //test if the value is inside
            if(this->isElementInside(value,
                                     edk::vec2f64(temp->origin.x,
                                                  temp->origin.y
                                                  ),
                                     edk::vec2f64(temp->size.width,
                                                  temp->size.height
                                                  )
                                     )
                    ){
                //remove the value from the tree
                if(temp->removeFromTree(value)){
                    ret=true;
                }
                id=0u;
            }
            else{
                //test if the id is zero
                if(!id){
                    //finish the new quads
                    break;
                }
            }
            //searh for the quads
            switch(id){
            case 0u:
                //go to the quad 0
                if(temp->haveQuads()){
                    temp = temp->getQuad(0u);
                    id++;
                }
                else{
                    temp=NULL;
                }
                break;
            case 1u:
                //go to the quad 1
                temp = temp->getFather();
                if(temp){
                    temp = temp->getQuad(1u);
                    id++;
                }
                break;
            case 2u:
                //go to the quad 2
                temp = temp->getFather();
                if(temp){
                    temp = temp->getQuad(2u);
                    id++;
                }
                break;
            case 3u:
                //go to the quad 3
                temp = temp->getFather();
                if(temp){
                    temp = temp->getQuad(3u);
                    id=0u;
                }
                break;
            }
        }
        return false;
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
        this->selected->treeLoad();
    }
    //Unload the elements
    virtual void selectedUnload(){
        this->selected->treeUnload();
    }
    //Print the elements
    virtual void selectedPrint(){
        this->selected->treePrint();
    }
    //render the elements
    virtual void selectedRender(){
        this->selected->treeRender();
    }
    virtual void selectedRenderWire(){
        this->selected->treeRenderWire();
    }
    //draw the elements
    virtual void selectedDraw(){
        this->selected->treeDraw();
    }
    virtual void selectedDrawWire(){
        this->selected->treeDrawWire();
    }
    //update the elements
    virtual void selectedUpdate(){
        this->selected->treeUpdate();
    }

#ifdef EDK_QUADTREE_GU
    void draw(){
        //
        edk::GU::guColor4f64(this->color);
        edk::GU::guPushMatrix();
        edk::GU::guBegin(GU_LINES);
        this->root.drawQUADS();
        edk::GU::guEnd();
        edk::GU::guPopMatrix();
    }
    edk::color4f64 color;
#endif

protected:
    //test if the object is inside the leaf
    virtual bool isElementInside(typeTemplate ,edk::vec2f64 ,edk::vec2f64 ){
        return false;
    }
    //function to create a new tree
    virtual edk::vector::BinaryTree<typeTemplate>* newTree(){
        return new edk::vector::BinaryTree<typeTemplate>;
    }

private:
    //quadtree Root
    edk::vector::QuadLeaf64<typeTemplate> root;
    edk::vector::QuadLeaf64<typeTemplate>* selected;

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
};

}//edn namespace vector
}//end namespace edk

#endif // QUADTREE_H
