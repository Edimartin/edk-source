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
#pragma message "Inside BinaryConverter"
#endif

#pragma once
#include <stdio.h>
#include "TypeVars.h"

#ifdef printMessages
#pragma message "    Compiling BinaryConverter"
#endif

namespace edk{
class BinaryConverter{
public:
    BinaryConverter();
    virtual ~BinaryConverter();

    void Constructor();
    void Destructor();

    static void printBits(edk::uchar8 byte);
    static inline void printBits(edk::char8 byte){printBits((edk::uchar8)byte);}

    static void printBits(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBits(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBits(const edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBits(const edk::char8* bytes,edk::uint32 size,bool newLine = false);

    static void printBits(edk::uchar8* bytes,edk::uint64 size,bool newLine = false);
    static void printBits(edk::char8* bytes,edk::uint64 size,bool newLine = false);
    static void printBits(const edk::uchar8* bytes,edk::uint64 size,bool newLine = false);
    static void printBits(const edk::char8* bytes,edk::uint64 size,bool newLine = false);

    static void printBitsInverted(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBitsInverted(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBitsInverted(const edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBitsInverted(const edk::char8* bytes,edk::uint32 size,bool newLine = false);

    static void printBitsInverted(edk::uchar8* bytes,edk::uint64 size,bool newLine = false);
    static void printBitsInverted(edk::char8* bytes,edk::uint64 size,bool newLine = false);
    static void printBitsInverted(const edk::uchar8* bytes,edk::uint64 size,bool newLine = false);
    static void printBitsInverted(const edk::char8* bytes,edk::uint64 size,bool newLine = false);

    static void printBits(edk::uint16 byte,bool newLine = false);
    static void printBits(edk::uint32 byte,bool newLine = false);
    static void printBits(edk::uint64 byte,bool newLine = false);
    static void printBits(edk::int16 byte,bool newLine = false);
    static void printBits(edk::int32 byte,bool newLine = false);
    static void printBits(edk::int64 byte,bool newLine = false);
    //
    static void printByte(edk::uchar8 byte);
    static inline void printByte(edk::char8 byte){printByte((edk::uchar8) byte);}
    static void printBytes(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytes(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytes(const edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytes(const edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytesInverted(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytesInverted(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytesInverted(const edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytesInverted(const edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printBytes(edk::uint16 byte,bool newLine = false);
    static void printBytes(edk::uint32 byte,bool newLine = false);
    static void printBytes(edk::uint64 byte,bool newLine = false);
    static void printBytes(edk::int16 byte,bool newLine = false);
    static void printBytes(edk::int32 byte,bool newLine = false);
    static void printBytes(edk::int64 byte,bool newLine = false);
    //
    static void printHex(edk::uchar8 byte);
    static inline void printHex(edk::char8 byte){printHex((edk::uchar8) byte);}
    static void printHex(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printHex(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printHex(const edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printHex(const edk::char8* bytes,edk::uint32 size,bool newLine = false);

    static void printHex(edk::uchar8* bytes,edk::uint64 size,bool newLine = false);
    static void printHex(edk::char8* bytes,edk::uint64 size,bool newLine = false);
    static void printHex(const edk::uchar8* bytes,edk::uint64 size,bool newLine = false);
    static void printHex(const edk::char8* bytes,edk::uint64 size,bool newLine = false);

    static void printHexInverted(edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printHexInverted(edk::char8* bytes,edk::uint32 size,bool newLine = false);
    static void printHexInverted(const edk::uchar8* bytes,edk::uint32 size,bool newLine = false);
    static void printHexInverted(const edk::char8* bytes,edk::uint32 size,bool newLine = false);

    static void printHexInverted(edk::uchar8* bytes,edk::uint64 size,bool newLine = false);
    static void printHexInverted(edk::char8* bytes,edk::uint64 size,bool newLine = false);
    static void printHexInverted(const edk::uchar8* bytes,edk::uint64 size,bool newLine = false);
    static void printHexInverted(const edk::char8* bytes,edk::uint64 size,bool newLine = false);

    static void printHex(edk::uint16 byte,bool newLine = false);
    static void printHex(edk::uint32 byte,bool newLine = false);
    static void printHex(edk::uint64 byte,bool newLine = false);
    static void printHex(edk::int16 byte,bool newLine = false);
    static void printHex(edk::int32 byte,bool newLine = false);
    static void printHex(edk::int64 byte,bool newLine = false);
    //inverte os bytes
    static inline edk::uint64 swapBytes(edk::uint64 value){
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
    static inline edk::uint32 swapBytes(edk::uint32 value){
        return  (edk::uint32)
                ((edk::uchar8)(value>>24u))     |
                ((edk::uchar8)(value>>16u)) <<8u|
                                              ((edk::uchar8)(value>>8u ))<<16u|
                                              ((edk::uchar8)(value     ))<<24u
                                              ;
    }
    static inline edk::uint16 swapBytes(edk::uint16 value){
        return  (edk::uint16)
                ((edk::uchar8)(value>>8u))    |
                ((edk::uint16)(value))   <<8u
                                           ;
    }
    static inline edk::int64 swapBytes(edk::int64 value){
        return  (edk::int64)
                ((edk::char8)(                     value>>56u  ))     |
                ((edk::char8)(                     value>>48u  )) <<8u|
                                                                    ((edk::char8)(                     value>>40u  ))<<16u|
                                                                    ((edk::char8)(                     value>>32u  ))<<24u|
                                                                    ((edk::int64)((edk::char8)(value>>24u )))<<32u|
                                                                    ((edk::int64)((edk::char8)(value>>16u )))<<40u|
                                                                    ((edk::int64)((edk::char8)(value>>8u  )))<<48u|
                                                                    ((edk::int64)((edk::char8)(value      )))<<56u
                                                                    ;
    }
    static inline edk::int32 swapBytes(edk::int32 value){
        return  (edk::int32)
                ((edk::char8)(value>>24u))     |
                ((edk::char8)(value>>16u)) <<8u|
                                             ((edk::char8)(value>>8u ))<<16u|
                                             ((edk::char8)(value     ))<<24u
                                             ;
    }
    static inline edk::int16 swapBytes(edk::int16 value){
        return  (edk::int16)
                ((edk::char8)(value>>8u))    |
                ((edk::int16)(value))   <<8u
                                          ;
    }

    //invert bits
    static inline bool bitsInvert(edk::uchar8* bytes,edk::uint32 size){
        if(bytes && size){
            for(edk::uint32 i=0u;i<size;i++){
                bytes[i]=~bytes[i];
            }
            return true;
        }
        return false;
    }
    static inline bool bitsInvert(edk::char8* bytes,edk::uint32 size){
        if(bytes && size){
            for(edk::uint32 i=0u;i<size;i++){
                bytes[i]=~bytes[i];
            }
            return true;
        }
        return false;
    }
    static inline edk::uchar8 bitsInvert(edk::uchar8 number){
        return ~number;
    }
    static inline edk::char8 bitsInvert(edk::char8 number){
        return ~number;
    }
    static inline edk::int8 bitsInvert(edk::int8 number){
        return ~number;
    }
    static inline edk::uint16 bitsInvert(edk::uint16 number){
        return ~number;
    }
    static inline edk::int16 bitsInvert(edk::int16 number){
        return ~number;
    }
    static inline edk::uint32 bitsInvert(edk::uint32 number){
        return ~number;
    }
    static inline edk::int32 bitsInvert(edk::int32 number){
        return ~number;
    }
    static inline edk::uint64 bitsInvert(edk::uint64 number){
        return ~number;
    }
    static inline edk::int64 bitsInvert(edk::int64 number){
        return ~number;
    }

    //AND
    static inline bool bitsAND(edk::uchar8* bytes1,edk::uchar8* bytes2,edk::uchar8* bytesDest,edk::uint32 size){
        if(bytes1 && bytes2 && bytesDest && size){
            for(edk::uint32 i=0u;i<size;i++){
                bytesDest[i]=bytes1[i]&bytes2[i];
            }
            return true;
        }
        return false;
    }
    static inline bool bitsAND(edk::char8* bytes1,edk::char8* bytes2,edk::uchar8* bytesDest,edk::uint32 size){
        if(bytes1 && bytes2 && bytesDest && size){
            for(edk::uint32 i=0u;i<size;i++){
                bytesDest[i]=bytes1[i]&bytes2[i];
            }
            return true;
        }
        return false;
    }
    static inline edk::uchar8 bitsAND(edk::uchar8 number1,edk::uchar8 number2){
        return number1&number2;
    }
    static inline edk::char8 bitsAND(edk::char8 number1,edk::char8 number2){
        return number1&number2;
    }
    static inline edk::int8 bitsAND(edk::int8 number1,edk::int8 number2){
        return number1&number2;
    }
    static inline edk::uint16 bitsAND(edk::uint16 number1,edk::uint16 number2){
        return number1&number2;
    }
    static inline edk::int16 bitsAND(edk::int16 number1,edk::int16 number2){
        return number1&number2;
    }
    static inline edk::uint32 bitsAND(edk::uint32 number1,edk::uint32 number2){
        return number1&number2;
    }
    static inline edk::int32 bitsAND(edk::int32 number1,edk::int32 number2){
        return number1&number2;
    }
    static inline edk::uint64 bitsAND(edk::uint64 number1,edk::uint64 number2){
        return number1&number2;
    }
    static inline edk::int64 bitsAND(edk::int64 number1,edk::int64 number2){
        return number1&number2;
    }

    //OR
    static inline bool bitsOR(edk::uchar8* bytes1,edk::uchar8* bytes2,edk::uchar8* bytesDest,edk::uint32 size){
        if(bytes1 && bytes2 && bytesDest && size){
            for(edk::uint32 i=0u;i<size;i++){
                bytesDest[i]=bytes1[i]|bytes2[i];
            }
            return true;
        }
        return false;
    }
    static inline bool bitsOR(edk::char8* bytes1,edk::char8* bytes2,edk::uchar8* bytesDest,edk::uint32 size){
        if(bytes1 && bytes2 && bytesDest && size){
            for(edk::uint32 i=0u;i<size;i++){
                bytesDest[i]=bytes1[i]|bytes2[i];
            }
            return true;
        }
        return false;
    }
    static inline edk::uchar8 bitsOR(edk::uchar8 number1,edk::uchar8 number2){
        return number1|number2;
    }
    static inline edk::char8 bitsOR(edk::char8 number1,edk::char8 number2){
        return number1|number2;
    }
    static inline edk::int8 bitsOR(edk::int8 number1,edk::int8 number2){
        return number1|number2;
    }
    static inline edk::uint16 bitsOR(edk::uint16 number1,edk::uint16 number2){
        return number1|number2;
    }
    static inline edk::int16 bitsOR(edk::int16 number1,edk::int16 number2){
        return number1|number2;
    }
    static inline edk::uint32 bitsOR(edk::uint32 number1,edk::uint32 number2){
        return number1|number2;
    }
    static inline edk::int32 bitsOR(edk::int32 number1,edk::int32 number2){
        return number1|number2;
    }
    static inline edk::uint64 bitsOR(edk::uint64 number1,edk::uint64 number2){
        return number1|number2;
    }
    static inline edk::int64 bitsOR(edk::int64 number1,edk::int64 number2){
        return number1|number2;
    }

    //XOR
    static inline bool bitsXOR(edk::uchar8* bytes1,edk::uchar8* bytes2,edk::uchar8* bytesDest,edk::uint32 size){
        if(bytes1 && bytes2 && bytesDest && size){
            for(edk::uint32 i=0u;i<size;i++){
                bytesDest[i]=bytes1[i]^bytes2[i];
            }
            return true;
        }
        return false;
    }
    static inline bool bitsXOR(edk::char8* bytes1,edk::char8* bytes2,edk::uchar8* bytesDest,edk::uint32 size){
        if(bytes1 && bytes2 && bytesDest && size){
            for(edk::uint32 i=0u;i<size;i++){
                bytesDest[i]=bytes1[i]^bytes2[i];
            }
            return true;
        }
        return false;
    }
    static inline edk::uchar8 bitsXOR(edk::uchar8 number1,edk::uchar8 number2){
        return number1^number2;
    }
    static inline edk::char8 bitsXOR(edk::char8 number1,edk::char8 number2){
        return number1^number2;
    }
    static inline edk::int8 bitsXOR(edk::int8 number1,edk::int8 number2){
        return number1^number2;
    }
    static inline edk::uint16 bitsXOR(edk::uint16 number1,edk::uint16 number2){
        return number1^number2;
    }
    static inline edk::int16 bitsXOR(edk::int16 number1,edk::int16 number2){
        return number1^number2;
    }
    static inline edk::uint32 bitsXOR(edk::uint32 number1,edk::uint32 number2){
        return number1^number2;
    }
    static inline edk::int32 bitsXOR(edk::int32 number1,edk::int32 number2){
        return number1^number2;
    }
    static inline edk::uint64 bitsXOR(edk::uint64 number1,edk::uint64 number2){
        return number1^number2;
    }
    static inline edk::int64 bitsXOR(edk::int64 number1,edk::int64 number2){
        return number1^number2;
    }

    //acende um bit especifico
    static inline void setBitTrue(edk::uchar8* byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::uchar8)*8u)){
            //
            *byte = *byte | (1u<<position);
        }
    }
    static inline void setBitFalse(edk::uchar8* byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::uchar8)*8u)){
            //
            *byte = *byte & (~(1u<<position));
        }
    }
    static inline void setBitTrue(edk::char8* byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::char8)*8u)){
            //
            *byte = *byte | (1u<<position);
        }
    }
    static inline void setBitFalse(edk::char8* byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::char8)*8u)){
            //
            *byte = *byte & (~(1u<<position));
        }
    }
    static inline void setBitTrue(edk::int8* byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::int8)*8u)){
            //
            *byte = *byte | (1u<<position);
        }
    }
    static inline void setBitFalse(edk::int8* byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::int8)*8u)){
            //
            *byte = *byte & (~(1u<<position));
        }
    }

    static inline edk::uint8 setBitTrue(edk::uint8 number,edk::uint8 position){
        if(position<(sizeof(edk::uint8)*8u)){
            //
            number = number | (1u<<position);
            return number;
        }
        return 0u;
    }
    static inline edk::uint8 setBitFalse(edk::uint8 number,edk::uint8 position){
        if(position<(sizeof(edk::uint8)*8u)){
            //
            number = number & (~(1u<<position));
            return number;
        }
        return 0u;
    }
    static inline edk::uint16 setBitTrue(edk::uint16 number,edk::uint8 position){
        if(position<(sizeof(edk::uint16)*8u)){
            //
            number = number | (1u<<position);
            return number;
        }
        return 0u;
    }
    static inline edk::uint16 setBitFalse(edk::uint16 number,edk::uint8 position){
        if(position<(sizeof(edk::uint16)*8u)){
            //
            number = number & (~(1u<<position));
            return number;
        }
        return 0u;
    }
    static inline edk::uint32 setBitTrue(edk::uint32 number,edk::uint8 position){
        if(position<(sizeof(edk::uint32)*8u)){
            //
            number = number | (1u<<position);
            return number;
        }
        return 0u;
    }
    static inline edk::uint32 setBitFalse(edk::uint32 number,edk::uint8 position){
        if(position<(sizeof(edk::uint32)*8u)){
            //
            number = number & (~(1u<<position));
            return number;
        }
        return 0u;
    }
    static inline edk::uint64 setBitTrue(edk::uint64 number,edk::uint8 position){
        if(position<(sizeof(edk::uint64)*8u)){
            //
            number = number | (1u<<position);
            return number;
        }
        return 0u;
    }
    static inline edk::uint64 setBitFalse(edk::uint64 number,edk::uint8 position){
        if(position<(sizeof(edk::uint64)*8u)){
            //
            number = number & (~(1u<<position));
            return number;
        }
        return 0u;
    }

    static inline edk::uint32 joinBits(edk::uint32 number1,edk::uint32 number2,edk::uint32 position){
        edk::uint32 ret = number1;
        if(position<=32u){
            ret  = ret<<position;
            position = 32u-position;
            number2 = (number2<<position)>>position;
            ret = ret|number2;
        }
        return ret;
    }
    static inline edk::uint64 joinBits(edk::uint64 number1,edk::uint64 number2,edk::uint32 position){
        edk::uint64 ret = number1;
        if(position<=64u){
            ret  = ret<<position;
            position = 64u-position;
            number2 = (number2<<position)>>position;
            ret = ret|number2;
        }
        return ret;
    }
    static inline edk::uint32 getStart(edk::uint32 number,edk::uint8 position){
        return number>>position;
    }
    static inline edk::uint64 getStart(edk::uint64 number,edk::uint8 position){
        return number>>position;
    }
    static inline edk::uint32 getEnd(edk::uint32 number,edk::uint8 position){
        position = 32u-position;
        return (number<<position)>>position;
    }
    static inline edk::uint64 getEnd(edk::uint64 number,edk::uint8 position){
        position = 64u-position;
        return (number<<position)>>position;
    }
    //joint bytes
    static inline edk::uint16 joinBytesLittleEndian(edk::uint8 byte1,edk::uint8 byte0){
        return ((edk::uint16)byte1<<8u) + ((edk::uint16)byte0);
    }
    static inline edk::uint32 joinBytesLittleEndian(edk::uint8 byte3,edk::uint8 byte2,edk::uint8 byte1,edk::uint8 byte0){
        return ((edk::uint32)byte3<<24u) + ((edk::uint32)byte2<<16u) + ((edk::uint32)byte1<<8u) + (edk::uint32)byte0;
    }
    static inline edk::uint64 joinBytesLittleEndian(edk::uint8 byte7,
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
    static inline edk::uint16 joinBytesBigEndian(edk::uint8 byte0,edk::uint8 byte1){
        return ((edk::uint16)byte1<<8u) + ((edk::uint16)byte0);
    }
    static inline edk::uint32 joinBytesBigEndian(edk::uint8 byte0,edk::uint8 byte1,edk::uint8 byte2,edk::uint8 byte3){
        return ((edk::uint32)byte3<<24u) + ((edk::uint32)byte2<<16u) + ((edk::uint32)byte1<<8u) + (edk::uint32)byte0;
    }
    static inline edk::uint64 joinBytesBigEndian(edk::uint8 byte0,
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
    static inline edk::uint8 getByteLittleEndian(edk::uint16 number,edk::uint8 position){
        //
        if(position<sizeof(number)){
            return (edk::uint8)((number<<((edk::uint8)(position*-8)+((sizeof(number)-1u)*8)))
                                >>((sizeof(number)-1u) * 8u));
        }
        return 0u;
    }
    static inline edk::uint8 getByteLittleEndian(edk::uint32 number,edk::uint8 position){
        //
        if(position<sizeof(number)){
            return (edk::uint8)((number<<((edk::uint8)(position*-8)+((sizeof(number)-1u)*8)))
                                >>((sizeof(number)-1u) * 8u));
        }
        return 0u;
    }
    static inline edk::uint8 getByteLittleEndian(edk::uint64 number,edk::uint8 position){
        //
        if(position<sizeof(number)){
            return (edk::uint8)((number<<((edk::uint8)(position*-8)+((sizeof(number)-1u)*8)))
                                >>((sizeof(number)-1u) * 8u));
        }
        return 0u;
    }
    static inline edk::uint8 getByteBigEndian(edk::uint16 number,edk::uint8 position){
        return getByteLittleEndian(number,position*-1+sizeof(number)-1u);
    }
    static inline edk::uint8 getByteBigEndian(edk::uint32 number,edk::uint8 position){
        return getByteLittleEndian(number,position*-1+sizeof(number)-1u);
    }
    static inline edk::uint8 getByteBigEndian(edk::uint64 number,edk::uint8 position){
        return getByteLittleEndian(number,position*-1+sizeof(number)-1u);
    }

    //testa se um bit especifico esta true or false
    static inline bool testBit(edk::uchar8 byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::uchar8)*8u)){
            edk::uchar8 byteCompare = 1u<<position;
            return (bool)(byteCompare & byte);
        }
        return false;
    }
    static inline bool testBit(edk::char8 byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::char8)*8u)){
            edk::char8 byteCompare = 1u<<position;
            return (bool)(byteCompare & byte);
        }
        return false;
    }
    static inline bool testBit(edk::int8 byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::int8)*8u)){
            edk::int8 byteCompare = 1u<<position;
            return (bool)(byteCompare & byte);
        }
        return false;
    }
    static inline bool testBit(edk::uint16 byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::uint16)*8u)){
            edk::uint16 byteCompare = 1u<<position;
            return (bool)(byteCompare & byte);
        }
        return false;
    }
    static inline bool testBit(edk::int16 byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::int16)*8u)){
            edk::int16 byteCompare = 1u<<position;
            return (bool)(byteCompare & byte);
        }
        return false;
    }
    static inline bool testBit(edk::uint32 byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::uint32)*8u)){
            edk::uint32 byteCompare = 1u<<position;
            return (bool)(byteCompare & byte);
        }
        return false;
    }
    static inline bool testBit(edk::int32 byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::int32)*8u)){
            edk::int32 byteCompare = 1u<<position;
            return (bool)(byteCompare & byte);
        }
        return false;
    }
    static inline bool testBit(edk::uint64 byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::uint64)*8u)){
            edk::uint64 byteCompare = 1u<<position;
            return (bool)(byteCompare & byte);
        }
        return false;
    }
    static inline bool testBit(edk::int64 byte,edk::uint8 position){
        if(byte && position<(sizeof(edk::int64)*8u)){
            edk::int64 byteCompare = 1u<<position;
            return (bool)(byteCompare & byte);
        }
        return false;
    }
private:
    edk::classID classThis;
};
}//end namespace edk

#endif // BINARYCONVERTER_H
