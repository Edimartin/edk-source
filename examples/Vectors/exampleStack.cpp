/*
Library EDK - How to use Extensible Development Kit
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
