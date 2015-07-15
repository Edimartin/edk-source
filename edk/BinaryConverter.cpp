#include "BinaryConverter.h"

edk::BinaryConverter::BinaryConverter()
{
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
void edk::BinaryConverter::printBits(const char* bytes,edk::uint32 size,bool newLine){
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
void edk::BinaryConverter::printBitsInverted(const char* bytes,edk::uint32 size,bool newLine){
    edk::BinaryConverter::printBitsInverted((edk::uchar8*) bytes,size,newLine);
}

void edk::BinaryConverter::printBits(edk::uint16 byte,bool newLine){
    //
    edk::BinaryConverter::printBitsInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);
}
void edk::BinaryConverter::printBits(edk::uint32 byte,bool newLine){
    //
    edk::BinaryConverter::printBitsInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);
}
void edk::BinaryConverter::printBits(edk::uint64 byte,bool newLine){
    //
    edk::BinaryConverter::printBitsInverted((edk::uchar8*)(&byte),sizeof(byte),newLine);

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
//testa se um bit especifico esta true or false
bool edk::BinaryConverter::testBit(edk::uchar8 byte,edk::uchar8 position){

    if(byte && position<(sizeof(edk::uchar8)*8u)){
        edk::uchar8 byteCompare = 1<<position;
        return (bool)(byteCompare & byte);
    }
    return false;
}
