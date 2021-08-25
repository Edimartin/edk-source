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
#include "../TypeRect.h"
#include "Stack.h"

#ifdef EDK_QUADTREE_GU
#include "../GU.h"
#endif

#ifdef printMessages
#warning "    Compiling QuadTree64"
#endif

namespace edk{
namespace vector{
template <class typeTemplate>
class QuadLeaf64 : public edk::rectf64{
    //Construtor
public:
    QuadLeaf64(edk::rectf64 rect = edk::rectf64(0,0,1,1),edk::uint8 id=1u){
        //start the values
        this->origin = rect.origin;
        this->size = rect.size;
        this->id = id;
        //
        this->quad[0u] = this->quad[1u] = this->quad[2u] = this->quad[3u] = NULL;
        //this->value=(typeTemplate)0u;
        this->thisHaveValue = false;
    }
    //Destrutor
    ~QuadLeaf64(){
        this->deleteQuads();
    }
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
    //new quads
    bool newQuads(edk::vec2f64 position){
        this->deleteQuads();

        if((this->quad[0u] = new edk::vector::QuadLeaf64<typeTemplate>(edk::rectf64(this->origin.x,
                                                                                    this->origin.y,
                                                                                    this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                    this->origin.y+((this->size.height - this->origin.y)*0.5)
                                                                                    ),1u
                                                                       )
            )
                ){
            if((this->quad[1u] = new edk::vector::QuadLeaf64<typeTemplate>(edk::rectf64(this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                        this->origin.y,
                                                                                        this->size.width,
                                                                                        this->origin.y+((this->size.height - this->origin.y)*0.5)
                                                                                        ),2u
                                                                           )
                )
                    ){
                if((this->quad[2u] = new edk::vector::QuadLeaf64<typeTemplate>(edk::rectf64(this->origin.x+((this->size.width - this->origin.x)*0.5),
                                                                                            this->origin.y+((this->size.height - this->origin.y)*0.5),
                                                                                            this->size.width,
                                                                                            this->size.height
                                                                                            ),3u
                                                                               )
                    )
                        ){
                    if((this->quad[3u] = new edk::vector::QuadLeaf64<typeTemplate>(edk::rectf64(this->origin.x,
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

/*
        if((this->quad[0u] = new edk::vector::QuadLeaf64<typeTemplate>(edk::rectf64(this->origin.x,
                                                                                    this->origin.y,
                                                                                    position.x,
                                                                                    position.y
                                                                                    )
                                                                       )
            )
                ){
            if((this->quad[1u] = new edk::vector::QuadLeaf64<typeTemplate>(edk::rectf64(position.x,
                                                                                        this->origin.y,
                                                                                        this->size.width,
                                                                                        position.y
                                                                                        )
                                                                           )
                )
                    ){
                if((this->quad[2u] = new edk::vector::QuadLeaf64<typeTemplate>(edk::rectf64(position.x,
                                                                                            position.y,
                                                                                            this->size.width,
                                                                                            this->size.height
                                                                                            )
                                                                               )
                    )
                        ){
                    if((this->quad[3u] = new edk::vector::QuadLeaf64<typeTemplate>(edk::rectf64(this->origin.x,
                                                                                                position.y,
                                                                                                position.x,
                                                                                                this->size.height
                                                                                                )
                                                                                   )
                        )
                            ){
                        //
                        return true;
                    }
                    //
                    delete this->quad[2u];this->quad[2u]=NULL;
                }
                //
                delete this->quad[1u];this->quad[1u]=NULL;
            }
            //
            delete this->quad[0u];this->quad[0u]=NULL;
        }
*/
        return false;
    }
    //test if the point gonna be inside
    bool isInside(edk::vec2f64 point){
        if(point.x >= this->origin.x
                &&
                point.y >= this->origin.y
                &&
                point.x < this->size.width
                &&
                point.y < this->size.height
                ){
            return true;
        }
        return false;
    }
    //return true if this need to be deleted
    bool needDeleted(){
        if(this->quad[0u]
                ||
                this->thisHaveValue
                ){
            return false;
        }
        return true;
    }
    //add new point
    bool addNew(typeTemplate value, edk::vec2f64 position){
        //test if the point is inside
        if(this->isInside(position)){
            if(!this->quad[0u]){
                //test if have the value
                if(this->thisHaveValue){
                    //create the new quads
                    this->newQuads(position);
                }
                else{
                    this->value = value;
                    this->position = position;
                    this->thisHaveValue=true;
                    return true;
                }
            }
            if(this->quad[0u]){
                //then test if have the value
                if(this->thisHaveValue){
                    //test the value in other quads
                    for(edk::uint32 i=0u;i<4u;i++){
                        if(this->quad[i]->addNew(this->value,this->position)){
                            //
                            this->thisHaveValue=false;
                            break;
                        }
                    }
                }
                //now test id dont have the value
                if(!this->thisHaveValue){
                    bool ret=false;
                    //add the new value to another quads
                    for(edk::uint32 i=0u;i<4u;i++){
                        if((ret=this->quad[i]->addNew(value,position))){
                            //
                            break;
                        }
                    }
                    return ret;
                }
            }
        }
        //
        return false;
    }
    bool removeValue(edk::vec2f64 position,bool* tryRemove){
        //test if the point is inside
        if(this->isInside(position)){
            if(this->quad[0u]){
                bool ret=false;
                //test remove from quads
                for(edk::uint32 i=0u;i<4u;i++){
                    if((ret=this->quad[i]->removeValue(position,tryRemove))){
                        //
                        break;
                    }
                }
                //test if need remove the quads
                if(*tryRemove){
                    *tryRemove=false;
                    //test the quads
                    for(edk::uint32 i=0u;i<4u;i++){
                        if(!this->quad[i]->needDeleted()){
                            *tryRemove=true;
                            break;
                        }
                    }
                    if(*tryRemove){
                        *tryRemove=false;
                    }
                    else{
                        //remove all the quads
                        this->deleteQuads();
                        return true;
                    }
                }
                return ret;
            }
            else if(this->thisHaveValue){
                //remove the value
                this->thisHaveValue=false;
                *tryRemove = true;
                return true;
            }
        }
        return false;
    }
    //return the value
    typeTemplate getValue(edk::vec2f64 position,bool* founded){
        typeTemplate zero;
        //test if the point is inside
        if(this->isInside(position)){
            //test if have the quads
            if(this->quad[0u]){
                typeTemplate ret;
                //find the value inside the quads
                for(edk::uint32 i=0u;i<4u;i++){
                    ret=this->quad[i]->getValue(position,founded);
                    if(*founded){
                        return ret;
                    }
                }
            }
            else{
                //test if have the value
                if(this->thisHaveValue){
                    //return the value
                    *founded=true;
                    return this->value;
                }
            }
        }
        return zero;
    }
    //return a list of values
    bool getValues(edk::vec2f64 position,edk::vector::Stack<typeTemplate>* list,edk::uint32* limit,bool *findLeaf){
        if(*findLeaf){
            //if(list->size()){
            if(this->quad[0u]){
                //find the others values
                for(edk::uint32 i=0u;i<4u;i++){
                    //test the limit
                    if(*limit){
                        this->quad[i]->getValues(position,list,limit,findLeaf);
                    }
                }
                return true;
            }
            else{
                //test if have the value
                if(this->thisHaveValue){
                    //add to the list
                    list->pushBack(this->value);
                    if(limit[0u]){
                        limit[0u]-=1;
                    }
                    return true;
                }
            }
        }
        else if(this->isInside(position)){
            //test if have the quads
            if(this->quad[0u]){
                edk::uint8 quadN=0u;
                //find the value inside the quads
                for(edk::uint32 i=0u;i<4u;i++){
                    //
                    if(this->quad[i]->getValues(position,list,limit,findLeaf)){
                        //
                        quadN = ++i;
                        break;
                    }
                }
                *findLeaf=true;
                //test the other quads
                if(limit[0u])
                    switch(quadN){
                    case 0u:
                        this->quad[0u]->getValues(position,list,limit,findLeaf);
                        this->quad[1u]->getValues(position,list,limit,findLeaf);
                        this->quad[2u]->getValues(position,list,limit,findLeaf);
                        this->quad[3u]->getValues(position,list,limit,findLeaf);
                        break;
                    case 1u:
                        this->quad[1u]->getValues(position,list,limit,findLeaf);
                        this->quad[2u]->getValues(position,list,limit,findLeaf);
                        this->quad[3u]->getValues(position,list,limit,findLeaf);
                        break;
                    case 2u:
                        this->quad[0u]->getValues(position,list,limit,findLeaf);
                        this->quad[2u]->getValues(position,list,limit,findLeaf);
                        this->quad[3u]->getValues(position,list,limit,findLeaf);
                        break;
                    case 3u:
                        this->quad[0u]->getValues(position,list,limit,findLeaf);
                        this->quad[1u]->getValues(position,list,limit,findLeaf);
                        this->quad[3u]->getValues(position,list,limit,findLeaf);
                        break;
                    case 4u:
                        this->quad[0u]->getValues(position,list,limit,findLeaf);
                        this->quad[1u]->getValues(position,list,limit,findLeaf);
                        this->quad[2u]->getValues(position,list,limit,findLeaf);
                        break;
                    }
                return true;
            }
            else{
                //test if have the value
                if(this->thisHaveValue){
                    //add to the list
                    list->pushBack(this->value);
                    if(limit[0u]){
                        limit[0u]-=1;
                    }
                    return true;
                }
            }
        }
        return false;
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

        if(this->thisHaveValue){
            //draw the value position
            edk::GU::guVertex2f64(this->position.x-0.01f,this->position.y-0.01f);
            edk::GU::guVertex2f64(this->position.x+0.01f,this->position.y+0.01f);
            edk::GU::guVertex2f64(this->position.x-0.01f,this->position.y+0.01f);
            edk::GU::guVertex2f64(this->position.x+0.01f,this->position.y-0.01f);
        }

        //go to the others quads
        if(this->quad[0u]){
            for(edk::uint32 i=0u;i<4u;i++){
                this->quad[i]->drawQUADS();
            }
        }
    }
#endif

private:
    //RIGHT
    QuadLeaf64* quad[4u];

    //Value of the leaf
    bool thisHaveValue;
    typeTemplate value;
    edk::vec2f64 position;
    edk::uint8 id;
};
template <class typeTemplate>
class QuadTree64{
public:
    QuadTree64(){
        this->position = edk::vec2f64(0,0);
        this->size = edk::size2f64(1,1);
    }
    virtual ~QuadTree64(){
        //
    }

    //add a object
    bool add(typeTemplate value, edk::vec2f64 position){
        return this->root.addNew(value,this->filterPosition(position));
    }
    bool add(typeTemplate value, edk::vec2f32 position){
        return this->add(value, edk::vec2f64(position.x,position.y));
    }
    bool remove(edk::vec2f64 position){
        bool tryRemove = false;
        return this->root.removeValue(this->filterPosition(position),&tryRemove);
    }
    bool remove(edk::vec2f32 position){
        return this->remove(edk::vec2f64(position.x,position.y));
    }
    //get the value in position
    typeTemplate getElement(edk::vec2f64 position){
        bool founded=false;
        return this->root.getValue(position,&founded);
    }
    typeTemplate getElement(edk::vec2f32 position){
        return this->getElement(edk::vec2f64(position.x,position.y));
    }
    edk::vector::Stack<typeTemplate>* getElements(edk::vec2f64 position,edk::uint32 elements){
        if(elements){
            edk::vector::Stack<typeTemplate>* list = new edk::vector::Stack<typeTemplate>(elements);
            if(list){
                bool findLeaf=false;
                this->root.getValues(position,list,&elements,&findLeaf);
                return list;
            }
        }
        return NULL;
    }
    edk::vector::Stack<typeTemplate>* getElements(edk::vec2f32 position,edk::uint32 elements){
        return this->getElements(edk::vec2f64(position.x,position.y),elements);
    }

    //clean the tree
    void clean(){
        this->root.deleteQuads();
    }

#ifdef EDK_QUADTREE_GU
    void draw(){
        //
        edk::GU::guColor4f32(this->color);
        edk::GU::guPushMatrix();
        edk::GU::guScale2f64(this->size);
        edk::GU::guTranslate2f64(this->position);
        edk::GU::guBegin(GU_LINES);
        this->root.drawQUADS();
        edk::GU::guEnd();
        edk::GU::guPopMatrix();
    }
    edk::color4f32 color;
#endif

private:
    //size of the quadtree
    edk::vec2f64 position;
    edk::size2f64 size;
    //quadtree Root
    edk::vector::QuadLeaf64<typeTemplate> root;
    //filter the position
    edk::vec2f64 filterPosition(edk::vec2f64 position){
        position -= this->position;
        position.x = position.x/this->size.width;
        position.y = position.y/this->size.height;
        return position;
    }
};
}//edn namespace vector
}//end namespace edk

#endif // QUADTREE64_H
