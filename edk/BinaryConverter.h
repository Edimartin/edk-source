#ifndef BINARYCONVERTER_H
#define BINARYCONVERTER_H

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

#ifdef printMessages
#warning "Inside BinaryConverter"
#endif

#pragma once
#include <stdio.h>
#include "TypeVars.h"

#ifdef printMessages
#warning "    Compiling BinaryConverter"
#endif

namespace edk{
class BinaryConverter{
public:
    BinaryConverter();
    virtual ~BinaryConverter();

    static void printBits(edk::uchar8 byte);
    static void printBits(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBits(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBits(const edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBitsInverted(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBitsInverted(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBitsInverted(const edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBits(edk::uint16 byte,bool newLine = false);
    static void printBits(edk::uint32 byte,bool newLine = false);
    static void printBits(edk::uint64 byte,bool newLine = false);
    //
    static void printByte(edk::uchar8 byte);
    static void printBytes(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytes(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytes(const edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytesInverted(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytesInverted(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytesInverted(const edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytes(edk::uint16 byte,bool newLine = false);
    static void printBytes(edk::uint32 byte,bool newLine = false);
    static void printBytes(edk::uint64 byte,bool newLine = false);
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
    //joint bytes
    static edk::uint16 joinBytesLittleEndian(edk::uint8 byte1,edk::uint8 byte0);
    static edk::uint32 joinBytesLittleEndian(edk::uint8 byte3,edk::uint8 byte2,edk::uint8 byte1,edk::uint8 byte0);
    static edk::uint64 joinBytesLittleEndian(edk::uint8 byte7,
                                             edk::uint8 byte6,
                                             edk::uint8 byte5,
                                             edk::uint8 byte4,
                                             edk::uint8 byte3,
                                             edk::uint8 byte2,
                                             edk::uint8 byte1,
                                             edk::uint8 byte0
                                             );
    static edk::uint16 joinBytesBigEndian(edk::uint8 byte0,edk::uint8 byte1);
    static edk::uint32 joinBytesBigEndian(edk::uint8 byte0,edk::uint8 byte1,edk::uint8 byte2,edk::uint8 byte3);
    static edk::uint64 joinBytesBigEndian(edk::uint8 byte0,
                                          edk::uint8 byte1,
                                          edk::uint8 byte2,
                                          edk::uint8 byte3,
                                          edk::uint8 byte4,
                                          edk::uint8 byte5,
                                          edk::uint8 byte6,
                                          edk::uint8 byte7
                                          );
    //get the bytes from a number
    static edk::uint8 getByteLittleEndian(edk::uint16 number,edk::uint8 position);
    static edk::uint8 getByteLittleEndian(edk::uint32 number,edk::uint8 position);
    static edk::uint8 getByteLittleEndian(edk::uint64 number,edk::uint8 position);
    static edk::uint8 getByteBigEndian(edk::uint16 number,edk::uint8 position);
    static edk::uint8 getByteBigEndian(edk::uint32 number,edk::uint8 position);
    static edk::uint8 getByteBigEndian(edk::uint64 number,edk::uint8 position);

    //testa se um bit especifico esta true or false
    static bool testBit(edk::uchar8 byte,edk::uchar8 position);
};
}//end namespace edk

#endif // BINARYCONVERTER_H
