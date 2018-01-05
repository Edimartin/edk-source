/*
Library EDK - How to use Extensible Development Kit
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

#include "edk/vector/BinaryTree.h"

//class position whith 2 values
class Position{
public:
    Position(){this->x = this->y = 0;}
    ~Position(){}
    edk::int32 x,y;
    void operator=(Position position){
        this->x = position.x;
        this->y = position.y;
    }
};
//class tree using the pointer for Position
class TreePosition : public edk::vector::BinaryTree<Position*>{
public:
    TreePosition(){}
    ~TreePosition(){this->clean();}
    //add the new position to the tree
    bool addNewPosition(edk::int32 x,edk::int32 y){
        //test if aready habe the Position on the tree
        Position* temp = this->getPositionPointer(x,y);
        if(temp){
            return false;
        }
        //else create a new Position
        temp = new Position;
        if(temp){
            temp->x = x;
            temp->y = y;
            if(this->add(temp)){
                //return true
                return true;
            }
            //if it can't add to the tree return false
            delete temp;
        }
        return false;
    }
    //return a position
    Position getPositionInPosition(edk::uint32 position){
        Position ret;
        //test if aready habe the Position on the tree
        Position* temp = this->getElementInPosition(position);
        if(temp){
            ret = *temp;
        }
        return ret;
    }
    //remove the Position
    bool removePosition(edk::int32 x,edk::int32 y){
        //test if aready habe the Position on the tree
        Position* temp = this->getPositionPointer(x,y);
        if(temp){
            //remove the temp
            if(this->remove(temp)){
                delete temp;
                return true;
            }
        }
        return false;
    }
    //remove the position in position (funny)
    bool removePositionInPosition(edk::uint32 position){
        //test if aready habe the Position on the tree
        Position* temp = this->getElementInPosition(position);
        if(temp){
            //remove the temp
            if(this->remove(temp)){
                delete temp;
                return true;
            }
        }
        return false;
    }
    //clean the binaryTree
    void clean(){
        Position* temp = NULL;
        edk::uint32 size  =this->size();
        for(edk::uint32 i=0u;i<size;i++){
            temp = this->getElementInPosition(i);
            if(temp)
                delete temp;
        }
        edk::vector::BinaryTree<Position*>::clean();
    }
    //VIRTUAL FUNCTIONS
    //compare if the value is bigger
    bool firstBiggerSecond(Position* first,Position* second){
        if(first && second){
            //test the X
            if(first->x>second->x)
                return true;
            else if(first->x==second->x)
                //else testthe Y
                if(first->y>second->y)
                    return true;
        }
        return false;
    }
    //compare if the value is equal
    bool firstEqualSecond(Position* first,Position* second){
        if(first && second)
            if(first->x==second->x
                    &&
                    first->y==second->y)
                return true;
        return false;
    }
    //Print
    void printElement(Position* value){
        if(value)
        printf(" [%d,%d]"
               ,value->x,value->y
               );
    }
    void renderElement(Position* value){
        if(value)
        printf("render [%d,%d]"
               ,value->x,value->y
               );
    }
    //UPDATE
    void updateElement(Position* value){
        if(value)
        printf("update [%d,%d]"
               ,value->x,value->y
               );
    }
private:
    //return the position pointer
    Position* getPositionPointer(edk::int32 x,edk::int32 y){
        //use a class to find the position on the tree
        Position find;
        find.x = x;
        find.y = y;
        return this->getElement(&find);
    }
};

int main(){
    edk::uint32 size = 0u;
    //create the binary tree
    edk::vector::BinaryTree<edk::int32> tree;
    //add some numbers
    tree.add(5);
    tree.add(10);
    tree.add(3);
    tree.add(7);
    tree.add(1);
    tree.add(4);
    tree.add(6);
    tree.add(8);
    tree.add(2);
    tree.add(9);
    //print the tree values
    size = tree.size();
    printf("\nBinary Tree with size %u:",size);fflush(stdout);
    for(edk::uint32 i=0u;i<size;i++){
        printf(" [%d]",tree.getElementInPosition(i));fflush(stdout);
    }
    //remove a number from the tree
    tree.remove(5);
    //print the tree values
    size = tree.size();
    printf("\nAfter remove the 5 the binary Tree have size %u:",size);fflush(stdout);
    for(edk::uint32 i=0u;i<size;i++){
        printf(" [%d]",tree.getElementInPosition(i));fflush(stdout);
    }
    //remove an element position
    tree.remove(tree.getElementInPosition(2u));
    //print the tree values
    size = tree.size();
    printf("\nAfter remove the element in position 2, the binary Tree have size %u:",size);fflush(stdout);
    for(edk::uint32 i=0u;i<size;i++){
        printf(" [%d]",tree.getElementInPosition(i));fflush(stdout);
    }
    //clean the tree
    tree.clean();

    printf("\n");fflush(stdout);

    //create a second tree to ordenate the position
    TreePosition treeP;
    treeP.addNewPosition(2,4);
    treeP.addNewPosition(2,5);
    treeP.addNewPosition(1,3);
    treeP.addNewPosition(2,1);
    treeP.addNewPosition(2,2);
    treeP.addNewPosition(1,2);
    treeP.addNewPosition(1,1);
    treeP.addNewPosition(1,5);
    treeP.addNewPosition(2,3);
    treeP.addNewPosition(1,4);
    //print the tree values
    size = treeP.size();
    printf("\nBinaryTree with positions have size %u:",size);fflush(stdout);
    treeP.print();
    //remove a posicao 1,4
    treeP.removePosition(1,4);
    //print the tree values
    size = treeP.size();
    printf("\nAfter remove position 1,4, the binaryTree with positions have size %u:",size);fflush(stdout);
    treeP.print();
    //remove the position in position 7
    treeP.removePositionInPosition(7u);
    //print the tree values
    size = treeP.size();
    printf("\nAfter remove position in position 7u, the binaryTree with positions have size %u:",size);fflush(stdout);
    treeP.print();
    //clean the tree
    treeP.clean();

    printf("\n\n");fflush(stdout);
    return 0;
}
