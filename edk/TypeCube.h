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
#warning "Inside TypeCube"
#endif

#pragma once
#include "TypeVars.h"
#include "TypeVec3.h"
#include "TypeSize3.h"

#ifdef printMessages
#warning "    Compiling TypeCube"
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
        this->origin.x=(edk::int8)0;edkEnd();
        this->origin.y=(edk::int8)0;edkEnd();
        this->origin.z=(edk::int8)0;edkEnd();
        this->size.width=(edk::int8)0;edkEnd();
        this->size.height=(edk::int8)0;edkEnd();
        this->size.length=(edk::int8)0;edkEnd();
    }
    cubei8(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::int8)x;edkEnd();
        this->origin.y=(edk::int8)y;edkEnd();
        this->origin.z=(edk::int8)z;edkEnd();
        this->size.width=(edk::int8)width;edkEnd();
        this->size.height=(edk::int8)height;edkEnd();
        this->size.length=(edk::int8)length;edkEnd();
    }
    cubei8(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::int8)x;edkEnd();
        this->origin.y=(edk::int8)y;edkEnd();
        this->origin.z=(edk::int8)z;edkEnd();
        this->size.width=(edk::int8)width;edkEnd();
        this->size.height=(edk::int8)height;edkEnd();
        this->size.length=(edk::int8)length;edkEnd();
    }
    cubei8(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::int8)x;edkEnd();
        this->origin.y=(edk::int8)y;edkEnd();
        this->origin.z=(edk::int8)z;edkEnd();
        this->size.width=(edk::int8)width;edkEnd();
        this->size.height=(edk::int8)height;edkEnd();
        this->size.length=(edk::int8)length;edkEnd();
    }
    cubei8(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::int8)x;edkEnd();
        this->origin.y=(edk::int8)y;edkEnd();
        this->origin.z=(edk::int8)z;edkEnd();
        this->size.width=(edk::int8)width;edkEnd();
        this->size.height=(edk::int8)height;edkEnd();
        this->size.length=(edk::int8)length;edkEnd();
    }
    cubei8(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::int8)x;edkEnd();
        this->origin.y=(edk::int8)y;edkEnd();
        this->origin.z=(edk::int8)z;edkEnd();
        this->size.width=(edk::int8)width;edkEnd();
        this->size.height=(edk::int8)height;edkEnd();
        this->size.length=(edk::int8)length;edkEnd();
    }
    cubei8(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::int8)x;edkEnd();
        this->origin.y=(edk::int8)y;edkEnd();
        this->origin.z=(edk::int8)z;edkEnd();
        this->size.width=(edk::int8)width;edkEnd();
        this->size.height=(edk::int8)height;edkEnd();
        this->size.length=(edk::int8)length;edkEnd();
    }
    cubei8(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::int8)x;edkEnd();
        this->origin.y=(edk::int8)y;edkEnd();
        this->origin.z=(edk::int8)z;edkEnd();
        this->size.width=(edk::int8)width;edkEnd();
        this->size.height=(edk::int8)height;edkEnd();
        this->size.length=(edk::int8)length;edkEnd();
    }
    cubei8(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::int8)x;edkEnd();
        this->origin.y=(edk::int8)y;edkEnd();
        this->origin.z=(edk::int8)z;edkEnd();
        this->size.width=(edk::int8)width;edkEnd();
        this->size.height=(edk::int8)height;edkEnd();
        this->size.length=(edk::int8)length;edkEnd();
    }
    cubei8(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::int8)origin.x;edkEnd();
        this->origin.y=(edk::int8)origin.y;edkEnd();
        this->origin.z=(edk::int8)origin.z;edkEnd();
        this->size.width=(edk::int8)size.width;edkEnd();
        this->size.height=(edk::int8)size.height;edkEnd();
        this->size.length=(edk::int8)size.length;edkEnd();
    }
    cubei8(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::int8)origin.x;edkEnd();
        this->origin.y=(edk::int8)origin.y;edkEnd();
        this->origin.z=(edk::int8)origin.z;edkEnd();
        this->size.width=(edk::int8)size.width;edkEnd();
        this->size.height=(edk::int8)size.height;edkEnd();
        this->size.length=(edk::int8)size.length;edkEnd();
    }
    cubei8(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::int8)origin.x;edkEnd();
        this->origin.y=(edk::int8)origin.y;edkEnd();
        this->origin.z=(edk::int8)origin.z;edkEnd();
        this->size.width=(edk::int8)size.width;edkEnd();
        this->size.height=(edk::int8)size.height;edkEnd();
        this->size.length=(edk::int8)size.length;edkEnd();
    }
    cubei8(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::int8)origin.x;edkEnd();
        this->origin.y=(edk::int8)origin.y;edkEnd();
        this->origin.z=(edk::int8)origin.z;edkEnd();
        this->size.width=(edk::int8)size.width;edkEnd();
        this->size.height=(edk::int8)size.height;edkEnd();
        this->size.length=(edk::int8)size.length;edkEnd();
    }
    cubei8(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::int8)origin.x;edkEnd();
        this->origin.y=(edk::int8)origin.y;edkEnd();
        this->origin.z=(edk::int8)origin.z;edkEnd();
        this->size.width=(edk::int8)size.width;edkEnd();
        this->size.height=(edk::int8)size.height;edkEnd();
        this->size.length=(edk::int8)size.length;edkEnd();
    }
    cubei8(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::int8)origin.x;edkEnd();
        this->origin.y=(edk::int8)origin.y;edkEnd();
        this->origin.z=(edk::int8)origin.z;edkEnd();
        this->size.width=(edk::int8)size.width;edkEnd();
        this->size.height=(edk::int8)size.height;edkEnd();
        this->size.length=(edk::int8)size.length;edkEnd();
    }
    cubei8(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::int8)origin.x;edkEnd();
        this->origin.y=(edk::int8)origin.y;edkEnd();
        this->origin.z=(edk::int8)origin.z;edkEnd();
        this->size.width=(edk::int8)size.width;edkEnd();
        this->size.height=(edk::int8)size.height;edkEnd();
        this->size.length=(edk::int8)size.length;edkEnd();
    }
    cubei8(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::int8)origin.x;edkEnd();
        this->origin.y=(edk::int8)origin.y;edkEnd();
        this->origin.z=(edk::int8)origin.z;edkEnd();
        this->size.width=(edk::int8)size.width;edkEnd();
        this->size.height=(edk::int8)size.height;edkEnd();
        this->size.length=(edk::int8)size.length;edkEnd();
    }

    //operators
    cubei8 operator=(cubei8 cube){
        //
        this->origin.x=(edk::int8)cube.origin.x;edkEnd();
        this->origin.y=(edk::int8)cube.origin.y;edkEnd();
        this->origin.z=(edk::int8)cube.origin.z;edkEnd();
        this->size.width=(edk::int8)cube.size.width;edkEnd();
        this->size.height=(edk::int8)cube.size.height;edkEnd();
        this->size.length=(edk::int8)cube.size.length;edkEnd();
        return *this;edkEnd();
    }
    cubei8 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int8)n;edkEnd();
        this->origin.y=(edk::int8)n;edkEnd();
        this->origin.z=(edk::int8)n;edkEnd();
        this->size.width=(edk::int8)n;edkEnd();
        this->size.height=(edk::int8)n;edkEnd();
        this->size.length=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    cubei8 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int8)n;edkEnd();
        this->origin.y=(edk::int8)n;edkEnd();
        this->origin.z=(edk::int8)n;edkEnd();
        this->size.width=(edk::int8)n;edkEnd();
        this->size.height=(edk::int8)n;edkEnd();
        this->size.length=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    cubei8 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int8)n;edkEnd();
        this->origin.y=(edk::int8)n;edkEnd();
        this->origin.z=(edk::int8)n;edkEnd();
        this->size.width=(edk::int8)n;edkEnd();
        this->size.height=(edk::int8)n;edkEnd();
        this->size.length=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    cubei8 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int8)n;edkEnd();
        this->origin.y=(edk::int8)n;edkEnd();
        this->origin.z=(edk::int8)n;edkEnd();
        this->size.width=(edk::int8)n;edkEnd();
        this->size.height=(edk::int8)n;edkEnd();
        this->size.length=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    cubei8 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int8)n;edkEnd();
        this->origin.y=(edk::int8)n;edkEnd();
        this->origin.z=(edk::int8)n;edkEnd();
        this->size.width=(edk::int8)n;edkEnd();
        this->size.height=(edk::int8)n;edkEnd();
        this->size.length=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    cubei8 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int8)n;edkEnd();
        this->origin.y=(edk::int8)n;edkEnd();
        this->origin.z=(edk::int8)n;edkEnd();
        this->size.width=(edk::int8)n;edkEnd();
        this->size.height=(edk::int8)n;edkEnd();
        this->size.length=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    cubei8 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int8)n;edkEnd();
        this->origin.y=(edk::int8)n;edkEnd();
        this->origin.z=(edk::int8)n;edkEnd();
        this->size.width=(edk::int8)n;edkEnd();
        this->size.height=(edk::int8)n;edkEnd();
        this->size.length=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    cubei8 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int8)n;edkEnd();
        this->origin.y=(edk::int8)n;edkEnd();
        this->origin.z=(edk::int8)n;edkEnd();
        this->size.width=(edk::int8)n;edkEnd();
        this->size.height=(edk::int8)n;edkEnd();
        this->size.length=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }

    bool operator==(cubei8 cube){
        //
        return (this->origin.x==(edk::int8)cube.origin.x
                &&this->origin.y==(edk::int8)cube.origin.y
                &&this->origin.z==(edk::int8)cube.origin.z
                &&this->size.width==(edk::int8)cube.size.width
                &&this->size.height==(edk::int8)cube.size.height
                &&this->size.length==(edk::int8)cube.size.length
                );edkEnd();
    }
    bool operator!=(cubei8 cube){
        //
        return (this->origin.x!=(edk::int8)cube.origin.x
                ||this->origin.y!=(edk::int8)cube.origin.y
                ||this->origin.z!=(edk::int8)cube.origin.z
                ||this->size.width!=(edk::int8)cube.size.width
                ||this->size.height!=(edk::int8)cube.size.height
                ||this->size.length!=(edk::int8)cube.size.length
                );edkEnd();
    }
    cubei8 operator+(cubei8 cube){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int8)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y+(edk::int8)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z+(edk::int8)cube.origin.z;edkEnd();
        ret.size.width=this->size.width+(edk::int8)cube.size.width;edkEnd();
        ret.size.height=this->size.height+(edk::int8)cube.size.height;edkEnd();
        ret.size.length=this->size.length+(edk::int8)cube.size.length;edkEnd();
        return ret;
    }
    cubei8 operator+(edk::int8 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int8)n;edkEnd();
        ret.size.width=this->size.width+(edk::int8)n;edkEnd();
        ret.size.height=this->size.height+(edk::int8)n;edkEnd();
        ret.size.length=this->size.length+(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator+(edk::int32 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int8)n;edkEnd();
        ret.size.width=this->size.width+(edk::int8)n;edkEnd();
        ret.size.height=this->size.height+(edk::int8)n;edkEnd();
        ret.size.length=this->size.length+(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator+(edk::int16 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int8)n;edkEnd();
        ret.size.width=this->size.width+(edk::int8)n;edkEnd();
        ret.size.height=this->size.height+(edk::int8)n;edkEnd();
        ret.size.length=this->size.length+(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator+(edk::int64 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int8)n;edkEnd();
        ret.size.width=this->size.width+(edk::int8)n;edkEnd();
        ret.size.height=this->size.height+(edk::int8)n;edkEnd();
        ret.size.length=this->size.length+(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator+(edk::uint8 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int8)n;edkEnd();
        ret.size.width=this->size.width+(edk::int8)n;edkEnd();
        ret.size.height=this->size.height+(edk::int8)n;edkEnd();
        ret.size.length=this->size.length+(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator+(edk::uint32 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int8)n;edkEnd();
        ret.size.width=this->size.width+(edk::int8)n;edkEnd();
        ret.size.height=this->size.height+(edk::int8)n;edkEnd();
        ret.size.length=this->size.length+(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator+(edk::uint16 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int8)n;edkEnd();
        ret.size.width=this->size.width+(edk::int8)n;edkEnd();
        ret.size.height=this->size.height+(edk::int8)n;edkEnd();
        ret.size.length=this->size.length+(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator+(edk::uint64 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int8)n;edkEnd();
        ret.size.width=this->size.width+(edk::int8)n;edkEnd();
        ret.size.height=this->size.height+(edk::int8)n;edkEnd();
        ret.size.length=this->size.length+(edk::int8)n;edkEnd();
        return ret;
    }
    void operator+=(cubei8 cube){
        //
        this->origin.x+=(edk::int8)cube.origin.x;edkEnd();
        this->origin.y+=(edk::int8)cube.origin.y;edkEnd();
        this->origin.z+=(edk::int8)cube.origin.z;edkEnd();
        this->size.width+=(edk::int8)cube.size.width;edkEnd();
        this->size.height+=(edk::int8)cube.size.height;edkEnd();
        this->size.length+=(edk::int8)cube.size.length;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int8)n;edkEnd();
        this->origin.y+=(edk::int8)n;edkEnd();
        this->origin.z+=(edk::int8)n;edkEnd();
        this->size.width+=(edk::int8)n;edkEnd();
        this->size.height+=(edk::int8)n;edkEnd();
        this->size.length+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int8)n;edkEnd();
        this->origin.y+=(edk::int8)n;edkEnd();
        this->origin.z+=(edk::int8)n;edkEnd();
        this->size.width+=(edk::int8)n;edkEnd();
        this->size.height+=(edk::int8)n;edkEnd();
        this->size.length+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int8)n;edkEnd();
        this->origin.y+=(edk::int8)n;edkEnd();
        this->origin.z+=(edk::int8)n;edkEnd();
        this->size.width+=(edk::int8)n;edkEnd();
        this->size.height+=(edk::int8)n;edkEnd();
        this->size.length+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int8)n;edkEnd();
        this->origin.y+=(edk::int8)n;edkEnd();
        this->origin.z+=(edk::int8)n;edkEnd();
        this->size.width+=(edk::int8)n;edkEnd();
        this->size.height+=(edk::int8)n;edkEnd();
        this->size.length+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int8)n;edkEnd();
        this->origin.y+=(edk::int8)n;edkEnd();
        this->origin.z+=(edk::int8)n;edkEnd();
        this->size.width+=(edk::int8)n;edkEnd();
        this->size.height+=(edk::int8)n;edkEnd();
        this->size.length+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int8)n;edkEnd();
        this->origin.y+=(edk::int8)n;edkEnd();
        this->origin.z+=(edk::int8)n;edkEnd();
        this->size.width+=(edk::int8)n;edkEnd();
        this->size.height+=(edk::int8)n;edkEnd();
        this->size.length+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int8)n;edkEnd();
        this->origin.y+=(edk::int8)n;edkEnd();
        this->origin.z+=(edk::int8)n;edkEnd();
        this->size.width+=(edk::int8)n;edkEnd();
        this->size.height+=(edk::int8)n;edkEnd();
        this->size.length+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int8)n;edkEnd();
        this->origin.y+=(edk::int8)n;edkEnd();
        this->origin.z+=(edk::int8)n;edkEnd();
        this->size.width+=(edk::int8)n;edkEnd();
        this->size.height+=(edk::int8)n;edkEnd();
        this->size.length+=(edk::int8)n;edkEnd();
    }
    cubei8 operator-(cubei8 cube){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int8)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y-(edk::int8)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z-(edk::int8)cube.origin.z;edkEnd();
        ret.size.width=this->size.width-(edk::int8)cube.size.width;edkEnd();
        ret.size.height=this->size.height-(edk::int8)cube.size.height;edkEnd();
        ret.size.length=this->size.length-(edk::int8)cube.size.length;edkEnd();
        return ret;
    }
    cubei8 operator-(edk::int8 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int8)n;edkEnd();
        ret.size.width=this->size.width-(edk::int8)n;edkEnd();
        ret.size.height=this->size.height-(edk::int8)n;edkEnd();
        ret.size.length=this->size.length-(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator-(edk::int32 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int8)n;edkEnd();
        ret.size.width=this->size.width-(edk::int8)n;edkEnd();
        ret.size.height=this->size.height-(edk::int8)n;edkEnd();
        ret.size.length=this->size.length-(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator-(edk::int16 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int8)n;edkEnd();
        ret.size.width=this->size.width-(edk::int8)n;edkEnd();
        ret.size.height=this->size.height-(edk::int8)n;edkEnd();
        ret.size.length=this->size.length-(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator-(edk::int64 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int8)n;edkEnd();
        ret.size.width=this->size.width-(edk::int8)n;edkEnd();
        ret.size.height=this->size.height-(edk::int8)n;edkEnd();
        ret.size.length=this->size.length-(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator-(edk::uint8 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int8)n;edkEnd();
        ret.size.width=this->size.width-(edk::int8)n;edkEnd();
        ret.size.height=this->size.height-(edk::int8)n;edkEnd();
        ret.size.length=this->size.length-(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator-(edk::uint32 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int8)n;edkEnd();
        ret.size.width=this->size.width-(edk::int8)n;edkEnd();
        ret.size.height=this->size.height-(edk::int8)n;edkEnd();
        ret.size.length=this->size.length-(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator-(edk::uint16 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int8)n;edkEnd();
        ret.size.width=this->size.width-(edk::int8)n;edkEnd();
        ret.size.height=this->size.height-(edk::int8)n;edkEnd();
        ret.size.length=this->size.length-(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator-(edk::uint64 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int8)n;edkEnd();
        ret.size.width=this->size.width-(edk::int8)n;edkEnd();
        ret.size.height=this->size.height-(edk::int8)n;edkEnd();
        ret.size.length=this->size.length-(edk::int8)n;edkEnd();
        return ret;
    }
    void operator-=(cubei8 vec){
        //
        this->origin.x-=(edk::int8)vec.origin.x;edkEnd();
        this->origin.y-=(edk::int8)vec.origin.y;edkEnd();
        this->origin.z-=(edk::int8)vec.origin.z;edkEnd();
        this->size.width-=(edk::int8)vec.size.width;edkEnd();
        this->size.height-=(edk::int8)vec.size.height;edkEnd();
        this->size.length-=(edk::int8)vec.size.length;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int8)n;edkEnd();
        this->origin.y-=(edk::int8)n;edkEnd();
        this->origin.z-=(edk::int8)n;edkEnd();
        this->size.width-=(edk::int8)n;edkEnd();
        this->size.height-=(edk::int8)n;edkEnd();
        this->size.length-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int8)n;edkEnd();
        this->origin.y-=(edk::int8)n;edkEnd();
        this->origin.z-=(edk::int8)n;edkEnd();
        this->size.width-=(edk::int8)n;edkEnd();
        this->size.height-=(edk::int8)n;edkEnd();
        this->size.length-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int8)n;edkEnd();
        this->origin.y-=(edk::int8)n;edkEnd();
        this->origin.z-=(edk::int8)n;edkEnd();
        this->size.width-=(edk::int8)n;edkEnd();
        this->size.height-=(edk::int8)n;edkEnd();
        this->size.length-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int8)n;edkEnd();
        this->origin.y-=(edk::int8)n;edkEnd();
        this->origin.z-=(edk::int8)n;edkEnd();
        this->size.width-=(edk::int8)n;edkEnd();
        this->size.height-=(edk::int8)n;edkEnd();
        this->size.length-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int8)n;edkEnd();
        this->origin.y-=(edk::int8)n;edkEnd();
        this->origin.z-=(edk::int8)n;edkEnd();
        this->size.width-=(edk::int8)n;edkEnd();
        this->size.height-=(edk::int8)n;edkEnd();
        this->size.length-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int8)n;edkEnd();
        this->origin.y-=(edk::int8)n;edkEnd();
        this->origin.z-=(edk::int8)n;edkEnd();
        this->size.width-=(edk::int8)n;edkEnd();
        this->size.height-=(edk::int8)n;edkEnd();
        this->size.length-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int8)n;edkEnd();
        this->origin.y-=(edk::int8)n;edkEnd();
        this->origin.z-=(edk::int8)n;edkEnd();
        this->size.width-=(edk::int8)n;edkEnd();
        this->size.height-=(edk::int8)n;edkEnd();
        this->size.length-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int8)n;edkEnd();
        this->origin.y-=(edk::int8)n;edkEnd();
        this->origin.z-=(edk::int8)n;edkEnd();
        this->size.width-=(edk::int8)n;edkEnd();
        this->size.height-=(edk::int8)n;edkEnd();
        this->size.length-=(edk::int8)n;edkEnd();
    }
    cubei8 operator*(cubei8 cube){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int8)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y*(edk::int8)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z*(edk::int8)cube.origin.z;edkEnd();
        ret.size.width=this->size.width*(edk::int8)cube.size.width;edkEnd();
        ret.size.height=this->size.height*(edk::int8)cube.size.height;edkEnd();
        ret.size.length=this->size.length*(edk::int8)cube.size.length;edkEnd();
        return ret;
    }
    cubei8 operator*(edk::int8 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int8)n;edkEnd();
        ret.size.width=this->size.width*(edk::int8)n;edkEnd();
        ret.size.height=this->size.height*(edk::int8)n;edkEnd();
        ret.size.length=this->size.length*(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator*(edk::int32 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int8)n;edkEnd();
        ret.size.width=this->size.width*(edk::int8)n;edkEnd();
        ret.size.height=this->size.height*(edk::int8)n;edkEnd();
        ret.size.length=this->size.length*(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator*(edk::int16 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int8)n;edkEnd();
        ret.size.width=this->size.width*(edk::int8)n;edkEnd();
        ret.size.height=this->size.height*(edk::int8)n;edkEnd();
        ret.size.length=this->size.length*(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator*(edk::int64 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int8)n;edkEnd();
        ret.size.width=this->size.width*(edk::int8)n;edkEnd();
        ret.size.height=this->size.height*(edk::int8)n;edkEnd();
        ret.size.length=this->size.length*(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator*(edk::uint8 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int8)n;edkEnd();
        ret.size.width=this->size.width*(edk::int8)n;edkEnd();
        ret.size.height=this->size.height*(edk::int8)n;edkEnd();
        ret.size.length=this->size.length*(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator*(edk::uint32 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int8)n;edkEnd();
        ret.size.width=this->size.width*(edk::int8)n;edkEnd();
        ret.size.height=this->size.height*(edk::int8)n;edkEnd();
        ret.size.length=this->size.length*(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator*(edk::uint16 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int8)n;edkEnd();
        ret.size.width=this->size.width*(edk::int8)n;edkEnd();
        ret.size.height=this->size.height*(edk::int8)n;edkEnd();
        ret.size.length=this->size.length*(edk::int8)n;edkEnd();
        return ret;
    }
    cubei8 operator*(edk::uint64 n){
        //
        cubei8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int8)n;edkEnd();
        ret.size.width=this->size.width*(edk::int8)n;edkEnd();
        ret.size.height=this->size.height*(edk::int8)n;edkEnd();
        ret.size.length=this->size.length*(edk::int8)n;edkEnd();
        return ret;
    }
    void operator*=(cubei8 cube){
        //
        this->origin.x*=(edk::int8)cube.origin.x;edkEnd();
        this->origin.y*=(edk::int8)cube.origin.y;edkEnd();
        this->origin.z*=(edk::int8)cube.origin.z;edkEnd();
        this->size.width*=(edk::int8)cube.size.width;edkEnd();
        this->size.height*=(edk::int8)cube.size.height;edkEnd();
        this->size.length*=(edk::int8)cube.size.length;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int8)n;edkEnd();
        this->origin.y*=(edk::int8)n;edkEnd();
        this->origin.z*=(edk::int8)n;edkEnd();
        this->size.width*=(edk::int8)n;edkEnd();
        this->size.height*=(edk::int8)n;edkEnd();
        this->size.length*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int8)n;edkEnd();
        this->origin.y*=(edk::int8)n;edkEnd();
        this->origin.z*=(edk::int8)n;edkEnd();
        this->size.width*=(edk::int8)n;edkEnd();
        this->size.height*=(edk::int8)n;edkEnd();
        this->size.length*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int8)n;edkEnd();
        this->origin.y*=(edk::int8)n;edkEnd();
        this->origin.z*=(edk::int8)n;edkEnd();
        this->size.width*=(edk::int8)n;edkEnd();
        this->size.height*=(edk::int8)n;edkEnd();
        this->size.length*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int8)n;edkEnd();
        this->origin.y*=(edk::int8)n;edkEnd();
        this->origin.z*=(edk::int8)n;edkEnd();
        this->size.width*=(edk::int8)n;edkEnd();
        this->size.height*=(edk::int8)n;edkEnd();
        this->size.length*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int8)n;edkEnd();
        this->origin.y*=(edk::int8)n;edkEnd();
        this->origin.z*=(edk::int8)n;edkEnd();
        this->size.width*=(edk::int8)n;edkEnd();
        this->size.height*=(edk::int8)n;edkEnd();
        this->size.length*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int8)n;edkEnd();
        this->origin.y*=(edk::int8)n;edkEnd();
        this->origin.z*=(edk::int8)n;edkEnd();
        this->size.width*=(edk::int8)n;edkEnd();
        this->size.height*=(edk::int8)n;edkEnd();
        this->size.length*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int8)n;edkEnd();
        this->origin.y*=(edk::int8)n;edkEnd();
        this->origin.z*=(edk::int8)n;edkEnd();
        this->size.width*=(edk::int8)n;edkEnd();
        this->size.height*=(edk::int8)n;edkEnd();
        this->size.length*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int8)n;edkEnd();
        this->origin.y*=(edk::int8)n;edkEnd();
        this->origin.z*=(edk::int8)n;edkEnd();
        this->size.width*=(edk::int8)n;edkEnd();
        this->size.height*=(edk::int8)n;edkEnd();
        this->size.length*=(edk::int8)n;edkEnd();
    }
    //
    cubei8 operator++(){
        //
        ++this->origin.x;edkEnd();
        ++this->origin.y;edkEnd();
        ++this->origin.z;edkEnd();
        ++this->size.width;edkEnd();
        ++this->size.height;edkEnd();
        ++this->size.length;edkEnd();
        return cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei8 operator++(edk::int32){
        //
        this->origin.x++;edkEnd();
        this->origin.y++;edkEnd();
        this->origin.z++;edkEnd();
        this->size.width++;edkEnd();
        this->size.height++;edkEnd();
        this->size.length++;edkEnd();
        return cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei8 operator--(){
        //
        --this->origin.x;edkEnd();
        --this->origin.y;edkEnd();
        --this->origin.z;edkEnd();
        --this->size.width;edkEnd();
        --this->size.height;edkEnd();
        --this->size.length;edkEnd();
        return cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei8 operator--(edk::int32){
        //
        this->origin.x--;edkEnd();
        this->origin.y--;edkEnd();
        this->origin.z--;edkEnd();
        this->size.width--;edkEnd();
        this->size.height--;edkEnd();
        this->size.length--;edkEnd();
        return cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei8 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);edkEnd();
    }
    cubei8 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);edkEnd();
    }
    cubei8 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);edkEnd();
    }
    cubei8 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);edkEnd();
    }
    cubei8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);edkEnd();
    }
    cubei8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);edkEnd();
    }
    cubei8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);edkEnd();
    }
    cubei8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);edkEnd();
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
        this->origin.x=(edk::int16)0;edkEnd();
        this->origin.y=(edk::int16)0;edkEnd();
        this->origin.z=(edk::int16)0;edkEnd();
        this->size.width=(edk::int16)0;edkEnd();
        this->size.height=(edk::int16)0;edkEnd();
        this->size.length=(edk::int16)0;edkEnd();
    }
    cubei16(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::int16)x;edkEnd();
        this->origin.y=(edk::int16)y;edkEnd();
        this->origin.z=(edk::int16)z;edkEnd();
        this->size.width=(edk::int16)width;edkEnd();
        this->size.height=(edk::int16)height;edkEnd();
        this->size.length=(edk::int16)length;edkEnd();
    }
    cubei16(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::int16)x;edkEnd();
        this->origin.y=(edk::int16)y;edkEnd();
        this->origin.z=(edk::int16)z;edkEnd();
        this->size.width=(edk::int16)width;edkEnd();
        this->size.height=(edk::int16)height;edkEnd();
        this->size.length=(edk::int16)length;edkEnd();
    }
    cubei16(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::int16)x;edkEnd();
        this->origin.y=(edk::int16)y;edkEnd();
        this->origin.z=(edk::int16)z;edkEnd();
        this->size.width=(edk::int16)width;edkEnd();
        this->size.height=(edk::int16)height;edkEnd();
        this->size.length=(edk::int16)length;edkEnd();
    }
    cubei16(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::int16)x;edkEnd();
        this->origin.y=(edk::int16)y;edkEnd();
        this->origin.z=(edk::int16)z;edkEnd();
        this->size.width=(edk::int16)width;edkEnd();
        this->size.height=(edk::int16)height;edkEnd();
        this->size.length=(edk::int16)length;edkEnd();
    }
    cubei16(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::int16)x;edkEnd();
        this->origin.y=(edk::int16)y;edkEnd();
        this->origin.z=(edk::int16)z;edkEnd();
        this->size.width=(edk::int16)width;edkEnd();
        this->size.height=(edk::int16)height;edkEnd();
        this->size.length=(edk::int16)length;edkEnd();
    }
    cubei16(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::int16)x;edkEnd();
        this->origin.y=(edk::int16)y;edkEnd();
        this->origin.z=(edk::int16)z;edkEnd();
        this->size.width=(edk::int16)width;edkEnd();
        this->size.height=(edk::int16)height;edkEnd();
        this->size.length=(edk::int16)length;edkEnd();
    }
    cubei16(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::int16)x;edkEnd();
        this->origin.y=(edk::int16)y;edkEnd();
        this->origin.z=(edk::int16)z;edkEnd();
        this->size.width=(edk::int16)width;edkEnd();
        this->size.height=(edk::int16)height;edkEnd();
        this->size.length=(edk::int16)length;edkEnd();
    }
    cubei16(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::int16)x;edkEnd();
        this->origin.y=(edk::int16)y;edkEnd();
        this->origin.z=(edk::int16)z;edkEnd();
        this->size.width=(edk::int16)width;edkEnd();
        this->size.height=(edk::int16)height;edkEnd();
        this->size.length=(edk::int16)length;edkEnd();
    }
    cubei16(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::int16)origin.x;edkEnd();
        this->origin.y=(edk::int16)origin.y;edkEnd();
        this->origin.z=(edk::int16)origin.z;edkEnd();
        this->size.width=(edk::int16)size.width;edkEnd();
        this->size.height=(edk::int16)size.height;edkEnd();
        this->size.length=(edk::int16)size.length;edkEnd();
    }
    cubei16(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::int16)origin.x;edkEnd();
        this->origin.y=(edk::int16)origin.y;edkEnd();
        this->origin.z=(edk::int16)origin.z;edkEnd();
        this->size.width=(edk::int16)size.width;edkEnd();
        this->size.height=(edk::int16)size.height;edkEnd();
        this->size.length=(edk::int16)size.length;edkEnd();
    }
    cubei16(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::int16)origin.x;edkEnd();
        this->origin.y=(edk::int16)origin.y;edkEnd();
        this->origin.z=(edk::int16)origin.z;edkEnd();
        this->size.width=(edk::int16)size.width;edkEnd();
        this->size.height=(edk::int16)size.height;edkEnd();
        this->size.length=(edk::int16)size.length;edkEnd();
    }
    cubei16(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::int16)origin.x;edkEnd();
        this->origin.y=(edk::int16)origin.y;edkEnd();
        this->origin.z=(edk::int16)origin.z;edkEnd();
        this->size.width=(edk::int16)size.width;edkEnd();
        this->size.height=(edk::int16)size.height;edkEnd();
        this->size.length=(edk::int16)size.length;edkEnd();
    }
    cubei16(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::int16)origin.x;edkEnd();
        this->origin.y=(edk::int16)origin.y;edkEnd();
        this->origin.z=(edk::int16)origin.z;edkEnd();
        this->size.width=(edk::int16)size.width;edkEnd();
        this->size.height=(edk::int16)size.height;edkEnd();
        this->size.length=(edk::int16)size.length;edkEnd();
    }
    cubei16(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::int16)origin.x;edkEnd();
        this->origin.y=(edk::int16)origin.y;edkEnd();
        this->origin.z=(edk::int16)origin.z;edkEnd();
        this->size.width=(edk::int16)size.width;edkEnd();
        this->size.height=(edk::int16)size.height;edkEnd();
        this->size.length=(edk::int16)size.length;edkEnd();
    }
    cubei16(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::int16)origin.x;edkEnd();
        this->origin.y=(edk::int16)origin.y;edkEnd();
        this->origin.z=(edk::int16)origin.z;edkEnd();
        this->size.width=(edk::int16)size.width;edkEnd();
        this->size.height=(edk::int16)size.height;edkEnd();
        this->size.length=(edk::int16)size.length;edkEnd();
    }
    cubei16(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::int16)origin.x;edkEnd();
        this->origin.y=(edk::int16)origin.y;edkEnd();
        this->origin.z=(edk::int16)origin.z;edkEnd();
        this->size.width=(edk::int16)size.width;edkEnd();
        this->size.height=(edk::int16)size.height;edkEnd();
        this->size.length=(edk::int16)size.length;edkEnd();
    }

    //operators
    cubei16 operator=(cubei16 cube){
        //
        this->origin.x=(edk::int16)cube.origin.x;edkEnd();
        this->origin.y=(edk::int16)cube.origin.y;edkEnd();
        this->origin.z=(edk::int16)cube.origin.z;edkEnd();
        this->size.width=(edk::int16)cube.size.width;edkEnd();
        this->size.height=(edk::int16)cube.size.height;edkEnd();
        this->size.length=(edk::int16)cube.size.length;edkEnd();
        return *this;edkEnd();
    }
    cubei16 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int16)n;edkEnd();
        this->origin.y=(edk::int16)n;edkEnd();
        this->origin.z=(edk::int16)n;edkEnd();
        this->size.width=(edk::int16)n;edkEnd();
        this->size.height=(edk::int16)n;edkEnd();
        this->size.length=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    cubei16 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int16)n;edkEnd();
        this->origin.y=(edk::int16)n;edkEnd();
        this->origin.z=(edk::int16)n;edkEnd();
        this->size.width=(edk::int16)n;edkEnd();
        this->size.height=(edk::int16)n;edkEnd();
        this->size.length=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    cubei16 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int16)n;edkEnd();
        this->origin.y=(edk::int16)n;edkEnd();
        this->origin.z=(edk::int16)n;edkEnd();
        this->size.width=(edk::int16)n;edkEnd();
        this->size.height=(edk::int16)n;edkEnd();
        this->size.length=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    cubei16 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int16)n;edkEnd();
        this->origin.y=(edk::int16)n;edkEnd();
        this->origin.z=(edk::int16)n;edkEnd();
        this->size.width=(edk::int16)n;edkEnd();
        this->size.height=(edk::int16)n;edkEnd();
        this->size.length=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    cubei16 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int16)n;edkEnd();
        this->origin.y=(edk::int16)n;edkEnd();
        this->origin.z=(edk::int16)n;edkEnd();
        this->size.width=(edk::int16)n;edkEnd();
        this->size.height=(edk::int16)n;edkEnd();
        this->size.length=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    cubei16 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int16)n;edkEnd();
        this->origin.y=(edk::int16)n;edkEnd();
        this->origin.z=(edk::int16)n;edkEnd();
        this->size.width=(edk::int16)n;edkEnd();
        this->size.height=(edk::int16)n;edkEnd();
        this->size.length=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    cubei16 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int16)n;edkEnd();
        this->origin.y=(edk::int16)n;edkEnd();
        this->origin.z=(edk::int16)n;edkEnd();
        this->size.width=(edk::int16)n;edkEnd();
        this->size.height=(edk::int16)n;edkEnd();
        this->size.length=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    cubei16 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int16)n;edkEnd();
        this->origin.y=(edk::int16)n;edkEnd();
        this->origin.z=(edk::int16)n;edkEnd();
        this->size.width=(edk::int16)n;edkEnd();
        this->size.height=(edk::int16)n;edkEnd();
        this->size.length=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }

    bool operator==(cubei16 cube){
        //
        return (this->origin.x==(edk::int16)cube.origin.x
                &&this->origin.y==(edk::int16)cube.origin.y
                &&this->origin.z==(edk::int16)cube.origin.z
                &&this->size.width==(edk::int16)cube.size.width
                &&this->size.height==(edk::int16)cube.size.height
                &&this->size.length==(edk::int16)cube.size.length
                );edkEnd();
    }
    bool operator!=(cubei16 cube){
        //
        return (this->origin.x!=(edk::int16)cube.origin.x
                ||this->origin.y!=(edk::int16)cube.origin.y
                ||this->origin.z!=(edk::int16)cube.origin.z
                ||this->size.width!=(edk::int16)cube.size.width
                ||this->size.height!=(edk::int16)cube.size.height
                ||this->size.length!=(edk::int16)cube.size.length
                );edkEnd();
    }
    cubei16 operator+(cubei16 cube){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int16)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y+(edk::int16)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z+(edk::int16)cube.origin.z;edkEnd();
        ret.size.width=this->size.width+(edk::int16)cube.size.width;edkEnd();
        ret.size.height=this->size.height+(edk::int16)cube.size.height;edkEnd();
        ret.size.length=this->size.length+(edk::int16)cube.size.length;edkEnd();
        return ret;
    }
    cubei16 operator+(edk::int8 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int16)n;edkEnd();
        ret.size.width=this->size.width+(edk::int16)n;edkEnd();
        ret.size.height=this->size.height+(edk::int16)n;edkEnd();
        ret.size.length=this->size.length+(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator+(edk::int32 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int16)n;edkEnd();
        ret.size.width=this->size.width+(edk::int16)n;edkEnd();
        ret.size.height=this->size.height+(edk::int16)n;edkEnd();
        ret.size.length=this->size.length+(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator+(edk::int16 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int16)n;edkEnd();
        ret.size.width=this->size.width+(edk::int16)n;edkEnd();
        ret.size.height=this->size.height+(edk::int16)n;edkEnd();
        ret.size.length=this->size.length+(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator+(edk::int64 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int16)n;edkEnd();
        ret.size.width=this->size.width+(edk::int16)n;edkEnd();
        ret.size.height=this->size.height+(edk::int16)n;edkEnd();
        ret.size.length=this->size.length+(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator+(edk::uint8 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int16)n;edkEnd();
        ret.size.width=this->size.width+(edk::int16)n;edkEnd();
        ret.size.height=this->size.height+(edk::int16)n;edkEnd();
        ret.size.length=this->size.length+(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator+(edk::uint32 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int16)n;edkEnd();
        ret.size.width=this->size.width+(edk::int16)n;edkEnd();
        ret.size.height=this->size.height+(edk::int16)n;edkEnd();
        ret.size.length=this->size.length+(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator+(edk::uint16 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int16)n;edkEnd();
        ret.size.width=this->size.width+(edk::int16)n;edkEnd();
        ret.size.height=this->size.height+(edk::int16)n;edkEnd();
        ret.size.length=this->size.length+(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator+(edk::uint64 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int16)n;edkEnd();
        ret.size.width=this->size.width+(edk::int16)n;edkEnd();
        ret.size.height=this->size.height+(edk::int16)n;edkEnd();
        ret.size.length=this->size.length+(edk::int16)n;edkEnd();
        return ret;
    }
    void operator+=(cubei16 cube){
        //
        this->origin.x+=(edk::int16)cube.origin.x;edkEnd();
        this->origin.y+=(edk::int16)cube.origin.y;edkEnd();
        this->origin.z+=(edk::int16)cube.origin.z;edkEnd();
        this->size.width+=(edk::int16)cube.size.width;edkEnd();
        this->size.height+=(edk::int16)cube.size.height;edkEnd();
        this->size.length+=(edk::int16)cube.size.length;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int16)n;edkEnd();
        this->origin.y+=(edk::int16)n;edkEnd();
        this->origin.z+=(edk::int16)n;edkEnd();
        this->size.width+=(edk::int16)n;edkEnd();
        this->size.height+=(edk::int16)n;edkEnd();
        this->size.length+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int16)n;edkEnd();
        this->origin.y+=(edk::int16)n;edkEnd();
        this->origin.z+=(edk::int16)n;edkEnd();
        this->size.width+=(edk::int16)n;edkEnd();
        this->size.height+=(edk::int16)n;edkEnd();
        this->size.length+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int16)n;edkEnd();
        this->origin.y+=(edk::int16)n;edkEnd();
        this->origin.z+=(edk::int16)n;edkEnd();
        this->size.width+=(edk::int16)n;edkEnd();
        this->size.height+=(edk::int16)n;edkEnd();
        this->size.length+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int16)n;edkEnd();
        this->origin.y+=(edk::int16)n;edkEnd();
        this->origin.z+=(edk::int16)n;edkEnd();
        this->size.width+=(edk::int16)n;edkEnd();
        this->size.height+=(edk::int16)n;edkEnd();
        this->size.length+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int16)n;edkEnd();
        this->origin.y+=(edk::int16)n;edkEnd();
        this->origin.z+=(edk::int16)n;edkEnd();
        this->size.width+=(edk::int16)n;edkEnd();
        this->size.height+=(edk::int16)n;edkEnd();
        this->size.length+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int16)n;edkEnd();
        this->origin.y+=(edk::int16)n;edkEnd();
        this->origin.z+=(edk::int16)n;edkEnd();
        this->size.width+=(edk::int16)n;edkEnd();
        this->size.height+=(edk::int16)n;edkEnd();
        this->size.length+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int16)n;edkEnd();
        this->origin.y+=(edk::int16)n;edkEnd();
        this->origin.z+=(edk::int16)n;edkEnd();
        this->size.width+=(edk::int16)n;edkEnd();
        this->size.height+=(edk::int16)n;edkEnd();
        this->size.length+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int16)n;edkEnd();
        this->origin.y+=(edk::int16)n;edkEnd();
        this->origin.z+=(edk::int16)n;edkEnd();
        this->size.width+=(edk::int16)n;edkEnd();
        this->size.height+=(edk::int16)n;edkEnd();
        this->size.length+=(edk::int16)n;edkEnd();
    }
    cubei16 operator-(cubei16 cube){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int16)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y-(edk::int16)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z-(edk::int16)cube.origin.z;edkEnd();
        ret.size.width=this->size.width-(edk::int16)cube.size.width;edkEnd();
        ret.size.height=this->size.height-(edk::int16)cube.size.height;edkEnd();
        ret.size.length=this->size.length-(edk::int16)cube.size.length;edkEnd();
        return ret;
    }
    cubei16 operator-(edk::int8 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int16)n;edkEnd();
        ret.size.width=this->size.width-(edk::int16)n;edkEnd();
        ret.size.height=this->size.height-(edk::int16)n;edkEnd();
        ret.size.length=this->size.length-(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator-(edk::int32 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int16)n;edkEnd();
        ret.size.width=this->size.width-(edk::int16)n;edkEnd();
        ret.size.height=this->size.height-(edk::int16)n;edkEnd();
        ret.size.length=this->size.length-(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator-(edk::int16 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int16)n;edkEnd();
        ret.size.width=this->size.width-(edk::int16)n;edkEnd();
        ret.size.height=this->size.height-(edk::int16)n;edkEnd();
        ret.size.length=this->size.length-(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator-(edk::int64 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int16)n;edkEnd();
        ret.size.width=this->size.width-(edk::int16)n;edkEnd();
        ret.size.height=this->size.height-(edk::int16)n;edkEnd();
        ret.size.length=this->size.length-(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator-(edk::uint8 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int16)n;edkEnd();
        ret.size.width=this->size.width-(edk::int16)n;edkEnd();
        ret.size.height=this->size.height-(edk::int16)n;edkEnd();
        ret.size.length=this->size.length-(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator-(edk::uint32 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int16)n;edkEnd();
        ret.size.width=this->size.width-(edk::int16)n;edkEnd();
        ret.size.height=this->size.height-(edk::int16)n;edkEnd();
        ret.size.length=this->size.length-(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator-(edk::uint16 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int16)n;edkEnd();
        ret.size.width=this->size.width-(edk::int16)n;edkEnd();
        ret.size.height=this->size.height-(edk::int16)n;edkEnd();
        ret.size.length=this->size.length-(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator-(edk::uint64 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int16)n;edkEnd();
        ret.size.width=this->size.width-(edk::int16)n;edkEnd();
        ret.size.height=this->size.height-(edk::int16)n;edkEnd();
        ret.size.length=this->size.length-(edk::int16)n;edkEnd();
        return ret;
    }
    void operator-=(cubei16 vec){
        //
        this->origin.x-=(edk::int16)vec.origin.x;edkEnd();
        this->origin.y-=(edk::int16)vec.origin.y;edkEnd();
        this->origin.z-=(edk::int16)vec.origin.z;edkEnd();
        this->size.width-=(edk::int16)vec.size.width;edkEnd();
        this->size.height-=(edk::int16)vec.size.height;edkEnd();
        this->size.length-=(edk::int16)vec.size.length;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int16)n;edkEnd();
        this->origin.y-=(edk::int16)n;edkEnd();
        this->origin.z-=(edk::int16)n;edkEnd();
        this->size.width-=(edk::int16)n;edkEnd();
        this->size.height-=(edk::int16)n;edkEnd();
        this->size.length-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int16)n;edkEnd();
        this->origin.y-=(edk::int16)n;edkEnd();
        this->origin.z-=(edk::int16)n;edkEnd();
        this->size.width-=(edk::int16)n;edkEnd();
        this->size.height-=(edk::int16)n;edkEnd();
        this->size.length-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int16)n;edkEnd();
        this->origin.y-=(edk::int16)n;edkEnd();
        this->origin.z-=(edk::int16)n;edkEnd();
        this->size.width-=(edk::int16)n;edkEnd();
        this->size.height-=(edk::int16)n;edkEnd();
        this->size.length-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int16)n;edkEnd();
        this->origin.y-=(edk::int16)n;edkEnd();
        this->origin.z-=(edk::int16)n;edkEnd();
        this->size.width-=(edk::int16)n;edkEnd();
        this->size.height-=(edk::int16)n;edkEnd();
        this->size.length-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int16)n;edkEnd();
        this->origin.y-=(edk::int16)n;edkEnd();
        this->origin.z-=(edk::int16)n;edkEnd();
        this->size.width-=(edk::int16)n;edkEnd();
        this->size.height-=(edk::int16)n;edkEnd();
        this->size.length-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int16)n;edkEnd();
        this->origin.y-=(edk::int16)n;edkEnd();
        this->origin.z-=(edk::int16)n;edkEnd();
        this->size.width-=(edk::int16)n;edkEnd();
        this->size.height-=(edk::int16)n;edkEnd();
        this->size.length-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int16)n;edkEnd();
        this->origin.y-=(edk::int16)n;edkEnd();
        this->origin.z-=(edk::int16)n;edkEnd();
        this->size.width-=(edk::int16)n;edkEnd();
        this->size.height-=(edk::int16)n;edkEnd();
        this->size.length-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int16)n;edkEnd();
        this->origin.y-=(edk::int16)n;edkEnd();
        this->origin.z-=(edk::int16)n;edkEnd();
        this->size.width-=(edk::int16)n;edkEnd();
        this->size.height-=(edk::int16)n;edkEnd();
        this->size.length-=(edk::int16)n;edkEnd();
    }
    cubei16 operator*(cubei16 cube){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int16)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y*(edk::int16)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z*(edk::int16)cube.origin.z;edkEnd();
        ret.size.width=this->size.width*(edk::int16)cube.size.width;edkEnd();
        ret.size.height=this->size.height*(edk::int16)cube.size.height;edkEnd();
        ret.size.length=this->size.length*(edk::int16)cube.size.length;edkEnd();
        return ret;
    }
    cubei16 operator*(edk::int8 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int16)n;edkEnd();
        ret.size.width=this->size.width*(edk::int16)n;edkEnd();
        ret.size.height=this->size.height*(edk::int16)n;edkEnd();
        ret.size.length=this->size.length*(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator*(edk::int32 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int16)n;edkEnd();
        ret.size.width=this->size.width*(edk::int16)n;edkEnd();
        ret.size.height=this->size.height*(edk::int16)n;edkEnd();
        ret.size.length=this->size.length*(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator*(edk::int16 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int16)n;edkEnd();
        ret.size.width=this->size.width*(edk::int16)n;edkEnd();
        ret.size.height=this->size.height*(edk::int16)n;edkEnd();
        ret.size.length=this->size.length*(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator*(edk::int64 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int16)n;edkEnd();
        ret.size.width=this->size.width*(edk::int16)n;edkEnd();
        ret.size.height=this->size.height*(edk::int16)n;edkEnd();
        ret.size.length=this->size.length*(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator*(edk::uint8 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int16)n;edkEnd();
        ret.size.width=this->size.width*(edk::int16)n;edkEnd();
        ret.size.height=this->size.height*(edk::int16)n;edkEnd();
        ret.size.length=this->size.length*(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator*(edk::uint32 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int16)n;edkEnd();
        ret.size.width=this->size.width*(edk::int16)n;edkEnd();
        ret.size.height=this->size.height*(edk::int16)n;edkEnd();
        ret.size.length=this->size.length*(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator*(edk::uint16 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int16)n;edkEnd();
        ret.size.width=this->size.width*(edk::int16)n;edkEnd();
        ret.size.height=this->size.height*(edk::int16)n;edkEnd();
        ret.size.length=this->size.length*(edk::int16)n;edkEnd();
        return ret;
    }
    cubei16 operator*(edk::uint64 n){
        //
        cubei16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int16)n;edkEnd();
        ret.size.width=this->size.width*(edk::int16)n;edkEnd();
        ret.size.height=this->size.height*(edk::int16)n;edkEnd();
        ret.size.length=this->size.length*(edk::int16)n;edkEnd();
        return ret;
    }
    void operator*=(cubei16 cube){
        //
        this->origin.x*=(edk::int16)cube.origin.x;edkEnd();
        this->origin.y*=(edk::int16)cube.origin.y;edkEnd();
        this->origin.z*=(edk::int16)cube.origin.z;edkEnd();
        this->size.width*=(edk::int16)cube.size.width;edkEnd();
        this->size.height*=(edk::int16)cube.size.height;edkEnd();
        this->size.length*=(edk::int16)cube.size.length;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int16)n;edkEnd();
        this->origin.y*=(edk::int16)n;edkEnd();
        this->origin.z*=(edk::int16)n;edkEnd();
        this->size.width*=(edk::int16)n;edkEnd();
        this->size.height*=(edk::int16)n;edkEnd();
        this->size.length*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int16)n;edkEnd();
        this->origin.y*=(edk::int16)n;edkEnd();
        this->origin.z*=(edk::int16)n;edkEnd();
        this->size.width*=(edk::int16)n;edkEnd();
        this->size.height*=(edk::int16)n;edkEnd();
        this->size.length*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int16)n;edkEnd();
        this->origin.y*=(edk::int16)n;edkEnd();
        this->origin.z*=(edk::int16)n;edkEnd();
        this->size.width*=(edk::int16)n;edkEnd();
        this->size.height*=(edk::int16)n;edkEnd();
        this->size.length*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int16)n;edkEnd();
        this->origin.y*=(edk::int16)n;edkEnd();
        this->origin.z*=(edk::int16)n;edkEnd();
        this->size.width*=(edk::int16)n;edkEnd();
        this->size.height*=(edk::int16)n;edkEnd();
        this->size.length*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int16)n;edkEnd();
        this->origin.y*=(edk::int16)n;edkEnd();
        this->origin.z*=(edk::int16)n;edkEnd();
        this->size.width*=(edk::int16)n;edkEnd();
        this->size.height*=(edk::int16)n;edkEnd();
        this->size.length*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int16)n;edkEnd();
        this->origin.y*=(edk::int16)n;edkEnd();
        this->origin.z*=(edk::int16)n;edkEnd();
        this->size.width*=(edk::int16)n;edkEnd();
        this->size.height*=(edk::int16)n;edkEnd();
        this->size.length*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int16)n;edkEnd();
        this->origin.y*=(edk::int16)n;edkEnd();
        this->origin.z*=(edk::int16)n;edkEnd();
        this->size.width*=(edk::int16)n;edkEnd();
        this->size.height*=(edk::int16)n;edkEnd();
        this->size.length*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int16)n;edkEnd();
        this->origin.y*=(edk::int16)n;edkEnd();
        this->origin.z*=(edk::int16)n;edkEnd();
        this->size.width*=(edk::int16)n;edkEnd();
        this->size.height*=(edk::int16)n;edkEnd();
        this->size.length*=(edk::int16)n;edkEnd();
    }
    //
    cubei16 operator++(){
        //
        ++this->origin.x;edkEnd();
        ++this->origin.y;edkEnd();
        ++this->origin.z;edkEnd();
        ++this->size.width;edkEnd();
        ++this->size.height;edkEnd();
        ++this->size.length;edkEnd();
        return cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei16 operator++(edk::int32){
        //
        this->origin.x++;edkEnd();
        this->origin.y++;edkEnd();
        this->origin.z++;edkEnd();
        this->size.width++;edkEnd();
        this->size.height++;edkEnd();
        this->size.length++;edkEnd();
        return cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei16 operator--(){
        //
        --this->origin.x;edkEnd();
        --this->origin.y;edkEnd();
        --this->origin.z;edkEnd();
        --this->size.width;edkEnd();
        --this->size.height;edkEnd();
        --this->size.length;edkEnd();
        return cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei16 operator--(edk::int32){
        //
        this->origin.x--;edkEnd();
        this->origin.y--;edkEnd();
        this->origin.z--;edkEnd();
        this->size.width--;edkEnd();
        this->size.height--;edkEnd();
        this->size.length--;edkEnd();
        return cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei16 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);edkEnd();
    }
    cubei16 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);edkEnd();
    }
    cubei16 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);edkEnd();
    }
    cubei16 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);edkEnd();
    }
    cubei16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);edkEnd();
    }
    cubei16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);edkEnd();
    }
    cubei16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);edkEnd();
    }
    cubei16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);edkEnd();
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
        this->origin.x=(edk::int32)0;edkEnd();
        this->origin.y=(edk::int32)0;edkEnd();
        this->origin.z=(edk::int32)0;edkEnd();
        this->size.width=(edk::int32)0;edkEnd();
        this->size.height=(edk::int32)0;edkEnd();
        this->size.length=(edk::int32)0;edkEnd();
    }
    cubei32(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::int32)x;edkEnd();
        this->origin.y=(edk::int32)y;edkEnd();
        this->origin.z=(edk::int32)z;edkEnd();
        this->size.width=(edk::int32)width;edkEnd();
        this->size.height=(edk::int32)height;edkEnd();
        this->size.length=(edk::int32)length;edkEnd();
    }
    cubei32(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::int32)x;edkEnd();
        this->origin.y=(edk::int32)y;edkEnd();
        this->origin.z=(edk::int32)z;edkEnd();
        this->size.width=(edk::int32)width;edkEnd();
        this->size.height=(edk::int32)height;edkEnd();
        this->size.length=(edk::int32)length;edkEnd();
    }
    cubei32(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::int32)x;edkEnd();
        this->origin.y=(edk::int32)y;edkEnd();
        this->origin.z=(edk::int32)z;edkEnd();
        this->size.width=(edk::int32)width;edkEnd();
        this->size.height=(edk::int32)height;edkEnd();
        this->size.length=(edk::int32)length;edkEnd();
    }
    cubei32(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::int32)x;edkEnd();
        this->origin.y=(edk::int32)y;edkEnd();
        this->origin.z=(edk::int32)z;edkEnd();
        this->size.width=(edk::int32)width;edkEnd();
        this->size.height=(edk::int32)height;edkEnd();
        this->size.length=(edk::int32)length;edkEnd();
    }
    cubei32(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::int32)x;edkEnd();
        this->origin.y=(edk::int32)y;edkEnd();
        this->origin.z=(edk::int32)z;edkEnd();
        this->size.width=(edk::int32)width;edkEnd();
        this->size.height=(edk::int32)height;edkEnd();
        this->size.length=(edk::int32)length;edkEnd();
    }
    cubei32(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::int32)x;edkEnd();
        this->origin.y=(edk::int32)y;edkEnd();
        this->origin.z=(edk::int32)z;edkEnd();
        this->size.width=(edk::int32)width;edkEnd();
        this->size.height=(edk::int32)height;edkEnd();
        this->size.length=(edk::int32)length;edkEnd();
    }
    cubei32(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::int32)x;edkEnd();
        this->origin.y=(edk::int32)y;edkEnd();
        this->origin.z=(edk::int32)z;edkEnd();
        this->size.width=(edk::int32)width;edkEnd();
        this->size.height=(edk::int32)height;edkEnd();
        this->size.length=(edk::int32)length;edkEnd();
    }
    cubei32(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::int32)x;edkEnd();
        this->origin.y=(edk::int32)y;edkEnd();
        this->origin.z=(edk::int32)z;edkEnd();
        this->size.width=(edk::int32)width;edkEnd();
        this->size.height=(edk::int32)height;edkEnd();
        this->size.length=(edk::int32)length;edkEnd();
    }
    cubei32(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::int32)origin.x;edkEnd();
        this->origin.y=(edk::int32)origin.y;edkEnd();
        this->origin.z=(edk::int32)origin.z;edkEnd();
        this->size.width=(edk::int32)size.width;edkEnd();
        this->size.height=(edk::int32)size.height;edkEnd();
        this->size.length=(edk::int32)size.length;edkEnd();
    }
    cubei32(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::int32)origin.x;edkEnd();
        this->origin.y=(edk::int32)origin.y;edkEnd();
        this->origin.z=(edk::int32)origin.z;edkEnd();
        this->size.width=(edk::int32)size.width;edkEnd();
        this->size.height=(edk::int32)size.height;edkEnd();
        this->size.length=(edk::int32)size.length;edkEnd();
    }
    cubei32(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::int32)origin.x;edkEnd();
        this->origin.y=(edk::int32)origin.y;edkEnd();
        this->origin.z=(edk::int32)origin.z;edkEnd();
        this->size.width=(edk::int32)size.width;edkEnd();
        this->size.height=(edk::int32)size.height;edkEnd();
        this->size.length=(edk::int32)size.length;edkEnd();
    }
    cubei32(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::int32)origin.x;edkEnd();
        this->origin.y=(edk::int32)origin.y;edkEnd();
        this->origin.z=(edk::int32)origin.z;edkEnd();
        this->size.width=(edk::int32)size.width;edkEnd();
        this->size.height=(edk::int32)size.height;edkEnd();
        this->size.length=(edk::int32)size.length;edkEnd();
    }
    cubei32(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::int32)origin.x;edkEnd();
        this->origin.y=(edk::int32)origin.y;edkEnd();
        this->origin.z=(edk::int32)origin.z;edkEnd();
        this->size.width=(edk::int32)size.width;edkEnd();
        this->size.height=(edk::int32)size.height;edkEnd();
        this->size.length=(edk::int32)size.length;edkEnd();
    }
    cubei32(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::int32)origin.x;edkEnd();
        this->origin.y=(edk::int32)origin.y;edkEnd();
        this->origin.z=(edk::int32)origin.z;edkEnd();
        this->size.width=(edk::int32)size.width;edkEnd();
        this->size.height=(edk::int32)size.height;edkEnd();
        this->size.length=(edk::int32)size.length;edkEnd();
    }
    cubei32(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::int32)origin.x;edkEnd();
        this->origin.y=(edk::int32)origin.y;edkEnd();
        this->origin.z=(edk::int32)origin.z;edkEnd();
        this->size.width=(edk::int32)size.width;edkEnd();
        this->size.height=(edk::int32)size.height;edkEnd();
        this->size.length=(edk::int32)size.length;edkEnd();
    }
    cubei32(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::int32)origin.x;edkEnd();
        this->origin.y=(edk::int32)origin.y;edkEnd();
        this->origin.z=(edk::int32)origin.z;edkEnd();
        this->size.width=(edk::int32)size.width;edkEnd();
        this->size.height=(edk::int32)size.height;edkEnd();
        this->size.length=(edk::int32)size.length;edkEnd();
    }

    //operators
    cubei32 operator=(cubei32 cube){
        //
        this->origin.x=(edk::int32)cube.origin.x;edkEnd();
        this->origin.y=(edk::int32)cube.origin.y;edkEnd();
        this->origin.z=(edk::int32)cube.origin.z;edkEnd();
        this->size.width=(edk::int32)cube.size.width;edkEnd();
        this->size.height=(edk::int32)cube.size.height;edkEnd();
        this->size.length=(edk::int32)cube.size.length;edkEnd();
        return *this;edkEnd();
    }
    cubei32 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int32)n;edkEnd();
        this->origin.y=(edk::int32)n;edkEnd();
        this->origin.z=(edk::int32)n;edkEnd();
        this->size.width=(edk::int32)n;edkEnd();
        this->size.height=(edk::int32)n;edkEnd();
        this->size.length=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    cubei32 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int32)n;edkEnd();
        this->origin.y=(edk::int32)n;edkEnd();
        this->origin.z=(edk::int32)n;edkEnd();
        this->size.width=(edk::int32)n;edkEnd();
        this->size.height=(edk::int32)n;edkEnd();
        this->size.length=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    cubei32 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int32)n;edkEnd();
        this->origin.y=(edk::int32)n;edkEnd();
        this->origin.z=(edk::int32)n;edkEnd();
        this->size.width=(edk::int32)n;edkEnd();
        this->size.height=(edk::int32)n;edkEnd();
        this->size.length=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    cubei32 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int32)n;edkEnd();
        this->origin.y=(edk::int32)n;edkEnd();
        this->origin.z=(edk::int32)n;edkEnd();
        this->size.width=(edk::int32)n;edkEnd();
        this->size.height=(edk::int32)n;edkEnd();
        this->size.length=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    cubei32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int32)n;edkEnd();
        this->origin.y=(edk::int32)n;edkEnd();
        this->origin.z=(edk::int32)n;edkEnd();
        this->size.width=(edk::int32)n;edkEnd();
        this->size.height=(edk::int32)n;edkEnd();
        this->size.length=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    cubei32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int32)n;edkEnd();
        this->origin.y=(edk::int32)n;edkEnd();
        this->origin.z=(edk::int32)n;edkEnd();
        this->size.width=(edk::int32)n;edkEnd();
        this->size.height=(edk::int32)n;edkEnd();
        this->size.length=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    cubei32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int32)n;edkEnd();
        this->origin.y=(edk::int32)n;edkEnd();
        this->origin.z=(edk::int32)n;edkEnd();
        this->size.width=(edk::int32)n;edkEnd();
        this->size.height=(edk::int32)n;edkEnd();
        this->size.length=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    cubei32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int32)n;edkEnd();
        this->origin.y=(edk::int32)n;edkEnd();
        this->origin.z=(edk::int32)n;edkEnd();
        this->size.width=(edk::int32)n;edkEnd();
        this->size.height=(edk::int32)n;edkEnd();
        this->size.length=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }

    bool operator==(cubei32 cube){
        //
        return (this->origin.x==(edk::int32)cube.origin.x
                &&this->origin.y==(edk::int32)cube.origin.y
                &&this->origin.z==(edk::int32)cube.origin.z
                &&this->size.width==(edk::int32)cube.size.width
                &&this->size.height==(edk::int32)cube.size.height
                &&this->size.length==(edk::int32)cube.size.length
                );edkEnd();
    }
    bool operator!=(cubei32 cube){
        //
        return (this->origin.x!=(edk::int32)cube.origin.x
                ||this->origin.y!=(edk::int32)cube.origin.y
                ||this->origin.z!=(edk::int32)cube.origin.z
                ||this->size.width!=(edk::int32)cube.size.width
                ||this->size.height!=(edk::int32)cube.size.height
                ||this->size.length!=(edk::int32)cube.size.length
                );edkEnd();
    }
    cubei32 operator+(cubei32 cube){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int32)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y+(edk::int32)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z+(edk::int32)cube.origin.z;edkEnd();
        ret.size.width=this->size.width+(edk::int32)cube.size.width;edkEnd();
        ret.size.height=this->size.height+(edk::int32)cube.size.height;edkEnd();
        ret.size.length=this->size.length+(edk::int32)cube.size.length;edkEnd();
        return ret;
    }
    cubei32 operator+(edk::int8 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int32)n;edkEnd();
        ret.size.width=this->size.width+(edk::int32)n;edkEnd();
        ret.size.height=this->size.height+(edk::int32)n;edkEnd();
        ret.size.length=this->size.length+(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator+(edk::int32 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int32)n;edkEnd();
        ret.size.width=this->size.width+(edk::int32)n;edkEnd();
        ret.size.height=this->size.height+(edk::int32)n;edkEnd();
        ret.size.length=this->size.length+(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator+(edk::int16 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int32)n;edkEnd();
        ret.size.width=this->size.width+(edk::int32)n;edkEnd();
        ret.size.height=this->size.height+(edk::int32)n;edkEnd();
        ret.size.length=this->size.length+(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator+(edk::int64 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int32)n;edkEnd();
        ret.size.width=this->size.width+(edk::int32)n;edkEnd();
        ret.size.height=this->size.height+(edk::int32)n;edkEnd();
        ret.size.length=this->size.length+(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator+(edk::uint8 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int32)n;edkEnd();
        ret.size.width=this->size.width+(edk::int32)n;edkEnd();
        ret.size.height=this->size.height+(edk::int32)n;edkEnd();
        ret.size.length=this->size.length+(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator+(edk::uint32 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int32)n;edkEnd();
        ret.size.width=this->size.width+(edk::int32)n;edkEnd();
        ret.size.height=this->size.height+(edk::int32)n;edkEnd();
        ret.size.length=this->size.length+(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator+(edk::uint16 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int32)n;edkEnd();
        ret.size.width=this->size.width+(edk::int32)n;edkEnd();
        ret.size.height=this->size.height+(edk::int32)n;edkEnd();
        ret.size.length=this->size.length+(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator+(edk::uint64 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int32)n;edkEnd();
        ret.size.width=this->size.width+(edk::int32)n;edkEnd();
        ret.size.height=this->size.height+(edk::int32)n;edkEnd();
        ret.size.length=this->size.length+(edk::int32)n;edkEnd();
        return ret;
    }
    void operator+=(cubei32 cube){
        //
        this->origin.x+=(edk::int32)cube.origin.x;edkEnd();
        this->origin.y+=(edk::int32)cube.origin.y;edkEnd();
        this->origin.z+=(edk::int32)cube.origin.z;edkEnd();
        this->size.width+=(edk::int32)cube.size.width;edkEnd();
        this->size.height+=(edk::int32)cube.size.height;edkEnd();
        this->size.length+=(edk::int32)cube.size.length;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int32)n;edkEnd();
        this->origin.y+=(edk::int32)n;edkEnd();
        this->origin.z+=(edk::int32)n;edkEnd();
        this->size.width+=(edk::int32)n;edkEnd();
        this->size.height+=(edk::int32)n;edkEnd();
        this->size.length+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int32)n;edkEnd();
        this->origin.y+=(edk::int32)n;edkEnd();
        this->origin.z+=(edk::int32)n;edkEnd();
        this->size.width+=(edk::int32)n;edkEnd();
        this->size.height+=(edk::int32)n;edkEnd();
        this->size.length+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int32)n;edkEnd();
        this->origin.y+=(edk::int32)n;edkEnd();
        this->origin.z+=(edk::int32)n;edkEnd();
        this->size.width+=(edk::int32)n;edkEnd();
        this->size.height+=(edk::int32)n;edkEnd();
        this->size.length+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int32)n;edkEnd();
        this->origin.y+=(edk::int32)n;edkEnd();
        this->origin.z+=(edk::int32)n;edkEnd();
        this->size.width+=(edk::int32)n;edkEnd();
        this->size.height+=(edk::int32)n;edkEnd();
        this->size.length+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int32)n;edkEnd();
        this->origin.y+=(edk::int32)n;edkEnd();
        this->origin.z+=(edk::int32)n;edkEnd();
        this->size.width+=(edk::int32)n;edkEnd();
        this->size.height+=(edk::int32)n;edkEnd();
        this->size.length+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int32)n;edkEnd();
        this->origin.y+=(edk::int32)n;edkEnd();
        this->origin.z+=(edk::int32)n;edkEnd();
        this->size.width+=(edk::int32)n;edkEnd();
        this->size.height+=(edk::int32)n;edkEnd();
        this->size.length+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int32)n;edkEnd();
        this->origin.y+=(edk::int32)n;edkEnd();
        this->origin.z+=(edk::int32)n;edkEnd();
        this->size.width+=(edk::int32)n;edkEnd();
        this->size.height+=(edk::int32)n;edkEnd();
        this->size.length+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int32)n;edkEnd();
        this->origin.y+=(edk::int32)n;edkEnd();
        this->origin.z+=(edk::int32)n;edkEnd();
        this->size.width+=(edk::int32)n;edkEnd();
        this->size.height+=(edk::int32)n;edkEnd();
        this->size.length+=(edk::int32)n;edkEnd();
    }
    cubei32 operator-(cubei32 cube){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int32)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y-(edk::int32)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z-(edk::int32)cube.origin.z;edkEnd();
        ret.size.width=this->size.width-(edk::int32)cube.size.width;edkEnd();
        ret.size.height=this->size.height-(edk::int32)cube.size.height;edkEnd();
        ret.size.length=this->size.length-(edk::int32)cube.size.length;edkEnd();
        return ret;
    }
    cubei32 operator-(edk::int8 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int32)n;edkEnd();
        ret.size.width=this->size.width-(edk::int32)n;edkEnd();
        ret.size.height=this->size.height-(edk::int32)n;edkEnd();
        ret.size.length=this->size.length-(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator-(edk::int32 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int32)n;edkEnd();
        ret.size.width=this->size.width-(edk::int32)n;edkEnd();
        ret.size.height=this->size.height-(edk::int32)n;edkEnd();
        ret.size.length=this->size.length-(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator-(edk::int16 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int32)n;edkEnd();
        ret.size.width=this->size.width-(edk::int32)n;edkEnd();
        ret.size.height=this->size.height-(edk::int32)n;edkEnd();
        ret.size.length=this->size.length-(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator-(edk::int64 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int32)n;edkEnd();
        ret.size.width=this->size.width-(edk::int32)n;edkEnd();
        ret.size.height=this->size.height-(edk::int32)n;edkEnd();
        ret.size.length=this->size.length-(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator-(edk::uint8 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int32)n;edkEnd();
        ret.size.width=this->size.width-(edk::int32)n;edkEnd();
        ret.size.height=this->size.height-(edk::int32)n;edkEnd();
        ret.size.length=this->size.length-(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator-(edk::uint32 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int32)n;edkEnd();
        ret.size.width=this->size.width-(edk::int32)n;edkEnd();
        ret.size.height=this->size.height-(edk::int32)n;edkEnd();
        ret.size.length=this->size.length-(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator-(edk::uint16 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int32)n;edkEnd();
        ret.size.width=this->size.width-(edk::int32)n;edkEnd();
        ret.size.height=this->size.height-(edk::int32)n;edkEnd();
        ret.size.length=this->size.length-(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator-(edk::uint64 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int32)n;edkEnd();
        ret.size.width=this->size.width-(edk::int32)n;edkEnd();
        ret.size.height=this->size.height-(edk::int32)n;edkEnd();
        ret.size.length=this->size.length-(edk::int32)n;edkEnd();
        return ret;
    }
    void operator-=(cubei32 vec){
        //
        this->origin.x-=(edk::int32)vec.origin.x;edkEnd();
        this->origin.y-=(edk::int32)vec.origin.y;edkEnd();
        this->origin.z-=(edk::int32)vec.origin.z;edkEnd();
        this->size.width-=(edk::int32)vec.size.width;edkEnd();
        this->size.height-=(edk::int32)vec.size.height;edkEnd();
        this->size.length-=(edk::int32)vec.size.length;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int32)n;edkEnd();
        this->origin.y-=(edk::int32)n;edkEnd();
        this->origin.z-=(edk::int32)n;edkEnd();
        this->size.width-=(edk::int32)n;edkEnd();
        this->size.height-=(edk::int32)n;edkEnd();
        this->size.length-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int32)n;edkEnd();
        this->origin.y-=(edk::int32)n;edkEnd();
        this->origin.z-=(edk::int32)n;edkEnd();
        this->size.width-=(edk::int32)n;edkEnd();
        this->size.height-=(edk::int32)n;edkEnd();
        this->size.length-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int32)n;edkEnd();
        this->origin.y-=(edk::int32)n;edkEnd();
        this->origin.z-=(edk::int32)n;edkEnd();
        this->size.width-=(edk::int32)n;edkEnd();
        this->size.height-=(edk::int32)n;edkEnd();
        this->size.length-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int32)n;edkEnd();
        this->origin.y-=(edk::int32)n;edkEnd();
        this->origin.z-=(edk::int32)n;edkEnd();
        this->size.width-=(edk::int32)n;edkEnd();
        this->size.height-=(edk::int32)n;edkEnd();
        this->size.length-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int32)n;edkEnd();
        this->origin.y-=(edk::int32)n;edkEnd();
        this->origin.z-=(edk::int32)n;edkEnd();
        this->size.width-=(edk::int32)n;edkEnd();
        this->size.height-=(edk::int32)n;edkEnd();
        this->size.length-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int32)n;edkEnd();
        this->origin.y-=(edk::int32)n;edkEnd();
        this->origin.z-=(edk::int32)n;edkEnd();
        this->size.width-=(edk::int32)n;edkEnd();
        this->size.height-=(edk::int32)n;edkEnd();
        this->size.length-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int32)n;edkEnd();
        this->origin.y-=(edk::int32)n;edkEnd();
        this->origin.z-=(edk::int32)n;edkEnd();
        this->size.width-=(edk::int32)n;edkEnd();
        this->size.height-=(edk::int32)n;edkEnd();
        this->size.length-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int32)n;edkEnd();
        this->origin.y-=(edk::int32)n;edkEnd();
        this->origin.z-=(edk::int32)n;edkEnd();
        this->size.width-=(edk::int32)n;edkEnd();
        this->size.height-=(edk::int32)n;edkEnd();
        this->size.length-=(edk::int32)n;edkEnd();
    }
    cubei32 operator*(cubei32 cube){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int32)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y*(edk::int32)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z*(edk::int32)cube.origin.z;edkEnd();
        ret.size.width=this->size.width*(edk::int32)cube.size.width;edkEnd();
        ret.size.height=this->size.height*(edk::int32)cube.size.height;edkEnd();
        ret.size.length=this->size.length*(edk::int32)cube.size.length;edkEnd();
        return ret;
    }
    cubei32 operator*(edk::int8 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int32)n;edkEnd();
        ret.size.width=this->size.width*(edk::int32)n;edkEnd();
        ret.size.height=this->size.height*(edk::int32)n;edkEnd();
        ret.size.length=this->size.length*(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator*(edk::int32 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int32)n;edkEnd();
        ret.size.width=this->size.width*(edk::int32)n;edkEnd();
        ret.size.height=this->size.height*(edk::int32)n;edkEnd();
        ret.size.length=this->size.length*(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator*(edk::int16 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int32)n;edkEnd();
        ret.size.width=this->size.width*(edk::int32)n;edkEnd();
        ret.size.height=this->size.height*(edk::int32)n;edkEnd();
        ret.size.length=this->size.length*(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator*(edk::int64 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int32)n;edkEnd();
        ret.size.width=this->size.width*(edk::int32)n;edkEnd();
        ret.size.height=this->size.height*(edk::int32)n;edkEnd();
        ret.size.length=this->size.length*(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator*(edk::uint8 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int32)n;edkEnd();
        ret.size.width=this->size.width*(edk::int32)n;edkEnd();
        ret.size.height=this->size.height*(edk::int32)n;edkEnd();
        ret.size.length=this->size.length*(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator*(edk::uint32 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int32)n;edkEnd();
        ret.size.width=this->size.width*(edk::int32)n;edkEnd();
        ret.size.height=this->size.height*(edk::int32)n;edkEnd();
        ret.size.length=this->size.length*(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator*(edk::uint16 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int32)n;edkEnd();
        ret.size.width=this->size.width*(edk::int32)n;edkEnd();
        ret.size.height=this->size.height*(edk::int32)n;edkEnd();
        ret.size.length=this->size.length*(edk::int32)n;edkEnd();
        return ret;
    }
    cubei32 operator*(edk::uint64 n){
        //
        cubei32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int32)n;edkEnd();
        ret.size.width=this->size.width*(edk::int32)n;edkEnd();
        ret.size.height=this->size.height*(edk::int32)n;edkEnd();
        ret.size.length=this->size.length*(edk::int32)n;edkEnd();
        return ret;
    }
    void operator*=(cubei32 cube){
        //
        this->origin.x*=(edk::int32)cube.origin.x;edkEnd();
        this->origin.y*=(edk::int32)cube.origin.y;edkEnd();
        this->origin.z*=(edk::int32)cube.origin.z;edkEnd();
        this->size.width*=(edk::int32)cube.size.width;edkEnd();
        this->size.height*=(edk::int32)cube.size.height;edkEnd();
        this->size.length*=(edk::int32)cube.size.length;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int32)n;edkEnd();
        this->origin.y*=(edk::int32)n;edkEnd();
        this->origin.z*=(edk::int32)n;edkEnd();
        this->size.width*=(edk::int32)n;edkEnd();
        this->size.height*=(edk::int32)n;edkEnd();
        this->size.length*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int32)n;edkEnd();
        this->origin.y*=(edk::int32)n;edkEnd();
        this->origin.z*=(edk::int32)n;edkEnd();
        this->size.width*=(edk::int32)n;edkEnd();
        this->size.height*=(edk::int32)n;edkEnd();
        this->size.length*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int32)n;edkEnd();
        this->origin.y*=(edk::int32)n;edkEnd();
        this->origin.z*=(edk::int32)n;edkEnd();
        this->size.width*=(edk::int32)n;edkEnd();
        this->size.height*=(edk::int32)n;edkEnd();
        this->size.length*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int32)n;edkEnd();
        this->origin.y*=(edk::int32)n;edkEnd();
        this->origin.z*=(edk::int32)n;edkEnd();
        this->size.width*=(edk::int32)n;edkEnd();
        this->size.height*=(edk::int32)n;edkEnd();
        this->size.length*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int32)n;edkEnd();
        this->origin.y*=(edk::int32)n;edkEnd();
        this->origin.z*=(edk::int32)n;edkEnd();
        this->size.width*=(edk::int32)n;edkEnd();
        this->size.height*=(edk::int32)n;edkEnd();
        this->size.length*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int32)n;edkEnd();
        this->origin.y*=(edk::int32)n;edkEnd();
        this->origin.z*=(edk::int32)n;edkEnd();
        this->size.width*=(edk::int32)n;edkEnd();
        this->size.height*=(edk::int32)n;edkEnd();
        this->size.length*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int32)n;edkEnd();
        this->origin.y*=(edk::int32)n;edkEnd();
        this->origin.z*=(edk::int32)n;edkEnd();
        this->size.width*=(edk::int32)n;edkEnd();
        this->size.height*=(edk::int32)n;edkEnd();
        this->size.length*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int32)n;edkEnd();
        this->origin.y*=(edk::int32)n;edkEnd();
        this->origin.z*=(edk::int32)n;edkEnd();
        this->size.width*=(edk::int32)n;edkEnd();
        this->size.height*=(edk::int32)n;edkEnd();
        this->size.length*=(edk::int32)n;edkEnd();
    }
    //
    cubei32 operator++(){
        //
        ++this->origin.x;edkEnd();
        ++this->origin.y;edkEnd();
        ++this->origin.z;edkEnd();
        ++this->size.width;edkEnd();
        ++this->size.height;edkEnd();
        ++this->size.length;edkEnd();
        return cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei32 operator++(edk::int32){
        //
        this->origin.x++;edkEnd();
        this->origin.y++;edkEnd();
        this->origin.z++;edkEnd();
        this->size.width++;edkEnd();
        this->size.height++;edkEnd();
        this->size.length++;edkEnd();
        return cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei32 operator--(){
        //
        --this->origin.x;edkEnd();
        --this->origin.y;edkEnd();
        --this->origin.z;edkEnd();
        --this->size.width;edkEnd();
        --this->size.height;edkEnd();
        --this->size.length;edkEnd();
        return cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei32 operator--(edk::int32){
        //
        this->origin.x--;edkEnd();
        this->origin.y--;edkEnd();
        this->origin.z--;edkEnd();
        this->size.width--;edkEnd();
        this->size.height--;edkEnd();
        this->size.length--;edkEnd();
        return cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei32 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);edkEnd();
    }
    cubei32 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);edkEnd();
    }
    cubei32 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);edkEnd();
    }
    cubei32 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);edkEnd();
    }
    cubei32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);edkEnd();
    }
    cubei32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);edkEnd();
    }
    cubei32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);edkEnd();
    }
    cubei32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);edkEnd();
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
        this->origin.x=(edk::int64)0;edkEnd();
        this->origin.y=(edk::int64)0;edkEnd();
        this->origin.z=(edk::int64)0;edkEnd();
        this->size.width=(edk::int64)0;edkEnd();
        this->size.height=(edk::int64)0;edkEnd();
        this->size.length=(edk::int64)0;edkEnd();
    }
    cubei64(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::int64)x;edkEnd();
        this->origin.y=(edk::int64)y;edkEnd();
        this->origin.z=(edk::int64)z;edkEnd();
        this->size.width=(edk::int64)width;edkEnd();
        this->size.height=(edk::int64)height;edkEnd();
        this->size.length=(edk::int64)length;edkEnd();
    }
    cubei64(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::int64)x;edkEnd();
        this->origin.y=(edk::int64)y;edkEnd();
        this->origin.z=(edk::int64)z;edkEnd();
        this->size.width=(edk::int64)width;edkEnd();
        this->size.height=(edk::int64)height;edkEnd();
        this->size.length=(edk::int64)length;edkEnd();
    }
    cubei64(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::int64)x;edkEnd();
        this->origin.y=(edk::int64)y;edkEnd();
        this->origin.z=(edk::int64)z;edkEnd();
        this->size.width=(edk::int64)width;edkEnd();
        this->size.height=(edk::int64)height;edkEnd();
        this->size.length=(edk::int64)length;edkEnd();
    }
    cubei64(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::int64)x;edkEnd();
        this->origin.y=(edk::int64)y;edkEnd();
        this->origin.z=(edk::int64)z;edkEnd();
        this->size.width=(edk::int64)width;edkEnd();
        this->size.height=(edk::int64)height;edkEnd();
        this->size.length=(edk::int64)length;edkEnd();
    }
    cubei64(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::int64)x;edkEnd();
        this->origin.y=(edk::int64)y;edkEnd();
        this->origin.z=(edk::int64)z;edkEnd();
        this->size.width=(edk::int64)width;edkEnd();
        this->size.height=(edk::int64)height;edkEnd();
        this->size.length=(edk::int64)length;edkEnd();
    }
    cubei64(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::int64)x;edkEnd();
        this->origin.y=(edk::int64)y;edkEnd();
        this->origin.z=(edk::int64)z;edkEnd();
        this->size.width=(edk::int64)width;edkEnd();
        this->size.height=(edk::int64)height;edkEnd();
        this->size.length=(edk::int64)length;edkEnd();
    }
    cubei64(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::int64)x;edkEnd();
        this->origin.y=(edk::int64)y;edkEnd();
        this->origin.z=(edk::int64)z;edkEnd();
        this->size.width=(edk::int64)width;edkEnd();
        this->size.height=(edk::int64)height;edkEnd();
        this->size.length=(edk::int64)length;edkEnd();
    }
    cubei64(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::int64)x;edkEnd();
        this->origin.y=(edk::int64)y;edkEnd();
        this->origin.z=(edk::int64)z;edkEnd();
        this->size.width=(edk::int64)width;edkEnd();
        this->size.height=(edk::int64)height;edkEnd();
        this->size.length=(edk::int64)length;edkEnd();
    }
    cubei64(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::int64)origin.x;edkEnd();
        this->origin.y=(edk::int64)origin.y;edkEnd();
        this->origin.z=(edk::int64)origin.z;edkEnd();
        this->size.width=(edk::int64)size.width;edkEnd();
        this->size.height=(edk::int64)size.height;edkEnd();
        this->size.length=(edk::int64)size.length;edkEnd();
    }
    cubei64(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::int64)origin.x;edkEnd();
        this->origin.y=(edk::int64)origin.y;edkEnd();
        this->origin.z=(edk::int64)origin.z;edkEnd();
        this->size.width=(edk::int64)size.width;edkEnd();
        this->size.height=(edk::int64)size.height;edkEnd();
        this->size.length=(edk::int64)size.length;edkEnd();
    }
    cubei64(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::int64)origin.x;edkEnd();
        this->origin.y=(edk::int64)origin.y;edkEnd();
        this->origin.z=(edk::int64)origin.z;edkEnd();
        this->size.width=(edk::int64)size.width;edkEnd();
        this->size.height=(edk::int64)size.height;edkEnd();
        this->size.length=(edk::int64)size.length;edkEnd();
    }
    cubei64(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::int64)origin.x;edkEnd();
        this->origin.y=(edk::int64)origin.y;edkEnd();
        this->origin.z=(edk::int64)origin.z;edkEnd();
        this->size.width=(edk::int64)size.width;edkEnd();
        this->size.height=(edk::int64)size.height;edkEnd();
        this->size.length=(edk::int64)size.length;edkEnd();
    }
    cubei64(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::int64)origin.x;edkEnd();
        this->origin.y=(edk::int64)origin.y;edkEnd();
        this->origin.z=(edk::int64)origin.z;edkEnd();
        this->size.width=(edk::int64)size.width;edkEnd();
        this->size.height=(edk::int64)size.height;edkEnd();
        this->size.length=(edk::int64)size.length;edkEnd();
    }
    cubei64(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::int64)origin.x;edkEnd();
        this->origin.y=(edk::int64)origin.y;edkEnd();
        this->origin.z=(edk::int64)origin.z;edkEnd();
        this->size.width=(edk::int64)size.width;edkEnd();
        this->size.height=(edk::int64)size.height;edkEnd();
        this->size.length=(edk::int64)size.length;edkEnd();
    }
    cubei64(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::int64)origin.x;edkEnd();
        this->origin.y=(edk::int64)origin.y;edkEnd();
        this->origin.z=(edk::int64)origin.z;edkEnd();
        this->size.width=(edk::int64)size.width;edkEnd();
        this->size.height=(edk::int64)size.height;edkEnd();
        this->size.length=(edk::int64)size.length;edkEnd();
    }
    cubei64(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::int64)origin.x;edkEnd();
        this->origin.y=(edk::int64)origin.y;edkEnd();
        this->origin.z=(edk::int64)origin.z;edkEnd();
        this->size.width=(edk::int64)size.width;edkEnd();
        this->size.height=(edk::int64)size.height;edkEnd();
        this->size.length=(edk::int64)size.length;edkEnd();
    }

    //operators
    cubei64 operator=(cubei64 cube){
        //
        this->origin.x=(edk::int64)cube.origin.x;edkEnd();
        this->origin.y=(edk::int64)cube.origin.y;edkEnd();
        this->origin.z=(edk::int64)cube.origin.z;edkEnd();
        this->size.width=(edk::int64)cube.size.width;edkEnd();
        this->size.height=(edk::int64)cube.size.height;edkEnd();
        this->size.length=(edk::int64)cube.size.length;edkEnd();
        return *this;edkEnd();
    }
    cubei64 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int64)n;edkEnd();
        this->origin.y=(edk::int64)n;edkEnd();
        this->origin.z=(edk::int64)n;edkEnd();
        this->size.width=(edk::int64)n;edkEnd();
        this->size.height=(edk::int64)n;edkEnd();
        this->size.length=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    cubei64 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int64)n;edkEnd();
        this->origin.y=(edk::int64)n;edkEnd();
        this->origin.z=(edk::int64)n;edkEnd();
        this->size.width=(edk::int64)n;edkEnd();
        this->size.height=(edk::int64)n;edkEnd();
        this->size.length=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    cubei64 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int64)n;edkEnd();
        this->origin.y=(edk::int64)n;edkEnd();
        this->origin.z=(edk::int64)n;edkEnd();
        this->size.width=(edk::int64)n;edkEnd();
        this->size.height=(edk::int64)n;edkEnd();
        this->size.length=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    cubei64 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int64)n;edkEnd();
        this->origin.y=(edk::int64)n;edkEnd();
        this->origin.z=(edk::int64)n;edkEnd();
        this->size.width=(edk::int64)n;edkEnd();
        this->size.height=(edk::int64)n;edkEnd();
        this->size.length=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    cubei64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int64)n;edkEnd();
        this->origin.y=(edk::int64)n;edkEnd();
        this->origin.z=(edk::int64)n;edkEnd();
        this->size.width=(edk::int64)n;edkEnd();
        this->size.height=(edk::int64)n;edkEnd();
        this->size.length=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    cubei64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int64)n;edkEnd();
        this->origin.y=(edk::int64)n;edkEnd();
        this->origin.z=(edk::int64)n;edkEnd();
        this->size.width=(edk::int64)n;edkEnd();
        this->size.height=(edk::int64)n;edkEnd();
        this->size.length=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    cubei64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int64)n;edkEnd();
        this->origin.y=(edk::int64)n;edkEnd();
        this->origin.z=(edk::int64)n;edkEnd();
        this->size.width=(edk::int64)n;edkEnd();
        this->size.height=(edk::int64)n;edkEnd();
        this->size.length=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    cubei64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int64)n;edkEnd();
        this->origin.y=(edk::int64)n;edkEnd();
        this->origin.z=(edk::int64)n;edkEnd();
        this->size.width=(edk::int64)n;edkEnd();
        this->size.height=(edk::int64)n;edkEnd();
        this->size.length=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }

    bool operator==(cubei64 cube){
        //
        return (this->origin.x==(edk::int64)cube.origin.x
                &&this->origin.y==(edk::int64)cube.origin.y
                &&this->origin.z==(edk::int64)cube.origin.z
                &&this->size.width==(edk::int64)cube.size.width
                &&this->size.height==(edk::int64)cube.size.height
                &&this->size.length==(edk::int64)cube.size.length
                );edkEnd();
    }
    bool operator!=(cubei64 cube){
        //
        return (this->origin.x!=(edk::int64)cube.origin.x
                ||this->origin.y!=(edk::int64)cube.origin.y
                ||this->origin.z!=(edk::int64)cube.origin.z
                ||this->size.width!=(edk::int64)cube.size.width
                ||this->size.height!=(edk::int64)cube.size.height
                ||this->size.length!=(edk::int64)cube.size.length
                );edkEnd();
    }
    cubei64 operator+(cubei64 cube){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int64)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y+(edk::int64)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z+(edk::int64)cube.origin.z;edkEnd();
        ret.size.width=this->size.width+(edk::int64)cube.size.width;edkEnd();
        ret.size.height=this->size.height+(edk::int64)cube.size.height;edkEnd();
        ret.size.length=this->size.length+(edk::int64)cube.size.length;edkEnd();
        return ret;
    }
    cubei64 operator+(edk::int8 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int64)n;edkEnd();
        ret.size.width=this->size.width+(edk::int64)n;edkEnd();
        ret.size.height=this->size.height+(edk::int64)n;edkEnd();
        ret.size.length=this->size.length+(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator+(edk::int32 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int64)n;edkEnd();
        ret.size.width=this->size.width+(edk::int64)n;edkEnd();
        ret.size.height=this->size.height+(edk::int64)n;edkEnd();
        ret.size.length=this->size.length+(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator+(edk::int16 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int64)n;edkEnd();
        ret.size.width=this->size.width+(edk::int64)n;edkEnd();
        ret.size.height=this->size.height+(edk::int64)n;edkEnd();
        ret.size.length=this->size.length+(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator+(edk::int64 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int64)n;edkEnd();
        ret.size.width=this->size.width+(edk::int64)n;edkEnd();
        ret.size.height=this->size.height+(edk::int64)n;edkEnd();
        ret.size.length=this->size.length+(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator+(edk::uint8 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int64)n;edkEnd();
        ret.size.width=this->size.width+(edk::int64)n;edkEnd();
        ret.size.height=this->size.height+(edk::int64)n;edkEnd();
        ret.size.length=this->size.length+(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator+(edk::uint32 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int64)n;edkEnd();
        ret.size.width=this->size.width+(edk::int64)n;edkEnd();
        ret.size.height=this->size.height+(edk::int64)n;edkEnd();
        ret.size.length=this->size.length+(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator+(edk::uint16 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int64)n;edkEnd();
        ret.size.width=this->size.width+(edk::int64)n;edkEnd();
        ret.size.height=this->size.height+(edk::int64)n;edkEnd();
        ret.size.length=this->size.length+(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator+(edk::uint64 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::int64)n;edkEnd();
        ret.size.width=this->size.width+(edk::int64)n;edkEnd();
        ret.size.height=this->size.height+(edk::int64)n;edkEnd();
        ret.size.length=this->size.length+(edk::int64)n;edkEnd();
        return ret;
    }
    void operator+=(cubei64 cube){
        //
        this->origin.x+=(edk::int64)cube.origin.x;edkEnd();
        this->origin.y+=(edk::int64)cube.origin.y;edkEnd();
        this->origin.z+=(edk::int64)cube.origin.z;edkEnd();
        this->size.width+=(edk::int64)cube.size.width;edkEnd();
        this->size.height+=(edk::int64)cube.size.height;edkEnd();
        this->size.length+=(edk::int64)cube.size.length;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int64)n;edkEnd();
        this->origin.y+=(edk::int64)n;edkEnd();
        this->origin.z+=(edk::int64)n;edkEnd();
        this->size.width+=(edk::int64)n;edkEnd();
        this->size.height+=(edk::int64)n;edkEnd();
        this->size.length+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int64)n;edkEnd();
        this->origin.y+=(edk::int64)n;edkEnd();
        this->origin.z+=(edk::int64)n;edkEnd();
        this->size.width+=(edk::int64)n;edkEnd();
        this->size.height+=(edk::int64)n;edkEnd();
        this->size.length+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int64)n;edkEnd();
        this->origin.y+=(edk::int64)n;edkEnd();
        this->origin.z+=(edk::int64)n;edkEnd();
        this->size.width+=(edk::int64)n;edkEnd();
        this->size.height+=(edk::int64)n;edkEnd();
        this->size.length+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int64)n;edkEnd();
        this->origin.y+=(edk::int64)n;edkEnd();
        this->origin.z+=(edk::int64)n;edkEnd();
        this->size.width+=(edk::int64)n;edkEnd();
        this->size.height+=(edk::int64)n;edkEnd();
        this->size.length+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int64)n;edkEnd();
        this->origin.y+=(edk::int64)n;edkEnd();
        this->origin.z+=(edk::int64)n;edkEnd();
        this->size.width+=(edk::int64)n;edkEnd();
        this->size.height+=(edk::int64)n;edkEnd();
        this->size.length+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int64)n;edkEnd();
        this->origin.y+=(edk::int64)n;edkEnd();
        this->origin.z+=(edk::int64)n;edkEnd();
        this->size.width+=(edk::int64)n;edkEnd();
        this->size.height+=(edk::int64)n;edkEnd();
        this->size.length+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int64)n;edkEnd();
        this->origin.y+=(edk::int64)n;edkEnd();
        this->origin.z+=(edk::int64)n;edkEnd();
        this->size.width+=(edk::int64)n;edkEnd();
        this->size.height+=(edk::int64)n;edkEnd();
        this->size.length+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int64)n;edkEnd();
        this->origin.y+=(edk::int64)n;edkEnd();
        this->origin.z+=(edk::int64)n;edkEnd();
        this->size.width+=(edk::int64)n;edkEnd();
        this->size.height+=(edk::int64)n;edkEnd();
        this->size.length+=(edk::int64)n;edkEnd();
    }
    cubei64 operator-(cubei64 cube){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int64)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y-(edk::int64)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z-(edk::int64)cube.origin.z;edkEnd();
        ret.size.width=this->size.width-(edk::int64)cube.size.width;edkEnd();
        ret.size.height=this->size.height-(edk::int64)cube.size.height;edkEnd();
        ret.size.length=this->size.length-(edk::int64)cube.size.length;edkEnd();
        return ret;
    }
    cubei64 operator-(edk::int8 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int64)n;edkEnd();
        ret.size.width=this->size.width-(edk::int64)n;edkEnd();
        ret.size.height=this->size.height-(edk::int64)n;edkEnd();
        ret.size.length=this->size.length-(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator-(edk::int32 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int64)n;edkEnd();
        ret.size.width=this->size.width-(edk::int64)n;edkEnd();
        ret.size.height=this->size.height-(edk::int64)n;edkEnd();
        ret.size.length=this->size.length-(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator-(edk::int16 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int64)n;edkEnd();
        ret.size.width=this->size.width-(edk::int64)n;edkEnd();
        ret.size.height=this->size.height-(edk::int64)n;edkEnd();
        ret.size.length=this->size.length-(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator-(edk::int64 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int64)n;edkEnd();
        ret.size.width=this->size.width-(edk::int64)n;edkEnd();
        ret.size.height=this->size.height-(edk::int64)n;edkEnd();
        ret.size.length=this->size.length-(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator-(edk::uint8 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int64)n;edkEnd();
        ret.size.width=this->size.width-(edk::int64)n;edkEnd();
        ret.size.height=this->size.height-(edk::int64)n;edkEnd();
        ret.size.length=this->size.length-(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator-(edk::uint32 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int64)n;edkEnd();
        ret.size.width=this->size.width-(edk::int64)n;edkEnd();
        ret.size.height=this->size.height-(edk::int64)n;edkEnd();
        ret.size.length=this->size.length-(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator-(edk::uint16 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int64)n;edkEnd();
        ret.size.width=this->size.width-(edk::int64)n;edkEnd();
        ret.size.height=this->size.height-(edk::int64)n;edkEnd();
        ret.size.length=this->size.length-(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator-(edk::uint64 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::int64)n;edkEnd();
        ret.size.width=this->size.width-(edk::int64)n;edkEnd();
        ret.size.height=this->size.height-(edk::int64)n;edkEnd();
        ret.size.length=this->size.length-(edk::int64)n;edkEnd();
        return ret;
    }
    void operator-=(cubei64 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;edkEnd();
        this->origin.y-=(edk::int64)vec.origin.y;edkEnd();
        this->origin.z-=(edk::int64)vec.origin.z;edkEnd();
        this->size.width-=(edk::int64)vec.size.width;edkEnd();
        this->size.height-=(edk::int64)vec.size.height;edkEnd();
        this->size.length-=(edk::int64)vec.size.length;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int64)n;edkEnd();
        this->origin.y-=(edk::int64)n;edkEnd();
        this->origin.z-=(edk::int64)n;edkEnd();
        this->size.width-=(edk::int64)n;edkEnd();
        this->size.height-=(edk::int64)n;edkEnd();
        this->size.length-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int64)n;edkEnd();
        this->origin.y-=(edk::int64)n;edkEnd();
        this->origin.z-=(edk::int64)n;edkEnd();
        this->size.width-=(edk::int64)n;edkEnd();
        this->size.height-=(edk::int64)n;edkEnd();
        this->size.length-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int64)n;edkEnd();
        this->origin.y-=(edk::int64)n;edkEnd();
        this->origin.z-=(edk::int64)n;edkEnd();
        this->size.width-=(edk::int64)n;edkEnd();
        this->size.height-=(edk::int64)n;edkEnd();
        this->size.length-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int64)n;edkEnd();
        this->origin.y-=(edk::int64)n;edkEnd();
        this->origin.z-=(edk::int64)n;edkEnd();
        this->size.width-=(edk::int64)n;edkEnd();
        this->size.height-=(edk::int64)n;edkEnd();
        this->size.length-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int64)n;edkEnd();
        this->origin.y-=(edk::int64)n;edkEnd();
        this->origin.z-=(edk::int64)n;edkEnd();
        this->size.width-=(edk::int64)n;edkEnd();
        this->size.height-=(edk::int64)n;edkEnd();
        this->size.length-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int64)n;edkEnd();
        this->origin.y-=(edk::int64)n;edkEnd();
        this->origin.z-=(edk::int64)n;edkEnd();
        this->size.width-=(edk::int64)n;edkEnd();
        this->size.height-=(edk::int64)n;edkEnd();
        this->size.length-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int64)n;edkEnd();
        this->origin.y-=(edk::int64)n;edkEnd();
        this->origin.z-=(edk::int64)n;edkEnd();
        this->size.width-=(edk::int64)n;edkEnd();
        this->size.height-=(edk::int64)n;edkEnd();
        this->size.length-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int64)n;edkEnd();
        this->origin.y-=(edk::int64)n;edkEnd();
        this->origin.z-=(edk::int64)n;edkEnd();
        this->size.width-=(edk::int64)n;edkEnd();
        this->size.height-=(edk::int64)n;edkEnd();
        this->size.length-=(edk::int64)n;edkEnd();
    }
    cubei64 operator*(cubei64 cube){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int64)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y*(edk::int64)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z*(edk::int64)cube.origin.z;edkEnd();
        ret.size.width=this->size.width*(edk::int64)cube.size.width;edkEnd();
        ret.size.height=this->size.height*(edk::int64)cube.size.height;edkEnd();
        ret.size.length=this->size.length*(edk::int64)cube.size.length;edkEnd();
        return ret;
    }
    cubei64 operator*(edk::int8 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int64)n;edkEnd();
        ret.size.width=this->size.width*(edk::int64)n;edkEnd();
        ret.size.height=this->size.height*(edk::int64)n;edkEnd();
        ret.size.length=this->size.length*(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator*(edk::int32 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int64)n;edkEnd();
        ret.size.width=this->size.width*(edk::int64)n;edkEnd();
        ret.size.height=this->size.height*(edk::int64)n;edkEnd();
        ret.size.length=this->size.length*(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator*(edk::int16 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int64)n;edkEnd();
        ret.size.width=this->size.width*(edk::int64)n;edkEnd();
        ret.size.height=this->size.height*(edk::int64)n;edkEnd();
        ret.size.length=this->size.length*(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator*(edk::int64 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int64)n;edkEnd();
        ret.size.width=this->size.width*(edk::int64)n;edkEnd();
        ret.size.height=this->size.height*(edk::int64)n;edkEnd();
        ret.size.length=this->size.length*(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator*(edk::uint8 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int64)n;edkEnd();
        ret.size.width=this->size.width*(edk::int64)n;edkEnd();
        ret.size.height=this->size.height*(edk::int64)n;edkEnd();
        ret.size.length=this->size.length*(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator*(edk::uint32 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int64)n;edkEnd();
        ret.size.width=this->size.width*(edk::int64)n;edkEnd();
        ret.size.height=this->size.height*(edk::int64)n;edkEnd();
        ret.size.length=this->size.length*(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator*(edk::uint16 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int64)n;edkEnd();
        ret.size.width=this->size.width*(edk::int64)n;edkEnd();
        ret.size.height=this->size.height*(edk::int64)n;edkEnd();
        ret.size.length=this->size.length*(edk::int64)n;edkEnd();
        return ret;
    }
    cubei64 operator*(edk::uint64 n){
        //
        cubei64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::int64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::int64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::int64)n;edkEnd();
        ret.size.width=this->size.width*(edk::int64)n;edkEnd();
        ret.size.height=this->size.height*(edk::int64)n;edkEnd();
        ret.size.length=this->size.length*(edk::int64)n;edkEnd();
        return ret;
    }
    void operator*=(cubei64 cube){
        //
        this->origin.x*=(edk::int64)cube.origin.x;edkEnd();
        this->origin.y*=(edk::int64)cube.origin.y;edkEnd();
        this->origin.z*=(edk::int64)cube.origin.z;edkEnd();
        this->size.width*=(edk::int64)cube.size.width;edkEnd();
        this->size.height*=(edk::int64)cube.size.height;edkEnd();
        this->size.length*=(edk::int64)cube.size.length;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int64)n;edkEnd();
        this->origin.y*=(edk::int64)n;edkEnd();
        this->origin.z*=(edk::int64)n;edkEnd();
        this->size.width*=(edk::int64)n;edkEnd();
        this->size.height*=(edk::int64)n;edkEnd();
        this->size.length*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int64)n;edkEnd();
        this->origin.y*=(edk::int64)n;edkEnd();
        this->origin.z*=(edk::int64)n;edkEnd();
        this->size.width*=(edk::int64)n;edkEnd();
        this->size.height*=(edk::int64)n;edkEnd();
        this->size.length*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int64)n;edkEnd();
        this->origin.y*=(edk::int64)n;edkEnd();
        this->origin.z*=(edk::int64)n;edkEnd();
        this->size.width*=(edk::int64)n;edkEnd();
        this->size.height*=(edk::int64)n;edkEnd();
        this->size.length*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int64)n;edkEnd();
        this->origin.y*=(edk::int64)n;edkEnd();
        this->origin.z*=(edk::int64)n;edkEnd();
        this->size.width*=(edk::int64)n;edkEnd();
        this->size.height*=(edk::int64)n;edkEnd();
        this->size.length*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int64)n;edkEnd();
        this->origin.y*=(edk::int64)n;edkEnd();
        this->origin.z*=(edk::int64)n;edkEnd();
        this->size.width*=(edk::int64)n;edkEnd();
        this->size.height*=(edk::int64)n;edkEnd();
        this->size.length*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int64)n;edkEnd();
        this->origin.y*=(edk::int64)n;edkEnd();
        this->origin.z*=(edk::int64)n;edkEnd();
        this->size.width*=(edk::int64)n;edkEnd();
        this->size.height*=(edk::int64)n;edkEnd();
        this->size.length*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int64)n;edkEnd();
        this->origin.y*=(edk::int64)n;edkEnd();
        this->origin.z*=(edk::int64)n;edkEnd();
        this->size.width*=(edk::int64)n;edkEnd();
        this->size.height*=(edk::int64)n;edkEnd();
        this->size.length*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int64)n;edkEnd();
        this->origin.y*=(edk::int64)n;edkEnd();
        this->origin.z*=(edk::int64)n;edkEnd();
        this->size.width*=(edk::int64)n;edkEnd();
        this->size.height*=(edk::int64)n;edkEnd();
        this->size.length*=(edk::int64)n;edkEnd();
    }
    //
    cubei64 operator++(){
        //
        ++this->origin.x;edkEnd();
        ++this->origin.y;edkEnd();
        ++this->origin.z;edkEnd();
        ++this->size.width;edkEnd();
        ++this->size.height;edkEnd();
        ++this->size.length;edkEnd();
        return cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei64 operator++(edk::int32){
        //
        this->origin.x++;edkEnd();
        this->origin.y++;edkEnd();
        this->origin.z++;edkEnd();
        this->size.width++;edkEnd();
        this->size.height++;edkEnd();
        this->size.length++;edkEnd();
        return cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei64 operator--(){
        //
        --this->origin.x;edkEnd();
        --this->origin.y;edkEnd();
        --this->origin.z;edkEnd();
        --this->size.width;edkEnd();
        --this->size.height;edkEnd();
        --this->size.length;edkEnd();
        return cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei64 operator--(edk::int32){
        //
        this->origin.x--;edkEnd();
        this->origin.y--;edkEnd();
        this->origin.z--;edkEnd();
        this->size.width--;edkEnd();
        this->size.height--;edkEnd();
        this->size.length--;edkEnd();
        return cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubei64 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);edkEnd();
    }
    cubei64 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);edkEnd();
    }
    cubei64 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);edkEnd();
    }
    cubei64 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);edkEnd();
    }
    cubei64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);edkEnd();
    }
    cubei64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);edkEnd();
    }
    cubei64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);edkEnd();
    }
    cubei64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);edkEnd();
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
        this->origin.x=(edk::uint8)0;edkEnd();
        this->origin.y=(edk::uint8)0;edkEnd();
        this->origin.z=(edk::uint8)0;edkEnd();
        this->size.width=(edk::uint8)0;edkEnd();
        this->size.height=(edk::uint8)0;edkEnd();
        this->size.length=(edk::uint8)0;edkEnd();
    }
    cubeui8(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::uint8)x;edkEnd();
        this->origin.y=(edk::uint8)y;edkEnd();
        this->origin.z=(edk::uint8)z;edkEnd();
        this->size.width=(edk::uint8)width;edkEnd();
        this->size.height=(edk::uint8)height;edkEnd();
        this->size.length=(edk::uint8)length;edkEnd();
    }
    cubeui8(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint8)x;edkEnd();
        this->origin.y=(edk::uint8)y;edkEnd();
        this->origin.z=(edk::uint8)z;edkEnd();
        this->size.width=(edk::uint8)width;edkEnd();
        this->size.height=(edk::uint8)height;edkEnd();
        this->size.length=(edk::uint8)length;edkEnd();
    }
    cubeui8(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint8)x;edkEnd();
        this->origin.y=(edk::uint8)y;edkEnd();
        this->origin.z=(edk::uint8)z;edkEnd();
        this->size.width=(edk::uint8)width;edkEnd();
        this->size.height=(edk::uint8)height;edkEnd();
        this->size.length=(edk::uint8)length;edkEnd();
    }
    cubeui8(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint8)x;edkEnd();
        this->origin.y=(edk::uint8)y;edkEnd();
        this->origin.z=(edk::uint8)z;edkEnd();
        this->size.width=(edk::uint8)width;edkEnd();
        this->size.height=(edk::uint8)height;edkEnd();
        this->size.length=(edk::uint8)length;edkEnd();
    }
    cubeui8(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::uint8)origin.x;edkEnd();
        this->origin.y=(edk::uint8)origin.y;edkEnd();
        this->origin.z=(edk::uint8)origin.z;edkEnd();
        this->size.width=(edk::uint8)size.width;edkEnd();
        this->size.height=(edk::uint8)size.height;edkEnd();
        this->size.length=(edk::uint8)size.length;edkEnd();
    }
    cubeui8(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::uint8)origin.x;edkEnd();
        this->origin.y=(edk::uint8)origin.y;edkEnd();
        this->origin.z=(edk::uint8)origin.z;edkEnd();
        this->size.width=(edk::uint8)size.width;edkEnd();
        this->size.height=(edk::uint8)size.height;edkEnd();
        this->size.length=(edk::uint8)size.length;edkEnd();
    }
    cubeui8(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::uint8)origin.x;edkEnd();
        this->origin.y=(edk::uint8)origin.y;edkEnd();
        this->origin.z=(edk::uint8)origin.z;edkEnd();
        this->size.width=(edk::uint8)size.width;edkEnd();
        this->size.height=(edk::uint8)size.height;edkEnd();
        this->size.length=(edk::uint8)size.length;edkEnd();
    }
    cubeui8(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::uint8)origin.x;edkEnd();
        this->origin.y=(edk::uint8)origin.y;edkEnd();
        this->origin.z=(edk::uint8)origin.z;edkEnd();
        this->size.width=(edk::uint8)size.width;edkEnd();
        this->size.height=(edk::uint8)size.height;edkEnd();
        this->size.length=(edk::uint8)size.length;edkEnd();
    }

    //operators
    cubeui8 operator=(cubeui8 cube){
        //
        this->origin.x=(edk::uint8)cube.origin.x;edkEnd();
        this->origin.y=(edk::uint8)cube.origin.y;edkEnd();
        this->origin.z=(edk::uint8)cube.origin.z;edkEnd();
        this->size.width=(edk::uint8)cube.size.width;edkEnd();
        this->size.height=(edk::uint8)cube.size.height;edkEnd();
        this->size.length=(edk::uint8)cube.size.length;edkEnd();
        return *this;edkEnd();
    }
    cubeui8 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint8)n;edkEnd();
        this->origin.y=(edk::uint8)n;edkEnd();
        this->origin.z=(edk::uint8)n;edkEnd();
        this->size.width=(edk::uint8)n;edkEnd();
        this->size.height=(edk::uint8)n;edkEnd();
        this->size.length=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui8 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint8)n;edkEnd();
        this->origin.y=(edk::uint8)n;edkEnd();
        this->origin.z=(edk::uint8)n;edkEnd();
        this->size.width=(edk::uint8)n;edkEnd();
        this->size.height=(edk::uint8)n;edkEnd();
        this->size.length=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui8 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint8)n;edkEnd();
        this->origin.y=(edk::uint8)n;edkEnd();
        this->origin.z=(edk::uint8)n;edkEnd();
        this->size.width=(edk::uint8)n;edkEnd();
        this->size.height=(edk::uint8)n;edkEnd();
        this->size.length=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui8 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint8)n;edkEnd();
        this->origin.y=(edk::uint8)n;edkEnd();
        this->origin.z=(edk::uint8)n;edkEnd();
        this->size.width=(edk::uint8)n;edkEnd();
        this->size.height=(edk::uint8)n;edkEnd();
        this->size.length=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }

    bool operator==(cubeui8 cube){
        //
        return (this->origin.x==(edk::uint8)cube.origin.x
                &&this->origin.y==(edk::uint8)cube.origin.y
                &&this->origin.z==(edk::uint8)cube.origin.z
                &&this->size.width==(edk::uint8)cube.size.width
                &&this->size.height==(edk::uint8)cube.size.height
                &&this->size.length==(edk::uint8)cube.size.length
                );edkEnd();
    }
    bool operator!=(cubeui8 cube){
        //
        return (this->origin.x!=(edk::uint8)cube.origin.x
                ||this->origin.y!=(edk::uint8)cube.origin.y
                ||this->origin.z!=(edk::uint8)cube.origin.z
                ||this->size.width!=(edk::uint8)cube.size.width
                ||this->size.height!=(edk::uint8)cube.size.height
                ||this->size.length!=(edk::uint8)cube.size.length
                );edkEnd();
    }
    cubeui8 operator+(cubeui8 cube){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint8)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint8)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint8)cube.origin.z;edkEnd();
        ret.size.width=this->size.width+(edk::uint8)cube.size.width;edkEnd();
        ret.size.height=this->size.height+(edk::uint8)cube.size.height;edkEnd();
        ret.size.length=this->size.length+(edk::uint8)cube.size.length;edkEnd();
        return ret;
    }
    cubeui8 operator+(edk::uint8 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint8)n;edkEnd();
        return ret;
    }
    cubeui8 operator+(edk::uint32 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint8)n;edkEnd();
        return ret;
    }
    cubeui8 operator+(edk::uint16 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint8)n;edkEnd();
        return ret;
    }
    cubeui8 operator+(edk::uint64 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint8)n;edkEnd();
        return ret;
    }
    void operator+=(cubeui8 cube){
        //
        this->origin.x+=(edk::uint8)cube.origin.x;edkEnd();
        this->origin.y+=(edk::uint8)cube.origin.y;edkEnd();
        this->origin.z+=(edk::uint8)cube.origin.z;edkEnd();
        this->size.width+=(edk::uint8)cube.size.width;edkEnd();
        this->size.height+=(edk::uint8)cube.size.height;edkEnd();
        this->size.length+=(edk::uint8)cube.size.length;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint8)n;edkEnd();
        this->origin.y+=(edk::uint8)n;edkEnd();
        this->origin.z+=(edk::uint8)n;edkEnd();
        this->size.width+=(edk::uint8)n;edkEnd();
        this->size.height+=(edk::uint8)n;edkEnd();
        this->size.length+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint8)n;edkEnd();
        this->origin.y+=(edk::uint8)n;edkEnd();
        this->origin.z+=(edk::uint8)n;edkEnd();
        this->size.width+=(edk::uint8)n;edkEnd();
        this->size.height+=(edk::uint8)n;edkEnd();
        this->size.length+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint8)n;edkEnd();
        this->origin.y+=(edk::uint8)n;edkEnd();
        this->origin.z+=(edk::uint8)n;edkEnd();
        this->size.width+=(edk::uint8)n;edkEnd();
        this->size.height+=(edk::uint8)n;edkEnd();
        this->size.length+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint8)n;edkEnd();
        this->origin.y+=(edk::uint8)n;edkEnd();
        this->origin.z+=(edk::uint8)n;edkEnd();
        this->size.width+=(edk::uint8)n;edkEnd();
        this->size.height+=(edk::uint8)n;edkEnd();
        this->size.length+=(edk::uint8)n;edkEnd();
    }
    cubeui8 operator-(cubeui8 cube){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint8)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint8)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint8)cube.origin.z;edkEnd();
        ret.size.width=this->size.width-(edk::uint8)cube.size.width;edkEnd();
        ret.size.height=this->size.height-(edk::uint8)cube.size.height;edkEnd();
        ret.size.length=this->size.length-(edk::uint8)cube.size.length;edkEnd();
        return ret;
    }
    cubeui8 operator-(edk::uint8 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint8)n;edkEnd();
        return ret;
    }
    cubeui8 operator-(edk::uint32 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint8)n;edkEnd();
        return ret;
    }
    cubeui8 operator-(edk::uint16 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint8)n;edkEnd();
        return ret;
    }
    cubeui8 operator-(edk::uint64 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint8)n;edkEnd();
        return ret;
    }
    void operator-=(cubeui8 vec){
        //
        this->origin.x-=(edk::uint8)vec.origin.x;edkEnd();
        this->origin.y-=(edk::uint8)vec.origin.y;edkEnd();
        this->origin.z-=(edk::uint8)vec.origin.z;edkEnd();
        this->size.width-=(edk::uint8)vec.size.width;edkEnd();
        this->size.height-=(edk::uint8)vec.size.height;edkEnd();
        this->size.length-=(edk::uint8)vec.size.length;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint8)n;edkEnd();
        this->origin.y-=(edk::uint8)n;edkEnd();
        this->origin.z-=(edk::uint8)n;edkEnd();
        this->size.width-=(edk::uint8)n;edkEnd();
        this->size.height-=(edk::uint8)n;edkEnd();
        this->size.length-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint8)n;edkEnd();
        this->origin.y-=(edk::uint8)n;edkEnd();
        this->origin.z-=(edk::uint8)n;edkEnd();
        this->size.width-=(edk::uint8)n;edkEnd();
        this->size.height-=(edk::uint8)n;edkEnd();
        this->size.length-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint8)n;edkEnd();
        this->origin.y-=(edk::uint8)n;edkEnd();
        this->origin.z-=(edk::uint8)n;edkEnd();
        this->size.width-=(edk::uint8)n;edkEnd();
        this->size.height-=(edk::uint8)n;edkEnd();
        this->size.length-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint8)n;edkEnd();
        this->origin.y-=(edk::uint8)n;edkEnd();
        this->origin.z-=(edk::uint8)n;edkEnd();
        this->size.width-=(edk::uint8)n;edkEnd();
        this->size.height-=(edk::uint8)n;edkEnd();
        this->size.length-=(edk::uint8)n;edkEnd();
    }
    cubeui8 operator*(cubeui8 cube){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint8)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint8)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint8)cube.origin.z;edkEnd();
        ret.size.width=this->size.width*(edk::uint8)cube.size.width;edkEnd();
        ret.size.height=this->size.height*(edk::uint8)cube.size.height;edkEnd();
        ret.size.length=this->size.length*(edk::uint8)cube.size.length;edkEnd();
        return ret;
    }
    cubeui8 operator*(edk::uint8 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint8)n;edkEnd();
        return ret;
    }
    cubeui8 operator*(edk::uint32 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint8)n;edkEnd();
        return ret;
    }
    cubeui8 operator*(edk::uint16 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint8)n;edkEnd();
        return ret;
    }
    cubeui8 operator*(edk::uint64 n){
        //
        cubeui8 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint8)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint8)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint8)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint8)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint8)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint8)n;edkEnd();
        return ret;
    }
    void operator*=(cubeui8 cube){
        //
        this->origin.x*=(edk::uint8)cube.origin.x;edkEnd();
        this->origin.y*=(edk::uint8)cube.origin.y;edkEnd();
        this->origin.z*=(edk::uint8)cube.origin.z;edkEnd();
        this->size.width*=(edk::uint8)cube.size.width;edkEnd();
        this->size.height*=(edk::uint8)cube.size.height;edkEnd();
        this->size.length*=(edk::uint8)cube.size.length;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint8)n;edkEnd();
        this->origin.y*=(edk::uint8)n;edkEnd();
        this->origin.z*=(edk::uint8)n;edkEnd();
        this->size.width*=(edk::uint8)n;edkEnd();
        this->size.height*=(edk::uint8)n;edkEnd();
        this->size.length*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint8)n;edkEnd();
        this->origin.y*=(edk::uint8)n;edkEnd();
        this->origin.z*=(edk::uint8)n;edkEnd();
        this->size.width*=(edk::uint8)n;edkEnd();
        this->size.height*=(edk::uint8)n;edkEnd();
        this->size.length*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint8)n;edkEnd();
        this->origin.y*=(edk::uint8)n;edkEnd();
        this->origin.z*=(edk::uint8)n;edkEnd();
        this->size.width*=(edk::uint8)n;edkEnd();
        this->size.height*=(edk::uint8)n;edkEnd();
        this->size.length*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint8)n;edkEnd();
        this->origin.y*=(edk::uint8)n;edkEnd();
        this->origin.z*=(edk::uint8)n;edkEnd();
        this->size.width*=(edk::uint8)n;edkEnd();
        this->size.height*=(edk::uint8)n;edkEnd();
        this->size.length*=(edk::uint8)n;edkEnd();
    }
    //
    cubeui8 operator++(){
        //
        ++this->origin.x;edkEnd();
        ++this->origin.y;edkEnd();
        ++this->origin.z;edkEnd();
        ++this->size.width;edkEnd();
        ++this->size.height;edkEnd();
        ++this->size.length;edkEnd();
        return cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui8 operator++(edk::int32){
        //
        this->origin.x++;edkEnd();
        this->origin.y++;edkEnd();
        this->origin.z++;edkEnd();
        this->size.width++;edkEnd();
        this->size.height++;edkEnd();
        this->size.length++;edkEnd();
        return cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui8 operator--(){
        //
        --this->origin.x;edkEnd();
        --this->origin.y;edkEnd();
        --this->origin.z;edkEnd();
        --this->size.width;edkEnd();
        --this->size.height;edkEnd();
        --this->size.length;edkEnd();
        return cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui8 operator--(edk::int32){
        //
        this->origin.x--;edkEnd();
        this->origin.y--;edkEnd();
        this->origin.z--;edkEnd();
        this->size.width--;edkEnd();
        this->size.height--;edkEnd();
        this->size.length--;edkEnd();
        return cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);edkEnd();
    }
    cubeui8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint8)x;edkEnd();
        this->origin.y=(edk::uint8)y;edkEnd();
        this->origin.z=(edk::uint8)z;edkEnd();
        this->size.width=(edk::uint8)width;edkEnd();
        this->size.height=(edk::uint8)height;edkEnd();
        this->size.length=(edk::uint8)length;edkEnd();
        return cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);edkEnd();
    }
    cubeui8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint8)x;edkEnd();
        this->origin.y=(edk::uint8)y;edkEnd();
        this->origin.z=(edk::uint8)z;edkEnd();
        this->size.width=(edk::uint8)width;edkEnd();
        this->size.height=(edk::uint8)height;edkEnd();
        this->size.length=(edk::uint8)length;edkEnd();
        return cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);edkEnd();
    }
    cubeui8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint8)x;edkEnd();
        this->origin.y=(edk::uint8)y;edkEnd();
        this->origin.z=(edk::uint8)z;edkEnd();
        this->size.width=(edk::uint8)width;edkEnd();
        this->size.height=(edk::uint8)height;edkEnd();
        this->size.length=(edk::uint8)length;edkEnd();
        return cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);edkEnd();
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
        this->origin.x=(edk::uint16)0;edkEnd();
        this->origin.y=(edk::uint16)0;edkEnd();
        this->origin.z=(edk::uint16)0;edkEnd();
        this->size.width=(edk::uint16)0;edkEnd();
        this->size.height=(edk::uint16)0;edkEnd();
        this->size.length=(edk::uint16)0;edkEnd();
    }
    cubeui16(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::uint16)x;edkEnd();
        this->origin.y=(edk::uint16)y;edkEnd();
        this->origin.z=(edk::uint16)z;edkEnd();
        this->size.width=(edk::uint16)width;edkEnd();
        this->size.height=(edk::uint16)height;edkEnd();
        this->size.length=(edk::uint16)length;edkEnd();
    }
    cubeui16(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint16)x;edkEnd();
        this->origin.y=(edk::uint16)y;edkEnd();
        this->origin.z=(edk::uint16)z;edkEnd();
        this->size.width=(edk::uint16)width;edkEnd();
        this->size.height=(edk::uint16)height;edkEnd();
        this->size.length=(edk::uint16)length;edkEnd();
    }
    cubeui16(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint16)x;edkEnd();
        this->origin.y=(edk::uint16)y;edkEnd();
        this->origin.z=(edk::uint16)z;edkEnd();
        this->size.width=(edk::uint16)width;edkEnd();
        this->size.height=(edk::uint16)height;edkEnd();
        this->size.length=(edk::uint16)length;edkEnd();
    }
    cubeui16(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint16)x;edkEnd();
        this->origin.y=(edk::uint16)y;edkEnd();
        this->origin.z=(edk::uint16)z;edkEnd();
        this->size.width=(edk::uint16)width;edkEnd();
        this->size.height=(edk::uint16)height;edkEnd();
        this->size.length=(edk::uint16)length;edkEnd();
    }
    cubeui16(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::uint16)origin.x;edkEnd();
        this->origin.y=(edk::uint16)origin.y;edkEnd();
        this->origin.z=(edk::uint16)origin.z;edkEnd();
        this->size.width=(edk::uint16)size.width;edkEnd();
        this->size.height=(edk::uint16)size.height;edkEnd();
        this->size.length=(edk::uint16)size.length;edkEnd();
    }
    cubeui16(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::uint16)origin.x;edkEnd();
        this->origin.y=(edk::uint16)origin.y;edkEnd();
        this->origin.z=(edk::uint16)origin.z;edkEnd();
        this->size.width=(edk::uint16)size.width;edkEnd();
        this->size.height=(edk::uint16)size.height;edkEnd();
        this->size.length=(edk::uint16)size.length;edkEnd();
    }
    cubeui16(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::uint16)origin.x;edkEnd();
        this->origin.y=(edk::uint16)origin.y;edkEnd();
        this->origin.z=(edk::uint16)origin.z;edkEnd();
        this->size.width=(edk::uint16)size.width;edkEnd();
        this->size.height=(edk::uint16)size.height;edkEnd();
        this->size.length=(edk::uint16)size.length;edkEnd();
    }
    cubeui16(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::uint16)origin.x;edkEnd();
        this->origin.y=(edk::uint16)origin.y;edkEnd();
        this->origin.z=(edk::uint16)origin.z;edkEnd();
        this->size.width=(edk::uint16)size.width;edkEnd();
        this->size.height=(edk::uint16)size.height;edkEnd();
        this->size.length=(edk::uint16)size.length;edkEnd();
    }

    //operators
    cubeui16 operator=(cubeui16 cube){
        //
        this->origin.x=(edk::uint16)cube.origin.x;edkEnd();
        this->origin.y=(edk::uint16)cube.origin.y;edkEnd();
        this->origin.z=(edk::uint16)cube.origin.z;edkEnd();
        this->size.width=(edk::uint16)cube.size.width;edkEnd();
        this->size.height=(edk::uint16)cube.size.height;edkEnd();
        this->size.length=(edk::uint16)cube.size.length;edkEnd();
        return *this;edkEnd();
    }
    cubeui16 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint16)n;edkEnd();
        this->origin.y=(edk::uint16)n;edkEnd();
        this->origin.z=(edk::uint16)n;edkEnd();
        this->size.width=(edk::uint16)n;edkEnd();
        this->size.height=(edk::uint16)n;edkEnd();
        this->size.length=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui16 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint16)n;edkEnd();
        this->origin.y=(edk::uint16)n;edkEnd();
        this->origin.z=(edk::uint16)n;edkEnd();
        this->size.width=(edk::uint16)n;edkEnd();
        this->size.height=(edk::uint16)n;edkEnd();
        this->size.length=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui16 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint16)n;edkEnd();
        this->origin.y=(edk::uint16)n;edkEnd();
        this->origin.z=(edk::uint16)n;edkEnd();
        this->size.width=(edk::uint16)n;edkEnd();
        this->size.height=(edk::uint16)n;edkEnd();
        this->size.length=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui16 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint16)n;edkEnd();
        this->origin.y=(edk::uint16)n;edkEnd();
        this->origin.z=(edk::uint16)n;edkEnd();
        this->size.width=(edk::uint16)n;edkEnd();
        this->size.height=(edk::uint16)n;edkEnd();
        this->size.length=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }

    bool operator==(cubeui16 cube){
        //
        return (this->origin.x==(edk::uint16)cube.origin.x
                &&this->origin.y==(edk::uint16)cube.origin.y
                &&this->origin.z==(edk::uint16)cube.origin.z
                &&this->size.width==(edk::uint16)cube.size.width
                &&this->size.height==(edk::uint16)cube.size.height
                &&this->size.length==(edk::uint16)cube.size.length
                );edkEnd();
    }
    bool operator!=(cubeui16 cube){
        //
        return (this->origin.x!=(edk::uint16)cube.origin.x
                ||this->origin.y!=(edk::uint16)cube.origin.y
                ||this->origin.z!=(edk::uint16)cube.origin.z
                ||this->size.width!=(edk::uint16)cube.size.width
                ||this->size.height!=(edk::uint16)cube.size.height
                ||this->size.length!=(edk::uint16)cube.size.length
                );edkEnd();
    }
    cubeui16 operator+(cubeui16 cube){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint16)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint16)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint16)cube.origin.z;edkEnd();
        ret.size.width=this->size.width+(edk::uint16)cube.size.width;edkEnd();
        ret.size.height=this->size.height+(edk::uint16)cube.size.height;edkEnd();
        ret.size.length=this->size.length+(edk::uint16)cube.size.length;edkEnd();
        return ret;
    }
    cubeui16 operator+(edk::uint8 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint16)n;edkEnd();
        return ret;
    }
    cubeui16 operator+(edk::uint32 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint16)n;edkEnd();
        return ret;
    }
    cubeui16 operator+(edk::uint16 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint16)n;edkEnd();
        return ret;
    }
    cubeui16 operator+(edk::uint64 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint16)n;edkEnd();
        return ret;
    }
    void operator+=(cubeui16 cube){
        //
        this->origin.x+=(edk::uint16)cube.origin.x;edkEnd();
        this->origin.y+=(edk::uint16)cube.origin.y;edkEnd();
        this->origin.z+=(edk::uint16)cube.origin.z;edkEnd();
        this->size.width+=(edk::uint16)cube.size.width;edkEnd();
        this->size.height+=(edk::uint16)cube.size.height;edkEnd();
        this->size.length+=(edk::uint16)cube.size.length;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint16)n;edkEnd();
        this->origin.y+=(edk::uint16)n;edkEnd();
        this->origin.z+=(edk::uint16)n;edkEnd();
        this->size.width+=(edk::uint16)n;edkEnd();
        this->size.height+=(edk::uint16)n;edkEnd();
        this->size.length+=(edk::uint16)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint16)n;edkEnd();
        this->origin.y+=(edk::uint16)n;edkEnd();
        this->origin.z+=(edk::uint16)n;edkEnd();
        this->size.width+=(edk::uint16)n;edkEnd();
        this->size.height+=(edk::uint16)n;edkEnd();
        this->size.length+=(edk::uint16)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint16)n;edkEnd();
        this->origin.y+=(edk::uint16)n;edkEnd();
        this->origin.z+=(edk::uint16)n;edkEnd();
        this->size.width+=(edk::uint16)n;edkEnd();
        this->size.height+=(edk::uint16)n;edkEnd();
        this->size.length+=(edk::uint16)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint16)n;edkEnd();
        this->origin.y+=(edk::uint16)n;edkEnd();
        this->origin.z+=(edk::uint16)n;edkEnd();
        this->size.width+=(edk::uint16)n;edkEnd();
        this->size.height+=(edk::uint16)n;edkEnd();
        this->size.length+=(edk::uint16)n;edkEnd();
    }
    cubeui16 operator-(cubeui16 cube){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint16)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint16)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint16)cube.origin.z;edkEnd();
        ret.size.width=this->size.width-(edk::uint16)cube.size.width;edkEnd();
        ret.size.height=this->size.height-(edk::uint16)cube.size.height;edkEnd();
        ret.size.length=this->size.length-(edk::uint16)cube.size.length;edkEnd();
        return ret;
    }
    cubeui16 operator-(edk::uint8 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint16)n;edkEnd();
        return ret;
    }
    cubeui16 operator-(edk::uint32 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint16)n;edkEnd();
        return ret;
    }
    cubeui16 operator-(edk::uint16 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint16)n;edkEnd();
        return ret;
    }
    cubeui16 operator-(edk::uint64 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint16)n;edkEnd();
        return ret;
    }
    void operator-=(cubeui16 vec){
        //
        this->origin.x-=(edk::uint16)vec.origin.x;edkEnd();
        this->origin.y-=(edk::uint16)vec.origin.y;edkEnd();
        this->origin.z-=(edk::uint16)vec.origin.z;edkEnd();
        this->size.width-=(edk::uint16)vec.size.width;edkEnd();
        this->size.height-=(edk::uint16)vec.size.height;edkEnd();
        this->size.length-=(edk::uint16)vec.size.length;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint16)n;edkEnd();
        this->origin.y-=(edk::uint16)n;edkEnd();
        this->origin.z-=(edk::uint16)n;edkEnd();
        this->size.width-=(edk::uint16)n;edkEnd();
        this->size.height-=(edk::uint16)n;edkEnd();
        this->size.length-=(edk::uint16)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint16)n;edkEnd();
        this->origin.y-=(edk::uint16)n;edkEnd();
        this->origin.z-=(edk::uint16)n;edkEnd();
        this->size.width-=(edk::uint16)n;edkEnd();
        this->size.height-=(edk::uint16)n;edkEnd();
        this->size.length-=(edk::uint16)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint16)n;edkEnd();
        this->origin.y-=(edk::uint16)n;edkEnd();
        this->origin.z-=(edk::uint16)n;edkEnd();
        this->size.width-=(edk::uint16)n;edkEnd();
        this->size.height-=(edk::uint16)n;edkEnd();
        this->size.length-=(edk::uint16)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint16)n;edkEnd();
        this->origin.y-=(edk::uint16)n;edkEnd();
        this->origin.z-=(edk::uint16)n;edkEnd();
        this->size.width-=(edk::uint16)n;edkEnd();
        this->size.height-=(edk::uint16)n;edkEnd();
        this->size.length-=(edk::uint16)n;edkEnd();
    }
    cubeui16 operator*(cubeui16 cube){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint16)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint16)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint16)cube.origin.z;edkEnd();
        ret.size.width=this->size.width*(edk::uint16)cube.size.width;edkEnd();
        ret.size.height=this->size.height*(edk::uint16)cube.size.height;edkEnd();
        ret.size.length=this->size.length*(edk::uint16)cube.size.length;edkEnd();
        return ret;
    }
    cubeui16 operator*(edk::uint8 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint16)n;edkEnd();
        return ret;
    }
    cubeui16 operator*(edk::uint32 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint16)n;edkEnd();
        return ret;
    }
    cubeui16 operator*(edk::uint16 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint16)n;edkEnd();
        return ret;
    }
    cubeui16 operator*(edk::uint64 n){
        //
        cubeui16 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint16)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint16)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint16)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint16)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint16)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint16)n;edkEnd();
        return ret;
    }
    void operator*=(cubeui16 cube){
        //
        this->origin.x*=(edk::uint16)cube.origin.x;edkEnd();
        this->origin.y*=(edk::uint16)cube.origin.y;edkEnd();
        this->origin.z*=(edk::uint16)cube.origin.z;edkEnd();
        this->size.width*=(edk::uint16)cube.size.width;edkEnd();
        this->size.height*=(edk::uint16)cube.size.height;edkEnd();
        this->size.length*=(edk::uint16)cube.size.length;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint16)n;edkEnd();
        this->origin.y*=(edk::uint16)n;edkEnd();
        this->origin.z*=(edk::uint16)n;edkEnd();
        this->size.width*=(edk::uint16)n;edkEnd();
        this->size.height*=(edk::uint16)n;edkEnd();
        this->size.length*=(edk::uint16)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint16)n;edkEnd();
        this->origin.y*=(edk::uint16)n;edkEnd();
        this->origin.z*=(edk::uint16)n;edkEnd();
        this->size.width*=(edk::uint16)n;edkEnd();
        this->size.height*=(edk::uint16)n;edkEnd();
        this->size.length*=(edk::uint16)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint16)n;edkEnd();
        this->origin.y*=(edk::uint16)n;edkEnd();
        this->origin.z*=(edk::uint16)n;edkEnd();
        this->size.width*=(edk::uint16)n;edkEnd();
        this->size.height*=(edk::uint16)n;edkEnd();
        this->size.length*=(edk::uint16)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint16)n;edkEnd();
        this->origin.y*=(edk::uint16)n;edkEnd();
        this->origin.z*=(edk::uint16)n;edkEnd();
        this->size.width*=(edk::uint16)n;edkEnd();
        this->size.height*=(edk::uint16)n;edkEnd();
        this->size.length*=(edk::uint16)n;edkEnd();
    }
    //
    cubeui16 operator++(){
        //
        ++this->origin.x;edkEnd();
        ++this->origin.y;edkEnd();
        ++this->origin.z;edkEnd();
        ++this->size.width;edkEnd();
        ++this->size.height;edkEnd();
        ++this->size.length;edkEnd();
        return cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui16 operator++(edk::int32){
        //
        this->origin.x++;edkEnd();
        this->origin.y++;edkEnd();
        this->origin.z++;edkEnd();
        this->size.width++;edkEnd();
        this->size.height++;edkEnd();
        this->size.length++;edkEnd();
        return cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui16 operator--(){
        //
        --this->origin.x;edkEnd();
        --this->origin.y;edkEnd();
        --this->origin.z;edkEnd();
        --this->size.width;edkEnd();
        --this->size.height;edkEnd();
        --this->size.length;edkEnd();
        return cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui16 operator--(edk::int32){
        //
        this->origin.x--;edkEnd();
        this->origin.y--;edkEnd();
        this->origin.z--;edkEnd();
        this->size.width--;edkEnd();
        this->size.height--;edkEnd();
        this->size.length--;edkEnd();
        return cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);edkEnd();
    }
    cubeui16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint16)x;edkEnd();
        this->origin.y=(edk::uint16)y;edkEnd();
        this->origin.z=(edk::uint16)z;edkEnd();
        this->size.width=(edk::uint16)width;edkEnd();
        this->size.height=(edk::uint16)height;edkEnd();
        this->size.length=(edk::uint16)length;edkEnd();
        return cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);edkEnd();
    }
    cubeui16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint16)x;edkEnd();
        this->origin.y=(edk::uint16)y;edkEnd();
        this->origin.z=(edk::uint16)z;edkEnd();
        this->size.width=(edk::uint16)width;edkEnd();
        this->size.height=(edk::uint16)height;edkEnd();
        this->size.length=(edk::uint16)length;edkEnd();
        return cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);edkEnd();
    }
    cubeui16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint16)x;edkEnd();
        this->origin.y=(edk::uint16)y;edkEnd();
        this->origin.z=(edk::uint16)z;edkEnd();
        this->size.width=(edk::uint16)width;edkEnd();
        this->size.height=(edk::uint16)height;edkEnd();
        this->size.length=(edk::uint16)length;edkEnd();
        return cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);edkEnd();
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
        this->origin.x=(edk::uint32)0;edkEnd();
        this->origin.y=(edk::uint32)0;edkEnd();
        this->origin.z=(edk::uint32)0;edkEnd();
        this->size.width=(edk::uint32)0;edkEnd();
        this->size.height=(edk::uint32)0;edkEnd();
        this->size.length=(edk::uint32)0;edkEnd();
    }
    cubeui32(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::uint32)x;edkEnd();
        this->origin.y=(edk::uint32)y;edkEnd();
        this->origin.z=(edk::uint32)z;edkEnd();
        this->size.width=(edk::uint32)width;edkEnd();
        this->size.height=(edk::uint32)height;edkEnd();
        this->size.length=(edk::uint32)length;edkEnd();
    }
    cubeui32(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint32)x;edkEnd();
        this->origin.y=(edk::uint32)y;edkEnd();
        this->origin.z=(edk::uint32)z;edkEnd();
        this->size.width=(edk::uint32)width;edkEnd();
        this->size.height=(edk::uint32)height;edkEnd();
        this->size.length=(edk::uint32)length;edkEnd();
    }
    cubeui32(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint32)x;edkEnd();
        this->origin.y=(edk::uint32)y;edkEnd();
        this->origin.z=(edk::uint32)z;edkEnd();
        this->size.width=(edk::uint32)width;edkEnd();
        this->size.height=(edk::uint32)height;edkEnd();
        this->size.length=(edk::uint32)length;edkEnd();
    }
    cubeui32(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint32)x;edkEnd();
        this->origin.y=(edk::uint32)y;edkEnd();
        this->origin.z=(edk::uint32)z;edkEnd();
        this->size.width=(edk::uint32)width;edkEnd();
        this->size.height=(edk::uint32)height;edkEnd();
        this->size.length=(edk::uint32)length;edkEnd();
    }
    cubeui32(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::uint32)origin.x;edkEnd();
        this->origin.y=(edk::uint32)origin.y;edkEnd();
        this->origin.z=(edk::uint32)origin.z;edkEnd();
        this->size.width=(edk::uint32)size.width;edkEnd();
        this->size.height=(edk::uint32)size.height;edkEnd();
        this->size.length=(edk::uint32)size.length;edkEnd();
    }
    cubeui32(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::uint32)origin.x;edkEnd();
        this->origin.y=(edk::uint32)origin.y;edkEnd();
        this->origin.z=(edk::uint32)origin.z;edkEnd();
        this->size.width=(edk::uint32)size.width;edkEnd();
        this->size.height=(edk::uint32)size.height;edkEnd();
        this->size.length=(edk::uint32)size.length;edkEnd();
    }
    cubeui32(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::uint32)origin.x;edkEnd();
        this->origin.y=(edk::uint32)origin.y;edkEnd();
        this->origin.z=(edk::uint32)origin.z;edkEnd();
        this->size.width=(edk::uint32)size.width;edkEnd();
        this->size.height=(edk::uint32)size.height;edkEnd();
        this->size.length=(edk::uint32)size.length;edkEnd();
    }
    cubeui32(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::uint32)origin.x;edkEnd();
        this->origin.y=(edk::uint32)origin.y;edkEnd();
        this->origin.z=(edk::uint32)origin.z;edkEnd();
        this->size.width=(edk::uint32)size.width;edkEnd();
        this->size.height=(edk::uint32)size.height;edkEnd();
        this->size.length=(edk::uint32)size.length;edkEnd();
    }

    //operators
    cubeui32 operator=(cubeui32 cube){
        //
        this->origin.x=(edk::uint32)cube.origin.x;edkEnd();
        this->origin.y=(edk::uint32)cube.origin.y;edkEnd();
        this->origin.z=(edk::uint32)cube.origin.z;edkEnd();
        this->size.width=(edk::uint32)cube.size.width;edkEnd();
        this->size.height=(edk::uint32)cube.size.height;edkEnd();
        this->size.length=(edk::uint32)cube.size.length;edkEnd();
        return *this;edkEnd();
    }
    cubeui32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint32)n;edkEnd();
        this->origin.y=(edk::uint32)n;edkEnd();
        this->origin.z=(edk::uint32)n;edkEnd();
        this->size.width=(edk::uint32)n;edkEnd();
        this->size.height=(edk::uint32)n;edkEnd();
        this->size.length=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint32)n;edkEnd();
        this->origin.y=(edk::uint32)n;edkEnd();
        this->origin.z=(edk::uint32)n;edkEnd();
        this->size.width=(edk::uint32)n;edkEnd();
        this->size.height=(edk::uint32)n;edkEnd();
        this->size.length=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint32)n;edkEnd();
        this->origin.y=(edk::uint32)n;edkEnd();
        this->origin.z=(edk::uint32)n;edkEnd();
        this->size.width=(edk::uint32)n;edkEnd();
        this->size.height=(edk::uint32)n;edkEnd();
        this->size.length=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint32)n;edkEnd();
        this->origin.y=(edk::uint32)n;edkEnd();
        this->origin.z=(edk::uint32)n;edkEnd();
        this->size.width=(edk::uint32)n;edkEnd();
        this->size.height=(edk::uint32)n;edkEnd();
        this->size.length=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }

    bool operator==(cubeui32 cube){
        //
        return (this->origin.x==(edk::uint32)cube.origin.x
                &&this->origin.y==(edk::uint32)cube.origin.y
                &&this->origin.z==(edk::uint32)cube.origin.z
                &&this->size.width==(edk::uint32)cube.size.width
                &&this->size.height==(edk::uint32)cube.size.height
                &&this->size.length==(edk::uint32)cube.size.length
                );edkEnd();
    }
    bool operator!=(cubeui32 cube){
        //
        return (this->origin.x!=(edk::uint32)cube.origin.x
                ||this->origin.y!=(edk::uint32)cube.origin.y
                ||this->origin.z!=(edk::uint32)cube.origin.z
                ||this->size.width!=(edk::uint32)cube.size.width
                ||this->size.height!=(edk::uint32)cube.size.height
                ||this->size.length!=(edk::uint32)cube.size.length
                );edkEnd();
    }
    cubeui32 operator+(cubeui32 cube){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint32)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint32)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint32)cube.origin.z;edkEnd();
        ret.size.width=this->size.width+(edk::uint32)cube.size.width;edkEnd();
        ret.size.height=this->size.height+(edk::uint32)cube.size.height;edkEnd();
        ret.size.length=this->size.length+(edk::uint32)cube.size.length;edkEnd();
        return ret;
    }
    cubeui32 operator+(edk::uint8 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint32)n;edkEnd();
        return ret;
    }
    cubeui32 operator+(edk::uint32 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint32)n;edkEnd();
        return ret;
    }
    cubeui32 operator+(edk::uint16 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint32)n;edkEnd();
        return ret;
    }
    cubeui32 operator+(edk::uint64 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint32)n;edkEnd();
        return ret;
    }
    void operator+=(cubeui32 cube){
        //
        this->origin.x+=(edk::uint32)cube.origin.x;edkEnd();
        this->origin.y+=(edk::uint32)cube.origin.y;edkEnd();
        this->origin.z+=(edk::uint32)cube.origin.z;edkEnd();
        this->size.width+=(edk::uint32)cube.size.width;edkEnd();
        this->size.height+=(edk::uint32)cube.size.height;edkEnd();
        this->size.length+=(edk::uint32)cube.size.length;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint32)n;edkEnd();
        this->origin.y+=(edk::uint32)n;edkEnd();
        this->origin.z+=(edk::uint32)n;edkEnd();
        this->size.width+=(edk::uint32)n;edkEnd();
        this->size.height+=(edk::uint32)n;edkEnd();
        this->size.length+=(edk::uint32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint32)n;edkEnd();
        this->origin.y+=(edk::uint32)n;edkEnd();
        this->origin.z+=(edk::uint32)n;edkEnd();
        this->size.width+=(edk::uint32)n;edkEnd();
        this->size.height+=(edk::uint32)n;edkEnd();
        this->size.length+=(edk::uint32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint32)n;edkEnd();
        this->origin.y+=(edk::uint32)n;edkEnd();
        this->origin.z+=(edk::uint32)n;edkEnd();
        this->size.width+=(edk::uint32)n;edkEnd();
        this->size.height+=(edk::uint32)n;edkEnd();
        this->size.length+=(edk::uint32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint32)n;edkEnd();
        this->origin.y+=(edk::uint32)n;edkEnd();
        this->origin.z+=(edk::uint32)n;edkEnd();
        this->size.width+=(edk::uint32)n;edkEnd();
        this->size.height+=(edk::uint32)n;edkEnd();
        this->size.length+=(edk::uint32)n;edkEnd();
    }
    cubeui32 operator-(cubeui32 cube){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint32)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint32)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint32)cube.origin.z;edkEnd();
        ret.size.width=this->size.width-(edk::uint32)cube.size.width;edkEnd();
        ret.size.height=this->size.height-(edk::uint32)cube.size.height;edkEnd();
        ret.size.length=this->size.length-(edk::uint32)cube.size.length;edkEnd();
        return ret;
    }
    cubeui32 operator-(edk::uint8 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint32)n;edkEnd();
        return ret;
    }
    cubeui32 operator-(edk::uint32 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint32)n;edkEnd();
        return ret;
    }
    cubeui32 operator-(edk::uint16 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint32)n;edkEnd();
        return ret;
    }
    cubeui32 operator-(edk::uint64 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint32)n;edkEnd();
        return ret;
    }
    void operator-=(cubeui32 vec){
        //
        this->origin.x-=(edk::uint32)vec.origin.x;edkEnd();
        this->origin.y-=(edk::uint32)vec.origin.y;edkEnd();
        this->origin.z-=(edk::uint32)vec.origin.z;edkEnd();
        this->size.width-=(edk::uint32)vec.size.width;edkEnd();
        this->size.height-=(edk::uint32)vec.size.height;edkEnd();
        this->size.length-=(edk::uint32)vec.size.length;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint32)n;edkEnd();
        this->origin.y-=(edk::uint32)n;edkEnd();
        this->origin.z-=(edk::uint32)n;edkEnd();
        this->size.width-=(edk::uint32)n;edkEnd();
        this->size.height-=(edk::uint32)n;edkEnd();
        this->size.length-=(edk::uint32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint32)n;edkEnd();
        this->origin.y-=(edk::uint32)n;edkEnd();
        this->origin.z-=(edk::uint32)n;edkEnd();
        this->size.width-=(edk::uint32)n;edkEnd();
        this->size.height-=(edk::uint32)n;edkEnd();
        this->size.length-=(edk::uint32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint32)n;edkEnd();
        this->origin.y-=(edk::uint32)n;edkEnd();
        this->origin.z-=(edk::uint32)n;edkEnd();
        this->size.width-=(edk::uint32)n;edkEnd();
        this->size.height-=(edk::uint32)n;edkEnd();
        this->size.length-=(edk::uint32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint32)n;edkEnd();
        this->origin.y-=(edk::uint32)n;edkEnd();
        this->origin.z-=(edk::uint32)n;edkEnd();
        this->size.width-=(edk::uint32)n;edkEnd();
        this->size.height-=(edk::uint32)n;edkEnd();
        this->size.length-=(edk::uint32)n;edkEnd();
    }
    cubeui32 operator*(cubeui32 cube){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint32)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint32)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint32)cube.origin.z;edkEnd();
        ret.size.width=this->size.width*(edk::uint32)cube.size.width;edkEnd();
        ret.size.height=this->size.height*(edk::uint32)cube.size.height;edkEnd();
        ret.size.length=this->size.length*(edk::uint32)cube.size.length;edkEnd();
        return ret;
    }
    cubeui32 operator*(edk::uint8 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint32)n;edkEnd();
        return ret;
    }
    cubeui32 operator*(edk::uint32 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint32)n;edkEnd();
        return ret;
    }
    cubeui32 operator*(edk::uint16 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint32)n;edkEnd();
        return ret;
    }
    cubeui32 operator*(edk::uint64 n){
        //
        cubeui32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint32)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint32)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint32)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint32)n;edkEnd();
        return ret;
    }
    void operator*=(cubeui32 cube){
        //
        this->origin.x*=(edk::uint32)cube.origin.x;edkEnd();
        this->origin.y*=(edk::uint32)cube.origin.y;edkEnd();
        this->origin.z*=(edk::uint32)cube.origin.z;edkEnd();
        this->size.width*=(edk::uint32)cube.size.width;edkEnd();
        this->size.height*=(edk::uint32)cube.size.height;edkEnd();
        this->size.length*=(edk::uint32)cube.size.length;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint32)n;edkEnd();
        this->origin.y*=(edk::uint32)n;edkEnd();
        this->origin.z*=(edk::uint32)n;edkEnd();
        this->size.width*=(edk::uint32)n;edkEnd();
        this->size.height*=(edk::uint32)n;edkEnd();
        this->size.length*=(edk::uint32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint32)n;edkEnd();
        this->origin.y*=(edk::uint32)n;edkEnd();
        this->origin.z*=(edk::uint32)n;edkEnd();
        this->size.width*=(edk::uint32)n;edkEnd();
        this->size.height*=(edk::uint32)n;edkEnd();
        this->size.length*=(edk::uint32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint32)n;edkEnd();
        this->origin.y*=(edk::uint32)n;edkEnd();
        this->origin.z*=(edk::uint32)n;edkEnd();
        this->size.width*=(edk::uint32)n;edkEnd();
        this->size.height*=(edk::uint32)n;edkEnd();
        this->size.length*=(edk::uint32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint32)n;edkEnd();
        this->origin.y*=(edk::uint32)n;edkEnd();
        this->origin.z*=(edk::uint32)n;edkEnd();
        this->size.width*=(edk::uint32)n;edkEnd();
        this->size.height*=(edk::uint32)n;edkEnd();
        this->size.length*=(edk::uint32)n;edkEnd();
    }
    //
    cubeui32 operator++(){
        //
        ++this->origin.x;edkEnd();
        ++this->origin.y;edkEnd();
        ++this->origin.z;edkEnd();
        ++this->size.width;edkEnd();
        ++this->size.height;edkEnd();
        ++this->size.length;edkEnd();
        return cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui32 operator++(edk::int32){
        //
        this->origin.x++;edkEnd();
        this->origin.y++;edkEnd();
        this->origin.z++;edkEnd();
        this->size.width++;edkEnd();
        this->size.height++;edkEnd();
        this->size.length++;edkEnd();
        return cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui32 operator--(){
        //
        --this->origin.x;edkEnd();
        --this->origin.y;edkEnd();
        --this->origin.z;edkEnd();
        --this->size.width;edkEnd();
        --this->size.height;edkEnd();
        --this->size.length;edkEnd();
        return cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui32 operator--(edk::int32){
        //
        this->origin.x--;edkEnd();
        this->origin.y--;edkEnd();
        this->origin.z--;edkEnd();
        this->size.width--;edkEnd();
        this->size.height--;edkEnd();
        this->size.length--;edkEnd();
        return cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);edkEnd();
    }
    cubeui32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint32)x;edkEnd();
        this->origin.y=(edk::uint32)y;edkEnd();
        this->origin.z=(edk::uint32)z;edkEnd();
        this->size.width=(edk::uint32)width;edkEnd();
        this->size.height=(edk::uint32)height;edkEnd();
        this->size.length=(edk::uint32)length;edkEnd();
        return cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);edkEnd();
    }
    cubeui32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint32)x;edkEnd();
        this->origin.y=(edk::uint32)y;edkEnd();
        this->origin.z=(edk::uint32)z;edkEnd();
        this->size.width=(edk::uint32)width;edkEnd();
        this->size.height=(edk::uint32)height;edkEnd();
        this->size.length=(edk::uint32)length;edkEnd();
        return cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);edkEnd();
    }
    cubeui32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint32)x;edkEnd();
        this->origin.y=(edk::uint32)y;edkEnd();
        this->origin.z=(edk::uint32)z;edkEnd();
        this->size.width=(edk::uint32)width;edkEnd();
        this->size.height=(edk::uint32)height;edkEnd();
        this->size.length=(edk::uint32)length;edkEnd();
        return cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);edkEnd();
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
        this->origin.x=(edk::uint64)0;edkEnd();
        this->origin.y=(edk::uint64)0;edkEnd();
        this->origin.z=(edk::uint64)0;edkEnd();
        this->size.width=(edk::uint64)0;edkEnd();
        this->size.height=(edk::uint64)0;edkEnd();
        this->size.length=(edk::uint64)0;edkEnd();
    }
    cubeui64(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::uint64)x;edkEnd();
        this->origin.y=(edk::uint64)y;edkEnd();
        this->origin.z=(edk::uint64)z;edkEnd();
        this->size.width=(edk::uint64)width;edkEnd();
        this->size.height=(edk::uint64)height;edkEnd();
        this->size.length=(edk::uint64)length;edkEnd();
    }
    cubeui64(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint64)x;edkEnd();
        this->origin.y=(edk::uint64)y;edkEnd();
        this->origin.z=(edk::uint64)z;edkEnd();
        this->size.width=(edk::uint64)width;edkEnd();
        this->size.height=(edk::uint64)height;edkEnd();
        this->size.length=(edk::uint64)length;edkEnd();
    }
    cubeui64(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint64)x;edkEnd();
        this->origin.y=(edk::uint64)y;edkEnd();
        this->origin.z=(edk::uint64)z;edkEnd();
        this->size.width=(edk::uint64)width;edkEnd();
        this->size.height=(edk::uint64)height;edkEnd();
        this->size.length=(edk::uint64)length;edkEnd();
    }
    cubeui64(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint64)x;edkEnd();
        this->origin.y=(edk::uint64)y;edkEnd();
        this->origin.z=(edk::uint64)z;edkEnd();
        this->size.width=(edk::uint64)width;edkEnd();
        this->size.height=(edk::uint64)height;edkEnd();
        this->size.length=(edk::uint64)length;edkEnd();
    }
    cubeui64(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::uint64)origin.x;edkEnd();
        this->origin.y=(edk::uint64)origin.y;edkEnd();
        this->origin.z=(edk::uint64)origin.z;edkEnd();
        this->size.width=(edk::uint64)size.width;edkEnd();
        this->size.height=(edk::uint64)size.height;edkEnd();
        this->size.length=(edk::uint64)size.length;edkEnd();
    }
    cubeui64(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::uint64)origin.x;edkEnd();
        this->origin.y=(edk::uint64)origin.y;edkEnd();
        this->origin.z=(edk::uint64)origin.z;edkEnd();
        this->size.width=(edk::uint64)size.width;edkEnd();
        this->size.height=(edk::uint64)size.height;edkEnd();
        this->size.length=(edk::uint64)size.length;edkEnd();
    }
    cubeui64(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::uint64)origin.x;edkEnd();
        this->origin.y=(edk::uint64)origin.y;edkEnd();
        this->origin.z=(edk::uint64)origin.z;edkEnd();
        this->size.width=(edk::uint64)size.width;edkEnd();
        this->size.height=(edk::uint64)size.height;edkEnd();
        this->size.length=(edk::uint64)size.length;edkEnd();
    }
    cubeui64(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::uint64)origin.x;edkEnd();
        this->origin.y=(edk::uint64)origin.y;edkEnd();
        this->origin.z=(edk::uint64)origin.z;edkEnd();
        this->size.width=(edk::uint64)size.width;edkEnd();
        this->size.height=(edk::uint64)size.height;edkEnd();
        this->size.length=(edk::uint64)size.length;edkEnd();
    }

    //operators
    cubeui64 operator=(cubeui64 cube){
        //
        this->origin.x=(edk::uint64)cube.origin.x;edkEnd();
        this->origin.y=(edk::uint64)cube.origin.y;edkEnd();
        this->origin.z=(edk::uint64)cube.origin.z;edkEnd();
        this->size.width=(edk::uint64)cube.size.width;edkEnd();
        this->size.height=(edk::uint64)cube.size.height;edkEnd();
        this->size.length=(edk::uint64)cube.size.length;edkEnd();
        return *this;edkEnd();
    }
    cubeui64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint64)n;edkEnd();
        this->origin.y=(edk::uint64)n;edkEnd();
        this->origin.z=(edk::uint64)n;edkEnd();
        this->size.width=(edk::uint64)n;edkEnd();
        this->size.height=(edk::uint64)n;edkEnd();
        this->size.length=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint64)n;edkEnd();
        this->origin.y=(edk::uint64)n;edkEnd();
        this->origin.z=(edk::uint64)n;edkEnd();
        this->size.width=(edk::uint64)n;edkEnd();
        this->size.height=(edk::uint64)n;edkEnd();
        this->size.length=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint64)n;edkEnd();
        this->origin.y=(edk::uint64)n;edkEnd();
        this->origin.z=(edk::uint64)n;edkEnd();
        this->size.width=(edk::uint64)n;edkEnd();
        this->size.height=(edk::uint64)n;edkEnd();
        this->size.length=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }
    cubeui64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint64)n;edkEnd();
        this->origin.y=(edk::uint64)n;edkEnd();
        this->origin.z=(edk::uint64)n;edkEnd();
        this->size.width=(edk::uint64)n;edkEnd();
        this->size.height=(edk::uint64)n;edkEnd();
        this->size.length=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }

    bool operator==(cubeui64 cube){
        //
        return (this->origin.x==(edk::uint64)cube.origin.x
                &&this->origin.y==(edk::uint64)cube.origin.y
                &&this->origin.z==(edk::uint64)cube.origin.z
                &&this->size.width==(edk::uint64)cube.size.width
                &&this->size.height==(edk::uint64)cube.size.height
                &&this->size.length==(edk::uint64)cube.size.length
                );edkEnd();
    }
    bool operator!=(cubeui64 cube){
        //
        return (this->origin.x!=(edk::uint64)cube.origin.x
                ||this->origin.y!=(edk::uint64)cube.origin.y
                ||this->origin.z!=(edk::uint64)cube.origin.z
                ||this->size.width!=(edk::uint64)cube.size.width
                ||this->size.height!=(edk::uint64)cube.size.height
                ||this->size.length!=(edk::uint64)cube.size.length
                );edkEnd();
    }
    cubeui64 operator+(cubeui64 cube){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint64)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint64)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint64)cube.origin.z;edkEnd();
        ret.size.width=this->size.width+(edk::uint64)cube.size.width;edkEnd();
        ret.size.height=this->size.height+(edk::uint64)cube.size.height;edkEnd();
        ret.size.length=this->size.length+(edk::uint64)cube.size.length;edkEnd();
        return ret;
    }
    cubeui64 operator+(edk::uint8 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint64)n;edkEnd();
        return ret;
    }
    cubeui64 operator+(edk::uint32 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint64)n;edkEnd();
        return ret;
    }
    cubeui64 operator+(edk::uint16 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint64)n;edkEnd();
        return ret;
    }
    cubeui64 operator+(edk::uint64 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width+(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height+(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length+(edk::uint64)n;edkEnd();
        return ret;
    }
    void operator+=(cubeui64 cube){
        //
        this->origin.x+=(edk::uint64)cube.origin.x;edkEnd();
        this->origin.y+=(edk::uint64)cube.origin.y;edkEnd();
        this->origin.z+=(edk::uint64)cube.origin.z;edkEnd();
        this->size.width+=(edk::uint64)cube.size.width;edkEnd();
        this->size.height+=(edk::uint64)cube.size.height;edkEnd();
        this->size.length+=(edk::uint64)cube.size.length;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint64)n;edkEnd();
        this->origin.y+=(edk::uint64)n;edkEnd();
        this->origin.z+=(edk::uint64)n;edkEnd();
        this->size.width+=(edk::uint64)n;edkEnd();
        this->size.height+=(edk::uint64)n;edkEnd();
        this->size.length+=(edk::uint64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint64)n;edkEnd();
        this->origin.y+=(edk::uint64)n;edkEnd();
        this->origin.z+=(edk::uint64)n;edkEnd();
        this->size.width+=(edk::uint64)n;edkEnd();
        this->size.height+=(edk::uint64)n;edkEnd();
        this->size.length+=(edk::uint64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint64)n;edkEnd();
        this->origin.y+=(edk::uint64)n;edkEnd();
        this->origin.z+=(edk::uint64)n;edkEnd();
        this->size.width+=(edk::uint64)n;edkEnd();
        this->size.height+=(edk::uint64)n;edkEnd();
        this->size.length+=(edk::uint64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint64)n;edkEnd();
        this->origin.y+=(edk::uint64)n;edkEnd();
        this->origin.z+=(edk::uint64)n;edkEnd();
        this->size.width+=(edk::uint64)n;edkEnd();
        this->size.height+=(edk::uint64)n;edkEnd();
        this->size.length+=(edk::uint64)n;edkEnd();
    }
    cubeui64 operator-(cubeui64 cube){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint64)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint64)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint64)cube.origin.z;edkEnd();
        ret.size.width=this->size.width-(edk::uint64)cube.size.width;edkEnd();
        ret.size.height=this->size.height-(edk::uint64)cube.size.height;edkEnd();
        ret.size.length=this->size.length-(edk::uint64)cube.size.length;edkEnd();
        return ret;
    }
    cubeui64 operator-(edk::uint8 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint64)n;edkEnd();
        return ret;
    }
    cubeui64 operator-(edk::uint32 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint64)n;edkEnd();
        return ret;
    }
    cubeui64 operator-(edk::uint16 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint64)n;edkEnd();
        return ret;
    }
    cubeui64 operator-(edk::uint64 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width-(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height-(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length-(edk::uint64)n;edkEnd();
        return ret;
    }
    void operator-=(cubeui64 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;edkEnd();
        this->origin.y-=(edk::uint64)vec.origin.y;edkEnd();
        this->origin.z-=(edk::uint64)vec.origin.z;edkEnd();
        this->size.width-=(edk::uint64)vec.size.width;edkEnd();
        this->size.height-=(edk::uint64)vec.size.height;edkEnd();
        this->size.length-=(edk::uint64)vec.size.length;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint64)n;edkEnd();
        this->origin.y-=(edk::uint64)n;edkEnd();
        this->origin.z-=(edk::uint64)n;edkEnd();
        this->size.width-=(edk::uint64)n;edkEnd();
        this->size.height-=(edk::uint64)n;edkEnd();
        this->size.length-=(edk::uint64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint64)n;edkEnd();
        this->origin.y-=(edk::uint64)n;edkEnd();
        this->origin.z-=(edk::uint64)n;edkEnd();
        this->size.width-=(edk::uint64)n;edkEnd();
        this->size.height-=(edk::uint64)n;edkEnd();
        this->size.length-=(edk::uint64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint64)n;edkEnd();
        this->origin.y-=(edk::uint64)n;edkEnd();
        this->origin.z-=(edk::uint64)n;edkEnd();
        this->size.width-=(edk::uint64)n;edkEnd();
        this->size.height-=(edk::uint64)n;edkEnd();
        this->size.length-=(edk::uint64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint64)n;edkEnd();
        this->origin.y-=(edk::uint64)n;edkEnd();
        this->origin.z-=(edk::uint64)n;edkEnd();
        this->size.width-=(edk::uint64)n;edkEnd();
        this->size.height-=(edk::uint64)n;edkEnd();
        this->size.length-=(edk::uint64)n;edkEnd();
    }
    cubeui64 operator*(cubeui64 cube){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint64)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint64)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint64)cube.origin.z;edkEnd();
        ret.size.width=this->size.width*(edk::uint64)cube.size.width;edkEnd();
        ret.size.height=this->size.height*(edk::uint64)cube.size.height;edkEnd();
        ret.size.length=this->size.length*(edk::uint64)cube.size.length;edkEnd();
        return ret;
    }
    cubeui64 operator*(edk::uint8 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint64)n;edkEnd();
        return ret;
    }
    cubeui64 operator*(edk::uint32 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint64)n;edkEnd();
        return ret;
    }
    cubeui64 operator*(edk::uint16 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint64)n;edkEnd();
        return ret;
    }
    cubeui64 operator*(edk::uint64 n){
        //
        cubeui64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::uint64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::uint64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::uint64)n;edkEnd();
        ret.size.width=this->size.width*(edk::uint64)n;edkEnd();
        ret.size.height=this->size.height*(edk::uint64)n;edkEnd();
        ret.size.length=this->size.length*(edk::uint64)n;edkEnd();
        return ret;
    }
    void operator*=(cubeui64 cube){
        //
        this->origin.x*=(edk::uint64)cube.origin.x;edkEnd();
        this->origin.y*=(edk::uint64)cube.origin.y;edkEnd();
        this->origin.z*=(edk::uint64)cube.origin.z;edkEnd();
        this->size.width*=(edk::uint64)cube.size.width;edkEnd();
        this->size.height*=(edk::uint64)cube.size.height;edkEnd();
        this->size.length*=(edk::uint64)cube.size.length;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint64)n;edkEnd();
        this->origin.y*=(edk::uint64)n;edkEnd();
        this->origin.z*=(edk::uint64)n;edkEnd();
        this->size.width*=(edk::uint64)n;edkEnd();
        this->size.height*=(edk::uint64)n;edkEnd();
        this->size.length*=(edk::uint64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint64)n;edkEnd();
        this->origin.y*=(edk::uint64)n;edkEnd();
        this->origin.z*=(edk::uint64)n;edkEnd();
        this->size.width*=(edk::uint64)n;edkEnd();
        this->size.height*=(edk::uint64)n;edkEnd();
        this->size.length*=(edk::uint64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint64)n;edkEnd();
        this->origin.y*=(edk::uint64)n;edkEnd();
        this->origin.z*=(edk::uint64)n;edkEnd();
        this->size.width*=(edk::uint64)n;edkEnd();
        this->size.height*=(edk::uint64)n;edkEnd();
        this->size.length*=(edk::uint64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint64)n;edkEnd();
        this->origin.y*=(edk::uint64)n;edkEnd();
        this->origin.z*=(edk::uint64)n;edkEnd();
        this->size.width*=(edk::uint64)n;edkEnd();
        this->size.height*=(edk::uint64)n;edkEnd();
        this->size.length*=(edk::uint64)n;edkEnd();
    }
    //
    cubeui64 operator++(){
        //
        ++this->origin.x;edkEnd();
        ++this->origin.y;edkEnd();
        ++this->origin.z;edkEnd();
        ++this->size.width;edkEnd();
        ++this->size.height;edkEnd();
        ++this->size.length;edkEnd();
        return cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui64 operator++(edk::int32){
        //
        this->origin.x++;edkEnd();
        this->origin.y++;edkEnd();
        this->origin.z++;edkEnd();
        this->size.width++;edkEnd();
        this->size.height++;edkEnd();
        this->size.length++;edkEnd();
        return cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui64 operator--(){
        //
        --this->origin.x;edkEnd();
        --this->origin.y;edkEnd();
        --this->origin.z;edkEnd();
        --this->size.width;edkEnd();
        --this->size.height;edkEnd();
        --this->size.length;edkEnd();
        return cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui64 operator--(edk::int32){
        //
        this->origin.x--;edkEnd();
        this->origin.y--;edkEnd();
        this->origin.z--;edkEnd();
        this->size.width--;edkEnd();
        this->size.height--;edkEnd();
        this->size.length--;edkEnd();
        return cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubeui64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);edkEnd();
    }
    cubeui64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint64)x;edkEnd();
        this->origin.y=(edk::uint64)y;edkEnd();
        this->origin.z=(edk::uint64)z;edkEnd();
        this->size.width=(edk::uint64)width;edkEnd();
        this->size.height=(edk::uint64)height;edkEnd();
        this->size.length=(edk::uint64)length;edkEnd();
        return cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);edkEnd();
    }
    cubeui64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint64)x;edkEnd();
        this->origin.y=(edk::uint64)y;edkEnd();
        this->origin.z=(edk::uint64)z;edkEnd();
        this->size.width=(edk::uint64)width;edkEnd();
        this->size.height=(edk::uint64)height;edkEnd();
        this->size.length=(edk::uint64)length;edkEnd();
        return cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);edkEnd();
    }
    cubeui64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint64)x;edkEnd();
        this->origin.y=(edk::uint64)y;edkEnd();
        this->origin.z=(edk::uint64)z;edkEnd();
        this->size.width=(edk::uint64)width;edkEnd();
        this->size.height=(edk::uint64)height;edkEnd();
        this->size.length=(edk::uint64)length;edkEnd();
        return cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);edkEnd();
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
        this->origin.x=(edk::float32)0;edkEnd();
        this->origin.y=(edk::float32)0;edkEnd();
        this->origin.z=(edk::float32)0;edkEnd();
        this->size.width=(edk::float32)0;edkEnd();
        this->size.height=(edk::float32)0;edkEnd();
        this->size.length=(edk::float32)0;edkEnd();
    }
    cubef32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->origin.x=(edk::float32)x;edkEnd();
        this->origin.y=(edk::float32)y;edkEnd();
        this->origin.z=(edk::float32)z;edkEnd();
        this->size.width=(edk::float32)width;edkEnd();
        this->size.height=(edk::float32)height;edkEnd();
        this->size.length=(edk::float32)length;edkEnd();
    }
    cubef32(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->origin.x=(edk::float32)x;edkEnd();
        this->origin.y=(edk::float32)y;edkEnd();
        this->origin.z=(edk::float32)z;edkEnd();
        this->size.width=(edk::float32)width;edkEnd();
        this->size.height=(edk::float32)height;edkEnd();
        this->size.length=(edk::float32)length;edkEnd();
    }
    cubef32(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::float32)x;edkEnd();
        this->origin.y=(edk::float32)y;edkEnd();
        this->origin.z=(edk::float32)z;edkEnd();
        this->size.width=(edk::float32)width;edkEnd();
        this->size.height=(edk::float32)height;edkEnd();
        this->size.length=(edk::float32)length;edkEnd();
    }
    cubef32(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::float32)x;edkEnd();
        this->origin.y=(edk::float32)y;edkEnd();
        this->origin.z=(edk::float32)z;edkEnd();
        this->size.width=(edk::float32)width;edkEnd();
        this->size.height=(edk::float32)height;edkEnd();
        this->size.length=(edk::float32)length;edkEnd();
    }
    cubef32(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::float32)x;edkEnd();
        this->origin.y=(edk::float32)y;edkEnd();
        this->origin.z=(edk::float32)z;edkEnd();
        this->size.width=(edk::float32)width;edkEnd();
        this->size.height=(edk::float32)height;edkEnd();
        this->size.length=(edk::float32)length;edkEnd();
    }
    cubef32(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::float32)x;edkEnd();
        this->origin.y=(edk::float32)y;edkEnd();
        this->origin.z=(edk::float32)z;edkEnd();
        this->size.width=(edk::float32)width;edkEnd();
        this->size.height=(edk::float32)height;edkEnd();
        this->size.length=(edk::float32)length;edkEnd();
    }
    cubef32(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::float32)x;edkEnd();
        this->origin.y=(edk::float32)y;edkEnd();
        this->origin.z=(edk::float32)z;edkEnd();
        this->size.width=(edk::float32)width;edkEnd();
        this->size.height=(edk::float32)height;edkEnd();
        this->size.length=(edk::float32)length;edkEnd();
    }
    cubef32(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::float32)x;edkEnd();
        this->origin.y=(edk::float32)y;edkEnd();
        this->origin.z=(edk::float32)z;edkEnd();
        this->size.width=(edk::float32)width;edkEnd();
        this->size.height=(edk::float32)height;edkEnd();
        this->size.length=(edk::float32)length;edkEnd();
    }
    cubef32(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::float32)x;edkEnd();
        this->origin.y=(edk::float32)y;edkEnd();
        this->origin.z=(edk::float32)z;edkEnd();
        this->size.width=(edk::float32)width;edkEnd();
        this->size.height=(edk::float32)height;edkEnd();
        this->size.length=(edk::float32)length;edkEnd();
    }
    cubef32(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::float32)x;edkEnd();
        this->origin.y=(edk::float32)y;edkEnd();
        this->origin.z=(edk::float32)z;edkEnd();
        this->size.width=(edk::float32)width;edkEnd();
        this->size.height=(edk::float32)height;edkEnd();
        this->size.length=(edk::float32)length;edkEnd();
    }
    cubef32(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::float32)origin.x;edkEnd();
        this->origin.y=(edk::float32)origin.y;edkEnd();
        this->origin.z=(edk::float32)origin.z;edkEnd();
        this->size.width=(edk::float32)size.width;edkEnd();
        this->size.height=(edk::float32)size.height;edkEnd();
        this->size.length=(edk::float32)size.length;edkEnd();
    }
    cubef32(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::float32)origin.x;edkEnd();
        this->origin.y=(edk::float32)origin.y;edkEnd();
        this->origin.z=(edk::float32)origin.z;edkEnd();
        this->size.width=(edk::float32)size.width;edkEnd();
        this->size.height=(edk::float32)size.height;edkEnd();
        this->size.length=(edk::float32)size.length;edkEnd();
    }
    cubef32(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::float32)origin.x;edkEnd();
        this->origin.y=(edk::float32)origin.y;edkEnd();
        this->origin.z=(edk::float32)origin.z;edkEnd();
        this->size.width=(edk::float32)size.width;edkEnd();
        this->size.height=(edk::float32)size.height;edkEnd();
        this->size.length=(edk::float32)size.length;edkEnd();
    }
    cubef32(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::float32)origin.x;edkEnd();
        this->origin.y=(edk::float32)origin.y;edkEnd();
        this->origin.z=(edk::float32)origin.z;edkEnd();
        this->size.width=(edk::float32)size.width;edkEnd();
        this->size.height=(edk::float32)size.height;edkEnd();
        this->size.length=(edk::float32)size.length;edkEnd();
    }
    cubef32(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::float32)origin.x;edkEnd();
        this->origin.y=(edk::float32)origin.y;edkEnd();
        this->origin.z=(edk::float32)origin.z;edkEnd();
        this->size.width=(edk::float32)size.width;edkEnd();
        this->size.height=(edk::float32)size.height;edkEnd();
        this->size.length=(edk::float32)size.length;edkEnd();
    }
    cubef32(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::float32)origin.x;edkEnd();
        this->origin.y=(edk::float32)origin.y;edkEnd();
        this->origin.z=(edk::float32)origin.z;edkEnd();
        this->size.width=(edk::float32)size.width;edkEnd();
        this->size.height=(edk::float32)size.height;edkEnd();
        this->size.length=(edk::float32)size.length;edkEnd();
    }
    cubef32(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::float32)origin.x;edkEnd();
        this->origin.y=(edk::float32)origin.y;edkEnd();
        this->origin.z=(edk::float32)origin.z;edkEnd();
        this->size.width=(edk::float32)size.width;edkEnd();
        this->size.height=(edk::float32)size.height;edkEnd();
        this->size.length=(edk::float32)size.length;edkEnd();
    }
    cubef32(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::float32)origin.x;edkEnd();
        this->origin.y=(edk::float32)origin.y;edkEnd();
        this->origin.z=(edk::float32)origin.z;edkEnd();
        this->size.width=(edk::float32)size.width;edkEnd();
        this->size.height=(edk::float32)size.height;edkEnd();
        this->size.length=(edk::float32)size.length;edkEnd();
    }
    cubef32(edk::vec3f32 origin,edk::size3f32 size){
        //
        this->origin.x=origin.x;edkEnd();
        this->origin.y=origin.y;edkEnd();
        this->origin.z=origin.z;edkEnd();
        this->size.width=size.width;edkEnd();
        this->size.height=size.height;edkEnd();
        this->size.length=size.length;edkEnd();
    }
    cubef32(edk::vec3f64 origin,edk::size3f64 size){
        //
        this->origin.x=(edk::float32)origin.x;edkEnd();
        this->origin.y=(edk::float32)origin.y;edkEnd();
        this->origin.z=(edk::float32)origin.z;edkEnd();
        this->size.width=(edk::float32)size.width;edkEnd();
        this->size.height=(edk::float32)size.height;edkEnd();
        this->size.length=(edk::float32)size.length;edkEnd();
    }

    //operators
    cubef32 operator=(cubef32 cube){
        //
        this->origin.x=(edk::float32)cube.origin.x;edkEnd();
        this->origin.y=(edk::float32)cube.origin.y;edkEnd();
        this->origin.z=(edk::float32)cube.origin.z;edkEnd();
        this->size.width=(edk::float32)cube.size.width;edkEnd();
        this->size.height=(edk::float32)cube.size.height;edkEnd();
        this->size.length=(edk::float32)cube.size.length;edkEnd();
        return *this;edkEnd();
    }
    cubef32 operator=(edk::float32 n){
        //
        this->origin.x=(edk::float32)n;edkEnd();
        this->origin.y=(edk::float32)n;edkEnd();
        this->origin.z=(edk::float32)n;edkEnd();
        this->size.width=(edk::float32)n;edkEnd();
        this->size.height=(edk::float32)n;edkEnd();
        this->size.length=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    cubef32 operator=(edk::float64 n){
        //
        this->origin.x=(edk::float32)n;edkEnd();
        this->origin.y=(edk::float32)n;edkEnd();
        this->origin.z=(edk::float32)n;edkEnd();
        this->size.width=(edk::float32)n;edkEnd();
        this->size.height=(edk::float32)n;edkEnd();
        this->size.length=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    cubef32 operator=(edk::int8 n){
        //
        this->origin.x=(edk::float32)n;edkEnd();
        this->origin.y=(edk::float32)n;edkEnd();
        this->origin.z=(edk::float32)n;edkEnd();
        this->size.width=(edk::float32)n;edkEnd();
        this->size.height=(edk::float32)n;edkEnd();
        this->size.length=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    cubef32 operator=(edk::int32 n){
        //
        this->origin.x=(edk::float32)n;edkEnd();
        this->origin.y=(edk::float32)n;edkEnd();
        this->origin.z=(edk::float32)n;edkEnd();
        this->size.width=(edk::float32)n;edkEnd();
        this->size.height=(edk::float32)n;edkEnd();
        this->size.length=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    cubef32 operator=(edk::int16 n){
        //
        this->origin.x=(edk::float32)n;edkEnd();
        this->origin.y=(edk::float32)n;edkEnd();
        this->origin.z=(edk::float32)n;edkEnd();
        this->size.width=(edk::float32)n;edkEnd();
        this->size.height=(edk::float32)n;edkEnd();
        this->size.length=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    cubef32 operator=(edk::int64 n){
        //
        this->origin.x=(edk::float32)n;edkEnd();
        this->origin.y=(edk::float32)n;edkEnd();
        this->origin.z=(edk::float32)n;edkEnd();
        this->size.width=(edk::float32)n;edkEnd();
        this->size.height=(edk::float32)n;edkEnd();
        this->size.length=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    cubef32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::float32)n;edkEnd();
        this->origin.y=(edk::float32)n;edkEnd();
        this->origin.z=(edk::float32)n;edkEnd();
        this->size.width=(edk::float32)n;edkEnd();
        this->size.height=(edk::float32)n;edkEnd();
        this->size.length=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    cubef32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::float32)n;edkEnd();
        this->origin.y=(edk::float32)n;edkEnd();
        this->origin.z=(edk::float32)n;edkEnd();
        this->size.width=(edk::float32)n;edkEnd();
        this->size.height=(edk::float32)n;edkEnd();
        this->size.length=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    cubef32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::float32)n;edkEnd();
        this->origin.y=(edk::float32)n;edkEnd();
        this->origin.z=(edk::float32)n;edkEnd();
        this->size.width=(edk::float32)n;edkEnd();
        this->size.height=(edk::float32)n;edkEnd();
        this->size.length=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    cubef32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::float32)n;edkEnd();
        this->origin.y=(edk::float32)n;edkEnd();
        this->origin.z=(edk::float32)n;edkEnd();
        this->size.width=(edk::float32)n;edkEnd();
        this->size.height=(edk::float32)n;edkEnd();
        this->size.length=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }

    bool operator==(cubef32 cube){
        //
        return (this->origin.x==(edk::float32)cube.origin.x
                &&this->origin.y==(edk::float32)cube.origin.y
                &&this->origin.z==(edk::float32)cube.origin.z
                &&this->size.width==(edk::float32)cube.size.width
                &&this->size.height==(edk::float32)cube.size.height
                &&this->size.length==(edk::float32)cube.size.length
                );edkEnd();
    }
    bool operator!=(cubef32 cube){
        //
        return (this->origin.x!=(edk::float32)cube.origin.x
                ||this->origin.y!=(edk::float32)cube.origin.y
                ||this->origin.z!=(edk::float32)cube.origin.z
                ||this->size.width!=(edk::float32)cube.size.width
                ||this->size.height!=(edk::float32)cube.size.height
                ||this->size.length!=(edk::float32)cube.size.length
                );edkEnd();
    }
    cubef32 operator+(cubef32 cube){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)cube.origin.z;edkEnd();
        ret.size.width=this->size.width+(edk::float32)cube.size.width;edkEnd();
        ret.size.height=this->size.height+(edk::float32)cube.size.height;edkEnd();
        ret.size.length=this->size.length+(edk::float32)cube.size.length;edkEnd();
        return ret;
    }
    cubef32 operator+(edk::float32 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)n;edkEnd();
        ret.size.width=this->size.width+(edk::float32)n;edkEnd();
        ret.size.height=this->size.height+(edk::float32)n;edkEnd();
        ret.size.length=this->size.length+(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator+(edk::float64 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)n;edkEnd();
        ret.size.width=this->size.width+(edk::float32)n;edkEnd();
        ret.size.height=this->size.height+(edk::float32)n;edkEnd();
        ret.size.length=this->size.length+(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator+(edk::int8 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)n;edkEnd();
        ret.size.width=this->size.width+(edk::float32)n;edkEnd();
        ret.size.height=this->size.height+(edk::float32)n;edkEnd();
        ret.size.length=this->size.length+(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator+(edk::int32 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)n;edkEnd();
        ret.size.width=this->size.width+(edk::float32)n;edkEnd();
        ret.size.height=this->size.height+(edk::float32)n;edkEnd();
        ret.size.length=this->size.length+(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator+(edk::int16 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)n;edkEnd();
        ret.size.width=this->size.width+(edk::float32)n;edkEnd();
        ret.size.height=this->size.height+(edk::float32)n;edkEnd();
        ret.size.length=this->size.length+(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator+(edk::int64 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)n;edkEnd();
        ret.size.width=this->size.width+(edk::float32)n;edkEnd();
        ret.size.height=this->size.height+(edk::float32)n;edkEnd();
        ret.size.length=this->size.length+(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator+(edk::uint8 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)n;edkEnd();
        ret.size.width=this->size.width+(edk::float32)n;edkEnd();
        ret.size.height=this->size.height+(edk::float32)n;edkEnd();
        ret.size.length=this->size.length+(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator+(edk::uint32 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)n;edkEnd();
        ret.size.width=this->size.width+(edk::float32)n;edkEnd();
        ret.size.height=this->size.height+(edk::float32)n;edkEnd();
        ret.size.length=this->size.length+(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator+(edk::uint16 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)n;edkEnd();
        ret.size.width=this->size.width+(edk::float32)n;edkEnd();
        ret.size.height=this->size.height+(edk::float32)n;edkEnd();
        ret.size.length=this->size.length+(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator+(edk::uint64 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float32)n;edkEnd();
        ret.size.width=this->size.width+(edk::float32)n;edkEnd();
        ret.size.height=this->size.height+(edk::float32)n;edkEnd();
        ret.size.length=this->size.length+(edk::float32)n;edkEnd();
        return ret;
    }
    void operator+=(cubef32 cube){
        //
        this->origin.x+=(edk::float32)cube.origin.x;edkEnd();
        this->origin.y+=(edk::float32)cube.origin.y;edkEnd();
        this->origin.z+=(edk::float32)cube.origin.z;edkEnd();
        this->size.width+=(edk::float32)cube.size.width;edkEnd();
        this->size.height+=(edk::float32)cube.size.height;edkEnd();
        this->size.length+=(edk::float32)cube.size.length;edkEnd();
    }
    void operator+=(edk::float32 n){
        //
        this->origin.x+=(edk::float32)n;edkEnd();
        this->origin.y+=(edk::float32)n;edkEnd();
        this->origin.z+=(edk::float32)n;edkEnd();
        this->size.width+=(edk::float32)n;edkEnd();
        this->size.height+=(edk::float32)n;edkEnd();
        this->size.length+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::float64 n){
        //
        this->origin.x+=(edk::float32)n;edkEnd();
        this->origin.y+=(edk::float32)n;edkEnd();
        this->origin.z+=(edk::float32)n;edkEnd();
        this->size.width+=(edk::float32)n;edkEnd();
        this->size.height+=(edk::float32)n;edkEnd();
        this->size.length+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::float32)n;edkEnd();
        this->origin.y+=(edk::float32)n;edkEnd();
        this->origin.z+=(edk::float32)n;edkEnd();
        this->size.width+=(edk::float32)n;edkEnd();
        this->size.height+=(edk::float32)n;edkEnd();
        this->size.length+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::float32)n;edkEnd();
        this->origin.y+=(edk::float32)n;edkEnd();
        this->origin.z+=(edk::float32)n;edkEnd();
        this->size.width+=(edk::float32)n;edkEnd();
        this->size.height+=(edk::float32)n;edkEnd();
        this->size.length+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::float32)n;edkEnd();
        this->origin.y+=(edk::float32)n;edkEnd();
        this->origin.z+=(edk::float32)n;edkEnd();
        this->size.width+=(edk::float32)n;edkEnd();
        this->size.height+=(edk::float32)n;edkEnd();
        this->size.length+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::float32)n;edkEnd();
        this->origin.y+=(edk::float32)n;edkEnd();
        this->origin.z+=(edk::float32)n;edkEnd();
        this->size.width+=(edk::float32)n;edkEnd();
        this->size.height+=(edk::float32)n;edkEnd();
        this->size.length+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::float32)n;edkEnd();
        this->origin.y+=(edk::float32)n;edkEnd();
        this->origin.z+=(edk::float32)n;edkEnd();
        this->size.width+=(edk::float32)n;edkEnd();
        this->size.height+=(edk::float32)n;edkEnd();
        this->size.length+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::float32)n;edkEnd();
        this->origin.y+=(edk::float32)n;edkEnd();
        this->origin.z+=(edk::float32)n;edkEnd();
        this->size.width+=(edk::float32)n;edkEnd();
        this->size.height+=(edk::float32)n;edkEnd();
        this->size.length+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::float32)n;edkEnd();
        this->origin.y+=(edk::float32)n;edkEnd();
        this->origin.z+=(edk::float32)n;edkEnd();
        this->size.width+=(edk::float32)n;edkEnd();
        this->size.height+=(edk::float32)n;edkEnd();
        this->size.length+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::float32)n;edkEnd();
        this->origin.y+=(edk::float32)n;edkEnd();
        this->origin.z+=(edk::float32)n;edkEnd();
        this->size.width+=(edk::float32)n;edkEnd();
        this->size.height+=(edk::float32)n;edkEnd();
        this->size.length+=(edk::float32)n;edkEnd();
    }
    cubef32 operator-(cubef32 cube){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)cube.origin.z;edkEnd();
        ret.size.width=this->size.width-(edk::float32)cube.size.width;edkEnd();
        ret.size.height=this->size.height-(edk::float32)cube.size.height;edkEnd();
        ret.size.length=this->size.length-(edk::float32)cube.size.length;edkEnd();
        return ret;
    }
    cubef32 operator-(edk::float32 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)n;edkEnd();
        ret.size.width=this->size.width-(edk::float32)n;edkEnd();
        ret.size.height=this->size.height-(edk::float32)n;edkEnd();
        ret.size.length=this->size.length-(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator-(edk::float64 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)n;edkEnd();
        ret.size.width=this->size.width-(edk::float32)n;edkEnd();
        ret.size.height=this->size.height-(edk::float32)n;edkEnd();
        ret.size.length=this->size.length-(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator-(edk::int8 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)n;edkEnd();
        ret.size.width=this->size.width-(edk::float32)n;edkEnd();
        ret.size.height=this->size.height-(edk::float32)n;edkEnd();
        ret.size.length=this->size.length-(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator-(edk::int32 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)n;edkEnd();
        ret.size.width=this->size.width-(edk::float32)n;edkEnd();
        ret.size.height=this->size.height-(edk::float32)n;edkEnd();
        ret.size.length=this->size.length-(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator-(edk::int16 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)n;edkEnd();
        ret.size.width=this->size.width-(edk::float32)n;edkEnd();
        ret.size.height=this->size.height-(edk::float32)n;edkEnd();
        ret.size.length=this->size.length-(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator-(edk::int64 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)n;edkEnd();
        ret.size.width=this->size.width-(edk::float32)n;edkEnd();
        ret.size.height=this->size.height-(edk::float32)n;edkEnd();
        ret.size.length=this->size.length-(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator-(edk::uint8 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)n;edkEnd();
        ret.size.width=this->size.width-(edk::float32)n;edkEnd();
        ret.size.height=this->size.height-(edk::float32)n;edkEnd();
        ret.size.length=this->size.length-(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator-(edk::uint32 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)n;edkEnd();
        ret.size.width=this->size.width-(edk::float32)n;edkEnd();
        ret.size.height=this->size.height-(edk::float32)n;edkEnd();
        ret.size.length=this->size.length-(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator-(edk::uint16 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)n;edkEnd();
        ret.size.width=this->size.width-(edk::float32)n;edkEnd();
        ret.size.height=this->size.height-(edk::float32)n;edkEnd();
        ret.size.length=this->size.length-(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator-(edk::uint64 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float32)n;edkEnd();
        ret.size.width=this->size.width-(edk::float32)n;edkEnd();
        ret.size.height=this->size.height-(edk::float32)n;edkEnd();
        ret.size.length=this->size.length-(edk::float32)n;edkEnd();
        return ret;
    }
    void operator-=(cubef32 vec){
        //
        this->origin.x-=(edk::float32)vec.origin.x;edkEnd();
        this->origin.y-=(edk::float32)vec.origin.y;edkEnd();
        this->origin.z-=(edk::float32)vec.origin.z;edkEnd();
        this->size.width-=(edk::float32)vec.size.width;edkEnd();
        this->size.height-=(edk::float32)vec.size.height;edkEnd();
        this->size.length-=(edk::float32)vec.size.length;edkEnd();
    }
    void operator-=(edk::float32 n){
        //
        this->origin.x-=(edk::float32)n;edkEnd();
        this->origin.y-=(edk::float32)n;edkEnd();
        this->origin.z-=(edk::float32)n;edkEnd();
        this->size.width-=(edk::float32)n;edkEnd();
        this->size.height-=(edk::float32)n;edkEnd();
        this->size.length-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::float64 n){
        //
        this->origin.x-=(edk::float32)n;edkEnd();
        this->origin.y-=(edk::float32)n;edkEnd();
        this->origin.z-=(edk::float32)n;edkEnd();
        this->size.width-=(edk::float32)n;edkEnd();
        this->size.height-=(edk::float32)n;edkEnd();
        this->size.length-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::float32)n;edkEnd();
        this->origin.y-=(edk::float32)n;edkEnd();
        this->origin.z-=(edk::float32)n;edkEnd();
        this->size.width-=(edk::float32)n;edkEnd();
        this->size.height-=(edk::float32)n;edkEnd();
        this->size.length-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::float32)n;edkEnd();
        this->origin.y-=(edk::float32)n;edkEnd();
        this->origin.z-=(edk::float32)n;edkEnd();
        this->size.width-=(edk::float32)n;edkEnd();
        this->size.height-=(edk::float32)n;edkEnd();
        this->size.length-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::float32)n;edkEnd();
        this->origin.y-=(edk::float32)n;edkEnd();
        this->origin.z-=(edk::float32)n;edkEnd();
        this->size.width-=(edk::float32)n;edkEnd();
        this->size.height-=(edk::float32)n;edkEnd();
        this->size.length-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::float32)n;edkEnd();
        this->origin.y-=(edk::float32)n;edkEnd();
        this->origin.z-=(edk::float32)n;edkEnd();
        this->size.width-=(edk::float32)n;edkEnd();
        this->size.height-=(edk::float32)n;edkEnd();
        this->size.length-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::float32)n;edkEnd();
        this->origin.y-=(edk::float32)n;edkEnd();
        this->origin.z-=(edk::float32)n;edkEnd();
        this->size.width-=(edk::float32)n;edkEnd();
        this->size.height-=(edk::float32)n;edkEnd();
        this->size.length-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::float32)n;edkEnd();
        this->origin.y-=(edk::float32)n;edkEnd();
        this->origin.z-=(edk::float32)n;edkEnd();
        this->size.width-=(edk::float32)n;edkEnd();
        this->size.height-=(edk::float32)n;edkEnd();
        this->size.length-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::float32)n;edkEnd();
        this->origin.y-=(edk::float32)n;edkEnd();
        this->origin.z-=(edk::float32)n;edkEnd();
        this->size.width-=(edk::float32)n;edkEnd();
        this->size.height-=(edk::float32)n;edkEnd();
        this->size.length-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::float32)n;edkEnd();
        this->origin.y-=(edk::float32)n;edkEnd();
        this->origin.z-=(edk::float32)n;edkEnd();
        this->size.width-=(edk::float32)n;edkEnd();
        this->size.height-=(edk::float32)n;edkEnd();
        this->size.length-=(edk::float32)n;edkEnd();
    }
    cubef32 operator*(cubef32 cube){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)cube.origin.z;edkEnd();
        ret.size.width=this->size.width*(edk::float32)cube.size.width;edkEnd();
        ret.size.height=this->size.height*(edk::float32)cube.size.height;edkEnd();
        ret.size.length=this->size.length*(edk::float32)cube.size.length;edkEnd();
        return ret;
    }
    cubef32 operator*(edk::float32 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)n;edkEnd();
        ret.size.width=this->size.width*(edk::float32)n;edkEnd();
        ret.size.height=this->size.height*(edk::float32)n;edkEnd();
        ret.size.length=this->size.length*(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator*(edk::float64 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)n;edkEnd();
        ret.size.width=this->size.width*(edk::float32)n;edkEnd();
        ret.size.height=this->size.height*(edk::float32)n;edkEnd();
        ret.size.length=this->size.length*(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator*(edk::int8 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)n;edkEnd();
        ret.size.width=this->size.width*(edk::float32)n;edkEnd();
        ret.size.height=this->size.height*(edk::float32)n;edkEnd();
        ret.size.length=this->size.length*(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator*(edk::int32 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)n;edkEnd();
        ret.size.width=this->size.width*(edk::float32)n;edkEnd();
        ret.size.height=this->size.height*(edk::float32)n;edkEnd();
        ret.size.length=this->size.length*(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator*(edk::int16 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)n;edkEnd();
        ret.size.width=this->size.width*(edk::float32)n;edkEnd();
        ret.size.height=this->size.height*(edk::float32)n;edkEnd();
        ret.size.length=this->size.length*(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator*(edk::int64 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)n;edkEnd();
        ret.size.width=this->size.width*(edk::float32)n;edkEnd();
        ret.size.height=this->size.height*(edk::float32)n;edkEnd();
        ret.size.length=this->size.length*(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator*(edk::uint8 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)n;edkEnd();
        ret.size.width=this->size.width*(edk::float32)n;edkEnd();
        ret.size.height=this->size.height*(edk::float32)n;edkEnd();
        ret.size.length=this->size.length*(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator*(edk::uint32 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)n;edkEnd();
        ret.size.width=this->size.width*(edk::float32)n;edkEnd();
        ret.size.height=this->size.height*(edk::float32)n;edkEnd();
        ret.size.length=this->size.length*(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator*(edk::uint16 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)n;edkEnd();
        ret.size.width=this->size.width*(edk::float32)n;edkEnd();
        ret.size.height=this->size.height*(edk::float32)n;edkEnd();
        ret.size.length=this->size.length*(edk::float32)n;edkEnd();
        return ret;
    }
    cubef32 operator*(edk::uint64 n){
        //
        cubef32 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float32)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float32)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float32)n;edkEnd();
        ret.size.width=this->size.width*(edk::float32)n;edkEnd();
        ret.size.height=this->size.height*(edk::float32)n;edkEnd();
        ret.size.length=this->size.length*(edk::float32)n;edkEnd();
        return ret;
    }
    void operator*=(cubef32 cube){
        //
        this->origin.x*=(edk::float32)cube.origin.x;edkEnd();
        this->origin.y*=(edk::float32)cube.origin.y;edkEnd();
        this->origin.z*=(edk::float32)cube.origin.z;edkEnd();
        this->size.width*=(edk::float32)cube.size.width;edkEnd();
        this->size.height*=(edk::float32)cube.size.height;edkEnd();
        this->size.length*=(edk::float32)cube.size.length;edkEnd();
    }
    void operator*=(edk::float32 n){
        //
        this->origin.x*=(edk::float32)n;edkEnd();
        this->origin.y*=(edk::float32)n;edkEnd();
        this->origin.z*=(edk::float32)n;edkEnd();
        this->size.width*=(edk::float32)n;edkEnd();
        this->size.height*=(edk::float32)n;edkEnd();
        this->size.length*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::float64 n){
        //
        this->origin.x*=(edk::float32)n;edkEnd();
        this->origin.y*=(edk::float32)n;edkEnd();
        this->origin.z*=(edk::float32)n;edkEnd();
        this->size.width*=(edk::float32)n;edkEnd();
        this->size.height*=(edk::float32)n;edkEnd();
        this->size.length*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::float32)n;edkEnd();
        this->origin.y*=(edk::float32)n;edkEnd();
        this->origin.z*=(edk::float32)n;edkEnd();
        this->size.width*=(edk::float32)n;edkEnd();
        this->size.height*=(edk::float32)n;edkEnd();
        this->size.length*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::float32)n;edkEnd();
        this->origin.y*=(edk::float32)n;edkEnd();
        this->origin.z*=(edk::float32)n;edkEnd();
        this->size.width*=(edk::float32)n;edkEnd();
        this->size.height*=(edk::float32)n;edkEnd();
        this->size.length*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::float32)n;edkEnd();
        this->origin.y*=(edk::float32)n;edkEnd();
        this->size.width*=(edk::float32)n;edkEnd();
        this->size.height*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::float32)n;edkEnd();
        this->origin.y*=(edk::float32)n;edkEnd();
        this->origin.z*=(edk::float32)n;edkEnd();
        this->size.width*=(edk::float32)n;edkEnd();
        this->size.height*=(edk::float32)n;edkEnd();
        this->size.length*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::float32)n;edkEnd();
        this->origin.y*=(edk::float32)n;edkEnd();
        this->origin.z*=(edk::float32)n;edkEnd();
        this->size.width*=(edk::float32)n;edkEnd();
        this->size.height*=(edk::float32)n;edkEnd();
        this->size.length*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::float32)n;edkEnd();
        this->origin.y*=(edk::float32)n;edkEnd();
        this->origin.z*=(edk::float32)n;edkEnd();
        this->size.width*=(edk::float32)n;edkEnd();
        this->size.height*=(edk::float32)n;edkEnd();
        this->size.length*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::float32)n;edkEnd();
        this->origin.y*=(edk::float32)n;edkEnd();
        this->origin.z*=(edk::float32)n;edkEnd();
        this->size.width*=(edk::float32)n;edkEnd();
        this->size.height*=(edk::float32)n;edkEnd();
        this->size.length*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::float32)n;edkEnd();
        this->origin.y*=(edk::float32)n;edkEnd();
        this->origin.z*=(edk::float32)n;edkEnd();
        this->size.width*=(edk::float32)n;edkEnd();
        this->size.height*=(edk::float32)n;edkEnd();
        this->size.length*=(edk::float32)n;edkEnd();
    }
    //
    cubef32 operator++(){
        //
        ++this->origin.x;edkEnd();
        ++this->origin.y;edkEnd();
        ++this->origin.z;edkEnd();
        ++this->size.width;edkEnd();
        ++this->size.height;edkEnd();
        ++this->size.length;edkEnd();
        return cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubef32 operator++(edk::int32){
        //
        this->origin.x++;edkEnd();
        this->origin.y++;edkEnd();
        this->origin.z++;edkEnd();
        this->size.width++;edkEnd();
        this->size.height++;edkEnd();
        this->size.length++;edkEnd();
        return cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubef32 operator--(){
        //
        --this->origin.x;edkEnd();
        --this->origin.y;edkEnd();
        --this->origin.z;edkEnd();
        --this->size.width;edkEnd();
        --this->size.height;edkEnd();
        --this->size.length;edkEnd();
        return cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubef32 operator--(edk::int32){
        //
        this->origin.x--;edkEnd();
        this->origin.y--;edkEnd();
        this->origin.z--;edkEnd();
        this->size.width--;edkEnd();
        this->size.height--;edkEnd();
        this->size.length--;edkEnd();
        return cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubef32 operator()(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);edkEnd();
    }
    cubef32 operator()(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);edkEnd();
    }
    cubef32 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);edkEnd();
    }
    cubef32 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);edkEnd();
    }
    cubef32 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);edkEnd();
    }
    cubef32 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);edkEnd();
    }
    cubef32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);edkEnd();
    }
    cubef32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);edkEnd();
    }
    cubef32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);edkEnd();
    }
    cubef32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);edkEnd();
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
        this->origin.x=(edk::float64)0;edkEnd();
        this->origin.y=(edk::float64)0;edkEnd();
        this->origin.z=(edk::float64)0;edkEnd();
        this->size.width=(edk::float64)0;edkEnd();
        this->size.height=(edk::float64)0;edkEnd();
        this->size.length=(edk::float64)0;edkEnd();
    }
    cubef64(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->origin.x=(edk::float64)x;edkEnd();
        this->origin.y=(edk::float64)y;edkEnd();
        this->origin.z=(edk::float64)z;edkEnd();
        this->size.width=(edk::float64)width;edkEnd();
        this->size.height=(edk::float64)height;edkEnd();
        this->size.length=(edk::float64)length;edkEnd();
    }
    cubef64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->origin.x=(edk::float64)x;edkEnd();
        this->origin.y=(edk::float64)y;edkEnd();
        this->origin.z=(edk::float64)z;edkEnd();
        this->size.width=(edk::float64)width;edkEnd();
        this->size.height=(edk::float64)height;edkEnd();
        this->size.length=(edk::float64)length;edkEnd();
    }
    cubef64(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=(edk::float64)x;edkEnd();
        this->origin.y=(edk::float64)y;edkEnd();
        this->origin.z=(edk::float64)z;edkEnd();
        this->size.width=(edk::float64)width;edkEnd();
        this->size.height=(edk::float64)height;edkEnd();
        this->size.length=(edk::float64)length;edkEnd();
    }
    cubef64(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=(edk::float64)x;edkEnd();
        this->origin.y=(edk::float64)y;edkEnd();
        this->origin.z=(edk::float64)z;edkEnd();
        this->size.width=(edk::float64)width;edkEnd();
        this->size.height=(edk::float64)height;edkEnd();
        this->size.length=(edk::float64)length;edkEnd();
    }
    cubef64(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=(edk::float64)x;edkEnd();
        this->origin.y=(edk::float64)y;edkEnd();
        this->origin.z=(edk::float64)z;edkEnd();
        this->size.width=(edk::float64)width;edkEnd();
        this->size.height=(edk::float64)height;edkEnd();
        this->size.length=(edk::float64)length;edkEnd();
    }
    cubef64(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=(edk::float64)x;edkEnd();
        this->origin.y=(edk::float64)y;edkEnd();
        this->origin.z=(edk::float64)z;edkEnd();
        this->size.width=(edk::float64)width;edkEnd();
        this->size.height=(edk::float64)height;edkEnd();
        this->size.length=(edk::float64)length;edkEnd();
    }
    cubef64(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=(edk::float64)x;edkEnd();
        this->origin.y=(edk::float64)y;edkEnd();
        this->origin.z=(edk::float64)z;edkEnd();
        this->size.width=(edk::float64)width;edkEnd();
        this->size.height=(edk::float64)height;edkEnd();
        this->size.length=(edk::float64)length;edkEnd();
    }
    cubef64(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::float64)x;edkEnd();
        this->origin.y=(edk::float64)y;edkEnd();
        this->origin.z=(edk::float64)z;edkEnd();
        this->size.width=(edk::float64)width;edkEnd();
        this->size.height=(edk::float64)height;edkEnd();
        this->size.length=(edk::float64)length;edkEnd();
    }
    cubef64(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::float64)x;edkEnd();
        this->origin.y=(edk::float64)y;edkEnd();
        this->origin.z=(edk::float64)z;edkEnd();
        this->size.width=(edk::float64)width;edkEnd();
        this->size.height=(edk::float64)height;edkEnd();
        this->size.length=(edk::float64)length;edkEnd();
    }
    cubef64(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::float64)x;edkEnd();
        this->origin.y=(edk::float64)y;edkEnd();
        this->origin.z=(edk::float64)z;edkEnd();
        this->size.width=(edk::float64)width;edkEnd();
        this->size.height=(edk::float64)height;edkEnd();
        this->size.length=(edk::float64)length;edkEnd();
    }
    cubef64(edk::vec3ui8 origin,edk::size3ui8 size){
        //
        this->origin.x=(edk::float64)origin.x;edkEnd();
        this->origin.y=(edk::float64)origin.y;edkEnd();
        this->origin.z=(edk::float64)origin.z;edkEnd();
        this->size.width=(edk::float64)size.width;edkEnd();
        this->size.height=(edk::float64)size.height;edkEnd();
        this->size.length=(edk::float64)size.length;edkEnd();
    }
    cubef64(edk::vec3ui16 origin,edk::size3ui16 size){
        //
        this->origin.x=(edk::float64)origin.x;edkEnd();
        this->origin.y=(edk::float64)origin.y;edkEnd();
        this->origin.z=(edk::float64)origin.z;edkEnd();
        this->size.width=(edk::float64)size.width;edkEnd();
        this->size.height=(edk::float64)size.height;edkEnd();
        this->size.length=(edk::float64)size.length;edkEnd();
    }
    cubef64(edk::vec3ui32 origin,edk::size3ui32 size){
        //
        this->origin.x=(edk::float64)origin.x;edkEnd();
        this->origin.y=(edk::float64)origin.y;edkEnd();
        this->origin.z=(edk::float64)origin.z;edkEnd();
        this->size.width=(edk::float64)size.width;edkEnd();
        this->size.height=(edk::float64)size.height;edkEnd();
        this->size.length=(edk::float64)size.length;edkEnd();
    }
    cubef64(edk::vec3ui64 origin,edk::size3ui64 size){
        //
        this->origin.x=(edk::float64)origin.x;edkEnd();
        this->origin.y=(edk::float64)origin.y;edkEnd();
        this->origin.z=(edk::float64)origin.z;edkEnd();
        this->size.width=(edk::float64)size.width;edkEnd();
        this->size.height=(edk::float64)size.height;edkEnd();
        this->size.length=(edk::float64)size.length;edkEnd();
    }
    cubef64(edk::vec3i8 origin,edk::size3i8 size){
        //
        this->origin.x=(edk::float64)origin.x;edkEnd();
        this->origin.y=(edk::float64)origin.y;edkEnd();
        this->origin.z=(edk::float64)origin.z;edkEnd();
        this->size.width=(edk::float64)size.width;edkEnd();
        this->size.height=(edk::float64)size.height;edkEnd();
        this->size.length=(edk::float64)size.length;edkEnd();
    }
    cubef64(edk::vec3i16 origin,edk::size3i16 size){
        //
        this->origin.x=(edk::float64)origin.x;edkEnd();
        this->origin.y=(edk::float64)origin.y;edkEnd();
        this->origin.z=(edk::float64)origin.z;edkEnd();
        this->size.width=(edk::float64)size.width;edkEnd();
        this->size.height=(edk::float64)size.height;edkEnd();
        this->size.length=(edk::float64)size.length;edkEnd();
    }
    cubef64(edk::vec3i32 origin,edk::size3i32 size){
        //
        this->origin.x=(edk::float64)origin.x;edkEnd();
        this->origin.y=(edk::float64)origin.y;edkEnd();
        this->origin.z=(edk::float64)origin.z;edkEnd();
        this->size.width=(edk::float64)size.width;edkEnd();
        this->size.height=(edk::float64)size.height;edkEnd();
        this->size.length=(edk::float64)size.length;edkEnd();
    }
    cubef64(edk::vec3i64 origin,edk::size3i64 size){
        //
        this->origin.x=(edk::float64)origin.x;edkEnd();
        this->origin.y=(edk::float64)origin.y;edkEnd();
        this->origin.z=(edk::float64)origin.z;edkEnd();
        this->size.width=(edk::float64)size.width;edkEnd();
        this->size.height=(edk::float64)size.height;edkEnd();
        this->size.length=(edk::float64)size.length;edkEnd();
    }
    cubef64(edk::vec3f32 origin,edk::size3f32 size){
        //
        this->origin.x=(edk::float64)origin.x;edkEnd();
        this->origin.y=(edk::float64)origin.y;edkEnd();
        this->origin.z=(edk::float64)origin.z;edkEnd();
        this->size.width=(edk::float64)size.width;edkEnd();
        this->size.height=(edk::float64)size.height;edkEnd();
        this->size.length=(edk::float64)size.length;edkEnd();
    }
    cubef64(edk::vec3f64 origin,edk::size3f64 size){
        //
        this->origin.x=origin.x;edkEnd();
        this->origin.y=origin.y;edkEnd();
        this->origin.z=origin.z;edkEnd();
        this->size.width=size.width;edkEnd();
        this->size.height=size.height;edkEnd();
        this->size.length=size.length;edkEnd();
    }

    //operators
    cubef64 operator=(cubef64 cube){
        //
        this->origin.x=(edk::float64)cube.origin.x;edkEnd();
        this->origin.y=(edk::float64)cube.origin.y;edkEnd();
        this->origin.z=(edk::float64)cube.origin.z;edkEnd();
        this->size.width=(edk::float64)cube.size.width;edkEnd();
        this->size.height=(edk::float64)cube.size.height;edkEnd();
        this->size.length=(edk::float64)cube.size.length;edkEnd();
        return *this;edkEnd();
    }
    cubef64 operator=(edk::float32 n){
        //
        this->origin.x=(edk::float64)n;edkEnd();
        this->origin.y=(edk::float64)n;edkEnd();
        this->origin.z=(edk::float64)n;edkEnd();
        this->size.width=(edk::float64)n;edkEnd();
        this->size.height=(edk::float64)n;edkEnd();
        this->size.length=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    cubef64 operator=(edk::float64 n){
        //
        this->origin.x=(edk::float64)n;edkEnd();
        this->origin.y=(edk::float64)n;edkEnd();
        this->origin.z=(edk::float64)n;edkEnd();
        this->size.width=(edk::float64)n;edkEnd();
        this->size.height=(edk::float64)n;edkEnd();
        this->size.length=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    cubef64 operator=(edk::int8 n){
        //
        this->origin.x=(edk::float64)n;edkEnd();
        this->origin.y=(edk::float64)n;edkEnd();
        this->origin.z=(edk::float64)n;edkEnd();
        this->size.width=(edk::float64)n;edkEnd();
        this->size.height=(edk::float64)n;edkEnd();
        this->size.length=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    cubef64 operator=(edk::int32 n){
        //
        this->origin.x=(edk::float64)n;edkEnd();
        this->origin.y=(edk::float64)n;edkEnd();
        this->origin.z=(edk::float64)n;edkEnd();
        this->size.width=(edk::float64)n;edkEnd();
        this->size.height=(edk::float64)n;edkEnd();
        this->size.length=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    cubef64 operator=(edk::int16 n){
        //
        this->origin.x=(edk::float64)n;edkEnd();
        this->origin.y=(edk::float64)n;edkEnd();
        this->origin.z=(edk::float64)n;edkEnd();
        this->size.width=(edk::float64)n;edkEnd();
        this->size.height=(edk::float64)n;edkEnd();
        this->size.length=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    cubef64 operator=(edk::int64 n){
        //
        this->origin.x=(edk::float64)n;edkEnd();
        this->origin.y=(edk::float64)n;edkEnd();
        this->origin.z=(edk::float64)n;edkEnd();
        this->size.width=(edk::float64)n;edkEnd();
        this->size.height=(edk::float64)n;edkEnd();
        this->size.length=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    cubef64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::float64)n;edkEnd();
        this->origin.y=(edk::float64)n;edkEnd();
        this->origin.z=(edk::float64)n;edkEnd();
        this->size.width=(edk::float64)n;edkEnd();
        this->size.height=(edk::float64)n;edkEnd();
        this->size.length=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    cubef64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::float64)n;edkEnd();
        this->origin.y=(edk::float64)n;edkEnd();
        this->origin.z=(edk::float64)n;edkEnd();
        this->size.width=(edk::float64)n;edkEnd();
        this->size.height=(edk::float64)n;edkEnd();
        this->size.length=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    cubef64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::float64)n;edkEnd();
        this->origin.y=(edk::float64)n;edkEnd();
        this->origin.z=(edk::float64)n;edkEnd();
        this->size.width=(edk::float64)n;edkEnd();
        this->size.height=(edk::float64)n;edkEnd();
        this->size.length=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    cubef64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::float64)n;edkEnd();
        this->origin.y=(edk::float64)n;edkEnd();
        this->origin.z=(edk::float64)n;edkEnd();
        this->size.width=(edk::float64)n;edkEnd();
        this->size.height=(edk::float64)n;edkEnd();
        this->size.length=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }

    bool operator==(cubef64 cube){
        //
        return (this->origin.x==(edk::float64)cube.origin.x
                &&this->origin.y==(edk::float64)cube.origin.y
                &&this->origin.z==(edk::float64)cube.origin.z
                &&this->size.width==(edk::float64)cube.size.width
                &&this->size.height==(edk::float64)cube.size.height
                &&this->size.length==(edk::float64)cube.size.length
                );edkEnd();
    }
    bool operator!=(cubef64 cube){
        //
        return (this->origin.x!=(edk::float64)cube.origin.x
                ||this->origin.y!=(edk::float64)cube.origin.y
                ||this->origin.z!=(edk::float64)cube.origin.z
                ||this->size.width!=(edk::float64)cube.size.width
                ||this->size.height!=(edk::float64)cube.size.height
                ||this->size.length!=(edk::float64)cube.size.length
                );edkEnd();
    }
    cubef64 operator+(cubef64 cube){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)cube.origin.z;edkEnd();
        ret.size.width=this->size.width+(edk::float64)cube.size.width;edkEnd();
        ret.size.height=this->size.height+(edk::float64)cube.size.height;edkEnd();
        ret.size.length=this->size.length+(edk::float64)cube.size.length;edkEnd();
        return ret;
    }
    cubef64 operator+(edk::float32 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)n;edkEnd();
        ret.size.width=this->size.width+(edk::float64)n;edkEnd();
        ret.size.height=this->size.height+(edk::float64)n;edkEnd();
        ret.size.length=this->size.length+(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator+(edk::float64 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)n;edkEnd();
        ret.size.width=this->size.width+(edk::float64)n;edkEnd();
        ret.size.height=this->size.height+(edk::float64)n;edkEnd();
        ret.size.length=this->size.length+(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator+(edk::int8 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)n;edkEnd();
        ret.size.width=this->size.width+(edk::float64)n;edkEnd();
        ret.size.height=this->size.height+(edk::float64)n;edkEnd();
        ret.size.length=this->size.length+(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator+(edk::int32 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)n;edkEnd();
        ret.size.width=this->size.width+(edk::float64)n;edkEnd();
        ret.size.height=this->size.height+(edk::float64)n;edkEnd();
        ret.size.length=this->size.length+(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator+(edk::int16 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)n;edkEnd();
        ret.size.width=this->size.width+(edk::float64)n;edkEnd();
        ret.size.height=this->size.height+(edk::float64)n;edkEnd();
        ret.size.length=this->size.length+(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator+(edk::int64 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)n;edkEnd();
        ret.size.width=this->size.width+(edk::float64)n;edkEnd();
        ret.size.height=this->size.height+(edk::float64)n;edkEnd();
        ret.size.length=this->size.length+(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator+(edk::uint8 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)n;edkEnd();
        ret.size.width=this->size.width+(edk::float64)n;edkEnd();
        ret.size.height=this->size.height+(edk::float64)n;edkEnd();
        ret.size.length=this->size.length+(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator+(edk::uint32 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)n;edkEnd();
        ret.size.width=this->size.width+(edk::float64)n;edkEnd();
        ret.size.height=this->size.height+(edk::float64)n;edkEnd();
        ret.size.length=this->size.length+(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator+(edk::uint16 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)n;edkEnd();
        ret.size.width=this->size.width+(edk::float64)n;edkEnd();
        ret.size.height=this->size.height+(edk::float64)n;edkEnd();
        ret.size.length=this->size.length+(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator+(edk::uint64 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x+(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y+(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z+(edk::float64)n;edkEnd();
        ret.size.width=this->size.width+(edk::float64)n;edkEnd();
        ret.size.height=this->size.height+(edk::float64)n;edkEnd();
        ret.size.length=this->size.length+(edk::float64)n;edkEnd();
        return ret;
    }
    void operator+=(cubef64 cube){
        //
        this->origin.x+=(edk::float64)cube.origin.x;edkEnd();
        this->origin.y+=(edk::float64)cube.origin.y;edkEnd();
        this->origin.z+=(edk::float64)cube.origin.z;edkEnd();
        this->size.width+=(edk::float64)cube.size.width;edkEnd();
        this->size.height+=(edk::float64)cube.size.height;edkEnd();
        this->size.length+=(edk::float64)cube.size.length;edkEnd();
    }
    void operator+=(edk::float32 n){
        //
        this->origin.x+=(edk::float64)n;edkEnd();
        this->origin.y+=(edk::float64)n;edkEnd();
        this->origin.z+=(edk::float64)n;edkEnd();
        this->size.width+=(edk::float64)n;edkEnd();
        this->size.height+=(edk::float64)n;edkEnd();
        this->size.length+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::float64 n){
        //
        this->origin.x+=(edk::float64)n;edkEnd();
        this->origin.y+=(edk::float64)n;edkEnd();
        this->origin.z+=(edk::float64)n;edkEnd();
        this->size.width+=(edk::float64)n;edkEnd();
        this->size.height+=(edk::float64)n;edkEnd();
        this->size.length+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::float64)n;edkEnd();
        this->origin.y+=(edk::float64)n;edkEnd();
        this->origin.z+=(edk::float64)n;edkEnd();
        this->size.width+=(edk::float64)n;edkEnd();
        this->size.height+=(edk::float64)n;edkEnd();
        this->size.length+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::float64)n;edkEnd();
        this->origin.y+=(edk::float64)n;edkEnd();
        this->origin.z+=(edk::float64)n;edkEnd();
        this->size.width+=(edk::float64)n;edkEnd();
        this->size.height+=(edk::float64)n;edkEnd();
        this->size.length+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::float64)n;edkEnd();
        this->origin.y+=(edk::float64)n;edkEnd();
        this->origin.z+=(edk::float64)n;edkEnd();
        this->size.width+=(edk::float64)n;edkEnd();
        this->size.height+=(edk::float64)n;edkEnd();
        this->size.length+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::float64)n;edkEnd();
        this->origin.y+=(edk::float64)n;edkEnd();
        this->origin.z+=(edk::float64)n;edkEnd();
        this->size.width+=(edk::float64)n;edkEnd();
        this->size.height+=(edk::float64)n;edkEnd();
        this->size.length+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::float64)n;edkEnd();
        this->origin.y+=(edk::float64)n;edkEnd();
        this->origin.z+=(edk::float64)n;edkEnd();
        this->size.width+=(edk::float64)n;edkEnd();
        this->size.height+=(edk::float64)n;edkEnd();
        this->size.length+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::float64)n;edkEnd();
        this->origin.y+=(edk::float64)n;edkEnd();
        this->origin.z+=(edk::float64)n;edkEnd();
        this->size.width+=(edk::float64)n;edkEnd();
        this->size.height+=(edk::float64)n;edkEnd();
        this->size.length+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::float64)n;edkEnd();
        this->origin.y+=(edk::float64)n;edkEnd();
        this->origin.z+=(edk::float64)n;edkEnd();
        this->size.width+=(edk::float64)n;edkEnd();
        this->size.height+=(edk::float64)n;edkEnd();
        this->size.length+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::float64)n;edkEnd();
        this->origin.y+=(edk::float64)n;edkEnd();
        this->origin.z+=(edk::float64)n;edkEnd();
        this->size.width+=(edk::float64)n;edkEnd();
        this->size.height+=(edk::float64)n;edkEnd();
        this->size.length+=(edk::float64)n;edkEnd();
    }
    cubef64 operator-(cubef64 cube){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)cube.origin.z;edkEnd();
        ret.size.width=this->size.width-(edk::float64)cube.size.width;edkEnd();
        ret.size.height=this->size.height-(edk::float64)cube.size.height;edkEnd();
        ret.size.length=this->size.length-(edk::float64)cube.size.length;edkEnd();
        return ret;
    }
    cubef64 operator-(edk::float32 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)n;edkEnd();
        ret.size.width=this->size.width-(edk::float64)n;edkEnd();
        ret.size.height=this->size.height-(edk::float64)n;edkEnd();
        ret.size.length=this->size.length-(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator-(edk::float64 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)n;edkEnd();
        ret.size.width=this->size.width-(edk::float64)n;edkEnd();
        ret.size.height=this->size.height-(edk::float64)n;edkEnd();
        ret.size.length=this->size.length-(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator-(edk::int8 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)n;edkEnd();
        ret.size.width=this->size.width-(edk::float64)n;edkEnd();
        ret.size.height=this->size.height-(edk::float64)n;edkEnd();
        ret.size.length=this->size.length-(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator-(edk::int32 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)n;edkEnd();
        ret.size.width=this->size.width-(edk::float64)n;edkEnd();
        ret.size.height=this->size.height-(edk::float64)n;edkEnd();
        ret.size.length=this->size.length-(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator-(edk::int16 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)n;edkEnd();
        ret.size.width=this->size.width-(edk::float64)n;edkEnd();
        ret.size.height=this->size.height-(edk::float64)n;edkEnd();
        ret.size.length=this->size.length-(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator-(edk::int64 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)n;edkEnd();
        ret.size.width=this->size.width-(edk::float64)n;edkEnd();
        ret.size.height=this->size.height-(edk::float64)n;edkEnd();
        ret.size.length=this->size.length-(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator-(edk::uint8 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)n;edkEnd();
        ret.size.width=this->size.width-(edk::float64)n;edkEnd();
        ret.size.height=this->size.height-(edk::float64)n;edkEnd();
        ret.size.length=this->size.length-(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator-(edk::uint32 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)n;edkEnd();
        ret.size.width=this->size.width-(edk::float64)n;edkEnd();
        ret.size.height=this->size.height-(edk::float64)n;edkEnd();
        ret.size.length=this->size.length-(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator-(edk::uint16 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)n;edkEnd();
        ret.size.width=this->size.width-(edk::float64)n;edkEnd();
        ret.size.height=this->size.height-(edk::float64)n;edkEnd();
        ret.size.length=this->size.length-(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator-(edk::uint64 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x-(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y-(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z-(edk::float64)n;edkEnd();
        ret.size.width=this->size.width-(edk::float64)n;edkEnd();
        ret.size.height=this->size.height-(edk::float64)n;edkEnd();
        ret.size.length=this->size.length-(edk::float64)n;edkEnd();
        return ret;
    }
    void operator-=(cubef64 vec){
        //
        this->origin.x-=(edk::float64)vec.origin.x;edkEnd();
        this->origin.y-=(edk::float64)vec.origin.y;edkEnd();
        this->origin.z-=(edk::float64)vec.origin.z;edkEnd();
        this->size.width-=(edk::float64)vec.size.width;edkEnd();
        this->size.height-=(edk::float64)vec.size.height;edkEnd();
        this->size.length-=(edk::float64)vec.size.length;edkEnd();
    }
    void operator-=(edk::float32 n){
        //
        this->origin.x-=(edk::float64)n;edkEnd();
        this->origin.y-=(edk::float64)n;edkEnd();
        this->origin.z-=(edk::float64)n;edkEnd();
        this->size.width-=(edk::float64)n;edkEnd();
        this->size.height-=(edk::float64)n;edkEnd();
        this->size.length-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::float64 n){
        //
        this->origin.x-=(edk::float64)n;edkEnd();
        this->origin.y-=(edk::float64)n;edkEnd();
        this->origin.z-=(edk::float64)n;edkEnd();
        this->size.width-=(edk::float64)n;edkEnd();
        this->size.height-=(edk::float64)n;edkEnd();
        this->size.length-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::float64)n;edkEnd();
        this->origin.y-=(edk::float64)n;edkEnd();
        this->origin.z-=(edk::float64)n;edkEnd();
        this->size.width-=(edk::float64)n;edkEnd();
        this->size.height-=(edk::float64)n;edkEnd();
        this->size.length-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::float64)n;edkEnd();
        this->origin.y-=(edk::float64)n;edkEnd();
        this->origin.z-=(edk::float64)n;edkEnd();
        this->size.width-=(edk::float64)n;edkEnd();
        this->size.height-=(edk::float64)n;edkEnd();
        this->size.length-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::float64)n;edkEnd();
        this->origin.y-=(edk::float64)n;edkEnd();
        this->origin.z-=(edk::float64)n;edkEnd();
        this->size.width-=(edk::float64)n;edkEnd();
        this->size.height-=(edk::float64)n;edkEnd();
        this->size.length-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::float64)n;edkEnd();
        this->origin.y-=(edk::float64)n;edkEnd();
        this->origin.z-=(edk::float64)n;edkEnd();
        this->size.width-=(edk::float64)n;edkEnd();
        this->size.height-=(edk::float64)n;edkEnd();
        this->size.length-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::float64)n;edkEnd();
        this->origin.y-=(edk::float64)n;edkEnd();
        this->origin.z-=(edk::float64)n;edkEnd();
        this->size.width-=(edk::float64)n;edkEnd();
        this->size.height-=(edk::float64)n;edkEnd();
        this->size.length-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::float64)n;edkEnd();
        this->origin.y-=(edk::float64)n;edkEnd();
        this->origin.z-=(edk::float64)n;edkEnd();
        this->size.width-=(edk::float64)n;edkEnd();
        this->size.height-=(edk::float64)n;edkEnd();
        this->size.length-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::float64)n;edkEnd();
        this->origin.y-=(edk::float64)n;edkEnd();
        this->origin.z-=(edk::float64)n;edkEnd();
        this->size.width-=(edk::float64)n;edkEnd();
        this->size.height-=(edk::float64)n;edkEnd();
        this->size.length-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::float64)n;edkEnd();
        this->origin.y-=(edk::float64)n;edkEnd();
        this->origin.z-=(edk::float64)n;edkEnd();
        this->size.width-=(edk::float64)n;edkEnd();
        this->size.height-=(edk::float64)n;edkEnd();
        this->size.length-=(edk::float64)n;edkEnd();
    }
    cubef64 operator*(cubef64 cube){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)cube.origin.x;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)cube.origin.y;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)cube.origin.z;edkEnd();
        ret.size.width=this->size.width*(edk::float64)cube.size.width;edkEnd();
        ret.size.height=this->size.height*(edk::float64)cube.size.height;edkEnd();
        ret.size.length=this->size.length*(edk::float64)cube.size.length;edkEnd();
        return ret;
    }
    cubef64 operator*(edk::float32 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)n;edkEnd();
        ret.size.width=this->size.width*(edk::float64)n;edkEnd();
        ret.size.height=this->size.height*(edk::float64)n;edkEnd();
        ret.size.length=this->size.length*(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator*(edk::float64 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)n;edkEnd();
        ret.size.width=this->size.width*(edk::float64)n;edkEnd();
        ret.size.height=this->size.height*(edk::float64)n;edkEnd();
        ret.size.length=this->size.length*(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator*(edk::int8 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)n;edkEnd();
        ret.size.width=this->size.width*(edk::float64)n;edkEnd();
        ret.size.height=this->size.height*(edk::float64)n;edkEnd();
        ret.size.length=this->size.length*(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator*(edk::int32 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)n;edkEnd();
        ret.size.width=this->size.width*(edk::float64)n;edkEnd();
        ret.size.height=this->size.height*(edk::float64)n;edkEnd();
        ret.size.length=this->size.length*(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator*(edk::int16 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)n;edkEnd();
        ret.size.width=this->size.width*(edk::float64)n;edkEnd();
        ret.size.height=this->size.height*(edk::float64)n;edkEnd();
        ret.size.length=this->size.length*(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator*(edk::int64 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)n;edkEnd();
        ret.size.width=this->size.width*(edk::float64)n;edkEnd();
        ret.size.height=this->size.height*(edk::float64)n;edkEnd();
        ret.size.length=this->size.length*(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator*(edk::uint8 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)n;edkEnd();
        ret.size.width=this->size.width*(edk::float64)n;edkEnd();
        ret.size.height=this->size.height*(edk::float64)n;edkEnd();
        ret.size.length=this->size.length*(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator*(edk::uint32 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)n;edkEnd();
        ret.size.width=this->size.width*(edk::float64)n;edkEnd();
        ret.size.height=this->size.height*(edk::float64)n;edkEnd();
        ret.size.length=this->size.length*(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator*(edk::uint16 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)n;edkEnd();
        ret.size.width=this->size.width*(edk::float64)n;edkEnd();
        ret.size.height=this->size.height*(edk::float64)n;edkEnd();
        ret.size.length=this->size.length*(edk::float64)n;edkEnd();
        return ret;
    }
    cubef64 operator*(edk::uint64 n){
        //
        cubef64 ret;edkEnd();
        ret.origin.x=this->origin.x*(edk::float64)n;edkEnd();
        ret.origin.y=this->origin.y*(edk::float64)n;edkEnd();
        ret.origin.z=this->origin.z*(edk::float64)n;edkEnd();
        ret.size.width=this->size.width*(edk::float64)n;edkEnd();
        ret.size.height=this->size.height*(edk::float64)n;edkEnd();
        ret.size.length=this->size.length*(edk::float64)n;edkEnd();
        return ret;
    }
    void operator*=(cubef64 cube){
        //
        this->origin.x*=(edk::float64)cube.origin.x;edkEnd();
        this->origin.y*=(edk::float64)cube.origin.y;edkEnd();
        this->origin.z*=(edk::float64)cube.origin.z;edkEnd();
        this->size.width*=(edk::float64)cube.size.width;edkEnd();
        this->size.height*=(edk::float64)cube.size.height;edkEnd();
        this->size.length*=(edk::float64)cube.size.length;edkEnd();
    }
    void operator*=(edk::float32 n){
        //
        this->origin.x*=(edk::float64)n;edkEnd();
        this->origin.y*=(edk::float64)n;edkEnd();
        this->origin.z*=(edk::float64)n;edkEnd();
        this->size.width*=(edk::float64)n;edkEnd();
        this->size.height*=(edk::float64)n;edkEnd();
        this->size.length*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::float64 n){
        //
        this->origin.x*=(edk::float64)n;edkEnd();
        this->origin.y*=(edk::float64)n;edkEnd();
        this->origin.z*=(edk::float64)n;edkEnd();
        this->size.width*=(edk::float64)n;edkEnd();
        this->size.height*=(edk::float64)n;edkEnd();
        this->size.length*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::float64)n;edkEnd();
        this->origin.y*=(edk::float64)n;edkEnd();
        this->origin.z*=(edk::float64)n;edkEnd();
        this->size.width*=(edk::float64)n;edkEnd();
        this->size.height*=(edk::float64)n;edkEnd();
        this->size.length*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::float64)n;edkEnd();
        this->origin.y*=(edk::float64)n;edkEnd();
        this->origin.z*=(edk::float64)n;edkEnd();
        this->size.width*=(edk::float64)n;edkEnd();
        this->size.height*=(edk::float64)n;edkEnd();
        this->size.length*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::float64)n;edkEnd();
        this->origin.y*=(edk::float64)n;edkEnd();
        this->size.width*=(edk::float64)n;edkEnd();
        this->size.height*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::float64)n;edkEnd();
        this->origin.y*=(edk::float64)n;edkEnd();
        this->origin.z*=(edk::float64)n;edkEnd();
        this->size.width*=(edk::float64)n;edkEnd();
        this->size.height*=(edk::float64)n;edkEnd();
        this->size.length*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::float64)n;edkEnd();
        this->origin.y*=(edk::float64)n;edkEnd();
        this->origin.z*=(edk::float64)n;edkEnd();
        this->size.width*=(edk::float64)n;edkEnd();
        this->size.height*=(edk::float64)n;edkEnd();
        this->size.length*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::float64)n;edkEnd();
        this->origin.y*=(edk::float64)n;edkEnd();
        this->origin.z*=(edk::float64)n;edkEnd();
        this->size.width*=(edk::float64)n;edkEnd();
        this->size.height*=(edk::float64)n;edkEnd();
        this->size.length*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::float64)n;edkEnd();
        this->origin.y*=(edk::float64)n;edkEnd();
        this->origin.z*=(edk::float64)n;edkEnd();
        this->size.width*=(edk::float64)n;edkEnd();
        this->size.height*=(edk::float64)n;edkEnd();
        this->size.length*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::float64)n;edkEnd();
        this->origin.y*=(edk::float64)n;edkEnd();
        this->origin.z*=(edk::float64)n;edkEnd();
        this->size.width*=(edk::float64)n;edkEnd();
        this->size.height*=(edk::float64)n;edkEnd();
        this->size.length*=(edk::float64)n;edkEnd();
    }
    //
    cubef64 operator++(){
        //
        ++this->origin.x;edkEnd();
        ++this->origin.y;edkEnd();
        ++this->origin.z;edkEnd();
        ++this->size.width;edkEnd();
        ++this->size.height;edkEnd();
        ++this->size.length;edkEnd();
        return cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubef64 operator++(edk::int32){
        //
        this->origin.x++;edkEnd();
        this->origin.y++;edkEnd();
        this->origin.z++;edkEnd();
        this->size.width++;edkEnd();
        this->size.height++;edkEnd();
        this->size.length++;edkEnd();
        return cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubef64 operator--(){
        //
        --this->origin.x;edkEnd();
        --this->origin.y;edkEnd();
        --this->origin.z;edkEnd();
        --this->size.width;edkEnd();
        --this->size.height;edkEnd();
        --this->size.length;edkEnd();
        return cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubef64 operator--(edk::int32){
        //
        this->origin.x--;edkEnd();
        this->origin.y--;edkEnd();
        this->origin.z--;edkEnd();
        this->size.width--;edkEnd();
        this->size.height--;edkEnd();
        this->size.length--;edkEnd();
        return cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);edkEnd();
    }
    cubef64 operator()(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);edkEnd();
    }
    cubef64 operator()(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);edkEnd();
    }
    cubef64 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);edkEnd();
    }
    cubef64 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);edkEnd();
    }
    cubef64 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);edkEnd();
    }
    cubef64 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);edkEnd();
    }
    cubef64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);edkEnd();
    }
    cubef64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);edkEnd();
    }
    cubef64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);edkEnd();
    }
    cubef64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;edkEnd();
        this->origin.y=y;edkEnd();
        this->origin.z=z;edkEnd();
        this->size.width=width;edkEnd();
        this->size.height=height;edkEnd();
        this->size.length=length;edkEnd();
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);edkEnd();
    }
};

}//end namespace






#endif // TYPECUBE_H
