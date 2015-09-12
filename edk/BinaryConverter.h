#ifndef BINARYCONVERTER_H
#define BINARYCONVERTER_H

#pragma once
#include <stdio.h>
#include "TypeVars.h"
namespace edk{
class BinaryConverter
{
public:
    BinaryConverter();

    static void printBits(edk::uchar8 byte);
    static void printBits(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBits(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBits(const char* bytes,edk::uint32 size,bool newLine = false);
    static void printBitsInverted(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBitsInverted(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBitsInverted(const char* bytes,edk::uint32 size,bool newLine = false);
    static void printBits(edk::uint16 byte,bool newLine = false);
    static void printBits(edk::uint32 byte,bool newLine = false);
    static void printBits(edk::uint64 byte,bool newLine = false);
    //inverte os bytes
    static edk::uint64 swapBytes(edk::uint64 value);
    static edk::uint32 swapBytes(edk::uint32 value);
    static edk::uint16 swapBytes(edk::uint16 value);

    //acende um bit especifico
    static void setBitTrue(edk::uchar8* byte,edk::uint32 position);
    static void setBitFalse(edk::uchar8* byte,edk::uint32 position);
    static edk::uint32 setBitTrue(edk::uint32 number,edk::uchar8 position);
    static edk::uint32 setBitFalse(edk::uint32 number,edk::uchar8 position);
    //static edk::uint32 setBitTrue(edk::uint32 number,edk::uchar8 position);

    static edk::uint32 joinBits(edk::uint32 number1,edk::uint32 number2,edk::uint32 position);
    static edk::uint64 joinBits(edk::uint64 number1,edk::uint64 number2,edk::uint32 position);
    static edk::uint32 getStart(edk::uint32 number,edk::uint8 position);
    static edk::uint64 getStart(edk::uint64 number,edk::uint8 position);
    static edk::uint32 getEnd(edk::uint32 number,edk::uint8 position);
    static edk::uint64 getEnd(edk::uint64 number,edk::uint8 position);

    //testa se um bit especifico esta true or false
    static bool testBit(edk::uchar8 byte,edk::uchar8 position);
};
}//end namespace edk

#endif // BINARYCONVERTER_H
