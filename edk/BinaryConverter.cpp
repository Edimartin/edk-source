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
            printf("1");
        }
        else{
            printf("0");
        }
        byteCompare=byteCompare>>1u;
    }
}
void edk::BinaryConverter::printBits(edk::uchar8* bytes,edk::uint32 size,bool newLine){
    //testa os bytes
    if (bytes && size){
        if (newLine){
            //escreve os bytes com uma nova linha no final

            for (edk::uint32 i = 0; i < size; i++){
                edk::BinaryConverter::printBits(bytes[i]);
                printf(" \n");
            }
        }
        else{
            //escreve os bytes sem a nova linha no final

            for (edk::uint32 i = 0; i < size; i++){
                edk::BinaryConverter::printBits(bytes[i]);
                printf(" ");
            }
        }
    }
}
void edk::BinaryConverter::printBits(edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBits((edk::uchar8*) bytes,size,newLine);
}
void edk::BinaryConverter::printBits(const edk::uchar8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBits((edk::uchar8*) bytes,size,newLine);
}

void edk::BinaryConverter::printBitsInverted(edk::uchar8* bytes,edk::uint32 size,bool newLine){

    //testa os bytes
    if (bytes && size){
        if (newLine){
            //escreve os bytes com uma nova linha no final

            for (edk::uint32 i = size; i > 0u; i--){
                edk::BinaryConverter::printBits(bytes[i-1u]);
                printf(" \n");
            }
        }
        else{
            //escreve os bytes sem a nova linha no final

            for (edk::uint32 i = size; i > 0u; i--){
                edk::BinaryConverter::printBits(bytes[i-1u]);
                printf(" ");
            }
        }
    }
}
void edk::BinaryConverter::printBitsInverted(edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*) bytes,size,newLine);
}
void edk::BinaryConverter::printBitsInverted(const edk::uchar8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*) bytes,size,newLine);
}

void edk::BinaryConverter::printBits(edk::uint16 byte,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);
}
void edk::BinaryConverter::printBits(edk::uint32 byte,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);
}
void edk::BinaryConverter::printBits(edk::uint64 byte,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);
}
void edk::BinaryConverter::printByte(edk::uchar8 byte){
    printf("%03u",byte);
}
void edk::BinaryConverter::printBytes(edk::uchar8* bytes,edk::uint32 size,bool newLine){
    //testa os bytes
    if (bytes && size){
        if (newLine){
            //escreve os bytes com uma nova linha no final
            for (edk::uint32 i = 0; i < size; i++){
                edk::BinaryConverter::printByte(bytes[i]);
                printf(" \n");
            }
        }
        else{
            //escreve os bytes sem a nova linha no final
            for (edk::uint32 i = 0; i < size; i++){
                edk::BinaryConverter::printByte(bytes[i]);
                printf(" ");
            }
        }
    }
}
void edk::BinaryConverter::printBytes(edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBytes((edk::uchar8*) bytes,size,newLine);
}
void edk::BinaryConverter::printBytes(const edk::uchar8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBytes((edk::uchar8*) bytes,size,newLine);
}
void edk::BinaryConverter::printBytesInverted(edk::uchar8* bytes,edk::uint32 size,bool newLine){
    //testa os bytes
    if (bytes && size){
        if (newLine){
            //escreve os bytes com uma nova linha no final

            for (edk::uint32 i = size; i > 0u; i--){
                edk::BinaryConverter::printByte(bytes[i-1u]);
                printf(" \n");
            }
        }
        else{
            //escreve os bytes sem a nova linha no final

            for (edk::uint32 i = size; i > 0u; i--){
                edk::BinaryConverter::printByte(bytes[i-1u]);
                printf(" ");
            }
        }
    }
}
void edk::BinaryConverter::printBytesInverted(edk::char8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::uchar8*) bytes,size,newLine);
}
void edk::BinaryConverter::printBytesInverted(const edk::uchar8* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::uchar8*) bytes,size,newLine);
}
void edk::BinaryConverter::printBytes(edk::uint16 byte,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);
}
void edk::BinaryConverter::printBytes(edk::uint32 byte,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);
}
void edk::BinaryConverter::printBytes(edk::uint64 byte,bool newLine){
    edk::BinaryConverter::printBytesInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);
}
//inverte os bytes
edk::uint64 edk::BinaryConverter::swapBytes(edk::uint64 value){
    return  (edk::uint64)
            ((edk::uchar8)(                     value>>56u  ))     |
            ((edk::uchar8)(                     value>>48u  )) <<8u|
                                                                 ((edk::uchar8)(                     value>>40u  ))<<16u|
                                                                 ((edk::uchar8)(                     value>>32u  ))<<24u|
                                                                 ((edk::uint64)((edk::uchar8)(value>>24u )))<<32u|
                                                                 ((edk::uint64)((edk::uchar8)(value>>16u )))<<40u|
                                                                 ((edk::uint64)((edk::uchar8)(value>>8u  )))<<48u|
                                                                 ((edk::uint64)((edk::uchar8)(value      )))<<56u
                                                                 ;
}
edk::uint32 edk::BinaryConverter::swapBytes(edk::uint32 value){
    //
    return  (edk::uint32)
            ((edk::uchar8)(value>>24u))     |
            ((edk::uchar8)(value>>16u)) <<8u|
                                          ((edk::uchar8)(value>>8u ))<<16u|
                                          ((edk::uchar8)(value     ))<<24u
                                          ;
}
edk::uint16 edk::BinaryConverter::swapBytes(edk::uint16 value){
    //
    return  (edk::uint16)
            ((edk::uchar8)(value>>8u))    |
            ((edk::uint16)(value))   <<8u
                                       ;
}


