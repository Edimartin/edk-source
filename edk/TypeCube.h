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
    //operators
    cubei8 operator=(cubei8 cube){
        //
        this->origin.x=(edk::int8)cube.origin.x;
        this->origin.y=(edk::int8)cube.origin.y;
        this->origin.z=(edk::int8)cube.origin.z;
        this->size.width=(edk::int8)cube.size.width;
        this->size.height=(edk::int8)cube.size.height;
        this->size.length=(edk::int8)cube.size.length;
        return *this;
    }
    cubei8 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    cubei8 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    cubei8 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    cubei8 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    cubei8 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    cubei8 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    cubei8 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }
    cubei8 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->origin.z=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        this->size.length=(edk::int8)n;
        return *this;
    }

    bool operator==(cubei8 cube){
        //
        return (this->origin.x==(edk::int8)cube.origin.x
                &&this->origin.y==(edk::int8)cube.origin.y
                &&this->origin.z==(edk::int8)cube.origin.z
                &&this->size.width==(edk::int8)cube.size.width
                &&this->size.height==(edk::int8)cube.size.height
                &&this->size.length==(edk::int8)cube.size.length
                );
    }
    bool operator!=(cubei8 cube){
        //
        return (this->origin.x!=(edk::int8)cube.origin.x
                ||this->origin.y!=(edk::int8)cube.origin.y
                ||this->origin.z!=(edk::int8)cube.origin.z
                ||this->size.width!=(edk::int8)cube.size.width
                ||this->size.height!=(edk::int8)cube.size.height
                ||this->size.length!=(edk::int8)cube.size.length
                );
    }
    cubei8 operator+(cubei8 cube){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::int8)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::int8)cube.origin.z;
        ret.size.width=this->size.width+(edk::int8)cube.size.width;
        ret.size.height=this->size.height+(edk::int8)cube.size.height;
        ret.size.length=this->size.length+(edk::int8)cube.size.length;
        return ret;
    }
    cubei8 operator+(edk::int8 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    cubei8 operator+(edk::int32 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    cubei8 operator+(edk::int16 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    cubei8 operator+(edk::int64 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    cubei8 operator+(edk::uint8 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    cubei8 operator+(edk::uint32 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    cubei8 operator+(edk::uint16 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    cubei8 operator+(edk::uint64 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.origin.z=this->origin.z+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        ret.size.length=this->size.length+(edk::int8)n;
        return ret;
    }
    void operator+=(cubei8 cube){
        //
        this->origin.x+=(edk::int8)cube.origin.x;
        this->origin.y+=(edk::int8)cube.origin.y;
        this->origin.z+=(edk::int8)cube.origin.z;
        this->size.width+=(edk::int8)cube.size.width;
        this->size.height+=(edk::int8)cube.size.height;
        this->size.length+=(edk::int8)cube.size.length;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->origin.z+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
        this->size.length+=(edk::int8)n;
    }
    cubei8 operator-(cubei8 cube){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::int8)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::int8)cube.origin.z;
        ret.size.width=this->size.width-(edk::int8)cube.size.width;
        ret.size.height=this->size.height-(edk::int8)cube.size.height;
        ret.size.length=this->size.length-(edk::int8)cube.size.length;
        return ret;
    }
    cubei8 operator-(edk::int8 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    cubei8 operator-(edk::int32 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    cubei8 operator-(edk::int16 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    cubei8 operator-(edk::int64 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    cubei8 operator-(edk::uint8 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    cubei8 operator-(edk::uint32 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    cubei8 operator-(edk::uint16 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    cubei8 operator-(edk::uint64 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.origin.z=this->origin.z-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        ret.size.length=this->size.length-(edk::int8)n;
        return ret;
    }
    void operator-=(cubei8 vec){
        //
        this->origin.x-=(edk::int8)vec.origin.x;
        this->origin.y-=(edk::int8)vec.origin.y;
        this->origin.z-=(edk::int8)vec.origin.z;
        this->size.width-=(edk::int8)vec.size.width;
        this->size.height-=(edk::int8)vec.size.height;
        this->size.length-=(edk::int8)vec.size.length;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->origin.z-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
        this->size.length-=(edk::int8)n;
    }
    cubei8 operator*(cubei8 cube){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::int8)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::int8)cube.origin.z;
        ret.size.width=this->size.width*(edk::int8)cube.size.width;
        ret.size.height=this->size.height*(edk::int8)cube.size.height;
        ret.size.length=this->size.length*(edk::int8)cube.size.length;
        return ret;
    }
    cubei8 operator*(edk::int8 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    cubei8 operator*(edk::int32 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    cubei8 operator*(edk::int16 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    cubei8 operator*(edk::int64 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    cubei8 operator*(edk::uint8 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    cubei8 operator*(edk::uint32 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    cubei8 operator*(edk::uint16 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    cubei8 operator*(edk::uint64 n){
        //
        cubei8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.origin.z=this->origin.z*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        ret.size.length=this->size.length*(edk::int8)n;
        return ret;
    }
    void operator*=(cubei8 cube){
        //
        this->origin.x*=(edk::int8)cube.origin.x;
        this->origin.y*=(edk::int8)cube.origin.y;
        this->origin.z*=(edk::int8)cube.origin.z;
        this->size.width*=(edk::int8)cube.size.width;
        this->size.height*=(edk::int8)cube.size.height;
        this->size.length*=(edk::int8)cube.size.length;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->origin.z*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
        this->size.length*=(edk::int8)n;
    }
    //
    cubei8 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei8 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei8 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei8 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return cubei8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei8 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    cubei8 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    cubei8 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    cubei8 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    cubei8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    cubei8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    cubei8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
    }
    cubei8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->origin.z,(edk::int8)this->size.width,(edk::int8)this->size.height,(edk::int8)this->size.length);
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
    //operators
    cubei16 operator=(cubei16 cube){
        //
        this->origin.x=(edk::int16)cube.origin.x;
        this->origin.y=(edk::int16)cube.origin.y;
        this->origin.z=(edk::int16)cube.origin.z;
        this->size.width=(edk::int16)cube.size.width;
        this->size.height=(edk::int16)cube.size.height;
        this->size.length=(edk::int16)cube.size.length;
        return *this;
    }
    cubei16 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    cubei16 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    cubei16 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    cubei16 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    cubei16 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    cubei16 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    cubei16 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }
    cubei16 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->origin.z=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        this->size.length=(edk::int16)n;
        return *this;
    }

    bool operator==(cubei16 cube){
        //
        return (this->origin.x==(edk::int16)cube.origin.x
                &&this->origin.y==(edk::int16)cube.origin.y
                &&this->origin.z==(edk::int16)cube.origin.z
                &&this->size.width==(edk::int16)cube.size.width
                &&this->size.height==(edk::int16)cube.size.height
                &&this->size.length==(edk::int16)cube.size.length
                );
    }
    bool operator!=(cubei16 cube){
        //
        return (this->origin.x!=(edk::int16)cube.origin.x
                ||this->origin.y!=(edk::int16)cube.origin.y
                ||this->origin.z!=(edk::int16)cube.origin.z
                ||this->size.width!=(edk::int16)cube.size.width
                ||this->size.height!=(edk::int16)cube.size.height
                ||this->size.length!=(edk::int16)cube.size.length
                );
    }
    cubei16 operator+(cubei16 cube){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::int16)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::int16)cube.origin.z;
        ret.size.width=this->size.width+(edk::int16)cube.size.width;
        ret.size.height=this->size.height+(edk::int16)cube.size.height;
        ret.size.length=this->size.length+(edk::int16)cube.size.length;
        return ret;
    }
    cubei16 operator+(edk::int8 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    cubei16 operator+(edk::int32 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    cubei16 operator+(edk::int16 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    cubei16 operator+(edk::int64 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    cubei16 operator+(edk::uint8 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    cubei16 operator+(edk::uint32 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    cubei16 operator+(edk::uint16 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    cubei16 operator+(edk::uint64 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.origin.z=this->origin.z+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        ret.size.length=this->size.length+(edk::int16)n;
        return ret;
    }
    void operator+=(cubei16 cube){
        //
        this->origin.x+=(edk::int16)cube.origin.x;
        this->origin.y+=(edk::int16)cube.origin.y;
        this->origin.z+=(edk::int16)cube.origin.z;
        this->size.width+=(edk::int16)cube.size.width;
        this->size.height+=(edk::int16)cube.size.height;
        this->size.length+=(edk::int16)cube.size.length;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->origin.z+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
        this->size.length+=(edk::int16)n;
    }
    cubei16 operator-(cubei16 cube){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::int16)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::int16)cube.origin.z;
        ret.size.width=this->size.width-(edk::int16)cube.size.width;
        ret.size.height=this->size.height-(edk::int16)cube.size.height;
        ret.size.length=this->size.length-(edk::int16)cube.size.length;
        return ret;
    }
    cubei16 operator-(edk::int8 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    cubei16 operator-(edk::int32 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    cubei16 operator-(edk::int16 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    cubei16 operator-(edk::int64 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    cubei16 operator-(edk::uint8 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    cubei16 operator-(edk::uint32 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    cubei16 operator-(edk::uint16 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    cubei16 operator-(edk::uint64 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.origin.z=this->origin.z-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        ret.size.length=this->size.length-(edk::int16)n;
        return ret;
    }
    void operator-=(cubei16 vec){
        //
        this->origin.x-=(edk::int16)vec.origin.x;
        this->origin.y-=(edk::int16)vec.origin.y;
        this->origin.z-=(edk::int16)vec.origin.z;
        this->size.width-=(edk::int16)vec.size.width;
        this->size.height-=(edk::int16)vec.size.height;
        this->size.length-=(edk::int16)vec.size.length;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->origin.z-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
        this->size.length-=(edk::int16)n;
    }
    cubei16 operator*(cubei16 cube){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::int16)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::int16)cube.origin.z;
        ret.size.width=this->size.width*(edk::int16)cube.size.width;
        ret.size.height=this->size.height*(edk::int16)cube.size.height;
        ret.size.length=this->size.length*(edk::int16)cube.size.length;
        return ret;
    }
    cubei16 operator*(edk::int8 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    cubei16 operator*(edk::int32 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    cubei16 operator*(edk::int16 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    cubei16 operator*(edk::int64 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    cubei16 operator*(edk::uint8 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    cubei16 operator*(edk::uint32 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    cubei16 operator*(edk::uint16 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    cubei16 operator*(edk::uint64 n){
        //
        cubei16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.origin.z=this->origin.z*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        ret.size.length=this->size.length*(edk::int16)n;
        return ret;
    }
    void operator*=(cubei16 cube){
        //
        this->origin.x*=(edk::int16)cube.origin.x;
        this->origin.y*=(edk::int16)cube.origin.y;
        this->origin.z*=(edk::int16)cube.origin.z;
        this->size.width*=(edk::int16)cube.size.width;
        this->size.height*=(edk::int16)cube.size.height;
        this->size.length*=(edk::int16)cube.size.length;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->origin.z*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
        this->size.length*=(edk::int16)n;
    }
    //
    cubei16 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei16 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei16 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei16 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return cubei16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei16 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    cubei16 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    cubei16 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    cubei16 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    cubei16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    cubei16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    cubei16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
    }
    cubei16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->origin.z,(edk::int16)this->size.width,(edk::int16)this->size.height,(edk::int16)this->size.length);
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
    //operators
    cubei32 operator=(cubei32 cube){
        //
        this->origin.x=(edk::int32)cube.origin.x;
        this->origin.y=(edk::int32)cube.origin.y;
        this->origin.z=(edk::int32)cube.origin.z;
        this->size.width=(edk::int32)cube.size.width;
        this->size.height=(edk::int32)cube.size.height;
        this->size.length=(edk::int32)cube.size.length;
        return *this;
    }
    cubei32 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    cubei32 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    cubei32 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    cubei32 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    cubei32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    cubei32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    cubei32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }
    cubei32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->origin.z=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        this->size.length=(edk::int32)n;
        return *this;
    }

    bool operator==(cubei32 cube){
        //
        return (this->origin.x==(edk::int32)cube.origin.x
                &&this->origin.y==(edk::int32)cube.origin.y
                &&this->origin.z==(edk::int32)cube.origin.z
                &&this->size.width==(edk::int32)cube.size.width
                &&this->size.height==(edk::int32)cube.size.height
                &&this->size.length==(edk::int32)cube.size.length
                );
    }
    bool operator!=(cubei32 cube){
        //
        return (this->origin.x!=(edk::int32)cube.origin.x
                ||this->origin.y!=(edk::int32)cube.origin.y
                ||this->origin.z!=(edk::int32)cube.origin.z
                ||this->size.width!=(edk::int32)cube.size.width
                ||this->size.height!=(edk::int32)cube.size.height
                ||this->size.length!=(edk::int32)cube.size.length
                );
    }
    cubei32 operator+(cubei32 cube){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::int32)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::int32)cube.origin.z;
        ret.size.width=this->size.width+(edk::int32)cube.size.width;
        ret.size.height=this->size.height+(edk::int32)cube.size.height;
        ret.size.length=this->size.length+(edk::int32)cube.size.length;
        return ret;
    }
    cubei32 operator+(edk::int8 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    cubei32 operator+(edk::int32 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    cubei32 operator+(edk::int16 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    cubei32 operator+(edk::int64 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    cubei32 operator+(edk::uint8 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    cubei32 operator+(edk::uint32 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    cubei32 operator+(edk::uint16 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    cubei32 operator+(edk::uint64 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.origin.z=this->origin.z+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        ret.size.length=this->size.length+(edk::int32)n;
        return ret;
    }
    void operator+=(cubei32 cube){
        //
        this->origin.x+=(edk::int32)cube.origin.x;
        this->origin.y+=(edk::int32)cube.origin.y;
        this->origin.z+=(edk::int32)cube.origin.z;
        this->size.width+=(edk::int32)cube.size.width;
        this->size.height+=(edk::int32)cube.size.height;
        this->size.length+=(edk::int32)cube.size.length;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->origin.z+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
        this->size.length+=(edk::int32)n;
    }
    cubei32 operator-(cubei32 cube){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::int32)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::int32)cube.origin.z;
        ret.size.width=this->size.width-(edk::int32)cube.size.width;
        ret.size.height=this->size.height-(edk::int32)cube.size.height;
        ret.size.length=this->size.length-(edk::int32)cube.size.length;
        return ret;
    }
    cubei32 operator-(edk::int8 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    cubei32 operator-(edk::int32 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    cubei32 operator-(edk::int16 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    cubei32 operator-(edk::int64 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    cubei32 operator-(edk::uint8 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    cubei32 operator-(edk::uint32 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    cubei32 operator-(edk::uint16 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    cubei32 operator-(edk::uint64 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.origin.z=this->origin.z-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        ret.size.length=this->size.length-(edk::int32)n;
        return ret;
    }
    void operator-=(cubei32 vec){
        //
        this->origin.x-=(edk::int32)vec.origin.x;
        this->origin.y-=(edk::int32)vec.origin.y;
        this->origin.z-=(edk::int32)vec.origin.z;
        this->size.width-=(edk::int32)vec.size.width;
        this->size.height-=(edk::int32)vec.size.height;
        this->size.length-=(edk::int32)vec.size.length;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->origin.z-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
        this->size.length-=(edk::int32)n;
    }
    cubei32 operator*(cubei32 cube){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::int32)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::int32)cube.origin.z;
        ret.size.width=this->size.width*(edk::int32)cube.size.width;
        ret.size.height=this->size.height*(edk::int32)cube.size.height;
        ret.size.length=this->size.length*(edk::int32)cube.size.length;
        return ret;
    }
    cubei32 operator*(edk::int8 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    cubei32 operator*(edk::int32 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    cubei32 operator*(edk::int16 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    cubei32 operator*(edk::int64 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    cubei32 operator*(edk::uint8 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    cubei32 operator*(edk::uint32 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    cubei32 operator*(edk::uint16 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    cubei32 operator*(edk::uint64 n){
        //
        cubei32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.origin.z=this->origin.z*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        ret.size.length=this->size.length*(edk::int32)n;
        return ret;
    }
    void operator*=(cubei32 cube){
        //
        this->origin.x*=(edk::int32)cube.origin.x;
        this->origin.y*=(edk::int32)cube.origin.y;
        this->origin.z*=(edk::int32)cube.origin.z;
        this->size.width*=(edk::int32)cube.size.width;
        this->size.height*=(edk::int32)cube.size.height;
        this->size.length*=(edk::int32)cube.size.length;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->origin.z*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
        this->size.length*=(edk::int32)n;
    }
    //
    cubei32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return cubei32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei32 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    cubei32 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    cubei32 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    cubei32 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    cubei32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    cubei32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    cubei32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
    }
    cubei32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->origin.z,(edk::int32)this->size.width,(edk::int32)this->size.height,(edk::int32)this->size.length);
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
    //operators
    cubei64 operator=(cubei64 cube){
        //
        this->origin.x=(edk::int64)cube.origin.x;
        this->origin.y=(edk::int64)cube.origin.y;
        this->origin.z=(edk::int64)cube.origin.z;
        this->size.width=(edk::int64)cube.size.width;
        this->size.height=(edk::int64)cube.size.height;
        this->size.length=(edk::int64)cube.size.length;
        return *this;
    }
    cubei64 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    cubei64 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    cubei64 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    cubei64 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    cubei64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    cubei64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    cubei64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }
    cubei64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->origin.z=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        this->size.length=(edk::int64)n;
        return *this;
    }

    bool operator==(cubei64 cube){
        //
        return (this->origin.x==(edk::int64)cube.origin.x
                &&this->origin.y==(edk::int64)cube.origin.y
                &&this->origin.z==(edk::int64)cube.origin.z
                &&this->size.width==(edk::int64)cube.size.width
                &&this->size.height==(edk::int64)cube.size.height
                &&this->size.length==(edk::int64)cube.size.length
                );
    }
    bool operator!=(cubei64 cube){
        //
        return (this->origin.x!=(edk::int64)cube.origin.x
                ||this->origin.y!=(edk::int64)cube.origin.y
                ||this->origin.z!=(edk::int64)cube.origin.z
                ||this->size.width!=(edk::int64)cube.size.width
                ||this->size.height!=(edk::int64)cube.size.height
                ||this->size.length!=(edk::int64)cube.size.length
                );
    }
    cubei64 operator+(cubei64 cube){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::int64)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::int64)cube.origin.z;
        ret.size.width=this->size.width+(edk::int64)cube.size.width;
        ret.size.height=this->size.height+(edk::int64)cube.size.height;
        ret.size.length=this->size.length+(edk::int64)cube.size.length;
        return ret;
    }
    cubei64 operator+(edk::int8 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    cubei64 operator+(edk::int32 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    cubei64 operator+(edk::int16 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    cubei64 operator+(edk::int64 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    cubei64 operator+(edk::uint8 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    cubei64 operator+(edk::uint32 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    cubei64 operator+(edk::uint16 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    cubei64 operator+(edk::uint64 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.origin.z=this->origin.z+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        ret.size.length=this->size.length+(edk::int64)n;
        return ret;
    }
    void operator+=(cubei64 cube){
        //
        this->origin.x+=(edk::int64)cube.origin.x;
        this->origin.y+=(edk::int64)cube.origin.y;
        this->origin.z+=(edk::int64)cube.origin.z;
        this->size.width+=(edk::int64)cube.size.width;
        this->size.height+=(edk::int64)cube.size.height;
        this->size.length+=(edk::int64)cube.size.length;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->origin.z+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
        this->size.length+=(edk::int64)n;
    }
    cubei64 operator-(cubei64 cube){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::int64)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::int64)cube.origin.z;
        ret.size.width=this->size.width-(edk::int64)cube.size.width;
        ret.size.height=this->size.height-(edk::int64)cube.size.height;
        ret.size.length=this->size.length-(edk::int64)cube.size.length;
        return ret;
    }
    cubei64 operator-(edk::int8 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    cubei64 operator-(edk::int32 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    cubei64 operator-(edk::int16 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    cubei64 operator-(edk::int64 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    cubei64 operator-(edk::uint8 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    cubei64 operator-(edk::uint32 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    cubei64 operator-(edk::uint16 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    cubei64 operator-(edk::uint64 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.origin.z=this->origin.z-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        ret.size.length=this->size.length-(edk::int64)n;
        return ret;
    }
    void operator-=(cubei64 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;
        this->origin.y-=(edk::int64)vec.origin.y;
        this->origin.z-=(edk::int64)vec.origin.z;
        this->size.width-=(edk::int64)vec.size.width;
        this->size.height-=(edk::int64)vec.size.height;
        this->size.length-=(edk::int64)vec.size.length;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->origin.z-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
        this->size.length-=(edk::int64)n;
    }
    cubei64 operator*(cubei64 cube){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::int64)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::int64)cube.origin.z;
        ret.size.width=this->size.width*(edk::int64)cube.size.width;
        ret.size.height=this->size.height*(edk::int64)cube.size.height;
        ret.size.length=this->size.length*(edk::int64)cube.size.length;
        return ret;
    }
    cubei64 operator*(edk::int8 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    cubei64 operator*(edk::int32 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    cubei64 operator*(edk::int16 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    cubei64 operator*(edk::int64 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    cubei64 operator*(edk::uint8 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    cubei64 operator*(edk::uint32 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    cubei64 operator*(edk::uint16 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    cubei64 operator*(edk::uint64 n){
        //
        cubei64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.origin.z=this->origin.z*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        ret.size.length=this->size.length*(edk::int64)n;
        return ret;
    }
    void operator*=(cubei64 cube){
        //
        this->origin.x*=(edk::int64)cube.origin.x;
        this->origin.y*=(edk::int64)cube.origin.y;
        this->origin.z*=(edk::int64)cube.origin.z;
        this->size.width*=(edk::int64)cube.size.width;
        this->size.height*=(edk::int64)cube.size.height;
        this->size.length*=(edk::int64)cube.size.length;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->origin.z*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
        this->size.length*=(edk::int64)n;
    }
    //
    cubei64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return cubei64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubei64 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    cubei64 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    cubei64 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    cubei64 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    cubei64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    cubei64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    cubei64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
    }
    cubei64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubei64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->origin.z,(edk::int64)this->size.width,(edk::int64)this->size.height,(edk::int64)this->size.length);
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

    //operators
    cubeui8 operator=(cubeui8 cube){
        //
        this->origin.x=(edk::uint8)cube.origin.x;
        this->origin.y=(edk::uint8)cube.origin.y;
        this->origin.z=(edk::uint8)cube.origin.z;
        this->size.width=(edk::uint8)cube.size.width;
        this->size.height=(edk::uint8)cube.size.height;
        this->size.length=(edk::uint8)cube.size.length;
        return *this;
    }
    cubeui8 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->origin.z=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        this->size.length=(edk::uint8)n;
        return *this;
    }
    cubeui8 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->origin.z=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        this->size.length=(edk::uint8)n;
        return *this;
    }
    cubeui8 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->origin.z=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        this->size.length=(edk::uint8)n;
        return *this;
    }
    cubeui8 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->origin.z=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        this->size.length=(edk::uint8)n;
        return *this;
    }

    bool operator==(cubeui8 cube){
        //
        return (this->origin.x==(edk::uint8)cube.origin.x
                &&this->origin.y==(edk::uint8)cube.origin.y
                &&this->origin.z==(edk::uint8)cube.origin.z
                &&this->size.width==(edk::uint8)cube.size.width
                &&this->size.height==(edk::uint8)cube.size.height
                &&this->size.length==(edk::uint8)cube.size.length
                );
    }
    bool operator!=(cubeui8 cube){
        //
        return (this->origin.x!=(edk::uint8)cube.origin.x
                ||this->origin.y!=(edk::uint8)cube.origin.y
                ||this->origin.z!=(edk::uint8)cube.origin.z
                ||this->size.width!=(edk::uint8)cube.size.width
                ||this->size.height!=(edk::uint8)cube.size.height
                ||this->size.length!=(edk::uint8)cube.size.length
                );
    }
    cubeui8 operator+(cubeui8 cube){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::uint8)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::uint8)cube.origin.z;
        ret.size.width=this->size.width+(edk::uint8)cube.size.width;
        ret.size.height=this->size.height+(edk::uint8)cube.size.height;
        ret.size.length=this->size.length+(edk::uint8)cube.size.length;
        return ret;
    }
    cubeui8 operator+(edk::uint8 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.origin.z=this->origin.z+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        ret.size.length=this->size.length+(edk::uint8)n;
        return ret;
    }
    cubeui8 operator+(edk::uint32 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.origin.z=this->origin.z+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        ret.size.length=this->size.length+(edk::uint8)n;
        return ret;
    }
    cubeui8 operator+(edk::uint16 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.origin.z=this->origin.z+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        ret.size.length=this->size.length+(edk::uint8)n;
        return ret;
    }
    cubeui8 operator+(edk::uint64 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.origin.z=this->origin.z+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        ret.size.length=this->size.length+(edk::uint8)n;
        return ret;
    }
    void operator+=(cubeui8 cube){
        //
        this->origin.x+=(edk::uint8)cube.origin.x;
        this->origin.y+=(edk::uint8)cube.origin.y;
        this->origin.z+=(edk::uint8)cube.origin.z;
        this->size.width+=(edk::uint8)cube.size.width;
        this->size.height+=(edk::uint8)cube.size.height;
        this->size.length+=(edk::uint8)cube.size.length;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->origin.z+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
        this->size.length+=(edk::uint8)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->origin.z+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
        this->size.length+=(edk::uint8)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->origin.z+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
        this->size.length+=(edk::uint8)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->origin.z+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
        this->size.length+=(edk::uint8)n;
    }
    cubeui8 operator-(cubeui8 cube){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::uint8)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::uint8)cube.origin.z;
        ret.size.width=this->size.width-(edk::uint8)cube.size.width;
        ret.size.height=this->size.height-(edk::uint8)cube.size.height;
        ret.size.length=this->size.length-(edk::uint8)cube.size.length;
        return ret;
    }
    cubeui8 operator-(edk::uint8 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.origin.z=this->origin.z-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        ret.size.length=this->size.length-(edk::uint8)n;
        return ret;
    }
    cubeui8 operator-(edk::uint32 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.origin.z=this->origin.z-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        ret.size.length=this->size.length-(edk::uint8)n;
        return ret;
    }
    cubeui8 operator-(edk::uint16 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.origin.z=this->origin.z-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        ret.size.length=this->size.length-(edk::uint8)n;
        return ret;
    }
    cubeui8 operator-(edk::uint64 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.origin.z=this->origin.z-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        ret.size.length=this->size.length-(edk::uint8)n;
        return ret;
    }
    void operator-=(cubeui8 vec){
        //
        this->origin.x-=(edk::uint8)vec.origin.x;
        this->origin.y-=(edk::uint8)vec.origin.y;
        this->origin.z-=(edk::uint8)vec.origin.z;
        this->size.width-=(edk::uint8)vec.size.width;
        this->size.height-=(edk::uint8)vec.size.height;
        this->size.length-=(edk::uint8)vec.size.length;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->origin.z-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
        this->size.length-=(edk::uint8)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->origin.z-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
        this->size.length-=(edk::uint8)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->origin.z-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
        this->size.length-=(edk::uint8)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->origin.z-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
        this->size.length-=(edk::uint8)n;
    }
    cubeui8 operator*(cubeui8 cube){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::uint8)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::uint8)cube.origin.z;
        ret.size.width=this->size.width*(edk::uint8)cube.size.width;
        ret.size.height=this->size.height*(edk::uint8)cube.size.height;
        ret.size.length=this->size.length*(edk::uint8)cube.size.length;
        return ret;
    }
    cubeui8 operator*(edk::uint8 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.origin.z=this->origin.z*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        ret.size.length=this->size.length*(edk::uint8)n;
        return ret;
    }
    cubeui8 operator*(edk::uint32 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.origin.z=this->origin.z*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        ret.size.length=this->size.length*(edk::uint8)n;
        return ret;
    }
    cubeui8 operator*(edk::uint16 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.origin.z=this->origin.z*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        ret.size.length=this->size.length*(edk::uint8)n;
        return ret;
    }
    cubeui8 operator*(edk::uint64 n){
        //
        cubeui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.origin.z=this->origin.z*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        ret.size.length=this->size.length*(edk::uint8)n;
        return ret;
    }
    void operator*=(cubeui8 cube){
        //
        this->origin.x*=(edk::uint8)cube.origin.x;
        this->origin.y*=(edk::uint8)cube.origin.y;
        this->origin.z*=(edk::uint8)cube.origin.z;
        this->size.width*=(edk::uint8)cube.size.width;
        this->size.height*=(edk::uint8)cube.size.height;
        this->size.length*=(edk::uint8)cube.size.length;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->origin.z*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
        this->size.length*=(edk::uint8)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->origin.z*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
        this->size.length*=(edk::uint8)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->origin.z*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
        this->size.length*=(edk::uint8)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->origin.z*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
        this->size.length*=(edk::uint8)n;
    }
    //
    cubeui8 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui8 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui8 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui8 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return cubeui8(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);
    }
    cubeui8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->origin.z=(edk::uint8)z;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        this->size.length=(edk::uint8)length;
        return cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);
    }
    cubeui8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->origin.z=(edk::uint8)z;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        this->size.length=(edk::uint8)length;
        return cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);
    }
    cubeui8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->origin.z=(edk::uint8)z;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        this->size.length=(edk::uint8)length;
        return cubeui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->origin.z,(edk::uint8)this->size.width,(edk::uint8)this->size.height,(edk::uint8)this->size.length);
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

    //operators
    cubeui16 operator=(cubeui16 cube){
        //
        this->origin.x=(edk::uint16)cube.origin.x;
        this->origin.y=(edk::uint16)cube.origin.y;
        this->origin.z=(edk::uint16)cube.origin.z;
        this->size.width=(edk::uint16)cube.size.width;
        this->size.height=(edk::uint16)cube.size.height;
        this->size.length=(edk::uint16)cube.size.length;
        return *this;
    }
    cubeui16 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->origin.z=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        this->size.length=(edk::uint16)n;
        return *this;
    }
    cubeui16 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->origin.z=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        this->size.length=(edk::uint16)n;
        return *this;
    }
    cubeui16 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->origin.z=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        this->size.length=(edk::uint16)n;
        return *this;
    }
    cubeui16 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->origin.z=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        this->size.length=(edk::uint16)n;
        return *this;
    }

    bool operator==(cubeui16 cube){
        //
        return (this->origin.x==(edk::uint16)cube.origin.x
                &&this->origin.y==(edk::uint16)cube.origin.y
                &&this->origin.z==(edk::uint16)cube.origin.z
                &&this->size.width==(edk::uint16)cube.size.width
                &&this->size.height==(edk::uint16)cube.size.height
                &&this->size.length==(edk::uint16)cube.size.length
                );
    }
    bool operator!=(cubeui16 cube){
        //
        return (this->origin.x!=(edk::uint16)cube.origin.x
                ||this->origin.y!=(edk::uint16)cube.origin.y
                ||this->origin.z!=(edk::uint16)cube.origin.z
                ||this->size.width!=(edk::uint16)cube.size.width
                ||this->size.height!=(edk::uint16)cube.size.height
                ||this->size.length!=(edk::uint16)cube.size.length
                );
    }
    cubeui16 operator+(cubeui16 cube){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::uint16)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::uint16)cube.origin.z;
        ret.size.width=this->size.width+(edk::uint16)cube.size.width;
        ret.size.height=this->size.height+(edk::uint16)cube.size.height;
        ret.size.length=this->size.length+(edk::uint16)cube.size.length;
        return ret;
    }
    cubeui16 operator+(edk::uint8 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.origin.z=this->origin.z+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        ret.size.length=this->size.length+(edk::uint16)n;
        return ret;
    }
    cubeui16 operator+(edk::uint32 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.origin.z=this->origin.z+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        ret.size.length=this->size.length+(edk::uint16)n;
        return ret;
    }
    cubeui16 operator+(edk::uint16 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.origin.z=this->origin.z+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        ret.size.length=this->size.length+(edk::uint16)n;
        return ret;
    }
    cubeui16 operator+(edk::uint64 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.origin.z=this->origin.z+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        ret.size.length=this->size.length+(edk::uint16)n;
        return ret;
    }
    void operator+=(cubeui16 cube){
        //
        this->origin.x+=(edk::uint16)cube.origin.x;
        this->origin.y+=(edk::uint16)cube.origin.y;
        this->origin.z+=(edk::uint16)cube.origin.z;
        this->size.width+=(edk::uint16)cube.size.width;
        this->size.height+=(edk::uint16)cube.size.height;
        this->size.length+=(edk::uint16)cube.size.length;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->origin.z+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
        this->size.length+=(edk::uint16)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->origin.z+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
        this->size.length+=(edk::uint16)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->origin.z+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
        this->size.length+=(edk::uint16)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->origin.z+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
        this->size.length+=(edk::uint16)n;
    }
    cubeui16 operator-(cubeui16 cube){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::uint16)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::uint16)cube.origin.z;
        ret.size.width=this->size.width-(edk::uint16)cube.size.width;
        ret.size.height=this->size.height-(edk::uint16)cube.size.height;
        ret.size.length=this->size.length-(edk::uint16)cube.size.length;
        return ret;
    }
    cubeui16 operator-(edk::uint8 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.origin.z=this->origin.z-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        ret.size.length=this->size.length-(edk::uint16)n;
        return ret;
    }
    cubeui16 operator-(edk::uint32 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.origin.z=this->origin.z-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        ret.size.length=this->size.length-(edk::uint16)n;
        return ret;
    }
    cubeui16 operator-(edk::uint16 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.origin.z=this->origin.z-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        ret.size.length=this->size.length-(edk::uint16)n;
        return ret;
    }
    cubeui16 operator-(edk::uint64 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.origin.z=this->origin.z-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        ret.size.length=this->size.length-(edk::uint16)n;
        return ret;
    }
    void operator-=(cubeui16 vec){
        //
        this->origin.x-=(edk::uint16)vec.origin.x;
        this->origin.y-=(edk::uint16)vec.origin.y;
        this->origin.z-=(edk::uint16)vec.origin.z;
        this->size.width-=(edk::uint16)vec.size.width;
        this->size.height-=(edk::uint16)vec.size.height;
        this->size.length-=(edk::uint16)vec.size.length;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->origin.z-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
        this->size.length-=(edk::uint16)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->origin.z-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
        this->size.length-=(edk::uint16)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->origin.z-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
        this->size.length-=(edk::uint16)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->origin.z-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
        this->size.length-=(edk::uint16)n;
    }
    cubeui16 operator*(cubeui16 cube){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::uint16)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::uint16)cube.origin.z;
        ret.size.width=this->size.width*(edk::uint16)cube.size.width;
        ret.size.height=this->size.height*(edk::uint16)cube.size.height;
        ret.size.length=this->size.length*(edk::uint16)cube.size.length;
        return ret;
    }
    cubeui16 operator*(edk::uint8 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.origin.z=this->origin.z*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        ret.size.length=this->size.length*(edk::uint16)n;
        return ret;
    }
    cubeui16 operator*(edk::uint32 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.origin.z=this->origin.z*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        ret.size.length=this->size.length*(edk::uint16)n;
        return ret;
    }
    cubeui16 operator*(edk::uint16 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.origin.z=this->origin.z*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        ret.size.length=this->size.length*(edk::uint16)n;
        return ret;
    }
    cubeui16 operator*(edk::uint64 n){
        //
        cubeui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.origin.z=this->origin.z*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        ret.size.length=this->size.length*(edk::uint16)n;
        return ret;
    }
    void operator*=(cubeui16 cube){
        //
        this->origin.x*=(edk::uint16)cube.origin.x;
        this->origin.y*=(edk::uint16)cube.origin.y;
        this->origin.z*=(edk::uint16)cube.origin.z;
        this->size.width*=(edk::uint16)cube.size.width;
        this->size.height*=(edk::uint16)cube.size.height;
        this->size.length*=(edk::uint16)cube.size.length;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->origin.z*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
        this->size.length*=(edk::uint16)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->origin.z*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
        this->size.length*=(edk::uint16)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->origin.z*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
        this->size.length*=(edk::uint16)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->origin.z*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
        this->size.length*=(edk::uint16)n;
    }
    //
    cubeui16 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui16 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui16 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui16 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return cubeui16(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);
    }
    cubeui16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->origin.z=(edk::uint16)z;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        this->size.length=(edk::uint16)length;
        return cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);
    }
    cubeui16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->origin.z=(edk::uint16)z;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        this->size.length=(edk::uint16)length;
        return cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);
    }
    cubeui16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->origin.z=(edk::uint16)z;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        this->size.length=(edk::uint16)length;
        return cubeui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->origin.z,(edk::uint16)this->size.width,(edk::uint16)this->size.height,(edk::uint16)this->size.length);
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

    //operators
    cubeui32 operator=(cubeui32 cube){
        //
        this->origin.x=(edk::uint32)cube.origin.x;
        this->origin.y=(edk::uint32)cube.origin.y;
        this->origin.z=(edk::uint32)cube.origin.z;
        this->size.width=(edk::uint32)cube.size.width;
        this->size.height=(edk::uint32)cube.size.height;
        this->size.length=(edk::uint32)cube.size.length;
        return *this;
    }
    cubeui32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->origin.z=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        this->size.length=(edk::uint32)n;
        return *this;
    }
    cubeui32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->origin.z=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        this->size.length=(edk::uint32)n;
        return *this;
    }
    cubeui32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->origin.z=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        this->size.length=(edk::uint32)n;
        return *this;
    }
    cubeui32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->origin.z=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        this->size.length=(edk::uint32)n;
        return *this;
    }

    bool operator==(cubeui32 cube){
        //
        return (this->origin.x==(edk::uint32)cube.origin.x
                &&this->origin.y==(edk::uint32)cube.origin.y
                &&this->origin.z==(edk::uint32)cube.origin.z
                &&this->size.width==(edk::uint32)cube.size.width
                &&this->size.height==(edk::uint32)cube.size.height
                &&this->size.length==(edk::uint32)cube.size.length
                );
    }
    bool operator!=(cubeui32 cube){
        //
        return (this->origin.x!=(edk::uint32)cube.origin.x
                ||this->origin.y!=(edk::uint32)cube.origin.y
                ||this->origin.z!=(edk::uint32)cube.origin.z
                ||this->size.width!=(edk::uint32)cube.size.width
                ||this->size.height!=(edk::uint32)cube.size.height
                ||this->size.length!=(edk::uint32)cube.size.length
                );
    }
    cubeui32 operator+(cubeui32 cube){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::uint32)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::uint32)cube.origin.z;
        ret.size.width=this->size.width+(edk::uint32)cube.size.width;
        ret.size.height=this->size.height+(edk::uint32)cube.size.height;
        ret.size.length=this->size.length+(edk::uint32)cube.size.length;
        return ret;
    }
    cubeui32 operator+(edk::uint8 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.origin.z=this->origin.z+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        ret.size.length=this->size.length+(edk::uint32)n;
        return ret;
    }
    cubeui32 operator+(edk::uint32 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.origin.z=this->origin.z+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        ret.size.length=this->size.length+(edk::uint32)n;
        return ret;
    }
    cubeui32 operator+(edk::uint16 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.origin.z=this->origin.z+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        ret.size.length=this->size.length+(edk::uint32)n;
        return ret;
    }
    cubeui32 operator+(edk::uint64 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.origin.z=this->origin.z+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        ret.size.length=this->size.length+(edk::uint32)n;
        return ret;
    }
    void operator+=(cubeui32 cube){
        //
        this->origin.x+=(edk::uint32)cube.origin.x;
        this->origin.y+=(edk::uint32)cube.origin.y;
        this->origin.z+=(edk::uint32)cube.origin.z;
        this->size.width+=(edk::uint32)cube.size.width;
        this->size.height+=(edk::uint32)cube.size.height;
        this->size.length+=(edk::uint32)cube.size.length;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->origin.z+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
        this->size.length+=(edk::uint32)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->origin.z+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
        this->size.length+=(edk::uint32)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->origin.z+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
        this->size.length+=(edk::uint32)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->origin.z+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
        this->size.length+=(edk::uint32)n;
    }
    cubeui32 operator-(cubeui32 cube){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::uint32)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::uint32)cube.origin.z;
        ret.size.width=this->size.width-(edk::uint32)cube.size.width;
        ret.size.height=this->size.height-(edk::uint32)cube.size.height;
        ret.size.length=this->size.length-(edk::uint32)cube.size.length;
        return ret;
    }
    cubeui32 operator-(edk::uint8 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.origin.z=this->origin.z-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        ret.size.length=this->size.length-(edk::uint32)n;
        return ret;
    }
    cubeui32 operator-(edk::uint32 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.origin.z=this->origin.z-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        ret.size.length=this->size.length-(edk::uint32)n;
        return ret;
    }
    cubeui32 operator-(edk::uint16 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.origin.z=this->origin.z-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        ret.size.length=this->size.length-(edk::uint32)n;
        return ret;
    }
    cubeui32 operator-(edk::uint64 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.origin.z=this->origin.z-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        ret.size.length=this->size.length-(edk::uint32)n;
        return ret;
    }
    void operator-=(cubeui32 vec){
        //
        this->origin.x-=(edk::uint32)vec.origin.x;
        this->origin.y-=(edk::uint32)vec.origin.y;
        this->origin.z-=(edk::uint32)vec.origin.z;
        this->size.width-=(edk::uint32)vec.size.width;
        this->size.height-=(edk::uint32)vec.size.height;
        this->size.length-=(edk::uint32)vec.size.length;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->origin.z-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
        this->size.length-=(edk::uint32)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->origin.z-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
        this->size.length-=(edk::uint32)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->origin.z-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
        this->size.length-=(edk::uint32)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->origin.z-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
        this->size.length-=(edk::uint32)n;
    }
    cubeui32 operator*(cubeui32 cube){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::uint32)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::uint32)cube.origin.z;
        ret.size.width=this->size.width*(edk::uint32)cube.size.width;
        ret.size.height=this->size.height*(edk::uint32)cube.size.height;
        ret.size.length=this->size.length*(edk::uint32)cube.size.length;
        return ret;
    }
    cubeui32 operator*(edk::uint8 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.origin.z=this->origin.z*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        ret.size.length=this->size.length*(edk::uint32)n;
        return ret;
    }
    cubeui32 operator*(edk::uint32 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.origin.z=this->origin.z*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        ret.size.length=this->size.length*(edk::uint32)n;
        return ret;
    }
    cubeui32 operator*(edk::uint16 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.origin.z=this->origin.z*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        ret.size.length=this->size.length*(edk::uint32)n;
        return ret;
    }
    cubeui32 operator*(edk::uint64 n){
        //
        cubeui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.origin.z=this->origin.z*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        ret.size.length=this->size.length*(edk::uint32)n;
        return ret;
    }
    void operator*=(cubeui32 cube){
        //
        this->origin.x*=(edk::uint32)cube.origin.x;
        this->origin.y*=(edk::uint32)cube.origin.y;
        this->origin.z*=(edk::uint32)cube.origin.z;
        this->size.width*=(edk::uint32)cube.size.width;
        this->size.height*=(edk::uint32)cube.size.height;
        this->size.length*=(edk::uint32)cube.size.length;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->origin.z*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
        this->size.length*=(edk::uint32)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->origin.z*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
        this->size.length*=(edk::uint32)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->origin.z*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
        this->size.length*=(edk::uint32)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->origin.z*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
        this->size.length*=(edk::uint32)n;
    }
    //
    cubeui32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return cubeui32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);
    }
    cubeui32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->origin.z=(edk::uint32)z;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        this->size.length=(edk::uint32)length;
        return cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);
    }
    cubeui32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->origin.z=(edk::uint32)z;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        this->size.length=(edk::uint32)length;
        return cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);
    }
    cubeui32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->origin.z=(edk::uint32)z;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        this->size.length=(edk::uint32)length;
        return cubeui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->origin.z,(edk::uint32)this->size.width,(edk::uint32)this->size.height,(edk::uint32)this->size.length);
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

    //operators
    cubeui64 operator=(cubeui64 cube){
        //
        this->origin.x=(edk::uint64)cube.origin.x;
        this->origin.y=(edk::uint64)cube.origin.y;
        this->origin.z=(edk::uint64)cube.origin.z;
        this->size.width=(edk::uint64)cube.size.width;
        this->size.height=(edk::uint64)cube.size.height;
        this->size.length=(edk::uint64)cube.size.length;
        return *this;
    }
    cubeui64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->origin.z=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        this->size.length=(edk::uint64)n;
        return *this;
    }
    cubeui64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->origin.z=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        this->size.length=(edk::uint64)n;
        return *this;
    }
    cubeui64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->origin.z=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        this->size.length=(edk::uint64)n;
        return *this;
    }
    cubeui64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->origin.z=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        this->size.length=(edk::uint64)n;
        return *this;
    }

    bool operator==(cubeui64 cube){
        //
        return (this->origin.x==(edk::uint64)cube.origin.x
                &&this->origin.y==(edk::uint64)cube.origin.y
                &&this->origin.z==(edk::uint64)cube.origin.z
                &&this->size.width==(edk::uint64)cube.size.width
                &&this->size.height==(edk::uint64)cube.size.height
                &&this->size.length==(edk::uint64)cube.size.length
                );
    }
    bool operator!=(cubeui64 cube){
        //
        return (this->origin.x!=(edk::uint64)cube.origin.x
                ||this->origin.y!=(edk::uint64)cube.origin.y
                ||this->origin.z!=(edk::uint64)cube.origin.z
                ||this->size.width!=(edk::uint64)cube.size.width
                ||this->size.height!=(edk::uint64)cube.size.height
                ||this->size.length!=(edk::uint64)cube.size.length
                );
    }
    cubeui64 operator+(cubeui64 cube){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)cube.origin.x;
        ret.origin.y=this->origin.y+(edk::uint64)cube.origin.y;
        ret.origin.z=this->origin.z+(edk::uint64)cube.origin.z;
        ret.size.width=this->size.width+(edk::uint64)cube.size.width;
        ret.size.height=this->size.height+(edk::uint64)cube.size.height;
        ret.size.length=this->size.length+(edk::uint64)cube.size.length;
        return ret;
    }
    cubeui64 operator+(edk::uint8 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.origin.z=this->origin.z+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        ret.size.length=this->size.length+(edk::uint64)n;
        return ret;
    }
    cubeui64 operator+(edk::uint32 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.origin.z=this->origin.z+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        ret.size.length=this->size.length+(edk::uint64)n;
        return ret;
    }
    cubeui64 operator+(edk::uint16 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.origin.z=this->origin.z+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        ret.size.length=this->size.length+(edk::uint64)n;
        return ret;
    }
    cubeui64 operator+(edk::uint64 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.origin.z=this->origin.z+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        ret.size.length=this->size.length+(edk::uint64)n;
        return ret;
    }
    void operator+=(cubeui64 cube){
        //
        this->origin.x+=(edk::uint64)cube.origin.x;
        this->origin.y+=(edk::uint64)cube.origin.y;
        this->origin.z+=(edk::uint64)cube.origin.z;
        this->size.width+=(edk::uint64)cube.size.width;
        this->size.height+=(edk::uint64)cube.size.height;
        this->size.length+=(edk::uint64)cube.size.length;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->origin.z+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
        this->size.length+=(edk::uint64)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->origin.z+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
        this->size.length+=(edk::uint64)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->origin.z+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
        this->size.length+=(edk::uint64)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->origin.z+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
        this->size.length+=(edk::uint64)n;
    }
    cubeui64 operator-(cubeui64 cube){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)cube.origin.x;
        ret.origin.y=this->origin.y-(edk::uint64)cube.origin.y;
        ret.origin.z=this->origin.z-(edk::uint64)cube.origin.z;
        ret.size.width=this->size.width-(edk::uint64)cube.size.width;
        ret.size.height=this->size.height-(edk::uint64)cube.size.height;
        ret.size.length=this->size.length-(edk::uint64)cube.size.length;
        return ret;
    }
    cubeui64 operator-(edk::uint8 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.origin.z=this->origin.z-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        ret.size.length=this->size.length-(edk::uint64)n;
        return ret;
    }
    cubeui64 operator-(edk::uint32 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.origin.z=this->origin.z-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        ret.size.length=this->size.length-(edk::uint64)n;
        return ret;
    }
    cubeui64 operator-(edk::uint16 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.origin.z=this->origin.z-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        ret.size.length=this->size.length-(edk::uint64)n;
        return ret;
    }
    cubeui64 operator-(edk::uint64 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.origin.z=this->origin.z-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        ret.size.length=this->size.length-(edk::uint64)n;
        return ret;
    }
    void operator-=(cubeui64 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;
        this->origin.y-=(edk::uint64)vec.origin.y;
        this->origin.z-=(edk::uint64)vec.origin.z;
        this->size.width-=(edk::uint64)vec.size.width;
        this->size.height-=(edk::uint64)vec.size.height;
        this->size.length-=(edk::uint64)vec.size.length;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->origin.z-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
        this->size.length-=(edk::uint64)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->origin.z-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
        this->size.length-=(edk::uint64)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->origin.z-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
        this->size.length-=(edk::uint64)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->origin.z-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
        this->size.length-=(edk::uint64)n;
    }
    cubeui64 operator*(cubeui64 cube){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)cube.origin.x;
        ret.origin.y=this->origin.y*(edk::uint64)cube.origin.y;
        ret.origin.z=this->origin.z*(edk::uint64)cube.origin.z;
        ret.size.width=this->size.width*(edk::uint64)cube.size.width;
        ret.size.height=this->size.height*(edk::uint64)cube.size.height;
        ret.size.length=this->size.length*(edk::uint64)cube.size.length;
        return ret;
    }
    cubeui64 operator*(edk::uint8 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.origin.z=this->origin.z*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        ret.size.length=this->size.length*(edk::uint64)n;
        return ret;
    }
    cubeui64 operator*(edk::uint32 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.origin.z=this->origin.z*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        ret.size.length=this->size.length*(edk::uint64)n;
        return ret;
    }
    cubeui64 operator*(edk::uint16 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.origin.z=this->origin.z*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        ret.size.length=this->size.length*(edk::uint64)n;
        return ret;
    }
    cubeui64 operator*(edk::uint64 n){
        //
        cubeui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.origin.z=this->origin.z*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        ret.size.length=this->size.length*(edk::uint64)n;
        return ret;
    }
    void operator*=(cubeui64 cube){
        //
        this->origin.x*=(edk::uint64)cube.origin.x;
        this->origin.y*=(edk::uint64)cube.origin.y;
        this->origin.z*=(edk::uint64)cube.origin.z;
        this->size.width*=(edk::uint64)cube.size.width;
        this->size.height*=(edk::uint64)cube.size.height;
        this->size.length*=(edk::uint64)cube.size.length;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->origin.z*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
        this->size.length*=(edk::uint64)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->origin.z*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
        this->size.length*=(edk::uint64)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->origin.z*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
        this->size.length*=(edk::uint64)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->origin.z*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
        this->size.length*=(edk::uint64)n;
    }
    //
    cubeui64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return cubeui64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubeui64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);
    }
    cubeui64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->origin.z=(edk::uint64)z;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        this->size.length=(edk::uint64)length;
        return cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);
    }
    cubeui64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->origin.z=(edk::uint64)z;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        this->size.length=(edk::uint64)length;
        return cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);
    }
    cubeui64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->origin.z=(edk::uint64)z;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        this->size.length=(edk::uint64)length;
        return cubeui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->origin.z,(edk::uint64)this->size.width,(edk::uint64)this->size.height,(edk::uint64)this->size.length);
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

    //operators
    cubef32 operator=(cubef32 cube){
        //
        this->origin.x=(edk::float32)cube.origin.x;
        this->origin.y=(edk::float32)cube.origin.y;
        this->origin.z=(edk::float32)cube.origin.z;
        this->size.width=(edk::float32)cube.size.width;
        this->size.height=(edk::float32)cube.size.height;
        this->size.length=(edk::float32)cube.size.length;
        return *this;
    }
    cubef32 operator=(edk::float32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    cubef32 operator=(edk::float64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    cubef32 operator=(edk::int8 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    cubef32 operator=(edk::int32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    cubef32 operator=(edk::int16 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    cubef32 operator=(edk::int64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    cubef32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    cubef32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    cubef32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }
    cubef32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->origin.z=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        this->size.length=(edk::float32)n;
        return *this;
    }

    bool operator==(cubef32 cube){
        //
        return (this->origin.x==(edk::float32)cube.origin.x
                &&this->origin.y==(edk::float32)cube.origin.y
                &&this->origin.z==(edk::float32)cube.origin.z
                &&this->size.width==(edk::float32)cube.size.width
                &&this->size.height==(edk::float32)cube.size.height
                &&this->size.length==(edk::float32)cube.size.length
                );
    }
    bool operator!=(cubef32 cube){
        //
        return (this->origin.x!=(edk::float32)cube.origin.x
                ||this->origin.y!=(edk::float32)cube.origin.y
                ||this->origin.z!=(edk::float32)cube.origin.z
                ||this->size.width!=(edk::float32)cube.size.width
                ||this->size.height!=(edk::float32)cube.size.height
                ||this->size.length!=(edk::float32)cube.size.length
                );
    }
    cubef32 operator+(cubef32 cube){
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
    cubef32 operator+(edk::float32 n){
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
    cubef32 operator+(edk::float64 n){
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
    cubef32 operator+(edk::int8 n){
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
    cubef32 operator+(edk::int32 n){
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
    cubef32 operator+(edk::int16 n){
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
    cubef32 operator+(edk::int64 n){
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
    cubef32 operator+(edk::uint8 n){
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
    cubef32 operator+(edk::uint32 n){
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
    cubef32 operator+(edk::uint16 n){
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
    cubef32 operator+(edk::uint64 n){
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
    void operator+=(cubef32 cube){
        //
        this->origin.x+=(edk::float32)cube.origin.x;
        this->origin.y+=(edk::float32)cube.origin.y;
        this->origin.z+=(edk::float32)cube.origin.z;
        this->size.width+=(edk::float32)cube.size.width;
        this->size.height+=(edk::float32)cube.size.height;
        this->size.length+=(edk::float32)cube.size.length;
    }
    void operator+=(edk::float32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    void operator+=(edk::float64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->origin.z+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
        this->size.length+=(edk::float32)n;
    }
    cubef32 operator-(cubef32 cube){
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
    cubef32 operator-(edk::float32 n){
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
    cubef32 operator-(edk::float64 n){
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
    cubef32 operator-(edk::int8 n){
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
    cubef32 operator-(edk::int32 n){
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
    cubef32 operator-(edk::int16 n){
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
    cubef32 operator-(edk::int64 n){
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
    cubef32 operator-(edk::uint8 n){
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
    cubef32 operator-(edk::uint32 n){
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
    cubef32 operator-(edk::uint16 n){
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
    cubef32 operator-(edk::uint64 n){
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
    void operator-=(cubef32 vec){
        //
        this->origin.x-=(edk::float32)vec.origin.x;
        this->origin.y-=(edk::float32)vec.origin.y;
        this->origin.z-=(edk::float32)vec.origin.z;
        this->size.width-=(edk::float32)vec.size.width;
        this->size.height-=(edk::float32)vec.size.height;
        this->size.length-=(edk::float32)vec.size.length;
    }
    void operator-=(edk::float32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    void operator-=(edk::float64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->origin.z-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
        this->size.length-=(edk::float32)n;
    }
    cubef32 operator*(cubef32 cube){
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
    cubef32 operator*(edk::float32 n){
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
    cubef32 operator*(edk::float64 n){
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
    cubef32 operator*(edk::int8 n){
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
    cubef32 operator*(edk::int32 n){
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
    cubef32 operator*(edk::int16 n){
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
    cubef32 operator*(edk::int64 n){
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
    cubef32 operator*(edk::uint8 n){
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
    cubef32 operator*(edk::uint32 n){
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
    cubef32 operator*(edk::uint16 n){
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
    cubef32 operator*(edk::uint64 n){
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
    void operator*=(cubef32 cube){
        //
        this->origin.x*=(edk::float32)cube.origin.x;
        this->origin.y*=(edk::float32)cube.origin.y;
        this->origin.z*=(edk::float32)cube.origin.z;
        this->size.width*=(edk::float32)cube.size.width;
        this->size.height*=(edk::float32)cube.size.height;
        this->size.length*=(edk::float32)cube.size.length;
    }
    void operator*=(edk::float32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    void operator*=(edk::float64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->origin.z*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
        this->size.length*=(edk::float32)n;
    }
    //
    cubef32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubef32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubef32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubef32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return cubef32(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubef32 operator()(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    cubef32 operator()(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    cubef32 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    cubef32 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    cubef32 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    cubef32 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    cubef32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    cubef32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    cubef32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
    }
    cubef32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->origin.z,(edk::float32)this->size.width,(edk::float32)this->size.height,(edk::float32)this->size.length);
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

    //operators
    cubef64 operator=(cubef64 cube){
        //
        this->origin.x=(edk::float64)cube.origin.x;
        this->origin.y=(edk::float64)cube.origin.y;
        this->origin.z=(edk::float64)cube.origin.z;
        this->size.width=(edk::float64)cube.size.width;
        this->size.height=(edk::float64)cube.size.height;
        this->size.length=(edk::float64)cube.size.length;
        return *this;
    }
    cubef64 operator=(edk::float32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    cubef64 operator=(edk::float64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    cubef64 operator=(edk::int8 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    cubef64 operator=(edk::int32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    cubef64 operator=(edk::int16 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    cubef64 operator=(edk::int64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    cubef64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    cubef64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    cubef64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }
    cubef64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->origin.z=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        this->size.length=(edk::float64)n;
        return *this;
    }

    bool operator==(cubef64 cube){
        //
        return (this->origin.x==(edk::float64)cube.origin.x
                &&this->origin.y==(edk::float64)cube.origin.y
                &&this->origin.z==(edk::float64)cube.origin.z
                &&this->size.width==(edk::float64)cube.size.width
                &&this->size.height==(edk::float64)cube.size.height
                &&this->size.length==(edk::float64)cube.size.length
                );
    }
    bool operator!=(cubef64 cube){
        //
        return (this->origin.x!=(edk::float64)cube.origin.x
                ||this->origin.y!=(edk::float64)cube.origin.y
                ||this->origin.z!=(edk::float64)cube.origin.z
                ||this->size.width!=(edk::float64)cube.size.width
                ||this->size.height!=(edk::float64)cube.size.height
                ||this->size.length!=(edk::float64)cube.size.length
                );
    }
    cubef64 operator+(cubef64 cube){
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
    cubef64 operator+(edk::float32 n){
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
    cubef64 operator+(edk::float64 n){
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
    cubef64 operator+(edk::int8 n){
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
    cubef64 operator+(edk::int32 n){
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
    cubef64 operator+(edk::int16 n){
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
    cubef64 operator+(edk::int64 n){
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
    cubef64 operator+(edk::uint8 n){
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
    cubef64 operator+(edk::uint32 n){
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
    cubef64 operator+(edk::uint16 n){
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
    cubef64 operator+(edk::uint64 n){
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
    void operator+=(cubef64 cube){
        //
        this->origin.x+=(edk::float64)cube.origin.x;
        this->origin.y+=(edk::float64)cube.origin.y;
        this->origin.z+=(edk::float64)cube.origin.z;
        this->size.width+=(edk::float64)cube.size.width;
        this->size.height+=(edk::float64)cube.size.height;
        this->size.length+=(edk::float64)cube.size.length;
    }
    void operator+=(edk::float32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    void operator+=(edk::float64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->origin.z+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
        this->size.length+=(edk::float64)n;
    }
    cubef64 operator-(cubef64 cube){
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
    cubef64 operator-(edk::float32 n){
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
    cubef64 operator-(edk::float64 n){
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
    cubef64 operator-(edk::int8 n){
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
    cubef64 operator-(edk::int32 n){
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
    cubef64 operator-(edk::int16 n){
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
    cubef64 operator-(edk::int64 n){
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
    cubef64 operator-(edk::uint8 n){
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
    cubef64 operator-(edk::uint32 n){
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
    cubef64 operator-(edk::uint16 n){
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
    cubef64 operator-(edk::uint64 n){
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
    void operator-=(cubef64 vec){
        //
        this->origin.x-=(edk::float64)vec.origin.x;
        this->origin.y-=(edk::float64)vec.origin.y;
        this->origin.z-=(edk::float64)vec.origin.z;
        this->size.width-=(edk::float64)vec.size.width;
        this->size.height-=(edk::float64)vec.size.height;
        this->size.length-=(edk::float64)vec.size.length;
    }
    void operator-=(edk::float32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    void operator-=(edk::float64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->origin.z-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
        this->size.length-=(edk::float64)n;
    }
    cubef64 operator*(cubef64 cube){
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
    cubef64 operator*(edk::float32 n){
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
    cubef64 operator*(edk::float64 n){
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
    cubef64 operator*(edk::int8 n){
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
    cubef64 operator*(edk::int32 n){
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
    cubef64 operator*(edk::int16 n){
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
    cubef64 operator*(edk::int64 n){
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
    cubef64 operator*(edk::uint8 n){
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
    cubef64 operator*(edk::uint32 n){
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
    cubef64 operator*(edk::uint16 n){
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
    cubef64 operator*(edk::uint64 n){
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
    void operator*=(cubef64 cube){
        //
        this->origin.x*=(edk::float64)cube.origin.x;
        this->origin.y*=(edk::float64)cube.origin.y;
        this->origin.z*=(edk::float64)cube.origin.z;
        this->size.width*=(edk::float64)cube.size.width;
        this->size.height*=(edk::float64)cube.size.height;
        this->size.length*=(edk::float64)cube.size.length;
    }
    void operator*=(edk::float32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    void operator*=(edk::float64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->origin.z*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
        this->size.length*=(edk::float64)n;
    }
    //
    cubef64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->origin.z;
        ++this->size.width;
        ++this->size.height;
        ++this->size.length;
        return cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubef64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->origin.z++;
        this->size.width++;
        this->size.height++;
        this->size.length++;
        return cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubef64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->origin.z;
        --this->size.width;
        --this->size.height;
        --this->size.length;
        return cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubef64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->origin.z--;
        this->size.width--;
        this->size.height--;
        this->size.length--;
        return cubef64(this->origin.x,this->origin.y,this->origin.z,this->size.width,this->size.height,this->size.length);
    }
    cubef64 operator()(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    cubef64 operator()(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    cubef64 operator()(edk::int8 x,edk::int8 y,edk::int8 z,edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    cubef64 operator()(edk::int32 x,edk::int32 y,edk::int32 z,edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    cubef64 operator()(edk::int16 x,edk::int16 y,edk::int16 z,edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    cubef64 operator()(edk::int64 x,edk::int64 y,edk::int64 z,edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    cubef64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 z,edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    cubef64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 z,edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    cubef64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 z,edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
    cubef64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 z,edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->origin.z=z;
        this->size.width=width;
        this->size.height=height;
        this->size.length=length;
        return cubef64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->origin.z,(edk::float64)this->size.width,(edk::float64)this->size.height,(edk::float64)this->size.length);
    }
};

}//end namespace






#endif // TYPECUBE_H