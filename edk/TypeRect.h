#ifndef EDK_TYPERECT_H
#define EDK_TYPERECT_H

/*
Library C++ typeRect - Rect types used in Edk Game Engine
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
    vec2i8 origin;
    //size
    size2i8 size;
    //Construtor
    recti8(){
        //
        this->origin.x=(int8)0;
        this->origin.y=(int8)0;
        this->size.width=(int8)0;
        this->size.height=(int8)0;
    }
    recti8(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
    }
    recti8(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
    }
    recti8(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
    }
    recti8(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
    }
    recti8(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
    }
    recti8(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
    }
    recti8(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
    }
    recti8(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
    }
    //operators
    recti8 operator=(recti8 rect){
        //
        this->origin.x=(int8)rect.origin.x;
        this->origin.y=(int8)rect.origin.y;
        this->size.width=(int8)rect.size.width;
        this->size.height=(int8)rect.size.height;
        return *this;
    }
    recti8 operator=(int8 n){
        //
        this->origin.x=(int8)n;
        this->origin.y=(int8)n;
        this->size.width=(int8)n;
        this->size.height=(int8)n;
        return *this;
    }
    recti8 operator=(int32 n){
        //
        this->origin.x=(int8)n;
        this->origin.y=(int8)n;
        this->size.width=(int8)n;
        this->size.height=(int8)n;
        return *this;
    }
    recti8 operator=(int16 n){
        //
        this->origin.x=(int8)n;
        this->origin.y=(int8)n;
        this->size.width=(int8)n;
        this->size.height=(int8)n;
        return *this;
    }
    recti8 operator=(int64 n){
        //
        this->origin.x=(int8)n;
        this->origin.y=(int8)n;
        this->size.width=(int8)n;
        this->size.height=(int8)n;
        return *this;
    }
    recti8 operator=(uint8 n){
        //
        this->origin.x=(int8)n;
        this->origin.y=(int8)n;
        this->size.width=(int8)n;
        this->size.height=(int8)n;
        return *this;
    }
    recti8 operator=(uint32 n){
        //
        this->origin.x=(int8)n;
        this->origin.y=(int8)n;
        this->size.width=(int8)n;
        this->size.height=(int8)n;
        return *this;
    }
    recti8 operator=(uint16 n){
        //
        this->origin.x=(int8)n;
        this->origin.y=(int8)n;
        this->size.width=(int8)n;
        this->size.height=(int8)n;
        return *this;
    }
    recti8 operator=(uint64 n){
        //
        this->origin.x=(int8)n;
        this->origin.y=(int8)n;
        this->size.width=(int8)n;
        this->size.height=(int8)n;
        return *this;
    }

    bool operator==(recti8 rect){
        //
        return (this->origin.x==(int8)rect.origin.x
                &&this->origin.y==(int8)rect.origin.y
                &&this->size.width==(int8)rect.size.width
                &&this->size.height==(int8)rect.size.height
                );
    }
    bool operator!=(recti8 rect){
        //
        return (this->origin.x!=(int8)rect.origin.x
                ||this->origin.y!=(int8)rect.origin.y
                ||this->size.width!=(int8)rect.size.width
                ||this->size.height!=(int8)rect.size.height
                );
    }
    recti8 operator+(recti8 rect){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(int8)rect.origin.x;
        ret.origin.y=this->origin.y+(int8)rect.origin.y;
        ret.size.width=this->size.width+(int8)rect.size.width;
        ret.size.height=this->size.height+(int8)rect.size.height;
        return ret;
    }
    recti8 operator+(int8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(int8)n;
        ret.origin.y=this->origin.y+(int8)n;
        ret.size.width=this->size.width+(int8)n;
        ret.size.height=this->size.height+(int8)n;
        return ret;
    }
    recti8 operator+(int32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(int8)n;
        ret.origin.y=this->origin.y+(int8)n;
        ret.size.width=this->size.width+(int8)n;
        ret.size.height=this->size.height+(int8)n;
        return ret;
    }
    recti8 operator+(int16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(int8)n;
        ret.origin.y=this->origin.y+(int8)n;
        ret.size.width=this->size.width+(int8)n;
        ret.size.height=this->size.height+(int8)n;
        return ret;
    }
    recti8 operator+(int64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(int8)n;
        ret.origin.y=this->origin.y+(int8)n;
        ret.size.width=this->size.width+(int8)n;
        ret.size.height=this->size.height+(int8)n;
        return ret;
    }
    recti8 operator+(uint8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(int8)n;
        ret.origin.y=this->origin.y+(int8)n;
        ret.size.width=this->size.width+(int8)n;
        ret.size.height=this->size.height+(int8)n;
        return ret;
    }
    recti8 operator+(uint32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(int8)n;
        ret.origin.y=this->origin.y+(int8)n;
        ret.size.width=this->size.width+(int8)n;
        ret.size.height=this->size.height+(int8)n;
        return ret;
    }
    recti8 operator+(uint16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(int8)n;
        ret.origin.y=this->origin.y+(int8)n;
        ret.size.width=this->size.width+(int8)n;
        ret.size.height=this->size.height+(int8)n;
        return ret;
    }
    recti8 operator+(uint64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x+(int8)n;
        ret.origin.y=this->origin.y+(int8)n;
        ret.size.width=this->size.width+(int8)n;
        ret.size.height=this->size.height+(int8)n;
        return ret;
    }
    void operator+=(recti8 rect){
        //
        this->origin.x+=(int8)rect.origin.x;
        this->origin.y+=(int8)rect.origin.y;
        this->size.width+=(int8)rect.size.width;
        this->size.height+=(int8)rect.size.height;
    }
    void operator+=(int8 n){
        //
        this->origin.x+=(int8)n;
        this->origin.y+=(int8)n;
        this->size.width+=(int8)n;
        this->size.height+=(int8)n;
    }
    void operator+=(int32 n){
        //
        this->origin.x+=(int8)n;
        this->origin.y+=(int8)n;
        this->size.width+=(int8)n;
        this->size.height+=(int8)n;
    }
    void operator+=(int16 n){
        //
        this->origin.x+=(int8)n;
        this->origin.y+=(int8)n;
        this->size.width+=(int8)n;
        this->size.height+=(int8)n;
    }
    void operator+=(int64 n){
        //
        this->origin.x+=(int8)n;
        this->origin.y+=(int8)n;
        this->size.width+=(int8)n;
        this->size.height+=(int8)n;
    }
    void operator+=(uint8 n){
        //
        this->origin.x+=(int8)n;
        this->origin.y+=(int8)n;
        this->size.width+=(int8)n;
        this->size.height+=(int8)n;
    }
    void operator+=(uint32 n){
        //
        this->origin.x+=(int8)n;
        this->origin.y+=(int8)n;
        this->size.width+=(int8)n;
        this->size.height+=(int8)n;
    }
    void operator+=(uint16 n){
        //
        this->origin.x+=(int8)n;
        this->origin.y+=(int8)n;
        this->size.width+=(int8)n;
        this->size.height+=(int8)n;
    }
    void operator+=(uint64 n){
        //
        this->origin.x+=(int8)n;
        this->origin.y+=(int8)n;
        this->size.width+=(int8)n;
        this->size.height+=(int8)n;
    }
    recti8 operator-(recti8 rect){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(int8)rect.origin.x;
        ret.origin.y=this->origin.y-(int8)rect.origin.y;
        ret.size.width=this->size.width-(int8)rect.size.width;
        ret.size.height=this->size.height-(int8)rect.size.height;
        return ret;
    }
    recti8 operator-(int8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(int8)n;
        ret.origin.y=this->origin.y-(int8)n;
        ret.size.width=this->size.width-(int8)n;
        ret.size.height=this->size.height-(int8)n;
        return ret;
    }
    recti8 operator-(int32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(int8)n;
        ret.origin.y=this->origin.y-(int8)n;
        ret.size.width=this->size.width-(int8)n;
        ret.size.height=this->size.height-(int8)n;
        return ret;
    }
    recti8 operator-(int16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(int8)n;
        ret.origin.y=this->origin.y-(int8)n;
        ret.size.width=this->size.width-(int8)n;
        ret.size.height=this->size.height-(int8)n;
        return ret;
    }
    recti8 operator-(int64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(int8)n;
        ret.origin.y=this->origin.y-(int8)n;
        ret.size.width=this->size.width-(int8)n;
        ret.size.height=this->size.height-(int8)n;
        return ret;
    }
    recti8 operator-(uint8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(int8)n;
        ret.origin.y=this->origin.y-(int8)n;
        ret.size.width=this->size.width-(int8)n;
        ret.size.height=this->size.height-(int8)n;
        return ret;
    }
    recti8 operator-(uint32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(int8)n;
        ret.origin.y=this->origin.y-(int8)n;
        ret.size.width=this->size.width-(int8)n;
        ret.size.height=this->size.height-(int8)n;
        return ret;
    }
    recti8 operator-(uint16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(int8)n;
        ret.origin.y=this->origin.y-(int8)n;
        ret.size.width=this->size.width-(int8)n;
        ret.size.height=this->size.height-(int8)n;
        return ret;
    }
    recti8 operator-(uint64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x-(int8)n;
        ret.origin.y=this->origin.y-(int8)n;
        ret.size.width=this->size.width-(int8)n;
        ret.size.height=this->size.height-(int8)n;
        return ret;
    }
    void operator-=(recti8 vec){
        //
        this->origin.x-=(int8)vec.origin.x;
        this->origin.y-=(int8)vec.origin.y;
        this->size.width-=(int8)vec.size.width;
        this->size.height-=(int8)vec.size.height;
    }
    void operator-=(int8 n){
        //
        this->origin.x-=(int8)n;
        this->origin.y-=(int8)n;
        this->size.width-=(int8)n;
        this->size.height-=(int8)n;
    }
    void operator-=(int32 n){
        //
        this->origin.x-=(int8)n;
        this->origin.y-=(int8)n;
        this->size.width-=(int8)n;
        this->size.height-=(int8)n;
    }
    void operator-=(int16 n){
        //
        this->origin.x-=(int8)n;
        this->origin.y-=(int8)n;
        this->size.width-=(int8)n;
        this->size.height-=(int8)n;
    }
    void operator-=(int64 n){
        //
        this->origin.x-=(int8)n;
        this->origin.y-=(int8)n;
        this->size.width-=(int8)n;
        this->size.height-=(int8)n;
    }
    void operator-=(uint8 n){
        //
        this->origin.x-=(int8)n;
        this->origin.y-=(int8)n;
        this->size.width-=(int8)n;
        this->size.height-=(int8)n;
    }
    void operator-=(uint32 n){
        //
        this->origin.x-=(int8)n;
        this->origin.y-=(int8)n;
        this->size.width-=(int8)n;
        this->size.height-=(int8)n;
    }
    void operator-=(uint16 n){
        //
        this->origin.x-=(int8)n;
        this->origin.y-=(int8)n;
        this->size.width-=(int8)n;
        this->size.height-=(int8)n;
    }
    void operator-=(uint64 n){
        //
        this->origin.x-=(int8)n;
        this->origin.y-=(int8)n;
        this->size.width-=(int8)n;
        this->size.height-=(int8)n;
    }
    recti8 operator*(recti8 rect){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(int8)rect.origin.x;
        ret.origin.y=this->origin.y*(int8)rect.origin.y;
        ret.size.width=this->size.width*(int8)rect.size.width;
        ret.size.height=this->size.height*(int8)rect.size.height;
        return ret;
    }
    recti8 operator*(int8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(int8)n;
        ret.origin.y=this->origin.y*(int8)n;
        ret.size.width=this->size.width*(int8)n;
        ret.size.height=this->size.height*(int8)n;
        return ret;
    }
    recti8 operator*(int32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(int8)n;
        ret.origin.y=this->origin.y*(int8)n;
        ret.size.width=this->size.width*(int8)n;
        ret.size.height=this->size.height*(int8)n;
        return ret;
    }
    recti8 operator*(int16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(int8)n;
        ret.origin.y=this->origin.y*(int8)n;
        ret.size.width=this->size.width*(int8)n;
        ret.size.height=this->size.height*(int8)n;
        return ret;
    }
    recti8 operator*(int64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(int8)n;
        ret.origin.y=this->origin.y*(int8)n;
        ret.size.width=this->size.width*(int8)n;
        ret.size.height=this->size.height*(int8)n;
        return ret;
    }
    recti8 operator*(uint8 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(int8)n;
        ret.origin.y=this->origin.y*(int8)n;
        ret.size.width=this->size.width*(int8)n;
        ret.size.height=this->size.height*(int8)n;
        return ret;
    }
    recti8 operator*(uint32 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(int8)n;
        ret.origin.y=this->origin.y*(int8)n;
        ret.size.width=this->size.width*(int8)n;
        ret.size.height=this->size.height*(int8)n;
        return ret;
    }
    recti8 operator*(uint16 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(int8)n;
        ret.origin.y=this->origin.y*(int8)n;
        ret.size.width=this->size.width*(int8)n;
        ret.size.height=this->size.height*(int8)n;
        return ret;
    }
    recti8 operator*(uint64 n){
        //
        recti8 ret;
        ret.origin.x=this->origin.x*(int8)n;
        ret.origin.y=this->origin.y*(int8)n;
        ret.size.width=this->size.width*(int8)n;
        ret.size.height=this->size.height*(int8)n;
        return ret;
    }
    void operator*=(recti8 rect){
        //
        this->origin.x*=(int8)rect.origin.x;
        this->origin.y*=(int8)rect.origin.y;
        this->size.width*=(int8)rect.size.width;
        this->size.height*=(int8)rect.size.height;
    }
    void operator*=(int8 n){
        //
        this->origin.x*=(int8)n;
        this->origin.y*=(int8)n;
        this->size.width*=(int8)n;
        this->size.height*=(int8)n;
    }
    void operator*=(int32 n){
        //
        this->origin.x*=(int8)n;
        this->origin.y*=(int8)n;
        this->size.width*=(int8)n;
        this->size.height*=(int8)n;
    }
    void operator*=(int16 n){
        //
        this->origin.x*=(int8)n;
        this->origin.y*=(int8)n;
        this->size.width*=(int8)n;
        this->size.height*=(int8)n;
    }
    void operator*=(int64 n){
        //
        this->origin.x*=(int8)n;
        this->origin.y*=(int8)n;
        this->size.width*=(int8)n;
        this->size.height*=(int8)n;
    }
    void operator*=(uint8 n){
        //
        this->origin.x*=(int8)n;
        this->origin.y*=(int8)n;
        this->size.width*=(int8)n;
        this->size.height*=(int8)n;
    }
    void operator*=(uint32 n){
        //
        this->origin.x*=(int8)n;
        this->origin.y*=(int8)n;
        this->size.width*=(int8)n;
        this->size.height*=(int8)n;
    }
    void operator*=(uint16 n){
        //
        this->origin.x*=(int8)n;
        this->origin.y*=(int8)n;
        this->size.width*=(int8)n;
        this->size.height*=(int8)n;
    }
    void operator*=(uint64 n){
        //
        this->origin.x*=(int8)n;
        this->origin.y*=(int8)n;
        this->size.width*=(int8)n;
        this->size.height*=(int8)n;
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
    recti8 operator++(int32){
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
    recti8 operator--(int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return recti8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti8 operator()(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti8((int8)this->origin.x,(int8)this->origin.y,(int8)this->size.width,(int8)this->size.height);
    }
    recti8 operator()(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
        return recti8((int8)this->origin.x,(int8)this->origin.y,(int8)this->size.width,(int8)this->size.height);
    }
    recti8 operator()(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
        return recti8((int8)this->origin.x,(int8)this->origin.y,(int8)this->size.width,(int8)this->size.height);
    }
    recti8 operator()(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
        return recti8((int8)this->origin.x,(int8)this->origin.y,(int8)this->size.width,(int8)this->size.height);
    }
    recti8 operator()(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti8((int8)this->origin.x,(int8)this->origin.y,(int8)this->size.width,(int8)this->size.height);
    }
    recti8 operator()(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
        return recti8((int8)this->origin.x,(int8)this->origin.y,(int8)this->size.width,(int8)this->size.height);
    }
    recti8 operator()(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
        return recti8((int8)this->origin.x,(int8)this->origin.y,(int8)this->size.width,(int8)this->size.height);
    }
    recti8 operator()(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(int8)x;
        this->origin.y=(int8)y;
        this->size.width=(int8)width;
        this->size.height=(int8)height;
        return recti8((int8)this->origin.x,(int8)this->origin.y,(int8)this->size.width,(int8)this->size.height);
    }
};

class recti16{
public:
    //position
    vec2i16 origin;
    //size
    size2i16 size;
    //Construtor
    recti16(){
        //
        this->origin.x=(int16)0;
        this->origin.y=(int16)0;
        this->size.width=(int16)0;
        this->size.height=(int16)0;
    }
    recti16(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
    }
    recti16(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
    }
    recti16(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
    }
    recti16(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
    }
    recti16(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
    }
    recti16(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
    }
    recti16(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
    }
    recti16(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
    }

    //operators
    recti16 operator=(recti8 rect){
        //
        this->origin.x=(int16)rect.origin.x;
        this->origin.y=(int16)rect.origin.y;
        this->size.width=(int16)rect.size.width;
        this->size.height=(int16)rect.size.height;
        return *this;
    }
    recti16 operator=(recti16 rect){
        //
        this->origin.x=(int16)rect.origin.x;
        this->origin.y=(int16)rect.origin.y;
        this->size.width=(int16)rect.size.width;
        this->size.height=(int16)rect.size.height;
        return *this;
    }
    recti16 operator=(int8 n){
        //
        this->origin.x=(int16)n;
        this->origin.y=(int16)n;
        this->size.width=(int16)n;
        this->size.height=(int16)n;
        return *this;
    }
    recti16 operator=(int32 n){
        //
        this->origin.x=(int16)n;
        this->origin.y=(int16)n;
        this->size.width=(int16)n;
        this->size.height=(int16)n;
        return *this;
    }
    recti16 operator=(int16 n){
        //
        this->origin.x=(int16)n;
        this->origin.y=(int16)n;
        this->size.width=(int16)n;
        this->size.height=(int16)n;
        return *this;
    }
    recti16 operator=(int64 n){
        //
        this->origin.x=(int16)n;
        this->origin.y=(int16)n;
        this->size.width=(int16)n;
        this->size.height=(int16)n;
        return *this;
    }
    recti16 operator=(uint8 n){
        //
        this->origin.x=(int16)n;
        this->origin.y=(int16)n;
        this->size.width=(int16)n;
        this->size.height=(int16)n;
        return *this;
    }
    recti16 operator=(uint32 n){
        //
        this->origin.x=(int16)n;
        this->origin.y=(int16)n;
        this->size.width=(int16)n;
        this->size.height=(int16)n;
        return *this;
    }
    recti16 operator=(uint16 n){
        //
        this->origin.x=(int16)n;
        this->origin.y=(int16)n;
        this->size.width=(int16)n;
        this->size.height=(int16)n;
        return *this;
    }
    recti16 operator=(uint64 n){
        //
        this->origin.x=(int16)n;
        this->origin.y=(int16)n;
        this->size.width=(int16)n;
        this->size.height=(int16)n;
        return *this;
    }

    bool operator==(recti8 rect){
        //
        return (this->origin.x==(int16)rect.origin.x
                &&this->origin.y==(int16)rect.origin.y
                &&this->size.width==(int16)rect.size.width
                &&this->size.height==(int16)rect.size.height
                );
    }
    bool operator==(recti16 rect){
        //
        return (this->origin.x==(int16)rect.origin.x
                &&this->origin.y==(int16)rect.origin.y
                &&this->size.width==(int16)rect.size.width
                &&this->size.height==(int16)rect.size.height
                );
    }
    bool operator!=(recti8 rect){
        //
        return (this->origin.x!=(int16)rect.origin.x
                ||this->origin.y!=(int16)rect.origin.y
                ||this->size.width!=(int16)rect.size.width
                ||this->size.height!=(int16)rect.size.height
                );
    }
    bool operator!=(recti16 rect){
        //
        return (this->origin.x!=(int16)rect.origin.x
                ||this->origin.y!=(int16)rect.origin.y
                ||this->size.width!=(int16)rect.size.width
                ||this->size.height!=(int16)rect.size.height
                );
    }
    recti16 operator+(recti8 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(int16)rect.origin.x;
        ret.origin.y=this->origin.y+(int16)rect.origin.y;
        ret.size.width=this->size.width+(int16)rect.size.width;
        ret.size.height=this->size.height+(int16)rect.size.height;
        return ret;
    }
    recti16 operator+(recti16 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(int16)rect.origin.x;
        ret.origin.y=this->origin.y+(int16)rect.origin.y;
        ret.size.width=this->size.width+(int16)rect.size.width;
        ret.size.height=this->size.height+(int16)rect.size.height;
        return ret;
    }
    recti16 operator+(int8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(int16)n;
        ret.origin.y=this->origin.y+(int16)n;
        ret.size.width=this->size.width+(int16)n;
        ret.size.height=this->size.height+(int16)n;
        return ret;
    }
    recti16 operator+(int32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(int16)n;
        ret.origin.y=this->origin.y+(int16)n;
        ret.size.width=this->size.width+(int16)n;
        ret.size.height=this->size.height+(int16)n;
        return ret;
    }
    recti16 operator+(int16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(int16)n;
        ret.origin.y=this->origin.y+(int16)n;
        ret.size.width=this->size.width+(int16)n;
        ret.size.height=this->size.height+(int16)n;
        return ret;
    }
    recti16 operator+(int64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(int16)n;
        ret.origin.y=this->origin.y+(int16)n;
        ret.size.width=this->size.width+(int16)n;
        ret.size.height=this->size.height+(int16)n;
        return ret;
    }
    recti16 operator+(uint8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(int16)n;
        ret.origin.y=this->origin.y+(int16)n;
        ret.size.width=this->size.width+(int16)n;
        ret.size.height=this->size.height+(int16)n;
        return ret;
    }
    recti16 operator+(uint32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(int16)n;
        ret.origin.y=this->origin.y+(int16)n;
        ret.size.width=this->size.width+(int16)n;
        ret.size.height=this->size.height+(int16)n;
        return ret;
    }
    recti16 operator+(uint16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(int16)n;
        ret.origin.y=this->origin.y+(int16)n;
        ret.size.width=this->size.width+(int16)n;
        ret.size.height=this->size.height+(int16)n;
        return ret;
    }
    recti16 operator+(uint64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x+(int16)n;
        ret.origin.y=this->origin.y+(int16)n;
        ret.size.width=this->size.width+(int16)n;
        ret.size.height=this->size.height+(int16)n;
        return ret;
    }
    void operator+=(recti8 rect){
        //
        this->origin.x+=(int16)rect.origin.x;
        this->origin.y+=(int16)rect.origin.y;
        this->size.width+=(int16)rect.size.width;
        this->size.height+=(int16)rect.size.height;
    }
    void operator+=(recti16 rect){
        //
        this->origin.x+=(int16)rect.origin.x;
        this->origin.y+=(int16)rect.origin.y;
        this->size.width+=(int16)rect.size.width;
        this->size.height+=(int16)rect.size.height;
    }
    void operator+=(int8 n){
        //
        this->origin.x+=(int16)n;
        this->origin.y+=(int16)n;
        this->size.width+=(int16)n;
        this->size.height+=(int16)n;
    }
    void operator+=(int32 n){
        //
        this->origin.x+=(int16)n;
        this->origin.y+=(int16)n;
        this->size.width+=(int16)n;
        this->size.height+=(int16)n;
    }
    void operator+=(int16 n){
        //
        this->origin.x+=(int16)n;
        this->origin.y+=(int16)n;
        this->size.width+=(int16)n;
        this->size.height+=(int16)n;
    }
    void operator+=(int64 n){
        //
        this->origin.x+=(int16)n;
        this->origin.y+=(int16)n;
        this->size.width+=(int16)n;
        this->size.height+=(int16)n;
    }
    void operator+=(uint8 n){
        //
        this->origin.x+=(int16)n;
        this->origin.y+=(int16)n;
        this->size.width+=(int16)n;
        this->size.height+=(int16)n;
    }
    void operator+=(uint32 n){
        //
        this->origin.x+=(int16)n;
        this->origin.y+=(int16)n;
        this->size.width+=(int16)n;
        this->size.height+=(int16)n;
    }
    void operator+=(uint16 n){
        //
        this->origin.x+=(int16)n;
        this->origin.y+=(int16)n;
        this->size.width+=(int16)n;
        this->size.height+=(int16)n;
    }
    void operator+=(uint64 n){
        //
        this->origin.x+=(int16)n;
        this->origin.y+=(int16)n;
        this->size.width+=(int16)n;
        this->size.height+=(int16)n;
    }
    recti16 operator-(recti8 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(int16)rect.origin.x;
        ret.origin.y=this->origin.y-(int16)rect.origin.y;
        ret.size.width=this->size.width-(int16)rect.size.width;
        ret.size.height=this->size.height-(int16)rect.size.height;
        return ret;
    }
    recti16 operator-(recti16 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(int16)rect.origin.x;
        ret.origin.y=this->origin.y-(int16)rect.origin.y;
        ret.size.width=this->size.width-(int16)rect.size.width;
        ret.size.height=this->size.height-(int16)rect.size.height;
        return ret;
    }
    recti16 operator-(int8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(int16)n;
        ret.origin.y=this->origin.y-(int16)n;
        ret.size.width=this->size.width-(int16)n;
        ret.size.height=this->size.height-(int16)n;
        return ret;
    }
    recti16 operator-(int32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(int16)n;
        ret.origin.y=this->origin.y-(int16)n;
        ret.size.width=this->size.width-(int16)n;
        ret.size.height=this->size.height-(int16)n;
        return ret;
    }
    recti16 operator-(int16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(int16)n;
        ret.origin.y=this->origin.y-(int16)n;
        ret.size.width=this->size.width-(int16)n;
        ret.size.height=this->size.height-(int16)n;
        return ret;
    }
    recti16 operator-(int64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(int16)n;
        ret.origin.y=this->origin.y-(int16)n;
        ret.size.width=this->size.width-(int16)n;
        ret.size.height=this->size.height-(int16)n;
        return ret;
    }
    recti16 operator-(uint8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(int16)n;
        ret.origin.y=this->origin.y-(int16)n;
        ret.size.width=this->size.width-(int16)n;
        ret.size.height=this->size.height-(int16)n;
        return ret;
    }
    recti16 operator-(uint32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(int16)n;
        ret.origin.y=this->origin.y-(int16)n;
        ret.size.width=this->size.width-(int16)n;
        ret.size.height=this->size.height-(int16)n;
        return ret;
    }
    recti16 operator-(uint16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(int16)n;
        ret.origin.y=this->origin.y-(int16)n;
        ret.size.width=this->size.width-(int16)n;
        ret.size.height=this->size.height-(int16)n;
        return ret;
    }
    recti16 operator-(uint64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x-(int16)n;
        ret.origin.y=this->origin.y-(int16)n;
        ret.size.width=this->size.width-(int16)n;
        ret.size.height=this->size.height-(int16)n;
        return ret;
    }
    void operator-=(recti8 vec){
        //
        this->origin.x-=(int16)vec.origin.x;
        this->origin.y-=(int16)vec.origin.y;
        this->size.width-=(int16)vec.size.width;
        this->size.height-=(int16)vec.size.height;
    }
    void operator-=(recti16 vec){
        //
        this->origin.x-=(int16)vec.origin.x;
        this->origin.y-=(int16)vec.origin.y;
        this->size.width-=(int16)vec.size.width;
        this->size.height-=(int16)vec.size.height;
    }
    void operator-=(int8 n){
        //
        this->origin.x-=(int16)n;
        this->origin.y-=(int16)n;
        this->size.width-=(int16)n;
        this->size.height-=(int16)n;
    }
    void operator-=(int32 n){
        //
        this->origin.x-=(int16)n;
        this->origin.y-=(int16)n;
        this->size.width-=(int16)n;
        this->size.height-=(int16)n;
    }
    void operator-=(int16 n){
        //
        this->origin.x-=(int16)n;
        this->origin.y-=(int16)n;
        this->size.width-=(int16)n;
        this->size.height-=(int16)n;
    }
    void operator-=(int64 n){
        //
        this->origin.x-=(int16)n;
        this->origin.y-=(int16)n;
        this->size.width-=(int16)n;
        this->size.height-=(int16)n;
    }
    void operator-=(uint8 n){
        //
        this->origin.x-=(int16)n;
        this->origin.y-=(int16)n;
        this->size.width-=(int16)n;
        this->size.height-=(int16)n;
    }
    void operator-=(uint32 n){
        //
        this->origin.x-=(int16)n;
        this->origin.y-=(int16)n;
        this->size.width-=(int16)n;
        this->size.height-=(int16)n;
    }
    void operator-=(uint16 n){
        //
        this->origin.x-=(int16)n;
        this->origin.y-=(int16)n;
        this->size.width-=(int16)n;
        this->size.height-=(int16)n;
    }
    void operator-=(uint64 n){
        //
        this->origin.x-=(int16)n;
        this->origin.y-=(int16)n;
        this->size.width-=(int16)n;
        this->size.height-=(int16)n;
    }
    recti16 operator*(recti8 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(int16)rect.origin.x;
        ret.origin.y=this->origin.y*(int16)rect.origin.y;
        ret.size.width=this->size.width*(int16)rect.size.width;
        ret.size.height=this->size.height*(int16)rect.size.height;
        return ret;
    }
    recti16 operator*(recti16 rect){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(int16)rect.origin.x;
        ret.origin.y=this->origin.y*(int16)rect.origin.y;
        ret.size.width=this->size.width*(int16)rect.size.width;
        ret.size.height=this->size.height*(int16)rect.size.height;
        return ret;
    }
    recti16 operator*(int8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(int16)n;
        ret.origin.y=this->origin.y*(int16)n;
        ret.size.width=this->size.width*(int16)n;
        ret.size.height=this->size.height*(int16)n;
        return ret;
    }
    recti16 operator*(int32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(int16)n;
        ret.origin.y=this->origin.y*(int16)n;
        ret.size.width=this->size.width*(int16)n;
        ret.size.height=this->size.height*(int16)n;
        return ret;
    }
    recti16 operator*(int16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(int16)n;
        ret.origin.y=this->origin.y*(int16)n;
        ret.size.width=this->size.width*(int16)n;
        ret.size.height=this->size.height*(int16)n;
        return ret;
    }
    recti16 operator*(int64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(int16)n;
        ret.origin.y=this->origin.y*(int16)n;
        ret.size.width=this->size.width*(int16)n;
        ret.size.height=this->size.height*(int16)n;
        return ret;
    }
    recti16 operator*(uint8 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(int16)n;
        ret.origin.y=this->origin.y*(int16)n;
        ret.size.width=this->size.width*(int16)n;
        ret.size.height=this->size.height*(int16)n;
        return ret;
    }
    recti16 operator*(uint32 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(int16)n;
        ret.origin.y=this->origin.y*(int16)n;
        ret.size.width=this->size.width*(int16)n;
        ret.size.height=this->size.height*(int16)n;
        return ret;
    }
    recti16 operator*(uint16 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(int16)n;
        ret.origin.y=this->origin.y*(int16)n;
        ret.size.width=this->size.width*(int16)n;
        ret.size.height=this->size.height*(int16)n;
        return ret;
    }
    recti16 operator*(uint64 n){
        //
        recti16 ret;
        ret.origin.x=this->origin.x*(int16)n;
        ret.origin.y=this->origin.y*(int16)n;
        ret.size.width=this->size.width*(int16)n;
        ret.size.height=this->size.height*(int16)n;
        return ret;
    }
    void operator*=(recti8 rect){
        //
        this->origin.x*=(int16)rect.origin.x;
        this->origin.y*=(int16)rect.origin.y;
        this->size.width*=(int16)rect.size.width;
        this->size.height*=(int16)rect.size.height;
    }
    void operator*=(recti16 rect){
        //
        this->origin.x*=(int16)rect.origin.x;
        this->origin.y*=(int16)rect.origin.y;
        this->size.width*=(int16)rect.size.width;
        this->size.height*=(int16)rect.size.height;
    }
    void operator*=(int8 n){
        //
        this->origin.x*=(int16)n;
        this->origin.y*=(int16)n;
        this->size.width*=(int16)n;
        this->size.height*=(int16)n;
    }
    void operator*=(int32 n){
        //
        this->origin.x*=(int16)n;
        this->origin.y*=(int16)n;
        this->size.width*=(int16)n;
        this->size.height*=(int16)n;
    }
    void operator*=(int16 n){
        //
        this->origin.x*=(int16)n;
        this->origin.y*=(int16)n;
        this->size.width*=(int16)n;
        this->size.height*=(int16)n;
    }
    void operator*=(int64 n){
        //
        this->origin.x*=(int16)n;
        this->origin.y*=(int16)n;
        this->size.width*=(int16)n;
        this->size.height*=(int16)n;
    }
    void operator*=(uint8 n){
        //
        this->origin.x*=(int16)n;
        this->origin.y*=(int16)n;
        this->size.width*=(int16)n;
        this->size.height*=(int16)n;
    }
    void operator*=(uint32 n){
        //
        this->origin.x*=(int16)n;
        this->origin.y*=(int16)n;
        this->size.width*=(int16)n;
        this->size.height*=(int16)n;
    }
    void operator*=(uint16 n){
        //
        this->origin.x*=(int16)n;
        this->origin.y*=(int16)n;
        this->size.width*=(int16)n;
        this->size.height*=(int16)n;
    }
    void operator*=(uint64 n){
        //
        this->origin.x*=(int16)n;
        this->origin.y*=(int16)n;
        this->size.width*=(int16)n;
        this->size.height*=(int16)n;
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
    recti16 operator++(int32){
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
    recti16 operator--(int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return recti16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti16 operator()(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti16((int16)this->origin.x,(int16)this->origin.y,(int16)this->size.width,(int16)this->size.height);
    }
    recti16 operator()(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
        return recti16((int16)this->origin.x,(int16)this->origin.y,(int16)this->size.width,(int16)this->size.height);
    }
    recti16 operator()(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
        return recti16((int16)this->origin.x,(int16)this->origin.y,(int16)this->size.width,(int16)this->size.height);
    }
    recti16 operator()(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
        return recti16((int16)this->origin.x,(int16)this->origin.y,(int16)this->size.width,(int16)this->size.height);
    }
    recti16 operator()(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti16((int16)this->origin.x,(int16)this->origin.y,(int16)this->size.width,(int16)this->size.height);
    }
    recti16 operator()(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
        return recti16((int16)this->origin.x,(int16)this->origin.y,(int16)this->size.width,(int16)this->size.height);
    }
    recti16 operator()(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
        return recti16((int16)this->origin.x,(int16)this->origin.y,(int16)this->size.width,(int16)this->size.height);
    }
    recti16 operator()(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(int16)x;
        this->origin.y=(int16)y;
        this->size.width=(int16)width;
        this->size.height=(int16)height;
        return recti16((int16)this->origin.x,(int16)this->origin.y,(int16)this->size.width,(int16)this->size.height);
    }
};

class recti32{
public:
    //position
    vec2i32 origin;
    //size
    size2i32 size;
    //Construtor
    recti32(){
        //
        this->origin.x=(int32)0;
        this->origin.y=(int32)0;
        this->size.width=(int32)0;
        this->size.height=(int32)0;
    }
    recti32(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
    }
    recti32(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
    }
    recti32(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
    }
    recti32(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
    }
    recti32(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
    }
    recti32(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
    }
    recti32(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
    }
    recti32(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
    }

    //operators
    recti32 operator=(recti8 rect){
        //
        this->origin.x=(int32)rect.origin.x;
        this->origin.y=(int32)rect.origin.y;
        this->size.width=(int32)rect.size.width;
        this->size.height=(int32)rect.size.height;
        return *this;
    }
    recti32 operator=(recti16 rect){
        //
        this->origin.x=(int32)rect.origin.x;
        this->origin.y=(int32)rect.origin.y;
        this->size.width=(int32)rect.size.width;
        this->size.height=(int32)rect.size.height;
        return *this;
    }
    recti32 operator=(recti32 rect){
        //
        this->origin.x=(int32)rect.origin.x;
        this->origin.y=(int32)rect.origin.y;
        this->size.width=(int32)rect.size.width;
        this->size.height=(int32)rect.size.height;
        return *this;
    }
    recti32 operator=(int8 n){
        //
        this->origin.x=(int32)n;
        this->origin.y=(int32)n;
        this->size.width=(int32)n;
        this->size.height=(int32)n;
        return *this;
    }
    recti32 operator=(int32 n){
        //
        this->origin.x=(int32)n;
        this->origin.y=(int32)n;
        this->size.width=(int32)n;
        this->size.height=(int32)n;
        return *this;
    }
    recti32 operator=(int16 n){
        //
        this->origin.x=(int32)n;
        this->origin.y=(int32)n;
        this->size.width=(int32)n;
        this->size.height=(int32)n;
        return *this;
    }
    recti32 operator=(int64 n){
        //
        this->origin.x=(int32)n;
        this->origin.y=(int32)n;
        this->size.width=(int32)n;
        this->size.height=(int32)n;
        return *this;
    }
    recti32 operator=(uint8 n){
        //
        this->origin.x=(int32)n;
        this->origin.y=(int32)n;
        this->size.width=(int32)n;
        this->size.height=(int32)n;
        return *this;
    }
    recti32 operator=(uint32 n){
        //
        this->origin.x=(int32)n;
        this->origin.y=(int32)n;
        this->size.width=(int32)n;
        this->size.height=(int32)n;
        return *this;
    }
    recti32 operator=(uint16 n){
        //
        this->origin.x=(int32)n;
        this->origin.y=(int32)n;
        this->size.width=(int32)n;
        this->size.height=(int32)n;
        return *this;
    }
    recti32 operator=(uint64 n){
        //
        this->origin.x=(int32)n;
        this->origin.y=(int32)n;
        this->size.width=(int32)n;
        this->size.height=(int32)n;
        return *this;
    }

    bool operator==(recti8 rect){
        //
        return (this->origin.x==(int32)rect.origin.x
                &&this->origin.y==(int32)rect.origin.y
                &&this->size.width==(int32)rect.size.width
                &&this->size.height==(int32)rect.size.height
                );
    }
    bool operator==(recti16 rect){
        //
        return (this->origin.x==(int32)rect.origin.x
                &&this->origin.y==(int32)rect.origin.y
                &&this->size.width==(int32)rect.size.width
                &&this->size.height==(int32)rect.size.height
                );
    }
    bool operator==(recti32 rect){
        //
        return (this->origin.x==(int32)rect.origin.x
                &&this->origin.y==(int32)rect.origin.y
                &&this->size.width==(int32)rect.size.width
                &&this->size.height==(int32)rect.size.height
                );
    }
    bool operator!=(recti8 rect){
        //
        return (this->origin.x!=(int32)rect.origin.x
                ||this->origin.y!=(int32)rect.origin.y
                ||this->size.width!=(int32)rect.size.width
                ||this->size.height!=(int32)rect.size.height
                );
    }
    bool operator!=(recti16 rect){
        //
        return (this->origin.x!=(int32)rect.origin.x
                ||this->origin.y!=(int32)rect.origin.y
                ||this->size.width!=(int32)rect.size.width
                ||this->size.height!=(int32)rect.size.height
                );
    }
    bool operator!=(recti32 rect){
        //
        return (this->origin.x!=(int32)rect.origin.x
                ||this->origin.y!=(int32)rect.origin.y
                ||this->size.width!=(int32)rect.size.width
                ||this->size.height!=(int32)rect.size.height
                );
    }
    recti32 operator+(recti8 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)rect.origin.x;
        ret.origin.y=this->origin.y+(int32)rect.origin.y;
        ret.size.width=this->size.width+(int32)rect.size.width;
        ret.size.height=this->size.height+(int32)rect.size.height;
        return ret;
    }
    recti32 operator+(recti16 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)rect.origin.x;
        ret.origin.y=this->origin.y+(int32)rect.origin.y;
        ret.size.width=this->size.width+(int32)rect.size.width;
        ret.size.height=this->size.height+(int32)rect.size.height;
        return ret;
    }
    recti32 operator+(recti32 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)rect.origin.x;
        ret.origin.y=this->origin.y+(int32)rect.origin.y;
        ret.size.width=this->size.width+(int32)rect.size.width;
        ret.size.height=this->size.height+(int32)rect.size.height;
        return ret;
    }
    recti32 operator+(int8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)n;
        ret.origin.y=this->origin.y+(int32)n;
        ret.size.width=this->size.width+(int32)n;
        ret.size.height=this->size.height+(int32)n;
        return ret;
    }
    recti32 operator+(int32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)n;
        ret.origin.y=this->origin.y+(int32)n;
        ret.size.width=this->size.width+(int32)n;
        ret.size.height=this->size.height+(int32)n;
        return ret;
    }
    recti32 operator+(int16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)n;
        ret.origin.y=this->origin.y+(int32)n;
        ret.size.width=this->size.width+(int32)n;
        ret.size.height=this->size.height+(int32)n;
        return ret;
    }
    recti32 operator+(int64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)n;
        ret.origin.y=this->origin.y+(int32)n;
        ret.size.width=this->size.width+(int32)n;
        ret.size.height=this->size.height+(int32)n;
        return ret;
    }
    recti32 operator+(uint8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)n;
        ret.origin.y=this->origin.y+(int32)n;
        ret.size.width=this->size.width+(int32)n;
        ret.size.height=this->size.height+(int32)n;
        return ret;
    }
    recti32 operator+(uint32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)n;
        ret.origin.y=this->origin.y+(int32)n;
        ret.size.width=this->size.width+(int32)n;
        ret.size.height=this->size.height+(int32)n;
        return ret;
    }
    recti32 operator+(uint16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)n;
        ret.origin.y=this->origin.y+(int32)n;
        ret.size.width=this->size.width+(int32)n;
        ret.size.height=this->size.height+(int32)n;
        return ret;
    }
    recti32 operator+(uint64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x+(int32)n;
        ret.origin.y=this->origin.y+(int32)n;
        ret.size.width=this->size.width+(int32)n;
        ret.size.height=this->size.height+(int32)n;
        return ret;
    }
    void operator+=(recti8 rect){
        //
        this->origin.x+=(int32)rect.origin.x;
        this->origin.y+=(int32)rect.origin.y;
        this->size.width+=(int32)rect.size.width;
        this->size.height+=(int32)rect.size.height;
    }
    void operator+=(recti16 rect){
        //
        this->origin.x+=(int32)rect.origin.x;
        this->origin.y+=(int32)rect.origin.y;
        this->size.width+=(int32)rect.size.width;
        this->size.height+=(int32)rect.size.height;
    }
    void operator+=(recti32 rect){
        //
        this->origin.x+=(int32)rect.origin.x;
        this->origin.y+=(int32)rect.origin.y;
        this->size.width+=(int32)rect.size.width;
        this->size.height+=(int32)rect.size.height;
    }
    void operator+=(int8 n){
        //
        this->origin.x+=(int32)n;
        this->origin.y+=(int32)n;
        this->size.width+=(int32)n;
        this->size.height+=(int32)n;
    }
    void operator+=(int32 n){
        //
        this->origin.x+=(int32)n;
        this->origin.y+=(int32)n;
        this->size.width+=(int32)n;
        this->size.height+=(int32)n;
    }
    void operator+=(int16 n){
        //
        this->origin.x+=(int32)n;
        this->origin.y+=(int32)n;
        this->size.width+=(int32)n;
        this->size.height+=(int32)n;
    }
    void operator+=(int64 n){
        //
        this->origin.x+=(int32)n;
        this->origin.y+=(int32)n;
        this->size.width+=(int32)n;
        this->size.height+=(int32)n;
    }
    void operator+=(uint8 n){
        //
        this->origin.x+=(int32)n;
        this->origin.y+=(int32)n;
        this->size.width+=(int32)n;
        this->size.height+=(int32)n;
    }
    void operator+=(uint32 n){
        //
        this->origin.x+=(int32)n;
        this->origin.y+=(int32)n;
        this->size.width+=(int32)n;
        this->size.height+=(int32)n;
    }
    void operator+=(uint16 n){
        //
        this->origin.x+=(int32)n;
        this->origin.y+=(int32)n;
        this->size.width+=(int32)n;
        this->size.height+=(int32)n;
    }
    void operator+=(uint64 n){
        //
        this->origin.x+=(int32)n;
        this->origin.y+=(int32)n;
        this->size.width+=(int32)n;
        this->size.height+=(int32)n;
    }
    recti32 operator-(recti8 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)rect.origin.x;
        ret.origin.y=this->origin.y-(int32)rect.origin.y;
        ret.size.width=this->size.width-(int32)rect.size.width;
        ret.size.height=this->size.height-(int32)rect.size.height;
        return ret;
    }
    recti32 operator-(recti16 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)rect.origin.x;
        ret.origin.y=this->origin.y-(int32)rect.origin.y;
        ret.size.width=this->size.width-(int32)rect.size.width;
        ret.size.height=this->size.height-(int32)rect.size.height;
        return ret;
    }
    recti32 operator-(recti32 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)rect.origin.x;
        ret.origin.y=this->origin.y-(int32)rect.origin.y;
        ret.size.width=this->size.width-(int32)rect.size.width;
        ret.size.height=this->size.height-(int32)rect.size.height;
        return ret;
    }
    recti32 operator-(int8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)n;
        ret.origin.y=this->origin.y-(int32)n;
        ret.size.width=this->size.width-(int32)n;
        ret.size.height=this->size.height-(int32)n;
        return ret;
    }
    recti32 operator-(int32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)n;
        ret.origin.y=this->origin.y-(int32)n;
        ret.size.width=this->size.width-(int32)n;
        ret.size.height=this->size.height-(int32)n;
        return ret;
    }
    recti32 operator-(int16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)n;
        ret.origin.y=this->origin.y-(int32)n;
        ret.size.width=this->size.width-(int32)n;
        ret.size.height=this->size.height-(int32)n;
        return ret;
    }
    recti32 operator-(int64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)n;
        ret.origin.y=this->origin.y-(int32)n;
        ret.size.width=this->size.width-(int32)n;
        ret.size.height=this->size.height-(int32)n;
        return ret;
    }
    recti32 operator-(uint8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)n;
        ret.origin.y=this->origin.y-(int32)n;
        ret.size.width=this->size.width-(int32)n;
        ret.size.height=this->size.height-(int32)n;
        return ret;
    }
    recti32 operator-(uint32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)n;
        ret.origin.y=this->origin.y-(int32)n;
        ret.size.width=this->size.width-(int32)n;
        ret.size.height=this->size.height-(int32)n;
        return ret;
    }
    recti32 operator-(uint16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)n;
        ret.origin.y=this->origin.y-(int32)n;
        ret.size.width=this->size.width-(int32)n;
        ret.size.height=this->size.height-(int32)n;
        return ret;
    }
    recti32 operator-(uint64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x-(int32)n;
        ret.origin.y=this->origin.y-(int32)n;
        ret.size.width=this->size.width-(int32)n;
        ret.size.height=this->size.height-(int32)n;
        return ret;
    }
    void operator-=(recti8 vec){
        //
        this->origin.x-=(int32)vec.origin.x;
        this->origin.y-=(int32)vec.origin.y;
        this->size.width-=(int32)vec.size.width;
        this->size.height-=(int32)vec.size.height;
    }
    void operator-=(recti16 vec){
        //
        this->origin.x-=(int32)vec.origin.x;
        this->origin.y-=(int32)vec.origin.y;
        this->size.width-=(int32)vec.size.width;
        this->size.height-=(int32)vec.size.height;
    }
    void operator-=(recti32 vec){
        //
        this->origin.x-=(int32)vec.origin.x;
        this->origin.y-=(int32)vec.origin.y;
        this->size.width-=(int32)vec.size.width;
        this->size.height-=(int32)vec.size.height;
    }
    void operator-=(int8 n){
        //
        this->origin.x-=(int32)n;
        this->origin.y-=(int32)n;
        this->size.width-=(int32)n;
        this->size.height-=(int32)n;
    }
    void operator-=(int32 n){
        //
        this->origin.x-=(int32)n;
        this->origin.y-=(int32)n;
        this->size.width-=(int32)n;
        this->size.height-=(int32)n;
    }
    void operator-=(int16 n){
        //
        this->origin.x-=(int32)n;
        this->origin.y-=(int32)n;
        this->size.width-=(int32)n;
        this->size.height-=(int32)n;
    }
    void operator-=(int64 n){
        //
        this->origin.x-=(int32)n;
        this->origin.y-=(int32)n;
        this->size.width-=(int32)n;
        this->size.height-=(int32)n;
    }
    void operator-=(uint8 n){
        //
        this->origin.x-=(int32)n;
        this->origin.y-=(int32)n;
        this->size.width-=(int32)n;
        this->size.height-=(int32)n;
    }
    void operator-=(uint32 n){
        //
        this->origin.x-=(int32)n;
        this->origin.y-=(int32)n;
        this->size.width-=(int32)n;
        this->size.height-=(int32)n;
    }
    void operator-=(uint16 n){
        //
        this->origin.x-=(int32)n;
        this->origin.y-=(int32)n;
        this->size.width-=(int32)n;
        this->size.height-=(int32)n;
    }
    void operator-=(uint64 n){
        //
        this->origin.x-=(int32)n;
        this->origin.y-=(int32)n;
        this->size.width-=(int32)n;
        this->size.height-=(int32)n;
    }
    recti32 operator*(recti8 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)rect.origin.x;
        ret.origin.y=this->origin.y*(int32)rect.origin.y;
        ret.size.width=this->size.width*(int32)rect.size.width;
        ret.size.height=this->size.height*(int32)rect.size.height;
        return ret;
    }
    recti32 operator*(recti16 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)rect.origin.x;
        ret.origin.y=this->origin.y*(int32)rect.origin.y;
        ret.size.width=this->size.width*(int32)rect.size.width;
        ret.size.height=this->size.height*(int32)rect.size.height;
        return ret;
    }
    recti32 operator*(recti32 rect){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)rect.origin.x;
        ret.origin.y=this->origin.y*(int32)rect.origin.y;
        ret.size.width=this->size.width*(int32)rect.size.width;
        ret.size.height=this->size.height*(int32)rect.size.height;
        return ret;
    }
    recti32 operator*(int8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)n;
        ret.origin.y=this->origin.y*(int32)n;
        ret.size.width=this->size.width*(int32)n;
        ret.size.height=this->size.height*(int32)n;
        return ret;
    }
    recti32 operator*(int32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)n;
        ret.origin.y=this->origin.y*(int32)n;
        ret.size.width=this->size.width*(int32)n;
        ret.size.height=this->size.height*(int32)n;
        return ret;
    }
    recti32 operator*(int16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)n;
        ret.origin.y=this->origin.y*(int32)n;
        ret.size.width=this->size.width*(int32)n;
        ret.size.height=this->size.height*(int32)n;
        return ret;
    }
    recti32 operator*(int64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)n;
        ret.origin.y=this->origin.y*(int32)n;
        ret.size.width=this->size.width*(int32)n;
        ret.size.height=this->size.height*(int32)n;
        return ret;
    }
    recti32 operator*(uint8 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)n;
        ret.origin.y=this->origin.y*(int32)n;
        ret.size.width=this->size.width*(int32)n;
        ret.size.height=this->size.height*(int32)n;
        return ret;
    }
    recti32 operator*(uint32 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)n;
        ret.origin.y=this->origin.y*(int32)n;
        ret.size.width=this->size.width*(int32)n;
        ret.size.height=this->size.height*(int32)n;
        return ret;
    }
    recti32 operator*(uint16 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)n;
        ret.origin.y=this->origin.y*(int32)n;
        ret.size.width=this->size.width*(int32)n;
        ret.size.height=this->size.height*(int32)n;
        return ret;
    }
    recti32 operator*(uint64 n){
        //
        recti32 ret;
        ret.origin.x=this->origin.x*(int32)n;
        ret.origin.y=this->origin.y*(int32)n;
        ret.size.width=this->size.width*(int32)n;
        ret.size.height=this->size.height*(int32)n;
        return ret;
    }
    void operator*=(recti8 rect){
        //
        this->origin.x*=(int32)rect.origin.x;
        this->origin.y*=(int32)rect.origin.y;
        this->size.width*=(int32)rect.size.width;
        this->size.height*=(int32)rect.size.height;
    }
    void operator*=(recti16 rect){
        //
        this->origin.x*=(int32)rect.origin.x;
        this->origin.y*=(int32)rect.origin.y;
        this->size.width*=(int32)rect.size.width;
        this->size.height*=(int32)rect.size.height;
    }
    void operator*=(recti32 rect){
        //
        this->origin.x*=(int32)rect.origin.x;
        this->origin.y*=(int32)rect.origin.y;
        this->size.width*=(int32)rect.size.width;
        this->size.height*=(int32)rect.size.height;
    }
    void operator*=(int8 n){
        //
        this->origin.x*=(int32)n;
        this->origin.y*=(int32)n;
        this->size.width*=(int32)n;
        this->size.height*=(int32)n;
    }
    void operator*=(int32 n){
        //
        this->origin.x*=(int32)n;
        this->origin.y*=(int32)n;
        this->size.width*=(int32)n;
        this->size.height*=(int32)n;
    }
    void operator*=(int16 n){
        //
        this->origin.x*=(int32)n;
        this->origin.y*=(int32)n;
        this->size.width*=(int32)n;
        this->size.height*=(int32)n;
    }
    void operator*=(int64 n){
        //
        this->origin.x*=(int32)n;
        this->origin.y*=(int32)n;
        this->size.width*=(int32)n;
        this->size.height*=(int32)n;
    }
    void operator*=(uint8 n){
        //
        this->origin.x*=(int32)n;
        this->origin.y*=(int32)n;
        this->size.width*=(int32)n;
        this->size.height*=(int32)n;
    }
    void operator*=(uint32 n){
        //
        this->origin.x*=(int32)n;
        this->origin.y*=(int32)n;
        this->size.width*=(int32)n;
        this->size.height*=(int32)n;
    }
    void operator*=(uint16 n){
        //
        this->origin.x*=(int32)n;
        this->origin.y*=(int32)n;
        this->size.width*=(int32)n;
        this->size.height*=(int32)n;
    }
    void operator*=(uint64 n){
        //
        this->origin.x*=(int32)n;
        this->origin.y*=(int32)n;
        this->size.width*=(int32)n;
        this->size.height*=(int32)n;
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
    recti32 operator++(int32){
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
    recti32 operator--(int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return recti32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti32 operator()(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti32((int32)this->origin.x,(int32)this->origin.y,(int32)this->size.width,(int32)this->size.height);
    }
    recti32 operator()(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
        return recti32((int32)this->origin.x,(int32)this->origin.y,(int32)this->size.width,(int32)this->size.height);
    }
    recti32 operator()(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
        return recti32((int32)this->origin.x,(int32)this->origin.y,(int32)this->size.width,(int32)this->size.height);
    }
    recti32 operator()(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
        return recti32((int32)this->origin.x,(int32)this->origin.y,(int32)this->size.width,(int32)this->size.height);
    }
    recti32 operator()(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti32((int32)this->origin.x,(int32)this->origin.y,(int32)this->size.width,(int32)this->size.height);
    }
    recti32 operator()(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
        return recti32((int32)this->origin.x,(int32)this->origin.y,(int32)this->size.width,(int32)this->size.height);
    }
    recti32 operator()(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
        return recti32((int32)this->origin.x,(int32)this->origin.y,(int32)this->size.width,(int32)this->size.height);
    }
    recti32 operator()(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(int32)x;
        this->origin.y=(int32)y;
        this->size.width=(int32)width;
        this->size.height=(int32)height;
        return recti32((int32)this->origin.x,(int32)this->origin.y,(int32)this->size.width,(int32)this->size.height);
    }
};

class recti64{
public:
    //position
    vec2i64 origin;
    //size
    size2i64 size;
    //Construtor
    recti64(){
        //
        this->origin.x=(int64)0;
        this->origin.y=(int64)0;
        this->size.width=(int64)0;
        this->size.height=(int64)0;
    }
    recti64(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
    }
    recti64(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
    }
    recti64(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
    }
    recti64(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
    }
    recti64(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
    }
    recti64(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
    }
    recti64(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
    }
    recti64(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
    }

    //operators
    recti64 operator=(recti8 rect){
        //
        this->origin.x=(int64)rect.origin.x;
        this->origin.y=(int64)rect.origin.y;
        this->size.width=(int64)rect.size.width;
        this->size.height=(int64)rect.size.height;
        return *this;
    }
    recti64 operator=(recti16 rect){
        //
        this->origin.x=(int64)rect.origin.x;
        this->origin.y=(int64)rect.origin.y;
        this->size.width=(int64)rect.size.width;
        this->size.height=(int64)rect.size.height;
        return *this;
    }
    recti64 operator=(recti32 rect){
        //
        this->origin.x=(int64)rect.origin.x;
        this->origin.y=(int64)rect.origin.y;
        this->size.width=(int64)rect.size.width;
        this->size.height=(int64)rect.size.height;
        return *this;
    }
    recti64 operator=(recti64 rect){
        //
        this->origin.x=(int64)rect.origin.x;
        this->origin.y=(int64)rect.origin.y;
        this->size.width=(int64)rect.size.width;
        this->size.height=(int64)rect.size.height;
        return *this;
    }
    recti64 operator=(int8 n){
        //
        this->origin.x=(int64)n;
        this->origin.y=(int64)n;
        this->size.width=(int64)n;
        this->size.height=(int64)n;
        return *this;
    }
    recti64 operator=(int32 n){
        //
        this->origin.x=(int64)n;
        this->origin.y=(int64)n;
        this->size.width=(int64)n;
        this->size.height=(int64)n;
        return *this;
    }
    recti64 operator=(int16 n){
        //
        this->origin.x=(int64)n;
        this->origin.y=(int64)n;
        this->size.width=(int64)n;
        this->size.height=(int64)n;
        return *this;
    }
    recti64 operator=(int64 n){
        //
        this->origin.x=(int64)n;
        this->origin.y=(int64)n;
        this->size.width=(int64)n;
        this->size.height=(int64)n;
        return *this;
    }
    recti64 operator=(uint8 n){
        //
        this->origin.x=(int64)n;
        this->origin.y=(int64)n;
        this->size.width=(int64)n;
        this->size.height=(int64)n;
        return *this;
    }
    recti64 operator=(uint32 n){
        //
        this->origin.x=(int64)n;
        this->origin.y=(int64)n;
        this->size.width=(int64)n;
        this->size.height=(int64)n;
        return *this;
    }
    recti64 operator=(uint16 n){
        //
        this->origin.x=(int64)n;
        this->origin.y=(int64)n;
        this->size.width=(int64)n;
        this->size.height=(int64)n;
        return *this;
    }
    recti64 operator=(uint64 n){
        //
        this->origin.x=(int64)n;
        this->origin.y=(int64)n;
        this->size.width=(int64)n;
        this->size.height=(int64)n;
        return *this;
    }

    bool operator==(recti8 rect){
        //
        return (this->origin.x==(int64)rect.origin.x
                &&this->origin.y==(int64)rect.origin.y
                &&this->size.width==(int64)rect.size.width
                &&this->size.height==(int64)rect.size.height
                );
    }
    bool operator==(recti16 rect){
        //
        return (this->origin.x==(int64)rect.origin.x
                &&this->origin.y==(int64)rect.origin.y
                &&this->size.width==(int64)rect.size.width
                &&this->size.height==(int64)rect.size.height
                );
    }
    bool operator==(recti32 rect){
        //
        return (this->origin.x==(int64)rect.origin.x
                &&this->origin.y==(int64)rect.origin.y
                &&this->size.width==(int64)rect.size.width
                &&this->size.height==(int64)rect.size.height
                );
    }
    bool operator==(recti64 rect){
        //
        return (this->origin.x==(int64)rect.origin.x
                &&this->origin.y==(int64)rect.origin.y
                &&this->size.width==(int64)rect.size.width
                &&this->size.height==(int64)rect.size.height
                );
    }
    bool operator!=(recti8 rect){
        //
        return (this->origin.x!=(int64)rect.origin.x
                ||this->origin.y!=(int64)rect.origin.y
                ||this->size.width!=(int64)rect.size.width
                ||this->size.height!=(int64)rect.size.height
                );
    }
    bool operator!=(recti16 rect){
        //
        return (this->origin.x!=(int64)rect.origin.x
                ||this->origin.y!=(int64)rect.origin.y
                ||this->size.width!=(int64)rect.size.width
                ||this->size.height!=(int64)rect.size.height
                );
    }
    bool operator!=(recti32 rect){
        //
        return (this->origin.x!=(int64)rect.origin.x
                ||this->origin.y!=(int64)rect.origin.y
                ||this->size.width!=(int64)rect.size.width
                ||this->size.height!=(int64)rect.size.height
                );
    }
    bool operator!=(recti64 rect){
        //
        return (this->origin.x!=(int64)rect.origin.x
                ||this->origin.y!=(int64)rect.origin.y
                ||this->size.width!=(int64)rect.size.width
                ||this->size.height!=(int64)rect.size.height
                );
    }
    recti64 operator+(recti8 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)rect.origin.x;
        ret.origin.y=this->origin.y+(int64)rect.origin.y;
        ret.size.width=this->size.width+(int64)rect.size.width;
        ret.size.height=this->size.height+(int64)rect.size.height;
        return ret;
    }
    recti64 operator+(recti16 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)rect.origin.x;
        ret.origin.y=this->origin.y+(int64)rect.origin.y;
        ret.size.width=this->size.width+(int64)rect.size.width;
        ret.size.height=this->size.height+(int64)rect.size.height;
        return ret;
    }
    recti64 operator+(recti32 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)rect.origin.x;
        ret.origin.y=this->origin.y+(int64)rect.origin.y;
        ret.size.width=this->size.width+(int64)rect.size.width;
        ret.size.height=this->size.height+(int64)rect.size.height;
        return ret;
    }
    recti64 operator+(recti64 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)rect.origin.x;
        ret.origin.y=this->origin.y+(int64)rect.origin.y;
        ret.size.width=this->size.width+(int64)rect.size.width;
        ret.size.height=this->size.height+(int64)rect.size.height;
        return ret;
    }
    recti64 operator+(int8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)n;
        ret.origin.y=this->origin.y+(int64)n;
        ret.size.width=this->size.width+(int64)n;
        ret.size.height=this->size.height+(int64)n;
        return ret;
    }
    recti64 operator+(int32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)n;
        ret.origin.y=this->origin.y+(int64)n;
        ret.size.width=this->size.width+(int64)n;
        ret.size.height=this->size.height+(int64)n;
        return ret;
    }
    recti64 operator+(int16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)n;
        ret.origin.y=this->origin.y+(int64)n;
        ret.size.width=this->size.width+(int64)n;
        ret.size.height=this->size.height+(int64)n;
        return ret;
    }
    recti64 operator+(int64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)n;
        ret.origin.y=this->origin.y+(int64)n;
        ret.size.width=this->size.width+(int64)n;
        ret.size.height=this->size.height+(int64)n;
        return ret;
    }
    recti64 operator+(uint8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)n;
        ret.origin.y=this->origin.y+(int64)n;
        ret.size.width=this->size.width+(int64)n;
        ret.size.height=this->size.height+(int64)n;
        return ret;
    }
    recti64 operator+(uint32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)n;
        ret.origin.y=this->origin.y+(int64)n;
        ret.size.width=this->size.width+(int64)n;
        ret.size.height=this->size.height+(int64)n;
        return ret;
    }
    recti64 operator+(uint16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)n;
        ret.origin.y=this->origin.y+(int64)n;
        ret.size.width=this->size.width+(int64)n;
        ret.size.height=this->size.height+(int64)n;
        return ret;
    }
    recti64 operator+(uint64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x+(int64)n;
        ret.origin.y=this->origin.y+(int64)n;
        ret.size.width=this->size.width+(int64)n;
        ret.size.height=this->size.height+(int64)n;
        return ret;
    }
    void operator+=(recti8 rect){
        //
        this->origin.x+=(int64)rect.origin.x;
        this->origin.y+=(int64)rect.origin.y;
        this->size.width+=(int64)rect.size.width;
        this->size.height+=(int64)rect.size.height;
    }
    void operator+=(recti16 rect){
        //
        this->origin.x+=(int64)rect.origin.x;
        this->origin.y+=(int64)rect.origin.y;
        this->size.width+=(int64)rect.size.width;
        this->size.height+=(int64)rect.size.height;
    }
    void operator+=(recti32 rect){
        //
        this->origin.x+=(int64)rect.origin.x;
        this->origin.y+=(int64)rect.origin.y;
        this->size.width+=(int64)rect.size.width;
        this->size.height+=(int64)rect.size.height;
    }
    void operator+=(recti64 rect){
        //
        this->origin.x+=(int64)rect.origin.x;
        this->origin.y+=(int64)rect.origin.y;
        this->size.width+=(int64)rect.size.width;
        this->size.height+=(int64)rect.size.height;
    }
    void operator+=(int8 n){
        //
        this->origin.x+=(int64)n;
        this->origin.y+=(int64)n;
        this->size.width+=(int64)n;
        this->size.height+=(int64)n;
    }
    void operator+=(int32 n){
        //
        this->origin.x+=(int64)n;
        this->origin.y+=(int64)n;
        this->size.width+=(int64)n;
        this->size.height+=(int64)n;
    }
    void operator+=(int16 n){
        //
        this->origin.x+=(int64)n;
        this->origin.y+=(int64)n;
        this->size.width+=(int64)n;
        this->size.height+=(int64)n;
    }
    void operator+=(int64 n){
        //
        this->origin.x+=(int64)n;
        this->origin.y+=(int64)n;
        this->size.width+=(int64)n;
        this->size.height+=(int64)n;
    }
    void operator+=(uint8 n){
        //
        this->origin.x+=(int64)n;
        this->origin.y+=(int64)n;
        this->size.width+=(int64)n;
        this->size.height+=(int64)n;
    }
    void operator+=(uint32 n){
        //
        this->origin.x+=(int64)n;
        this->origin.y+=(int64)n;
        this->size.width+=(int64)n;
        this->size.height+=(int64)n;
    }
    void operator+=(uint16 n){
        //
        this->origin.x+=(int64)n;
        this->origin.y+=(int64)n;
        this->size.width+=(int64)n;
        this->size.height+=(int64)n;
    }
    void operator+=(uint64 n){
        //
        this->origin.x+=(int64)n;
        this->origin.y+=(int64)n;
        this->size.width+=(int64)n;
        this->size.height+=(int64)n;
    }
    recti64 operator-(recti8 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)rect.origin.x;
        ret.origin.y=this->origin.y-(int64)rect.origin.y;
        ret.size.width=this->size.width-(int64)rect.size.width;
        ret.size.height=this->size.height-(int64)rect.size.height;
        return ret;
    }
    recti64 operator-(recti16 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)rect.origin.x;
        ret.origin.y=this->origin.y-(int64)rect.origin.y;
        ret.size.width=this->size.width-(int64)rect.size.width;
        ret.size.height=this->size.height-(int64)rect.size.height;
        return ret;
    }
    recti64 operator-(recti32 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)rect.origin.x;
        ret.origin.y=this->origin.y-(int64)rect.origin.y;
        ret.size.width=this->size.width-(int64)rect.size.width;
        ret.size.height=this->size.height-(int64)rect.size.height;
        return ret;
    }
    recti64 operator-(recti64 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)rect.origin.x;
        ret.origin.y=this->origin.y-(int64)rect.origin.y;
        ret.size.width=this->size.width-(int64)rect.size.width;
        ret.size.height=this->size.height-(int64)rect.size.height;
        return ret;
    }
    recti64 operator-(int8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)n;
        ret.origin.y=this->origin.y-(int64)n;
        ret.size.width=this->size.width-(int64)n;
        ret.size.height=this->size.height-(int64)n;
        return ret;
    }
    recti64 operator-(int32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)n;
        ret.origin.y=this->origin.y-(int64)n;
        ret.size.width=this->size.width-(int64)n;
        ret.size.height=this->size.height-(int64)n;
        return ret;
    }
    recti64 operator-(int16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)n;
        ret.origin.y=this->origin.y-(int64)n;
        ret.size.width=this->size.width-(int64)n;
        ret.size.height=this->size.height-(int64)n;
        return ret;
    }
    recti64 operator-(int64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)n;
        ret.origin.y=this->origin.y-(int64)n;
        ret.size.width=this->size.width-(int64)n;
        ret.size.height=this->size.height-(int64)n;
        return ret;
    }
    recti64 operator-(uint8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)n;
        ret.origin.y=this->origin.y-(int64)n;
        ret.size.width=this->size.width-(int64)n;
        ret.size.height=this->size.height-(int64)n;
        return ret;
    }
    recti64 operator-(uint32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)n;
        ret.origin.y=this->origin.y-(int64)n;
        ret.size.width=this->size.width-(int64)n;
        ret.size.height=this->size.height-(int64)n;
        return ret;
    }
    recti64 operator-(uint16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)n;
        ret.origin.y=this->origin.y-(int64)n;
        ret.size.width=this->size.width-(int64)n;
        ret.size.height=this->size.height-(int64)n;
        return ret;
    }
    recti64 operator-(uint64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x-(int64)n;
        ret.origin.y=this->origin.y-(int64)n;
        ret.size.width=this->size.width-(int64)n;
        ret.size.height=this->size.height-(int64)n;
        return ret;
    }
    void operator-=(recti8 vec){
        //
        this->origin.x-=(int64)vec.origin.x;
        this->origin.y-=(int64)vec.origin.y;
        this->size.width-=(int64)vec.size.width;
        this->size.height-=(int64)vec.size.height;
    }
    void operator-=(recti16 vec){
        //
        this->origin.x-=(int64)vec.origin.x;
        this->origin.y-=(int64)vec.origin.y;
        this->size.width-=(int64)vec.size.width;
        this->size.height-=(int64)vec.size.height;
    }
    void operator-=(recti32 vec){
        //
        this->origin.x-=(int64)vec.origin.x;
        this->origin.y-=(int64)vec.origin.y;
        this->size.width-=(int64)vec.size.width;
        this->size.height-=(int64)vec.size.height;
    }
    void operator-=(recti64 vec){
        //
        this->origin.x-=(int64)vec.origin.x;
        this->origin.y-=(int64)vec.origin.y;
        this->size.width-=(int64)vec.size.width;
        this->size.height-=(int64)vec.size.height;
    }
    void operator-=(int8 n){
        //
        this->origin.x-=(int64)n;
        this->origin.y-=(int64)n;
        this->size.width-=(int64)n;
        this->size.height-=(int64)n;
    }
    void operator-=(int32 n){
        //
        this->origin.x-=(int64)n;
        this->origin.y-=(int64)n;
        this->size.width-=(int64)n;
        this->size.height-=(int64)n;
    }
    void operator-=(int16 n){
        //
        this->origin.x-=(int64)n;
        this->origin.y-=(int64)n;
        this->size.width-=(int64)n;
        this->size.height-=(int64)n;
    }
    void operator-=(int64 n){
        //
        this->origin.x-=(int64)n;
        this->origin.y-=(int64)n;
        this->size.width-=(int64)n;
        this->size.height-=(int64)n;
    }
    void operator-=(uint8 n){
        //
        this->origin.x-=(int64)n;
        this->origin.y-=(int64)n;
        this->size.width-=(int64)n;
        this->size.height-=(int64)n;
    }
    void operator-=(uint32 n){
        //
        this->origin.x-=(int64)n;
        this->origin.y-=(int64)n;
        this->size.width-=(int64)n;
        this->size.height-=(int64)n;
    }
    void operator-=(uint16 n){
        //
        this->origin.x-=(int64)n;
        this->origin.y-=(int64)n;
        this->size.width-=(int64)n;
        this->size.height-=(int64)n;
    }
    void operator-=(uint64 n){
        //
        this->origin.x-=(int64)n;
        this->origin.y-=(int64)n;
        this->size.width-=(int64)n;
        this->size.height-=(int64)n;
    }
    recti64 operator*(recti8 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)rect.origin.x;
        ret.origin.y=this->origin.y*(int64)rect.origin.y;
        ret.size.width=this->size.width*(int64)rect.size.width;
        ret.size.height=this->size.height*(int64)rect.size.height;
        return ret;
    }
    recti64 operator*(recti16 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)rect.origin.x;
        ret.origin.y=this->origin.y*(int64)rect.origin.y;
        ret.size.width=this->size.width*(int64)rect.size.width;
        ret.size.height=this->size.height*(int64)rect.size.height;
        return ret;
    }
    recti64 operator*(recti32 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)rect.origin.x;
        ret.origin.y=this->origin.y*(int64)rect.origin.y;
        ret.size.width=this->size.width*(int64)rect.size.width;
        ret.size.height=this->size.height*(int64)rect.size.height;
        return ret;
    }
    recti64 operator*(recti64 rect){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)rect.origin.x;
        ret.origin.y=this->origin.y*(int64)rect.origin.y;
        ret.size.width=this->size.width*(int64)rect.size.width;
        ret.size.height=this->size.height*(int64)rect.size.height;
        return ret;
    }
    recti64 operator*(int8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)n;
        ret.origin.y=this->origin.y*(int64)n;
        ret.size.width=this->size.width*(int64)n;
        ret.size.height=this->size.height*(int64)n;
        return ret;
    }
    recti64 operator*(int32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)n;
        ret.origin.y=this->origin.y*(int64)n;
        ret.size.width=this->size.width*(int64)n;
        ret.size.height=this->size.height*(int64)n;
        return ret;
    }
    recti64 operator*(int16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)n;
        ret.origin.y=this->origin.y*(int64)n;
        ret.size.width=this->size.width*(int64)n;
        ret.size.height=this->size.height*(int64)n;
        return ret;
    }
    recti64 operator*(int64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)n;
        ret.origin.y=this->origin.y*(int64)n;
        ret.size.width=this->size.width*(int64)n;
        ret.size.height=this->size.height*(int64)n;
        return ret;
    }
    recti64 operator*(uint8 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)n;
        ret.origin.y=this->origin.y*(int64)n;
        ret.size.width=this->size.width*(int64)n;
        ret.size.height=this->size.height*(int64)n;
        return ret;
    }
    recti64 operator*(uint32 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)n;
        ret.origin.y=this->origin.y*(int64)n;
        ret.size.width=this->size.width*(int64)n;
        ret.size.height=this->size.height*(int64)n;
        return ret;
    }
    recti64 operator*(uint16 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)n;
        ret.origin.y=this->origin.y*(int64)n;
        ret.size.width=this->size.width*(int64)n;
        ret.size.height=this->size.height*(int64)n;
        return ret;
    }
    recti64 operator*(uint64 n){
        //
        recti64 ret;
        ret.origin.x=this->origin.x*(int64)n;
        ret.origin.y=this->origin.y*(int64)n;
        ret.size.width=this->size.width*(int64)n;
        ret.size.height=this->size.height*(int64)n;
        return ret;
    }
    void operator*=(recti8 rect){
        //
        this->origin.x*=(int64)rect.origin.x;
        this->origin.y*=(int64)rect.origin.y;
        this->size.width*=(int64)rect.size.width;
        this->size.height*=(int64)rect.size.height;
    }
    void operator*=(recti16 rect){
        //
        this->origin.x*=(int64)rect.origin.x;
        this->origin.y*=(int64)rect.origin.y;
        this->size.width*=(int64)rect.size.width;
        this->size.height*=(int64)rect.size.height;
    }
    void operator*=(recti32 rect){
        //
        this->origin.x*=(int64)rect.origin.x;
        this->origin.y*=(int64)rect.origin.y;
        this->size.width*=(int64)rect.size.width;
        this->size.height*=(int64)rect.size.height;
    }
    void operator*=(recti64 rect){
        //
        this->origin.x*=(int64)rect.origin.x;
        this->origin.y*=(int64)rect.origin.y;
        this->size.width*=(int64)rect.size.width;
        this->size.height*=(int64)rect.size.height;
    }
    void operator*=(int8 n){
        //
        this->origin.x*=(int64)n;
        this->origin.y*=(int64)n;
        this->size.width*=(int64)n;
        this->size.height*=(int64)n;
    }
    void operator*=(int32 n){
        //
        this->origin.x*=(int64)n;
        this->origin.y*=(int64)n;
        this->size.width*=(int64)n;
        this->size.height*=(int64)n;
    }
    void operator*=(int16 n){
        //
        this->origin.x*=(int64)n;
        this->origin.y*=(int64)n;
        this->size.width*=(int64)n;
        this->size.height*=(int64)n;
    }
    void operator*=(int64 n){
        //
        this->origin.x*=(int64)n;
        this->origin.y*=(int64)n;
        this->size.width*=(int64)n;
        this->size.height*=(int64)n;
    }
    void operator*=(uint8 n){
        //
        this->origin.x*=(int64)n;
        this->origin.y*=(int64)n;
        this->size.width*=(int64)n;
        this->size.height*=(int64)n;
    }
    void operator*=(uint32 n){
        //
        this->origin.x*=(int64)n;
        this->origin.y*=(int64)n;
        this->size.width*=(int64)n;
        this->size.height*=(int64)n;
    }
    void operator*=(uint16 n){
        //
        this->origin.x*=(int64)n;
        this->origin.y*=(int64)n;
        this->size.width*=(int64)n;
        this->size.height*=(int64)n;
    }
    void operator*=(uint64 n){
        //
        this->origin.x*=(int64)n;
        this->origin.y*=(int64)n;
        this->size.width*=(int64)n;
        this->size.height*=(int64)n;
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
    recti64 operator++(int32){
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
    recti64 operator--(int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return recti64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    recti64 operator()(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti64((int64)this->origin.x,(int64)this->origin.y,(int64)this->size.width,(int64)this->size.height);
    }
    recti64 operator()(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
        return recti64((int64)this->origin.x,(int64)this->origin.y,(int64)this->size.width,(int64)this->size.height);
    }
    recti64 operator()(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
        return recti64((int64)this->origin.x,(int64)this->origin.y,(int64)this->size.width,(int64)this->size.height);
    }
    recti64 operator()(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
        return recti64((int64)this->origin.x,(int64)this->origin.y,(int64)this->size.width,(int64)this->size.height);
    }
    recti64 operator()(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return recti64((int64)this->origin.x,(int64)this->origin.y,(int64)this->size.width,(int64)this->size.height);
    }
    recti64 operator()(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
        return recti64((int64)this->origin.x,(int64)this->origin.y,(int64)this->size.width,(int64)this->size.height);
    }
    recti64 operator()(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
        return recti64((int64)this->origin.x,(int64)this->origin.y,(int64)this->size.width,(int64)this->size.height);
    }
    recti64 operator()(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(int64)x;
        this->origin.y=(int64)y;
        this->size.width=(int64)width;
        this->size.height=(int64)height;
        return recti64((int64)this->origin.x,(int64)this->origin.y,(int64)this->size.width,(int64)this->size.height);
    }
};

class rectui8{
public:
    //position
    vec2ui8 origin;
    //size
    size2ui8 size;
    //Construtor
    rectui8(){
        //
        this->origin.x=(uint8)0;
        this->origin.y=(uint8)0;
        this->size.width=(uint8)0;
        this->size.height=(uint8)0;
    }
    rectui8(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=(uint8)x;
        this->origin.y=(uint8)y;
        this->size.width=(uint8)width;
        this->size.height=(uint8)height;
    }
    rectui8(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(uint8)x;
        this->origin.y=(uint8)y;
        this->size.width=(uint8)width;
        this->size.height=(uint8)height;
    }
    rectui8(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(uint8)x;
        this->origin.y=(uint8)y;
        this->size.width=(uint8)width;
        this->size.height=(uint8)height;
    }
    rectui8(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(uint8)x;
        this->origin.y=(uint8)y;
        this->size.width=(uint8)width;
        this->size.height=(uint8)height;
    }

    //operators
    rectui8 operator=(rectui8 rect){
        //
        this->origin.x=(uint8)rect.origin.x;
        this->origin.y=(uint8)rect.origin.y;
        this->size.width=(uint8)rect.size.width;
        this->size.height=(uint8)rect.size.height;
        return *this;
    }
    rectui8 operator=(uint8 n){
        //
        this->origin.x=(uint8)n;
        this->origin.y=(uint8)n;
        this->size.width=(uint8)n;
        this->size.height=(uint8)n;
        return *this;
    }
    rectui8 operator=(uint32 n){
        //
        this->origin.x=(uint8)n;
        this->origin.y=(uint8)n;
        this->size.width=(uint8)n;
        this->size.height=(uint8)n;
        return *this;
    }
    rectui8 operator=(uint16 n){
        //
        this->origin.x=(uint8)n;
        this->origin.y=(uint8)n;
        this->size.width=(uint8)n;
        this->size.height=(uint8)n;
        return *this;
    }
    rectui8 operator=(uint64 n){
        //
        this->origin.x=(uint8)n;
        this->origin.y=(uint8)n;
        this->size.width=(uint8)n;
        this->size.height=(uint8)n;
        return *this;
    }

    bool operator==(rectui8 rect){
        //
        return (this->origin.x==(uint8)rect.origin.x
                &&this->origin.y==(uint8)rect.origin.y
                &&this->size.width==(uint8)rect.size.width
                &&this->size.height==(uint8)rect.size.height
                );
    }
    bool operator!=(rectui8 rect){
        //
        return (this->origin.x!=(uint8)rect.origin.x
                ||this->origin.y!=(uint8)rect.origin.y
                ||this->size.width!=(uint8)rect.size.width
                ||this->size.height!=(uint8)rect.size.height
                );
    }
    rectui8 operator+(rectui8 rect){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x+(uint8)rect.origin.x;
        ret.origin.y=this->origin.y+(uint8)rect.origin.y;
        ret.size.width=this->size.width+(uint8)rect.size.width;
        ret.size.height=this->size.height+(uint8)rect.size.height;
        return ret;
    }
    rectui8 operator+(uint8 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x+(uint8)n;
        ret.origin.y=this->origin.y+(uint8)n;
        ret.size.width=this->size.width+(uint8)n;
        ret.size.height=this->size.height+(uint8)n;
        return ret;
    }
    rectui8 operator+(uint32 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x+(uint8)n;
        ret.origin.y=this->origin.y+(uint8)n;
        ret.size.width=this->size.width+(uint8)n;
        ret.size.height=this->size.height+(uint8)n;
        return ret;
    }
    rectui8 operator+(uint16 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x+(uint8)n;
        ret.origin.y=this->origin.y+(uint8)n;
        ret.size.width=this->size.width+(uint8)n;
        ret.size.height=this->size.height+(uint8)n;
        return ret;
    }
    rectui8 operator+(uint64 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x+(uint8)n;
        ret.origin.y=this->origin.y+(uint8)n;
        ret.size.width=this->size.width+(uint8)n;
        ret.size.height=this->size.height+(uint8)n;
        return ret;
    }
    void operator+=(rectui8 rect){
        //
        this->origin.x+=(uint8)rect.origin.x;
        this->origin.y+=(uint8)rect.origin.y;
        this->size.width+=(uint8)rect.size.width;
        this->size.height+=(uint8)rect.size.height;
    }
    void operator+=(uint8 n){
        //
        this->origin.x+=(uint8)n;
        this->origin.y+=(uint8)n;
        this->size.width+=(uint8)n;
        this->size.height+=(uint8)n;
    }
    void operator+=(uint32 n){
        //
        this->origin.x+=(uint8)n;
        this->origin.y+=(uint8)n;
        this->size.width+=(uint8)n;
        this->size.height+=(uint8)n;
    }
    void operator+=(uint16 n){
        //
        this->origin.x+=(uint8)n;
        this->origin.y+=(uint8)n;
        this->size.width+=(uint8)n;
        this->size.height+=(uint8)n;
    }
    void operator+=(uint64 n){
        //
        this->origin.x+=(uint8)n;
        this->origin.y+=(uint8)n;
        this->size.width+=(uint8)n;
        this->size.height+=(uint8)n;
    }
    rectui8 operator-(rectui8 rect){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x-(uint8)rect.origin.x;
        ret.origin.y=this->origin.y-(uint8)rect.origin.y;
        ret.size.width=this->size.width-(uint8)rect.size.width;
        ret.size.height=this->size.height-(uint8)rect.size.height;
        return ret;
    }
    rectui8 operator-(uint8 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x-(uint8)n;
        ret.origin.y=this->origin.y-(uint8)n;
        ret.size.width=this->size.width-(uint8)n;
        ret.size.height=this->size.height-(uint8)n;
        return ret;
    }
    rectui8 operator-(uint32 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x-(uint8)n;
        ret.origin.y=this->origin.y-(uint8)n;
        ret.size.width=this->size.width-(uint8)n;
        ret.size.height=this->size.height-(uint8)n;
        return ret;
    }
    rectui8 operator-(uint16 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x-(uint8)n;
        ret.origin.y=this->origin.y-(uint8)n;
        ret.size.width=this->size.width-(uint8)n;
        ret.size.height=this->size.height-(uint8)n;
        return ret;
    }
    rectui8 operator-(uint64 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x-(uint8)n;
        ret.origin.y=this->origin.y-(uint8)n;
        ret.size.width=this->size.width-(uint8)n;
        ret.size.height=this->size.height-(uint8)n;
        return ret;
    }
    void operator-=(rectui8 vec){
        //
        this->origin.x-=(uint8)vec.origin.x;
        this->origin.y-=(uint8)vec.origin.y;
        this->size.width-=(uint8)vec.size.width;
        this->size.height-=(uint8)vec.size.height;
    }
    void operator-=(uint8 n){
        //
        this->origin.x-=(uint8)n;
        this->origin.y-=(uint8)n;
        this->size.width-=(uint8)n;
        this->size.height-=(uint8)n;
    }
    void operator-=(uint32 n){
        //
        this->origin.x-=(uint8)n;
        this->origin.y-=(uint8)n;
        this->size.width-=(uint8)n;
        this->size.height-=(uint8)n;
    }
    void operator-=(uint16 n){
        //
        this->origin.x-=(uint8)n;
        this->origin.y-=(uint8)n;
        this->size.width-=(uint8)n;
        this->size.height-=(uint8)n;
    }
    void operator-=(uint64 n){
        //
        this->origin.x-=(uint8)n;
        this->origin.y-=(uint8)n;
        this->size.width-=(uint8)n;
        this->size.height-=(uint8)n;
    }
    rectui8 operator*(rectui8 rect){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x*(uint8)rect.origin.x;
        ret.origin.y=this->origin.y*(uint8)rect.origin.y;
        ret.size.width=this->size.width*(uint8)rect.size.width;
        ret.size.height=this->size.height*(uint8)rect.size.height;
        return ret;
    }
    rectui8 operator*(uint8 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x*(uint8)n;
        ret.origin.y=this->origin.y*(uint8)n;
        ret.size.width=this->size.width*(uint8)n;
        ret.size.height=this->size.height*(uint8)n;
        return ret;
    }
    rectui8 operator*(uint32 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x*(uint8)n;
        ret.origin.y=this->origin.y*(uint8)n;
        ret.size.width=this->size.width*(uint8)n;
        ret.size.height=this->size.height*(uint8)n;
        return ret;
    }
    rectui8 operator*(uint16 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x*(uint8)n;
        ret.origin.y=this->origin.y*(uint8)n;
        ret.size.width=this->size.width*(uint8)n;
        ret.size.height=this->size.height*(uint8)n;
        return ret;
    }
    rectui8 operator*(uint64 n){
        //
        rectui8 ret;
        ret.origin.x=this->origin.x*(uint8)n;
        ret.origin.y=this->origin.y*(uint8)n;
        ret.size.width=this->size.width*(uint8)n;
        ret.size.height=this->size.height*(uint8)n;
        return ret;
    }
    void operator*=(rectui8 rect){
        //
        this->origin.x*=(uint8)rect.origin.x;
        this->origin.y*=(uint8)rect.origin.y;
        this->size.width*=(uint8)rect.size.width;
        this->size.height*=(uint8)rect.size.height;
    }
    void operator*=(uint8 n){
        //
        this->origin.x*=(uint8)n;
        this->origin.y*=(uint8)n;
        this->size.width*=(uint8)n;
        this->size.height*=(uint8)n;
    }
    void operator*=(uint32 n){
        //
        this->origin.x*=(uint8)n;
        this->origin.y*=(uint8)n;
        this->size.width*=(uint8)n;
        this->size.height*=(uint8)n;
    }
    void operator*=(uint16 n){
        //
        this->origin.x*=(uint8)n;
        this->origin.y*=(uint8)n;
        this->size.width*=(uint8)n;
        this->size.height*=(uint8)n;
    }
    void operator*=(uint64 n){
        //
        this->origin.x*=(uint8)n;
        this->origin.y*=(uint8)n;
        this->size.width*=(uint8)n;
        this->size.height*=(uint8)n;
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
    rectui8 operator++(int32){
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
    rectui8 operator--(int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return rectui8(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui8 operator()(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectui8((uint8)this->origin.x,(uint8)this->origin.y,(uint8)this->size.width,(uint8)this->size.height);
    }
    rectui8 operator()(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(uint8)x;
        this->origin.y=(uint8)y;
        this->size.width=(uint8)width;
        this->size.height=(uint8)height;
        return rectui8((uint8)this->origin.x,(uint8)this->origin.y,(uint8)this->size.width,(uint8)this->size.height);
    }
    rectui8 operator()(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(uint8)x;
        this->origin.y=(uint8)y;
        this->size.width=(uint8)width;
        this->size.height=(uint8)height;
        return rectui8((uint8)this->origin.x,(uint8)this->origin.y,(uint8)this->size.width,(uint8)this->size.height);
    }
    rectui8 operator()(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(uint8)x;
        this->origin.y=(uint8)y;
        this->size.width=(uint8)width;
        this->size.height=(uint8)height;
        return rectui8((uint8)this->origin.x,(uint8)this->origin.y,(uint8)this->size.width,(uint8)this->size.height);
    }
};

class rectui16{
public:
    //position
    vec2ui16 origin;
    //size
    size2ui16 size;
    //Construtor
    rectui16(){
        //
        this->origin.x=(uint16)0;
        this->origin.y=(uint16)0;
        this->size.width=(uint16)0;
        this->size.height=(uint16)0;
    }
    rectui16(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=(uint16)x;
        this->origin.y=(uint16)y;
        this->size.width=(uint16)width;
        this->size.height=(uint16)height;
    }
    rectui16(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(uint16)x;
        this->origin.y=(uint16)y;
        this->size.width=(uint16)width;
        this->size.height=(uint16)height;
    }
    rectui16(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(uint16)x;
        this->origin.y=(uint16)y;
        this->size.width=(uint16)width;
        this->size.height=(uint16)height;
    }
    rectui16(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(uint16)x;
        this->origin.y=(uint16)y;
        this->size.width=(uint16)width;
        this->size.height=(uint16)height;
    }

    //operators
    rectui16 operator=(rectui8 rect){
        //
        this->origin.x=(uint16)rect.origin.x;
        this->origin.y=(uint16)rect.origin.y;
        this->size.width=(uint16)rect.size.width;
        this->size.height=(uint16)rect.size.height;
        return *this;
    }
    rectui16 operator=(rectui16 rect){
        //
        this->origin.x=(uint16)rect.origin.x;
        this->origin.y=(uint16)rect.origin.y;
        this->size.width=(uint16)rect.size.width;
        this->size.height=(uint16)rect.size.height;
        return *this;
    }
    rectui16 operator=(uint8 n){
        //
        this->origin.x=(uint16)n;
        this->origin.y=(uint16)n;
        this->size.width=(uint16)n;
        this->size.height=(uint16)n;
        return *this;
    }
    rectui16 operator=(uint32 n){
        //
        this->origin.x=(uint16)n;
        this->origin.y=(uint16)n;
        this->size.width=(uint16)n;
        this->size.height=(uint16)n;
        return *this;
    }
    rectui16 operator=(uint16 n){
        //
        this->origin.x=(uint16)n;
        this->origin.y=(uint16)n;
        this->size.width=(uint16)n;
        this->size.height=(uint16)n;
        return *this;
    }
    rectui16 operator=(uint64 n){
        //
        this->origin.x=(uint16)n;
        this->origin.y=(uint16)n;
        this->size.width=(uint16)n;
        this->size.height=(uint16)n;
        return *this;
    }

    bool operator==(rectui8 rect){
        //
        return (this->origin.x==(uint16)rect.origin.x
                &&this->origin.y==(uint16)rect.origin.y
                &&this->size.width==(uint16)rect.size.width
                &&this->size.height==(uint16)rect.size.height
                );
    }
    bool operator==(rectui16 rect){
        //
        return (this->origin.x==(uint16)rect.origin.x
                &&this->origin.y==(uint16)rect.origin.y
                &&this->size.width==(uint16)rect.size.width
                &&this->size.height==(uint16)rect.size.height
                );
    }
    bool operator!=(rectui8 rect){
        //
        return (this->origin.x!=(uint16)rect.origin.x
                ||this->origin.y!=(uint16)rect.origin.y
                ||this->size.width!=(uint16)rect.size.width
                ||this->size.height!=(uint16)rect.size.height
                );
    }
    bool operator!=(rectui16 rect){
        //
        return (this->origin.x!=(uint16)rect.origin.x
                ||this->origin.y!=(uint16)rect.origin.y
                ||this->size.width!=(uint16)rect.size.width
                ||this->size.height!=(uint16)rect.size.height
                );
    }
    rectui16 operator+(rectui8 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(uint16)rect.origin.x;
        ret.origin.y=this->origin.y+(uint16)rect.origin.y;
        ret.size.width=this->size.width+(uint16)rect.size.width;
        ret.size.height=this->size.height+(uint16)rect.size.height;
        return ret;
    }
    rectui16 operator+(rectui16 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(uint16)rect.origin.x;
        ret.origin.y=this->origin.y+(uint16)rect.origin.y;
        ret.size.width=this->size.width+(uint16)rect.size.width;
        ret.size.height=this->size.height+(uint16)rect.size.height;
        return ret;
    }
    rectui16 operator+(uint8 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(uint16)n;
        ret.origin.y=this->origin.y+(uint16)n;
        ret.size.width=this->size.width+(uint16)n;
        ret.size.height=this->size.height+(uint16)n;
        return ret;
    }
    rectui16 operator+(uint32 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(uint16)n;
        ret.origin.y=this->origin.y+(uint16)n;
        ret.size.width=this->size.width+(uint16)n;
        ret.size.height=this->size.height+(uint16)n;
        return ret;
    }
    rectui16 operator+(uint16 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(uint16)n;
        ret.origin.y=this->origin.y+(uint16)n;
        ret.size.width=this->size.width+(uint16)n;
        ret.size.height=this->size.height+(uint16)n;
        return ret;
    }
    rectui16 operator+(uint64 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x+(uint16)n;
        ret.origin.y=this->origin.y+(uint16)n;
        ret.size.width=this->size.width+(uint16)n;
        ret.size.height=this->size.height+(uint16)n;
        return ret;
    }
    void operator+=(rectui8 rect){
        //
        this->origin.x+=(uint16)rect.origin.x;
        this->origin.y+=(uint16)rect.origin.y;
        this->size.width+=(uint16)rect.size.width;
        this->size.height+=(uint16)rect.size.height;
    }
    void operator+=(rectui16 rect){
        //
        this->origin.x+=(uint16)rect.origin.x;
        this->origin.y+=(uint16)rect.origin.y;
        this->size.width+=(uint16)rect.size.width;
        this->size.height+=(uint16)rect.size.height;
    }
    void operator+=(uint8 n){
        //
        this->origin.x+=(uint16)n;
        this->origin.y+=(uint16)n;
        this->size.width+=(uint16)n;
        this->size.height+=(uint16)n;
    }
    void operator+=(uint32 n){
        //
        this->origin.x+=(uint16)n;
        this->origin.y+=(uint16)n;
        this->size.width+=(uint16)n;
        this->size.height+=(uint16)n;
    }
    void operator+=(uint16 n){
        //
        this->origin.x+=(uint16)n;
        this->origin.y+=(uint16)n;
        this->size.width+=(uint16)n;
        this->size.height+=(uint16)n;
    }
    void operator+=(uint64 n){
        //
        this->origin.x+=(uint16)n;
        this->origin.y+=(uint16)n;
        this->size.width+=(uint16)n;
        this->size.height+=(uint16)n;
    }
    rectui16 operator-(rectui8 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(uint16)rect.origin.x;
        ret.origin.y=this->origin.y-(uint16)rect.origin.y;
        ret.size.width=this->size.width-(uint16)rect.size.width;
        ret.size.height=this->size.height-(uint16)rect.size.height;
        return ret;
    }
    rectui16 operator-(rectui16 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(uint16)rect.origin.x;
        ret.origin.y=this->origin.y-(uint16)rect.origin.y;
        ret.size.width=this->size.width-(uint16)rect.size.width;
        ret.size.height=this->size.height-(uint16)rect.size.height;
        return ret;
    }
    rectui16 operator-(uint8 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(uint16)n;
        ret.origin.y=this->origin.y-(uint16)n;
        ret.size.width=this->size.width-(uint16)n;
        ret.size.height=this->size.height-(uint16)n;
        return ret;
    }
    rectui16 operator-(uint32 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(uint16)n;
        ret.origin.y=this->origin.y-(uint16)n;
        ret.size.width=this->size.width-(uint16)n;
        ret.size.height=this->size.height-(uint16)n;
        return ret;
    }
    rectui16 operator-(uint16 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(uint16)n;
        ret.origin.y=this->origin.y-(uint16)n;
        ret.size.width=this->size.width-(uint16)n;
        ret.size.height=this->size.height-(uint16)n;
        return ret;
    }
    rectui16 operator-(uint64 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x-(uint16)n;
        ret.origin.y=this->origin.y-(uint16)n;
        ret.size.width=this->size.width-(uint16)n;
        ret.size.height=this->size.height-(uint16)n;
        return ret;
    }
    void operator-=(rectui8 vec){
        //
        this->origin.x-=(uint16)vec.origin.x;
        this->origin.y-=(uint16)vec.origin.y;
        this->size.width-=(uint16)vec.size.width;
        this->size.height-=(uint16)vec.size.height;
    }
    void operator-=(rectui16 vec){
        //
        this->origin.x-=(uint16)vec.origin.x;
        this->origin.y-=(uint16)vec.origin.y;
        this->size.width-=(uint16)vec.size.width;
        this->size.height-=(uint16)vec.size.height;
    }
    void operator-=(uint8 n){
        //
        this->origin.x-=(uint16)n;
        this->origin.y-=(uint16)n;
        this->size.width-=(uint16)n;
        this->size.height-=(uint16)n;
    }
    void operator-=(uint32 n){
        //
        this->origin.x-=(uint16)n;
        this->origin.y-=(uint16)n;
        this->size.width-=(uint16)n;
        this->size.height-=(uint16)n;
    }
    void operator-=(uint16 n){
        //
        this->origin.x-=(uint16)n;
        this->origin.y-=(uint16)n;
        this->size.width-=(uint16)n;
        this->size.height-=(uint16)n;
    }
    void operator-=(uint64 n){
        //
        this->origin.x-=(uint16)n;
        this->origin.y-=(uint16)n;
        this->size.width-=(uint16)n;
        this->size.height-=(uint16)n;
    }
    rectui16 operator*(rectui8 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(uint16)rect.origin.x;
        ret.origin.y=this->origin.y*(uint16)rect.origin.y;
        ret.size.width=this->size.width*(uint16)rect.size.width;
        ret.size.height=this->size.height*(uint16)rect.size.height;
        return ret;
    }
    rectui16 operator*(rectui16 rect){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(uint16)rect.origin.x;
        ret.origin.y=this->origin.y*(uint16)rect.origin.y;
        ret.size.width=this->size.width*(uint16)rect.size.width;
        ret.size.height=this->size.height*(uint16)rect.size.height;
        return ret;
    }
    rectui16 operator*(uint8 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(uint16)n;
        ret.origin.y=this->origin.y*(uint16)n;
        ret.size.width=this->size.width*(uint16)n;
        ret.size.height=this->size.height*(uint16)n;
        return ret;
    }
    rectui16 operator*(uint32 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(uint16)n;
        ret.origin.y=this->origin.y*(uint16)n;
        ret.size.width=this->size.width*(uint16)n;
        ret.size.height=this->size.height*(uint16)n;
        return ret;
    }
    rectui16 operator*(uint16 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(uint16)n;
        ret.origin.y=this->origin.y*(uint16)n;
        ret.size.width=this->size.width*(uint16)n;
        ret.size.height=this->size.height*(uint16)n;
        return ret;
    }
    rectui16 operator*(uint64 n){
        //
        rectui16 ret;
        ret.origin.x=this->origin.x*(uint16)n;
        ret.origin.y=this->origin.y*(uint16)n;
        ret.size.width=this->size.width*(uint16)n;
        ret.size.height=this->size.height*(uint16)n;
        return ret;
    }
    void operator*=(rectui8 rect){
        //
        this->origin.x*=(uint16)rect.origin.x;
        this->origin.y*=(uint16)rect.origin.y;
        this->size.width*=(uint16)rect.size.width;
        this->size.height*=(uint16)rect.size.height;
    }
    void operator*=(rectui16 rect){
        //
        this->origin.x*=(uint16)rect.origin.x;
        this->origin.y*=(uint16)rect.origin.y;
        this->size.width*=(uint16)rect.size.width;
        this->size.height*=(uint16)rect.size.height;
    }
    void operator*=(uint8 n){
        //
        this->origin.x*=(uint16)n;
        this->origin.y*=(uint16)n;
        this->size.width*=(uint16)n;
        this->size.height*=(uint16)n;
    }
    void operator*=(uint32 n){
        //
        this->origin.x*=(uint16)n;
        this->origin.y*=(uint16)n;
        this->size.width*=(uint16)n;
        this->size.height*=(uint16)n;
    }
    void operator*=(uint16 n){
        //
        this->origin.x*=(uint16)n;
        this->origin.y*=(uint16)n;
        this->size.width*=(uint16)n;
        this->size.height*=(uint16)n;
    }
    void operator*=(uint64 n){
        //
        this->origin.x*=(uint16)n;
        this->origin.y*=(uint16)n;
        this->size.width*=(uint16)n;
        this->size.height*=(uint16)n;
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
    rectui16 operator++(int32){
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
    rectui16 operator--(int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return rectui16(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui16 operator()(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectui16((uint16)this->origin.x,(uint16)this->origin.y,(uint16)this->size.width,(uint16)this->size.height);
    }
    rectui16 operator()(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(uint16)x;
        this->origin.y=(uint16)y;
        this->size.width=(uint16)width;
        this->size.height=(uint16)height;
        return rectui16((uint16)this->origin.x,(uint16)this->origin.y,(uint16)this->size.width,(uint16)this->size.height);
    }
    rectui16 operator()(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(uint16)x;
        this->origin.y=(uint16)y;
        this->size.width=(uint16)width;
        this->size.height=(uint16)height;
        return rectui16((uint16)this->origin.x,(uint16)this->origin.y,(uint16)this->size.width,(uint16)this->size.height);
    }
    rectui16 operator()(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(uint16)x;
        this->origin.y=(uint16)y;
        this->size.width=(uint16)width;
        this->size.height=(uint16)height;
        return rectui16((uint16)this->origin.x,(uint16)this->origin.y,(uint16)this->size.width,(uint16)this->size.height);
    }
};

class rectui32{
public:
    //position
    vec2ui32 origin;
    //size
    size2ui32 size;
    //Construtor
    rectui32(){
        //
        this->origin.x=(uint32)0;
        this->origin.y=(uint32)0;
        this->size.width=(uint32)0;
        this->size.height=(uint32)0;
    }
    rectui32(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=(uint32)x;
        this->origin.y=(uint32)y;
        this->size.width=(uint32)width;
        this->size.height=(uint32)height;
    }
    rectui32(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(uint32)x;
        this->origin.y=(uint32)y;
        this->size.width=(uint32)width;
        this->size.height=(uint32)height;
    }
    rectui32(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(uint32)x;
        this->origin.y=(uint32)y;
        this->size.width=(uint32)width;
        this->size.height=(uint32)height;
    }
    rectui32(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(uint32)x;
        this->origin.y=(uint32)y;
        this->size.width=(uint32)width;
        this->size.height=(uint32)height;
    }

    //operators
    rectui32 operator=(rectui8 rect){
        //
        this->origin.x=(uint32)rect.origin.x;
        this->origin.y=(uint32)rect.origin.y;
        this->size.width=(uint32)rect.size.width;
        this->size.height=(uint32)rect.size.height;
        return *this;
    }
    rectui32 operator=(rectui16 rect){
        //
        this->origin.x=(uint32)rect.origin.x;
        this->origin.y=(uint32)rect.origin.y;
        this->size.width=(uint32)rect.size.width;
        this->size.height=(uint32)rect.size.height;
        return *this;
    }
    rectui32 operator=(rectui32 rect){
        //
        this->origin.x=(uint32)rect.origin.x;
        this->origin.y=(uint32)rect.origin.y;
        this->size.width=(uint32)rect.size.width;
        this->size.height=(uint32)rect.size.height;
        return *this;
    }
    rectui32 operator=(uint8 n){
        //
        this->origin.x=(uint32)n;
        this->origin.y=(uint32)n;
        this->size.width=(uint32)n;
        this->size.height=(uint32)n;
        return *this;
    }
    rectui32 operator=(uint32 n){
        //
        this->origin.x=(uint32)n;
        this->origin.y=(uint32)n;
        this->size.width=(uint32)n;
        this->size.height=(uint32)n;
        return *this;
    }
    rectui32 operator=(uint16 n){
        //
        this->origin.x=(uint32)n;
        this->origin.y=(uint32)n;
        this->size.width=(uint32)n;
        this->size.height=(uint32)n;
        return *this;
    }
    rectui32 operator=(uint64 n){
        //
        this->origin.x=(uint32)n;
        this->origin.y=(uint32)n;
        this->size.width=(uint32)n;
        this->size.height=(uint32)n;
        return *this;
    }

    bool operator==(rectui8 rect){
        //
        return (this->origin.x==(uint32)rect.origin.x
                &&this->origin.y==(uint32)rect.origin.y
                &&this->size.width==(uint32)rect.size.width
                &&this->size.height==(uint32)rect.size.height
                );
    }
    bool operator==(rectui16 rect){
        //
        return (this->origin.x==(uint32)rect.origin.x
                &&this->origin.y==(uint32)rect.origin.y
                &&this->size.width==(uint32)rect.size.width
                &&this->size.height==(uint32)rect.size.height
                );
    }
    bool operator==(rectui32 rect){
        //
        return (this->origin.x==(uint32)rect.origin.x
                &&this->origin.y==(uint32)rect.origin.y
                &&this->size.width==(uint32)rect.size.width
                &&this->size.height==(uint32)rect.size.height
                );
    }
    bool operator!=(rectui8 rect){
        //
        return (this->origin.x!=(uint32)rect.origin.x
                ||this->origin.y!=(uint32)rect.origin.y
                ||this->size.width!=(uint32)rect.size.width
                ||this->size.height!=(uint32)rect.size.height
                );
    }
    bool operator!=(rectui16 rect){
        //
        return (this->origin.x!=(uint32)rect.origin.x
                ||this->origin.y!=(uint32)rect.origin.y
                ||this->size.width!=(uint32)rect.size.width
                ||this->size.height!=(uint32)rect.size.height
                );
    }
    bool operator!=(rectui32 rect){
        //
        return (this->origin.x!=(uint32)rect.origin.x
                ||this->origin.y!=(uint32)rect.origin.y
                ||this->size.width!=(uint32)rect.size.width
                ||this->size.height!=(uint32)rect.size.height
                );
    }
    rectui32 operator+(rectui8 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(uint32)rect.origin.x;
        ret.origin.y=this->origin.y+(uint32)rect.origin.y;
        ret.size.width=this->size.width+(uint32)rect.size.width;
        ret.size.height=this->size.height+(uint32)rect.size.height;
        return ret;
    }
    rectui32 operator+(rectui16 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(uint32)rect.origin.x;
        ret.origin.y=this->origin.y+(uint32)rect.origin.y;
        ret.size.width=this->size.width+(uint32)rect.size.width;
        ret.size.height=this->size.height+(uint32)rect.size.height;
        return ret;
    }
    rectui32 operator+(rectui32 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(uint32)rect.origin.x;
        ret.origin.y=this->origin.y+(uint32)rect.origin.y;
        ret.size.width=this->size.width+(uint32)rect.size.width;
        ret.size.height=this->size.height+(uint32)rect.size.height;
        return ret;
    }
    rectui32 operator+(uint8 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(uint32)n;
        ret.origin.y=this->origin.y+(uint32)n;
        ret.size.width=this->size.width+(uint32)n;
        ret.size.height=this->size.height+(uint32)n;
        return ret;
    }
    rectui32 operator+(uint32 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(uint32)n;
        ret.origin.y=this->origin.y+(uint32)n;
        ret.size.width=this->size.width+(uint32)n;
        ret.size.height=this->size.height+(uint32)n;
        return ret;
    }
    rectui32 operator+(uint16 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(uint32)n;
        ret.origin.y=this->origin.y+(uint32)n;
        ret.size.width=this->size.width+(uint32)n;
        ret.size.height=this->size.height+(uint32)n;
        return ret;
    }
    rectui32 operator+(uint64 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x+(uint32)n;
        ret.origin.y=this->origin.y+(uint32)n;
        ret.size.width=this->size.width+(uint32)n;
        ret.size.height=this->size.height+(uint32)n;
        return ret;
    }
    void operator+=(rectui8 rect){
        //
        this->origin.x+=(uint32)rect.origin.x;
        this->origin.y+=(uint32)rect.origin.y;
        this->size.width+=(uint32)rect.size.width;
        this->size.height+=(uint32)rect.size.height;
    }
    void operator+=(rectui16 rect){
        //
        this->origin.x+=(uint32)rect.origin.x;
        this->origin.y+=(uint32)rect.origin.y;
        this->size.width+=(uint32)rect.size.width;
        this->size.height+=(uint32)rect.size.height;
    }
    void operator+=(rectui32 rect){
        //
        this->origin.x+=(uint32)rect.origin.x;
        this->origin.y+=(uint32)rect.origin.y;
        this->size.width+=(uint32)rect.size.width;
        this->size.height+=(uint32)rect.size.height;
    }
    void operator+=(uint8 n){
        //
        this->origin.x+=(uint32)n;
        this->origin.y+=(uint32)n;
        this->size.width+=(uint32)n;
        this->size.height+=(uint32)n;
    }
    void operator+=(uint32 n){
        //
        this->origin.x+=(uint32)n;
        this->origin.y+=(uint32)n;
        this->size.width+=(uint32)n;
        this->size.height+=(uint32)n;
    }
    void operator+=(uint16 n){
        //
        this->origin.x+=(uint32)n;
        this->origin.y+=(uint32)n;
        this->size.width+=(uint32)n;
        this->size.height+=(uint32)n;
    }
    void operator+=(uint64 n){
        //
        this->origin.x+=(uint32)n;
        this->origin.y+=(uint32)n;
        this->size.width+=(uint32)n;
        this->size.height+=(uint32)n;
    }
    rectui32 operator-(rectui8 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(uint32)rect.origin.x;
        ret.origin.y=this->origin.y-(uint32)rect.origin.y;
        ret.size.width=this->size.width-(uint32)rect.size.width;
        ret.size.height=this->size.height-(uint32)rect.size.height;
        return ret;
    }
    rectui32 operator-(rectui16 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(uint32)rect.origin.x;
        ret.origin.y=this->origin.y-(uint32)rect.origin.y;
        ret.size.width=this->size.width-(uint32)rect.size.width;
        ret.size.height=this->size.height-(uint32)rect.size.height;
        return ret;
    }
    rectui32 operator-(rectui32 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(uint32)rect.origin.x;
        ret.origin.y=this->origin.y-(uint32)rect.origin.y;
        ret.size.width=this->size.width-(uint32)rect.size.width;
        ret.size.height=this->size.height-(uint32)rect.size.height;
        return ret;
    }
    rectui32 operator-(uint8 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(uint32)n;
        ret.origin.y=this->origin.y-(uint32)n;
        ret.size.width=this->size.width-(uint32)n;
        ret.size.height=this->size.height-(uint32)n;
        return ret;
    }
    rectui32 operator-(uint32 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(uint32)n;
        ret.origin.y=this->origin.y-(uint32)n;
        ret.size.width=this->size.width-(uint32)n;
        ret.size.height=this->size.height-(uint32)n;
        return ret;
    }
    rectui32 operator-(uint16 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(uint32)n;
        ret.origin.y=this->origin.y-(uint32)n;
        ret.size.width=this->size.width-(uint32)n;
        ret.size.height=this->size.height-(uint32)n;
        return ret;
    }
    rectui32 operator-(uint64 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x-(uint32)n;
        ret.origin.y=this->origin.y-(uint32)n;
        ret.size.width=this->size.width-(uint32)n;
        ret.size.height=this->size.height-(uint32)n;
        return ret;
    }
    void operator-=(rectui8 vec){
        //
        this->origin.x-=(uint32)vec.origin.x;
        this->origin.y-=(uint32)vec.origin.y;
        this->size.width-=(uint32)vec.size.width;
        this->size.height-=(uint32)vec.size.height;
    }
    void operator-=(rectui16 vec){
        //
        this->origin.x-=(uint32)vec.origin.x;
        this->origin.y-=(uint32)vec.origin.y;
        this->size.width-=(uint32)vec.size.width;
        this->size.height-=(uint32)vec.size.height;
    }
    void operator-=(rectui32 vec){
        //
        this->origin.x-=(uint32)vec.origin.x;
        this->origin.y-=(uint32)vec.origin.y;
        this->size.width-=(uint32)vec.size.width;
        this->size.height-=(uint32)vec.size.height;
    }
    void operator-=(uint8 n){
        //
        this->origin.x-=(uint32)n;
        this->origin.y-=(uint32)n;
        this->size.width-=(uint32)n;
        this->size.height-=(uint32)n;
    }
    void operator-=(uint32 n){
        //
        this->origin.x-=(uint32)n;
        this->origin.y-=(uint32)n;
        this->size.width-=(uint32)n;
        this->size.height-=(uint32)n;
    }
    void operator-=(uint16 n){
        //
        this->origin.x-=(uint32)n;
        this->origin.y-=(uint32)n;
        this->size.width-=(uint32)n;
        this->size.height-=(uint32)n;
    }
    void operator-=(uint64 n){
        //
        this->origin.x-=(uint32)n;
        this->origin.y-=(uint32)n;
        this->size.width-=(uint32)n;
        this->size.height-=(uint32)n;
    }
    rectui32 operator*(rectui8 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(uint32)rect.origin.x;
        ret.origin.y=this->origin.y*(uint32)rect.origin.y;
        ret.size.width=this->size.width*(uint32)rect.size.width;
        ret.size.height=this->size.height*(uint32)rect.size.height;
        return ret;
    }
    rectui32 operator*(rectui16 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(uint32)rect.origin.x;
        ret.origin.y=this->origin.y*(uint32)rect.origin.y;
        ret.size.width=this->size.width*(uint32)rect.size.width;
        ret.size.height=this->size.height*(uint32)rect.size.height;
        return ret;
    }
    rectui32 operator*(rectui32 rect){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(uint32)rect.origin.x;
        ret.origin.y=this->origin.y*(uint32)rect.origin.y;
        ret.size.width=this->size.width*(uint32)rect.size.width;
        ret.size.height=this->size.height*(uint32)rect.size.height;
        return ret;
    }
    rectui32 operator*(uint8 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(uint32)n;
        ret.origin.y=this->origin.y*(uint32)n;
        ret.size.width=this->size.width*(uint32)n;
        ret.size.height=this->size.height*(uint32)n;
        return ret;
    }
    rectui32 operator*(uint32 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(uint32)n;
        ret.origin.y=this->origin.y*(uint32)n;
        ret.size.width=this->size.width*(uint32)n;
        ret.size.height=this->size.height*(uint32)n;
        return ret;
    }
    rectui32 operator*(uint16 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(uint32)n;
        ret.origin.y=this->origin.y*(uint32)n;
        ret.size.width=this->size.width*(uint32)n;
        ret.size.height=this->size.height*(uint32)n;
        return ret;
    }
    rectui32 operator*(uint64 n){
        //
        rectui32 ret;
        ret.origin.x=this->origin.x*(uint32)n;
        ret.origin.y=this->origin.y*(uint32)n;
        ret.size.width=this->size.width*(uint32)n;
        ret.size.height=this->size.height*(uint32)n;
        return ret;
    }
    void operator*=(rectui8 rect){
        //
        this->origin.x*=(uint32)rect.origin.x;
        this->origin.y*=(uint32)rect.origin.y;
        this->size.width*=(uint32)rect.size.width;
        this->size.height*=(uint32)rect.size.height;
    }
    void operator*=(rectui16 rect){
        //
        this->origin.x*=(uint32)rect.origin.x;
        this->origin.y*=(uint32)rect.origin.y;
        this->size.width*=(uint32)rect.size.width;
        this->size.height*=(uint32)rect.size.height;
    }
    void operator*=(rectui32 rect){
        //
        this->origin.x*=(uint32)rect.origin.x;
        this->origin.y*=(uint32)rect.origin.y;
        this->size.width*=(uint32)rect.size.width;
        this->size.height*=(uint32)rect.size.height;
    }
    void operator*=(uint8 n){
        //
        this->origin.x*=(uint32)n;
        this->origin.y*=(uint32)n;
        this->size.width*=(uint32)n;
        this->size.height*=(uint32)n;
    }
    void operator*=(uint32 n){
        //
        this->origin.x*=(uint32)n;
        this->origin.y*=(uint32)n;
        this->size.width*=(uint32)n;
        this->size.height*=(uint32)n;
    }
    void operator*=(uint16 n){
        //
        this->origin.x*=(uint32)n;
        this->origin.y*=(uint32)n;
        this->size.width*=(uint32)n;
        this->size.height*=(uint32)n;
    }
    void operator*=(uint64 n){
        //
        this->origin.x*=(uint32)n;
        this->origin.y*=(uint32)n;
        this->size.width*=(uint32)n;
        this->size.height*=(uint32)n;
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
    rectui32 operator++(int32){
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
    rectui32 operator--(int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return rectui32(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui32 operator()(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectui32((uint32)this->origin.x,(uint32)this->origin.y,(uint32)this->size.width,(uint32)this->size.height);
    }
    rectui32 operator()(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(uint32)x;
        this->origin.y=(uint32)y;
        this->size.width=(uint32)width;
        this->size.height=(uint32)height;
        return rectui32((uint32)this->origin.x,(uint32)this->origin.y,(uint32)this->size.width,(uint32)this->size.height);
    }
    rectui32 operator()(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(uint32)x;
        this->origin.y=(uint32)y;
        this->size.width=(uint32)width;
        this->size.height=(uint32)height;
        return rectui32((uint32)this->origin.x,(uint32)this->origin.y,(uint32)this->size.width,(uint32)this->size.height);
    }
    rectui32 operator()(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(uint32)x;
        this->origin.y=(uint32)y;
        this->size.width=(uint32)width;
        this->size.height=(uint32)height;
        return rectui32((uint32)this->origin.x,(uint32)this->origin.y,(uint32)this->size.width,(uint32)this->size.height);
    }
};

class rectui64{
public:
    //position
    vec2ui64 origin;
    //size
    size2ui64 size;
    //Construtor
    rectui64(){
        //
        this->origin.x=(uint64)0;
        this->origin.y=(uint64)0;
        this->size.width=(uint64)0;
        this->size.height=(uint64)0;
    }
    rectui64(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=(uint64)x;
        this->origin.y=(uint64)y;
        this->size.width=(uint64)width;
        this->size.height=(uint64)height;
    }
    rectui64(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(uint64)x;
        this->origin.y=(uint64)y;
        this->size.width=(uint64)width;
        this->size.height=(uint64)height;
    }
    rectui64(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(uint64)x;
        this->origin.y=(uint64)y;
        this->size.width=(uint64)width;
        this->size.height=(uint64)height;
    }
    rectui64(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(uint64)x;
        this->origin.y=(uint64)y;
        this->size.width=(uint64)width;
        this->size.height=(uint64)height;
    }

    //operators
    rectui64 operator=(rectui8 rect){
        //
        this->origin.x=(uint64)rect.origin.x;
        this->origin.y=(uint64)rect.origin.y;
        this->size.width=(uint64)rect.size.width;
        this->size.height=(uint64)rect.size.height;
        return *this;
    }
    rectui64 operator=(rectui16 rect){
        //
        this->origin.x=(uint64)rect.origin.x;
        this->origin.y=(uint64)rect.origin.y;
        this->size.width=(uint64)rect.size.width;
        this->size.height=(uint64)rect.size.height;
        return *this;
    }
    rectui64 operator=(rectui32 rect){
        //
        this->origin.x=(uint64)rect.origin.x;
        this->origin.y=(uint64)rect.origin.y;
        this->size.width=(uint64)rect.size.width;
        this->size.height=(uint64)rect.size.height;
        return *this;
    }
    rectui64 operator=(rectui64 rect){
        //
        this->origin.x=(uint64)rect.origin.x;
        this->origin.y=(uint64)rect.origin.y;
        this->size.width=(uint64)rect.size.width;
        this->size.height=(uint64)rect.size.height;
        return *this;
    }
    rectui64 operator=(uint8 n){
        //
        this->origin.x=(uint64)n;
        this->origin.y=(uint64)n;
        this->size.width=(uint64)n;
        this->size.height=(uint64)n;
        return *this;
    }
    rectui64 operator=(uint32 n){
        //
        this->origin.x=(uint64)n;
        this->origin.y=(uint64)n;
        this->size.width=(uint64)n;
        this->size.height=(uint64)n;
        return *this;
    }
    rectui64 operator=(uint16 n){
        //
        this->origin.x=(uint64)n;
        this->origin.y=(uint64)n;
        this->size.width=(uint64)n;
        this->size.height=(uint64)n;
        return *this;
    }
    rectui64 operator=(uint64 n){
        //
        this->origin.x=(uint64)n;
        this->origin.y=(uint64)n;
        this->size.width=(uint64)n;
        this->size.height=(uint64)n;
        return *this;
    }

    bool operator==(rectui8 rect){
        //
        return (this->origin.x==(uint64)rect.origin.x
                &&this->origin.y==(uint64)rect.origin.y
                &&this->size.width==(uint64)rect.size.width
                &&this->size.height==(uint64)rect.size.height
                );
    }
    bool operator==(rectui16 rect){
        //
        return (this->origin.x==(uint64)rect.origin.x
                &&this->origin.y==(uint64)rect.origin.y
                &&this->size.width==(uint64)rect.size.width
                &&this->size.height==(uint64)rect.size.height
                );
    }
    bool operator==(rectui32 rect){
        //
        return (this->origin.x==(uint64)rect.origin.x
                &&this->origin.y==(uint64)rect.origin.y
                &&this->size.width==(uint64)rect.size.width
                &&this->size.height==(uint64)rect.size.height
                );
    }
    bool operator==(rectui64 rect){
        //
        return (this->origin.x==(uint64)rect.origin.x
                &&this->origin.y==(uint64)rect.origin.y
                &&this->size.width==(uint64)rect.size.width
                &&this->size.height==(uint64)rect.size.height
                );
    }
    bool operator!=(rectui8 rect){
        //
        return (this->origin.x!=(uint64)rect.origin.x
                ||this->origin.y!=(uint64)rect.origin.y
                ||this->size.width!=(uint64)rect.size.width
                ||this->size.height!=(uint64)rect.size.height
                );
    }
    bool operator!=(rectui16 rect){
        //
        return (this->origin.x!=(uint64)rect.origin.x
                ||this->origin.y!=(uint64)rect.origin.y
                ||this->size.width!=(uint64)rect.size.width
                ||this->size.height!=(uint64)rect.size.height
                );
    }
    bool operator!=(rectui32 rect){
        //
        return (this->origin.x!=(uint64)rect.origin.x
                ||this->origin.y!=(uint64)rect.origin.y
                ||this->size.width!=(uint64)rect.size.width
                ||this->size.height!=(uint64)rect.size.height
                );
    }
    bool operator!=(rectui64 rect){
        //
        return (this->origin.x!=(uint64)rect.origin.x
                ||this->origin.y!=(uint64)rect.origin.y
                ||this->size.width!=(uint64)rect.size.width
                ||this->size.height!=(uint64)rect.size.height
                );
    }
    rectui64 operator+(rectui8 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(uint64)rect.origin.y;
        ret.size.width=this->size.width+(uint64)rect.size.width;
        ret.size.height=this->size.height+(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator+(rectui16 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(uint64)rect.origin.y;
        ret.size.width=this->size.width+(uint64)rect.size.width;
        ret.size.height=this->size.height+(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator+(rectui32 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(uint64)rect.origin.y;
        ret.size.width=this->size.width+(uint64)rect.size.width;
        ret.size.height=this->size.height+(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator+(rectui64 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(uint64)rect.origin.x;
        ret.origin.y=this->origin.y+(uint64)rect.origin.y;
        ret.size.width=this->size.width+(uint64)rect.size.width;
        ret.size.height=this->size.height+(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator+(uint8 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(uint64)n;
        ret.origin.y=this->origin.y+(uint64)n;
        ret.size.width=this->size.width+(uint64)n;
        ret.size.height=this->size.height+(uint64)n;
        return ret;
    }
    rectui64 operator+(uint32 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(uint64)n;
        ret.origin.y=this->origin.y+(uint64)n;
        ret.size.width=this->size.width+(uint64)n;
        ret.size.height=this->size.height+(uint64)n;
        return ret;
    }
    rectui64 operator+(uint16 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(uint64)n;
        ret.origin.y=this->origin.y+(uint64)n;
        ret.size.width=this->size.width+(uint64)n;
        ret.size.height=this->size.height+(uint64)n;
        return ret;
    }
    rectui64 operator+(uint64 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x+(uint64)n;
        ret.origin.y=this->origin.y+(uint64)n;
        ret.size.width=this->size.width+(uint64)n;
        ret.size.height=this->size.height+(uint64)n;
        return ret;
    }
    void operator+=(rectui8 rect){
        //
        this->origin.x+=(uint64)rect.origin.x;
        this->origin.y+=(uint64)rect.origin.y;
        this->size.width+=(uint64)rect.size.width;
        this->size.height+=(uint64)rect.size.height;
    }
    void operator+=(rectui16 rect){
        //
        this->origin.x+=(uint64)rect.origin.x;
        this->origin.y+=(uint64)rect.origin.y;
        this->size.width+=(uint64)rect.size.width;
        this->size.height+=(uint64)rect.size.height;
    }
    void operator+=(rectui32 rect){
        //
        this->origin.x+=(uint64)rect.origin.x;
        this->origin.y+=(uint64)rect.origin.y;
        this->size.width+=(uint64)rect.size.width;
        this->size.height+=(uint64)rect.size.height;
    }
    void operator+=(rectui64 rect){
        //
        this->origin.x+=(uint64)rect.origin.x;
        this->origin.y+=(uint64)rect.origin.y;
        this->size.width+=(uint64)rect.size.width;
        this->size.height+=(uint64)rect.size.height;
    }
    void operator+=(uint8 n){
        //
        this->origin.x+=(uint64)n;
        this->origin.y+=(uint64)n;
        this->size.width+=(uint64)n;
        this->size.height+=(uint64)n;
    }
    void operator+=(uint32 n){
        //
        this->origin.x+=(uint64)n;
        this->origin.y+=(uint64)n;
        this->size.width+=(uint64)n;
        this->size.height+=(uint64)n;
    }
    void operator+=(uint16 n){
        //
        this->origin.x+=(uint64)n;
        this->origin.y+=(uint64)n;
        this->size.width+=(uint64)n;
        this->size.height+=(uint64)n;
    }
    void operator+=(uint64 n){
        //
        this->origin.x+=(uint64)n;
        this->origin.y+=(uint64)n;
        this->size.width+=(uint64)n;
        this->size.height+=(uint64)n;
    }
    rectui64 operator-(rectui8 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(uint64)rect.origin.y;
        ret.size.width=this->size.width-(uint64)rect.size.width;
        ret.size.height=this->size.height-(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator-(rectui16 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(uint64)rect.origin.y;
        ret.size.width=this->size.width-(uint64)rect.size.width;
        ret.size.height=this->size.height-(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator-(rectui32 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(uint64)rect.origin.y;
        ret.size.width=this->size.width-(uint64)rect.size.width;
        ret.size.height=this->size.height-(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator-(rectui64 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(uint64)rect.origin.x;
        ret.origin.y=this->origin.y-(uint64)rect.origin.y;
        ret.size.width=this->size.width-(uint64)rect.size.width;
        ret.size.height=this->size.height-(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator-(uint8 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(uint64)n;
        ret.origin.y=this->origin.y-(uint64)n;
        ret.size.width=this->size.width-(uint64)n;
        ret.size.height=this->size.height-(uint64)n;
        return ret;
    }
    rectui64 operator-(uint32 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(uint64)n;
        ret.origin.y=this->origin.y-(uint64)n;
        ret.size.width=this->size.width-(uint64)n;
        ret.size.height=this->size.height-(uint64)n;
        return ret;
    }
    rectui64 operator-(uint16 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(uint64)n;
        ret.origin.y=this->origin.y-(uint64)n;
        ret.size.width=this->size.width-(uint64)n;
        ret.size.height=this->size.height-(uint64)n;
        return ret;
    }
    rectui64 operator-(uint64 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x-(uint64)n;
        ret.origin.y=this->origin.y-(uint64)n;
        ret.size.width=this->size.width-(uint64)n;
        ret.size.height=this->size.height-(uint64)n;
        return ret;
    }
    void operator-=(rectui8 vec){
        //
        this->origin.x-=(uint64)vec.origin.x;
        this->origin.y-=(uint64)vec.origin.y;
        this->size.width-=(uint64)vec.size.width;
        this->size.height-=(uint64)vec.size.height;
    }
    void operator-=(rectui16 vec){
        //
        this->origin.x-=(uint64)vec.origin.x;
        this->origin.y-=(uint64)vec.origin.y;
        this->size.width-=(uint64)vec.size.width;
        this->size.height-=(uint64)vec.size.height;
    }
    void operator-=(rectui32 vec){
        //
        this->origin.x-=(uint64)vec.origin.x;
        this->origin.y-=(uint64)vec.origin.y;
        this->size.width-=(uint64)vec.size.width;
        this->size.height-=(uint64)vec.size.height;
    }
    void operator-=(rectui64 vec){
        //
        this->origin.x-=(uint64)vec.origin.x;
        this->origin.y-=(uint64)vec.origin.y;
        this->size.width-=(uint64)vec.size.width;
        this->size.height-=(uint64)vec.size.height;
    }
    void operator-=(uint8 n){
        //
        this->origin.x-=(uint64)n;
        this->origin.y-=(uint64)n;
        this->size.width-=(uint64)n;
        this->size.height-=(uint64)n;
    }
    void operator-=(uint32 n){
        //
        this->origin.x-=(uint64)n;
        this->origin.y-=(uint64)n;
        this->size.width-=(uint64)n;
        this->size.height-=(uint64)n;
    }
    void operator-=(uint16 n){
        //
        this->origin.x-=(uint64)n;
        this->origin.y-=(uint64)n;
        this->size.width-=(uint64)n;
        this->size.height-=(uint64)n;
    }
    void operator-=(uint64 n){
        //
        this->origin.x-=(uint64)n;
        this->origin.y-=(uint64)n;
        this->size.width-=(uint64)n;
        this->size.height-=(uint64)n;
    }
    rectui64 operator*(rectui8 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(uint64)rect.origin.y;
        ret.size.width=this->size.width*(uint64)rect.size.width;
        ret.size.height=this->size.height*(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator*(rectui16 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(uint64)rect.origin.y;
        ret.size.width=this->size.width*(uint64)rect.size.width;
        ret.size.height=this->size.height*(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator*(rectui32 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(uint64)rect.origin.y;
        ret.size.width=this->size.width*(uint64)rect.size.width;
        ret.size.height=this->size.height*(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator*(rectui64 rect){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(uint64)rect.origin.x;
        ret.origin.y=this->origin.y*(uint64)rect.origin.y;
        ret.size.width=this->size.width*(uint64)rect.size.width;
        ret.size.height=this->size.height*(uint64)rect.size.height;
        return ret;
    }
    rectui64 operator*(uint8 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(uint64)n;
        ret.origin.y=this->origin.y*(uint64)n;
        ret.size.width=this->size.width*(uint64)n;
        ret.size.height=this->size.height*(uint64)n;
        return ret;
    }
    rectui64 operator*(uint32 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(uint64)n;
        ret.origin.y=this->origin.y*(uint64)n;
        ret.size.width=this->size.width*(uint64)n;
        ret.size.height=this->size.height*(uint64)n;
        return ret;
    }
    rectui64 operator*(uint16 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(uint64)n;
        ret.origin.y=this->origin.y*(uint64)n;
        ret.size.width=this->size.width*(uint64)n;
        ret.size.height=this->size.height*(uint64)n;
        return ret;
    }
    rectui64 operator*(uint64 n){
        //
        rectui64 ret;
        ret.origin.x=this->origin.x*(uint64)n;
        ret.origin.y=this->origin.y*(uint64)n;
        ret.size.width=this->size.width*(uint64)n;
        ret.size.height=this->size.height*(uint64)n;
        return ret;
    }
    void operator*=(rectui8 rect){
        //
        this->origin.x*=(uint64)rect.origin.x;
        this->origin.y*=(uint64)rect.origin.y;
        this->size.width*=(uint64)rect.size.width;
        this->size.height*=(uint64)rect.size.height;
    }
    void operator*=(rectui16 rect){
        //
        this->origin.x*=(uint64)rect.origin.x;
        this->origin.y*=(uint64)rect.origin.y;
        this->size.width*=(uint64)rect.size.width;
        this->size.height*=(uint64)rect.size.height;
    }
    void operator*=(rectui32 rect){
        //
        this->origin.x*=(uint64)rect.origin.x;
        this->origin.y*=(uint64)rect.origin.y;
        this->size.width*=(uint64)rect.size.width;
        this->size.height*=(uint64)rect.size.height;
    }
    void operator*=(rectui64 rect){
        //
        this->origin.x*=(uint64)rect.origin.x;
        this->origin.y*=(uint64)rect.origin.y;
        this->size.width*=(uint64)rect.size.width;
        this->size.height*=(uint64)rect.size.height;
    }
    void operator*=(uint8 n){
        //
        this->origin.x*=(uint64)n;
        this->origin.y*=(uint64)n;
        this->size.width*=(uint64)n;
        this->size.height*=(uint64)n;
    }
    void operator*=(uint32 n){
        //
        this->origin.x*=(uint64)n;
        this->origin.y*=(uint64)n;
        this->size.width*=(uint64)n;
        this->size.height*=(uint64)n;
    }
    void operator*=(uint16 n){
        //
        this->origin.x*=(uint64)n;
        this->origin.y*=(uint64)n;
        this->size.width*=(uint64)n;
        this->size.height*=(uint64)n;
    }
    void operator*=(uint64 n){
        //
        this->origin.x*=(uint64)n;
        this->origin.y*=(uint64)n;
        this->size.width*=(uint64)n;
        this->size.height*=(uint64)n;
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
    rectui64 operator++(int32){
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
    rectui64 operator--(int32){
        //
        this->origin.x--;
        this->origin.y--;
        this->size.width--;
        this->size.height--;
        return rectui64(this->origin.x,this->origin.y,this->size.width,this->size.height);
    }
    rectui64 operator()(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectui64((uint64)this->origin.x,(uint64)this->origin.y,(uint64)this->size.width,(uint64)this->size.height);
    }
    rectui64 operator()(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(uint64)x;
        this->origin.y=(uint64)y;
        this->size.width=(uint64)width;
        this->size.height=(uint64)height;
        return rectui64((uint64)this->origin.x,(uint64)this->origin.y,(uint64)this->size.width,(uint64)this->size.height);
    }
    rectui64 operator()(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(uint64)x;
        this->origin.y=(uint64)y;
        this->size.width=(uint64)width;
        this->size.height=(uint64)height;
        return rectui64((uint64)this->origin.x,(uint64)this->origin.y,(uint64)this->size.width,(uint64)this->size.height);
    }
    rectui64 operator()(uint64 x,uint64 y,uint64 width,uint64 height){
        //
        this->origin.x=(uint64)x;
        this->origin.y=(uint64)y;
        this->size.width=(uint64)width;
        this->size.height=(uint64)height;
        return rectui64((uint64)this->origin.x,(uint64)this->origin.y,(uint64)this->size.width,(uint64)this->size.height);
    }
};

class rectf32{
public:
    //position
    vec2f32 origin;
    //size
    size2f32 size;
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
    rectf32(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
    }
    rectf32(uint64 x,uint64 y,uint64 width,uint64 height){
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
    rectf32 operator=(int8 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(int32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(int16 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(int64 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(uint8 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(uint32 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(uint16 n){
        //
        this->origin.x=(edk::float32)n;
        this->origin.y=(edk::float32)n;
        this->size.width=(edk::float32)n;
        this->size.height=(edk::float32)n;
        return *this;
    }
    rectf32 operator=(uint64 n){
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
    rectf32 operator+(int8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(int32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(int16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(int64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(uint8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(uint32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(uint16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x+(edk::float32)n;
        ret.origin.y=this->origin.y+(edk::float32)n;
        ret.size.width=this->size.width+(edk::float32)n;
        ret.size.height=this->size.height+(edk::float32)n;
        return ret;
    }
    rectf32 operator+(uint64 n){
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
    void operator+=(int8 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(int32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(int16 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(int64 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(uint8 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(uint32 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(uint16 n){
        //
        this->origin.x+=(edk::float32)n;
        this->origin.y+=(edk::float32)n;
        this->size.width+=(edk::float32)n;
        this->size.height+=(edk::float32)n;
    }
    void operator+=(uint64 n){
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
    rectf32 operator-(int8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(int32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(int16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(int64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(uint8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(uint32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(uint16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x-(edk::float32)n;
        ret.origin.y=this->origin.y-(edk::float32)n;
        ret.size.width=this->size.width-(edk::float32)n;
        ret.size.height=this->size.height-(edk::float32)n;
        return ret;
    }
    rectf32 operator-(uint64 n){
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
    void operator-=(int8 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(int32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(int16 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(int64 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(uint8 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(uint32 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(uint16 n){
        //
        this->origin.x-=(edk::float32)n;
        this->origin.y-=(edk::float32)n;
        this->size.width-=(edk::float32)n;
        this->size.height-=(edk::float32)n;
    }
    void operator-=(uint64 n){
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
    rectf32 operator*(int8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(int32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(int16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(int64 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(uint8 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(uint32 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(uint16 n){
        //
        rectf32 ret;
        ret.origin.x=this->origin.x*(edk::float32)n;
        ret.origin.y=this->origin.y*(edk::float32)n;
        ret.size.width=this->size.width*(edk::float32)n;
        ret.size.height=this->size.height*(edk::float32)n;
        return ret;
    }
    rectf32 operator*(uint64 n){
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
    void operator*=(int8 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(int32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(int16 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(int64 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(uint8 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(uint32 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(uint16 n){
        //
        this->origin.x*=(edk::float32)n;
        this->origin.y*=(edk::float32)n;
        this->size.width*=(edk::float32)n;
        this->size.height*=(edk::float32)n;
    }
    void operator*=(uint64 n){
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
    rectf32 operator++(int32){
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
    rectf32 operator--(int32){
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
    rectf32 operator()(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(edk::float32)x;
        this->origin.y=(edk::float32)y;
        this->size.width=(edk::float32)width;
        this->size.height=(edk::float32)height;
        return rectf32((edk::float32)this->origin.x,(edk::float32)this->origin.y,(edk::float32)this->size.width,(edk::float32)this->size.height);
    }
    rectf32 operator()(uint64 x,uint64 y,uint64 width,uint64 height){
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
    vec2f64 origin;
    //size
    size2f64 size;
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
    rectf64(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
    }
    rectf64(uint64 x,uint64 y,uint64 width,uint64 height){
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
    rectf64 operator=(int8 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(int32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(int16 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(int64 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(uint8 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(uint32 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(uint16 n){
        //
        this->origin.x=(edk::float64)n;
        this->origin.y=(edk::float64)n;
        this->size.width=(edk::float64)n;
        this->size.height=(edk::float64)n;
        return *this;
    }
    rectf64 operator=(uint64 n){
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
    rectf64 operator+(int8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(int32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(int16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(int64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(uint8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(uint32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(uint16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x+(edk::float64)n;
        ret.origin.y=this->origin.y+(edk::float64)n;
        ret.size.width=this->size.width+(edk::float64)n;
        ret.size.height=this->size.height+(edk::float64)n;
        return ret;
    }
    rectf64 operator+(uint64 n){
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
    void operator+=(int8 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(int32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(int16 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(int64 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(uint8 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(uint32 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(uint16 n){
        //
        this->origin.x+=(edk::float64)n;
        this->origin.y+=(edk::float64)n;
        this->size.width+=(edk::float64)n;
        this->size.height+=(edk::float64)n;
    }
    void operator+=(uint64 n){
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
    rectf64 operator-(int8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(int32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(int16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(int64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(uint8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(uint32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(uint16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x-(edk::float64)n;
        ret.origin.y=this->origin.y-(edk::float64)n;
        ret.size.width=this->size.width-(edk::float64)n;
        ret.size.height=this->size.height-(edk::float64)n;
        return ret;
    }
    rectf64 operator-(uint64 n){
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
    void operator-=(int8 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(int32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(int16 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(int64 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(uint8 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(uint32 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(uint16 n){
        //
        this->origin.x-=(edk::float64)n;
        this->origin.y-=(edk::float64)n;
        this->size.width-=(edk::float64)n;
        this->size.height-=(edk::float64)n;
    }
    void operator-=(uint64 n){
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
    rectf64 operator*(int8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(int32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(int16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(int64 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(uint8 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(uint32 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(uint16 n){
        //
        rectf64 ret;
        ret.origin.x=this->origin.x*(edk::float64)n;
        ret.origin.y=this->origin.y*(edk::float64)n;
        ret.size.width=this->size.width*(edk::float64)n;
        ret.size.height=this->size.height*(edk::float64)n;
        return ret;
    }
    rectf64 operator*(uint64 n){
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
    void operator*=(int8 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(int32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(int16 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(int64 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(uint8 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(uint32 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(uint16 n){
        //
        this->origin.x*=(edk::float64)n;
        this->origin.y*=(edk::float64)n;
        this->size.width*=(edk::float64)n;
        this->size.height*=(edk::float64)n;
    }
    void operator*=(uint64 n){
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
    rectf64 operator++(int32){
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
    rectf64 operator--(int32){
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
    rectf64 operator()(int8 x,int8 y,int8 width,int8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(int32 x,int32 y,int32 width,int32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(int16 x,int16 y,int16 width,int16 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(int64 x,int64 y,int64 width,int64 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(uint8 x,uint8 y,uint8 width,uint8 height){
        //
        this->origin.x=x;
        this->origin.y=y;
        this->size.width=width;
        this->size.height=height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(uint32 x,uint32 y,uint32 width,uint32 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(uint16 x,uint16 y,uint16 width,uint16 height){
        //
        this->origin.x=(edk::float64)x;
        this->origin.y=(edk::float64)y;
        this->size.width=(edk::float64)width;
        this->size.height=(edk::float64)height;
        return rectf64((edk::float64)this->origin.x,(edk::float64)this->origin.y,(edk::float64)this->size.width,(edk::float64)this->size.height);
    }
    rectf64 operator()(uint64 x,uint64 y,uint64 width,uint64 height){
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
