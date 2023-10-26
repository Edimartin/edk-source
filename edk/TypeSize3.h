#ifndef EDK_TYPESIZE3_H
#define EDK_TYPESIZE3_H

/*
Library C++ typeSize3 - 3D size types used in Edk Game Engine
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
#pragma message "Inside TypesSize3"
#endif

#pragma once
#include "TypeVars.h"
#include "TypeSize2.h"

#ifdef printMessages
#pragma message "    Compiling TypesSize3"
#endif

namespace edk{
//
//size3i8
class size3i8{
    //
public:
    edk::int8 width,height,length;

    //CONSTRUTOR
    size3i8(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3i8(edk::int8 width,edk::int8 height,edk::int8 length){
        //zera as variaveis
        this->width=(edk::int8)width;
        this->height=(edk::int8)height;
        this->length=(edk::int8)length;
    }
    size3i8(edk::int16 width,edk::int16 height,edk::int16 length){
        //zera as variaveis
        this->width=(edk::int8)width;
        this->height=(edk::int8)height;
        this->length=(edk::int8)length;
    }
    size3i8(edk::int32 width,edk::int32 height,edk::int32 length){
        //zera as variaveis
        this->width=(edk::int8)width;
        this->height=(edk::int8)height;
        this->length=(edk::int8)length;
    }
    size3i8(edk::int64 width,edk::int64 height,edk::int64 length){
        //zera as variaveis
        this->width=(edk::int8)width;
        this->height=(edk::int8)height;
        this->length=(edk::int8)length;
    }
    size3i8(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //zera as variaveis
        this->width=(edk::int8)width;
        this->height=(edk::int8)height;
        this->length=(edk::int8)length;
    }
    size3i8(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //zera as variaveis
        this->width=(edk::int8)width;
        this->height=(edk::int8)height;
        this->length=(edk::int8)length;
    }
    size3i8(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //zera as variaveis
        this->width=(edk::int8)width;
        this->height=(edk::int8)height;
        this->length=(edk::int8)length;
    }
    size3i8(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //zera as variaveis
        this->width=(edk::int8)width;
        this->height=(edk::int8)height;
        this->length=(edk::int8)length;
    }
    size3i8(edk::int8 size){
        //zera as variaveis
        this->width=(edk::int8)size;
        this->height=(edk::int8)size;
        this->length=(edk::int8)size;
    }
    size3i8(edk::int16 size){
        //zera as variaveis
        this->width=(edk::int8)size;
        this->height=(edk::int8)size;
        this->length=(edk::int8)size;
    }
    size3i8(edk::int32 size){
        //zera as variaveis
        this->width=(edk::int8)size;
        this->height=(edk::int8)size;
        this->length=(edk::int8)size;
    }
    size3i8(edk::int64 size){
        //zera as variaveis
        this->width=(edk::int8)size;
        this->height=(edk::int8)size;
        this->length=(edk::int8)size;
    }
    size3i8(edk::uint8 size){
        //zera as variaveis
        this->width=(edk::int8)size;
        this->height=(edk::int8)size;
        this->length=(edk::int8)size;
    }
    size3i8(edk::uint16 size){
        //zera as variaveis
        this->width=(edk::int8)size;
        this->height=(edk::int8)size;
        this->length=(edk::int8)size;
    }
    size3i8(edk::uint32 size){
        //zera as variaveis
        this->width=(edk::int8)size;
        this->height=(edk::int8)size;
        this->length=(edk::int8)size;
    }
    size3i8(edk::uint64 size){
        //zera as variaveis
        this->width=(edk::int8)size;
        this->height=(edk::int8)size;
        this->length=(edk::int8)size;
    }
    //operators

    //=
    inline edk::size3i8 operator=(edk::size3i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3i8 operator=(edk::size2i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=(edk::int8)0;
        return *this;
    }
    inline edk::size3i8 operator=(edk::int8 n){
        //
        this->width=(edk::int8)n;
        this->height=(edk::int8)n;
        this->length=(edk::int8)n;
        return *this;
    }
    inline edk::size3i8 operator=(edk::int16 n){
        //
        this->width=(edk::int8)n;
        this->height=(edk::int8)n;
        this->length=(edk::int8)n;
        return *this;
    }
    inline edk::size3i8 operator=(edk::int32 n){
        //
        this->width=(edk::int8)n;
        this->height=(edk::int8)n;
        this->length=(edk::int8)n;
        return *this;
    }
    inline edk::size3i8 operator=(edk::int64 n){
        //
        this->width=(edk::int8)n;
        this->height=(edk::int8)n;
        this->length=(edk::int8)n;
        return *this;
    }
    inline edk::size3i8 operator=(edk::uint8 n){
        //
        this->width=(edk::int8)n;
        this->height=(edk::int8)n;
        this->length=(edk::int8)n;
        return *this;
    }
    inline edk::size3i8 operator=(edk::uint16 n){
        //
        this->width=(edk::int8)n;
        this->height=(edk::int8)n;
        this->length=(edk::int8)n;
        return *this;
    }
    inline edk::size3i8 operator=(edk::uint32 n){
        //
        this->width=(edk::int8)n;
        this->height=(edk::int8)n;
        this->length=(edk::int8)n;
        return *this;
    }
    inline edk::size3i8 operator=(edk::uint64 n){
        //
        this->width=(edk::int8)n;
        this->height=(edk::int8)n;
        this->length=(edk::int8)n;
        return *this;
    }

    //==
    inline bool operator==(edk::size3i8 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    inline bool operator!=(edk::size3i8 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    inline edk::size3i8 operator+(edk::size3i8 size){
        //
        edk::size3i8 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    inline edk::size3i8 operator+(edk::size2i8 size){
        //
        edk::size3i8 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    inline edk::size3i8 operator+(edk::int8 n){
        //
        edk::size3i8 ret;
        ret.width=this->width+(edk::int8)n;
        ret.height=this->height+(edk::int8)n;
        ret.length=this->length+(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator+(edk::int16 n){
        //
        edk::size3i8 ret;
        ret.width=this->width+(edk::int8)n;
        ret.height=this->height+(edk::int8)n;
        ret.length=this->length+(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator+(edk::int32 n){
        //
        edk::size3i8 ret;
        ret.width=this->width+(edk::int8)n;
        ret.height=this->height+(edk::int8)n;
        ret.length=this->length+(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator+(edk::int64 n){
        //
        edk::size3i8 ret;
        ret.width=this->width+(edk::int8)n;
        ret.height=this->height+(edk::int8)n;
        ret.length=this->length+(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator+(edk::uint8 n){
        //
        edk::size3i8 ret;
        ret.width=this->width+(edk::int8)n;
        ret.height=this->height+(edk::int8)n;
        ret.length=this->length+(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator+(edk::uint16 n){
        //
        edk::size3i8 ret;
        ret.width=this->width+(edk::int8)n;
        ret.height=this->height+(edk::int8)n;
        ret.length=this->length+(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator+(edk::uint32 n){
        //
        edk::size3i8 ret;
        ret.width=this->width+(edk::int8)n;
        ret.height=this->height+(edk::int8)n;
        ret.length=this->length+(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator+(edk::uint64 n){
        //
        edk::size3i8 ret;
        ret.width=this->width+(edk::int8)n;
        ret.height=this->height+(edk::int8)n;
        ret.length=this->length+(edk::int8)n;
        return ret;
    }

    //+=
    inline void operator+=(edk::size3i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    inline void operator+=(edk::size2i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    inline void operator+=(edk::int8 n){
        //
        this->width+=(edk::int8)n;
        this->height+=(edk::int8)n;
        this->length+=(edk::int8)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->width+=(edk::int8)n;
        this->height+=(edk::int8)n;
        this->length+=(edk::int8)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->width+=(edk::int8)n;
        this->height+=(edk::int8)n;
        this->length+=(edk::int8)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->width+=(edk::int8)n;
        this->height+=(edk::int8)n;
        this->length+=(edk::int8)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->width+=(edk::int8)n;
        this->height+=(edk::int8)n;
        this->length+=(edk::int8)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->width+=(edk::int8)n;
        this->height+=(edk::int8)n;
        this->length+=(edk::int8)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->width+=(edk::int8)n;
        this->height+=(edk::int8)n;
        this->length+=(edk::int8)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->width+=(edk::int8)n;
        this->height+=(edk::int8)n;
        this->length+=(edk::int8)n;
    }

    //-
    inline edk::size3i8 operator-(edk::size3i8 size){
        //
        edk::size3i8 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    inline edk::size3i8 operator-(edk::size2i8 size){
        //
        edk::size3i8 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    inline edk::size3i8 operator-(edk::int8 n){
        //
        edk::size3i8 ret;
        ret.width=this->width-(edk::int8)n;
        ret.height=this->height-(edk::int8)n;
        ret.length=this->length-(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator-(edk::int16 n){
        //
        edk::size3i8 ret;
        ret.width=this->width-(edk::int8)n;
        ret.height=this->height-(edk::int8)n;
        ret.length=this->length-(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator-(edk::int32 n){
        //
        edk::size3i8 ret;
        ret.width=this->width-(edk::int8)n;
        ret.height=this->height-(edk::int8)n;
        ret.length=this->length-(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator-(edk::int64 n){
        //
        edk::size3i8 ret;
        ret.width=this->width-(edk::int8)n;
        ret.height=this->height-(edk::int8)n;
        ret.length=this->length-(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator-(edk::uint8 n){
        //
        edk::size3i8 ret;
        ret.width=this->width-(edk::int8)n;
        ret.height=this->height-(edk::int8)n;
        ret.length=this->length-(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator-(edk::uint16 n){
        //
        edk::size3i8 ret;
        ret.width=this->width-(edk::int8)n;
        ret.height=this->height-(edk::int8)n;
        ret.length=this->length-(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator-(edk::uint32 n){
        //
        edk::size3i8 ret;
        ret.width=this->width-(edk::int8)n;
        ret.height=this->height-(edk::int8)n;
        ret.length=this->length-(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator-(edk::uint64 n){
        //
        edk::size3i8 ret;
        ret.width=this->width-(edk::int8)n;
        ret.height=this->height-(edk::int8)n;
        ret.length=this->length-(edk::int8)n;
        return ret;
    }

    //-=
    inline void operator-=(edk::size3i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    inline void operator-=(edk::size2i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    inline void operator-=(edk::int8 n){
        //
        this->width-=(edk::int8)n;
        this->height-=(edk::int8)n;
        this->length-=(edk::int8)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->width-=(edk::int8)n;
        this->height-=(edk::int8)n;
        this->length-=(edk::int8)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->width-=(edk::int8)n;
        this->height-=(edk::int8)n;
        this->length-=(edk::int8)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->width-=(edk::int8)n;
        this->height-=(edk::int8)n;
        this->length-=(edk::int8)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->width-=(edk::int8)n;
        this->height-=(edk::int8)n;
        this->length-=(edk::int8)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->width-=(edk::int8)n;
        this->height-=(edk::int8)n;
        this->length-=(edk::int8)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->width-=(edk::int8)n;
        this->height-=(edk::int8)n;
        this->length-=(edk::int8)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->width-=(edk::int8)n;
        this->height-=(edk::int8)n;
        this->length-=(edk::int8)n;
    }

    //*
    inline edk::size3i8 operator*(edk::size3i8 size){
        //
        edk::size3i8 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    inline edk::size3i8 operator*(edk::size2i8 size){
        //
        edk::size3i8 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    inline edk::size3i8 operator*(edk::int8 n){
        //
        edk::size3i8 ret;
        ret.width=this->width*(edk::int8)n;
        ret.height=this->height*(edk::int8)n;
        ret.length=this->length*(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator*(edk::int16 n){
        //
        edk::size3i8 ret;
        ret.width=this->width*(edk::int8)n;
        ret.height=this->height*(edk::int8)n;
        ret.length=this->length*(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator*(edk::int32 n){
        //
        edk::size3i8 ret;
        ret.width=this->width*(edk::int8)n;
        ret.height=this->height*(edk::int8)n;
        ret.length=this->length*(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator*(edk::int64 n){
        //
        edk::size3i8 ret;
        ret.width=this->width*(edk::int8)n;
        ret.height=this->height*(edk::int8)n;
        ret.length=this->length*(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator*(edk::uint8 n){
        //
        edk::size3i8 ret;
        ret.width=this->width*(edk::int8)n;
        ret.height=this->height*(edk::int8)n;
        ret.length=this->length*(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator*(edk::uint16 n){
        //
        edk::size3i8 ret;
        ret.width=this->width*(edk::int8)n;
        ret.height=this->height*(edk::int8)n;
        ret.length=this->length*(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator*(edk::uint32 n){
        //
        edk::size3i8 ret;
        ret.width=this->width*(edk::int8)n;
        ret.height=this->height*(edk::int8)n;
        ret.length=this->length*(edk::int8)n;
        return ret;
    }
    inline edk::size3i8 operator*(edk::uint64 n){
        //
        edk::size3i8 ret;
        ret.width=this->width*(edk::int8)n;
        ret.height=this->height*(edk::int8)n;
        ret.length=this->length*(edk::int8)n;
        return ret;
    }

    //*=
    inline void operator*=(edk::size3i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    inline void operator*=(edk::size2i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    inline void operator*=(edk::int8 n){
        //
        this->width*=(edk::int8)n;
        this->height*=(edk::int8)n;
        this->length*=(edk::int8)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->width*=(edk::int8)n;
        this->height*=(edk::int8)n;
        this->length*=(edk::int8)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->width*=(edk::int8)n;
        this->height*=(edk::int8)n;
        this->length*=(edk::int8)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->width*=(edk::int8)n;
        this->height*=(edk::int8)n;
        this->length*=(edk::int8)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->width*=(edk::int8)n;
        this->height*=(edk::int8)n;
        this->length*=(edk::int8)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->width*=(edk::int8)n;
        this->height*=(edk::int8)n;
        this->length*=(edk::int8)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->width*=(edk::int8)n;
        this->height*=(edk::int8)n;
        this->length*=(edk::int8)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->width*=(edk::int8)n;
        this->height*=(edk::int8)n;
        this->length*=(edk::int8)n;
    }

    //++
    inline edk::size3i8 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return edk::size3i8(this->width,this->height,this->length);
    }
    inline edk::size3i8 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return edk::size3i8(this->width,this->height,this->length);
    }

    //--
    inline edk::size3i8 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return edk::size3i8(this->width,this->height,this->length);
    }
    inline edk::size3i8 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return edk::size3i8(this->width,this->height,this->length);
    }

    //
    inline edk::size3i8 operator()(edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i8((edk::int8)this->width,(edk::int8)this->height,(edk::int8)this->length);
    }
    inline edk::size3i8 operator()(edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i8((edk::int8)this->width,(edk::int8)this->height,(edk::int8)this->length);
    }
    inline edk::size3i8 operator()(edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i8((edk::int8)this->width,(edk::int8)this->height,(edk::int8)this->length);
    }
    inline edk::size3i8 operator()(edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i8((edk::int8)this->width,(edk::int8)this->height,(edk::int8)this->length);
    }
    inline edk::size3i8 operator()(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i8((edk::int8)this->width,(edk::int8)this->height,(edk::int8)this->length);
    }
    inline edk::size3i8 operator()(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i8((edk::int8)this->width,(edk::int8)this->height,(edk::int8)this->length);
    }
    inline edk::size3i8 operator()(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i8((edk::int8)this->width,(edk::int8)this->height,(edk::int8)this->length);
    }
    inline edk::size3i8 operator()(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i8((edk::int8)this->width,(edk::int8)this->height,(edk::int8)this->length);
    }
};

//size3i16
class size3i16{
    //
public:
    edk::int16 width,height,length;

    //CONSTRUTOR
    size3i16(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3i16(edk::int8 width,edk::int8 height,edk::int8 length){
        //zera as variaveis
        this->width=(edk::int16)width;
        this->height=(edk::int16)height;
        this->length=(edk::int16)length;
    }
    size3i16(edk::int16 width,edk::int16 height,edk::int16 length){
        //zera as variaveis
        this->width=(edk::int16)width;
        this->height=(edk::int16)height;
        this->length=(edk::int16)length;
    }
    size3i16(edk::int32 width,edk::int32 height,edk::int32 length){
        //zera as variaveis
        this->width=(edk::int16)width;
        this->height=(edk::int16)height;
        this->length=(edk::int16)length;
    }
    size3i16(edk::int64 width,edk::int64 height,edk::int64 length){
        //zera as variaveis
        this->width=(edk::int16)width;
        this->height=(edk::int16)height;
        this->length=(edk::int16)length;
    }
    size3i16(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //zera as variaveis
        this->width=(edk::int16)width;
        this->height=(edk::int16)height;
        this->length=(edk::int16)length;
    }
    size3i16(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //zera as variaveis
        this->width=(edk::int16)width;
        this->height=(edk::int16)height;
        this->length=(edk::int16)length;
    }
    size3i16(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //zera as variaveis
        this->width=(edk::int16)width;
        this->height=(edk::int16)height;
        this->length=(edk::int16)length;
    }
    size3i16(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //zera as variaveis
        this->width=(edk::int16)width;
        this->height=(edk::int16)height;
        this->length=(edk::int16)length;
    }
    size3i16(edk::int8 size){
        //zera as variaveis
        this->width=(edk::int16)size;
        this->height=(edk::int16)size;
        this->length=(edk::int16)size;
    }
    size3i16(edk::int16 size){
        //zera as variaveis
        this->width=(edk::int16)size;
        this->height=(edk::int16)size;
        this->length=(edk::int16)size;
    }
    size3i16(edk::int32 size){
        //zera as variaveis
        this->width=(edk::int16)size;
        this->height=(edk::int16)size;
        this->length=(edk::int16)size;
    }
    size3i16(edk::int64 size){
        //zera as variaveis
        this->width=(edk::int16)size;
        this->height=(edk::int16)size;
        this->length=(edk::int16)size;
    }
    size3i16(edk::uint8 size){
        //zera as variaveis
        this->width=(edk::int16)size;
        this->height=(edk::int16)size;
        this->length=(edk::int16)size;
    }
    size3i16(edk::uint16 size){
        //zera as variaveis
        this->width=(edk::int16)size;
        this->height=(edk::int16)size;
        this->length=(edk::int16)size;
    }
    size3i16(edk::uint32 size){
        //zera as variaveis
        this->width=(edk::int16)size;
        this->height=(edk::int16)size;
        this->length=(edk::int16)size;
    }
    size3i16(edk::uint64 size){
        //zera as variaveis
        this->width=(edk::int16)size;
        this->height=(edk::int16)size;
        this->length=(edk::int16)size;
    }
    //operators

    //=
    inline edk::size3i16 operator=(edk::size3i8 size){
        //
        this->width=(edk::int16)size.width;
        this->height=(edk::int16)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3i16 operator=(edk::size3i16 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3i16 operator=(edk::size2i8 size){
        //
        this->width=(edk::int16)size.width;
        this->height=(edk::int16)size.height;
        this->length=(edk::int16)0;
        return *this;
    }
    inline edk::size3i16 operator=(edk::int8 n){
        //
        this->width=(edk::int16)n;
        this->height=(edk::int16)n;
        this->length=(edk::int16)n;
        return *this;
    }
    inline edk::size3i16 operator=(edk::int16 n){
        //
        this->width=(edk::int16)n;
        this->height=(edk::int16)n;
        this->length=(edk::int16)n;
        return *this;
    }
    inline edk::size3i16 operator=(edk::int32 n){
        //
        this->width=(edk::int16)n;
        this->height=(edk::int16)n;
        this->length=(edk::int16)n;
        return *this;
    }
    inline edk::size3i16 operator=(edk::int64 n){
        //
        this->width=(edk::int16)n;
        this->height=(edk::int16)n;
        this->length=(edk::int16)n;
        return *this;
    }
    inline edk::size3i16 operator=(edk::uint8 n){
        //
        this->width=(edk::int16)n;
        this->height=(edk::int16)n;
        this->length=(edk::int16)n;
        return *this;
    }
    inline edk::size3i16 operator=(edk::uint16 n){
        //
        this->width=(edk::int16)n;
        this->height=(edk::int16)n;
        this->length=(edk::int16)n;
        return *this;
    }
    inline edk::size3i16 operator=(edk::uint32 n){
        //
        this->width=(edk::int16)n;
        this->height=(edk::int16)n;
        this->length=(edk::int16)n;
        return *this;
    }
    inline edk::size3i16 operator=(edk::uint64 n){
        //
        this->width=(edk::int16)n;
        this->height=(edk::int16)n;
        this->length=(edk::int16)n;
        return *this;
    }

    //==
    inline bool operator==(edk::size3i8 size){
        //
        return (this->width==(edk::int16)size.width&&this->height==(edk::int16)size.height&&this->length==(edk::int16)size.length);
    }
    inline bool operator==(edk::size3i16 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    inline bool operator!=(edk::size3i8 size){
        //
        return (this->width!=(edk::int16)size.width||this->height!=(edk::int16)size.height||this->length!=(edk::int16)size.length);
    }
    inline bool operator!=(edk::size3i16 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    inline edk::size3i16 operator+(edk::size3i8 size){
        //
        edk::size3i16 ret;
        ret.width=this->width+(edk::int16)size.width;
        ret.height=this->height+(edk::int16)size.height;
        ret.length=this->length+(edk::int16)size.length;
        return ret;
    }
    inline edk::size3i16 operator+(edk::size3i16 size){
        //
        edk::size3i16 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    inline edk::size3i16 operator+(edk::size2i8 size){
        //
        edk::size3i16 ret;
        ret.width=this->width+(edk::int16)size.width;
        ret.height=this->height+(edk::int16)size.height;
        return ret;
    }
    inline edk::size3i16 operator+(edk::int8 n){
        //
        edk::size3i16 ret;
        ret.width=this->width+(edk::int16)n;
        ret.height=this->height+(edk::int16)n;
        ret.length=this->length+(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator+(edk::int16 n){
        //
        edk::size3i16 ret;
        ret.width=this->width+(edk::int16)n;
        ret.height=this->height+(edk::int16)n;
        ret.length=this->length+(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator+(edk::int32 n){
        //
        edk::size3i16 ret;
        ret.width=this->width+(edk::int16)n;
        ret.height=this->height+(edk::int16)n;
        ret.length=this->length+(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator+(edk::int64 n){
        //
        edk::size3i16 ret;
        ret.width=this->width+(edk::int16)n;
        ret.height=this->height+(edk::int16)n;
        ret.length=this->length+(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator+(edk::uint8 n){
        //
        edk::size3i16 ret;
        ret.width=this->width+(edk::int16)n;
        ret.height=this->height+(edk::int16)n;
        ret.length=this->length+(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator+(edk::uint16 n){
        //
        edk::size3i16 ret;
        ret.width=this->width+(edk::int16)n;
        ret.height=this->height+(edk::int16)n;
        ret.length=this->length+(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator+(edk::uint32 n){
        //
        edk::size3i16 ret;
        ret.width=this->width+(edk::int16)n;
        ret.height=this->height+(edk::int16)n;
        ret.length=this->length+(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator+(edk::uint64 n){
        //
        edk::size3i16 ret;
        ret.width=this->width+(edk::int16)n;
        ret.height=this->height+(edk::int16)n;
        ret.length=this->length+(edk::int16)n;
        return ret;
    }

    //+=
    inline void operator+=(edk::size3i8 size){
        //
        this->width+=(edk::int16)size.width;
        this->height+=(edk::int16)size.height;
        this->length+=(edk::int16)size.length;
    }
    inline void operator+=(edk::size3i16 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    inline void operator+=(edk::size2i8 size){
        //
        this->width+=(edk::int16)size.width;
        this->height+=(edk::int16)size.height;
    }
    inline void operator+=(edk::int8 n){
        //
        this->width+=(edk::int16)n;
        this->height+=(edk::int16)n;
        this->length+=(edk::int16)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->width+=(edk::int16)n;
        this->height+=(edk::int16)n;
        this->length+=(edk::int16)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->width+=(edk::int16)n;
        this->height+=(edk::int16)n;
        this->length+=(edk::int16)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->width+=(edk::int16)n;
        this->height+=(edk::int16)n;
        this->length+=(edk::int16)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->width+=(edk::int16)n;
        this->height+=(edk::int16)n;
        this->length+=(edk::int16)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->width+=(edk::int16)n;
        this->height+=(edk::int16)n;
        this->length+=(edk::int16)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->width+=(edk::int16)n;
        this->height+=(edk::int16)n;
        this->length+=(edk::int16)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->width+=(edk::int16)n;
        this->height+=(edk::int16)n;
        this->length+=(edk::int16)n;
    }

    //-
    inline edk::size3i16 operator-(edk::size3i8 size){
        //
        edk::size3i16 ret;
        ret.width=this->width-(edk::int16)size.width;
        ret.height=this->height-(edk::int16)size.height;
        ret.length=this->length-(edk::int16)size.length;
        return ret;
    }
    inline edk::size3i16 operator-(edk::size3i16 size){
        //
        edk::size3i16 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    inline edk::size3i16 operator-(edk::size2i8 size){
        //
        edk::size3i16 ret;
        ret.width=this->width-(edk::int16)size.width;
        ret.height=this->height-(edk::int16)size.height;
        return ret;
    }
    inline edk::size3i16 operator-(edk::int8 n){
        //
        edk::size3i16 ret;
        ret.width=this->width-(edk::int16)n;
        ret.height=this->height-(edk::int16)n;
        ret.length=this->length-(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator-(edk::int16 n){
        //
        edk::size3i16 ret;
        ret.width=this->width-(edk::int16)n;
        ret.height=this->height-(edk::int16)n;
        ret.length=this->length-(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator-(edk::int32 n){
        //
        edk::size3i16 ret;
        ret.width=this->width-(edk::int16)n;
        ret.height=this->height-(edk::int16)n;
        ret.length=this->length-(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator-(edk::int64 n){
        //
        edk::size3i16 ret;
        ret.width=this->width-(edk::int16)n;
        ret.height=this->height-(edk::int16)n;
        ret.length=this->length-(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator-(edk::uint8 n){
        //
        edk::size3i16 ret;
        ret.width=this->width-(edk::int16)n;
        ret.height=this->height-(edk::int16)n;
        ret.length=this->length-(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator-(edk::uint16 n){
        //
        edk::size3i16 ret;
        ret.width=this->width-(edk::int16)n;
        ret.height=this->height-(edk::int16)n;
        ret.length=this->length-(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator-(edk::uint32 n){
        //
        edk::size3i16 ret;
        ret.width=this->width-(edk::int16)n;
        ret.height=this->height-(edk::int16)n;
        ret.length=this->length-(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator-(edk::uint64 n){
        //
        edk::size3i16 ret;
        ret.width=this->width-(edk::int16)n;
        ret.height=this->height-(edk::int16)n;
        ret.length=this->length-(edk::int16)n;
        return ret;
    }

    //-=
    inline void operator-=(edk::size3i8 size){
        //
        this->width-=(edk::int16)size.width;
        this->height-=(edk::int16)size.height;
        this->length-=(edk::int16)size.length;
    }
    inline void operator-=(edk::size3i16 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    inline void operator-=(edk::size2i8 size){
        //
        this->width-=(edk::int16)size.width;
        this->height-=(edk::int16)size.height;
    }
    inline void operator-=(edk::int8 n){
        //
        this->width-=(edk::int16)n;
        this->height-=(edk::int16)n;
        this->length-=(edk::int16)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->width-=(edk::int16)n;
        this->height-=(edk::int16)n;
        this->length-=(edk::int16)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->width-=(edk::int16)n;
        this->height-=(edk::int16)n;
        this->length-=(edk::int16)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->width-=(edk::int16)n;
        this->height-=(edk::int16)n;
        this->length-=(edk::int16)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->width-=(edk::int16)n;
        this->height-=(edk::int16)n;
        this->length-=(edk::int16)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->width-=(edk::int16)n;
        this->height-=(edk::int16)n;
        this->length-=(edk::int16)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->width-=(edk::int16)n;
        this->height-=(edk::int16)n;
        this->length-=(edk::int16)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->width-=(edk::int16)n;
        this->height-=(edk::int16)n;
        this->length-=(edk::int16)n;
    }

    //*
    inline edk::size3i16 operator*(edk::size3i8 size){
        //
        edk::size3i16 ret;
        ret.width=this->width*(edk::int16)size.width;
        ret.height=this->height*(edk::int16)size.height;
        ret.length=this->length*(edk::int16)size.length;
        return ret;
    }
    inline edk::size3i16 operator*(edk::size3i16 size){
        //
        edk::size3i16 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    inline edk::size3i16 operator*(edk::size2i8 size){
        //
        edk::size3i16 ret;
        ret.width=this->width*(edk::int16)size.width;
        ret.height=this->height*(edk::int16)size.height;
        return ret;
    }
    inline edk::size3i16 operator*(edk::int8 n){
        //
        edk::size3i16 ret;
        ret.width=this->width*(edk::int16)n;
        ret.height=this->height*(edk::int16)n;
        ret.length=this->length*(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator*(edk::int16 n){
        //
        edk::size3i16 ret;
        ret.width=this->width*(edk::int16)n;
        ret.height=this->height*(edk::int16)n;
        ret.length=this->length*(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator*(edk::int32 n){
        //
        edk::size3i16 ret;
        ret.width=this->width*(edk::int16)n;
        ret.height=this->height*(edk::int16)n;
        ret.length=this->length*(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator*(edk::int64 n){
        //
        edk::size3i16 ret;
        ret.width=this->width*(edk::int16)n;
        ret.height=this->height*(edk::int16)n;
        ret.length=this->length*(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator*(edk::uint8 n){
        //
        edk::size3i16 ret;
        ret.width=this->width*(edk::int16)n;
        ret.height=this->height*(edk::int16)n;
        ret.length=this->length*(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator*(edk::uint16 n){
        //
        edk::size3i16 ret;
        ret.width=this->width*(edk::int16)n;
        ret.height=this->height*(edk::int16)n;
        ret.length=this->length*(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator*(edk::uint32 n){
        //
        edk::size3i16 ret;
        ret.width=this->width*(edk::int16)n;
        ret.height=this->height*(edk::int16)n;
        ret.length=this->length*(edk::int16)n;
        return ret;
    }
    inline edk::size3i16 operator*(edk::uint64 n){
        //
        edk::size3i16 ret;
        ret.width=this->width*(edk::int16)n;
        ret.height=this->height*(edk::int16)n;
        ret.length=this->length*(edk::int16)n;
        return ret;
    }

    //*=
    inline void operator*=(edk::size3i8 size){
        //
        this->width*=(edk::int16)size.width;
        this->height*=(edk::int16)size.height;
        this->length*=(edk::int16)size.length;
    }
    inline void operator*=(edk::size3i16 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    inline void operator*=(edk::size2i8 size){
        //
        this->width*=(edk::int16)size.width;
        this->height*=(edk::int16)size.height;
    }
    inline void operator*=(edk::int8 n){
        //
        this->width*=(edk::int16)n;
        this->height*=(edk::int16)n;
        this->length*=(edk::int16)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->width*=(edk::int16)n;
        this->height*=(edk::int16)n;
        this->length*=(edk::int16)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->width*=(edk::int16)n;
        this->height*=(edk::int16)n;
        this->length*=(edk::int16)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->width*=(edk::int16)n;
        this->height*=(edk::int16)n;
        this->length*=(edk::int16)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->width*=(edk::int16)n;
        this->height*=(edk::int16)n;
        this->length*=(edk::int16)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->width*=(edk::int16)n;
        this->height*=(edk::int16)n;
        this->length*=(edk::int16)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->width*=(edk::int16)n;
        this->height*=(edk::int16)n;
        this->length*=(edk::int16)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->width*=(edk::int16)n;
        this->height*=(edk::int16)n;
        this->length*=(edk::int16)n;
    }

    //++
    inline edk::size3i16 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return edk::size3i16(this->width,this->height,this->length);
    }
    inline edk::size3i16 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return edk::size3i16(this->width,this->height,this->length);
    }

    //--
    inline edk::size3i16 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return edk::size3i16(this->width,this->height,this->length);
    }
    inline edk::size3i16 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return edk::size3i16(this->width,this->height,this->length);
    }

    //
    inline edk::size3i16 operator()(edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i16((edk::int16)this->width,(edk::int16)this->height,(edk::int16)this->length);
    }
    inline edk::size3i16 operator()(edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i16((edk::int16)this->width,(edk::int16)this->height,(edk::int16)this->length);
    }
    inline edk::size3i16 operator()(edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i16((edk::int16)this->width,(edk::int16)this->height,(edk::int16)this->length);
    }
    inline edk::size3i16 operator()(edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i16((edk::int16)this->width,(edk::int16)this->height,(edk::int16)this->length);
    }
    inline edk::size3i16 operator()(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i16((edk::int16)this->width,(edk::int16)this->height,(edk::int16)this->length);
    }
    inline edk::size3i16 operator()(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i16((edk::int16)this->width,(edk::int16)this->height,(edk::int16)this->length);
    }
    inline edk::size3i16 operator()(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i16((edk::int16)this->width,(edk::int16)this->height,(edk::int16)this->length);
    }
    inline edk::size3i16 operator()(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i16((edk::int16)this->width,(edk::int16)this->height,(edk::int16)this->length);
    }
};

//size3i32
class size3i32{
    //
public:
    edk::int32 width,height,length;

    //CONSTRUTOR
    size3i32(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3i32(edk::int8 width,edk::int8 height,edk::int8 length){
        //zera as variaveis
        this->width=(edk::int32)width;
        this->height=(edk::int32)height;
        this->length=(edk::int32)length;
    }
    size3i32(edk::int16 width,edk::int16 height,edk::int16 length){
        //zera as variaveis
        this->width=(edk::int32)width;
        this->height=(edk::int32)height;
        this->length=(edk::int32)length;
    }
    size3i32(edk::int32 width,edk::int32 height,edk::int32 length){
        //zera as variaveis
        this->width=(edk::int32)width;
        this->height=(edk::int32)height;
        this->length=(edk::int32)length;
    }
    size3i32(edk::int64 width,edk::int64 height,edk::int64 length){
        //zera as variaveis
        this->width=(edk::int32)width;
        this->height=(edk::int32)height;
        this->length=(edk::int32)length;
    }
    size3i32(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //zera as variaveis
        this->width=(edk::int32)width;
        this->height=(edk::int32)height;
        this->length=(edk::int32)length;
    }
    size3i32(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //zera as variaveis
        this->width=(edk::int32)width;
        this->height=(edk::int32)height;
        this->length=(edk::int32)length;
    }
    size3i32(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //zera as variaveis
        this->width=(edk::int32)width;
        this->height=(edk::int32)height;
        this->length=(edk::int32)length;
    }
    size3i32(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //zera as variaveis
        this->width=(edk::int32)width;
        this->height=(edk::int32)height;
        this->length=(edk::int32)length;
    }
    size3i32(edk::int8 size){
        //zera as variaveis
        this->width=(edk::int32)size;
        this->height=(edk::int32)size;
        this->length=(edk::int32)size;
    }
    size3i32(edk::int16 size){
        //zera as variaveis
        this->width=(edk::int32)size;
        this->height=(edk::int32)size;
        this->length=(edk::int32)size;
    }
    size3i32(edk::int32 size){
        //zera as variaveis
        this->width=(edk::int32)size;
        this->height=(edk::int32)size;
        this->length=(edk::int32)size;
    }
    size3i32(edk::int64 size){
        //zera as variaveis
        this->width=(edk::int32)size;
        this->height=(edk::int32)size;
        this->length=(edk::int32)size;
    }
    size3i32(edk::uint8 size){
        //zera as variaveis
        this->width=(edk::int32)size;
        this->height=(edk::int32)size;
        this->length=(edk::int32)size;
    }
    size3i32(edk::uint16 size){
        //zera as variaveis
        this->width=(edk::int32)size;
        this->height=(edk::int32)size;
        this->length=(edk::int32)size;
    }
    size3i32(edk::uint32 size){
        //zera as variaveis
        this->width=(edk::int32)size;
        this->height=(edk::int32)size;
        this->length=(edk::int32)size;
    }
    size3i32(edk::uint64 size){
        //zera as variaveis
        this->width=(edk::int32)size;
        this->height=(edk::int32)size;
        this->length=(edk::int32)size;
    }
    //operators

    //=
    inline edk::size3i32 operator=(edk::size3i8 size){
        //
        this->width=(edk::int32)size.width;
        this->height=(edk::int32)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3i32 operator=(edk::size3i16 size){
        //
        this->width=(edk::int32)size.width;
        this->height=(edk::int32)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3i32 operator=(edk::size3i32 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3i32 operator=(edk::size2i8 size){
        //
        this->width=(edk::int32)size.width;
        this->height=(edk::int32)size.height;
        this->length=(edk::int32)0;
        return *this;
    }
    inline edk::size3i32 operator=(edk::int8 n){
        //
        this->width=(edk::int32)n;
        this->height=(edk::int32)n;
        this->length=(edk::int32)n;
        return *this;
    }
    inline edk::size3i32 operator=(edk::int16 n){
        //
        this->width=(edk::int32)n;
        this->height=(edk::int32)n;
        this->length=(edk::int32)n;
        return *this;
    }
    inline edk::size3i32 operator=(edk::int32 n){
        //
        this->width=(edk::int32)n;
        this->height=(edk::int32)n;
        this->length=(edk::int32)n;
        return *this;
    }
    inline edk::size3i32 operator=(edk::int64 n){
        //
        this->width=(edk::int32)n;
        this->height=(edk::int32)n;
        this->length=(edk::int32)n;
        return *this;
    }
    inline edk::size3i32 operator=(edk::uint8 n){
        //
        this->width=(edk::int32)n;
        this->height=(edk::int32)n;
        this->length=(edk::int32)n;
        return *this;
    }
    inline edk::size3i32 operator=(edk::uint16 n){
        //
        this->width=(edk::int32)n;
        this->height=(edk::int32)n;
        this->length=(edk::int32)n;
        return *this;
    }
    inline edk::size3i32 operator=(edk::uint32 n){
        //
        this->width=(edk::int32)n;
        this->height=(edk::int32)n;
        this->length=(edk::int32)n;
        return *this;
    }
    inline edk::size3i32 operator=(edk::uint64 n){
        //
        this->width=(edk::int32)n;
        this->height=(edk::int32)n;
        this->length=(edk::int32)n;
        return *this;
    }

    //==
    inline bool operator==(edk::size3i8 size){
        //
        return (this->width==(edk::int32)size.width&&this->height==(edk::int32)size.height&&this->length==(edk::int32)size.length);
    }
    inline bool operator==(edk::size3i16 size){
        //
        return (this->width==(edk::int32)size.width&&this->height==(edk::int32)size.height&&this->length==(edk::int32)size.length);
    }
    inline bool operator==(edk::size3i32 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    inline bool operator!=(edk::size3i8 size){
        //
        return (this->width!=(edk::int32)size.width||this->height!=(edk::int32)size.height||this->length!=(edk::int32)size.length);
    }
    inline bool operator!=(edk::size3i16 size){
        //
        return (this->width!=(edk::int32)size.width||this->height!=(edk::int32)size.height||this->length!=(edk::int32)size.length);
    }
    inline bool operator!=(edk::size3i32 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    inline edk::size3i32 operator+(edk::size3i8 size){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)size.width;
        ret.height=this->height+(edk::int32)size.height;
        ret.length=this->length+(edk::int32)size.length;
        return ret;
    }
    inline edk::size3i32 operator+(edk::size3i16 size){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)size.width;
        ret.height=this->height+(edk::int32)size.height;
        ret.length=this->length+(edk::int32)size.length;
        return ret;
    }
    inline edk::size3i32 operator+(edk::size3i32 size){
        //
        edk::size3i32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    inline edk::size3i32 operator+(edk::size2i8 size){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)size.width;
        ret.height=this->height+(edk::int32)size.height;
        return ret;
    }
    inline edk::size3i32 operator+(edk::int8 n){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)n;
        ret.height=this->height+(edk::int32)n;
        ret.length=this->length+(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator+(edk::int16 n){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)n;
        ret.height=this->height+(edk::int32)n;
        ret.length=this->length+(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator+(edk::int32 n){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)n;
        ret.height=this->height+(edk::int32)n;
        ret.length=this->length+(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator+(edk::int64 n){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)n;
        ret.height=this->height+(edk::int32)n;
        ret.length=this->length+(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator+(edk::uint8 n){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)n;
        ret.height=this->height+(edk::int32)n;
        ret.length=this->length+(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator+(edk::uint16 n){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)n;
        ret.height=this->height+(edk::int32)n;
        ret.length=this->length+(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator+(edk::uint32 n){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)n;
        ret.height=this->height+(edk::int32)n;
        ret.length=this->length+(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator+(edk::uint64 n){
        //
        edk::size3i32 ret;
        ret.width=this->width+(edk::int32)n;
        ret.height=this->height+(edk::int32)n;
        ret.length=this->length+(edk::int32)n;
        return ret;
    }

    //+=
    inline void operator+=(edk::size3i8 size){
        //
        this->width+=(edk::int32)size.width;
        this->height+=(edk::int32)size.height;
        this->length+=(edk::int32)size.length;
    }
    inline void operator+=(edk::size3i16 size){
        //
        this->width+=(edk::int32)size.width;
        this->height+=(edk::int32)size.height;
        this->length+=(edk::int32)size.length;
    }
    inline void operator+=(edk::size3i32 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    inline void operator+=(edk::size2i8 size){
        //
        this->width+=(edk::int32)size.width;
        this->height+=(edk::int32)size.height;
    }
    inline void operator+=(edk::int8 n){
        //
        this->width+=(edk::int32)n;
        this->height+=(edk::int32)n;
        this->length+=(edk::int32)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->width+=(edk::int32)n;
        this->height+=(edk::int32)n;
        this->length+=(edk::int32)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->width+=(edk::int32)n;
        this->height+=(edk::int32)n;
        this->length+=(edk::int32)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->width+=(edk::int32)n;
        this->height+=(edk::int32)n;
        this->length+=(edk::int32)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->width+=(edk::int32)n;
        this->height+=(edk::int32)n;
        this->length+=(edk::int32)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->width+=(edk::int32)n;
        this->height+=(edk::int32)n;
        this->length+=(edk::int32)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->width+=(edk::int32)n;
        this->height+=(edk::int32)n;
        this->length+=(edk::int32)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->width+=(edk::int32)n;
        this->height+=(edk::int32)n;
        this->length+=(edk::int32)n;
    }

    //-
    inline edk::size3i32 operator-(edk::size3i8 size){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)size.width;
        ret.height=this->height-(edk::int32)size.height;
        ret.length=this->length-(edk::int32)size.length;
        return ret;
    }
    inline edk::size3i32 operator-(edk::size3i16 size){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)size.width;
        ret.height=this->height-(edk::int32)size.height;
        ret.length=this->length-(edk::int32)size.length;
        return ret;
    }
    inline edk::size3i32 operator-(edk::size3i32 size){
        //
        edk::size3i32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    inline edk::size3i32 operator-(edk::size2i8 size){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)size.width;
        ret.height=this->height-(edk::int32)size.height;
        return ret;
    }
    inline edk::size3i32 operator-(edk::int8 n){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)n;
        ret.height=this->height-(edk::int32)n;
        ret.length=this->length-(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator-(edk::int16 n){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)n;
        ret.height=this->height-(edk::int32)n;
        ret.length=this->length-(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator-(edk::int32 n){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)n;
        ret.height=this->height-(edk::int32)n;
        ret.length=this->length-(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator-(edk::int64 n){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)n;
        ret.height=this->height-(edk::int32)n;
        ret.length=this->length-(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator-(edk::uint8 n){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)n;
        ret.height=this->height-(edk::int32)n;
        ret.length=this->length-(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator-(edk::uint16 n){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)n;
        ret.height=this->height-(edk::int32)n;
        ret.length=this->length-(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator-(edk::uint32 n){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)n;
        ret.height=this->height-(edk::int32)n;
        ret.length=this->length-(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator-(edk::uint64 n){
        //
        edk::size3i32 ret;
        ret.width=this->width-(edk::int32)n;
        ret.height=this->height-(edk::int32)n;
        ret.length=this->length-(edk::int32)n;
        return ret;
    }

    //-=
    inline void operator-=(edk::size3i8 size){
        //
        this->width-=(edk::int32)size.width;
        this->height-=(edk::int32)size.height;
        this->length-=(edk::int32)size.length;
    }
    inline void operator-=(edk::size3i16 size){
        //
        this->width-=(edk::int32)size.width;
        this->height-=(edk::int32)size.height;
        this->length-=(edk::int32)size.length;
    }
    inline void operator-=(edk::size3i32 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    inline void operator-=(edk::size2i8 size){
        //
        this->width-=(edk::int32)size.width;
        this->height-=(edk::int32)size.height;
    }
    inline void operator-=(edk::int8 n){
        //
        this->width-=(edk::int32)n;
        this->height-=(edk::int32)n;
        this->length-=(edk::int32)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->width-=(edk::int32)n;
        this->height-=(edk::int32)n;
        this->length-=(edk::int32)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->width-=(edk::int32)n;
        this->height-=(edk::int32)n;
        this->length-=(edk::int32)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->width-=(edk::int32)n;
        this->height-=(edk::int32)n;
        this->length-=(edk::int32)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->width-=(edk::int32)n;
        this->height-=(edk::int32)n;
        this->length-=(edk::int32)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->width-=(edk::int32)n;
        this->height-=(edk::int32)n;
        this->length-=(edk::int32)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->width-=(edk::int32)n;
        this->height-=(edk::int32)n;
        this->length-=(edk::int32)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->width-=(edk::int32)n;
        this->height-=(edk::int32)n;
        this->length-=(edk::int32)n;
    }

    //*
    inline edk::size3i32 operator*(edk::size3i8 size){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)size.width;
        ret.height=this->height*(edk::int32)size.height;
        ret.length=this->length*(edk::int32)size.length;
        return ret;
    }
    inline edk::size3i32 operator*(edk::size3i16 size){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)size.width;
        ret.height=this->height*(edk::int32)size.height;
        ret.length=this->length*(edk::int32)size.length;
        return ret;
    }
    inline edk::size3i32 operator*(edk::size3i32 size){
        //
        edk::size3i32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    inline edk::size3i32 operator*(edk::size2i8 size){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)size.width;
        ret.height=this->height*(edk::int32)size.height;
        return ret;
    }
    inline edk::size3i32 operator*(edk::int8 n){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)n;
        ret.height=this->height*(edk::int32)n;
        ret.length=this->length*(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator*(edk::int16 n){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)n;
        ret.height=this->height*(edk::int32)n;
        ret.length=this->length*(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator*(edk::int32 n){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)n;
        ret.height=this->height*(edk::int32)n;
        ret.length=this->length*(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator*(edk::int64 n){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)n;
        ret.height=this->height*(edk::int32)n;
        ret.length=this->length*(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator*(edk::uint8 n){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)n;
        ret.height=this->height*(edk::int32)n;
        ret.length=this->length*(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator*(edk::uint16 n){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)n;
        ret.height=this->height*(edk::int32)n;
        ret.length=this->length*(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator*(edk::uint32 n){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)n;
        ret.height=this->height*(edk::int32)n;
        ret.length=this->length*(edk::int32)n;
        return ret;
    }
    inline edk::size3i32 operator*(edk::uint64 n){
        //
        edk::size3i32 ret;
        ret.width=this->width*(edk::int32)n;
        ret.height=this->height*(edk::int32)n;
        ret.length=this->length*(edk::int32)n;
        return ret;
    }

    //*=
    inline void operator*=(edk::size3i8 size){
        //
        this->width*=(edk::int32)size.width;
        this->height*=(edk::int32)size.height;
        this->length*=(edk::int32)size.length;
    }
    inline void operator*=(edk::size3i16 size){
        //
        this->width*=(edk::int32)size.width;
        this->height*=(edk::int32)size.height;
        this->length*=(edk::int32)size.length;
    }
    inline void operator*=(edk::size3i32 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    inline void operator*=(edk::size2i8 size){
        //
        this->width*=(edk::int32)size.width;
        this->height*=(edk::int32)size.height;
    }
    inline void operator*=(edk::int8 n){
        //
        this->width*=(edk::int32)n;
        this->height*=(edk::int32)n;
        this->length*=(edk::int32)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->width*=(edk::int32)n;
        this->height*=(edk::int32)n;
        this->length*=(edk::int32)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->width*=(edk::int32)n;
        this->height*=(edk::int32)n;
        this->length*=(edk::int32)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->width*=(edk::int32)n;
        this->height*=(edk::int32)n;
        this->length*=(edk::int32)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->width*=(edk::int32)n;
        this->height*=(edk::int32)n;
        this->length*=(edk::int32)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->width*=(edk::int32)n;
        this->height*=(edk::int32)n;
        this->length*=(edk::int32)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->width*=(edk::int32)n;
        this->height*=(edk::int32)n;
        this->length*=(edk::int32)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->width*=(edk::int32)n;
        this->height*=(edk::int32)n;
        this->length*=(edk::int32)n;
    }

    //++
    inline edk::size3i32 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return edk::size3i32(this->width,this->height,this->length);
    }
    inline edk::size3i32 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return edk::size3i32(this->width,this->height,this->length);
    }

    //--
    inline edk::size3i32 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return edk::size3i32(this->width,this->height,this->length);
    }
    inline edk::size3i32 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return edk::size3i32(this->width,this->height,this->length);
    }

    //
    inline edk::size3i32 operator()(edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i32((edk::int32)this->width,(edk::int32)this->height,(edk::int32)this->length);
    }
    inline edk::size3i32 operator()(edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i32((edk::int32)this->width,(edk::int32)this->height,(edk::int32)this->length);
    }
    inline edk::size3i32 operator()(edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i32((edk::int32)this->width,(edk::int32)this->height,(edk::int32)this->length);
    }
    inline edk::size3i32 operator()(edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i32((edk::int32)this->width,(edk::int32)this->height,(edk::int32)this->length);
    }
    inline edk::size3i32 operator()(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i32((edk::int32)this->width,(edk::int32)this->height,(edk::int32)this->length);
    }
    inline edk::size3i32 operator()(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i32((edk::int32)this->width,(edk::int32)this->height,(edk::int32)this->length);
    }
    inline edk::size3i32 operator()(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i32((edk::int32)this->width,(edk::int32)this->height,(edk::int32)this->length);
    }
    inline edk::size3i32 operator()(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i32((edk::int32)this->width,(edk::int32)this->height,(edk::int32)this->length);
    }
};

//size3i64
class size3i64{
    //
public:
    edk::int64 width,height,length;

    //CONSTRUTOR
    size3i64(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3i64(edk::int8 width,edk::int8 height,edk::int8 length){
        //zera as variaveis
        this->width=(edk::int64)width;
        this->height=(edk::int64)height;
        this->length=(edk::int64)length;
    }
    size3i64(edk::int16 width,edk::int16 height,edk::int16 length){
        //zera as variaveis
        this->width=(edk::int64)width;
        this->height=(edk::int64)height;
        this->length=(edk::int64)length;
    }
    size3i64(edk::int32 width,edk::int32 height,edk::int32 length){
        //zera as variaveis
        this->width=(edk::int64)width;
        this->height=(edk::int64)height;
        this->length=(edk::int64)length;
    }
    size3i64(edk::int64 width,edk::int64 height,edk::int64 length){
        //zera as variaveis
        this->width=(edk::int64)width;
        this->height=(edk::int64)height;
        this->length=(edk::int64)length;
    }
    size3i64(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //zera as variaveis
        this->width=(edk::int64)width;
        this->height=(edk::int64)height;
        this->length=(edk::int64)length;
    }
    size3i64(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //zera as variaveis
        this->width=(edk::int64)width;
        this->height=(edk::int64)height;
        this->length=(edk::int64)length;
    }
    size3i64(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //zera as variaveis
        this->width=(edk::int64)width;
        this->height=(edk::int64)height;
        this->length=(edk::int64)length;
    }
    size3i64(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //zera as variaveis
        this->width=(edk::int64)width;
        this->height=(edk::int64)height;
        this->length=(edk::int64)length;
    }
    size3i64(edk::int8 size){
        //zera as variaveis
        this->width=(edk::int64)size;
        this->height=(edk::int64)size;
        this->length=(edk::int64)size;
    }
    size3i64(edk::int16 size){
        //zera as variaveis
        this->width=(edk::int64)size;
        this->height=(edk::int64)size;
        this->length=(edk::int64)size;
    }
    size3i64(edk::int32 size){
        //zera as variaveis
        this->width=(edk::int64)size;
        this->height=(edk::int64)size;
        this->length=(edk::int64)size;
    }
    size3i64(edk::int64 size){
        //zera as variaveis
        this->width=(edk::int64)size;
        this->height=(edk::int64)size;
        this->length=(edk::int64)size;
    }
    size3i64(edk::uint8 size){
        //zera as variaveis
        this->width=(edk::int64)size;
        this->height=(edk::int64)size;
        this->length=(edk::int64)size;
    }
    size3i64(edk::uint16 size){
        //zera as variaveis
        this->width=(edk::int64)size;
        this->height=(edk::int64)size;
        this->length=(edk::int64)size;
    }
    size3i64(edk::uint32 size){
        //zera as variaveis
        this->width=(edk::int64)size;
        this->height=(edk::int64)size;
        this->length=(edk::int64)size;
    }
    size3i64(edk::uint64 size){
        //zera as variaveis
        this->width=(edk::int64)size;
        this->height=(edk::int64)size;
        this->length=(edk::int64)size;
    }
    //operators

    //=
    inline edk::size3i64 operator=(edk::size3i8 size){
        //
        this->width=(edk::int64)size.width;
        this->height=(edk::int64)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3i64 operator=(edk::size3i16 size){
        //
        this->width=(edk::int64)size.width;
        this->height=(edk::int64)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3i64 operator=(edk::size3i32 size){
        //
        this->width=(edk::int64)size.width;
        this->height=(edk::int64)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3i64 operator=(edk::size3i64 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3i64 operator=(edk::size2i8 size){
        //
        this->width=(edk::int64)size.width;
        this->height=(edk::int64)size.height;
        this->length=(edk::int64)0;
        return *this;
    }
    inline edk::size3i64 operator=(edk::int8 n){
        //
        this->width=(edk::int64)n;
        this->height=(edk::int64)n;
        this->length=(edk::int64)n;
        return *this;
    }
    inline edk::size3i64 operator=(edk::int16 n){
        //
        this->width=(edk::int64)n;
        this->height=(edk::int64)n;
        this->length=(edk::int64)n;
        return *this;
    }
    inline edk::size3i64 operator=(edk::int32 n){
        //
        this->width=(edk::int64)n;
        this->height=(edk::int64)n;
        this->length=(edk::int64)n;
        return *this;
    }
    inline edk::size3i64 operator=(edk::int64 n){
        //
        this->width=(edk::int64)n;
        this->height=(edk::int64)n;
        this->length=(edk::int64)n;
        return *this;
    }
    inline edk::size3i64 operator=(edk::uint8 n){
        //
        this->width=(edk::int64)n;
        this->height=(edk::int64)n;
        this->length=(edk::int64)n;
        return *this;
    }
    inline edk::size3i64 operator=(edk::uint16 n){
        //
        this->width=(edk::int64)n;
        this->height=(edk::int64)n;
        this->length=(edk::int64)n;
        return *this;
    }
    inline edk::size3i64 operator=(edk::uint32 n){
        //
        this->width=(edk::int64)n;
        this->height=(edk::int64)n;
        this->length=(edk::int64)n;
        return *this;
    }
    inline edk::size3i64 operator=(edk::uint64 n){
        //
        this->width=(edk::int64)n;
        this->height=(edk::int64)n;
        this->length=(edk::int64)n;
        return *this;
    }

    //==
    inline bool operator==(edk::size3i8 size){
        //
        return (this->width==(edk::int64)size.width&&this->height==(edk::int64)size.height&&this->length==(edk::int64)size.length);
    }
    inline bool operator==(edk::size3i16 size){
        //
        return (this->width==(edk::int64)size.width&&this->height==(edk::int64)size.height&&this->length==(edk::int64)size.length);
    }
    inline bool operator==(edk::size3i32 size){
        //
        return (this->width==(edk::int64)size.width&&this->height==(edk::int64)size.height&&this->length==(edk::int64)size.length);
    }
    inline bool operator==(edk::size3i64 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    inline bool operator!=(edk::size3i8 size){
        //
        return (this->width!=(edk::int64)size.width||this->height!=(edk::int64)size.height||this->length!=(edk::int64)size.length);
    }
    inline bool operator!=(edk::size3i16 size){
        //
        return (this->width!=(edk::int64)size.width||this->height!=(edk::int64)size.height||this->length!=(edk::int64)size.length);
    }
    inline bool operator!=(edk::size3i32 size){
        //
        return (this->width!=(edk::int64)size.width||this->height!=(edk::int64)size.height||this->length!=(edk::int64)size.length);
    }
    inline bool operator!=(edk::size3i64 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    inline edk::size3i64 operator+(edk::size3i8 size){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)size.width;
        ret.height=this->height+(edk::int64)size.height;
        ret.length=this->length+(edk::int64)size.length;
        return ret;
    }
    inline edk::size3i64 operator+(edk::size3i16 size){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)size.width;
        ret.height=this->height+(edk::int64)size.height;
        ret.length=this->length+(edk::int64)size.length;
        return ret;
    }
    inline edk::size3i64 operator+(edk::size3i32 size){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)size.width;
        ret.height=this->height+(edk::int64)size.height;
        ret.length=this->length+(edk::int64)size.length;
        return ret;
    }
    inline edk::size3i64 operator+(edk::size3i64 size){
        //
        edk::size3i64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    inline edk::size3i64 operator+(edk::size2i8 size){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)size.width;
        ret.height=this->height+(edk::int64)size.height;
        return ret;
    }
    inline edk::size3i64 operator+(edk::int8 n){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)n;
        ret.height=this->height+(edk::int64)n;
        ret.length=this->length+(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator+(edk::int16 n){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)n;
        ret.height=this->height+(edk::int64)n;
        ret.length=this->length+(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator+(edk::int32 n){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)n;
        ret.height=this->height+(edk::int64)n;
        ret.length=this->length+(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator+(edk::int64 n){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)n;
        ret.height=this->height+(edk::int64)n;
        ret.length=this->length+(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator+(edk::uint8 n){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)n;
        ret.height=this->height+(edk::int64)n;
        ret.length=this->length+(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator+(edk::uint16 n){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)n;
        ret.height=this->height+(edk::int64)n;
        ret.length=this->length+(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator+(edk::uint32 n){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)n;
        ret.height=this->height+(edk::int64)n;
        ret.length=this->length+(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator+(edk::uint64 n){
        //
        edk::size3i64 ret;
        ret.width=this->width+(edk::int64)n;
        ret.height=this->height+(edk::int64)n;
        ret.length=this->length+(edk::int64)n;
        return ret;
    }

    //+=
    inline void operator+=(edk::size3i8 size){
        //
        this->width+=(edk::int64)size.width;
        this->height+=(edk::int64)size.height;
        this->length+=(edk::int64)size.length;
    }
    inline void operator+=(edk::size3i16 size){
        //
        this->width+=(edk::int64)size.width;
        this->height+=(edk::int64)size.height;
        this->length+=(edk::int64)size.length;
    }
    inline void operator+=(edk::size3i32 size){
        //
        this->width+=(edk::int64)size.width;
        this->height+=(edk::int64)size.height;
        this->length+=(edk::int64)size.length;
    }
    inline void operator+=(edk::size3i64 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    inline void operator+=(edk::size2i8 size){
        //
        this->width+=(edk::int64)size.width;
        this->height+=(edk::int64)size.height;
    }
    inline void operator+=(edk::int8 n){
        //
        this->width+=(edk::int64)n;
        this->height+=(edk::int64)n;
        this->length+=(edk::int64)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->width+=(edk::int64)n;
        this->height+=(edk::int64)n;
        this->length+=(edk::int64)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->width+=(edk::int64)n;
        this->height+=(edk::int64)n;
        this->length+=(edk::int64)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->width+=(edk::int64)n;
        this->height+=(edk::int64)n;
        this->length+=(edk::int64)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->width+=(edk::int64)n;
        this->height+=(edk::int64)n;
        this->length+=(edk::int64)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->width+=(edk::int64)n;
        this->height+=(edk::int64)n;
        this->length+=(edk::int64)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->width+=(edk::int64)n;
        this->height+=(edk::int64)n;
        this->length+=(edk::int64)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->width+=(edk::int64)n;
        this->height+=(edk::int64)n;
        this->length+=(edk::int64)n;
    }

    //-
    inline edk::size3i64 operator-(edk::size3i8 size){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)size.width;
        ret.height=this->height-(edk::int64)size.height;
        ret.length=this->length-(edk::int64)size.length;
        return ret;
    }
    inline edk::size3i64 operator-(edk::size3i16 size){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)size.width;
        ret.height=this->height-(edk::int64)size.height;
        ret.length=this->length-(edk::int64)size.length;
        return ret;
    }
    inline edk::size3i64 operator-(edk::size3i32 size){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)size.width;
        ret.height=this->height-(edk::int64)size.height;
        ret.length=this->length-(edk::int64)size.length;
        return ret;
    }
    inline edk::size3i64 operator-(edk::size3i64 size){
        //
        edk::size3i64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    inline edk::size3i64 operator-(edk::size2i8 size){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)size.width;
        ret.height=this->height-(edk::int64)size.height;
        return ret;
    }
    inline edk::size3i64 operator-(edk::int8 n){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)n;
        ret.height=this->height-(edk::int64)n;
        ret.length=this->length-(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator-(edk::int16 n){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)n;
        ret.height=this->height-(edk::int64)n;
        ret.length=this->length-(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator-(edk::int32 n){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)n;
        ret.height=this->height-(edk::int64)n;
        ret.length=this->length-(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator-(edk::int64 n){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)n;
        ret.height=this->height-(edk::int64)n;
        ret.length=this->length-(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator-(edk::uint8 n){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)n;
        ret.height=this->height-(edk::int64)n;
        ret.length=this->length-(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator-(edk::uint16 n){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)n;
        ret.height=this->height-(edk::int64)n;
        ret.length=this->length-(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator-(edk::uint32 n){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)n;
        ret.height=this->height-(edk::int64)n;
        ret.length=this->length-(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator-(edk::uint64 n){
        //
        edk::size3i64 ret;
        ret.width=this->width-(edk::int64)n;
        ret.height=this->height-(edk::int64)n;
        ret.length=this->length-(edk::int64)n;
        return ret;
    }

    //-=
    inline void operator-=(edk::size3i8 size){
        //
        this->width-=(edk::int64)size.width;
        this->height-=(edk::int64)size.height;
        this->length-=(edk::int64)size.length;
    }
    inline void operator-=(edk::size3i16 size){
        //
        this->width-=(edk::int64)size.width;
        this->height-=(edk::int64)size.height;
        this->length-=(edk::int64)size.length;
    }
    inline void operator-=(edk::size3i32 size){
        //
        this->width-=(edk::int64)size.width;
        this->height-=(edk::int64)size.height;
        this->length-=(edk::int64)size.length;
    }
    inline void operator-=(edk::size3i64 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    inline void operator-=(edk::size2i8 size){
        //
        this->width-=(edk::int64)size.width;
        this->height-=(edk::int64)size.height;
    }
    inline void operator-=(edk::int8 n){
        //
        this->width-=(edk::int64)n;
        this->height-=(edk::int64)n;
        this->length-=(edk::int64)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->width-=(edk::int64)n;
        this->height-=(edk::int64)n;
        this->length-=(edk::int64)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->width-=(edk::int64)n;
        this->height-=(edk::int64)n;
        this->length-=(edk::int64)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->width-=(edk::int64)n;
        this->height-=(edk::int64)n;
        this->length-=(edk::int64)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->width-=(edk::int64)n;
        this->height-=(edk::int64)n;
        this->length-=(edk::int64)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->width-=(edk::int64)n;
        this->height-=(edk::int64)n;
        this->length-=(edk::int64)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->width-=(edk::int64)n;
        this->height-=(edk::int64)n;
        this->length-=(edk::int64)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->width-=(edk::int64)n;
        this->height-=(edk::int64)n;
        this->length-=(edk::int64)n;
    }

    //*
    inline edk::size3i64 operator*(edk::size3i8 size){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)size.width;
        ret.height=this->height*(edk::int64)size.height;
        ret.length=this->length*(edk::int64)size.length;
        return ret;
    }
    inline edk::size3i64 operator*(edk::size3i16 size){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)size.width;
        ret.height=this->height*(edk::int64)size.height;
        ret.length=this->length*(edk::int64)size.length;
        return ret;
    }
    inline edk::size3i64 operator*(edk::size3i32 size){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)size.width;
        ret.height=this->height*(edk::int64)size.height;
        ret.length=this->length*(edk::int64)size.length;
        return ret;
    }
    inline edk::size3i64 operator*(edk::size3i64 size){
        //
        edk::size3i64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    inline edk::size3i64 operator*(edk::size2i8 size){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)size.width;
        ret.height=this->height*(edk::int64)size.height;
        return ret;
    }
    inline edk::size3i64 operator*(edk::int8 n){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)n;
        ret.height=this->height*(edk::int64)n;
        ret.length=this->length*(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator*(edk::int16 n){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)n;
        ret.height=this->height*(edk::int64)n;
        ret.length=this->length*(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator*(edk::int32 n){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)n;
        ret.height=this->height*(edk::int64)n;
        ret.length=this->length*(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator*(edk::int64 n){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)n;
        ret.height=this->height*(edk::int64)n;
        ret.length=this->length*(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator*(edk::uint8 n){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)n;
        ret.height=this->height*(edk::int64)n;
        ret.length=this->length*(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator*(edk::uint16 n){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)n;
        ret.height=this->height*(edk::int64)n;
        ret.length=this->length*(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator*(edk::uint32 n){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)n;
        ret.height=this->height*(edk::int64)n;
        ret.length=this->length*(edk::int64)n;
        return ret;
    }
    inline edk::size3i64 operator*(edk::uint64 n){
        //
        edk::size3i64 ret;
        ret.width=this->width*(edk::int64)n;
        ret.height=this->height*(edk::int64)n;
        ret.length=this->length*(edk::int64)n;
        return ret;
    }

    //*=
    inline void operator*=(edk::size3i8 size){
        //
        this->width*=(edk::int64)size.width;
        this->height*=(edk::int64)size.height;
        this->length*=(edk::int64)size.length;
    }
    inline void operator*=(edk::size3i16 size){
        //
        this->width*=(edk::int64)size.width;
        this->height*=(edk::int64)size.height;
        this->length*=(edk::int64)size.length;
    }
    inline void operator*=(edk::size3i32 size){
        //
        this->width*=(edk::int64)size.width;
        this->height*=(edk::int64)size.height;
        this->length*=(edk::int64)size.length;
    }
    inline void operator*=(edk::size3i64 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    inline void operator*=(edk::size2i8 size){
        //
        this->width*=(edk::int64)size.width;
        this->height*=(edk::int64)size.height;
    }
    inline void operator*=(edk::int8 n){
        //
        this->width*=(edk::int64)n;
        this->height*=(edk::int64)n;
        this->length*=(edk::int64)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->width*=(edk::int64)n;
        this->height*=(edk::int64)n;
        this->length*=(edk::int64)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->width*=(edk::int64)n;
        this->height*=(edk::int64)n;
        this->length*=(edk::int64)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->width*=(edk::int64)n;
        this->height*=(edk::int64)n;
        this->length*=(edk::int64)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->width*=(edk::int64)n;
        this->height*=(edk::int64)n;
        this->length*=(edk::int64)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->width*=(edk::int64)n;
        this->height*=(edk::int64)n;
        this->length*=(edk::int64)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->width*=(edk::int64)n;
        this->height*=(edk::int64)n;
        this->length*=(edk::int64)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->width*=(edk::int64)n;
        this->height*=(edk::int64)n;
        this->length*=(edk::int64)n;
    }

    //++
    inline edk::size3i64 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return edk::size3i64(this->width,this->height,this->length);
    }
    inline edk::size3i64 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return edk::size3i64(this->width,this->height,this->length);
    }

    //--
    inline edk::size3i64 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return edk::size3i64(this->width,this->height,this->length);
    }
    inline edk::size3i64 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return edk::size3i64(this->width,this->height,this->length);
    }

    //
    inline edk::size3i64 operator()(edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i64((edk::int64)this->width,(edk::int64)this->height,(edk::int64)this->length);
    }
    inline edk::size3i64 operator()(edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i64((edk::int64)this->width,(edk::int64)this->height,(edk::int64)this->length);
    }
    inline edk::size3i64 operator()(edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i64((edk::int64)this->width,(edk::int64)this->height,(edk::int64)this->length);
    }
    inline edk::size3i64 operator()(edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i64((edk::int64)this->width,(edk::int64)this->height,(edk::int64)this->length);
    }
    inline edk::size3i64 operator()(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i64((edk::int64)this->width,(edk::int64)this->height,(edk::int64)this->length);
    }
    inline edk::size3i64 operator()(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i64((edk::int64)this->width,(edk::int64)this->height,(edk::int64)this->length);
    }
    inline edk::size3i64 operator()(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i64((edk::int64)this->width,(edk::int64)this->height,(edk::int64)this->length);
    }
    inline edk::size3i64 operator()(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3i64((edk::int64)this->width,(edk::int64)this->height,(edk::int64)this->length);
    }
};

//size3ui8
class size3ui8{
    //
public:
    edk::uint8 width,height,length;

    //CONSTRUTOR
    size3ui8(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3ui8(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //zera as variaveis
        this->width=(edk::uint8)width;
        this->height=(edk::uint8)height;
        this->length=(edk::uint8)length;
    }
    size3ui8(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //zera as variaveis
        this->width=(edk::uint8)width;
        this->height=(edk::uint8)height;
        this->length=(edk::uint8)length;
    }
    size3ui8(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //zera as variaveis
        this->width=(edk::uint8)width;
        this->height=(edk::uint8)height;
        this->length=(edk::uint8)length;
    }
    size3ui8(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //zera as variaveis
        this->width=(edk::uint8)width;
        this->height=(edk::uint8)height;
        this->length=(edk::uint8)length;
    }
    size3ui8(edk::uint8 size){
        //zera as variaveis
        this->width=(edk::uint8)size;
        this->height=(edk::uint8)size;
        this->length=(edk::uint8)size;
    }
    size3ui8(edk::uint16 size){
        //zera as variaveis
        this->width=(edk::uint8)size;
        this->height=(edk::uint8)size;
        this->length=(edk::uint8)size;
    }
    size3ui8(edk::uint32 size){
        //zera as variaveis
        this->width=(edk::uint8)size;
        this->height=(edk::uint8)size;
        this->length=(edk::uint8)size;
    }
    size3ui8(edk::uint64 size){
        //zera as variaveis
        this->width=(edk::uint8)size;
        this->height=(edk::uint8)size;
        this->length=(edk::uint8)size;
    }
    //operators

    //=
    inline edk::size3ui8 operator=(edk::size3ui8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3ui8 operator=(edk::size2i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=(edk::uint8)0;
        return *this;
    }
    inline edk::size3ui8 operator=(edk::uint8 n){
        //
        this->width=(edk::uint8)n;
        this->height=(edk::uint8)n;
        this->length=(edk::uint8)n;
        return *this;
    }
    inline edk::size3ui8 operator=(edk::uint16 n){
        //
        this->width=(edk::uint8)n;
        this->height=(edk::uint8)n;
        this->length=(edk::uint8)n;
        return *this;
    }
    inline edk::size3ui8 operator=(edk::uint32 n){
        //
        this->width=(edk::uint8)n;
        this->height=(edk::uint8)n;
        this->length=(edk::uint8)n;
        return *this;
    }
    inline edk::size3ui8 operator=(edk::uint64 n){
        //
        this->width=(edk::uint8)n;
        this->height=(edk::uint8)n;
        this->length=(edk::uint8)n;
        return *this;
    }

    //==
    inline bool operator==(edk::size3ui8 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    inline bool operator!=(edk::size3ui8 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    inline edk::size3ui8 operator+(edk::size3ui8 size){
        //
        edk::size3ui8 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    inline edk::size3ui8 operator+(edk::size2i8 size){
        //
        edk::size3ui8 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    inline edk::size3ui8 operator+(edk::uint8 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width+(edk::uint8)n;
        ret.height=this->height+(edk::uint8)n;
        ret.length=this->length+(edk::uint8)n;
        return ret;
    }
    inline edk::size3ui8 operator+(edk::uint16 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width+(edk::uint8)n;
        ret.height=this->height+(edk::uint8)n;
        ret.length=this->length+(edk::uint8)n;
        return ret;
    }
    inline edk::size3ui8 operator+(edk::uint32 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width+(edk::uint8)n;
        ret.height=this->height+(edk::uint8)n;
        ret.length=this->length+(edk::uint8)n;
        return ret;
    }
    inline edk::size3ui8 operator+(edk::uint64 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width+(edk::uint8)n;
        ret.height=this->height+(edk::uint8)n;
        ret.length=this->length+(edk::uint8)n;
        return ret;
    }

    //+=
    inline void operator+=(edk::size3ui8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    inline void operator+=(edk::size2i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->width+=(edk::uint8)n;
        this->height+=(edk::uint8)n;
        this->length+=(edk::uint8)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->width+=(edk::uint8)n;
        this->height+=(edk::uint8)n;
        this->length+=(edk::uint8)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->width+=(edk::uint8)n;
        this->height+=(edk::uint8)n;
        this->length+=(edk::uint8)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->width+=(edk::uint8)n;
        this->height+=(edk::uint8)n;
        this->length+=(edk::uint8)n;
    }

    //-
    inline edk::size3ui8 operator-(edk::size3ui8 size){
        //
        edk::size3ui8 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    inline edk::size3ui8 operator-(edk::size2i8 size){
        //
        edk::size3ui8 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    inline edk::size3ui8 operator-(edk::uint8 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width-(edk::uint8)n;
        ret.height=this->height-(edk::uint8)n;
        ret.length=this->length-(edk::uint8)n;
        return ret;
    }
    inline edk::size3ui8 operator-(edk::uint16 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width-(edk::uint8)n;
        ret.height=this->height-(edk::uint8)n;
        ret.length=this->length-(edk::uint8)n;
        return ret;
    }
    inline edk::size3ui8 operator-(edk::uint32 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width-(edk::uint8)n;
        ret.height=this->height-(edk::uint8)n;
        ret.length=this->length-(edk::uint8)n;
        return ret;
    }
    inline edk::size3ui8 operator-(edk::uint64 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width-(edk::uint8)n;
        ret.height=this->height-(edk::uint8)n;
        ret.length=this->length-(edk::uint8)n;
        return ret;
    }

    //-=
    inline void operator-=(edk::size3ui8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    inline void operator-=(edk::size2i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->width-=(edk::uint8)n;
        this->height-=(edk::uint8)n;
        this->length-=(edk::uint8)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->width-=(edk::uint8)n;
        this->height-=(edk::uint8)n;
        this->length-=(edk::uint8)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->width-=(edk::uint8)n;
        this->height-=(edk::uint8)n;
        this->length-=(edk::uint8)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->width-=(edk::uint8)n;
        this->height-=(edk::uint8)n;
        this->length-=(edk::uint8)n;
    }

    //*
    inline edk::size3ui8 operator*(edk::size3ui8 size){
        //
        edk::size3ui8 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    inline edk::size3ui8 operator*(edk::size2i8 size){
        //
        edk::size3ui8 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    inline edk::size3ui8 operator*(edk::uint8 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width*(edk::uint8)n;
        ret.height=this->height*(edk::uint8)n;
        ret.length=this->length*(edk::uint8)n;
        return ret;
    }
    inline edk::size3ui8 operator*(edk::uint16 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width*(edk::uint8)n;
        ret.height=this->height*(edk::uint8)n;
        ret.length=this->length*(edk::uint8)n;
        return ret;
    }
    inline edk::size3ui8 operator*(edk::uint32 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width*(edk::uint8)n;
        ret.height=this->height*(edk::uint8)n;
        ret.length=this->length*(edk::uint8)n;
        return ret;
    }
    inline edk::size3ui8 operator*(edk::uint64 n){
        //
        edk::size3ui8 ret;
        ret.width=this->width*(edk::uint8)n;
        ret.height=this->height*(edk::uint8)n;
        ret.length=this->length*(edk::uint8)n;
        return ret;
    }

    //*=
    inline void operator*=(edk::size3ui8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    inline void operator*=(edk::size2i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->width*=(edk::uint8)n;
        this->height*=(edk::uint8)n;
        this->length*=(edk::uint8)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->width*=(edk::uint8)n;
        this->height*=(edk::uint8)n;
        this->length*=(edk::uint8)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->width*=(edk::uint8)n;
        this->height*=(edk::uint8)n;
        this->length*=(edk::uint8)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->width*=(edk::uint8)n;
        this->height*=(edk::uint8)n;
        this->length*=(edk::uint8)n;
    }

    //++
    inline edk::size3ui8 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return edk::size3ui8(this->width,this->height,this->length);
    }
    inline edk::size3ui8 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return edk::size3ui8(this->width,this->height,this->length);
    }

    //--
    inline edk::size3ui8 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return edk::size3ui8(this->width,this->height,this->length);
    }
    inline edk::size3ui8 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return edk::size3ui8(this->width,this->height,this->length);
    }

    //
    inline edk::size3ui8 operator()(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui8((edk::uint8)this->width,(edk::uint8)this->height,(edk::uint8)this->length);
    }
    inline edk::size3ui8 operator()(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui8((edk::uint8)this->width,(edk::uint8)this->height,(edk::uint8)this->length);
    }
    inline edk::size3ui8 operator()(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui8((edk::uint8)this->width,(edk::uint8)this->height,(edk::uint8)this->length);
    }
    inline edk::size3ui8 operator()(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui8((edk::uint8)this->width,(edk::uint8)this->height,(edk::uint8)this->length);
    }
};

//size3ui16
class size3ui16{
    //
public:
    edk::uint16 width,height,length;

    //CONSTRUTOR
    size3ui16(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3ui16(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //zera as variaveis
        this->width=(edk::uint16)width;
        this->height=(edk::uint16)height;
        this->length=(edk::uint16)length;
    }
    size3ui16(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //zera as variaveis
        this->width=(edk::uint16)width;
        this->height=(edk::uint16)height;
        this->length=(edk::uint16)length;
    }
    size3ui16(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //zera as variaveis
        this->width=(edk::uint16)width;
        this->height=(edk::uint16)height;
        this->length=(edk::uint16)length;
    }
    size3ui16(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //zera as variaveis
        this->width=(edk::uint16)width;
        this->height=(edk::uint16)height;
        this->length=(edk::uint16)length;
    }
    size3ui16(edk::uint8 size){
        //zera as variaveis
        this->width=(edk::uint16)size;
        this->height=(edk::uint16)size;
        this->length=(edk::uint16)size;
    }
    size3ui16(edk::uint16 size){
        //zera as variaveis
        this->width=(edk::uint16)size;
        this->height=(edk::uint16)size;
        this->length=(edk::uint16)size;
    }
    size3ui16(edk::uint32 size){
        //zera as variaveis
        this->width=(edk::uint16)size;
        this->height=(edk::uint16)size;
        this->length=(edk::uint16)size;
    }
    size3ui16(edk::uint64 size){
        //zera as variaveis
        this->width=(edk::uint16)size;
        this->height=(edk::uint16)size;
        this->length=(edk::uint16)size;
    }
    //operators

    //=
    inline edk::size3ui16 operator=(edk::size3ui8 size){
        //
        this->width=(edk::uint16)size.width;
        this->height=(edk::uint16)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3ui16 operator=(edk::size3ui16 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3ui16 operator=(edk::size2i8 size){
        //
        this->width=(edk::uint16)size.width;
        this->height=(edk::uint16)size.height;
        this->length=(edk::uint16)0;
        return *this;
    }
    inline edk::size3ui16 operator=(edk::uint8 n){
        //
        this->width=(edk::uint16)n;
        this->height=(edk::uint16)n;
        this->length=(edk::uint16)n;
        return *this;
    }
    inline edk::size3ui16 operator=(edk::uint16 n){
        //
        this->width=(edk::uint16)n;
        this->height=(edk::uint16)n;
        this->length=(edk::uint16)n;
        return *this;
    }
    inline edk::size3ui16 operator=(edk::uint32 n){
        //
        this->width=(edk::uint16)n;
        this->height=(edk::uint16)n;
        this->length=(edk::uint16)n;
        return *this;
    }
    inline edk::size3ui16 operator=(edk::uint64 n){
        //
        this->width=(edk::uint16)n;
        this->height=(edk::uint16)n;
        this->length=(edk::uint16)n;
        return *this;
    }

    //==
    inline bool operator==(edk::size3ui8 size){
        //
        return (this->width==(edk::uint16)size.width&&this->height==(edk::uint16)size.height&&this->length==(edk::uint16)size.length);
    }
    inline bool operator==(edk::size3ui16 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    inline bool operator!=(edk::size3ui8 size){
        //
        return (this->width!=(edk::uint16)size.width||this->height!=(edk::uint16)size.height||this->length!=(edk::uint16)size.length);
    }
    inline bool operator!=(edk::size3ui16 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    inline edk::size3ui16 operator+(edk::size3ui8 size){
        //
        edk::size3ui16 ret;
        ret.width=this->width+(edk::uint16)size.width;
        ret.height=this->height+(edk::uint16)size.height;
        ret.length=this->length+(edk::uint16)size.length;
        return ret;
    }
    inline edk::size3ui16 operator+(edk::size3ui16 size){
        //
        edk::size3ui16 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    inline edk::size3ui16 operator+(edk::size2i8 size){
        //
        edk::size3ui16 ret;
        ret.width=this->width+(edk::uint16)size.width;
        ret.height=this->height+(edk::uint16)size.height;
        return ret;
    }
    inline edk::size3ui16 operator+(edk::uint8 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width+(edk::uint16)n;
        ret.height=this->height+(edk::uint16)n;
        ret.length=this->length+(edk::uint16)n;
        return ret;
    }
    inline edk::size3ui16 operator+(edk::uint16 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width+(edk::uint16)n;
        ret.height=this->height+(edk::uint16)n;
        ret.length=this->length+(edk::uint16)n;
        return ret;
    }
    inline edk::size3ui16 operator+(edk::uint32 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width+(edk::uint16)n;
        ret.height=this->height+(edk::uint16)n;
        ret.length=this->length+(edk::uint16)n;
        return ret;
    }
    inline edk::size3ui16 operator+(edk::uint64 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width+(edk::uint16)n;
        ret.height=this->height+(edk::uint16)n;
        ret.length=this->length+(edk::uint16)n;
        return ret;
    }

    //+=
    inline void operator+=(edk::size3ui8 size){
        //
        this->width+=(edk::uint16)size.width;
        this->height+=(edk::uint16)size.height;
        this->length+=(edk::uint16)size.length;
    }
    inline void operator+=(edk::size3ui16 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    inline void operator+=(edk::size2i8 size){
        //
        this->width+=(edk::uint16)size.width;
        this->height+=(edk::uint16)size.height;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->width+=(edk::uint16)n;
        this->height+=(edk::uint16)n;
        this->length+=(edk::uint16)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->width+=(edk::uint16)n;
        this->height+=(edk::uint16)n;
        this->length+=(edk::uint16)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->width+=(edk::uint16)n;
        this->height+=(edk::uint16)n;
        this->length+=(edk::uint16)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->width+=(edk::uint16)n;
        this->height+=(edk::uint16)n;
        this->length+=(edk::uint16)n;
    }

    //-
    inline edk::size3ui16 operator-(edk::size3ui8 size){
        //
        edk::size3ui16 ret;
        ret.width=this->width-(edk::uint16)size.width;
        ret.height=this->height-(edk::uint16)size.height;
        ret.length=this->length-(edk::uint16)size.length;
        return ret;
    }
    inline edk::size3ui16 operator-(edk::size3ui16 size){
        //
        edk::size3ui16 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    inline edk::size3ui16 operator-(edk::size2i8 size){
        //
        edk::size3ui16 ret;
        ret.width=this->width-(edk::uint16)size.width;
        ret.height=this->height-(edk::uint16)size.height;
        return ret;
    }
    inline edk::size3ui16 operator-(edk::uint8 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width-(edk::uint16)n;
        ret.height=this->height-(edk::uint16)n;
        ret.length=this->length-(edk::uint16)n;
        return ret;
    }
    inline edk::size3ui16 operator-(edk::uint16 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width-(edk::uint16)n;
        ret.height=this->height-(edk::uint16)n;
        ret.length=this->length-(edk::uint16)n;
        return ret;
    }
    inline edk::size3ui16 operator-(edk::uint32 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width-(edk::uint16)n;
        ret.height=this->height-(edk::uint16)n;
        ret.length=this->length-(edk::uint16)n;
        return ret;
    }
    inline edk::size3ui16 operator-(edk::uint64 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width-(edk::uint16)n;
        ret.height=this->height-(edk::uint16)n;
        ret.length=this->length-(edk::uint16)n;
        return ret;
    }

    //-=
    inline void operator-=(edk::size3ui8 size){
        //
        this->width-=(edk::uint16)size.width;
        this->height-=(edk::uint16)size.height;
        this->length-=(edk::uint16)size.length;
    }
    inline void operator-=(edk::size3ui16 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    inline void operator-=(edk::size2i8 size){
        //
        this->width-=(edk::uint16)size.width;
        this->height-=(edk::uint16)size.height;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->width-=(edk::uint16)n;
        this->height-=(edk::uint16)n;
        this->length-=(edk::uint16)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->width-=(edk::uint16)n;
        this->height-=(edk::uint16)n;
        this->length-=(edk::uint16)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->width-=(edk::uint16)n;
        this->height-=(edk::uint16)n;
        this->length-=(edk::uint16)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->width-=(edk::uint16)n;
        this->height-=(edk::uint16)n;
        this->length-=(edk::uint16)n;
    }

    //*
    inline edk::size3ui16 operator*(edk::size3ui8 size){
        //
        edk::size3ui16 ret;
        ret.width=this->width*(edk::uint16)size.width;
        ret.height=this->height*(edk::uint16)size.height;
        ret.length=this->length*(edk::uint16)size.length;
        return ret;
    }
    inline edk::size3ui16 operator*(edk::size3ui16 size){
        //
        edk::size3ui16 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    inline edk::size3ui16 operator*(edk::size2i8 size){
        //
        edk::size3ui16 ret;
        ret.width=this->width*(edk::uint16)size.width;
        ret.height=this->height*(edk::uint16)size.height;
        return ret;
    }
    inline edk::size3ui16 operator*(edk::uint8 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width*(edk::uint16)n;
        ret.height=this->height*(edk::uint16)n;
        ret.length=this->length*(edk::uint16)n;
        return ret;
    }
    inline edk::size3ui16 operator*(edk::uint16 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width*(edk::uint16)n;
        ret.height=this->height*(edk::uint16)n;
        ret.length=this->length*(edk::uint16)n;
        return ret;
    }
    inline edk::size3ui16 operator*(edk::uint32 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width*(edk::uint16)n;
        ret.height=this->height*(edk::uint16)n;
        ret.length=this->length*(edk::uint16)n;
        return ret;
    }
    inline edk::size3ui16 operator*(edk::uint64 n){
        //
        edk::size3ui16 ret;
        ret.width=this->width*(edk::uint16)n;
        ret.height=this->height*(edk::uint16)n;
        ret.length=this->length*(edk::uint16)n;
        return ret;
    }

    //*=
    inline void operator*=(edk::size3ui8 size){
        //
        this->width*=(edk::uint16)size.width;
        this->height*=(edk::uint16)size.height;
        this->length*=(edk::uint16)size.length;
    }
    inline void operator*=(edk::size3ui16 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    inline void operator*=(edk::size2i8 size){
        //
        this->width*=(edk::uint16)size.width;
        this->height*=(edk::uint16)size.height;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->width*=(edk::uint16)n;
        this->height*=(edk::uint16)n;
        this->length*=(edk::uint16)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->width*=(edk::uint16)n;
        this->height*=(edk::uint16)n;
        this->length*=(edk::uint16)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->width*=(edk::uint16)n;
        this->height*=(edk::uint16)n;
        this->length*=(edk::uint16)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->width*=(edk::uint16)n;
        this->height*=(edk::uint16)n;
        this->length*=(edk::uint16)n;
    }

    //++
    inline edk::size3ui16 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return edk::size3ui16(this->width,this->height,this->length);
    }
    inline edk::size3ui16 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return edk::size3ui16(this->width,this->height,this->length);
    }

    //--
    inline edk::size3ui16 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return edk::size3ui16(this->width,this->height,this->length);
    }
    inline edk::size3ui16 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return edk::size3ui16(this->width,this->height,this->length);
    }

    //
    inline edk::size3ui16 operator()(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui16((edk::uint16)this->width,(edk::uint16)this->height,(edk::uint16)this->length);
    }
    inline edk::size3ui16 operator()(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui16((edk::uint16)this->width,(edk::uint16)this->height,(edk::uint16)this->length);
    }
    inline edk::size3ui16 operator()(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui16((edk::uint16)this->width,(edk::uint16)this->height,(edk::uint16)this->length);
    }
    inline edk::size3ui16 operator()(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui16((edk::uint16)this->width,(edk::uint16)this->height,(edk::uint16)this->length);
    }
};

//size3ui32
class size3ui32{
    //
public:
    edk::uint32 width,height,length;

    //CONSTRUTOR
    size3ui32(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3ui32(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //zera as variaveis
        this->width=(edk::uint32)width;
        this->height=(edk::uint32)height;
        this->length=(edk::uint32)length;
    }
    size3ui32(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //zera as variaveis
        this->width=(edk::uint32)width;
        this->height=(edk::uint32)height;
        this->length=(edk::uint32)length;
    }
    size3ui32(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //zera as variaveis
        this->width=(edk::uint32)width;
        this->height=(edk::uint32)height;
        this->length=(edk::uint32)length;
    }
    size3ui32(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //zera as variaveis
        this->width=(edk::uint32)width;
        this->height=(edk::uint32)height;
        this->length=(edk::uint32)length;
    }
    size3ui32(edk::uint8 size){
        //zera as variaveis
        this->width=(edk::uint32)size;
        this->height=(edk::uint32)size;
        this->length=(edk::uint32)size;
    }
    size3ui32(edk::uint16 size){
        //zera as variaveis
        this->width=(edk::uint32)size;
        this->height=(edk::uint32)size;
        this->length=(edk::uint32)size;
    }
    size3ui32(edk::uint32 size){
        //zera as variaveis
        this->width=(edk::uint32)size;
        this->height=(edk::uint32)size;
        this->length=(edk::uint32)size;
    }
    size3ui32(edk::uint64 size){
        //zera as variaveis
        this->width=(edk::uint32)size;
        this->height=(edk::uint32)size;
        this->length=(edk::uint32)size;
    }
    //operators

    //=
    inline edk::size3ui32 operator=(edk::size3ui8 size){
        //
        this->width=(edk::uint32)size.width;
        this->height=(edk::uint32)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3ui32 operator=(edk::size3ui16 size){
        //
        this->width=(edk::uint32)size.width;
        this->height=(edk::uint32)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3ui32 operator=(edk::size3ui32 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3ui32 operator=(edk::size2i8 size){
        //
        this->width=(edk::uint32)size.width;
        this->height=(edk::uint32)size.height;
        this->length=(edk::uint32)0;
        return *this;
    }
    inline edk::size3ui32 operator=(edk::uint8 n){
        //
        this->width=(edk::uint32)n;
        this->height=(edk::uint32)n;
        this->length=(edk::uint32)n;
        return *this;
    }
    inline edk::size3ui32 operator=(edk::uint16 n){
        //
        this->width=(edk::uint32)n;
        this->height=(edk::uint32)n;
        this->length=(edk::uint32)n;
        return *this;
    }
    inline edk::size3ui32 operator=(edk::uint32 n){
        //
        this->width=(edk::uint32)n;
        this->height=(edk::uint32)n;
        this->length=(edk::uint32)n;
        return *this;
    }
    inline edk::size3ui32 operator=(edk::uint64 n){
        //
        this->width=(edk::uint32)n;
        this->height=(edk::uint32)n;
        this->length=(edk::uint32)n;
        return *this;
    }

    //==
    inline bool operator==(edk::size3ui8 size){
        //
        return (this->width==(edk::uint32)size.width&&this->height==(edk::uint32)size.height&&this->length==(edk::uint32)size.length);
    }
    inline bool operator==(edk::size3ui16 size){
        //
        return (this->width==(edk::uint32)size.width&&this->height==(edk::uint32)size.height&&this->length==(edk::uint32)size.length);
    }
    inline bool operator==(edk::size3ui32 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    inline bool operator!=(edk::size3ui8 size){
        //
        return (this->width!=(edk::uint32)size.width||this->height!=(edk::uint32)size.height||this->length!=(edk::uint32)size.length);
    }
    inline bool operator!=(edk::size3ui16 size){
        //
        return (this->width!=(edk::uint32)size.width||this->height!=(edk::uint32)size.height||this->length!=(edk::uint32)size.length);
    }
    inline bool operator!=(edk::size3ui32 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    inline edk::size3ui32 operator+(edk::size3ui8 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width+(edk::uint32)size.width;
        ret.height=this->height+(edk::uint32)size.height;
        ret.length=this->length+(edk::uint32)size.length;
        return ret;
    }
    inline edk::size3ui32 operator+(edk::size3ui16 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width+(edk::uint32)size.width;
        ret.height=this->height+(edk::uint32)size.height;
        ret.length=this->length+(edk::uint32)size.length;
        return ret;
    }
    inline edk::size3ui32 operator+(edk::size3ui32 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    inline edk::size3ui32 operator+(edk::size2i8 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width+(edk::uint32)size.width;
        ret.height=this->height+(edk::uint32)size.height;
        return ret;
    }
    inline edk::size3ui32 operator+(edk::uint8 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width+(edk::uint32)n;
        ret.height=this->height+(edk::uint32)n;
        ret.length=this->length+(edk::uint32)n;
        return ret;
    }
    inline edk::size3ui32 operator+(edk::uint16 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width+(edk::uint32)n;
        ret.height=this->height+(edk::uint32)n;
        ret.length=this->length+(edk::uint32)n;
        return ret;
    }
    inline edk::size3ui32 operator+(edk::uint32 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width+(edk::uint32)n;
        ret.height=this->height+(edk::uint32)n;
        ret.length=this->length+(edk::uint32)n;
        return ret;
    }
    inline edk::size3ui32 operator+(edk::uint64 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width+(edk::uint32)n;
        ret.height=this->height+(edk::uint32)n;
        ret.length=this->length+(edk::uint32)n;
        return ret;
    }

    //+=
    inline void operator+=(edk::size3ui8 size){
        //
        this->width+=(edk::uint32)size.width;
        this->height+=(edk::uint32)size.height;
        this->length+=(edk::uint32)size.length;
    }
    inline void operator+=(edk::size3ui16 size){
        //
        this->width+=(edk::uint32)size.width;
        this->height+=(edk::uint32)size.height;
        this->length+=(edk::uint32)size.length;
    }
    inline void operator+=(edk::size3ui32 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    inline void operator+=(edk::size2i8 size){
        //
        this->width+=(edk::uint32)size.width;
        this->height+=(edk::uint32)size.height;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->width+=(edk::uint32)n;
        this->height+=(edk::uint32)n;
        this->length+=(edk::uint32)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->width+=(edk::uint32)n;
        this->height+=(edk::uint32)n;
        this->length+=(edk::uint32)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->width+=(edk::uint32)n;
        this->height+=(edk::uint32)n;
        this->length+=(edk::uint32)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->width+=(edk::uint32)n;
        this->height+=(edk::uint32)n;
        this->length+=(edk::uint32)n;
    }

    //-
    inline edk::size3ui32 operator-(edk::size3ui8 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width-(edk::uint32)size.width;
        ret.height=this->height-(edk::uint32)size.height;
        ret.length=this->length-(edk::uint32)size.length;
        return ret;
    }
    inline edk::size3ui32 operator-(edk::size3ui16 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width-(edk::uint32)size.width;
        ret.height=this->height-(edk::uint32)size.height;
        ret.length=this->length-(edk::uint32)size.length;
        return ret;
    }
    inline edk::size3ui32 operator-(edk::size3ui32 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    inline edk::size3ui32 operator-(edk::size2i8 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width-(edk::uint32)size.width;
        ret.height=this->height-(edk::uint32)size.height;
        return ret;
    }
    inline edk::size3ui32 operator-(edk::uint8 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width-(edk::uint32)n;
        ret.height=this->height-(edk::uint32)n;
        ret.length=this->length-(edk::uint32)n;
        return ret;
    }
    inline edk::size3ui32 operator-(edk::uint16 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width-(edk::uint32)n;
        ret.height=this->height-(edk::uint32)n;
        ret.length=this->length-(edk::uint32)n;
        return ret;
    }
    inline edk::size3ui32 operator-(edk::uint32 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width-(edk::uint32)n;
        ret.height=this->height-(edk::uint32)n;
        ret.length=this->length-(edk::uint32)n;
        return ret;
    }
    inline edk::size3ui32 operator-(edk::uint64 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width-(edk::uint32)n;
        ret.height=this->height-(edk::uint32)n;
        ret.length=this->length-(edk::uint32)n;
        return ret;
    }

    //-=
    inline void operator-=(edk::size3ui8 size){
        //
        this->width-=(edk::uint32)size.width;
        this->height-=(edk::uint32)size.height;
        this->length-=(edk::uint32)size.length;
    }
    inline void operator-=(edk::size3ui16 size){
        //
        this->width-=(edk::uint32)size.width;
        this->height-=(edk::uint32)size.height;
        this->length-=(edk::uint32)size.length;
    }
    inline void operator-=(edk::size3ui32 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    inline void operator-=(edk::size2i8 size){
        //
        this->width-=(edk::uint32)size.width;
        this->height-=(edk::uint32)size.height;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->width-=(edk::uint32)n;
        this->height-=(edk::uint32)n;
        this->length-=(edk::uint32)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->width-=(edk::uint32)n;
        this->height-=(edk::uint32)n;
        this->length-=(edk::uint32)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->width-=(edk::uint32)n;
        this->height-=(edk::uint32)n;
        this->length-=(edk::uint32)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->width-=(edk::uint32)n;
        this->height-=(edk::uint32)n;
        this->length-=(edk::uint32)n;
    }

    //*
    inline edk::size3ui32 operator*(edk::size3ui8 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width*(edk::uint32)size.width;
        ret.height=this->height*(edk::uint32)size.height;
        ret.length=this->length*(edk::uint32)size.length;
        return ret;
    }
    inline edk::size3ui32 operator*(edk::size3ui16 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width*(edk::uint32)size.width;
        ret.height=this->height*(edk::uint32)size.height;
        ret.length=this->length*(edk::uint32)size.length;
        return ret;
    }
    inline edk::size3ui32 operator*(edk::size3ui32 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    inline edk::size3ui32 operator*(edk::size2i8 size){
        //
        edk::size3ui32 ret;
        ret.width=this->width*(edk::uint32)size.width;
        ret.height=this->height*(edk::uint32)size.height;
        return ret;
    }
    inline edk::size3ui32 operator*(edk::uint8 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width*(edk::uint32)n;
        ret.height=this->height*(edk::uint32)n;
        ret.length=this->length*(edk::uint32)n;
        return ret;
    }
    inline edk::size3ui32 operator*(edk::uint16 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width*(edk::uint32)n;
        ret.height=this->height*(edk::uint32)n;
        ret.length=this->length*(edk::uint32)n;
        return ret;
    }
    inline edk::size3ui32 operator*(edk::uint32 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width*(edk::uint32)n;
        ret.height=this->height*(edk::uint32)n;
        ret.length=this->length*(edk::uint32)n;
        return ret;
    }
    inline edk::size3ui32 operator*(edk::uint64 n){
        //
        edk::size3ui32 ret;
        ret.width=this->width*(edk::uint32)n;
        ret.height=this->height*(edk::uint32)n;
        ret.length=this->length*(edk::uint32)n;
        return ret;
    }

    //*=
    inline void operator*=(edk::size3ui8 size){
        //
        this->width*=(edk::uint32)size.width;
        this->height*=(edk::uint32)size.height;
        this->length*=(edk::uint32)size.length;
    }
    inline void operator*=(edk::size3ui16 size){
        //
        this->width*=(edk::uint32)size.width;
        this->height*=(edk::uint32)size.height;
        this->length*=(edk::uint32)size.length;
    }
    inline void operator*=(edk::size3ui32 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    inline void operator*=(edk::size2i8 size){
        //
        this->width*=(edk::uint32)size.width;
        this->height*=(edk::uint32)size.height;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->width*=(edk::uint32)n;
        this->height*=(edk::uint32)n;
        this->length*=(edk::uint32)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->width*=(edk::uint32)n;
        this->height*=(edk::uint32)n;
        this->length*=(edk::uint32)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->width*=(edk::uint32)n;
        this->height*=(edk::uint32)n;
        this->length*=(edk::uint32)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->width*=(edk::uint32)n;
        this->height*=(edk::uint32)n;
        this->length*=(edk::uint32)n;
    }

    //++
    inline edk::size3ui32 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return edk::size3ui32(this->width,this->height,this->length);
    }
    inline edk::size3ui32 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return edk::size3ui32(this->width,this->height,this->length);
    }

    //--
    inline edk::size3ui32 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return edk::size3ui32(this->width,this->height,this->length);
    }
    inline edk::size3ui32 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return edk::size3ui32(this->width,this->height,this->length);
    }

    //
    inline edk::size3ui32 operator()(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui32((edk::uint32)this->width,(edk::uint32)this->height,(edk::uint32)this->length);
    }
    inline edk::size3ui32 operator()(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui32((edk::uint32)this->width,(edk::uint32)this->height,(edk::uint32)this->length);
    }
    inline edk::size3ui32 operator()(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui32((edk::uint32)this->width,(edk::uint32)this->height,(edk::uint32)this->length);
    }
    inline edk::size3ui32 operator()(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui32((edk::uint32)this->width,(edk::uint32)this->height,(edk::uint32)this->length);
    }
};

//size3ui64
class size3ui64{
    //
public:
    edk::uint64 width,height,length;

    //CONSTRUTOR
    size3ui64(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3ui64(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //zera as variaveis
        this->width=(edk::uint64)width;
        this->height=(edk::uint64)height;
        this->length=(edk::uint64)length;
    }
    size3ui64(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //zera as variaveis
        this->width=(edk::uint64)width;
        this->height=(edk::uint64)height;
        this->length=(edk::uint64)length;
    }
    size3ui64(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //zera as variaveis
        this->width=(edk::uint64)width;
        this->height=(edk::uint64)height;
        this->length=(edk::uint64)length;
    }
    size3ui64(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //zera as variaveis
        this->width=(edk::uint64)width;
        this->height=(edk::uint64)height;
        this->length=(edk::uint64)length;
    }
    size3ui64(edk::uint8 size){
        //zera as variaveis
        this->width=(edk::uint64)size;
        this->height=(edk::uint64)size;
        this->length=(edk::uint64)size;
    }
    size3ui64(edk::uint16 size){
        //zera as variaveis
        this->width=(edk::uint64)size;
        this->height=(edk::uint64)size;
        this->length=(edk::uint64)size;
    }
    size3ui64(edk::uint32 size){
        //zera as variaveis
        this->width=(edk::uint64)size;
        this->height=(edk::uint64)size;
        this->length=(edk::uint64)size;
    }
    size3ui64(edk::uint64 size){
        //zera as variaveis
        this->width=(edk::uint64)size;
        this->height=(edk::uint64)size;
        this->length=(edk::uint64)size;
    }
    //operators

    //=
    inline edk::size3ui64 operator=(edk::size3ui8 size){
        //
        this->width=(edk::uint64)size.width;
        this->height=(edk::uint64)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3ui64 operator=(edk::size3ui16 size){
        //
        this->width=(edk::uint64)size.width;
        this->height=(edk::uint64)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3ui64 operator=(edk::size3ui32 size){
        //
        this->width=(edk::uint64)size.width;
        this->height=(edk::uint64)size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3ui64 operator=(edk::size3ui64 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3ui64 operator=(edk::size2i8 size){
        //
        this->width=(edk::uint64)size.width;
        this->height=(edk::uint64)size.height;
        this->length=(edk::uint64)0;
        return *this;
    }
    inline edk::size3ui64 operator=(edk::uint8 n){
        //
        this->width=(edk::uint64)n;
        this->height=(edk::uint64)n;
        this->length=(edk::uint64)n;
        return *this;
    }
    inline edk::size3ui64 operator=(edk::uint16 n){
        //
        this->width=(edk::uint64)n;
        this->height=(edk::uint64)n;
        this->length=(edk::uint64)n;
        return *this;
    }
    inline edk::size3ui64 operator=(edk::uint32 n){
        //
        this->width=(edk::uint64)n;
        this->height=(edk::uint64)n;
        this->length=(edk::uint64)n;
        return *this;
    }
    inline edk::size3ui64 operator=(edk::uint64 n){
        //
        this->width=(edk::uint64)n;
        this->height=(edk::uint64)n;
        this->length=(edk::uint64)n;
        return *this;
    }

    //==
    inline bool operator==(edk::size3ui8 size){
        //
        return (this->width==(edk::uint64)size.width&&this->height==(edk::uint64)size.height&&this->length==(edk::uint64)size.length);
    }
    inline bool operator==(edk::size3ui16 size){
        //
        return (this->width==(edk::uint64)size.width&&this->height==(edk::uint64)size.height&&this->length==(edk::uint64)size.length);
    }
    inline bool operator==(edk::size3ui32 size){
        //
        return (this->width==(edk::uint64)size.width&&this->height==(edk::uint64)size.height&&this->length==(edk::uint64)size.length);
    }
    inline bool operator==(edk::size3ui64 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    inline bool operator!=(edk::size3ui8 size){
        //
        return (this->width!=(edk::uint64)size.width||this->height!=(edk::uint64)size.height||this->length!=(edk::uint64)size.length);
    }
    inline bool operator!=(edk::size3ui16 size){
        //
        return (this->width!=(edk::uint64)size.width||this->height!=(edk::uint64)size.height||this->length!=(edk::uint64)size.length);
    }
    inline bool operator!=(edk::size3ui32 size){
        //
        return (this->width!=(edk::uint64)size.width||this->height!=(edk::uint64)size.height||this->length!=(edk::uint64)size.length);
    }
    inline bool operator!=(edk::size3ui64 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    inline edk::size3ui64 operator+(edk::size3ui8 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width+(edk::uint64)size.width;
        ret.height=this->height+(edk::uint64)size.height;
        ret.length=this->length+(edk::uint64)size.length;
        return ret;
    }
    inline edk::size3ui64 operator+(edk::size3ui16 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width+(edk::uint64)size.width;
        ret.height=this->height+(edk::uint64)size.height;
        ret.length=this->length+(edk::uint64)size.length;
        return ret;
    }
    inline edk::size3ui64 operator+(edk::size3ui32 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width+(edk::uint64)size.width;
        ret.height=this->height+(edk::uint64)size.height;
        ret.length=this->length+(edk::uint64)size.length;
        return ret;
    }
    inline edk::size3ui64 operator+(edk::size3ui64 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    inline edk::size3ui64 operator+(edk::size2i8 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width+(edk::uint64)size.width;
        ret.height=this->height+(edk::uint64)size.height;
        return ret;
    }
    inline edk::size3ui64 operator+(edk::uint8 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width+(edk::uint64)n;
        ret.height=this->height+(edk::uint64)n;
        ret.length=this->length+(edk::uint64)n;
        return ret;
    }
    inline edk::size3ui64 operator+(edk::uint16 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width+(edk::uint64)n;
        ret.height=this->height+(edk::uint64)n;
        ret.length=this->length+(edk::uint64)n;
        return ret;
    }
    inline edk::size3ui64 operator+(edk::uint32 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width+(edk::uint64)n;
        ret.height=this->height+(edk::uint64)n;
        ret.length=this->length+(edk::uint64)n;
        return ret;
    }
    inline edk::size3ui64 operator+(edk::uint64 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width+(edk::uint64)n;
        ret.height=this->height+(edk::uint64)n;
        ret.length=this->length+(edk::uint64)n;
        return ret;
    }

    //+=
    inline void operator+=(edk::size3ui8 size){
        //
        this->width+=(edk::uint64)size.width;
        this->height+=(edk::uint64)size.height;
        this->length+=(edk::uint64)size.length;
    }
    inline void operator+=(edk::size3ui16 size){
        //
        this->width+=(edk::uint64)size.width;
        this->height+=(edk::uint64)size.height;
        this->length+=(edk::uint64)size.length;
    }
    inline void operator+=(edk::size3ui32 size){
        //
        this->width+=(edk::uint64)size.width;
        this->height+=(edk::uint64)size.height;
        this->length+=(edk::uint64)size.length;
    }
    inline void operator+=(edk::size3ui64 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    inline void operator+=(edk::size2i8 size){
        //
        this->width+=(edk::uint64)size.width;
        this->height+=(edk::uint64)size.height;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->width+=(edk::uint64)n;
        this->height+=(edk::uint64)n;
        this->length+=(edk::uint64)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->width+=(edk::uint64)n;
        this->height+=(edk::uint64)n;
        this->length+=(edk::uint64)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->width+=(edk::uint64)n;
        this->height+=(edk::uint64)n;
        this->length+=(edk::uint64)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->width+=(edk::uint64)n;
        this->height+=(edk::uint64)n;
        this->length+=(edk::uint64)n;
    }

    //-
    inline edk::size3ui64 operator-(edk::size3ui8 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width-(edk::uint64)size.width;
        ret.height=this->height-(edk::uint64)size.height;
        ret.length=this->length-(edk::uint64)size.length;
        return ret;
    }
    inline edk::size3ui64 operator-(edk::size3ui16 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width-(edk::uint64)size.width;
        ret.height=this->height-(edk::uint64)size.height;
        ret.length=this->length-(edk::uint64)size.length;
        return ret;
    }
    inline edk::size3ui64 operator-(edk::size3ui32 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width-(edk::uint64)size.width;
        ret.height=this->height-(edk::uint64)size.height;
        ret.length=this->length-(edk::uint64)size.length;
        return ret;
    }
    inline edk::size3ui64 operator-(edk::size3ui64 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    inline edk::size3ui64 operator-(edk::size2i8 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width-(edk::uint64)size.width;
        ret.height=this->height-(edk::uint64)size.height;
        return ret;
    }
    inline edk::size3ui64 operator-(edk::uint8 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width-(edk::uint64)n;
        ret.height=this->height-(edk::uint64)n;
        ret.length=this->length-(edk::uint64)n;
        return ret;
    }
    inline edk::size3ui64 operator-(edk::uint16 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width-(edk::uint64)n;
        ret.height=this->height-(edk::uint64)n;
        ret.length=this->length-(edk::uint64)n;
        return ret;
    }
    inline edk::size3ui64 operator-(edk::uint32 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width-(edk::uint64)n;
        ret.height=this->height-(edk::uint64)n;
        ret.length=this->length-(edk::uint64)n;
        return ret;
    }
    inline edk::size3ui64 operator-(edk::uint64 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width-(edk::uint64)n;
        ret.height=this->height-(edk::uint64)n;
        ret.length=this->length-(edk::uint64)n;
        return ret;
    }

    //-=
    inline void operator-=(edk::size3ui8 size){
        //
        this->width-=(edk::uint64)size.width;
        this->height-=(edk::uint64)size.height;
        this->length-=(edk::uint64)size.length;
    }
    inline void operator-=(edk::size3ui16 size){
        //
        this->width-=(edk::uint64)size.width;
        this->height-=(edk::uint64)size.height;
        this->length-=(edk::uint64)size.length;
    }
    inline void operator-=(edk::size3ui32 size){
        //
        this->width-=(edk::uint64)size.width;
        this->height-=(edk::uint64)size.height;
        this->length-=(edk::uint64)size.length;
    }
    inline void operator-=(edk::size3ui64 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    inline void operator-=(edk::size2i8 size){
        //
        this->width-=(edk::uint64)size.width;
        this->height-=(edk::uint64)size.height;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->width-=(edk::uint64)n;
        this->height-=(edk::uint64)n;
        this->length-=(edk::uint64)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->width-=(edk::uint64)n;
        this->height-=(edk::uint64)n;
        this->length-=(edk::uint64)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->width-=(edk::uint64)n;
        this->height-=(edk::uint64)n;
        this->length-=(edk::uint64)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->width-=(edk::uint64)n;
        this->height-=(edk::uint64)n;
        this->length-=(edk::uint64)n;
    }

    //*
    inline edk::size3ui64 operator*(edk::size3ui8 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width*(edk::uint64)size.width;
        ret.height=this->height*(edk::uint64)size.height;
        ret.length=this->length*(edk::uint64)size.length;
        return ret;
    }
    inline edk::size3ui64 operator*(edk::size3ui16 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width*(edk::uint64)size.width;
        ret.height=this->height*(edk::uint64)size.height;
        ret.length=this->length*(edk::uint64)size.length;
        return ret;
    }
    inline edk::size3ui64 operator*(edk::size3ui32 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width*(edk::uint64)size.width;
        ret.height=this->height*(edk::uint64)size.height;
        ret.length=this->length*(edk::uint64)size.length;
        return ret;
    }
    inline edk::size3ui64 operator*(edk::size3ui64 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    inline edk::size3ui64 operator*(edk::size2i8 size){
        //
        edk::size3ui64 ret;
        ret.width=this->width*(edk::uint64)size.width;
        ret.height=this->height*(edk::uint64)size.height;
        return ret;
    }
    inline edk::size3ui64 operator*(edk::uint8 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width*(edk::uint64)n;
        ret.height=this->height*(edk::uint64)n;
        ret.length=this->length*(edk::uint64)n;
        return ret;
    }
    inline edk::size3ui64 operator*(edk::uint16 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width*(edk::uint64)n;
        ret.height=this->height*(edk::uint64)n;
        ret.length=this->length*(edk::uint64)n;
        return ret;
    }
    inline edk::size3ui64 operator*(edk::uint32 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width*(edk::uint64)n;
        ret.height=this->height*(edk::uint64)n;
        ret.length=this->length*(edk::uint64)n;
        return ret;
    }
    inline edk::size3ui64 operator*(edk::uint64 n){
        //
        edk::size3ui64 ret;
        ret.width=this->width*(edk::uint64)n;
        ret.height=this->height*(edk::uint64)n;
        ret.length=this->length*(edk::uint64)n;
        return ret;
    }

    //*=
    inline void operator*=(edk::size3ui8 size){
        //
        this->width*=(edk::uint64)size.width;
        this->height*=(edk::uint64)size.height;
        this->length*=(edk::uint64)size.length;
    }
    inline void operator*=(edk::size3ui16 size){
        //
        this->width*=(edk::uint64)size.width;
        this->height*=(edk::uint64)size.height;
        this->length*=(edk::uint64)size.length;
    }
    inline void operator*=(edk::size3ui32 size){
        //
        this->width*=(edk::uint64)size.width;
        this->height*=(edk::uint64)size.height;
        this->length*=(edk::uint64)size.length;
    }
    inline void operator*=(edk::size3ui64 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    inline void operator*=(edk::size2i8 size){
        //
        this->width*=(edk::uint64)size.width;
        this->height*=(edk::uint64)size.height;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->width*=(edk::uint64)n;
        this->height*=(edk::uint64)n;
        this->length*=(edk::uint64)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->width*=(edk::uint64)n;
        this->height*=(edk::uint64)n;
        this->length*=(edk::uint64)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->width*=(edk::uint64)n;
        this->height*=(edk::uint64)n;
        this->length*=(edk::uint64)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->width*=(edk::uint64)n;
        this->height*=(edk::uint64)n;
        this->length*=(edk::uint64)n;
    }

    //++
    inline edk::size3ui64 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return edk::size3ui64(this->width,this->height,this->length);
    }
    inline edk::size3ui64 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return edk::size3ui64(this->width,this->height,this->length);
    }

    //--
    inline edk::size3ui64 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return edk::size3ui64(this->width,this->height,this->length);
    }
    inline edk::size3ui64 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return edk::size3ui64(this->width,this->height,this->length);
    }

    //
    inline edk::size3ui64 operator()(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui64((edk::uint64)this->width,(edk::uint64)this->height,(edk::uint64)this->length);
    }
    inline edk::size3ui64 operator()(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui64((edk::uint64)this->width,(edk::uint64)this->height,(edk::uint64)this->length);
    }
    inline edk::size3ui64 operator()(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui64((edk::uint64)this->width,(edk::uint64)this->height,(edk::uint64)this->length);
    }
    inline edk::size3ui64 operator()(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3ui64((edk::uint64)this->width,(edk::uint64)this->height,(edk::uint64)this->length);
    }
};

//size3f32
class size3f32{
    //
public:
    edk::float32 width,height,length;

    //CONSTRUTOR
    size3f32(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3f32(edk::float32 width,edk::float32 height,edk::float32 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(edk::float64 width,edk::float64 height,edk::float64 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(edk::int8 width,edk::int8 height,edk::int8 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(edk::int16 width,edk::int16 height,edk::int16 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(edk::int32 width,edk::int32 height,edk::int32 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(edk::int64 width,edk::int64 height,edk::int64 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(edk::float32 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(edk::float64 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(edk::int8 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(edk::int16 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(edk::int32 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(edk::int64 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(edk::uint8 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(edk::uint16 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(edk::uint32 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(edk::uint64 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    //operators

    //=
    inline edk::size3f32 operator=(edk::size3f32 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3f32 operator=(edk::size2i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=(edk::float32)0;
        return *this;
    }
    inline edk::size3f32 operator=(edk::float32 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    inline edk::size3f32 operator=(edk::float64 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    inline edk::size3f32 operator=(edk::int8 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    inline edk::size3f32 operator=(edk::int16 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    inline edk::size3f32 operator=(edk::int32 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    inline edk::size3f32 operator=(edk::int64 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    inline edk::size3f32 operator=(edk::uint8 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    inline edk::size3f32 operator=(edk::uint16 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    inline edk::size3f32 operator=(edk::uint32 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    inline edk::size3f32 operator=(edk::uint64 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }

    //==
    inline bool operator==(edk::size3f32 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    inline bool operator!=(edk::size3f32 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    inline edk::size3f32 operator+(edk::size3f32 size){
        //
        edk::size3f32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    inline edk::size3f32 operator+(edk::size2i8 size){
        //
        edk::size3f32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    inline edk::size3f32 operator+(edk::float32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator+(edk::float64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator+(edk::int8 n){
        //
        edk::size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator+(edk::int16 n){
        //
        edk::size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator+(edk::int32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator+(edk::int64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator+(edk::uint8 n){
        //
        edk::size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator+(edk::uint16 n){
        //
        edk::size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator+(edk::uint32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator+(edk::uint64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }

    //+=
    inline void operator+=(edk::size3f32 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    inline void operator+=(edk::size2i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    inline void operator+=(edk::float32 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    inline void operator+=(edk::float64 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    inline void operator+=(edk::int8 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }

    //-
    inline edk::size3f32 operator-(edk::size3f32 size){
        //
        edk::size3f32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    inline edk::size3f32 operator-(edk::size2i8 size){
        //
        edk::size3f32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    inline edk::size3f32 operator-(edk::float32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator-(edk::float64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator-(edk::int8 n){
        //
        edk::size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator-(edk::int16 n){
        //
        edk::size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator-(edk::int32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator-(edk::int64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator-(edk::uint8 n){
        //
        edk::size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator-(edk::uint16 n){
        //
        edk::size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator-(edk::uint32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator-(edk::uint64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }

    //-=
    inline void operator-=(edk::size3f32 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    inline void operator-=(edk::size2i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    inline void operator-=(edk::float32 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    inline void operator-=(edk::float64 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    inline void operator-=(edk::int8 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }

    //*
    inline edk::size3f32 operator*(edk::size3f32 size){
        //
        edk::size3f32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    inline edk::size3f32 operator*(edk::size2i8 size){
        //
        edk::size3f32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    inline edk::size3f32 operator*(edk::float32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator*(edk::float64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator*(edk::int8 n){
        //
        edk::size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator*(edk::int16 n){
        //
        edk::size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator*(edk::int32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator*(edk::int64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator*(edk::uint8 n){
        //
        edk::size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator*(edk::uint16 n){
        //
        edk::size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator*(edk::uint32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator*(edk::uint64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }

    //*=
    inline void operator*=(edk::size3f32 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    inline void operator*=(edk::size2i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    inline void operator*=(edk::float32 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    inline void operator*=(edk::float64 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    inline void operator*=(edk::int8 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }

    // /
    inline edk::size3f32 operator/(edk::size3f32 size){
        //
        edk::size3f32 ret;
        ret.width=this->width/size.width;
        ret.height=this->height/size.height;
        ret.length=this->length/size.length;
        return ret;
    }
    inline edk::size3f32 operator/(edk::size2i8 size){
        //
        edk::size3f32 ret;
        ret.width=this->width/size.width;
        ret.height=this->height/size.height;
        return ret;
    }
    inline edk::size3f32 operator/(edk::float32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator/(edk::float64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator/(edk::int8 n){
        //
        edk::size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator/(edk::int16 n){
        //
        edk::size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator/(edk::int32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator/(edk::int64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator/(edk::uint8 n){
        //
        edk::size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator/(edk::uint16 n){
        //
        edk::size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator/(edk::uint32 n){
        //
        edk::size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    inline edk::size3f32 operator/(edk::uint64 n){
        //
        edk::size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }

    // /=
    inline void operator/=(edk::size3f32 size){
        //
        this->width/=size.width;
        this->height/=size.height;
        this->length/=size.length;
    }
    inline void operator/=(edk::size2i8 size){
        //
        this->width/=size.width;
        this->height/=size.height;
    }
    inline void operator/=(edk::float32 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    inline void operator/=(edk::float64 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    inline void operator/=(edk::int8 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    inline void operator/=(edk::int16 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    inline void operator/=(edk::int32 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    inline void operator/=(edk::int64 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    inline void operator/=(edk::uint8 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    inline void operator/=(edk::uint16 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    inline void operator/=(edk::uint32 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    inline void operator/=(edk::uint64 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }

    //++
    inline edk::size3f32 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return edk::size3f32(this->width,this->height,this->length);
    }
    inline edk::size3f32 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return edk::size3f32(this->width,this->height,this->length);
    }

    //--
    inline edk::size3f32 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return edk::size3f32(this->width,this->height,this->length);
    }
    inline edk::size3f32 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return edk::size3f32(this->width,this->height,this->length);
    }

    //
    inline edk::size3f32 operator()(edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    inline edk::size3f32 operator()(edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    inline edk::size3f32 operator()(edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    inline edk::size3f32 operator()(edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    inline edk::size3f32 operator()(edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    inline edk::size3f32 operator()(edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    inline edk::size3f32 operator()(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    inline edk::size3f32 operator()(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    inline edk::size3f32 operator()(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    inline edk::size3f32 operator()(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
};

//size3f64
class size3f64{
    //
public:
    edk::float64 width,height,length;

    //CONSTRUTOR
    size3f64(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3f64(edk::float32 width,edk::float32 height,edk::float32 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(edk::float64 width,edk::float64 height,edk::float64 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(edk::int8 width,edk::int8 height,edk::int8 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(edk::int16 width,edk::int16 height,edk::int16 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(edk::int32 width,edk::int32 height,edk::int32 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(edk::int64 width,edk::int64 height,edk::int64 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(edk::float32 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(edk::float64 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(edk::int8 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(edk::int16 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(edk::int32 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(edk::int64 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(edk::uint8 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(edk::uint16 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(edk::uint32 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(edk::uint64 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    //operators

    //=
    inline edk::size3f64 operator=(edk::size3f64 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    inline edk::size3f64 operator=(edk::size2i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=(edk::float64)0;
        return *this;
    }
    inline edk::size3f64 operator=(edk::float32 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    inline edk::size3f64 operator=(edk::float64 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    inline edk::size3f64 operator=(edk::int8 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    inline edk::size3f64 operator=(edk::int16 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    inline edk::size3f64 operator=(edk::int32 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    inline edk::size3f64 operator=(edk::int64 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    inline edk::size3f64 operator=(edk::uint8 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    inline edk::size3f64 operator=(edk::uint16 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    inline edk::size3f64 operator=(edk::uint32 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    inline edk::size3f64 operator=(edk::uint64 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }

    //==
    inline bool operator==(edk::size3f64 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    inline bool operator!=(edk::size3f64 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    inline edk::size3f64 operator+(edk::size3f64 size){
        //
        edk::size3f64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    inline edk::size3f64 operator+(edk::size2i8 size){
        //
        edk::size3f64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    inline edk::size3f64 operator+(edk::float32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator+(edk::float64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator+(edk::int8 n){
        //
        edk::size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator+(edk::int16 n){
        //
        edk::size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator+(edk::int32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator+(edk::int64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator+(edk::uint8 n){
        //
        edk::size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator+(edk::uint16 n){
        //
        edk::size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator+(edk::uint32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator+(edk::uint64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }

    //+=
    inline void operator+=(edk::size3f64 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    inline void operator+=(edk::size2i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    inline void operator+=(edk::float32 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    inline void operator+=(edk::float64 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    inline void operator+=(edk::int8 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    inline void operator+=(edk::int16 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    inline void operator+=(edk::int32 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    inline void operator+=(edk::int64 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    inline void operator+=(edk::uint8 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    inline void operator+=(edk::uint16 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    inline void operator+=(edk::uint32 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    inline void operator+=(edk::uint64 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }

    //-
    inline edk::size3f64 operator-(edk::size3f64 size){
        //
        edk::size3f64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    inline edk::size3f64 operator-(edk::size2i8 size){
        //
        edk::size3f64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    inline edk::size3f64 operator-(edk::float32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator-(edk::float64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator-(edk::int8 n){
        //
        edk::size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator-(edk::int16 n){
        //
        edk::size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator-(edk::int32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator-(edk::int64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator-(edk::uint8 n){
        //
        edk::size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator-(edk::uint16 n){
        //
        edk::size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator-(edk::uint32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator-(edk::uint64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }

    //-=
    inline void operator-=(edk::size3f64 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    inline void operator-=(edk::size2i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    inline void operator-=(edk::float32 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    inline void operator-=(edk::float64 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    inline void operator-=(edk::int8 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    inline void operator-=(edk::int16 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    inline void operator-=(edk::int32 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    inline void operator-=(edk::int64 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    inline void operator-=(edk::uint8 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    inline void operator-=(edk::uint16 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    inline void operator-=(edk::uint32 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    inline void operator-=(edk::uint64 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }

    //*
    inline edk::size3f64 operator*(edk::size3f64 size){
        //
        edk::size3f64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    inline edk::size3f64 operator*(edk::size2i8 size){
        //
        edk::size3f64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    inline edk::size3f64 operator*(edk::float32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator*(edk::float64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator*(edk::int8 n){
        //
        edk::size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator*(edk::int16 n){
        //
        edk::size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator*(edk::int32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator*(edk::int64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator*(edk::uint8 n){
        //
        edk::size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator*(edk::uint16 n){
        //
        edk::size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator*(edk::uint32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator*(edk::uint64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }

    //*=
    inline void operator*=(edk::size3f64 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    inline void operator*=(edk::size2i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    inline void operator*=(edk::float32 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    inline void operator*=(edk::float64 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    inline void operator*=(edk::int8 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    inline void operator*=(edk::int16 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    inline void operator*=(edk::int32 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    inline void operator*=(edk::int64 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    inline void operator*=(edk::uint8 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    inline void operator*=(edk::uint16 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    inline void operator*=(edk::uint32 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    inline void operator*=(edk::uint64 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }

    // /
    inline edk::size3f64 operator/(edk::size3f64 size){
        //
        edk::size3f64 ret;
        ret.width=this->width/size.width;
        ret.height=this->height/size.height;
        ret.length=this->length/size.length;
        return ret;
    }
    inline edk::size3f64 operator/(edk::size2i8 size){
        //
        edk::size3f64 ret;
        ret.width=this->width/size.width;
        ret.height=this->height/size.height;
        return ret;
    }
    inline edk::size3f64 operator/(edk::float32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator/(edk::float64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator/(edk::int8 n){
        //
        edk::size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator/(edk::int16 n){
        //
        edk::size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator/(edk::int32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator/(edk::int64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator/(edk::uint8 n){
        //
        edk::size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator/(edk::uint16 n){
        //
        edk::size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator/(edk::uint32 n){
        //
        edk::size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    inline edk::size3f64 operator/(edk::uint64 n){
        //
        edk::size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }

    // /=
    inline void operator/=(edk::size3f64 size){
        //
        this->width/=size.width;
        this->height/=size.height;
        this->length/=size.length;
    }
    inline void operator/=(edk::size2i8 size){
        //
        this->width/=size.width;
        this->height/=size.height;
    }
    inline void operator/=(edk::float32 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    inline void operator/=(edk::float64 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    inline void operator/=(edk::int8 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    inline void operator/=(edk::int16 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    inline void operator/=(edk::int32 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    inline void operator/=(edk::int64 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    inline void operator/=(edk::uint8 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    inline void operator/=(edk::uint16 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    inline void operator/=(edk::uint32 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    inline void operator/=(edk::uint64 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }

    //++
    inline edk::size3f64 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return edk::size3f64(this->width,this->height,this->length);
    }
    inline edk::size3f64 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return edk::size3f64(this->width,this->height,this->length);
    }

    //--
    inline edk::size3f64 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return edk::size3f64(this->width,this->height,this->length);
    }
    inline edk::size3f64 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return edk::size3f64(this->width,this->height,this->length);
    }

    //
    inline edk::size3f64 operator()(edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    inline edk::size3f64 operator()(edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    inline edk::size3f64 operator()(edk::int8 width,edk::int8 height,edk::int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    inline edk::size3f64 operator()(edk::int16 width,edk::int16 height,edk::int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    inline edk::size3f64 operator()(edk::int32 width,edk::int32 height,edk::int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    inline edk::size3f64 operator()(edk::int64 width,edk::int64 height,edk::int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    inline edk::size3f64 operator()(edk::uint8 width,edk::uint8 height,edk::uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    inline edk::size3f64 operator()(edk::uint16 width,edk::uint16 height,edk::uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    inline edk::size3f64 operator()(edk::uint32 width,edk::uint32 height,edk::uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    inline edk::size3f64 operator()(edk::uint64 width,edk::uint64 height,edk::uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return edk::size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
};

}//end namespace

#endif // TYPESIZE3_H
