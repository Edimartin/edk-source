#ifndef ASTAR_H
#define ASTAR_H

/*
Library C++ AStar - Find the pathway using A Star algoritm
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
#pragma message "Inside AStar"
#endif

#pragma once
#include <stdio.h>
#include "../TypeColor.h"
#include "../TypeSize2.h"
#include "../vector/Stack.h"
#include "../vector/BinaryTree.h"
#include "../vector/Matrix.h"
#include "../Math.h"

#ifdef printMessages
#pragma message "    Compiling AStar"
#endif

namespace edk{
namespace ai{
class AStar{
public:
    AStar();
    virtual ~AStar();

    void Constructor();
    void Destructor();

    //function aStar
    static bool run(edk::uint32 startX,edk::uint32 startY,
               edk::uint32 destX,edk::uint32 destY,
               edk::vector::MatrixDynamic<edk::uint8>* field,
               edk::vector::Stack<edk::vec2ui32>* result
               );
    static bool run(edk::vec2ui32 start,
               edk::vec2ui32 dest,
               edk::vector::MatrixDynamic<edk::uint8>* field,
               edk::vector::Stack<edk::vec2ui32>* result
               );
private:
    class aStarPosition{
    public:
        aStarPosition(){
            this->position=0u;
            this->walk=0.f;
            this->distance=0.f;
            this->weight=0.f;
            this->father=NULL;
        }
        aStarPosition(edk::vec2ui32 position,edk::vec2ui32 start,edk::vec2ui32 dest,aStarPosition* father){
            this->calculateWeight(position,start,dest);
            this->father=father;
        }
        aStarPosition(edk::uint32 x, edk::uint32 y,edk::vec2ui32 start,edk::vec2ui32 dest,aStarPosition* father){
            this->calculateWeight(edk::vec2ui32(x,y),start,dest);
            this->father=father;
        }
        ~aStarPosition(){}
        edk::vec2ui32 position;
        edk::float32 walk;
        edk::float32 distance;
        edk::float32 weight;
        aStarPosition* father;
        void calculateWeight(edk::vec2ui32 position,edk::vec2ui32 start,edk::vec2ui32 dest){
            this->position = position;
            this->walk=edk::Math::pythagoras(position-start);
            this->distance = edk::Math::pythagoras(dest-position);
            this->weight = this->distance+walk;
        }

        inline bool operator>(aStarPosition position){
            if(this->weight>position.weight){
                return true;
            }
            else if(edk::Math::equal(this->weight,position.weight)
                    &&
                    this->position>position.position
                    ){
                return true;
            }
            return false;
        }
        inline bool operator==(aStarPosition position){
            if(this->position == position.position
                    &&
                    edk::Math::equal(this->weight,position.weight)
                    &&
                    edk::Math::equal(this->walk,position.walk)
                    &&
                    edk::Math::equal(this->distance,position.distance)
                    ){
                return true;
            }
            return false;
        }
        inline aStarPosition operator=(aStarPosition position){
            this->position = position.position;
            this->weight = position.weight;
            this->walk = position.walk;
            this->distance = position.distance;
            this->father = position.father;
            return *this;
        }
        void print(){
            printf("pos[%u,%u] walk[%.2f]weight[%.2f]dist[%.2f]"
                   ,this->position.x
                   ,this->position.y
                   ,this->walk
                   ,this->weight
                   ,this->distance
                   );fflush(stdout);
        }
    };

    class aStarOpened : public edk::vector::BinaryTree<aStarPosition*>{
    public:
        aStarOpened(){}
        ~aStarOpened(){this->clean();}
        //compare if the value is bigger
        virtual bool firstBiggerSecond(aStarPosition* first,aStarPosition* second){
            if(*first>*second){
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(aStarPosition* first,aStarPosition* second){
            if(*first==*second){
                return true;
            }
            return false;
        }

        void clean(){
            aStarPosition* temp;
            edk::uint32 size = this->size();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    delete temp;
                }
            }
            edk::vector::BinaryTree<aStarPosition*>::clean();
        }

        //add a new opened
        bool newOpened(edk::uint32 x,edk::uint32 y,edk::vec2ui32 start,edk::vec2ui32 dest,aStarPosition* father){
            return this->newOpened(edk::vec2ui32(x,y),start,dest,father);
        }
        aStarPosition* newOpened(edk::vec2ui32 position,edk::vec2ui32 start,edk::vec2ui32 dest,aStarPosition* father){
            aStarPosition* temp = new aStarPosition(position,start,dest,father);
            if(temp){
                if(this->add(temp)){
                    return temp;
                }
                delete temp;
            }
            return NULL;
        }
        //remove an opened
        bool removeOpened(aStarPosition* obj){
            if(this->remove(obj)){
                delete obj;
                return true;
            }
            return false;
        }

        bool haveOpened(edk::uint32 x,edk::uint32 y,edk::vec2ui32 start,edk::vec2ui32 dest){
            return this->haveOpened(edk::vec2ui32(x,y),start,dest);
        }
        bool haveOpened(edk::vec2ui32 position,edk::vec2ui32 start,edk::vec2ui32 dest){
            this->templateObj.calculateWeight(position,start,dest);
            return this->haveElement(&this->templateObj);
        }
    protected:
        aStarPosition templateObj;
    };
    class aStarClosed : public edk::vector::BinaryTree<aStarPosition*>{
    public:
        aStarClosed(){}
        ~aStarClosed(){this->clean();}
        //compare if the value is bigger
        virtual bool firstBiggerSecond(aStarPosition* first,aStarPosition* second){
            if(first->position>second->position){
                return true;
            }
            return false;
        }
        //compare if the value is equal
        virtual bool firstEqualSecond(aStarPosition* first,aStarPosition* second){
            if(first->position==second->position){
                return true;
            }
            return false;
        }

        void clean(){
            aStarPosition* temp;
            edk::uint32 size = this->size();
            for(edk::uint32 i=0u;i<size;i++){
                temp = this->getElementInPosition(i);
                if(temp){
                    delete temp;
                }
            }
            edk::vector::BinaryTree<aStarPosition*>::clean();
        }

        //add a new opened
        bool newClosed(edk::uint32 x,edk::uint32 y){
            return this->newClosed(edk::vec2ui32(x,y));
        }
        aStarPosition* newClosed(edk::vec2ui32 position){
            aStarPosition* temp = new aStarPosition;
            if(temp){
                temp->position=position;
                if(this->add(temp)){
                    return temp;
                }
                delete temp;
            }
            return NULL;
        }
        //remove an opened
        bool removeClosed(aStarPosition* obj){
            if(this->remove(obj)){
                delete obj;
                return true;
            }
            return false;
        }

        bool haveClosed(edk::uint32 x,edk::uint32 y){
            return this->haveClosed(edk::vec2ui32(x,y));
        }
        bool haveClosed(edk::vec2ui32 position){
            this->templateObj.position=position;
            return this->haveElement(&this->templateObj);
        }
    protected:
        aStarPosition templateObj;
    };
private:
    edk::classID classThis;
};
}//end namespace ai
}//end namespace edk

#endif // ASTAR_H
