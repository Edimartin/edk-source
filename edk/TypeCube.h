#ifndef TYPECUBE_H
#define TYPECUBE_H

/*
Library C++ typeCube - Cube types used in Edk Game Engine
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
#pragma message "Inside TypeCube"
#endif

#pragma once
#include "TypeVars.h"
#include "TypeVec3.h"
#include "TypeSize3.h"

#ifdef printMessages
#pragma message "    Compiling TypeCube"
#endif

namespace edk{
//
class cubei8{
public:
    //position
    edk::vec3i8 origin;
    //size
    edk::size3i8 size;
    //Construtor
    cubei8(){
        //
        this->origin.x=(edk::int8)0;
        this->origin.y=(edk::int8)0;
        this->origin.z=(edk::int8)0;
        this->size.width=(edk::int8)0;
        this->size.height=(edk::int8)0;
        this->size.length=(edk::int8)0;
    }
    cubei8(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->origin.z=(edk::int8)z;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        this->size.length=(edk::int8)length;
    }
    cubei8(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->origin.z=(edk::int8)z;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        this->size.length=(edk::int8)length;
    }
    cubei8(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->origin.z=(edk::int8)z;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        this->size.length=(edk::int8)length;
    }
    cubei8(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->origin.z=(edk::int8)z;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        this->size.length=(edk::int8)length;
    }
    cubei8(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->origin.z=(edk::int8)z;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        this->size.length=(edk::int8)length;
    }
    cubei8(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->origin.z=(edk::int8)z;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        this->size.length=(edk::int8)length;
    }
    cubei8(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->origin.z=(edk::int8)z;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        this->size.length=(edk::int8)length;
    }
    cubei8(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->origin.z=(edk::int8)z;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        this->size.length=(edk::int8)length;
    }
    cubei8(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->origin.z=(edk::int8)origin.z;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
        this->size.length=(edk::int8)size.length;
    }
    cubei8(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->origin.z=(edk::int8)origin.z;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
        this->size.length=(edk::int8)size.length;
    }
    cubei8(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->origin.z=(edk::int8)origin.z;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
        this->size.length=(edk::int8)size.length;
    }
    cubei8(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->origin.z=(edk::int8)origin.z;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
        this->size.length=(edk::int8)size.length;
    }
    cubei8(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->origin.z=(edk::int8)origin.z;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
        this->size.length=(edk::int8)size.length;
    }
    cubei8(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->origin.z=(edk::int8)origin.z;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
        this->size.length=(edk::int8)size.length;
    }
    cubei8(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->origin.z=(edk::int8)origin.z;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
        this->size.length=(edk::int8)size.length;
    }
    cubei8(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::int8)origin.x;
        this->origin.y=(edk::int8)origin.y;
        this->origin.z=(edk::int8)origin.z;
        this->size.width=(edk::int8)size.width;
        this->size.height=(edk::int8)size.height;
        this->size.length=(edk::int8)size.length;
    }

    //operators
    inline edk::cubei8 operator=(edk::cubei8 cube){
        //
        this->origin.x=(edk::int8)cube.origin.x;
        this->origin.y=(edk::int8)cube.origin.y;
        this->origin.z=(edk::int8)cube.origin.z;
        this->size.width=(edk::int8)cube.size.width;
        this->size.height=(edk::int8)cube.size.height;
        this->size.length=(edk::int8)cube.size.length;
        return *this;
    }
    inline edk::cubei8 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    inline edk::cubei8 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    inline edk::cubei8 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    inline edk::cubei8 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    inline edk::cubei8 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    inline edk::cubei8 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    inline edk::cubei8 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    inline edk::cubei8 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }

    inline bool operator==(edk::cubei8 cube){
        //
        return (this->origin.x==(edk::int8)cube.origin.x
                &&this->origin.y==(edk::int8)cube.origin.y
                &&this->origin.z==(edk::int8)cube.origin.z
                &&this->size.width==(edk::int8)cube.size.width
                &&this->size.height==(edk::int8)cube.size.height
                &&this->size.length==(edk::int8)cube.size.length
                );
    }
    inline bool operator!=(edk::cubei8 cube){
        //
        return (this->origin.x!=(edk::int8)cube.origin.x
                ||this->origin.y!=(edk::int8)cube.origin.y
                ||this->origin.z!=(edk::int8)cube.origin.z
                ||this->size.width!=(edk::int8)cube.size.width
                ||this->size.height!=(edk::int8)cube.size.height
                ||this->size.length!=(edk::int8)cube.size.length
                );
    }
    inline edk::cubei8 operator+(edk::cubei8 cube){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::int8)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::int8)cube.origin.z;
        ret.size.width=this->size.width+(edk::int8)cube.size.width;
        ret.size.height=this->size.height+(edk::int8)cube.size.height;
        ret.size.length=this->size.length+(edk::int8)cube.size.length;
        return ret;
    }
    inline edk::cubei8 operator+(edk::int8 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator+(edk::int32 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator+(edk::int16 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator+(edk::int64 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator+(edk::uint8 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator+(edk::uint32 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator+(edk::uint16 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator+(edk::uint64 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    inline void operator+=(edk::cubei8 cube){
        //
        this->origin.x+=(edk::int8)cube.origin.x;
        this->origin.y+=(edk::int8)cube.origin.y;
        this->origin.z+=(edk::int8)cube.origin.z;
        this->size.width+=(edk::int8)cube.size.width;
        this->size.height+=(edk::int8)cube.size.height;
        this->size.length+=(edk::int8)cube.size.length;
    }
    inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    inline edk::cubei8 operator-(edk::cubei8 cube){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::int8)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::int8)cube.origin.z;
        ret.size.width=this->size.width-(edk::int8)cube.size.width;
        ret.size.height=this->size.height-(edk::int8)cube.size.height;
        ret.size.length=this->size.length-(edk::int8)cube.size.length;
        return ret;
    }
    inline edk::cubei8 operator-(edk::int8 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator-(edk::int32 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator-(edk::int16 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator-(edk::int64 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator-(edk::uint8 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator-(edk::uint32 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator-(edk::uint16 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator-(edk::uint64 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    inline void operator-=(edk::cubei8 vec){
        //
        this->origin.x-=(edk::int8)vec.origin.x;
        this->origin.y-=(edk::int8)vec.origin.y;
        this->origin.z-=(edk::int8)vec.origin.z;
        this->size.width-=(edk::int8)vec.size.width;
        this->size.height-=(edk::int8)vec.size.height;
        this->size.length-=(edk::int8)vec.size.length;
    }
    inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    inline edk::cubei8 operator*(edk::cubei8 cube){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::int8)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::int8)cube.origin.z;
        ret.size.width=this->size.width*(edk::int8)cube.size.width;
        ret.size.height=this->size.height*(edk::int8)cube.size.height;
        ret.size.length=this->size.length*(edk::int8)cube.size.length;
        return ret;
    }
    inline edk::cubei8 operator*(edk::int8 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator*(edk::int32 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator*(edk::int16 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator*(edk::int64 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator*(edk::uint8 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator*(edk::uint32 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator*(edk::uint16 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    inline edk::cubei8 operator*(edk::uint64 n){
        //
        inline edk::cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    inline void operator*=(edk::cubei8 cube){
        //
        this->origin.x*=(edk::int8)cube.origin.x;
        this->origin.y*=(edk::int8)cube.origin.y;
        this->origin.z*=(edk::int8)cube.origin.z;
        this->size.width*=(edk::int8)cube.size.width;
        this->size.height*=(edk::int8)cube.size.height;
        this->size.length*=(edk::int8)cube.size.length;
    }
    inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    //
    inline edk::cubei8 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return edk::cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei8 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return edk::cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei8 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return edk::cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei8 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return edk::cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei8 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    inline edk::cubei8 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    inline edk::cubei8 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    inline edk::cubei8 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    inline edk::cubei8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    inline edk::cubei8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    inline edk::cubei8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    inline edk::cubei8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    //function to merge the cube with another cube
    inline void merge(edk::cubei8 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->origin.z > rect.origin.z)this->origin.z = rect.origin.z;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
        if(this->size.length < rect.size.length)this->size.length = rect.size.length;
    }
};

class cubei16{
public:
    //position
    edk::vec3i16 origin;
    //size
    edk::size3i16 size;
    //Construtor
    cubei16(){
        //
        this->origin.x=(edk::int16)0;
        this->origin.y=(edk::int16)0;
        this->origin.z=(edk::int16)0;
        this->size.width=(edk::int16)0;
        this->size.height=(edk::int16)0;
        this->size.length=(edk::int16)0;
    }
    cubei16(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->origin.z=(edk::int16)z;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        this->size.length=(edk::int16)length;
    }
    cubei16(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->origin.z=(edk::int16)z;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        this->size.length=(edk::int16)length;
    }
    cubei16(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->origin.z=(edk::int16)z;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        this->size.length=(edk::int16)length;
    }
    cubei16(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->origin.z=(edk::int16)z;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        this->size.length=(edk::int16)length;
    }
    cubei16(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->origin.z=(edk::int16)z;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        this->size.length=(edk::int16)length;
    }
    cubei16(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->origin.z=(edk::int16)z;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        this->size.length=(edk::int16)length;
    }
    cubei16(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->origin.z=(edk::int16)z;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        this->size.length=(edk::int16)length;
    }
    cubei16(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->origin.z=(edk::int16)z;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        this->size.length=(edk::int16)length;
    }
    cubei16(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->origin.z=(edk::int16)origin.z;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
        this->size.length=(edk::int16)size.length;
    }
    cubei16(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->origin.z=(edk::int16)origin.z;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
        this->size.length=(edk::int16)size.length;
    }
    cubei16(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->origin.z=(edk::int16)origin.z;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
        this->size.length=(edk::int16)size.length;
    }
    cubei16(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->origin.z=(edk::int16)origin.z;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
        this->size.length=(edk::int16)size.length;
    }
    cubei16(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->origin.z=(edk::int16)origin.z;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
        this->size.length=(edk::int16)size.length;
    }
    cubei16(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->origin.z=(edk::int16)origin.z;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
        this->size.length=(edk::int16)size.length;
    }
    cubei16(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->origin.z=(edk::int16)origin.z;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
        this->size.length=(edk::int16)size.length;
    }
    cubei16(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::int16)origin.x;
        this->origin.y=(edk::int16)origin.y;
        this->origin.z=(edk::int16)origin.z;
        this->size.width=(edk::int16)size.width;
        this->size.height=(edk::int16)size.height;
        this->size.length=(edk::int16)size.length;
    }

    //operators
    inline edk::cubei16 operator=(cubei16 cube){
        //
        this->origin.x=(edk::int16)cube.origin.x;
        this->origin.y=(edk::int16)cube.origin.y;
        this->origin.z=(edk::int16)cube.origin.z;
        this->size.width=(edk::int16)cube.size.width;
        this->size.height=(edk::int16)cube.size.height;
        this->size.length=(edk::int16)cube.size.length;
        return *this;
    }
    inline edk::cubei16 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    inline edk::cubei16 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    inline edk::cubei16 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    inline edk::cubei16 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    inline edk::cubei16 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    inline edk::cubei16 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    inline edk::cubei16 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    inline edk::cubei16 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }

    inline bool operator==(cubei16 cube){
        //
        return (this->origin.x==(edk::int16)cube.origin.x
                &&this->origin.y==(edk::int16)cube.origin.y
                &&this->origin.z==(edk::int16)cube.origin.z
                &&this->size.width==(edk::int16)cube.size.width
                &&this->size.height==(edk::int16)cube.size.height
                &&this->size.length==(edk::int16)cube.size.length
                );
    }
    inline bool operator!=(cubei16 cube){
        //
        return (this->origin.x!=(edk::int16)cube.origin.x
                ||this->origin.y!=(edk::int16)cube.origin.y
                ||this->origin.z!=(edk::int16)cube.origin.z
                ||this->size.width!=(edk::int16)cube.size.width
                ||this->size.height!=(edk::int16)cube.size.height
                ||this->size.length!=(edk::int16)cube.size.length
                );
    }
    inline edk::cubei16 operator+(cubei16 cube){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::int16)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::int16)cube.origin.z;
        ret.size.width=this->size.width+(edk::int16)cube.size.width;
        ret.size.height=this->size.height+(edk::int16)cube.size.height;
        ret.size.length=this->size.length+(edk::int16)cube.size.length;
        return ret;
    }
    inline edk::cubei16 operator+(edk::int8 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator+(edk::int32 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator+(edk::int16 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator+(edk::int64 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator+(edk::uint8 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator+(edk::uint32 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator+(edk::uint16 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator+(edk::uint64 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    inline void operator+=(cubei16 cube){
        //
        this->origin.x+=(edk::int16)cube.origin.x;
        this->origin.y+=(edk::int16)cube.origin.y;
        this->origin.z+=(edk::int16)cube.origin.z;
        this->size.width+=(edk::int16)cube.size.width;
        this->size.height+=(edk::int16)cube.size.height;
        this->size.length+=(edk::int16)cube.size.length;
    }
    inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    inline edk::cubei16 operator-(cubei16 cube){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::int16)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::int16)cube.origin.z;
        ret.size.width=this->size.width-(edk::int16)cube.size.width;
        ret.size.height=this->size.height-(edk::int16)cube.size.height;
        ret.size.length=this->size.length-(edk::int16)cube.size.length;
        return ret;
    }
    inline edk::cubei16 operator-(edk::int8 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator-(edk::int32 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator-(edk::int16 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator-(edk::int64 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator-(edk::uint8 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator-(edk::uint32 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator-(edk::uint16 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator-(edk::uint64 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    inline void operator-=(cubei16 vec){
        //
        this->origin.x-=(edk::int16)vec.origin.x;
        this->origin.y-=(edk::int16)vec.origin.y;
        this->origin.z-=(edk::int16)vec.origin.z;
        this->size.width-=(edk::int16)vec.size.width;
        this->size.height-=(edk::int16)vec.size.height;
        this->size.length-=(edk::int16)vec.size.length;
    }
    inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    inline edk::cubei16 operator*(cubei16 cube){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::int16)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::int16)cube.origin.z;
        ret.size.width=this->size.width*(edk::int16)cube.size.width;
        ret.size.height=this->size.height*(edk::int16)cube.size.height;
        ret.size.length=this->size.length*(edk::int16)cube.size.length;
        return ret;
    }
    inline edk::cubei16 operator*(edk::int8 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator*(edk::int32 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator*(edk::int16 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator*(edk::int64 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator*(edk::uint8 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator*(edk::uint32 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator*(edk::uint16 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    inline edk::cubei16 operator*(edk::uint64 n){
        //
        edk::cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    inline void operator*=(cubei16 cube){
        //
        this->origin.x*=(edk::int16)cube.origin.x;
        this->origin.y*=(edk::int16)cube.origin.y;
        this->origin.z*=(edk::int16)cube.origin.z;
        this->size.width*=(edk::int16)cube.size.width;
        this->size.height*=(edk::int16)cube.size.height;
        this->size.length*=(edk::int16)cube.size.length;
    }
    inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    //
    inline edk::cubei16 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return edk::cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei16 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return edk::cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei16 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return edk::cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei16 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return edk::cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei16 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    inline edk::cubei16 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    inline edk::cubei16 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    inline edk::cubei16 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    inline edk::cubei16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    inline edk::cubei16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    inline edk::cubei16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    inline edk::cubei16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    //function to merge the cube with another cube
    inline void merge(edk::cubei8 rect){
        if(this->origin.x > (edk::int16)rect.origin.x)this->origin.x = (edk::int16)rect.origin.x;
        if(this->origin.y > (edk::int16)rect.origin.y)this->origin.y = (edk::int16)rect.origin.y;
        if(this->origin.z > (edk::int16)rect.origin.z)this->origin.z = (edk::int16)rect.origin.z;
        if(this->size.width < (edk::int16)rect.size.width)this->size.width = (edk::int16)rect.size.width;
        if(this->size.height < (edk::int16)rect.size.height)this->size.height = (edk::int16)rect.size.height;
        if(this->size.length < (edk::int16)rect.size.length)this->size.length = (edk::int16)rect.size.length;
    }
    inline void merge(edk::cubei16 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->origin.z > rect.origin.z)this->origin.z = rect.origin.z;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
        if(this->size.length < rect.size.length)this->size.length = rect.size.length;
    }
};

class cubei32{
public:
    //position
    edk::vec3i32 origin;
    //size
    edk::size3i32 size;
    //Construtor
    cubei32(){
        //
        this->origin.x=(edk::int32)0;
        this->origin.y=(edk::int32)0;
        this->origin.z=(edk::int32)0;
        this->size.width=(edk::int32)0;
        this->size.height=(edk::int32)0;
        this->size.length=(edk::int32)0;
    }
    cubei32(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->origin.z=(edk::int32)z;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        this->size.length=(edk::int32)length;
    }
    cubei32(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->origin.z=(edk::int32)z;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        this->size.length=(edk::int32)length;
    }
    cubei32(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->origin.z=(edk::int32)z;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        this->size.length=(edk::int32)length;
    }
    cubei32(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->origin.z=(edk::int32)z;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        this->size.length=(edk::int32)length;
    }
    cubei32(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->origin.z=(edk::int32)z;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        this->size.length=(edk::int32)length;
    }
    cubei32(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->origin.z=(edk::int32)z;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        this->size.length=(edk::int32)length;
    }
    cubei32(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->origin.z=(edk::int32)z;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        this->size.length=(edk::int32)length;
    }
    cubei32(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->origin.z=(edk::int32)z;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        this->size.length=(edk::int32)length;
    }
    cubei32(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->origin.z=(edk::int32)origin.z;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
        this->size.length=(edk::int32)size.length;
    }
    cubei32(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->origin.z=(edk::int32)origin.z;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
        this->size.length=(edk::int32)size.length;
    }
    cubei32(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->origin.z=(edk::int32)origin.z;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
        this->size.length=(edk::int32)size.length;
    }
    cubei32(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->origin.z=(edk::int32)origin.z;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
        this->size.length=(edk::int32)size.length;
    }
    cubei32(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->origin.z=(edk::int32)origin.z;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
        this->size.length=(edk::int32)size.length;
    }
    cubei32(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->origin.z=(edk::int32)origin.z;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
        this->size.length=(edk::int32)size.length;
    }
    cubei32(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->origin.z=(edk::int32)origin.z;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
        this->size.length=(edk::int32)size.length;
    }
    cubei32(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::int32)origin.x;
        this->origin.y=(edk::int32)origin.y;
        this->origin.z=(edk::int32)origin.z;
        this->size.width=(edk::int32)size.width;
        this->size.height=(edk::int32)size.height;
        this->size.length=(edk::int32)size.length;
    }

    //operators
    inline edk::cubei32 operator=(cubei32 cube){
        //
        this->origin.x=(edk::int32)cube.origin.x;
        this->origin.y=(edk::int32)cube.origin.y;
        this->origin.z=(edk::int32)cube.origin.z;
        this->size.width=(edk::int32)cube.size.width;
        this->size.height=(edk::int32)cube.size.height;
        this->size.length=(edk::int32)cube.size.length;
        return *this;
    }
    inline edk::cubei32 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    inline edk::cubei32 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    inline edk::cubei32 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    inline edk::cubei32 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    inline edk::cubei32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    inline edk::cubei32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    inline edk::cubei32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    inline edk::cubei32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }

    inline bool operator==(cubei32 cube){
        //
        return (this->origin.x==(edk::int32)cube.origin.x
                &&this->origin.y==(edk::int32)cube.origin.y
                &&this->origin.z==(edk::int32)cube.origin.z
                &&this->size.width==(edk::int32)cube.size.width
                &&this->size.height==(edk::int32)cube.size.height
                &&this->size.length==(edk::int32)cube.size.length
                );
    }
    inline bool operator!=(cubei32 cube){
        //
        return (this->origin.x!=(edk::int32)cube.origin.x
                ||this->origin.y!=(edk::int32)cube.origin.y
                ||this->origin.z!=(edk::int32)cube.origin.z
                ||this->size.width!=(edk::int32)cube.size.width
                ||this->size.height!=(edk::int32)cube.size.height
                ||this->size.length!=(edk::int32)cube.size.length
                );
    }
    inline edk::cubei32 operator+(cubei32 cube){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::int32)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::int32)cube.origin.z;
        ret.size.width=this->size.width+(edk::int32)cube.size.width;
        ret.size.height=this->size.height+(edk::int32)cube.size.height;
        ret.size.length=this->size.length+(edk::int32)cube.size.length;
        return ret;
    }
    inline edk::cubei32 operator+(edk::int8 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator+(edk::int32 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator+(edk::int16 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator+(edk::int64 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator+(edk::uint8 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator+(edk::uint32 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator+(edk::uint16 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator+(edk::uint64 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    inline void operator+=(cubei32 cube){
        //
        this->origin.x+=(edk::int32)cube.origin.x;
        this->origin.y+=(edk::int32)cube.origin.y;
        this->origin.z+=(edk::int32)cube.origin.z;
        this->size.width+=(edk::int32)cube.size.width;
        this->size.height+=(edk::int32)cube.size.height;
        this->size.length+=(edk::int32)cube.size.length;
    }
    inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    inline edk::cubei32 operator-(cubei32 cube){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::int32)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::int32)cube.origin.z;
        ret.size.width=this->size.width-(edk::int32)cube.size.width;
        ret.size.height=this->size.height-(edk::int32)cube.size.height;
        ret.size.length=this->size.length-(edk::int32)cube.size.length;
        return ret;
    }
    inline edk::cubei32 operator-(edk::int8 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator-(edk::int32 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator-(edk::int16 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator-(edk::int64 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator-(edk::uint8 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator-(edk::uint32 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator-(edk::uint16 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator-(edk::uint64 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    inline void operator-=(cubei32 vec){
        //
        this->origin.x-=(edk::int32)vec.origin.x;
        this->origin.y-=(edk::int32)vec.origin.y;
        this->origin.z-=(edk::int32)vec.origin.z;
        this->size.width-=(edk::int32)vec.size.width;
        this->size.height-=(edk::int32)vec.size.height;
        this->size.length-=(edk::int32)vec.size.length;
    }
    inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    inline edk::cubei32 operator*(cubei32 cube){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::int32)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::int32)cube.origin.z;
        ret.size.width=this->size.width*(edk::int32)cube.size.width;
        ret.size.height=this->size.height*(edk::int32)cube.size.height;
        ret.size.length=this->size.length*(edk::int32)cube.size.length;
        return ret;
    }
    inline edk::cubei32 operator*(edk::int8 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator*(edk::int32 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator*(edk::int16 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator*(edk::int64 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator*(edk::uint8 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator*(edk::uint32 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator*(edk::uint16 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    inline edk::cubei32 operator*(edk::uint64 n){
        //
        edk::cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    inline void operator*=(cubei32 cube){
        //
        this->origin.x*=(edk::int32)cube.origin.x;
        this->origin.y*=(edk::int32)cube.origin.y;
        this->origin.z*=(edk::int32)cube.origin.z;
        this->size.width*=(edk::int32)cube.size.width;
        this->size.height*=(edk::int32)cube.size.height;
        this->size.length*=(edk::int32)cube.size.length;
    }
    inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    //
    inline edk::cubei32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return edk::cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return edk::cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return edk::cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return edk::cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei32 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    inline edk::cubei32 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    inline edk::cubei32 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    inline edk::cubei32 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    inline edk::cubei32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    inline edk::cubei32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    inline edk::cubei32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    inline edk::cubei32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    //function to merge the cube with another cube
    inline void merge(edk::cubei8 rect){
        if(this->origin.x > (edk::int32)rect.origin.x)this->origin.x = (edk::int32)rect.origin.x;
        if(this->origin.y > (edk::int32)rect.origin.y)this->origin.y = (edk::int32)rect.origin.y;
        if(this->origin.z > (edk::int32)rect.origin.z)this->origin.z = (edk::int32)rect.origin.z;
        if(this->size.width < (edk::int32)rect.size.width)this->size.width = (edk::int32)rect.size.width;
        if(this->size.height < (edk::int32)rect.size.height)this->size.height = (edk::int32)rect.size.height;
        if(this->size.length < (edk::int32)rect.size.length)this->size.length = (edk::int32)rect.size.length;
    }
    inline void merge(edk::cubei16 rect){
        if(this->origin.x > (edk::int32)rect.origin.x)this->origin.x = (edk::int32)rect.origin.x;
        if(this->origin.y > (edk::int32)rect.origin.y)this->origin.y = (edk::int32)rect.origin.y;
        if(this->origin.z > (edk::int32)rect.origin.z)this->origin.z = (edk::int32)rect.origin.z;
        if(this->size.width < (edk::int32)rect.size.width)this->size.width = (edk::int32)rect.size.width;
        if(this->size.height < (edk::int32)rect.size.height)this->size.height = (edk::int32)rect.size.height;
        if(this->size.length < (edk::int32)rect.size.length)this->size.length = (edk::int32)rect.size.length;
    }
    inline void merge(edk::cubei32 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->origin.z > rect.origin.z)this->origin.z = rect.origin.z;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
        if(this->size.length < rect.size.length)this->size.length = rect.size.length;
    }
};

class cubei64{
public:
    //position
    edk::vec3i64 origin;
    //size
    edk::size3i64 size;
    //Construtor
    cubei64(){
        //
        this->origin.x=(edk::int64)0;
        this->origin.y=(edk::int64)0;
        this->origin.z=(edk::int64)0;
        this->size.width=(edk::int64)0;
        this->size.height=(edk::int64)0;
        this->size.length=(edk::int64)0;
    }
    cubei64(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->origin.z=(edk::int64)z;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        this->size.length=(edk::int64)length;
    }
    cubei64(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->origin.z=(edk::int64)z;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        this->size.length=(edk::int64)length;
    }
    cubei64(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->origin.z=(edk::int64)z;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        this->size.length=(edk::int64)length;
    }
    cubei64(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->origin.z=(edk::int64)z;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        this->size.length=(edk::int64)length;
    }
    cubei64(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->origin.z=(edk::int64)z;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        this->size.length=(edk::int64)length;
    }
    cubei64(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->origin.z=(edk::int64)z;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        this->size.length=(edk::int64)length;
    }
    cubei64(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->origin.z=(edk::int64)z;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        this->size.length=(edk::int64)length;
    }
    cubei64(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->origin.z=(edk::int64)z;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        this->size.length=(edk::int64)length;
    }
    cubei64(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->origin.z=(edk::int64)origin.z;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
        this->size.length=(edk::int64)size.length;
    }
    cubei64(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->origin.z=(edk::int64)origin.z;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
        this->size.length=(edk::int64)size.length;
    }
    cubei64(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->origin.z=(edk::int64)origin.z;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
        this->size.length=(edk::int64)size.length;
    }
    cubei64(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->origin.z=(edk::int64)origin.z;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
        this->size.length=(edk::int64)size.length;
    }
    cubei64(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->origin.z=(edk::int64)origin.z;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
        this->size.length=(edk::int64)size.length;
    }
    cubei64(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->origin.z=(edk::int64)origin.z;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
        this->size.length=(edk::int64)size.length;
    }
    cubei64(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->origin.z=(edk::int64)origin.z;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
        this->size.length=(edk::int64)size.length;
    }
    cubei64(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::int64)origin.x;
        this->origin.y=(edk::int64)origin.y;
        this->origin.z=(edk::int64)origin.z;
        this->size.width=(edk::int64)size.width;
        this->size.height=(edk::int64)size.height;
        this->size.length=(edk::int64)size.length;
    }

    //operators
    inline edk::cubei64 operator=(cubei64 cube){
        //
        this->origin.x=(edk::int64)cube.origin.x;
        this->origin.y=(edk::int64)cube.origin.y;
        this->origin.z=(edk::int64)cube.origin.z;
        this->size.width=(edk::int64)cube.size.width;
        this->size.height=(edk::int64)cube.size.height;
        this->size.length=(edk::int64)cube.size.length;
        return *this;
    }
    inline edk::cubei64 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    inline edk::cubei64 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    inline edk::cubei64 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    inline edk::cubei64 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    inline edk::cubei64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    inline edk::cubei64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    inline edk::cubei64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    inline edk::cubei64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }

    inline bool operator==(cubei64 cube){
        //
        return (this->origin.x==(edk::int64)cube.origin.x
                &&this->origin.y==(edk::int64)cube.origin.y
                &&this->origin.z==(edk::int64)cube.origin.z
                &&this->size.width==(edk::int64)cube.size.width
                &&this->size.height==(edk::int64)cube.size.height
                &&this->size.length==(edk::int64)cube.size.length
                );
    }
    inline bool operator!=(cubei64 cube){
        //
        return (this->origin.x!=(edk::int64)cube.origin.x
                ||this->origin.y!=(edk::int64)cube.origin.y
                ||this->origin.z!=(edk::int64)cube.origin.z
                ||this->size.width!=(edk::int64)cube.size.width
                ||this->size.height!=(edk::int64)cube.size.height
                ||this->size.length!=(edk::int64)cube.size.length
                );
    }
    inline edk::cubei64 operator+(cubei64 cube){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::int64)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::int64)cube.origin.z;
        ret.size.width=this->size.width+(edk::int64)cube.size.width;
        ret.size.height=this->size.height+(edk::int64)cube.size.height;
        ret.size.length=this->size.length+(edk::int64)cube.size.length;
        return ret;
    }
    inline edk::cubei64 operator+(edk::int8 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator+(edk::int32 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator+(edk::int16 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator+(edk::int64 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator+(edk::uint8 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator+(edk::uint32 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator+(edk::uint16 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator+(edk::uint64 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    inline void operator+=(cubei64 cube){
        //
        this->origin.x+=(edk::int64)cube.origin.x;
        this->origin.y+=(edk::int64)cube.origin.y;
        this->origin.z+=(edk::int64)cube.origin.z;
        this->size.width+=(edk::int64)cube.size.width;
        this->size.height+=(edk::int64)cube.size.height;
        this->size.length+=(edk::int64)cube.size.length;
    }
    inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    inline edk::cubei64 operator-(cubei64 cube){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::int64)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::int64)cube.origin.z;
        ret.size.width=this->size.width-(edk::int64)cube.size.width;
        ret.size.height=this->size.height-(edk::int64)cube.size.height;
        ret.size.length=this->size.length-(edk::int64)cube.size.length;
        return ret;
    }
    inline edk::cubei64 operator-(edk::int8 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator-(edk::int32 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator-(edk::int16 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator-(edk::int64 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator-(edk::uint8 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator-(edk::uint32 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator-(edk::uint16 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator-(edk::uint64 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    inline void operator-=(cubei64 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;
        this->origin.y-=(edk::int64)vec.origin.y;
        this->origin.z-=(edk::int64)vec.origin.z;
        this->size.width-=(edk::int64)vec.size.width;
        this->size.height-=(edk::int64)vec.size.height;
        this->size.length-=(edk::int64)vec.size.length;
    }
    inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    inline edk::cubei64 operator*(cubei64 cube){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::int64)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::int64)cube.origin.z;
        ret.size.width=this->size.width*(edk::int64)cube.size.width;
        ret.size.height=this->size.height*(edk::int64)cube.size.height;
        ret.size.length=this->size.length*(edk::int64)cube.size.length;
        return ret;
    }
    inline edk::cubei64 operator*(edk::int8 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator*(edk::int32 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator*(edk::int16 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator*(edk::int64 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator*(edk::uint8 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator*(edk::uint32 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator*(edk::uint16 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    inline edk::cubei64 operator*(edk::uint64 n){
        //
        edk::cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    inline void operator*=(cubei64 cube){
        //
        this->origin.x*=(edk::int64)cube.origin.x;
        this->origin.y*=(edk::int64)cube.origin.y;
        this->origin.z*=(edk::int64)cube.origin.z;
        this->size.width*=(edk::int64)cube.size.width;
        this->size.height*=(edk::int64)cube.size.height;
        this->size.length*=(edk::int64)cube.size.length;
    }
    inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    //
    inline edk::cubei64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return edk::cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return edk::cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return edk::cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return edk::cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubei64 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    inline edk::cubei64 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    inline edk::cubei64 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    inline edk::cubei64 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    inline edk::cubei64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    inline edk::cubei64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    inline edk::cubei64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    inline edk::cubei64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    //function to merge the cube with another cube
    inline void merge(edk::cubei8 rect){
        if(this->origin.x > (edk::int64)rect.origin.x)this->origin.x = (edk::int64)rect.origin.x;
        if(this->origin.y > (edk::int64)rect.origin.y)this->origin.y = (edk::int64)rect.origin.y;
        if(this->origin.z > (edk::int64)rect.origin.z)this->origin.z = (edk::int64)rect.origin.z;
        if(this->size.width < (edk::int64)rect.size.width)this->size.width = (edk::int64)rect.size.width;
        if(this->size.height < (edk::int64)rect.size.height)this->size.height = (edk::int64)rect.size.height;
        if(this->size.length < (edk::int64)rect.size.length)this->size.length = (edk::int64)rect.size.length;
    }
    inline void merge(edk::cubei16 rect){
        if(this->origin.x > (edk::int64)rect.origin.x)this->origin.x = (edk::int64)rect.origin.x;
        if(this->origin.y > (edk::int64)rect.origin.y)this->origin.y = (edk::int64)rect.origin.y;
        if(this->origin.z > (edk::int64)rect.origin.z)this->origin.z = (edk::int64)rect.origin.z;
        if(this->size.width < (edk::int64)rect.size.width)this->size.width = (edk::int64)rect.size.width;
        if(this->size.height < (edk::int64)rect.size.height)this->size.height = (edk::int64)rect.size.height;
        if(this->size.length < (edk::int64)rect.size.length)this->size.length = (edk::int64)rect.size.length;
    }
    inline void merge(edk::cubei32 rect){
        if(this->origin.x > (edk::int64)rect.origin.x)this->origin.x = (edk::int64)rect.origin.x;
        if(this->origin.y > (edk::int64)rect.origin.y)this->origin.y = (edk::int64)rect.origin.y;
        if(this->origin.z > (edk::int64)rect.origin.z)this->origin.z = (edk::int64)rect.origin.z;
        if(this->size.width < (edk::int64)rect.size.width)this->size.width = (edk::int64)rect.size.width;
        if(this->size.height < (edk::int64)rect.size.height)this->size.height = (edk::int64)rect.size.height;
        if(this->size.length < (edk::int64)rect.size.length)this->size.length = (edk::int64)rect.size.length;
    }
    inline void merge(edk::cubei64 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->origin.z > rect.origin.z)this->origin.z = rect.origin.z;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
        if(this->size.length < rect.size.length)this->size.length = rect.size.length;
    }
};

class cubeui8{
public:
    //position
    edk::vec3ui8 origin;
    //size
    edk::size3ui8 size;
    //Construtor
    cubeui8(){
        //
        this->origin.x=(edk::uint8)0;
        this->origin.y=(edk::uint8)0;
        this->origin.z=(edk::uint8)0;
        this->size.width=(edk::uint8)0;
        this->size.height=(edk::uint8)0;
        this->size.length=(edk::uint8)0;
    }
    cubeui8(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->origin.z=(edk::uint8)z;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        this->size.length=(edk::uint8)length;
    }
    cubeui8(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->origin.z=(edk::uint8)z;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        this->size.length=(edk::uint8)length;
    }
    cubeui8(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->origin.z=(edk::uint8)z;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        this->size.length=(edk::uint8)length;
    }
    cubeui8(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->origin.z=(edk::uint8)z;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        this->size.length=(edk::uint8)length;
    }
    cubeui8(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::uint8)origin.x;
        this->origin.y=(edk::uint8)origin.y;
        this->origin.z=(edk::uint8)origin.z;
        this->size.width=(edk::uint8)size.width;
        this->size.height=(edk::uint8)size.height;
        this->size.length=(edk::uint8)size.length;
    }
    cubeui8(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::uint8)origin.x;
        this->origin.y=(edk::uint8)origin.y;
        this->origin.z=(edk::uint8)origin.z;
        this->size.width=(edk::uint8)size.width;
        this->size.height=(edk::uint8)size.height;
        this->size.length=(edk::uint8)size.length;
    }
    cubeui8(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::uint8)origin.x;
        this->origin.y=(edk::uint8)origin.y;
        this->origin.z=(edk::uint8)origin.z;
        this->size.width=(edk::uint8)size.width;
        this->size.height=(edk::uint8)size.height;
        this->size.length=(edk::uint8)size.length;
    }
    cubeui8(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::uint8)origin.x;
        this->origin.y=(edk::uint8)origin.y;
        this->origin.z=(edk::uint8)origin.z;
        this->size.width=(edk::uint8)size.width;
        this->size.height=(edk::uint8)size.height;
        this->size.length=(edk::uint8)size.length;
    }

    //operators
    inline edk::cubeui8 operator=(cubeui8 cube){
        //
        this->origin.x=(edk::uint8)cube.origin.x;
        this->origin.y=(edk::uint8)cube.origin.y;
        this->origin.z=(edk::uint8)cube.origin.z;
        this->size.width=(edk::uint8)cube.size.width;
        this->size.height=(edk::uint8)cube.size.height;
        this->size.length=(edk::uint8)cube.size.length;
        return *this;
    }
    inline edk::cubeui8 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->origin.z=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        this->size.length=(edk::uint8)n;
        return *this;
    }
    inline edk::cubeui8 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->origin.z=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        this->size.length=(edk::uint8)n;
        return *this;
    }
    inline edk::cubeui8 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->origin.z=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        this->size.length=(edk::uint8)n;
        return *this;
    }
    inline edk::cubeui8 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->origin.z=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        this->size.length=(edk::uint8)n;
        return *this;
    }

    inline bool operator==(cubeui8 cube){
        //
        return (this->origin.x==(edk::uint8)cube.origin.x
                &&this->origin.y==(edk::uint8)cube.origin.y
                &&this->origin.z==(edk::uint8)cube.origin.z
                &&this->size.width==(edk::uint8)cube.size.width
                &&this->size.height==(edk::uint8)cube.size.height
                &&this->size.length==(edk::uint8)cube.size.length
                );
    }
    inline bool operator!=(cubeui8 cube){
        //
        return (this->origin.x!=(edk::uint8)cube.origin.x
                ||this->origin.y!=(edk::uint8)cube.origin.y
                ||this->origin.z!=(edk::uint8)cube.origin.z
                ||this->size.width!=(edk::uint8)cube.size.width
                ||this->size.height!=(edk::uint8)cube.size.height
                ||this->size.length!=(edk::uint8)cube.size.length
                );
    }
    inline edk::cubeui8 operator+(cubeui8 cube){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::uint8)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::uint8)cube.origin.z;
        ret.size.width=this->size.width+(edk::uint8)cube.size.width;
        ret.size.height=this->size.height+(edk::uint8)cube.size.height;
        ret.size.length=this->size.length+(edk::uint8)cube.size.length;
        return ret;
    }
    inline edk::cubeui8 operator+(edk::uint8 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.origin.z=this->origin.z+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        ret.size.length=this->size.length+(edk::uint8)n;
        return ret;
    }
    inline edk::cubeui8 operator+(edk::uint32 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.origin.z=this->origin.z+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        ret.size.length=this->size.length+(edk::uint8)n;
        return ret;
    }
    inline edk::cubeui8 operator+(edk::uint16 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.origin.z=this->origin.z+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        ret.size.length=this->size.length+(edk::uint8)n;
        return ret;
    }
    inline edk::cubeui8 operator+(edk::uint64 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.origin.z=this->origin.z+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        ret.size.length=this->size.length+(edk::uint8)n;
        return ret;
    }
    inline void operator+=(cubeui8 cube){
        //
        this->origin.x+=(edk::uint8)cube.origin.x;
        this->origin.y+=(edk::uint8)cube.origin.y;
        this->origin.z+=(edk::uint8)cube.origin.z;
        this->size.width+=(edk::uint8)cube.size.width;
        this->size.height+=(edk::uint8)cube.size.height;
        this->size.length+=(edk::uint8)cube.size.length;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->origin.z+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
        this->size.length+=(edk::uint8)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->origin.z+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
        this->size.length+=(edk::uint8)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->origin.z+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
        this->size.length+=(edk::uint8)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->origin.z+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
        this->size.length+=(edk::uint8)n;
    }
    inline edk::cubeui8 operator-(cubeui8 cube){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::uint8)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::uint8)cube.origin.z;
        ret.size.width=this->size.width-(edk::uint8)cube.size.width;
        ret.size.height=this->size.height-(edk::uint8)cube.size.height;
        ret.size.length=this->size.length-(edk::uint8)cube.size.length;
        return ret;
    }
    inline edk::cubeui8 operator-(edk::uint8 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.origin.z=this->origin.z-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        ret.size.length=this->size.length-(edk::uint8)n;
        return ret;
    }
    inline edk::cubeui8 operator-(edk::uint32 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.origin.z=this->origin.z-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        ret.size.length=this->size.length-(edk::uint8)n;
        return ret;
    }
    inline edk::cubeui8 operator-(edk::uint16 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.origin.z=this->origin.z-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        ret.size.length=this->size.length-(edk::uint8)n;
        return ret;
    }
    inline edk::cubeui8 operator-(edk::uint64 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.origin.z=this->origin.z-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        ret.size.length=this->size.length-(edk::uint8)n;
        return ret;
    }
    inline void operator-=(cubeui8 vec){
        //
        this->origin.x-=(edk::uint8)vec.origin.x;
        this->origin.y-=(edk::uint8)vec.origin.y;
        this->origin.z-=(edk::uint8)vec.origin.z;
        this->size.width-=(edk::uint8)vec.size.width;
        this->size.height-=(edk::uint8)vec.size.height;
        this->size.length-=(edk::uint8)vec.size.length;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->origin.z-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
        this->size.length-=(edk::uint8)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->origin.z-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
        this->size.length-=(edk::uint8)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->origin.z-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
        this->size.length-=(edk::uint8)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->origin.z-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
        this->size.length-=(edk::uint8)n;
    }
    inline edk::cubeui8 operator*(cubeui8 cube){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::uint8)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::uint8)cube.origin.z;
        ret.size.width=this->size.width*(edk::uint8)cube.size.width;
        ret.size.height=this->size.height*(edk::uint8)cube.size.height;
        ret.size.length=this->size.length*(edk::uint8)cube.size.length;
        return ret;
    }
    inline edk::cubeui8 operator*(edk::uint8 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.origin.z=this->origin.z*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        ret.size.length=this->size.length*(edk::uint8)n;
        return ret;
    }
    inline edk::cubeui8 operator*(edk::uint32 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.origin.z=this->origin.z*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        ret.size.length=this->size.length*(edk::uint8)n;
        return ret;
    }
    inline edk::cubeui8 operator*(edk::uint16 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.origin.z=this->origin.z*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        ret.size.length=this->size.length*(edk::uint8)n;
        return ret;
    }
    inline edk::cubeui8 operator*(edk::uint64 n){
        //
        edk::cubeui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.origin.z=this->origin.z*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        ret.size.length=this->size.length*(edk::uint8)n;
        return ret;
    }
    inline void operator*=(cubeui8 cube){
        //
        this->origin.x*=(edk::uint8)cube.origin.x;
        this->origin.y*=(edk::uint8)cube.origin.y;
        this->origin.z*=(edk::uint8)cube.origin.z;
        this->size.width*=(edk::uint8)cube.size.width;
        this->size.height*=(edk::uint8)cube.size.height;
        this->size.length*=(edk::uint8)cube.size.length;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->origin.z*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
        this->size.length*=(edk::uint8)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->origin.z*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
        this->size.length*=(edk::uint8)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->origin.z*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
        this->size.length*=(edk::uint8)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->origin.z*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
        this->size.length*=(edk::uint8)n;
    }
    //
    inline edk::cubeui8 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return edk::cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui8 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return edk::cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui8 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return edk::cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui8 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return edk::cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);
    }
    inline edk::cubeui8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->origin.z=(edk::uint8)z;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        this->size.length=(edk::uint8)length;
        return edk::cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);
    }
    inline edk::cubeui8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->origin.z=(edk::uint8)z;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        this->size.length=(edk::uint8)length;
        return edk::cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);
    }
    inline edk::cubeui8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->origin.z=(edk::uint8)z;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        this->size.length=(edk::uint8)length;
        return edk::cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);
    }
    //function to merge the cube with another cube
    inline void merge(edk::cubeui8 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->origin.z > rect.origin.z)this->origin.z = rect.origin.z;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
        if(this->size.length < rect.size.length)this->size.length = rect.size.length;
    }
};

class cubeui16{
public:
    //position
    edk::vec3ui16 origin;
    //size
    edk::size3ui16 size;
    //Construtor
    cubeui16(){
        //
        this->origin.x=(edk::uint16)0;
        this->origin.y=(edk::uint16)0;
        this->origin.z=(edk::uint16)0;
        this->size.width=(edk::uint16)0;
        this->size.height=(edk::uint16)0;
        this->size.length=(edk::uint16)0;
    }
    cubeui16(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->origin.z=(edk::uint16)z;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        this->size.length=(edk::uint16)length;
    }
    cubeui16(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->origin.z=(edk::uint16)z;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        this->size.length=(edk::uint16)length;
    }
    cubeui16(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->origin.z=(edk::uint16)z;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        this->size.length=(edk::uint16)length;
    }
    cubeui16(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->origin.z=(edk::uint16)z;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        this->size.length=(edk::uint16)length;
    }
    cubeui16(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::uint16)origin.x;
        this->origin.y=(edk::uint16)origin.y;
        this->origin.z=(edk::uint16)origin.z;
        this->size.width=(edk::uint16)size.width;
        this->size.height=(edk::uint16)size.height;
        this->size.length=(edk::uint16)size.length;
    }
    cubeui16(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::uint16)origin.x;
        this->origin.y=(edk::uint16)origin.y;
        this->origin.z=(edk::uint16)origin.z;
        this->size.width=(edk::uint16)size.width;
        this->size.height=(edk::uint16)size.height;
        this->size.length=(edk::uint16)size.length;
    }
    cubeui16(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::uint16)origin.x;
        this->origin.y=(edk::uint16)origin.y;
        this->origin.z=(edk::uint16)origin.z;
        this->size.width=(edk::uint16)size.width;
        this->size.height=(edk::uint16)size.height;
        this->size.length=(edk::uint16)size.length;
    }
    cubeui16(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::uint16)origin.x;
        this->origin.y=(edk::uint16)origin.y;
        this->origin.z=(edk::uint16)origin.z;
        this->size.width=(edk::uint16)size.width;
        this->size.height=(edk::uint16)size.height;
        this->size.length=(edk::uint16)size.length;
    }

    //operators
    inline edk::cubeui16 operator=(cubeui16 cube){
        //
        this->origin.x=(edk::uint16)cube.origin.x;
        this->origin.y=(edk::uint16)cube.origin.y;
        this->origin.z=(edk::uint16)cube.origin.z;
        this->size.width=(edk::uint16)cube.size.width;
        this->size.height=(edk::uint16)cube.size.height;
        this->size.length=(edk::uint16)cube.size.length;
        return *this;
    }
    inline edk::cubeui16 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->origin.z=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        this->size.length=(edk::uint16)n;
        return *this;
    }
    inline edk::cubeui16 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->origin.z=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        this->size.length=(edk::uint16)n;
        return *this;
    }
    inline edk::cubeui16 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->origin.z=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        this->size.length=(edk::uint16)n;
        return *this;
    }
    inline edk::cubeui16 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->origin.z=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        this->size.length=(edk::uint16)n;
        return *this;
    }

    inline bool operator==(cubeui16 cube){
        //
        return (this->origin.x==(edk::uint16)cube.origin.x
                &&this->origin.y==(edk::uint16)cube.origin.y
                &&this->origin.z==(edk::uint16)cube.origin.z
                &&this->size.width==(edk::uint16)cube.size.width
                &&this->size.height==(edk::uint16)cube.size.height
                &&this->size.length==(edk::uint16)cube.size.length
                );
    }
    inline bool operator!=(cubeui16 cube){
        //
        return (this->origin.x!=(edk::uint16)cube.origin.x
                ||this->origin.y!=(edk::uint16)cube.origin.y
                ||this->origin.z!=(edk::uint16)cube.origin.z
                ||this->size.width!=(edk::uint16)cube.size.width
                ||this->size.height!=(edk::uint16)cube.size.height
                ||this->size.length!=(edk::uint16)cube.size.length
                );
    }
    inline edk::cubeui16 operator+(cubeui16 cube){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::uint16)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::uint16)cube.origin.z;
        ret.size.width=this->size.width+(edk::uint16)cube.size.width;
        ret.size.height=this->size.height+(edk::uint16)cube.size.height;
        ret.size.length=this->size.length+(edk::uint16)cube.size.length;
        return ret;
    }
    inline edk::cubeui16 operator+(edk::uint8 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.origin.z=this->origin.z+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        ret.size.length=this->size.length+(edk::uint16)n;
        return ret;
    }
    inline edk::cubeui16 operator+(edk::uint32 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.origin.z=this->origin.z+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        ret.size.length=this->size.length+(edk::uint16)n;
        return ret;
    }
    inline edk::cubeui16 operator+(edk::uint16 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.origin.z=this->origin.z+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        ret.size.length=this->size.length+(edk::uint16)n;
        return ret;
    }
    inline edk::cubeui16 operator+(edk::uint64 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.origin.z=this->origin.z+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        ret.size.length=this->size.length+(edk::uint16)n;
        return ret;
    }
    inline void operator+=(cubeui16 cube){
        //
        this->origin.x+=(edk::uint16)cube.origin.x;
        this->origin.y+=(edk::uint16)cube.origin.y;
        this->origin.z+=(edk::uint16)cube.origin.z;
        this->size.width+=(edk::uint16)cube.size.width;
        this->size.height+=(edk::uint16)cube.size.height;
        this->size.length+=(edk::uint16)cube.size.length;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->origin.z+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
        this->size.length+=(edk::uint16)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->origin.z+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
        this->size.length+=(edk::uint16)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->origin.z+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
        this->size.length+=(edk::uint16)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->origin.z+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
        this->size.length+=(edk::uint16)n;
    }
    inline edk::cubeui16 operator-(cubeui16 cube){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::uint16)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::uint16)cube.origin.z;
        ret.size.width=this->size.width-(edk::uint16)cube.size.width;
        ret.size.height=this->size.height-(edk::uint16)cube.size.height;
        ret.size.length=this->size.length-(edk::uint16)cube.size.length;
        return ret;
    }
    inline edk::cubeui16 operator-(edk::uint8 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.origin.z=this->origin.z-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        ret.size.length=this->size.length-(edk::uint16)n;
        return ret;
    }
    inline edk::cubeui16 operator-(edk::uint32 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.origin.z=this->origin.z-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        ret.size.length=this->size.length-(edk::uint16)n;
        return ret;
    }
    inline edk::cubeui16 operator-(edk::uint16 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.origin.z=this->origin.z-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        ret.size.length=this->size.length-(edk::uint16)n;
        return ret;
    }
    inline edk::cubeui16 operator-(edk::uint64 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.origin.z=this->origin.z-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        ret.size.length=this->size.length-(edk::uint16)n;
        return ret;
    }
    inline void operator-=(cubeui16 vec){
        //
        this->origin.x-=(edk::uint16)vec.origin.x;
        this->origin.y-=(edk::uint16)vec.origin.y;
        this->origin.z-=(edk::uint16)vec.origin.z;
        this->size.width-=(edk::uint16)vec.size.width;
        this->size.height-=(edk::uint16)vec.size.height;
        this->size.length-=(edk::uint16)vec.size.length;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->origin.z-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
        this->size.length-=(edk::uint16)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->origin.z-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
        this->size.length-=(edk::uint16)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->origin.z-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
        this->size.length-=(edk::uint16)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->origin.z-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
        this->size.length-=(edk::uint16)n;
    }
    inline edk::cubeui16 operator*(cubeui16 cube){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::uint16)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::uint16)cube.origin.z;
        ret.size.width=this->size.width*(edk::uint16)cube.size.width;
        ret.size.height=this->size.height*(edk::uint16)cube.size.height;
        ret.size.length=this->size.length*(edk::uint16)cube.size.length;
        return ret;
    }
    inline edk::cubeui16 operator*(edk::uint8 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.origin.z=this->origin.z*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        ret.size.length=this->size.length*(edk::uint16)n;
        return ret;
    }
    inline edk::cubeui16 operator*(edk::uint32 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.origin.z=this->origin.z*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        ret.size.length=this->size.length*(edk::uint16)n;
        return ret;
    }
    inline edk::cubeui16 operator*(edk::uint16 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.origin.z=this->origin.z*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        ret.size.length=this->size.length*(edk::uint16)n;
        return ret;
    }
    inline edk::cubeui16 operator*(edk::uint64 n){
        //
        edk::cubeui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.origin.z=this->origin.z*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        ret.size.length=this->size.length*(edk::uint16)n;
        return ret;
    }
    inline void operator*=(cubeui16 cube){
        //
        this->origin.x*=(edk::uint16)cube.origin.x;
        this->origin.y*=(edk::uint16)cube.origin.y;
        this->origin.z*=(edk::uint16)cube.origin.z;
        this->size.width*=(edk::uint16)cube.size.width;
        this->size.height*=(edk::uint16)cube.size.height;
        this->size.length*=(edk::uint16)cube.size.length;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->origin.z*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
        this->size.length*=(edk::uint16)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->origin.z*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
        this->size.length*=(edk::uint16)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->origin.z*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
        this->size.length*=(edk::uint16)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->origin.z*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
        this->size.length*=(edk::uint16)n;
    }
    //
    inline edk::cubeui16 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return edk::cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui16 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return edk::cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui16 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return edk::cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui16 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return edk::cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);
    }
    inline edk::cubeui16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->origin.z=(edk::uint16)z;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        this->size.length=(edk::uint16)length;
        return edk::cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);
    }
    inline edk::cubeui16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->origin.z=(edk::uint16)z;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        this->size.length=(edk::uint16)length;
        return edk::cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);
    }
    inline edk::cubeui16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->origin.z=(edk::uint16)z;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        this->size.length=(edk::uint16)length;
        return edk::cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);
    }
    //function to merge the cube with another cube
    inline void merge(edk::cubeui8 rect){
        if(this->origin.x > (edk::uint16)rect.origin.x)this->origin.x = (edk::uint16)rect.origin.x;
        if(this->origin.y > (edk::uint16)rect.origin.y)this->origin.y = (edk::uint16)rect.origin.y;
        if(this->origin.z > (edk::uint16)rect.origin.z)this->origin.z = (edk::uint16)rect.origin.z;
        if(this->size.width < (edk::uint16)rect.size.width)this->size.width = (edk::uint16)rect.size.width;
        if(this->size.height < (edk::uint16)rect.size.height)this->size.height = (edk::uint16)rect.size.height;
        if(this->size.length < (edk::uint16)rect.size.length)this->size.length = (edk::uint16)rect.size.length;
    }
    inline void merge(edk::cubeui16 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->origin.z > rect.origin.z)this->origin.z = rect.origin.z;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
        if(this->size.length < rect.size.length)this->size.length = rect.size.length;
    }
};

class cubeui32{
public:
    //position
    edk::vec3ui32 origin;
    //size
    edk::size3ui32 size;
    //Construtor
    cubeui32(){
        //
        this->origin.x=(edk::uint32)0;
        this->origin.y=(edk::uint32)0;
        this->origin.z=(edk::uint32)0;
        this->size.width=(edk::uint32)0;
        this->size.height=(edk::uint32)0;
        this->size.length=(edk::uint32)0;
    }
    cubeui32(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->origin.z=(edk::uint32)z;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        this->size.length=(edk::uint32)length;
    }
    cubeui32(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->origin.z=(edk::uint32)z;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        this->size.length=(edk::uint32)length;
    }
    cubeui32(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->origin.z=(edk::uint32)z;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        this->size.length=(edk::uint32)length;
    }
    cubeui32(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->origin.z=(edk::uint32)z;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        this->size.length=(edk::uint32)length;
    }
    cubeui32(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::uint32)origin.x;
        this->origin.y=(edk::uint32)origin.y;
        this->origin.z=(edk::uint32)origin.z;
        this->size.width=(edk::uint32)size.width;
        this->size.height=(edk::uint32)size.height;
        this->size.length=(edk::uint32)size.length;
    }
    cubeui32(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::uint32)origin.x;
        this->origin.y=(edk::uint32)origin.y;
        this->origin.z=(edk::uint32)origin.z;
        this->size.width=(edk::uint32)size.width;
        this->size.height=(edk::uint32)size.height;
        this->size.length=(edk::uint32)size.length;
    }
    cubeui32(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::uint32)origin.x;
        this->origin.y=(edk::uint32)origin.y;
        this->origin.z=(edk::uint32)origin.z;
        this->size.width=(edk::uint32)size.width;
        this->size.height=(edk::uint32)size.height;
        this->size.length=(edk::uint32)size.length;
    }
    cubeui32(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::uint32)origin.x;
        this->origin.y=(edk::uint32)origin.y;
        this->origin.z=(edk::uint32)origin.z;
        this->size.width=(edk::uint32)size.width;
        this->size.height=(edk::uint32)size.height;
        this->size.length=(edk::uint32)size.length;
    }

    //operators
    inline edk::cubeui32 operator=(cubeui32 cube){
        //
        this->origin.x=(edk::uint32)cube.origin.x;
        this->origin.y=(edk::uint32)cube.origin.y;
        this->origin.z=(edk::uint32)cube.origin.z;
        this->size.width=(edk::uint32)cube.size.width;
        this->size.height=(edk::uint32)cube.size.height;
        this->size.length=(edk::uint32)cube.size.length;
        return *this;
    }
    inline edk::cubeui32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->origin.z=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        this->size.length=(edk::uint32)n;
        return *this;
    }
    inline edk::cubeui32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->origin.z=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        this->size.length=(edk::uint32)n;
        return *this;
    }
    inline edk::cubeui32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->origin.z=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        this->size.length=(edk::uint32)n;
        return *this;
    }
    inline edk::cubeui32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->origin.z=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        this->size.length=(edk::uint32)n;
        return *this;
    }

    inline bool operator==(cubeui32 cube){
        //
        return (this->origin.x==(edk::uint32)cube.origin.x
                &&this->origin.y==(edk::uint32)cube.origin.y
                &&this->origin.z==(edk::uint32)cube.origin.z
                &&this->size.width==(edk::uint32)cube.size.width
                &&this->size.height==(edk::uint32)cube.size.height
                &&this->size.length==(edk::uint32)cube.size.length
                );
    }
    inline bool operator!=(cubeui32 cube){
        //
        return (this->origin.x!=(edk::uint32)cube.origin.x
                ||this->origin.y!=(edk::uint32)cube.origin.y
                ||this->origin.z!=(edk::uint32)cube.origin.z
                ||this->size.width!=(edk::uint32)cube.size.width
                ||this->size.height!=(edk::uint32)cube.size.height
                ||this->size.length!=(edk::uint32)cube.size.length
                );
    }
    inline edk::cubeui32 operator+(cubeui32 cube){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::uint32)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::uint32)cube.origin.z;
        ret.size.width=this->size.width+(edk::uint32)cube.size.width;
        ret.size.height=this->size.height+(edk::uint32)cube.size.height;
        ret.size.length=this->size.length+(edk::uint32)cube.size.length;
        return ret;
    }
    inline edk::cubeui32 operator+(edk::uint8 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.origin.z=this->origin.z+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        ret.size.length=this->size.length+(edk::uint32)n;
        return ret;
    }
    inline edk::cubeui32 operator+(edk::uint32 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.origin.z=this->origin.z+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        ret.size.length=this->size.length+(edk::uint32)n;
        return ret;
    }
    inline edk::cubeui32 operator+(edk::uint16 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.origin.z=this->origin.z+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        ret.size.length=this->size.length+(edk::uint32)n;
        return ret;
    }
    inline edk::cubeui32 operator+(edk::uint64 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.origin.z=this->origin.z+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        ret.size.length=this->size.length+(edk::uint32)n;
        return ret;
    }
    inline void operator+=(cubeui32 cube){
        //
        this->origin.x+=(edk::uint32)cube.origin.x;
        this->origin.y+=(edk::uint32)cube.origin.y;
        this->origin.z+=(edk::uint32)cube.origin.z;
        this->size.width+=(edk::uint32)cube.size.width;
        this->size.height+=(edk::uint32)cube.size.height;
        this->size.length+=(edk::uint32)cube.size.length;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->origin.z+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
        this->size.length+=(edk::uint32)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->origin.z+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
        this->size.length+=(edk::uint32)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->origin.z+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
        this->size.length+=(edk::uint32)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->origin.z+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
        this->size.length+=(edk::uint32)n;
    }
    inline edk::cubeui32 operator-(cubeui32 cube){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::uint32)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::uint32)cube.origin.z;
        ret.size.width=this->size.width-(edk::uint32)cube.size.width;
        ret.size.height=this->size.height-(edk::uint32)cube.size.height;
        ret.size.length=this->size.length-(edk::uint32)cube.size.length;
        return ret;
    }
    inline edk::cubeui32 operator-(edk::uint8 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.origin.z=this->origin.z-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        ret.size.length=this->size.length-(edk::uint32)n;
        return ret;
    }
    inline edk::cubeui32 operator-(edk::uint32 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.origin.z=this->origin.z-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        ret.size.length=this->size.length-(edk::uint32)n;
        return ret;
    }
    inline edk::cubeui32 operator-(edk::uint16 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.origin.z=this->origin.z-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        ret.size.length=this->size.length-(edk::uint32)n;
        return ret;
    }
    inline edk::cubeui32 operator-(edk::uint64 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.origin.z=this->origin.z-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        ret.size.length=this->size.length-(edk::uint32)n;
        return ret;
    }
    inline void operator-=(cubeui32 vec){
        //
        this->origin.x-=(edk::uint32)vec.origin.x;
        this->origin.y-=(edk::uint32)vec.origin.y;
        this->origin.z-=(edk::uint32)vec.origin.z;
        this->size.width-=(edk::uint32)vec.size.width;
        this->size.height-=(edk::uint32)vec.size.height;
        this->size.length-=(edk::uint32)vec.size.length;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->origin.z-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
        this->size.length-=(edk::uint32)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->origin.z-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
        this->size.length-=(edk::uint32)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->origin.z-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
        this->size.length-=(edk::uint32)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->origin.z-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
        this->size.length-=(edk::uint32)n;
    }
    inline edk::cubeui32 operator*(cubeui32 cube){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::uint32)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::uint32)cube.origin.z;
        ret.size.width=this->size.width*(edk::uint32)cube.size.width;
        ret.size.height=this->size.height*(edk::uint32)cube.size.height;
        ret.size.length=this->size.length*(edk::uint32)cube.size.length;
        return ret;
    }
    inline edk::cubeui32 operator*(edk::uint8 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.origin.z=this->origin.z*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        ret.size.length=this->size.length*(edk::uint32)n;
        return ret;
    }
    inline edk::cubeui32 operator*(edk::uint32 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.origin.z=this->origin.z*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        ret.size.length=this->size.length*(edk::uint32)n;
        return ret;
    }
    inline edk::cubeui32 operator*(edk::uint16 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.origin.z=this->origin.z*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        ret.size.length=this->size.length*(edk::uint32)n;
        return ret;
    }
    inline edk::cubeui32 operator*(edk::uint64 n){
        //
        edk::cubeui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.origin.z=this->origin.z*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        ret.size.length=this->size.length*(edk::uint32)n;
        return ret;
    }
    inline void operator*=(cubeui32 cube){
        //
        this->origin.x*=(edk::uint32)cube.origin.x;
        this->origin.y*=(edk::uint32)cube.origin.y;
        this->origin.z*=(edk::uint32)cube.origin.z;
        this->size.width*=(edk::uint32)cube.size.width;
        this->size.height*=(edk::uint32)cube.size.height;
        this->size.length*=(edk::uint32)cube.size.length;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->origin.z*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
        this->size.length*=(edk::uint32)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->origin.z*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
        this->size.length*=(edk::uint32)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->origin.z*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
        this->size.length*=(edk::uint32)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->origin.z*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
        this->size.length*=(edk::uint32)n;
    }
    //
    inline edk::cubeui32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return edk::cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return edk::cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return edk::cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return edk::cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);
    }
    inline edk::cubeui32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->origin.z=(edk::uint32)z;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        this->size.length=(edk::uint32)length;
        return edk::cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);
    }
    inline edk::cubeui32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->origin.z=(edk::uint32)z;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        this->size.length=(edk::uint32)length;
        return edk::cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);
    }
    inline edk::cubeui32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->origin.z=(edk::uint32)z;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        this->size.length=(edk::uint32)length;
        return edk::cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);
    }
    //function to merge the cube with another cube
    inline void merge(edk::cubeui8 rect){
        if(this->origin.x > (edk::uint32)rect.origin.x)this->origin.x = (edk::uint32)rect.origin.x;
        if(this->origin.y > (edk::uint32)rect.origin.y)this->origin.y = (edk::uint32)rect.origin.y;
        if(this->origin.z > (edk::uint32)rect.origin.z)this->origin.z = (edk::uint32)rect.origin.z;
        if(this->size.width < (edk::uint32)rect.size.width)this->size.width = (edk::uint32)rect.size.width;
        if(this->size.height < (edk::uint32)rect.size.height)this->size.height = (edk::uint32)rect.size.height;
        if(this->size.length < (edk::uint32)rect.size.length)this->size.length = (edk::uint32)rect.size.length;
    }
    inline void merge(edk::cubeui16 rect){
        if(this->origin.x > (edk::uint32)rect.origin.x)this->origin.x = (edk::uint32)rect.origin.x;
        if(this->origin.y > (edk::uint32)rect.origin.y)this->origin.y = (edk::uint32)rect.origin.y;
        if(this->origin.z > (edk::uint32)rect.origin.z)this->origin.z = (edk::uint32)rect.origin.z;
        if(this->size.width < (edk::uint32)rect.size.width)this->size.width = (edk::uint32)rect.size.width;
        if(this->size.height < (edk::uint32)rect.size.height)this->size.height = (edk::uint32)rect.size.height;
        if(this->size.length < (edk::uint32)rect.size.length)this->size.length = (edk::uint32)rect.size.length;
    }
    inline void merge(edk::cubeui32 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->origin.z > rect.origin.z)this->origin.z = rect.origin.z;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
        if(this->size.length < rect.size.length)this->size.length = rect.size.length;
    }
};

class cubeui64{
public:
    //position
    edk::vec3ui64 origin;
    //size
    edk::size3ui64 size;
    //Construtor
    cubeui64(){
        //
        this->origin.x=(edk::uint64)0;
        this->origin.y=(edk::uint64)0;
        this->origin.z=(edk::uint64)0;
        this->size.width=(edk::uint64)0;
        this->size.height=(edk::uint64)0;
        this->size.length=(edk::uint64)0;
    }
    cubeui64(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->origin.z=(edk::uint64)z;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        this->size.length=(edk::uint64)length;
    }
    cubeui64(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->origin.z=(edk::uint64)z;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        this->size.length=(edk::uint64)length;
    }
    cubeui64(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->origin.z=(edk::uint64)z;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        this->size.length=(edk::uint64)length;
    }
    cubeui64(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->origin.z=(edk::uint64)z;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        this->size.length=(edk::uint64)length;
    }
    cubeui64(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::uint64)origin.x;
        this->origin.y=(edk::uint64)origin.y;
        this->origin.z=(edk::uint64)origin.z;
        this->size.width=(edk::uint64)size.width;
        this->size.height=(edk::uint64)size.height;
        this->size.length=(edk::uint64)size.length;
    }
    cubeui64(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::uint64)origin.x;
        this->origin.y=(edk::uint64)origin.y;
        this->origin.z=(edk::uint64)origin.z;
        this->size.width=(edk::uint64)size.width;
        this->size.height=(edk::uint64)size.height;
        this->size.length=(edk::uint64)size.length;
    }
    cubeui64(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::uint64)origin.x;
        this->origin.y=(edk::uint64)origin.y;
        this->origin.z=(edk::uint64)origin.z;
        this->size.width=(edk::uint64)size.width;
        this->size.height=(edk::uint64)size.height;
        this->size.length=(edk::uint64)size.length;
    }
    cubeui64(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::uint64)origin.x;
        this->origin.y=(edk::uint64)origin.y;
        this->origin.z=(edk::uint64)origin.z;
        this->size.width=(edk::uint64)size.width;
        this->size.height=(edk::uint64)size.height;
        this->size.length=(edk::uint64)size.length;
    }

    //operators
    inline edk::cubeui64 operator=(cubeui64 cube){
        //
        this->origin.x=(edk::uint64)cube.origin.x;
        this->origin.y=(edk::uint64)cube.origin.y;
        this->origin.z=(edk::uint64)cube.origin.z;
        this->size.width=(edk::uint64)cube.size.width;
        this->size.height=(edk::uint64)cube.size.height;
        this->size.length=(edk::uint64)cube.size.length;
        return *this;
    }
    inline edk::cubeui64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->origin.z=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        this->size.length=(edk::uint64)n;
        return *this;
    }
    inline edk::cubeui64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->origin.z=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        this->size.length=(edk::uint64)n;
        return *this;
    }
    inline edk::cubeui64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->origin.z=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        this->size.length=(edk::uint64)n;
        return *this;
    }
    inline edk::cubeui64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->origin.z=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        this->size.length=(edk::uint64)n;
        return *this;
    }

    inline bool operator==(cubeui64 cube){
        //
        return (this->origin.x==(edk::uint64)cube.origin.x
                &&this->origin.y==(edk::uint64)cube.origin.y
                &&this->origin.z==(edk::uint64)cube.origin.z
                &&this->size.width==(edk::uint64)cube.size.width
                &&this->size.height==(edk::uint64)cube.size.height
                &&this->size.length==(edk::uint64)cube.size.length
                );
    }
    inline bool operator!=(cubeui64 cube){
        //
        return (this->origin.x!=(edk::uint64)cube.origin.x
                ||this->origin.y!=(edk::uint64)cube.origin.y
                ||this->origin.z!=(edk::uint64)cube.origin.z
                ||this->size.width!=(edk::uint64)cube.size.width
                ||this->size.height!=(edk::uint64)cube.size.height
                ||this->size.length!=(edk::uint64)cube.size.length
                );
    }
    inline edk::cubeui64 operator+(cubeui64 cube){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::uint64)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::uint64)cube.origin.z;
        ret.size.width=this->size.width+(edk::uint64)cube.size.width;
        ret.size.height=this->size.height+(edk::uint64)cube.size.height;
        ret.size.length=this->size.length+(edk::uint64)cube.size.length;
        return ret;
    }
    inline edk::cubeui64 operator+(edk::uint8 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.origin.z=this->origin.z+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        ret.size.length=this->size.length+(edk::uint64)n;
        return ret;
    }
    inline edk::cubeui64 operator+(edk::uint32 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.origin.z=this->origin.z+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        ret.size.length=this->size.length+(edk::uint64)n;
        return ret;
    }
    inline edk::cubeui64 operator+(edk::uint16 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.origin.z=this->origin.z+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        ret.size.length=this->size.length+(edk::uint64)n;
        return ret;
    }
    inline edk::cubeui64 operator+(edk::uint64 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.origin.z=this->origin.z+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        ret.size.length=this->size.length+(edk::uint64)n;
        return ret;
    }
    inline void operator+=(cubeui64 cube){
        //
        this->origin.x+=(edk::uint64)cube.origin.x;
        this->origin.y+=(edk::uint64)cube.origin.y;
        this->origin.z+=(edk::uint64)cube.origin.z;
        this->size.width+=(edk::uint64)cube.size.width;
        this->size.height+=(edk::uint64)cube.size.height;
        this->size.length+=(edk::uint64)cube.size.length;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->origin.z+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
        this->size.length+=(edk::uint64)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->origin.z+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
        this->size.length+=(edk::uint64)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->origin.z+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
        this->size.length+=(edk::uint64)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->origin.z+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
        this->size.length+=(edk::uint64)n;
    }
    inline edk::cubeui64 operator-(cubeui64 cube){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::uint64)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::uint64)cube.origin.z;
        ret.size.width=this->size.width-(edk::uint64)cube.size.width;
        ret.size.height=this->size.height-(edk::uint64)cube.size.height;
        ret.size.length=this->size.length-(edk::uint64)cube.size.length;
        return ret;
    }
    inline edk::cubeui64 operator-(edk::uint8 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.origin.z=this->origin.z-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        ret.size.length=this->size.length-(edk::uint64)n;
        return ret;
    }
    inline edk::cubeui64 operator-(edk::uint32 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.origin.z=this->origin.z-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        ret.size.length=this->size.length-(edk::uint64)n;
        return ret;
    }
    inline edk::cubeui64 operator-(edk::uint16 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.origin.z=this->origin.z-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        ret.size.length=this->size.length-(edk::uint64)n;
        return ret;
    }
    inline edk::cubeui64 operator-(edk::uint64 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.origin.z=this->origin.z-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        ret.size.length=this->size.length-(edk::uint64)n;
        return ret;
    }
    inline void operator-=(cubeui64 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;
        this->origin.y-=(edk::uint64)vec.origin.y;
        this->origin.z-=(edk::uint64)vec.origin.z;
        this->size.width-=(edk::uint64)vec.size.width;
        this->size.height-=(edk::uint64)vec.size.height;
        this->size.length-=(edk::uint64)vec.size.length;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->origin.z-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
        this->size.length-=(edk::uint64)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->origin.z-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
        this->size.length-=(edk::uint64)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->origin.z-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
        this->size.length-=(edk::uint64)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->origin.z-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
        this->size.length-=(edk::uint64)n;
    }
    inline edk::cubeui64 operator*(cubeui64 cube){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::uint64)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::uint64)cube.origin.z;
        ret.size.width=this->size.width*(edk::uint64)cube.size.width;
        ret.size.height=this->size.height*(edk::uint64)cube.size.height;
        ret.size.length=this->size.length*(edk::uint64)cube.size.length;
        return ret;
    }
    inline edk::cubeui64 operator*(edk::uint8 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.origin.z=this->origin.z*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        ret.size.length=this->size.length*(edk::uint64)n;
        return ret;
    }
    inline edk::cubeui64 operator*(edk::uint32 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.origin.z=this->origin.z*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        ret.size.length=this->size.length*(edk::uint64)n;
        return ret;
    }
    inline edk::cubeui64 operator*(edk::uint16 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.origin.z=this->origin.z*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        ret.size.length=this->size.length*(edk::uint64)n;
        return ret;
    }
    inline edk::cubeui64 operator*(edk::uint64 n){
        //
        edk::cubeui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.origin.z=this->origin.z*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        ret.size.length=this->size.length*(edk::uint64)n;
        return ret;
    }
    inline void operator*=(cubeui64 cube){
        //
        this->origin.x*=(edk::uint64)cube.origin.x;
        this->origin.y*=(edk::uint64)cube.origin.y;
        this->origin.z*=(edk::uint64)cube.origin.z;
        this->size.width*=(edk::uint64)cube.size.width;
        this->size.height*=(edk::uint64)cube.size.height;
        this->size.length*=(edk::uint64)cube.size.length;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->origin.z*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
        this->size.length*=(edk::uint64)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->origin.z*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
        this->size.length*=(edk::uint64)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->origin.z*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
        this->size.length*=(edk::uint64)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->origin.z*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
        this->size.length*=(edk::uint64)n;
    }
    //
    inline edk::cubeui64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return edk::cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return edk::cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return edk::cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return edk::cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline edk::cubeui64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);
    }
    inline edk::cubeui64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->origin.z=(edk::uint64)z;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        this->size.length=(edk::uint64)length;
        return edk::cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);
    }
    inline edk::cubeui64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->origin.z=(edk::uint64)z;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        this->size.length=(edk::uint64)length;
        return edk::cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);
    }
    inline edk::cubeui64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->origin.z=(edk::uint64)z;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        this->size.length=(edk::uint64)length;
        return edk::cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);
    }
    //function to merge the cube with another cube
    inline void merge(edk::cubeui8 rect){
        if(this->origin.x > (edk::uint64)rect.origin.x)this->origin.x = (edk::uint64)rect.origin.x;
        if(this->origin.y > (edk::uint64)rect.origin.y)this->origin.y = (edk::uint64)rect.origin.y;
        if(this->origin.z > (edk::uint64)rect.origin.z)this->origin.z = (edk::uint64)rect.origin.z;
        if(this->size.width < (edk::uint64)rect.size.width)this->size.width = (edk::uint64)rect.size.width;
        if(this->size.height < (edk::uint64)rect.size.height)this->size.height = (edk::uint64)rect.size.height;
        if(this->size.length < (edk::uint64)rect.size.length)this->size.length = (edk::uint64)rect.size.length;
    }
    inline void merge(edk::cubeui16 rect){
        if(this->origin.x > (edk::uint64)rect.origin.x)this->origin.x = (edk::uint64)rect.origin.x;
        if(this->origin.y > (edk::uint64)rect.origin.y)this->origin.y = (edk::uint64)rect.origin.y;
        if(this->origin.z > (edk::uint64)rect.origin.z)this->origin.z = (edk::uint64)rect.origin.z;
        if(this->size.width < (edk::uint64)rect.size.width)this->size.width = (edk::uint64)rect.size.width;
        if(this->size.height < (edk::uint64)rect.size.height)this->size.height = (edk::uint64)rect.size.height;
        if(this->size.length < (edk::uint64)rect.size.length)this->size.length = (edk::uint64)rect.size.length;
    }
    inline void merge(edk::cubeui32 rect){
        if(this->origin.x > (edk::uint64)rect.origin.x)this->origin.x = (edk::uint64)rect.origin.x;
        if(this->origin.y > (edk::uint64)rect.origin.y)this->origin.y = (edk::uint64)rect.origin.y;
        if(this->origin.z > (edk::uint64)rect.origin.z)this->origin.z = (edk::uint64)rect.origin.z;
        if(this->size.width < (edk::uint64)rect.size.width)this->size.width = (edk::uint64)rect.size.width;
        if(this->size.height < (edk::uint64)rect.size.height)this->size.height = (edk::uint64)rect.size.height;
        if(this->size.length < (edk::uint64)rect.size.length)this->size.length = (edk::uint64)rect.size.length;
    }
    inline void merge(edk::cubeui64 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->origin.z > rect.origin.z)this->origin.z = rect.origin.z;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
        if(this->size.length < rect.size.length)this->size.length = rect.size.length;
    }
};

class cubef32{
public:
    //position
    edk::vec3f32 origin;
    //size
    edk::size3f32 size;
    //Construtor
    cubef32(){
        //
        this->origin.x=(edk::float32)0;
        this->origin.y=(edk::float32)0;
        this->origin.z=(edk::float32)0;
        this->size.width=(edk::float32)0;
        this->size.height=(edk::float32)0;
        this->size.length=(edk::float32)0;
    }
    cubef32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->origin.z=(edk::float32)z;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        this->size.length=(edk::float32)length;
    }
    cubef32(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->origin.z=(edk::float32)z;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        this->size.length=(edk::float32)length;
    }
    cubef32(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->origin.z=(edk::float32)z;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        this->size.length=(edk::float32)length;
    }
    cubef32(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->origin.z=(edk::float32)z;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        this->size.length=(edk::float32)length;
    }
    cubef32(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->origin.z=(edk::float32)z;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        this->size.length=(edk::float32)length;
    }
    cubef32(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->origin.z=(edk::float32)z;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        this->size.length=(edk::float32)length;
    }
    cubef32(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->origin.z=(edk::float32)z;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        this->size.length=(edk::float32)length;
    }
    cubef32(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->origin.z=(edk::float32)z;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        this->size.length=(edk::float32)length;
    }
    cubef32(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->origin.z=(edk::float32)z;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        this->size.length=(edk::float32)length;
    }
    cubef32(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->origin.z=(edk::float32)z;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        this->size.length=(edk::float32)length;
    }
    cubef32(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->origin.z=(edk::float32)origin.z;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
        this->size.length=(edk::float32)size.length;
    }
    cubef32(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->origin.z=(edk::float32)origin.z;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
        this->size.length=(edk::float32)size.length;
    }
    cubef32(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->origin.z=(edk::float32)origin.z;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
        this->size.length=(edk::float32)size.length;
    }
    cubef32(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->origin.z=(edk::float32)origin.z;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
        this->size.length=(edk::float32)size.length;
    }
    cubef32(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->origin.z=(edk::float32)origin.z;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
        this->size.length=(edk::float32)size.length;
    }
    cubef32(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->origin.z=(edk::float32)origin.z;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
        this->size.length=(edk::float32)size.length;
    }
    cubef32(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->origin.z=(edk::float32)origin.z;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
        this->size.length=(edk::float32)size.length;
    }
    cubef32(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->origin.z=(edk::float32)origin.z;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
        this->size.length=(edk::float32)size.length;
    }
    cubef32(edk::vec3f32 origin,edk::size3f32 size){
        //
        this->origin.x=origin.x;
        this->origin.y=origin.y;
        this->origin.z=origin.z;
        this->size.width=size.width;
        this->size.height=size.height;
        this->size.length=size.length;
    }
    cubef32(edk::vec3f64 origin,edk::size3f64 size){
        //
        this->origin.x=(edk::float32)origin.x;
        this->origin.y=(edk::float32)origin.y;
        this->origin.z=(edk::float32)origin.z;
        this->size.width=(edk::float32)size.width;
        this->size.height=(edk::float32)size.height;
        this->size.length=(edk::float32)size.length;
    }

    //operators
    inline cubef32 operator=(cubef32 cube){
        //
        this->origin.x=(edk::float32)cube.origin.x;
        this->origin.y=(edk::float32)cube.origin.y;
        this->origin.z=(edk::float32)cube.origin.z;
        this->size.width=(edk::float32)cube.size.width;
        this->size.height=(edk::float32)cube.size.height;
        this->size.length=(edk::float32)cube.size.length;
        return *this;
    }
    inline cubef32 operator=(edk::float32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    inline cubef32 operator=(edk::float64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    inline cubef32 operator=(edk::int8 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    inline cubef32 operator=(edk::int32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    inline cubef32 operator=(edk::int16 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    inline cubef32 operator=(edk::int64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    inline cubef32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    inline cubef32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    inline cubef32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    inline cubef32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }

    inline bool operator==(cubef32 cube){
        //
        return (this->origin.x==(edk::float32)cube.origin.x
                &&this->origin.y==(edk::float32)cube.origin.y
                &&this->origin.z==(edk::float32)cube.origin.z
                &&this->size.width==(edk::float32)cube.size.width
                &&this->size.height==(edk::float32)cube.size.height
                &&this->size.length==(edk::float32)cube.size.length
                );
    }
    inline bool operator!=(cubef32 cube){
        //
        return (this->origin.x!=(edk::float32)cube.origin.x
                ||this->origin.y!=(edk::float32)cube.origin.y
                ||this->origin.z!=(edk::float32)cube.origin.z
                ||this->size.width!=(edk::float32)cube.size.width
                ||this->size.height!=(edk::float32)cube.size.height
                ||this->size.length!=(edk::float32)cube.size.length
                );
    }
    inline cubef32 operator+(cubef32 cube){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::float32)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::float32)cube.origin.z;
        ret.size.width=this->size.width+(edk::float32)cube.size.width;
        ret.size.height=this->size.height+(edk::float32)cube.size.height;
        ret.size.length=this->size.length+(edk::float32)cube.size.length;
        return ret;
    }
    inline cubef32 operator+(edk::float32 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.origin.z=this->origin.z+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        ret.size.length=this->size.length+(edk::float32)n;
        return ret;
    }
    inline cubef32 operator+(edk::float64 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.origin.z=this->origin.z+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        ret.size.length=this->size.length+(edk::float32)n;
        return ret;
    }
    inline cubef32 operator+(edk::int8 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.origin.z=this->origin.z+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        ret.size.length=this->size.length+(edk::float32)n;
        return ret;
    }
    inline cubef32 operator+(edk::int32 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.origin.z=this->origin.z+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        ret.size.length=this->size.length+(edk::float32)n;
        return ret;
    }
    inline cubef32 operator+(edk::int16 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.origin.z=this->origin.z+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        ret.size.length=this->size.length+(edk::float32)n;
        return ret;
    }
    inline cubef32 operator+(edk::int64 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.origin.z=this->origin.z+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        ret.size.length=this->size.length+(edk::float32)n;
        return ret;
    }
    inline cubef32 operator+(edk::uint8 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.origin.z=this->origin.z+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        ret.size.length=this->size.length+(edk::float32)n;
        return ret;
    }
    inline cubef32 operator+(edk::uint32 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.origin.z=this->origin.z+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        ret.size.length=this->size.length+(edk::float32)n;
        return ret;
    }
    inline cubef32 operator+(edk::uint16 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.origin.z=this->origin.z+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        ret.size.length=this->size.length+(edk::float32)n;
        return ret;
    }
    inline cubef32 operator+(edk::uint64 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.origin.z=this->origin.z+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        ret.size.length=this->size.length+(edk::float32)n;
        return ret;
    }
    inline void operator+=(cubef32 cube){
        //
        this->origin.x+=(edk::float32)cube.origin.x;
        this->origin.y+=(edk::float32)cube.origin.y;
        this->origin.z+=(edk::float32)cube.origin.z;
        this->size.width+=(edk::float32)cube.size.width;
        this->size.height+=(edk::float32)cube.size.height;
        this->size.length+=(edk::float32)cube.size.length;
    }
    inline void operator+=(edk::float32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    inline void operator+=(edk::float64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    inline cubef32 operator-(cubef32 cube){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::float32)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::float32)cube.origin.z;
        ret.size.width=this->size.width-(edk::float32)cube.size.width;
        ret.size.height=this->size.height-(edk::float32)cube.size.height;
        ret.size.length=this->size.length-(edk::float32)cube.size.length;
        return ret;
    }
    inline cubef32 operator-(edk::float32 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.origin.z=this->origin.z-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        ret.size.length=this->size.length-(edk::float32)n;
        return ret;
    }
    inline cubef32 operator-(edk::float64 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.origin.z=this->origin.z-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        ret.size.length=this->size.length-(edk::float32)n;
        return ret;
    }
    inline cubef32 operator-(edk::int8 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.origin.z=this->origin.z-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        ret.size.length=this->size.length-(edk::float32)n;
        return ret;
    }
    inline cubef32 operator-(edk::int32 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.origin.z=this->origin.z-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        ret.size.length=this->size.length-(edk::float32)n;
        return ret;
    }
    inline cubef32 operator-(edk::int16 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.origin.z=this->origin.z-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        ret.size.length=this->size.length-(edk::float32)n;
        return ret;
    }
    inline cubef32 operator-(edk::int64 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.origin.z=this->origin.z-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        ret.size.length=this->size.length-(edk::float32)n;
        return ret;
    }
    inline cubef32 operator-(edk::uint8 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.origin.z=this->origin.z-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        ret.size.length=this->size.length-(edk::float32)n;
        return ret;
    }
    inline cubef32 operator-(edk::uint32 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.origin.z=this->origin.z-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        ret.size.length=this->size.length-(edk::float32)n;
        return ret;
    }
    inline cubef32 operator-(edk::uint16 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.origin.z=this->origin.z-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        ret.size.length=this->size.length-(edk::float32)n;
        return ret;
    }
    inline cubef32 operator-(edk::uint64 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.origin.z=this->origin.z-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        ret.size.length=this->size.length-(edk::float32)n;
        return ret;
    }
    inline void operator-=(cubef32 vec){
        //
        this->origin.x-=(edk::float32)vec.origin.x;
        this->origin.y-=(edk::float32)vec.origin.y;
        this->origin.z-=(edk::float32)vec.origin.z;
        this->size.width-=(edk::float32)vec.size.width;
        this->size.height-=(edk::float32)vec.size.height;
        this->size.length-=(edk::float32)vec.size.length;
    }
    inline void operator-=(edk::float32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    inline void operator-=(edk::float64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    inline cubef32 operator*(cubef32 cube){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::float32)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::float32)cube.origin.z;
        ret.size.width=this->size.width*(edk::float32)cube.size.width;
        ret.size.height=this->size.height*(edk::float32)cube.size.height;
        ret.size.length=this->size.length*(edk::float32)cube.size.length;
        return ret;
    }
    inline cubef32 operator*(edk::float32 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.origin.z=this->origin.z*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        ret.size.length=this->size.length*(edk::float32)n;
        return ret;
    }
    inline cubef32 operator*(edk::float64 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.origin.z=this->origin.z*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        ret.size.length=this->size.length*(edk::float32)n;
        return ret;
    }
    inline cubef32 operator*(edk::int8 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.origin.z=this->origin.z*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        ret.size.length=this->size.length*(edk::float32)n;
        return ret;
    }
    inline cubef32 operator*(edk::int32 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.origin.z=this->origin.z*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        ret.size.length=this->size.length*(edk::float32)n;
        return ret;
    }
    inline cubef32 operator*(edk::int16 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.origin.z=this->origin.z*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        ret.size.length=this->size.length*(edk::float32)n;
        return ret;
    }
    inline cubef32 operator*(edk::int64 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.origin.z=this->origin.z*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        ret.size.length=this->size.length*(edk::float32)n;
        return ret;
    }
    inline cubef32 operator*(edk::uint8 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.origin.z=this->origin.z*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        ret.size.length=this->size.length*(edk::float32)n;
        return ret;
    }
    inline cubef32 operator*(edk::uint32 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.origin.z=this->origin.z*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        ret.size.length=this->size.length*(edk::float32)n;
        return ret;
    }
    inline cubef32 operator*(edk::uint16 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.origin.z=this->origin.z*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        ret.size.length=this->size.length*(edk::float32)n;
        return ret;
    }
    inline cubef32 operator*(edk::uint64 n){
        //
        cubef32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.origin.z=this->origin.z*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        ret.size.length=this->size.length*(edk::float32)n;
        return ret;
    }
    inline void operator*=(cubef32 cube){
        //
        this->origin.x*=(edk::float32)cube.origin.x;
        this->origin.y*=(edk::float32)cube.origin.y;
        this->origin.z*=(edk::float32)cube.origin.z;
        this->size.width*=(edk::float32)cube.size.width;
        this->size.height*=(edk::float32)cube.size.height;
        this->size.length*=(edk::float32)cube.size.length;
    }
    inline void operator*=(edk::float32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    inline void operator*=(edk::float64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    //
    inline cubef32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return edk::cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline cubef32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return edk::cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline cubef32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return edk::cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline cubef32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return edk::cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline cubef32 operator()(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    inline cubef32 operator()(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    inline cubef32 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    inline cubef32 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    inline cubef32 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    inline cubef32 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    inline cubef32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    inline cubef32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    inline cubef32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    inline cubef32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    //function to merge the cube with another cube
    inline void merge(edk::cubef32 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->origin.z > rect.origin.z)this->origin.z = rect.origin.z;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
        if(this->size.length < rect.size.length)this->size.length = rect.size.length;
    }
};

class cubef64{
public:
    //position
    edk::vec3f64 origin;
    //size
    edk::size3f64 size;
    //Construtor
    cubef64(){
        //
        this->origin.x=(edk::float64)0;
        this->origin.y=(edk::float64)0;
        this->origin.z=(edk::float64)0;
        this->size.width=(edk::float64)0;
        this->size.height=(edk::float64)0;
        this->size.length=(edk::float64)0;
    }
    cubef64(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->origin.z=(edk::float64)z;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        this->size.length=(edk::float64)length;
    }
    cubef64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->origin.z=(edk::float64)z;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        this->size.length=(edk::float64)length;
    }
    cubef64(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->origin.z=(edk::float64)z;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        this->size.length=(edk::float64)length;
    }
    cubef64(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->origin.z=(edk::float64)z;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        this->size.length=(edk::float64)length;
    }
    cubef64(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->origin.z=(edk::float64)z;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        this->size.length=(edk::float64)length;
    }
    cubef64(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->origin.z=(edk::float64)z;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        this->size.length=(edk::float64)length;
    }
    cubef64(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->origin.z=(edk::float64)z;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        this->size.length=(edk::float64)length;
    }
    cubef64(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->origin.z=(edk::float64)z;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        this->size.length=(edk::float64)length;
    }
    cubef64(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->origin.z=(edk::float64)z;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        this->size.length=(edk::float64)length;
    }
    cubef64(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->origin.z=(edk::float64)z;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        this->size.length=(edk::float64)length;
    }
    cubef64(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->origin.z=(edk::float64)origin.z;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
        this->size.length=(edk::float64)size.length;
    }
    cubef64(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->origin.z=(edk::float64)origin.z;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
        this->size.length=(edk::float64)size.length;
    }
    cubef64(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->origin.z=(edk::float64)origin.z;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
        this->size.length=(edk::float64)size.length;
    }
    cubef64(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->origin.z=(edk::float64)origin.z;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
        this->size.length=(edk::float64)size.length;
    }
    cubef64(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->origin.z=(edk::float64)origin.z;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
        this->size.length=(edk::float64)size.length;
    }
    cubef64(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->origin.z=(edk::float64)origin.z;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
        this->size.length=(edk::float64)size.length;
    }
    cubef64(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->origin.z=(edk::float64)origin.z;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
        this->size.length=(edk::float64)size.length;
    }
    cubef64(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->origin.z=(edk::float64)origin.z;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
        this->size.length=(edk::float64)size.length;
    }
    cubef64(edk::vec3f32 origin,edk::size3f32 size){
        //
        this->origin.x=(edk::float64)origin.x;
        this->origin.y=(edk::float64)origin.y;
        this->origin.z=(edk::float64)origin.z;
        this->size.width=(edk::float64)size.width;
        this->size.height=(edk::float64)size.height;
        this->size.length=(edk::float64)size.length;
    }
    cubef64(edk::vec3f64 origin,edk::size3f64 size){
        //
        this->origin.x=origin.x;
        this->origin.y=origin.y;
        this->origin.z=origin.z;
        this->size.width=size.width;
        this->size.height=size.height;
        this->size.length=size.length;
    }

    //operators
    inline cubef64 operator=(cubef64 cube){
        //
        this->origin.x=(edk::float64)cube.origin.x;
        this->origin.y=(edk::float64)cube.origin.y;
        this->origin.z=(edk::float64)cube.origin.z;
        this->size.width=(edk::float64)cube.size.width;
        this->size.height=(edk::float64)cube.size.height;
        this->size.length=(edk::float64)cube.size.length;
        return *this;
    }
    inline cubef64 operator=(edk::float32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    inline cubef64 operator=(edk::float64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    inline cubef64 operator=(edk::int8 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    inline cubef64 operator=(edk::int32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    inline cubef64 operator=(edk::int16 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    inline cubef64 operator=(edk::int64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    inline cubef64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    inline cubef64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    inline cubef64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    inline cubef64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }

    inline bool operator==(cubef64 cube){
        //
        return (this->origin.x==(edk::float64)cube.origin.x
                &&this->origin.y==(edk::float64)cube.origin.y
                &&this->origin.z==(edk::float64)cube.origin.z
                &&this->size.width==(edk::float64)cube.size.width
                &&this->size.height==(edk::float64)cube.size.height
                &&this->size.length==(edk::float64)cube.size.length
                );
    }
    inline bool operator!=(cubef64 cube){
        //
        return (this->origin.x!=(edk::float64)cube.origin.x
                ||this->origin.y!=(edk::float64)cube.origin.y
                ||this->origin.z!=(edk::float64)cube.origin.z
                ||this->size.width!=(edk::float64)cube.size.width
                ||this->size.height!=(edk::float64)cube.size.height
                ||this->size.length!=(edk::float64)cube.size.length
                );
    }
    inline cubef64 operator+(cubef64 cube){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::float64)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::float64)cube.origin.z;
        ret.size.width=this->size.width+(edk::float64)cube.size.width;
        ret.size.height=this->size.height+(edk::float64)cube.size.height;
        ret.size.length=this->size.length+(edk::float64)cube.size.length;
        return ret;
    }
    inline cubef64 operator+(edk::float32 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.origin.z=this->origin.z+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        ret.size.length=this->size.length+(edk::float64)n;
        return ret;
    }
    inline cubef64 operator+(edk::float64 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.origin.z=this->origin.z+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        ret.size.length=this->size.length+(edk::float64)n;
        return ret;
    }
    inline cubef64 operator+(edk::int8 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.origin.z=this->origin.z+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        ret.size.length=this->size.length+(edk::float64)n;
        return ret;
    }
    inline cubef64 operator+(edk::int32 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.origin.z=this->origin.z+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        ret.size.length=this->size.length+(edk::float64)n;
        return ret;
    }
    inline cubef64 operator+(edk::int16 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.origin.z=this->origin.z+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        ret.size.length=this->size.length+(edk::float64)n;
        return ret;
    }
    inline cubef64 operator+(edk::int64 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.origin.z=this->origin.z+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        ret.size.length=this->size.length+(edk::float64)n;
        return ret;
    }
    inline cubef64 operator+(edk::uint8 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.origin.z=this->origin.z+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        ret.size.length=this->size.length+(edk::float64)n;
        return ret;
    }
    inline cubef64 operator+(edk::uint32 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.origin.z=this->origin.z+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        ret.size.length=this->size.length+(edk::float64)n;
        return ret;
    }
    inline cubef64 operator+(edk::uint16 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.origin.z=this->origin.z+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        ret.size.length=this->size.length+(edk::float64)n;
        return ret;
    }
    inline cubef64 operator+(edk::uint64 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.origin.z=this->origin.z+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        ret.size.length=this->size.length+(edk::float64)n;
        return ret;
    }
    inline void operator+=(cubef64 cube){
        //
        this->origin.x+=(edk::float64)cube.origin.x;
        this->origin.y+=(edk::float64)cube.origin.y;
        this->origin.z+=(edk::float64)cube.origin.z;
        this->size.width+=(edk::float64)cube.size.width;
        this->size.height+=(edk::float64)cube.size.height;
        this->size.length+=(edk::float64)cube.size.length;
    }
    inline void operator+=(edk::float32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    inline void operator+=(edk::float64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    inline void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    inline cubef64 operator-(cubef64 cube){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::float64)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::float64)cube.origin.z;
        ret.size.width=this->size.width-(edk::float64)cube.size.width;
        ret.size.height=this->size.height-(edk::float64)cube.size.height;
        ret.size.length=this->size.length-(edk::float64)cube.size.length;
        return ret;
    }
    inline cubef64 operator-(edk::float32 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.origin.z=this->origin.z-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        ret.size.length=this->size.length-(edk::float64)n;
        return ret;
    }
    inline cubef64 operator-(edk::float64 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.origin.z=this->origin.z-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        ret.size.length=this->size.length-(edk::float64)n;
        return ret;
    }
    inline cubef64 operator-(edk::int8 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.origin.z=this->origin.z-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        ret.size.length=this->size.length-(edk::float64)n;
        return ret;
    }
    inline cubef64 operator-(edk::int32 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.origin.z=this->origin.z-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        ret.size.length=this->size.length-(edk::float64)n;
        return ret;
    }
    inline cubef64 operator-(edk::int16 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.origin.z=this->origin.z-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        ret.size.length=this->size.length-(edk::float64)n;
        return ret;
    }
    inline cubef64 operator-(edk::int64 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.origin.z=this->origin.z-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        ret.size.length=this->size.length-(edk::float64)n;
        return ret;
    }
    inline cubef64 operator-(edk::uint8 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.origin.z=this->origin.z-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        ret.size.length=this->size.length-(edk::float64)n;
        return ret;
    }
    inline cubef64 operator-(edk::uint32 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.origin.z=this->origin.z-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        ret.size.length=this->size.length-(edk::float64)n;
        return ret;
    }
    inline cubef64 operator-(edk::uint16 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.origin.z=this->origin.z-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        ret.size.length=this->size.length-(edk::float64)n;
        return ret;
    }
    inline cubef64 operator-(edk::uint64 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.origin.z=this->origin.z-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        ret.size.length=this->size.length-(edk::float64)n;
        return ret;
    }
    inline void operator-=(cubef64 vec){
        //
        this->origin.x-=(edk::float64)vec.origin.x;
        this->origin.y-=(edk::float64)vec.origin.y;
        this->origin.z-=(edk::float64)vec.origin.z;
        this->size.width-=(edk::float64)vec.size.width;
        this->size.height-=(edk::float64)vec.size.height;
        this->size.length-=(edk::float64)vec.size.length;
    }
    inline void operator-=(edk::float32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    inline void operator-=(edk::float64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    inline void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    inline cubef64 operator*(cubef64 cube){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::float64)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::float64)cube.origin.z;
        ret.size.width=this->size.width*(edk::float64)cube.size.width;
        ret.size.height=this->size.height*(edk::float64)cube.size.height;
        ret.size.length=this->size.length*(edk::float64)cube.size.length;
        return ret;
    }
    inline cubef64 operator*(edk::float32 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.origin.z=this->origin.z*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        ret.size.length=this->size.length*(edk::float64)n;
        return ret;
    }
    inline cubef64 operator*(edk::float64 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.origin.z=this->origin.z*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        ret.size.length=this->size.length*(edk::float64)n;
        return ret;
    }
    inline cubef64 operator*(edk::int8 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.origin.z=this->origin.z*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        ret.size.length=this->size.length*(edk::float64)n;
        return ret;
    }
    inline cubef64 operator*(edk::int32 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.origin.z=this->origin.z*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        ret.size.length=this->size.length*(edk::float64)n;
        return ret;
    }
    inline cubef64 operator*(edk::int16 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.origin.z=this->origin.z*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        ret.size.length=this->size.length*(edk::float64)n;
        return ret;
    }
    inline cubef64 operator*(edk::int64 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.origin.z=this->origin.z*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        ret.size.length=this->size.length*(edk::float64)n;
        return ret;
    }
    inline cubef64 operator*(edk::uint8 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.origin.z=this->origin.z*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        ret.size.length=this->size.length*(edk::float64)n;
        return ret;
    }
    inline cubef64 operator*(edk::uint32 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.origin.z=this->origin.z*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        ret.size.length=this->size.length*(edk::float64)n;
        return ret;
    }
    inline cubef64 operator*(edk::uint16 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.origin.z=this->origin.z*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        ret.size.length=this->size.length*(edk::float64)n;
        return ret;
    }
    inline cubef64 operator*(edk::uint64 n){
        //
        cubef64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.origin.z=this->origin.z*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        ret.size.length=this->size.length*(edk::float64)n;
        return ret;
    }
    inline void operator*=(cubef64 cube){
        //
        this->origin.x*=(edk::float64)cube.origin.x;
        this->origin.y*=(edk::float64)cube.origin.y;
        this->origin.z*=(edk::float64)cube.origin.z;
        this->size.width*=(edk::float64)cube.size.width;
        this->size.height*=(edk::float64)cube.size.height;
        this->size.length*=(edk::float64)cube.size.length;
    }
    inline void operator*=(edk::float32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    inline void operator*=(edk::float64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    inline void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    //
    inline cubef64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return edk::cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline cubef64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return edk::cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline cubef64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return edk::cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline cubef64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return edk::cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    inline cubef64 operator()(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    inline cubef64 operator()(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    inline cubef64 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    inline cubef64 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    inline cubef64 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    inline cubef64 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    inline cubef64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    inline cubef64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    inline cubef64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    inline cubef64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return edk::cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    //function to merge the cube with another cube
    inline void merge(edk::cubef32 rect){
        if(this->origin.x > (edk::float64)rect.origin.x)this->origin.x = (edk::float64)rect.origin.x;
        if(this->origin.y > (edk::float64)rect.origin.y)this->origin.y = (edk::float64)rect.origin.y;
        if(this->origin.z > (edk::float64)rect.origin.z)this->origin.z = (edk::float64)rect.origin.z;
        if(this->size.width < (edk::float64)rect.size.width)this->size.width = (edk::float64)rect.size.width;
        if(this->size.height < (edk::float64)rect.size.height)this->size.height = (edk::float64)rect.size.height;
        if(this->size.length < (edk::float64)rect.size.length)this->size.length = (edk::float64)rect.size.length;
    }
    inline void merge(edk::cubef64 rect){
        if(this->origin.x > rect.origin.x)this->origin.x = rect.origin.x;
        if(this->origin.y > rect.origin.y)this->origin.y = rect.origin.y;
        if(this->origin.z > rect.origin.z)this->origin.z = rect.origin.z;
        if(this->size.width < rect.size.width)this->size.width = rect.size.width;
        if(this->size.height < rect.size.height)this->size.height = rect.size.height;
        if(this->size.length < rect.size.length)this->size.length = rect.size.length;
    }
};

}//end namespace






#endif // TYPECUBE_H
