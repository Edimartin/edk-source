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

//Include the edk::vector::Array
#include "edk/vector/Array.h"

int main(){
    edk::int32 size1 = 5;
    //create an array with 32 bit integer where can alocate five positions
    edk::vector::Array<edk::int32> n1(size1);
    //fill the array with values
    for(edk::int32 i=0;i<size1;i++){
        //set the value
        n1.set(i,i+1);
    }
    //print the array values
    printf("\nArray N1 with size %u have values: ",n1.size());
    for(edk::int32 i=0;i<size1;i++){
        //set the value
        printf(" [%d]",n1.get(i));
    }
    printf(";");fflush(stdout);

    //Create a new array
    edk::int32 size2 = 4;
    //create the new array with 4 positions
    edk::vector::Array<edk::int32> n2(size2);
    //fill the second array
    for(edk::int32 i=0;i<size2;i++){
        //set the value
        n2.set(i,size2-i);
    }
    //print the array values
    printf("\nArray N2 with size %u have values: ",n2.size());
    for(edk::int32 i=0;i<size2;i++){
        //set the value
        printf(" [%d]",n2.get(i));
    }
    printf(";");fflush(stdout);

    //copy the vector 1 to vector 2
    n2.cloneFrom(n1);

    //print the array values

    //print the array values
    printf("\nAfter copy N1 to N2. The array N2 with size %u have values: ",n2.size());
    size2 = n2.size();
    for(edk::int32 i=0;i<size2;i++){
        //set the value
        printf(" [%d]",n2.get(i));
    }
    printf(";");fflush(stdout);


    printf("\n\n");
    return 0;
}
