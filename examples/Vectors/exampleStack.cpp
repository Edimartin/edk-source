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

#include "edk/vector/Stack.h"

int main(){
    edk::int32 size = 10;
    //create the stack
    edk::vector::Stack<edk::int32> stack;
    //clean the stack to use array's with 10 positions
    stack.clean(size);
    //push some values
    size*=2;
    for(edk::int32 i=0u;i<size;i++){
        stack.pushBack(i+1);
    }
    //print the values
    size = stack.size();
    printf("\nStack with size %d:",size);fflush(stdout);
    for(edk::int32 i=0u;i<size;i++){
        printf(" [%d]",stack.get(i));fflush(stdout);
    }
    //remove two elements from the stack
    stack.popBack();
    stack.remove(10);
    //if I print. It will return zero
    size = stack.size();
    printf("\nAfter remove the stack will have the size %d:",size);fflush(stdout);
    for(edk::int32 i=0u;i<size;i++){
        printf(" [%d]",stack.get(i));fflush(stdout);
    }
    //to not show the zero. test if the stack have the position
    size = stack.size();
    printf("\nShow the stack without show the removes. Stack size %d:",size);fflush(stdout);
    for(edk::int32 i=0u;i<size;i++){
        if(stack.havePos(i)){
            printf(" [%d]",stack.get(i));fflush(stdout);
        }
    }
    //to bring some position to up or down. It need not been removed
    stack.pushBack(21);
    //print the stack
    size = stack.size();
    printf("\nAfter push back for the removed position, the stack will have the size %d:",size);fflush(stdout);
    for(edk::int32 i=0u;i<size;i++){
        printf(" [%d]",stack.get(i));fflush(stdout);
    }
    //move the zero position to the end of the stack
    stack.bringPositionTo(10,stack.size()-1u);
    //print the stack
    size = stack.size();
    printf("\nAfter move the zero position to the end, the stack will have the size %d:",size);fflush(stdout);
    for(edk::int32 i=0u;i<size;i++){
        printf(" [%d]",stack.get(i));fflush(stdout);
    }
    //and remove the end position
    stack.remove(stack.size()-1);
    //print the stack
    size = stack.size();
    printf("\nAfter remove the end, the stack will have the size %d:",size);fflush(stdout);
    for(edk::int32 i=0u;i<size;i++){
        printf(" [%d]",stack.get(i));fflush(stdout);
    }
    //clean the stack
    stack.clean();
    printf("\n\n");fflush(stdout);
    return 0;
}
