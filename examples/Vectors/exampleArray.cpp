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
    n2 = n1;

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
