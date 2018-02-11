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

#include <stdio.h>

//Include the MD5 encryptor
#include "edk/encrypt/MD5.h"

#define string1 "temp1"
#define string2 "temp2"

//This example writes the MD5Sum software to generate MD5 from file
int main(int argc,char* argv[]){
    if(argc>1){
        edk::char8 dest[33u];
        dest[32u]=0u;
        for(edk::int32 i=1;i<argc;i++){
            if(edk::encrypt::MD5::convertFileTo(argv[i],(edk::char8*)dest)){
                printf("%s %s"
                       ,dest
                       ,argv[i]
                       );fflush(stdout);
            }
            else{
                printf("Can't read the file %s"
                       ,argv[i]
                       );fflush(stdout);
            }
            printf("\n");fflush(stdout);
        }
    }
    else{
        printf("You have to write fileName(s)");fflush(stdout);
        printf("\nIf you want generate MD5 from a string, you can use the funcions convert() and convertTo()");fflush(stdout);
        edk::char8 dest[33u];
        edk::char8* dest2=NULL;
        if(edk::encrypt::MD5::convertTo(string1,dest)){
            printf("\nEX:");fflush(stdout);
            printf(" The MD5 from %s is %s"
                   ,string1
                   ,dest
                   );fflush(stdout);
        }
        dest2=edk::encrypt::MD5::convert(string2);
        if(dest2){
            printf("\nEX:");fflush(stdout);
            printf(" The MD5 from %s is %s"
                   ,string2
                   ,dest2
                   );fflush(stdout);
            //don't forget to delete the string generated
            delete[] dest2;
        }
        printf("\n");fflush(stdout);
    }
    return 0;
}
