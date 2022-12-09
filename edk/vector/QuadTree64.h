#ifndef QUADTREE64_H
#define QUADTREE64_H

/*
Library QuadTree64 - Create a quadTree with 64 bits rect in EDK Game Engine
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
#warning "Inside QuadTree64"
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
#warning "    Compiling QuadTree64"
#endif


/*
//code sample

//QuadTree

class QuadtreePoints:public edk::vector::QuadTree64<edk::vec2f32>{
public:
    QuadtreePoints(){}
    virtual ~QuadtreePoints(){}

    virtual edk::vector::QuadtreeCollisionTypes isElementInside(edk::vec2f32 element,edk::vec2f32 point1,edk::vec2f32 point2){
        if(element.x >= point1.x
                &&
                element.y >= point1.y
                &&
                element.x < point2.x
                &&
                element.y < point2.y
                ){
            return edk::vector::quadtreeObjectFullInside;
        }
        return edk::vector::quadtreeObjectOutside;
    }
};

class QuadtreeRectangles:public edk::vector::QuadTree64<edk::rectf32>{
public:
    QuadtreeRectangles(){}
    virtual ~QuadtreeRectangles(){}

    virtual edk::vector::QuadtreeCollisionTypes isElementInside(edk::rectf32 element,edk::vec2f32 point1,edk::vec2f32 point2){
        if(element.origin.x >= point1.x
                &&
                element.origin.y >= point1.y
                &&
                element.origin.x < point2.x
                &&
                element.origin.y < point2.y
                ){
            if(element.size.width >= point1.x
                    &&
                    element.size.height >= point1.y
                    &&
                    element.size.width < point2.x
                    &&
                    element.size.height < point2.y
                    ){
                return edk::vector::quadtreeObjectFullInside;
            }
            return edk::vector::quadtreeObjectHalfInside;
        }
        else if(element.size.width >= point1.x
                &&
                element.size.height >= point1.y
                &&
                element.size.width < point2.x
                &&
                element.size.height < point2.y
                ){
            return edk::vector::quadtreeObjectHalfInside;
        }
        return edk::vector::quadtreeObjectOutside;
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
    }
    QuadLeaf32(QuadLeaf32* father,edk::rectf32 rect = edk::rectf32(0,0,1,1),edk::uint8 id=1u){
        this->father=father;
        //start the values
        this->origin = rect.origin;
        this->size = rect.size;
        this->id = id;
        //
        this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;
    }
    ~QuadLeaf32(){
        this->clean();
    }
    void clean(){
        this->father=NULL;
        this->tree.clean();
        this->deleteQuads();
    }
    //new quads
    bool newQuads(){
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
    edk::vector::BinaryTree<typeTemplate> tree;

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


template <class typeTemplate>
class QuadTree32{
public:
    QuadTree32(){}
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
    bool add(typeTemplate value){
        //test if have quads inside
        edk::vector::QuadLeaf32<typeTemplate>* temp = &this->root;
        edk::uint8 id=0u;
        bool createNewQuads=true;
        bool ret=false;

        while(temp){
            //test if the value is inside
            if(this->isElementInside(value,
                                     edk::vec2f32(this->root.origin.x,
                                                  this->root.origin.y
                                                  ),
                                     edk::vec2f32(this->root.size.width,
                                                  this->root.size.height
                                                  )
                                     )
                    ){
                //add the value in to the leaf
            }
            else{
                //test if the id is zero
                if(!id){
                    //finish the new quads
                    break;
                }
            }

            //add the value in to the leaf
            ret=true;


            //test if need create new quads
            if(createNewQuads){
                //test if don't have quads
                if(!temp->haveQuads()){
                    //create new quads
                    temp->newQuads();
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
        return ret;
    }

    //clean the tree
    void clean(edk::rectf32 rect = edk::rectf32(0.f,0.f,1.f,1.f)){
        this->root.clean();
        this->root.origin = rect.origin;
        this->root.size = rect.size;
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
    virtual bool isPointInside(edk::vec2f32 point,edk::vec2f32 point1,edk::vec2f32 point2){
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

private:
    //quadtree Root
    edk::vector::QuadLeaf32<typeTemplate> root;
};


}//edn namespace vector
}//end namespace edk

#endif // QUADTREE64_H
