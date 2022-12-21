#ifndef EDK_TYPEVEC2_H
#define EDK_TYPEVEC2_H

/*
Library C++ typeVec2 - 2D vectors used in Edk Game Engine
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
#warning "Inside TypesVec2"
#endif

#pragma once
#include "TypeVars.h"

#ifdef printMessages
#warning "    Compiling TypesVec2"
#endif

namespace edk{
//vec2i8
class vec2i8{
    //
public:
    edk::int8 x,y;

    //CONSTRUTOR
    vec2i8(){
        //zera as variaveis
        this->x=this->y=0;edkEnd();
    }
    vec2i8(edk::int8 x,edk::int8 y){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
    }
    vec2i8(edk::int16 x,edk::int16 y){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
    }
    vec2i8(edk::int32 x,edk::int32 y){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
    }
    vec2i8(edk::int64 x,edk::int64 y){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
    }
    vec2i8(edk::uint8 x,edk::uint8 y){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
    }
    vec2i8(edk::uint16 x,edk::uint16 y){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
    }
    vec2i8(edk::uint32 x,edk::uint32 y){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
    }
    vec2i8(edk::uint64 x,edk::uint64 y){
        //zera as variaveis
        this->x=(edk::int8)x;edkEnd();
        this->y=(edk::int8)y;edkEnd();
    }
    //operators

    //=
    vec2i8 operator=(edk::vec2i8 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2i8 operator=(edk::int8 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i8 operator=(edk::int16 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i8 operator=(edk::int32 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i8 operator=(edk::int64 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i8 operator=(edk::uint8 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i8 operator=(edk::uint16 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i8 operator=(edk::uint32 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i8 operator=(edk::uint64 n){
        //
        this->x=(edk::int8)n;edkEnd();
        this->y=(edk::int8)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::vec2i8 vec){
        //
        return (this->x==vec.x&&this->y==vec.y);edkEnd();
    }
    //!=
    bool operator!=(edk::vec2i8 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y);edkEnd();
    }

    //Operator >
    bool operator>(edk::vec2i8 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::int8 value){
        if(this->x>value && this->y>value){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(edk::vec2i8 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>=vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::int8 value){
        if(this->x>value && this->y>=value){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::vec2i8 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::int8 value){
        if(this->x<value && this->y<value){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(edk::vec2i8 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<=vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::int8 value){
        if(this->x<value && this->y<=value){
            return true;
        }
        return false;
    }

    //+
    vec2i8 operator+(edk::vec2i8 vec){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec2i8 operator+(edk::int8 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator+(edk::int16 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator+(edk::int32 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator+(edk::int64 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator+(edk::uint8 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator+(edk::uint16 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator+(edk::uint32 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator+(edk::uint64 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x+(edk::int8)n;edkEnd();
        ret.y=this->y+(edk::int8)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::vec2i8 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::int8)n;edkEnd();
        this->y+=(edk::int8)n;edkEnd();
    }

    //-
    vec2i8 operator-(edk::vec2i8 vec){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec2i8 operator-(edk::int8 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator-(edk::int16 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator-(edk::int32 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator-(edk::int64 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator-(edk::uint8 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator-(edk::uint16 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator-(edk::uint32 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator-(edk::uint64 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x-(edk::int8)n;edkEnd();
        ret.y=this->y-(edk::int8)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::vec2i8 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::int8)n;edkEnd();
        this->y-=(edk::int8)n;edkEnd();
    }

    //*
    vec2i8 operator*(edk::vec2i8 vec){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec2i8 operator*(edk::int8 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator*(edk::int16 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator*(edk::int32 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator*(edk::int64 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator*(edk::uint8 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator*(edk::uint16 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator*(edk::uint32 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        return ret;
    }
    vec2i8 operator*(edk::uint64 n){
        //
        vec2i8 ret;edkEnd();
        ret.x=this->x*(edk::int8)n;edkEnd();
        ret.y=this->y*(edk::int8)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::vec2i8 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::int8)n;edkEnd();
        this->y*=(edk::int8)n;edkEnd();
    }

    //++
    vec2i8 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        return edk::vec2i8(this->x,this->y);edkEnd();
    }
    vec2i8 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        return edk::vec2i8(this->x,this->y);edkEnd();
    }

    //--
    vec2i8 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        return edk::vec2i8(this->x,this->y);edkEnd();
    }
    vec2i8 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        return edk::vec2i8(this->x,this->y);edkEnd();
    }

    //
    vec2i8 operator()(edk::int8 x,edk::int8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i8((edk::int8)this->x,(edk::int8)this->y);edkEnd();
    }
    vec2i8 operator()(edk::int16 x,edk::int16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i8((edk::int8)this->x,(edk::int8)this->y);edkEnd();
    }
    vec2i8 operator()(edk::int32 x,edk::int32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i8((edk::int8)this->x,(edk::int8)this->y);edkEnd();
    }
    vec2i8 operator()(edk::int64 x,edk::int64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i8((edk::int8)this->x,(edk::int8)this->y);edkEnd();
    }
    vec2i8 operator()(edk::uint8 x,edk::uint8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i8((edk::int8)this->x,(edk::int8)this->y);edkEnd();
    }
    vec2i8 operator()(edk::uint16 x,edk::uint16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i8((edk::int8)this->x,(edk::int8)this->y);edkEnd();
    }
    vec2i8 operator()(edk::uint32 x,edk::uint32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i8((edk::int8)this->x,(edk::int8)this->y);edkEnd();
    }
    vec2i8 operator()(edk::uint64 x,edk::uint64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i8((edk::int8)this->x,(edk::int8)this->y);edkEnd();
    }
};

//vec2i16
class vec2i16{
    //
public:
    edk::int16 x,y;

    //CONSTRUTOR
    vec2i16(){
        //zera as variaveis
        this->x=this->y=0;edkEnd();
    }
    vec2i16(edk::int8 x,edk::int8 y){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
    }
    vec2i16(edk::int16 x,edk::int16 y){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
    }
    vec2i16(edk::int32 x,edk::int32 y){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
    }
    vec2i16(edk::int64 x,edk::int64 y){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
    }
    vec2i16(edk::uint8 x,edk::uint8 y){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
    }
    vec2i16(edk::uint16 x,edk::uint16 y){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
    }
    vec2i16(edk::uint32 x,edk::uint32 y){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
    }
    vec2i16(edk::uint64 x,edk::uint64 y){
        //zera as variaveis
        this->x=(edk::int16)x;edkEnd();
        this->y=(edk::int16)y;edkEnd();
    }
    //operators

    //=
    vec2i16 operator=(edk::vec2i8 vec){
        //
        this->x=(edk::int16)vec.x;edkEnd();
        this->y=(edk::int16)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2i16 operator=(edk::vec2i16 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2i16 operator=(edk::int8 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i16 operator=(edk::int16 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i16 operator=(edk::int32 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i16 operator=(edk::int64 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i16 operator=(edk::uint8 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i16 operator=(edk::uint16 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i16 operator=(edk::uint32 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i16 operator=(edk::uint64 n){
        //
        this->x=(edk::int16)n;edkEnd();
        this->y=(edk::int16)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::vec2i8 vec){
        //
        return (this->x==(edk::int16)vec.x&&this->y==(edk::int16)vec.y);edkEnd();
    }
    bool operator==(edk::vec2i16 vec){
        //
        return (this->x==vec.x&&this->y==vec.y);edkEnd();
    }
    //!=
    bool operator!=(edk::vec2i8 vec){
        //
        return (this->x!=(edk::int16)vec.x&&this->y!=(edk::int16)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2i16 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y);edkEnd();
    }

    //Operator >
    bool operator>(edk::vec2i8 vec){
        if(this->x>(edk::int16)vec.x){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y>(edk::int16)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::int8 value){
        if(this->x>(edk::int16)value && this->y>(edk::int16)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2i16 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::int16 value){
        if(this->x>value && this->y>value){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(edk::vec2i8 vec){
        if(this->x>(edk::int16)vec.x){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y>=(edk::int16)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::int8 value){
        if(this->x>(edk::int16)value && this->y>=(edk::int16)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2i16 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>=vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::int16 value){
        if(this->x>value && this->y>=value){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::vec2i8 vec){
        if(this->x<(edk::int16)vec.x){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y<(edk::int16)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::int8 value){
        if(this->x<(edk::int16)value && this->y<(edk::int16)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2i16 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::int16 value){
        if(this->x<value && this->y<value){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(edk::vec2i8 vec){
        if(this->x<(edk::int16)vec.x){
            return true;
        }
        else if(this->x==(edk::int16)vec.x && this->y<=(edk::int16)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::int8 value){
        if(this->x<(edk::int16)value && this->y<=(edk::int16)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2i16 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<=vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::int16 value){
        if(this->x<value && this->y<=value){
            return true;
        }
        return false;
    }

    //+
    vec2i16 operator+(edk::vec2i8 vec){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)vec.x;edkEnd();
        ret.y=this->y+(edk::int16)vec.y;edkEnd();
        return ret;
    }
    vec2i16 operator+(edk::vec2i16 vec){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec2i16 operator+(edk::int8 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator+(edk::int16 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator+(edk::int32 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator+(edk::int64 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator+(edk::uint8 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator+(edk::uint16 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator+(edk::uint32 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator+(edk::uint64 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x+(edk::int16)n;edkEnd();
        ret.y=this->y+(edk::int16)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::vec2i8 vec){
        //
        this->x+=(edk::int16)vec.x;edkEnd();
        this->y+=(edk::int16)vec.y;edkEnd();
    }
    void operator+=(edk::vec2i16 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::int16)n;edkEnd();
        this->y+=(edk::int16)n;edkEnd();
    }

    //-
    vec2i16 operator-(edk::vec2i8 vec){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)vec.x;edkEnd();
        ret.y=this->y-(edk::int16)vec.y;edkEnd();
        return ret;
    }
    vec2i16 operator-(edk::vec2i16 vec){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec2i16 operator-(edk::int8 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator-(edk::int16 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator-(edk::int32 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator-(edk::int64 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator-(edk::uint8 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator-(edk::uint16 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator-(edk::uint32 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator-(edk::uint64 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x-(edk::int16)n;edkEnd();
        ret.y=this->y-(edk::int16)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::vec2i8 vec){
        //
        this->x-=(edk::int16)vec.x;edkEnd();
        this->y-=(edk::int16)vec.y;edkEnd();
    }
    void operator-=(edk::vec2i16 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::int16)n;edkEnd();
        this->y-=(edk::int16)n;edkEnd();
    }

    //*
    vec2i16 operator*(edk::vec2i8 vec){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)vec.x;edkEnd();
        ret.y=this->y*(edk::int16)vec.y;edkEnd();
        return ret;
    }
    vec2i16 operator*(edk::vec2i16 vec){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec2i16 operator*(edk::int8 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator*(edk::int16 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator*(edk::int32 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator*(edk::int64 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator*(edk::uint8 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator*(edk::uint16 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator*(edk::uint32 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        return ret;
    }
    vec2i16 operator*(edk::uint64 n){
        //
        vec2i16 ret;edkEnd();
        ret.x=this->x*(edk::int16)n;edkEnd();
        ret.y=this->y*(edk::int16)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::vec2i8 vec){
        //
        this->x*=(edk::int16)vec.x;edkEnd();
        this->y*=(edk::int16)vec.y;edkEnd();
    }
    void operator*=(edk::vec2i16 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::int16)n;edkEnd();
        this->y*=(edk::int16)n;edkEnd();
    }

    //++
    vec2i16 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        return edk::vec2i16(this->x,this->y);edkEnd();
    }
    vec2i16 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        return edk::vec2i16(this->x,this->y);edkEnd();
    }

    //--
    vec2i16 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        return edk::vec2i16(this->x,this->y);edkEnd();
    }
    vec2i16 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        return edk::vec2i16(this->x,this->y);edkEnd();
    }

    //
    vec2i16 operator()(edk::int8 x,edk::int8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i16((edk::int16)this->x,(edk::int16)this->y);edkEnd();
    }
    vec2i16 operator()(edk::int16 x,edk::int16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i16((edk::int16)this->x,(edk::int16)this->y);edkEnd();
    }
    vec2i16 operator()(edk::int32 x,edk::int32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i16((edk::int16)this->x,(edk::int16)this->y);edkEnd();
    }
    vec2i16 operator()(edk::int64 x,edk::int64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i16((edk::int16)this->x,(edk::int16)this->y);edkEnd();
    }
    vec2i16 operator()(edk::uint8 x,edk::uint8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i16((edk::int16)this->x,(edk::int16)this->y);edkEnd();
    }
    vec2i16 operator()(edk::uint16 x,edk::uint16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i16((edk::int16)this->x,(edk::int16)this->y);edkEnd();
    }
    vec2i16 operator()(edk::uint32 x,edk::uint32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i16((edk::int16)this->x,(edk::int16)this->y);edkEnd();
    }
    vec2i16 operator()(edk::uint64 x,edk::uint64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i16((edk::int16)this->x,(edk::int16)this->y);edkEnd();
    }
};

//vec2i32
class vec2i32{
    //
public:
    edk::int32 x,y;

    //CONSTRUTOR
    vec2i32(){
        //zera as variaveis
        this->x=this->y=0;edkEnd();
    }
    vec2i32(edk::int8 x,edk::int8 y){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
    }
    vec2i32(edk::int16 x,edk::int16 y){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
    }
    vec2i32(edk::int32 x,edk::int32 y){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
    }
    vec2i32(edk::int64 x,edk::int64 y){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
    }
    vec2i32(edk::uint8 x,edk::uint8 y){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
    }
    vec2i32(edk::uint16 x,edk::uint16 y){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
    }
    vec2i32(edk::uint32 x,edk::uint32 y){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
    }
    vec2i32(edk::uint64 x,edk::uint64 y){
        //zera as variaveis
        this->x=(edk::int32)x;edkEnd();
        this->y=(edk::int32)y;edkEnd();
    }
    //operators

    //=
    vec2i32 operator=(edk::vec2i8 vec){
        //
        this->x=(edk::int32)vec.x;edkEnd();
        this->y=(edk::int32)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2i32 operator=(edk::vec2i16 vec){
        //
        this->x=(edk::int32)vec.x;edkEnd();
        this->y=(edk::int32)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2i32 operator=(edk::vec2i32 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2i32 operator=(edk::int8 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i32 operator=(edk::int16 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i32 operator=(edk::int32 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i32 operator=(edk::int64 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i32 operator=(edk::uint8 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i32 operator=(edk::uint16 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i32 operator=(edk::uint32 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i32 operator=(edk::uint64 n){
        //
        this->x=(edk::int32)n;edkEnd();
        this->y=(edk::int32)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::vec2i8 vec){
        //
        return (this->x==(edk::int32)vec.x&&this->y==(edk::int32)vec.y);edkEnd();
    }
    bool operator==(edk::vec2i16 vec){
        //
        return (this->x==(edk::int32)vec.x&&this->y==(edk::int32)vec.y);edkEnd();
    }
    bool operator==(edk::vec2i32 vec){
        //
        return (this->x==vec.x&&this->y==vec.y);edkEnd();
    }
    //!=
    bool operator!=(edk::vec2i8 vec){
        //
        return (this->x!=(edk::int32)vec.x&&this->y!=(edk::int32)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2i16 vec){
        //
        return (this->x!=(edk::int32)vec.x&&this->y!=(edk::int32)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2i32 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y);edkEnd();
    }

    //Operator >
    bool operator>(edk::vec2i8 vec){
        if(this->x>(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y>(edk::int32)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::int8 value){
        if(this->x>(edk::int32)value && this->y>(edk::int32)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2i16 vec){
        if(this->x>(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y>(edk::int32)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::int16 value){
        if(this->x>(edk::int32)value && this->y>(edk::int32)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2i32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::int32 value){
        if(this->x>value && this->y>value){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(edk::vec2i8 vec){
        if(this->x>(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y>=(edk::int32)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::int8 value){
        if(this->x>(edk::int32)value && this->y>=(edk::int32)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2i16 vec){
        if(this->x>(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y>=(edk::int32)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::int16 value){
        if(this->x>(edk::int32)value && this->y>=(edk::int32)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2i32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>=vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::int32 value){
        if(this->x>value && this->y>=value){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::vec2i8 vec){
        if(this->x<(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y<(edk::int32)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::int8 value){
        if(this->x<(edk::int32)value && this->y<(edk::int32)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2i16 vec){
        if(this->x<(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y<(edk::int32)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::int16 value){
        if(this->x<(edk::int32)value && this->y<(edk::int32)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2i32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::int32 value){
        if(this->x<value && this->y<value){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(edk::vec2i8 vec){
        if(this->x<(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y<=(edk::int32)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::int8 value){
        if(this->x<(edk::int32)value && this->y<=(edk::int32)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2i16 vec){
        if(this->x<(edk::int32)vec.x){
            return true;
        }
        else if(this->x==(edk::int32)vec.x && this->y<=(edk::int32)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::int16 value){
        if(this->x<(edk::int32)value && this->y<=(edk::int32)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2i32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<=vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::int32 value){
        if(this->x<value && this->y<=value){
            return true;
        }
        return false;
    }

    //+
    vec2i32 operator+(edk::vec2i8 vec){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)vec.x;edkEnd();
        ret.y=this->y+(edk::int32)vec.y;edkEnd();
        return ret;
    }
    vec2i32 operator+(edk::vec2i16 vec){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)vec.x;edkEnd();
        ret.y=this->y+(edk::int32)vec.y;edkEnd();
        return ret;
    }
    vec2i32 operator+(edk::vec2i32 vec){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec2i32 operator+(edk::int8 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator+(edk::int16 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator+(edk::int32 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator+(edk::int64 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator+(edk::uint8 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator+(edk::uint16 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator+(edk::uint32 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator+(edk::uint64 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x+(edk::int32)n;edkEnd();
        ret.y=this->y+(edk::int32)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::vec2i8 vec){
        //
        this->x+=(edk::int32)vec.x;edkEnd();
        this->y+=(edk::int32)vec.y;edkEnd();
    }
    void operator+=(edk::vec2i16 vec){
        //
        this->x+=(edk::int32)vec.x;edkEnd();
        this->y+=(edk::int32)vec.y;edkEnd();
    }
    void operator+=(edk::vec2i32 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::int32)n;edkEnd();
        this->y+=(edk::int32)n;edkEnd();
    }

    //-
    vec2i32 operator-(edk::vec2i8 vec){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)vec.x;edkEnd();
        ret.y=this->y-(edk::int32)vec.y;edkEnd();
        return ret;
    }
    vec2i32 operator-(edk::vec2i16 vec){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)vec.x;edkEnd();
        ret.y=this->y-(edk::int32)vec.y;edkEnd();
        return ret;
    }
    vec2i32 operator-(edk::vec2i32 vec){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec2i32 operator-(edk::int8 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator-(edk::int16 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator-(edk::int32 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator-(edk::int64 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator-(edk::uint8 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator-(edk::uint16 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator-(edk::uint32 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator-(edk::uint64 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x-(edk::int32)n;edkEnd();
        ret.y=this->y-(edk::int32)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::vec2i8 vec){
        //
        this->x-=(edk::int32)vec.x;edkEnd();
        this->y-=(edk::int32)vec.y;edkEnd();
    }
    void operator-=(edk::vec2i16 vec){
        //
        this->x-=(edk::int32)vec.x;edkEnd();
        this->y-=(edk::int32)vec.y;edkEnd();
    }
    void operator-=(edk::vec2i32 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::int32)n;edkEnd();
        this->y-=(edk::int32)n;edkEnd();
    }

    //*
    vec2i32 operator*(edk::vec2i8 vec){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)vec.x;edkEnd();
        ret.y=this->y*(edk::int32)vec.y;edkEnd();
        return ret;
    }
    vec2i32 operator*(edk::vec2i16 vec){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)vec.x;edkEnd();
        ret.y=this->y*(edk::int32)vec.y;edkEnd();
        return ret;
    }
    vec2i32 operator*(edk::vec2i32 vec){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec2i32 operator*(edk::int8 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator*(edk::int16 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator*(edk::int32 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator*(edk::int64 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator*(edk::uint8 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator*(edk::uint16 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator*(edk::uint32 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        return ret;
    }
    vec2i32 operator*(edk::uint64 n){
        //
        vec2i32 ret;edkEnd();
        ret.x=this->x*(edk::int32)n;edkEnd();
        ret.y=this->y*(edk::int32)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::vec2i8 vec){
        //
        this->x*=(edk::int32)vec.x;edkEnd();
        this->y*=(edk::int32)vec.y;edkEnd();
    }
    void operator*=(edk::vec2i16 vec){
        //
        this->x*=(edk::int32)vec.x;edkEnd();
        this->y*=(edk::int32)vec.y;edkEnd();
    }
    void operator*=(edk::vec2i32 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::int32)n;edkEnd();
        this->y*=(edk::int32)n;edkEnd();
    }

    //++
    vec2i32 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        return edk::vec2i32(this->x,this->y);edkEnd();
    }
    vec2i32 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        return edk::vec2i32(this->x,this->y);edkEnd();
    }

    //--
    vec2i32 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        return edk::vec2i32(this->x,this->y);edkEnd();
    }
    vec2i32 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        return edk::vec2i32(this->x,this->y);edkEnd();
    }

    //
    vec2i32 operator()(edk::int8 x,edk::int8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i32((edk::int32)this->x,(edk::int32)this->y);edkEnd();
    }
    vec2i32 operator()(edk::int16 x,edk::int16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i32((edk::int32)this->x,(edk::int32)this->y);edkEnd();
    }
    vec2i32 operator()(edk::int32 x,edk::int32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i32((edk::int32)this->x,(edk::int32)this->y);edkEnd();
    }
    vec2i32 operator()(edk::int64 x,edk::int64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i32((edk::int32)this->x,(edk::int32)this->y);edkEnd();
    }
    vec2i32 operator()(edk::uint8 x,edk::uint8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i32((edk::int32)this->x,(edk::int32)this->y);edkEnd();
    }
    vec2i32 operator()(edk::uint16 x,edk::uint16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i32((edk::int32)this->x,(edk::int32)this->y);edkEnd();
    }
    vec2i32 operator()(edk::uint32 x,edk::uint32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i32((edk::int32)this->x,(edk::int32)this->y);edkEnd();
    }
    vec2i32 operator()(edk::uint64 x,edk::uint64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i32((edk::int32)this->x,(edk::int32)this->y);edkEnd();
    }
};

//vec2i64
class vec2i64{
    //
public:
    edk::int64 x,y;

    //CONSTRUTOR
    vec2i64(){
        //zera as variaveis
        this->x=this->y=0;edkEnd();
    }
    vec2i64(edk::int8 x,edk::int8 y){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
    }
    vec2i64(edk::int16 x,edk::int16 y){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
    }
    vec2i64(edk::int32 x,edk::int32 y){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
    }
    vec2i64(edk::int64 x,edk::int64 y){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
    }
    vec2i64(edk::uint8 x,edk::uint8 y){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
    }
    vec2i64(edk::uint16 x,edk::uint16 y){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
    }
    vec2i64(edk::uint32 x,edk::uint32 y){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
    }
    vec2i64(edk::uint64 x,edk::uint64 y){
        //zera as variaveis
        this->x=(edk::int64)x;edkEnd();
        this->y=(edk::int64)y;edkEnd();
    }
    //operators

    //=
    vec2i64 operator=(edk::vec2i8 vec){
        //
        this->x=(edk::int64)vec.x;edkEnd();
        this->y=(edk::int64)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::vec2i16 vec){
        //
        this->x=(edk::int64)vec.x;edkEnd();
        this->y=(edk::int64)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::vec2i32 vec){
        //
        this->x=(edk::int64)vec.x;edkEnd();
        this->y=(edk::int64)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::vec2i64 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::int8 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::int16 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::int32 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::int64 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::uint8 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::uint16 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::uint32 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2i64 operator=(edk::uint64 n){
        //
        this->x=(edk::int64)n;edkEnd();
        this->y=(edk::int64)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::vec2i8 vec){
        //
        return (this->x==(edk::int64)vec.x&&this->y==(edk::int64)vec.y);edkEnd();
    }
    bool operator==(edk::vec2i16 vec){
        //
        return (this->x==(edk::int64)vec.x&&this->y==(edk::int64)vec.y);edkEnd();
    }
    bool operator==(edk::vec2i32 vec){
        //
        return (this->x==(edk::int64)vec.x&&this->y==(edk::int64)vec.y);edkEnd();
    }
    bool operator==(edk::vec2i64 vec){
        //
        return (this->x==vec.x&&this->y==vec.y);edkEnd();
    }
    //!=
    bool operator!=(edk::vec2i8 vec){
        //
        return (this->x!=(edk::int64)vec.x&&this->y!=(edk::int64)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2i16 vec){
        //
        return (this->x!=(edk::int64)vec.x&&this->y!=(edk::int64)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2i32 vec){
        //
        return (this->x!=(edk::int64)vec.x&&this->y!=(edk::int64)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2i64 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y);edkEnd();
    }

    //Operator >
    bool operator>(edk::vec2i8 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::int8 value){
        if(this->x>(edk::int64)value && this->y>(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2i16 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::int16 value){
        if(this->x>(edk::int64)value && this->y>(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2i32 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::int32 value){
        if(this->x>(edk::int64)value && this->y>(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2i64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::int64 value){
        if(this->x>value && this->y>value){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(edk::vec2i8 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>=(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::int8 value){
        if(this->x>(edk::int64)value && this->y>=(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2i16 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>=(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::int16 value){
        if(this->x>(edk::int64)value && this->y>=(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2i32 vec){
        if(this->x>(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y>=(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::int32 value){
        if(this->x>(edk::int64)value && this->y>=(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2i64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>=vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::int64 value){
        if(this->x>value && this->y>=value){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::vec2i8 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::int8 value){
        if(this->x<(edk::int64)value && this->y<(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2i16 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::int16 value){
        if(this->x<(edk::int64)value && this->y<(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2i32 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::int32 value){
        if(this->x<(edk::int64)value && this->y<(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2i64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::int64 value){
        if(this->x<value && this->y<value){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(edk::vec2i8 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<=(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::int8 value){
        if(this->x<(edk::int64)value && this->y<=(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2i16 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<=(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::int16 value){
        if(this->x<(edk::int64)value && this->y<=(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2i32 vec){
        if(this->x<(edk::int64)vec.x){
            return true;
        }
        else if(this->x==(edk::int64)vec.x && this->y<=(edk::int64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::int32 value){
        if(this->x<(edk::int64)value && this->y<=(edk::int64)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2i64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<=vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::int64 value){
        if(this->x<value && this->y<=value){
            return true;
        }
        return false;
    }

    //+
    vec2i64 operator+(edk::vec2i8 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)vec.x;edkEnd();
        ret.y=this->y+(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::vec2i16 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)vec.x;edkEnd();
        ret.y=this->y+(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::vec2i32 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)vec.x;edkEnd();
        ret.y=this->y+(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::vec2i64 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::int8 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::int16 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::int32 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::int64 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::uint8 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::uint16 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::uint32 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator+(edk::uint64 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x+(edk::int64)n;edkEnd();
        ret.y=this->y+(edk::int64)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::vec2i8 vec){
        //
        this->x+=(edk::int64)vec.x;edkEnd();
        this->y+=(edk::int64)vec.y;edkEnd();
    }
    void operator+=(edk::vec2i16 vec){
        //
        this->x+=(edk::int64)vec.x;edkEnd();
        this->y+=(edk::int64)vec.y;edkEnd();
    }
    void operator+=(edk::vec2i32 vec){
        //
        this->x+=(edk::int64)vec.x;edkEnd();
        this->y+=(edk::int64)vec.y;edkEnd();
    }
    void operator+=(edk::vec2i64 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::int64)n;edkEnd();
        this->y+=(edk::int64)n;edkEnd();
    }

    //-
    vec2i64 operator-(edk::vec2i8 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)vec.x;edkEnd();
        ret.y=this->y-(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::vec2i16 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)vec.x;edkEnd();
        ret.y=this->y-(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::vec2i32 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)vec.x;edkEnd();
        ret.y=this->y-(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::vec2i64 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::int8 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::int16 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::int32 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::int64 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::uint8 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::uint16 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::uint32 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator-(edk::uint64 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x-(edk::int64)n;edkEnd();
        ret.y=this->y-(edk::int64)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::vec2i8 vec){
        //
        this->x-=(edk::int64)vec.x;edkEnd();
        this->y-=(edk::int64)vec.y;edkEnd();
    }
    void operator-=(edk::vec2i16 vec){
        //
        this->x-=(edk::int64)vec.x;edkEnd();
        this->y-=(edk::int64)vec.y;edkEnd();
    }
    void operator-=(edk::vec2i32 vec){
        //
        this->x-=(edk::int64)vec.x;edkEnd();
        this->y-=(edk::int64)vec.y;edkEnd();
    }
    void operator-=(edk::vec2i64 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::int64)n;edkEnd();
        this->y-=(edk::int64)n;edkEnd();
    }

    //*
    vec2i64 operator*(edk::vec2i8 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)vec.x;edkEnd();
        ret.y=this->y*(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::vec2i16 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)vec.x;edkEnd();
        ret.y=this->y*(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::vec2i32 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)vec.x;edkEnd();
        ret.y=this->y*(edk::int64)vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::vec2i64 vec){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::int8 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::int16 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::int32 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::int64 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::uint8 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::uint16 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::uint32 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        return ret;
    }
    vec2i64 operator*(edk::uint64 n){
        //
        vec2i64 ret;edkEnd();
        ret.x=this->x*(edk::int64)n;edkEnd();
        ret.y=this->y*(edk::int64)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::vec2i8 vec){
        //
        this->x*=(edk::int64)vec.x;edkEnd();
        this->y*=(edk::int64)vec.y;edkEnd();
    }
    void operator*=(edk::vec2i16 vec){
        //
        this->x*=(edk::int64)vec.x;edkEnd();
        this->y*=(edk::int64)vec.y;edkEnd();
    }
    void operator*=(edk::vec2i32 vec){
        //
        this->x*=(edk::int64)vec.x;edkEnd();
        this->y*=(edk::int64)vec.y;edkEnd();
    }
    void operator*=(edk::vec2i64 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::int64)n;edkEnd();
        this->y*=(edk::int64)n;edkEnd();
    }

    //++
    vec2i64 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        return edk::vec2i64(this->x,this->y);edkEnd();
    }
    vec2i64 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        return edk::vec2i64(this->x,this->y);edkEnd();
    }

    //--
    vec2i64 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        return edk::vec2i64(this->x,this->y);edkEnd();
    }
    vec2i64 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        return edk::vec2i64(this->x,this->y);edkEnd();
    }

    //
    vec2i64 operator()(edk::int8 x,edk::int8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i64((edk::int64)this->x,(edk::int64)this->y);edkEnd();
    }
    vec2i64 operator()(edk::int16 x,edk::int16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i64((edk::int64)this->x,(edk::int64)this->y);edkEnd();
    }
    vec2i64 operator()(edk::int32 x,edk::int32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i64((edk::int64)this->x,(edk::int64)this->y);edkEnd();
    }
    vec2i64 operator()(edk::int64 x,edk::int64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i64((edk::int64)this->x,(edk::int64)this->y);edkEnd();
    }
    vec2i64 operator()(edk::uint8 x,edk::uint8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i64((edk::int64)this->x,(edk::int64)this->y);edkEnd();
    }
    vec2i64 operator()(edk::uint16 x,edk::uint16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i64((edk::int64)this->x,(edk::int64)this->y);edkEnd();
    }
    vec2i64 operator()(edk::uint32 x,edk::uint32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i64((edk::int64)this->x,(edk::int64)this->y);edkEnd();
    }
    vec2i64 operator()(edk::uint64 x,edk::uint64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2i64((edk::int64)this->x,(edk::int64)this->y);edkEnd();
    }
};

//vec2ui8
class vec2ui8{
    //
public:
    edk::uint8 x,y;

    //CONSTRUTOR
    vec2ui8(){
        //zera as variaveis
        this->x=this->y=0;edkEnd();
    }
    vec2ui8(edk::uint8 x,edk::uint8 y){
        //zera as variaveis
        this->x=(edk::uint8)x;edkEnd();
        this->y=(edk::uint8)y;edkEnd();
    }
    vec2ui8(edk::uint16 x,edk::uint16 y){
        //zera as variaveis
        this->x=(edk::uint8)x;edkEnd();
        this->y=(edk::uint8)y;edkEnd();
    }
    vec2ui8(edk::uint32 x,edk::uint32 y){
        //zera as variaveis
        this->x=(edk::uint8)x;edkEnd();
        this->y=(edk::uint8)y;edkEnd();
    }
    vec2ui8(edk::uint64 x,edk::uint64 y){
        //zera as variaveis
        this->x=(edk::uint8)x;edkEnd();
        this->y=(edk::uint8)y;edkEnd();
    }
    //operators

    //=
    vec2ui8 operator=(edk::vec2ui8 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2ui8 operator=(edk::uint8 n){
        //
        this->x=(edk::uint8)n;edkEnd();
        this->y=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui8 operator=(edk::uint16 n){
        //
        this->x=(edk::uint8)n;edkEnd();
        this->y=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui8 operator=(edk::uint32 n){
        //
        this->x=(edk::uint8)n;edkEnd();
        this->y=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui8 operator=(edk::uint64 n){
        //
        this->x=(edk::uint8)n;edkEnd();
        this->y=(edk::uint8)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::vec2ui8 vec){
        //
        return (this->x==vec.x&&this->y==vec.y);edkEnd();
    }
    //!=
    bool operator!=(edk::vec2ui8 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y);edkEnd();
    }

    //Operator >
    bool operator>(edk::vec2ui8 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::uint8 value){
        if(this->x>value && this->y>value){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(edk::vec2ui8 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>=vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::uint8 value){
        if(this->x>value && this->y>=value){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::vec2ui8 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::uint8 value){
        if(this->x<value && this->y<value){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(edk::vec2ui8 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<=vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::uint8 value){
        if(this->x<value && this->y<=value){
            return true;
        }
        return false;
    }

    //+
    vec2ui8 operator+(edk::vec2ui8 vec){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec2ui8 operator+(edk::uint8 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x+(edk::uint8)n;edkEnd();
        ret.y=this->y+(edk::uint8)n;edkEnd();
        return ret;
    }
    vec2ui8 operator+(edk::uint16 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x+(edk::uint8)n;edkEnd();
        ret.y=this->y+(edk::uint8)n;edkEnd();
        return ret;
    }
    vec2ui8 operator+(edk::uint32 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x+(edk::uint8)n;edkEnd();
        ret.y=this->y+(edk::uint8)n;edkEnd();
        return ret;
    }
    vec2ui8 operator+(edk::uint64 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x+(edk::uint8)n;edkEnd();
        ret.y=this->y+(edk::uint8)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::vec2ui8 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::uint8)n;edkEnd();
        this->y+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::uint8)n;edkEnd();
        this->y+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::uint8)n;edkEnd();
        this->y+=(edk::uint8)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::uint8)n;edkEnd();
        this->y+=(edk::uint8)n;edkEnd();
    }

    //-
    vec2ui8 operator-(edk::vec2ui8 vec){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec2ui8 operator-(edk::uint8 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x-(edk::uint8)n;edkEnd();
        ret.y=this->y-(edk::uint8)n;edkEnd();
        return ret;
    }
    vec2ui8 operator-(edk::uint16 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x-(edk::uint8)n;edkEnd();
        ret.y=this->y-(edk::uint8)n;edkEnd();
        return ret;
    }
    vec2ui8 operator-(edk::uint32 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x-(edk::uint8)n;edkEnd();
        ret.y=this->y-(edk::uint8)n;edkEnd();
        return ret;
    }
    vec2ui8 operator-(edk::uint64 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x-(edk::uint8)n;edkEnd();
        ret.y=this->y-(edk::uint8)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::vec2ui8 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::uint8)n;edkEnd();
        this->y-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::uint8)n;edkEnd();
        this->y-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::uint8)n;edkEnd();
        this->y-=(edk::uint8)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::uint8)n;edkEnd();
        this->y-=(edk::uint8)n;edkEnd();
    }

    //*
    vec2ui8 operator*(edk::vec2ui8 vec){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec2ui8 operator*(edk::uint8 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x*(edk::uint8)n;edkEnd();
        ret.y=this->y*(edk::uint8)n;edkEnd();
        return ret;
    }
    vec2ui8 operator*(edk::uint16 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x*(edk::uint8)n;edkEnd();
        ret.y=this->y*(edk::uint8)n;edkEnd();
        return ret;
    }
    vec2ui8 operator*(edk::uint32 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x*(edk::uint8)n;edkEnd();
        ret.y=this->y*(edk::uint8)n;edkEnd();
        return ret;
    }
    vec2ui8 operator*(edk::uint64 n){
        //
        vec2ui8 ret;edkEnd();
        ret.x=this->x*(edk::uint8)n;edkEnd();
        ret.y=this->y*(edk::uint8)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::vec2ui8 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::uint8)n;edkEnd();
        this->y*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::uint8)n;edkEnd();
        this->y*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::uint8)n;edkEnd();
        this->y*=(edk::uint8)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::uint8)n;edkEnd();
        this->y*=(edk::uint8)n;edkEnd();
    }

    //++
    vec2ui8 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        return edk::vec2ui8(this->x,this->y);edkEnd();
    }
    vec2ui8 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        return edk::vec2ui8(this->x,this->y);edkEnd();
    }

    //--
    vec2ui8 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        return edk::vec2ui8(this->x,this->y);edkEnd();
    }
    vec2ui8 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        return edk::vec2ui8(this->x,this->y);edkEnd();
    }

    //
    vec2ui8 operator()(edk::uint8 x,edk::uint8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui8((edk::uint8)this->x,(edk::uint8)this->y);edkEnd();
    }
    vec2ui8 operator()(edk::uint16 x,edk::uint16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui8((edk::uint8)this->x,(edk::uint8)this->y);edkEnd();
    }
    vec2ui8 operator()(edk::uint32 x,edk::uint32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui8((edk::uint8)this->x,(edk::uint8)this->y);edkEnd();
    }
    vec2ui8 operator()(edk::uint64 x,edk::uint64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui8((edk::uint8)this->x,(edk::uint8)this->y);edkEnd();
    }
};

//vec2ui16
class vec2ui16{
    //
public:
    edk::uint16 x,y;

    //CONSTRUTOR
    vec2ui16(){
        //zera as variaveis
        this->x=this->y=0;edkEnd();
    }
    vec2ui16(edk::uint8 x,edk::uint8 y){
        //zera as variaveis
        this->x=(edk::uint16)x;edkEnd();
        this->y=(edk::uint16)y;edkEnd();
    }
    vec2ui16(edk::uint16 x,edk::uint16 y){
        //zera as variaveis
        this->x=(edk::uint16)x;edkEnd();
        this->y=(edk::uint16)y;edkEnd();
    }
    vec2ui16(edk::uint32 x,edk::uint32 y){
        //zera as variaveis
        this->x=(edk::uint16)x;edkEnd();
        this->y=(edk::uint16)y;edkEnd();
    }
    vec2ui16(edk::uint64 x,edk::uint64 y){
        //zera as variaveis
        this->x=(edk::uint16)x;edkEnd();
        this->y=(edk::uint16)y;edkEnd();
    }
    //operators

    //=
    vec2ui16 operator=(edk::vec2ui8 vec){
        //
        this->x=(edk::uint16)vec.x;edkEnd();
        this->y=(edk::uint16)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2ui16 operator=(edk::vec2ui16 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2ui16 operator=(edk::uint8 n){
        //
        this->x=(edk::uint16)n;edkEnd();
        this->y=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui16 operator=(edk::uint16 n){
        //
        this->x=(edk::uint16)n;edkEnd();
        this->y=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui16 operator=(edk::uint32 n){
        //
        this->x=(edk::uint16)n;edkEnd();
        this->y=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui16 operator=(edk::uint64 n){
        //
        this->x=(edk::uint16)n;edkEnd();
        this->y=(edk::uint16)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::vec2ui8 vec){
        //
        return (this->x==(edk::uint16)vec.x&&this->y==(edk::uint16)vec.y);edkEnd();
    }
    bool operator==(edk::vec2ui16 vec){
        //
        return (this->x==vec.x&&this->y==vec.y);edkEnd();
    }
    //!=
    bool operator!=(edk::vec2ui8 vec){
        //
        return (this->x!=(edk::uint16)vec.x||this->y!=(edk::uint16)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2ui16 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y);edkEnd();
    }

    //Operator >
    bool operator>(edk::vec2ui8 vec){
        if(this->x>(edk::uint16)vec.x){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y>(edk::uint16)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::uint8 value){
        if(this->x>(edk::uint16)value && this->y>(edk::uint16)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2ui16 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::uint16 value){
        if(this->x>value && this->y>value){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(edk::vec2ui8 vec){
        if(this->x>(edk::uint16)vec.x){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y>=(edk::uint16)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::uint8 value){
        if(this->x>(edk::uint16)value && this->y>=(edk::uint16)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2ui16 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>=vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::uint16 value){
        if(this->x>value && this->y>=value){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::vec2ui8 vec){
        if(this->x<(edk::uint16)vec.x){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y<(edk::uint16)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::uint8 value){
        if(this->x<(edk::uint16)value && this->y<(edk::uint16)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2ui16 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::uint16 value){
        if(this->x<value && this->y<value){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(edk::vec2ui8 vec){
        if(this->x<(edk::uint16)vec.x){
            return true;
        }
        else if(this->x==(edk::uint16)vec.x && this->y<=(edk::uint16)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::uint8 value){
        if(this->x<(edk::uint16)value && this->y<=(edk::uint16)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2ui16 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<=vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::uint16 value){
        if(this->x<value && this->y<=value){
            return true;
        }
        return false;
    }

    //+
    vec2ui16 operator+(edk::vec2ui8 vec){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)vec.x;edkEnd();
        ret.y=this->y+(edk::uint16)vec.y;edkEnd();
        return ret;
    }
    vec2ui16 operator+(edk::vec2ui16 vec){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec2ui16 operator+(edk::uint8 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)n;edkEnd();
        ret.y=this->y+(edk::uint16)n;edkEnd();
        return ret;
    }
    vec2ui16 operator+(edk::uint16 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)n;edkEnd();
        ret.y=this->y+(edk::uint16)n;edkEnd();
        return ret;
    }
    vec2ui16 operator+(edk::uint32 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)n;edkEnd();
        ret.y=this->y+(edk::uint16)n;edkEnd();
        return ret;
    }
    vec2ui16 operator+(edk::uint64 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x+(edk::uint16)n;edkEnd();
        ret.y=this->y+(edk::uint16)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::vec2ui8 vec){
        //
        this->x+=(edk::uint16)vec.x;edkEnd();
        this->y+=(edk::uint16)vec.y;edkEnd();
    }
    void operator+=(edk::vec2ui16 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::uint16)n;edkEnd();
        this->y+=(edk::uint16)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::uint16)n;edkEnd();
        this->y+=(edk::uint16)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::uint16)n;edkEnd();
        this->y+=(edk::uint16)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::uint16)n;edkEnd();
        this->y+=(edk::uint16)n;edkEnd();
    }

    //-
    vec2ui16 operator-(edk::vec2ui8 vec){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)vec.x;edkEnd();
        ret.y=this->y-(edk::uint16)vec.y;edkEnd();
        return ret;
    }
    vec2ui16 operator-(edk::vec2ui16 vec){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec2ui16 operator-(edk::uint8 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)n;edkEnd();
        ret.y=this->y-(edk::uint16)n;edkEnd();
        return ret;
    }
    vec2ui16 operator-(edk::uint16 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)n;edkEnd();
        ret.y=this->y-(edk::uint16)n;edkEnd();
        return ret;
    }
    vec2ui16 operator-(edk::uint32 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)n;edkEnd();
        ret.y=this->y-(edk::uint16)n;edkEnd();
        return ret;
    }
    vec2ui16 operator-(edk::uint64 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x-(edk::uint16)n;edkEnd();
        ret.y=this->y-(edk::uint16)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::vec2ui8 vec){
        //
        this->x-=(edk::uint16)vec.x;edkEnd();
        this->y-=(edk::uint16)vec.y;edkEnd();
    }
    void operator-=(edk::vec2ui16 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::uint16)n;edkEnd();
        this->y-=(edk::uint16)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::uint16)n;edkEnd();
        this->y-=(edk::uint16)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::uint16)n;edkEnd();
        this->y-=(edk::uint16)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::uint16)n;edkEnd();
        this->y-=(edk::uint16)n;edkEnd();
    }

    //*
    vec2ui16 operator*(edk::vec2ui8 vec){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)vec.x;edkEnd();
        ret.y=this->y*(edk::uint16)vec.y;edkEnd();
        return ret;
    }
    vec2ui16 operator*(edk::vec2ui16 vec){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec2ui16 operator*(edk::uint8 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)n;edkEnd();
        ret.y=this->y*(edk::uint16)n;edkEnd();
        return ret;
    }
    vec2ui16 operator*(edk::uint16 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)n;edkEnd();
        ret.y=this->y*(edk::uint16)n;edkEnd();
        return ret;
    }
    vec2ui16 operator*(edk::uint32 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)n;edkEnd();
        ret.y=this->y*(edk::uint16)n;edkEnd();
        return ret;
    }
    vec2ui16 operator*(edk::uint64 n){
        //
        vec2ui16 ret;edkEnd();
        ret.x=this->x*(edk::uint16)n;edkEnd();
        ret.y=this->y*(edk::uint16)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::vec2ui8 vec){
        //
        this->x*=(edk::uint16)vec.x;edkEnd();
        this->y*=(edk::uint16)vec.y;edkEnd();
    }
    void operator*=(edk::vec2ui16 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::uint16)n;edkEnd();
        this->y*=(edk::uint16)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::uint16)n;edkEnd();
        this->y*=(edk::uint16)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::uint16)n;edkEnd();
        this->y*=(edk::uint16)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::uint16)n;edkEnd();
        this->y*=(edk::uint16)n;edkEnd();
    }

    //++
    vec2ui16 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        return edk::vec2ui16(this->x,this->y);edkEnd();
    }
    vec2ui16 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        return edk::vec2ui16(this->x,this->y);edkEnd();
    }

    //--
    vec2ui16 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        return edk::vec2ui16(this->x,this->y);edkEnd();
    }
    vec2ui16 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        return edk::vec2ui16(this->x,this->y);edkEnd();
    }

    //
    vec2ui16 operator()(edk::uint8 x,edk::uint8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui16((edk::uint16)this->x,(edk::uint16)this->y);edkEnd();
    }
    vec2ui16 operator()(edk::uint16 x,edk::uint16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui16((edk::uint16)this->x,(edk::uint16)this->y);edkEnd();
    }
    vec2ui16 operator()(edk::uint32 x,edk::uint32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui16((edk::uint16)this->x,(edk::uint16)this->y);edkEnd();
    }
    vec2ui16 operator()(edk::uint64 x,edk::uint64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui16((edk::uint16)this->x,(edk::uint16)this->y);edkEnd();
    }
};

//vec2ui32
class vec2ui32{
    //
public:
    edk::uint32 x,y;

    //CONSTRUTOR
    vec2ui32(){
        //zera as variaveis
        this->x=this->y=0;edkEnd();
    }
    vec2ui32(edk::uint8 x,edk::uint8 y){
        //zera as variaveis
        this->x=(edk::uint32)x;edkEnd();
        this->y=(edk::uint32)y;edkEnd();
    }
    vec2ui32(edk::uint16 x,edk::uint16 y){
        //zera as variaveis
        this->x=(edk::uint32)x;edkEnd();
        this->y=(edk::uint32)y;edkEnd();
    }
    vec2ui32(edk::uint32 x,edk::uint32 y){
        //zera as variaveis
        this->x=(edk::uint32)x;edkEnd();
        this->y=(edk::uint32)y;edkEnd();
    }
    vec2ui32(edk::uint64 x,edk::uint64 y){
        //zera as variaveis
        this->x=(edk::uint32)x;edkEnd();
        this->y=(edk::uint32)y;edkEnd();
    }
    //operators

    //=
    vec2ui32 operator=(edk::vec2ui8 vec){
        //
        this->x=(edk::uint32)vec.x;edkEnd();
        this->y=(edk::uint32)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2ui32 operator=(edk::vec2ui16 vec){
        //
        this->x=(edk::uint32)vec.x;edkEnd();
        this->y=(edk::uint32)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2ui32 operator=(edk::vec2ui32 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2ui32 operator=(edk::uint8 n){
        //
        this->x=(edk::uint32)n;edkEnd();
        this->y=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui32 operator=(edk::uint16 n){
        //
        this->x=(edk::uint32)n;edkEnd();
        this->y=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui32 operator=(edk::uint32 n){
        //
        this->x=(edk::uint32)n;edkEnd();
        this->y=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui32 operator=(edk::uint64 n){
        //
        this->x=(edk::uint32)n;edkEnd();
        this->y=(edk::uint32)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::vec2ui8 vec){
        //
        return (this->x==(edk::uint32)vec.x&&this->y==(edk::uint32)vec.y);edkEnd();
    }
    bool operator==(edk::vec2ui16 vec){
        //
        return (this->x==(edk::uint32)vec.x&&this->y==(edk::uint32)vec.y);edkEnd();
    }
    bool operator==(edk::vec2ui32 vec){
        //
        return (this->x==vec.x&&this->y==vec.y);edkEnd();
    }
    //!=
    bool operator!=(edk::vec2ui8 vec){
        //
        return (this->x!=(edk::uint32)vec.x||this->y!=(edk::uint32)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2ui16 vec){
        //
        return (this->x!=(edk::uint32)vec.x||this->y!=(edk::uint32)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2ui32 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y);edkEnd();
    }

    //Operator >
    bool operator>(edk::vec2ui8 vec){
        if(this->x>(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y>(edk::uint32)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::uint8 value){
        if(this->x>(edk::uint32)value && this->y>(edk::uint32)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2ui16 vec){
        if(this->x>(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y>(edk::uint32)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::uint16 value){
        if(this->x>(edk::uint32)value && this->y>(edk::uint32)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2ui32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::uint32 value){
        if(this->x>value && this->y>value){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(edk::vec2ui8 vec){
        if(this->x>(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y>=(edk::uint32)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::uint8 value){
        if(this->x>(edk::uint32)value && this->y>=(edk::uint32)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2ui16 vec){
        if(this->x>(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y>=(edk::uint32)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::uint16 value){
        if(this->x>(edk::uint32)value && this->y>=(edk::uint32)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2ui32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>=vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::uint32 value){
        if(this->x>value && this->y>=value){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::vec2ui8 vec){
        if(this->x<(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y<(edk::uint32)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::uint8 value){
        if(this->x<(edk::uint32)value && this->y<(edk::uint32)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2ui16 vec){
        if(this->x<(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y<(edk::uint32)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::uint16 value){
        if(this->x<(edk::uint32)value && this->y<(edk::uint32)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2ui32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::uint32 value){
        if(this->x<value && this->y<value){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(edk::vec2ui8 vec){
        if(this->x<(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y<=(edk::uint32)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::uint8 value){
        if(this->x<(edk::uint32)value && this->y<=(edk::uint32)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2ui16 vec){
        if(this->x<(edk::uint32)vec.x){
            return true;
        }
        else if(this->x==(edk::uint32)vec.x && this->y<=(edk::uint32)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::uint16 value){
        if(this->x<(edk::uint32)value && this->y<=(edk::uint32)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2ui32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<=vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::uint32 value){
        if(this->x<value && this->y<=value){
            return true;
        }
        return false;
    }

    //+
    vec2ui32 operator+(edk::vec2ui8 vec){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)vec.x;edkEnd();
        ret.y=this->y+(edk::uint32)vec.y;edkEnd();
        return ret;
    }
    vec2ui32 operator+(edk::vec2ui16 vec){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)vec.x;edkEnd();
        ret.y=this->y+(edk::uint32)vec.y;edkEnd();
        return ret;
    }
    vec2ui32 operator+(edk::vec2ui32 vec){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec2ui32 operator+(edk::uint8 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)n;edkEnd();
        ret.y=this->y+(edk::uint32)n;edkEnd();
        return ret;
    }
    vec2ui32 operator+(edk::uint16 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)n;edkEnd();
        ret.y=this->y+(edk::uint32)n;edkEnd();
        return ret;
    }
    vec2ui32 operator+(edk::uint32 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)n;edkEnd();
        ret.y=this->y+(edk::uint32)n;edkEnd();
        return ret;
    }
    vec2ui32 operator+(edk::uint64 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x+(edk::uint32)n;edkEnd();
        ret.y=this->y+(edk::uint32)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::vec2ui8 vec){
        //
        this->x+=(edk::uint32)vec.x;edkEnd();
        this->y+=(edk::uint32)vec.y;edkEnd();
    }
    void operator+=(edk::vec2ui16 vec){
        //
        this->x+=(edk::uint32)vec.x;edkEnd();
        this->y+=(edk::uint32)vec.y;edkEnd();
    }
    void operator+=(edk::vec2ui32 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::uint32)n;edkEnd();
        this->y+=(edk::uint32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::uint32)n;edkEnd();
        this->y+=(edk::uint32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::uint32)n;edkEnd();
        this->y+=(edk::uint32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::uint32)n;edkEnd();
        this->y+=(edk::uint32)n;edkEnd();
    }

    //-
    vec2ui32 operator-(edk::vec2ui8 vec){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)vec.x;edkEnd();
        ret.y=this->y-(edk::uint32)vec.y;edkEnd();
        return ret;
    }
    vec2ui32 operator-(edk::vec2ui16 vec){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)vec.x;edkEnd();
        ret.y=this->y-(edk::uint32)vec.y;edkEnd();
        return ret;
    }
    vec2ui32 operator-(edk::vec2ui32 vec){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec2ui32 operator-(edk::uint8 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)n;edkEnd();
        ret.y=this->y-(edk::uint32)n;edkEnd();
        return ret;
    }
    vec2ui32 operator-(edk::uint16 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)n;edkEnd();
        ret.y=this->y-(edk::uint32)n;edkEnd();
        return ret;
    }
    vec2ui32 operator-(edk::uint32 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)n;edkEnd();
        ret.y=this->y-(edk::uint32)n;edkEnd();
        return ret;
    }
    vec2ui32 operator-(edk::uint64 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x-(edk::uint32)n;edkEnd();
        ret.y=this->y-(edk::uint32)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::vec2ui8 vec){
        //
        this->x-=(edk::uint32)vec.x;edkEnd();
        this->y-=(edk::uint32)vec.y;edkEnd();
    }
    void operator-=(edk::vec2ui16 vec){
        //
        this->x-=(edk::uint32)vec.x;edkEnd();
        this->y-=(edk::uint32)vec.y;edkEnd();
    }
    void operator-=(edk::vec2ui32 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::uint32)n;edkEnd();
        this->y-=(edk::uint32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::uint32)n;edkEnd();
        this->y-=(edk::uint32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::uint32)n;edkEnd();
        this->y-=(edk::uint32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::uint32)n;edkEnd();
        this->y-=(edk::uint32)n;edkEnd();
    }

    //*
    vec2ui32 operator*(edk::vec2ui8 vec){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)vec.x;edkEnd();
        ret.y=this->y*(edk::uint32)vec.y;edkEnd();
        return ret;
    }
    vec2ui32 operator*(edk::vec2ui16 vec){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)vec.x;edkEnd();
        ret.y=this->y*(edk::uint32)vec.y;edkEnd();
        return ret;
    }
    vec2ui32 operator*(edk::vec2ui32 vec){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec2ui32 operator*(edk::uint8 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)n;edkEnd();
        ret.y=this->y*(edk::uint32)n;edkEnd();
        return ret;
    }
    vec2ui32 operator*(edk::uint16 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)n;edkEnd();
        ret.y=this->y*(edk::uint32)n;edkEnd();
        return ret;
    }
    vec2ui32 operator*(edk::uint32 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)n;edkEnd();
        ret.y=this->y*(edk::uint32)n;edkEnd();
        return ret;
    }
    vec2ui32 operator*(edk::uint64 n){
        //
        vec2ui32 ret;edkEnd();
        ret.x=this->x*(edk::uint32)n;edkEnd();
        ret.y=this->y*(edk::uint32)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::vec2ui8 vec){
        //
        this->x*=(edk::uint32)vec.x;edkEnd();
        this->y*=(edk::uint32)vec.y;edkEnd();
    }
    void operator*=(edk::vec2ui16 vec){
        //
        this->x*=(edk::uint32)vec.x;edkEnd();
        this->y*=(edk::uint32)vec.y;edkEnd();
    }
    void operator*=(edk::vec2ui32 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::uint32)n;edkEnd();
        this->y*=(edk::uint32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::uint32)n;edkEnd();
        this->y*=(edk::uint32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::uint32)n;edkEnd();
        this->y*=(edk::uint32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::uint32)n;edkEnd();
        this->y*=(edk::uint32)n;edkEnd();
    }

    //++
    vec2ui32 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        return edk::vec2ui32(this->x,this->y);edkEnd();
    }
    vec2ui32 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        return edk::vec2ui32(this->x,this->y);edkEnd();
    }

    //--
    vec2ui32 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        return edk::vec2ui32(this->x,this->y);edkEnd();
    }
    vec2ui32 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        return edk::vec2ui32(this->x,this->y);edkEnd();
    }

    //
    vec2ui32 operator()(edk::uint8 x,edk::uint8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui32((edk::uint32)this->x,(edk::uint32)this->y);edkEnd();
    }
    vec2ui32 operator()(edk::uint16 x,edk::uint16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui32((edk::uint32)this->x,(edk::uint32)this->y);edkEnd();
    }
    vec2ui32 operator()(edk::uint32 x,edk::uint32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui32((edk::uint32)this->x,(edk::uint32)this->y);edkEnd();
    }
    vec2ui32 operator()(edk::uint64 x,edk::uint64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui32((edk::uint32)this->x,(edk::uint32)this->y);edkEnd();
    }
};

//vec2ui64
class vec2ui64{
    //
public:
    edk::uint64 x,y;

    //CONSTRUTOR
    vec2ui64(){
        //zera as variaveis
        this->x=this->y=0;edkEnd();
    }
    vec2ui64(edk::uint8 x,edk::uint8 y){
        //zera as variaveis
        this->x=(edk::uint64)x;edkEnd();
        this->y=(edk::uint64)y;edkEnd();
    }
    vec2ui64(edk::uint16 x,edk::uint16 y){
        //zera as variaveis
        this->x=(edk::uint64)x;edkEnd();
        this->y=(edk::uint64)y;edkEnd();
    }
    vec2ui64(edk::uint32 x,edk::uint32 y){
        //zera as variaveis
        this->x=(edk::uint64)x;edkEnd();
        this->y=(edk::uint64)y;edkEnd();
    }
    vec2ui64(edk::uint64 x,edk::uint64 y){
        //zera as variaveis
        this->x=(edk::uint64)x;edkEnd();
        this->y=(edk::uint64)y;edkEnd();
    }
    //operators

    //=
    vec2ui64 operator=(edk::vec2ui8 vec){
        //
        this->x=(edk::uint64)vec.x;edkEnd();
        this->y=(edk::uint64)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2ui64 operator=(edk::vec2ui16 vec){
        //
        this->x=(edk::uint64)vec.x;edkEnd();
        this->y=(edk::uint64)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2ui64 operator=(edk::vec2ui32 vec){
        //
        this->x=(edk::uint64)vec.x;edkEnd();
        this->y=(edk::uint64)vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2ui64 operator=(edk::vec2ui64 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2ui64 operator=(edk::uint8 n){
        //
        this->x=(edk::uint64)n;edkEnd();
        this->y=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui64 operator=(edk::uint16 n){
        //
        this->x=(edk::uint64)n;edkEnd();
        this->y=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui64 operator=(edk::uint32 n){
        //
        this->x=(edk::uint64)n;edkEnd();
        this->y=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2ui64 operator=(edk::uint64 n){
        //
        this->x=(edk::uint64)n;edkEnd();
        this->y=(edk::uint64)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::vec2ui8 vec){
        //
        return (this->x==(edk::uint64)vec.x&&this->y==(edk::uint64)vec.y);edkEnd();
    }
    bool operator==(edk::vec2ui16 vec){
        //
        return (this->x==(edk::uint64)vec.x&&this->y==(edk::uint64)vec.y);edkEnd();
    }
    bool operator==(edk::vec2ui32 vec){
        //
        return (this->x==(edk::uint64)vec.x&&this->y==(edk::uint64)vec.y);edkEnd();
    }
    bool operator==(edk::vec2ui64 vec){
        //
        return (this->x==vec.x&&this->y==vec.y);edkEnd();
    }
    //!=
    bool operator!=(edk::vec2ui8 vec){
        //
        return (this->x!=(edk::uint64)vec.x||this->y!=(edk::uint64)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2ui16 vec){
        //
        return (this->x!=(edk::uint64)vec.x||this->y!=(edk::uint64)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2ui32 vec){
        //
        return (this->x!=(edk::uint64)vec.x||this->y!=(edk::uint64)vec.y);edkEnd();
    }
    bool operator!=(edk::vec2ui64 vec){
        //
        return (this->x!=vec.x||this->y!=vec.y);edkEnd();
    }

    //Operator >
    bool operator>(edk::vec2ui8 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::uint8 value){
        if(this->x>(edk::uint64)value && this->y>(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2ui16 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::uint16 value){
        if(this->x>(edk::uint64)value && this->y>(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2ui32 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::uint32 value){
        if(this->x>(edk::uint64)value && this->y>(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2ui64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::uint64 value){
        if(this->x>value && this->y>value){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(edk::vec2ui8 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>=(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::uint8 value){
        if(this->x>(edk::uint64)value && this->y>=(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2ui16 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>=(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::uint16 value){
        if(this->x>(edk::uint64)value && this->y>=(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2ui32 vec){
        if(this->x>(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y>=(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::uint32 value){
        if(this->x>(edk::uint64)value && this->y>=(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2ui64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>=vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::uint64 value){
        if(this->x>value && this->y>=value){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::vec2ui8 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::uint8 value){
        if(this->x<(edk::uint64)value && this->y<(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2ui16 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::uint16 value){
        if(this->x<(edk::uint64)value && this->y<(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2ui32 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::uint32 value){
        if(this->x<(edk::uint64)value && this->y<(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2ui64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::uint64 value){
        if(this->x<value && this->y<value){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(edk::vec2ui8 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<=(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::uint8 value){
        if(this->x<(edk::uint64)value && this->y<=(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2ui16 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<=(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::uint16 value){
        if(this->x<(edk::uint64)value && this->y<=(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2ui32 vec){
        if(this->x<(edk::uint64)vec.x){
            return true;
        }
        else if(this->x==(edk::uint64)vec.x && this->y<=(edk::uint64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::uint32 value){
        if(this->x<(edk::uint64)value && this->y<=(edk::uint64)value){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2ui64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<=vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::uint64 value){
        if(this->x<value && this->y<=value){
            return true;
        }
        return false;
    }

    //+
    vec2ui64 operator+(edk::vec2ui8 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)vec.x;edkEnd();
        ret.y=this->y+(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator+(edk::vec2ui16 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)vec.x;edkEnd();
        ret.y=this->y+(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator+(edk::vec2ui32 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)vec.x;edkEnd();
        ret.y=this->y+(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator+(edk::vec2ui64 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator+(edk::uint8 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)n;edkEnd();
        ret.y=this->y+(edk::uint64)n;edkEnd();
        return ret;
    }
    vec2ui64 operator+(edk::uint16 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)n;edkEnd();
        ret.y=this->y+(edk::uint64)n;edkEnd();
        return ret;
    }
    vec2ui64 operator+(edk::uint32 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)n;edkEnd();
        ret.y=this->y+(edk::uint64)n;edkEnd();
        return ret;
    }
    vec2ui64 operator+(edk::uint64 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x+(edk::uint64)n;edkEnd();
        ret.y=this->y+(edk::uint64)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::vec2ui8 vec){
        //
        this->x+=(edk::uint64)vec.x;edkEnd();
        this->y+=(edk::uint64)vec.y;edkEnd();
    }
    void operator+=(edk::vec2ui16 vec){
        //
        this->x+=(edk::uint64)vec.x;edkEnd();
        this->y+=(edk::uint64)vec.y;edkEnd();
    }
    void operator+=(edk::vec2ui32 vec){
        //
        this->x+=(edk::uint64)vec.x;edkEnd();
        this->y+=(edk::uint64)vec.y;edkEnd();
    }
    void operator+=(edk::vec2ui64 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::uint64)n;edkEnd();
        this->y+=(edk::uint64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::uint64)n;edkEnd();
        this->y+=(edk::uint64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::uint64)n;edkEnd();
        this->y+=(edk::uint64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::uint64)n;edkEnd();
        this->y+=(edk::uint64)n;edkEnd();
    }

    //-
    vec2ui64 operator-(edk::vec2ui8 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)vec.x;edkEnd();
        ret.y=this->y-(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator-(edk::vec2ui16 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)vec.x;edkEnd();
        ret.y=this->y-(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator-(edk::vec2ui32 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)vec.x;edkEnd();
        ret.y=this->y-(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator-(edk::vec2ui64 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator-(edk::uint8 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)n;edkEnd();
        ret.y=this->y-(edk::uint64)n;edkEnd();
        return ret;
    }
    vec2ui64 operator-(edk::uint16 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)n;edkEnd();
        ret.y=this->y-(edk::uint64)n;edkEnd();
        return ret;
    }
    vec2ui64 operator-(edk::uint32 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)n;edkEnd();
        ret.y=this->y-(edk::uint64)n;edkEnd();
        return ret;
    }
    vec2ui64 operator-(edk::uint64 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x-(edk::uint64)n;edkEnd();
        ret.y=this->y-(edk::uint64)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::vec2ui8 vec){
        //
        this->x-=(edk::uint64)vec.x;edkEnd();
        this->y-=(edk::uint64)vec.y;edkEnd();
    }
    void operator-=(edk::vec2ui16 vec){
        //
        this->x-=(edk::uint64)vec.x;edkEnd();
        this->y-=(edk::uint64)vec.y;edkEnd();
    }
    void operator-=(edk::vec2ui32 vec){
        //
        this->x-=(edk::uint64)vec.x;edkEnd();
        this->y-=(edk::uint64)vec.y;edkEnd();
    }
    void operator-=(edk::vec2ui64 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::uint64)n;edkEnd();
        this->y-=(edk::uint64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::uint64)n;edkEnd();
        this->y-=(edk::uint64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::uint64)n;edkEnd();
        this->y-=(edk::uint64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::uint64)n;edkEnd();
        this->y-=(edk::uint64)n;edkEnd();
    }

    //*
    vec2ui64 operator*(edk::vec2ui8 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)vec.x;edkEnd();
        ret.y=this->y*(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator*(edk::vec2ui16 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)vec.x;edkEnd();
        ret.y=this->y*(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator*(edk::vec2ui32 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)vec.x;edkEnd();
        ret.y=this->y*(edk::uint64)vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator*(edk::vec2ui64 vec){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec2ui64 operator*(edk::uint8 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)n;edkEnd();
        ret.y=this->y*(edk::uint64)n;edkEnd();
        return ret;
    }
    vec2ui64 operator*(edk::uint16 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)n;edkEnd();
        ret.y=this->y*(edk::uint64)n;edkEnd();
        return ret;
    }
    vec2ui64 operator*(edk::uint32 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)n;edkEnd();
        ret.y=this->y*(edk::uint64)n;edkEnd();
        return ret;
    }
    vec2ui64 operator*(edk::uint64 n){
        //
        vec2ui64 ret;edkEnd();
        ret.x=this->x*(edk::uint64)n;edkEnd();
        ret.y=this->y*(edk::uint64)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::vec2ui8 vec){
        //
        this->x*=(edk::uint64)vec.x;edkEnd();
        this->y*=(edk::uint64)vec.y;edkEnd();
    }
    void operator*=(edk::vec2ui16 vec){
        //
        this->x*=(edk::uint64)vec.x;edkEnd();
        this->y*=(edk::uint64)vec.y;edkEnd();
    }
    void operator*=(edk::vec2ui32 vec){
        //
        this->x*=(edk::uint64)vec.x;edkEnd();
        this->y*=(edk::uint64)vec.y;edkEnd();
    }
    void operator*=(edk::vec2ui64 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::uint64)n;edkEnd();
        this->y*=(edk::uint64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::uint64)n;edkEnd();
        this->y*=(edk::uint64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::uint64)n;edkEnd();
        this->y*=(edk::uint64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::uint64)n;edkEnd();
        this->y*=(edk::uint64)n;edkEnd();
    }

    //++
    vec2ui64 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        return edk::vec2ui64(this->x,this->y);edkEnd();
    }
    vec2ui64 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        return edk::vec2ui64(this->x,this->y);edkEnd();
    }

    //--
    vec2ui64 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        return edk::vec2ui64(this->x,this->y);edkEnd();
    }
    vec2ui64 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        return edk::vec2ui64(this->x,this->y);edkEnd();
    }

    //
    vec2ui64 operator()(edk::uint8 x,edk::uint8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui64((edk::uint64)this->x,(edk::uint64)this->y);edkEnd();
    }
    vec2ui64 operator()(edk::uint16 x,edk::uint16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui64((edk::uint64)this->x,(edk::uint64)this->y);edkEnd();
    }
    vec2ui64 operator()(edk::uint32 x,edk::uint32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui64((edk::uint64)this->x,(edk::uint64)this->y);edkEnd();
    }
    vec2ui64 operator()(edk::uint64 x,edk::uint64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2ui64((edk::uint64)this->x,(edk::uint64)this->y);edkEnd();
    }
};

//vec2f3232
class vec2f32{
    //
public:
    edk::float32 x,y;

    //CONSTRUTOR
    vec2f32(){
        //zera as variaveis
        this->x=this->y=0;edkEnd();
    }
    vec2f32(edk::float32 x,edk::float32 y){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
    }
    vec2f32(edk::float64 x,edk::float64 y){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
    }
    vec2f32(edk::int8 x,edk::int8 y){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
    }
    vec2f32(edk::int16 x,edk::int16 y){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
    }
    vec2f32(edk::int32 x,edk::int32 y){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
    }
    vec2f32(edk::int64 x,edk::int64 y){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
    }
    vec2f32(edk::uint8 x,edk::uint8 y){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
    }
    vec2f32(edk::uint16 x,edk::uint16 y){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
    }
    vec2f32(edk::uint32 x,edk::uint32 y){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
    }
    vec2f32(edk::uint64 x,edk::uint64 y){
        //zera as variaveis
        this->x=(edk::float32)x;edkEnd();
        this->y=(edk::float32)y;edkEnd();
    }
    //operators

    //=
    vec2f32 operator=(edk::vec2f32 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2f32 operator=(edk::float32 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f32 operator=(edk::float64 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f32 operator=(edk::int8 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f32 operator=(edk::int16 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f32 operator=(edk::int32 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f32 operator=(edk::int64 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f32 operator=(edk::uint8 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f32 operator=(edk::uint16 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f32 operator=(edk::uint32 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f32 operator=(edk::uint64 n){
        //
        this->x=(edk::float32)n;edkEnd();
        this->y=(edk::float32)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::vec2f32 vec){
        //
        return (this->x>(vec.x-0.0001f) && this->x<(vec.x+0.0001f) &&
                this->y>(vec.y-0.0001f) && this->y<(vec.y+0.0001f)
                );edkEnd();
    }
    //!=
    bool operator!=(edk::vec2f32 vec){
        //
        return (this->x<(vec.x-0.0001f) || this->x>(vec.x+0.0001f) ||
                this->y<(vec.y-0.0001f) || this->y>(vec.y+0.0001f)
                );edkEnd();
    }

    //Operator >
    bool operator>(edk::vec2f32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::float32 value){
        if(this->x>value && this->y>value){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(edk::vec2f32 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>=vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::float32 value){
        if(this->x>value && this->y>=value){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::vec2f32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::float32 value){
        if(this->x<value && this->y<value){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(edk::vec2f32 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<=vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::float32 value){
        if(this->x<value && this->y<=value){
            return true;
        }
        return false;
    }

    //+
    vec2f32 operator+(edk::vec2f32 vec){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec2f32 operator+(edk::float32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator+(edk::float64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator+(edk::int8 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator+(edk::int16 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator+(edk::int32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator+(edk::int64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator+(edk::uint8 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator+(edk::uint16 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator+(edk::uint32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator+(edk::uint64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x+(edk::float32)n;edkEnd();
        ret.y=this->y+(edk::float32)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::vec2f32 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::float32 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::float64 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::float32)n;edkEnd();
        this->y+=(edk::float32)n;edkEnd();
    }

    //-
    vec2f32 operator-(edk::vec2f32 vec){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec2f32 operator-(edk::float32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator-(edk::float64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator-(edk::int8 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator-(edk::int16 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator-(edk::int32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator-(edk::int64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator-(edk::uint8 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator-(edk::uint16 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator-(edk::uint32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator-(edk::uint64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x-(edk::float32)n;edkEnd();
        ret.y=this->y-(edk::float32)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::vec2f32 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::float32 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::float64 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::float32)n;edkEnd();
        this->y-=(edk::float32)n;edkEnd();
    }

    //*
    vec2f32 operator*(edk::vec2f32 vec){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec2f32 operator*(edk::float32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator*(edk::float64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator*(edk::int8 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator*(edk::int16 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator*(edk::int32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator*(edk::int64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator*(edk::uint8 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator*(edk::uint16 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator*(edk::uint32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator*(edk::uint64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x*(edk::float32)n;edkEnd();
        ret.y=this->y*(edk::float32)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::vec2f32 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::float32 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::float64 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::float32)n;edkEnd();
        this->y*=(edk::float32)n;edkEnd();
    }

    // /
    vec2f32 operator/(edk::vec2f32 vec){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/vec.x;edkEnd();
        ret.y=this->y/vec.y;edkEnd();
        return ret;
    }
    vec2f32 operator/(edk::float32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator/(edk::float64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator/(edk::int8 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator/(edk::int16 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator/(edk::int32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator/(edk::int64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator/(edk::uint8 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator/(edk::uint16 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator/(edk::uint32 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        return ret;
    }
    vec2f32 operator/(edk::uint64 n){
        //
        vec2f32 ret;edkEnd();
        ret.x=this->x/(edk::float32)n;edkEnd();
        ret.y=this->y/(edk::float32)n;edkEnd();
        return ret;
    }

    // /=

    void operator/=(edk::vec2f32 vec){
        //
        this->x/=vec.x;edkEnd();
        this->y/=vec.y;edkEnd();
    }
    void operator/=(edk::float32 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::float64 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int8 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int16 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int32 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::int64 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint8 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint16 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint32 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
    }
    void operator/=(edk::uint64 n){
        //
        this->x/=(edk::float32)n;edkEnd();
        this->y/=(edk::float32)n;edkEnd();
    }

    //++
    vec2f32 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        return edk::vec2f32(this->x,this->y);edkEnd();
    }
    vec2f32 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        return edk::vec2f32(this->x,this->y);edkEnd();
    }

    //--
    vec2f32 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        return edk::vec2f32(this->x,this->y);edkEnd();
    }
    vec2f32 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        return edk::vec2f32(this->x,this->y);edkEnd();
    }

    //
    vec2f32 operator()(edk::float32 x,edk::float32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f32((edk::float32)this->x,(edk::float32)this->y);edkEnd();
    }
    vec2f32 operator()(edk::float64 x,edk::float64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f32((edk::float32)this->x,(edk::float32)this->y);edkEnd();
    }
    vec2f32 operator()(edk::int8 x,edk::int8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f32((edk::float32)this->x,(edk::float32)this->y);edkEnd();
    }
    vec2f32 operator()(edk::int16 x,edk::int16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f32((edk::float32)this->x,(edk::float32)this->y);edkEnd();
    }
    vec2f32 operator()(edk::int32 x,edk::int32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f32((edk::float32)this->x,(edk::float32)this->y);edkEnd();
    }
    vec2f32 operator()(edk::int64 x,edk::int64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f32((edk::float32)this->x,(edk::float32)this->y);edkEnd();
    }
    vec2f32 operator()(edk::uint8 x,edk::uint8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f32((edk::float32)this->x,(edk::float32)this->y);edkEnd();
    }
    vec2f32 operator()(edk::uint16 x,edk::uint16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f32((edk::float32)this->x,(edk::float32)this->y);edkEnd();
    }
    vec2f32 operator()(edk::uint32 x,edk::uint32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f32((edk::float32)this->x,(edk::float32)this->y);edkEnd();
    }
    vec2f32 operator()(edk::uint64 x,edk::uint64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f32((edk::float32)this->x,(edk::float32)this->y);edkEnd();
    }
};

//vec2f64
class vec2f64{
    //
public:
    edk::float64 x,y;

    //CONSTRUTOR
    vec2f64(){
        //zera as variaveis
        this->x=this->y=0;edkEnd();
    }
    vec2f64(edk::float32 x,edk::float32 y){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
    }
    vec2f64(edk::float64 x,edk::float64 y){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
    }
    vec2f64(edk::int8 x,edk::int8 y){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
    }
    vec2f64(edk::int16 x,edk::int16 y){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
    }
    vec2f64(edk::int32 x,edk::int32 y){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
    }
    vec2f64(edk::int64 x,edk::int64 y){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
    }
    vec2f64(edk::uint8 x,edk::uint8 y){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
    }
    vec2f64(edk::uint16 x,edk::uint16 y){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
    }
    vec2f64(edk::uint32 x,edk::uint32 y){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
    }
    vec2f64(edk::uint64 x,edk::uint64 y){
        //zera as variaveis
        this->x=(edk::float64)x;edkEnd();
        this->y=(edk::float64)y;edkEnd();
    }
    //operators

    //=
    vec2f64 operator=(edk::vec2f64 vec){
        //
        this->x=vec.x;edkEnd();
        this->y=vec.y;edkEnd();
        return *this;edkEnd();
    }
    vec2f64 operator=(edk::float32 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f64 operator=(edk::float64 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f64 operator=(edk::int8 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f64 operator=(edk::int16 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f64 operator=(edk::int32 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f64 operator=(edk::int64 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f64 operator=(edk::uint8 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f64 operator=(edk::uint16 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f64 operator=(edk::uint32 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }
    vec2f64 operator=(edk::uint64 n){
        //
        this->x=(edk::float64)n;edkEnd();
        this->y=(edk::float64)n;edkEnd();
        return *this;edkEnd();
    }

    //==
    bool operator==(edk::vec2f64 vec){
        //
        return (this->x>(vec.x-0.000001f) && this->x<(vec.x+0.000001f) &&
                this->y>(vec.y-0.000001f) && this->y<(vec.y+0.000001f)
                );edkEnd();
    }
    //!=
    bool operator!=(edk::vec2f64 vec){
        //
        return (this->x<(vec.x-0.000001f) || this->x>(vec.x+0.000001f) ||
                this->y<(vec.y-0.000001f) || this->y>(vec.y+0.000001f)
                );edkEnd();
    }

    //Operator >
    bool operator>(edk::vec2f32 vec){
        if(this->x>(edk::float64)vec.x){
            return true;
        }
        else if(this->x==(edk::float64)vec.x && this->y>(edk::float64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>(edk::vec2f64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>vec.y){
            return true;
        }
        return false;
    }
    //Operator >=
    bool operator>=(edk::vec2f32 vec){
        if(this->x>(edk::float64)vec.x){
            return true;
        }
        else if(this->x==(edk::float64)vec.x && this->y>=(edk::float64)vec.y){
            return true;
        }
        return false;
    }
    bool operator>=(edk::vec2f64 vec){
        if(this->x>vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y>=vec.y){
            return true;
        }
        return false;
    }
    //Operator <
    bool operator<(edk::vec2f32 vec){
        if(this->x<(edk::float64)vec.x){
            return true;
        }
        else if(this->x==(edk::float64)vec.x && this->y<(edk::float64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<(edk::vec2f64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<vec.y){
            return true;
        }
        return false;
    }
    //Operator <=
    bool operator<=(edk::vec2f32 vec){
        if(this->x<(edk::float64)vec.x){
            return true;
        }
        else if(this->x==(edk::float64)vec.x && this->y<=(edk::float64)vec.y){
            return true;
        }
        return false;
    }
    bool operator<=(edk::vec2f64 vec){
        if(this->x<vec.x){
            return true;
        }
        else if(this->x==vec.x && this->y<=vec.y){
            return true;
        }
        return false;
    }

    //+
    vec2f64 operator+(edk::vec2f64 vec){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+vec.x;edkEnd();
        ret.y=this->y+vec.y;edkEnd();
        return ret;
    }
    vec2f64 operator+(edk::float32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator+(edk::float64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator+(edk::int8 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator+(edk::int16 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator+(edk::int32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator+(edk::int64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator+(edk::uint8 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator+(edk::uint16 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator+(edk::uint32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator+(edk::uint64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x+(edk::float64)n;edkEnd();
        ret.y=this->y+(edk::float64)n;edkEnd();
        return ret;
    }

    //+=
    void operator+=(edk::vec2f64 vec){
        //
        this->x+=vec.x;edkEnd();
        this->y+=vec.y;edkEnd();
    }
    void operator+=(edk::float32 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::float64 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int8 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int16 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int32 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::int64 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint8 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint16 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint32 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
    }
    void operator+=(edk::uint64 n){
        //
        this->x+=(edk::float64)n;edkEnd();
        this->y+=(edk::float64)n;edkEnd();
    }

    //-
    vec2f64 operator-(edk::vec2f64 vec){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-vec.x;edkEnd();
        ret.y=this->y-vec.y;edkEnd();
        return ret;
    }
    vec2f64 operator-(edk::float32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator-(edk::float64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator-(edk::int8 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator-(edk::int16 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator-(edk::int32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator-(edk::int64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator-(edk::uint8 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator-(edk::uint16 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator-(edk::uint32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator-(edk::uint64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x-(edk::float64)n;edkEnd();
        ret.y=this->y-(edk::float64)n;edkEnd();
        return ret;
    }

    //-=
    void operator-=(edk::vec2f64 vec){
        //
        this->x-=vec.x;edkEnd();
        this->y-=vec.y;edkEnd();
    }
    void operator-=(edk::float32 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::float64 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int8 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int16 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int32 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::int64 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint8 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint16 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint32 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
    }
    void operator-=(edk::uint64 n){
        //
        this->x-=(edk::float64)n;edkEnd();
        this->y-=(edk::float64)n;edkEnd();
    }

    //*
    vec2f64 operator*(edk::vec2f64 vec){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*vec.x;edkEnd();
        ret.y=this->y*vec.y;edkEnd();
        return ret;
    }
    vec2f64 operator*(edk::float32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator*(edk::float64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator*(edk::int8 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator*(edk::int16 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator*(edk::int32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator*(edk::int64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator*(edk::uint8 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator*(edk::uint16 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator*(edk::uint32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator*(edk::uint64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x*(edk::float64)n;edkEnd();
        ret.y=this->y*(edk::float64)n;edkEnd();
        return ret;
    }

    //*=
    void operator*=(edk::vec2f64 vec){
        //
        this->x*=vec.x;edkEnd();
        this->y*=vec.y;edkEnd();
    }
    void operator*=(edk::float32 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::float64 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int8 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int16 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int32 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::int64 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint8 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint16 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint32 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
    }
    void operator*=(edk::uint64 n){
        //
        this->x*=(edk::float64)n;edkEnd();
        this->y*=(edk::float64)n;edkEnd();
    }

    // /
    vec2f64 operator/(edk::vec2f64 vec){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/vec.x;edkEnd();
        ret.y=this->y/vec.y;edkEnd();
        return ret;
    }
    vec2f64 operator/(edk::float32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator/(edk::float64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator/(edk::int8 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator/(edk::int16 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator/(edk::int32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator/(edk::int64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator/(edk::uint8 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator/(edk::uint16 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator/(edk::uint32 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        return ret;
    }
    vec2f64 operator/(edk::uint64 n){
        //
        vec2f64 ret;edkEnd();
        ret.x=this->x/(edk::float64)n;edkEnd();
        ret.y=this->y/(edk::float64)n;edkEnd();
        return ret;
    }

    // /=

    void operator/=(edk::vec2f64 vec){
        //
        this->x/=vec.x;edkEnd();
        this->y/=vec.y;edkEnd();
    }
    void operator/=(edk::float32 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::float64 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int8 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int16 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int32 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::int64 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint8 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint16 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint32 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
    }
    void operator/=(edk::uint64 n){
        //
        this->x/=(edk::float64)n;edkEnd();
        this->y/=(edk::float64)n;edkEnd();
    }

    //++
    vec2f64 operator++(){
        //
        ++this->x;edkEnd();
        ++this->y;edkEnd();
        return edk::vec2f64(this->x,this->y);edkEnd();
    }
    vec2f64 operator++(edk::int32){
        //
        this->x++;edkEnd();
        this->y++;edkEnd();
        return edk::vec2f64(this->x,this->y);edkEnd();
    }

    //--
    vec2f64 operator--(){
        //
        --this->x;edkEnd();
        --this->y;edkEnd();
        return edk::vec2f64(this->x,this->y);edkEnd();
    }
    vec2f64 operator--(edk::int32){
        //
        this->x--;edkEnd();
        this->y--;edkEnd();
        return edk::vec2f64(this->x,this->y);edkEnd();
    }

    //
    vec2f64 operator()(edk::float32 x,edk::float32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f64((edk::float64)this->x,(edk::float64)this->y);edkEnd();
    }
    vec2f64 operator()(edk::float64 x,edk::float64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f64((edk::float64)this->x,(edk::float64)this->y);edkEnd();
    }
    vec2f64 operator()(edk::int8 x,edk::int8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f64((edk::float64)this->x,(edk::float64)this->y);edkEnd();
    }
    vec2f64 operator()(edk::int16 x,edk::int16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f64((edk::float64)this->x,(edk::float64)this->y);edkEnd();
    }
    vec2f64 operator()(edk::int32 x,edk::int32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f64((edk::float64)this->x,(edk::float64)this->y);edkEnd();
    }
    vec2f64 operator()(edk::int64 x,edk::int64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f64((edk::float64)this->x,(edk::float64)this->y);edkEnd();
    }
    vec2f64 operator()(edk::uint8 x,edk::uint8 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f64((edk::float64)this->x,(edk::float64)this->y);edkEnd();
    }
    vec2f64 operator()(edk::uint16 x,edk::uint16 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f64((edk::float64)this->x,(edk::float64)this->y);edkEnd();
    }
    vec2f64 operator()(edk::uint32 x,edk::uint32 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f64((edk::float64)this->x,(edk::float64)this->y);edkEnd();
    }
    vec2f64 operator()(edk::uint64 x,edk::uint64 y){
        //
        this->x=x;edkEnd();
        this->y=y;edkEnd();
        return edk::vec2f64((edk::float64)this->x,(edk::float64)this->y);edkEnd();
    }
};
}//end namespace edk

#endif // TYPEVEC2_H
