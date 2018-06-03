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

/*
 This example encript the edk password to MD5
*/

#include "edk/encrypt/MD5.h"
#include "edk/File.h"

#define pass "edk"
#define fileName "edk.txt"

#include <stdio.h>

int main(){
    edk::File file;
    //first function tipe will convert an string to another MD5 string alloc in memory
    edk::char8* hash;
    if((hash = edk::encrypt::MD5::convert(pass))){
        printf("\nThe result from '%s' is '%s'",pass,hash);fflush(stdout);

        //don't forget to delete the hash
        delete[] hash;
    }

    //convert the an pre-alloc string with at least 33 bit size (32 characters and the '\0')
    edk::char8 preAllocHash[33u];
    memset(preAllocHash,0u,sizeof(preAllocHash));
    if(edk::encrypt::MD5::convertTo(pass,preAllocHash)){
        printf("\nThe result from '%s' is '%s'",pass,preAllocHash);fflush(stdout);
    }

    //create a file to write the pass inside and generate the hash
    if(file.createAndOpenTextFile(fileName)){
        file.writeText(pass);
        file.closeFile();
    }
    //generate the md5 from the file
    if((hash = edk::encrypt::MD5::convertFile(fileName))){
        printf("\nThe result from the bits from file '%s' is '%s'",fileName,hash);fflush(stdout);

        //don't forget to delete the hash
        delete[] hash;
    }
    //generate a md5 from a file to a pre-alloc string
    if(edk::encrypt::MD5::convertFileTo(fileName,preAllocHash)){
        printf("\nThe result from the bits from file '%s' is '%s'",fileName,preAllocHash);fflush(stdout);
    }

    //delete the file
    if(edk::File::deleteFile(fileName)){
        printf("\nFile '%s' Deleted",fileName);fflush(stdout);
    }

    printf("\n");
    return 0;
}

