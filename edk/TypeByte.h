#ifndef TYPEBYTE_H
#define TYPEBYTE_H
/*
Library C++ TypeByte - Byte type used by EDK Game Engine
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
#pragma message "Inside TypeByte"
#endif

#pragma once
#include <stdio.h>
#include "TypeVars.h"

#ifdef printMessages
#pragma message "    Compiling TypeByte"
#endif

namespace edk {
union ubyte{
    struct sbyte{
        edk::char8 pos0:1;
        edk::char8 pos1:1;
        edk::char8 pos2:1;
        edk::char8 pos3:1;
        edk::char8 pos4:1;
        edk::char8 pos5:1;
        edk::char8 pos6:1;
        edk::char8 pos7:1;
    }pos;
    edk::char8 value;
};

class Byte{
public:
    Byte(){
        this->classThis=NULL;edkEnd();
        this->Constructor(false);
    }
    virtual ~Byte(){
        if(this->classThis==this){
            this->classThis=NULL;edkEnd();
            //can destruct the class
        }
    }

    void Constructor(bool runFather=true){
        if(runFather){runFather=false;}
        if(this->classThis!=this){
            this->classThis=this;
        }
    }
    //
    inline bool set(edk::uint8 position,edk::uint8 value){
        switch(position){
        case 0u:
            this->b.pos.pos0 = value;
            break;
        case 1u:
            this->b.pos.pos1 = value;
            break;
        case 2u:
            this->b.pos.pos2 = value;
            break;
        case 3u:
            this->b.pos.pos3 = value;
            break;
        case 4u:
            this->b.pos.pos4 = value;
            break;
        case 5u:
            this->b.pos.pos5 = value;
            break;
        case 6u:
            this->b.pos.pos6 = value;
            break;
        case 7u:
            this->b.pos.pos7 = value;
            break;
        default:
            return false;
        }
        return true;
    }
    inline bool set(edk::uint16 position,edk::uint8 value){
        switch(position){
        case 0u:
            this->b.pos.pos0 = value;
            break;
        case 1u:
            this->b.pos.pos1 = value;
            break;
        case 2u:
            this->b.pos.pos2 = value;
            break;
        case 3u:
            this->b.pos.pos3 = value;
            break;
        case 4u:
            this->b.pos.pos4 = value;
            break;
        case 5u:
            this->b.pos.pos5 = value;
            break;
        case 6u:
            this->b.pos.pos6 = value;
            break;
        case 7u:
            this->b.pos.pos7 = value;
            break;
        default:
            return false;
        }
        return true;
    }
    inline bool set(edk::uint32 position,edk::uint8 value){
        switch(position){
        case 0u:
            this->b.pos.pos0 = value;
            break;
        case 1u:
            this->b.pos.pos1 = value;
            break;
        case 2u:
            this->b.pos.pos2 = value;
            break;
        case 3u:
            this->b.pos.pos3 = value;
            break;
        case 4u:
            this->b.pos.pos4 = value;
            break;
        case 5u:
            this->b.pos.pos5 = value;
            break;
        case 6u:
            this->b.pos.pos6 = value;
            break;
        case 7u:
            this->b.pos.pos7 = value;
            break;
        default:
            return false;
        }
        return true;
    }
    inline bool set(edk::uint64 position,edk::uint8 value){
        switch(position){
        case 0u:
            this->b.pos.pos0 = value;
            break;
        case 1u:
            this->b.pos.pos1 = value;
            break;
        case 2u:
            this->b.pos.pos2 = value;
            break;
        case 3u:
            this->b.pos.pos3 = value;
            break;
        case 4u:
            this->b.pos.pos4 = value;
            break;
        case 5u:
            this->b.pos.pos5 = value;
            break;
        case 6u:
            this->b.pos.pos6 = value;
            break;
        case 7u:
            this->b.pos.pos7 = value;
            break;
        default:
            return false;
        }
        return true;
    }
    inline bool set(edk::int8 position,edk::uint8 value){
        switch(position){
        case 0:
            this->b.pos.pos0 = value;
            break;
        case 1:
            this->b.pos.pos1 = value;
            break;
        case 2:
            this->b.pos.pos2 = value;
            break;
        case 3:
            this->b.pos.pos3 = value;
            break;
        case 4:
            this->b.pos.pos4 = value;
            break;
        case 5:
            this->b.pos.pos5 = value;
            break;
        case 6:
            this->b.pos.pos6 = value;
            break;
        case 7:
            this->b.pos.pos7 = value;
            break;
        default:
            return false;
        }
        return true;
    }
    inline bool set(edk::int16 position,edk::uint8 value){
        switch(position){
        case 0:
            this->b.pos.pos0 = value;
            break;
        case 1:
            this->b.pos.pos1 = value;
            break;
        case 2:
            this->b.pos.pos2 = value;
            break;
        case 3:
            this->b.pos.pos3 = value;
            break;
        case 4:
            this->b.pos.pos4 = value;
            break;
        case 5:
            this->b.pos.pos5 = value;
            break;
        case 6:
            this->b.pos.pos6 = value;
            break;
        case 7:
            this->b.pos.pos7 = value;
            break;
        default:
            return false;
        }
        return true;
    }
    inline bool set(edk::int32 position,edk::uint8 value){
        switch(position){
        case 0:
            this->b.pos.pos0 = value;
            break;
        case 1:
            this->b.pos.pos1 = value;
            break;
        case 2:
            this->b.pos.pos2 = value;
            break;
        case 3:
            this->b.pos.pos3 = value;
            break;
        case 4:
            this->b.pos.pos4 = value;
            break;
        case 5:
            this->b.pos.pos5 = value;
            break;
        case 6:
            this->b.pos.pos6 = value;
            break;
        case 7:
            this->b.pos.pos7 = value;
            break;
        default:
            return false;
        }
        return true;
    }
    inline bool set(edk::int64 position,edk::uint8 value){
        switch(position){
        case 0:
            this->b.pos.pos0 = value;
            break;
        case 1:
            this->b.pos.pos1 = value;
            break;
        case 2:
            this->b.pos.pos2 = value;
            break;
        case 3:
            this->b.pos.pos3 = value;
            break;
        case 4:
            this->b.pos.pos4 = value;
            break;
        case 5:
            this->b.pos.pos5 = value;
            break;
        case 6:
            this->b.pos.pos6 = value;
            break;
        case 7:
            this->b.pos.pos7 = value;
            break;
        default:
            return false;
        }
        return true;
    }
    inline bool swap(edk::int64 position){
        switch(position){
        case 0:
            this->b.pos.pos0 += 1u;
            break;
        case 1:
            this->b.pos.pos1 += 1u;
            break;
        case 2:
            this->b.pos.pos2 += 1u;
            break;
        case 3:
            this->b.pos.pos3 += 1u;
            break;
        case 4:
            this->b.pos.pos4 += 1u;
            break;
        case 5:
            this->b.pos.pos5 += 1u;
            break;
        case 6:
            this->b.pos.pos6 += 1u;
            break;
        case 7:
            this->b.pos.pos7 += 1u;
            break;
        default:
            return false;
        }
        return true;
    }
    //
    inline void setValue(edk::uint8 value){
        this->b.value=value;
    }
    inline void setValue(edk::uint16 value){
        this->b.value=value;
    }
    inline void setValue(edk::uint32 value){
        this->b.value=value;
    }
    inline void setValue(edk::uint64 value){
        this->b.value=value;
    }
    inline void setValue(edk::int8 value){
        this->b.value=value;
    }
    inline void setValue(edk::int16 value){
        this->b.value=value;
    }
    inline void setValue(edk::int32 value){
        this->b.value=value;
    }
    inline void setValue(edk::int64 value){
        this->b.value=value;
    }
    inline void setValue(edk::char8 value){
        this->b.value=value;
    }
    //
    inline edk::uint8 get(edk::uint8 position){
        switch(position){
        case 0u:
            return this->b.pos.pos0;
        case 1u:
            return this->b.pos.pos1;
        case 2u:
            return this->b.pos.pos2;
        case 3u:
            return this->b.pos.pos3;
        case 4u:
            return this->b.pos.pos4;
        case 5u:
            return this->b.pos.pos5;
        case 6u:
            return this->b.pos.pos6;
        case 7u:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    inline bool getBool(edk::uint8 position){
        switch(position){
        case 0u:
            return (bool)this->b.pos.pos0;
        case 1u:
            return (bool)this->b.pos.pos1;
        case 2u:
            return (bool)this->b.pos.pos2;
        case 3u:
            return (bool)this->b.pos.pos3;
        case 4u:
            return (bool)this->b.pos.pos4;
        case 5u:
            return (bool)this->b.pos.pos5;
        case 6u:
            return (bool)this->b.pos.pos6;
        case 7u:
            return (bool)this->b.pos.pos7;
        default:
            return false;
        }
        return false;
    }
    inline edk::uint8 getUI8(edk::uint8 position){
        switch(position){
        case 0u:
            return this->b.pos.pos0;
        case 1u:
            return this->b.pos.pos1;
        case 2u:
            return this->b.pos.pos2;
        case 3u:
            return this->b.pos.pos3;
        case 4u:
            return this->b.pos.pos4;
        case 5u:
            return this->b.pos.pos5;
        case 6u:
            return this->b.pos.pos6;
        case 7u:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    inline edk::uchar8 getUCHAR8(edk::uint8 position){
        switch(position){
        case 0u:
            return this->b.pos.pos0;
        case 1u:
            return this->b.pos.pos1;
        case 2u:
            return this->b.pos.pos2;
        case 3u:
            return this->b.pos.pos3;
        case 4u:
            return this->b.pos.pos4;
        case 5u:
            return this->b.pos.pos5;
        case 6u:
            return this->b.pos.pos6;
        case 7u:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    inline edk::int8 getI8(edk::uint8 position){
        switch(position){
        case 0u:
            return this->b.pos.pos0;
        case 1u:
            return this->b.pos.pos1;
        case 2u:
            return this->b.pos.pos2;
        case 3u:
            return this->b.pos.pos3;
        case 4u:
            return this->b.pos.pos4;
        case 5u:
            return this->b.pos.pos5;
        case 6u:
            return this->b.pos.pos6;
        case 7u:
            return this->b.pos.pos7;
        default:
            return 0;
        }
        return 0;
    }
    inline edk::char8 getCHAR8(edk::uint8 position){
        switch(position){
        case 0u:
            return this->b.pos.pos0;
        case 1u:
            return this->b.pos.pos1;
        case 2u:
            return this->b.pos.pos2;
        case 3u:
            return this->b.pos.pos3;
        case 4u:
            return this->b.pos.pos4;
        case 5u:
            return this->b.pos.pos5;
        case 6u:
            return this->b.pos.pos6;
        case 7u:
            return this->b.pos.pos7;
        default:
            return 0;
        }
        return 0;
    }
    inline edk::uint8 get(){
        return this->b.value;
    }
    inline bool getBool(){
        return this->b.value;
    }
    inline edk::uint8 getUI8(){
        return this->b.value;
    }
    inline edk::uchar8 getUCHAR8(){
        return this->b.value;
    }
    inline edk::int8 getI8(){
        return this->b.value;
    }
    inline edk::char8 getCHAR8(){
        return this->b.value;
    }
    inline edk::uint8 value(){
        return this->b.value;
    }
    inline bool valueBool(){
        return this->b.value;
    }
    inline edk::uint8 valueUI8(){
        return this->b.value;
    }
    inline edk::uchar8 valueUCHAR8(){
        return this->b.value;
    }
    inline edk::int8 valueI8(){
        return this->b.value;
    }
    inline edk::char8 valueCHAR8(){
        return this->b.value;
    }
    inline edk::uint8 operator[](edk::uint8 position){
        switch(position){
        case 0u:
            return this->b.pos.pos0;
        case 1u:
            return this->b.pos.pos1;
        case 2u:
            return this->b.pos.pos2;
        case 3u:
            return this->b.pos.pos3;
        case 4u:
            return this->b.pos.pos4;
        case 5u:
            return this->b.pos.pos5;
        case 6u:
            return this->b.pos.pos6;
        case 7u:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    inline edk::uint8 operator[](edk::uint16 position){
        switch(position){
        case 0u:
            return this->b.pos.pos0;
        case 1u:
            return this->b.pos.pos1;
        case 2u:
            return this->b.pos.pos2;
        case 3u:
            return this->b.pos.pos3;
        case 4u:
            return this->b.pos.pos4;
        case 5u:
            return this->b.pos.pos5;
        case 6u:
            return this->b.pos.pos6;
        case 7u:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    inline edk::uint8 operator[](edk::uint32 position){
        switch(position){
        case 0u:
            return this->b.pos.pos0;
        case 1u:
            return this->b.pos.pos1;
        case 2u:
            return this->b.pos.pos2;
        case 3u:
            return this->b.pos.pos3;
        case 4u:
            return this->b.pos.pos4;
        case 5u:
            return this->b.pos.pos5;
        case 6u:
            return this->b.pos.pos6;
        case 7u:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    inline edk::uint8 operator[](edk::uint64 position){
        switch(position){
        case 0u:
            return this->b.pos.pos0;
        case 1u:
            return this->b.pos.pos1;
        case 2u:
            return this->b.pos.pos2;
        case 3u:
            return this->b.pos.pos3;
        case 4u:
            return this->b.pos.pos4;
        case 5u:
            return this->b.pos.pos5;
        case 6u:
            return this->b.pos.pos6;
        case 7u:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    inline edk::uint8 operator[](edk::int8 position){
        switch(position){
        case 0:
            return this->b.pos.pos0;
        case 1:
            return this->b.pos.pos1;
        case 2:
            return this->b.pos.pos2;
        case 3:
            return this->b.pos.pos3;
        case 4:
            return this->b.pos.pos4;
        case 5:
            return this->b.pos.pos5;
        case 6:
            return this->b.pos.pos6;
        case 7:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    inline edk::uint8 operator[](edk::int16 position){
        switch(position){
        case 0:
            return this->b.pos.pos0;
        case 1:
            return this->b.pos.pos1;
        case 2:
            return this->b.pos.pos2;
        case 3:
            return this->b.pos.pos3;
        case 4:
            return this->b.pos.pos4;
        case 5:
            return this->b.pos.pos5;
        case 6:
            return this->b.pos.pos6;
        case 7:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    inline edk::uint8 operator[](edk::int32 position){
        switch(position){
        case 0:
            return this->b.pos.pos0;
        case 1:
            return this->b.pos.pos1;
        case 2:
            return this->b.pos.pos2;
        case 3:
            return this->b.pos.pos3;
        case 4:
            return this->b.pos.pos4;
        case 5:
            return this->b.pos.pos5;
        case 6:
            return this->b.pos.pos6;
        case 7:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    inline edk::uint8 operator[](edk::int64 position){
        switch(position){
        case 0:
            return this->b.pos.pos0;
        case 1:
            return this->b.pos.pos1;
        case 2:
            return this->b.pos.pos2;
        case 3:
            return this->b.pos.pos3;
        case 4:
            return this->b.pos.pos4;
        case 5:
            return this->b.pos.pos5;
        case 6:
            return this->b.pos.pos6;
        case 7:
            return this->b.pos.pos7;
        default:
            return 0u;
        }
        return 0u;
    }
    //
    inline edk::uint8 operator=(edk::uint8 value){
        return this->b.value=value;
    }
    inline edk::uint8 operator=(edk::uint16 value){
        return this->b.value=(edk::uint8)value;
    }
    inline edk::uint8 operator=(edk::uint32 value){
        return this->b.value=(edk::uint8)value;
    }
    inline edk::uint8 operator=(edk::uint64 value){
        return this->b.value=(edk::uint8)value;
    }
    inline edk::uint8 operator=(edk::int8 value){
        return this->b.value=(edk::uint8)value;
    }
    inline edk::uint8 operator=(edk::int16 value){
        return this->b.value=(edk::uint8)value;
    }
    inline edk::uint8 operator=(edk::int32 value){
        return this->b.value=(edk::uint8)value;
    }
    inline edk::uint8 operator=(edk::int64 value){
        return this->b.value=(edk::uint8)value;
    }
    //
    inline edk::uint8 operator!=(edk::uint8 value){
        return this->b.value=!value;
    }
    inline edk::uint8 operator!=(edk::uint16 value){
        return this->b.value=(edk::uint8)!value;
    }
    inline edk::uint8 operator!=(edk::uint32 value){
        return this->b.value=(edk::uint8)!value;
    }
    inline edk::uint8 operator!=(edk::uint64 value){
        return this->b.value=(edk::uint8)!value;
    }
    inline edk::uint8 operator!=(edk::int8 value){
        return this->b.value=(edk::uint8)!value;
    }
    inline edk::uint8 operator!=(edk::int16 value){
        return this->b.value=(edk::uint8)!value;
    }
    inline edk::uint8 operator!=(edk::int32 value){
        return this->b.value=(edk::uint8)!value;
    }
    inline edk::uint8 operator!=(edk::int64 value){
        return this->b.value=(edk::uint8)!value;
    }
    //
    inline edk::uint8 operator!(){
        return !this->b.value;
    }
    //
    inline bool operator==(edk::uint8 value){
        return this->b.value==value;
    }
    inline bool operator==(edk::uint16 value){
        return this->b.value==(edk::uint8)value;
    }
    inline bool operator==(edk::uint32 value){
        return this->b.value==(edk::uint8)value;
    }
    inline bool operator==(edk::uint64 value){
        return this->b.value==(edk::uint8)value;
    }
    inline bool operator==(edk::int8 value){
        return this->b.value==(edk::uint8)value;
    }
    inline bool operator==(edk::int16 value){
        return this->b.value==(edk::uint8)value;
    }
    inline bool operator==(edk::int32 value){
        return this->b.value==(edk::uint8)value;
    }
    inline bool operator==(edk::int64 value){
        return this->b.value==(edk::uint8)value;
    }
    //
    inline edk::uint8 operator+=(edk::uint8 value){
        return this->b.value+=value;
    }
    inline edk::uint8 operator+=(edk::uint16 value){
        return this->b.value+=(edk::uint8)value;
    }
    inline edk::uint8 operator+=(edk::uint32 value){
        return this->b.value+=(edk::uint8)value;
    }
    inline edk::uint8 operator+=(edk::uint64 value){
        return this->b.value+=(edk::uint8)value;
    }
    inline edk::uint8 operator+=(edk::int8 value){
        return this->b.value+=(edk::uint8)value;
    }
    inline edk::uint8 operator+=(edk::int16 value){
        return this->b.value+=(edk::uint8)value;
    }
    inline edk::uint8 operator+=(edk::int32 value){
        return this->b.value+=(edk::uint8)value;
    }
    inline edk::uint8 operator+=(edk::int64 value){
        return this->b.value+=(edk::uint8)value;
    }
    //
    inline edk::uint8 operator-=(edk::uint8 value){
        return this->b.value-=value;
    }
    inline edk::uint8 operator-=(edk::uint16 value){
        return this->b.value-=(edk::uint8)value;
    }
    inline edk::uint8 operator-=(edk::uint32 value){
        return this->b.value-=(edk::uint8)value;
    }
    inline edk::uint8 operator-=(edk::uint64 value){
        return this->b.value-=(edk::uint8)value;
    }
    inline edk::uint8 operator-=(edk::int8 value){
        return this->b.value-=(edk::uint8)value;
    }
    inline edk::uint8 operator-=(edk::int16 value){
        return this->b.value-=(edk::uint8)value;
    }
    inline edk::uint8 operator-=(edk::int32 value){
        return this->b.value-=(edk::uint8)value;
    }
    inline edk::uint8 operator-=(edk::int64 value){
        return this->b.value-=(edk::uint8)value;
    }
    //
    inline edk::uint8 operator++(){
        return this->b.value++;
    }
    //
    inline edk::uint8 operator--(){
        return this->b.value++;
    }
    //
    inline bool operator>(edk::uint8 value){
        return this->b.value>value;
    }
    inline bool operator>(edk::uint16 value){
        return this->b.value>(edk::uint8)value;
    }
    inline bool operator>(edk::uint32 value){
        return this->b.value>(edk::uint8)value;
    }
    inline bool operator>(edk::uint64 value){
        return this->b.value>(edk::uint8)value;
    }
    inline bool operator>(edk::int8 value){
        return this->b.value>(edk::uint8)value;
    }
    inline bool operator>(edk::int16 value){
        return this->b.value>(edk::uint8)value;
    }
    inline bool operator>(edk::int32 value){
        return this->b.value>(edk::uint8)value;
    }
    inline bool operator>(edk::int64 value){
        return this->b.value>(edk::uint8)value;
    }
    //
    inline bool operator<(edk::uint8 value){
        return this->b.value<value;
    }
    inline bool operator<(edk::uint16 value){
        return this->b.value<(edk::uint8)value;
    }
    inline bool operator<(edk::uint32 value){
        return this->b.value<(edk::uint8)value;
    }
    inline bool operator<(edk::uint64 value){
        return this->b.value<(edk::uint8)value;
    }
    inline bool operator<(edk::int8 value){
        return this->b.value<(edk::uint8)value;
    }
    inline bool operator<(edk::int16 value){
        return this->b.value<(edk::uint8)value;
    }
    inline bool operator<(edk::int32 value){
        return this->b.value<(edk::uint8)value;
    }
    inline bool operator<(edk::int64 value){
        return this->b.value<(edk::uint8)value;
    }
    //
    inline edk::uint8 operator>>(edk::uint8 value){
        return this->b.value>>value;
    }
    inline edk::uint8 operator>>(edk::uint16 value){
        return this->b.value>>(edk::uint8)value;
    }
    inline edk::uint8 operator>>(edk::uint32 value){
        return this->b.value>>(edk::uint8)value;
    }
    inline edk::uint8 operator>>(edk::uint64 value){
        return this->b.value>>(edk::uint8)value;
    }
    inline edk::uint8 operator>>(edk::int8 value){
        return this->b.value>>(edk::uint8)value;
    }
    inline edk::uint8 operator>>(edk::int16 value){
        return this->b.value>>(edk::uint8)value;
    }
    inline edk::uint8 operator>>(edk::int32 value){
        return this->b.value>>(edk::uint8)value;
    }
    inline edk::uint8 operator>>(edk::int64 value){
        return this->b.value>>(edk::uint8)value;
    }
    //
    inline edk::uint8 operator<<(edk::uint8 value){
        return this->b.value<<value;
    }
    inline edk::uint8 operator<<(edk::uint16 value){
        return this->b.value<<(edk::uint8)value;
    }
    inline edk::uint8 operator<<(edk::uint32 value){
        return this->b.value<<(edk::uint8)value;
    }
    inline edk::uint8 operator<<(edk::uint64 value){
        return this->b.value<<(edk::uint8)value;
    }
    inline edk::uint8 operator<<(edk::int8 value){
        return this->b.value<<(edk::uint8)value;
    }
    inline edk::uint8 operator<<(edk::int16 value){
        return this->b.value<<(edk::uint8)value;
    }
    inline edk::uint8 operator<<(edk::int32 value){
        return this->b.value<<(edk::uint8)value;
    }
    inline edk::uint8 operator<<(edk::int64 value){
        return this->b.value<<(edk::uint8)value;
    }
    //print the byte
    inline void printBits(){
        edk::uchar8 byteCompare = 0x80;
        for (edk::uint32 i = 0; i < 8u; i++){
            if(byteCompare & this->b.value){
                printf("1");
            }
            else{
                printf("0");
            }
            byteCompare=byteCompare>>1u;
        }
    }
    inline void printValue(){
        printf("%03u",(edk::uint8)this->b.value);
    }
    inline void printHex(){
        printf("%02X",(edk::uint8)this->b.value);
    }
private:
    union ubyte b;
private:
    edk::classID classThis;
};
}//end namespace ekd

#endif // TYPEBYTE_H