//acende um bit especifico
void edk::BinaryConverter::setBitTrue(edk::uchar8* byte,edk::uint32 position){
    if(byte && position<(sizeof(edk::uchar8)*8u)){
        //
        *byte = *byte | (1u<<position);
    }
}
void edk::BinaryConverter::setBitFalse(edk::uchar8* byte,edk::uint32 position){
    if(byte && position<(sizeof(edk::uchar8)*8u)){
        //
        *byte = *byte & (~(1u<<position));
    }
}
edk::uint32 edk::BinaryConverter::setBitTrue(edk::uint32 number,edk::uchar8 position){
    edk::uchar8 div = position/8u;
    edk::uchar8 rest = position%8u;
    edk::uchar8* temp = (edk::uchar8*)&number;
    edk::BinaryConverter::setBitTrue(temp+(div),rest);
    return number;
}
edk::uint32 edk::BinaryConverter::setBitFalse(edk::uint32 number,edk::uchar8 position){
    edk::uchar8 div = position/8u;
    edk::uchar8 rest = position%8u;
    edk::uchar8* temp = (edk::uchar8*)&number;
    edk::BinaryConverter::setBitFalse(temp+(div),rest);
    return number;
}
/*
edk::uint32 edk::BinaryConverter::setBitTrue(edk::uint32 number,edk::uchar8 position){
    edk::uchar8 div = position/4u;
    edk::uchar8 rest = position%4u;
    edk::uchar8* temp = (edk::uchar8*)&number;
    if(div)div--;
    if(rest)rest--;
    edk::BinaryConverter::setBitTrue(temp+(div),rest);
    return number;
}
*/
edk::uint32 edk::BinaryConverter::joinBits(edk::uint32 number1,edk::uint32 number2,edk::uint32 position){
    edk::uint32 ret = number1;
    if(position<=32u){
        ret  = ret<<position;
        position = 32u-position;
        number2 = (number2<<position)>>position;
        ret = ret|number2;
    }
    return ret;
}
edk::uint64 edk::BinaryConverter::joinBits(edk::uint64 number1,edk::uint64 number2,edk::uint32 position){
    edk::uint64 ret = number1;
    if(position<=64u){
        ret  = ret<<position;
        position = 64u-position;
        number2 = (number2<<position)>>position;
        ret = ret|number2;
    }
    return ret;
}
edk::uint32 edk::BinaryConverter::getStart(edk::uint32 number,edk::uint8 position){
    return number>>position;
}
edk::uint64 edk::BinaryConverter::getStart(edk::uint64 number,edk::uint8 position){
    return number>>position;
}
edk::uint32 edk::BinaryConverter::getEnd(edk::uint32 number,edk::uint8 position){
    position = 32u-position;
    return (number<<position)>>position;
}
edk::uint64 edk::BinaryConverter::getEnd(edk::uint64 number,edk::uint8 position){
    position = 64u-position;
    return (number<<position)>>position;
}
//joint bytes
edk::uint16 edk::BinaryConverter::joinBytesLittleEndian(edk::uint8 byte1,edk::uint8 byte0){
    return ((edk::uint16)byte1<<8u) + ((edk::uint16)byte0);
}
edk::uint32 edk::BinaryConverter::joinBytesLittleEndian(edk::uint8 byte3,edk::uint8 byte2,edk::uint8 byte1,edk::uint8 byte0){
    return ((edk::uint32)byte3<<24u) + ((edk::uint32)byte2<<16u) + ((edk::uint32)byte1<<8u) + (edk::uint32)byte0;
}
edk::uint64 edk::BinaryConverter::joinBytesLittleEndian(edk::uint8 byte7,
                                                        edk::uint8 byte6,
                                                        edk::uint8 byte5,
                                                        edk::uint8 byte4,
                                                        edk::uint8 byte3,
                                                        edk::uint8 byte2,
                                                        edk::uint8 byte1,
                                                        edk::uint8 byte0
                                                        ){
    return ((edk::uint64)byte7<<56u)
            +
            ((edk::uint64)byte6<<48u)
            +
            ((edk::uint64)byte5<<40u)
            +
            ((edk::uint64)byte4<<32u)
            +
            ((edk::uint64)byte3<<24u)
            +
            ((edk::uint64)byte2<<16u)
            +
            ((edk::uint64)byte1<<8u)
            +
            (edk::uint64)byte0;
}
edk::uint16 edk::BinaryConverter::joinBytesBigEndian(edk::uint8 byte0,edk::uint8 byte1){
    return ((edk::uint16)byte1<<8u) + ((edk::uint16)byte0);
}
edk::uint32 edk::BinaryConverter::joinBytesBigEndian(edk::uint8 byte0,edk::uint8 byte1,edk::uint8 byte2,edk::uint8 byte3){
    return ((edk::uint32)byte3<<24u) + ((edk::uint32)byte2<<16u) + ((edk::uint32)byte1<<8u) + (edk::uint32)byte0;
}
edk::uint64 edk::BinaryConverter::joinBytesBigEndian(edk::uint8 byte0,
                                                     edk::uint8 byte1,
                                                     edk::uint8 byte2,
                                                     edk::uint8 byte3,
                                                     edk::uint8 byte4,
                                                     edk::uint8 byte5,
                                                     edk::uint8 byte6,
                                                     edk::uint8 byte7
                                                     ){
    return ((edk::uint64)byte7<<56u)
            +
            ((edk::uint64)byte6<<48u)
            +
            ((edk::uint64)byte5<<40u)
            +
            ((edk::uint64)byte4<<32u)
            +
            ((edk::uint64)byte3<<24u)
            +
            ((edk::uint64)byte2<<16u)
            +
            ((edk::uint64)byte1<<8u)
            +
            (edk::uint64)byte0;
}
//get the bytes from a number
edk::uint8 edk::BinaryConverter::getByteLittleEndian(edk::uint16 number,edk::uint8 position){
    //
    if(position<sizeof(number)){
        return (edk::uint8)((number<<((edk::uint8)(position*-8)+((sizeof(number)-1u)*8)))
                            >>((sizeof(number)-1u) * 8u));
    }
    return 0u;
}
edk::uint8 edk::BinaryConverter::getByteLittleEndian(edk::uint32 number,edk::uint8 position){
    //
    if(position<sizeof(number)){
        return (edk::uint8)((number<<((edk::uint8)(position*-8)+((sizeof(number)-1u)*8)))
                            >>((sizeof(number)-1u) * 8u));
    }
    return 0u;
}
edk::uint8 edk::BinaryConverter::getByteLittleEndian(edk::uint64 number,edk::uint8 position){
    //
    if(position<sizeof(number)){
        return (edk::uint8)((number<<((edk::uint8)(position*-8)+((sizeof(number)-1u)*8)))
                            >>((sizeof(number)-1u) * 8u));
    }
    return 0u;
}
edk::uint8 edk::BinaryConverter::getByteBigEndian(edk::uint16 number,edk::uint8 position){
    return edk::BinaryConverter::getByteLittleEndian(number,position*-1+sizeof(number)-1u);
}
edk::uint8 edk::BinaryConverter::getByteBigEndian(edk::uint32 number,edk::uint8 position){
    return edk::BinaryConverter::getByteLittleEndian(number,position*-1+sizeof(number)-1u);
}
edk::uint8 edk::BinaryConverter::getByteBigEndian(edk::uint64 number,edk::uint8 position){
    return edk::BinaryConverter::getByteLittleEndian(number,position*-1+sizeof(number)-1u);
}

//testa se um bit especifico esta true or false
bool edk::BinaryConverter::testBit(edk::uchar8 byte,edk::uchar8 position){

    if(byte && position<(sizeof(edk::uchar8)*8u)){
        edk::uchar8 byteCompare = 1<<position;
        return (bool)(byteCompare & byte);
    }
    return false;
}
