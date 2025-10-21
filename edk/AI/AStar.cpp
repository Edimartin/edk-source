#include "AStar.h"

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
#pragma message "            Inside AStar.cpp"
#endif

edk::ai::AStar::AStar(){
    //
    this->classThis=NULL;
    this->Constructor();
}
edk::ai::AStar::~AStar(){
    this->Destructor();
}

void edk::ai::AStar::Constructor(){
    //
    if(this->classThis!=this){
        this->classThis=this;
    }
}
void edk::ai::AStar::Destructor(){
    if(this->classThis==this){
        this->classThis=NULL;
    }
}

//function aStar
bool edk::ai::AStar::run(edk::uint32 startX,edk::uint32 startY,
                         edk::uint32 destX,edk::uint32 destY,
                         edk::vector::MatrixDynamic<edk::uint8>* field,
                         edk::vector::Stack<edk::vec2ui32>* result
                         ){
    return edk::ai::AStar::run(edk::vec2ui32(startX,startY),
                               edk::vec2ui32(destX,destY),
                               field,
                               result
                               );
}
bool edk::ai::AStar::run(edk::vec2ui32 start,
                         edk::vec2ui32 dest,
                         edk::vector::MatrixDynamic<edk::uint8>* field,
                         edk::vector::Stack<edk::vec2ui32>* result
                         ){
    if(field && result){
        if(field->haveMatrix()
                &&
                field->have(start)
                &&
                field->have(dest)
                &&
                field->size().width
                &&
                field->size().height
                ){
            //
            aStarOpened nexts;
            aStarClosed closed;
            aStarPosition* temp=NULL;
            aStarPosition* father=NULL;
            edk::uint32 minus=0u;
            edk::vec2ui32 position;
            edk::vec2ui32 fieldSize = edk::vec2ui32(field->size().width-1u,field->size().height-1u);

            position = start;

            //create the first node
            father = closed.newClosed(position);

            edk::uint32 startX,startY,endX,endY;

            while(true){
                position = father->position;
                //first populate the nexts with the positions
                if(position.x && position.y){
                    startX=position.x-1u;
                    startY=position.y-1u;
                }
                else if(position.x){
                    startX=position.x-1u;
                    startY=position.y;
                }
                else if(position.y){
                    startX=position.x;
                    startY=position.y-1u;
                }
                if(position.x<fieldSize.x && position.y<fieldSize.y){
                    endX=position.x+1u;
                    endY=position.y+1u;
                }
                else if(position.x < fieldSize.x){
                    endX=position.x+1u;
                    endY=position.y;
                }
                else if(position.y < fieldSize.y){
                    endX=position.x;
                    endY=position.y+1u;
                }

                for(edk::uint32 y = startY;y<=endY;y++){
                    for(edk::uint32 x = startX;x<=endX;x++){
                        if(dest.x == x && dest.y == y){
                            result->pushBack(edk::vec2ui32(x,y));
                            if(result->size()){
                                while(father){
                                    result->pushBack(edk::vec2ui32(father->position.x,father->position.y));
                                    minus = result->size()-1u;
                                    result->bringPositionMinusTimes(minus,minus);
                                    father=father->father;
                                }
                                return true;
                            }
                        }
                        if(field->getNoIF(x,y)){
                            if(!closed.haveClosed(edk::vec2ui32(x,y))){
                                nexts.newOpened(edk::vec2ui32(x,y),start,dest,father);
                            }
                        }
                    }
                }

                if(nexts.size()){
                    //walk into the next position
                    temp = nexts.getElementInPosition(0u);
                    nexts.remove(temp);
                    closed.add(temp);
                    father = temp;
                }
                else{
                    break;
                }
            }
        }
    }
    return false;
}
