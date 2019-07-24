#ifndef EDK_TYPESIZE3_H
#define EDK_TYPESIZE3_H

/*
Library C++ typeSize3 - 3D size types used in Edk Game Engine
Copyright (C) 2013 Eduardo Moura Sales Martins
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
email: edimartin@gmail.com.br

AV: Walmor M. de Souza 392 Casa
Gravatai RS Brazil 94065100
*/

#ifdef printMessages
#warning "Inside TypesSize3"
#endif

#pragma once
#include "TypeVars.h"
#include "TypeSize2.h"

#ifdef printMessages
#warning "    Compiling TypesSize3"
#endif

namespace edk{
//
//size3i8
class size3i8{
    //
public:
    int8 width,height,length;

    //CONSTRUTOR
    size3i8(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3i8(int8 width,int8 height,int8 length){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
        this->length=(int8)length;
    }
    size3i8(int16 width,int16 height,int16 length){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
        this->length=(int8)length;
    }
    size3i8(int32 width,int32 height,int32 length){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
        this->length=(int8)length;
    }
    size3i8(int64 width,int64 height,int64 length){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
        this->length=(int8)length;
    }
    size3i8(uint8 width,uint8 height,uint8 length){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
        this->length=(int8)length;
    }
    size3i8(uint16 width,uint16 height,uint16 length){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
        this->length=(int8)length;
    }
    size3i8(uint32 width,uint32 height,uint32 length){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
        this->length=(int8)length;
    }
    size3i8(uint64 width,uint64 height,uint64 length){
        //zera as variaveis
        this->width=(int8)width;
        this->height=(int8)height;
        this->length=(int8)length;
    }
    size3i8(int8 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
        this->length=(int8)size;
    }
    size3i8(int16 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
        this->length=(int8)size;
    }
    size3i8(int32 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
        this->length=(int8)size;
    }
    size3i8(int64 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
        this->length=(int8)size;
    }
    size3i8(uint8 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
        this->length=(int8)size;
    }
    size3i8(uint16 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
        this->length=(int8)size;
    }
    size3i8(uint32 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
        this->length=(int8)size;
    }
    size3i8(uint64 size){
        //zera as variaveis
        this->width=(int8)size;
        this->height=(int8)size;
        this->length=(int8)size;
    }
    //operators

    //=
    size3i8 operator=(size3i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    size3i8 operator=(size2i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=(int8)0;
        return *this;
    }
    size3i8 operator=(int8 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        this->length=(int8)n;
        return *this;
    }
    size3i8 operator=(int16 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        this->length=(int8)n;
        return *this;
    }
    size3i8 operator=(int32 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        this->length=(int8)n;
        return *this;
    }
    size3i8 operator=(int64 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        this->length=(int8)n;
        return *this;
    }
    size3i8 operator=(uint8 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        this->length=(int8)n;
        return *this;
    }
    size3i8 operator=(uint16 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        this->length=(int8)n;
        return *this;
    }
    size3i8 operator=(uint32 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        this->length=(int8)n;
        return *this;
    }
    size3i8 operator=(uint64 n){
        //
        this->width=(int8)n;
        this->height=(int8)n;
        this->length=(int8)n;
        return *this;
    }

    //==
    bool operator==(size3i8 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    bool operator!=(size3i8 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    size3i8 operator+(size3i8 size){
        //
        size3i8 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    size3i8 operator+(size2i8 size){
        //
        size3i8 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size3i8 operator+(int8 n){
        //
        size3i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        ret.length=this->length+(int8)n;
        return ret;
    }
    size3i8 operator+(int16 n){
        //
        size3i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        ret.length=this->length+(int8)n;
        return ret;
    }
    size3i8 operator+(int32 n){
        //
        size3i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        ret.length=this->length+(int8)n;
        return ret;
    }
    size3i8 operator+(int64 n){
        //
        size3i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        ret.length=this->length+(int8)n;
        return ret;
    }
    size3i8 operator+(uint8 n){
        //
        size3i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        ret.length=this->length+(int8)n;
        return ret;
    }
    size3i8 operator+(uint16 n){
        //
        size3i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        ret.length=this->length+(int8)n;
        return ret;
    }
    size3i8 operator+(uint32 n){
        //
        size3i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        ret.length=this->length+(int8)n;
        return ret;
    }
    size3i8 operator+(uint64 n){
        //
        size3i8 ret;
        ret.width=this->width+(int8)n;
        ret.height=this->height+(int8)n;
        ret.length=this->length+(int8)n;
        return ret;
    }

    //+=
    void operator+=(size3i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    void operator+=(size2i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(int8 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
        this->length+=(int8)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
        this->length+=(int8)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
        this->length+=(int8)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
        this->length+=(int8)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
        this->length+=(int8)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
        this->length+=(int8)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
        this->length+=(int8)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(int8)n;
        this->height+=(int8)n;
        this->length+=(int8)n;
    }

    //-
    size3i8 operator-(size3i8 size){
        //
        size3i8 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    size3i8 operator-(size2i8 size){
        //
        size3i8 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size3i8 operator-(int8 n){
        //
        size3i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        ret.length=this->length-(int8)n;
        return ret;
    }
    size3i8 operator-(int16 n){
        //
        size3i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        ret.length=this->length-(int8)n;
        return ret;
    }
    size3i8 operator-(int32 n){
        //
        size3i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        ret.length=this->length-(int8)n;
        return ret;
    }
    size3i8 operator-(int64 n){
        //
        size3i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        ret.length=this->length-(int8)n;
        return ret;
    }
    size3i8 operator-(uint8 n){
        //
        size3i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        ret.length=this->length-(int8)n;
        return ret;
    }
    size3i8 operator-(uint16 n){
        //
        size3i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        ret.length=this->length-(int8)n;
        return ret;
    }
    size3i8 operator-(uint32 n){
        //
        size3i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        ret.length=this->length-(int8)n;
        return ret;
    }
    size3i8 operator-(uint64 n){
        //
        size3i8 ret;
        ret.width=this->width-(int8)n;
        ret.height=this->height-(int8)n;
        ret.length=this->length-(int8)n;
        return ret;
    }

    //-=
    void operator-=(size3i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    void operator-=(size2i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(int8 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
        this->length-=(int8)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
        this->length-=(int8)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
        this->length-=(int8)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
        this->length-=(int8)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
        this->length-=(int8)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
        this->length-=(int8)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
        this->length-=(int8)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(int8)n;
        this->height-=(int8)n;
        this->length-=(int8)n;
    }

    //*
    size3i8 operator*(size3i8 size){
        //
        size3i8 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    size3i8 operator*(size2i8 size){
        //
        size3i8 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size3i8 operator*(int8 n){
        //
        size3i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        ret.length=this->length*(int8)n;
        return ret;
    }
    size3i8 operator*(int16 n){
        //
        size3i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        ret.length=this->length*(int8)n;
        return ret;
    }
    size3i8 operator*(int32 n){
        //
        size3i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        ret.length=this->length*(int8)n;
        return ret;
    }
    size3i8 operator*(int64 n){
        //
        size3i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        ret.length=this->length*(int8)n;
        return ret;
    }
    size3i8 operator*(uint8 n){
        //
        size3i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        ret.length=this->length*(int8)n;
        return ret;
    }
    size3i8 operator*(uint16 n){
        //
        size3i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        ret.length=this->length*(int8)n;
        return ret;
    }
    size3i8 operator*(uint32 n){
        //
        size3i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        ret.length=this->length*(int8)n;
        return ret;
    }
    size3i8 operator*(uint64 n){
        //
        size3i8 ret;
        ret.width=this->width*(int8)n;
        ret.height=this->height*(int8)n;
        ret.length=this->length*(int8)n;
        return ret;
    }

    //*=
    void operator*=(size3i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    void operator*=(size2i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(int8 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
        this->length*=(int8)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
        this->length*=(int8)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
        this->length*=(int8)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
        this->length*=(int8)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
        this->length*=(int8)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
        this->length*=(int8)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
        this->length*=(int8)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(int8)n;
        this->height*=(int8)n;
        this->length*=(int8)n;
    }

    //++
    size3i8 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return size3i8(this->width,this->height,this->length);
    }
    size3i8 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return size3i8(this->width,this->height,this->length);
    }

    //--
    size3i8 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return size3i8(this->width,this->height,this->length);
    }
    size3i8 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return size3i8(this->width,this->height,this->length);
    }

    //
    size3i8 operator()(int8 width,int8 height,int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i8((int8)this->width,(int8)this->height,(int8)this->length);
    }
    size3i8 operator()(int16 width,int16 height,int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i8((int8)this->width,(int8)this->height,(int8)this->length);
    }
    size3i8 operator()(int32 width,int32 height,int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i8((int8)this->width,(int8)this->height,(int8)this->length);
    }
    size3i8 operator()(int64 width,int64 height,int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i8((int8)this->width,(int8)this->height,(int8)this->length);
    }
    size3i8 operator()(uint8 width,uint8 height,uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i8((int8)this->width,(int8)this->height,(int8)this->length);
    }
    size3i8 operator()(uint16 width,uint16 height,uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i8((int8)this->width,(int8)this->height,(int8)this->length);
    }
    size3i8 operator()(uint32 width,uint32 height,uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i8((int8)this->width,(int8)this->height,(int8)this->length);
    }
    size3i8 operator()(uint64 width,uint64 height,uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i8((int8)this->width,(int8)this->height,(int8)this->length);
    }
};

//size3i16
class size3i16{
    //
public:
    int16 width,height,length;

    //CONSTRUTOR
    size3i16(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3i16(int8 width,int8 height,int8 length){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
        this->length=(int16)length;
    }
    size3i16(int16 width,int16 height,int16 length){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
        this->length=(int16)length;
    }
    size3i16(int32 width,int32 height,int32 length){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
        this->length=(int16)length;
    }
    size3i16(int64 width,int64 height,int64 length){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
        this->length=(int16)length;
    }
    size3i16(uint8 width,uint8 height,uint8 length){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
        this->length=(int16)length;
    }
    size3i16(uint16 width,uint16 height,uint16 length){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
        this->length=(int16)length;
    }
    size3i16(uint32 width,uint32 height,uint32 length){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
        this->length=(int16)length;
    }
    size3i16(uint64 width,uint64 height,uint64 length){
        //zera as variaveis
        this->width=(int16)width;
        this->height=(int16)height;
        this->length=(int16)length;
    }
    size3i16(int8 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
        this->length=(int16)size;
    }
    size3i16(int16 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
        this->length=(int16)size;
    }
    size3i16(int32 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
        this->length=(int16)size;
    }
    size3i16(int64 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
        this->length=(int16)size;
    }
    size3i16(uint8 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
        this->length=(int16)size;
    }
    size3i16(uint16 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
        this->length=(int16)size;
    }
    size3i16(uint32 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
        this->length=(int16)size;
    }
    size3i16(uint64 size){
        //zera as variaveis
        this->width=(int16)size;
        this->height=(int16)size;
        this->length=(int16)size;
    }
    //operators

    //=
    size3i16 operator=(size3i8 size){
        //
        this->width=(int16)size.width;
        this->height=(int16)size.height;
        this->length=size.length;
        return *this;
    }
    size3i16 operator=(size3i16 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    size3i16 operator=(size2i8 size){
        //
        this->width=(int16)size.width;
        this->height=(int16)size.height;
        this->length=(int16)0;
        return *this;
    }
    size3i16 operator=(int8 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        this->length=(int16)n;
        return *this;
    }
    size3i16 operator=(int16 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        this->length=(int16)n;
        return *this;
    }
    size3i16 operator=(int32 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        this->length=(int16)n;
        return *this;
    }
    size3i16 operator=(int64 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        this->length=(int16)n;
        return *this;
    }
    size3i16 operator=(uint8 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        this->length=(int16)n;
        return *this;
    }
    size3i16 operator=(uint16 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        this->length=(int16)n;
        return *this;
    }
    size3i16 operator=(uint32 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        this->length=(int16)n;
        return *this;
    }
    size3i16 operator=(uint64 n){
        //
        this->width=(int16)n;
        this->height=(int16)n;
        this->length=(int16)n;
        return *this;
    }

    //==
    bool operator==(size3i8 size){
        //
        return (this->width==(int16)size.width&&this->height==(int16)size.height&&this->length==(int16)size.length);
    }
    bool operator==(size3i16 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    bool operator!=(size3i8 size){
        //
        return (this->width!=(int16)size.width||this->height!=(int16)size.height||this->length!=(int16)size.length);
    }
    bool operator!=(size3i16 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    size3i16 operator+(size3i8 size){
        //
        size3i16 ret;
        ret.width=this->width+(int16)size.width;
        ret.height=this->height+(int16)size.height;
        ret.length=this->length+(int16)size.length;
        return ret;
    }
    size3i16 operator+(size3i16 size){
        //
        size3i16 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    size3i16 operator+(size2i8 size){
        //
        size3i16 ret;
        ret.width=this->width+(int16)size.width;
        ret.height=this->height+(int16)size.height;
        return ret;
    }
    size3i16 operator+(int8 n){
        //
        size3i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        ret.length=this->length+(int16)n;
        return ret;
    }
    size3i16 operator+(int16 n){
        //
        size3i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        ret.length=this->length+(int16)n;
        return ret;
    }
    size3i16 operator+(int32 n){
        //
        size3i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        ret.length=this->length+(int16)n;
        return ret;
    }
    size3i16 operator+(int64 n){
        //
        size3i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        ret.length=this->length+(int16)n;
        return ret;
    }
    size3i16 operator+(uint8 n){
        //
        size3i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        ret.length=this->length+(int16)n;
        return ret;
    }
    size3i16 operator+(uint16 n){
        //
        size3i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        ret.length=this->length+(int16)n;
        return ret;
    }
    size3i16 operator+(uint32 n){
        //
        size3i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        ret.length=this->length+(int16)n;
        return ret;
    }
    size3i16 operator+(uint64 n){
        //
        size3i16 ret;
        ret.width=this->width+(int16)n;
        ret.height=this->height+(int16)n;
        ret.length=this->length+(int16)n;
        return ret;
    }

    //+=
    void operator+=(size3i8 size){
        //
        this->width+=(int16)size.width;
        this->height+=(int16)size.height;
        this->length+=(int16)size.length;
    }
    void operator+=(size3i16 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    void operator+=(size2i8 size){
        //
        this->width+=(int16)size.width;
        this->height+=(int16)size.height;
    }
    void operator+=(int8 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
        this->length+=(int16)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
        this->length+=(int16)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
        this->length+=(int16)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
        this->length+=(int16)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
        this->length+=(int16)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
        this->length+=(int16)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
        this->length+=(int16)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(int16)n;
        this->height+=(int16)n;
        this->length+=(int16)n;
    }

    //-
    size3i16 operator-(size3i8 size){
        //
        size3i16 ret;
        ret.width=this->width-(int16)size.width;
        ret.height=this->height-(int16)size.height;
        ret.length=this->length-(int16)size.length;
        return ret;
    }
    size3i16 operator-(size3i16 size){
        //
        size3i16 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    size3i16 operator-(size2i8 size){
        //
        size3i16 ret;
        ret.width=this->width-(int16)size.width;
        ret.height=this->height-(int16)size.height;
        return ret;
    }
    size3i16 operator-(int8 n){
        //
        size3i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        ret.length=this->length-(int16)n;
        return ret;
    }
    size3i16 operator-(int16 n){
        //
        size3i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        ret.length=this->length-(int16)n;
        return ret;
    }
    size3i16 operator-(int32 n){
        //
        size3i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        ret.length=this->length-(int16)n;
        return ret;
    }
    size3i16 operator-(int64 n){
        //
        size3i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        ret.length=this->length-(int16)n;
        return ret;
    }
    size3i16 operator-(uint8 n){
        //
        size3i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        ret.length=this->length-(int16)n;
        return ret;
    }
    size3i16 operator-(uint16 n){
        //
        size3i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        ret.length=this->length-(int16)n;
        return ret;
    }
    size3i16 operator-(uint32 n){
        //
        size3i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        ret.length=this->length-(int16)n;
        return ret;
    }
    size3i16 operator-(uint64 n){
        //
        size3i16 ret;
        ret.width=this->width-(int16)n;
        ret.height=this->height-(int16)n;
        ret.length=this->length-(int16)n;
        return ret;
    }

    //-=
    void operator-=(size3i8 size){
        //
        this->width-=(int16)size.width;
        this->height-=(int16)size.height;
        this->length-=(int16)size.length;
    }
    void operator-=(size3i16 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    void operator-=(size2i8 size){
        //
        this->width-=(int16)size.width;
        this->height-=(int16)size.height;
    }
    void operator-=(int8 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
        this->length-=(int16)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
        this->length-=(int16)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
        this->length-=(int16)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
        this->length-=(int16)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
        this->length-=(int16)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
        this->length-=(int16)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
        this->length-=(int16)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(int16)n;
        this->height-=(int16)n;
        this->length-=(int16)n;
    }

    //*
    size3i16 operator*(size3i8 size){
        //
        size3i16 ret;
        ret.width=this->width*(int16)size.width;
        ret.height=this->height*(int16)size.height;
        ret.length=this->length*(int16)size.length;
        return ret;
    }
    size3i16 operator*(size3i16 size){
        //
        size3i16 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    size3i16 operator*(size2i8 size){
        //
        size3i16 ret;
        ret.width=this->width*(int16)size.width;
        ret.height=this->height*(int16)size.height;
        return ret;
    }
    size3i16 operator*(int8 n){
        //
        size3i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        ret.length=this->length*(int16)n;
        return ret;
    }
    size3i16 operator*(int16 n){
        //
        size3i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        ret.length=this->length*(int16)n;
        return ret;
    }
    size3i16 operator*(int32 n){
        //
        size3i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        ret.length=this->length*(int16)n;
        return ret;
    }
    size3i16 operator*(int64 n){
        //
        size3i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        ret.length=this->length*(int16)n;
        return ret;
    }
    size3i16 operator*(uint8 n){
        //
        size3i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        ret.length=this->length*(int16)n;
        return ret;
    }
    size3i16 operator*(uint16 n){
        //
        size3i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        ret.length=this->length*(int16)n;
        return ret;
    }
    size3i16 operator*(uint32 n){
        //
        size3i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        ret.length=this->length*(int16)n;
        return ret;
    }
    size3i16 operator*(uint64 n){
        //
        size3i16 ret;
        ret.width=this->width*(int16)n;
        ret.height=this->height*(int16)n;
        ret.length=this->length*(int16)n;
        return ret;
    }

    //*=
    void operator*=(size3i8 size){
        //
        this->width*=(int16)size.width;
        this->height*=(int16)size.height;
        this->length*=(int16)size.length;
    }
    void operator*=(size3i16 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    void operator*=(size2i8 size){
        //
        this->width*=(int16)size.width;
        this->height*=(int16)size.height;
    }
    void operator*=(int8 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
        this->length*=(int16)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
        this->length*=(int16)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
        this->length*=(int16)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
        this->length*=(int16)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
        this->length*=(int16)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
        this->length*=(int16)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
        this->length*=(int16)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(int16)n;
        this->height*=(int16)n;
        this->length*=(int16)n;
    }

    //++
    size3i16 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return size3i16(this->width,this->height,this->length);
    }
    size3i16 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return size3i16(this->width,this->height,this->length);
    }

    //--
    size3i16 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return size3i16(this->width,this->height,this->length);
    }
    size3i16 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return size3i16(this->width,this->height,this->length);
    }

    //
    size3i16 operator()(int8 width,int8 height,int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i16((int16)this->width,(int16)this->height,(int16)this->length);
    }
    size3i16 operator()(int16 width,int16 height,int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i16((int16)this->width,(int16)this->height,(int16)this->length);
    }
    size3i16 operator()(int32 width,int32 height,int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i16((int16)this->width,(int16)this->height,(int16)this->length);
    }
    size3i16 operator()(int64 width,int64 height,int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i16((int16)this->width,(int16)this->height,(int16)this->length);
    }
    size3i16 operator()(uint8 width,uint8 height,uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i16((int16)this->width,(int16)this->height,(int16)this->length);
    }
    size3i16 operator()(uint16 width,uint16 height,uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i16((int16)this->width,(int16)this->height,(int16)this->length);
    }
    size3i16 operator()(uint32 width,uint32 height,uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i16((int16)this->width,(int16)this->height,(int16)this->length);
    }
    size3i16 operator()(uint64 width,uint64 height,uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i16((int16)this->width,(int16)this->height,(int16)this->length);
    }
};

//size3i32
class size3i32{
    //
public:
    int32 width,height,length;

    //CONSTRUTOR
    size3i32(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3i32(int8 width,int8 height,int8 length){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
        this->length=(int32)length;
    }
    size3i32(int16 width,int16 height,int16 length){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
        this->length=(int32)length;
    }
    size3i32(int32 width,int32 height,int32 length){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
        this->length=(int32)length;
    }
    size3i32(int64 width,int64 height,int64 length){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
        this->length=(int32)length;
    }
    size3i32(uint8 width,uint8 height,uint8 length){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
        this->length=(int32)length;
    }
    size3i32(uint16 width,uint16 height,uint16 length){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
        this->length=(int32)length;
    }
    size3i32(uint32 width,uint32 height,uint32 length){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
        this->length=(int32)length;
    }
    size3i32(uint64 width,uint64 height,uint64 length){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
        this->length=(int32)length;
    }
    size3i32(int8 size){
        //zera as variaveis
        this->width=(int32)width;
        this->height=(int32)height;
        this->length=(int32)length;
    }
    size3i32(int16 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
        this->length=(int32)size;
    }
    size3i32(int32 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
        this->length=(int32)size;
    }
    size3i32(int64 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
        this->length=(int32)size;
    }
    size3i32(uint8 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
        this->length=(int32)size;
    }
    size3i32(uint16 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
        this->length=(int32)size;
    }
    size3i32(uint32 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
        this->length=(int32)size;
    }
    size3i32(uint64 size){
        //zera as variaveis
        this->width=(int32)size;
        this->height=(int32)size;
        this->length=(int32)size;
    }
    //operators

    //=
    size3i32 operator=(size3i8 size){
        //
        this->width=(int32)size.width;
        this->height=(int32)size.height;
        this->length=size.length;
        return *this;
    }
    size3i32 operator=(size3i16 size){
        //
        this->width=(int32)size.width;
        this->height=(int32)size.height;
        this->length=size.length;
        return *this;
    }
    size3i32 operator=(size3i32 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    size3i32 operator=(size2i8 size){
        //
        this->width=(int32)size.width;
        this->height=(int32)size.height;
        this->length=(int32)0;
        return *this;
    }
    size3i32 operator=(int8 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        this->length=(int32)n;
        return *this;
    }
    size3i32 operator=(int16 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        this->length=(int32)n;
        return *this;
    }
    size3i32 operator=(int32 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        this->length=(int32)n;
        return *this;
    }
    size3i32 operator=(int64 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        this->length=(int32)n;
        return *this;
    }
    size3i32 operator=(uint8 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        this->length=(int32)n;
        return *this;
    }
    size3i32 operator=(uint16 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        this->length=(int32)n;
        return *this;
    }
    size3i32 operator=(uint32 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        this->length=(int32)n;
        return *this;
    }
    size3i32 operator=(uint64 n){
        //
        this->width=(int32)n;
        this->height=(int32)n;
        this->length=(int32)n;
        return *this;
    }

    //==
    bool operator==(size3i8 size){
        //
        return (this->width==(int32)size.width&&this->height==(int32)size.height&&this->length==(int32)size.length);
    }
    bool operator==(size3i16 size){
        //
        return (this->width==(int32)size.width&&this->height==(int32)size.height&&this->length==(int32)size.length);
    }
    bool operator==(size3i32 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    bool operator!=(size3i8 size){
        //
        return (this->width!=(int32)size.width||this->height!=(int32)size.height||this->length!=(int32)size.length);
    }
    bool operator!=(size3i16 size){
        //
        return (this->width!=(int32)size.width||this->height!=(int32)size.height||this->length!=(int32)size.length);
    }
    bool operator!=(size3i32 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    size3i32 operator+(size3i8 size){
        //
        size3i32 ret;
        ret.width=this->width+(int32)size.width;
        ret.height=this->height+(int32)size.height;
        ret.length=this->length+(int32)size.length;
        return ret;
    }
    size3i32 operator+(size3i16 size){
        //
        size3i32 ret;
        ret.width=this->width+(int32)size.width;
        ret.height=this->height+(int32)size.height;
        ret.length=this->length+(int32)size.length;
        return ret;
    }
    size3i32 operator+(size3i32 size){
        //
        size3i32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    size3i32 operator+(size2i8 size){
        //
        size3i32 ret;
        ret.width=this->width+(int32)size.width;
        ret.height=this->height+(int32)size.height;
        return ret;
    }
    size3i32 operator+(int8 n){
        //
        size3i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        ret.length=this->length+(int32)n;
        return ret;
    }
    size3i32 operator+(int16 n){
        //
        size3i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        ret.length=this->length+(int32)n;
        return ret;
    }
    size3i32 operator+(int32 n){
        //
        size3i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        ret.length=this->length+(int32)n;
        return ret;
    }
    size3i32 operator+(int64 n){
        //
        size3i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        ret.length=this->length+(int32)n;
        return ret;
    }
    size3i32 operator+(uint8 n){
        //
        size3i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        ret.length=this->length+(int32)n;
        return ret;
    }
    size3i32 operator+(uint16 n){
        //
        size3i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        ret.length=this->length+(int32)n;
        return ret;
    }
    size3i32 operator+(uint32 n){
        //
        size3i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        ret.length=this->length+(int32)n;
        return ret;
    }
    size3i32 operator+(uint64 n){
        //
        size3i32 ret;
        ret.width=this->width+(int32)n;
        ret.height=this->height+(int32)n;
        ret.length=this->length+(int32)n;
        return ret;
    }

    //+=
    void operator+=(size3i8 size){
        //
        this->width+=(int32)size.width;
        this->height+=(int32)size.height;
        this->length+=(int32)size.length;
    }
    void operator+=(size3i16 size){
        //
        this->width+=(int32)size.width;
        this->height+=(int32)size.height;
        this->length+=(int32)size.length;
    }
    void operator+=(size3i32 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    void operator+=(size2i8 size){
        //
        this->width+=(int32)size.width;
        this->height+=(int32)size.height;
    }
    void operator+=(int8 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
        this->length+=(int32)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
        this->length+=(int32)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
        this->length+=(int32)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
        this->length+=(int32)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
        this->length+=(int32)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
        this->length+=(int32)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
        this->length+=(int32)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(int32)n;
        this->height+=(int32)n;
        this->length+=(int32)n;
    }

    //-
    size3i32 operator-(size3i8 size){
        //
        size3i32 ret;
        ret.width=this->width-(int32)size.width;
        ret.height=this->height-(int32)size.height;
        ret.length=this->length-(int32)size.length;
        return ret;
    }
    size3i32 operator-(size3i16 size){
        //
        size3i32 ret;
        ret.width=this->width-(int32)size.width;
        ret.height=this->height-(int32)size.height;
        ret.length=this->length-(int32)size.length;
        return ret;
    }
    size3i32 operator-(size3i32 size){
        //
        size3i32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    size3i32 operator-(size2i8 size){
        //
        size3i32 ret;
        ret.width=this->width-(int32)size.width;
        ret.height=this->height-(int32)size.height;
        return ret;
    }
    size3i32 operator-(int8 n){
        //
        size3i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        ret.length=this->length-(int32)n;
        return ret;
    }
    size3i32 operator-(int16 n){
        //
        size3i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        ret.length=this->length-(int32)n;
        return ret;
    }
    size3i32 operator-(int32 n){
        //
        size3i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        ret.length=this->length-(int32)n;
        return ret;
    }
    size3i32 operator-(int64 n){
        //
        size3i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        ret.length=this->length-(int32)n;
        return ret;
    }
    size3i32 operator-(uint8 n){
        //
        size3i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        ret.length=this->length-(int32)n;
        return ret;
    }
    size3i32 operator-(uint16 n){
        //
        size3i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        ret.length=this->length-(int32)n;
        return ret;
    }
    size3i32 operator-(uint32 n){
        //
        size3i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        ret.length=this->length-(int32)n;
        return ret;
    }
    size3i32 operator-(uint64 n){
        //
        size3i32 ret;
        ret.width=this->width-(int32)n;
        ret.height=this->height-(int32)n;
        ret.length=this->length-(int32)n;
        return ret;
    }

    //-=
    void operator-=(size3i8 size){
        //
        this->width-=(int32)size.width;
        this->height-=(int32)size.height;
        this->length-=(int32)size.length;
    }
    void operator-=(size3i16 size){
        //
        this->width-=(int32)size.width;
        this->height-=(int32)size.height;
        this->length-=(int32)size.length;
    }
    void operator-=(size3i32 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    void operator-=(size2i8 size){
        //
        this->width-=(int32)size.width;
        this->height-=(int32)size.height;
    }
    void operator-=(int8 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
        this->length-=(int32)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
        this->length-=(int32)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
        this->length-=(int32)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
        this->length-=(int32)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
        this->length-=(int32)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
        this->length-=(int32)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
        this->length-=(int32)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(int32)n;
        this->height-=(int32)n;
        this->length-=(int32)n;
    }

    //*
    size3i32 operator*(size3i8 size){
        //
        size3i32 ret;
        ret.width=this->width*(int32)size.width;
        ret.height=this->height*(int32)size.height;
        ret.length=this->length*(int32)size.length;
        return ret;
    }
    size3i32 operator*(size3i16 size){
        //
        size3i32 ret;
        ret.width=this->width*(int32)size.width;
        ret.height=this->height*(int32)size.height;
        ret.length=this->length*(int32)size.length;
        return ret;
    }
    size3i32 operator*(size3i32 size){
        //
        size3i32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    size3i32 operator*(size2i8 size){
        //
        size3i32 ret;
        ret.width=this->width*(int32)size.width;
        ret.height=this->height*(int32)size.height;
        return ret;
    }
    size3i32 operator*(int8 n){
        //
        size3i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        ret.length=this->length*(int32)n;
        return ret;
    }
    size3i32 operator*(int16 n){
        //
        size3i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        ret.length=this->length*(int32)n;
        return ret;
    }
    size3i32 operator*(int32 n){
        //
        size3i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        ret.length=this->length*(int32)n;
        return ret;
    }
    size3i32 operator*(int64 n){
        //
        size3i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        ret.length=this->length*(int32)n;
        return ret;
    }
    size3i32 operator*(uint8 n){
        //
        size3i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        ret.length=this->length*(int32)n;
        return ret;
    }
    size3i32 operator*(uint16 n){
        //
        size3i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        ret.length=this->length*(int32)n;
        return ret;
    }
    size3i32 operator*(uint32 n){
        //
        size3i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        ret.length=this->length*(int32)n;
        return ret;
    }
    size3i32 operator*(uint64 n){
        //
        size3i32 ret;
        ret.width=this->width*(int32)n;
        ret.height=this->height*(int32)n;
        ret.length=this->length*(int32)n;
        return ret;
    }

    //*=
    void operator*=(size3i8 size){
        //
        this->width*=(int32)size.width;
        this->height*=(int32)size.height;
        this->length*=(int32)size.length;
    }
    void operator*=(size3i16 size){
        //
        this->width*=(int32)size.width;
        this->height*=(int32)size.height;
        this->length*=(int32)size.length;
    }
    void operator*=(size3i32 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    void operator*=(size2i8 size){
        //
        this->width*=(int32)size.width;
        this->height*=(int32)size.height;
    }
    void operator*=(int8 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
        this->length*=(int32)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
        this->length*=(int32)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
        this->length*=(int32)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
        this->length*=(int32)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
        this->length*=(int32)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
        this->length*=(int32)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
        this->length*=(int32)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(int32)n;
        this->height*=(int32)n;
        this->length*=(int32)n;
    }

    //++
    size3i32 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return size3i32(this->width,this->height,this->length);
    }
    size3i32 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return size3i32(this->width,this->height,this->length);
    }

    //--
    size3i32 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return size3i32(this->width,this->height,this->length);
    }
    size3i32 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return size3i32(this->width,this->height,this->length);
    }

    //
    size3i32 operator()(int8 width,int8 height,int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i32((int32)this->width,(int32)this->height,(int32)this->length);
    }
    size3i32 operator()(int16 width,int16 height,int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i32((int32)this->width,(int32)this->height,(int32)this->length);
    }
    size3i32 operator()(int32 width,int32 height,int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i32((int32)this->width,(int32)this->height,(int32)this->length);
    }
    size3i32 operator()(int64 width,int64 height,int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i32((int32)this->width,(int32)this->height,(int32)this->length);
    }
    size3i32 operator()(uint8 width,uint8 height,uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i32((int32)this->width,(int32)this->height,(int32)this->length);
    }
    size3i32 operator()(uint16 width,uint16 height,uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i32((int32)this->width,(int32)this->height,(int32)this->length);
    }
    size3i32 operator()(uint32 width,uint32 height,uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i32((int32)this->width,(int32)this->height,(int32)this->length);
    }
    size3i32 operator()(uint64 width,uint64 height,uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i32((int32)this->width,(int32)this->height,(int32)this->length);
    }
};

//size3i64
class size3i64{
    //
public:
    int64 width,height,length;

    //CONSTRUTOR
    size3i64(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3i64(int8 width,int8 height,int8 length){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
        this->length=(int64)length;
    }
    size3i64(int16 width,int16 height,int16 length){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
        this->length=(int64)length;
    }
    size3i64(int32 width,int32 height,int32 length){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
        this->length=(int64)length;
    }
    size3i64(int64 width,int64 height,int64 length){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
        this->length=(int64)length;
    }
    size3i64(uint8 width,uint8 height,uint8 length){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
        this->length=(int64)length;
    }
    size3i64(uint16 width,uint16 height,uint16 length){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
        this->length=(int64)length;
    }
    size3i64(uint32 width,uint32 height,uint32 length){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
        this->length=(int64)length;
    }
    size3i64(uint64 width,uint64 height,uint64 length){
        //zera as variaveis
        this->width=(int64)width;
        this->height=(int64)height;
        this->length=(int64)length;
    }
    size3i64(int8 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
        this->length=(int64)size;
    }
    size3i64(int16 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
        this->length=(int64)size;
    }
    size3i64(int32 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
        this->length=(int64)size;
    }
    size3i64(int64 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
        this->length=(int64)size;
    }
    size3i64(uint8 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
        this->length=(int64)size;
    }
    size3i64(uint16 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
        this->length=(int64)size;
    }
    size3i64(uint32 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
        this->length=(int64)size;
    }
    size3i64(uint64 size){
        //zera as variaveis
        this->width=(int64)size;
        this->height=(int64)size;
        this->length=(int64)size;
    }
    //operators

    //=
    size3i64 operator=(size3i8 size){
        //
        this->width=(int64)size.width;
        this->height=(int64)size.height;
        this->length=size.length;
        return *this;
    }
    size3i64 operator=(size3i16 size){
        //
        this->width=(int64)size.width;
        this->height=(int64)size.height;
        this->length=size.length;
        return *this;
    }
    size3i64 operator=(size3i32 size){
        //
        this->width=(int64)size.width;
        this->height=(int64)size.height;
        this->length=size.length;
        return *this;
    }
    size3i64 operator=(size3i64 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    size3i64 operator=(size2i8 size){
        //
        this->width=(int64)size.width;
        this->height=(int64)size.height;
        this->length=(int64)0;
        return *this;
    }
    size3i64 operator=(int8 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        this->length=(int64)n;
        return *this;
    }
    size3i64 operator=(int16 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        this->length=(int64)n;
        return *this;
    }
    size3i64 operator=(int32 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        this->length=(int64)n;
        return *this;
    }
    size3i64 operator=(int64 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        this->length=(int64)n;
        return *this;
    }
    size3i64 operator=(uint8 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        this->length=(int64)n;
        return *this;
    }
    size3i64 operator=(uint16 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        this->length=(int64)n;
        return *this;
    }
    size3i64 operator=(uint32 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        this->length=(int64)n;
        return *this;
    }
    size3i64 operator=(uint64 n){
        //
        this->width=(int64)n;
        this->height=(int64)n;
        this->length=(int64)n;
        return *this;
    }

    //==
    bool operator==(size3i8 size){
        //
        return (this->width==(int64)size.width&&this->height==(int64)size.height&&this->length==(int64)size.length);
    }
    bool operator==(size3i16 size){
        //
        return (this->width==(int64)size.width&&this->height==(int64)size.height&&this->length==(int64)size.length);
    }
    bool operator==(size3i32 size){
        //
        return (this->width==(int64)size.width&&this->height==(int64)size.height&&this->length==(int64)size.length);
    }
    bool operator==(size3i64 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    bool operator!=(size3i8 size){
        //
        return (this->width!=(int64)size.width||this->height!=(int64)size.height||this->length!=(int64)size.length);
    }
    bool operator!=(size3i16 size){
        //
        return (this->width!=(int64)size.width||this->height!=(int64)size.height||this->length!=(int64)size.length);
    }
    bool operator!=(size3i32 size){
        //
        return (this->width!=(int64)size.width||this->height!=(int64)size.height||this->length!=(int64)size.length);
    }
    bool operator!=(size3i64 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    size3i64 operator+(size3i8 size){
        //
        size3i64 ret;
        ret.width=this->width+(int64)size.width;
        ret.height=this->height+(int64)size.height;
        ret.length=this->length+(int64)size.length;
        return ret;
    }
    size3i64 operator+(size3i16 size){
        //
        size3i64 ret;
        ret.width=this->width+(int64)size.width;
        ret.height=this->height+(int64)size.height;
        ret.length=this->length+(int64)size.length;
        return ret;
    }
    size3i64 operator+(size3i32 size){
        //
        size3i64 ret;
        ret.width=this->width+(int64)size.width;
        ret.height=this->height+(int64)size.height;
        ret.length=this->length+(int64)size.length;
        return ret;
    }
    size3i64 operator+(size3i64 size){
        //
        size3i64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    size3i64 operator+(size2i8 size){
        //
        size3i64 ret;
        ret.width=this->width+(int64)size.width;
        ret.height=this->height+(int64)size.height;
        return ret;
    }
    size3i64 operator+(int8 n){
        //
        size3i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        ret.length=this->length+(int64)n;
        return ret;
    }
    size3i64 operator+(int16 n){
        //
        size3i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        ret.length=this->length+(int64)n;
        return ret;
    }
    size3i64 operator+(int32 n){
        //
        size3i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        ret.length=this->length+(int64)n;
        return ret;
    }
    size3i64 operator+(int64 n){
        //
        size3i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        ret.length=this->length+(int64)n;
        return ret;
    }
    size3i64 operator+(uint8 n){
        //
        size3i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        ret.length=this->length+(int64)n;
        return ret;
    }
    size3i64 operator+(uint16 n){
        //
        size3i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        ret.length=this->length+(int64)n;
        return ret;
    }
    size3i64 operator+(uint32 n){
        //
        size3i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        ret.length=this->length+(int64)n;
        return ret;
    }
    size3i64 operator+(uint64 n){
        //
        size3i64 ret;
        ret.width=this->width+(int64)n;
        ret.height=this->height+(int64)n;
        ret.length=this->length+(int64)n;
        return ret;
    }

    //+=
    void operator+=(size3i8 size){
        //
        this->width+=(int64)size.width;
        this->height+=(int64)size.height;
        this->length+=(int64)size.length;
    }
    void operator+=(size3i16 size){
        //
        this->width+=(int64)size.width;
        this->height+=(int64)size.height;
        this->length+=(int64)size.length;
    }
    void operator+=(size3i32 size){
        //
        this->width+=(int64)size.width;
        this->height+=(int64)size.height;
        this->length+=(int64)size.length;
    }
    void operator+=(size3i64 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    void operator+=(size2i8 size){
        //
        this->width+=(int64)size.width;
        this->height+=(int64)size.height;
    }
    void operator+=(int8 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
        this->length+=(int64)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
        this->length+=(int64)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
        this->length+=(int64)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
        this->length+=(int64)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
        this->length+=(int64)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
        this->length+=(int64)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
        this->length+=(int64)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(int64)n;
        this->height+=(int64)n;
        this->length+=(int64)n;
    }

    //-
    size3i64 operator-(size3i8 size){
        //
        size3i64 ret;
        ret.width=this->width-(int64)size.width;
        ret.height=this->height-(int64)size.height;
        ret.length=this->length-(int64)size.length;
        return ret;
    }
    size3i64 operator-(size3i16 size){
        //
        size3i64 ret;
        ret.width=this->width-(int64)size.width;
        ret.height=this->height-(int64)size.height;
        ret.length=this->length-(int64)size.length;
        return ret;
    }
    size3i64 operator-(size3i32 size){
        //
        size3i64 ret;
        ret.width=this->width-(int64)size.width;
        ret.height=this->height-(int64)size.height;
        ret.length=this->length-(int64)size.length;
        return ret;
    }
    size3i64 operator-(size3i64 size){
        //
        size3i64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    size3i64 operator-(size2i8 size){
        //
        size3i64 ret;
        ret.width=this->width-(int64)size.width;
        ret.height=this->height-(int64)size.height;
        return ret;
    }
    size3i64 operator-(int8 n){
        //
        size3i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        ret.length=this->length-(int64)n;
        return ret;
    }
    size3i64 operator-(int16 n){
        //
        size3i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        ret.length=this->length-(int64)n;
        return ret;
    }
    size3i64 operator-(int32 n){
        //
        size3i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        ret.length=this->length-(int64)n;
        return ret;
    }
    size3i64 operator-(int64 n){
        //
        size3i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        ret.length=this->length-(int64)n;
        return ret;
    }
    size3i64 operator-(uint8 n){
        //
        size3i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        ret.length=this->length-(int64)n;
        return ret;
    }
    size3i64 operator-(uint16 n){
        //
        size3i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        ret.length=this->length-(int64)n;
        return ret;
    }
    size3i64 operator-(uint32 n){
        //
        size3i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        ret.length=this->length-(int64)n;
        return ret;
    }
    size3i64 operator-(uint64 n){
        //
        size3i64 ret;
        ret.width=this->width-(int64)n;
        ret.height=this->height-(int64)n;
        ret.length=this->length-(int64)n;
        return ret;
    }

    //-=
    void operator-=(size3i8 size){
        //
        this->width-=(int64)size.width;
        this->height-=(int64)size.height;
        this->length-=(int64)size.length;
    }
    void operator-=(size3i16 size){
        //
        this->width-=(int64)size.width;
        this->height-=(int64)size.height;
        this->length-=(int64)size.length;
    }
    void operator-=(size3i32 size){
        //
        this->width-=(int64)size.width;
        this->height-=(int64)size.height;
        this->length-=(int64)size.length;
    }
    void operator-=(size3i64 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    void operator-=(size2i8 size){
        //
        this->width-=(int64)size.width;
        this->height-=(int64)size.height;
    }
    void operator-=(int8 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
        this->length-=(int64)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
        this->length-=(int64)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
        this->length-=(int64)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
        this->length-=(int64)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
        this->length-=(int64)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
        this->length-=(int64)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
        this->length-=(int64)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(int64)n;
        this->height-=(int64)n;
        this->length-=(int64)n;
    }

    //*
    size3i64 operator*(size3i8 size){
        //
        size3i64 ret;
        ret.width=this->width*(int64)size.width;
        ret.height=this->height*(int64)size.height;
        ret.length=this->length*(int64)size.length;
        return ret;
    }
    size3i64 operator*(size3i16 size){
        //
        size3i64 ret;
        ret.width=this->width*(int64)size.width;
        ret.height=this->height*(int64)size.height;
        ret.length=this->length*(int64)size.length;
        return ret;
    }
    size3i64 operator*(size3i32 size){
        //
        size3i64 ret;
        ret.width=this->width*(int64)size.width;
        ret.height=this->height*(int64)size.height;
        ret.length=this->length*(int64)size.length;
        return ret;
    }
    size3i64 operator*(size3i64 size){
        //
        size3i64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    size3i64 operator*(size2i8 size){
        //
        size3i64 ret;
        ret.width=this->width*(int64)size.width;
        ret.height=this->height*(int64)size.height;
        return ret;
    }
    size3i64 operator*(int8 n){
        //
        size3i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        ret.length=this->length*(int64)n;
        return ret;
    }
    size3i64 operator*(int16 n){
        //
        size3i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        ret.length=this->length*(int64)n;
        return ret;
    }
    size3i64 operator*(int32 n){
        //
        size3i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        ret.length=this->length*(int64)n;
        return ret;
    }
    size3i64 operator*(int64 n){
        //
        size3i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        ret.length=this->length*(int64)n;
        return ret;
    }
    size3i64 operator*(uint8 n){
        //
        size3i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        ret.length=this->length*(int64)n;
        return ret;
    }
    size3i64 operator*(uint16 n){
        //
        size3i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        ret.length=this->length*(int64)n;
        return ret;
    }
    size3i64 operator*(uint32 n){
        //
        size3i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        ret.length=this->length*(int64)n;
        return ret;
    }
    size3i64 operator*(uint64 n){
        //
        size3i64 ret;
        ret.width=this->width*(int64)n;
        ret.height=this->height*(int64)n;
        ret.length=this->length*(int64)n;
        return ret;
    }

    //*=
    void operator*=(size3i8 size){
        //
        this->width*=(int64)size.width;
        this->height*=(int64)size.height;
        this->length*=(int64)size.length;
    }
    void operator*=(size3i16 size){
        //
        this->width*=(int64)size.width;
        this->height*=(int64)size.height;
        this->length*=(int64)size.length;
    }
    void operator*=(size3i32 size){
        //
        this->width*=(int64)size.width;
        this->height*=(int64)size.height;
        this->length*=(int64)size.length;
    }
    void operator*=(size3i64 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    void operator*=(size2i8 size){
        //
        this->width*=(int64)size.width;
        this->height*=(int64)size.height;
    }
    void operator*=(int8 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
        this->length*=(int64)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
        this->length*=(int64)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
        this->length*=(int64)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
        this->length*=(int64)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
        this->length*=(int64)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
        this->length*=(int64)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
        this->length*=(int64)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(int64)n;
        this->height*=(int64)n;
        this->length*=(int64)n;
    }

    //++
    size3i64 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return size3i64(this->width,this->height,this->length);
    }
    size3i64 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return size3i64(this->width,this->height,this->length);
    }

    //--
    size3i64 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return size3i64(this->width,this->height,this->length);
    }
    size3i64 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return size3i64(this->width,this->height,this->length);
    }

    //
    size3i64 operator()(int8 width,int8 height,int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i64((int64)this->width,(int64)this->height,(int64)this->length);
    }
    size3i64 operator()(int16 width,int16 height,int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i64((int64)this->width,(int64)this->height,(int64)this->length);
    }
    size3i64 operator()(int32 width,int32 height,int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i64((int64)this->width,(int64)this->height,(int64)this->length);
    }
    size3i64 operator()(int64 width,int64 height,int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i64((int64)this->width,(int64)this->height,(int64)this->length);
    }
    size3i64 operator()(uint8 width,uint8 height,uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i64((int64)this->width,(int64)this->height,(int64)this->length);
    }
    size3i64 operator()(uint16 width,uint16 height,uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i64((int64)this->width,(int64)this->height,(int64)this->length);
    }
    size3i64 operator()(uint32 width,uint32 height,uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i64((int64)this->width,(int64)this->height,(int64)this->length);
    }
    size3i64 operator()(uint64 width,uint64 height,uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3i64((int64)this->width,(int64)this->height,(int64)this->length);
    }
};

//size3ui8
class size3ui8{
    //
public:
    uint8 width,height,length;

    //CONSTRUTOR
    size3ui8(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3ui8(uint8 width,uint8 height,uint8 length){
        //zera as variaveis
        this->width=(uint8)width;
        this->height=(uint8)height;
        this->length=(uint8)length;
    }
    size3ui8(uint16 width,uint16 height,uint16 length){
        //zera as variaveis
        this->width=(uint8)width;
        this->height=(uint8)height;
        this->length=(uint8)length;
    }
    size3ui8(uint32 width,uint32 height,uint32 length){
        //zera as variaveis
        this->width=(uint8)width;
        this->height=(uint8)height;
        this->length=(uint8)length;
    }
    size3ui8(uint64 width,uint64 height,uint64 length){
        //zera as variaveis
        this->width=(uint8)width;
        this->height=(uint8)height;
        this->length=(uint8)length;
    }
    size3ui8(uint8 size){
        //zera as variaveis
        this->width=(uint8)size;
        this->height=(uint8)size;
        this->length=(uint8)size;
    }
    size3ui8(uint16 size){
        //zera as variaveis
        this->width=(uint8)size;
        this->height=(uint8)size;
        this->length=(uint8)size;
    }
    size3ui8(uint32 size){
        //zera as variaveis
        this->width=(uint8)size;
        this->height=(uint8)size;
        this->length=(uint8)size;
    }
    size3ui8(uint64 size){
        //zera as variaveis
        this->width=(uint8)size;
        this->height=(uint8)size;
        this->length=(uint8)size;
    }
    //operators

    //=
    size3ui8 operator=(size3ui8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    size3ui8 operator=(size2i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=(uint8)0;
        return *this;
    }
    size3ui8 operator=(uint8 n){
        //
        this->width=(uint8)n;
        this->height=(uint8)n;
        this->length=(uint8)n;
        return *this;
    }
    size3ui8 operator=(uint16 n){
        //
        this->width=(uint8)n;
        this->height=(uint8)n;
        this->length=(uint8)n;
        return *this;
    }
    size3ui8 operator=(uint32 n){
        //
        this->width=(uint8)n;
        this->height=(uint8)n;
        this->length=(uint8)n;
        return *this;
    }
    size3ui8 operator=(uint64 n){
        //
        this->width=(uint8)n;
        this->height=(uint8)n;
        this->length=(uint8)n;
        return *this;
    }

    //==
    bool operator==(size3ui8 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    bool operator!=(size3ui8 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    size3ui8 operator+(size3ui8 size){
        //
        size3ui8 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    size3ui8 operator+(size2i8 size){
        //
        size3ui8 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size3ui8 operator+(uint8 n){
        //
        size3ui8 ret;
        ret.width=this->width+(uint8)n;
        ret.height=this->height+(uint8)n;
        ret.length=this->length+(uint8)n;
        return ret;
    }
    size3ui8 operator+(uint16 n){
        //
        size3ui8 ret;
        ret.width=this->width+(uint8)n;
        ret.height=this->height+(uint8)n;
        ret.length=this->length+(uint8)n;
        return ret;
    }
    size3ui8 operator+(uint32 n){
        //
        size3ui8 ret;
        ret.width=this->width+(uint8)n;
        ret.height=this->height+(uint8)n;
        ret.length=this->length+(uint8)n;
        return ret;
    }
    size3ui8 operator+(uint64 n){
        //
        size3ui8 ret;
        ret.width=this->width+(uint8)n;
        ret.height=this->height+(uint8)n;
        ret.length=this->length+(uint8)n;
        return ret;
    }

    //+=
    void operator+=(size3ui8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    void operator+=(size2i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(uint8 n){
        //
        this->width+=(uint8)n;
        this->height+=(uint8)n;
        this->length+=(uint8)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(uint8)n;
        this->height+=(uint8)n;
        this->length+=(uint8)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(uint8)n;
        this->height+=(uint8)n;
        this->length+=(uint8)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(uint8)n;
        this->height+=(uint8)n;
        this->length+=(uint8)n;
    }

    //-
    size3ui8 operator-(size3ui8 size){
        //
        size3ui8 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    size3ui8 operator-(size2i8 size){
        //
        size3ui8 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size3ui8 operator-(uint8 n){
        //
        size3ui8 ret;
        ret.width=this->width-(uint8)n;
        ret.height=this->height-(uint8)n;
        ret.length=this->length-(uint8)n;
        return ret;
    }
    size3ui8 operator-(uint16 n){
        //
        size3ui8 ret;
        ret.width=this->width-(uint8)n;
        ret.height=this->height-(uint8)n;
        ret.length=this->length-(uint8)n;
        return ret;
    }
    size3ui8 operator-(uint32 n){
        //
        size3ui8 ret;
        ret.width=this->width-(uint8)n;
        ret.height=this->height-(uint8)n;
        ret.length=this->length-(uint8)n;
        return ret;
    }
    size3ui8 operator-(uint64 n){
        //
        size3ui8 ret;
        ret.width=this->width-(uint8)n;
        ret.height=this->height-(uint8)n;
        ret.length=this->length-(uint8)n;
        return ret;
    }

    //-=
    void operator-=(size3ui8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    void operator-=(size2i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(uint8 n){
        //
        this->width-=(uint8)n;
        this->height-=(uint8)n;
        this->length-=(uint8)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(uint8)n;
        this->height-=(uint8)n;
        this->length-=(uint8)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(uint8)n;
        this->height-=(uint8)n;
        this->length-=(uint8)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(uint8)n;
        this->height-=(uint8)n;
        this->length-=(uint8)n;
    }

    //*
    size3ui8 operator*(size3ui8 size){
        //
        size3ui8 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    size3ui8 operator*(size2i8 size){
        //
        size3ui8 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size3ui8 operator*(uint8 n){
        //
        size3ui8 ret;
        ret.width=this->width*(uint8)n;
        ret.height=this->height*(uint8)n;
        ret.length=this->length*(uint8)n;
        return ret;
    }
    size3ui8 operator*(uint16 n){
        //
        size3ui8 ret;
        ret.width=this->width*(uint8)n;
        ret.height=this->height*(uint8)n;
        ret.length=this->length*(uint8)n;
        return ret;
    }
    size3ui8 operator*(uint32 n){
        //
        size3ui8 ret;
        ret.width=this->width*(uint8)n;
        ret.height=this->height*(uint8)n;
        ret.length=this->length*(uint8)n;
        return ret;
    }
    size3ui8 operator*(uint64 n){
        //
        size3ui8 ret;
        ret.width=this->width*(uint8)n;
        ret.height=this->height*(uint8)n;
        ret.length=this->length*(uint8)n;
        return ret;
    }

    //*=
    void operator*=(size3ui8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    void operator*=(size2i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(uint8 n){
        //
        this->width*=(uint8)n;
        this->height*=(uint8)n;
        this->length*=(uint8)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(uint8)n;
        this->height*=(uint8)n;
        this->length*=(uint8)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(uint8)n;
        this->height*=(uint8)n;
        this->length*=(uint8)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(uint8)n;
        this->height*=(uint8)n;
        this->length*=(uint8)n;
    }

    //++
    size3ui8 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return size3ui8(this->width,this->height,this->length);
    }
    size3ui8 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return size3ui8(this->width,this->height,this->length);
    }

    //--
    size3ui8 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return size3ui8(this->width,this->height,this->length);
    }
    size3ui8 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return size3ui8(this->width,this->height,this->length);
    }

    //
    size3ui8 operator()(uint8 width,uint8 height,uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui8((uint8)this->width,(uint8)this->height,(uint8)this->length);
    }
    size3ui8 operator()(uint16 width,uint16 height,uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui8((uint8)this->width,(uint8)this->height,(uint8)this->length);
    }
    size3ui8 operator()(uint32 width,uint32 height,uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui8((uint8)this->width,(uint8)this->height,(uint8)this->length);
    }
    size3ui8 operator()(uint64 width,uint64 height,uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui8((uint8)this->width,(uint8)this->height,(uint8)this->length);
    }
};

//size3ui16
class size3ui16{
    //
public:
    uint16 width,height,length;

    //CONSTRUTOR
    size3ui16(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3ui16(uint8 width,uint8 height,uint8 length){
        //zera as variaveis
        this->width=(uint16)width;
        this->height=(uint16)height;
        this->length=(uint16)length;
    }
    size3ui16(uint16 width,uint16 height,uint16 length){
        //zera as variaveis
        this->width=(uint16)width;
        this->height=(uint16)height;
        this->length=(uint16)length;
    }
    size3ui16(uint32 width,uint32 height,uint32 length){
        //zera as variaveis
        this->width=(uint16)width;
        this->height=(uint16)height;
        this->length=(uint16)length;
    }
    size3ui16(uint64 width,uint64 height,uint64 length){
        //zera as variaveis
        this->width=(uint16)width;
        this->height=(uint16)height;
        this->length=(uint16)length;
    }
    size3ui16(uint8 size){
        //zera as variaveis
        this->width=(uint16)size;
        this->height=(uint16)size;
        this->length=(uint16)size;
    }
    size3ui16(uint16 size){
        //zera as variaveis
        this->width=(uint16)size;
        this->height=(uint16)size;
        this->length=(uint16)size;
    }
    size3ui16(uint32 size){
        //zera as variaveis
        this->width=(uint16)size;
        this->height=(uint16)size;
        this->length=(uint16)size;
    }
    size3ui16(uint64 size){
        //zera as variaveis
        this->width=(uint16)size;
        this->height=(uint16)size;
        this->length=(uint16)size;
    }
    //operators

    //=
    size3ui16 operator=(size3ui8 size){
        //
        this->width=(uint16)size.width;
        this->height=(uint16)size.height;
        this->length=size.length;
        return *this;
    }
    size3ui16 operator=(size3ui16 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    size3ui16 operator=(size2i8 size){
        //
        this->width=(uint16)size.width;
        this->height=(uint16)size.height;
        this->length=(uint16)0;
        return *this;
    }
    size3ui16 operator=(uint8 n){
        //
        this->width=(uint16)n;
        this->height=(uint16)n;
        this->length=(uint16)n;
        return *this;
    }
    size3ui16 operator=(uint16 n){
        //
        this->width=(uint16)n;
        this->height=(uint16)n;
        this->length=(uint16)n;
        return *this;
    }
    size3ui16 operator=(uint32 n){
        //
        this->width=(uint16)n;
        this->height=(uint16)n;
        this->length=(uint16)n;
        return *this;
    }
    size3ui16 operator=(uint64 n){
        //
        this->width=(uint16)n;
        this->height=(uint16)n;
        this->length=(uint16)n;
        return *this;
    }

    //==
    bool operator==(size3ui8 size){
        //
        return (this->width==(uint16)size.width&&this->height==(uint16)size.height&&this->length==(uint16)size.length);
    }
    bool operator==(size3ui16 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    bool operator!=(size3ui8 size){
        //
        return (this->width!=(uint16)size.width||this->height!=(uint16)size.height||this->length!=(uint16)size.length);
    }
    bool operator!=(size3ui16 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    size3ui16 operator+(size3ui8 size){
        //
        size3ui16 ret;
        ret.width=this->width+(uint16)size.width;
        ret.height=this->height+(uint16)size.height;
        ret.length=this->length+(uint16)size.length;
        return ret;
    }
    size3ui16 operator+(size3ui16 size){
        //
        size3ui16 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    size3ui16 operator+(size2i8 size){
        //
        size3ui16 ret;
        ret.width=this->width+(uint16)size.width;
        ret.height=this->height+(uint16)size.height;
        return ret;
    }
    size3ui16 operator+(uint8 n){
        //
        size3ui16 ret;
        ret.width=this->width+(uint16)n;
        ret.height=this->height+(uint16)n;
        ret.length=this->length+(uint16)n;
        return ret;
    }
    size3ui16 operator+(uint16 n){
        //
        size3ui16 ret;
        ret.width=this->width+(uint16)n;
        ret.height=this->height+(uint16)n;
        ret.length=this->length+(uint16)n;
        return ret;
    }
    size3ui16 operator+(uint32 n){
        //
        size3ui16 ret;
        ret.width=this->width+(uint16)n;
        ret.height=this->height+(uint16)n;
        ret.length=this->length+(uint16)n;
        return ret;
    }
    size3ui16 operator+(uint64 n){
        //
        size3ui16 ret;
        ret.width=this->width+(uint16)n;
        ret.height=this->height+(uint16)n;
        ret.length=this->length+(uint16)n;
        return ret;
    }

    //+=
    void operator+=(size3ui8 size){
        //
        this->width+=(uint16)size.width;
        this->height+=(uint16)size.height;
        this->length+=(uint16)size.length;
    }
    void operator+=(size3ui16 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    void operator+=(size2i8 size){
        //
        this->width+=(uint16)size.width;
        this->height+=(uint16)size.height;
    }
    void operator+=(uint8 n){
        //
        this->width+=(uint16)n;
        this->height+=(uint16)n;
        this->length+=(uint16)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(uint16)n;
        this->height+=(uint16)n;
        this->length+=(uint16)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(uint16)n;
        this->height+=(uint16)n;
        this->length+=(uint16)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(uint16)n;
        this->height+=(uint16)n;
        this->length+=(uint16)n;
    }

    //-
    size3ui16 operator-(size3ui8 size){
        //
        size3ui16 ret;
        ret.width=this->width-(uint16)size.width;
        ret.height=this->height-(uint16)size.height;
        ret.length=this->length-(uint16)size.length;
        return ret;
    }
    size3ui16 operator-(size3ui16 size){
        //
        size3ui16 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    size3ui16 operator-(size2i8 size){
        //
        size3ui16 ret;
        ret.width=this->width-(uint16)size.width;
        ret.height=this->height-(uint16)size.height;
        return ret;
    }
    size3ui16 operator-(uint8 n){
        //
        size3ui16 ret;
        ret.width=this->width-(uint16)n;
        ret.height=this->height-(uint16)n;
        ret.length=this->length-(uint16)n;
        return ret;
    }
    size3ui16 operator-(uint16 n){
        //
        size3ui16 ret;
        ret.width=this->width-(uint16)n;
        ret.height=this->height-(uint16)n;
        ret.length=this->length-(uint16)n;
        return ret;
    }
    size3ui16 operator-(uint32 n){
        //
        size3ui16 ret;
        ret.width=this->width-(uint16)n;
        ret.height=this->height-(uint16)n;
        ret.length=this->length-(uint16)n;
        return ret;
    }
    size3ui16 operator-(uint64 n){
        //
        size3ui16 ret;
        ret.width=this->width-(uint16)n;
        ret.height=this->height-(uint16)n;
        ret.length=this->length-(uint16)n;
        return ret;
    }

    //-=
    void operator-=(size3ui8 size){
        //
        this->width-=(uint16)size.width;
        this->height-=(uint16)size.height;
        this->length-=(uint16)size.length;
    }
    void operator-=(size3ui16 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    void operator-=(size2i8 size){
        //
        this->width-=(uint16)size.width;
        this->height-=(uint16)size.height;
    }
    void operator-=(uint8 n){
        //
        this->width-=(uint16)n;
        this->height-=(uint16)n;
        this->length-=(uint16)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(uint16)n;
        this->height-=(uint16)n;
        this->length-=(uint16)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(uint16)n;
        this->height-=(uint16)n;
        this->length-=(uint16)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(uint16)n;
        this->height-=(uint16)n;
        this->length-=(uint16)n;
    }

    //*
    size3ui16 operator*(size3ui8 size){
        //
        size3ui16 ret;
        ret.width=this->width*(uint16)size.width;
        ret.height=this->height*(uint16)size.height;
        ret.length=this->length*(uint16)size.length;
        return ret;
    }
    size3ui16 operator*(size3ui16 size){
        //
        size3ui16 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    size3ui16 operator*(size2i8 size){
        //
        size3ui16 ret;
        ret.width=this->width*(uint16)size.width;
        ret.height=this->height*(uint16)size.height;
        return ret;
    }
    size3ui16 operator*(uint8 n){
        //
        size3ui16 ret;
        ret.width=this->width*(uint16)n;
        ret.height=this->height*(uint16)n;
        ret.length=this->length*(uint16)n;
        return ret;
    }
    size3ui16 operator*(uint16 n){
        //
        size3ui16 ret;
        ret.width=this->width*(uint16)n;
        ret.height=this->height*(uint16)n;
        ret.length=this->length*(uint16)n;
        return ret;
    }
    size3ui16 operator*(uint32 n){
        //
        size3ui16 ret;
        ret.width=this->width*(uint16)n;
        ret.height=this->height*(uint16)n;
        ret.length=this->length*(uint16)n;
        return ret;
    }
    size3ui16 operator*(uint64 n){
        //
        size3ui16 ret;
        ret.width=this->width*(uint16)n;
        ret.height=this->height*(uint16)n;
        ret.length=this->length*(uint16)n;
        return ret;
    }

    //*=
    void operator*=(size3ui8 size){
        //
        this->width*=(uint16)size.width;
        this->height*=(uint16)size.height;
        this->length*=(uint16)size.length;
    }
    void operator*=(size3ui16 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    void operator*=(size2i8 size){
        //
        this->width*=(uint16)size.width;
        this->height*=(uint16)size.height;
    }
    void operator*=(uint8 n){
        //
        this->width*=(uint16)n;
        this->height*=(uint16)n;
        this->length*=(uint16)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(uint16)n;
        this->height*=(uint16)n;
        this->length*=(uint16)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(uint16)n;
        this->height*=(uint16)n;
        this->length*=(uint16)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(uint16)n;
        this->height*=(uint16)n;
        this->length*=(uint16)n;
    }

    //++
    size3ui16 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return size3ui16(this->width,this->height,this->length);
    }
    size3ui16 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return size3ui16(this->width,this->height,this->length);
    }

    //--
    size3ui16 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return size3ui16(this->width,this->height,this->length);
    }
    size3ui16 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return size3ui16(this->width,this->height,this->length);
    }

    //
    size3ui16 operator()(uint8 width,uint8 height,uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui16((uint16)this->width,(uint16)this->height,(uint16)this->length);
    }
    size3ui16 operator()(uint16 width,uint16 height,uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui16((uint16)this->width,(uint16)this->height,(uint16)this->length);
    }
    size3ui16 operator()(uint32 width,uint32 height,uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui16((uint16)this->width,(uint16)this->height,(uint16)this->length);
    }
    size3ui16 operator()(uint64 width,uint64 height,uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui16((uint16)this->width,(uint16)this->height,(uint16)this->length);
    }
};

//size3ui32
class size3ui32{
    //
public:
    uint32 width,height,length;

    //CONSTRUTOR
    size3ui32(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3ui32(uint8 width,uint8 height,uint8 length){
        //zera as variaveis
        this->width=(uint32)width;
        this->height=(uint32)height;
        this->length=(uint32)length;
    }
    size3ui32(uint16 width,uint16 height,uint16 length){
        //zera as variaveis
        this->width=(uint32)width;
        this->height=(uint32)height;
        this->length=(uint32)length;
    }
    size3ui32(uint32 width,uint32 height,uint32 length){
        //zera as variaveis
        this->width=(uint32)width;
        this->height=(uint32)height;
        this->length=(uint32)length;
    }
    size3ui32(uint64 width,uint64 height,uint64 length){
        //zera as variaveis
        this->width=(uint32)width;
        this->height=(uint32)height;
        this->length=(uint32)length;
    }
    size3ui32(uint8 size){
        //zera as variaveis
        this->width=(uint32)size;
        this->height=(uint32)size;
        this->length=(uint32)size;
    }
    size3ui32(uint16 size){
        //zera as variaveis
        this->width=(uint32)size;
        this->height=(uint32)size;
        this->length=(uint32)size;
    }
    size3ui32(uint32 size){
        //zera as variaveis
        this->width=(uint32)size;
        this->height=(uint32)size;
        this->length=(uint32)size;
    }
    size3ui32(uint64 size){
        //zera as variaveis
        this->width=(uint32)size;
        this->height=(uint32)size;
        this->length=(uint32)size;
    }
    //operators

    //=
    size3ui32 operator=(size3ui8 size){
        //
        this->width=(uint32)size.width;
        this->height=(uint32)size.height;
        this->length=size.length;
        return *this;
    }
    size3ui32 operator=(size3ui16 size){
        //
        this->width=(uint32)size.width;
        this->height=(uint32)size.height;
        this->length=size.length;
        return *this;
    }
    size3ui32 operator=(size3ui32 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    size3ui32 operator=(size2i8 size){
        //
        this->width=(uint32)size.width;
        this->height=(uint32)size.height;
        this->length=(uint32)0;
        return *this;
    }
    size3ui32 operator=(uint8 n){
        //
        this->width=(uint32)n;
        this->height=(uint32)n;
        this->length=(uint32)n;
        return *this;
    }
    size3ui32 operator=(uint16 n){
        //
        this->width=(uint32)n;
        this->height=(uint32)n;
        this->length=(uint32)n;
        return *this;
    }
    size3ui32 operator=(uint32 n){
        //
        this->width=(uint32)n;
        this->height=(uint32)n;
        this->length=(uint32)n;
        return *this;
    }
    size3ui32 operator=(uint64 n){
        //
        this->width=(uint32)n;
        this->height=(uint32)n;
        this->length=(uint32)n;
        return *this;
    }

    //==
    bool operator==(size3ui8 size){
        //
        return (this->width==(uint32)size.width&&this->height==(uint32)size.height&&this->length==(uint32)size.length);
    }
    bool operator==(size3ui16 size){
        //
        return (this->width==(uint32)size.width&&this->height==(uint32)size.height&&this->length==(uint32)size.length);
    }
    bool operator==(size3ui32 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    bool operator!=(size3ui8 size){
        //
        return (this->width!=(uint32)size.width||this->height!=(uint32)size.height||this->length!=(uint32)size.length);
    }
    bool operator!=(size3ui16 size){
        //
        return (this->width!=(uint32)size.width||this->height!=(uint32)size.height||this->length!=(uint32)size.length);
    }
    bool operator!=(size3ui32 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    size3ui32 operator+(size3ui8 size){
        //
        size3ui32 ret;
        ret.width=this->width+(uint32)size.width;
        ret.height=this->height+(uint32)size.height;
        ret.length=this->length+(uint32)size.length;
        return ret;
    }
    size3ui32 operator+(size3ui16 size){
        //
        size3ui32 ret;
        ret.width=this->width+(uint32)size.width;
        ret.height=this->height+(uint32)size.height;
        ret.length=this->length+(uint32)size.length;
        return ret;
    }
    size3ui32 operator+(size3ui32 size){
        //
        size3ui32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    size3ui32 operator+(size2i8 size){
        //
        size3ui32 ret;
        ret.width=this->width+(uint32)size.width;
        ret.height=this->height+(uint32)size.height;
        return ret;
    }
    size3ui32 operator+(uint8 n){
        //
        size3ui32 ret;
        ret.width=this->width+(uint32)n;
        ret.height=this->height+(uint32)n;
        ret.length=this->length+(uint32)n;
        return ret;
    }
    size3ui32 operator+(uint16 n){
        //
        size3ui32 ret;
        ret.width=this->width+(uint32)n;
        ret.height=this->height+(uint32)n;
        ret.length=this->length+(uint32)n;
        return ret;
    }
    size3ui32 operator+(uint32 n){
        //
        size3ui32 ret;
        ret.width=this->width+(uint32)n;
        ret.height=this->height+(uint32)n;
        ret.length=this->length+(uint32)n;
        return ret;
    }
    size3ui32 operator+(uint64 n){
        //
        size3ui32 ret;
        ret.width=this->width+(uint32)n;
        ret.height=this->height+(uint32)n;
        ret.length=this->length+(uint32)n;
        return ret;
    }

    //+=
    void operator+=(size3ui8 size){
        //
        this->width+=(uint32)size.width;
        this->height+=(uint32)size.height;
        this->length+=(uint32)size.length;
    }
    void operator+=(size3ui16 size){
        //
        this->width+=(uint32)size.width;
        this->height+=(uint32)size.height;
        this->length+=(uint32)size.length;
    }
    void operator+=(size3ui32 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    void operator+=(size2i8 size){
        //
        this->width+=(uint32)size.width;
        this->height+=(uint32)size.height;
    }
    void operator+=(uint8 n){
        //
        this->width+=(uint32)n;
        this->height+=(uint32)n;
        this->length+=(uint32)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(uint32)n;
        this->height+=(uint32)n;
        this->length+=(uint32)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(uint32)n;
        this->height+=(uint32)n;
        this->length+=(uint32)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(uint32)n;
        this->height+=(uint32)n;
        this->length+=(uint32)n;
    }

    //-
    size3ui32 operator-(size3ui8 size){
        //
        size3ui32 ret;
        ret.width=this->width-(uint32)size.width;
        ret.height=this->height-(uint32)size.height;
        ret.length=this->length-(uint32)size.length;
        return ret;
    }
    size3ui32 operator-(size3ui16 size){
        //
        size3ui32 ret;
        ret.width=this->width-(uint32)size.width;
        ret.height=this->height-(uint32)size.height;
        ret.length=this->length-(uint32)size.length;
        return ret;
    }
    size3ui32 operator-(size3ui32 size){
        //
        size3ui32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    size3ui32 operator-(size2i8 size){
        //
        size3ui32 ret;
        ret.width=this->width-(uint32)size.width;
        ret.height=this->height-(uint32)size.height;
        return ret;
    }
    size3ui32 operator-(uint8 n){
        //
        size3ui32 ret;
        ret.width=this->width-(uint32)n;
        ret.height=this->height-(uint32)n;
        ret.length=this->length-(uint32)n;
        return ret;
    }
    size3ui32 operator-(uint16 n){
        //
        size3ui32 ret;
        ret.width=this->width-(uint32)n;
        ret.height=this->height-(uint32)n;
        ret.length=this->length-(uint32)n;
        return ret;
    }
    size3ui32 operator-(uint32 n){
        //
        size3ui32 ret;
        ret.width=this->width-(uint32)n;
        ret.height=this->height-(uint32)n;
        ret.length=this->length-(uint32)n;
        return ret;
    }
    size3ui32 operator-(uint64 n){
        //
        size3ui32 ret;
        ret.width=this->width-(uint32)n;
        ret.height=this->height-(uint32)n;
        ret.length=this->length-(uint32)n;
        return ret;
    }

    //-=
    void operator-=(size3ui8 size){
        //
        this->width-=(uint32)size.width;
        this->height-=(uint32)size.height;
        this->length-=(uint32)size.length;
    }
    void operator-=(size3ui16 size){
        //
        this->width-=(uint32)size.width;
        this->height-=(uint32)size.height;
        this->length-=(uint32)size.length;
    }
    void operator-=(size3ui32 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    void operator-=(size2i8 size){
        //
        this->width-=(uint32)size.width;
        this->height-=(uint32)size.height;
    }
    void operator-=(uint8 n){
        //
        this->width-=(uint32)n;
        this->height-=(uint32)n;
        this->length-=(uint32)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(uint32)n;
        this->height-=(uint32)n;
        this->length-=(uint32)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(uint32)n;
        this->height-=(uint32)n;
        this->length-=(uint32)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(uint32)n;
        this->height-=(uint32)n;
        this->length-=(uint32)n;
    }

    //*
    size3ui32 operator*(size3ui8 size){
        //
        size3ui32 ret;
        ret.width=this->width*(uint32)size.width;
        ret.height=this->height*(uint32)size.height;
        ret.length=this->length*(uint32)size.length;
        return ret;
    }
    size3ui32 operator*(size3ui16 size){
        //
        size3ui32 ret;
        ret.width=this->width*(uint32)size.width;
        ret.height=this->height*(uint32)size.height;
        ret.length=this->length*(uint32)size.length;
        return ret;
    }
    size3ui32 operator*(size3ui32 size){
        //
        size3ui32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    size3ui32 operator*(size2i8 size){
        //
        size3ui32 ret;
        ret.width=this->width*(uint32)size.width;
        ret.height=this->height*(uint32)size.height;
        return ret;
    }
    size3ui32 operator*(uint8 n){
        //
        size3ui32 ret;
        ret.width=this->width*(uint32)n;
        ret.height=this->height*(uint32)n;
        ret.length=this->length*(uint32)n;
        return ret;
    }
    size3ui32 operator*(uint16 n){
        //
        size3ui32 ret;
        ret.width=this->width*(uint32)n;
        ret.height=this->height*(uint32)n;
        ret.length=this->length*(uint32)n;
        return ret;
    }
    size3ui32 operator*(uint32 n){
        //
        size3ui32 ret;
        ret.width=this->width*(uint32)n;
        ret.height=this->height*(uint32)n;
        ret.length=this->length*(uint32)n;
        return ret;
    }
    size3ui32 operator*(uint64 n){
        //
        size3ui32 ret;
        ret.width=this->width*(uint32)n;
        ret.height=this->height*(uint32)n;
        ret.length=this->length*(uint32)n;
        return ret;
    }

    //*=
    void operator*=(size3ui8 size){
        //
        this->width*=(uint32)size.width;
        this->height*=(uint32)size.height;
        this->length*=(uint32)size.length;
    }
    void operator*=(size3ui16 size){
        //
        this->width*=(uint32)size.width;
        this->height*=(uint32)size.height;
        this->length*=(uint32)size.length;
    }
    void operator*=(size3ui32 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    void operator*=(size2i8 size){
        //
        this->width*=(uint32)size.width;
        this->height*=(uint32)size.height;
    }
    void operator*=(uint8 n){
        //
        this->width*=(uint32)n;
        this->height*=(uint32)n;
        this->length*=(uint32)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(uint32)n;
        this->height*=(uint32)n;
        this->length*=(uint32)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(uint32)n;
        this->height*=(uint32)n;
        this->length*=(uint32)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(uint32)n;
        this->height*=(uint32)n;
        this->length*=(uint32)n;
    }

    //++
    size3ui32 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return size3ui32(this->width,this->height,this->length);
    }
    size3ui32 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return size3ui32(this->width,this->height,this->length);
    }

    //--
    size3ui32 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return size3ui32(this->width,this->height,this->length);
    }
    size3ui32 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return size3ui32(this->width,this->height,this->length);
    }

    //
    size3ui32 operator()(uint8 width,uint8 height,uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui32((uint32)this->width,(uint32)this->height,(uint32)this->length);
    }
    size3ui32 operator()(uint16 width,uint16 height,uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui32((uint32)this->width,(uint32)this->height,(uint32)this->length);
    }
    size3ui32 operator()(uint32 width,uint32 height,uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui32((uint32)this->width,(uint32)this->height,(uint32)this->length);
    }
    size3ui32 operator()(uint64 width,uint64 height,uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui32((uint32)this->width,(uint32)this->height,(uint32)this->length);
    }
};

//size3ui64
class size3ui64{
    //
public:
    uint64 width,height,length;

    //CONSTRUTOR
    size3ui64(){
        //zera as variaveis
        this->width=this->height=this->length=0;
    }
    size3ui64(uint8 width,uint8 height,uint8 length){
        //zera as variaveis
        this->width=(uint64)width;
        this->height=(uint64)height;
        this->length=(uint64)length;
    }
    size3ui64(uint16 width,uint16 height,uint16 length){
        //zera as variaveis
        this->width=(uint64)width;
        this->height=(uint64)height;
        this->length=(uint64)length;
    }
    size3ui64(uint32 width,uint32 height,uint32 length){
        //zera as variaveis
        this->width=(uint64)width;
        this->height=(uint64)height;
        this->length=(uint64)length;
    }
    size3ui64(uint64 width,uint64 height,uint64 length){
        //zera as variaveis
        this->width=(uint64)width;
        this->height=(uint64)height;
        this->length=(uint64)length;
    }
    size3ui64(uint8 size){
        //zera as variaveis
        this->width=(uint64)size;
        this->height=(uint64)size;
        this->length=(uint64)size;
    }
    size3ui64(uint16 size){
        //zera as variaveis
        this->width=(uint64)size;
        this->height=(uint64)size;
        this->length=(uint64)size;
    }
    size3ui64(uint32 size){
        //zera as variaveis
        this->width=(uint64)size;
        this->height=(uint64)size;
        this->length=(uint64)size;
    }
    size3ui64(uint64 size){
        //zera as variaveis
        this->width=(uint64)size;
        this->height=(uint64)size;
        this->length=(uint64)size;
    }
    //operators

    //=
    size3ui64 operator=(size3ui8 size){
        //
        this->width=(uint64)size.width;
        this->height=(uint64)size.height;
        this->length=size.length;
        return *this;
    }
    size3ui64 operator=(size3ui16 size){
        //
        this->width=(uint64)size.width;
        this->height=(uint64)size.height;
        this->length=size.length;
        return *this;
    }
    size3ui64 operator=(size3ui32 size){
        //
        this->width=(uint64)size.width;
        this->height=(uint64)size.height;
        this->length=size.length;
        return *this;
    }
    size3ui64 operator=(size3ui64 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    size3ui64 operator=(size2i8 size){
        //
        this->width=(uint64)size.width;
        this->height=(uint64)size.height;
        this->length=(uint64)0;
        return *this;
    }
    size3ui64 operator=(uint8 n){
        //
        this->width=(uint64)n;
        this->height=(uint64)n;
        this->length=(uint64)n;
        return *this;
    }
    size3ui64 operator=(uint16 n){
        //
        this->width=(uint64)n;
        this->height=(uint64)n;
        this->length=(uint64)n;
        return *this;
    }
    size3ui64 operator=(uint32 n){
        //
        this->width=(uint64)n;
        this->height=(uint64)n;
        this->length=(uint64)n;
        return *this;
    }
    size3ui64 operator=(uint64 n){
        //
        this->width=(uint64)n;
        this->height=(uint64)n;
        this->length=(uint64)n;
        return *this;
    }

    //==
    bool operator==(size3ui8 size){
        //
        return (this->width==(uint64)size.width&&this->height==(uint64)size.height&&this->length==(uint64)size.length);
    }
    bool operator==(size3ui16 size){
        //
        return (this->width==(uint64)size.width&&this->height==(uint64)size.height&&this->length==(uint64)size.length);
    }
    bool operator==(size3ui32 size){
        //
        return (this->width==(uint64)size.width&&this->height==(uint64)size.height&&this->length==(uint64)size.length);
    }
    bool operator==(size3ui64 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    bool operator!=(size3ui8 size){
        //
        return (this->width!=(uint64)size.width||this->height!=(uint64)size.height||this->length!=(uint64)size.length);
    }
    bool operator!=(size3ui16 size){
        //
        return (this->width!=(uint64)size.width||this->height!=(uint64)size.height||this->length!=(uint64)size.length);
    }
    bool operator!=(size3ui32 size){
        //
        return (this->width!=(uint64)size.width||this->height!=(uint64)size.height||this->length!=(uint64)size.length);
    }
    bool operator!=(size3ui64 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    size3ui64 operator+(size3ui8 size){
        //
        size3ui64 ret;
        ret.width=this->width+(uint64)size.width;
        ret.height=this->height+(uint64)size.height;
        ret.length=this->length+(uint64)size.length;
        return ret;
    }
    size3ui64 operator+(size3ui16 size){
        //
        size3ui64 ret;
        ret.width=this->width+(uint64)size.width;
        ret.height=this->height+(uint64)size.height;
        ret.length=this->length+(uint64)size.length;
        return ret;
    }
    size3ui64 operator+(size3ui32 size){
        //
        size3ui64 ret;
        ret.width=this->width+(uint64)size.width;
        ret.height=this->height+(uint64)size.height;
        ret.length=this->length+(uint64)size.length;
        return ret;
    }
    size3ui64 operator+(size3ui64 size){
        //
        size3ui64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    size3ui64 operator+(size2i8 size){
        //
        size3ui64 ret;
        ret.width=this->width+(uint64)size.width;
        ret.height=this->height+(uint64)size.height;
        return ret;
    }
    size3ui64 operator+(uint8 n){
        //
        size3ui64 ret;
        ret.width=this->width+(uint64)n;
        ret.height=this->height+(uint64)n;
        ret.length=this->length+(uint64)n;
        return ret;
    }
    size3ui64 operator+(uint16 n){
        //
        size3ui64 ret;
        ret.width=this->width+(uint64)n;
        ret.height=this->height+(uint64)n;
        ret.length=this->length+(uint64)n;
        return ret;
    }
    size3ui64 operator+(uint32 n){
        //
        size3ui64 ret;
        ret.width=this->width+(uint64)n;
        ret.height=this->height+(uint64)n;
        ret.length=this->length+(uint64)n;
        return ret;
    }
    size3ui64 operator+(uint64 n){
        //
        size3ui64 ret;
        ret.width=this->width+(uint64)n;
        ret.height=this->height+(uint64)n;
        ret.length=this->length+(uint64)n;
        return ret;
    }

    //+=
    void operator+=(size3ui8 size){
        //
        this->width+=(uint64)size.width;
        this->height+=(uint64)size.height;
        this->length+=(uint64)size.length;
    }
    void operator+=(size3ui16 size){
        //
        this->width+=(uint64)size.width;
        this->height+=(uint64)size.height;
        this->length+=(uint64)size.length;
    }
    void operator+=(size3ui32 size){
        //
        this->width+=(uint64)size.width;
        this->height+=(uint64)size.height;
        this->length+=(uint64)size.length;
    }
    void operator+=(size3ui64 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    void operator+=(size2i8 size){
        //
        this->width+=(uint64)size.width;
        this->height+=(uint64)size.height;
    }
    void operator+=(uint8 n){
        //
        this->width+=(uint64)n;
        this->height+=(uint64)n;
        this->length+=(uint64)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(uint64)n;
        this->height+=(uint64)n;
        this->length+=(uint64)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(uint64)n;
        this->height+=(uint64)n;
        this->length+=(uint64)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(uint64)n;
        this->height+=(uint64)n;
        this->length+=(uint64)n;
    }

    //-
    size3ui64 operator-(size3ui8 size){
        //
        size3ui64 ret;
        ret.width=this->width-(uint64)size.width;
        ret.height=this->height-(uint64)size.height;
        ret.length=this->length-(uint64)size.length;
        return ret;
    }
    size3ui64 operator-(size3ui16 size){
        //
        size3ui64 ret;
        ret.width=this->width-(uint64)size.width;
        ret.height=this->height-(uint64)size.height;
        ret.length=this->length-(uint64)size.length;
        return ret;
    }
    size3ui64 operator-(size3ui32 size){
        //
        size3ui64 ret;
        ret.width=this->width-(uint64)size.width;
        ret.height=this->height-(uint64)size.height;
        ret.length=this->length-(uint64)size.length;
        return ret;
    }
    size3ui64 operator-(size3ui64 size){
        //
        size3ui64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    size3ui64 operator-(size2i8 size){
        //
        size3ui64 ret;
        ret.width=this->width-(uint64)size.width;
        ret.height=this->height-(uint64)size.height;
        return ret;
    }
    size3ui64 operator-(uint8 n){
        //
        size3ui64 ret;
        ret.width=this->width-(uint64)n;
        ret.height=this->height-(uint64)n;
        ret.length=this->length-(uint64)n;
        return ret;
    }
    size3ui64 operator-(uint16 n){
        //
        size3ui64 ret;
        ret.width=this->width-(uint64)n;
        ret.height=this->height-(uint64)n;
        ret.length=this->length-(uint64)n;
        return ret;
    }
    size3ui64 operator-(uint32 n){
        //
        size3ui64 ret;
        ret.width=this->width-(uint64)n;
        ret.height=this->height-(uint64)n;
        ret.length=this->length-(uint64)n;
        return ret;
    }
    size3ui64 operator-(uint64 n){
        //
        size3ui64 ret;
        ret.width=this->width-(uint64)n;
        ret.height=this->height-(uint64)n;
        ret.length=this->length-(uint64)n;
        return ret;
    }

    //-=
    void operator-=(size3ui8 size){
        //
        this->width-=(uint64)size.width;
        this->height-=(uint64)size.height;
        this->length-=(uint64)size.length;
    }
    void operator-=(size3ui16 size){
        //
        this->width-=(uint64)size.width;
        this->height-=(uint64)size.height;
        this->length-=(uint64)size.length;
    }
    void operator-=(size3ui32 size){
        //
        this->width-=(uint64)size.width;
        this->height-=(uint64)size.height;
        this->length-=(uint64)size.length;
    }
    void operator-=(size3ui64 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    void operator-=(size2i8 size){
        //
        this->width-=(uint64)size.width;
        this->height-=(uint64)size.height;
    }
    void operator-=(uint8 n){
        //
        this->width-=(uint64)n;
        this->height-=(uint64)n;
        this->length-=(uint64)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(uint64)n;
        this->height-=(uint64)n;
        this->length-=(uint64)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(uint64)n;
        this->height-=(uint64)n;
        this->length-=(uint64)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(uint64)n;
        this->height-=(uint64)n;
        this->length-=(uint64)n;
    }

    //*
    size3ui64 operator*(size3ui8 size){
        //
        size3ui64 ret;
        ret.width=this->width*(uint64)size.width;
        ret.height=this->height*(uint64)size.height;
        ret.length=this->length*(uint64)size.length;
        return ret;
    }
    size3ui64 operator*(size3ui16 size){
        //
        size3ui64 ret;
        ret.width=this->width*(uint64)size.width;
        ret.height=this->height*(uint64)size.height;
        ret.length=this->length*(uint64)size.length;
        return ret;
    }
    size3ui64 operator*(size3ui32 size){
        //
        size3ui64 ret;
        ret.width=this->width*(uint64)size.width;
        ret.height=this->height*(uint64)size.height;
        ret.length=this->length*(uint64)size.length;
        return ret;
    }
    size3ui64 operator*(size3ui64 size){
        //
        size3ui64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    size3ui64 operator*(size2i8 size){
        //
        size3ui64 ret;
        ret.width=this->width*(uint64)size.width;
        ret.height=this->height*(uint64)size.height;
        return ret;
    }
    size3ui64 operator*(uint8 n){
        //
        size3ui64 ret;
        ret.width=this->width*(uint64)n;
        ret.height=this->height*(uint64)n;
        ret.length=this->length*(uint64)n;
        return ret;
    }
    size3ui64 operator*(uint16 n){
        //
        size3ui64 ret;
        ret.width=this->width*(uint64)n;
        ret.height=this->height*(uint64)n;
        ret.length=this->length*(uint64)n;
        return ret;
    }
    size3ui64 operator*(uint32 n){
        //
        size3ui64 ret;
        ret.width=this->width*(uint64)n;
        ret.height=this->height*(uint64)n;
        ret.length=this->length*(uint64)n;
        return ret;
    }
    size3ui64 operator*(uint64 n){
        //
        size3ui64 ret;
        ret.width=this->width*(uint64)n;
        ret.height=this->height*(uint64)n;
        ret.length=this->length*(uint64)n;
        return ret;
    }

    //*=
    void operator*=(size3ui8 size){
        //
        this->width*=(uint64)size.width;
        this->height*=(uint64)size.height;
        this->length*=(uint64)size.length;
    }
    void operator*=(size3ui16 size){
        //
        this->width*=(uint64)size.width;
        this->height*=(uint64)size.height;
        this->length*=(uint64)size.length;
    }
    void operator*=(size3ui32 size){
        //
        this->width*=(uint64)size.width;
        this->height*=(uint64)size.height;
        this->length*=(uint64)size.length;
    }
    void operator*=(size3ui64 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    void operator*=(size2i8 size){
        //
        this->width*=(uint64)size.width;
        this->height*=(uint64)size.height;
    }
    void operator*=(uint8 n){
        //
        this->width*=(uint64)n;
        this->height*=(uint64)n;
        this->length*=(uint64)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(uint64)n;
        this->height*=(uint64)n;
        this->length*=(uint64)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(uint64)n;
        this->height*=(uint64)n;
        this->length*=(uint64)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(uint64)n;
        this->height*=(uint64)n;
        this->length*=(uint64)n;
    }

    //++
    size3ui64 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return size3ui64(this->width,this->height,this->length);
    }
    size3ui64 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return size3ui64(this->width,this->height,this->length);
    }

    //--
    size3ui64 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return size3ui64(this->width,this->height,this->length);
    }
    size3ui64 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return size3ui64(this->width,this->height,this->length);
    }

    //
    size3ui64 operator()(uint8 width,uint8 height,uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui64((uint64)this->width,(uint64)this->height,(uint64)this->length);
    }
    size3ui64 operator()(uint16 width,uint16 height,uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui64((uint64)this->width,(uint64)this->height,(uint64)this->length);
    }
    size3ui64 operator()(uint32 width,uint32 height,uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui64((uint64)this->width,(uint64)this->height,(uint64)this->length);
    }
    size3ui64 operator()(uint64 width,uint64 height,uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3ui64((uint64)this->width,(uint64)this->height,(uint64)this->length);
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
    size3f32(int8 width,int8 height,int8 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(int16 width,int16 height,int16 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(int32 width,int32 height,int32 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(int64 width,int64 height,int64 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(uint8 width,uint8 height,uint8 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(uint16 width,uint16 height,uint16 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(uint32 width,uint32 height,uint32 length){
        //zera as variaveis
        this->width=(edk::float32)width;
        this->height=(edk::float32)height;
        this->length=(edk::float32)length;
    }
    size3f32(uint64 width,uint64 height,uint64 length){
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
    size3f32(int8 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(int16 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(int32 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(int64 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(uint8 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(uint16 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(uint32 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    size3f32(uint64 size){
        //zera as variaveis
        this->width=(edk::float32)size;
        this->height=(edk::float32)size;
        this->length=(edk::float32)size;
    }
    //operators

    //=
    size3f32 operator=(size3f32 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    size3f32 operator=(size2i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=(edk::float32)0;
        return *this;
    }
    size3f32 operator=(edk::float32 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    size3f32 operator=(edk::float64 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    size3f32 operator=(int8 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    size3f32 operator=(int16 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    size3f32 operator=(int32 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    size3f32 operator=(int64 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    size3f32 operator=(uint8 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    size3f32 operator=(uint16 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    size3f32 operator=(uint32 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }
    size3f32 operator=(uint64 n){
        //
        this->width=(edk::float32)n;
        this->height=(edk::float32)n;
        this->length=(edk::float32)n;
        return *this;
    }

    //==
    bool operator==(size3f32 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    bool operator!=(size3f32 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    size3f32 operator+(size3f32 size){
        //
        size3f32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    size3f32 operator+(size2i8 size){
        //
        size3f32 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size3f32 operator+(edk::float32 n){
        //
        size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    size3f32 operator+(edk::float64 n){
        //
        size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    size3f32 operator+(int8 n){
        //
        size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    size3f32 operator+(int16 n){
        //
        size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    size3f32 operator+(int32 n){
        //
        size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    size3f32 operator+(int64 n){
        //
        size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    size3f32 operator+(uint8 n){
        //
        size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    size3f32 operator+(uint16 n){
        //
        size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    size3f32 operator+(uint32 n){
        //
        size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }
    size3f32 operator+(uint64 n){
        //
        size3f32 ret;
        ret.width=this->width+(edk::float32)n;
        ret.height=this->height+(edk::float32)n;
        ret.length=this->length+(edk::float32)n;
        return ret;
    }

    //+=
    void operator+=(size3f32 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    void operator+=(size2i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(edk::float32 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    void operator+=(edk::float64 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    void operator+=(int8 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(edk::float32)n;
        this->height+=(edk::float32)n;
        this->length+=(edk::float32)n;
    }

    //-
    size3f32 operator-(size3f32 size){
        //
        size3f32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    size3f32 operator-(size2i8 size){
        //
        size3f32 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size3f32 operator-(edk::float32 n){
        //
        size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    size3f32 operator-(edk::float64 n){
        //
        size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    size3f32 operator-(int8 n){
        //
        size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    size3f32 operator-(int16 n){
        //
        size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    size3f32 operator-(int32 n){
        //
        size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    size3f32 operator-(int64 n){
        //
        size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    size3f32 operator-(uint8 n){
        //
        size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    size3f32 operator-(uint16 n){
        //
        size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    size3f32 operator-(uint32 n){
        //
        size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }
    size3f32 operator-(uint64 n){
        //
        size3f32 ret;
        ret.width=this->width-(edk::float32)n;
        ret.height=this->height-(edk::float32)n;
        ret.length=this->length-(edk::float32)n;
        return ret;
    }

    //-=
    void operator-=(size3f32 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    void operator-=(size2i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(edk::float32 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    void operator-=(edk::float64 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    void operator-=(int8 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(edk::float32)n;
        this->height-=(edk::float32)n;
        this->length-=(edk::float32)n;
    }

    //*
    size3f32 operator*(size3f32 size){
        //
        size3f32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    size3f32 operator*(size2i8 size){
        //
        size3f32 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size3f32 operator*(edk::float32 n){
        //
        size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    size3f32 operator*(edk::float64 n){
        //
        size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    size3f32 operator*(int8 n){
        //
        size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    size3f32 operator*(int16 n){
        //
        size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    size3f32 operator*(int32 n){
        //
        size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    size3f32 operator*(int64 n){
        //
        size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    size3f32 operator*(uint8 n){
        //
        size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    size3f32 operator*(uint16 n){
        //
        size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    size3f32 operator*(uint32 n){
        //
        size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }
    size3f32 operator*(uint64 n){
        //
        size3f32 ret;
        ret.width=this->width*(edk::float32)n;
        ret.height=this->height*(edk::float32)n;
        ret.length=this->length*(edk::float32)n;
        return ret;
    }

    //*=
    void operator*=(size3f32 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    void operator*=(size2i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(edk::float32 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    void operator*=(edk::float64 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    void operator*=(int8 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(edk::float32)n;
        this->height*=(edk::float32)n;
        this->length*=(edk::float32)n;
    }

    // /
    size3f32 operator/(size3f32 size){
        //
        size3f32 ret;
        ret.width=this->width/size.width;
        ret.height=this->height/size.height;
        ret.length=this->length/size.length;
        return ret;
    }
    size3f32 operator/(size2i8 size){
        //
        size3f32 ret;
        ret.width=this->width/size.width;
        ret.height=this->height/size.height;
        return ret;
    }
    size3f32 operator/(edk::float32 n){
        //
        size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    size3f32 operator/(edk::float64 n){
        //
        size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    size3f32 operator/(int8 n){
        //
        size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    size3f32 operator/(int16 n){
        //
        size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    size3f32 operator/(int32 n){
        //
        size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    size3f32 operator/(int64 n){
        //
        size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    size3f32 operator/(uint8 n){
        //
        size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    size3f32 operator/(uint16 n){
        //
        size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    size3f32 operator/(uint32 n){
        //
        size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }
    size3f32 operator/(uint64 n){
        //
        size3f32 ret;
        ret.width=this->width/(edk::float32)n;
        ret.height=this->height/(edk::float32)n;
        ret.length=this->length/(edk::float32)n;
        return ret;
    }

    // /=
    void operator/=(size3f32 size){
        //
        this->width/=size.width;
        this->height/=size.height;
        this->length/=size.length;
    }
    void operator/=(size2i8 size){
        //
        this->width/=size.width;
        this->height/=size.height;
    }
    void operator/=(edk::float32 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    void operator/=(edk::float64 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    void operator/=(int8 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    void operator/=(int16 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    void operator/=(int32 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    void operator/=(int64 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    void operator/=(uint8 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    void operator/=(uint16 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    void operator/=(uint32 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }
    void operator/=(uint64 n){
        //
        this->width/=(edk::float32)n;
        this->height/=(edk::float32)n;
        this->length/=(edk::float32)n;
    }

    //++
    size3f32 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return size3f32(this->width,this->height,this->length);
    }
    size3f32 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return size3f32(this->width,this->height,this->length);
    }

    //--
    size3f32 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return size3f32(this->width,this->height,this->length);
    }
    size3f32 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return size3f32(this->width,this->height,this->length);
    }

    //
    size3f32 operator()(edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    size3f32 operator()(edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    size3f32 operator()(int8 width,int8 height,int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    size3f32 operator()(int16 width,int16 height,int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    size3f32 operator()(int32 width,int32 height,int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    size3f32 operator()(int64 width,int64 height,int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    size3f32 operator()(uint8 width,uint8 height,uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    size3f32 operator()(uint16 width,uint16 height,uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    size3f32 operator()(uint32 width,uint32 height,uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
    }
    size3f32 operator()(uint64 width,uint64 height,uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f32((edk::float32)this->width,(edk::float32)this->height,(edk::float32)this->length);
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
    size3f64(int8 width,int8 height,int8 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(int16 width,int16 height,int16 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(int32 width,int32 height,int32 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(int64 width,int64 height,int64 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(uint8 width,uint8 height,uint8 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(uint16 width,uint16 height,uint16 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(uint32 width,uint32 height,uint32 length){
        //zera as variaveis
        this->width=(edk::float64)width;
        this->height=(edk::float64)height;
        this->length=(edk::float64)length;
    }
    size3f64(uint64 width,uint64 height,uint64 length){
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
    size3f64(int8 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(int16 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(int32 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(int64 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(uint8 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(uint16 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(uint32 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    size3f64(uint64 size){
        //zera as variaveis
        this->width=(edk::float64)size;
        this->height=(edk::float64)size;
        this->length=(edk::float64)size;
    }
    //operators

    //=
    size3f64 operator=(size3f64 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=size.length;
        return *this;
    }
    size3f64 operator=(size2i8 size){
        //
        this->width=size.width;
        this->height=size.height;
        this->length=(edk::float64)0;
        return *this;
    }
    size3f64 operator=(edk::float32 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    size3f64 operator=(edk::float64 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    size3f64 operator=(int8 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    size3f64 operator=(int16 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    size3f64 operator=(int32 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    size3f64 operator=(int64 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    size3f64 operator=(uint8 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    size3f64 operator=(uint16 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    size3f64 operator=(uint32 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }
    size3f64 operator=(uint64 n){
        //
        this->width=(edk::float64)n;
        this->height=(edk::float64)n;
        this->length=(edk::float64)n;
        return *this;
    }

    //==
    bool operator==(size3f64 size){
        //
        return (this->width==size.width&&this->height==size.height&&this->length==size.length);
    }
    //!=
    bool operator!=(size3f64 size){
        //
        return (this->width!=size.width||this->height!=size.height||this->length!=size.length);
    }

    //+
    size3f64 operator+(size3f64 size){
        //
        size3f64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        ret.length=this->length+size.length;
        return ret;
    }
    size3f64 operator+(size2i8 size){
        //
        size3f64 ret;
        ret.width=this->width+size.width;
        ret.height=this->height+size.height;
        return ret;
    }
    size3f64 operator+(edk::float32 n){
        //
        size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    size3f64 operator+(edk::float64 n){
        //
        size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    size3f64 operator+(int8 n){
        //
        size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    size3f64 operator+(int16 n){
        //
        size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    size3f64 operator+(int32 n){
        //
        size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    size3f64 operator+(int64 n){
        //
        size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    size3f64 operator+(uint8 n){
        //
        size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    size3f64 operator+(uint16 n){
        //
        size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    size3f64 operator+(uint32 n){
        //
        size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }
    size3f64 operator+(uint64 n){
        //
        size3f64 ret;
        ret.width=this->width+(edk::float64)n;
        ret.height=this->height+(edk::float64)n;
        ret.length=this->length+(edk::float64)n;
        return ret;
    }

    //+=
    void operator+=(size3f64 size){
        //
        this->width+=size.width;
        this->height+=size.height;
        this->length+=size.length;
    }
    void operator+=(size2i8 size){
        //
        this->width+=size.width;
        this->height+=size.height;
    }
    void operator+=(edk::float32 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    void operator+=(edk::float64 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    void operator+=(int8 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    void operator+=(int16 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    void operator+=(int32 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    void operator+=(int64 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    void operator+=(uint8 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    void operator+=(uint16 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    void operator+=(uint32 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }
    void operator+=(uint64 n){
        //
        this->width+=(edk::float64)n;
        this->height+=(edk::float64)n;
        this->length+=(edk::float64)n;
    }

    //-
    size3f64 operator-(size3f64 size){
        //
        size3f64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        ret.length=this->length-size.length;
        return ret;
    }
    size3f64 operator-(size2i8 size){
        //
        size3f64 ret;
        ret.width=this->width-size.width;
        ret.height=this->height-size.height;
        return ret;
    }
    size3f64 operator-(edk::float32 n){
        //
        size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    size3f64 operator-(edk::float64 n){
        //
        size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    size3f64 operator-(int8 n){
        //
        size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    size3f64 operator-(int16 n){
        //
        size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    size3f64 operator-(int32 n){
        //
        size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    size3f64 operator-(int64 n){
        //
        size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    size3f64 operator-(uint8 n){
        //
        size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    size3f64 operator-(uint16 n){
        //
        size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    size3f64 operator-(uint32 n){
        //
        size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }
    size3f64 operator-(uint64 n){
        //
        size3f64 ret;
        ret.width=this->width-(edk::float64)n;
        ret.height=this->height-(edk::float64)n;
        ret.length=this->length-(edk::float64)n;
        return ret;
    }

    //-=
    void operator-=(size3f64 size){
        //
        this->width-=size.width;
        this->height-=size.height;
        this->length-=size.length;
    }
    void operator-=(size2i8 size){
        //
        this->width-=size.width;
        this->height-=size.height;
    }
    void operator-=(edk::float32 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    void operator-=(edk::float64 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    void operator-=(int8 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    void operator-=(int16 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    void operator-=(int32 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    void operator-=(int64 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    void operator-=(uint8 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    void operator-=(uint16 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    void operator-=(uint32 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }
    void operator-=(uint64 n){
        //
        this->width-=(edk::float64)n;
        this->height-=(edk::float64)n;
        this->length-=(edk::float64)n;
    }

    //*
    size3f64 operator*(size3f64 size){
        //
        size3f64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        ret.length=this->length*size.length;
        return ret;
    }
    size3f64 operator*(size2i8 size){
        //
        size3f64 ret;
        ret.width=this->width*size.width;
        ret.height=this->height*size.height;
        return ret;
    }
    size3f64 operator*(edk::float32 n){
        //
        size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    size3f64 operator*(edk::float64 n){
        //
        size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    size3f64 operator*(int8 n){
        //
        size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    size3f64 operator*(int16 n){
        //
        size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    size3f64 operator*(int32 n){
        //
        size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    size3f64 operator*(int64 n){
        //
        size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    size3f64 operator*(uint8 n){
        //
        size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    size3f64 operator*(uint16 n){
        //
        size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    size3f64 operator*(uint32 n){
        //
        size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }
    size3f64 operator*(uint64 n){
        //
        size3f64 ret;
        ret.width=this->width*(edk::float64)n;
        ret.height=this->height*(edk::float64)n;
        ret.length=this->length*(edk::float64)n;
        return ret;
    }

    //*=
    void operator*=(size3f64 size){
        //
        this->width*=size.width;
        this->height*=size.height;
        this->length*=size.length;
    }
    void operator*=(size2i8 size){
        //
        this->width*=size.width;
        this->height*=size.height;
    }
    void operator*=(edk::float32 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    void operator*=(edk::float64 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    void operator*=(int8 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    void operator*=(int16 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    void operator*=(int32 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    void operator*=(int64 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    void operator*=(uint8 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    void operator*=(uint16 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    void operator*=(uint32 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }
    void operator*=(uint64 n){
        //
        this->width*=(edk::float64)n;
        this->height*=(edk::float64)n;
        this->length*=(edk::float64)n;
    }

    // /
    size3f64 operator/(size3f64 size){
        //
        size3f64 ret;
        ret.width=this->width/size.width;
        ret.height=this->height/size.height;
        ret.length=this->length/size.length;
        return ret;
    }
    size3f64 operator/(size2i8 size){
        //
        size3f64 ret;
        ret.width=this->width/size.width;
        ret.height=this->height/size.height;
        return ret;
    }
    size3f64 operator/(edk::float32 n){
        //
        size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    size3f64 operator/(edk::float64 n){
        //
        size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    size3f64 operator/(int8 n){
        //
        size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    size3f64 operator/(int16 n){
        //
        size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    size3f64 operator/(int32 n){
        //
        size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    size3f64 operator/(int64 n){
        //
        size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    size3f64 operator/(uint8 n){
        //
        size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    size3f64 operator/(uint16 n){
        //
        size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    size3f64 operator/(uint32 n){
        //
        size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }
    size3f64 operator/(uint64 n){
        //
        size3f64 ret;
        ret.width=this->width/(edk::float64)n;
        ret.height=this->height/(edk::float64)n;
        ret.length=this->length/(edk::float64)n;
        return ret;
    }

    // /=
    void operator/=(size3f64 size){
        //
        this->width/=size.width;
        this->height/=size.height;
        this->length/=size.length;
    }
    void operator/=(size2i8 size){
        //
        this->width/=size.width;
        this->height/=size.height;
    }
    void operator/=(edk::float32 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    void operator/=(edk::float64 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    void operator/=(int8 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    void operator/=(int16 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    void operator/=(int32 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    void operator/=(int64 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    void operator/=(uint8 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    void operator/=(uint16 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    void operator/=(uint32 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }
    void operator/=(uint64 n){
        //
        this->width/=(edk::float64)n;
        this->height/=(edk::float64)n;
        this->length/=(edk::float64)n;
    }

    //++
    size3f64 operator++(){
        //
        ++this->width;
        ++this->height;
        ++this->length;
        return size3f64(this->width,this->height,this->length);
    }
    size3f64 operator++(edk::int32){
        //
        this->width++;
        this->height++;
        this->length++;
        return size3f64(this->width,this->height,this->length);
    }

    //--
    size3f64 operator--(){
        //
        --this->width;
        --this->height;
        --this->length;
        return size3f64(this->width,this->height,this->length);
    }
    size3f64 operator--(edk::int32){
        //
        this->width--;
        this->height--;
        this->length--;
        return size3f64(this->width,this->height,this->length);
    }

    //
    size3f64 operator()(edk::float32 width,edk::float32 height,edk::float32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    size3f64 operator()(edk::float64 width,edk::float64 height,edk::float64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    size3f64 operator()(int8 width,int8 height,int8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    size3f64 operator()(int16 width,int16 height,int16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    size3f64 operator()(int32 width,int32 height,int32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    size3f64 operator()(int64 width,int64 height,int64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    size3f64 operator()(uint8 width,uint8 height,uint8 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    size3f64 operator()(uint16 width,uint16 height,uint16 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    size3f64 operator()(uint32 width,uint32 height,uint32 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
    size3f64 operator()(uint64 width,uint64 height,uint64 length){
        //
        this->width=width;
        this->height=height;
        this->length=length;
        return size3f64((edk::float64)this->width,(edk::float64)this->height,(edk::float64)this->length);
    }
};

}//end namespace

#endif // TYPESIZE3_H
