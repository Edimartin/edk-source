#ifndef EDK_TYPERECT_H
#define EDK_TYPERECT_H

/*
Library C++ typeRect - Rect types used in Edk Game Engine
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
#warning "Inside TypeRect"
#endif

#pragma once
#include "TypeVars.h"
#include "TypeVec2.h"
#include "TypeSize2.h"

#ifdef printMessages
#warning "    Compiling TypeRect"
#endif

namespace edk{
//
class recti8{
public:
    //position
    edk::vec2i8 origin;
    //size
    edk::size2i8 size;
    //Construtor
    recti8(){
        //
        this->origin.x=(edk::int8)0;
        this->origin.y=(edk::int8)0;
        this->size.width=(edk::int8)0;
        this->size.height=(edk::int8)0;
    }
    recti8(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
    }
    recti8(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
    }
    recti8(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
    }
    recti8(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
    }
    recti8(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
    }
    recti8(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
    }
    recti8(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
    }
    recti8(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
    }
    //operators
    recti8 operator=(recti8 rect){
        //
        this->origin.x=(edk::int8)rect.origin.x;
        this->origin.y=(edk::int8)rect.origin.y;
        this->size.width=(edk::int8)rect.size.width;
        this->size.height=(edk::int8)rect.size.height;
        return *this;
    }
    recti8 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    recti8 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    recti8 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    recti8 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    recti8 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    recti8 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    recti8 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }
    recti8 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int8)n;
        this->origin.y=(edk::int8)n;
        this->size.width=(edk::int8)n;
        this->size.height=(edk::int8)n;
        return *this;
    }

    bool operator==(recti8 rect){
        //
        return (this->origin.x==(edk::int8)rect.origin.x
                &&this->origin.y==(edk::int8)rect.origin.y
                &&this->size.width==(edk::int8)rect.size.width
                &&this->size.height==(edk::int8)rect.size.height
                );
    }
    bool operator!=(recti8 rect){
        //
        return (this->origin.x!=(edk::int8)rect.origin.x
                ||this->origin.y!=(edk::int8)rect.origin.y
                ||this->size.width!=(edk::int8)rect.size.width
                ||this->size.height!=(edk::int8)rect.size.height
                );
    }
    recti8 operator+(recti8 rect){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int8)rect.origin.y;
        ret.size.width=this->size.width+(edk::int8)rect.size.width;
        ret.size.height=this->size.height+(edk::int8)rect.size.height;
        return ret;
    }
    recti8 operator+(edk::int8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    recti8 operator+(edk::int32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    recti8 operator+(edk::int16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    recti8 operator+(edk::int64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    recti8 operator+(edk::uint8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    recti8 operator+(edk::uint32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    recti8 operator+(edk::uint16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    recti8 operator+(edk::uint64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(edk::int8)n;
        ret.origin.y=this->origin.y+(edk::int8)n;
        ret.size.width=this->size.width+(edk::int8)n;
        ret.size.height=this->size.height+(edk::int8)n;
        return ret;
    }
    void operator+=(recti8 rect){
        //
        this->origin.x+=(edk::int8)rect.origin.x;
        this->origin.y+=(edk::int8)rect.origin.y;
        this->size.width+=(edk::int8)rect.size.width;
        this->size.height+=(edk::int8)rect.size.height;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int8)n;
        this->origin.y+=(edk::int8)n;
        this->size.width+=(edk::int8)n;
        this->size.height+=(edk::int8)n;
    }
    recti8 operator-(recti8 rect){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int8)rect.origin.y;
        ret.size.width=this->size.width-(edk::int8)rect.size.width;
        ret.size.height=this->size.height-(edk::int8)rect.size.height;
        return ret;
    }
    recti8 operator-(edk::int8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    recti8 operator-(edk::int32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    recti8 operator-(edk::int16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    recti8 operator-(edk::int64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    recti8 operator-(edk::uint8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    recti8 operator-(edk::uint32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    recti8 operator-(edk::uint16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    recti8 operator-(edk::uint64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(edk::int8)n;
        ret.origin.y=this->origin.y-(edk::int8)n;
        ret.size.width=this->size.width-(edk::int8)n;
        ret.size.height=this->size.height-(edk::int8)n;
        return ret;
    }
    void operator-=(recti8 vec){
        //
        this->origin.x-=(edk::int8)vec.origin.x;
        this->origin.y-=(edk::int8)vec.origin.y;
        this->size.width-=(edk::int8)vec.size.width;
        this->size.height-=(edk::int8)vec.size.height;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int8)n;
        this->origin.y-=(edk::int8)n;
        this->size.width-=(edk::int8)n;
        this->size.height-=(edk::int8)n;
    }
    recti8 operator*(recti8 rect){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int8)rect.origin.y;
        ret.size.width=this->size.width*(edk::int8)rect.size.width;
        ret.size.height=this->size.height*(edk::int8)rect.size.height;
        return ret;
    }
    recti8 operator*(edk::int8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    recti8 operator*(edk::int32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    recti8 operator*(edk::int16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    recti8 operator*(edk::int64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    recti8 operator*(edk::uint8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    recti8 operator*(edk::uint32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    recti8 operator*(edk::uint16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    recti8 operator*(edk::uint64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(edk::int8)n;
        ret.origin.y=this->origin.y*(edk::int8)n;
        ret.size.width=this->size.width*(edk::int8)n;
        ret.size.height=this->size.height*(edk::int8)n;
        return ret;
    }
    void operator*=(recti8 rect){
        //
        this->origin.x*=(edk::int8)rect.origin.x;
        this->origin.y*=(edk::int8)rect.origin.y;
        this->size.width*=(edk::int8)rect.size.width;
        this->size.height*=(edk::int8)rect.size.height;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int8)n;
        this->origin.y*=(edk::int8)n;
        this->size.width*=(edk::int8)n;
        this->size.height*=(edk::int8)n;
    }
    //
    recti8 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return recti8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti8 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return recti8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti8 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return recti8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti8 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return recti8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti8 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    recti8 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    recti8 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    recti8 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    recti8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    recti8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    recti8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
    recti8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int8)x;
        this->origin.y=(edk::int8)y;
        this->size.width=(edk::int8)width;
        this->size.height=(edk::int8)height;
        return recti8((edk::int8)this->origin.x,(edk::int8)this->origin.y,(edk::int8)this->size.width,(edk::int8)this->size.height);
    }
};

class recti16{
public:
    //position
    edk::vec2i16 origin;
    //size
    edk::size2i16 size;
    //Construtor
    recti16(){
        //
        this->origin.x=(edk::int16)0;
        this->origin.y=(edk::int16)0;
        this->size.width=(edk::int16)0;
        this->size.height=(edk::int16)0;
    }
    recti16(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
    }
    recti16(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
    }
    recti16(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
    }
    recti16(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
    }
    recti16(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
    }
    recti16(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
    }
    recti16(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
    }
    recti16(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
    }

    //operators
    recti16 operator=(recti8 rect){
        //
        this->origin.x=(edk::int16)rect.origin.x;
        this->origin.y=(edk::int16)rect.origin.y;
        this->size.width=(edk::int16)rect.size.width;
        this->size.height=(edk::int16)rect.size.height;
        return *this;
    }
    recti16 operator=(recti16 rect){
        //
        this->origin.x=(edk::int16)rect.origin.x;
        this->origin.y=(edk::int16)rect.origin.y;
        this->size.width=(edk::int16)rect.size.width;
        this->size.height=(edk::int16)rect.size.height;
        return *this;
    }
    recti16 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    recti16 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    recti16 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    recti16 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    recti16 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    recti16 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    recti16 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }
    recti16 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int16)n;
        this->origin.y=(edk::int16)n;
        this->size.width=(edk::int16)n;
        this->size.height=(edk::int16)n;
        return *this;
    }

    bool operator==(recti8 rect){
        //
        return (this->origin.x==(edk::int16)rect.origin.x
                &&this->origin.y==(edk::int16)rect.origin.y
                &&this->size.width==(edk::int16)rect.size.width
                &&this->size.height==(edk::int16)rect.size.height
                );
    }
    bool operator==(recti16 rect){
        //
        return (this->origin.x==(edk::int16)rect.origin.x
                &&this->origin.y==(edk::int16)rect.origin.y
                &&this->size.width==(edk::int16)rect.size.width
                &&this->size.height==(edk::int16)rect.size.height
                );
    }
    bool operator!=(recti8 rect){
        //
        return (this->origin.x!=(edk::int16)rect.origin.x
                ||this->origin.y!=(edk::int16)rect.origin.y
                ||this->size.width!=(edk::int16)rect.size.width
                ||this->size.height!=(edk::int16)rect.size.height
                );
    }
    bool operator!=(recti16 rect){
        //
        return (this->origin.x!=(edk::int16)rect.origin.x
                ||this->origin.y!=(edk::int16)rect.origin.y
                ||this->size.width!=(edk::int16)rect.size.width
                ||this->size.height!=(edk::int16)rect.size.height
                );
    }
    recti16 operator+(recti8 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int16)rect.origin.y;
        ret.size.width=this->size.width+(edk::int16)rect.size.width;
        ret.size.height=this->size.height+(edk::int16)rect.size.height;
        return ret;
    }
    recti16 operator+(recti16 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int16)rect.origin.y;
        ret.size.width=this->size.width+(edk::int16)rect.size.width;
        ret.size.height=this->size.height+(edk::int16)rect.size.height;
        return ret;
    }
    recti16 operator+(edk::int8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    recti16 operator+(edk::int32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    recti16 operator+(edk::int16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    recti16 operator+(edk::int64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    recti16 operator+(edk::uint8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    recti16 operator+(edk::uint32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    recti16 operator+(edk::uint16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    recti16 operator+(edk::uint64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(edk::int16)n;
        ret.origin.y=this->origin.y+(edk::int16)n;
        ret.size.width=this->size.width+(edk::int16)n;
        ret.size.height=this->size.height+(edk::int16)n;
        return ret;
    }
    void operator+=(recti8 rect){
        //
        this->origin.x+=(edk::int16)rect.origin.x;
        this->origin.y+=(edk::int16)rect.origin.y;
        this->size.width+=(edk::int16)rect.size.width;
        this->size.height+=(edk::int16)rect.size.height;
    }
    void operator+=(recti16 rect){
        //
        this->origin.x+=(edk::int16)rect.origin.x;
        this->origin.y+=(edk::int16)rect.origin.y;
        this->size.width+=(edk::int16)rect.size.width;
        this->size.height+=(edk::int16)rect.size.height;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int16)n;
        this->origin.y+=(edk::int16)n;
        this->size.width+=(edk::int16)n;
        this->size.height+=(edk::int16)n;
    }
    recti16 operator-(recti8 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int16)rect.origin.y;
        ret.size.width=this->size.width-(edk::int16)rect.size.width;
        ret.size.height=this->size.height-(edk::int16)rect.size.height;
        return ret;
    }
    recti16 operator-(recti16 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int16)rect.origin.y;
        ret.size.width=this->size.width-(edk::int16)rect.size.width;
        ret.size.height=this->size.height-(edk::int16)rect.size.height;
        return ret;
    }
    recti16 operator-(edk::int8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    recti16 operator-(edk::int32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    recti16 operator-(edk::int16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    recti16 operator-(edk::int64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    recti16 operator-(edk::uint8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    recti16 operator-(edk::uint32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    recti16 operator-(edk::uint16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    recti16 operator-(edk::uint64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(edk::int16)n;
        ret.origin.y=this->origin.y-(edk::int16)n;
        ret.size.width=this->size.width-(edk::int16)n;
        ret.size.height=this->size.height-(edk::int16)n;
        return ret;
    }
    void operator-=(recti8 vec){
        //
        this->origin.x-=(edk::int16)vec.origin.x;
        this->origin.y-=(edk::int16)vec.origin.y;
        this->size.width-=(edk::int16)vec.size.width;
        this->size.height-=(edk::int16)vec.size.height;
    }
    void operator-=(recti16 vec){
        //
        this->origin.x-=(edk::int16)vec.origin.x;
        this->origin.y-=(edk::int16)vec.origin.y;
        this->size.width-=(edk::int16)vec.size.width;
        this->size.height-=(edk::int16)vec.size.height;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int16)n;
        this->origin.y-=(edk::int16)n;
        this->size.width-=(edk::int16)n;
        this->size.height-=(edk::int16)n;
    }
    recti16 operator*(recti8 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int16)rect.origin.y;
        ret.size.width=this->size.width*(edk::int16)rect.size.width;
        ret.size.height=this->size.height*(edk::int16)rect.size.height;
        return ret;
    }
    recti16 operator*(recti16 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int16)rect.origin.y;
        ret.size.width=this->size.width*(edk::int16)rect.size.width;
        ret.size.height=this->size.height*(edk::int16)rect.size.height;
        return ret;
    }
    recti16 operator*(edk::int8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    recti16 operator*(edk::int32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    recti16 operator*(edk::int16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    recti16 operator*(edk::int64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    recti16 operator*(edk::uint8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    recti16 operator*(edk::uint32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    recti16 operator*(edk::uint16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    recti16 operator*(edk::uint64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(edk::int16)n;
        ret.origin.y=this->origin.y*(edk::int16)n;
        ret.size.width=this->size.width*(edk::int16)n;
        ret.size.height=this->size.height*(edk::int16)n;
        return ret;
    }
    void operator*=(recti8 rect){
        //
        this->origin.x*=(edk::int16)rect.origin.x;
        this->origin.y*=(edk::int16)rect.origin.y;
        this->size.width*=(edk::int16)rect.size.width;
        this->size.height*=(edk::int16)rect.size.height;
    }
    void operator*=(recti16 rect){
        //
        this->origin.x*=(edk::int16)rect.origin.x;
        this->origin.y*=(edk::int16)rect.origin.y;
        this->size.width*=(edk::int16)rect.size.width;
        this->size.height*=(edk::int16)rect.size.height;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int16)n;
        this->origin.y*=(edk::int16)n;
        this->size.width*=(edk::int16)n;
        this->size.height*=(edk::int16)n;
    }
    //
    recti16 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return recti16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti16 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return recti16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti16 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return recti16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti16 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return recti16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti16 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    recti16 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    recti16 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    recti16 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    recti16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    recti16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    recti16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
    recti16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int16)x;
        this->origin.y=(edk::int16)y;
        this->size.width=(edk::int16)width;
        this->size.height=(edk::int16)height;
        return recti16((edk::int16)this->origin.x,(edk::int16)this->origin.y,(edk::int16)this->size.width,(edk::int16)this->size.height);
    }
};

class recti32{
public:
    //position
    edk::vec2i32 origin;
    //size
    edk::size2i32 size;
    //Construtor
    recti32(){
        //
        this->origin.x=(edk::int32)0;
        this->origin.y=(edk::int32)0;
        this->size.width=(edk::int32)0;
        this->size.height=(edk::int32)0;
    }
    recti32(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
    }
    recti32(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
    }
    recti32(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
    }
    recti32(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
    }
    recti32(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
    }
    recti32(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
    }
    recti32(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
    }
    recti32(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
    }

    //operators
    recti32 operator=(recti8 rect){
        //
        this->origin.x=(edk::int32)rect.origin.x;
        this->origin.y=(edk::int32)rect.origin.y;
        this->size.width=(edk::int32)rect.size.width;
        this->size.height=(edk::int32)rect.size.height;
        return *this;
    }
    recti32 operator=(recti16 rect){
        //
        this->origin.x=(edk::int32)rect.origin.x;
        this->origin.y=(edk::int32)rect.origin.y;
        this->size.width=(edk::int32)rect.size.width;
        this->size.height=(edk::int32)rect.size.height;
        return *this;
    }
    recti32 operator=(recti32 rect){
        //
        this->origin.x=(edk::int32)rect.origin.x;
        this->origin.y=(edk::int32)rect.origin.y;
        this->size.width=(edk::int32)rect.size.width;
        this->size.height=(edk::int32)rect.size.height;
        return *this;
    }
    recti32 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    recti32 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    recti32 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    recti32 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    recti32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    recti32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    recti32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }
    recti32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int32)n;
        this->origin.y=(edk::int32)n;
        this->size.width=(edk::int32)n;
        this->size.height=(edk::int32)n;
        return *this;
    }

    bool operator==(recti8 rect){
        //
        return (this->origin.x==(edk::int32)rect.origin.x
                &&this->origin.y==(edk::int32)rect.origin.y
                &&this->size.width==(edk::int32)rect.size.width
                &&this->size.height==(edk::int32)rect.size.height
                );
    }
    bool operator==(recti16 rect){
        //
        return (this->origin.x==(edk::int32)rect.origin.x
                &&this->origin.y==(edk::int32)rect.origin.y
                &&this->size.width==(edk::int32)rect.size.width
                &&this->size.height==(edk::int32)rect.size.height
                );
    }
    bool operator==(recti32 rect){
        //
        return (this->origin.x==(edk::int32)rect.origin.x
                &&this->origin.y==(edk::int32)rect.origin.y
                &&this->size.width==(edk::int32)rect.size.width
                &&this->size.height==(edk::int32)rect.size.height
                );
    }
    bool operator!=(recti8 rect){
        //
        return (this->origin.x!=(edk::int32)rect.origin.x
                ||this->origin.y!=(edk::int32)rect.origin.y
                ||this->size.width!=(edk::int32)rect.size.width
                ||this->size.height!=(edk::int32)rect.size.height
                );
    }
    bool operator!=(recti16 rect){
        //
        return (this->origin.x!=(edk::int32)rect.origin.x
                ||this->origin.y!=(edk::int32)rect.origin.y
                ||this->size.width!=(edk::int32)rect.size.width
                ||this->size.height!=(edk::int32)rect.size.height
                );
    }
    bool operator!=(recti32 rect){
        //
        return (this->origin.x!=(edk::int32)rect.origin.x
                ||this->origin.y!=(edk::int32)rect.origin.y
                ||this->size.width!=(edk::int32)rect.size.width
                ||this->size.height!=(edk::int32)rect.size.height
                );
    }
    recti32 operator+(recti8 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int32)rect.origin.y;
        ret.size.width=this->size.width+(edk::int32)rect.size.width;
        ret.size.height=this->size.height+(edk::int32)rect.size.height;
        return ret;
    }
    recti32 operator+(recti16 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int32)rect.origin.y;
        ret.size.width=this->size.width+(edk::int32)rect.size.width;
        ret.size.height=this->size.height+(edk::int32)rect.size.height;
        return ret;
    }
    recti32 operator+(recti32 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int32)rect.origin.y;
        ret.size.width=this->size.width+(edk::int32)rect.size.width;
        ret.size.height=this->size.height+(edk::int32)rect.size.height;
        return ret;
    }
    recti32 operator+(edk::int8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    recti32 operator+(edk::int32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    recti32 operator+(edk::int16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    recti32 operator+(edk::int64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    recti32 operator+(edk::uint8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    recti32 operator+(edk::uint32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    recti32 operator+(edk::uint16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    recti32 operator+(edk::uint64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(edk::int32)n;
        ret.origin.y=this->origin.y+(edk::int32)n;
        ret.size.width=this->size.width+(edk::int32)n;
        ret.size.height=this->size.height+(edk::int32)n;
        return ret;
    }
    void operator+=(recti8 rect){
        //
        this->origin.x+=(edk::int32)rect.origin.x;
        this->origin.y+=(edk::int32)rect.origin.y;
        this->size.width+=(edk::int32)rect.size.width;
        this->size.height+=(edk::int32)rect.size.height;
    }
    void operator+=(recti16 rect){
        //
        this->origin.x+=(edk::int32)rect.origin.x;
        this->origin.y+=(edk::int32)rect.origin.y;
        this->size.width+=(edk::int32)rect.size.width;
        this->size.height+=(edk::int32)rect.size.height;
    }
    void operator+=(recti32 rect){
        //
        this->origin.x+=(edk::int32)rect.origin.x;
        this->origin.y+=(edk::int32)rect.origin.y;
        this->size.width+=(edk::int32)rect.size.width;
        this->size.height+=(edk::int32)rect.size.height;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int32)n;
        this->origin.y+=(edk::int32)n;
        this->size.width+=(edk::int32)n;
        this->size.height+=(edk::int32)n;
    }
    recti32 operator-(recti8 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int32)rect.origin.y;
        ret.size.width=this->size.width-(edk::int32)rect.size.width;
        ret.size.height=this->size.height-(edk::int32)rect.size.height;
        return ret;
    }
    recti32 operator-(recti16 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int32)rect.origin.y;
        ret.size.width=this->size.width-(edk::int32)rect.size.width;
        ret.size.height=this->size.height-(edk::int32)rect.size.height;
        return ret;
    }
    recti32 operator-(recti32 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int32)rect.origin.y;
        ret.size.width=this->size.width-(edk::int32)rect.size.width;
        ret.size.height=this->size.height-(edk::int32)rect.size.height;
        return ret;
    }
    recti32 operator-(edk::int8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    recti32 operator-(edk::int32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    recti32 operator-(edk::int16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    recti32 operator-(edk::int64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    recti32 operator-(edk::uint8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    recti32 operator-(edk::uint32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    recti32 operator-(edk::uint16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    recti32 operator-(edk::uint64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(edk::int32)n;
        ret.origin.y=this->origin.y-(edk::int32)n;
        ret.size.width=this->size.width-(edk::int32)n;
        ret.size.height=this->size.height-(edk::int32)n;
        return ret;
    }
    void operator-=(recti8 vec){
        //
        this->origin.x-=(edk::int32)vec.origin.x;
        this->origin.y-=(edk::int32)vec.origin.y;
        this->size.width-=(edk::int32)vec.size.width;
        this->size.height-=(edk::int32)vec.size.height;
    }
    void operator-=(recti16 vec){
        //
        this->origin.x-=(edk::int32)vec.origin.x;
        this->origin.y-=(edk::int32)vec.origin.y;
        this->size.width-=(edk::int32)vec.size.width;
        this->size.height-=(edk::int32)vec.size.height;
    }
    void operator-=(recti32 vec){
        //
        this->origin.x-=(edk::int32)vec.origin.x;
        this->origin.y-=(edk::int32)vec.origin.y;
        this->size.width-=(edk::int32)vec.size.width;
        this->size.height-=(edk::int32)vec.size.height;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int32)n;
        this->origin.y-=(edk::int32)n;
        this->size.width-=(edk::int32)n;
        this->size.height-=(edk::int32)n;
    }
    recti32 operator*(recti8 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int32)rect.origin.y;
        ret.size.width=this->size.width*(edk::int32)rect.size.width;
        ret.size.height=this->size.height*(edk::int32)rect.size.height;
        return ret;
    }
    recti32 operator*(recti16 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int32)rect.origin.y;
        ret.size.width=this->size.width*(edk::int32)rect.size.width;
        ret.size.height=this->size.height*(edk::int32)rect.size.height;
        return ret;
    }
    recti32 operator*(recti32 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int32)rect.origin.y;
        ret.size.width=this->size.width*(edk::int32)rect.size.width;
        ret.size.height=this->size.height*(edk::int32)rect.size.height;
        return ret;
    }
    recti32 operator*(edk::int8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    recti32 operator*(edk::int32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    recti32 operator*(edk::int16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    recti32 operator*(edk::int64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    recti32 operator*(edk::uint8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    recti32 operator*(edk::uint32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    recti32 operator*(edk::uint16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    recti32 operator*(edk::uint64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(edk::int32)n;
        ret.origin.y=this->origin.y*(edk::int32)n;
        ret.size.width=this->size.width*(edk::int32)n;
        ret.size.height=this->size.height*(edk::int32)n;
        return ret;
    }
    void operator*=(recti8 rect){
        //
        this->origin.x*=(edk::int32)rect.origin.x;
        this->origin.y*=(edk::int32)rect.origin.y;
        this->size.width*=(edk::int32)rect.size.width;
        this->size.height*=(edk::int32)rect.size.height;
    }
    void operator*=(recti16 rect){
        //
        this->origin.x*=(edk::int32)rect.origin.x;
        this->origin.y*=(edk::int32)rect.origin.y;
        this->size.width*=(edk::int32)rect.size.width;
        this->size.height*=(edk::int32)rect.size.height;
    }
    void operator*=(recti32 rect){
        //
        this->origin.x*=(edk::int32)rect.origin.x;
        this->origin.y*=(edk::int32)rect.origin.y;
        this->size.width*=(edk::int32)rect.size.width;
        this->size.height*=(edk::int32)rect.size.height;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int32)n;
        this->origin.y*=(edk::int32)n;
        this->size.width*=(edk::int32)n;
        this->size.height*=(edk::int32)n;
    }
    //
    recti32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return recti32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return recti32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return recti32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return recti32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti32 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    recti32 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    recti32 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    recti32 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    recti32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    recti32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    recti32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
    recti32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int32)x;
        this->origin.y=(edk::int32)y;
        this->size.width=(edk::int32)width;
        this->size.height=(edk::int32)height;
        return recti32((edk::int32)this->origin.x,(edk::int32)this->origin.y,(edk::int32)this->size.width,(edk::int32)this->size.height);
    }
};

class recti64{
public:
    //position
    edk::vec2i64 origin;
    //size
    edk::size2i64 size;
    //Construtor
    recti64(){
        //
        this->origin.x=(edk::int64)0;
        this->origin.y=(edk::int64)0;
        this->size.width=(edk::int64)0;
        this->size.height=(edk::int64)0;
    }
    recti64(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
    }
    recti64(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
    }
    recti64(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
    }
    recti64(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
    }
    recti64(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
    }
    recti64(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
    }
    recti64(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
    }
    recti64(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
    }

    //operators
    recti64 operator=(recti8 rect){
        //
        this->origin.x=(edk::int64)rect.origin.x;
        this->origin.y=(edk::int64)rect.origin.y;
        this->size.width=(edk::int64)rect.size.width;
        this->size.height=(edk::int64)rect.size.height;
        return *this;
    }
    recti64 operator=(recti16 rect){
        //
        this->origin.x=(edk::int64)rect.origin.x;
        this->origin.y=(edk::int64)rect.origin.y;
        this->size.width=(edk::int64)rect.size.width;
        this->size.height=(edk::int64)rect.size.height;
        return *this;
    }
    recti64 operator=(recti32 rect){
        //
        this->origin.x=(edk::int64)rect.origin.x;
        this->origin.y=(edk::int64)rect.origin.y;
        this->size.width=(edk::int64)rect.size.width;
        this->size.height=(edk::int64)rect.size.height;
        return *this;
    }
    recti64 operator=(recti64 rect){
        //
        this->origin.x=(edk::int64)rect.origin.x;
        this->origin.y=(edk::int64)rect.origin.y;
        this->size.width=(edk::int64)rect.size.width;
        this->size.height=(edk::int64)rect.size.height;
        return *this;
    }
    recti64 operator=(edk::int8 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    recti64 operator=(edk::int32 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    recti64 operator=(edk::int16 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    recti64 operator=(edk::int64 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    recti64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    recti64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    recti64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }
    recti64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::int64)n;
        this->origin.y=(edk::int64)n;
        this->size.width=(edk::int64)n;
        this->size.height=(edk::int64)n;
        return *this;
    }

    bool operator==(recti8 rect){
        //
        return (this->origin.x==(edk::int64)rect.origin.x
                &&this->origin.y==(edk::int64)rect.origin.y
                &&this->size.width==(edk::int64)rect.size.width
                &&this->size.height==(edk::int64)rect.size.height
                );
    }
    bool operator==(recti16 rect){
        //
        return (this->origin.x==(edk::int64)rect.origin.x
                &&this->origin.y==(edk::int64)rect.origin.y
                &&this->size.width==(edk::int64)rect.size.width
                &&this->size.height==(edk::int64)rect.size.height
                );
    }
    bool operator==(recti32 rect){
        //
        return (this->origin.x==(edk::int64)rect.origin.x
                &&this->origin.y==(edk::int64)rect.origin.y
                &&this->size.width==(edk::int64)rect.size.width
                &&this->size.height==(edk::int64)rect.size.height
                );
    }
    bool operator==(recti64 rect){
        //
        return (this->origin.x==(edk::int64)rect.origin.x
                &&this->origin.y==(edk::int64)rect.origin.y
                &&this->size.width==(edk::int64)rect.size.width
                &&this->size.height==(edk::int64)rect.size.height
                );
    }
    bool operator!=(recti8 rect){
        //
        return (this->origin.x!=(edk::int64)rect.origin.x
                ||this->origin.y!=(edk::int64)rect.origin.y
                ||this->size.width!=(edk::int64)rect.size.width
                ||this->size.height!=(edk::int64)rect.size.height
                );
    }
    bool operator!=(recti16 rect){
        //
        return (this->origin.x!=(edk::int64)rect.origin.x
                ||this->origin.y!=(edk::int64)rect.origin.y
                ||this->size.width!=(edk::int64)rect.size.width
                ||this->size.height!=(edk::int64)rect.size.height
                );
    }
    bool operator!=(recti32 rect){
        //
        return (this->origin.x!=(edk::int64)rect.origin.x
                ||this->origin.y!=(edk::int64)rect.origin.y
                ||this->size.width!=(edk::int64)rect.size.width
                ||this->size.height!=(edk::int64)rect.size.height
                );
    }
    bool operator!=(recti64 rect){
        //
        return (this->origin.x!=(edk::int64)rect.origin.x
                ||this->origin.y!=(edk::int64)rect.origin.y
                ||this->size.width!=(edk::int64)rect.size.width
                ||this->size.height!=(edk::int64)rect.size.height
                );
    }
    recti64 operator+(recti8 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int64)rect.origin.y;
        ret.size.width=this->size.width+(edk::int64)rect.size.width;
        ret.size.height=this->size.height+(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator+(recti16 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int64)rect.origin.y;
        ret.size.width=this->size.width+(edk::int64)rect.size.width;
        ret.size.height=this->size.height+(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator+(recti32 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int64)rect.origin.y;
        ret.size.width=this->size.width+(edk::int64)rect.size.width;
        ret.size.height=this->size.height+(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator+(recti64 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::int64)rect.origin.y;
        ret.size.width=this->size.width+(edk::int64)rect.size.width;
        ret.size.height=this->size.height+(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator+(edk::int8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    recti64 operator+(edk::int32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    recti64 operator+(edk::int16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    recti64 operator+(edk::int64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    recti64 operator+(edk::uint8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    recti64 operator+(edk::uint32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    recti64 operator+(edk::uint16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    recti64 operator+(edk::uint64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(edk::int64)n;
        ret.origin.y=this->origin.y+(edk::int64)n;
        ret.size.width=this->size.width+(edk::int64)n;
        ret.size.height=this->size.height+(edk::int64)n;
        return ret;
    }
    void operator+=(recti8 rect){
        //
        this->origin.x+=(edk::int64)rect.origin.x;
        this->origin.y+=(edk::int64)rect.origin.y;
        this->size.width+=(edk::int64)rect.size.width;
        this->size.height+=(edk::int64)rect.size.height;
    }
    void operator+=(recti16 rect){
        //
        this->origin.x+=(edk::int64)rect.origin.x;
        this->origin.y+=(edk::int64)rect.origin.y;
        this->size.width+=(edk::int64)rect.size.width;
        this->size.height+=(edk::int64)rect.size.height;
    }
    void operator+=(recti32 rect){
        //
        this->origin.x+=(edk::int64)rect.origin.x;
        this->origin.y+=(edk::int64)rect.origin.y;
        this->size.width+=(edk::int64)rect.size.width;
        this->size.height+=(edk::int64)rect.size.height;
    }
    void operator+=(recti64 rect){
        //
        this->origin.x+=(edk::int64)rect.origin.x;
        this->origin.y+=(edk::int64)rect.origin.y;
        this->size.width+=(edk::int64)rect.size.width;
        this->size.height+=(edk::int64)rect.size.height;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::int64)n;
        this->origin.y+=(edk::int64)n;
        this->size.width+=(edk::int64)n;
        this->size.height+=(edk::int64)n;
    }
    recti64 operator-(recti8 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int64)rect.origin.y;
        ret.size.width=this->size.width-(edk::int64)rect.size.width;
        ret.size.height=this->size.height-(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator-(recti16 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int64)rect.origin.y;
        ret.size.width=this->size.width-(edk::int64)rect.size.width;
        ret.size.height=this->size.height-(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator-(recti32 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int64)rect.origin.y;
        ret.size.width=this->size.width-(edk::int64)rect.size.width;
        ret.size.height=this->size.height-(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator-(recti64 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::int64)rect.origin.y;
        ret.size.width=this->size.width-(edk::int64)rect.size.width;
        ret.size.height=this->size.height-(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator-(edk::int8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    recti64 operator-(edk::int32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    recti64 operator-(edk::int16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    recti64 operator-(edk::int64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    recti64 operator-(edk::uint8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    recti64 operator-(edk::uint32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    recti64 operator-(edk::uint16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    recti64 operator-(edk::uint64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(edk::int64)n;
        ret.origin.y=this->origin.y-(edk::int64)n;
        ret.size.width=this->size.width-(edk::int64)n;
        ret.size.height=this->size.height-(edk::int64)n;
        return ret;
    }
    void operator-=(recti8 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;
        this->origin.y-=(edk::int64)vec.origin.y;
        this->size.width-=(edk::int64)vec.size.width;
        this->size.height-=(edk::int64)vec.size.height;
    }
    void operator-=(recti16 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;
        this->origin.y-=(edk::int64)vec.origin.y;
        this->size.width-=(edk::int64)vec.size.width;
        this->size.height-=(edk::int64)vec.size.height;
    }
    void operator-=(recti32 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;
        this->origin.y-=(edk::int64)vec.origin.y;
        this->size.width-=(edk::int64)vec.size.width;
        this->size.height-=(edk::int64)vec.size.height;
    }
    void operator-=(recti64 vec){
        //
        this->origin.x-=(edk::int64)vec.origin.x;
        this->origin.y-=(edk::int64)vec.origin.y;
        this->size.width-=(edk::int64)vec.size.width;
        this->size.height-=(edk::int64)vec.size.height;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::int64)n;
        this->origin.y-=(edk::int64)n;
        this->size.width-=(edk::int64)n;
        this->size.height-=(edk::int64)n;
    }
    recti64 operator*(recti8 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int64)rect.origin.y;
        ret.size.width=this->size.width*(edk::int64)rect.size.width;
        ret.size.height=this->size.height*(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator*(recti16 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int64)rect.origin.y;
        ret.size.width=this->size.width*(edk::int64)rect.size.width;
        ret.size.height=this->size.height*(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator*(recti32 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int64)rect.origin.y;
        ret.size.width=this->size.width*(edk::int64)rect.size.width;
        ret.size.height=this->size.height*(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator*(recti64 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::int64)rect.origin.y;
        ret.size.width=this->size.width*(edk::int64)rect.size.width;
        ret.size.height=this->size.height*(edk::int64)rect.size.height;
        return ret;
    }
    recti64 operator*(edk::int8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    recti64 operator*(edk::int32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    recti64 operator*(edk::int16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    recti64 operator*(edk::int64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    recti64 operator*(edk::uint8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    recti64 operator*(edk::uint32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    recti64 operator*(edk::uint16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    recti64 operator*(edk::uint64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(edk::int64)n;
        ret.origin.y=this->origin.y*(edk::int64)n;
        ret.size.width=this->size.width*(edk::int64)n;
        ret.size.height=this->size.height*(edk::int64)n;
        return ret;
    }
    void operator*=(recti8 rect){
        //
        this->origin.x*=(edk::int64)rect.origin.x;
        this->origin.y*=(edk::int64)rect.origin.y;
        this->size.width*=(edk::int64)rect.size.width;
        this->size.height*=(edk::int64)rect.size.height;
    }
    void operator*=(recti16 rect){
        //
        this->origin.x*=(edk::int64)rect.origin.x;
        this->origin.y*=(edk::int64)rect.origin.y;
        this->size.width*=(edk::int64)rect.size.width;
        this->size.height*=(edk::int64)rect.size.height;
    }
    void operator*=(recti32 rect){
        //
        this->origin.x*=(edk::int64)rect.origin.x;
        this->origin.y*=(edk::int64)rect.origin.y;
        this->size.width*=(edk::int64)rect.size.width;
        this->size.height*=(edk::int64)rect.size.height;
    }
    void operator*=(recti64 rect){
        //
        this->origin.x*=(edk::int64)rect.origin.x;
        this->origin.y*=(edk::int64)rect.origin.y;
        this->size.width*=(edk::int64)rect.size.width;
        this->size.height*=(edk::int64)rect.size.height;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
    void operator*=(edk::int16 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
    void operator*=(edk::int64 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::int64)n;
        this->origin.y*=(edk::int64)n;
        this->size.width*=(edk::int64)n;
        this->size.height*=(edk::int64)n;
    }
    //
    recti64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return recti64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return recti64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return recti64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return recti64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti64 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    recti64 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    recti64 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    recti64 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    recti64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    recti64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    recti64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
    recti64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::int64)x;
        this->origin.y=(edk::int64)y;
        this->size.width=(edk::int64)width;
        this->size.height=(edk::int64)height;
        return recti64((edk::int64)this->origin.x,(edk::int64)this->origin.y,(edk::int64)this->size.width,(edk::int64)this->size.height);
    }
};

class rectui8{
public:
    //position
    edk::vec2ui8 origin;
    //size
    edk::size2ui8 size;
    //Construtor
    rectui8(){
        //
        this->origin.x=(edk::uint8)0;
        this->origin.y=(edk::uint8)0;
        this->size.width=(edk::uint8)0;
        this->size.height=(edk::uint8)0;
    }
    rectui8(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
    }
    rectui8(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
    }
    rectui8(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
    }
    rectui8(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
    }

    //operators
    rectui8 operator=(rectui8 rect){
        //
        this->origin.x=(edk::uint8)rect.origin.x;
        this->origin.y=(edk::uint8)rect.origin.y;
        this->size.width=(edk::uint8)rect.size.width;
        this->size.height=(edk::uint8)rect.size.height;
        return *this;
    }
    rectui8 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        return *this;
    }
    rectui8 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        return *this;
    }
    rectui8 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        return *this;
    }
    rectui8 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint8)n;
        this->origin.y=(edk::uint8)n;
        this->size.width=(edk::uint8)n;
        this->size.height=(edk::uint8)n;
        return *this;
    }

    bool operator==(rectui8 rect){
        //
        return (this->origin.x==(edk::uint8)rect.origin.x
                &&this->origin.y==(edk::uint8)rect.origin.y
                &&this->size.width==(edk::uint8)rect.size.width
                &&this->size.height==(edk::uint8)rect.size.height
                );
    }
    bool operator!=(rectui8 rect){
        //
        return (this->origin.x!=(edk::uint8)rect.origin.x
                ||this->origin.y!=(edk::uint8)rect.origin.y
                ||this->size.width!=(edk::uint8)rect.size.width
                ||this->size.height!=(edk::uint8)rect.size.height
                );
    }
    rectui8 operator+(rectui8 rect){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint8)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint8)rect.size.width;
        ret.size.height=this->size.height+(edk::uint8)rect.size.height;
        return ret;
    }
    rectui8 operator+(edk::uint8 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        return ret;
    }
    rectui8 operator+(edk::uint32 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        return ret;
    }
    rectui8 operator+(edk::uint16 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        return ret;
    }
    rectui8 operator+(edk::uint64 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x+(edk::uint8)n;
        ret.origin.y=this->origin.y+(edk::uint8)n;
        ret.size.width=this->size.width+(edk::uint8)n;
        ret.size.height=this->size.height+(edk::uint8)n;
        return ret;
    }
    void operator+=(rectui8 rect){
        //
        this->origin.x+=(edk::uint8)rect.origin.x;
        this->origin.y+=(edk::uint8)rect.origin.y;
        this->size.width+=(edk::uint8)rect.size.width;
        this->size.height+=(edk::uint8)rect.size.height;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint8)n;
        this->origin.y+=(edk::uint8)n;
        this->size.width+=(edk::uint8)n;
        this->size.height+=(edk::uint8)n;
    }
    rectui8 operator-(rectui8 rect){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint8)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint8)rect.size.width;
        ret.size.height=this->size.height-(edk::uint8)rect.size.height;
        return ret;
    }
    rectui8 operator-(edk::uint8 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        return ret;
    }
    rectui8 operator-(edk::uint32 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        return ret;
    }
    rectui8 operator-(edk::uint16 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        return ret;
    }
    rectui8 operator-(edk::uint64 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x-(edk::uint8)n;
        ret.origin.y=this->origin.y-(edk::uint8)n;
        ret.size.width=this->size.width-(edk::uint8)n;
        ret.size.height=this->size.height-(edk::uint8)n;
        return ret;
    }
    void operator-=(rectui8 vec){
        //
        this->origin.x-=(edk::uint8)vec.origin.x;
        this->origin.y-=(edk::uint8)vec.origin.y;
        this->size.width-=(edk::uint8)vec.size.width;
        this->size.height-=(edk::uint8)vec.size.height;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint8)n;
        this->origin.y-=(edk::uint8)n;
        this->size.width-=(edk::uint8)n;
        this->size.height-=(edk::uint8)n;
    }
    rectui8 operator*(rectui8 rect){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint8)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint8)rect.size.width;
        ret.size.height=this->size.height*(edk::uint8)rect.size.height;
        return ret;
    }
    rectui8 operator*(edk::uint8 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        return ret;
    }
    rectui8 operator*(edk::uint32 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        return ret;
    }
    rectui8 operator*(edk::uint16 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        return ret;
    }
    rectui8 operator*(edk::uint64 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x*(edk::uint8)n;
        ret.origin.y=this->origin.y*(edk::uint8)n;
        ret.size.width=this->size.width*(edk::uint8)n;
        ret.size.height=this->size.height*(edk::uint8)n;
        return ret;
    }
    void operator*=(rectui8 rect){
        //
        this->origin.x*=(edk::uint8)rect.origin.x;
        this->origin.y*=(edk::uint8)rect.origin.y;
        this->size.width*=(edk::uint8)rect.size.width;
        this->size.height*=(edk::uint8)rect.size.height;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint8)n;
        this->origin.y*=(edk::uint8)n;
        this->size.width*=(edk::uint8)n;
        this->size.height*=(edk::uint8)n;
    }
    //
    rectui8 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return rectui8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui8 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return rectui8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui8 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return rectui8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui8 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return rectui8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui8 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->size.width,(edk::uint8)this->size.height);
    }
    rectui8 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        return rectui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->size.width,(edk::uint8)this->size.height);
    }
    rectui8 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        return rectui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->size.width,(edk::uint8)this->size.height);
    }
    rectui8 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint8)x;
        this->origin.y=(edk::uint8)y;
        this->size.width=(edk::uint8)width;
        this->size.height=(edk::uint8)height;
        return rectui8((edk::uint8)this->origin.x,(edk::uint8)this->origin.y,(edk::uint8)this->size.width,(edk::uint8)this->size.height);
    }
};

class rectui16{
public:
    //position
    edk::vec2ui16 origin;
    //size
    edk::size2ui16 size;
    //Construtor
    rectui16(){
        //
        this->origin.x=(edk::uint16)0;
        this->origin.y=(edk::uint16)0;
        this->size.width=(edk::uint16)0;
        this->size.height=(edk::uint16)0;
    }
    rectui16(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
    }
    rectui16(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
    }
    rectui16(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
    }
    rectui16(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
    }

    //operators
    rectui16 operator=(rectui8 rect){
        //
        this->origin.x=(edk::uint16)rect.origin.x;
        this->origin.y=(edk::uint16)rect.origin.y;
        this->size.width=(edk::uint16)rect.size.width;
        this->size.height=(edk::uint16)rect.size.height;
        return *this;
    }
    rectui16 operator=(rectui16 rect){
        //
        this->origin.x=(edk::uint16)rect.origin.x;
        this->origin.y=(edk::uint16)rect.origin.y;
        this->size.width=(edk::uint16)rect.size.width;
        this->size.height=(edk::uint16)rect.size.height;
        return *this;
    }
    rectui16 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        return *this;
    }
    rectui16 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        return *this;
    }
    rectui16 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        return *this;
    }
    rectui16 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint16)n;
        this->origin.y=(edk::uint16)n;
        this->size.width=(edk::uint16)n;
        this->size.height=(edk::uint16)n;
        return *this;
    }

    bool operator==(rectui8 rect){
        //
        return (this->origin.x==(edk::uint16)rect.origin.x
                &&this->origin.y==(edk::uint16)rect.origin.y
                &&this->size.width==(edk::uint16)rect.size.width
                &&this->size.height==(edk::uint16)rect.size.height
                );
    }
    bool operator==(rectui16 rect){
        //
        return (this->origin.x==(edk::uint16)rect.origin.x
                &&this->origin.y==(edk::uint16)rect.origin.y
                &&this->size.width==(edk::uint16)rect.size.width
                &&this->size.height==(edk::uint16)rect.size.height
                );
    }
    bool operator!=(rectui8 rect){
        //
        return (this->origin.x!=(edk::uint16)rect.origin.x
                ||this->origin.y!=(edk::uint16)rect.origin.y
                ||this->size.width!=(edk::uint16)rect.size.width
                ||this->size.height!=(edk::uint16)rect.size.height
                );
    }
    bool operator!=(rectui16 rect){
        //
        return (this->origin.x!=(edk::uint16)rect.origin.x
                ||this->origin.y!=(edk::uint16)rect.origin.y
                ||this->size.width!=(edk::uint16)rect.size.width
                ||this->size.height!=(edk::uint16)rect.size.height
                );
    }
    rectui16 operator+(rectui8 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint16)rect.size.width;
        ret.size.height=this->size.height+(edk::uint16)rect.size.height;
        return ret;
    }
    rectui16 operator+(rectui16 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint16)rect.size.width;
        ret.size.height=this->size.height+(edk::uint16)rect.size.height;
        return ret;
    }
    rectui16 operator+(edk::uint8 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        return ret;
    }
    rectui16 operator+(edk::uint32 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        return ret;
    }
    rectui16 operator+(edk::uint16 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        return ret;
    }
    rectui16 operator+(edk::uint64 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(edk::uint16)n;
        ret.origin.y=this->origin.y+(edk::uint16)n;
        ret.size.width=this->size.width+(edk::uint16)n;
        ret.size.height=this->size.height+(edk::uint16)n;
        return ret;
    }
    void operator+=(rectui8 rect){
        //
        this->origin.x+=(edk::uint16)rect.origin.x;
        this->origin.y+=(edk::uint16)rect.origin.y;
        this->size.width+=(edk::uint16)rect.size.width;
        this->size.height+=(edk::uint16)rect.size.height;
    }
    void operator+=(rectui16 rect){
        //
        this->origin.x+=(edk::uint16)rect.origin.x;
        this->origin.y+=(edk::uint16)rect.origin.y;
        this->size.width+=(edk::uint16)rect.size.width;
        this->size.height+=(edk::uint16)rect.size.height;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint16)n;
        this->origin.y+=(edk::uint16)n;
        this->size.width+=(edk::uint16)n;
        this->size.height+=(edk::uint16)n;
    }
    rectui16 operator-(rectui8 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint16)rect.size.width;
        ret.size.height=this->size.height-(edk::uint16)rect.size.height;
        return ret;
    }
    rectui16 operator-(rectui16 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint16)rect.size.width;
        ret.size.height=this->size.height-(edk::uint16)rect.size.height;
        return ret;
    }
    rectui16 operator-(edk::uint8 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        return ret;
    }
    rectui16 operator-(edk::uint32 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        return ret;
    }
    rectui16 operator-(edk::uint16 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        return ret;
    }
    rectui16 operator-(edk::uint64 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(edk::uint16)n;
        ret.origin.y=this->origin.y-(edk::uint16)n;
        ret.size.width=this->size.width-(edk::uint16)n;
        ret.size.height=this->size.height-(edk::uint16)n;
        return ret;
    }
    void operator-=(rectui8 vec){
        //
        this->origin.x-=(edk::uint16)vec.origin.x;
        this->origin.y-=(edk::uint16)vec.origin.y;
        this->size.width-=(edk::uint16)vec.size.width;
        this->size.height-=(edk::uint16)vec.size.height;
    }
    void operator-=(rectui16 vec){
        //
        this->origin.x-=(edk::uint16)vec.origin.x;
        this->origin.y-=(edk::uint16)vec.origin.y;
        this->size.width-=(edk::uint16)vec.size.width;
        this->size.height-=(edk::uint16)vec.size.height;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint16)n;
        this->origin.y-=(edk::uint16)n;
        this->size.width-=(edk::uint16)n;
        this->size.height-=(edk::uint16)n;
    }
    rectui16 operator*(rectui8 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint16)rect.size.width;
        ret.size.height=this->size.height*(edk::uint16)rect.size.height;
        return ret;
    }
    rectui16 operator*(rectui16 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint16)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint16)rect.size.width;
        ret.size.height=this->size.height*(edk::uint16)rect.size.height;
        return ret;
    }
    rectui16 operator*(edk::uint8 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        return ret;
    }
    rectui16 operator*(edk::uint32 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        return ret;
    }
    rectui16 operator*(edk::uint16 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        return ret;
    }
    rectui16 operator*(edk::uint64 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(edk::uint16)n;
        ret.origin.y=this->origin.y*(edk::uint16)n;
        ret.size.width=this->size.width*(edk::uint16)n;
        ret.size.height=this->size.height*(edk::uint16)n;
        return ret;
    }
    void operator*=(rectui8 rect){
        //
        this->origin.x*=(edk::uint16)rect.origin.x;
        this->origin.y*=(edk::uint16)rect.origin.y;
        this->size.width*=(edk::uint16)rect.size.width;
        this->size.height*=(edk::uint16)rect.size.height;
    }
    void operator*=(rectui16 rect){
        //
        this->origin.x*=(edk::uint16)rect.origin.x;
        this->origin.y*=(edk::uint16)rect.origin.y;
        this->size.width*=(edk::uint16)rect.size.width;
        this->size.height*=(edk::uint16)rect.size.height;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint16)n;
        this->origin.y*=(edk::uint16)n;
        this->size.width*=(edk::uint16)n;
        this->size.height*=(edk::uint16)n;
    }
    //
    rectui16 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return rectui16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui16 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return rectui16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui16 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return rectui16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui16 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return rectui16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui16 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->size.width,(edk::uint16)this->size.height);
    }
    rectui16 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        return rectui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->size.width,(edk::uint16)this->size.height);
    }
    rectui16 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        return rectui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->size.width,(edk::uint16)this->size.height);
    }
    rectui16 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint16)x;
        this->origin.y=(edk::uint16)y;
        this->size.width=(edk::uint16)width;
        this->size.height=(edk::uint16)height;
        return rectui16((edk::uint16)this->origin.x,(edk::uint16)this->origin.y,(edk::uint16)this->size.width,(edk::uint16)this->size.height);
    }
};

class rectui32{
public:
    //position
    edk::vec2ui32 origin;
    //size
    edk::size2ui32 size;
    //Construtor
    rectui32(){
        //
        this->origin.x=(edk::uint32)0;
        this->origin.y=(edk::uint32)0;
        this->size.width=(edk::uint32)0;
        this->size.height=(edk::uint32)0;
    }
    rectui32(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
    }
    rectui32(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
    }
    rectui32(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
    }
    rectui32(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
    }

    //operators
    rectui32 operator=(rectui8 rect){
        //
        this->origin.x=(edk::uint32)rect.origin.x;
        this->origin.y=(edk::uint32)rect.origin.y;
        this->size.width=(edk::uint32)rect.size.width;
        this->size.height=(edk::uint32)rect.size.height;
        return *this;
    }
    rectui32 operator=(rectui16 rect){
        //
        this->origin.x=(edk::uint32)rect.origin.x;
        this->origin.y=(edk::uint32)rect.origin.y;
        this->size.width=(edk::uint32)rect.size.width;
        this->size.height=(edk::uint32)rect.size.height;
        return *this;
    }
    rectui32 operator=(rectui32 rect){
        //
        this->origin.x=(edk::uint32)rect.origin.x;
        this->origin.y=(edk::uint32)rect.origin.y;
        this->size.width=(edk::uint32)rect.size.width;
        this->size.height=(edk::uint32)rect.size.height;
        return *this;
    }
    rectui32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        return *this;
    }
    rectui32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        return *this;
    }
    rectui32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        return *this;
    }
    rectui32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint32)n;
        this->origin.y=(edk::uint32)n;
        this->size.width=(edk::uint32)n;
        this->size.height=(edk::uint32)n;
        return *this;
    }

    bool operator==(rectui8 rect){
        //
        return (this->origin.x==(edk::uint32)rect.origin.x
                &&this->origin.y==(edk::uint32)rect.origin.y
                &&this->size.width==(edk::uint32)rect.size.width
                &&this->size.height==(edk::uint32)rect.size.height
                );
    }
    bool operator==(rectui16 rect){
        //
        return (this->origin.x==(edk::uint32)rect.origin.x
                &&this->origin.y==(edk::uint32)rect.origin.y
                &&this->size.width==(edk::uint32)rect.size.width
                &&this->size.height==(edk::uint32)rect.size.height
                );
    }
    bool operator==(rectui32 rect){
        //
        return (this->origin.x==(edk::uint32)rect.origin.x
                &&this->origin.y==(edk::uint32)rect.origin.y
                &&this->size.width==(edk::uint32)rect.size.width
                &&this->size.height==(edk::uint32)rect.size.height
                );
    }
    bool operator!=(rectui8 rect){
        //
        return (this->origin.x!=(edk::uint32)rect.origin.x
                ||this->origin.y!=(edk::uint32)rect.origin.y
                ||this->size.width!=(edk::uint32)rect.size.width
                ||this->size.height!=(edk::uint32)rect.size.height
                );
    }
    bool operator!=(rectui16 rect){
        //
        return (this->origin.x!=(edk::uint32)rect.origin.x
                ||this->origin.y!=(edk::uint32)rect.origin.y
                ||this->size.width!=(edk::uint32)rect.size.width
                ||this->size.height!=(edk::uint32)rect.size.height
                );
    }
    bool operator!=(rectui32 rect){
        //
        return (this->origin.x!=(edk::uint32)rect.origin.x
                ||this->origin.y!=(edk::uint32)rect.origin.y
                ||this->size.width!=(edk::uint32)rect.size.width
                ||this->size.height!=(edk::uint32)rect.size.height
                );
    }
    rectui32 operator+(rectui8 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint32)rect.size.width;
        ret.size.height=this->size.height+(edk::uint32)rect.size.height;
        return ret;
    }
    rectui32 operator+(rectui16 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint32)rect.size.width;
        ret.size.height=this->size.height+(edk::uint32)rect.size.height;
        return ret;
    }
    rectui32 operator+(rectui32 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint32)rect.size.width;
        ret.size.height=this->size.height+(edk::uint32)rect.size.height;
        return ret;
    }
    rectui32 operator+(edk::uint8 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        return ret;
    }
    rectui32 operator+(edk::uint32 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        return ret;
    }
    rectui32 operator+(edk::uint16 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        return ret;
    }
    rectui32 operator+(edk::uint64 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(edk::uint32)n;
        ret.origin.y=this->origin.y+(edk::uint32)n;
        ret.size.width=this->size.width+(edk::uint32)n;
        ret.size.height=this->size.height+(edk::uint32)n;
        return ret;
    }
    void operator+=(rectui8 rect){
        //
        this->origin.x+=(edk::uint32)rect.origin.x;
        this->origin.y+=(edk::uint32)rect.origin.y;
        this->size.width+=(edk::uint32)rect.size.width;
        this->size.height+=(edk::uint32)rect.size.height;
    }
    void operator+=(rectui16 rect){
        //
        this->origin.x+=(edk::uint32)rect.origin.x;
        this->origin.y+=(edk::uint32)rect.origin.y;
        this->size.width+=(edk::uint32)rect.size.width;
        this->size.height+=(edk::uint32)rect.size.height;
    }
    void operator+=(rectui32 rect){
        //
        this->origin.x+=(edk::uint32)rect.origin.x;
        this->origin.y+=(edk::uint32)rect.origin.y;
        this->size.width+=(edk::uint32)rect.size.width;
        this->size.height+=(edk::uint32)rect.size.height;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint32)n;
        this->origin.y+=(edk::uint32)n;
        this->size.width+=(edk::uint32)n;
        this->size.height+=(edk::uint32)n;
    }
    rectui32 operator-(rectui8 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint32)rect.size.width;
        ret.size.height=this->size.height-(edk::uint32)rect.size.height;
        return ret;
    }
    rectui32 operator-(rectui16 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint32)rect.size.width;
        ret.size.height=this->size.height-(edk::uint32)rect.size.height;
        return ret;
    }
    rectui32 operator-(rectui32 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint32)rect.size.width;
        ret.size.height=this->size.height-(edk::uint32)rect.size.height;
        return ret;
    }
    rectui32 operator-(edk::uint8 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        return ret;
    }
    rectui32 operator-(edk::uint32 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        return ret;
    }
    rectui32 operator-(edk::uint16 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        return ret;
    }
    rectui32 operator-(edk::uint64 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(edk::uint32)n;
        ret.origin.y=this->origin.y-(edk::uint32)n;
        ret.size.width=this->size.width-(edk::uint32)n;
        ret.size.height=this->size.height-(edk::uint32)n;
        return ret;
    }
    void operator-=(rectui8 vec){
        //
        this->origin.x-=(edk::uint32)vec.origin.x;
        this->origin.y-=(edk::uint32)vec.origin.y;
        this->size.width-=(edk::uint32)vec.size.width;
        this->size.height-=(edk::uint32)vec.size.height;
    }
    void operator-=(rectui16 vec){
        //
        this->origin.x-=(edk::uint32)vec.origin.x;
        this->origin.y-=(edk::uint32)vec.origin.y;
        this->size.width-=(edk::uint32)vec.size.width;
        this->size.height-=(edk::uint32)vec.size.height;
    }
    void operator-=(rectui32 vec){
        //
        this->origin.x-=(edk::uint32)vec.origin.x;
        this->origin.y-=(edk::uint32)vec.origin.y;
        this->size.width-=(edk::uint32)vec.size.width;
        this->size.height-=(edk::uint32)vec.size.height;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint32)n;
        this->origin.y-=(edk::uint32)n;
        this->size.width-=(edk::uint32)n;
        this->size.height-=(edk::uint32)n;
    }
    rectui32 operator*(rectui8 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint32)rect.size.width;
        ret.size.height=this->size.height*(edk::uint32)rect.size.height;
        return ret;
    }
    rectui32 operator*(rectui16 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint32)rect.size.width;
        ret.size.height=this->size.height*(edk::uint32)rect.size.height;
        return ret;
    }
    rectui32 operator*(rectui32 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint32)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint32)rect.size.width;
        ret.size.height=this->size.height*(edk::uint32)rect.size.height;
        return ret;
    }
    rectui32 operator*(edk::uint8 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        return ret;
    }
    rectui32 operator*(edk::uint32 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        return ret;
    }
    rectui32 operator*(edk::uint16 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        return ret;
    }
    rectui32 operator*(edk::uint64 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(edk::uint32)n;
        ret.origin.y=this->origin.y*(edk::uint32)n;
        ret.size.width=this->size.width*(edk::uint32)n;
        ret.size.height=this->size.height*(edk::uint32)n;
        return ret;
    }
    void operator*=(rectui8 rect){
        //
        this->origin.x*=(edk::uint32)rect.origin.x;
        this->origin.y*=(edk::uint32)rect.origin.y;
        this->size.width*=(edk::uint32)rect.size.width;
        this->size.height*=(edk::uint32)rect.size.height;
    }
    void operator*=(rectui16 rect){
        //
        this->origin.x*=(edk::uint32)rect.origin.x;
        this->origin.y*=(edk::uint32)rect.origin.y;
        this->size.width*=(edk::uint32)rect.size.width;
        this->size.height*=(edk::uint32)rect.size.height;
    }
    void operator*=(rectui32 rect){
        //
        this->origin.x*=(edk::uint32)rect.origin.x;
        this->origin.y*=(edk::uint32)rect.origin.y;
        this->size.width*=(edk::uint32)rect.size.width;
        this->size.height*=(edk::uint32)rect.size.height;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint32)n;
        this->origin.y*=(edk::uint32)n;
        this->size.width*=(edk::uint32)n;
        this->size.height*=(edk::uint32)n;
    }
    //
    rectui32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return rectui32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return rectui32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return rectui32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return rectui32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->size.width,(edk::uint32)this->size.height);
    }
    rectui32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        return rectui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->size.width,(edk::uint32)this->size.height);
    }
    rectui32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        return rectui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->size.width,(edk::uint32)this->size.height);
    }
    rectui32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint32)x;
        this->origin.y=(edk::uint32)y;
        this->size.width=(edk::uint32)width;
        this->size.height=(edk::uint32)height;
        return rectui32((edk::uint32)this->origin.x,(edk::uint32)this->origin.y,(edk::uint32)this->size.width,(edk::uint32)this->size.height);
    }
};

class rectui64{
public:
    //position
    edk::vec2ui64 origin;
    //size
    edk::size2ui64 size;
    //Construtor
    rectui64(){
        //
        this->origin.x=(edk::uint64)0;
        this->origin.y=(edk::uint64)0;
        this->size.width=(edk::uint64)0;
        this->size.height=(edk::uint64)0;
    }
    rectui64(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
    }
    rectui64(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
    }
    rectui64(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
    }
    rectui64(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
    }

    //operators
    rectui64 operator=(rectui8 rect){
        //
        this->origin.x=(edk::uint64)rect.origin.x;
        this->origin.y=(edk::uint64)rect.origin.y;
        this->size.width=(edk::uint64)rect.size.width;
        this->size.height=(edk::uint64)rect.size.height;
        return *this;
    }
    rectui64 operator=(rectui16 rect){
        //
        this->origin.x=(edk::uint64)rect.origin.x;
        this->origin.y=(edk::uint64)rect.origin.y;
        this->size.width=(edk::uint64)rect.size.width;
        this->size.height=(edk::uint64)rect.size.height;
        return *this;
    }
    rectui64 operator=(rectui32 rect){
        //
        this->origin.x=(edk::uint64)rect.origin.x;
        this->origin.y=(edk::uint64)rect.origin.y;
        this->size.width=(edk::uint64)rect.size.width;
        this->size.height=(edk::uint64)rect.size.height;
        return *this;
    }
    rectui64 operator=(rectui64 rect){
        //
        this->origin.x=(edk::uint64)rect.origin.x;
        this->origin.y=(edk::uint64)rect.origin.y;
        this->size.width=(edk::uint64)rect.size.width;
        this->size.height=(edk::uint64)rect.size.height;
        return *this;
    }
    rectui64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        return *this;
    }
    rectui64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        return *this;
    }
    rectui64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        return *this;
    }
    rectui64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::uint64)n;
        this->origin.y=(edk::uint64)n;
        this->size.width=(edk::uint64)n;
        this->size.height=(edk::uint64)n;
        return *this;
    }

    bool operator==(rectui8 rect){
        //
        return (this->origin.x==(edk::uint64)rect.origin.x
                &&this->origin.y==(edk::uint64)rect.origin.y
                &&this->size.width==(edk::uint64)rect.size.width
                &&this->size.height==(edk::uint64)rect.size.height
                );
    }
    bool operator==(rectui16 rect){
        //
        return (this->origin.x==(edk::uint64)rect.origin.x
                &&this->origin.y==(edk::uint64)rect.origin.y
                &&this->size.width==(edk::uint64)rect.size.width
                &&this->size.height==(edk::uint64)rect.size.height
                );
    }
    bool operator==(rectui32 rect){
        //
        return (this->origin.x==(edk::uint64)rect.origin.x
                &&this->origin.y==(edk::uint64)rect.origin.y
                &&this->size.width==(edk::uint64)rect.size.width
                &&this->size.height==(edk::uint64)rect.size.height
                );
    }
    bool operator==(rectui64 rect){
        //
        return (this->origin.x==(edk::uint64)rect.origin.x
                &&this->origin.y==(edk::uint64)rect.origin.y
                &&this->size.width==(edk::uint64)rect.size.width
                &&this->size.height==(edk::uint64)rect.size.height
                );
    }
    bool operator!=(rectui8 rect){
        //
        return (this->origin.x!=(edk::uint64)rect.origin.x
                ||this->origin.y!=(edk::uint64)rect.origin.y
                ||this->size.width!=(edk::uint64)rect.size.width
                ||this->size.height!=(edk::uint64)rect.size.height
                );
    }
    bool operator!=(rectui16 rect){
        //
        return (this->origin.x!=(edk::uint64)rect.origin.x
                ||this->origin.y!=(edk::uint64)rect.origin.y
                ||this->size.width!=(edk::uint64)rect.size.width
                ||this->size.height!=(edk::uint64)rect.size.height
                );
    }
    bool operator!=(rectui32 rect){
        //
        return (this->origin.x!=(edk::uint64)rect.origin.x
                ||this->origin.y!=(edk::uint64)rect.origin.y
                ||this->size.width!=(edk::uint64)rect.size.width
                ||this->size.height!=(edk::uint64)rect.size.height
                );
    }
    bool operator!=(rectui64 rect){
        //
        return (this->origin.x!=(edk::uint64)rect.origin.x
                ||this->origin.y!=(edk::uint64)rect.origin.y
                ||this->size.width!=(edk::uint64)rect.size.width
                ||this->size.height!=(edk::uint64)rect.size.height
                );
    }
    rectui64 operator+(rectui8 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint64)rect.size.width;
        ret.size.height=this->size.height+(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator+(rectui16 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint64)rect.size.width;
        ret.size.height=this->size.height+(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator+(rectui32 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint64)rect.size.width;
        ret.size.height=this->size.height+(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator+(rectui64 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width+(edk::uint64)rect.size.width;
        ret.size.height=this->size.height+(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator+(edk::uint8 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        return ret;
    }
    rectui64 operator+(edk::uint32 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        return ret;
    }
    rectui64 operator+(edk::uint16 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        return ret;
    }
    rectui64 operator+(edk::uint64 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(edk::uint64)n;
        ret.origin.y=this->origin.y+(edk::uint64)n;
        ret.size.width=this->size.width+(edk::uint64)n;
        ret.size.height=this->size.height+(edk::uint64)n;
        return ret;
    }
    void operator+=(rectui8 rect){
        //
        this->origin.x+=(edk::uint64)rect.origin.x;
        this->origin.y+=(edk::uint64)rect.origin.y;
        this->size.width+=(edk::uint64)rect.size.width;
        this->size.height+=(edk::uint64)rect.size.height;
    }
    void operator+=(rectui16 rect){
        //
        this->origin.x+=(edk::uint64)rect.origin.x;
        this->origin.y+=(edk::uint64)rect.origin.y;
        this->size.width+=(edk::uint64)rect.size.width;
        this->size.height+=(edk::uint64)rect.size.height;
    }
    void operator+=(rectui32 rect){
        //
        this->origin.x+=(edk::uint64)rect.origin.x;
        this->origin.y+=(edk::uint64)rect.origin.y;
        this->size.width+=(edk::uint64)rect.size.width;
        this->size.height+=(edk::uint64)rect.size.height;
    }
    void operator+=(rectui64 rect){
        //
        this->origin.x+=(edk::uint64)rect.origin.x;
        this->origin.y+=(edk::uint64)rect.origin.y;
        this->size.width+=(edk::uint64)rect.size.width;
        this->size.height+=(edk::uint64)rect.size.height;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::uint64)n;
        this->origin.y+=(edk::uint64)n;
        this->size.width+=(edk::uint64)n;
        this->size.height+=(edk::uint64)n;
    }
    rectui64 operator-(rectui8 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint64)rect.size.width;
        ret.size.height=this->size.height-(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator-(rectui16 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint64)rect.size.width;
        ret.size.height=this->size.height-(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator-(rectui32 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint64)rect.size.width;
        ret.size.height=this->size.height-(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator-(rectui64 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width-(edk::uint64)rect.size.width;
        ret.size.height=this->size.height-(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator-(edk::uint8 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        return ret;
    }
    rectui64 operator-(edk::uint32 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        return ret;
    }
    rectui64 operator-(edk::uint16 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        return ret;
    }
    rectui64 operator-(edk::uint64 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(edk::uint64)n;
        ret.origin.y=this->origin.y-(edk::uint64)n;
        ret.size.width=this->size.width-(edk::uint64)n;
        ret.size.height=this->size.height-(edk::uint64)n;
        return ret;
    }
    void operator-=(rectui8 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;
        this->origin.y-=(edk::uint64)vec.origin.y;
        this->size.width-=(edk::uint64)vec.size.width;
        this->size.height-=(edk::uint64)vec.size.height;
    }
    void operator-=(rectui16 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;
        this->origin.y-=(edk::uint64)vec.origin.y;
        this->size.width-=(edk::uint64)vec.size.width;
        this->size.height-=(edk::uint64)vec.size.height;
    }
    void operator-=(rectui32 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;
        this->origin.y-=(edk::uint64)vec.origin.y;
        this->size.width-=(edk::uint64)vec.size.width;
        this->size.height-=(edk::uint64)vec.size.height;
    }
    void operator-=(rectui64 vec){
        //
        this->origin.x-=(edk::uint64)vec.origin.x;
        this->origin.y-=(edk::uint64)vec.origin.y;
        this->size.width-=(edk::uint64)vec.size.width;
        this->size.height-=(edk::uint64)vec.size.height;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::uint64)n;
        this->origin.y-=(edk::uint64)n;
        this->size.width-=(edk::uint64)n;
        this->size.height-=(edk::uint64)n;
    }
    rectui64 operator*(rectui8 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint64)rect.size.width;
        ret.size.height=this->size.height*(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator*(rectui16 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint64)rect.size.width;
        ret.size.height=this->size.height*(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator*(rectui32 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint64)rect.size.width;
        ret.size.height=this->size.height*(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator*(rectui64 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::uint64)rect.origin.y;
        ret.size.width=this->size.width*(edk::uint64)rect.size.width;
        ret.size.height=this->size.height*(edk::uint64)rect.size.height;
        return ret;
    }
    rectui64 operator*(edk::uint8 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        return ret;
    }
    rectui64 operator*(edk::uint32 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        return ret;
    }
    rectui64 operator*(edk::uint16 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        return ret;
    }
    rectui64 operator*(edk::uint64 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(edk::uint64)n;
        ret.origin.y=this->origin.y*(edk::uint64)n;
        ret.size.width=this->size.width*(edk::uint64)n;
        ret.size.height=this->size.height*(edk::uint64)n;
        return ret;
    }
    void operator*=(rectui8 rect){
        //
        this->origin.x*=(edk::uint64)rect.origin.x;
        this->origin.y*=(edk::uint64)rect.origin.y;
        this->size.width*=(edk::uint64)rect.size.width;
        this->size.height*=(edk::uint64)rect.size.height;
    }
    void operator*=(rectui16 rect){
        //
        this->origin.x*=(edk::uint64)rect.origin.x;
        this->origin.y*=(edk::uint64)rect.origin.y;
        this->size.width*=(edk::uint64)rect.size.width;
        this->size.height*=(edk::uint64)rect.size.height;
    }
    void operator*=(rectui32 rect){
        //
        this->origin.x*=(edk::uint64)rect.origin.x;
        this->origin.y*=(edk::uint64)rect.origin.y;
        this->size.width*=(edk::uint64)rect.size.width;
        this->size.height*=(edk::uint64)rect.size.height;
    }
    void operator*=(rectui64 rect){
        //
        this->origin.x*=(edk::uint64)rect.origin.x;
        this->origin.y*=(edk::uint64)rect.origin.y;
        this->size.width*=(edk::uint64)rect.size.width;
        this->size.height*=(edk::uint64)rect.size.height;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::uint64)n;
        this->origin.y*=(edk::uint64)n;
        this->size.width*=(edk::uint64)n;
        this->size.height*=(edk::uint64)n;
    }
    //
    rectui64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return rectui64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return rectui64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return rectui64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return rectui64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->size.width,(edk::uint64)this->size.height);
    }
    rectui64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        return rectui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->size.width,(edk::uint64)this->size.height);
    }
    rectui64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        return rectui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->size.width,(edk::uint64)this->size.height);
    }
    rectui64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::uint64)x;
        this->origin.y=(edk::uint64)y;
        this->size.width=(edk::uint64)width;
        this->size.height=(edk::uint64)height;
        return rectui64((edk::uint64)this->origin.x,(edk::uint64)this->origin.y,(edk::uint64)this->size.width,(edk::uint64)this->size.height);
    }
};

class rectf32{
public:
    //position
    edk::vec2f32 origin;
    //size
    edk::size2f32 size;
    //Construtor
    rectf32(){
        //
        this->origin.x=(edk::float32)0;
        this->origin.y=(edk::float32)0;
        this->size.width=(edk::float32)0;
        this->size.height=(edk::float32)0;
    }
    rectf32(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(edk::float64 x,edk::float64 y,edk::float64 width,edk::float64 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }

    //operators
    rectf32 operator=(rectf32 rect){
        //
        this->origin.x=(edk::float32)rect.origin.x;
        this->origin.y=(edk::float32)rect.origin.y;
        this->size.width=(edk::float32)rect.size.width;
        this->size.height=(edk::float32)rect.size.height;
        return *this;
    }
    rectf32 operator=(edk::float32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(edk::float64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(edk::int8 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(edk::int32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(edk::int16 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(edk::int64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }

    bool operator==(rectf32 rect){
        //
        return (this->origin.x==(edk::float32)rect.origin.x
                &&this->origin.y==(edk::float32)rect.origin.y
                &&this->size.width==(edk::float32)rect.size.width
                &&this->size.height==(edk::float32)rect.size.height
                );
    }
    bool operator!=(rectf32 rect){
        //
        return (this->origin.x!=(edk::float32)rect.origin.x
                ||this->origin.y!=(edk::float32)rect.origin.y
                ||this->size.width!=(edk::float32)rect.size.width
                ||this->size.height!=(edk::float32)rect.size.height
                );
    }
    rectf32 operator+(rectf32 rect){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::float32)rect.origin.y;
        ret.size.width=this->size.width+(edk::float32)rect.size.width;
        ret.size.height=this->size.height+(edk::float32)rect.size.height;
        return ret;
    }
    rectf32 operator+(edk::float32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(edk::float64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(edk::int8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(edk::int32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(edk::int16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(edk::int64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(edk::uint8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(edk::uint32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(edk::uint16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(edk::uint64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    void operator+=(rectf32 rect){
        //
        this->origin.x+=(edk::float32)rect.origin.x;
        this->origin.y+=(edk::float32)rect.origin.y;
        this->size.width+=(edk::float32)rect.size.width;
        this->size.height+=(edk::float32)rect.size.height;
    }
    void operator+=(edk::float32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(edk::float64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    rectf32 operator-(rectf32 rect){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::float32)rect.origin.y;
        ret.size.width=this->size.width-(edk::float32)rect.size.width;
        ret.size.height=this->size.height-(edk::float32)rect.size.height;
        return ret;
    }
    rectf32 operator-(edk::float32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(edk::float64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(edk::int8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(edk::int32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(edk::int16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(edk::int64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(edk::uint8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(edk::uint32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(edk::uint16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(edk::uint64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    void operator-=(rectf32 vec){
        //
        this->origin.x-=(edk::float32)vec.origin.x;
        this->origin.y-=(edk::float32)vec.origin.y;
        this->size.width-=(edk::float32)vec.size.width;
        this->size.height-=(edk::float32)vec.size.height;
    }
    void operator-=(edk::float32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(edk::float64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    rectf32 operator*(rectf32 rect){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::float32)rect.origin.y;
        ret.size.width=this->size.width*(edk::float32)rect.size.width;
        ret.size.height=this->size.height*(edk::float32)rect.size.height;
        return ret;
    }
    rectf32 operator*(edk::float32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(edk::float64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(edk::int8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(edk::int32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(edk::int16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(edk::int64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(edk::uint8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(edk::uint32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(edk::uint16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(edk::uint64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    void operator*=(rectf32 rect){
        //
        this->origin.x*=(edk::float32)rect.origin.x;
        this->origin.y*=(edk::float32)rect.origin.y;
        this->size.width*=(edk::float32)rect.size.width;
        this->size.height*=(edk::float32)rect.size.height;
    }
    void operator*=(edk::float32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(edk::float64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
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
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    //
    rectf32 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return rectf32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectf32 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return rectf32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectf32 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return rectf32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectf32 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return rectf32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectf32 operator()(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(edk::float64 x,edk::float64 y,edk::float64 width,edk::float64 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
};

class rectf64{
public:
    //position
    edk::vec2f64 origin;
    //size
    edk::size2f64 size;
    //Construtor
    rectf64(){
        //
        this->origin.x=(edk::float64)0;
        this->origin.y=(edk::float64)0;
        this->size.width=(edk::float64)0;
        this->size.height=(edk::float64)0;
    }
    rectf64(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(edk::float64 x,edk::float64 y,edk::float64 width,edk::float64 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }

    //operators
    rectf64 operator=(rectf64 rect){
        //
        this->origin.x=(edk::float64)rect.origin.x;
        this->origin.y=(edk::float64)rect.origin.y;
        this->size.width=(edk::float64)rect.size.width;
        this->size.height=(edk::float64)rect.size.height;
        return *this;
    }
    rectf64 operator=(edk::float32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(edk::float64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(edk::int8 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(edk::int32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(edk::int16 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(edk::int64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(edk::uint8 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(edk::uint32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(edk::uint16 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(edk::uint64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }

    bool operator==(rectf64 rect){
        //
        return (this->origin.x==(edk::float64)rect.origin.x
                &&this->origin.y==(edk::float64)rect.origin.y
                &&this->size.width==(edk::float64)rect.size.width
                &&this->size.height==(edk::float64)rect.size.height
                );
    }
    bool operator!=(rectf64 rect){
        //
        return (this->origin.x!=(edk::float64)rect.origin.x
                ||this->origin.y!=(edk::float64)rect.origin.y
                ||this->size.width!=(edk::float64)rect.size.width
                ||this->size.height!=(edk::float64)rect.size.height
                );
    }
    rectf64 operator+(rectf64 rect){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)rect.origin.x;
        ret.origin.y=this->origin.y+(edk::float64)rect.origin.y;
        ret.size.width=this->size.width+(edk::float64)rect.size.width;
        ret.size.height=this->size.height+(edk::float64)rect.size.height;
        return ret;
    }
    rectf64 operator+(edk::float32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(edk::float64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(edk::int8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(edk::int32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(edk::int16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(edk::int64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(edk::uint8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(edk::uint32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(edk::uint16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(edk::uint64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    void operator+=(rectf64 rect){
        //
        this->origin.x+=(edk::float64)rect.origin.x;
        this->origin.y+=(edk::float64)rect.origin.y;
        this->size.width+=(edk::float64)rect.size.width;
        this->size.height+=(edk::float64)rect.size.height;
    }
    void operator+=(edk::float32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(edk::float64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(edk::int8 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(edk::int32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(edk::int16 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(edk::int64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(edk::uint8 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(edk::uint32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(edk::uint16 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(edk::uint64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    rectf64 operator-(rectf64 rect){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)rect.origin.x;
        ret.origin.y=this->origin.y-(edk::float64)rect.origin.y;
        ret.size.width=this->size.width-(edk::float64)rect.size.width;
        ret.size.height=this->size.height-(edk::float64)rect.size.height;
        return ret;
    }
    rectf64 operator-(edk::float32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(edk::float64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(edk::int8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(edk::int32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(edk::int16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(edk::int64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(edk::uint8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(edk::uint32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(edk::uint16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(edk::uint64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    void operator-=(rectf64 vec){
        //
        this->origin.x-=(edk::float64)vec.origin.x;
        this->origin.y-=(edk::float64)vec.origin.y;
        this->size.width-=(edk::float64)vec.size.width;
        this->size.height-=(edk::float64)vec.size.height;
    }
    void operator-=(edk::float32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(edk::float64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(edk::int8 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(edk::int32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(edk::int16 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(edk::int64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(edk::uint8 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(edk::uint32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(edk::uint16 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(edk::uint64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    rectf64 operator*(rectf64 rect){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)rect.origin.x;
        ret.origin.y=this->origin.y*(edk::float64)rect.origin.y;
        ret.size.width=this->size.width*(edk::float64)rect.size.width;
        ret.size.height=this->size.height*(edk::float64)rect.size.height;
        return ret;
    }
    rectf64 operator*(edk::float32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(edk::float64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(edk::int8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(edk::int32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(edk::int16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(edk::int64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(edk::uint8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(edk::uint32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(edk::uint16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(edk::uint64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    void operator*=(rectf64 rect){
        //
        this->origin.x*=(edk::float64)rect.origin.x;
        this->origin.y*=(edk::float64)rect.origin.y;
        this->size.width*=(edk::float64)rect.size.width;
        this->size.height*=(edk::float64)rect.size.height;
    }
    void operator*=(edk::float32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(edk::float64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(edk::int8 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(edk::int32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
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
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(edk::uint8 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(edk::uint32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(edk::uint16 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(edk::uint64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    //
    rectf64 operator++(){
        //
        ++this->origin.x;
        ++this->origin.y;
        ++this->size.width;
        ++this->size.height;
        return rectf64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectf64 operator++(edk::int32){
        //
        this->origin.x++;
        this->origin.y++;
        this->size.width++;
        this->size.height++;
        return rectf64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectf64 operator--(){
        //
        --this->origin.x;
        --this->origin.y;
        --this->size.width;
        --this->size.height;
        return rectf64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectf64 operator--(edk::int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return rectf64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectf64 operator()(edk::float32 x,edk::float32 y,edk::float32 width,edk::float32 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(edk::float64 x,edk::float64 y,edk::float64 width,edk::float64 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(edk::int8 x,edk::int8 y,edk::int8 width,edk::int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(edk::int32 x,edk::int32 y,edk::int32 width,edk::int32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(edk::int16 x,edk::int16 y,edk::int16 width,edk::int16 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(edk::int64 x,edk::int64 y,edk::int64 width,edk::int64 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(edk::uint8 x,edk::uint8 y,edk::uint8 width,edk::uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(edk::uint16 x,edk::uint16 y,edk::uint16 width,edk::uint16 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(edk::uint64 x,edk::uint64 y,edk::uint64 width,edk::uint64 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
};

}//end namespace

#endif // TYPERECT_H
