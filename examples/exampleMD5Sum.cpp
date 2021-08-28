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
