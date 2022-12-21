#include "BinaryConverter.h"

/*
Library C++ BinaryConverter - Change bit values from bytes
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

edk::BinaryConverter::BinaryConverter(){
    //
}
edk::BinaryConverter::~BinaryConverter(){
    //
}

void edk::BinaryConverter::printBits(edk::uchar8 byte){
    //
    edk::uchar8 byteCompare = 0x80;
    for (edk::uint32 i = 0; i < 8u; i++){
        if (byteCompare & byte){
            printf("1");edkEnd();
        }
        else{
            printf("0");edkEnd();
        }
        byteCompare=byteCompare>>1u;edkEnd();
    }
}
void edk::BinaryConverter::printBits(edk::uchar8* bytes,edk::uint32 size,bool newLine){
    //testa os bytes
    if (bytes && size){
        if (newLine){
            //escreve os bytes com uma nova linha no final

            for (edk::uint32 i = 0; i < size; i++){
                edk::BinaryConverter::printBits(bytes[i]);edkEnd();
                printf(" \n");edkEnd();
            }
        }
        else{
            //escreve os bytes sem a nova linha no final

            for (edk::uint32 i = 0; i < size; i++){
                edk::BinaryConverter::printBits(bytes[i]);edkEnd();
                printf(" ");edkEnd();
            }
        }
    }
}
void edk::BinaryConverter::printBits(edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBits((edk::uchar8*) bytes,size,newLine);edkEnd();
}
void edk::BinaryConverter::printBits(const edk::uchar8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBits((edk::uchar8*) bytes,size,newLine);edkEnd();
}
void edk::BinaryConverter::printBits(const edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBits((edk::char8*) bytes,size,newLine);edkEnd();
}

void edk::BinaryConverter::printBitsInverted(edk::uchar8* bytes,edk::uint32 size,bool newLine){
    //testa os bytes
    if (bytes && size){
        if (newLine){
            //escreve os bytes com uma nova linha no final

            for (edk::uint32 i = size; i > 0u; i--){
                edk::BinaryConverter::printBits(bytes[i-1u]);edkEnd();
                printf(" \n");edkEnd();
            }
        }
        else{
            //escreve os bytes sem a nova linha no final

            for (edk::uint32 i = size; i > 0u; i--){
                edk::BinaryConverter::printBits(bytes[i-1u]);edkEnd();
                printf(" ");edkEnd();
            }
        }
    }
}
void edk::BinaryConverter::printBitsInverted(edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*) bytes,size,newLine);edkEnd();
}
void edk::BinaryConverter::printBitsInverted(const edk::uchar8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*) bytes,size,newLine);edkEnd();
}
void edk::BinaryConverter::printBitsInverted(const edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::char8*) bytes,size,newLine);edkEnd();
}

void edk::BinaryConverter::printBits(edk::uint16 byte,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);edkEnd();
}
void edk::BinaryConverter::printBits(edk::uint32 byte,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);edkEnd();
}
void edk::BinaryConverter::printBits(edk::uint64 byte,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);edkEnd();
}
void edk::BinaryConverter::printBits(edk::int16 byte,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::char8*)(&byte),sizeof(byte),newLine);edkEnd();
}
void edk::BinaryConverter::printBits(edk::int32 byte,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::char8*)(&byte),sizeof(byte),newLine);edkEnd();
}
void edk::BinaryConverter::printBits(edk::int64 byte,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::char8*)(&byte),sizeof(byte),newLine);edkEnd();
}

void edk::BinaryConverter::printByte(edk::uchar8 byte){
    printf("%03u",byte);edkEnd();
}
void edk::BinaryConverter::printBytes(edk::uchar8* bytes,edk::uint32 size,bool newLine){
    //testa os bytes
    if (bytes && size){
        if (newLine){
            //escreve os bytes com uma nova linha no final
            for (edk::uint32 i = 0; i < size; i++){
                edk::BinaryConverter::printByte(bytes[i]);edkEnd();
                printf(" \n");edkEnd();
            }
        }
        else{
            //escreve os bytes sem a nova linha no final
            for (edk::uint32 i = 0; i < size; i++){
                edk::BinaryConverter::printByte(bytes[i]);edkEnd();
                printf(" ");edkEnd();
            }
        }
    }
}
void edk::BinaryConverter::printBytes(edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBytes((edk::uchar8*) bytes,size,newLine);edkEnd();
}
void edk::BinaryConverter::printBytes(const edk::uchar8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBytes((edk::uchar8*) bytes,size,newLine);edkEnd();
}
void printBytes(const edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBytes((edk::char8*) bytes,size,newLine);edkEnd();
}
void edk::BinaryConverter::printBytesInverted(edk::uchar8* bytes,edk::uint32 size,bool newLine){
    //testa os bytes
    if (bytes && size){
        if (newLine){
            //escreve os bytes com uma nova linha no final

            for (edk::uint32 i = size; i > 0u; i--){
                edk::BinaryConverter::printByte(bytes[i-1u]);edkEnd();
                printf(" \n");edkEnd();
            }
        }
        else{
            //escreve os bytes sem a nova linha no final

            for (edk::uint32 i = size; i > 0u; i--){
                edk::BinaryConverter::printByte(bytes[i-1u]);edkEnd();
                printf(" ");edkEnd();
            }
        }
    }
}
void edk::BinaryConverter::printBytesInverted(edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::uchar8*) bytes,size,newLine);edkEnd();
}
void edk::BinaryConverter::printBytesInverted(const edk::uchar8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::uchar8*) bytes,size,newLine);edkEnd();
}
void edk::BinaryConverter::printBytesInverted(const edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::char8*) bytes,size,newLine);edkEnd();
}
void edk::BinaryConverter::printBytes(edk::uint16 byte,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);edkEnd();
}
void edk::BinaryConverter::printBytes(edk::uint32 byte,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);edkEnd();
}
void edk::BinaryConverter::printBytes(edk::uint64 byte,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);edkEnd();
}
void edk::BinaryConverter::printBytes(edk::int16 byte,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::char8*)(&byte),sizeof(byte),newLine);edkEnd();
}
void edk::BinaryConverter::printBytes(edk::int32 byte,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::char8*)(&byte),sizeof(byte),newLine);edkEnd();
}
void edk::BinaryConverter::printBytes(edk::int64 byte,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::char8*)(&byte),sizeof(byte),newLine);edkEnd();
}
