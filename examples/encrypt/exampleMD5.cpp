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

