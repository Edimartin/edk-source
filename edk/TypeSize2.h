#ifndef EDK_TYPESIZE2_H
#define EDK_TYPESIZE2_H

/*
Library C++ typeSize2 - 2D size types used in Edk Game Engine
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
#warning "Inside TypesSize2"
#endif

#pragma once
#include "TypeVars.h"

#ifdef printMessages
#warning "    Compiling TypesSize2"
#endif

namespace edk{
//size2i8
class size2i8{
    //
public:
    int8 width,height;

    //CONSTRUTOR
    size2i8(){
        //zera as variaveis
        this->width=this->height=1;
    }
    size2i8(int8 width,int8 height){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
    }
    size2i8(int16 width,int16 height){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
    }
    size2i8(int32 width,int32 height){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
    }
    size2i8(int64 width,int64 height){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
    }
    size2i8(uint8 width,uint8 height){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
    }
    size2i8(uint16 width,uint16 height){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
    }
    size2i8(uint32 width,uint32 height){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
    }
    size2i8(uint64 width,uint64 height){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
    }
    size2i8(int8 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
    }
    size2i8(int16 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
    }
    size2i8(int32 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
    }
    size2i8(int64 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
    }
    size2i8(uint8 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
    }
    size2i8(uint16 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
    }
    size2i8(uint32 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
    }
    size2i8(uint64 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
    }
    //operators

    //=
    size2i8 operator=(size2i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        return *this;
    }
    size2i8 operator=(int8 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        return *this;
    }
    size2i8 operator=(int16 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        return *this;
    }
    size2i8 operator=(int32 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        return *this;
    }
    size2i8 operator=(int64 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        return *this;
    }
    size2i8 operator=(uint8 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        return *this;
    }
    size2i8 operator=(uint16 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        return *this;
    }
    size2i8 operator=(uint32 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        return *this;
    }
    size2i8 operator=(uint64 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        return *this;
    }

    //==
    bool operator==(size2i8 size){
        //
        return (this->width==size.width&&this->height==size.height);
    }
    //!=
    bool operator!=(size2i8 size){
        //
        return (this->width!=size.width||this->height!=size.height);
    }

    //+
    size2i8 operator+(size2i8 size){
        //
        size2i8 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size2i8 operator+(int8 n){
        //
        size2i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        return ret;
    }
    size2i8 operator+(int16 n){
        //
        size2i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        return ret;
    }
    size2i8 operator+(int32 n){
        //
        size2i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        return ret;
    }
    size2i8 operator+(int64 n){
        //
        size2i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        return ret;
    }
    size2i8 operator+(uint8 n){
        //
        size2i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        return ret;
    }
    size2i8 operator+(uint16 n){
        //
        size2i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        return ret;
    }
    size2i8 operator+(uint32 n){
        //
        size2i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        return ret;
    }
    size2i8 operator+(uint64 n){
        //
        size2i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        return ret;
    }

    //+=
    void operator+=(size2i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(int8 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
    }

    //-
    size2i8 operator-(size2i8 size){
        //
        size2i8 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size2i8 operator-(int8 n){
        //
        size2i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        return ret;
    }
    size2i8 operator-(int16 n){
        //
        size2i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        return ret;
    }
    size2i8 operator-(int32 n){
        //
        size2i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        return ret;
    }
    size2i8 operator-(int64 n){
        //
        size2i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        return ret;
    }
    size2i8 operator-(uint8 n){
        //
        size2i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        return ret;
    }
    size2i8 operator-(uint16 n){
        //
        size2i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        return ret;
    }
    size2i8 operator-(uint32 n){
        //
        size2i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        return ret;
    }
    size2i8 operator-(uint64 n){
        //
        size2i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        return ret;
    }

    //-=
    void operator-=(size2i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(int8 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
    }

    //*
    size2i8 operator*(size2i8 size){
        //
        size2i8 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size2i8 operator*(int8 n){
        //
        size2i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        return ret;
    }
    size2i8 operator*(int16 n){
        //
        size2i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        return ret;
    }
    size2i8 operator*(int32 n){
        //
        size2i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        return ret;
    }
    size2i8 operator*(int64 n){
        //
        size2i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        return ret;
    }
    size2i8 operator*(uint8 n){
        //
        size2i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        return ret;
    }
    size2i8 operator*(uint16 n){
        //
        size2i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        return ret;
    }
    size2i8 operator*(uint32 n){
        //
        size2i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        return ret;
    }
    size2i8 operator*(uint64 n){
        //
        size2i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        return ret;
    }

    //*=
    void operator*=(size2i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(int8 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
    }

    //++
    size2i8 operator++(){
        //
        ++this->width;
        ++this->height;
        return size2i8(this->width,this->height);
    }
    size2i8 operator++(int32){
        //
        this->width++;
        this->height++;
        return size2i8(this->width,this->height);
    }

    //--
    size2i8 operator--(){
        //
        --this->width;
        --this->height;
        return size2i8(this->width,this->height);
    }
    size2i8 operator--(int32){
        //
        this->width--;
        this->height--;
        return size2i8(this->width,this->height);
    }

    //
    size2i8 operator()(int8 width,int8 height){
        //
        this->width=width;
        this->height=height;
        return size2i8((int8)this->width,(int8)this->height);
    }
    size2i8 operator()(int16 width,int16 height){
        //
        this->width=width;
        this->height=height;
        return size2i8((int8)this->width,(int8)this->height);
    }
    size2i8 operator()(int32 width,int32 height){
        //
        this->width=width;
        this->height=height;
        return size2i8((int8)this->width,(int8)this->height);
    }
    size2i8 operator()(int64 width,int64 height){
        //
        this->width=width;
        this->height=height;
        return size2i8((int8)this->width,(int8)this->height);
    }
    size2i8 operator()(uint8 width,uint8 height){
        //
        this->width=width;
        this->height=height;
        return size2i8((int8)this->width,(int8)this->height);
    }
    size2i8 operator()(uint16 width,uint16 height){
        //
        this->width=width;
        this->height=height;
        return size2i8((int8)this->width,(int8)this->height);
    }
    size2i8 operator()(uint32 width,uint32 height){
        //
        this->width=width;
        this->height=height;
        return size2i8((int8)this->width,(int8)this->height);
    }
    size2i8 operator()(uint64 width,uint64 height){
        //
        this->width=width;
        this->height=height;
        return size2i8((int8)this->width,(int8)this->height);
    }
};

//size2i16
class size2i16{
    //
public:
    int16 width,height;

    //CONSTRUTOR
    size2i16(){
        //zera as variaveis
        this->width=this->height=1;
    }
    size2i16(int8 width,int8 height){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
    }
    size2i16(int16 width,int16 height){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
    }
    size2i16(int32 width,int32 height){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
    }
    size2i16(int64 width,int64 height){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
    }
    size2i16(uint8 width,uint8 height){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
    }
    size2i16(uint16 width,uint16 height){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
    }
    size2i16(uint32 width,uint32 height){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
    }
    size2i16(uint64 width,uint64 height){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
    }
    size2i16(int8 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
    }
    size2i16(int16 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
    }
    size2i16(int32 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
    }
    size2i16(int64 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
    }
    size2i16(uint8 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
    }
    size2i16(uint16 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
    }
    size2i16(uint32 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
    }
    size2i16(uint64 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
    }
    //operators

    //=
    size2i16 operator=(size2i8 size){
        //
        this->width=(int16)size.width;
        this->height=(int16)size.height;
        return *this;
    }
    size2i16 operator=(size2i16 size){
        //
        this->width=size.width;
        this->height=size.height;
        return *this;
    }
    size2i16 operator=(int8 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        return *this;
    }
    size2i16 operator=(int16 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        return *this;
    }
    size2i16 operator=(int32 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        return *this;
    }
    size2i16 operator=(int64 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        return *this;
    }
    size2i16 operator=(uint8 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        return *this;
    }
    size2i16 operator=(uint16 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        return *this;
    }
    size2i16 operator=(uint32 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        return *this;
    }
    size2i16 operator=(uint64 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        return *this;
    }

    //==
    bool operator==(size2i8 size){
        //
        return (this->width==(int16)size.width&&this->height==(int16)size.height);
    }
    bool operator==(size2i16 size){
        //
        return (this->width==size.width&&this->height==size.height);
    }
    //!=
    bool operator!=(size2i8 size){
        //
        return (this->width!=(int16)size.width&&this->height!=(int16)size.height);
    }
    bool operator!=(size2i16 size){
        //
        return (this->width!=size.width||this->height!=size.height);
    }

    //+
    size2i16 operator+(size2i8 size){
        //
        size2i16 ret;
        ret.width=this->width+(int16)size.width;
        ret.height=this->height+(int16)size.height;
        return ret;
    }
    size2i16 operator+(size2i16 size){
        //
        size2i16 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size2i16 operator+(int8 n){
        //
        size2i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        return ret;
    }
    size2i16 operator+(int16 n){
        //
        size2i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        return ret;
    }
    size2i16 operator+(int32 n){
        //
        size2i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        return ret;
    }
    size2i16 operator+(int64 n){
        //
        size2i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        return ret;
    }
    size2i16 operator+(uint8 n){
        //
        size2i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        return ret;
    }
    size2i16 operator+(uint16 n){
        //
        size2i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        return ret;
    }
    size2i16 operator+(uint32 n){
        //
        size2i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        return ret;
    }
    size2i16 operator+(uint64 n){
        //
        size2i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        return ret;
    }

    //+=
    void operator+=(size2i8 size){
        //
        this->width+=(int16)size.width;
        this->height+=(int16)size.height;
    }
    void operator+=(size2i16 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(int8 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
    }

    //-
    size2i16 operator-(size2i8 size){
        //
        size2i16 ret;
        ret.width=this->width-(int16)size.width;
        ret.height=this->height-(int16)size.height;
        return ret;
    }
    size2i16 operator-(size2i16 size){
        //
        size2i16 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size2i16 operator-(int8 n){
        //
        size2i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        return ret;
    }
    size2i16 operator-(int16 n){
        //
        size2i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        return ret;
    }
    size2i16 operator-(int32 n){
        //
        size2i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        return ret;
    }
    size2i16 operator-(int64 n){
        //
        size2i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        return ret;
    }
    size2i16 operator-(uint8 n){
        //
        size2i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        return ret;
    }
    size2i16 operator-(uint16 n){
        //
        size2i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        return ret;
    }
    size2i16 operator-(uint32 n){
        //
        size2i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        return ret;
    }
    size2i16 operator-(uint64 n){
        //
        size2i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        return ret;
    }

    //-=
    void operator-=(size2i8 size){
        //
        this->width-=(int16)size.width;
        this->height-=(int16)size.height;
    }
    void operator-=(size2i16 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(int8 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
    }

    //*
    size2i16 operator*(size2i8 size){
        //
        size2i16 ret;
        ret.width=this->width*(int16)size.width;
        ret.height=this->height*(int16)size.height;
        return ret;
    }
    size2i16 operator*(size2i16 size){
        //
        size2i16 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size2i16 operator*(int8 n){
        //
        size2i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        return ret;
    }
    size2i16 operator*(int16 n){
        //
        size2i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        return ret;
    }
    size2i16 operator*(int32 n){
        //
        size2i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        return ret;
    }
    size2i16 operator*(int64 n){
        //
        size2i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        return ret;
    }
    size2i16 operator*(uint8 n){
        //
        size2i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        return ret;
    }
    size2i16 operator*(uint16 n){
        //
        size2i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        return ret;
    }
    size2i16 operator*(uint32 n){
        //
        size2i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        return ret;
    }
    size2i16 operator*(uint64 n){
        //
        size2i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        return ret;
    }

    //*=
    void operator*=(size2i8 size){
        //
        this->width*=(int16)size.width;
        this->height*=(int16)size.height;
    }
    void operator*=(size2i16 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(int8 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
    }

    //++
    size2i16 operator++(){
        //
        ++this->width;
        ++this->height;
        return size2i16(this->width,this->height);
    }
    size2i16 operator++(int32){
        //
        this->width++;
        this->height++;
        return size2i16(this->width,this->height);
    }

    //--
    size2i16 operator--(){
        //
        --this->width;
        --this->height;
        return size2i16(this->width,this->height);
    }
    size2i16 operator--(int32){
        //
        this->width--;
        this->height--;
        return size2i16(this->width,this->height);
    }

    //
    size2i16 operator()(int8 width,int8 height){
        //
        this->width=width;
        this->height=height;
        return size2i16((int16)this->width,(int16)this->height);
    }
    size2i16 operator()(int16 width,int16 height){
        //
        this->width=width;
        this->height=height;
        return size2i16((int16)this->width,(int16)this->height);
    }
    size2i16 operator()(int32 width,int32 height){
        //
        this->width=width;
        this->height=height;
        return size2i16((int16)this->width,(int16)this->height);
    }
    size2i16 operator()(int64 width,int64 height){
        //
        this->width=width;
        this->height=height;
        return size2i16((int16)this->width,(int16)this->height);
    }
    size2i16 operator()(uint8 width,uint8 height){
        //
        this->width=width;
        this->height=height;
        return size2i16((int16)this->width,(int16)this->height);
    }
    size2i16 operator()(uint16 width,uint16 height){
        //
        this->width=width;
        this->height=height;
        return size2i16((int16)this->width,(int16)this->height);
    }
    size2i16 operator()(uint32 width,uint32 height){
        //
        this->width=width;
        this->height=height;
        return size2i16((int16)this->width,(int16)this->height);
    }
    size2i16 operator()(uint64 width,uint64 height){
        //
        this->width=width;
        this->height=height;
        return size2i16((int16)this->width,(int16)this->height);
    }
};

//size2i32
class size2i32{
    //
public:
    int32 width,height;

    //CONSTRUTOR
    size2i32(){
        //zera as variaveis
        this->width=this->height=1;
    }
    size2i32(int8 width,int8 height){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
    }
    size2i32(int16 width,int16 height){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
    }
    size2i32(int32 width,int32 height){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
    }
    size2i32(int64 width,int64 height){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
    }
    size2i32(uint8 width,uint8 height){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
    }
    size2i32(uint16 width,uint16 height){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
    }
    size2i32(uint32 width,uint32 height){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
    }
    size2i32(uint64 width,uint64 height){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
    }
    size2i32(int8 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
    }
    size2i32(int16 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
    }
    size2i32(int32 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
    }
    size2i32(int64 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
    }
    size2i32(uint8 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
    }
    size2i32(uint16 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
    }
    size2i32(uint32 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
    }
    size2i32(uint64 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
    }
    //operators

    //=
    size2i32 operator=(size2i8 size){
        //
        this->width=(int32)size.width;
        this->height=(int32)size.height;
        return *this;
    }
    size2i32 operator=(size2i16 size){
        //
        this->width=(int32)size.width;
        this->height=(int32)size.height;
        return *this;
    }
    size2i32 operator=(size2i32 size){
        //
        this->width=size.width;
        this->height=size.height;
        return *this;
    }
    size2i32 operator=(int8 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        return *this;
    }
    size2i32 operator=(int16 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        return *this;
    }
    size2i32 operator=(int32 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        return *this;
    }
    size2i32 operator=(int64 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        return *this;
    }
    size2i32 operator=(uint8 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        return *this;
    }
    size2i32 operator=(uint16 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        return *this;
    }
    size2i32 operator=(uint32 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        return *this;
    }
    size2i32 operator=(uint64 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        return *this;
    }

    //==
    bool operator==(size2i8 size){
        //
        return (this->width==(int32)size.width&&this->height==(int32)size.height);
    }
    bool operator==(size2i16 size){
        //
        return (this->width==(int32)size.width&&this->height==(int32)size.height);
    }
    bool operator==(size2i32 size){
        //
        return (this->width==size.width&&this->height==size.height);
    }
    //!=
    bool operator!=(size2i8 size){
        //
        return (this->width!=(int32)size.width&&this->height!=(int32)size.height);
    }
    bool operator!=(size2i16 size){
        //
        return (this->width!=(int32)size.width&&this->height!=(int32)size.height);
    }
    bool operator!=(size2i32 size){
        //
        return (this->width!=size.width||this->height!=size.height);
    }

    //+
    size2i32 operator+(size2i8 size){
        //
        size2i32 ret;
        ret.width=this->width+(int32)size.width;
        ret.height=this->height+(int32)size.height;
        return ret;
    }
    size2i32 operator+(size2i16 size){
        //
        size2i32 ret;
        ret.width=this->width+(int32)size.width;
        ret.height=this->height+(int32)size.height;
        return ret;
    }
    size2i32 operator+(size2i32 size){
        //
        size2i32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size2i32 operator+(int8 n){
        //
        size2i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        return ret;
    }
    size2i32 operator+(int16 n){
        //
        size2i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        return ret;
    }
    size2i32 operator+(int32 n){
        //
        size2i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        return ret;
    }
    size2i32 operator+(int64 n){
        //
        size2i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        return ret;
    }
    size2i32 operator+(uint8 n){
        //
        size2i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        return ret;
    }
    size2i32 operator+(uint16 n){
        //
        size2i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        return ret;
    }
    size2i32 operator+(uint32 n){
        //
        size2i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        return ret;
    }
    size2i32 operator+(uint64 n){
        //
        size2i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        return ret;
    }

    //+=
    void operator+=(size2i8 size){
        //
        this->width+=(int32)size.width;
        this->height+=(int32)size.height;
    }
    void operator+=(size2i16 size){
        //
        this->width+=(int32)size.width;
        this->height+=(int32)size.height;
    }
    void operator+=(size2i32 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(int8 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
    }

    //-
    size2i32 operator-(size2i8 size){
        //
        size2i32 ret;
        ret.width=this->width-(int32)size.width;
        ret.height=this->height-(int32)size.height;
        return ret;
    }
    size2i32 operator-(size2i16 size){
        //
        size2i32 ret;
        ret.width=this->width-(int32)size.width;
        ret.height=this->height-(int32)size.height;
        return ret;
    }
    size2i32 operator-(size2i32 size){
        //
        size2i32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size2i32 operator-(int8 n){
        //
        size2i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        return ret;
    }
    size2i32 operator-(int16 n){
        //
        size2i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        return ret;
    }
    size2i32 operator-(int32 n){
        //
        size2i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        return ret;
    }
    size2i32 operator-(int64 n){
        //
        size2i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        return ret;
    }
    size2i32 operator-(uint8 n){
        //
        size2i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        return ret;
    }
    size2i32 operator-(uint16 n){
        //
        size2i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        return ret;
    }
    size2i32 operator-(uint32 n){
        //
        size2i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        return ret;
    }
    size2i32 operator-(uint64 n){
        //
        size2i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        return ret;
    }

    //-=
    void operator-=(size2i8 size){
        //
        this->width-=(int32)size.width;
        this->height-=(int32)size.height;
    }
    void operator-=(size2i16 size){
        //
        this->width-=(int32)size.width;
        this->height-=(int32)size.height;
    }
    void operator-=(size2i32 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(int8 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
    }

    //*
    size2i32 operator*(size2i8 size){
        //
        size2i32 ret;
        ret.width=this->width*(int32)size.width;
        ret.height=this->height*(int32)size.height;
        return ret;
    }
    size2i32 operator*(size2i16 size){
        //
        size2i32 ret;
        ret.width=this->width*(int32)size.width;
        ret.height=this->height*(int32)size.height;
        return ret;
    }
    size2i32 operator*(size2i32 size){
        //
        size2i32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size2i32 operator*(int8 n){
        //
        size2i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        return ret;
    }
    size2i32 operator*(int16 n){
        //
        size2i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        return ret;
    }
    size2i32 operator*(int32 n){
        //
        size2i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        return ret;
    }
    size2i32 operator*(int64 n){
        //
        size2i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        return ret;
    }
    size2i32 operator*(uint8 n){
        //
        size2i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        return ret;
    }
    size2i32 operator*(uint16 n){
        //
        size2i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        return ret;
    }
    size2i32 operator*(uint32 n){
        //
        size2i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        return ret;
    }
    size2i32 operator*(uint64 n){
        //
        size2i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        return ret;
    }

    //*=
    void operator*=(size2i8 size){
        //
        this->width*=(int32)size.width;
        this->height*=(int32)size.height;
    }
    void operator*=(size2i16 size){
        //
        this->width*=(int32)size.width;
        this->height*=(int32)size.height;
    }
    void operator*=(size2i32 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(int8 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
    }

    //++
    size2i32 operator++(){
        //
        ++this->width;
        ++this->height;
        return size2i32(this->width,this->height);
    }
    size2i32 operator++(int32){
        //
        this->width++;
        this->height++;
        return size2i32(this->width,this->height);
    }

    //--
    size2i32 operator--(){
        //
        --this->width;
        --this->height;
        return size2i32(this->width,this->height);
    }
    size2i32 operator--(int32){
        //
        this->width--;
        this->height--;
        return size2i32(this->width,this->height);
    }

    //
    size2i32 operator()(int8 width,int8 height){
        //
        this->width=width;
        this->height=height;
        return size2i32((int32)this->width,(int32)this->height);
    }
    size2i32 operator()(int16 width,int16 height){
        //
        this->width=width;
        this->height=height;
        return size2i32((int32)this->width,(int32)this->height);
    }
    size2i32 operator()(int32 width,int32 height){
        //
        this->width=width;
        this->height=height;
        return size2i32((int32)this->width,(int32)this->height);
    }
    size2i32 operator()(int64 width,int64 height){
        //
        this->width=width;
        this->height=height;
        return size2i32((int32)this->width,(int32)this->height);
    }
    size2i32 operator()(uint8 width,uint8 height){
        //
        this->width=width;
        this->height=height;
        return size2i32((int32)this->width,(int32)this->height);
    }
    size2i32 operator()(uint16 width,uint16 height){
        //
        this->width=width;
        this->height=height;
        return size2i32((int32)this->width,(int32)this->height);
    }
    size2i32 operator()(uint32 width,uint32 height){
        //
        this->width=width;
        this->height=height;
        return size2i32((int32)this->width,(int32)this->height);
    }
    size2i32 operator()(uint64 width,uint64 height){
        //
        this->width=width;
        this->height=height;
        return size2i32((int32)this->width,(int32)this->height);
    }
};

//size2i64
class size2i64{
    //
public:
    int64 width,height;

    //CONSTRUTOR
    size2i64(){
        //zera as variaveis
        this->width=this->height=1;
    }
    size2i64(int8 width,int8 height){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
    }
    size2i64(int16 width,int16 height){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
    }
    size2i64(int32 width,int32 height){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
    }
    size2i64(int64 width,int64 height){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
    }
    size2i64(uint8 width,uint8 height){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
    }
    size2i64(uint16 width,uint16 height){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
    }
    size2i64(uint32 width,uint32 height){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
    }
    size2i64(uint64 width,uint64 height){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
    }
    size2i64(int8 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
    }
    size2i64(int16 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
    }
    size2i64(int32 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
    }
    size2i64(int64 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
    }
    size2i64(uint8 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
    }
    size2i64(uint16 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
    }
    size2i64(uint32 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
    }
    size2i64(uint64 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
    }
    //operators

    //=
    size2i64 operator=(size2i8 size){
        //
        this->width=(int64)size.width;
        this->height=(int64)size.height;
        return *this;
    }
    size2i64 operator=(size2i16 size){
        //
        this->width=(int64)size.width;
        this->height=(int64)size.height;
        return *this;
    }
    size2i64 operator=(size2i32 size){
        //
        this->width=(int64)size.width;
        this->height=(int64)size.height;
        return *this;
    }
    size2i64 operator=(size2i64 size){
        //
        this->width=size.width;
        this->height=size.height;
        return *this;
    }
    size2i64 operator=(int8 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        return *this;
    }
    size2i64 operator=(int16 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        return *this;
    }
    size2i64 operator=(int32 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        return *this;
    }
    size2i64 operator=(int64 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        return *this;
    }
    size2i64 operator=(uint8 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        return *this;
    }
    size2i64 operator=(uint16 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        return *this;
    }
    size2i64 operator=(uint32 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        return *this;
    }
    size2i64 operator=(uint64 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        return *this;
    }

    //==
    bool operator==(size2i8 size){
        //
        return (this->width==(int64)size.width&&this->height==(int64)size.height);
    }
    bool operator==(size2i16 size){
        //
        return (this->width==(int64)size.width&&this->height==(int64)size.height);
    }
    bool operator==(size2i32 size){
        //
        return (this->width==(int64)size.width&&this->height==(int64)size.height);
    }
    bool operator==(size2i64 size){
        //
        return (this->width==size.width&&this->height==size.height);
    }
    //!=
    bool operator!=(size2i8 size){
        //
        return (this->width!=(int64)size.width&&this->height!=(int64)size.height);
    }
    bool operator!=(size2i16 size){
        //
        return (this->width!=(int64)size.width&&this->height!=(int64)size.height);
    }
    bool operator!=(size2i32 size){
        //
        return (this->width!=(int64)size.width&&this->height!=(int64)size.height);
    }
    bool operator!=(size2i64 size){
        //
        return (this->width!=size.width||this->height!=size.height);
    }

    //+
    size2i64 operator+(size2i8 size){
        //
        size2i64 ret;
        ret.width=this->width+(int64)size.width;
        ret.height=this->height+(int64)size.height;
        return ret;
    }
    size2i64 operator+(size2i16 size){
        //
        size2i64 ret;
        ret.width=this->width+(int64)size.width;
        ret.height=this->height+(int64)size.height;
        return ret;
    }
    size2i64 operator+(size2i32 size){
        //
        size2i64 ret;
        ret.width=this->width+(int64)size.width;
        ret.height=this->height+(int64)size.height;
        return ret;
    }
    size2i64 operator+(size2i64 size){
        //
        size2i64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size2i64 operator+(int8 n){
        //
        size2i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        return ret;
    }
    size2i64 operator+(int16 n){
        //
        size2i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        return ret;
    }
    size2i64 operator+(int32 n){
        //
        size2i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        return ret;
    }
    size2i64 operator+(int64 n){
        //
        size2i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        return ret;
    }
    size2i64 operator+(uint8 n){
        //
        size2i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        return ret;
    }
    size2i64 operator+(uint16 n){
        //
        size2i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        return ret;
    }
    size2i64 operator+(uint32 n){
        //
        size2i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        return ret;
    }
    size2i64 operator+(uint64 n){
        //
        size2i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        return ret;
    }

    //+=
    void operator+=(size2i8 size){
        //
        this->width+=(int64)size.width;
        this->height+=(int64)size.height;
    }
    void operator+=(size2i16 size){
        //
        this->width+=(int64)size.width;
        this->height+=(int64)size.height;
    }
    void operator+=(size2i32 size){
        //
        this->width+=(int64)size.width;
        this->height+=(int64)size.height;
    }
    void operator+=(size2i64 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(int8 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
    }

    //-
    size2i64 operator-(size2i8 size){
        //
        size2i64 ret;
        ret.width=this->width-(int64)size.width;
        ret.height=this->height-(int64)size.height;
        return ret;
    }
    size2i64 operator-(size2i16 size){
        //
        size2i64 ret;
        ret.width=this->width-(int64)size.width;
        ret.height=this->height-(int64)size.height;
        return ret;
    }
    size2i64 operator-(size2i32 size){
        //
        size2i64 ret;
        ret.width=this->width-(int64)size.width;
        ret.height=this->height-(int64)size.height;
        return ret;
    }
    size2i64 operator-(size2i64 size){
        //
        size2i64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size2i64 operator-(int8 n){
        //
        size2i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        return ret;
    }
    size2i64 operator-(int16 n){
        //
        size2i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        return ret;
    }
    size2i64 operator-(int32 n){
        //
        size2i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        return ret;
    }
    size2i64 operator-(int64 n){
        //
        size2i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        return ret;
    }
    size2i64 operator-(uint8 n){
        //
        size2i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        return ret;
    }
    size2i64 operator-(uint16 n){
        //
        size2i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        return ret;
    }
    size2i64 operator-(uint32 n){
        //
        size2i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        return ret;
    }
    size2i64 operator-(uint64 n){
        //
        size2i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        return ret;
    }

    //-=
    void operator-=(size2i8 size){
        //
        this->width-=(int64)size.width;
        this->height-=(int64)size.height;
    }
    void operator-=(size2i16 size){
        //
        this->width-=(int64)size.width;
        this->height-=(int64)size.height;
    }
    void operator-=(size2i32 size){
        //
        this->width-=(int64)size.width;
        this->height-=(int64)size.height;
    }
    void operator-=(size2i64 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(int8 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
    }

    //*
    size2i64 operator*(size2i8 size){
        //
        size2i64 ret;
        ret.width=this->width*(int64)size.width;
        ret.height=this->height*(int64)size.height;
        return ret;
    }
    size2i64 operator*(size2i16 size){
        //
        size2i64 ret;
        ret.width=this->width*(int64)size.width;
        ret.height=this->height*(int64)size.height;
        return ret;
    }
    size2i64 operator*(size2i32 size){
        //
        size2i64 ret;
        ret.width=this->width*(int64)size.width;
        ret.height=this->height*(int64)size.height;
        return ret;
    }
    size2i64 operator*(size2i64 size){
        //
        size2i64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size2i64 operator*(int8 n){
        //
        size2i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        return ret;
    }
    size2i64 operator*(int16 n){
        //
        size2i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        return ret;
    }
    size2i64 operator*(int32 n){
        //
        size2i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        return ret;
    }
    size2i64 operator*(int64 n){
        //
        size2i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        return ret;
    }
    size2i64 operator*(uint8 n){
        //
        size2i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        return ret;
    }
    size2i64 operator*(uint16 n){
        //
        size2i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        return ret;
    }
    size2i64 operator*(uint32 n){
        //
        size2i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        return ret;
    }
    size2i64 operator*(uint64 n){
        //
        size2i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        return ret;
    }

    //*=
    void operator*=(size2i8 size){
        //
        this->width*=(int64)size.width;
        this->height*=(int64)size.height;
    }
    void operator*=(size2i16 size){
        //
        this->width*=(int64)size.width;
        this->height*=(int64)size.height;
    }
    void operator*=(size2i32 size){
        //
        this->width*=(int64)size.width;
        this->height*=(int64)size.height;
    }
    void operator*=(size2i64 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(int8 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
    }

    //++
    size2i64 operator++(){
        //
        ++this->width;
        ++this->height;
        return size2i64(this->width,this->height);
    }
    size2i64 operator++(int32){
        //
        this->width++;
        this->height++;
        return size2i64(this->width,this->height);
    }

    //--
    size2i64 operator--(){
        //
        --this->width;
        --this->height;
        return size2i64(this->width,this->height);
    }
    size2i64 operator--(int32){
        //
        this->width--;
        this->height--;
        return size2i64(this->width,this->height);
    }

    //
    size2i64 operator()(int8 width,int8 height){
        //
        this->width=width;
        this->height=height;
        return size2i64((int64)this->width,(int64)this->height);
    }
    size2i64 operator()(int16 width,int16 height){
        //
        this->width=width;
        this->height=height;
        return size2i64((int64)this->width,(int64)this->height);
    }
    size2i64 operator()(int32 width,int32 height){
        //
        this->width=width;
        this->height=height;
        return size2i64((int64)this->width,(int64)this->height);
    }
    size2i64 operator()(int64 width,int64 height){
        //
        this->width=width;
        this->height=height;
        return size2i64((int64)this->width,(int64)this->height);
    }
    size2i64 operator()(uint8 width,uint8 height){
        //
        this->width=width;
        this->height=height;
        return size2i64((int64)this->width,(int64)this->height);
    }
    size2i64 operator()(uint16 width,uint16 height){
        //
        this->width=width;
        this->height=height;
        return size2i64((int64)this->width,(int64)this->height);
    }
    size2i64 operator()(uint32 width,uint32 height){
        //
        this->width=width;
        this->height=height;
        return size2i64((int64)this->width,(int64)this->height);
    }
    size2i64 operator()(uint64 width,uint64 height){
        //
        this->width=width;
        this->height=height;
        return size2i64((int64)this->width,(int64)this->height);
    }
};

//size2ui8
class size2ui8{
    //
public:
    uint8 width,height;

    //CONSTRUTOR
    size2ui8(){
        //zera as variaveis
        this->width=this->height=1u;
    }
    size2ui8(uint8 width,uint8 height){
        //zera as variaveis
        this->width=(uint8)width;
        this->height=(uint8)height;
    }
    size2ui8(uint16 width,uint16 height){
        //zera as variaveis
        this->width=(uint8)width;
        this->height=(uint8)height;
    }
    size2ui8(uint32 width,uint32 height){
        //zera as variaveis
        this->width=(uint8)width;
        this->height=(uint8)height;
    }
    size2ui8(uint64 width,uint64 height){
        //zera as variaveis
        this->width=(uint8)width;
        this->height=(uint8)height;
    }
    size2ui8(uint8 size){
        //zera as variaveis
        this->width=(uint8)size;
        this->height=(uint8)size;
    }
    size2ui8(uint16 size){
        //zera as variaveis
        this->width=(uint8)size;
        this->height=(uint8)size;
    }
    size2ui8(uint32 size){
        //zera as variaveis
        this->width=(uint8)size;
        this->height=(uint8)size;
    }
    size2ui8(uint64 size){
        //zera as variaveis
        this->width=(uint8)size;
        this->height=(uint8)size;
    }
    //operators

    //=
    size2ui8 operator=(size2ui8 size){
        //
        this->width=size.width;
        this->height=size.height;
        return *this;
    }
    size2ui8 operator=(uint8 n){
        //
        this->width=(uint8)n;
        this->height=(uint8)n;
        return *this;
    }
    size2ui8 operator=(uint16 n){
        //
        this->width=(uint8)n;
        this->height=(uint8)n;
        return *this;
    }
    size2ui8 operator=(uint32 n){
        //
        this->width=(uint8)n;
        this->height=(uint8)n;
        return *this;
    }
    size2ui8 operator=(uint64 n){
        //
        this->width=(uint8)n;
        this->height=(uint8)n;
        return *this;
    }

    //==
    bool operator==(size2ui8 size){
        //
        return (this->width==size.width&&this->height==size.height);
    }
    //!=
    bool operator!=(size2ui8 size){
        //
        return (this->width!=size.width||this->height!=size.height);
    }

    //+
    size2ui8 operator+(size2ui8 size){
        //
        size2ui8 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size2ui8 operator+(uint8 n){
        //
        size2ui8 ret;
        ret.width=this->width+(uint8)n;
        ret.height=this->height+(uint8)n;
        return ret;
    }
    size2ui8 operator+(uint16 n){
        //
        size2ui8 ret;
        ret.width=this->width+(uint8)n;
        ret.height=this->height+(uint8)n;
        return ret;
    }
    size2ui8 operator+(uint32 n){
        //
        size2ui8 ret;
        ret.width=this->width+(uint8)n;
        ret.height=this->height+(uint8)n;
        return ret;
    }
    size2ui8 operator+(uint64 n){
        //
        size2ui8 ret;
        ret.width=this->width+(uint8)n;
        ret.height=this->height+(uint8)n;
        return ret;
    }

    //+=
    void operator+=(size2ui8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(uint8 n){
        //
        this->width+=(uint8)n;
        this->height+=(uint8)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(uint8)n;
        this->height+=(uint8)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(uint8)n;
        this->height+=(uint8)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(uint8)n;
        this->height+=(uint8)n;
    }

    //-
    size2ui8 operator-(size2ui8 size){
        //
        size2ui8 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size2ui8 operator-(uint8 n){
        //
        size2ui8 ret;
        ret.width=this->width-(uint8)n;
        ret.height=this->height-(uint8)n;
        return ret;
    }
    size2ui8 operator-(uint16 n){
        //
        size2ui8 ret;
        ret.width=this->width-(uint8)n;
        ret.height=this->height-(uint8)n;
        return ret;
    }
    size2ui8 operator-(uint32 n){
        //
        size2ui8 ret;
        ret.width=this->width-(uint8)n;
        ret.height=this->height-(uint8)n;
        return ret;
    }
    size2ui8 operator-(uint64 n){
        //
        size2ui8 ret;
        ret.width=this->width-(uint8)n;
        ret.height=this->height-(uint8)n;
        return ret;
    }

    //-=
    void operator-=(size2ui8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(uint8 n){
        //
        this->width-=(uint8)n;
        this->height-=(uint8)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(uint8)n;
        this->height-=(uint8)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(uint8)n;
        this->height-=(uint8)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(uint8)n;
        this->height-=(uint8)n;
    }

    //*
    size2ui8 operator*(size2ui8 size){
        //
        size2ui8 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size2ui8 operator*(uint8 n){
        //
        size2ui8 ret;
        ret.width=this->width*(uint8)n;
        ret.height=this->height*(uint8)n;
        return ret;
    }
    size2ui8 operator*(uint16 n){
        //
        size2ui8 ret;
        ret.width=this->width*(uint8)n;
        ret.height=this->height*(uint8)n;
        return ret;
    }
    size2ui8 operator*(uint32 n){
        //
        size2ui8 ret;
        ret.width=this->width*(uint8)n;
        ret.height=this->height*(uint8)n;
        return ret;
    }
    size2ui8 operator*(uint64 n){
        //
        size2ui8 ret;
        ret.width=this->width*(uint8)n;
        ret.height=this->height*(uint8)n;
        return ret;
    }

    //*=
    void operator*=(size2ui8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(uint8 n){
        //
        this->width*=(uint8)n;
        this->height*=(uint8)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(uint8)n;
        this->height*=(uint8)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(uint8)n;
        this->height*=(uint8)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(uint8)n;
        this->height*=(uint8)n;
    }

    //++
    size2ui8 operator++(){
        //
        ++this->width;
        ++this->height;
        return size2ui8(this->width,this->height);
    }
    size2ui8 operator++(int32){
        //
        this->width++;
        this->height++;
        return size2ui8(this->width,this->height);
    }

    //--
    size2ui8 operator--(){
        //
        --this->width;
        --this->height;
        return size2ui8(this->width,this->height);
    }
    size2ui8 operator--(int32){
        //
        this->width--;
        this->height--;
        return size2ui8(this->width,this->height);
    }

    //
    size2ui8 operator()(uint8 width,uint8 height){
        //
        this->width=width;
        this->height=height;
        return size2ui8((uint8)this->width,(uint8)this->height);
    }
    size2ui8 operator()(uint16 width,uint16 height){
        //
        this->width=width;
        this->height=height;
        return size2ui8((uint8)this->width,(uint8)this->height);
    }
    size2ui8 operator()(uint32 width,uint32 height){
        //
        this->width=width;
        this->height=height;
        return size2ui8((uint8)this->width,(uint8)this->height);
    }
    size2ui8 operator()(uint64 width,uint64 height){
        //
        this->width=width;
        this->height=height;
        return size2ui8((uint8)this->width,(uint8)this->height);
    }
};

//size2ui16
class size2ui16{
    //
public:
    uint16 width,height;

    //CONSTRUTOR
    size2ui16(){
        //zera as variaveis
        this->width=this->height=1u;
    }
    size2ui16(uint8 width,uint8 height){
        //zera as variaveis
        this->width=(uint16)width;
        this->height=(uint16)height;
    }
    size2ui16(uint16 width,uint16 height){
        //zera as variaveis
        this->width=(uint16)width;
        this->height=(uint16)height;
    }
    size2ui16(uint32 width,uint32 height){
        //zera as variaveis
        this->width=(uint16)width;
        this->height=(uint16)height;
    }
    size2ui16(uint64 width,uint64 height){
        //zera as variaveis
        this->width=(uint16)width;
        this->height=(uint16)height;
    }
    size2ui16(uint8 size){
        //zera as variaveis
        this->width=(uint16)size;
        this->height=(uint16)size;
    }
    size2ui16(uint16 size){
        //zera as variaveis
        this->width=(uint16)size;
        this->height=(uint16)size;
    }
    size2ui16(uint32 size){
        //zera as variaveis
        this->width=(uint16)size;
        this->height=(uint16)size;
    }
    size2ui16(uint64 size){
        //zera as variaveis
        this->width=(uint16)size;
        this->height=(uint16)size;
    }
    //operators

    //=
    size2ui16 operator=(size2ui8 size){
        //
        this->width=(uint16)size.width;
        this->height=(uint16)size.height;
        return *this;
    }
    size2ui16 operator=(size2ui16 size){
        //
        this->width=size.width;
        this->height=size.height;
        return *this;
    }
    size2ui16 operator=(uint8 n){
        //
        this->width=(uint16)n;
        this->height=(uint16)n;
        return *this;
    }
    size2ui16 operator=(uint16 n){
        //
        this->width=(uint16)n;
        this->height=(uint16)n;
        return *this;
    }
    size2ui16 operator=(uint32 n){
        //
        this->width=(uint16)n;
        this->height=(uint16)n;
        return *this;
    }
    size2ui16 operator=(uint64 n){
        //
        this->width=(uint16)n;
        this->height=(uint16)n;
        return *this;
    }

    //==
    bool operator==(size2ui8 size){
        //
        return (this->width==(uint16)size.width&&this->height==(uint16)size.height);
    }
    bool operator==(size2ui16 size){
        //
        return (this->width==size.width&&this->height==size.height);
    }
    //!=
    bool operator!=(size2ui8 size){
        //
        return (this->width!=(uint16)size.width||this->height!=(uint16)size.height);
    }
    bool operator!=(size2ui16 size){
        //
        return (this->width!=size.width||this->height!=size.height);
    }

    //+
    size2ui16 operator+(size2ui8 size){
        //
        size2ui16 ret;
        ret.width=this->width+(uint16)size.width;
        ret.height=this->height+(uint16)size.height;
        return ret;
    }
    size2ui16 operator+(size2ui16 size){
        //
        size2ui16 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size2ui16 operator+(uint8 n){
        //
        size2ui16 ret;
        ret.width=this->width+(uint16)n;
        ret.height=this->height+(uint16)n;
        return ret;
    }
    size2ui16 operator+(uint16 n){
        //
        size2ui16 ret;
        ret.width=this->width+(uint16)n;
        ret.height=this->height+(uint16)n;
        return ret;
    }
    size2ui16 operator+(uint32 n){
        //
        size2ui16 ret;
        ret.width=this->width+(uint16)n;
        ret.height=this->height+(uint16)n;
        return ret;
    }
    size2ui16 operator+(uint64 n){
        //
        size2ui16 ret;
        ret.width=this->width+(uint16)n;
        ret.height=this->height+(uint16)n;
        return ret;
    }

    //+=
    void operator+=(size2ui8 size){
        //
        this->width+=(uint16)size.width;
        this->height+=(uint16)size.height;
    }
    void operator+=(size2ui16 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(uint8 n){
        //
        this->width+=(uint16)n;
        this->height+=(uint16)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(uint16)n;
        this->height+=(uint16)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(uint16)n;
        this->height+=(uint16)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(uint16)n;
        this->height+=(uint16)n;
    }

    //-
    size2ui16 operator-(size2ui8 size){
        //
        size2ui16 ret;
        ret.width=this->width-(uint16)size.width;
        ret.height=this->height-(uint16)size.height;
        return ret;
    }
    size2ui16 operator-(size2ui16 size){
        //
        size2ui16 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size2ui16 operator-(uint8 n){
        //
        size2ui16 ret;
        ret.width=this->width-(uint16)n;
        ret.height=this->height-(uint16)n;
        return ret;
    }
    size2ui16 operator-(uint16 n){
        //
        size2ui16 ret;
        ret.width=this->width-(uint16)n;
        ret.height=this->height-(uint16)n;
        return ret;
    }
    size2ui16 operator-(uint32 n){
        //
        size2ui16 ret;
        ret.width=this->width-(uint16)n;
        ret.height=this->height-(uint16)n;
        return ret;
    }
    size2ui16 operator-(uint64 n){
        //
        size2ui16 ret;
        ret.width=this->width-(uint16)n;
        ret.height=this->height-(uint16)n;
        return ret;
    }

    //-=
    void operator-=(size2ui8 size){
        //
        this->width-=(uint16)size.width;
        this->height-=(uint16)size.height;
    }
    void operator-=(size2ui16 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(uint8 n){
        //
        this->width-=(uint16)n;
        this->height-=(uint16)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(uint16)n;
        this->height-=(uint16)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(uint16)n;
        this->height-=(uint16)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(uint16)n;
        this->height-=(uint16)n;
    }

    //*
    size2ui16 operator*(size2ui8 size){
        //
        size2ui16 ret;
        ret.width=this->width*(uint16)size.width;
        ret.height=this->height*(uint16)size.height;
        return ret;
    }
    size2ui16 operator*(size2ui16 size){
        //
        size2ui16 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size2ui16 operator*(uint8 n){
        //
        size2ui16 ret;
        ret.width=this->width*(uint16)n;
        ret.height=this->height*(uint16)n;
        return ret;
    }
    size2ui16 operator*(uint16 n){
        //
        size2ui16 ret;
        ret.width=this->width*(uint16)n;
        ret.height=this->height*(uint16)n;
        return ret;
    }
    size2ui16 operator*(uint32 n){
        //
        size2ui16 ret;
        ret.width=this->width*(uint16)n;
        ret.height=this->height*(uint16)n;
        return ret;
    }
    size2ui16 operator*(uint64 n){
        //
        size2ui16 ret;
        ret.width=this->width*(uint16)n;
        ret.height=this->height*(uint16)n;
        return ret;
    }

    //*=
    void operator*=(size2ui8 size){
        //
        this->width*=(uint16)size.width;
        this->height*=(uint16)size.height;
    }
    void operator*=(size2ui16 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(uint8 n){
        //
        this->width*=(uint16)n;
        this->height*=(uint16)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(uint16)n;
        this->height*=(uint16)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(uint16)n;
        this->height*=(uint16)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(uint16)n;
        this->height*=(uint16)n;
    }

    //++
    size2ui16 operator++(){
        //
        ++this->width;
        ++this->height;
        return size2ui16(this->width,this->height);
    }
    size2ui16 operator++(int32){
        //
        this->width++;
        this->height++;
        return size2ui16(this->width,this->height);
    }

    //--
    size2ui16 operator--(){
        //
        --this->width;
        --this->height;
        return size2ui16(this->width,this->height);
    }
    size2ui16 operator--(int32){
        //
        this->width--;
        this->height--;
        return size2ui16(this->width,this->height);
    }

    //
    size2ui16 operator()(uint8 width,uint8 height){
        //
        this->width=width;
        this->height=height;
        return size2ui16((uint16)this->width,(uint16)this->height);
    }
    size2ui16 operator()(uint16 width,uint16 height){
        //
        this->width=width;
        this->height=height;
        return size2ui16((uint16)this->width,(uint16)this->height);
    }
    size2ui16 operator()(uint32 width,uint32 height){
        //
        this->width=width;
        this->height=height;
        return size2ui16((uint16)this->width,(uint16)this->height);
    }
    size2ui16 operator()(uint64 width,uint64 height){
        //
        this->width=width;
        this->height=height;
        return size2ui16((uint16)this->width,(uint16)this->height);
    }
};

//size2ui32
class size2ui32{
    //
public:
    uint32 width,height;

    //CONSTRUTOR
    size2ui32(){
        //zera as variaveis
        this->width=this->height=1u;
    }
    size2ui32(uint8 width,uint8 height){
        //zera as variaveis
        this->width=(uint32)width;
        this->height=(uint32)height;
    }
    size2ui32(uint16 width,uint16 height){
        //zera as variaveis
        this->width=(uint32)width;
        this->height=(uint32)height;
    }
    size2ui32(uint32 width,uint32 height){
        //zera as variaveis
        this->width=(uint32)width;
        this->height=(uint32)height;
    }
    size2ui32(uint64 width,uint64 height){
        //zera as variaveis
        this->width=(uint32)width;
        this->height=(uint32)height;
    }
    size2ui32(uint8 size){
        //zera as variaveis
        this->width=(uint32)size;
        this->height=(uint32)size;
    }
    size2ui32(uint16 size){
        //zera as variaveis
        this->width=(uint32)size;
        this->height=(uint32)size;
    }
    size2ui32(uint32 size){
        //zera as variaveis
        this->width=(uint32)size;
        this->height=(uint32)size;
    }
    size2ui32(uint64 size){
        //zera as variaveis
        this->width=(uint32)size;
        this->height=(uint32)size;
    }
    //operators

    //=
    size2ui32 operator=(size2ui8 size){
        //
        this->width=(uint32)size.width;
        this->height=(uint32)size.height;
        return *this;
    }
    size2ui32 operator=(size2ui16 size){
        //
        this->width=(uint32)size.width;
        this->height=(uint32)size.height;
        return *this;
    }
    size2ui32 operator=(size2ui32 size){
        //
        this->width=size.width;
        this->height=size.height;
        return *this;
    }
    size2ui32 operator=(uint8 n){
        //
        this->width=(uint32)n;
        this->height=(uint32)n;
        return *this;
    }
    size2ui32 operator=(uint16 n){
        //
        this->width=(uint32)n;
        this->height=(uint32)n;
        return *this;
    }
    size2ui32 operator=(uint32 n){
        //
        this->width=(uint32)n;
        this->height=(uint32)n;
        return *this;
    }
    size2ui32 operator=(uint64 n){
        //
        this->width=(uint32)n;
        this->height=(uint32)n;
        return *this;
    }

    //==
    bool operator==(size2ui8 size){
        //
        return (this->width==(uint32)size.width&&this->height==(uint32)size.height);
    }
    bool operator==(size2ui16 size){
        //
        return (this->width==(uint32)size.width&&this->height==(uint32)size.height);
    }
    bool operator==(size2ui32 size){
        //
        return (this->width==size.width&&this->height==size.height);
    }
    //!=
    bool operator!=(size2ui8 size){
        //
        return (this->width!=(uint32)size.width||this->height!=(uint32)size.height);
    }
    bool operator!=(size2ui16 size){
        //
        return (this->width!=(uint32)size.width||this->height!=(uint32)size.height);
    }
    bool operator!=(size2ui32 size){
        //
        return (this->width!=size.width||this->height!=size.height);
    }

    //+
    size2ui32 operator+(size2ui8 size){
        //
        size2ui32 ret;
        ret.width=this->width+(uint32)size.width;
        ret.height=this->height+(uint32)size.height;
        return ret;
    }
    size2ui32 operator+(size2ui16 size){
        //
        size2ui32 ret;
        ret.width=this->width+(uint32)size.width;
        ret.height=this->height+(uint32)size.height;
        return ret;
    }
    size2ui32 operator+(size2ui32 size){
        //
        size2ui32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size2ui32 operator+(uint8 n){
        //
        size2ui32 ret;
        ret.width=this->width+(uint32)n;
        ret.height=this->height+(uint32)n;
        return ret;
    }
    size2ui32 operator+(uint16 n){
        //
        size2ui32 ret;
        ret.width=this->width+(uint32)n;
        ret.height=this->height+(uint32)n;
        return ret;
    }
    size2ui32 operator+(uint32 n){
        //
        size2ui32 ret;
        ret.width=this->width+(uint32)n;
        ret.height=this->height+(uint32)n;
        return ret;
    }
    size2ui32 operator+(uint64 n){
        //
        size2ui32 ret;
        ret.width=this->width+(uint32)n;
        ret.height=this->height+(uint32)n;
        return ret;
    }

    //+=
    void operator+=(size2ui8 size){
        //
        this->width+=(uint32)size.width;
        this->height+=(uint32)size.height;
    }
    void operator+=(size2ui16 size){
        //
        this->width+=(uint32)size.width;
        this->height+=(uint32)size.height;
    }
    void operator+=(size2ui32 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(uint8 n){
        //
        this->width+=(uint32)n;
        this->height+=(uint32)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(uint32)n;
        this->height+=(uint32)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(uint32)n;
        this->height+=(uint32)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(uint32)n;
        this->height+=(uint32)n;
    }

    //-
    size2ui32 operator-(size2ui8 size){
        //
        size2ui32 ret;
        ret.width=this->width-(uint32)size.width;
        ret.height=this->height-(uint32)size.height;
        return ret;
    }
    size2ui32 operator-(size2ui16 size){
        //
        size2ui32 ret;
        ret.width=this->width-(uint32)size.width;
        ret.height=this->height-(uint32)size.height;
        return ret;
    }
    size2ui32 operator-(size2ui32 size){
        //
        size2ui32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size2ui32 operator-(uint8 n){
        //
        size2ui32 ret;
        ret.width=this->width-(uint32)n;
        ret.height=this->height-(uint32)n;
        return ret;
    }
    size2ui32 operator-(uint16 n){
        //
        size2ui32 ret;
        ret.width=this->width-(uint32)n;
        ret.height=this->height-(uint32)n;
        return ret;
    }
    size2ui32 operator-(uint32 n){
        //
        size2ui32 ret;
        ret.width=this->width-(uint32)n;
        ret.height=this->height-(uint32)n;
        return ret;
    }
    size2ui32 operator-(uint64 n){
        //
        size2ui32 ret;
        ret.width=this->width-(uint32)n;
        ret.height=this->height-(uint32)n;
        return ret;
    }

    //-=
    void operator-=(size2ui8 size){
        //
        this->width-=(uint32)size.width;
        this->height-=(uint32)size.height;
    }
    void operator-=(size2ui16 size){
        //
        this->width-=(uint32)size.width;
        this->height-=(uint32)size.height;
    }
    void operator-=(size2ui32 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(uint8 n){
        //
        this->width-=(uint32)n;
        this->height-=(uint32)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(uint32)n;
        this->height-=(uint32)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(uint32)n;
        this->height-=(uint32)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(uint32)n;
        this->height-=(uint32)n;
    }

    //*
    size2ui32 operator*(size2ui8 size){
        //
        size2ui32 ret;
        ret.width=this->width*(uint32)size.width;
        ret.height=this->height*(uint32)size.height;
        return ret;
    }
    size2ui32 operator*(size2ui16 size){
        //
        size2ui32 ret;
        ret.width=this->width*(uint32)size.width;
        ret.height=this->height*(uint32)size.height;
        return ret;
    }
    size2ui32 operator*(size2ui32 size){
        //
        size2ui32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size2ui32 operator*(uint8 n){
        //
        size2ui32 ret;
        ret.width=this->width*(uint32)n;
        ret.height=this->height*(uint32)n;
        return ret;
    }
    size2ui32 operator*(uint16 n){
        //
        size2ui32 ret;
        ret.width=this->width*(uint32)n;
        ret.height=this->height*(uint32)n;
        return ret;
    }
    size2ui32 operator*(uint32 n){
        //
        size2ui32 ret;
        ret.width=this->width*(uint32)n;
        ret.height=this->height*(uint32)n;
        return ret;
    }
    size2ui32 operator*(uint64 n){
        //
        size2ui32 ret;
        ret.width=this->width*(uint32)n;
        ret.height=this->height*(uint32)n;
        return ret;
    }

    //*=
    void operator*=(size2ui8 size){
        //
        this->width*=(uint32)size.width;
        this->height*=(uint32)size.height;
    }
    void operator*=(size2ui16 size){
        //
        this->width*=(uint32)size.width;
        this->height*=(uint32)size.height;
    }
    void operator*=(size2ui32 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(uint8 n){
        //
        this->width*=(uint32)n;
        this->height*=(uint32)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(uint32)n;
        this->height*=(uint32)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(uint32)n;
        this->height*=(uint32)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(uint32)n;
        this->height*=(uint32)n;
    }

    //++
    size2ui32 operator++(){
        //
        ++this->width;
        ++this->height;
        return size2ui32(this->width,this->height);
    }
    size2ui32 operator++(int32){
        //
        this->width++;
        this->height++;
        return size2ui32(this->width,this->height);
    }

    //--
    size2ui32 operator--(){
        //
        --this->width;
        --this->height;
        return size2ui32(this->width,this->height);
    }
    size2ui32 operator--(int32){
        //
        this->width--;
        this->height--;
        return size2ui32(this->width,this->height);
    }

    //
    size2ui32 operator()(uint8 width,uint8 height){
        //
        this->width=width;
        this->height=height;
        return size2ui32((uint32)this->width,(uint32)this->height);
    }
    size2ui32 operator()(uint16 width,uint16 height){
        //
        this->width=width;
        this->height=height;
        return size2ui32((uint32)this->width,(uint32)this->height);
    }
    size2ui32 operator()(uint32 width,uint32 height){
        //
        this->width=width;
        this->height=height;
        return size2ui32((uint32)this->width,(uint32)this->height);
    }
    size2ui32 operator()(uint64 width,uint64 height){
        //
        this->width=width;
        this->height=height;
        return size2ui32((uint32)this->width,(uint32)this->height);
    }
};

//size2ui64
class size2ui64{
    //
public:
    uint64 width,height;

    //CONSTRUTOR
    size2ui64(){
        //zera as variaveis
        this->width=this->height=1u;
    }
    size2ui64(uint8 width,uint8 height){
        //zera as variaveis
        this->width=(uint64)width;
        this->height=(uint64)height;
    }
    size2ui64(uint16 width,uint16 height){
        //zera as variaveis
        this->width=(uint64)width;
        this->height=(uint64)height;
    }
    size2ui64(uint32 width,uint32 height){
        //zera as variaveis
        this->width=(uint64)width;
        this->height=(uint64)height;
    }
    size2ui64(uint64 width,uint64 height){
        //zera as variaveis
        this->width=(uint64)width;
        this->height=(uint64)height;
    }
    size2ui64(uint8 size){
        //zera as variaveis
        this->width=(uint64)size;
        this->height=(uint64)size;
    }
    size2ui64(uint16 size){
        //zera as variaveis
        this->width=(uint64)size;
        this->height=(uint64)size;
    }
    size2ui64(uint32 size){
        //zera as variaveis
        this->width=(uint64)size;
        this->height=(uint64)size;
    }
    size2ui64(uint64 size){
        //zera as variaveis
        this->width=(uint64)size;
        this->height=(uint64)size;
    }

    //operators
    //=
    size2ui64 operator=(size2ui8 size){
        //
        this->width=(uint64)size.width;
        this->height=(uint64)size.height;
        return *this;
    }
    size2ui64 operator=(size2ui16 size){
        //
        this->width=(uint64)size.width;
        this->height=(uint64)size.height;
        return *this;
    }
    size2ui64 operator=(size2ui32 size){
        //
        this->width=(uint64)size.width;
        this->height=(uint64)size.height;
        return *this;
    }
    size2ui64 operator=(size2ui64 size){
        //
        this->width=size.width;
        this->height=size.height;
        return *this;
    }
    size2ui64 operator=(uint8 n){
        //
        this->width=(uint64)n;
        this->height=(uint64)n;
        return *this;
    }
    size2ui64 operator=(uint16 n){
        //
        this->width=(uint64)n;
        this->height=(uint64)n;
        return *this;
    }
    size2ui64 operator=(uint32 n){
        //
        this->width=(uint64)n;
        this->height=(uint64)n;
        return *this;
    }
    size2ui64 operator=(uint64 n){
        //
        this->width=(uint64)n;
        this->height=(uint64)n;
        return *this;
    }

    //==
    bool operator==(size2ui8 size){
        //
        return (this->width==(uint64)size.width&&this->height==(uint64)size.height);
    }
    bool operator==(size2ui16 size){
        //
        return (this->width==(uint64)size.width&&this->height==(uint64)size.height);
    }
    bool operator==(size2ui32 size){
        //
        return (this->width==(uint64)size.width&&this->height==(uint64)size.height);
    }
    bool operator==(size2ui64 size){
        //
        return (this->width==size.width&&this->height==size.height);
    }
    //!=
    bool operator!=(size2ui8 size){
        //
        return (this->width!=(uint64)size.width||this->height!=(uint64)size.height);
    }
    bool operator!=(size2ui16 size){
        //
        return (this->width!=(uint64)size.width||this->height!=(uint64)size.height);
    }
    bool operator!=(size2ui32 size){
        //
        return (this->width!=(uint64)size.width||this->height!=(uint64)size.height);
    }
    bool operator!=(size2ui64 size){
        //
        return (this->width!=size.width||this->height!=size.height);
    }

    //+
    size2ui64 operator+(size2ui8 size){
        //
        size2ui64 ret;
        ret.width=this->width+(uint64)size.width;
        ret.height=this->height+(uint64)size.height;
        return ret;
    }
    size2ui64 operator+(size2ui16 size){
        //
        size2ui64 ret;
        ret.width=this->width+(uint64)size.width;
        ret.height=this->height+(uint64)size.height;
        return ret;
    }
    size2ui64 operator+(size2ui32 size){
        //
        size2ui64 ret;
        ret.width=this->width+(uint64)size.width;
        ret.height=this->height+(uint64)size.height;
        return ret;
    }
    size2ui64 operator+(size2ui64 size){
        //
        size2ui64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size2ui64 operator+(uint8 n){
        //
        size2ui64 ret;
        ret.width=this->width+(uint64)n;
        ret.height=this->height+(uint64)n;
        return ret;
    }
    size2ui64 operator+(uint16 n){
        //
        size2ui64 ret;
        ret.width=this->width+(uint64)n;
        ret.height=this->height+(uint64)n;
        return ret;
    }
    size2ui64 operator+(uint32 n){
        //
        size2ui64 ret;
        ret.width=this->width+(uint64)n;
        ret.height=this->height+(uint64)n;
        return ret;
    }
    size2ui64 operator+(uint64 n){
        //
        size2ui64 ret;
        ret.width=this->width+(uint64)n;
        ret.height=this->height+(uint64)n;
        return ret;
    }

    //+=
    void operator+=(size2ui8 size){
        //
        this->width+=(uint64)size.width;
        this->height+=(uint64)size.height;
    }
    void operator+=(size2ui16 size){
        //
        this->width+=(uint64)size.width;
        this->height+=(uint64)size.height;
    }
    void operator+=(size2ui32 size){
        //
        this->width+=(uint64)size.width;
        this->height+=(uint64)size.height;
    }
    void operator+=(size2ui64 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(uint8 n){
        //
        this->width+=(uint64)n;
        this->height+=(uint64)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(uint64)n;
        this->height+=(uint64)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(uint64)n;
        this->height+=(uint64)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(uint64)n;
        this->height+=(uint64)n;
    }

    //-
    size2ui64 operator-(size2ui8 size){
        //
        size2ui64 ret;
        ret.width=this->width-(uint64)size.width;
        ret.height=this->height-(uint64)size.height;
        return ret;
    }
    size2ui64 operator-(size2ui16 size){
        //
        size2ui64 ret;
        ret.width=this->width-(uint64)size.width;
        ret.height=this->height-(uint64)size.height;
        return ret;
    }
    size2ui64 operator-(size2ui32 size){
        //
        size2ui64 ret;
        ret.width=this->width-(uint64)size.width;
        ret.height=this->height-(uint64)size.height;
        return ret;
    }
    size2ui64 operator-(size2ui64 size){
        //
        size2ui64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size2ui64 operator-(uint8 n){
        //
        size2ui64 ret;
        ret.width=this->width-(uint64)n;
        ret.height=this->height-(uint64)n;
        return ret;
    }
    size2ui64 operator-(uint16 n){
        //
        size2ui64 ret;
        ret.width=this->width-(uint64)n;
        ret.height=this->height-(uint64)n;
        return ret;
    }
    size2ui64 operator-(uint32 n){
        //
        size2ui64 ret;
        ret.width=this->width-(uint64)n;
        ret.height=this->height-(uint64)n;
        return ret;
    }
    size2ui64 operator-(uint64 n){
        //
        size2ui64 ret;
        ret.width=this->width-(uint64)n;
        ret.height=this->height-(uint64)n;
        return ret;
    }

    //-=
    void operator-=(size2ui8 size){
        //
        this->width-=(uint64)size.width;
        this->height-=(uint64)size.height;
    }
    void operator-=(size2ui16 size){
        //
        this->width-=(uint64)size.width;
        this->height-=(uint64)size.height;
    }
    void operator-=(size2ui32 size){
        //
        this->width-=(uint64)size.width;
        this->height-=(uint64)size.height;
    }
    void operator-=(size2ui64 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(uint8 n){
        //
        this->width-=(uint64)n;
        this->height-=(uint64)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(uint64)n;
        this->height-=(uint64)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(uint64)n;
        this->height-=(uint64)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(uint64)n;
        this->height-=(uint64)n;
    }

    //*
    size2ui64 operator*(size2ui8 size){
        //
        size2ui64 ret;
        ret.width=this->width*(uint64)size.width;
        ret.height=this->height*(uint64)size.height;
        return ret;
    }
    size2ui64 operator*(size2ui16 size){
        //
        size2ui64 ret;
        ret.width=this->width*(uint64)size.width;
        ret.height=this->height*(uint64)size.height;
        return ret;
    }
    size2ui64 operator*(size2ui32 size){
        //
        size2ui64 ret;
        ret.width=this->width*(uint64)size.width;
        ret.height=this->height*(uint64)size.height;
        return ret;
    }
    size2ui64 operator*(size2ui64 size){
        //
        size2ui64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size2ui64 operator*(uint8 n){
        //
        size2ui64 ret;
        ret.width=this->width*(uint64)n;
        ret.height=this->height*(uint64)n;
        return ret;
    }
    size2ui64 operator*(uint16 n){
        //
        size2ui64 ret;
        ret.width=this->width*(uint64)n;
        ret.height=this->height*(uint64)n;
        return ret;
    }
    size2ui64 operator*(uint32 n){
        //
        size2ui64 ret;
        ret.width=this->width*(uint64)n;
        ret.height=this->height*(uint64)n;
        return ret;
    }
    size2ui64 operator*(uint64 n){
        //
        size2ui64 ret;
        ret.width=this->width*(uint64)n;
        ret.height=this->height*(uint64)n;
        return ret;
    }

    //*=
    void operator*=(size2ui8 size){
        //
        this->width*=(uint64)size.width;
        this->height*=(uint64)size.height;
    }
    void operator*=(size2ui16 size){
        //
        this->width*=(uint64)size.width;
        this->height*=(uint64)size.height;
    }
    void operator*=(size2ui32 size){
        //
        this->width*=(uint64)size.width;
        this->height*=(uint64)size.height;
    }
    void operator*=(size2ui64 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(uint8 n){
        //
        this->width*=(uint64)n;
        this->height*=(uint64)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(uint64)n;
        this->height*=(uint64)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(uint64)n;
        this->height*=(uint64)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(uint64)n;
        this->height*=(uint64)n;
    }

    //++
    size2ui64 operator++(){
        //
        ++this->width;
        ++this->height;
        return size2ui64(this->width,this->height);
    }
    size2ui64 operator++(int32){
        //
        this->width++;
        this->height++;
        return size2ui64(this->width,this->height);
    }

    //--
    size2ui64 operator--(){
        //
        --this->width;
        --this->height;
        return size2ui64(this->width,this->height);
    }
    size2ui64 operator--(int32){
        //
        this->width--;
        this->height--;
        return size2ui64(this->width,this->height);
    }

    //
    size2ui64 operator()(uint8 width,uint8 height){
        //
        this->width=width;
        this->height=height;
        return size2ui64((uint64)this->width,(uint64)this->height);
    }
    size2ui64 operator()(uint16 width,uint16 height){
        //
        this->width=width;
        this->height=height;
        return size2ui64((uint64)this->width,(uint64)this->height);
    }
    size2ui64 operator()(uint32 width,uint32 height){
        //
        this->width=width;
        this->height=height;
        return size2ui64((uint64)this->width,(uint64)this->height);
    }
    size2ui64 operator()(uint64 width,uint64 height){
        //
        this->width=width;
        this->height=height;
        return size2ui64((uint64)this->width,(uint64)this->height);
    }
};

//size2f32
class size2f32{
    //
public:
    edk::float32 width,height;

    //CONSTRUTOR
    size2f32(){
        //zera as variaveis
        this->width=this->height=1.f;
    }
    size2f32(edk::float32 width,edk::float32 height){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
    }
    size2f32(edk::float64 width,edk::float64 height){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
    }
    size2f32(int8 width,int8 height){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
    }
    size2f32(int16 width,int16 height){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
    }
    size2f32(int32 width,int32 height){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
    }
    size2f32(int64 width,int64 height){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
    }
    size2f32(uint8 width,uint8 height){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
    }
    size2f32(uint16 width,uint16 height){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
    }
    size2f32(uint32 width,uint32 height){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
    }
    size2f32(uint64 width,uint64 height){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
    }
    size2f32(edk::float32 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
    }
    size2f32(edk::float64 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
    }
    size2f32(int8 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
    }
    size2f32(int16 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
    }
    size2f32(int32 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
    }
    size2f32(int64 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
    }
    size2f32(uint8 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
    }
    size2f32(uint16 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
    }
    size2f32(uint32 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
    }
    size2f32(uint64 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
    }
    //operators

    //=
    size2f32 operator=(size2f32 size){
        //
        this->width=size.width;
        this->height=size.height;
        return *this;
    }
    size2f32 operator=(edk::float32 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        return *this;
    }
    size2f32 operator=(edk::float64 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        return *this;
    }
    size2f32 operator=(int8 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        return *this;
    }
    size2f32 operator=(int16 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        return *this;
    }
    size2f32 operator=(int32 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        return *this;
    }
    size2f32 operator=(int64 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        return *this;
    }
    size2f32 operator=(uint8 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        return *this;
    }
    size2f32 operator=(uint16 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        return *this;
    }
    size2f32 operator=(uint32 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        return *this;
    }
    size2f32 operator=(uint64 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        return *this;
    }

    //==
    bool operator==(size2f32 size){
        //
        return (this->width==size.width&&this->height==size.height);
    }
    //!=
    bool operator!=(size2f32 size){
        //
        return (this->width!=size.width||this->height!=size.height);
    }

    //+
    size2f32 operator+(size2f32 size){
        //
        size2f32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size2f32 operator+(edk::float32 n){
        //
        size2f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        return ret;
    }
    size2f32 operator+(edk::float64 n){
        //
        size2f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        return ret;
    }
    size2f32 operator+(int8 n){
        //
        size2f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        return ret;
    }
    size2f32 operator+(int16 n){
        //
        size2f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        return ret;
    }
    size2f32 operator+(int32 n){
        //
        size2f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        return ret;
    }
    size2f32 operator+(int64 n){
        //
        size2f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        return ret;
    }
    size2f32 operator+(uint8 n){
        //
        size2f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        return ret;
    }
    size2f32 operator+(uint16 n){
        //
        size2f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        return ret;
    }
    size2f32 operator+(uint32 n){
        //
        size2f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        return ret;
    }
    size2f32 operator+(uint64 n){
        //
        size2f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        return ret;
    }

    //+=
    void operator+=(size2f32 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(edk::float32 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
    }
    void operator+=(edk::float64 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
    }
    void operator+=(int8 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
    }

    //-
    size2f32 operator-(size2f32 size){
        //
        size2f32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size2f32 operator-(edk::float32 n){
        //
        size2f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        return ret;
    }
    size2f32 operator-(edk::float64 n){
        //
        size2f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        return ret;
    }
    size2f32 operator-(int8 n){
        //
        size2f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        return ret;
    }
    size2f32 operator-(int16 n){
        //
        size2f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        return ret;
    }
    size2f32 operator-(int32 n){
        //
        size2f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        return ret;
    }
    size2f32 operator-(int64 n){
        //
        size2f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        return ret;
    }
    size2f32 operator-(uint8 n){
        //
        size2f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        return ret;
    }
    size2f32 operator-(uint16 n){
        //
        size2f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        return ret;
    }
    size2f32 operator-(uint32 n){
        //
        size2f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        return ret;
    }
    size2f32 operator-(uint64 n){
        //
        size2f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        return ret;
    }

    //-=
    void operator-=(size2f32 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(edk::float32 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
    }
    void operator-=(edk::float64 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
    }
    void operator-=(int8 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
    }

    //*
    size2f32 operator*(size2f32 size){
        //
        size2f32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size2f32 operator*(edk::float32 n){
        //
        size2f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        return ret;
    }
    size2f32 operator*(edk::float64 n){
        //
        size2f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        return ret;
    }
    size2f32 operator*(int8 n){
        //
        size2f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        return ret;
    }
    size2f32 operator*(int16 n){
        //
        size2f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        return ret;
    }
    size2f32 operator*(int32 n){
        //
        size2f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        return ret;
    }
    size2f32 operator*(int64 n){
        //
        size2f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        return ret;
    }
    size2f32 operator*(uint8 n){
        //
        size2f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        return ret;
    }
    size2f32 operator*(uint16 n){
        //
        size2f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        return ret;
    }
    size2f32 operator*(uint32 n){
        //
        size2f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        return ret;
    }
    size2f32 operator*(uint64 n){
        //
        size2f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        return ret;
    }

    //*=
    void operator*=(size2f32 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(edk::float32 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
    }
    void operator*=(edk::float64 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
    }
    void operator*=(int8 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
    }

    // /
    size2f32 operator/(size2f32 size){
        //
        size2f32 ret;
        ret.width=this->width/size.width;
        ret.height=this->height/size.height;
        return ret;
    }
    size2f32 operator/(edk::float32 n){
        //
        size2f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        return ret;
    }
    size2f32 operator/(edk::float64 n){
        //
        size2f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        return ret;
    }
    size2f32 operator/(int8 n){
        //
        size2f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        return ret;
    }
    size2f32 operator/(int16 n){
        //
        size2f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        return ret;
    }
    size2f32 operator/(int32 n){
        //
        size2f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        return ret;
    }
    size2f32 operator/(int64 n){
        //
        size2f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        return ret;
    }
    size2f32 operator/(uint8 n){
        //
        size2f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        return ret;
    }
    size2f32 operator/(uint16 n){
        //
        size2f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        return ret;
    }
    size2f32 operator/(uint32 n){
        //
        size2f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        return ret;
    }
    size2f32 operator/(uint64 n){
        //
        size2f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        return ret;
    }

    // /=

    void operator/=(size2f32 size){
        //
        this->width/=size.width;
        this->height/=size.height;
    }
    void operator/=(edk::float32 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
    }
    void operator/=(edk::float64 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
    }
    void operator/=(int8 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
    }
    void operator/=(int16 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
    }
    void operator/=(int32 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
    }
    void operator/=(int64 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
    }
    void operator/=(uint8 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
    }
    void operator/=(uint16 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
    }
    void operator/=(uint32 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
    }
    void operator/=(uint64 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
    }

    //++
    size2f32 operator++(){
        //
        ++this->width;
        ++this->height;
        return size2f32(this->width,this->height);
    }
    size2f32 operator++(int32){
        //
        this->width++;
        this->height++;
        return size2f32(this->width,this->height);
    }

    //--
    size2f32 operator--(){
        //
        --this->width;
        --this->height;
        return size2f32(this->width,this->height);
    }
    size2f32 operator--(int32){
        //
        this->width--;
        this->height--;
        return size2f32(this->width,this->height);
    }

    //
    size2f32 operator()(edk::float32 width,edk::float32 height){
        //
        this->width=width;
        this->height=height;
        return size2f32((edk::float32)this->width,(edk::float32)this->height);
    }
    size2f32 operator()(edk::float64 width,edk::float64 height){
        //
        this->width=width;
        this->height=height;
        return size2f32((edk::float32)this->width,(edk::float32)this->height);
    }
    size2f32 operator()(int8 width,int8 height){
        //
        this->width=width;
        this->height=height;
        return size2f32((edk::float32)this->width,(edk::float32)this->height);
    }
    size2f32 operator()(int16 width,int16 height){
        //
        this->width=width;
        this->height=height;
        return size2f32((edk::float32)this->width,(edk::float32)this->height);
    }
    size2f32 operator()(int32 width,int32 height){
        //
        this->width=width;
        this->height=height;
        return size2f32((edk::float32)this->width,(edk::float32)this->height);
    }
    size2f32 operator()(int64 width,int64 height){
        //
        this->width=width;
        this->height=height;
        return size2f32((edk::float32)this->width,(edk::float32)this->height);
    }
    size2f32 operator()(uint8 width,uint8 height){
        //
        this->width=width;
        this->height=height;
        return size2f32((edk::float32)this->width,(edk::float32)this->height);
    }
    size2f32 operator()(uint16 width,uint16 height){
        //
        this->width=width;
        this->height=height;
        return size2f32((edk::float32)this->width,(edk::float32)this->height);
    }
    size2f32 operator()(uint32 width,uint32 height){
        //
        this->width=width;
        this->height=height;
        return size2f32((edk::float32)this->width,(edk::float32)this->height);
    }
    size2f32 operator()(uint64 width,uint64 height){
        //
        this->width=width;
        this->height=height;
        return size2f32((edk::float32)this->width,(edk::float32)this->height);
    }
};

//size2f64
class size2f64{
    //
public:
    edk::float64 width,height;

    //CONSTRUTOR
    size2f64(){
        //zera as variaveis
        this->width=this->height=1.0;
    }
    size2f64(edk::float32 width,edk::float32 height){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
    }
    size2f64(edk::float64 width,edk::float64 height){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
    }
    size2f64(int8 width,int8 height){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
    }
    size2f64(int16 width,int16 height){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
    }
    size2f64(int32 width,int32 height){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
    }
    size2f64(int64 width,int64 height){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
    }
    size2f64(uint8 width,uint8 height){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
    }
    size2f64(uint16 width,uint16 height){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
    }
    size2f64(uint32 width,uint32 height){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
    }
    size2f64(uint64 width,uint64 height){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
    }
    size2f64(edk::float32 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
    }
    size2f64(edk::float64 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
    }
    size2f64(int8 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
    }
    size2f64(int16 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
    }
    size2f64(int32 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
    }
    size2f64(int64 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
    }
    size2f64(uint8 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
    }
    size2f64(uint16 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
    }
    size2f64(uint32 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
    }
    size2f64(uint64 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
    }
    //operators

    //=
    size2f64 operator=(size2f64 size){
        //
        this->width=size.width;
        this->height=size.height;
        return *this;
    }
    size2f64 operator=(edk::float32 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        return *this;
    }
    size2f64 operator=(edk::float64 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        return *this;
    }
    size2f64 operator=(int8 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        return *this;
    }
    size2f64 operator=(int16 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        return *this;
    }
    size2f64 operator=(int32 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        return *this;
    }
    size2f64 operator=(int64 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        return *this;
    }
    size2f64 operator=(uint8 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        return *this;
    }
    size2f64 operator=(uint16 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        return *this;
    }
    size2f64 operator=(uint32 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        return *this;
    }
    size2f64 operator=(uint64 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        return *this;
    }

    //==
    bool operator==(size2f64 size){
        //
        return (this->width==size.width&&this->height==size.height);
    }
    //!=
    bool operator!=(size2f64 size){
        //
        return (this->width!=size.width||this->height!=size.height);
    }

    //+
    size2f64 operator+(size2f64 size){
        //
        size2f64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size2f64 operator+(edk::float32 n){
        //
        size2f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        return ret;
    }
    size2f64 operator+(edk::float64 n){
        //
        size2f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        return ret;
    }
    size2f64 operator+(int8 n){
        //
        size2f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        return ret;
    }
    size2f64 operator+(int16 n){
        //
        size2f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        return ret;
    }
    size2f64 operator+(int32 n){
        //
        size2f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        return ret;
    }
    size2f64 operator+(int64 n){
        //
        size2f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        return ret;
    }
    size2f64 operator+(uint8 n){
        //
        size2f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        return ret;
    }
    size2f64 operator+(uint16 n){
        //
        size2f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        return ret;
    }
    size2f64 operator+(uint32 n){
        //
        size2f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        return ret;
    }
    size2f64 operator+(uint64 n){
        //
        size2f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        return ret;
    }

    //+=
    void operator+=(size2f64 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(edk::float32 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
    }
    void operator+=(edk::float64 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
    }
    void operator+=(int8 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
    }

    //-
    size2f64 operator-(size2f64 size){
        //
        size2f64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size2f64 operator-(edk::float32 n){
        //
        size2f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        return ret;
    }
    size2f64 operator-(edk::float64 n){
        //
        size2f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        return ret;
    }
    size2f64 operator-(int8 n){
        //
        size2f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        return ret;
    }
    size2f64 operator-(int16 n){
        //
        size2f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        return ret;
    }
    size2f64 operator-(int32 n){
        //
        size2f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        return ret;
    }
    size2f64 operator-(int64 n){
        //
        size2f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        return ret;
    }
    size2f64 operator-(uint8 n){
        //
        size2f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        return ret;
    }
    size2f64 operator-(uint16 n){
        //
        size2f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        return ret;
    }
    size2f64 operator-(uint32 n){
        //
        size2f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        return ret;
    }
    size2f64 operator-(uint64 n){
        //
        size2f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        return ret;
    }

    //-=
    void operator-=(size2f64 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(edk::float32 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
    }
    void operator-=(edk::float64 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
    }
    void operator-=(int8 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
    }

    //*
    size2f64 operator*(size2f64 size){
        //
        size2f64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size2f64 operator*(edk::float32 n){
        //
        size2f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        return ret;
    }
    size2f64 operator*(edk::float64 n){
        //
        size2f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        return ret;
    }
    size2f64 operator*(int8 n){
        //
        size2f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        return ret;
    }
    size2f64 operator*(int16 n){
        //
        size2f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        return ret;
    }
    size2f64 operator*(int32 n){
        //
        size2f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        return ret;
    }
    size2f64 operator*(int64 n){
        //
        size2f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        return ret;
    }
    size2f64 operator*(uint8 n){
        //
        size2f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        return ret;
    }
    size2f64 operator*(uint16 n){
        //
        size2f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        return ret;
    }
    size2f64 operator*(uint32 n){
        //
        size2f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        return ret;
    }
    size2f64 operator*(uint64 n){
        //
        size2f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        return ret;
    }

    //*=
    void operator*=(size2f64 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(edk::float32 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
    }
    void operator*=(edk::float64 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
    }
    void operator*=(int8 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
    }

    // /
    size2f64 operator/(size2f64 size){
        //
        size2f64 ret;
        ret.width=this->width/size.width;
        ret.height=this->height/size.height;
        return ret;
    }
    size2f64 operator/(edk::float32 n){
        //
        size2f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        return ret;
    }
    size2f64 operator/(edk::float64 n){
        //
        size2f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        return ret;
    }
    size2f64 operator/(int8 n){
        //
        size2f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        return ret;
    }
    size2f64 operator/(int16 n){
        //
        size2f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        return ret;
    }
    size2f64 operator/(int32 n){
        //
        size2f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        return ret;
    }
    size2f64 operator/(int64 n){
        //
        size2f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        return ret;
    }
    size2f64 operator/(uint8 n){
        //
        size2f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        return ret;
    }
    size2f64 operator/(uint16 n){
        //
        size2f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        return ret;
    }
    size2f64 operator/(uint32 n){
        //
        size2f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        return ret;
    }
    size2f64 operator/(uint64 n){
        //
        size2f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        return ret;
    }

    // /=

    void operator/=(size2f64 size){
        //
        this->width/=size.width;
        this->height/=size.height;
    }
    void operator/=(edk::float32 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
    }
    void operator/=(edk::float64 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
    }
    void operator/=(int8 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
    }
    void operator/=(int16 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
    }
    void operator/=(int32 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
    }
    void operator/=(int64 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
    }
    void operator/=(uint8 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
    }
    void operator/=(uint16 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
    }
    void operator/=(uint32 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
    }
    void operator/=(uint64 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
    }

    //++
    size2f64 operator++(){
        //
        ++this->width;
        ++this->height;
        return size2f64(this->width,this->height);
    }
    size2f64 operator++(int32){
        //
        this->width++;
        this->height++;
        return size2f64(this->width,this->height);
    }

    //--
    size2f64 operator--(){
        //
        --this->width;
        --this->height;
        return size2f64(this->width,this->height);
    }
    size2f64 operator--(int32){
        //
        this->width--;
        this->height--;
        return size2f64(this->width,this->height);
    }

    //
    size2f64 operator()(edk::float32 width,edk::float32 height){
        //
        this->width=width;
        this->height=height;
        return size2f64((edk::float64)this->width,(edk::float64)this->height);
    }
    size2f64 operator()(edk::float64 width,edk::float64 height){
        //
        this->width=width;
        this->height=height;
        return size2f64((edk::float64)this->width,(edk::float64)this->height);
    }
    size2f64 operator()(int8 width,int8 height){
        //
        this->width=width;
        this->height=height;
        return size2f64((edk::float64)this->width,(edk::float64)this->height);
    }
    size2f64 operator()(int16 width,int16 height){
        //
        this->width=width;
        this->height=height;
        return size2f64((edk::float64)this->width,(edk::float64)this->height);
    }
    size2f64 operator()(int32 width,int32 height){
        //
        this->width=width;
        this->height=height;
        return size2f64((edk::float64)this->width,(edk::float64)this->height);
    }
    size2f64 operator()(int64 width,int64 height){
        //
        this->width=width;
        this->height=height;
        return size2f64((edk::float64)this->width,(edk::float64)this->height);
    }
    size2f64 operator()(uint8 width,uint8 height){
        //
        this->width=width;
        this->height=height;
        return size2f64((edk::float64)this->width,(edk::float64)this->height);
    }
    size2f64 operator()(uint16 width,uint16 height){
        //
        this->width=width;
        this->height=height;
        return size2f64((edk::float64)this->width,(edk::float64)this->height);
    }
    size2f64 operator()(uint32 width,uint32 height){
        //
        this->width=width;
        this->height=height;
        return size2f64((edk::float64)this->width,(edk::float64)this->height);
    }
    size2f64 operator()(uint64 width,uint64 height){
        //
        this->width=width;
        this->height=height;
        return size2f64((edk::float64)this->width,(edk::float64)this->height);
    }
};

}//end namespace

#endif // TYPESIZE2_H
